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
#ifndef Scheduler_h
	#define Scheduler_h

#ifdef Scheduler_c
	#define Scheduler_ext
#else
	#define Scheduler_ext extern
#endif

/*======================================= 全局有效定义、声明 ======================================*/

//调度申请相关枚举类型定义-------------------------------------------------------------------------//
enum eFRQ{eFRQ_Null,eFRQ_NewFA,eFRQ_InsConAct,eFRQ_InsReAct,eFRQ_FinAct,eFRQ_InsBrkAct,eFRQ_BrkAct,eFRQ_KeyBrkAct};	
//SchReqStr.Request						优先级	作用范围	
//	eFRQ_Null		0	无申请
//	eFRQ_NewFA		1	新开始流及动作		1	单个流程	例：按下动作键执行动作；自动循环开始一个动作
//	eFRQ_InsConAct	2	插入、继续动作		2	单个流程	限中子动作使用，以确保时序逻辑清晰
//	eFRQ_InsReAct	3	插入、重新开始动作	3	单个流程	限中子动作使用，以确保时序逻辑清晰
//	eFRQ_FinAct		4	正常结束动作		4	多个流程	例：排气开模，开模时间到
//	eFRQ_InsBrkAct	5	插入、中断动作		5	多个流程	限中子动作使用，以确保时序逻辑清晰
//	eFRQ_BrkAct		6	中断动作（异常）	6	多个流程	例：有警报停止动作；关模低压超时中断关模
//	eFRQ_KeyBrkAct	7	按键中断动作		7	多个流程	例：按下手动键；动作按键放开；立转手动警报

//注：eFRQ_BrkAct、eFRQ_KeyBrkAct差别在于：
//		1)如果是手动模式，出现前者不会撤消流程，而后者会；如果是自动模式，则无区别；
//      2)后者专用于动作按键放开、按下手动键、立转手动警报三种情况。
//	    3)eFRQ_InsBrkAct为多个流程时，FlowSN流程插入动作，而其它同组流程则是eFRQ_BrkAct中断动作
//		4)为使时序逻辑清晰，eFRQ_InsConAct、eFRQ_InsReAct、eFRQ_InsBrkAct限中子动作使用

enum eFRM{eFRM_AllDly,eFRM_OutDly,eFRM_ActDly,eFRM_Imm};
//SchReqStr.RespMode					在Request相同时，也影响优先级，值大优先级高
//	eFRM_AllDly		0	动作的所有延时后，即输出延时、动作延时后
//  eFRM_OutDly		1	动作的输出延时后
//	eFRM_ActDly		2	动作的动作延时后
//	eFRM_Imm		3	立即

enum eFREA{eFREA_Single,eFREA_Group,eFREA_All};
//SchReqStr.EffArea
//	eFREA_Single	0	FlowSN
//	eFREA_Group		1	同组流程
//	eFREA_All		2	所有流程

//动作属性相关枚举类型定义-------------------------------------------------------------------------//
enum eFARS{eFARS_Null,eFARS_Init,eFARS_Start,eFARS_Run,eFARS_HangRdy,eFARS_Hang,eFARS_End};
//FActAttrStr.RunState
//	eFARS_Null				0	无效
//	eFARS_Init				1	初始						仅动作刚建立时赋该值，Sch_GenReq()--FlowActAttrInit()--赋该值
//	eFARS_Start				2	开始		响应调度		尚未真正执行
//	eFARS_Run				3	正常执行中	响应调度
//	eFARS_HangRdy			4	挂起准备	响应调度
//	eFARS_Hang				5	挂起		不响应
//	eFARS_End				6	刚结束

enum eFARR{eFARR_Nor,eFARR_EndOK,eFARR_EndErr,eFARR_KeyBrkAct};
//FActAttrStr.RunResults
//	eFARR_Nor		0	正常
//	eFARR_EndOK		1	正常结束
//	eFARR_EndErr	2	异常结束
//	eFARR_KeyBrkAct	3	按键中断动作	动作按键放、按下手动键才会产生该执行结果
//										储料、清料等自动保持动作可能会借用该申请产生的执行结果，以自行结束之

