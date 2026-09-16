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
1、基于
2、硬件接口：
   	P0.11/SCL2
   	P0.10/SDA2
3、写100字节再读100字节用时约4.5mS
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
	IntVectTabRemap();
	Time_Drv_Init();        //时间驱动初始化	必须最先
	I2Cx_Drv_Init();		//IIC总线初始化		必须第二
	
    // enable the LEDs GPIO clock 
    rcu_periph_clock_enable(RCU_GPIOC);

    // configure LED1 GPIO port 
    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    // reset LED1 GPIO pin 
    gpio_bit_reset(GPIOC, GPIO_PIN_0);

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
	//引脚配置，IIC1引脚
	/* enable GPIOB clock */
    rcu_periph_clock_enable(RCU_GPIOB);
    /* enable I2C0 clock */
    rcu_periph_clock_enable(RCU_I2C0);

    // connect PB8 to I2C0_SCL 
    gpio_af_set(GPIOB, GPIO_AF_4, GPIO_PIN_8);
    // connect PB9 to I2C0_SDA 
    gpio_af_set(GPIOB, GPIO_AF_4, GPIO_PIN_9);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLUP,GPIO_PIN_8);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ,GPIO_PIN_8);
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLUP,GPIO_PIN_9);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ,GPIO_PIN_9);
	
	//IIC2初始化配置
	/* enable I2C clock */
    rcu_periph_clock_enable(RCU_I2C0);
    /* configure I2C clock */
    i2c_clock_config(I2C0,mFI2C,I2C_DTCY_2);
    /* configure I2C address */
    i2c_mode_addr_config(I2C0,I2C_I2CMODE_ENABLE,I2C_ADDFORMAT_7BITS,mAddI2C);
    /* enable I2C0 */
    i2c_enable(I2C0);
    /* enable acknowledge */
    i2c_ack_config(I2C0,I2C_ACK_ENABLE);
}
void I2CClkOut(void)
{
	U8 i;
	//PB8 to I2C0_SCL 
	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit8);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit8);
	for(i=0;i<10;i++)
	{
		GPIO_BOP(GPIOB)	=mBit8;							//置信号
		Dly1us(3);
		GPIO_BC(GPIOB)	=mBit8;							//清信号
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
			
	I2CErrCnt=0;	//复位出错计数
I2CStart:
	ToteByte=Datalen;
	pD=WriteBuffer;
	
	//等待总线空闲
	I2C_RstTimer();
	while(i2c_flag_get(I2C0, I2C_FLAG_I2CBSY))	
	{	
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	//启动总线	发送启始
	i2c_start_on_bus(I2C0);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_SBSEND))
	{
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	
	//发器件地址	Slave	
	i2c_master_addressing(I2C0, Slave, I2C_TRANSMITTER);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_ADDSEND))
	{	
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	i2c_flag_clear(I2C0,I2C_FLAG_ADDSEND);
	
	//发高地址
	if(Addr16Flag)
	{
		i2c_data_transmit(I2C0, (Address>>8)&0x00ff);
		
		I2C_RstTimer();
		while(!i2c_flag_get(I2C0, I2C_FLAG_TBE))
		{
			if(I2C_OverTimeChk())		//超时未完成	
				goto I2CErr;
		}
	}
	//发低地址
	i2c_data_transmit(I2C0, (Address>>0)&0x00ff);
		
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_TBE))
	{
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	//发数据
	 while(ToteByte--)
	 {  
        i2c_data_transmit(I2C0, *pD);
        pD++; 
        //等待数据发送完成
        I2C_RstTimer();
       	while(!i2c_flag_get(I2C0, I2C_FLAG_TBE))     
       	{
			if(I2C_OverTimeChk())		//超时未完成	
				goto I2CErr;
		}   
    }
    //发送结束条件
	i2c_stop_on_bus(I2C0);
	
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
	
    i2c_disable(I2C0);
    rcu_periph_reset_enable(RCU_I2C0RST);
    rcu_periph_reset_disable(RCU_I2C0RST);
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
	
	I2CErrCnt=0;	//复位出错计数	
	if(Datalen==0)return mTrue;
	
I2CStart:	
    ToteByte=Datalen;
    
	//等待总线空闲
	I2C_RstTimer();
	while(i2c_flag_get(I2C0, I2C_FLAG_I2CBSY))	
	{	
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	//启动总线	发送启始
	i2c_start_on_bus(I2C0);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_SBSEND))
	{
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	//发器件地址	Slave	
	i2c_master_addressing(I2C0, Slave, I2C_TRANSMITTER);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_ADDSEND))
	{	
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	i2c_flag_clear(I2C0,I2C_FLAG_ADDSEND);
	
	//发高地址
	if(Addr16Flag)
	{
		i2c_data_transmit(I2C0, (Address>>8)&0x00ff);
		
		I2C_RstTimer();
		while(!i2c_flag_get(I2C0, I2C_FLAG_TBE))
		{
			if(I2C_OverTimeChk())		//超时未完成	
				goto I2CErr;
		}
	}
	//发低地址
	i2c_data_transmit(I2C0, (Address>>0)&0x00ff);
		
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_TBE))
	{
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	//重新发送启始信号
	i2c_start_on_bus(I2C0);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_SBSEND))
    {
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
    //发器件地址	Slave	
	i2c_master_addressing(I2C0, Slave, I2C_RECEIVER);
	
	I2C_RstTimer();
	while(!i2c_flag_get(I2C0, I2C_FLAG_ADDSEND))
	{	
		if(I2C_OverTimeChk())		//超时未完成	
			goto I2CErr;
	}
	i2c_flag_clear(I2C0,I2C_FLAG_ADDSEND);		
	
	
	//读数据
	for(i=0;i<ToteByte;i++)
	{
        //设置要不要应答
        if(i>=(ToteByte-1))
            i2c_ack_config(I2C0, I2C_ACK_DISABLE);
        else
            i2c_ack_config(I2C0, I2C_ACK_ENABLE);
    
    
		I2C_RstTimer();
        while(!i2c_flag_get(I2C0, I2C_FLAG_RBNE))
        {	
            if(I2C_OverTimeChk())		//超时未完成	
                goto I2CErr;
        }
        *(ReadBuffer+i)=i2c_data_receive(I2C0);
	}
	//产生结束信号
	i2c_stop_on_bus(I2C0);
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
	
    i2c_disable(I2C0);
    rcu_periph_reset_enable(RCU_I2C0RST);
    rcu_periph_reset_disable(RCU_I2C0RST);
    I2Cx_Drv_Init();
	if(I2CErrCnt<3)
	{	//允许3次出错
		I2CErrCnt++;
		goto I2CStart;
	}
	else
		return mFalse;		
}

