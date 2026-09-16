/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：标准注塑机动作程序配置文件
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
#ifndef ActConf_Std_h
	#define ActConf_Std_h

#ifdef ActConf_Std_c
	#define ActConf_Std_ext
#else
	#define ActConf_Std_ext extern
#endif

//包含用到动作的.h文件
//动作单元
#include "AU_MoldCls.h"				//关模			常规
#include "AU_MoldOpen.h"			//开模			常规
#include "AU_Inject.h"				//注射			常规
#include "AU_Charge.h"				//储料			常规
#include "AU_SuckBack.h"			//射退			常规
#include "AU_NozFor.h"				//座进			常规
#include "AU_NozRet.h"				//座退			常规
#include "AU_MoldThin.h"			//调模进			常规
#include "AU_MoldThick.h"			//调模退			常规
#include "AU_EjeRet.h"				//托模退			常规
#include "AU_EjeFor.h"				//托模进			常规
#include "AU_Motor.h"				//马达			常规
#include "AU_MotDrv.h"				//驱动器			常规
#include "AU_OilHtr.h"				//油温预热		常规
#include "AU_NozSG.h"				//注射防护罩		常规
#include "AU_SafeGate.h"			//安全门			常规
#include "AU_AutoGate.h"			//自动门			常规
#include "AU_Cool.h"				//冷却			常规
#include "AU_AirInj.h"				//气辅助注射		常规
#include "AU_Air.h"					//吹气			常规
#include "AU_Purge.h"				//清料			常规
#include "AU_Lubr.h"				//润滑			常规
#include "AU_SysStop.h"				//紧急停止		常规
#include "AU_MachProt.h"			//机械保险		常规
//#include "AU_HydProt.h"			//液压保险		常规
#include "AU_CycStartKey.h"			//循环启动键		常规
#include "AU_AssAct.h"				//辅助动作		常规
#include "AU_GB22530.h"				//GB22530		常规
#include "AU_Core.h"				//中子			常规
#include "AU_Acc.h"					//蓄能器			常规
#include "AU_Nozzle.h"				//喷嘴			常规
#include "AU_Robot.h"				//机械手			常规		包含欧规、STAR、简易等
#include "AU_AutoMoldAdj.h"			//自动调模		常规
#include "AU_Exhaust.h"				//排气			常规
#include "AU_EjeCutHandle.h"		//托模切料柄 	常规
#include "AU_Jig.h"					//模具夹具		常规		液压、磁力等类型夹具
#include "AU_PilotOilAcc.h"			//先导油蓄能器	常规	
#include "AU_BMC.h"					//BMC			常规	
#include "AU_RelPres.h"				//中子、阀门卸压	常规	
#include "AU_SteamInj.h"			//蒸汽注射		常规	
#include "AU_InjComp.h"				//压缩注射		常规	
#include "AU_TieBar.h"				//抽插拉杆		常规	



//动作逻辑
#include "AL_SafeGate.h"			//安全门			常规
#include "AL_AutoGate.h"			//自动门			常规
#include "AL_MoldCls.h"				//关模			常规
#include "AL_MoldOpen.h"			//开模			常规
#include "AL_Inject.h"				//注射			常规
#include "AL_Charge.h"				//储料			常规
#include "AL_SuckBack.h"			//射退			常规
#include "AL_EjeFor.h"				//托模进			常规
#include "AL_EjeRet.h"				//托模退			常规
#include "AL_NozFor.h"				//座进			常规
#include "AL_NozRet.h"				//座退			常规
#include "AL_MoldThin.h"			//调模进			常规
#include "AL_MoldThick.h"			//调模退			常规
#include "AL_Motor.h"				//马达			常规
#include "AL_MotDrv.h"				//驱动器			常规
#include "AL_OilHtr.h"				//油温预热		常规
#include "AL_NozSG.h"				//注射防护罩		常规
#include "AL_Cool.h"				//冷却			常规
#include "AL_AirInj.h"				//气辅助注射		常规
#include "AL_Air.h"					//吹气			常规
#include "AL_Purge.h"				//清料			常规
#include "AL_Lubr.h"				//润滑			常规
#include "AL_SysStop.h"				//紧急停止		常规
#include "AL_MachProt.h"			//机械保险		常规
#include "AL_HydProt.h"				//液压保险		常规
#include "AL_CycStartKey.h"			//循环启动键		常规
#include "AL_AssAct.h"				//辅助动作		常规
#include "AL_GB22530.h"				//GB22530		常规
#include "AL_Core.h"				//中子			常规
#include "AL_Acc.h"					//蓄能器			常规
#include "AL_Nozzle.h"				//喷嘴			常规
#include "AL_Robot.h"				//机械手			常规		包含欧规、STAR、简易等
#include "AL_AutoMoldAdj.h"			//自动调模		常规
#include "AL_Exhaust.h"				//排气			常规
#include "AL_EjeCutHandle.h"		//托模切料柄 	常规
#include "AL_Jig.h"					//模具夹具		常规		液压、磁力等类型夹具
#include "AL_PilotOilAcc.h"			//先导油蓄能器	常规	
#include "AL_BMC.h"					//BMC			常规	
#include "AL_RelPres.h"				//中子、阀门卸压	常规	
#include "AL_SteamInj.h"			//蒸汽注射		常规	
#include "AL_InjComp.h"				//压缩注射		常规	
#include "AL_TieBar.h"				//抽插拉杆		常规	


void ActConf_Init(void);			//初始化
void ActConf_Pcs(void);				//主循环执行

void ActConf_DryCycConf(void);		//干周期模式初始化	20200713
void ActConf_AutoConf(void);		//自动模式初始化	20200713


#endif