enum eFATCM{eFATCM_Time,eFATCM_Cnt};
//FActAttrStr.TimeCntMode
//	eFATCM_Time		0	计时
//	eFATCM_Cnt		1	计数

//enum eEOM{eEOM_SecValid,eEOM_ActValid};
	//eEOM_SecValid		段有效，段结束、动作结束立即清除、关闭
	//eEOM_ActValid		动作有效，动作结束才清除、关闭
	//eEOM_ContValid	持续有效，动作结束后还有效				暂不支持

//输出表结构定义-----------------------------------------------------------------------------------//
#define mSecDONum	6	//段DO输出数量
#define mSecDANum	6	//段DA输出数量
typedef struct
{
	U16 DOResSN[mSecDONum];			//DO资源序号				0-空
	U32 DOOnDly[mSecDONum];			//开启延时											单位:10us
	U32 DOOnTime[mSecDONum];		//开时间					0-关闭	0x80000000-常开	单位:10us	
	U32 DOActEndDly[mSecDONum];		//动作结束切阀延时时间								单位:10us
	
	enum eDAC DAChan[mSecDANum];	//DA通道					
	Bool DAOutFlag[mSecDANum];		//DA已经输出标志			True--DA已输出，即开启斜率已经使用过
	U8   DAScale[mSecDANum];		//比例
	U32 DAValue[mSecDANum];			//DA值		
	U32 DAOnRamp[mSecDANum];		//开启斜率											单位:10us
	U32 DAOnDly[mSecDANum];			//开启延时											单位:10us
	U32 DAActEndOffRamp[mSecDANum];	//动作结束时斜率									单位:10us
	
	U16 Prompt;						//提示						mAlarm_NoAlarm-无(CM_Alarm.h中宏)
}OutTabStr;	//输出表
	#define mOT_DOResSN_Null	0	//DO资源序号空
	
//流动作属性结构定义-------------------------------------------------------------------------------//
typedef struct
{
	U8			FlowSN;			//调度	流序号			0～5
	U8			FlowLevel;		//调度	级次			0～5
	U16			ActFunID;		//调度	动作函数ID		全局唯一
	U8			SecID;			//调度	段 ID			动作中唯一
	U8			ActSeg;			//调度	动作细分		精确描述动作		如：正常开模、关模失败开模、排气开模
	U8			ActGroup;		//调度	动作组别		动作宏观类别		如：冷却类、合模类、注射类

	U8			ActStep;		//调度	动作步骤		动作中段执行步骤	ActStep直接即段函数序号，除非ActStep为mFAAAS_Start等值
	U8			SecStep;		//调度	段步骤			段中细分的执行步骤
	enum eFARS	RunState;		//调度	执行状态			
	enum eFARR	RunResults;		//调度	执行结果		RunState=eFARS_End时为最终执行结果，否则也用作存放中间结果
	
	enum eFRQ	ReqBuff;		//调度	调度请求暂存	有调度时使用，暂存调度请求
	enum eFRM	RespModeBuff;	//调度  响应模式暂存	有调度时使用，暂存响应模式
	U8			ActStepBuff;	//调度	动作步骤暂存	有调度时使用，暂存动作步骤
	U8			SecIDBuff;		//调度	段ID暂存		有调度时使用，暂存段ID
	
	U32			RoundCnt;		//状态	执行循环周期数
	U8			Display;		//状态	显示动作名（段名）
	enum eFATCM	TimeCntMode;	//状态	计时或计数模式
	U16			SetTime;		//状态	设置时间		单位:100ms
	U16			SetCnt;			//状态	设置次数
	U16			ActCounter;		//状态	操作计数器
	G10usTimer	ActTimer;		//状态	操作计时器		也用作动作超时监控	当有其它动作插入，计时不停、不复位（T6F2也采用此方式）
	
	G10usTimer  SecTimer;		//段计时器				段公用
	OutTabStr 	OutTab;			//输出记录表		
}FActAttrStr;	//流动作属性
	//ActStep
	#define mFAAAS_TStartN	241	//真正开始			约定：此步骤只能被引用于检查动作开始，不能据此进入插入动作等，共同保证第一步真正执行完整、且一个动作中只会执行一次该步骤
	#define mFAAAS_TStartS	242	//真正开始S步骤			  此步骤可以被引用、并据此插入动作前进行的动作，如关模前中子、机械手等
	#define mFAAAS_TStartM	243	//真正开始M步骤			  同上
	#define mFAAAS_TStartE	244	//真正开始E步骤			  同上    注：开始设立多步，目的是区分插入优先级，不过实际意义不大，除中子、机械手并行外基本不这么用

	#define mFAAAS_LStart	245	//逻辑开始步骤			  动作被插入且重新开始时，恢复时开始执行的步骤

	#define mFAAAS_OutDly	246	//切阀延时				  DO、DA一起结束，以DO时间为准，即DO延时到DA一起关闭
	#define mFAAAS_EndDly	247	//动作结束延时	
	#define mFAAAS_LEnd		248	//逻辑结束步骤			  动作被插入进行挂起准备时，执行的最后步骤

	#define mFAAAS_TEndS	249	//真正结束S步骤			  此步骤可以被引用、并据此插入动作后进行的动作，如关模后中子等
	#define mFAAAS_TEndM	250	//真正结束M步骤			  同上
	#define mFAAAS_TEndE	251	//真正结束E步骤			  同上
	#define mFAAAS_TEndN	252	//真正结束				  此步骤只能被引用于检查动作开始，不能据此进入插入动作等，共同保证第一步真正执行完整、且一个动作中只会执行一次该步骤
	
	#define mFAAAS_RSEnd	253	//RunState为End时步骤	  仅用于识别动作最后一个循环
	#define	mFAAAS_Null		254	//空					  新建动作时使用，表示步骤尚无意义
	
	//SecStep
	#define	mFAASS_Null		0	//空
	#define mFAASS_Start	1	//启动			判断条件是否满足、生成OutTab
	#define mFAASS_Out		2	//输出
	#define mFAASS_ActDly	3	//动作延时		指动作开始延时
	#define mFAASS_EndChk	4	//结束检查

