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
#ifndef AU_MoldCls_h
	#define AU_MoldCls_h

#ifdef AU_MoldCls_c
	#define AU_MoldCls_ext
#else
	#define AU_MoldCls_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
#define mASID_AU_MoldCls_Start			10	//关模			起始段		时间控制
#define mASID_AU_MoldCls_SpeUp			15	//关模			智能关模前的加速段
#define mASID_AU_MoldCls_MC1			20	//关模			一段
#define mASID_AU_MoldCls_MC2			30	//关模			二段
#define mASID_AU_MoldCls_MC3			40	//关模			三段
#define mASID_AU_MoldCls_LP				50	//关模			低压
#define mASID_AU_MoldCls_HP				60	//关模			高压
#define mASID_AU_MoldCls_HPDly			70	//关模			高压保持

#define mASID_AU_MoldCls_AM_MC1			10	//调模关模		一段

#define mASID_AU_MoldCls_AMA_AM			10	//调模关模		自动调模时关模
#define mASID_AU_MoldCls_AMA_LP			20	//低压关模
#define mASID_AU_MoldCls_AMA_HP			30	//高压关模
#define mASID_AU_MoldCls_AMA_HPDly		40	//高压保持




//动作函数-----------------------------------------------------------------------------------------//
void AU_MoldCls(void *FP,FActAttrStr *FAAP);
void AU_MoldCls_AM(void *FP,FActAttrStr *FAAP);
void AU_MoldCls_AMA(void *FP,FActAttrStr *FAAP);		//自动调模时关模

Bool MoldClsIsEnd(void);		//关模到终检查
Bool MoldClsInEndEffArea(void);	//关模到关终有效区检查		注：由于关终无有效区参数，因此本函数同MoldClsIsEnd()，但是两者含义有别，注意区分使用。
    							//								本函数主要给一些关模是否到位然后据此报警时使用。

#endif

