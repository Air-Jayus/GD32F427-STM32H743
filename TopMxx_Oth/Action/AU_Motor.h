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
#ifndef AU_Motor_h
	#define AU_Motor_h

#ifdef AU_Motor_c
	#define AU_Motor_ext
#else
	#define AU_Motor_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//#define mAG_MotorOn					0x20					//马达开					动作组
//	#define mAFID_MotorOn					0x90				//			马达开			函数ID
//		#define mASEG_MotorOn_Std				mASEG_Stand		//				标准				

//#define mAG_MotorOff					0x21					//马达关					动作组
//	#define mAFID_MotorOff					0x94				//			马达关			函数ID
//		#define mASEG_MotorOff_Std				mASEG_Stand		//				标准				

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AU_MotorOn(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_MotOn_HoldSta		10	//保持启动
	#define mASID_AU_MotOn_Y			20	//Y形启动
	#define mASID_AU_MotOn_YToASpa		30	//Y-A间歇
	#define mASID_AU_MotOn_A			40	//A形启动
	#define mASID_AU_MotOn_Hold			50	//马达稳定

void AU_MotorOff(void *FP,FActAttrStr *FAAP);
	#define mASID_AU_MotOff_Off			10	//马达关



void AU_MotorOff_SSM(void *FP,FActAttrStr *FAAP);	//紧急停止模式用

Bool MotorIsOn(void);								//马达开着检查
Bool MotorIsOff(void);								//马达关着检查
U8 GetMotState(void);								//获取马达状态
void SysStopMotStateOff(void);						//紧急停止马达状态强制关	由AU_SysStop()调用，用于同步马达状态

#endif