/*RunState、ActStep状态变换过程
RunState	ActStep/SecID			
Init			Null										禁止任意插入
Start			TStartN			确保只会执行一次			禁止任意插入、允许中断
Start			TStartS			通常一次，有插入则多次		允许插入继续或中断、禁止插入重新开始(恢复时直接转LStart,跳过一些步骤)
Start			TStartM			通常一次，有插入则多次		允许插入继续或中断、禁止插入重新开始(恢复时直接转LStart,跳过一些步骤)
Start			TStartE			通常一次，有插入则多次		允许插入继续或中断、禁止插入重新开始(恢复时直接转LStart,跳过一些步骤)
Start			LStart			插入重新开始时恢复执行点	一般不被引用
Start/Run		0~mASID_NorMax	可能不执行到，也可能多次	引用用于动作过程中段步骤识别，如高压关模
...				...
(有插入)
HangRdy			OutDly			有时会跳过					一般不被引用
HangRdy			EndDly										一般不被引用
HangRdy			LEnd			挂起准备最后执行步骤		一般不被引用
Hang			(恢复时步骤)	TStartS~0~mASID_NorMax~TEndE
...				...
(恢复)
Start			(恢复时步骤)	如果是插入重新开始，则LStart；如果出错，则直接转TEndS
Start/Run		0~mASID_NorMax
...				...
(结束)
Start/Run		OutDly			通常一次，有插入则多次		一般不被引用
Start/Run		EndDly			通常一次，有插入则多次		一般不被引用
Start/Run		LEnd			挂起准备最后执行步骤		一般不被引用
Start/Run		TEndS			通常一次，有插入则多次		允许任意插入(插入重新开始无意义，并不会重新再执行)
Start/Run		TEndM			通常一次，有插入则多次		允许任意插入(插入重新开始无意义，并不会重新再执行)
Start/Run		TEndE			通常一次，有插入则多次		允许任意插入(插入重新开始无意义，并不会重新再执行)
Start/Run		TEndN			确保只会执行一次			禁止任意插入、允许中断
End				Null

RunState必经步骤：Init--Start--End			直接结束时Run状态无、无插入时HangRdy和Hang状态无
ActStep 必经步骤：Null--TStartN--TStartS--OutDly--EndDly--LEnd--TEndS--TEndM--TEndE--TEndN
SecStep 必经步骤：Start
推荐引用段ID：TStartS～TStartE、0～mASID_NorMax、TEndS～TEndE，另TStartN、TEndN可用于识别动作开始和结束

实际程序中引用段ID(主要特殊引用，另以下引用均在AU动作单元):
	开终位置监测……………………………TEndS时检查	如果超差且报警，可避免机械手动作，确保与机械手取物之间良好配合
	开模机械手………………………………TEndM时输出	确保开模一结束立即输出机械手，不受连动、动作结束时执行中子的影响
	连动监控…………………………………TEndM时插入	若连动未结束，主动作执行到该步，立即插入连动等待，确保连动先结束
	中子(结束时执行)………………………TEndE时插入	各项结束后，再插入动作结束中子，如连动已经在TEndM步骤结束
	中子(开始时执行)………………………LStart时插入	由于ReAct插入会在动作恢复时转LStart步，所以必须在该步插入
	中子(中途执行、但结束时还未执行)…TEndS时插入	中途执行的中子，但条件一直到动作结束还未满足，则在TEndS时插入执行

	开模微观逻辑步骤：
	LStart…开模始出芯
	…………中途时出芯
	…………连动出芯/托模
	TEndS… 开终位置监测				
	TEndS… 中途出芯中子、但一直未出芯（如有连动中子、出芯位置与开终位置相同）	调度优先级低于"开终位置监测"时的超差警报，故超差时不会出芯
	TEndM… 开模机械手		开模一结束，立即输出机械手，不受连动、开终执行中子的影响
	TEndM… 连动监控		开模已经到位结束、但连动还在执行，插入连动等待，确保连动先于开模结束
	TEndE… 开终时出芯		开终时中子在各项结束后才出芯
	
	中子动作时机：
	中子（动作始）……LStart
	中子（中途）………LStart～TEndS		即使动作位置很大或很小
	中子（动作终）……TEndE

	排气微观逻辑步骤：
	注射后排气……mASID_AU_HoldPres_HP1
	保一后排气……mASID_AU_HoldPres_HP2
	保二后排气……mASID_AU_HoldPres_HP3
	保压后排气……mASID_TEndS
*/


