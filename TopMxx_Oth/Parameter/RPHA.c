/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：RPHA.c
文件说明：RPHA参数管理文件，完成生产、系统、机器、硬件、状态等参数初始化，及机器、硬件参数的EEPROM中保存。

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
1、RPHA参数管理应用文件，主要管理如下与FM24CL64相关的操作：
	机器参数
	硬件配置
	计数数据
	归零及长度校准
2、本文件中函数需要IIC_Drv.c中驱动支持，并与之关系密切，因此在更改IIC_Drv.c中接口函数时，需要谨慎并注意对
   本文件中函数的可能影响。可能影响有：如果IIC驱动的读写时间增加，可能会使本文件中读写参数的函数执行时间加
   长，影响整个系统主循环的执行周期。
3、参数向FM24CL64读写未采用中断方式，因此较占用时间资源。
4、计数数据一般在一模后或清开模数后保存，在保存时不回读检查。
5、计数数据保存在两个区域，每次开机时要先找出最新的数据，判断过程为：
    	校验和均正确--------序号大的一组为最新数据
    	校验和只有一组正确--正确的一组为最新数据
    	校验和均不正确------警报“模数读取出错”
5、机器参数和硬件配置通过累加和（补码）校验码保证正确性。因此更改参数时，累加和也要同步更改。
   （注：原用CRC，但其计算时间约2ms，故简化为累加和）
6、FRAM使用FM24CL64（原FM24CL16），即FRAM（原EEPROM）。
****************************************************************************************************/
//#define mSysDebug		

#ifndef RPHA_c
	#define RPHA_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
//T6H3  FM24CL64	Slave:0x00  Addr:0x0000-0x1fff   Slave:0x01  Addr:0x0000-0x1fff 
//T6H5  FM24V02A  Slave:0x00  Addr:0x0000-0x7fff
#define	mFM24CLxxSlave0		0xA0	//FM24CL64/FM24V02A一的Slave地址	
#define	mFM24CLxxSlave1		0xA2	//FM24CL64二的Slave地址	
#define mFM24CLxxAddr16Flag	mTrue	//16位地址	FM24CL16	8位地址		应mFalse	并且还要改调用时的Slave和AddrH
									//			FM24CL64	16位地址	应mTrue

//FM24CL64一中参数存放		
#define mFMSA_MachParaUnRst		0x0000	//主机参数未重置标志	主机程序升级后，参数未重置标志		注意与Boot相关，更改时一起更改
#define mFMSA_ProdBatch			0x0002	//生产批号
#define mFMSA_ProdSN			0x0004	//生产序号
#define mFMSA_License0			0x0006	//License 0		4字节
#define mFMSA_License1			0x000A	//License 1		4字节

#define mFMSA_CntData1			0x0010	//开模计数、装模数、不良品数、润滑计数等计数数据存放区域1
#define mFMSA_CntData2			0x0040	//开模计数、装模数、不良品数、润滑计数等计数数据存放区域2
#define mFMSA_HardConf			0x1000	//硬件配置存放开始地址

#define mFMSA_MachPara1			0x2000	//机器参数存放开始地址，T6H5的机器参数存在FM24V02A一中

//FM24CL64二中参数存放		
#define mFMSA_MachPara2			0x0000	//机器参数存放开始地址，T6H3的机器参数存在FM24CL64二中



/*======================================= 模块内有效变量定义 ======================================*/
U8 Fm24xxSlave;								//机器参数存放从站地址
U16 Fmsa_MachPara;						//机器参数存放开始地址变量
	
Bool FM24CLxxErrFlag=mFalse;	//FM24CLxx出错
G10usTimer WorkTimeSaveTimer;	//工作时数保存计时器	每隔10分钟保存一次
								//						CntDataSave()时复位、RPHA_Pcs()中检查
	#define mWorkTimeSaveTime	T1sTo10us(600)

U8 CntDataSaveP=0xff;			//计数数据保存指针		0~sizeof(CntDataStr)-1：需要保存	
								//						0xff或sizeof(CntDataStr)：保存结束
	
/*======================================= 模块内有效函数声明 ======================================*/
Bool SaveAMachPara(U16 ParaSN);		//保存一个机器参数
Bool SaveAHardConf(U16 ParaSN);		//保存一个硬件配置

Bool ReadAMachPara(U16 ParaSN);		//读取一个机器参数
Bool ReadAHardConf(U16 ParaSN);		//读取一个硬件配置
Bool HardConfOLChk(U16 ParaSN);		//硬件配置超限检查

U16 ReadProdBatch(void);			//读取生产批号
U16 ReadProdSN(void);				//读取生产序号

Bool SaveProdBatch(U16 ProdBatch);	//保存生产批号
Bool SaveProdSN(U16 ProdSN);		//保存生产序号

Bool MachParaUnInitChk(void);		//主机参数未重置过检查
Bool MachParaUnInitRst(void);		//主机参数未重置过标志复位

Bool HardConfInit(void);			//硬件配置初始化
Bool MachParaInit(void);			//机器参数初始化
void CntDataInit(void);				//计数数据初始化

void HardConfReConf(void);			//硬件配置二次配置
void MachParaReConf(void);			//机器参数二次配置

