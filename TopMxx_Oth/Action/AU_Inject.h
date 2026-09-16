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
动作文件命名  ：动作名称_特点					特点如二板机、双色机等；或针对某厂家特殊机型。
												如未标示，则默认HT、常规三板机。
动作函数命名  ：Act_动作名称_模式_特点_序号		模式指手动(MM)、调模(AM)、自动(AU)、多种(MU或无)
												特点如某机型、某厂家的特有机型等
												序号用A、B、C……
动作函数ID命名：mASID_函数名_段名				

****************************************************************************************************/
#ifndef AU_Inject_h
	#define AU_Inject_h

#ifdef AU_Inject_c
	#define AU_Inject_ext
#else
	#define AU_Inject_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AU_Inject(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Inject_Inj1			10	//注射一
	#define mASID_AU_Inject_Inj2			15	//注射二
	#define mASID_AU_Inject_Inj3			20	//注射三
	#define mASID_AU_Inject_Inj4			25	//注射四
	#define mASID_AU_Inject_Inj5			30	//注射五
	#define mASID_AU_Inject_Inj6			35	//注射六
	#define mASID_AU_Inject_Inj7			40	//注射七
	#define mASID_AU_Inject_Inj8			45	//注射八
	#define mASID_AU_Inject_Inj9			50	//注射九
	#define mASID_AU_Inject_Inj10			55	//注射十
	#define mASID_AU_HoldPres_HP1			60	//保压一	在排气中引用，注意修改
	#define mASID_AU_HoldPres_HP2			65	//保压二	在排气中引用，注意修改
	#define mASID_AU_HoldPres_HP3			70	//保压三	在排气中引用，注意修改
	#define mASID_AU_HoldPres_HP4			75	//保压四
	#define mASID_AU_HoldPres_HP5			80	//保压五
	#define mASID_AU_HoldPres_HP6			85	//保压六
	#define mASID_AU_HoldPres_HP7			90	//保压七
	#define mASID_AU_HoldPres_HP8			95	//保压八
	#define mASID_AU_HoldPres_HP9			100	//保压九
	#define mASID_AU_HoldPres_HP10			105	//保压十

void AU_Inject_AM(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Inject_AM_Inj			10	//调模注射

void AU_InjBefNozFor(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_InjBefNozFor_Inj		10	//座进前注射

void AU_PrgInject(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_PrgInject_Inj			10	//清料注射

void Inject2_Pcs(void);		//20140325加,本函数由ActConf_Pcs()调用，相当于在主循环执行

void AU_InjComp(void *FP,FActAttrStr *FAAP);	//压缩注射
	#define mASID_AU_InjComp_Inj1			10	//注射一
	#define mASID_AU_InjComp_Inj2			15	//注射二
	#define mASID_AU_InjComp_Inj3			20	//注射三
	#define mASID_AU_InjComp_Inj4			25	//注射四
	#define mASID_AU_InjComp_Inj5			30	//注射五
	#define mASID_AU_InjComp_Inj6			35	//注射六
	#define mASID_AU_InjComp_Inj7			40	//注射七
	#define mASID_AU_InjComp_Inj8			45	//注射八
	#define mASID_AU_InjComp_Inj9			50	//注射九
	#define mASID_AU_InjComp_Inj10			55	//注射十


#endif

