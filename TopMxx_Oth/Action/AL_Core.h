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
动作函数命名  ：Act_动作名称_模式_特点_序号		模式指手动(MM)、中子(AM)、自动(AU)、多种(MU或无)
												特点如某机型、某厂家的特有机型等
												序号用A、B、C……
动作函数ID命名：mASID_函数名_段名				

****************************************************************************************************/
#ifndef AL_Core_h
	#define AL_Core_h

#ifdef AL_Core_c
	#define AL_Core_ext
#else
	#define AL_Core_ext extern
#endif

/*========================================= 全局有效宏定义 ========================================*/
/*======================================== 全局有效变量定义 =======================================*/
//中子位置状态定义
enum eCPS{eCPS_Off,eCPS_Mid,eCPS_InEnd,eCPS_OutEnd,eCPS_AllEnd};
	//eCPS_Off		关闭	某些情况下限制同eCPS_Mid，即位置未知
	//eCPS_Mid		中间	
	//eCPS_InEnd	进终	如果是行程开关控制，则实时更新
	//eCPS_OutEnd	退终	如果是行程开关控制，则实时更新
	//eCPS_AllEnd	均到位	同时进终、退终，一般是异常

#ifdef ActConf_c
ActConf_ext enum eCPS CorePosState[mCoreMaxNum]={								//位置状态
	eCPS_Mid,eCPS_Mid,eCPS_Mid,eCPS_Mid,eCPS_Mid,eCPS_Mid,eCPS_Mid,eCPS_Mid};
#else
ActConf_ext enum eCPS CorePosState[mCoreMaxNum];								//位置状态
#endif

//中子方向类型
enum eCDT{eCDT_Off,eCDT_InOut,eCDT_OnlyIn,eCDT_OnlyOut};
	//eCDT_Off		关闭
	//eCDT_InOut	双向
	//eCDT_OnlyIn	只进
	//eCDT_OnlyOut	只退
ActConf_ext enum eCDT CoreDirType[mCoreMaxNum];									//中子方向类型

//中子序列
#define mCoreSeqMaxNum		18

enum eCSA{eCSA_KeyIn,eCSA_KeyOut,eCSA_In,eCSA_Out};								//中子属性				入芯、出芯决定方向，按此进行到位检查、给出相应警报
	//eCSA_KeyIn		按键入芯	用于按键中子，找到队列中相应的中子
	//eCSA_KeyOut		按键出芯	用于按键中子，找到队列中相应的中子
	//eCSA_In			普通入芯	
	//eCSA_Out			普通出芯
	
enum eCSAA{eCSAA_EjeRet,eCSAA_MoldCls,eCSAA_Inject,eCSAA_Charge,eCSAA_MoldOpen,eCSAA_EjeFor};//中子执行所在动作		用于排序、对应到相应的动作
	//eCSAA_EjeRet			托退时		20130412加：特殊中子“B:托模-出芯-取件-入芯”
	//eCSAA_MoldCls			关模时
	//eCSAA_Inject			注射时
	//eCSAA_Charge			储料时
	//eCSAA_MoldOpen		开模时
	//eCSAA_EjeFor			托进时

enum eCSOM{eCSOM_FixStart,eCSOM_FixEnd,eCSOM_InOcc,eCSOM_OutOcc};		//中子动作时机模式		与CorePara中的InOcc、OutOcc不是一回事
	//eCSOM_FixStart		固定动作开始
	//eCSOM_FixEnd			固定动作结束
	//eCSOM_InOcc			根据CorePara.InOcc和CorePara.InSPos
	//eCSOM_OutOcc			根据CorePara.OutOcc和CorePara.OutSPos
	//eCSOM_				托进后、注射保压前等，待定义……
	
enum eCSRT {eCSRT_In,eCSRT_Out,eCSRT_LinkOut,eCSRT_LinkIn};				//在动作中中子执行模式
	//eCSRT_In			入芯			标准入芯
	//eCSRT_Out			出芯			标准出芯
	//eCSRT_LinkOut		连动出芯
	//eCSRT_LinkIn		连动入芯		以下特殊类型
	//eCSRT_			其它特殊		如二段中子、多次中子，待定义……

