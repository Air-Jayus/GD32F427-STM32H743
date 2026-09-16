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
#ifndef Monitor_h
	#define Monitor_h

#ifdef Monitor_c
	#define Monitor_ext
#else
	#define Monitor_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/


/*======================================== 全局有效变量定义 =======================================*/
enum eMonMode{eMM_UpLow,eMM_Up};		//监测模式
enum eChkOcc{eCO_SecWhole,eCO_SecEnd,eCO_SecEndDly};	//监测时机
enum eChkStep{eCS_Wait,eCS_Mon,eCS_End};//监测步骤

typedef const struct{
	enum eMonMode Mode;		//监测模式				0-上、下限	1-上限
	Bool MonAlarmOnChk;		//监测警报开启才检查	1-监测警报开启才有效	0-任何情况下均有效	主要受是否有最大值影响
	enum eChkOcc ChkOcc;	//超差检查时机			0-动作段全程	1-动作段结束时
	U32 * Maximum;			//最大值				系统参数	无该项的监测对象，MonAlarmOnChk应为1，即监测警报开启才有效，否则无初始标准数据
	U32 * SetStand;			//用户设置标准值		生产参数
	U32 * Dev;				//允许偏差				生产参数
	U32 * OLPcs;			//超差处理				生产参数
	U16 * WSStand;			//标准值				工作状态	20160506加
	U16 * WSUpLim;			//上限					工作状态
	U16 * WSLowLim;			//下限					工作状态
	U16 * WSReal;			//实时值				工作状态
	U16 * WSLast;			//上一模				工作状态
	U16 * WSOL;				//超差					工作状态	B0-当前模	B1-上一模
	Bool EnNegFlag;			//允许负值				如果是位置，则允许负值
	S16 WSSacle;			//状态值缩小比例		如位置是/100、时间是/10000
}MonObjAttrStr;	//监测对象属性

typedef struct{
	MonObjAttrStr *MOAP;	//属性
	U32 DevBuff;			//允许偏差缓存			当发生改变时，更新一次上、下限
	S32 Real;				//实时值
	S32 Last;				//上一模
	S32 Stand;				//标准值
	S32	UpLim;				//上限					为0xffffffff，则上限不比较
	S32	LowLim;				//下限					为0，则下限不比较
	U32 SetStandBuff;		//设置标准值缓存		当发生改变时，更新一次上、下限	20160506
	U16 OLPrompt;			//超限提示		
	U8  OLFlag;				//当前模超限标志		B0-当前模	B1-上一模
	enum eChkStep ChkStep;	//检查步骤
}MonObjStr;		//监测对象结构

typedef const struct{
	MonObjStr *MOP;			//监测对象
                        	
	U8 ActSeg[3];			//动作细分		0xff		任意动作细分
	U8 SecIDBtw[2];			//段ID区间		Start～End
	                    	
	U16 PromptSN;			//提示代码		超差处理为提示时用，mASN_Null为无效
	U16 PromptAtttr;		//提示属性		二次配置属性，mAA_Def则用默认属性
	U16 AlarmSN;			//警报代码		超差处理为警报时用，mASN_Null为无效
	U16 AlarmAttr;			//警报属性		二次配置属性，mAA_Def则用默认属性
                        	
	FReqStr const *Req;		//警报时调度请求	会自动生成相应流程及组、并且对同组流程有效
}MonAlarmStr;	//监测警报结构
	#define mMAFR_Null		0	//警报调度请求空

#define mMOP_CycTi         &MonObj[ 0]	//循环时间           
#define mMOP_MoldClsTi     &MonObj[ 1]	//关模时间           
#define mMOP_MoldClsLPTi   &MonObj[ 2]	//关模低压时间       
#define mMOP_MoldClsHPTi   &MonObj[ 3]	//关模高压时间       
#define mMOP_MoldOpenTi    &MonObj[ 4]	//开模时间           
#define mMOP_MoldOpenEPos  &MonObj[ 5]	//开模结束位置       
#define mMOP_InjectTi      &MonObj[ 6]	//射出时间           
#define mMOP_InjectEPos    &MonObj[ 7]	//射出结束位置       
#define mMOP_InjectSpd     &MonObj[ 8]	//射出最高速度       
#define mMOP_ChargeTi      &MonObj[ 9]	//储料时间           
#define mMOP_ChargeEPos    &MonObj[10]	//储料结束位置       
#define mMOP_ChargeRPM     &MonObj[11]	//储料最高转速       
#define mMOP_SuckBackTi    &MonObj[12]	//射退时间           
#define mMOP_HoldPresSPos  &MonObj[13]	//保压转换位置       
#define mMOP_HoldPresTi    &MonObj[14]	//保压转换时间       
#define mMOP_HoldPresPres  &MonObj[15]	//保压转换压力       
#define mMOP_EjeForTi      &MonObj[16]	//托模时间           
#define mMOP_InjPeakPres   &MonObj[17]	//注射峰值压力    20120821加

