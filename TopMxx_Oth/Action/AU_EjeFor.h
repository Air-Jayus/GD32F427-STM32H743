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
#ifndef AU_EjeFor_h
	#define AU_EjeFor_h

#ifdef AU_EjeFor_c
	#define AU_EjeFor_ext
#else
	#define AU_EjeFor_ext extern
#endif


//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义

//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
#define mASID_AU_EjeFor_SEFDly       	10 	//托进前延迟	停留、定次、震动
#define mASID_AU_EjeFor_SEF1         	15 	//托进一		停留、定次、震动
#define mASID_AU_EjeFor_SEF2         	20 	//托进二		停留、定次、震动
#define mASID_AU_EjeFor_SEFValOffDly 	25 	//托进切阀延时        定次、震动
#define mASID_AU_EjeFor_SEFPresHold 	26 	//托进压力保持  停留、定次		20230504加
#define mASID_AU_EjeFor_SEFActDly    	30 	//转换动作延时        定次、震动
#define mASID_AU_EjeFor_SERDly       	35 	//托退前延迟	      定次、震动
#define mASID_AU_EjeFor_CER1           	40 	//托退一			  定次      
#define mASID_AU_EjeFor_CER2           	45 	//托退二			  定次      
#define mASID_AU_EjeFor_CCntChk        	50 	//次数到检查	  	  定次      
#define mASID_AU_EjeFor_CERValOffDly   	55 	//托退切阀延时		  定次      
#define mASID_AU_EjeFor_CERActDly      	60 	//转换动作延时  	  定次      
#define mASID_AU_EjeFor_CEF2           	65 	//托进二			  定次      
#define mASID_AU_EjeFor_CEFValOffDly   	70 	//托进切阀延时  	  定次      
#define mASID_AU_EjeFor_CEFPresHold   	71 	//托进压力保持  	  定次 		20230504加
#define mASID_AU_EjeFor_CEFActDly      	75 	//转换动作延时  	  定次      
#define mASID_AU_EjeFor_VCntChk        	80 	//次数到检查		  		震动
#define mASID_AU_EjeFor_VER1           	85 	//托退一			  		震动
#define mASID_AU_EjeFor_VERValOffDly   	90 	//托退切阀延时  	  		震动
#define mASID_AU_EjeFor_VERActDly      	95 	//转换动作延时  	  		震动
#define mASID_AU_EjeFor_VEF2           	100 //托进二			  		震动
#define mASID_AU_EjeFor_VEFValOffDly   	105 //托进切阀延时  	  		震动
#define mASID_AU_EjeFor_VEFActDly      	110 //转换动作延时  	  		震动
#define mASID_AU_EjeFor_VEndER1        	115 //托退一			  		震动
#define mASID_AU_EjeFor_VEndER2        	120 //托退二			  		震动


#define mASID_AU_EjeFor_AM_EF			10	//调模托模

//动作函数-----------------------------------------------------------------------------------------//
void AU_EjectFor(void *FP,FActAttrStr *FAAP);
void AU_EjectFor_AM(void *FP,FActAttrStr *FAAP);

void AU_EjectForLink(void *FP,FActAttrStr *FAAP);		//连动托模进


void AU_EjectForLinkEndCore(void *FP,FActAttrStr *FAAP);//连动托模进时托进后中子处理	实际只调用托模中子处理函数
	#define mASID_AU_EjeForLinkEndCore_Null		10				

void AU_EjeForLinkWait(void *FP,FActAttrStr *FAAP);		//连动时等待					辅助动作
	#define mASID_AU_EjeForLinkWait_Wait		10				//等待

void AU_EjeFor1PauseTi(void *FP,FActAttrStr *FAAP);		//托进一段暂停时间				辅助动作	20170508
	#define mASID_AU_EjeFor1PauseTi_Pause		10				//暂停

#define EjeForIsEnd()			PosOverChk_EjeFor(Para_EjeForEPos)	//托进到位检查
#define EjeForInEndEffArea()	PosOverChk_EjeFor(Sub_MinZero(Para_EjeForEPos,Para_EjeRetEffArea))	//托进在有效区检查	20131112：引入有效区，避免误报警
U32 EjeDoTimeGetAtfDec(void);

void EjeRulOptChkPcs(void);							//托模电子尺配备检查及处理		20140813加

#endif

