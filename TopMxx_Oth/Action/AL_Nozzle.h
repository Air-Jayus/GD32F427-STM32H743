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
#ifndef AL_Nozzle_h
	#define AL_Nozzle_h

#ifdef AL_Nozzle_c
	#define AL_Nozzle_ext
#else
	#define AL_Nozzle_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_NozzleOn(void *FP,FActAttrStr *FAAP);	//喷嘴开
	#define mASID_AL_NozzleOn_SigPos	10			//单向喷嘴
	#define mASID_AL_NozzleOn_DouPos	20			//双向喷嘴
	
void AL_NozzleOff(void *FP,FActAttrStr *FAAP);	//喷嘴关
	#define mASID_AL_NozzleOff_SigPos	10			//单向喷嘴
	#define mASID_AL_NozzleOff_DouPos	20			//双向喷嘴

#define NozzleUseChk()		(((Para_HydNozType==mHNT_SigPos)||(Para_HydNozType==mHNT_DouPos)) && Para_HydNozSel)//喷嘴使用检查	配备且选用
#define NozzleIsSigPos()	((Para_HydNozType==mHNT_SigPos) && Para_HydNozSel)									//单向喷嘴检查	配备且单向
#define NozzleIsDouPos()	((Para_HydNozType==mHNT_DouPos) && Para_HydNozSel)									//双向喷嘴检查	配备且双向
#define NozzleIsSigAndNoUse()	((Para_HydNozType==mHNT_SigPos) && (!Para_HydNozSel))							//单向喷嘴检查	配备且不使用	20200508加
#define NozzleIsDouAndNoUse()	((Para_HydNozType==mHNT_DouPos) && (!Para_HydNozSel))							//双向喷嘴检查	配备且不使用	20200508加

#endif

