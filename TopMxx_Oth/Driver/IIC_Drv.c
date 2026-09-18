/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：IIC_Drv.c
文件说明：IIC驱动程序

作    者：LC
编写时间：2019.9
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
1、基于 STM32H743 硬件 I2C1 外设
2、硬件接口：
   	PB8/SCL（AF4，开漏上拉）
   	PB9/SDA（AF4，开漏上拉）
3、SCL 频率 400kHz（PCLK1=50MHz，Timing 经 4 次标定补偿 RC 延迟）
4、写50字节再读50字节用时约2.8mS
****************************************************************************************************/
//#define mSysDebug

#ifndef IIC_Drv_c
	#define IIC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define mFI2C	400000		//IIC总线频率	400kHz	工具可以计算
#define mAddI2C	0xA0		//IIC从站地址

/*======================================= 模块内有效变量定义 ======================================*/
G10usTimer I2CTimer;
	#define I2C_RstTimer()		G10usTimerRes(&I2CTimer)		//复位
	#define I2C_OverTimeChk()	G10usTimerOver(&I2CTimer,200)	//超时检查	2ms
	
/*======================================= 模块内有效函数声明 ======================================*/


/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug

volatile Bool RWOKFlag;   
U16 Addr,Len;
	U8 Buff[128];
	U16 x[128];
	U8 y[128];
	U16 i,d;
    U32 Wtime;
