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
#define	SB_SetRd()		GPIOE->BSRR	=mBit14									//置Rd信号
#define SB_ClrRd()		GPIOE->BSRR	=((U32)mBit14<<16)						//清Rd信号
#define SB_SetWr()		GPIOE->BSRR	=mBit15									//置Wr信号
#define SB_ClrWr()		GPIOE->BSRR	=((U32)mBit15<<16)						//清Wr信号
#define	SB_SetDir()		//GPIOB->BSRR	=mBit0								//置Dir信号，数据方向设置为输出（新硬件无SN74LVC16245，不使用）
#define SB_ClrDir()		//GPIOB->BSRR	=((U32)mBit0<<16)					//清Dir信号，数据方向设置为输入（同上）
#define	SB_SetRst()		GPIOD->BSRR	=mBit15									//置Rst信号，复位释放，总线使能
#define SB_ClrRst()		GPIOD->BSRR	=((U32)mBit15<<16)						//清Rst信号，复位数据总线
#define SB_SetAddr(a)	GPIOE->BSRR	=(((((a)&0x003f)<<8)|((((~(a))&0x003f))<<(8+16))))		//设地址
//数据总线
#define SB_SetDataRdDir()	GPIOE->MODER	&=(~(0x0000ffff))					//数据读方向
#define SB_SetDataWrDir()	GPIOE->MODER	|=(0x00005555)						//数据写方向
#define SB_SetData(d)		GPIOE->BSRR	=(((d)&0xff)|(((~(d))&0xff)<<16))		//设数据
#define SB_GetData()		(GPIOE->IDR&0xff)								//获取数据


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
   写信号WR					PE15
   读信号RD					PE14
   CPLD总线复位RST 			PD15
****************************************************************************************************/
void SimBus_Drv_Init(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	// 使能GPIO时钟
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOD);
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);

	SB_ClrRst();			//复位总线
	SB_SetWr();				//复位Wr
	SB_SetRd();				//复位Rd
	SB_SetDir();       //复位Dir
	SB_SetAddr(0);		//地址输出为0x00

	//数据线D0～D7		PE0~PE7	推挽输出，上拉，高速
	GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1|LL_GPIO_PIN_2|LL_GPIO_PIN_3|LL_GPIO_PIN_4|LL_GPIO_PIN_5|LL_GPIO_PIN_6|LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	//设置为输出：地址线A0～A5	PE8~PE13		PE14~PE15读写控制线
	GPIO_InitStruct.Pin = LL_GPIO_PIN_8|LL_GPIO_PIN_9|LL_GPIO_PIN_10|LL_GPIO_PIN_11|LL_GPIO_PIN_12|LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
	LL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    //设置为输出：CPLD_RST PD15
	GPIO_InitStruct.Pin = LL_GPIO_PIN_15;
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

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
	
	SB_ClrDir();	          //数据方向设置为输入
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
	SB_SetDir();            //数据方向设置为输出
	SB_SetDataWrDir();			//数据输出方向
	SB_SetAddr(Addr);				//地址输出
	SB_SetData(Buff);				//数据输出	
	SB_ClrWr();						  //Wr有效
	__NOP(),__NOP();				//延时
	__NOP(),__NOP();				//延时
	SB_SetWr();						  //Wr无效
}
