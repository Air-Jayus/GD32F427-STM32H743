/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：xxxxxx
文件说明：xxxxxx

作    者：LC
编写时间：2025.3
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================



****************************************************************************************************/
#ifndef RobotCommunication_Drv_h
	#define RobotCommunication_Drv_h


#ifdef RobotCommunication_Drv_c
	#define RobotCommunication_Drv_ext
#else
	#define RobotCommunication_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
#define GetRobotIO() GetRobotIO		//获取机械手IO状态
#define SetRobotIO() SetRobotIO		//设置机械手IO状态

/*======================================== 全局有效变量定义 =======================================*/
RobotCommunication_Drv_ext U16 GetRobotIO;		//获取机械手IO状态
	#define	mCI_RobotRetEnd			mBit0	//机械手回到位
	#define	mCI_RobotOptMode		mBit2	//机械手不用
	#define	mCI_EmerStop			mBit3	//机械手紧停
	#define	mCI_CycStart			mBit4	//循环启动
	#define	mCI_MoldAreaFree		mBit5	//模区安全
	#define	mCI_EnClamp				mBit6	//关模允许
	#define	mCI_EnMoldOpen			mBit7	//开模允许
	#define	mCI_EnFullMoldOpen		mBit8	//全开模允许
	#define	mCI_EnEjeFor			mBit9	//托模进允许
	#define	mCI_EnEjeRet			mBit10	//托模退允许
	#define	mCI_EnCoreIn			mBit11	//中子进允许
	#define	mCI_EnCoreOut			mBit12	//中子退允许
	
RobotCommunication_Drv_ext U16 SetRobotIO;		//设置机械手IO状态
	#define	mCO_RobotRun			mBit0	//机械手
	#define	mCO_EmerStopOut			mBit2	//系统紧急停止
	#define	mCO_SafeGate			mBit3	//安全门
	#define	mCO_AutoMode			mBit4	//自动方式
	#define	mCO_ClampEnd			mBit5	//关模到位
	#define	mCO_MoldOpenEnd			mBit6	//开模到位
	#define	mCO_MidMoldOpen			mBit7	//中途取件位置到
	#define	mCO_EjeForEnd			mBit8	//托模进到位
	#define	mCO_EjeRetEnd			mBit9	//托模退到位
	#define	mCO_CoreInEnd			mBit10	//中子进到位
	#define	mCO_CoreOutEnd			mBit11	//中子退到位
	#define	mCO_Reject 				mBit12	//不良品
	#define	mCO_FullAutoMode		mBit13	//全自动方式
	
/*======================================== 全局有效函数声明 =======================================*/
void RobotComm_Drv_Init(void);			//CAN 模块初始化
void RobotComm_Drv_Pcs(void);			//CAN 模块处理

#endif
