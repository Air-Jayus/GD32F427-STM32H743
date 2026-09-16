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
#ifndef Action_h
	#define Action_h

#ifdef Action_c
	#define Action_ext
#else
	#define Action_ext extern
#endif

//段枚举类型定义-------------------------------------------------------------------------------//
enum eSECCT{eSECCT_DIIsTrue,eSECCT_DIIsFalse,eSECCT_ValueIsTrue,eSECCT_ValueIsFalse,eSECCT_TimeOver,
			eSECCT_MCPosOver,eSECCT_MOPosOver,eSECCT_SFPosOver,eSECCT_SRPosOver,eSECCT_EFPosOver,eSECCT_ERPosOver,eSECCT_NFPosOver,eSECCT_NRPosOver};
	//SecEndCondStr.CondType
	//eSECCT_DIIsTrue……资源DI为mTrue			eSECCT_DIIsFalse……资源DI为mFlase
	//eSECCT_ValueIsTrue…值为mTrue				eSECCT_ValueIsFalse…值为mFlase
	//eSECCT_TimeOver……时间到(段10us计时器)														单位固定10us
	//eSECCT_MCPosOver……关模位置到				eSECCT_MOPosOver……开模位置到					单位固定1um
	//eSECCT_SFPosOver……螺杆进位置到(注射)		eSECCT_SRPosOver……螺杆退位置到(射退、储料)		单位固定1um
	//eSECCT_EFPosOver……顶针进位置到			eSECCT_ERPosOver……顶针退位置到					单位固定1um
	//eSECCT_NFPosOver……座台进位置到			eSECCT_NRPosOver……座台退位置到					单位固定1um
	
enum eDT{eDT_Const,eDT_U8P,eDT_U16P,eDT_U32P};
	//数据类型
	//eDT_Const		U32常量
	//eDT_U8P		U8变量地址
	//eDT_U16P		U16变量地址
	//eDT_U32P		U32变量地址

enum eSCL{eSCL_Or,eSCL_And};	
	//结束条件之间逻辑
	//eSCL_Or		或
	//eSCL_And		与

//段结构定义---------------------------------------------------------------------------------------//
typedef const struct 
{
	U8 SecID;				//段ID
	U8 SecDisp;				//段显示				mActDisp_Transparent-继承显示属性，即不更新原显示
	U16 Prompt;				//警报、提示			mAlarm_NoAlarm-无警报		段结束立即清除
}SecAttrStr;	//段属性

typedef union
{
	U32 *U32P;
	U32 Const;
	U8  *U8P;
	U16 *U16P;
}SU32;

typedef const struct
{
	enum eSECCT CondType;	//条件类型
	SU32 Para;				//条件参数
	enum eDT ParaType;		//参数类型
}SecEndCondStr;	//段结束条件		通常是单目条件，此部分可根据实际情况进行扩充，如条件类型增加“系统压力”、“注射压力”等。

typedef const struct
{
	U16	DOResSN;			//DO资源序号
	
	U32 *OnDly;				//开启延时			单位10us，每段都有效
	U32 *OnTime;			//输出时间			单位10us
	
	U32 *ActEndOffDly;		//动作结束延迟关时间 	单位10us
}SecDOStr;		//段DO输出
	
typedef const struct
{	
	enum eDAC DAChan;		//DA资源序号			0-主压力阀		1-主流量阀	2-背压阀	3-开模阀（双向）	4-关模阀（双向）	5-注射阀（双向）	6-射退阀（双向）	……
	U32  *Scale;			//比例因子
	U32  *DAValue;			//输出值
	
	U32 *OnRamp;			//输出斜率			单位10us
	
	U32 *ActStartOnDly;		//动作开始输出延时	单位10us，指动作刚好在该段开始时，经延时输出DA
	U32 *ActStartOnRamp;	//动作开始斜率		单位10us，指动作刚好在该段开始时，采用的斜率
	U32 *ActEndOffRamp;		//动作结束斜率		单位10us，指动作刚好在该段结束时，关闭斜率；最长时间取决于DO的延迟关时间，即所有DO延迟关时间到，则同时关DA输出
}SecDAStr;		//段DA输出

