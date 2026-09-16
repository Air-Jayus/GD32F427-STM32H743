/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：Can_Drv.c
文件说明：CAN驱动文件

作    者：WLZ
编写时间：2020.4
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================



****************************************************************************************************/
#ifndef Can_Drv_h
	#define Can_Drv_h

#ifdef Can_Drv_c
	#define Can_Drv_ext
#else
	#define Can_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
//波特率计算公式：Baud=CANClk/预分频/(1+BS1+BS2)	本系统CANClk=50M
//#define		mCanBaud_500K		((1<<20)|(8<<16)|(10<<0))			//采样率在80%	BS1=1；	BS2=8；预分频=10
//#define		mCanBaud_1000K		((1<<20)|(8<<16)|(5<<0))			//采样率在80%	BS1=1；	BS2=8；预分频=5
#define		mCanBaud_100K		100000			//采样率在80%	BS1=7；	BS2=2；预分频=50	全部减1
#define		mCanBaud_500K		500000			//采样率在80%	BS1=7；	BS2=2；预分频=10	全部减1
#define		mCanBaud_1000K		1000000			//采样率在80%	BS1=7；	BS2=2；预分频=5

#define mCC_CAN1		0			//CAN通道1
#define mCC_CAN2		1			//CAN通道2

#define CAN2_StartBank	14	//CAN2 滤波寄存器组开始序号
#define CAN_FiltBankEnd 28	//CAN全部滤波寄存器组结束序号28

typedef struct{
	U32 Head;	//数据长度
	U32 ID;		//ID
	U32 HData;
	U32 LData;
}CanMessStr;						//CAN报文结构

/*======================================== 全局有效变量定义 =======================================*/


/*======================================== 全局有效函数声明 =======================================*/
void CanSendIrqEn(U32 CanSN);
void CanSendIrqDis(U32 CanSN);
void CanRS485_IO_Init(void);
void Can_Drv_Init(U32 CanSN,U32 Baud);
Bool AddAnCanRxIrq(U32 CanSN, void (* CallBackP)());
Bool AddAnCanTxIrq(U32 CanSN, void (* CallBackP)());
Bool Can_AddAnFilter(U32 CanSN,U32 Id,U32 Mask,U32 Mode);
Bool CanRecMessage(U32 CanSN,U8 MailSN,CanMessStr *CMP);
Bool CanSendMessage(U32 CanSN,CanMessStr *CMP);
Bool CanSendMessageRTR(U32 CanSN,U32 ID);
void CAN1_RX0_IRQHandler(void);
void CAN2_RX0_IRQHandler(void);
void CAN1_TX_IRQHandler(void);
void CAN2_TX_IRQHandler(void);
void CAN1_SCE_IRQHandler(void);
void CAN2_SCE_IRQHandler(void);

#endif
