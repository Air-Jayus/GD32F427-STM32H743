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
#ifndef AU_Core_h
	#define AU_Core_h

#ifdef AU_Core_c
	#define AU_Core_ext
#else
	#define AU_Core_ext extern
#endif

/*========================================= 全局有效宏定义 ========================================*/
/*======================================== 全局有效变量定义 =======================================*/
//中子序号定义
enum eCSN{eCSN_Core1,eCSN_Core2,eCSN_Core3,eCSN_Core4,eCSN_Core5,eCSN_Core6,eCSN_Core7,eCSN_Core8,eCSN_Null};

#define mCoreMaxNum		eCSN_Null						//中子最大组数
#define CoreNum			Min(mCoreMaxNum,Para_CoreNum)	//实际使用中子组数


//中子参数结构
typedef struct
{
	U32 *Fun		;	//中子功能					0-不用 1-中子 2-绞牙
	U32 *ProtSel	;	//中子保护功能	
	U32 *InjHold	;	//中子注射保持				0-不保持 1-保持
	U32 *Reverse	;	//中子反向					0-不用 1-使用	20240223加
	U32 *SnrErrChk	;	//进退到位开关异常检查		即同时压合检查

	U32 *InCtrlMode	;	//中子进控制方式			0-行程 1-时间 0-计数(绞牙时)
	U32 *InOcc		;	//中子进时机				0-关模前 1-中途 2-关模后 
	U32 *InPres		;	//中子进压力	
	U32 *InFlow		;	//中子进流量	
	U32 *InTi		;	//中子进时间	
	U32 *InCnt		;	//中子进计数	
	U32 *InSPos		;	//中子进起始位置	

	U32 *OutCtrlMode;	//中子出控制方式			0-行程 1-时间 0-计数(绞牙时)
	U32 *OutOcc		;	//中子出时机				0-开模前 1-中途 2-开模后 
	U32 *OutPres	;	//中子出压力        	
	U32 *OutFlow	;	//中子出流量        	
	U32 *OutTi		;	//中子出时间            	
	U32 *OutCnt		;	//中子出计数            	
	U32 *OutSPos	;	//中子出起始位置	
	U32 *OutECnt	;	//中子退二计数	

	U32 *InPresRamp	;	//中子进压力斜率	
	U32 *InFlowRamp	;	//中子进流量斜率	
	U32 *InEndDly	;	//中子进完延迟计时	
	U32 *InDVOffDly	;	//中子进方向阀关延时	
	U32 *InPVOnDly	;	//中子进比例阀开延时	
	U32 *InStartDly	;	//中子进前延迟计时	

	U32 *OutPresRamp;	//中子出压力斜率	
	U32 *OutFlowRamp;	//中子出流量斜率	
	U32 *OutEndDly	;	//中子出完延迟计时	
	U32 *OutDVOffDly;	//中子出方向阀关延时	
	U32 *OutPVOnDly	;	//中子出比例阀开延时	
	U32 *OutStartDly;	//中子退前延迟计时	

	U32 *ScrewEndSlowCnt;	//绞牙结束前慢速齿数	绞牙结束前，以慢速绞牙该计数
	U32 *ScrewSlowFlow	;	//绞牙慢速流量			慢速绞牙时流量

	//资源
	U16 RI_InEnd		;	//中子进终
	U16 RI_OutEnd 		;	//中子退终
	U16 RI_SrwSnr		;	//中子电眼
	U16 RO_In			;	//中子进
	U16 RO_Out			;	//中子退

	//显示
	U8 AD_CoreIn		;	//中子进
	U8 AD_CoreOut		;	//中子退
	U8 AD_ScrewIn		;	//绞牙进
	U8 AD_ScrewOut		;	//绞牙出

	//警报
	U8 Alarm_UnInEnd	;	//中子未进到位
	U8 Alarm_UnOutEnd	;	//中子未退到位
	U8 Alarm_PosOL		;	//中子动作位置偏差
	U8 Alarm_Err		;	//中子异常
}CoreParaStruct;