//动作函数指针类型定义-----------------------------------------------------------------------------//
typedef void (* TActFunP)(void *,FActAttrStr *);	//动作函数指针类型	形参1：所在Flow[]的指针；形参2：所对应Flow[].FActAttr[]的指针 

//动作流程结构定义---------------------------------------------------------------------------------//
#define mAFS_ActFunNum	36					//动作流中动作函数个数

typedef struct {
	TActFunP ActFunP[mAFS_ActFunNum];		//动作函数指针

	U16	CycStartStep;						//循环开始步骤	产品循环开始的步骤序号，不包括自动方式启动时辅助步骤
	U16	CycEndStep;							//循环结束步骤	指步骤序号，非步骤数

	Bool ActFlowStartFlag;					//流程启动标志	
	U32 CycCnt;								//循环计次		0-刚开始
	U16 Step;								//步骤	
}ActFlowStr;	//动作流程

//调度请求结构定义---------------------------------------------------------------------------------//
typedef struct
{
	enum eFRQ	Request;		//调度请求		
	enum eFRM	RespMode;		//响应模式		
	U8			ActPara;		//动作参数		通常传递给FActAttrStr.ActSeg
	TActFunP	InsActFunP;		//动作函数入口	插入调度请求时的插入函数
	const U8  	*MemoP;			//调度说明		辅助，调试用，描述调度产生的原因
}FReqStr;		//流程调度请求结构

typedef struct
{
	U8 			FlowSN;			//流程号
	enum eFREA	EffArea;		//有效范围
	U8			Group;			//组号			只在新建流程时有效，主流程固定为0，并行流程使用相差的主流程序号，否则使用其流程序号为组号
								//				例：开模动作时，吹气启动，其组号同开模流程的组号；自动循环时有润滑动作，其组号为润滑流程的序号
								
	FReqStr		FReq;			//
}UReqStr;		//用户调度请求结构