///*************************************************************************
//函数说明: I2C1初始化——软件模拟
//输入参数: Address,从器件写地址；Datalen,要发送的数据长度；
//    	  WriteBuffer[],要发送的数据
//输出参数: 无
//返 回 值: mTrue, 发送完成；mFalse,发送未完成
//          调用前先指定从器件地址：SlaveAddr
//**************************************************************************/
//void I2Cx_Drv_Init(void)
//{					     
//  RCC->AHB1ENR|=1<<1;	    //使能PORTB口时钟	
//	GPIO_Set(GPIOB,mBit8|mBit9,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//PB8/PB9设置 
//	IIC_SCL(1);
//	IIC_SDA(1);
//}
///****************************************************************************************************
//函数名称：延时n*100ns
//函数说明：
//输入参数：DlyTi--延时时间，单位100ns
//返 回 值：无
//其    它：
//****************************************************************************************************/
//void Dly100ns(U32 DlyTi)
//{
//	G10nsTimer t;
//	DlyTi=DlyTi*10;
//	G10nsTimerRes(&t);
//	while(G10nsTimerLess(&t,DlyTi)){;}
//}
///****************************************************************************************************
//函数名称：产生IIC起始信号
//函数说明：
//输入参数：
//返 回 值：无
//其    它：
//****************************************************************************************************/
//void IIC_Start(void)
//{
//	SDA_OUT();	//sda线输出
//	IIC_SDA(1);	  	  
//	IIC_SCL(1);
//	Dly100ns(8);
// 	IIC_SDA(0);//START:when CLK is high,DATA change form high to low 
//	Dly100ns(8);
//	IIC_SCL(0);//钳住I2C总线，准备发送或接收数据 
//}	  
///****************************************************************************************************
//函数名称：产生IIC停止信号
//函数说明：
//输入参数：
//返 回 值：无
//其    它：
//****************************************************************************************************/
//void IIC_Stop(void) 
//{
//	SDA_OUT();//sda线输出
//	IIC_SCL(0);
//	IIC_SDA(0);//STOP:when CLK is high DATA change form low to high
// 	Dly100ns(8);
//	IIC_SCL(1); 
//	Dly100ns(8);	
//	IIC_SDA(1);//发送I2C总线结束信号						   	
//}
///****************************************************************************************************
//函数名称：等待应答信号到来
//函数说明：
//输入参数：
//返 回 值：FALSE，接收应答失败
//          TRUE，接收应答成功
//其    它：
//****************************************************************************************************/
//U8 IIC_Ack_Chk(void) //ack信号检测
//{
//	SDA_IN();      //SDA设置为输入  
//	IIC_SDA(1);Dly100ns(8);	   
//	IIC_SCL(1);Dly100ns(8);	 
//	I2C_RstTimer();	//开始定时	
//	
//	while(READ_SDA)
//	{
//		if(I2C_OverTimeChk())	//超时
//		{
//			IIC_Stop();
//			return FALSE;
//		}
//	}
//	IIC_SCL(0);//时钟输出0 	   
//	return TRUE;  
//} 
///****************************************************************************************************
//函数名称：产生ACK应答
//函数说明：
//输入参数：
//返 回 值：无
//其    它：
//****************************************************************************************************/
//void IIC_Ack(void)
//{
//	IIC_SCL(0);
//	SDA_OUT();
//	IIC_SDA(0);
//	Dly100ns(8);
//	IIC_SCL(1);
//	Dly100ns(8);
//	IIC_SCL(0);
//}
///****************************************************************************************************
//函数名称：不产生ACK应答
//函数说明：
//输入参数：
//返 回 值：无
//其    它：
//****************************************************************************************************/	    
//void IIC_NAck(void)
//{
//	IIC_SCL(0);
//	SDA_OUT();
//	IIC_SDA(1);
//	Dly100ns(8);
//	IIC_SCL(1);
//	Dly100ns(8);
//	IIC_SCL(0);
//}					 				     
///****************************************************************************************************
//函数名称：IIC发送一个字节
//函数说明：
//输入参数：
//返 回 值：无
//其    它：
//****************************************************************************************************/		  
//void IIC_Send_Byte(U8 txd)
//{                        
//	U8 t;   
//	SDA_OUT(); 	    
//	IIC_SCL(0);//拉低时钟开始数据传输
//	for(t=0;t<8;t++)
//	{              
//		IIC_SDA((txd&0x80)>>7);
//		txd<<=1; 	  
//	  IIC_SCL(1);
//		Dly100ns(8); 
//		IIC_SCL(0);	
//		Dly100ns(8);
//	}	 
//} 
///****************************************************************************************************
//函数名称：IIC读1个字节
//函数说明：
//输入参数：ack=1时，发送ACK，ack=0，发送nACK 
//返 回 值：
//其    它：
//****************************************************************************************************/	  
//U8 IIC_Read_Byte(unsigned char ack)
//{
//	unsigned char i,receive=0;
//	SDA_IN();//SDA设置为输入
//  for(i=0;i<8;i++ )
//	{
//		IIC_SCL(0); 
//		Dly100ns(8);
//		IIC_SCL(1);
//		receive<<=1;
//		if(READ_SDA)receive++;   
//		Dly100ns(8);
//  }					 
//  if(!ack)
//		IIC_NAck();//发送nACK
//  else
//		IIC_Ack(); //发送ACK   
//  return receive;
//}
///*************************************************************************
//函数说明: 发送数据
//输入参数: Slave，从器件地址或页地址；
//		  Address,从器件写地址；Datalen,要发送的数据长度；
//    	  WriteBuffer[],要发送的数据；Addr16Flag,地址是16位标志
//输出参数: 无
//返 回 值: mTrue, 发送完成；mFalse,发送未完成
//          调用前先指定从器件地址：SlaveAddr
//          
//注    意: Datalen的长度不能超过器件缓冲区的长度
//**************************************************************************/
//Bool I2CWrite(U8 Slave,U16 Address,U16 Datalen,U8 *WriteBuffer,Bool Addr16Flag)
//{
//	U8 I2CErrCnt=0;	//出错计数
//	U16 i;
//  Slave=((Slave<<1)&0x0f)|0xa0;//器件地址处理，R/w位置0	，0xa0写命令
//I2CStart:
//	//启动总线		发器件地址	Slave	
//	IIC_Start();
//	IIC_Send_Byte(Slave);	    //发送Slave
//  if(IIC_Ack_Chk()!=TRUE) goto I2CErr; //ack信号检测
//	//发高地址
//	if(Addr16Flag)
//	{		
//		IIC_Send_Byte((Address>>8)&0x00ff);	    //
//		if(IIC_Ack_Chk()!=TRUE) goto I2CErr; //ack信号检测
//	}
//	//发低地址
//	IIC_Send_Byte((Address)&0x00ff);	
//	if(IIC_Ack_Chk()!=TRUE) goto I2CErr; //ack信号检测
//	for(i=0;i<Datalen;i++)//发数据
//	{
//		IIC_Send_Byte(WriteBuffer[i]);
//		if(IIC_Ack_Chk()!=TRUE) goto I2CErr; //ack信号检测
//	}
//	IIC_Stop(); //产生IIC停止信号	
//	return mTrue;
//	
//	//出错处理
//I2CErr:	
//	if(I2CErrCnt<2)
//	{	//允许3次出错
//		I2CErrCnt++;
//		goto I2CStart;
//	}
//	else
//		return mFalse;			
//}
///*************************************************************************
//函数说明: 读取数据
//输入参数: Address,从器件写地址；Datalen,要发送的数据长度；
//    	  ReadBuffer[],读取的数据；Addr16Flag,地址是16位标志
//输出参数: 无
//返 回 值: mTrue, 读成功；mFalse,读失败
//          调用前先指定从器件地址：SlaveAddr
//注    意：最后一个字节读出后，必须发出的是非应答信号，否则可能出现竞争。
//**************************************************************************/
//Bool I2CRead(U8 Slave,U16 Address,U16 Datalen,U8 *ReadBuffer,Bool Addr16Flag)
//{
//	U8 I2CErrCnt=0;	//出错计数
//	U8 SlaveWr;
//	U16 i;	
//	
//	SlaveWr=Slave;
//	Slave=((Slave<<1)&0x0f)+0xa1;//0xa1读命令 
//	if(Datalen==0)return mTrue;
//	
//I2CStart:	
//	if(!I2CWrite(SlaveWr,Address,0,&I2CErrCnt,Addr16Flag))	//空写,定位指针
//		return mFalse;	//失败
//	IIC_Start();
//	IIC_Send_Byte(Slave);	    //发送SlaveRD
//  if(IIC_Ack_Chk()!=TRUE) goto I2CErr; //ack信号检测
//  for(i=0;i<Datalen-1;i++)
//	{
//		ReadBuffer[i]=IIC_Read_Byte(1);
//	}
//	ReadBuffer[i]=IIC_Read_Byte(0);//noack
//	IIC_Stop(); //产生IIC停止信号	
//	return mTrue;
//	//出错处理
//I2CErr:		
//	if(I2CErrCnt<2)
//	{	//允许3次出错
//		I2CErrCnt++;
//		goto I2CStart;
//	}
//	else
//		return mFalse;		
//}