#define mMonObjNum	18		//17		20120821改：增加注射峰值压力

#ifdef Monitor_c
U32 Para_Max_0=0;  						//辅助用
MonObjAttrStr MonObjAttr[mMonObjNum]={	//监测对象属性			20160506加工作状态标准值
	//监测模式	警开检查 检查时机		最大值					标准值				  	允许偏差		    	超差处理				标准值						上限					   	下限						实时值					 	上一模					 	超差				   	允许负值	缩小比例
	{eMM_Up,	mFalse,	 eCO_SecWhole, 	&Para_CycMaxTi,			&Para_CycTiStd       	,&Para_CycTiDev       	,&Para_CycTiOLP       	,&State_CycTiStd       	    ,&State_CycTiUpLim       	,&State_CycTiLowLim       	,&State_CycTiReal       	,&State_CycTiLast       	,&State_CycTiOL       	,mFalse		,10000		},//循环时间     
	{eMM_Up,	mTrue,	 eCO_SecWhole,	&Para_Max_0,			&Para_MoldClsTiStd   	,&Para_MoldClsTiDev   	,&Para_MoldClsTiOLP   	,&State_MoldClsTiStd   	    ,&State_MoldClsTiUpLim   	,&State_MoldClsTiLowLim   	,&State_MoldClsTiReal   	,&State_MoldClsTiLast   	,&State_MoldClsTiOL   	,mFalse		,10000		},//关模时间     
	{eMM_Up,	mFalse,	 eCO_SecWhole,	&Para_MoldClsLPMaxTi,	&Para_MoldClsLPTiStd 	,&Para_MoldClsLPTiDev 	,&Para_MoldClsLPTiOLP 	,&State_MoldClsLPTiStd 	    ,&State_MoldClsLPTiUpLim 	,&State_MoldClsLPTiLowLim 	,&State_MoldClsLPTiReal 	,&State_MoldClsLPTiLast 	,&State_MoldClsLPTiOL 	,mFalse		,1000		},//关模低压时间 20240913改显示2位小数
	{eMM_Up,	mFalse,	 eCO_SecWhole,	&Para_MoldClsHPMaxTi,	&Para_MoldClsHPTiStd 	,&Para_MoldClsHPTiDev 	,&Para_MoldClsHPTiOLP 	,&State_MoldClsHPTiStd 	    ,&State_MoldClsHPTiUpLim 	,&State_MoldClsHPTiLowLim 	,&State_MoldClsHPTiReal 	,&State_MoldClsHPTiLast 	,&State_MoldClsHPTiOL 	,mFalse		,10000		},//关模高压时间 
	{eMM_Up,	mTrue,	 eCO_SecWhole,	&Para_Max_0,			&Para_MoldOpenTiStd  	,&Para_MoldOpenTiDev  	,&Para_MoldOpenTiOLP  	,&State_MoldOpenTiStd  	    ,&State_MoldOpenTiUpLim  	,&State_MoldOpenTiLowLim  	,&State_MoldOpenTiReal  	,&State_MoldOpenTiLast  	,&State_MoldOpenTiOL  	,mFalse		,10000		},//开模时间     
	{eMM_UpLow,	mTrue,	 eCO_SecEndDly,	&Para_Max_0,			&Para_MoldOpenEPosStd	,&Para_MoldOpenEPosDev	,&Para_MoldOpenEPosOLP	,&State_MoldOpenEPosStd	    ,&State_MoldOpenEPosUpLim	,&State_MoldOpenEPosLowLim	,&State_MoldOpenEPosReal	,&State_MoldOpenEPosLast	,&State_MoldOpenEPosOL	,mTrue		,100		},//开模结束位置 20260205
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_InjectTiStd    	,&Para_InjectTiDev    	,&Para_InjectTiOLP    	,&State_InjectTiStd    	    ,&State_InjectTiUpLim    	,&State_InjectTiLowLim    	,&State_InjectTiReal    	,&State_InjectTiLast    	,&State_InjectTiOL    	,mFalse		,10000		},//射出时间     
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_InjectEPosStd  	,&Para_InjectEPosDev  	,&Para_InjectEPosOLP  	,&State_InjectEPosStd  	    ,&State_InjectEPosUpLim  	,&State_InjectEPosLowLim  	,&State_InjectEPosReal  	,&State_InjectEPosLast  	,&State_InjectEPosOL  	,mTrue		,100		},//射出结束位置
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_InjectSpdStd   	,&Para_InjectSpdDev   	,&Para_InjectSpdOLP   	,&State_InjectSpdStd   	    ,&State_InjectSpdUpLim   	,&State_InjectSpdLowLim   	,&State_InjectSpdReal   	,&State_InjectSpdLast   	,&State_InjectSpdOL   	,mFalse		,1			},//射出最高速度 
	{eMM_Up,	mFalse,	 eCO_SecWhole,	&Para_ChgMaxTi,			&Para_ChargeTiStd    	,&Para_ChargeTiDev    	,&Para_ChargeTiOLP    	,&State_ChargeTiStd    	    ,&State_ChargeTiUpLim    	,&State_ChargeTiLowLim    	,&State_ChargeTiReal    	,&State_ChargeTiLast    	,&State_ChargeTiOL    	,mFalse		,10000		},//储料时间     
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_ChargeEPosStd  	,&Para_ChargeEPosDev  	,&Para_ChargeEPosOLP  	,&State_ChargeEPosStd  	    ,&State_ChargeEPosUpLim  	,&State_ChargeEPosLowLim  	,&State_ChargeEPosReal  	,&State_ChargeEPosLast  	,&State_ChargeEPosOL  	,mTrue		,100		},//储料结束位置 
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_ChargeRPMStd   	,&Para_ChargeRPMDev   	,&Para_ChargeRPMOLP   	,&State_ChargeRPMStd   	    ,&State_ChargeRPMUpLim   	,&State_ChargeRPMLowLim   	,&State_ChargeRPMReal   	,&State_ChargeRPMLast   	,&State_ChargeRPMOL   	,mFalse		,1			},//储料最高转速 
	{eMM_Up,	mFalse,	 eCO_SecWhole,	&Para_SuckBackMaxTi,	&Para_SuckBackTiStd  	,&Para_SuckBackTiDev  	,&Para_SuckBackTiOLP  	,&State_SuckBackTiStd  	    ,&State_SuckBackTiUpLim  	,&State_SuckBackTiLowLim  	,&State_SuckBackTiReal  	,&State_SuckBackTiLast  	,&State_SuckBackTiOL  	,mFalse		,10000		},//射退时间     
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_HoldPresSPosStd	,&Para_HoldPresSPosDev	,&Para_HoldPresSPosOLP	,&State_HoldPresSPosStd	    ,&State_HoldPresSPosUpLim	,&State_HoldPresSPosLowLim	,&State_HoldPresSPosReal	,&State_HoldPresSPosLast	,&State_HoldPresSPosOL	,mTrue		,100		},//保压转换位置
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_HoldPresTiStd  	,&Para_HoldPresTiDev  	,&Para_HoldPresTiOLP  	,&State_HoldPresTiStd  	    ,&State_HoldPresTiUpLim  	,&State_HoldPresTiLowLim  	,&State_HoldPresTiReal  	,&State_HoldPresTiLast  	,&State_HoldPresTiOL  	,mFalse		,10000		},//保压转换时间 
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_HoldPresSPresStd	,&Para_HoldPresSPresDev	,&Para_HoldPresSPresOLP	,&State_HoldPresSPresStd	,&State_HoldPresSPresUpLim	,&State_HoldPresSPresLowLim	,&State_HoldPresSPresReal	,&State_HoldPresSPresLast	,&State_HoldPresSPresOL	,mFalse		,1			},//保压转换压力 
	{eMM_Up,	mTrue,	 eCO_SecWhole,	&Para_Max_0,			&Para_EjeForTiStd    	,&Para_EjeForTiDev    	,&Para_EjeForTiOLP    	,&State_EjeForTiStd    	    ,&State_EjeForTiUpLim    	,&State_EjeForTiLowLim    	,&State_EjeForTiReal    	,&State_EjeForTiLast    	,&State_EjeForTiOL    	,mFalse		,10000		},//托模时间     
	{eMM_UpLow,	mTrue,	 eCO_SecEnd,	&Para_Max_0,			&Para_InjPeakPresStd   	,&Para_InjPeakPresDev  	,&Para_InjPeakPresOLP  	,&State_InjPeakPresStd   	,&State_InjPeakPresUpLim   	,&State_InjPeakPresLowLim   ,&State_InjPeakPresReal   	,&State_InjPeakPresLast   	,&State_InjPeakPresOL   ,mFalse		,1			},//注射峰值压力	20120821加
};
MonObjStr MonObj[mMonObjNum]={			//监测对象
	//属性					
	{&MonObjAttr[ 0],	},//循环时间     
	{&MonObjAttr[ 1],	},//关模时间     
	{&MonObjAttr[ 2],	},//关模低压时间 
	{&MonObjAttr[ 3],	},//关模高压时间 
	{&MonObjAttr[ 4],	},//开模时间     
	{&MonObjAttr[ 5],	},//开模结束位置 
	{&MonObjAttr[ 6],	},//射出时间     
	{&MonObjAttr[ 7],	},//射出结束位置 
	{&MonObjAttr[ 8],	},//射出最高速度 
	{&MonObjAttr[ 9],	},//储料时间     
	{&MonObjAttr[10],	},//储料结束位置 
	{&MonObjAttr[11],	},//储料最高转速 
	{&MonObjAttr[12],	},//射退时间     
	{&MonObjAttr[13],	},//保压转换位置 
	{&MonObjAttr[14],	},//保压转换时间 
	{&MonObjAttr[15],	},//保压转换压力 
	{&MonObjAttr[16],	},//托模时间     
	{&MonObjAttr[17],	} //注射峰值压力    20120821加    
};