//流程结构定义-------------------------------------------------------------------------------------//
#define mFlowNum		7	//流程数
#define mFlowLevelNum	7	//流程级数			最大流程：关模AL-(失败)-开模AL--开模AU--插入中子AL--插入等待机械手AL--等待机械手AU
typedef struct
{
	Bool		Flag;					//流程有效标志		mTrue--流程有效
	U8			Group;					//流程组别			同一组流程意味着是其下动作相互配合的，实现同步结束等
	U16			CurrLevel;				//当前级			表示当前最新嵌套的动作级数
	enum eFARR	State;					//流程状态			表示流程中动作的执行结果
	FReqStr		FReq;					//调度请求			流程开始、结束、中断、插入等，均通过此调度申请实现
	U32         ReqRunNum;				//调度请求流水号	
	FActAttrStr	FActAttr[mFlowLevelNum];//动作函数属性		与Flow中的动作函数一一对应
	TActFunP	FActFunP[mFlowLevelNum];//动作函数地址		每个动作都会执行，但只有当前级的完全执行
}FlowStr;	//流程
	#define mFlowLvl_Top		0				//最高一级
	
	//流程分配
	#define mFlow_Main		0	//主流程		尽量按照显示优先级分配流程
	#define mFlow_Air		1	//吹气
	#define mFlow_AutoGate	2	//自动门
	#define mFlow_AirInj	3	//气辅
	#define mFlow_Link		4	//连动			中子连动、顶针连动、BMC储料时连动(20120805加)
	#define mFlow_Lubr1		5	//润滑1
	#define mFlow_Lubr2		6	//润滑2
	
	//流程组
	#define mFlowGrp_Main 		0				//主流程组号
	#define mFlowGrp_Lubr1		mFlow_Lubr1		//润滑1组号
	#define mFlowGrp_Lubr2		mFlow_Lubr2		//润滑1组号
	#define mFlowGrp_AutoGate	mFlow_AutoGate	//自动门


//-------------------------------------------------------------------------------------------------//
enum eMode{eMode_Manu,eMode_SemiAuto,eMode_SenrAuto,eMode_TimeAuto,eMode_ManuMoldAdj,eMode_AutoMoldAdj,eMode_Test,eMode_SysStop};
//SysStateStr.CurrMode	与CMWMDef.h中定义一致
//	eMode_Manu			0	手动
//	eMode_SemiAuto		1	半自动
//	eMode_SenrAuto		2	电眼自动
//	eMode_TimeAuto		3	时间自动
//	eMode_ManuMoldAdj	4	手动调模模式
//	eMode_AutoMoldAdj	5	自动调模模式
//	eMode_Test			6	调试模式
//	eMode_SysStop		7	紧急停止模式

//系统状态相关函数---------------------------------------------------------------------------------//
Bool SysSta_IsManuMode(void);		//检查系统状态是否为手动模式

Bool SysSta_IsAutoMode(void);		//检查系统状态是否为自动模式			时间自动、电眼自动、半自动
Bool SysSta_IsTimeAutoMode(void);	//检查系统状态是否为时间自动模式		
Bool SysSta_IsSenrAutoMode(void);	//检查系统状态是否为电眼自动模式		
Bool SysSta_IsSemiAutoMode(void);	//检查系统状态是否为半自动模式		

Bool SysSta_IsSysStopMode(void);	//检查系统状态是否为紧急停止模式

Bool SysSta_IsMoldAdjMode(void);	//检查系统状态是否为调模模式			手动调模、自动调模
Bool SysSta_IsManuMoldAdjMode(void);//检查系统状态是否为手动调模模式		
Bool SysSta_IsAutoMoldAdjMode(void);//检查系统状态是否为自动调模模式

Bool SysSta_IsTestMode(void);		//检查系统状态是否为调试模式			IOTest、DATest

