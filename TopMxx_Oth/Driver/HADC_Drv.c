/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：HADC_Drv.c
文件说明：HADC驱动

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
1、	SPP1	SCK		PF.4										经隔离极性相同
			SSEL	GPIO 1.8用作CS，但须软件以IO方式控制		经隔离极性相同	
			MISO	P1.3										经隔离极性相同
			MOSI	P1.4										经隔离极性相同
	
	mSBA_HADCPwrSta	0x000c	R	HADC电源状态		Bit0:0-正常、1-异常	在SimBus.h定义
2、AD7689的0通道对应硬件配置HardConf[mHSN_HADC+0]，n通道对应硬件配置HardConf[mHSN_HADC+n]。

##其它
1、AD7689特性：
	250ksps、16bit、8通道、SPI接口最高20MHz、转换时间为3.2us(采用内部时钟)ADC芯片
	SDI:下降沿锁存
	SDO:上升沿移出
	CS :当CS低，AD7689的SPI接口有效
	SCK:模式00，CS为低，SCK发出指定的脉冲后(4、16或48，取决于设置)，后续SCK脉冲会忽略，除非CS再次由高变低。
2、本驱动，产生输入信号的电压值（单位1uV），或为电子尺位置、或为压力传感器、或为其它信号，取决于硬件配置定义。
3、AD7689有8个通道，实际参与转换使用的通道数可定义，取决于机器参数Para_HADCNum，即0～(Para_HADCNum-1)通
   道有效。
4、本驱动只用到定时器3中断，通过定时来控制采样（数据读写）、ADC转换时间。
5、在定时器中断中，只是简单的获取ADC数据，然后在主循环的处理函数中经滤波、转换为电压值、写到对应资源。
6、转换循环：0-0-1-1-2-2-3-3-4-4-5-5-6-6-7-7-0-0	(最大通道取决于Para_HADCNum-1)，即每个通道转换2次。
7、滤波算法：窗口滤波算法，通过宏mWinFilteNum定义窗口大小，通过mOneChanTimes定义每个通道连续转换次数。

AD7689性能测试： 
10K电位器调至最中间：经4次取平均后，数据最大跳动4-5，应有14-位精度。
					 经8次取平均后，数据最大跳动3-4，应有14+位精度。

8、转换时间：AD采样率为39.2kps，一次转换用时约25.5us。
12、转换顺序：动态可变，允许一或二路设为高优先级（机器参数设置），高优先级的每隔一个通道就轮到一次转换，详细如下。
			一路高优先级：P(8次)--1通道(8次)--P(8次)--2通道(8次)……	
						 高优先级的每隔205us产生一组数据
						 低优先级的每隔2.87ms产生一组数据(用8通道时)
						 低优先级的每隔1.23ms产生一组数据(用4通道时)
			二路高优先级：P1(4次)--P2(4次)--1通道(4次)--P1(4次)--P2(4次)--2通道(4次)……	
						 高优先级的每隔?us产生一组数据
						 低优先级的每隔?ms产生一组数据(用8通道时)
						 低优先级的每隔?ms产生一组数据(用4通道时)
						 此情况主要用于双色机，有两组位置尺相关动作同时进行	

****************************************************************************************************/
//#define mSysDebug	

#ifndef HADC_Drv_c
	#define HADC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define	mHadcSPI	SPI3				/* GD32原工程为SPI2（APB1+0x3C00），H743同地址为SPI3 */

//#define mSPI_BPS			800000		//SPI-SCK频率	当mPCLK_SPI为24MHz时，范围3MHz～93.75KHz
#define	mHADCChanMax		8	    //最大通道数
#define mChanFilteNum		16			//滤波次数		每个通道

#define mHADCTimer_5us		500			//100M	5us定时

#define AD768x_CS_Set() 	GPIOA->BSRR=mBit4								//GPIOA4 CS 置高
#define AD768x_CS_Clr()		GPIOA->BSRR=((U32)mBit4<<16)		//GPIOA4 CS 置低

