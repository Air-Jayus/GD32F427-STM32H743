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
#ifndef AL_Inject_h
	#define AL_Inject_h

#ifdef AL_Inject_c
	#define AL_Inject_ext
#else
	#define AL_Inject_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_Inject(void *FP,FActAttrStr *FAAP);
void AL_InjBefNozFor(void *FP,FActAttrStr *FAAP);
void AL_PrgInject(void *FP,FActAttrStr *FAAP);
void AL_InjComp(void *FP,FActAttrStr *FAAP);
void Sprue_Pcs(void);

	#define mASID_AL_Inject_NozSGCls	10	//关防护罩
	#define mASID_AL_Inject_Acc			20	//蓄能器		
	#define mASID_AL_Inject_InjNozOpen	30	//喷嘴开		                
	#define mASID_AL_Inject_StaAirInj	40	//气辅开始    
	#define mASID_AL_Inject_ReChg		50	//再次储料    
	#define mASID_AL_Inject_Inj			60	//注射    
	#define mASID_AL_Inject_Inj_AM		70	//调模注射      
	#define mASID_AL_Inject_BefNozFor	80	//座进前注射	
	#define mASID_AL_Inject_Purge		90	//清料
	#define mASID_AL_Inject_InjNozCls	100	//喷嘴关
	#define mASID_AL_Inject_InjNozReCls	110	//喷嘴关		注射异常时，喷嘴强制再次一次
	#define mASID_AL_Inject_Comp		120	//压缩注射



#endif