typedef void (* TSecFunP)(FActAttrStr * FAAP,void *AP);	//段函数指针

typedef const struct
{
	SecAttrStr SecAttr;			//段属性
	SecDOStr DOOut[mSecDONum];	//DO输出
	SecDAStr DAOut[mSecDANum];	//DA输出
	SecEndCondStr EndCondP[2];	//结束条件		固定一个结束条件，如果有多个，则通过段函数实现
	enum eSCL CondLog;			//条件逻辑		与、或
	U8   NextSecID;				//下一段ID				
	TSecFunP SecCallFunP;		//段调用函数		0-无效	每个段都可附带一个函数，该段执行时同步调用，利用该函数执行非标功能，如段分支跳转、多重判断等
								//						该函数先于DO输出、DA输出、结束判断被执行，且该函数中改变ActStep时，将不执行本轮DO、DA等
}SectionStr;	//段结构							固定Const类型
	#define mSNS_Def	0xff//下一段ID采用默认，即顺序下一段
	#define mSSFP_Null	0	//段附带函数无效

//动作结构定义-------------------------------------------------------------------------------------//
#define mAS_SecNum	28	//动作中最大段数

enum eASHT{eASHT_UnHold,eASHT_Hold};	
	//eASHT_UnHold		动作非自保持
	//eASHT_Hold		动作为自保持
enum eASBA{eASBA_Def,eASBA_DisBrk};
	//eASBA_Def				默认属性
	//eASBA_DisBrk			禁止中断		如：马达关，禁止被打断。其它动作使用要特别注意，因为调度请求会被清除，可能出现意外逻辑

typedef struct
{	
	U8	Group;					//动作组别			动作宏观类别		如：冷却类、合模类、注射类
	U16	ActID;					//动作ID
	enum eASHT SelfHoldType;	//自保持类型		动作是否自保持		如：储料、清料、马达
	enum eASBA BrkAttr;			//中断属性			动作被中断时属性，主要用于马达开、关动作
	U16	MainPosSnr;				//主位置传感器		使用资源序号，如：mRU_MoldSnrAD...
	U16	DefDisp;				//默认显示			如果段未设置显示，则显示该名称
	enum eFATCM TimeCntMode;	//时间、计数模式	如果要改变显示模式，通过直接改变Flow[].ActAttr[].TimeCntMode实现
	U32 *SetTime;				//设置时间
	U32 *SetCnt;				//设置次数
	U32 ActResp;				//动作响应			应伺服驱动器加
								//					目前暂定义：对应所有驱动器的响应、最高4位对应特殊（如注射动作响应根据Para_SDInjActRespLevel变量）
								//					必要时可以重新定义，如每4位对应一路DA（SecDAStr）响应、又如每4位对应一个驱动器响应，介时只需修改ActionStr AS_xxx中定义、Action.c中SetActResp()相关处理即可
								//					20120225改，最低字节对应HCI300驱动器、最高二字节对应J5卡多段PID(支持4个驱动器)

	U16 ActSecNum;				//动作段数			最多36段
	Bool SecFlag[mAS_SecNum];	//段是否有效标志	mTrue-对应段有效	用以实现如：注射1-10段配置
	SectionStr *SectionP;		//段数组指针
	
	U32 *ActStartDly;			//动作启动延时		
	U32 *ActEndDly;				//动作结束延时		

	TActFunP ActCallFunP;		//动作调用的函数	用该函数指针提供修改时与内部循环同等的执行机会，从RunState为Start开始有效调用（即eFARS_Init状态不会经历）
	const U8 * Description;		//动作描述			用于界面动作流程的显示,字符串类型，最好由中英文组成，如“关模Clamp”
}ActionStr;		//动作结构
	#define mAACFP_Null		0	//ActCallFunP为空，未指向函数

