/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：DIDO_Drv.c
文件说明：T6F5硬件平台中数字IO信号处理。

作    者：WLZ
编写时间：2025.4
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
##系统资源
1、模拟总线：		
	//CPLD DI
	//0x00C～0x010	R	DI寄存器
	//0x013			R	计数器0				5位（有效4位）、双向计数（上升沿和下降沿均计数）		调模电眼
	//0x014			R	计数器1				5位（有效4位）、双向计数（上升沿和下降沿均计数）		储料电眼
	//0x015			RW	触发器				Bit0:对应X18		Bit1:对应X29

	//CPLD DO
	//0x0001		W	DO输出寄存器0
	//0x0002		W	DO输出寄存器1
	//0x0003		W	DO输出寄存器2
	//0x0004		W	DO输出寄存器3
	//0x0005		W	DO输出寄存器4
	//0x0006		W	DO输出寄存器5
	//0x0007		W	DO输出寄存器6
	//0x0008		W	IO电源保护复位	即状态Bit0位复位
	//0x0008		R	IO电源状态		Bit1:电源正常标志(0-正常、1-异常)		Bit0:输出禁止标志(1-禁止、0-允许)
	
	//CPLD OTH
	//0x0016		W	继电器输出寄存器0
	//0x0017		W	继电器输出寄存器1
   
   上述地址在SimBus_Drv.h定义。

##其它说明
输入信号
1、每隔1ms进行一次读入，并与最近2个读入值进行3取2滤波。如果有变化，则更新到对应资源，否则隔20ms更新一次。
2、固定按照T6F5的最大配置进行扫描。对于DI点减少的简化T6F5，此驱动同样适用（HardConf硬件配置中减少的点定义
   为mRI_Null即可），但略浪费主循环时间。
3、驱动中输入点定义0-47共48个，对应硬件配置HardConf[mHSN_DI+0～47]。

输出信号
3、如果BIT型输出资源变量有变化，立即进行一次DO更新，否则以3ms为周期进行输出更新。（此设计提高输出实时性）
4、MOS类型输出定义0-47、Relay输出定义48-63，HardConf[mHSN_DO+0～64]。
5、固定按照T6F5的最大配置输出更新。对于DO点减少的简化T6F5，此驱动同样适用（HardConf硬件配置中减少的点定义
   为mRO_Null即可），但略浪费主循环时间。

6、无论输入信号、输出信号，均在主循环进行处理。（原T6F2在中断中进行）

电源状态
1、电源标志Bit1(0-正常)	输出禁止标志Bit0(1-禁止)			
	0					0						正    常----电源正常、无保护
	0					1						短路保护----出现过短路，保护了，电源已经恢复正常，保护还有效
	1					0						电源异常----未加电或电压严重低（正常不应出现的状态组合）
	1					1						电源异常----未加电或电压严重低
				
****************************************************************************************************/
//#define mSysDebug		

#ifndef DIDO_Drv_c
	#define DIDO_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define	DIDOPwrProtRst() SB_WriteData(mSBA_DIDOPwrProtRst,0)	//阀电源保护复位


/*======================================= 模块内有效变量定义 ======================================*/
struct 
{
	U8 Mode;		//模式				0-退出	1-普通	2-高级
	U8 DOHardSN;	//强制输出点		指硬件上的通道序号，从0开始
	U8 DIHardSN;	//强制输入点		指硬件上的通道序号，从0开始
	
	U8 CanModSN;		//强制输出的CAN模块序号			以下两个参数供CanModule_Drv.c强制输出使用，这里图省事之故
	U8 CanModDOHardSN;	//CAN模块强制输出点
}IODebug;	//IO调试

//高级调试模式指：1)强制输出时，马达可以开着，并且还可以进行动作，此时强制输出点和动作一起有效，主要是方便
//				   检修以及蓄能器等特殊调试
//				 2)还可以强制输入，即将某输入点虚拟短路，也是方便检修
//               3)与Code.c配合可以实现高级调试功能，主要是在动作时不去复位IODebug结构即可。
//				 4)该调试有较大危险，不提供。替代方案是针对部分常用的特殊调试（如蓄能器、背压调试），提供
//				   专用指令。


Bool ScrewRPMSnrState;	//螺杆转速电眼状态		用于软件计数
Bool MoldAdjSnrState;	//调模电眼状态
U8   ProdSnrState;		//检物电眼状态
	#define mPSS_Rst		0	//复位
	#define mPSS_Tri		1	//触发
	#define mPSS_WaitRst	2	//等待真正复位		即已经清除、但要等到输入点也变0，才算真正清除
	
