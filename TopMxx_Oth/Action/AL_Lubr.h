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
#ifndef AL_Lubr_h
	#define AL_Lubr_h

#ifdef AL_Lubr_c
	#define AL_Lubr_ext
#else
	#define AL_Lubr_ext extern
#endif

#ifdef ActConf_c
	ActConf_ext Bool AutoLubr1FinFlag=mTrue;	//自动润滑完成标志							20130910加，实现自动润滑中断继续功能
	ActConf_ext Bool AutoLubr2FinFlag=mTrue;	//自动润滑完成标志							20130910加，实现自动润滑中断继续功能
	ActConf_ext Bool PwrOnLubrFlag=mFalse;		//开机润滑标志									20260124加，实现开机后前两模润滑
	ActConf_ext U8 LubrMoldOpenCnt=0;					//开机润滑开模计数							20260124加，实现开机后前两模润滑
	ActConf_ext U8 LubrMoldClsCnt=0;					//开机润滑关模计数							20260124加，实现开机后前两模润滑
#else
	ActConf_ext Bool AutoLubr1FinFlag;			//自动润滑完成标志							20130910加，实现自动润滑中断继续功能
	ActConf_ext Bool AutoLubr2FinFlag;			//自动润滑完成标志							20130910加，实现自动润滑中断继续功能
	ActConf_ext Bool PwrOnLubrFlag;					//开机润滑标志									20260124加，实现开机后前两模润滑
	ActConf_ext U8 LubrMoldOpenCnt;					//开机润滑开模计数							20260124加，实现开机后前两模润滑
	ActConf_ext U8 LubrMoldClsCnt;					//开机润滑关模计数							20260124加，实现开机后前两模润滑
#endif

//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_Lubr1(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_Lubr1_Lubr		10		//润滑1

void AL_Lubr2(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_Lubr2_WiatLubr1	10		//润滑2开始前等待润滑1结束	20200305
	#define mASID_AL_Lubr2_Lubr			20		//润滑2

void AL_KeyLubr(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_KeyLubr_Lubr	10		//按键润滑

void AutoLubrChk(void);						//自动润滑检查		在AU_AssAct.h中AU_CycEndCnt()函数调用执行

void Lubr_Pcs(void);						//润滑处理			于主循环执行，主要完成二板润滑

void AL_MoldAdjLubr(void *FP,FActAttrStr *FAAP);
	#define mASID_AL_MoldAdjLubr_Lubr	10	//调模润滑			20150327加
	
void MoldOpen_Lubr_Pcs(void);				//20191018	第1组、第2组润滑按时间间隔进行润滑

void AL_Lubr2WaitLubr1(void *FP,FActAttrStr *FAAP);		
	#define mASID_AL_Lubr2_WaitLubr1	10	//20200305	润滑2开始前等待润滑一结束
	
#endif