#else
Monitor_ext U32 Para_Max_0;
Monitor_ext MonObjAttrStr MonOibAttr[mMonObjNum];
Monitor_ext MonObjStr MonObj[mMonObjNum];
#endif


/*======================================== 全局有效函数声明 =======================================*/
void Monitor_Init(void);			//监测初始化				初始化执行
void Monitor_Pcs(void);				//监测处理					主循环执行
void Monitor_AutoModeStart(void);	//自动模式开始监测处理		自动循环开始调用，指刚开始自动循环，非每个循环开始	Scheduler.c中调用 初始化监测数据
void Monitor_CycEnd(void);			//一模循环结束监测处理		自动循环结束调用，指每个循环结束					Scheduler.c中调用 本模复位、上一模更新

enum eMonState{eMS_Start,eMS_Mid,eMS_End};
	//eMS_Start		开始
	//eMS_Mid		中间过程
	//eMS_End		结束
Bool MonAlarm(S32 MonData,FlowStr *FP,FActAttrStr *FAAP,MonAlarmStr *MAP);	//监测警报		动作中调用，监测某项数据
Bool MonAlarmEndDlyFunAdd(void (* MonAlrEndDlyP)(),FlowStr *FP,FActAttrStr *FAAP,MonAlarmStr *MAP);
Bool MonAlarmEndDly(S32 MonData,MonAlarmStr *MAP);

void MonAlarm_CycTi_Start(U32 CycTi,MonObjStr * MOP);		//全程计时监测（开始）
void MonAlarm_CycTi(U32 CycTi,MonObjStr * MOP);				//全程计时监测（过程）

Bool CurrMoldShotIsBad(void);								//当前模是否不良品检查		由AL_AssAct.c中CycEndCntPcs()函数、AL_Robot.c中AL_RobotWaitChk_MoldOpenStart()调用

#endif

