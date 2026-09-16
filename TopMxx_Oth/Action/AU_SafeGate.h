/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：xxxxxx
文件说明：xxxxxx

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================



****************************************************************************************************/
#ifndef AU_SafeGate_h
	#define AU_SafeGate_h

#ifdef AU_SafeGate_c
	#define AU_SafeGate_ext
#else
	#define AU_SafeGate_ext extern
#endif

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//

void AU_SafeGateCls(void *FP,FActAttrStr *FAAP);			//请关安全门		主要用于关模前
	#define mASID_AU_SafeGateCls_WaitCls			10		//等待关安全门		Act_SafeGate_ClsPrompt()

void AU_SafeGateOpenCls(void *FP,FActAttrStr *FAAP);		//开关安全门		主要用于自动模式开始、半自动循环结束
	#define mASID_AU_SafeGateOpenCls_WaitOpen		10		//等待关安全门		Act_SafeGate_ClsPrompt()
	#define mASID_AU_SafeGateOpenCls_WaitCls		20		//等待开安全门		Act_SafeGate_ClsPrompt()

Bool SG_FrontIsCls(void);									//前安全门关着检查
Bool SG_FrontIsOpen(void);									//前安全门开着检查
Bool SG_BackIsCls(void);									//后安全门关着检查
Bool SG_AllIsCls(void);										//所有安全门关着检查
U16 SG_AllIsCls_UnClsAlarm(void);							//所有安全门关着检查	未关返回警报代码

#endif