enum eCSPCM{eCSPCM_Cancel,eCSPCM_MoldCls,eCSPCM_MoldOpen,eCSPCM_Inject,eCSPCM_Charge,eCSPCM_EjeRet,eCSPCM_EjeFor};	//位置偏差检查模式
	//eCSPCM_Cancel		取消
	//eCSPCM_MoldCls	模板位置关模方向
	//eCSPCM_MoldOpen	模板位置开模方向
	//eCSPCM_Inject		螺杆位置注射方向			暂不支持，无有效区
	//eCSPCM_Charge		螺杆位置储料方向			暂不支持，无有效区
	//eCSPCM_EjeRet		托模位置托退方向			暂不支持
	//eCSPCM_EjeFor		托模位置托进方向			暂不支持，无有效区

enum eCSPCA{eCSPCA_FixStart,eCSPCA_FixEnd,eCSPCA_InOcc,eCSPCA_OutOcc};	//位置偏差检查依据
	//eCSPCA_FixStart	固定动作开始
	//eCSPCA_FixEnd		固定动作结束
	//eCSPCA_InOcc		根据CorePara.InOcc和CorePara.InSPos
	//eCSPCA_OutOcc		根据CorePara.OutOcc和CorePara.OutSPos

typedef struct {
	enum eCSN CoreSN;		//中子序号			可以重复出现，如特殊中子在动作前执行一次、动作后再执行一次 
	enum eCSA Attr;			//中子属性			按键入芯、按键出芯，用于按键中子找到队列中相应的中子
							//					入芯、出芯决定方向，按此进行到位检查、给出相应警报

	enum eCSAA AtAct;		//所在动作			用于排序、对应到相应的动作
	enum eCSOM OccMode;		//动作时机			用于动作执行时的时机选择		不用于排序
	enum eCSRT RunType;		//动作类型			入、出、退二、连动等

	Bool SeqChkHide;		//顺序检查隐藏		隐藏不被检查					被动，不影响其它中子
	Bool SeqChkCancel;		//顺序检查忽略		该中子不需要检查顺序			主动
	
	Bool LinkEn;			//连动允许
	
	enum eCSPCM PosChkMode;	//位置偏差检查模式	取消、模板位置关模方向……	即出入芯位置偏差检查对应的位置尺、及动作方向
	enum eCSPCA PosChkAcc;	//位置偏差检查依据								即出入芯位置偏差检查对应的位置参数
	Bool EjeRetEndChk;		//托模退到位检查		中子开始时，检查托退是否到位
	
	Bool EndChk_MoldCls;	//关模时检查到位		关模开始时，检查中子到位情况	根据CoreSeq[]，动作之前的已经执行应到位、动作之后的应未执行到位
	Bool EndChk_MoldOpen;	//开模时检查到位
	Bool EndChk_EjeFor;		//托模时检查到位
	Bool EndChk_Inject;		//注射时检查到位
	Bool EndChk_Charge;		//储料时检查到位
	Bool EndChk_EjeRet;		//托退时检查到位		20130412加：特殊中子“B:托模-出芯-取件-入芯”
}CoreSeqStruct;
ActConf_ext CoreSeqStruct CoreSeq[mCoreSeqMaxNum];

typedef struct{
	enum eCSN CoreSN;		//中子序号			 
	enum eCSA Attr;			//中子属性
	enum eCSOM OccMode;		//动作时机
	enum eCSRT RunType;		//动作类型			入、出、退二、连动等
}ActCoreRunStruct;	//动作中执行中子结构