//动作、段监控结构定义-----------------------------------------------------------------------------//
typedef const struct 
{
	U8 ActGroup;				//动作组		0xff		任意动作组
	U16 ActFunID;				//动作函数ID	0xff		任意动作函数ID
	U8 ActSeg[3];				//动作细分		0xff		任意动作细分
	U8 RunState[3];				//运行状态		0xff		任意动作细分
	U8 RunResults[3];			//运行结果		0xff		任意结果
	U8 SecIDBtw[2];				//段ID区间		1组，以S～E，无效用mASID_Null
}ActMonStr;		//动作监控
typedef const struct 
{
	U8 ActSeg[3];				//动作细分		0xff		任意动作细分
	U8 RunState[3];				//运行状态
	U8 RunResults[3];			//运行结果		0xff		任意结果
	U8 SecIDBtw[2];				//段ID区间		1组，以S～E，无效用mASID_Null
}SecMonStr;		//动作中段的监控
	#define	mAG_Any			0xff		//动作组		任意
	#define mAFID_Any		0xff		//动作函数ID	任意
	#define mFARS_Any		0xff		//运行状态		任意
	#define mASEG_Any		0xff		//细分 			任意
	#define	mFARR_Any		0xff		//运行结果		任意
	#define mASID_Any		0xff		//段ID			任意

typedef struct
{
	SecMonStr *SMP;		//监控对象
	U16 AlarmSN;		//警报序号
	FReqStr const *FRP;	//调度请求
	
	Bool GenFlag;		//已经生成警报、请求标志
}MonAlarmBrkReqStr;	//监控、生成警报和中断类型的调度请求	
					//主要用于动作逻辑中，监控并生成警报和调度请求
					//限用于生成中断动作类型的调度请求，因为只会产生一次
					//为保证标志为复位，最好用于动作循环中、重复调用
//-------------------------------------------------------------------------------------------------//
typedef struct
{
	U16 ResSN;				//阀对应资源
	U32 * DlyTime;			//延迟			开始输出延迟
	U32 * OutTime;			//输出时间
	G10usTimer ValTimer;	//阀计时器
	Bool OnFlag;			//输出标志
}ActParaValStr;	//动作并行阀结构

//动作逻辑结构定义---------------------------------------------------------------------------------//
enum eLSUMC{eLSUMC_Any,eLSUMC_DisAU,eLSUMC_EnAU,eLSUMC_DisAM,eLSUMC_EnAM,eLSUMC_DisAUAM,eLSUMC_EnAUAM};
	//eLSUMC_Any		0	任意模式
	//eLSUMC_DisAU		1	禁止自动模式
	//eLSUMC_EnAU		2	只允许自动模式
	//eLSUMC_DisAM		3	禁止调模模式
	//eLSUMC_EnAM		4	只允许调模模式
	//eLSUMC_DisAUAM	5	禁止自动、调模模式
	//eLSUMC_EnAUAM		6	只允许自动、调模模式
enum eLSRR{eLSRR_Def,eLSRR_EndOK,eLSRR_EndErr};
	//eLSRR_Def		0	默认，不给出执行结果
	//eLSRR_EndOK	1	正常结束，即该段执行后就正常结束
	//eLSRR_EndErr	2	出错结束，即该段执行后就出错结束
typedef const struct
{
	U8 SecID;				//段ID	
	TActFunP ALP;			//动作逻辑指针
	U8 ActPara;				//动作逻辑函数调用时参数	即动作细分类型
	U8 UseActSeg;			//使用细分类型			用于区分适用细分类型
	enum eLSUMC UseModeConf;//使用模式配置			用于区分适用模式
	enum eLSRR RunResults;	//执行结果				该段执行时的结果，正常情况下结束执行、或出错情况下执行，该结果在该段一执行就给出
							//						例：关模失败开模时，执行开模时应eLSRR_EndErr
}LogSecStr;
	#define mLSAP_Def	0xff	//默认调用参数		即延用AL动作逻辑的细分类型，通常都用该属性，除非明确是特殊调用
								//					如：AL_MoldCls()中，AU_MoldCls是该属性，而调用安全门则用特殊属性mASEG_SafeGateCls_MoldCls
	#define mLSUAS_Any	0		//适用全部细分类型
	
