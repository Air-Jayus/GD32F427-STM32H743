/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：xxxxxx
文件说明：xxxxxx

作    者：CXQ
编写时间：2012.03
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================
动作文件命名  ：动作名称_特点					特点如二板机、双色机等；或针对某厂家特殊机型。
												如未标示，则默认HT、常规三板机。
动作函数命名  ：Act_动作名称_模式_特点_序号		模式指手动(MM)、调模(AM)、自动(AU)、多种(MU或无)
												特点如某机型、某厂家的特有机型等
												序号用A、B、C……
动作函数ID命名：mASID_函数名_段名				

****************************************************************************************************/
#ifndef AL_AutoGate_h
	#define AL_AutoGate_h

#ifdef AL_AutoGate_c
	#define AL_AutoGate_ext
#else
	#define AL_AutoGate_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_AutoGateCls(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_AutoGateCls				10	//关自动门
	#define mASID_AL_AutoGateCls_SnrErrOpen		11	//开自动门				安全检知异常转开门	20130313

void AL_AutoGateOpen(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_AutoGateOpen		10	//开自动门

void AutoGate_Pcs(void);							//自动门处理			主要是检查自动门按钮是否有按下，以开关自动门，在主循环调用执行
void AutoGateLinkPcs(void *FP,FActAttrStr *FAAP);	//自动门连动处理		本函数于AU_MoldOpen()中调用执行


ActConf_ext Bool AutoGateClsButtPushFlag;	//自动门关按钮按下标志
ActConf_ext Bool AutoGateOpenButtPushFlag;	//自动门开按钮按下标志

ActConf_ext Bool AutoGateOpenEndFlag;		//自动门开到位标志	20141231应KEB加
#ifdef ActConf_c
	Bool AutoGateDotClsFlag=mTrue;			//点动关门标志		20141231应KEB加，点动关门时要求常按关门按钮
#else
	extern Bool AutoGateDotClsFlag;			//点动关门标志		20141231应KEB加，点动关门时要求常按关门按钮
#endif


#endif