void CntDataASave(void);			//计数数据保存一次(4字节)
/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug
int main(void)
{           
	do{
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
函数名称：	RPHA参数初始化
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void RPHA_Init(void)
{
	U16 i;
	
	//if(MachParaUnInitChk())	SetAlarm(mAlarm_MachParaUnRst);	//主程序升级后，机器参数未重置过	???
	
	for(i=0;i<mManuParaNum;i++)		ManuPara[i]=0;			//生产参数清0
	//for(i=0;i<mSysParaNum;i++)	SysPara[i]=0;			//系统参数清0	已经合并到机器参数
	for(i=0;i<mWorkStateNum;i++)	WorkState[i]=0;			//工作状态清0
	
	/*if((GetHardPlatLinkCode()==0x5C)||(GetHardPlatLinkCode()==0x60))//T6H5硬件  //20200511改 兼容T6H3和T6H5的铁电驱动
	{
		Fm24xxSlave=mFM24CLxxSlave0;
		Fmsa_MachPara=mFMSA_MachPara1;
	}
	else//T6H3硬件*/
	{
		Fm24xxSlave=mFM24CLxxSlave1;
		Fmsa_MachPara=mFMSA_MachPara2;
	}

	if(!HardConfInit())	SetAlarm(mAlarm_HardConfReadErr);	//硬件配置初始化
	if(!MachParaInit())	SetAlarm(mAlarm_MachParaReadErr);	//机器参数初始化

	CntDataInit();							//计数数据初始化
	
	State_CMSoftLinkCode=mCMSoftLinkCode;	//主机互连代码
	State_CMSoftSer     =mCMSoftSer     ;	//主机软件系列
	State_CMSoftVer     =mCMSoftVer     ;	//主机软件版本
	
	State_CMProdBatch   =ReadProdBatch();	//主机批号
	State_CMProdSN      =ReadProdSN();		//主机序号
	
	State_CMBootVer		=GetBootVer();		//获取Boot版本	
	
	G10usTimerRes(&WorkTimeSaveTimer);		//复位工作计时器
}
/****************************************************************************************************
函数名称：	RPHA处理
函数说明：
输入参数：
返 回 值：
其    它：
1、置于主循环。
2、实现：机器参数、硬件配置保存；位置尺归零、长度调整；计数清零。
3、机器参数保存后，计算累加和并保存周期用时约470us。
****************************************************************************************************/
void RPHA_Pcs(void)
{
	static Bool ParaRWOKFlag=mTrue;	//参数读写OK标志
	U32 Buff;

	//RPHA互连匹配检查
	if(CommLinkOKChk())
	{	//通讯正常
		if( (HardConf_HardConfLinkCode!=mCMSoftHardConfLinkCode)||
			(Para_MachParaLinkCode!=mCMSoftMachParaLinkCode)||
			(Para_ManuParaLinkCode!=mCMSoftManuParaLinkCode))
			//(Para_SysParaLinkCode!=mCMSoftSysParaLinkCode))						已经合并到机器参数
				SetAlarm(mAlarm_SoftParaLinkCodeErr);	//警报：程序和参数不匹配
	}
	
	//参数保存、位置尺校准和归零、计数清零、批号和序号设置
	if(MachParaSave.UpdateFlag)
	{	//机器参数保存
		if(MachParaSave.Len>0)
		{
			ParaRWOKFlag&=SaveAMachPara(MachParaSave.StartSN);
			MachParaSave.Len--,MachParaSave.StartSN++;
		}
		else
		{	//累加和校验处理
			MachPara[0]=0xa5a5a5a5-U32Array_Cal_Sum(&MachPara[1],mMachParaNum-1);	//重新计算累加和（补码）
			ParaRWOKFlag&=SaveAMachPara(mPara_MachParaSum);							//保存累加和
			MachParaReConf();														//二次配置
			
			if(ParaRWOKFlag!=mTrue)
			{	//读写失败
				SetAlarm(mAlarm_MachParaSaveErr);	//警报:机器参数保存出错
				ParaRWOKFlag=mTrue;
			}
			MachParaSave.UpdateFlag=mFalse;
		}
	}
	else if(HardConfSave.UpdateFlag)
	{	//硬件配置保存
		if(HardConfSave.Len>0)
		{
			ParaRWOKFlag&=SaveAHardConf(HardConfSave.StartSN);
			HardConfSave.Len--,HardConfSave.StartSN++;
		}
		else
		{	//累加和校验处理
			HardConf[0]=0xa5a5a5a5-U16Array_Cal_Sum(&HardConf[1],mHardConfNum-1);	//重新计算累加和（补码）
			ParaRWOKFlag&=SaveAHardConf(mHardConf_HardConfSum);			//保存累加和
			HardConfReConf();											//二次配置
			
			if(ParaRWOKFlag!=mTrue)
			{	//读写失败
				SetAlarm(mAlarm_HardConfSaveErr);	//警报:硬件配置保存出错
				ParaRWOKFlag=mTrue;
			}			
			HardConfSave.UpdateFlag=mFalse;
		}
	}
	else if(GetCommRecCode()==CC_SnrSetZero)
	{	//位置尺归零
		if(!MachParaSave.UpdateFlag)		
		{	//无机器参数在写入		如果有则放弃本次归零
			switch(GetCommRecCodePara0())
			{
				case mScrewSnrSetZero:	//螺杆尺归零	
					Para_ScrewSnrZero=GetScrewAbsPos();			//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_ScrewSnrZero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mMoldSnrSetZero:	//模板尺归零
					Para_MoldSnrZero=GetMold_CylAbsPos();		//更新零点位置		   	油缸位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_MoldSnrZero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mEjeSnrSetZero:	//顶针尺归零
					Para_EjeSnrZero=GetEjectAbsPos();			//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_EjeSnrZero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mNozSnrSetZero:	//座台尺归零
					Para_NozSnrZero=GetNozAbsPos();				//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_NozSnrZero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI1SetZero:		//模拟量1归零
					Para_HAI1Zero=GetHAI1AbsValue();			//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI1Zero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI2SetZero:		//模拟量2归零
					Para_HAI2Zero=GetHAI2AbsValue();			//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI2Zero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI3SetZero:		//模拟量3归零
					Para_HAI3Zero=GetHAI3AbsValue();			//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI3Zero;
					MachParaSave.Len=1;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mMoldThickSnrSetZero://模厚尺归零			20120814加
					Para_MoldThickSnrZero=GetMoldThickAbsPos();	//更新零点位置
					PosRefReq();								//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_MoldThickSnrZero;
					MachParaSave.Len=1;	
					MachParaSave.UpdateFlag=mTrue;
					break;					
			}
		}		
	}
	else if(GetCommRecCode()==CC_SnrSetLen)
	{	//位置尺长度校准		零点位置同比例修改
		if(!MachParaSave.UpdateFlag)		
		{	//无机器参数在写入		如果有则放弃本次归零
			switch(GetCommRecCodePara0())
			{
				case mScrewSnrSetLen:	//螺杆尺校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_ScrewSnrZero=(U64)Buff*Para_ScrewSnrZero/Para_ScrewSnrLen;		//零点位置同比例修改
					Para_ScrewSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_ScrewSnrLen;
					MachParaSave.Len=2;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mMoldSnrSetLen:	//模板尺校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_MoldSnrZero=(U64)Buff*Para_MoldSnrZero/Para_MoldSnrLen;		//零点位置同比例修改
					Para_MoldSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_MoldSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mEjeSnrSetLen:		//顶针尺校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_EjeSnrZero=(U64)Buff*Para_EjeSnrZero/Para_EjeSnrLen;			//零点位置同比例修改
					Para_EjeSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_EjeSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mNozSnrSetLen:		//座台尺校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_NozSnrZero=(U64)Buff*Para_NozSnrZero/Para_NozSnrLen;			//零点位置同比例修改
					Para_NozSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_NozSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI1SetLen:		//模拟量1校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_HAI1Zero=(U64)Buff*Para_HAI1Zero/Para_HAI1Len;					//零点位置同比例修改
					Para_HAI1Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI1Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI2SetLen:		//模拟量2校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_HAI2Zero=(U64)Buff*Para_HAI2Zero/Para_HAI2Len;					//零点位置同比例修改
					Para_HAI2Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI2Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI3SetLen:		//模拟量3校长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_HAI3Zero=(U64)Buff*Para_HAI3Zero/Para_HAI3Len;					//零点位置同比例修改
					Para_HAI3Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI3Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mMoldThickSnrSetLen://模厚尺校长度		20120814加
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					Para_MoldThickSnrZero=(U64)Buff*Para_MoldThickSnrZero/Para_MoldThickSnrLen;	//零点位置同比例修改
					Para_MoldThickSnrLen=Buff;
					PosRefReq();																//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_MoldThickSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mScrewSnrSetLen_CP:	//螺杆尺校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetScrewPos()<=0))	break;							//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_ScrewSnrLen/GetScrewPos();						//当前位置=>尺长度:P/Px=L/Lx

					Para_ScrewSnrZero=(U64)Buff*Para_ScrewSnrZero/Para_ScrewSnrLen;		//零点位置同比例修改
					Para_ScrewSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_ScrewSnrLen;
					MachParaSave.Len=2;							
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mMoldSnrSetLen_CP:		//模板尺校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetMold_MoldPos()<=0))	break;						//输入位置为0、当前位置为0或负，则无法校准
					Buff=MoldPosToCylPos(Buff);											//转换为油缸位置
					Buff=(U64)Buff*Para_MoldSnrLen/GetMold_CylPos();					//当前位置=>尺长度:P/Px=L/Lx

					Para_MoldSnrZero=(U64)Buff*Para_MoldSnrZero/Para_MoldSnrLen;		//零点位置同比例修改
					Para_MoldSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_MoldSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mEjeSnrSetLen_CP:		//顶针尺校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetEjectPos()<=0))	break;							//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_EjeSnrLen/GetEjectPos();						//当前位置=>尺长度:P/Px=L/Lx

					Para_EjeSnrZero=(U64)Buff*Para_EjeSnrZero/Para_EjeSnrLen;			//零点位置同比例修改
					Para_EjeSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_EjeSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mNozSnrSetLen_CP:		//座台尺校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetNozPos()<=0))	break;								//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_NozSnrLen/GetNozPos();							//当前位置=>尺长度:P/Px=L/Lx

					Para_NozSnrZero=(U64)Buff*Para_NozSnrZero/Para_NozSnrLen;			//零点位置同比例修改
					Para_NozSnrLen=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_NozSnrLen;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI1SetLen_CP:		//模拟量1校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetHAI1Value()<=0))	break;							//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_HAI1Len/GetHAI1Value();							//当前位置=>尺长度:P/Px=L/Lx

					Para_HAI1Zero=(U64)Buff*Para_HAI1Zero/Para_HAI1Len;					//零点位置同比例修改
					Para_HAI1Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI1Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI2SetLen_CP:		//模拟量2校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetHAI2Value()<=0))	break;							//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_HAI2Len/GetHAI2Value();							//当前位置=>尺长度:P/Px=L/Lx

					Para_HAI2Zero=(U64)Buff*Para_HAI2Zero/Para_HAI2Len;					//零点位置同比例修改
					Para_HAI2Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI2Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;
				case mHAI3SetLen_CP:		//模拟量3校长度			通过输入当前位置的方法校准长度
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();

					if((Buff==0)||(GetHAI3Value()<=0))	break;							//输入位置为0、当前位置为0或负，则无法校准
					Buff=(U64)Buff*Para_HAI3Len/GetHAI3Value();							//当前位置=>尺长度:P/Px=L/Lx

					Para_HAI3Zero=(U64)Buff*Para_HAI3Zero/Para_HAI3Len;					//零点位置同比例修改
					Para_HAI3Len=Buff;
					PosRefReq();														//申请立即刷新位置显示
					MachParaSave.StartSN=mPara_HAI3Len;
					MachParaSave.Len=2;
					MachParaSave.UpdateFlag=mTrue;
					break;			
				case mMoldThickSnrSetLen_CP://模厚尺校长度			通过输入当前位置的方法校准长度		20120814加
					Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
					if(Para_MoldThickSnrOpt)//配备模厚尺
					{
						Buff=Sub_MinZero(Buff,Para_MoldThickSnrOffset);						//需要先减去偏移量
						
						if((Buff==0)||(GetMoldThickPos()<=0))	break;						//输入位置为0、当前位置为0或负，则无法校准
						Buff=(U64)Buff*Para_MoldThickSnrLen/GetMoldThickPos();				//当前位置=>尺长度:P/Px=L/Lx

						Para_MoldThickSnrZero=(U64)Buff*Para_MoldThickSnrZero/Para_MoldThickSnrLen;	//零点位置同比例修改
						Para_MoldThickSnrLen=Buff;
						PosRefReq();																//申请立即刷新位置显示
						MachParaSave.StartSN=mPara_MoldThickSnrLen;
						MachParaSave.Len=2;
						MachParaSave.UpdateFlag=mTrue;
					}
					else//无模厚尺，校准调模电眼计数	20260112加
					{
						CntData.MoldAdjSnr=Buff;
						CntDataSave();
						State_MoldAdjSnrCnt=CntData.MoldAdjSnr;	
					}
					break;
			}
		}
	}
	else if(GetCommRecCode()==CC_CntClr)
	{	//计数清零
		switch(GetCommRecCodePara0())
		{	
			case mShotCntClr:	//清开模计数	
				CntData.Shot=0;
				CntData.ProdShot=0;//生产模数（模号）	20250325加
				CntDataSave();
				break;
			case mPackCntClr:	//清装模数
				CntData.Pack=0;
				CntDataSave();
				break;
			case mShotBadCntClr://清不良品数
				CntData.ShotBad=0;
				CntDataSave();
				break;
			case mWorkCnt:		//工作计数清零		包括累计开模数和工作时数
				CntData.WorkShot=0;
				CntData.WorkTime=0;
				CntDataSave();
				break;
			case mLubr1CntSet:	//设置离下次润滑模数	注意特殊，不是简单的清零，后面需再加4字节参数，0xffffffff即已经润滑模数清0	20121025加
				Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
				CntData.Lubr1=Sub_MinZero(GetLubr1UnitCnt(),Buff);
				if(Buff==0xffffffff)	CntData.LubrCnt_1W=0;			//如果润滑模数清成0，则润滑1万模计数也清0
				CntDataSave();
				break;
			case mLubr2CntSet:	//设置离下次润滑模数	注意特殊，不是简单的清零，后面需再加4字节参数，0xffffffff即已经润滑模数清0	20121025加
				Buff=(GetCommRecCodePara4()<<24)+(GetCommRecCodePara3()<<16)+(GetCommRecCodePara2()<<8)+GetCommRecCodePara1();
				CntData.Lubr2=Sub_MinZero(GetLubr2UnitCnt(),Buff);
				if(Buff==0xffffffff)	CntData.LubrCnt_1W=0;			//如果润滑模数清成0，则润滑1万模计数也清0
				CntDataSave();
				break;
		}		
	}
	else if(GetCommRecCode()==CC_SetBatchSN)	
	{	//产品序号、批号设置	
		SaveProdBatch((GetCommRecCodePara0()<<8)+GetCommRecCodePara1());
		SaveProdSN((GetCommRecCodePara2()<<8)+GetCommRecCodePara3());

		State_CMProdBatch   =ReadProdBatch();	//主机批号
		State_CMProdSN      =ReadProdSN();		//主机序号
	}
	else if(GetCommRecCode()==CC_MachParaUnInitRst)
	{	//主机参数未初始化标志复位
		MachParaUnInitRst();
	}
	else if(CntDataSaveP<sizeof(CntDataStr))
	{	//计数数据要保存
		CntDataASave();
	}
	
	//20200713
	if(GetCommRecCode()==CC_DryCycCont)
		DryCycFlag=GetCommRecCodePara0();
		
	if(SysSta_IsIdle()||SysSta_IsSysStopMode())
	{	//累计工作时数处理		系统空闲或紧急停止模式时,隔10分钟保存一次
		if(G10usTimerOver(&WorkTimeSaveTimer,mWorkTimeSaveTime))
			CntDataSave();
	
		State_Lubr1NextUnitCnt=Min(Sub_MinZero(GetLubr1UnitCnt(),CntData.Lubr1),0xffff);	//20121026加：显示离下次润滑剩余模数
		State_Lubr2NextUnitCnt=Min(Sub_MinZero(GetLubr2UnitCnt(),CntData.Lubr2),0xffff);	//20121026加：显示离下次润滑剩余模数
																							//主循环也处理一下，主要是为了润滑模数修改后及时更新
	}
	
	//FM24CLxx失效检查
	if(FM24CLxxErrFlag)
	{	//失效
		SetAlarm(mAlarm_IICMemoryErr);
		SetDigiLed(mDC_HardErr);
	}
}
/****************************************************************************************************
函数名称：	硬件配置二次配置
函数说明：	
输入参数：	
返 回 值：	
其    它：
****************************************************************************************************/
void HardConfReConf(void)
{
}
/****************************************************************************************************
函数名称：	机器参数二次配置
函数说明：
输入参数：	
返 回 值：	
其    它：
****************************************************************************************************/
void MachParaReConf(void)
{
}
/****************************************************************************************************
函数名称：	硬件配置初始化
函数说明：
输入参数：	
返 回 值：	mTrue--成功	mFalse--失败
其    它：
1、硬件参数不出现超限，否则后果未知，可能导致程序死机。原因是要依据硬件配置向资源数组读、写数据，如果
   超出资源数组的范围，则可能导致非法内存读写。
****************************************************************************************************/
Bool HardConfInit(void)
{
	U16 i;
	Bool SumFlag;
	
	//读取
	for(i=0;i<mHardConfNum;i++)	
	{
		if(ReadAHardConf(i)==mFalse)
			return mFalse;
	}
	//累加和校验（补码）
	if(U16Array_Cal_Sum(&HardConf[0],mHardConfNum)==0xa5a5)	SumFlag=mTrue;
	else													SumFlag=mFalse;
	//二次配置
	HardConfReConf();
	
	return	SumFlag;
}
/****************************************************************************************************
函数名称：	机器参数初始化
函数说明：
输入参数：	
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool MachParaInit(void)
{
	U16 i;
	Bool SumFlag;
	
	//读取
	for(i=0;i<mMachParaNum;i++)	
	{
		if(ReadAMachPara(i)==mFalse)
			return mFalse;
	}
	//累加和校验（补码）
	if(U32Array_Cal_Sum(&MachPara[0],mMachParaNum)==0xa5a5a5a5)	SumFlag=mTrue;
	else														SumFlag=mFalse;
	//二次配置
	MachParaReConf();
	
	return	SumFlag;
}
/****************************************************************************************************
函数名称：	保存一个机器参数
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveAMachPara(U16 ParaSN)
{
	U32 SavePara;
	U8 Buff[4];

	if(ParaSN>=mMachParaNum)
		return mFalse;
	
	SavePara=MachPara[ParaSN];
	Buff[0]=GetU8_L1(SavePara);
	Buff[1]=GetU8_L2(SavePara);
	Buff[2]=GetU8_L3(SavePara);
	Buff[3]=GetU8_L4(SavePara);
	
	if(I2CWrite(Fm24xxSlave,Fmsa_MachPara+(ParaSN<<2),4,Buff,mFM24CLxxAddr16Flag)) //20200511改
	{	//有效写入
		if(ReadAMachPara(ParaSN))
		{	//读取成功
			if(SavePara==MachPara[ParaSN])	return mTrue;	//回读成功
			else							return mFalse;	//回读失败
		}
		else
		{
			FM24CLxxErrFlag=mTrue;
			return mFalse;
		}
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	读取一个机器参数
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--读取失败
			读取到的机器参数直接放在MachPara数组
其    它：
****************************************************************************************************/
Bool ReadAMachPara(U16 ParaSN)
{
	U8 Buff[4];

	if(ParaSN>=mMachParaNum)
		return mFalse;

	if(I2CRead(Fm24xxSlave,Fmsa_MachPara+(ParaSN<<2),4,Buff,mFM24CLxxAddr16Flag)) //20200511改
	{	//有效读取
		MachPara[ParaSN]=(Buff[3]<<24)+(Buff[2]<<16)+(Buff[1]<<8)+Buff[0];
		
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	保存一个硬件配置
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveAHardConf(U16 ParaSN)
{
	U16 SavePara;
	U8 Buff[2];

	if(ParaSN>=mHardConfNum)
		return mFalse;

	SavePara=HardConf[ParaSN];
	Buff[0]=SavePara&0x00ff;
	Buff[1]=SavePara>>8;
	
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_HardConf+(ParaSN<<1),2,Buff,mFM24CLxxAddr16Flag))
	{	//有效写入
		if(ReadAHardConf(ParaSN))
		{	//读取成功
			if(SavePara==HardConf[ParaSN])	return mTrue;	//回读成功
			else							return mFalse;	//回读失败
		}
		else
		{
			FM24CLxxErrFlag=mTrue;
			return mFalse;
		}			
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	读取一个硬件配置
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--读取失败
			读取到的硬件配置直接放在HardConf数组
其    它：
****************************************************************************************************/
Bool ReadAHardConf(U16 ParaSN)
{
	U8 Buff[2];

	if(ParaSN>=mHardConfNum)
		return mFalse;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_HardConf+(ParaSN<<1),2,Buff,mFM24CLxxAddr16Flag))
	{	//有效读取
		HardConf[ParaSN]=(Buff[1]<<8)+Buff[0];
		
		//超限检查
		if(HardConfOLChk(ParaSN))	return mTrue;
		else 						return mFalse;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;

		//超限检查				必须，否则可能异常内存访问导致死机
		HardConfOLChk(ParaSN);
		
		return mFalse;;	
	}
}	
/****************************************************************************************************
函数名称：	硬件配置超限检查
函数说明：
输入参数：
返 回 值：	mTrue--正常	mFalse--超限
其    它：
1、检查硬件配置值是否超出范围，如mHard_DIxx应在mRI_StartSN~mRI_EndSN范围，如超出则直接改成mRI_Null。
2、如硬件配置出错，可能致死机。原因是要依据硬件配置向资源数组读、写数据，如果超出资源数组的范围，则
   可能导致非法内存读写。

???目前程序只检查基本模块，对其它模块尚未做检查，如果使用了，则也要检查。
****************************************************************************************************/
Bool HardConfOLChk(U16 ParaSN)
{
	if((ParaSN>=mHard_DI01)&&(ParaSN<=mHard_DI64))
	{	//DI类型
		if((HardConf[ParaSN]<=mRI_StartSN)||(HardConf[ParaSN]>=mRI_EndSN))
		{
			HardConf[ParaSN]=mRI_Null;
			return mFalse;
		}
	}
	else if((ParaSN>=mHard_DO01)&&(ParaSN<=mHard_DO96))	
	{	//DO类型
		if((HardConf[ParaSN]<=mRO_StartSN)||(HardConf[ParaSN]>=mRO_EndSN))
		{
			HardConf[ParaSN]=mRO_Null;
			return mFalse;
		}
	}
	else if((ParaSN>=mHard_DA01)&&(ParaSN<=mHard_DA16))	
	{	//DA类型
		if((HardConf[ParaSN]<=mRU_StartSN)||(HardConf[ParaSN]>=mRU_EndSN))
		{
			HardConf[ParaSN]=mRU_OutNull;
			return mFalse;
		}
	}
	else if((ParaSN>=mHard_HAD01)&&(ParaSN<=mHard_HAD16))	
	{	//HAD类型
		if((HardConf[ParaSN]<=mRU_StartSN)||(HardConf[ParaSN]>=mRU_EndSN))
		{
			HardConf[ParaSN]=mRU_InNull;
			return mFalse;
		}
	}
	else if((ParaSN>=mHard_LAD01)&&(ParaSN<=mHard_LAD16))	
	{	//LAD类型
		if((HardConf[ParaSN]<=mRU_StartSN)||(HardConf[ParaSN]>=mRU_EndSN))
		{
			HardConf[ParaSN]=mRU_InNull;
			return mFalse;
		}
	}
	else if((ParaSN>=mHard_CNT01)&&(ParaSN<=mHard_CNT08))	
	{	//CNT类型
		if((HardConf[ParaSN]<=mRU_StartSN)||(HardConf[ParaSN]>=mRU_EndSN))
		{
			HardConf[ParaSN]=mRU_InNull;
			return mFalse;
		}
	}
	//???其它模块
	
	return mTrue;
}
/****************************************************************************************************
函数名称：	读取产品批号
函数说明：
输入参数：
返 回 值：	0xfff0--读取失败
其    它：
****************************************************************************************************/
U16 ReadProdBatch(void)
{
	U16 ProdBatch;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_ProdBatch,2,(U8 *)(&ProdBatch),mFM24CLxxAddr16Flag))
	{	//有效读取
		return ProdBatch;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return 0xfff0;	
	}
}
/****************************************************************************************************
函数名称：	读取产品序号
函数说明：
输入参数：
返 回 值：	0xfff0--读取失败
其    它：
****************************************************************************************************/
U16 ReadProdSN(void)
{
	U16 ProdSN;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_ProdSN,2,(U8 *)(&ProdSN),mFM24CLxxAddr16Flag))
	{	//有效读取
		return ProdSN;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return 0xfff0;	
	}
}
/****************************************************************************************************
函数名称：	保存产品批号
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveProdBatch(U16 ProdBatch)
{
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_ProdBatch,2,(U8 *)(&ProdBatch),mFM24CLxxAddr16Flag))
	{	//有效写入
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	保存产品序号
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveProdSN(U16 ProdSN)
{
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_ProdSN,2,(U8 *)(&ProdSN),mFM24CLxxAddr16Flag))
	{	//有效写入
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}

/****************************************************************************************************
函数名称：	读取License0
函数说明：
输入参数：
返 回 值：	0xffffffff--读取失败
其    它：
****************************************************************************************************/
U32 ReadLicense0(void)
{
	U32 License;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_License0,4,(U8 *)(&License),mFM24CLxxAddr16Flag))
	{	//有效读取
		return License;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return 0xffffffff;	
	}
}
/****************************************************************************************************
函数名称：	读取License1
函数说明：
输入参数：
返 回 值：	0xffffffff--读取失败
其    它：
****************************************************************************************************/
U32 ReadLicense1(void)
{
	U32 License;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_License1,4,(U8 *)(&License),mFM24CLxxAddr16Flag))
	{	//有效读取
		return License;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return 0xffffffff;	
	}
}
/****************************************************************************************************
函数名称：	保存License0
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveLicense0(U32 License)
{
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_License0,4,(U8 *)(&License),mFM24CLxxAddr16Flag))
	{	//有效写入
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	保存License1
函数说明：
输入参数：
返 回 值：	mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool SaveLicense1(U32 License)
{
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_License1,4,(U8 *)(&License),mFM24CLxxAddr16Flag))
	{	//有效写入
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}

/****************************************************************************************************
函数名称：	主机参数未重置过检查
函数说明：
输入参数：
返 回 值：	mTrue--未重置过
其    它：
1、主机程序升级时，会更新FRAM中mFMSA_MachParaUnRst地址，提示用户程序升级后机器参数最好也重置
****************************************************************************************************/
Bool MachParaUnInitChk(void)
{
	U16 Buff;

	if(I2CRead(mFM24CLxxSlave0,mFMSA_MachParaUnRst,2,(U8 *)(&Buff),mFM24CLxxAddr16Flag))
	{	//有效读取
		return(Buff!=mMachParaRstCode);
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}
/****************************************************************************************************
函数名称：	主机参数未重置过标志复位
函数说明：
输入参数：
返 回 值：	mTrue--重置过
其    它：
1、主机程序升级时，会更新FRAM中mFMSA_MachParaUnRst地址，提示用户程序升级后机器参数最好也重置
****************************************************************************************************/
Bool MachParaUnInitRst(void)
{
	U16 Buff;
	
	Buff=mMachParaRstCode;
	
	if(I2CWrite(mFM24CLxxSlave0,mFMSA_MachParaUnRst,2,(U8 *)(&Buff),mFM24CLxxAddr16Flag))
	{	//有效写入
		return mTrue;
	}
	else
	{
		FM24CLxxErrFlag=mTrue;
		return mFalse;	
	}
}

/****************************************************************************************************
函数名称：计数信息一次保存
函数说明：
输入参数：
返 回 值：
其    它：
1、保存一组计数数据(4字节)。
****************************************************************************************************/
void CntDataASave(void)
{
	U16 Addr;
	
	if(CntDataSaveP<sizeof(CntDataStr))
	{
		if(CntData.SaveSn&1)	Addr=mFMSA_CntData1+CntDataSaveP;
		else					Addr=mFMSA_CntData2+CntDataSaveP;
			
		if(!I2CWrite(mFM24CLxxSlave0,Addr,4,((U8 *)(&CntData))+CntDataSaveP,mFM24CLxxAddr16Flag))
			FM24CLxxErrFlag=mTrue;
		
		CntDataSaveP+=4;
	}	
}
/****************************************************************************************************
函数名称：计数信息读取
函数说明：开机后，读取计数信息
输入参数：
返 回 值：
其    它：
1、本函数只在开机初始化时执行。
****************************************************************************************************/
void CntDataInit(void)
{
	Bool CntData1ReadOKFlag,CntData2ReadOKFlag;
	CntDataStr CntData1,CntData2;
	U16 ChkSum,i;
	U8 *p;
	
	CntData1ReadOKFlag=I2CRead(mFM24CLxxSlave0,mFMSA_CntData1,sizeof(CntDataStr),((U8 *)(&CntData1)),mFM24CLxxAddr16Flag);
	if(!CntData1ReadOKFlag)FM24CLxxErrFlag=mTrue;
	p=((U8 *)(&CntData1));
	for(i=0,ChkSum=0;i<sizeof(CntDataStr);i++)	ChkSum+=p[i];		//校验和检查
	ChkSum=ChkSum-(CntData1.ChkSum>>8)-(CntData1.ChkSum&0x00ff);
	if(ChkSum==CntData1.ChkSum)	CntData1ReadOKFlag&=mTrue;	
	else						CntData1ReadOKFlag=mFalse;
	
	CntData2ReadOKFlag=I2CRead(mFM24CLxxSlave0,mFMSA_CntData2,sizeof(CntDataStr),((U8 *)(&CntData2)),mFM24CLxxAddr16Flag);
	if(!CntData2ReadOKFlag)FM24CLxxErrFlag=mTrue;
	p=((U8 *)(&CntData2));
	for(i=0,ChkSum=0;i<sizeof(CntDataStr);i++)	ChkSum+=p[i];		//校验和检查
	ChkSum=ChkSum-(CntData2.ChkSum>>8)-(CntData2.ChkSum&0x00ff);
	if(ChkSum==CntData2.ChkSum)	CntData2ReadOKFlag&=mTrue;	
	else						CntData2ReadOKFlag=mFalse;

	CntData1ReadOKFlag&=((CntData1.SaveSn&1)==1)?mTrue:mFalse;		//序号检查
	CntData2ReadOKFlag&=((CntData2.SaveSn&1)==0)?mTrue:mFalse;

	if(CntData1ReadOKFlag&&CntData2ReadOKFlag)
	{	//读出都正确
		if((CntData1.SaveSn-CntData2.SaveSn)==1)CntData=CntData1;	//序号差1				取Buff1为最新计数
		else									CntData=CntData2;	//序号差255或序号不连续	取Buff2为最新计数
	}
	else if(CntData1ReadOKFlag)
		CntData=CntData1;							//只有CntData1计数数据有效
	else if(CntData2ReadOKFlag)
		CntData=CntData2;							//只有CntData2计数数据有效
	else
	{
		CntData=CntData2;							//计数数据都无效，任取Buff2
		
		p=((U8 *)(&CntData2));
		for(i=0,ChkSum=0;i<sizeof(CntDataStr)-4;i++)	ChkSum+=p[i];		//校验和检查
		ChkSum=ChkSum-(CntData2.MoldAdjSnr>>8)-(CntData2.MoldAdjSnr&0x00ff);
		if(ChkSum!=CntData2.MoldAdjSnr)SetAlarm(mAlarm_CntDataReadErr);		//警报：计数数据读取失败
		//20121027对警报增加条件，原因：为实现润滑区分前后1万模，CntData结构增加了4个字节，因此当程序升级后会出现计数数据出错（校验和出错）
		//避免升级后误报警方案：CntData2.Reserve挤占了原校验和空间，如果CntData2.Reserve作为校验和发现是正确的，意味着可能程序升级引起出错，不警报
	}
	
	//更新到状态
	State_ShotCntLW	=CntData.Shot;		//开模计数
	State_ShotCntHW =CntData.Shot>>16;
	State_PackageCnt=CntData.Pack;		//包装数
	State_ShotBadCnt=CntData.ShotBad;	//不良品数

	State_ProdShotCntLW=CntData.ProdShot;		//生产模数（模号）	20250325加
	State_ProdShotCntHW=CntData.ProdShot>>16;
	
	State_CMWorkShotCntLW=CntData.WorkShot;			//累计工作模数
	State_CMWorkShotCntHW=CntData.WorkShot>>16;
	State_CMWorkTimeLW	 =CntData.WorkTime;			//累计工作时间
	State_CMWorkTimeHW	 =CntData.WorkTime>>16;
	
	//State_LubrCnt_1W=(CntData.LubrCnt_1W>=Get_LPM_Num())?1:0;							//20121026加：润滑1万模计数		20130905改：10000用Get_LPM_Num()代替，后者为宏，改宏原因是：可能5万模为界
	State_LubrCnt_1W=(CntData.LubrCnt_1W>=Get_LPM1_Num())? mBit0:0;						//20181008改：检查润滑1是否超过前后润滑模数
	if(CntData.LubrCnt_1W>=Get_LPM2_Num())	State_LubrCnt_1W|=mBit1;					//20181008改：检查润滑2是否超过前后润滑模数
	State_Lubr1NextUnitCnt=Min(Sub_MinZero(GetLubr1UnitCnt(),CntData.Lubr1),0xffff);	//20121026加：显示离下次润滑剩余模数
	State_Lubr2NextUnitCnt=Min(Sub_MinZero(GetLubr2UnitCnt(),CntData.Lubr2),0xffff);	//20121026加：显示离下次润滑剩余模数
	
	State_MoldAdjSnrCnt=CntData.MoldAdjSnr;			//20260112加：显示调模电眼计数 调模电眼计数*位置调模比=模厚值
}
/****************************************************************************************************
函数名称：	计数信息保存
函数说明：	计数信息保存到FM24CL16，并更新到状态
输入参数：
返 回 值：
其    它：
1、对于写入，不做回读亦不管写出错，由开机读取时检查出错否（若出错给出提示）。
2、本函数在完成1模后、开模数清0后、润滑计数到后时，调用执行。
3、本函数中并不真正执行向FRAM的写入，而是在RPHA_Pcs()才分次写入，目的是减小主循环周期。具体方法：
   	调用本函数-->生成写入数据-->CntDataSaveP=0
   	RPHA_Pcs()-->检查CntDataSaveP<Sizeof(CntDataStr)-->写入4字节
****************************************************************************************************/
void CntDataSave(void)
{
	U8 *p;
	U16 ChkSum,i;
	
	//工作时数处理
	CntData.WorkTime+=T10usTo1s(G10usTimerCal(&WorkTimeSaveTimer));		//计算累计工作时间
	G10usTimerRes(&WorkTimeSaveTimer);									//复位计时器
	
	//序号及指针调整
	if(CntDataSaveP>=sizeof(CntDataStr))
		CntData.SaveSn++;				
	CntDataSaveP=0;						//写入指针复位		RPHA_Pcs()中检查该指针然后写入

	//累加和计算
	p=(U8 *)(&CntData);CntData.ChkSum=0;
	for(i=0,ChkSum=0;i<sizeof(CntDataStr);i++)	ChkSum+=p[i];
	CntData.ChkSum=ChkSum;
	
	//更新到状态
	State_ShotCntLW	=CntData.Shot;		//开模计数
	State_ShotCntHW =CntData.Shot>>16;
	State_PackageCnt=CntData.Pack;		//包装数
	State_ShotBadCnt=CntData.ShotBad;	//不良品数
	
	State_ProdShotCntLW=CntData.ProdShot;		//生产模数（模号）	20250325加
	State_ProdShotCntHW=CntData.ProdShot>>16;
	
	State_CMWorkShotCntLW=CntData.WorkShot;			//累计工作模数
	State_CMWorkShotCntHW=CntData.WorkShot>>16;
	State_CMWorkTimeLW	 =CntData.WorkTime;			//累计工作时间
	State_CMWorkTimeHW	 =CntData.WorkTime>>16;
	
	//State_LubrCnt_1W=(CntData.LubrCnt_1W>=Get_LPM_Num())?1:0;							//20121026加：润滑1万模计数		20130905改：10000用Get_LPM_Num()代替，后者为宏，改宏原因是：可能5万模为界
	State_LubrCnt_1W=(CntData.LubrCnt_1W>=Get_LPM1_Num())? mBit0:0;						//20181008改：检查润滑1是否超过前后润滑模数
	if(CntData.LubrCnt_1W>=Get_LPM2_Num())	State_LubrCnt_1W|=mBit1;					//20181008改：检查润滑2是否超过前后润滑模数
	State_Lubr1NextUnitCnt=Min(Sub_MinZero(GetLubr1UnitCnt(),CntData.Lubr1),0xffff);	//20121026加：显示离下次润滑剩余模数
	State_Lubr2NextUnitCnt=Min(Sub_MinZero(GetLubr2UnitCnt(),CntData.Lubr2),0xffff);	//20121026加：显示离下次润滑剩余模数
}

/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/


//???机器参数、硬件配置出错时，要求重置才能正常工作，否则有较大安全隐患
//	 如硬件配置出错，可能致死机。原因是要依据硬件配置向资源数组读、写数据，如果超出资源数组的范围，则可能导致非法内存读写。