#define mAL_LogSecNum	18
typedef struct
{
	U8	Group;						//动作组别			动作宏观类别		如：冷却类、合模类、注射类
	U16	ActID;						//动作ID
	enum eASHT SelfHoldType;		//自保持类型			动作是否自保持		如：储料、清料、马达
	enum eASBA BrkAttr;				//中断属性			动作被中断时属性	主要用于马达关动作，其它动作使用应特别注意
									//					只支持eASBA_DisBrk，且指禁止AL外部的Req，AL内产生的Req是可以的
									//					如：AL_MotOff()属性eASBA_DisBrk，AL_MotOff()有两段，用于执行这两个段的Req是允许的
									//						
	U16	DefDisp;					//默认显示			如果段未设置显示，则显示该名称

	U8 LogSecNum;					//逻辑段数			最多8段
	Bool LogSecFlag[mAL_LogSecNum];	//逻辑段是否有效标志	mTrue-对应段有效	用以实现如：注射1-10段配置
	LogSecStr *LogSecP;				//段数组指针

	TActFunP ActCallFunP;			//动作调用的函数		用该函数指针提供修改时与内部循环同等的执行机会，从RunState为Start开始有效调用（即eFARS_Init状态不会经历）
	const U8 * Description;			//动作描述			用于界面动作流程的显示,字符串类型，最好由中英文组成，如“关模Clamp”
	
	Bool GotoNexSecFlag;			//转下一段标志
	Bool IntSchReqFlag;				//有内部调度请求标志	用于实现eASBA_DisBrk中断属性(禁止外来的Req、但自身的Req是允许的)
	Bool ReRunFlag;					//动作重新执行标志	动作失败时，在AL一级如果还要执行连带动作，可通过此标志实现，方法是调用ALM_ReRunConf()
									//					此重新执行在RunState为End时生效，一般要求在RunState=End时调用执行ALM_ReRunConf()
									//					与正常动作执行的唯一区别是RunState无Init状态，即AUM_SecStartConf()不会有效
									//					如：关模失败开模，通过此方法实现（还要其它变量配合）
									//					注：马达开失败转马达关，因在AU一级，故是通过中断属性配置实现（动作中断调用函数）
}ActLogStr;		//动作逻辑结构
	//#define mAACFP_Null	0	//ActCallFunP为空，未指向函数

//-------------------------------------------------------------------------------------------------//

void Action_Init(void);		//动作初始化
void Action_Pcs(void);		//动作处理

TActFunP GetCodeActFun(U8 Code);									//获取指令(按键)对应动作地址
Bool ConfCodeActFun(U8 Code,TActFunP ActFunP);						//配置指令(按键)对应动作函数

void AUM_SerSecCtrl(FlowStr *FP,FActAttrStr * FAAP,ActionStr * AP);	//动作单元方法	顺序段控制
void AUM_SecJump(FActAttrStr * FAAP,ActionStr * AP,U8 SecID);		//动作单元方法	段跳转			动作中改变段，必须用该函数进行跳转
Bool AUM_SecStartConf(FActAttrStr * FAAP,ActionStr *AP,U32 SecConf);//动作单元方法	动作段初始配置
void AUM_SecConf(ActionStr * AP,U32 SecConf);						//动作单元方法	动作段配置
void AUM_ParaVal(FActAttrStr * FAAP,ActParaValStr * APVP,Bool OutFlag);	//动作并行控制	并行输出阀	与动作并行阀输出控制，如关模时差动阀
																		//				如遇切阀延时则与主阀同步切

void ALM_SerLogCtrl(FlowStr *FP,FActAttrStr * FAAP,ActLogStr * ALP);//动作逻辑方法	顺序逻辑控制
void ALM_SecJump(FActAttrStr * FAAP,ActLogStr * ALP,U8 SecID);		//动作逻辑方法	段跳转			动作中改变段，必须用该函数进行跳转
Bool ALM_SecStartConf(FActAttrStr *FAAP,ActLogStr *ALP,U32 SecConf);//动作逻辑方法	动作段初始配置
void ALM_SecConf(ActLogStr * ALP,U32 SecConf);						//动作逻辑方法	动作段配置
void ALM_ReRunConf(ActLogStr * ALP,U32 SecConf);					//动作逻辑方法	动作重新执行及段配置
void ALM_SetBrkAttr(ActLogStr * ALP,enum eASBA NewBrkAttr);			//动作逻辑方法	修改中断属性
void ALM_SetSelfHoldType(ActLogStr * ALP,enum eASHT NewType);		//动作逻辑方法	修改自保持属性