G10usTimer DbgModeTimer;//调试模式计时			用于时间到自动结束调试模式，IODebug、DADebug共用

/*======================================= 模块内有效函数声明 ======================================*/


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
函数名称：
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/


/****************************************************************************************************
函数名称：DIDO驱动初始化
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void DIDO_Drv_Init(void)		
{
	DIDOPwrProtRst();	//阀电源保护复位
}
/****************************************************************************************************
函数名称：DIDO驱动处理
函数说明：
输入参数：
返 回 值：
其    它：
1)本函数由主循环调用。
2)
****************************************************************************************************/
#define mDIChkTime		100		//DI检查时间		100*10us	1ms
#define mDIUpdateTime	2000	//DI更新时间		2000*10us	20ms
#define	mDINum			64		//DI输入点数

#define mDOUpdateTime	300		//DO更新时间		300*10us	3ms
#define mCntChkTime		200		//Cnt检查时间		200*10us	2ms

#define mPwrOnPwrChkDlyTime		300000		//开机电源检查延时时间		300000*10us		3s

void DIDO_Drv_Pcs(void)
{
	static G10usTimer DITimer;					//DI检查定时器			检查是否有输入
	static G10usTimer DIUpdateTimer[mDINum/8];	//DI更新定时器			更新到变量
	static U8 DIBuff[mDINum/8][3];				//DI缓存
	static U8 DILastSta[mDINum/8];				//DI上一次更新时状态
	
	//static G10usTimer DOTimer;				//DO定时器				更新到输出
	static G10usTimer CntTimer;					//Cnt定时器			
	U8 InBuff,OutBuff;
	
	static U8 LastCnt1,LastCnt2;				//计数上一次值
	U8 Cnt,Buff;
	
	static Bool PwrErrFlag=mFalse;				//电源异常标志
	static G10usTimer PwrErrFiltTimer;			//电源异常滤波计时器
	
	static G10usTimer PwrOnPwrChkDlyTimer;		//开机电源检查延时	
	static U8 PwrOnPwrChkStep=0;				//开机时电源检查步骤
		#define mPOPCS_Init		0	//刚开始，复位计时
		#define mPOPCS_Dly		1	//延时
		#define mPOPCS_Chk		2	//检查
	
	//DI处理	
	if(G10usTimerOver(&DITimer,mDIChkTime))
	{	//检查时间到		1ms
		G10usTimerRes(&DITimer);
		
		//检查0-7
		if(HardConf_DINum>0)
		{
			DIBuff[0][0]=DIBuff[0][1],	DIBuff[0][1]=DIBuff[0][2],	DIBuff[0][2]=SB_ReadData(mSBA_DIInReg0);	//通道0
			InBuff=((DIBuff[0][0]^DIBuff[0][1])&DIBuff[0][2])|(DIBuff[0][0]&DIBuff[0][1]);						//3取2滤波
			if((InBuff!=DILastSta[0])||G10usTimerOver(&DIUpdateTimer[0],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[0]);						//复位更新计时
				DILastSta[0]=InBuff;
				State_DIn01_16=(State_DIn01_16&0xff00)|InBuff;			//反映到输入状态
																
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI01);			//光隔输入		IN01
				else					RstResBit(Hard_DI01);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI02);		
				else					RstResBit(Hard_DI02);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI03);		
				else					RstResBit(Hard_DI03);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI04);		
				else					RstResBit(Hard_DI04);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI05);		
				else					RstResBit(Hard_DI05);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI06);		
				else					RstResBit(Hard_DI06);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI07);		
				else					RstResBit(Hard_DI07);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI08);		
				else					RstResBit(Hard_DI08);	
			}
		}
		//检查8-15
		if(HardConf_DINum>8)
		{
			DIBuff[1][0]=DIBuff[1][1],	DIBuff[1][1]=DIBuff[1][2],	DIBuff[1][2]=SB_ReadData(mSBA_DIInReg1);	//通道1
			InBuff=((DIBuff[1][0]^DIBuff[1][1])&DIBuff[1][2])|(DIBuff[1][0]&DIBuff[1][1]);						//3取2滤波
			if((InBuff!=DILastSta[1])||G10usTimerOver(&DIUpdateTimer[1],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[1]);						//复位更新计时
				DILastSta[1]=InBuff;
				State_DIn01_16=(State_DIn01_16&0x00ff)|(InBuff<<8);		//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI09);			//光隔输入		IN09
				else					RstResBit(Hard_DI09);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI10);		
				else					RstResBit(Hard_DI10);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI11);		
				else					RstResBit(Hard_DI11);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI12);		
				else					RstResBit(Hard_DI12);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI13);		
				else					RstResBit(Hard_DI13);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI14);		
				else					RstResBit(Hard_DI14);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI15);		
				else					RstResBit(Hard_DI15);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI16);		
				else					RstResBit(Hard_DI16);			
			}
		}		
		//检查16-23
		if(HardConf_DINum>16)
		{
			DIBuff[2][0]=DIBuff[2][1],	DIBuff[2][1]=DIBuff[2][2],	DIBuff[2][2]=SB_ReadData(mSBA_DIInReg2);	//通道2
			InBuff=((DIBuff[2][0]^DIBuff[2][1])&DIBuff[2][2])|(DIBuff[2][0]&DIBuff[2][1]);						//3取2滤波
			if((InBuff!=DILastSta[2])||G10usTimerOver(&DIUpdateTimer[2],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[2]);						//复位更新计时
				DILastSta[2]=InBuff;
				State_DIn17_32=(State_DIn17_32&0xff00)|InBuff;			//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI17);			//光隔输入		IN17
				else					RstResBit(Hard_DI17);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI18);		
				else					RstResBit(Hard_DI18);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI19);		
				else					RstResBit(Hard_DI19);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI20);		
				else					RstResBit(Hard_DI20);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI21);		
				else					RstResBit(Hard_DI21);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI22);		
				else					RstResBit(Hard_DI22);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI23);		
				else					RstResBit(Hard_DI23);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI24);		
				else					RstResBit(Hard_DI24);			
			}	
		}	
		//检查24-31
		if(HardConf_DINum>24)
		{
			DIBuff[3][0]=DIBuff[3][1],	DIBuff[3][1]=DIBuff[3][2],	DIBuff[3][2]=SB_ReadData(mSBA_DIInReg3);	//通道3
			InBuff=((DIBuff[3][0]^DIBuff[3][1])&DIBuff[3][2])|(DIBuff[3][0]&DIBuff[3][1]);						//3取2滤波
			if((InBuff!=DILastSta[3])||G10usTimerOver(&DIUpdateTimer[3],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[3]);						//复位更新计时
				DILastSta[3]=InBuff;
				State_DIn17_32=(State_DIn17_32&0x00ff)|(InBuff<<8);		//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI25);			//光隔输入		IN25
				else					RstResBit(Hard_DI25);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI26);		
				else					RstResBit(Hard_DI26);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI27);		
				else					RstResBit(Hard_DI27);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI28);		
				else					RstResBit(Hard_DI28);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI29);		
				else					RstResBit(Hard_DI29);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI30);		
				else					RstResBit(Hard_DI30);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI31);		
				else					RstResBit(Hard_DI31);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI32);		
				else					RstResBit(Hard_DI32);			
			}
		}
		//检查32-39
		if(HardConf_DINum>32)
		{
			DIBuff[4][0]=DIBuff[4][1],	DIBuff[4][1]=DIBuff[4][2],	DIBuff[4][2]=SB_ReadData(mSBA_DIInReg4);	//通道4
			InBuff=((DIBuff[4][0]^DIBuff[4][1])&DIBuff[4][2])|(DIBuff[4][0]&DIBuff[4][1]);						//3取2滤波
			if((InBuff!=DILastSta[4])||G10usTimerOver(&DIUpdateTimer[4],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[4]);						//复位更新计时
				DILastSta[4]=InBuff;
				State_DIn33_48=(State_DIn33_48&0xff00)|InBuff;			//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI33);			//光隔输入		IN33
				else					RstResBit(Hard_DI33);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI34);		
				else					RstResBit(Hard_DI34);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI35);		
				else					RstResBit(Hard_DI35);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI36);		
				else					RstResBit(Hard_DI36);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI37);		
				else					RstResBit(Hard_DI37);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI38);		
				else					RstResBit(Hard_DI38);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI39);		
				else					RstResBit(Hard_DI39);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI40);		
				else					RstResBit(Hard_DI40);			
			}
		}
		//检查40-47
		/*if(HardConf_DINum>40)
		{
			DIBuff[5][0]=DIBuff[5][1],	DIBuff[5][1]=DIBuff[5][2],	DIBuff[5][2]=SB_ReadData(mSBA_DIInReg5);	//通道5
			InBuff=((DIBuff[5][0]^DIBuff[5][1])&DIBuff[5][2])|(DIBuff[5][0]&DIBuff[5][1]);						//3取2滤波
			if((InBuff!=DILastSta[5])||G10usTimerOver(&DIUpdateTimer[5],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[5]);						//复位更新计时
				DILastSta[5]=InBuff;
				State_DIn33_48=(State_DIn33_48&0x00ff)|(InBuff<<8);		//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI41);			//光隔输入		IN41
				else					RstResBit(Hard_DI41);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI42);		
				else					RstResBit(Hard_DI42);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI43);		
				else					RstResBit(Hard_DI43);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI44);		
				else					RstResBit(Hard_DI44);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI45);		
				else					RstResBit(Hard_DI45);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI46);		
				else					RstResBit(Hard_DI46);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI47);		
				else					RstResBit(Hard_DI47);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI48);		
				else					RstResBit(Hard_DI48);			
			}  
		}
		//检查48-55
		if(HardConf_DINum>48)
		{
			DIBuff[6][0]=DIBuff[6][1],	DIBuff[6][1]=DIBuff[6][2],	DIBuff[6][2]=SB_ReadData(mSBA_DIInReg6);	//通道6
			InBuff=((DIBuff[6][0]^DIBuff[6][1])&DIBuff[6][2])|(DIBuff[6][0]&DIBuff[6][1]);						//3取2滤波
			if((InBuff!=DILastSta[6])||G10usTimerOver(&DIUpdateTimer[6],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[6]);						//复位更新计时
				DILastSta[6]=InBuff;
				State_DIn49_64=(State_DIn49_64&0xff00)|InBuff;			//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI49);			//光隔输入		IN49
				else					RstResBit(Hard_DI49);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI50);		
				else					RstResBit(Hard_DI50);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI51);		
				else					RstResBit(Hard_DI51);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI52);		
				else					RstResBit(Hard_DI52);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI53);		
				else					RstResBit(Hard_DI53);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI54);		
				else					RstResBit(Hard_DI54);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI55);		
				else					RstResBit(Hard_DI55);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI56);		
				else					RstResBit(Hard_DI56);			
			}  
		}
		//检查56-63
		if(HardConf_DINum>56)
		{
			DIBuff[7][0]=DIBuff[7][1],	DIBuff[7][1]=DIBuff[7][2],	DIBuff[7][2]=SB_ReadData(mSBA_DIInReg7);	//通道7
			InBuff=((DIBuff[7][0]^DIBuff[7][1])&DIBuff[7][2])|(DIBuff[7][0]&DIBuff[7][1]);						//3取2滤波
			if((InBuff!=DILastSta[7])||G10usTimerOver(&DIUpdateTimer[7],mDIUpdateTime))
			{
				G10usTimerRes(&DIUpdateTimer[7]);						//复位更新计时
				DILastSta[7]=InBuff;
				State_DIn49_64=(State_DIn49_64&0x00ff)|(InBuff<<8);		//反映到输入状态
	
				if(ChkBit(InBuff,0))	SetResBit(Hard_DI57);			//光隔输入		IN57
				else					RstResBit(Hard_DI57);
				if(ChkBit(InBuff,1))	SetResBit(Hard_DI58);		
				else					RstResBit(Hard_DI58);
				if(ChkBit(InBuff,2))	SetResBit(Hard_DI59);		
				else					RstResBit(Hard_DI59);
				if(ChkBit(InBuff,3))	SetResBit(Hard_DI60);		
				else					RstResBit(Hard_DI60);
				if(ChkBit(InBuff,4))	SetResBit(Hard_DI61);		
				else					RstResBit(Hard_DI61);
				if(ChkBit(InBuff,5))	SetResBit(Hard_DI62);		
				else					RstResBit(Hard_DI62);
				if(ChkBit(InBuff,6))	SetResBit(Hard_DI63);		
				else					RstResBit(Hard_DI63);
				if(ChkBit(InBuff,7))	SetResBit(Hard_DI64);		
				else					RstResBit(Hard_DI64);			
			}  
		}*/
	}
	
	//DO处理			由于有些输出会在主循环重复刷新，所以DO固定每个循环刷新
	//if(ResBitOutChgFlag||G10usTimerOver(&DOTimer,mDOUpdateTime))
	{	//BIT类型输出资源变量有变化、更新时间到
	//	G10usTimerRes(&DOTimer);
	//	ResBitOutChgFlag=mFalse;
		
		//更新0-7
		if(HardConf_DONum>0)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO01))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO02))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO03))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO04))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO05))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO06))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO07))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO08))	SetBit(OutBuff,7);
			
			if(IODebug.DOHardSN<=7)
				OutBuff|=1<<IODebug.DOHardSN;							//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg0,OutBuff);						//输出到端口
			State_DOut01_16=(State_DOut01_16&0xff00)|OutBuff;			//反应到状态
		}		
		//更新8-15
		if(HardConf_DONum>8)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO09))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO10))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO11))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO12))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO13))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO14))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO15))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO16))	SetBit(OutBuff,7);
			
			if((IODebug.DOHardSN>=8)&&(IODebug.DOHardSN<=15))
				OutBuff|=1<<(IODebug.DOHardSN-8);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg1,OutBuff);						//输出到端口
			State_DOut01_16=(State_DOut01_16&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}
		//更新16-23
		if(HardConf_DONum>16)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO17))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO18))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO19))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO20))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO21))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO22))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO23))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO24))	SetBit(OutBuff,7);
		
			if((IODebug.DOHardSN>=16)&&(IODebug.DOHardSN<=23))
				OutBuff|=1<<(IODebug.DOHardSN-16);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg2,OutBuff);						//输出到端口
			State_DOut17_32=(State_DOut17_32&0xff00)|OutBuff;			//反应到状态
		}
		//更新24-31
		if(HardConf_DONum>24)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO25))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO26))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO27))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO28))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO29))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO30))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO31))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO32))	SetBit(OutBuff,7);		
			
			if((IODebug.DOHardSN>=24)&&(IODebug.DOHardSN<=31))
				OutBuff|=1<<(IODebug.DOHardSN-24);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg3,OutBuff);						//输出到端口
			State_DOut17_32=(State_DOut17_32&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}
		//更新32-39
		if(HardConf_DONum>32)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO33))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO34))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO35))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO36))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO37))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO38))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO39))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO40))	SetBit(OutBuff,7);
        	
			if((IODebug.DOHardSN>=32)&&(IODebug.DOHardSN<=39))
				OutBuff|=1<<(IODebug.DOHardSN-32);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg4,OutBuff);						//输出到端口
			State_DOut33_48=(State_DOut33_48&0xff00)|OutBuff;			//反应到状态
		}
		//更新40-47
		if(HardConf_DONum>40)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO41))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO42))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO43))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO44))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO45))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO46))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO47))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO48))	SetBit(OutBuff,7);
        	
			if((IODebug.DOHardSN>=40)&&(IODebug.DOHardSN<=47))
				OutBuff|=1<<(IODebug.DOHardSN-40);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg5,OutBuff);						//输出到端口
			State_DOut33_48=(State_DOut33_48&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}
		//更新48-55
		if(HardConf_DONum>48)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO49))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO50))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO51))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO52))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO53))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO54))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO55))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO56))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=48)&&(IODebug.DOHardSN<=55))
				OutBuff|=1<<(IODebug.DOHardSN-48);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg6,OutBuff);						//输出到端口
			State_DOut49_64=(State_DOut49_64&0xff00)|OutBuff;			//反应到状态
		}
		//更新56-63
		/*if(HardConf_DONum>56)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO57))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO58))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO59))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO60))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO61))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO62))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO63))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO64))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=56)&&(IODebug.DOHardSN<=63))
				OutBuff|=1<<(IODebug.DOHardSN-56);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_DOOutReg7,OutBuff);						//输出到端口
			State_DOut49_64=(State_DOut49_64&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}*/
		
		//更新0-7	(64-71)		继电器输出
		if(HardConf_RLYNum>0)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO65))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO66))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO67))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO68))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO69))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO70))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO71))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO72))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=64)&&(IODebug.DOHardSN<=71))
				OutBuff|=1<<(IODebug.DOHardSN-64);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_RlyOutReg0,OutBuff);						//输出到端口
			State_DOut65_80=(State_DOut65_80&0xff00)|OutBuff;			//反应到状态
		}
		//更新8-15	(72-79)	继电器输出
		if(HardConf_RLYNum>8)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO73))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO74))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO75))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO76))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO77))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO78))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO79))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO80))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=72)&&(IODebug.DOHardSN<=79))
				OutBuff|=1<<(IODebug.DOHardSN-72);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_RlyOutReg1,OutBuff);						//输出到端口
			State_DOut65_80=(State_DOut65_80&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}
		//更新16-23	(80-87)	更新继电器
		/*if(HardConf_RLYNum>16)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO81))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO82))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO83))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO84))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO85))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO86))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO87))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO88))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=80)&&(IODebug.DOHardSN<=87))
				OutBuff|=1<<(IODebug.DOHardSN-80);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_RlyOutReg2,OutBuff);						//输出到端口
			State_DOut81_96=(State_DOut81_96&0xff00)|OutBuff;			//反应到状态
		}
		//更新24-31	(88-95)	更新继电器
		if(HardConf_RLYNum>24)
		{
			OutBuff=0;
			if(GetResBit(Hard_DO89))	SetBit(OutBuff,0);
			if(GetResBit(Hard_DO90))	SetBit(OutBuff,1);
			if(GetResBit(Hard_DO91))	SetBit(OutBuff,2);
			if(GetResBit(Hard_DO92))	SetBit(OutBuff,3);
			if(GetResBit(Hard_DO93))	SetBit(OutBuff,4);
			if(GetResBit(Hard_DO94))	SetBit(OutBuff,5);
			if(GetResBit(Hard_DO95))	SetBit(OutBuff,6);
			if(GetResBit(Hard_DO96))	SetBit(OutBuff,7);
	
			if((IODebug.DOHardSN>=88)&&(IODebug.DOHardSN<=95))
				OutBuff|=1<<(IODebug.DOHardSN-88);						//强制输出	Buff未清零，即允许与其它点(如：警报)同时有效输出	
			SB_WriteData(mSBA_RlyOutReg3,OutBuff);						//输出到端口
			State_DOut81_96=(State_DOut81_96&0x00ff)|((U16)OutBuff<<8);	//反应到状态
		}*/	
	}

	//计数处理	
	if(G10usTimerOver(&CntTimer,mCntChkTime))
	{	//检查时间到		2ms
		G10usTimerRes(&CntTimer);
		
		//计数器1		调模电眼计数			5位（有效4位），上升、下降沿双向计数
		Cnt=SB_ReadData(mSBA_Counter1)&0x0f;
		WrResU32(Hard_CNT01,RdResU32(Hard_CNT01)+(Cnt-LastCnt1+0x10)%0x10);
		LastCnt1=Cnt;

		//计数器2		螺杆转速电眼计数		4位，单向计数
		Cnt=SB_ReadData(mSBA_Counter2)&0x0f;	
		WrResU32(Hard_CNT02,RdResU32(Hard_CNT02)+(Cnt-LastCnt2+0x10)%0x10);
		LastCnt2=Cnt;
	}
	
	//软件计数处理		主要用于如：采用CAN总线模块时，电眼定义在CAN模块上（即无硬件计数器），此时可配置Para_ScrewRPMSoftCnt（螺杆
	//							    转速软件计数）、Para_MoldAdjSnrSoftCnt（调模电眼用软件计数）、Para_ProdSnrSoftTri（检物电眼软
	//								件触发）为1，并在Hard_Cnt01、Hard_Cnt02中删去与RU_MoldAdjSnrCnt、RU_ScrewRPMCnt的关联
	//螺杆转速电眼
	if(Para_ScrewRPMSoftCnt)
	{	//软件计数有效
		if(ScrewRPMSnrState!=GetResBit(mRI_ScrewRPMSnr))
		{
			ScrewRPMSnrState=GetResBit(mRI_ScrewRPMSnr);
			if(ScrewRPMSnrState)
				WrResU32(mRU_ScrewRPMCnt,RdResU32(mRU_ScrewRPMCnt)+1);		//单边沿计数
		}
	}
	//调模电眼
	if(Para_MoldAdjSnrSoftCnt)
	{	//软件计数有效
		if(MoldAdjSnrState!=GetResBit(mRI_MoldAdjSnr))
		{
			MoldAdjSnrState=GetResBit(mRI_MoldAdjSnr);
			WrResU32(mRU_MoldAdjSnrCnt,RdResU32(mRU_MoldAdjSnrCnt)+1);		//双边沿计数
		}
	}

	//软件触发器处理
	//检物电眼
	if(Para_ProdSnrSoftTri)
	{	//软件触发有效
		if(GetResBit(mRI_ProdSnr))
		{
			if(ProdSnrState==mPSS_Rst)
				ProdSnrState=mPSS_Tri;			//触发
		}
		else
		{
			if(ProdSnrState==mPSS_WaitRst)
				ProdSnrState=mPSS_Rst;			//复位
		}
	}

	//H24V电源状态检查及保护处理	???密切注意是否会出现误保护，如果会则增加自动复位保护或关闭保护功能（去掉保护，但电压低检查保留）

	//H24V电源异常时：先出现“电源异常”
	//        恢复时：“电源异常”自动解除，但短路保护还在，因此会出现警报显示由“电源异常”变“短路保护”
	//负 载 短 路 时：瞬间出现“电源异常”，然后才变短路保护
	//为使上述异常时显示警报正确，解决方法：1)“电源异常”时做标志，只有按手动键该标志复位后才允许“短路保护”报警，使电源异常时显示正确
	//                                      2)该标志要“电源异常”持续200ms才生效，使电源短路时正确识别出
	//电源标志Bit1(0-正常)	输出禁止标志Bit0(1-禁止)			
	//0						0						正    常----电源正常、无保护
	//0						1						短路保护----出现过短路，保护了，电源已经恢复正常，保护还有效
	//1						0						电源异常----未加电或电压严重低（正常不应出现的状态组合）
	//1						1						电源异常----未加电或电压严重低
	
	//H24V电源上电延迟检查：为避免主电源和阀电源之间开机加电不同步，对阀电源的检查延迟3秒后进行
	if(PwrOnPwrChkStep==mPOPCS_Init)
	{	//刚开机上电
		G10usTimerRes(&PwrOnPwrChkDlyTimer);
		PwrOnPwrChkStep=mPOPCS_Dly;
	}
	else if(PwrOnPwrChkStep==mPOPCS_Dly)	
	{	//延时				
		if(G10usTimerOver(&PwrOnPwrChkDlyTimer,mPwrOnPwrChkDlyTime))
			PwrOnPwrChkStep=mPOPCS_Chk;

		DIDOPwrProtRst();	//复位保护
	}
	else// if(PwrOnPwrChkStep==mPOPCS_Chk)
	{	//检查
		Buff=SB_ReadData(mSBA_DIDOPwrSta);
		if(((Buff&mBit1)==0)&&((Buff&mBit0)==0)&&(!PwrErrFlag))
		{	//正    常
			G10usTimerRes(&PwrErrFiltTimer);
		}
		else if(((Buff&mBit1)==0)&&((Buff&mBit0)==1)&&(!PwrErrFlag))
		{	//短路保护
			SetDigiLed(mDC_DIDOPwrProt);			//显示：阀电源保护
			SetAlarm(mAlarm_DIDOPwrOLProt);			//警报：阀电源过载保护			该警报为延时显示和保存，故断电时不会误显示和记录
		
			G10usTimerRes(&PwrErrFiltTimer);
		
			if(IsAnyKeyPush())	DIDOPwrProtRst();	//有动作键或方式键接下即复位保护
		}
		else //if(((Buff&mBit1)==1)&&((Buff&mBit0)==0))
		//else if(((Buff&mBit1)==1)&&((Buff&mBit0)==1))
		{	//电源异常
			SetDigiLed(mDC_PowerErr);				//显示：电源异常
			SetAlarm(mAlarm_DIDOPwrErr);			//警报：阀电源异常				该警报为延时显示和保存，故断电时不会误显示和记录
			
			if(G10usTimerOver(&PwrErrFiltTimer,T1msTo10us(200)))
				PwrErrFlag=mTrue;
			if(IsAnyKeyPush())	
				DIDOPwrProtRst(),PwrErrFlag=mFalse;	//有动作键或方式键接下即复位保护
		}
	}
	
	//调试模式时间到检查
	if(SysSta_IsTestMode())
	{	//调试模式
		if(G10usTimerOver(&DbgModeTimer,(Para_IODbgOutTime<T1sTo10us(60)) ? T1sTo10us(60*15) : Para_IODbgOutTime))
		{	//时间到
			SetAlarm(mAlarm_DebugAutoStop);	//警报“强制输出时间到结束”		属性为立转手动
		}
	}
	else
		G10usTimerRes(&DbgModeTimer);
		
	//调试模式检查
	if(!SysSta_IsTestMode())
	{	//非调试模式
		IODebug.Mode=mDBM_Exit;
	}
	if(IODebug.Mode!=mDBM_Nor)
	{
		IODebug.DOHardSN=0xff;
		IODebug.DIHardSN=0xff;	
		
		IODebug.CanModSN=0xff;
	}
}
/****************************************************************************************************
函数名称：	IO调试设置模式
函数说明：
输入参数：	
返 回 值：
其    它：
1)本函数主要由Code.c根据界面指令调用。
****************************************************************************************************/
void IODebugSetMode(U8 Mode)
{
	if(Mode==mDBM_Nor)
		IODebug.Mode=mDBM_Nor;
	else
	{
		IODebug.Mode=mDBM_Exit;
		
		IODebug.DOHardSN=0xff;
		IODebug.DIHardSN=0xff;
		
		IODebug.CanModSN=0xff;
	}
}
/****************************************************************************************************
函数名称：	IO调试设置通道
函数说明：
输入参数：
返 回 值：
其    它：
1)本函数主要由Code.c根据界面指令调用。
****************************************************************************************************/
Bool IODebugSetOut(U8 IOType,U8 HardSN)
{
	if(SysSta_IsTestMode()&&(IODebug.Mode==mDBM_Nor))
	{	//普通IO调试模式
		if(IOType==mDBT_DO)			IODebug.DOHardSN=HardSN;
		else if(IOType==mDBT_DI)	IODebug.DIHardSN=HardSN;
		else if((IOType>=mDBT_DO_CM1)&&(IOType<=mDBT_DO_CM8))	IODebug.CanModSN=IOType-mDBT_DO_CM1,IODebug.CanModDOHardSN=HardSN;
		
		RstDbgModeTimer();			//复位调试模式计时器			实现强制输出时间到自动结束
		return mTrue;
	}

	return mFalse;
}
/****************************************************************************************************
函数名称：	获取CAN模块IO调试通讯
函数说明：
输入参数：
返 回 值：
其    它：
1)本函数主要由CanModule_Drv.c文件调用，用以获取强制输出的通道。
****************************************************************************************************/
U8 GetCanModIODebugOut(U8 CanModSN)
{
	if( (CanModSN==IODebug.CanModSN)&&
		SysSta_IsTestMode()&&(IODebug.Mode==mDBM_Nor))
	{	//普通IO调试模式
		return IODebug.CanModDOHardSN;
	}
	return 0xff;
}

