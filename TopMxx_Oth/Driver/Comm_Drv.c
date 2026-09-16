/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：串口通信处理.c
文件说明：处理串口通信的文件

作    者：WLZ
编写时间：2024.12.19
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
1、通讯驱动程序。
2、基于UART3完成与WM的通讯，使用Pd8/TXD0和Pd9/RXD0。
3、与WM采用主从应答方式通讯，WM为。数据传送以帧为单位，通过CRC、偶校验进行传输级的差错控制，通过帧序
   号、长度限制、标识符等进行协议级的差错控制。在CM中通讯收发由中断实现，但中断中只是简单的数据收发，
   收发的数据均在主循环中处理（目的是保证数据完整性）。
4、本驱动占用了较多的RAM空间（约2kBytes），这是因为通讯以帧为单位所致。
5、通讯相关约定详见文档“T6F5-Qxx通讯协议.DOC”

注：本驱动与T6F3-Q8C的驱动基本同，改动有：
****************************************************************************************************/
//#define mSysDebug				

#ifndef Comm_Drv_c
	#define Comm_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define mComm_BPS			115200	//通讯波特率

#define EnCommTxInt()		(usart_interrupt_enable(USART2, USART_INT_TBE))  	//串口发送使能 
#define DisCommTxInt()		(usart_interrupt_disable(USART2, USART_INT_TBE))  	//串口发送禁能 

#define UartStartCode()  (usart_data_transmit(USART2, F_StartCode1)) //串口发送第一个字符

#define mSendFrameLenMax	1024	//发送帧最大长度	字节
#define mRecFrameLenmax		1024	//接收帧最大长度	字节

#define mCommRecBrkTime		3		//通讯接收中断时间	10ms	为满足Linux系统下的Q8C程序，降至30ms(操作系统响应实时性略差)
#define mCommLinkErrTime	150		//通讯联机出错时间	1500ms	为减少通讯检出次数(增加通讯出错重发次数)，延长通讯联机中断检出时间到1.5s

//帧特殊代码定义
#define F_StartCode1		0xf6	//启始符1
#define F_StartCode2		0x6f	//启始符2

#define LSS_ChkCode1		0x66	//程序下载启动帧校验码
#define LSS_ChkCode2		0x99
#define LSS_ChkCode3		0x99
#define LSS_ChkCode4		0x66
#define LSS_ChkCode5		0x69
#define LSS_ChkCode6		0x96
#define LSS_ChkCode7		0x55
#define LSS_ChkCode8		0x88

//通讯指令定义
#define CC_LinkRst				0x11	//联机复位
#define CC_ReadWorkState	0x12	//读取工作状态
#define CC_ReadManuPara		0x38	//读取生产参数
#define CC_LoadManuPara		0x13	//加载生产参数
#define CC_LoadSysPara		0x14	//加载系统参数
#define CC_ReadMachPara		0x15	//读取机器参数
#define CC_LoadMachPara		0x16	//加载机器参数
#define CC_ReadHardConf		0x17	//读取硬件配置
#define CC_LoadHardConf		0x18	//加载硬件配置
#define CC_ReadPeriPara		0x1b	//读取外设参数
#define CC_LoadPeriPara		0x1c	//加载外设参数
#define CC_ReadGivenPeriPara		0x1d	//读取指定外设参数,数据部分16位,最多一次回读64个参数
#define CC_ReadWavePara		0x1e	//读取波形参数

#define CC_LoadForward		0x58	//加载界面到CBox数据，由主机转发	20170705
#define CC_ReadForward		0x59	//读取CBox到界面数据，由主机转发	20170705
/*======================================= 模块内有效变量定义 ======================================*/
U8 CommState=0;					//通讯状态
	#define CS_LinkErr			0	//联机出错
	#define CS_RecManuPara		1	//接收生产参数
	#define CS_SendMachPara		2	//返回机器参数
	#define CS_SendHardPara		3	//返回硬件配置
	#define CS_SendWorkState	4	//返回工作状态	
	#define CS_LinkOK					5	//联机成功
U8	CommRecState=1;				//通讯接收状态
	#define CRS_RecDisable		0	//接收禁止
	#define CRS_FrameStart1		1	//帧启始符1接收
	#define CRS_FrameStart2		2	//帧启始符2接收
	#define CRS_FrameSN			3	//帧序号接收
	#define CRS_FrameLen		4	//帧长度接收
	#define CRS_FrameData		5	//帧数据接收
	#define CRS_FrameCRC1		6	//帧CRC高字节接收
	#define CRS_FrameCRC2		7	//帧CRC低字节接收
U8 CommSendState=0;				//通讯发送状态
	#define CSS_SendDisable		0	//发送禁止
	#define CSS_SendData		1	//发送数据
	#define CSS_SendCRC1		2	//发送CRC高字节
	#define CSS_SendCRC2		3	//发送CRC低字节

U8 CommSendBuff[mSendFrameLenMax+16];//发送缓存
U16 CommSendBuffP;					
U16 CommSendLen;					//数据字节数＋1字节起始符＋2字节帧长度和序号
U16 CommSendCRC;

U8 CommRecBuff[mRecFrameLenmax+16];	//接收缓存
U16 CommRecBuffP;
U16 CommRecLen;						//数据字节数＋2字节帧长度和序号
U16 CommRecCRC;
G10msTimer CommRecBrkTimer;		//通讯接收中断检查定时器

