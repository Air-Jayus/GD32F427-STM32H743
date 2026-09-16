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
#ifndef AL_AutoMoldAdj_h
	#define AL_AutoMoldAdj_h

#ifdef AL_AutoMoldAdj_c
	#define AL_AutoMoldAdj_ext
#else
	#define AL_AutoMoldAdj_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_AutoMoldAdj(void *FP,FActAttrStr *FAAP);

void AL_AutoMoldAdj_Std(void *FP,FActAttrStr *FAAP);			//20150326
	#define mASID_AL_AutoMoldAdj_SGOpenCls		10	//开关安全门
	#define mASID_AL_AutoMoldAdj_MC				20	//关模
	#define mASID_AL_AutoMoldAdj_ConThin		30	//持续调模进
	#define mASID_AL_AutoMoldAdj_MO				40	//开模
	#define mASID_AL_AutoMoldAdj_Thin			50	//调模进
	#define mASID_AL_AutoMoldAdj_Thick			60	//调模退
	
enum eMCES{eMCES_Null,eMCES_UnEnd,eMCES_End};	//关模终开关状态
	//eMCES_Null	未知
	//eMCES_UnEnd	未压合
	//eMCES_End		压合
enum eMCM{eMCM_AM,eMCM_LP};						//关模模式
	//eMCM_AM		调模关模
	//eMCM_LP		低压、高压关模
enum eMOM{eMOM_Slow1,eMOM_Slow1AM};				//开模模式
	//eMOM_Slow1	一慢开模
	//eMOM_Slow1AM	一慢、调模关模
	
ActConf_ext enum eMCES eMoldClsEndState;		//关模终开关状态
ActConf_ext enum eMCM eMoldClsMode	;			//关模模式
ActConf_ext enum eMOM eMoldOpenMode	;			//开模模式
ActConf_ext U32 MoldThinPulseNum;				//调模进齿数		调模进动作使用，调进齿数
ActConf_ext U32 MoldThickPulseNum;				//调模进齿数		调模退动作使用，调退齿数

void AL_AutoAdjMoldThick(void *FP,FActAttrStr *FAAP);	//自动调模厚
	#define mASID_AL_AutoAdjMoldThick_SGOpenCls	10	//开关安全门
	#define mASID_AL_AutoAdjMoldThick_Thin		20	//调进
	#define mASID_AL_AutoAdjMoldThick_Thick		30	//调退

void AutoAdjMoldThick_Pcs(void);				//自动调模厚处理	主循环执行
void MoldAdjSnr_Pcs(void);							//调模电眼计数累计处理	20260112加

#endif