//AD7689相关宏定义
//AD768x相关宏定义
#define mAD768x_SEL0		(((7<<10)+(0<<7)+mAD768xCFR_DEF)<<2)	//选择通道0
#define mAD768x_SEL1		(((7<<10)+(1<<7)+mAD768xCFR_DEF)<<2)	//选择通道1
#define mAD768x_SEL2		(((7<<10)+(2<<7)+mAD768xCFR_DEF)<<2)	//选择通道2
#define mAD768x_SEL3		(((7<<10)+(3<<7)+mAD768xCFR_DEF)<<2)	//选择通道3
#define mAD768x_SEL4		(((7<<10)+(4<<7)+mAD768xCFR_DEF)<<2)	//选择通道4
#define mAD768x_SEL5		(((7<<10)+(5<<7)+mAD768xCFR_DEF)<<2)	//选择通道5
#define mAD768x_SEL6		(((7<<10)+(6<<7)+mAD768xCFR_DEF)<<2)	//选择通道6
#define mAD768x_SEL7		(((7<<10)+(7<<7)+mAD768xCFR_DEF)<<2)	//选择通道7
#define mAD768x_Temp		(((3<<10)+(0<<7)+mAD768xCFR_DEF)<<2)	//选择温度通道

#define mAD768xCFR_DEF		(mBit13+mBit6+mBit0)		//CFR寄存器在本项目中的默认设置
														//更新CFR、全带宽、2.5V片内基准源、禁用序列、不回读

#define mAD768x_TempMin		(283-(40+25))*65536/2500	//-40度		ADC内部温度传感器的温度下限，超限则异常
#define mAD768x_TempMax		(283+(80-25))*65536/2500	//+80度		ADC内部温度传感器的温度上限，超限则异常
														//			当25度时电压为283mV，变化为1mV/度
U16 HADCChan_CMRTab[]={	//通道对应AD768x的CFG
	mAD768x_SEL0,mAD768x_SEL1,mAD768x_SEL2,mAD768x_SEL3,mAD768x_SEL4,mAD768x_SEL5,mAD768x_SEL6,mAD768x_SEL7,mAD768x_Temp};
	#define mAD768x_TempChan	8	//温度通道

/*======================================= 模块内有效变量定义 ======================================*/
U16 HADC_ADCBuff[mHADCChanMax][mChanFilteNum];	//ADC缓冲			直接ADC结果，尚未处理
Bool HADC_NewADCFlag[mHADCChanMax];				//新的ADC标志

U8 HADC_UseChanNum;					//使用通道数

	#define mSeqLen			22			//队列长度		2路优先级时：6*3+1(温度)、1路优先级时：3*2+1(温度)
	#define mSeqEnd			0xff		//队列结束
U8 HADC_CurrSeq[mSeqLen];			//当前转换序列		值0xff即序列结束		一个序列完成后，更新为HADC_NextSeq[]
U8 HADC_NextSeq[mSeqLen];			//下一转换序列		值0xff即序列结束		优先级调整申请时改该序列
	
static U8 SeqCnt,SeqNum;			//序列进行次数		序列总次数
static Bool PriReqFalg;				//序列变化标志

Bool HADCErrFlag;					//HADC异常标志

static U8 SeqChan_Next=mAD768x_TempChan;				//下一步对应的通道赋,初值为温度通道

//static U16 ErrADCDataCnt;		//异常ADC数据计数	SPI读到数据为0x0000、0xffff为异常数据
								//					异常数据连续24*4次则认为ADC转换可能存在异常，插
								//					入一次温度检查，如果也异常则置位ADC转换硬件出错
			 					//					根据实际程序，异常时最多22*4+22*4会插入一次温度
								//					检查，因为插入发生在一个序列完成时
	#define mErrADCDataCnt_Max	24*4	//异常数据最大计数