#ifdef ActConf_c
ActConf_ext U32 Para_CoreOutECnt=0;	//辅助用		因为只有中子1有退二
ActConf_ext const CoreParaStruct CorePara[mCoreMaxNum]={						//中子参数
	//中子A		1
   {&Para_Core1Fun,			&Para_CoreProtSel,		&Para_Core1InjHold,	&Para_Core1Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core1InCtrlMode,	&Para_Core1InOcc,		&Para_Core1InPres,	&Para_Core1InFlow,		&Para_Core1InTi,		&Para_Core1InCnt,		&Para_Core1InSPos,	
	&Para_Core1OutCtrlMode,	&Para_Core1OutOcc,		&Para_Core1OutPres,	&Para_Core1OutFlow,		&Para_Core1OutTi,		&Para_Core1OutCnt,		&Para_Core1OutSPos,	&Para_Core1OutECnt,
	&Para_Core1InPresRamp,	&Para_Core1InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core1InStartDly,	 //20260507改中子进前延时单独
	&Para_Core1OutPresRamp,	&Para_Core1OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core1OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core01InEnd,		mRI_Core01OutEnd,		mRI_Core01InEnd,	mRO_Core01In,			mRO_Core01Out,
	mActDisp_CoreAIn,		mActDisp_CoreAOut,		mActDisp_SrwAIn,	mActDisp_SrwAOut,
	mAlarm_Core1UnInEnd,	mAlarm_Core1UnOutEnd,	mAlarm_Core1PosOL,	mAlarm_Core1Err},
	//中子B		2
   {&Para_Core2Fun,			&Para_CoreProtSel,		&Para_Core2InjHold,	&Para_Core2Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core2InCtrlMode,	&Para_Core2InOcc,		&Para_Core2InPres,	&Para_Core2InFlow,		&Para_Core2InTi,		&Para_Core2InCnt,		&Para_Core2InSPos,	
	&Para_Core2OutCtrlMode,	&Para_Core2OutOcc,		&Para_Core2OutPres,	&Para_Core2OutFlow,		&Para_Core2OutTi,		&Para_Core2OutCnt,		&Para_Core2OutSPos,	&Para_CoreOutECnt,
	&Para_Core2InPresRamp,	&Para_Core2InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core2InStartDly,	 //20260507改中子进前延时单独
	&Para_Core2OutPresRamp,	&Para_Core2OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core2OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core02InEnd,		mRI_Core02OutEnd,		mRI_Core02InEnd,	mRO_Core02In,			mRO_Core02Out,
	mActDisp_CoreBIn,		mActDisp_CoreBOut,		mActDisp_SrwBIn,	mActDisp_SrwBOut,
	mAlarm_Core2UnInEnd,	mAlarm_Core2UnOutEnd,	mAlarm_Core2PosOL,	mAlarm_Core2Err},
	//中子C		3
   {&Para_Core3Fun,			&Para_CoreProtSel,		&Para_Core3InjHold,	&Para_Core3Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core3InCtrlMode,	&Para_Core3InOcc,		&Para_Core3InPres,	&Para_Core3InFlow,		&Para_Core3InTi,		&Para_Core3InCnt,		&Para_Core3InSPos,	
	&Para_Core3OutCtrlMode,	&Para_Core3OutOcc,		&Para_Core3OutPres,	&Para_Core3OutFlow,		&Para_Core3OutTi,		&Para_Core3OutCnt,		&Para_Core3OutSPos,	&Para_CoreOutECnt,
	&Para_Core3InPresRamp,	&Para_Core3InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core3InStartDly,	 //20260507改中子进前延时单独
	&Para_Core3OutPresRamp,	&Para_Core3OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core3OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core03InEnd,		mRI_Core03OutEnd,		mRI_Core03InEnd,	mRO_Core03In,			mRO_Core03Out,
	mActDisp_CoreCIn,		mActDisp_CoreCOut,		mActDisp_SrwCIn,	mActDisp_SrwCOut,
	mAlarm_Core3UnInEnd,	mAlarm_Core3UnOutEnd,	mAlarm_Core3PosOL,	mAlarm_Core3Err},
	//中子D		4
   {&Para_Core4Fun,			&Para_CoreProtSel,		&Para_Core4InjHold,	&Para_Core4Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core4InCtrlMode,	&Para_Core4InOcc,		&Para_Core4InPres,	&Para_Core4InFlow,		&Para_Core4InTi,		&Para_Core4InCnt,		&Para_Core4InSPos,	
	&Para_Core4OutCtrlMode,	&Para_Core4OutOcc,		&Para_Core4OutPres,	&Para_Core4OutFlow,		&Para_Core4OutTi,		&Para_Core4OutCnt,		&Para_Core4OutSPos,	&Para_CoreOutECnt,
	&Para_Core4InPresRamp,	&Para_Core4InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core4InStartDly,	 //20260507改中子进前延时单独
	&Para_Core4OutPresRamp,	&Para_Core4OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core4OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core04InEnd,		mRI_Core04OutEnd,		mRI_Core04InEnd,	mRO_Core04In,			mRO_Core04Out,
	mActDisp_CoreDIn,		mActDisp_CoreDOut,		mActDisp_SrwDIn,	mActDisp_SrwDOut,
	mAlarm_Core4UnInEnd,	mAlarm_Core4UnOutEnd,	mAlarm_Core4PosOL,	mAlarm_Core4Err},
	//中子E		5
   {&Para_Core5Fun,			&Para_CoreProtSel,		&Para_Core5InjHold,	&Para_Core5Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core5InCtrlMode,	&Para_Core5InOcc,		&Para_Core5InPres,	&Para_Core5InFlow,		&Para_Core5InTi,		&Para_Core5InCnt,		&Para_Core5InSPos,	
	&Para_Core5OutCtrlMode,	&Para_Core5OutOcc,		&Para_Core5OutPres,	&Para_Core5OutFlow,		&Para_Core5OutTi,		&Para_Core5OutCnt,		&Para_Core5OutSPos,	&Para_CoreOutECnt,
	&Para_Core5InPresRamp,	&Para_Core5InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core5InStartDly,	 //20260507改中子进前延时单独
	&Para_Core5OutPresRamp,	&Para_Core5OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core5OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core05InEnd,		mRI_Core05OutEnd,		mRI_Core05InEnd,	mRO_Core05In,			mRO_Core05Out,
	mActDisp_CoreEIn,		mActDisp_CoreEOut,		mActDisp_SrwEIn,	mActDisp_SrwEOut,
	mAlarm_Core5UnInEnd,	mAlarm_Core5UnOutEnd,	mAlarm_Core5PosOL,	mAlarm_Core5Err},
	//中子F		6
   {&Para_Core6Fun,			&Para_CoreProtSel,		&Para_Core6InjHold,	&Para_Core6Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core6InCtrlMode,	&Para_Core6InOcc,		&Para_Core6InPres,	&Para_Core6InFlow,		&Para_Core6InTi,		&Para_Core6InCnt,		&Para_Core6InSPos,	
	&Para_Core6OutCtrlMode,	&Para_Core6OutOcc,		&Para_Core6OutPres,	&Para_Core6OutFlow,		&Para_Core6OutTi,		&Para_Core6OutCnt,		&Para_Core6OutSPos,	&Para_CoreOutECnt,
	&Para_Core6InPresRamp,	&Para_Core6InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core6InStartDly,	 //20260507改中子进前延时单独
	&Para_Core6OutPresRamp,	&Para_Core6OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core6OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core06InEnd,		mRI_Core06OutEnd,		mRI_Core06InEnd,	mRO_Core06In,			mRO_Core06Out,
	mActDisp_CoreFIn,		mActDisp_CoreFOut,		mActDisp_SrwFIn,	mActDisp_SrwFOut,
	mAlarm_Core6UnInEnd,	mAlarm_Core6UnOutEnd,	mAlarm_Core6PosOL,	mAlarm_Core6Err},
	//中子G		7
   {&Para_Core7Fun,			&Para_CoreProtSel,		&Para_Core7InjHold,	&Para_Core7Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core7InCtrlMode,	&Para_Core7InOcc,		&Para_Core7InPres,	&Para_Core7InFlow,		&Para_Core7InTi,		&Para_Core7InCnt,		&Para_Core7InSPos,	
	&Para_Core7OutCtrlMode,	&Para_Core7OutOcc,		&Para_Core7OutPres,	&Para_Core7OutFlow,		&Para_Core7OutTi,		&Para_Core7OutCnt,		&Para_Core7OutSPos,	&Para_CoreOutECnt,
	&Para_Core7InPresRamp,	&Para_Core7InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core7InStartDly,	 //20260507改中子进前延时单独
	&Para_Core7OutPresRamp,	&Para_Core7OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core7OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core07InEnd,		mRI_Core07OutEnd,		mRI_Core07InEnd,	mRO_Core07In,			mRO_Core07Out,
	mActDisp_CoreGIn,		mActDisp_CoreGOut,		mActDisp_SrwGIn,	mActDisp_SrwGOut,
	mAlarm_Core7UnInEnd,	mAlarm_Core7UnOutEnd,	mAlarm_Core7PosOL,	mAlarm_Core7Err},
	//中子H		8
   {&Para_Core8Fun,			&Para_CoreProtSel,		&Para_Core8InjHold,	&Para_Core8Reverse,		&Para_CoreSnrErrChk,	//20240223加中子反向
	&Para_Core8InCtrlMode,	&Para_Core8InOcc,		&Para_Core8InPres,	&Para_Core8InFlow,		&Para_Core8InTi,		&Para_Core8InCnt,		&Para_Core8InSPos,	
	&Para_Core8OutCtrlMode,	&Para_Core8OutOcc,		&Para_Core8OutPres,	&Para_Core8OutFlow,		&Para_Core8OutTi,		&Para_Core8OutCnt,		&Para_Core8OutSPos,	&Para_CoreOutECnt,
	&Para_Core8InPresRamp,	&Para_Core8InFlowRamp,	&Para_CoreInEndDly,	&Para_CoreInDVOffDly,	&Para_CoreInPVOnDly,	&Para_Core8InStartDly,	 //20260507改中子进前延时单独
	&Para_Core8OutPresRamp,	&Para_Core8OutFlowRamp,	&Para_CoreOutEndDly,&Para_CoreOutDVOffDly,	&Para_CoreOutPVOnDly,	&Para_Core8OutStartDly,//20260507改中子退前延时单独
	&Para_ScrewEndSlowCnt,	&Para_ScrewSlowFlow,
	mRI_Core08InEnd,		mRI_Core08OutEnd,		mRI_Core08InEnd,	mRO_Core08In,			mRO_Core08Out,
	mActDisp_CoreHIn,		mActDisp_CoreHOut,		mActDisp_SrwHIn,	mActDisp_SrwHOut,
	mAlarm_Core8UnInEnd,	mAlarm_Core8UnOutEnd,	mAlarm_Core8PosOL,	mAlarm_Core8Err}};