//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void AL_KeyCore1In(void *FP,FActAttrStr *FAAP);		//按键中子1进
void AL_KeyCore2In(void *FP,FActAttrStr *FAAP);		//按键中子2进
void AL_KeyCore3In(void *FP,FActAttrStr *FAAP);		//按键中子3进
void AL_KeyCore4In(void *FP,FActAttrStr *FAAP);		//按键中子4进
void AL_KeyCore5In(void *FP,FActAttrStr *FAAP);		//按键中子5进
void AL_KeyCore6In(void *FP,FActAttrStr *FAAP);		//按键中子6进
void AL_KeyCore7In(void *FP,FActAttrStr *FAAP);		//按键中子7进
void AL_KeyCore8In(void *FP,FActAttrStr *FAAP);		//按键中子8进
void AL_Core1In(void *FP,FActAttrStr *FAAP);		//中子1进
void AL_Core2In(void *FP,FActAttrStr *FAAP);		//中子2进
void AL_Core3In(void *FP,FActAttrStr *FAAP);		//中子3进
void AL_Core4In(void *FP,FActAttrStr *FAAP);		//中子4进
void AL_Core5In(void *FP,FActAttrStr *FAAP);		//中子5进
void AL_Core6In(void *FP,FActAttrStr *FAAP);		//中子6进
void AL_Core7In(void *FP,FActAttrStr *FAAP);		//中子7进
void AL_Core8In(void *FP,FActAttrStr *FAAP);		//中子8进
void AL_LinkCore1In(void *FP,FActAttrStr *FAAP);	//连动中子1进
void AL_LinkCore2In(void *FP,FActAttrStr *FAAP);	//连动中子2进
void AL_LinkCore3In(void *FP,FActAttrStr *FAAP);	//连动中子3进
void AL_LinkCore4In(void *FP,FActAttrStr *FAAP);	//连动中子4进
void AL_LinkCore5In(void *FP,FActAttrStr *FAAP);	//连动中子5进
void AL_LinkCore6In(void *FP,FActAttrStr *FAAP);	//连动中子6进
void AL_LinkCore7In(void *FP,FActAttrStr *FAAP);	//连动中子7进
void AL_LinkCore8In(void *FP,FActAttrStr *FAAP);	//连动中子8进
	#define mASID_AL_CoreIn_RCIS		10	//机械手进允许检查
	#define mASID_AL_CoreIn_StdIn		20	//中子进		标准入芯
	#define mASID_AL_CoreIn_LinkIn		30	//中子进		连动入芯

void AL_KeyCore1Out(void *FP,FActAttrStr *FAAP);	//按键中子1退
void AL_KeyCore2Out(void *FP,FActAttrStr *FAAP);	//按键中子2退
void AL_KeyCore3Out(void *FP,FActAttrStr *FAAP);	//按键中子3退
void AL_KeyCore4Out(void *FP,FActAttrStr *FAAP);	//按键中子4退
void AL_KeyCore5Out(void *FP,FActAttrStr *FAAP);	//按键中子5退
void AL_KeyCore6Out(void *FP,FActAttrStr *FAAP);	//按键中子6退
void AL_KeyCore7Out(void *FP,FActAttrStr *FAAP);	//按键中子7退
void AL_KeyCore8Out(void *FP,FActAttrStr *FAAP);	//按键中子8退
void AL_Core1Out(void *FP,FActAttrStr *FAAP);		//中子1退
void AL_Core2Out(void *FP,FActAttrStr *FAAP);		//中子2退
void AL_Core3Out(void *FP,FActAttrStr *FAAP);		//中子3退
void AL_Core4Out(void *FP,FActAttrStr *FAAP);		//中子4退
void AL_Core5Out(void *FP,FActAttrStr *FAAP);		//中子5退
void AL_Core6Out(void *FP,FActAttrStr *FAAP);		//中子6退
void AL_Core7Out(void *FP,FActAttrStr *FAAP);		//中子7退
void AL_Core8Out(void *FP,FActAttrStr *FAAP);		//中子8退
void AL_LinkCore1Out(void *FP,FActAttrStr *FAAP);	//连动中子1退
void AL_LinkCore2Out(void *FP,FActAttrStr *FAAP);	//连动中子2退
void AL_LinkCore3Out(void *FP,FActAttrStr *FAAP);	//连动中子3退
void AL_LinkCore4Out(void *FP,FActAttrStr *FAAP);	//连动中子4退
void AL_LinkCore5Out(void *FP,FActAttrStr *FAAP);	//连动中子5退
void AL_LinkCore6Out(void *FP,FActAttrStr *FAAP);	//连动中子6退
void AL_LinkCore7Out(void *FP,FActAttrStr *FAAP);	//连动中子7退
void AL_LinkCore8Out(void *FP,FActAttrStr *FAAP);	//连动中子8退
	#define mASID_AL_CoreOut_RCOS		10	//机械手退允许检查
	#define mASID_AL_CoreOut_StdOut		20	//中子退		标准出芯
	#define mASID_AL_CoreOut_LinkOut	30	//中子退		连动出芯

void AL_CoreLinkWait(void *FP,FActAttrStr *FAAP);	//连动中子等待
	#define mASID_AL_CoreLinkWait_Wait	10	//等待