int main(void)
{           

    G10usTimer LedTwinkle;
	Time_Drv_Init();        //时间驱动初始化	必须最先
	I2Cx_Drv_Init();		//IIC总线初始化		必须第二

    //使能 LED GPIO 时钟
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);

    //配置 LED1 GPIO 端口
    LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_0, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinOutputType(GPIOC, LL_GPIO_PIN_0, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinSpeed(GPIOC, LL_GPIO_PIN_0, LL_GPIO_SPEED_FREQ_HIGH);
    LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_0, LL_GPIO_PULL_NO);
    //复位 LED1 GPIO 引脚
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_0);

	d=0;
	Addr=0xA2;
	Len=50;
	do{

		for(i=0;i<Len;i++)
			Buff[i]=0x55,y[i]=d+1;
        G10usTimerRes(&LedTwinkle);
		RWOKFlag=I2CWrite(Addr,0,Len,Buff,mTrue);	//写FM24CL16
		RWOKFlag=I2CRead (Addr,0,Len,y,mTrue);		//读FM24CL16
		Wtime=G10usTimerCal(&LedTwinkle);		
		d++;
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/

/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
/*************************************************************************
函数说明: I2C1初始化——硬件IIC
输入参数: Address,从器件写地址；Datalen,要发送的数据长度；
    	  WriteBuffer[],要发送的数据
输出参数: 无
返 回 值: mTrue, 发送完成；mFalse,发送未完成
          调用前先指定从器件地址：SlaveAddr
**************************************************************************/
void I2Cx_Drv_Init(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	//引脚配置，IIC1引脚
	/* 使能 GPIOB 时钟 + I2C1 时钟 */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C1);

    /* PB8 = I2C1_SCL, PB9 = I2C1_SDA, AF4 */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	//IIC1初始化配置
	/* H7 I2C IP 配置：用 ST 官方宏按 50MHz/400kHz 精确算 Timing 值，并补偿实测 RC 延迟 */
	/* 参数：PRESC=0, SCLDEL=8, SDADEL=0, SCLH=53, SCLL=53（参见 RM0433 I2C_TIMINGR 字段定义） */
	/* 精确公式：tSCL = tSYNC1(2×tI2CCLK) + tSYNC2(2×tI2CCLK) + (SCLH+1)×tpresc + (SCLL+1)×tpresc + tRC */
	/*   tpresc = (PRESC+1)×tI2CCLK = 1×20ns = 20ns (PCLK1=50MHz) */
	/*   tSCL_理论 = 80 + 54×20 + 54×20 = 80 + 1080 + 1080 = 2240ns → fSCL_理论 = 446.4kHz */
	/*   实测 SCL 线 RC 上升延迟约 270ns (开漏+上拉电阻+总线电容, 随 tSCL 变化) */
	/*   tSCL_实际 ≈ 2240 + 270 = 2510ns → fSCL_实际 ≈ 398.4kHz (目标 400kHz, 误差 -0.4%) */
	/* 标定依据: 3 次实测数据反推 RC 延迟: 363/278/264ns, 取近次稳定值 270ns */
    LL_I2C_SetTiming(I2C1, __LL_I2C_CONVERT_TIMINGS(0, 8, 0, 53, 53));
    LL_I2C_SetMode(I2C1, LL_I2C_MODE_I2C);
    LL_I2C_SetOwnAddress1(I2C1, mAddI2C, LL_I2C_OWNADDRESS1_7BIT);
    LL_I2C_EnableOwnAddress1(I2C1);
    /* 使能 I2C1 */
    LL_I2C_Enable(I2C1);
    /* 使能应答 */
    LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_ACK);
}
void I2CClkOut(void)
{
	U8 i;
	//PB8 临时切回普通输出，强拉 SCL 时钟解锁死锁从机
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_8, LL_GPIO_OUTPUT_PUSHPULL);
	for(i=0;i<10;i++)
	{
		GPIOB->BSRR	=mBit8;							//置信号
		Dly1us(3);
		GPIOB->BSRR	=((U32)mBit8<<16);				//清信号
		Dly1us(3);
	}
}
/*************************************************************************
函数说明: 发送数据
输入参数: Slave，从器件地址或页地址；
		  Address,从器件写地址；Datalen,要发送的数据长度；
    	  WriteBuffer[],要发送的数据；Addr16Flag,地址是16位标志
输出参数: 无
返 回 值: mTrue, 发送完成；mFalse,发送未完成
          调用前先指定从器件地址：SlaveAddr
          
注    意: Datalen的长度不能超过器件缓冲区的长度
**************************************************************************/
Bool I2CWrite(U8 Slave,U16 Address,U16 Datalen,U8 *WriteBuffer,Bool Addr16Flag)
{
	U8 I2CErrCnt;	//出错计数
	U32 ToteByte;
	U8 * pD;
	U32 AddrCnt;
	U32 TotalNbytes;

	I2CErrCnt=0;	//复位出错计数
I2CStart:
	ToteByte=Datalen;
	pD=WriteBuffer;
	AddrCnt = (Addr16Flag ? 2 : 1);
	TotalNbytes = AddrCnt + Datalen;

	//等待总线空闲
	I2C_RstTimer();
	while(LL_I2C_IsActiveFlag_BUSY(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	//启动总线 + 发器件地址 + 写 + 总字节数(含地址)
	//<=255 用 SOFTEND（末字节后由 TC 置位，软件发 STOP）
	//>255 用 RELOAD 续传（FM24CL16 单页 64 字节，Datalen=50 不会触发，保留兼容性）
	LL_I2C_HandleTransfer(I2C1,
						  Slave,
						  LL_I2C_ADDRSLAVE_7BIT,
						  (TotalNbytes > 255 ? 255 : TotalNbytes),
						  (TotalNbytes > 255 ? LL_I2C_MODE_RELOAD : LL_I2C_MODE_SOFTEND),
						  LL_I2C_GENERATE_START_WRITE);

	//发高地址
	if(Addr16Flag)
	{
		I2C_RstTimer();
		while(!LL_I2C_IsActiveFlag_TXIS(I2C1))
		{
			if(I2C_OverTimeChk())		//超时未完成
				goto I2CErr;
		}
		LL_I2C_TransmitData8(I2C1, (Address>>8)&0x00ff);
	}
	//发低地址
	I2C_RstTimer();
	while(!LL_I2C_IsActiveFlag_TXIS(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	LL_I2C_TransmitData8(I2C1, (Address>>0)&0x00ff);

	//发数据
	 while(ToteByte--)
	 {
		I2C_RstTimer();
		while(!LL_I2C_IsActiveFlag_TXIS(I2C1))
		{
			if(I2C_OverTimeChk())		//超时未完成
				goto I2CErr;
		}
		LL_I2C_TransmitData8(I2C1, *pD);
		pD++;
    }
    //等传输完成（SOFTEND 模式下 TC 置位）
	I2C_RstTimer();
	while(!LL_I2C_IsActiveFlag_TC(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	//发送结束条件
	LL_I2C_GenerateStopCondition(I2C1);

	return mTrue;
	//出错处理
I2CErr:
	//产生结束信号
	/*i2c_flag_clear(I2C0,I2C_FLAG_SMBALT);
	i2c_flag_clear(I2C0,I2C_FLAG_SMBTO);
	i2c_flag_clear(I2C0,I2C_FLAG_PECERR);
	i2c_flag_clear(I2C0,I2C_FLAG_OUERR);
	i2c_flag_clear(I2C0,I2C_FLAG_AERR);
	i2c_flag_clear(I2C0,I2C_FLAG_LOSTARB);
	i2c_flag_clear(I2C0,I2C_FLAG_BERR);
	i2c_flag_clear(I2C0,I2C_FLAG_ADDSEND);

    i2c_start_on_bus(I2C0);*/
    //i2c_data_transmit(I2C0, 0);
	//i2c_stop_on_bus(I2C0);
	I2CClkOut();

    LL_I2C_Disable(I2C1);
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_I2C1);
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_I2C1);
    I2Cx_Drv_Init();
	if(I2CErrCnt<2)
	{	//允许3次出错
		I2CErrCnt++;
		goto I2CStart;
	}
	else
		return mFalse;
}


/*************************************************************************
函数说明: 读取数据
输入参数: Address,从器件写地址；Datalen,要发送的数据长度；
    	  ReadBuffer[],读取的数据；Addr16Flag,地址是16位标志
输出参数: 无
返 回 值: mTrue, 读成功；mFalse,读失败
          调用前先指定从器件地址：SlaveAddr
注    意：最后一个字节读出后，必须发出的是非应答信号，否则可能出现竞争。
**************************************************************************/
Bool I2CRead(U8 Slave,U16 Address,U16 Datalen,U8 *ReadBuffer,Bool Addr16Flag)
{
	U8 I2CErrCnt;	//出错计数
	U16 i;
	U32 ToteByte;
	U32 AddrCnt;

	I2CErrCnt=0;	//复位出错计数
	if(Datalen==0)return mTrue;
	AddrCnt = (Addr16Flag ? 2 : 1);

I2CStart:
	ToteByte=Datalen;

	//等待总线空闲
	I2C_RstTimer();
	while(LL_I2C_IsActiveFlag_BUSY(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	//阶段1：空写定位指针（发从地址+方向写+发地址字节，SOFTEND）
	LL_I2C_HandleTransfer(I2C1,
						  Slave,
						  LL_I2C_ADDRSLAVE_7BIT,
						  AddrCnt,
						  LL_I2C_MODE_SOFTEND,
						  LL_I2C_GENERATE_START_WRITE);

	//发高地址
	if(Addr16Flag)
	{
		I2C_RstTimer();
		while(!LL_I2C_IsActiveFlag_TXIS(I2C1))
		{
			if(I2C_OverTimeChk())		//超时未完成
				goto I2CErr;
		}
		LL_I2C_TransmitData8(I2C1, (Address>>8)&0x00ff);
	}
	//发低地址
	I2C_RstTimer();
	while(!LL_I2C_IsActiveFlag_TXIS(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	LL_I2C_TransmitData8(I2C1, (Address>>0)&0x00ff);

	//等 TC 置位（SOFTEND）
	I2C_RstTimer();
	while(!LL_I2C_IsActiveFlag_TC(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}

	//阶段2：重新启动读，AUTOEND 模式自动产生 STOP
	LL_I2C_HandleTransfer(I2C1,
						  Slave,
						  LL_I2C_ADDRSLAVE_7BIT,
						  ToteByte,
						  LL_I2C_MODE_AUTOEND,
						  LL_I2C_GENERATE_START_READ);

	//读数据
	for(i=0;i<ToteByte;i++)
	{
        //设置要不要应答
        if(i>=(ToteByte-1))
            LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_NACK);
        else
            LL_I2C_AcknowledgeNextData(I2C1, LL_I2C_ACK);


		I2C_RstTimer();
        while(!LL_I2C_IsActiveFlag_RXNE(I2C1))
        {
            if(I2C_OverTimeChk())		//超时未完成
                goto I2CErr;
        }
        *(ReadBuffer+i)=LL_I2C_ReceiveData8(I2C1);
	}
	//等 STOP 置位（AUTOEND 自动产生）
	I2C_RstTimer();
	while(!LL_I2C_IsActiveFlag_STOP(I2C1))
	{
		if(I2C_OverTimeChk())		//超时未完成
			goto I2CErr;
	}
	LL_I2C_ClearFlag_STOP(I2C1);
	return mTrue;

	//出错处理
I2CErr:
	for(i=0;i<Datalen;i++)
		ReadBuffer[i]=0;

	//产生结束信号
	/*i2c_flag_clear(I2C0,I2C_FLAG_SMBALT);
	i2c_flag_clear(I2C0,I2C_FLAG_SMBTO);
	i2c_flag_clear(I2C0,I2C_FLAG_PECERR);
	i2c_flag_clear(I2C0,I2C_FLAG_OUERR);
	i2c_flag_clear(I2C0,I2C_FLAG_AERR);
	i2c_flag_clear(I2C0,I2C_FLAG_LOSTARB);
	i2c_flag_clear(I2C0,I2C_FLAG_BERR);
	i2c_flag_clear(I2C0,I2C_FLAG_ADDSEND);
	*/
    //i2c_start_on_bus(I2C0);
    //i2c_data_transmit(I2C0, 0);
	//i2c_stop_on_bus(I2C0);

	I2CClkOut();

    LL_I2C_Disable(I2C1);
    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_I2C1);
    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_I2C1);
    I2Cx_Drv_Init();
	if(I2CErrCnt<3)
	{	//允许3次出错
		I2CErrCnt++;
		goto I2CStart;
	}
	else
		return mFalse;
}
