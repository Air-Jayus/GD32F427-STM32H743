/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：SimBus_Drv.c
文件说明：模拟总线文件

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
1、地址线A0～A5		PE8~PE13
   数据线D0～D7		PE0~PE7
   写信号WR			PE15
   读信号RD			PE14
   CPLD总线复位 CPLD_RST PD15
##其它说明


****************************************************************************************************/
//#define mSysDebug		

#ifndef SimBus_Drv_c
	#define SimBus_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define	SB_SetRd()		GPIO_BOP(GPIOE)	=mBit14							//置Rd信号
#define SB_ClrRd()		GPIO_BC(GPIOE)	=mBit14							//清Rd信号
#define SB_SetWr()		GPIO_BOP(GPIOE)	=mBit15							//置Wr信号
#define SB_ClrWr()		GPIO_BC(GPIOE)	=mBit15							//清Wr信号
#define	SB_SetDir()		//GPIO_BOP(GPIOB)	=mBit0							//置Dir信号，数据方向设置为输出
#define SB_ClrDir()		//GPIO_BC(GPIOB)	=mBit0							//清Dir信号，数据方向设置为输入
#define	SB_SetRst()		GPIO_BOP(GPIOD)	=mBit15							//置Rst信号，复位释放，总线使能
#define SB_ClrRst()		GPIO_BC(GPIOD)	=mBit15							//清Rst信号，复位数据总线
#define SB_SetAddr(a)	GPIO_BOP(GPIOE)	=((((a)&0x003f)<<8)|((((~(a))&0x003f))<<(8+16)))		//设地址
//数据总线   
#define SB_SetDataRdDir()	GPIO_CTL(GPIOE)	&=(~(0x0000ffff))					//数据读方向
#define SB_SetDataWrDir()	GPIO_CTL(GPIOE)	|=(0x00005555)						//数据写方向
#define SB_SetData(d)		GPIO_BOP(GPIOE)	=(((d)&0xff)|(((~(d))&0xff)<<16))	//设数据	
#define SB_GetData()		(GPIO_ISTAT(GPIOE)&0xff)							//获取数据


/*======================================= 模块内有效变量定义 ======================================*/


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
函数名称：模拟总线初始化
函数说明：
输入参数：
返 回 值：
其    它：
1、地址线A0～A5				PE8~PE13
   数据线D0～D7				PE0~PE7
   写信号WR						PE15
   读信号RD						PE14
   CPLD总线复位RST 		PD15
	 读写方向切换DDIR 	PB0
****************************************************************************************************/
void SimBus_Drv_Init(void)
{
	// enable the LEDs GPIO clock 
    //rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);
  
	SB_ClrRst();			//复位总线
	SB_SetWr();				//复位Wr
	SB_SetRd();				//复位Rd
	SB_SetDir();       //复位Dir
	SB_SetAddr(0);		//地址输出为0x00
	
	//数据线D0～D7		PE0~PE7
    gpio_mode_set(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit0|mBit1|mBit2|mBit3|mBit4|mBit5|mBit6|mBit7);
    gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit0|mBit1|mBit2|mBit3|mBit4|mBit5|mBit6|mBit7);
	//设置为输出：地址线A0～A5	PE8~PE13		PE14~PE15读写控制线
	gpio_mode_set(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit8|mBit9|mBit10|mBit11|mBit12|mBit13|mBit14|mBit15);
    gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit8|mBit9|mBit10|mBit11|mBit12|mBit13|mBit14|mBit15);
    //设置为输出：CPLD_RST PD15
	gpio_mode_set(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit15);
    gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit15);
	//SN74LVC16245读写方向切换 PB0	设置值为输出
	//gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit0);
    //gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit0);
    
	SB_SetRst();		//总线使能
	SB_SetAddr(0);		//地址输出为0x00	
}

/****************************************************************************************************
函数名称：模拟总线读数据
函数说明：
输入参数：U8 Addr--地址
返 回 值：
其    它：
****************************************************************************************************/
U8 SB_ReadData(U16 Addr)
{
	U8 Buff;
	
	SB_ClrDir();	          //设置SN74LVC16245数据方向设置为输入
	SB_SetDataRdDir();			//数据读入方向
	SB_SetAddr(Addr);				//地址输出
	SB_ClrRd();							//Rd有效
	__NOP(),__NOP();				//延时		
	__NOP(),__NOP();				//延时		
	__NOP(),__NOP();				//延时
	Buff=SB_GetData();			//读取
	SB_SetRd();							//Rd无效

	return Buff;
}
/****************************************************************************************************
函数名称：模拟总线写数据
函数说明：
输入参数：U8 Addr--地址，注意不连续的，中间空了3位
返 回 值：
其    它：
****************************************************************************************************/
void SB_WriteData(U16 Addr,U8 Buff)
{	
	SB_SetDir();            //设置SN74LVC16245数据方向设置为输出
	SB_SetDataWrDir();			//数据输出方向
	SB_SetAddr(Addr);				//地址输出
	SB_SetData(Buff);				//数据输出	
	SB_ClrWr();						  //Wr有效
	__NOP(),__NOP();				//延时
	__NOP(),__NOP();				//延时
	SB_SetWr();						  //Wr无效
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
