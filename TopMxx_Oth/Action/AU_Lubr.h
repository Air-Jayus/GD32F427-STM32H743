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
#ifndef AU_Lubr_h
	#define AU_Lubr_h

#ifdef AU_Lubr_c
	#define AU_Lubr_ext
#else
	#define AU_Lubr_ext extern
#endif


//#define Get_LPM_Num()	((Para_LubrParaMangMode==mLPMM_5W) ? 50000:10000)		//20130905加，润滑前后分界模数		20130905加
																				//注：如果再增加不同的分界模数，则该宏改用函数实现即可

//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AU_KeyLubr(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_KeyLubr_Wait	10		//等待润滑结束

void AU_Lubr1(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Lubr1_Lubr		10		//润滑
	#define mASID_AU_Lubr1_HP		20		//保压
	#define mASID_AU_Lubr1_Dly		30		//延时
	#define mASID_AU_Lubr1_Cnt		40		//计次

void AU_Lubr2(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Lubr2_Lubr		10		//润滑
	#define mASID_AU_Lubr2_HP		20		//保压
	#define mASID_AU_Lubr2_Dly		30		//延时
	#define mASID_AU_Lubr2_Cnt		40		//计次

U32 GetLubr1UnitCnt(void);	//获取润滑1模数		AL_Lubr.c、RPHA.c中调用
U32 GetLubr2UnitCnt(void);	//获取润滑2模数		AL_Lubr.c、RPHA.c中调用

U32 Get_LPM1_Num(void);		//非标准模式时润滑1润滑启动模数获取	20181008
U32 Get_LPM2_Num(void);		//非标准模式时润滑2润滑启动模数获取	20181008

void AU_MoldAdjLubr(void *FP,FActAttrStr *FAAP);	//调模润滑	20150327加
	#define mASID_AU_MoldAdjLubr_Lubr	10		//润滑
	#define mASID_AU_MoldAdjLubr_HP		20		//保压

//润滑2开始前等待润滑一结束	20200305
void AU_Lubr2WaitLubr1(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_Lubr2WaitLubr1_Wait	10	//润滑


#endif