Bool CommFrameRecFlag=mFalse;		//帧接收标志	用于中断函数通知通讯处理函数有帧接收
U8 CommLastFrameSN=0;				//最后一次通讯帧序号
G10msTimer CommLinkErrTimer;		//通讯联机出错定时器


Bool RecCodeFlag;				//接收到指令标志
U8 RecCodeBuff[20];				//接收到的指令

Bool ParaModifyFlag=mTrue;		//参数修改标志			收到生产参数、系统参数、机器参数或资源修改时给出
								//						类似中子处理函数中引用，根据该标志对某些变量进行更新，以降低执行时间占用
Bool ManuParaModifyFlag=mTrue;	//生产参数修改标志
Bool MachParaModifyFlag=mTrue;	//机器参数修改标志
Bool SysParaModifyFlag=mTrue;	//系统参数修改标志
Bool HardConfModifyFlag=mTrue;	//硬件配置修改标志
Bool PeriParaModifyFlag=mTrue;	//外设参数修改标志

Bool WorkStateReadFlag=mFalse;	//工作状态被读走		20210608加：蒙德多个驱动器时，状态轮流经WorkState[]返回，所以用到

U32	ManuParaModifySn=mManuParaNum;			//生产参数修改序号

/*======================================= 模块内有效函数声明 ======================================*/
void UART2_IRQHandler(void);	//UART2中断 
void CommRecIRQPcs(void);			//接收中断处理
void CommSendIRQPcs(void);			//发送中断处理

void Ack_CodeFrame(void);			//指令帧应答
void Ack_ReadFrame(void);			//读取帧应答
void Ack_LoadFrame(void);			//加载帧应答

/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug
U16 x,y,z;
    
