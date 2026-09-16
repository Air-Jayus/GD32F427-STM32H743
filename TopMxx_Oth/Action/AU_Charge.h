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
#ifndef AU_Charge_h
	#define AU_Charge_h

#ifdef AU_Charge_c
	#define AU_Charge_ext
#else
	#define AU_Charge_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AU_Charge(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Charge_Chg1		10	//储料一
	#define mASID_AU_Charge_Chg2		15	//储料二
	#define mASID_AU_Charge_Chg3		20	//储料三
	#define mASID_AU_Charge_Chg4		25	//储料四
	#define mASID_AU_Charge_Chg5		30	//储料五
	#define mASID_AU_Charge_Chg6		35	//储料六
	#define mASID_AU_Charge_Chg7		40	//储料七
	#define mASID_AU_Charge_Chg8		45	//储料八
	#define mASID_AU_Charge_Chg9		50	//储料九
	#define mASID_AU_Charge_Chg10		55	//储料十

void AU_Charge_AM(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Charge_AM_Chg		10		//调模储料

void AU_ReCharge(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_ReCharge_Chg		10		//再次储料

void AU_PrgCharge(void *FP,FActAttrStr *FAAP);	//清料储料
	#define mASID_AU_PrgCharge_Chg		10
	
#endif