Bool SysSta_IsIdle(void);			//检查系统状态是否为空闲				手动、调模或紧急停止，且无动作
Bool SysSta_IsIdle_EnLubr(void);	//检查系统状态是否为空闲(润滑除外)		手动、调模或紧急停止，且无动作(润滑除外)	主要在Code.c中调用，实现手动润滑时，可进行其它动作

Bool SysSta_IsAutoModeFirstCyc(void);//检查系统状态是否为自动方式且首模
U32 SysSta_GetAutoModeCyc(void);	//获取自动循环模数

void SysSta_RstCycTimer(void);		//复位系统循环计时器

//Flow[]相关函数-----------------------------------------------------------------------------------//
void Flow_ActAttrInit(FActAttrStr *FAAP);							//流程中运作属性初始化
Bool Flow_SetRunResults(FActAttrStr *FAAP,enum eFARR RunResults);	//设置动作运行结果			修改Flow.FActAttr.RunResults
U8   Flow_GetTopLevActGroup(U8 FlowSN);								//获取流程最高一级动作组号
U8   Flow_GetFlowGroup(U8 FlowSN);									//获取流程组
FlowStr * Flow_GetFlowP(U8 FlowSN);									//获取流程地址
Bool Flow_SameFlowGroupAllIsOff(FActAttrStr *FAAP);					//同组流程均结束检查
Bool Flow_FlowIsOff(U8 FlowSN);										//流程结束检查
Bool Flow_AllFlowIsOff(void);										//所有流程关闭检查		所有流程的Flow[].Flag为mFalse
void Flow_UpdateActCounter(FActAttrStr * FAAP,U32 Cnt);							//更新动作计数
void Flow_SetActDispTiCntMode(FActAttrStr * FAAP,enum eFATCM NewTimeCntMode);	//设置动作计时、计数显示模式
void Flow_SetActDisp(FActAttrStr * FAAP,U8 ActDisp);							//设置动作显示

U8 Flow_GetFlowSN(FActAttrStr * FAAP);											//获取流程序号

//调度相关函数-------------------------------------------------------------------------------------//
U32 Sch_GenReq(UReqStr Req);													//生成调度请求
U32 Sch_GenReq_FReq(FReqStr const *FReq,U8 FlowSN,enum eFREA EffArea,U8 Group);	//生成调度请求
	#define mGenReqErr		0	//生成调度请求失败

void Sch_AutoModeModify(void);							//自动模式修正				停留托模只允许半自动		方式切换时、循环结束前调用
Bool Sch_ToNewMode(enum eMode NewMode);					//切换到新模式				需由主调函数负责切换时机
Bool Sch_ConfAutoModeMainActFlow(ActFlowStr const *ActFlow);	//配置自动模式主动作流程	主要由Action.c中初始化调用	20200713

void Sch_FreeToManuChk(void);			//空闲转手动检查		由自动循环中可以转手动的动作调用执行。在AL_AssAct.c的循环结束、循环开始时调用执行。
Bool Sch_GetFreeToManuState(void);		//获取闲转手动状态	在AL_EjeFor.c中用到
void Sch_SetImmToManu(void);			//设置立即转手动
void Sch_SetFreeToManu(void);			//设置闲转手动
void Sch_SetFreeHtrOff(void);			//设置闲关电热
void Sch_SetFreeMotOff(void);			//设置闲关马达

//-------------------------------------------------------------------------------------------------//
#define TimeAutoModeEnChk()	((Para_EjectMode!=mEjeMode_Hold)||Get_R_RobotUse())//时间自动方式允许检查	非停留方式或使用机械手
#define SenrAutoModeEnChk()	((Para_EjectMode!=mEjeMode_Hold)||Get_R_RobotUse())//电眼自动方式允许检查	非停留方式或使用机械手

//-------------------------------------------------------------------------------------------------//


void Scheduler_Init(void);				//调度初始化	
void Scheduler_Pcs(void);				//调度处理		于主循环


Bool SetDVOffDly(FActAttrStr *FAAP,U16 ResSn,U32 DlyTime);			//指定Do资源重新设置切阀延时	20190815
Bool SetPVEndRamp(FActAttrStr *FAAP,enum eDAC ResSn,U32 EndRamp);	//指定DA资源重新设置结束斜率	20190815


#endif