int main(void)
{           	
	do{
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
函数名称：通讯处理
函数说明：
输入参数：
返 回 值：
其    它：
1)本函数置于主循环中。

****************************************************************************************************/
void Comm_Drv_Pcs(void)
{
	Bool FrameReRecFlag;	//收到重发帧标志
	
	usart_interrupt_disable(USART2, USART_INT_RBNE);	//接收非空中断	
	
	RecCodeFlag=mFalse;		//复位发出的指令
	
	ParaModifyFlag=mFalse;		//复位参数修改标记
	ManuParaModifyFlag=mFalse;	//生产参数修改标志
	MachParaModifyFlag=mFalse;	//机器参数修改标志
	PeriParaModifyFlag = mFalse;
	SysParaModifyFlag=mFalse;	//系统参数修改标志
	HardConfModifyFlag=mFalse;	//硬件配置修改标志
	WorkStateReadFlag=mFalse;	//工作状态读取指令标志	20210608加
	
	ManuParaModifySn=mManuParaNum;		//复位生产参数修改序号
	
	if(G10msTimerOver(&CommLinkErrTimer,mCommLinkErrTime))
		CommState=CS_LinkErr;	//正常通讯间隔超过1.5s
	if(CommFrameRecFlag)
	{	//有帧接收
		CommFrameRecFlag=mFalse;
		CommRecState=CRS_FrameStart1;	//重启接收
		
		//检查是否重发帧
		if((CommRecBuff[0]&mBit7)&&((CommRecBuff[0]&0x70)==CommLastFrameSN))
			FrameReRecFlag=mTrue;
		else
			FrameReRecFlag=mFalse;
		CommLastFrameSN=CommRecBuff[0]&0x70;
		
		if(CommRecBuff[2]==CC_BootOperate)
		{	//收到Boot操作指令		无论通讯是否正常，均予以响应
			RecCodeFlag=mTrue;
			RecCodeBuff[0]=CommRecBuff[2];
			RecCodeBuff[1]=CommRecBuff[3];
			RecCodeBuff[2]=CommRecBuff[4];
			RecCodeBuff[3]=CommRecBuff[5];
			RecCodeBuff[4]=CommRecBuff[6];
			RecCodeBuff[5]=CommRecBuff[7];
			Ack_CodeFrame();
		}
		
		if(CommLinkOKChk())
		{	//通讯正常
			switch(CommRecBuff[2])
			{
				case CC_LinkRst			:
					CommState=CS_LinkErr;
					Ack_CodeFrame();
					break;
				case CC_ReadWorkState   :
					G10msTimerRes(&CommLinkErrTimer);	//复位通讯联机出错定时器
					Ack_ReadFrame();
					break;
				case CC_ReadMachPara	:
				case CC_ReadManuPara	:
				case CC_ReadHardConf	:
				case CC_ReadForward		:	//20170705	读取CBox到界面数据，由主机转发
				case CC_ReadPeriPara	:	
				case CC_ReadWavePara  :
				case CC_ReadGivenPeriPara://20191231 读取指定外设参数
					Ack_ReadFrame();
					break;
				case CC_LoadManuPara	:
				case CC_LoadSysPara	    :
				case CC_LoadMachPara	:
				case CC_LoadHardConf	:
				case CC_LoadForward		:	//20170705	加载数据到主机，并由主机转发到CBox
				case CC_LoadPeriPara		:	
					Ack_LoadFrame();
					break;
				case CC_BootOperate		:	//Boot操作指令		上面程序已经做相应处理
					break;
				default:	//收到指令
					if(!FrameReRecFlag)
					{	//重发帧，不重复执行
						RecCodeFlag=mTrue;
						RecCodeBuff[0]=CommRecBuff[2];
						RecCodeBuff[1]=CommRecBuff[3];
						RecCodeBuff[2]=CommRecBuff[4];
						RecCodeBuff[3]=CommRecBuff[5];
						RecCodeBuff[4]=CommRecBuff[6];
						RecCodeBuff[5]=CommRecBuff[7];
						RecCodeBuff[6]=CommRecBuff[8];
						RecCodeBuff[7]=CommRecBuff[9];
						RecCodeBuff[8]=CommRecBuff[10];
						RecCodeBuff[9]=CommRecBuff[11];
						RecCodeBuff[10]=CommRecBuff[12];
						RecCodeBuff[11]=CommRecBuff[13];
						RecCodeBuff[12]=CommRecBuff[14];
						RecCodeBuff[13]=CommRecBuff[15];
						RecCodeBuff[14]=CommRecBuff[16];
						RecCodeBuff[15]=CommRecBuff[17];
						RecCodeBuff[16]=CommRecBuff[18];
						RecCodeBuff[17]=CommRecBuff[19];
						RecCodeBuff[18]=CommRecBuff[20];
						RecCodeBuff[19]=CommRecBuff[21];
					}
					Ack_CodeFrame();
			}			
		}
		else
		{	//通讯联机
			switch(CommState)
			{
				case CS_RecManuPara	:	//只响应生产参数加载指令
					if(CommRecBuff[2]==CC_LoadManuPara)
					{
						if((CommRecBuff[3]<<8)+CommRecBuff[4]+(CommRecBuff[5]<<8)+CommRecBuff[6]==mManuParaNum)
							CommState=CS_SendMachPara;			//加载到最未尾的参数，认为完成所有生产参数的加载	系统参数和机器参数合并了，故直接转机器参数通讯
							//CommState=CS_RecSysPara;			//加载到最未尾的参数，认为完成所有生产参数的加载	
						Ack_LoadFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器						
					}
					else
						CommState=CS_LinkErr;	//复位通讯状态，并不返回
					break;
				case CS_SendMachPara:	//只响应机器参数读取指令
					if(CommRecBuff[2]==CC_ReadMachPara)
					{
						if((CommRecBuff[3]<<8)+CommRecBuff[4]+(CommRecBuff[5]<<8)+CommRecBuff[6]==mMachParaNum)
							CommState=CS_SendHardPara;			//加载到最未尾的参数，认为完成所有系统参数的加载
						Ack_ReadFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器						
					}
					else
						CommState=CS_LinkErr;	//复位通讯状态，并不返回
					break;
				case CS_SendHardPara:	//只响应硬件配置读取指令
					if(CommRecBuff[2]==CC_ReadHardConf)
					{
						if((CommRecBuff[3]<<8)+CommRecBuff[4]+(CommRecBuff[5]<<8)+CommRecBuff[6]==mHardConfNum)
							CommState=CS_SendWorkState;			//加载到最未尾的参数，认为完成所有系统参数的加载
						Ack_ReadFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器						
					}
					else
						CommState=CS_LinkErr;	//复位通讯状态，并不返回
					break;
				case CS_SendWorkState:	//只响应状态查询指令
					if(CommRecBuff[2]==CC_ReadWorkState)
					{
						CommState=CS_LinkOK;					//完成联机
						Ack_ReadFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器						
					}
					else
						CommState=CS_LinkErr;	//复位通讯状态，并不返回
					break;
				default:				//只响应复位指令	后加也响应状态读指令
					if(CommRecBuff[2]==CC_LinkRst)
					{
						CommState=CS_RecManuPara;				//准备接收生产参数
						Ack_CodeFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器
					}
					else if(CommRecBuff[2]==CC_ReadWorkState)
					{
						Ack_ReadFrame();						//生成返回帧
						G10msTimerRes(&CommLinkErrTimer);		//复位通讯联机出错定时器
					}
					else
						CommState=CS_LinkErr;	//复位通讯状态，并不返回
			}
		}
	}
	usart_interrupt_enable(USART2, USART_INT_RBNE);	//接收非空中断	
	
	if(!CommLinkOKChk())
	{	//通讯联机未完成
		SetDigiLed(mDC_CommLinkErr);	//显示:通讯联机出错
		//SetAlarm(mAlarm_CommLink);	//警报:通讯联机……	注：界面直接给出
	}
}
/****************************************************************************************************
函数名称：指令帧应答
函数说明：
输入参数：
返 回 值：
其    它：
1、专用于Comm_Drv_Pcs()的返回处理，在本函数的执行过程中，中断已经暂时关闭
2、指令帧应答特点是无数据返回
3、本函数依据CommRecBuff[]的内容生成返回帧，返回帧直接写入到CommSendBuff[]，并启动发送
****************************************************************************************************/
void Ack_CodeFrame(void)
{
	CommSendState=CSS_SendData;			
	UartStartCode();
	
	CommSendBuff[0]=F_StartCode2;
	CommSendBuff[1]=CommLastFrameSN;
	CommSendBuff[2]=1;
	CommSendBuff[3]=~CommRecBuff[2];
	CommSendBuffP=0;	
	CommSendLen=4;	
	EnCommTxInt();	//串口发送使能
}
/****************************************************************************************************
函数名称：加载帧应答
函数说明：
输入参数：
返 回 值：
其    它：
1、专用于Comm_Drv_Pcs()的返回处理，在本函数的执行过程中，中断已经暂时关闭
2、加载帧是指生产、系统、机器或硬件数据加载，它的返回帧内容与指令帧返回内容相同
3、本函数将CommRecBuff[]的内容加载到对应数组，同时生成返回帧，返回帧直接写入到CommSendBuff[]，并启动发送
4、对于单独的电子尺长度机器参数加载，本函数还将电子尺零点也同比例修改并给出一道保存的处理。
5、上面4的处理，要求电子尺长度与零点依序排列，否则出错。
****************************************************************************************************/
void Ack_LoadFrame(void)
{
	U32 * ManuParaLoadP;
	U32 * MachParaLoadP;
	U32 * PeriParaLoadP;
	U16 * HardConfLoadP;
	U32 Len,i;
	
	ParaModifyFlag=mTrue;	//参数有修改
	
	switch(CommRecBuff[2])
	{
		case CC_LoadManuPara:	
			if((CommRecBuff[3]<<8)+CommRecBuff[4]+(CommRecBuff[5]<<8)+CommRecBuff[6]>mManuParaNum)
				return;	//溢出
			ManuParaLoadP=ManuPara+((CommRecBuff[3]<<8)+CommRecBuff[4]);//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];						//加载长度

			//数据加载
			for(i=0;i<Len;i++,ManuParaLoadP++)
				*ManuParaLoadP=(CommRecBuff[10+i*4]<<24)+(CommRecBuff[9+i*4]<<16)+(CommRecBuff[8+i*4]<<8)+CommRecBuff[7+i*4];
			
			ManuParaModifySn=(CommRecBuff[3]<<8)+CommRecBuff[4];	//记录被修改生产参数的起始序号
			ManuParaModifyFlag=mTrue;	//生产参数修改标志
			break;
		case CC_LoadSysPara	:
			/*	系统参数和机器参数合并了，故取消
			if((CommRecBuff[3]<<8)+CommRecBuff[4]+(CommRecBuff[5]<<8)+CommRecBuff[6]>mSysParaNum)
				return;	//溢出
			SysParaLoadP=SysPara+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];						//加载长度

			//数据加载
			for(i=0;i<Len;i++,SysParaLoadP++)
				*SysParaLoadP=(CommRecBuff[10+i*4]<<24)+(CommRecBuff[9+i*4]<<16)+(CommRecBuff[8+i*4]<<8)+CommRecBuff[7+i*4];
			
			SysParaModifyFlag=mTrue;	//系统参数修改标志	*/
			break;
		case CC_LoadMachPara:	
			{	//应在非自动方式下，才允许修改，但是此处不做检查，由界面保证;另界面还要保证下载帧之间有足够的写入时间，否则可能写入不完全
				//界面程序：回读后才会发下一加载帧，长帧回读延时时间500ms
				if(MachParaSave.StartSN+MachParaSave.Len>mMachParaNum)
					return;	//溢出

				MachParaSave.UpdateFlag=mTrue;
				MachParaSave.StartSN=(CommRecBuff[3]<<8)+CommRecBuff[4];
				MachParaSave.Len=(CommRecBuff[5]<<8)+CommRecBuff[6];
				
				MachParaLoadP=MachPara+MachParaSave.StartSN;	//加载首地址
				Len=MachParaSave.Len;							//加载长度
				
				//数据加载
				for(i=0;i<Len;i++,MachParaLoadP++)
					*MachParaLoadP=(CommRecBuff[10+i*4]<<24)+(CommRecBuff[9+i*4]<<16)+(CommRecBuff[8+i*4]<<8)+CommRecBuff[7+i*4];
				
				/*改由指令CC_SnrSetLen进行长度校准
				if((Len==1)&&
				   ((MachParaSave.StartSN==mPara_EjeLen)||
			        (MachParaSave.StartSN==mPara_ScrewLen)||	
			        (MachParaSave.StartSN==mPara_MoldLen)||	
			        (MachParaSave.StartSN==mPara_NozLen)))
			    {	//单独的电子尺长度修改:零点也同比例修改
			    	Temp=(CommRecBuff[7]<<8)+CommRecBuff[8];
			    	Temp=(unsigned long)MachPara[MachParaSave.StartSN+1]*Temp/MachPara[MachParaSave.StartSN];
			    	CommRecBuff[9]=Temp>>8;		//将调整后的电子尺零点写入接收缓存，由下面的程序拷到MachPara[xxxZero]中
			    	CommRecBuff[10]=Temp&0xff;
			    	Len++;						//长度加1,以便零点保存到EEPROM
			    	MachParaSave.Len++;
			    }*/
			}
			
			MachParaModifyFlag=mTrue;	//机器参数修改标志
			break;
		case CC_LoadPeriPara:	
			//应在非自动方式下，才允许修改，但是此处不做检查，由界面保证;另界面还要保证下载帧之间有足够的写入时间，否则可能写入不完全
				//界面程序：回读后才会发下一加载帧，长帧回读延时时间500ms
				if(PeriParaSave.StartSN+PeriParaSave.Len>mPeriParaNum)
					return;	//溢出

				PeriParaSave.UpdateFlag=mTrue;
				PeriParaSave.StartSN=(CommRecBuff[3]<<8)+CommRecBuff[4];
				PeriParaSave.Len=(CommRecBuff[5]<<8)+CommRecBuff[6];
				
				PeriParaLoadP=PeriPara+PeriParaSave.StartSN;	//加载首地址
				Len=PeriParaSave.Len;							//加载长度
				
				PeriParaWriteReq.Sn	=(CommRecBuff[3]<<8)+CommRecBuff[4];
				PeriParaWriteReq.Data=(CommRecBuff[10]<<24)+(CommRecBuff[9]<<16)+(CommRecBuff[8]<<8)+CommRecBuff[7];	
				//数据加载
				for(i=0;i<Len;i++,PeriParaLoadP++)
					*PeriParaLoadP=(CommRecBuff[10+i*4]<<24)+(CommRecBuff[9+i*4]<<16)+(CommRecBuff[8+i*4]<<8)+CommRecBuff[7+i*4];	
					
			PeriParaModifyFlag=mTrue;	//机器参数修改标志
			break;
		case CC_LoadHardConf:	
			{	//应在非自动方式下，才允许修改，但是此处不做检查，由界面保证;另界面还要保证下载帧之间有足够的写入时间，否则可能写入不完全
				if(HardConfSave.StartSN+HardConfSave.Len>mHardConfNum)
					return;	//溢出

				HardConfSave.UpdateFlag=mTrue;
				HardConfSave.StartSN=(CommRecBuff[3]<<8)+CommRecBuff[4];
				HardConfSave.Len=(CommRecBuff[5]<<8)+CommRecBuff[6];
				
				HardConfLoadP=HardConf+HardConfSave.StartSN;	//加载首地址
				Len=HardConfSave.Len;							//加载长度

				//数据加载
				for(i=0;i<Len;i++,HardConfLoadP++)
					*HardConfLoadP=(CommRecBuff[8+i*2]<<8)+CommRecBuff[7+i*2];
			}
		
			HardConfModifyFlag=mTrue;	//硬件配置修改标志
			break;
		default:
			return;
	}	
	
	//生成返回帧
	Ack_CodeFrame();
}
/****************************************************************************************************
函数名称：读取帧应答
函数说明：
输入参数：
返 回 值：
其    它：
1、专用于Comm_Drv_Pcs()的返回处理，在本函数的执行过程中，中断已经暂时关闭
2、读取帧是指状态、机器或硬件数据读取
3、本函数依据CommRecBuff[]的内容生成返回帧，返回帧直接写入到CommSendBuff[]，并启动发送
****************************************************************************************************/
void Ack_ReadFrame(void)
{
	U16 * HardConfReadP;	
	U16 * WorkStateReadP;
	U32 * MachParaReadP;
	U32 * ManuParaReadP;
	U32 * PeriParaReadP;
	U32 Len,i,LenWave;
	
	switch(CommRecBuff[2])
	{
		case CC_ReadWorkState:
			if(((CommRecBuff[3]<<8)+CommRecBuff[4])+(CommRecBuff[5]<<8)+CommRecBuff[6]>mWorkStateNum)
				return;	//溢出
			WorkStateReadP=WorkState+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度

			if(Len*2>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*2+1);
			CommSendBuff[2]=GetU8_L1(Len*2+1);
			CommSendBuff[3]=~CommRecBuff[2];
		
			for(i=0;i<Len;i++,WorkStateReadP++)
			{
				CommSendBuff[4+i*2]=GetU8_L1(*WorkStateReadP);
				CommSendBuff[5+i*2]=GetU8_L2(*WorkStateReadP);
			}	
			CommSendBuffP=0;	
			CommSendLen=4+Len*2;	
			EnCommTxInt();	//串口发送使能
			
			WorkStateReadFlag=mTrue;	//工作状态被读走		20210608加：蒙德多个驱动器时，状态轮流经WorkState[]返回，所以用到
			break;			
		case CC_ReadMachPara:
			if(((CommRecBuff[3]<<8)+CommRecBuff[4])+(CommRecBuff[5]<<8)+CommRecBuff[6]>mMachParaNum)
				return;	//溢出
			MachParaReadP=MachPara+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度

			if(Len*4>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*4+1);
			CommSendBuff[2]=GetU8_L1(Len*4+1);
			CommSendBuff[3]=~CommRecBuff[2];
		
			for(i=0;i<Len;i++,MachParaReadP++)
			{
				CommSendBuff[4+i*4]=GetU8_L1(*MachParaReadP);
				CommSendBuff[5+i*4]=GetU8_L2(*MachParaReadP);
				CommSendBuff[6+i*4]=GetU8_L3(*MachParaReadP);
				CommSendBuff[7+i*4]=GetU8_L4(*MachParaReadP);
			}	
			CommSendBuffP=0;	
			CommSendLen=4+Len*4;	
			EnCommTxInt();	//串口发送使能
			break;		
		case CC_ReadManuPara:	
			if(((CommRecBuff[3]<<8)+CommRecBuff[4])+(CommRecBuff[5]<<8)+CommRecBuff[6]>mManuParaNum)
				return;	//溢出
			ManuParaReadP=ManuPara+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度

			if(Len*4>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*4+1);
			CommSendBuff[2]=GetU8_L1(Len*4+1);
			CommSendBuff[3]=~CommRecBuff[2];
		
			for(i=0;i<Len;i++,ManuParaReadP++)
			{
				CommSendBuff[4+i*4]=GetU8_L1(*ManuParaReadP);
				CommSendBuff[5+i*4]=GetU8_L2(*ManuParaReadP);
				CommSendBuff[6+i*4]=GetU8_L3(*ManuParaReadP);
				CommSendBuff[7+i*4]=GetU8_L4(*ManuParaReadP);
			}	
			CommSendBuffP=0;	
			CommSendLen=4+Len*4;	
			EnCommTxInt();	//串口发送使能
			break;		
		case CC_ReadHardConf:
			if(((CommRecBuff[3]<<8)+CommRecBuff[4])+(CommRecBuff[5]<<8)+CommRecBuff[6]>mHardConfNum)
				return;	//溢出
			HardConfReadP=HardConf+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度

			if(Len*2>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*2+1);
			CommSendBuff[2]=GetU8_L1(Len*2+1);
			CommSendBuff[3]=~CommRecBuff[2];
		
			for(i=0;i<Len;i++,HardConfReadP++)
			{
				CommSendBuff[4+i*2]=GetU8_L1(*HardConfReadP);
				CommSendBuff[5+i*2]=GetU8_L2(*HardConfReadP);
			}	
			CommSendBuffP=0;	
			CommSendLen=4+Len*2;	
			EnCommTxInt();	//串口发送使能
			break;	
		case CC_ReadPeriPara:
			if(((CommRecBuff[3]<<8)+CommRecBuff[4])+(CommRecBuff[5]<<8)+CommRecBuff[6]>mPeriParaNum)
				return;	//溢出
			PeriParaReadP=PeriPara+((CommRecBuff[3]<<8)+CommRecBuff[4]);	//加载首地址
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度

			if(Len*4>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*4+1);
			CommSendBuff[2]=GetU8_L1(Len*4+1);
			CommSendBuff[3]=~CommRecBuff[2];
		
			for(i=0;i<Len;i++,PeriParaReadP++)
			{
				CommSendBuff[4+i*4]=GetU8_L1(*PeriParaReadP);
				CommSendBuff[5+i*4]=GetU8_L2(*PeriParaReadP);
				CommSendBuff[6+i*4]=GetU8_L3(*PeriParaReadP);
				CommSendBuff[7+i*4]=GetU8_L4(*PeriParaReadP);
			}	
			CommSendBuffP=0;	
			CommSendLen=4+Len*4;	
			EnCommTxInt();	//串口发送使能
			break;	
		case CC_ReadGivenPeriPara://20191231 读取指定外设参数 //参数个数,参数0index,参数1index,...参数63index
			if((CommRecBuff[5]<<8)+CommRecBuff[6]>mPeriParaReadMax)//一次最多读64个参数
				return;	//溢出
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度
			//SetJ6hMenuMap(Len,&CommRecBuff[7]);
			for(i=0;i<Len;i++)
				PeriParaReadReq.Sn[i]=(CommRecBuff[7+i*2]<<8)+CommRecBuff[7+1+i*2];
			PeriParaReadReq.Sn[i]=0;	//以0为结束标志
			//生成返回帧
			CommSendState=CSS_SendData;			
			UartStartCode();
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*4+1);
			CommSendBuff[2]=GetU8_L1(Len*4+1);
			CommSendBuff[3]=~CommRecBuff[2];
			//GetJ6hMenuPara(Len,&CommSendBuff[4]);	
			for(i=0;i<Len;i++)
			{
				CommSendBuff[4+i*4]=GetU8_L1(PeriPara[PeriParaReadReq.Sn[i]]);
				CommSendBuff[5+i*4]=GetU8_L2(PeriPara[PeriParaReadReq.Sn[i]]);
				CommSendBuff[6+i*4]=GetU8_L3(PeriPara[PeriParaReadReq.Sn[i]]);
				CommSendBuff[7+i*4]=GetU8_L4(PeriPara[PeriParaReadReq.Sn[i]]);
			}
			CommSendBuffP=0;
			CommSendLen=4+Len*4;
			EnCommTxInt();	//串口发送使能
			break;
		case CC_ReadWavePara:
			Len=(CommRecBuff[5]<<8)+CommRecBuff[6];							//加载长度
			if(Len*2>mSendFrameLenMax)
				return;					//返回长度超限	最多512byte
			//生成返回帧
			LenWave = ((WaveParaEnd - WaveParaStart) & mWaveParaMask);			
			CommSendState=CSS_SendData;			
			UartStartCode();			
			CommSendBuff[0]=F_StartCode2;
			CommSendBuff[1]=CommLastFrameSN+GetU8_L2(Len*2+1);
			CommSendBuff[2]=GetU8_L1(Len*2+1);
			CommSendBuff[3]=~CommRecBuff[2];
			CommSendBuff[4]=GetU8_L1(WaveParaStart);
			CommSendBuff[5]=(GetU8_L2(WaveParaStart)) | ((State_WaveDataAttr&(mBit15|mBit14))>>8);//数据起始地址最大使用11位，波形属性的15-14位放在数据起始地址高2位传给界面	20210926改
			i=0;
			if(WaveNum > 0)
			{																											//每次发送都是完整组数波形
				if(((Len-2)-((Len-2)%WaveNum)) < LenWave) 	LenWave = ((Len-2)-((Len-2)%WaveNum));
				for(i=0;i<LenWave;i++)
					{
						WaveParaStart = (WaveParaStart+1) & mWaveParaMask;
						CommSendBuff[10+i*2]=GetU8_L1(WaveParaBuff[WaveParaStart]);
						CommSendBuff[11+i*2]=GetU8_L2(WaveParaBuff[WaveParaStart]);	
					}			
			}
			CommSendBuff[6]=GetU8_L1(WaveParaStart);
			CommSendBuff[7]=GetU8_L2(WaveParaStart);
			CommSendBuff[8]=WaveCurTrigModeSave;	//当前波形实际触发模式
			CommSendBuff[9]=0;					//当这个字节暂时保留
			for(;i<Len-2;i++)
			{					
				CommSendBuff[10+i*2]=0x0;
				CommSendBuff[11+i*2]=0x0;	
			}

			CommSendBuffP=0;	
			CommSendLen=4+Len*2;	
            EnCommTxInt();	//串口发送使能
			break;				
			
		default:
			return;
	}
}
/****************************************************************************************************
函数名称：通讯联机正常检查
函数说明：
输入参数：
返 回 值：True--联机正常	False--尚未联机
其    它：
****************************************************************************************************/
Bool CommLinkOKChk(void)
{
	return(CommState==CS_LinkOK);
}
/****************************************************************************************************
函数名称：参数修改标志
函数说明：
输入参数：
返 回 值：True--有修改
其    它：
1、收到生产参数、系统参数、机器参数或资源修改时给出。
2、类似中子处理函数中引用，根据该标志对某些变量进行更新，以降低执行时间占用
****************************************************************************************************/
Bool ParaIsModify(void)
{
	return(ParaModifyFlag);
}
Bool ManuParaIsModify(void)
{
	return(ManuParaModifyFlag);
}
Bool MachParaIsModify(void)
{
	return(MachParaModifyFlag);
}
Bool PeriParaIsModify(void)
{
	return(PeriParaModifyFlag);
}
Bool SysParaIsModify(void)
{
	return(SysParaModifyFlag);
}
Bool HardConfIsModify(void)
{
	return(HardConfModifyFlag);
}
Bool WorkStateIsRead(void)
{
	return(WorkStateReadFlag);	//工作状态被读走		20210608加：蒙德多个驱动器时，状态轮流经WorkState[]返回，所以用到
}