/****************************************************************************************************
函数名称：	硬件通道是加热输出检查
函数说明：
输入参数：
返 回 值：
其    它：
1) 本函数由Code.c中调用
2) 用于在IO调试强制输出时，检查强制输出点是否属电热输出，在电热点输出时须关着电热
3) 注意：增加电热时，必须在本函数作相应增加
         mRes_Out_Heater1~mRes_Out_Heater8资源的定义须连续
****************************************************************************************************/
Bool HardSNIsHtrOut(U16 HardSN)
{
	if(HardSN+mHard_DO01<mHardConfNum)
	{
		if( (HardConf[HardSN+mHard_DO01]==mRO_HeaterOn)||
			((HardConf[HardSN+mHard_DO01]>=mRO_Heater01)&&
		   	 (HardConf[HardSN+mHard_DO01]<=mRO_Heater16)))
			return mTrue;
	}

	return mFalse;	
}
/****************************************************************************************************
函数名称：	获取检物触器状态
函数说明：
输入参数：
返 回 值：
其    它：
1) 与CPLD电路相关,暂定DI19；也可能是软件处理实现，取决于Para_ProdSnrSoftTri参数
****************************************************************************************************/
Bool GetProdSnrTri(void)
{
	if(Para_ProdSnrSoftTri)	return(ProdSnrState==mPSS_Tri);					//软件处理
	else					return(SB_ReadData(mSBA_ProdSnrTri)&mBit0);		//硬件触发器
}
/****************************************************************************************************
函数名称：	获取检物触器状态
函数说明：
输入参数：
返 回 值：
其    它：
1) 与CPLD电路相关,暂定DI19；也可能是软件处理实现，取决于Para_ProdSnrSoftTri参数
****************************************************************************************************/
void RstProdSnrTri(void)
{
	//无论软件、硬件触发器一并复位
	if(ProdSnrState==mPSS_Tri)
		ProdSnrState=mPSS_WaitRst;
	SB_WriteData(mSBA_ProdSnrTri,0);
}
/****************************************************************************************************
函数名称：	复位调试模式计时器
函数说明：	用于实现调试时强制输出时间限制
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void RstDbgModeTimer(void)
{
	G10usTimerRes(&DbgModeTimer);
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
