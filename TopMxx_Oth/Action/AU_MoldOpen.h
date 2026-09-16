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
#ifndef AU_MoldOpen_h
	#define AU_MoldOpen_h

#ifdef AU_MoldOpen_c
	#define AU_MoldOpen_ext
#else
	#define AU_MoldOpen_ext extern
#endif

//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
#define mASID_AU_MoldOpen_Start		10		//开模		起始段			时间控制、如果模板在一慢则不起作用(直接一慢)
#define mASID_AU_MoldOpen_MO1		20		//开模		一段（一慢）
#define mASID_AU_MoldOpen_SpdUp		25		//开模		智能开模的定时加速段
#define mASID_AU_MoldOpen_MO2		30		//开模		二段
#define mASID_AU_MoldOpen_MO3		40		//开模		三段
#define mASID_AU_MoldOpen_MO4		50		//开模		四段
#define mASID_AU_MoldOpen_MO5		60		//开模		五段（二慢）

#define mASID_AU_MoldOpen_AM_MO1	10		//调模开模	一段

#define mASID_AU_MoldOpen_AMA_S1MO	10		//自动调模时一慢开模
#define mASID_AU_MoldOpen_AMA_AMMO	20		//自动调模时调模开模

//动作函数-----------------------------------------------------------------------------------------//
void AU_MoldOpen(void *FP,FActAttrStr *FAAP);		//
void AU_MoldOpenAlg(void *FP,FActAttrStr *FAAP);	//开模算法	20171214
void AU_MoldOpen_AM(void *FP,FActAttrStr *FAAP);	//调模时开模
void AU_MoldOpen_AMA(void *FP,FActAttrStr *FAAP);	//自动调模时一慢开模

Bool MoldOpenIsEnd(void);			//开模到位检查			
Bool MoldOpenInEndEffArea(void);	//开模到开终有效区检查		依据有效区检查开模是否已经到位，主要给一些开模是否到位然后据此报警时使用
									//							如托模、中子动作时开模是否已经到位检查

#endif