void AL_Srw1EndOut(void *FP,FActAttrStr *FAAP);		//中子1绞牙退二
	#define mASID_AL_Srw1EndOut_Out		10	//退

void AL_Core1AOut_S0(void *FP,FActAttrStr *FAAP);	//中子A特殊退		
	#define mASID_AL_Core1Out_S0_RCOS	10	//机械手退允许检查
	#define mASID_AL_Core1Out_S0		20	//中子A特殊退
	


void Core_Pcs(void);							//中子处理				主循环执行


void CorePcs_MoldCls(void *FP,FActAttrStr *FAAP);		//关模时中子相关处理		AU_MoldCls()函数中调用执行	
void CorePcs_MoldOpen(void *FP,FActAttrStr *FAAP);		//开模时中子相关处理		AU_MoldOpen()函数中调用执行	
void CorePcs_EjeFor(void *FP,FActAttrStr *FAAP);		//托模时中子相关处理		AU_EjeFor()函数中调用执行	
void CorePcs_EjeForLink(void *FP,FActAttrStr *FAAP);	//托模连动时中子相关处理	AU_EjeForLink()函数中调用执行	
void CorePcs_Inject(void *FP,FActAttrStr *FAAP);		//注射时中子相关处理		AU_Inject()函数中调用执行	
void CorePcs_Charge(void *FP,FActAttrStr *FAAP);		//储料时中子相关处理		AU_Charge()函数中调用执行	
void CorePcs_EjeRet(void *FP,FActAttrStr *FAAP);		//托退时中子相关处理		AU_EjeRet()函数中调用执行	20130412加：特殊中子“B:托模-出芯-取件-入芯”


#define CoreAIsOff()	(CoreDirType[eCSN_Core1]==eCDT_Off)		//中子A关闭检查		主要在AL_Robot.c中调用
#define CoreBIsOff()	(CoreDirType[eCSN_Core2]==eCDT_Off)		//中子B关闭检查		主要在AL_Robot.c中调用	

#define CoreAInIsEnd()	((CorePosState[eCSN_Core1]==eCPS_InEnd)||(CorePosState[eCSN_Core1]==eCPS_AllEnd))	//中子A进终		主要在AL_Robot.c中调用
#define CoreBInIsEnd()	((CorePosState[eCSN_Core2]==eCPS_InEnd)||(CorePosState[eCSN_Core2]==eCPS_AllEnd))	//中子B进终		主要在AL_Robot.c中调用

#define CoreAOutIsEnd()	((CorePosState[eCSN_Core1]==eCPS_OutEnd)||(CorePosState[eCSN_Core1]==eCPS_AllEnd))	//中子A退终		主要在AL_Robot.c中调用
#define CoreBOutIsEnd()	((CorePosState[eCSN_Core2]==eCPS_OutEnd)||(CorePosState[eCSN_Core2]==eCPS_AllEnd))	//中子B退终		主要在AL_Robot.c中调用


Bool ALCF_CoreIn_IsCoreA(void);			//ALCF_CoreIn()函数在执行的中子为CoreA		主要在AL_Robot.c中调用
Bool ALCF_CoreIn_IsCoreB(void);			//ALCF_CoreIn()函数在执行的中子为CoreB		主要在AL_Robot.c中调用

Bool ALCF_CoreOut_IsCoreA(void);		//ALCF_CoreOut()函数在执行的中子为CoreA		主要在AL_Robot.c中调用
Bool ALCF_CoreOut_IsCoreB(void);		//ALCF_CoreOut()函数在执行的中子为CoreB		主要在AL_Robot.c中调用

Bool CoreAInIsRun(void);				//中子A进有效执行检查						主要在AL_Robot.c中调用
Bool CoreBInIsRun(void);				//中子B进有效执行检查						主要在AL_Robot.c中调用

Bool CoreAOutIsRun(void);				//中子A退有效执行检查						主要在AL_Robot.c中调用
Bool CoreBOutIsRun(void);				//中子B退有效执行检查						主要在AL_Robot.c中调用

void MoldCls_CoreEndRet(void);			//中子进终状态复位
void MoldOpen_CoreEndRet(void);			//中子退终状态复位

void MoldClsCoreRunCntRes(void);
void MoldOpeCoreRunCntRes(void);

#endif
