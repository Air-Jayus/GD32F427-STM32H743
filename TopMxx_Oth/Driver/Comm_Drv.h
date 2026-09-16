/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：Comm_Drv.h
文件说明：串口通讯文件

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
#ifndef Comm_Drv_h
	#define Comm_Drv_h

#ifdef Comm_Drv_c
	#define Comm_Drv_ext
#else
	#define Comm_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
#define mPeriParaReadMax	32	//外设不连续参数一次读取的最大数量

/*======================================== 全局有效变量定义 =======================================*/
typedef struct
{
	U16				Sn;			//参数序号	
	U32				Data;		//数据
}PeriParaWriteReqStr;	//外设参数写请求序号

typedef struct
{
	U16				Sn[mPeriParaReadMax+1];			//参数序号	
}PeriParaReadReqStr;	//外设参数读请求序号

Comm_Drv_ext PeriParaWriteReqStr	PeriParaWriteReq;	//请求写入的外设参数
Comm_Drv_ext PeriParaReadReqStr		PeriParaReadReq;	//请求读取的外设参数

/*======================================== 全局有效函数声明 =======================================*/
Bool CommLinkOKChk(void);				//通讯联机正常检查

void Comm_Drv_Init(void);				//Comm驱动初始化
void Comm_Drv_Pcs(void);				//Comm处理函数		主循环中执行 

Bool ParaIsModify(void);				//参数有修改
Bool ManuParaIsModify(void);			//生产参数有修改
Bool MachParaIsModify(void);			//机器参数有修改
Bool PeriParaIsModify(void);			//外设参数有修改
Bool HardConfIsModify(void);			//硬件配置有修改
Bool WorkStateIsRead(void);				//工作状态被读走		20210608加：蒙德多个驱动器时，状态轮流经WorkState[]返回，所以用到

U32 GetManuParaModifySn(void);			//获取当前被修改生产参数的起始序号

U8 GetCommRecCode(void);				//获取通讯接收命令
U8 GetCommRecCodePara0(void);			//获取通讯接收命令参数0
U8 GetCommRecCodePara1(void);			//获取通讯接收命令参数1
U8 GetCommRecCodePara2(void);			//获取通讯接收命令参数2
U8 GetCommRecCodePara3(void);			//获取通讯接收命令参数3
U8 GetCommRecCodePara4(void);			//获取通讯接收命令参数4
U8 GetCommRecCodePara_SN(U32 SN);		//获取通讯接收命令第N个参数

#endif