U8 APM_ActMon_FSN_MainFlow(ActMonStr *AMP);									//主流程动作并行监控	针对动作	返回FlowSN
U8 APM_ActMon_FSN_LinkFlow(ActMonStr *AMP);									//连动流程动作并行监控	针对动作	返回FlowSN
Bool APM_SecMon(FActAttrStr * FAAP,SecMonStr *SMP);							//动作并行监控	针对段
U8   APM_ActMon_FSN(ActMonStr *AMP);										//动作并行监控	针对动作	返回FlowSN
#define APM_ActMon(AMP)	(APM_ActMon_FSN(AMP)<mFlowNum)						//动作并行监控	针对动作	返回mTrue
U8 APM_ActMon_FSN_MainFlowTopLevel(ActMonStr *AMP);							//动作并行监控	针对动作	返回FlowSN	只检查主流程的最高一级动作
Bool APM_SecMon_AlarmReq(FlowStr *,FActAttrStr *,MonAlarmBrkReqStr *,Bool);	//动作并行监控	针对段、并生成警报和调度请求
																			//主要用于AL动作逻辑中、亦可用于AU
																			//调度请求是针对组的、且最好是中断动作一类的调度请求
																			//只会产生一次警报和调度
																			//应在动作循环中重复调用，否则标志可能不复位，产生异常

void Act_SetAlarmReq(FlowStr *FP,FActAttrStr *FAAP,U16 AlarmSN,FReqStr const *FRP);		//动作中输出警报、调度请求
Bool Act_IsFirstCyc(FActAttrStr * FAAP);				//动作第一个循环检查			必须在AUM_SerSecCtrl()函数前调用
Bool Act_IsFirstCyc_AftInit(FActAttrStr * FAAP);		//动作第一个循环检查			必须在AUM_SerSecCtrl()函数后面调用
Bool Act_IsLastCyc(FActAttrStr * FAAP);					//动作最后一个循环检查			必须在AUM_SerSecCtrl()函数前调用，否则可能是倒数第二个循环
Bool Act_IsSecStart(FActAttrStr * FAAP);				//段Start步骤，即段第一步
Bool Act_IsActive(FActAttrStr * FAAP);					//动作为当前动作检查(活跃状态，即非挂起)
Bool Act_ActSegChk(FActAttrStr * FAAP,U8 ActSeg);		//动作细分检查
Bool Act_RunResultsIsNor(FActAttrStr * FAAP);			//动作运行结果正常检查
Bool Act_RunResultsIsEndOK(FActAttrStr * FAAP);			//动作运行结果正常结束检查
Bool Act_RunResultsIsEndErr(FActAttrStr * FAAP);		//动作运行结果异常结束检查
Bool Act_RunResultsIsKeyBrk(FActAttrStr * FAAP);		//动作运行结果按键中断检查
Bool Act_ROInCurrSecDOTabChk(FActAttrStr * FAAP,ActionStr * AP,U16 RO);	//检查当前执行的段中是否有对应资源输出		主要用于AU_EjeFor.c中
U8 	 Act_GetCurrSecID(FActAttrStr * FAAP);				//获取当前动作段ID

Bool Act_MainFlow_DAUseChk(enum eDAC DAChan);			//主流程动作DA阀是否有使用检查		20130504加，大机变量泵动力为“变量泵+定量泵”

void Act_Null(void *FP,FActAttrStr *FAAP);				//空动作函数

Bool APM_ActMon_Group(U8 ActGroup);						//动作监控（根据动作组）				20160803加
Bool APM_ActMon_GrpFunID(U8 ActGroup,U16 ActFunID);		//动作监控（根据动作组及动作函数ID）	20160803加

#endif

