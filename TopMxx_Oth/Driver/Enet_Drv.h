/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：Enet_Drv.h
文件说明：以太网驱动文件

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


****************************************************************************************************/
#ifndef Enet_Drv_h
	#define Enet_Drv_h


#ifdef Enet_Drv_c
	#define Enet_Drv_ext 
#else
	#define Enet_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
//#define mRxBuffNum			2							//以太网帧接收缓存个数
//#define mTxBuffNum			2							//以太网帧发送缓存个数，经测至少需要2个描述符，循环使用不然发送会出错

//#define mEnetFramBuffLen 	1524						//
//#define mEnetTxBuffAddr		0x2000e700					//
//#define mEnetRxBuffAddr		0x2000e700+mEnetFramBuffLen*mTxBuffNum	//


/*======================================== 全局有效变量定义 =======================================*/
//Enet_Drv_ext ETH_HandleTypeDef ETH_Hand;      //以太网句柄
//Enet_Drv_ext ETH_DMADescTypeDef RxDscrTab[mRxBuffNum] __attribute__((at(0x20007000)));	//以太网DMA接收描述符数据结构体指针
//Enet_Drv_ext ETH_DMADescTypeDef TxDscrTab[mTxBuffNum] __attribute__((at(0x20007200)));	//以太网DMA发送描述符数据结构体指针 
//Enet_Drv_ext U8 RxBuff[mRxBuffNum][mEnetFramBuffLen] __attribute__((at(mEnetRxBuffAddr)));	//以太网底层驱动接收buffers指针 
//Enet_Drv_ext U8 TxBuff[mTxBuffNum][mEnetFramBuffLen] __attribute__((at(mEnetTxBuffAddr)));	//以太网底层驱动发送buffers指针
//Enet_Drv_ext U8 TXBuffer[mEnetFramBuffLen] __attribute__((at(mEnetTxBuffAddr)));	//发送缓存
//Enet_Drv_ext U8 RXBuffer[mEnetFramBuffLen] __attribute__((at(mEnetRxBuffAddr)));	//接收缓存

//Enet_Drv_ext U8 __attribute__((aligned (4))) TXBuffer[mEnetFramBuffLen];	//发送缓存
//Enet_Drv_ext U8 __attribute__((aligned (4))) RXBuffer[mEnetFramBuffLen];	//接收缓存
/*======================================== 全局有效函数声明 =======================================*/
void Ecat_FrameHeaderSet(void);
void Enet_IODrv_Init(void);
Bool Enet_Link_Init(void);
Bool Enet_Drv_Init(void);
void Enet_Drv_Pcs(void);
Bool Enet_TxCompCheck(void);
//Bool Enet_TxQueue(ETH_HandleTypeDef *ETH_Hand,U32 Bytes);
Bool PhyLinkOk(void);
//U32  Enet_GetRxPktSize(ETH_DMADescTypeDef *DMARxDesc);
void ETH_RecProcess(void);

#endif