U32 GetManuParaModifySn(void)
{	return ManuParaModifySn;
}
/****************************************************************************************************
函数名称：获取通讯接收命令
函数说明：
输入参数：
返 回 值：0x00-无命令
其    它：
****************************************************************************************************/
U8 GetCommRecCode(void)
{
	if(RecCodeFlag)		return RecCodeBuff[0];
	else				return 0x00;
}
/****************************************************************************************************
函数名称：获取通讯接收命令参数0
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara0(void)
{
	return RecCodeBuff[1];
}
/****************************************************************************************************
函数名称：获取通讯接收命令参数1
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara1(void)
{
	return RecCodeBuff[2];
}
/****************************************************************************************************
函数名称：获取通讯接收命令参数2
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara2(void)
{
	return RecCodeBuff[3];
}
/****************************************************************************************************
函数名称：获取通讯接收命令参数3
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara3(void)
{
	return RecCodeBuff[4];
}
/****************************************************************************************************
函数名称：获取通讯接收命令参数4
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara4(void)
{
	return RecCodeBuff[5];
}
/****************************************************************************************************
函数名称：获取通讯接收命令第N个参数
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
U8 GetCommRecCodePara_SN(U32 SN)
{
	return RecCodeBuff[SN+1];
}
/****************************************************************************************************
函数名称：通讯接收中断处理
函数说明：
输入参数：
返 回 值：
其    它：
1、帧在CommRecBuff[]中存放格式：
序号----       0               1          2             3     	4    5     6    7
内容----帧序号和长度高2位、帧长度低8位、功能码、参数（AddrH、AddrL、LenH、LenL、D1……）
****************************************************************************************************/
void CommRecIRQPcs(void)
{
	U8 RecData;

	RecData=(U8)usart_data_receive(USART2);

	if(CommRecState==CRS_RecDisable)						//禁止接收检查：禁止则退出
		return;						
	if(G10msTimerOver(&CommRecBrkTimer,mCommRecBrkTime))	//接收超时检查：起时则复位帧接收
		CommRecState=CRS_FrameStart1;	
	G10msTimerRes(&CommRecBrkTimer);						//复位超时检查计时器
	
	switch(CommRecState)
	{
		case CRS_FrameStart1:	//帧起始符接收
			if(RecData==F_StartCode1)
				CommRecState=CRS_FrameStart2;
			break;
		case CRS_FrameStart2:	//帧起始符接收
			if(RecData==F_StartCode2)
				CommRecState=CRS_FrameSN;
			else						//起始符2出错：复位帧接收，并重新同步
				CommRecState=(RecData==F_StartCode1)?CRS_FrameStart2:CRS_FrameStart1;
			break;
		case CRS_FrameSN:		//帧序号和长度高4位接收
			CommRecState=CRS_FrameLen;
			CommRecBuff[0]=RecData;
			//CommRecBuffP;
			CommRecCRC=Cal_CRC(RecData,0);	
			//CRC->INIT = 0;
			//*(uint8_t *)(void *)(&CRC->DR) = RecData;
			break;
		case CRS_FrameLen:		//帧长度接收
			CommRecState=CRS_FrameData;
			
			CommRecBuff[1]=RecData;
			CommRecBuffP=2;
			CommRecCRC=Cal_CRC(RecData,CommRecCRC);
			//*(uint8_t *)(void *)(&CRC->DR) = RecData;
			CommRecLen=((CommRecBuff[0]&0x0f)<<8)+RecData;
			
			if(CommRecLen>mRecFrameLenmax+5)
				CommRecState=(RecData==F_StartCode1)?CRS_FrameStart2:CRS_FrameStart1;
			break;
		case CRS_FrameData:		//帧数据接收
			CommRecBuff[CommRecBuffP]=RecData;
			CommRecBuffP++;
			CommRecCRC=Cal_CRC(RecData,CommRecCRC);
			//*(uint8_t *)(void *)(&CRC->DR) = RecData;
			if(CommRecBuffP>=CommRecLen+2)//数据接收完毕检查：转CRC
				CommRecState=CRS_FrameCRC1;
			break;
		case CRS_FrameCRC1:		//帧CRC高字节接收
			CommRecState=CRS_FrameCRC2;

			CommRecBuff[CommRecBuffP]=RecData;
			//CommRecBuffP;
			//CommRecCRC;
			//CommRecCRC = (U16)CRC->DR;
			break;
		case CRS_FrameCRC2:		//帧CRC低字节接收
			if((RecData==(CommRecCRC&0xff))&&(CommRecBuff[CommRecBuffP]==(CommRecCRC>>8)))
			{	//CRC校验正确：给出帧接收标志并禁止接收
				CommRecState=CRS_RecDisable;	
				CommFrameRecFlag=mTrue;
			}
			else
			{	//CRC校验失败：不做任何返回
				CommRecState=(RecData==F_StartCode1)?CRS_FrameStart2:CRS_FrameStart1;
			}
	}	
}
/****************************************************************************************************
函数名称：通讯发送中断处理
函数说明：
输入参数：
返 回 值：
其    它：
1、帧在CommSendBuff[]中存放格式：
序号----   0          1                 2         3      4
内容----起始符2	帧序号和长度高2位、帧长度低8位、功能码、D1……
****************************************************************************************************/
void CommSendIRQPcs(void)
{
	U8 SendData;
	
	SendData=CommSendBuff[CommSendBuffP];
	CommSendBuffP++;
	
	switch(CommSendState)
	{
		case CSS_SendData:	//发送数据
			usart_data_transmit(USART2, SendData);
			if(CommSendBuffP==1)
			{
				CommSendCRC=0;
				//CRC->INIT=0;
			}
			else
			{
				CommSendCRC=Cal_CRC(SendData,CommSendCRC);
				//*(uint8_t *)(void *)(&CRC->DR) = SendData;
				if(CommSendBuffP>=CommSendLen)
				{
					CommSendState=CSS_SendCRC1;
					//CommSendCRC = (U16)CRC->DR;
				}
			}
			break;		
		case CSS_SendCRC1:	//CRC高字节
			usart_data_transmit(USART2, CommSendCRC>>8);
			CommSendState=CSS_SendCRC2;
			break;
		case CSS_SendCRC2:	//CRC低字节
			usart_data_transmit(USART2, CommSendCRC&0xff);
			CommSendState=CSS_SendDisable;
			break;
		default:			//不发送
			DisCommTxInt();
	}
}