#else
ActConf_ext const CoreParaStruct CorePara[mCoreMaxNum];							//中子参数
#endif



//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AU_CoreIn(void *FP,FActAttrStr *FAAP);		//标准入芯
	#define mASID_AU_CoreIn_Ti				10		//计时中子
	#define mASID_AU_CoreIn_Snr				20		//行程开关中子
	#define mASID_AU_CoreIn_Cnt				30		//计数中子
	#define mASID_AU_CoreIn_CntSlow			40		//计数中子二慢				结束时

void AU_CoreOut(void *FP,FActAttrStr *FAAP);	//标准出芯
	#define mASID_AU_CoreOut_Ti				10		//计时中子
	#define mASID_AU_CoreOut_Snr			20		//行程开关中子
	#define mASID_AU_CoreOut_Cnt			30		//计数中子
	#define mASID_AU_CoreOut_CntSlow		40		//计数中子二慢				结束时



void AU_LinkCoreIn(void *FP,FActAttrStr *FAAP);	//连动入芯
	#define mASID_AU_LinkCoreIn_Ti			10		//计时中子
	#define mASID_AU_LinkCoreIn_Snr			20		//行程开关中子
	#define mASID_AU_LinkCoreIn_Cnt			30		//计数中子
	#define mASID_AU_LinkCoreIn_CntSlow		40		//计数中子二慢				结束时

void AU_LinkCoreOut(void *FP,FActAttrStr *FAAP);//连动出芯
	#define mASID_AU_LinkCoreOut_Ti			10		//计时中子
	#define mASID_AU_LinkCoreOut_Snr		20		//行程开关中子
	#define mASID_AU_LinkCoreOut_Cnt		30		//计数中子
	#define mASID_AU_LinkCoreOut_CntSlow	40		//计数中子二慢				结束时




void AU_SrwEndOut(void *FP,FActAttrStr *FAAP);	//绞牙退二
	#define mASID_AU_SrwEndOut_Cnt		10			//绞牙退二计数中子
	#define mASID_SrwEndOut_CntSlow		20			//绞牙退二计数中子二慢		结束时
	
void AU_CoreLinkWait(void *FP,FActAttrStr *FAAP);//连动时等待					辅助动作
	#define mASID_AU_CoreLinkWait_Wait	10			//等待

void AU_Core1Out_S0(void *FP,FActAttrStr *FAAP);//中子A特殊退动作				20130724加		退“特殊中子参数一”时间，主要用于特殊中子：托进-特殊出芯-托退-出芯
	#define mASID_AU_Core1Out_S0_Ti		10			//时间退					退“特殊中子参数一”时间

#endif