/*======================================= 模块内有效函数声明 ======================================*/
void __inline SPISendData(U16 SendData);	//SPI数据发送


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
函数名称：HADC处理
函数说明：
输入参数：无
返 回 值：无
其    它：
1、置于主循环。
****************************************************************************************************/
void HADC_Drv_Pcs(void)
{
	U32 HadcDataSum,i,j;
	static U8 LastHADC_NewADCFlag[mHADCChanMax];
	//U16 Buff[mChanFilteNum],Temp;
	//U8 i;

	//HADC转换结果处理
	for(i=0;i<HADC_UseChanNum;i++)
	{	
		if(HADC_NewADCFlag[i]!=LastHADC_NewADCFlag[i])
		{	//数据已经更新
			DisPerIRQ(SPI3_IRQn);				//关闭HADC相关定时器中断
			LastHADC_NewADCFlag[i]=HADC_NewADCFlag[i];
			
			//滤波:对指定窗口大小的数据取平均值
			HadcDataSum=HADC_ADCBuff[i][0];
			for(j=1;j<mChanFilteNum;j++)
				HadcDataSum+=(U32)HADC_ADCBuff[i][j];
			EnPerIRQ(SPI3_IRQn);						//开启中断
			//写入资源		以16位AD值形式
			WrResU32(HardConf[mHard_HAD01+i],HadcDataSum/mChanFilteNum);	
		}
			
		
		/*改简单平均值
		if(HADC_NewADCFlag[i])
		{	//数据已经更新
			//复制
			DisPerIRQ(SPI3_IRQn);			//关闭中断	
			HADC_NewADCFlag[i]=mFalse;
			
			Buff[0]=HADC_ADCBuff[i][0];
			Buff[1]=HADC_ADCBuff[i][1];
			Buff[2]=HADC_ADCBuff[i][2];
			Buff[3]=HADC_ADCBuff[i][3];
			EnPerIRQ(SPI3_IRQn);			//开启中断	

			//滤波:复合滤波算法,4个结果中去掉最高1个和最低1个,然后将剩余的2个取平均值
			//排序
			if(Buff[0]>Buff[1])	Temp=Buff[1],	Buff[1]=Buff[0],	Buff[0]=Temp;
			if(Buff[0]>Buff[2])	Temp=Buff[2],	Buff[2]=Buff[0],	Buff[0]=Temp;
			if(Buff[0]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[0],	Buff[0]=Temp;

			if(Buff[1]>Buff[2])	Temp=Buff[2],	Buff[2]=Buff[1],	Buff[1]=Temp;
			if(Buff[1]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[1],	Buff[1]=Temp;

			if(Buff[2]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[2],	Buff[2]=Temp;
			//写入资源		以16位AD值形式
			WrResU32(HardConf[mHard_HAD01+i],(Buff[1]+Buff[2])>>1);	
		}*/
	}
	
	//通道数检查
	if(HADC_UseChanNum!=HardConf_HADNum)
	{	//通道数发生变化 	通常是进行了重置
		DisPerIRQ(SPI3_IRQn);										//关闭中断
		HADC_UseChanNum=HardConf_HADNum;							//通道数
		if((HADC_UseChanNum==0)||(HADC_UseChanNum>mHADCChanMax))
			HADC_UseChanNum=mHADCChanMax;
		for(i=0;i<HADC_UseChanNum;i++)	HADC_NextSeq[i]=i;			//转换队列
		for(;i<mSeqLen;i++)				HADC_NextSeq[i]=mSeqEnd;	//队列结束
		EnPerIRQ(SPI3_IRQn);											//开启中断
	}
}
/****************************************************************************************************
函数名称：HADC优先级申请
函数说明：用于调整HADC转换的优先级，通常在执行某个动作时调用，将本动作相关的电子尺通道优先级调高。
输入参数：U16 ResSn	资源序号
返 回 值：mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool HADC_PriReq(U16 ResSn)
{
	U8 Chan,i,j,p;

	if(ResSn==mHADCPR_DefSeq)	
	{	//恢复默认序列
		DisPerIRQ(SPI3_IRQn);										//关闭中断
		for(i=0;i<HADC_UseChanNum;i++)	HADC_NextSeq[i]=i;			//转换队列
		for(;i<mSeqLen;i++)				HADC_NextSeq[i]=mSeqEnd;	//队列结束
		EnPerIRQ(SPI3_IRQn);											//开启中断
	
		return mTrue;
	}
	
	//搜索ResSN对应HADC通道
	for(Chan=0;Chan<HADC_UseChanNum;Chan++)
	{
		if(HardConf[mHard_HAD01+Chan]==ResSn)
		{	//通道找到		调整优先级
			if(Para_HADPriNum==0)
			{	//1路优先级
				
				DisPerIRQ(SPI3_IRQn);			//关闭中断	
				for(i=0,j=0;i<HADC_UseChanNum;i++)	
				{
					if(i!=Chan)
					{
						HADC_NextSeq[j]=Chan;	j++;
						HADC_NextSeq[j]=i;		j++;
					}
				}
				for(;j<mSeqLen;j++)
					HADC_NextSeq[j]=mSeqEnd;
				EnPerIRQ(SPI3_IRQn);				//开启中断	
				
			}
			else
			{	//2路优先级				
				DisPerIRQ(SPI3_IRQn);			//关闭中断	
				for(i=0,j=0,p=HADC_NextSeq[0];i<HADC_UseChanNum;i++)
				{
					if((i!=Chan)&&(i!=p))
					{
						HADC_NextSeq[j]=Chan;	j++;
						HADC_NextSeq[j]=p;		j++;
						HADC_NextSeq[j]=i;		j++;
					}
				}
				for(;j<mSeqLen;j++)
					HADC_NextSeq[j]=mSeqEnd;
				EnPerIRQ(SPI3_IRQn);				//开启中断	
				
			}
			return mTrue;
		}
	}
	return mFalse;
}
/****************************************************************************************************
函数名称：HADC电源检查
函数说明：
输入参数：mTrue--正常	mFalse--出错
返 回 值：
其    它：
1、PC9--HADC电源状态:0-正常、1-异常
****************************************************************************************************/
Bool HADC_PwrChk(void)
{
	return (!LL_GPIO_IsInputPinSet(GPIOC, LL_GPIO_PIN_9));
}
/****************************************************************************************************
函数名称：HADC模块检查
函数说明：
输入参数：mTrue--正常	mFalse--出错
返 回 值：
其    它：
****************************************************************************************************/
Bool HADC_ModuleChk(void)
{
	return !HADCErrFlag;
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
/****************************************************************************************************
函数名称：HADC初始化
函数说明：
输入参数：
返 回 值：
其    它：
1)TIM13挂APB1，TIMPRE=4倍频，定时器内核时钟200M；PSC=2-1后为100M。PCLK1为50M，PCLK2为100M。
2)SPI3内核时钟走D2CCIP2R复位默认pll1_q_ck=PLL1Q 400/2=200M，MBR=256分频后SCK为0.78125M。
****************************************************************************************************/
void HADC_Drv_Init(void)
{
	volatile U32 Buff;
	LL_GPIO_InitTypeDef GPIO_InitStruct;
    LL_SPI_InitTypeDef spi_init_struct;
	
	//变量初始化
	HADC_UseChanNum=HardConf_HADNum;			//通道数
	if((HADC_UseChanNum==0)||(HADC_UseChanNum>mHADCChanMax))
		HADC_UseChanNum=mHADCChanMax;
	if((GetHardPlatLinkCode()==0x5C)||(GetHardPlatLinkCode()==0x60))//E2或E4为HADC由AD7682配为AD7689（默认通道为0-7顺序的，但AD7682和AD7689引脚差异，硬件不改时，由4通道AD7682替换为8通道的AD7689要改变通道顺序）	20220311
	{
		HADCChan_CMRTab[0]=mAD768x_SEL0;
		HADCChan_CMRTab[1]=mAD768x_SEL2;
		HADCChan_CMRTab[2]=mAD768x_SEL5;
		HADCChan_CMRTab[3]=mAD768x_SEL7;
	}
	for(Buff=0;Buff<HADC_UseChanNum;Buff++)		//转换队列
	{
		HADC_CurrSeq[Buff]=Buff;
		HADC_NextSeq[Buff]=Buff;
	}
	SeqNum=HADC_UseChanNum;
	for(;Buff<mSeqLen;Buff++)			
	{
		HADC_CurrSeq[Buff]=mSeqEnd;				//队列结束
		HADC_NextSeq[Buff]=mSeqEnd;
	}
	
	

	HADCErrFlag=mFalse;
	//IO端口初始化
	//SSEL		PA4	CS
	//SCK		  PC10
	//MISO		PC11
	//MOSI		PC12
	LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
	LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);
   	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI3);

   	//PC10 复用功能	SPI3_SCK（H743 Port C：AF6=SPI3）
	GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	GPIO_InitStruct.Alternate = LL_GPIO_AF_6;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    //PC11 复用功能	SPI3_MISO
	GPIO_InitStruct.Pin = LL_GPIO_PIN_11;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    //PC12 复用功能	SPI3_MOSI
	GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
   	//PA4	CS	输出IO
	GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//PC9	HADC电源状态输入引脚（新板由PD0改PC9）
	GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	AD768x_CS_Set();
	
	//SPI初始化（H743为新SPI IP，CFG寄存器配置，须先禁用才能写）
	LL_SPI_Disable(mHadcSPI);
    spi_init_struct.TransferDirection = LL_SPI_FULL_DUPLEX;	//全双工模式
    spi_init_struct.Mode          = LL_SPI_MODE_MASTER;		//SPI主机
    spi_init_struct.DataWidth     = LL_SPI_DATAWIDTH_16BIT;	//16位数据格式
    spi_init_struct.ClockPolarity= LL_SPI_POLARITY_LOW;		//空闲模式下SCK为0 CPOL=0
    spi_init_struct.ClockPhase   = LL_SPI_PHASE_1EDGE;		//CPHA=0,数据采样从第1个时间边沿开始
    spi_init_struct.NSS          = LL_SPI_NSS_SOFT;			//软件nss管理（LL_Init内部自动置SSI=1）
    spi_init_struct.BaudRate     = LL_SPI_BAUDRATEPRESCALER_DIV256;	//Fsck=pll1_q(PLL1Q) 200M/256=0.78125M（原Fpclk1 50M/64）
    spi_init_struct.BitOrder     = LL_SPI_MSB_FIRST;			//MSB First
    spi_init_struct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    LL_SPI_Init(mHadcSPI, &spi_init_struct);
    LL_SPI_SetTransferSize(mHadcSPI,1);		//每次CSTART固定传输1个16位帧，硬件在第16个SCK后产生EOT并停止

    LL_SPI_SetStandard(mHadcSPI, LL_SPI_PROTOCOL_MOTOROLA);		//禁用TI模式(摩托罗拉模式)
    LL_SPI_SetFIFOThreshold(mHadcSPI, LL_SPI_FIFO_TH_01DATA);	//16位单包接收阈值
    LL_SPI_DisableNSSPulseMgt(mHadcSPI);						//软件NSS，禁止NSSP脉冲
    LL_SPI_EnableIT_EOT(mHadcSPI);								//整帧在线上传输完成后再结束软件CS
    NVIC_SetPriority(SPI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),mIRQPriorityL,mIRQPriorityL));	//配置NVIC（抢占0/子0，分组5）
    NVIC_EnableIRQ(SPI3_IRQn);

	LL_SPI_Enable(mHadcSPI);
	//CSTART由每次SPISendData按帧重臂，禁止跨软件CS边界连续移位
	//TIM13初始化（GD32原工程为TIMER12）
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM13);
    LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_FOUR_TIMES);
    LL_TIM_DeInit(TIM13);

	LL_TIM_SetPrescaler(TIM13, 2U-1U);
    LL_TIM_SetCounterMode(TIM13, LL_TIM_COUNTERMODE_UP);
    LL_TIM_SetAutoReload(TIM13, 0xffffffffUL);
    LL_TIM_SetClockDivision(TIM13, LL_TIM_CLOCKDIVISION_DIV1);
    LL_TIM_GenerateEvent_UPDATE(TIM13);		//软件更新，立即加载PSC/ARR（对应GD32 timer_init末尾内置UPG）

 	//匹配中断设置（H743同地址实例为TIM13，仅1个比较通道CH1；GD32 TIMER12原用CH_0，此为实例级强制适配，中断功能等价）
    LL_TIM_OC_ConfigOutput(TIM13,LL_TIM_CHANNEL_CH1,LL_TIM_OCPOLARITY_HIGH|LL_TIM_OCIDLESTATE_LOW);
    LL_TIM_CC_EnableChannel(TIM13, LL_TIM_CHANNEL_CH1);		//通道输出使能（对应原CCX_ENABLE）
    //设置CH1的比较值（等价原TIMER_CH_0的CCR）
    LL_TIM_OC_SetCompareCH1(TIM13, mHADCTimer_5us);
    LL_TIM_OC_SetMode(TIM13, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
    LL_TIM_OC_DisablePreload(TIM13, LL_TIM_CHANNEL_CH1);
    // 启用CH1匹配中断（等价原TIMER_INT_CH0），5us等转换完成
    //LL_TIM_EnableIT_UPDATE(TIM13);
    LL_TIM_EnableIT_CC1(TIM13);
    // 配置NVIC
    NVIC_SetPriority(TIM8_UP_TIM13_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),mIRQPriorityL,mIRQPriorityL));
    NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
    // TIM13 enable
    LL_TIM_EnableCounter(TIM13);

}
/****************************************************************************************************
函数名称：SPI3中断和TIM13中断
函数说明：
输入参数：
返 回 值：
其    它：
1、SPI+TIM13的中断周期无Ecat约25-30.1us，有Ecat约25-35.1us,平均估计在26us。其中：SPI收发约21us、SPI中断
   程序执行用时约0.54-2.38us,TIM13中断约5us、TIM13中断程序执行用时约0.38-0.98us。
2、中断部分对CPU时间的占用约9～19%，平均估计在12%左右。
3、通道间有一定的影响，主要是换通道后的第一次ADC。如果通道间电压相差大，影响很明显，会有8左右的偏差。
4、AD结果精度：	经4次取平均值后，有约14位精度，50%量程的长时间跳动约4-6。
****************************************************************************************************/
void SPI3_IRQHandler(void)
{
	U16 RecBuff;
	U32 i;
	U8 Temp;
	static Bool NewSeqFlag;

	if(LL_SPI_IsActiveFlag_EOT(SPI3))
	{	//一个16位SPI事务已经在线上完整结束
		RecBuff=*((__IO U16 *)&SPI3->RXDR);					//ARMCC下必须半字访问，避免RXFIFO数据打包
		LL_SPI_ClearFlag_EOT(SPI3);
		LL_SPI_ClearFlag_TXTF(SPI3);
		//启动ADC转换
		AD768x_CS_Set();						//置高	结束本次通讯并启动ADC转换(EOT保证SCK已静止)
		//开启5us定时中断	即等待5us后ADC转换完成
		LL_TIM_ClearFlag_CC1(TIM13);					//清除中断标志位
		//TIMER_CH0CV(TIMER12)=TIMER_CNT(TIMER12)+mHADCTimer_5us;		//5uS匹配中断
		TIM13->CNT=0;
		EnPerIRQ(TIM8_UP_TIM13_IRQn);									//开启中断
		
//		if((RecBuff==0)||(RecBuff==0xffff))
//			ErrADCDataCnt++;					//异常数据
//		else
//			ErrADCDataCnt=0,HADCErrFlag=mFalse;	//正常数据		直接复位
		
		//ADC转换处理		
		if(SeqNum>=2)	//防下标超出	
		{	//完成一个通道
			if(SeqCnt>=2)	//-2是因为AD768x的CFG延迟2个周期才生效
			{
				Temp=SeqCnt-2;		
				Temp=HADC_CurrSeq[Temp];	//获取通道号
				HADC_ADCBuff[Temp][HADC_NewADCFlag[Temp]++]=RecBuff;
				if(HADC_NewADCFlag[Temp]>=mChanFilteNum)
					HADC_NewADCFlag[Temp]=0;
				
				NewSeqFlag=mFalse;	//复位新序列标志
			}
			else if(NewSeqFlag==mFalse)
			{
				Temp=SeqNum+SeqCnt-2;
				Temp=HADC_CurrSeq[Temp];	//获取通道号
				HADC_ADCBuff[Temp][HADC_NewADCFlag[Temp]++]=RecBuff;
				if(HADC_NewADCFlag[Temp]>=mChanFilteNum)
					HADC_NewADCFlag[Temp]=0;
			}
		}
		SeqCnt++;
    	
		//if(SeqCnt==mHADCChanMax-2)		//-2是因为AD768x的CFG延迟2个周期才生效
		{	//准备下一通道			
			if((SeqCnt>=SeqNum)||(SeqCnt>=mSeqLen))
			{	//一个序列即将结束		复制新的序列
				SeqCnt=0;
				if(PriReqFalg==mTrue)
				{	//启动新序列
					NewSeqFlag=mTrue;
					PriReqFalg=mFalse;
					for(i=0;i<mSeqLen;i++)	
					{
						HADC_CurrSeq[i]=HADC_NextSeq[i];
						if(HADC_NextSeq[i]==mSeqEnd)
						{
							SeqNum=i;		//记录有多少个有效序列
							break;
						}
    				}
    			}
//				if(ErrADCDataCnt>=mErrADCDataCnt_Max)
//				{	//ADC数据连续异常，插入一次温度检查
//					for(i=0;i<mSeqLen;i++)
//					{
//						if(HADC_CurrSeq[i]>mAD768x_TempChan)
//						{
//							HADC_CurrSeq[i]=mAD768x_TempChan;
//							ErrADCDataCnt=0;
//							SeqNum++;
//							break;
//						}
//					}
//				}
			}			
		}
		
		SeqChan_Next=HADC_CurrSeq[SeqCnt];
	}
}
void TIM8_UP_TIM13_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_CC1(TIM13))
	{
		LL_TIM_ClearFlag_CC1(TIM13);					//清除中断标志位
		DisPerIRQ(TIM8_UP_TIM13_IRQn);										//关闭中断
		SPISendData(HADCChan_CMRTab[SeqChan_Next]);	//发下一通道
	}
}

/****************************************************************************************************
函数名称：SPI发送数据
函数说明：
输入参数：
返 回 值：
其    它：
1、CS下降沿到SCK上升沿，延迟约900ns。
****************************************************************************************************/
void __inline SPISendData(U16 SendData)
{
	AD768x_CS_Clr();							//选中AD768x
	*((__IO U16 *)&SPI3->TXDR)=SendData;		//ARMCC下强制半字写，确保TXFIFO只压入1个16位帧
	LL_SPI_StartMasterTransfer(SPI3);			//TSIZE=1：发送16位后硬件自动停止并置EOT
}