/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
/****************************************************************************************************
函数名称：通讯驱动初始化
函数说明：
输入参数：
返 回 值：
其    它：
1、使用Pd8/TXD0和Pd9/RXD0
2、UART3：57600bps、奇校验、8位数据、1位停止
3、开启RDA和THRE两中断
4、USART3的时钟为APB1,即50M。APB1为50M，APB2为100M。
****************************************************************************************************/
void Comm_Drv_Init(void)
{
	//通讯变量
	G10msTimerRes(&CommLinkErrTimer); 
	
	//管脚
 	rcu_periph_clock_enable(RCU_GPIOD); 	//使能PORTA口时钟  
	rcu_periph_clock_enable(RCU_USART2);  	//使能串口2时钟 
	//GPIO_Set(GPIOD,mBit8|mBit9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_50M,GPIO_PUPD_PU);//PD8,PD9,复用功能,上拉输出
 	gpio_af_set(GPIOD, GPIO_AF_7,GPIO_PIN_8);	//PD8,AF7	Tx
 	gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
 	gpio_mode_set(GPIOD, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_8);
	gpio_af_set(GPIOD, GPIO_AF_7,GPIO_PIN_9);	//PD9,AF7  Rx
	gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
 	gpio_mode_set(GPIOD, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
 	
	//UART0相关	波特率设置
 	usart_deinit(USART2);
    usart_baudrate_set(USART2,mComm_BPS);
    usart_parity_config(USART2,USART_PM_ODD);
    usart_word_length_set(USART2,USART_WL_9BIT);
    usart_receive_config(USART2, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART2, USART_TRANSMIT_ENABLE);
    usart_enable(USART2);

	//使能接收中断 
    nvic_irq_enable(USART2_IRQn, 0, 0);
	usart_interrupt_enable(USART2, USART_INT_RBNE);	//接收非受中断
    usart_interrupt_enable(USART2, USART_INT_TBE);	//发送为空中断
    usart_interrupt_enable(USART2, USART_INT_PERR);	//奇偶校验错误中断
	//CRC_CCITT_init();
}
/****************************************************************************************************
函数名称：UART0中断
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void USART2_IRQHandler(void)
{
	if((0 != usart_flag_get(USART2, USART_FLAG_TBE)) && 
       (0 != usart_interrupt_flag_get(USART2, USART_INT_FLAG_TBE)))
	{	//发送中断		
		CommSendIRQPcs();
	}
	if((0 != usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE)) && 
       (0 != usart_flag_get(USART2, USART_FLAG_RBNE)))
	{	//接收中断		
		CommRecIRQPcs();
	}	
	if((0 != usart_interrupt_flag_get(USART2, USART_INT_FLAG_PERR)) && 
       (0 != usart_flag_get(USART2, USART_FLAG_PERR)))
	{	//奇偶校验错误		
		CommRecState=CRS_FrameStart1;
        usart_data_receive(USART2);
	}	
}

