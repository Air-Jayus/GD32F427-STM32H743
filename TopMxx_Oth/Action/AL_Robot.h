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
#ifndef AL_Robot_h
	#define AL_Robot_h

#ifdef AL_Robot_c
	#define AL_Robot_ext
#else
	#define AL_Robot_ext extern
#endif



/*========================================= 全局有效宏定义 ========================================*/



//动作组、细分、函数ID-----------------------------------------------------------------------------//
//在ActConf.h统一定义
//段ID定义(必须按序定义、要用于大小比较)-----------------------------------------------------------//
//动作函数-----------------------------------------------------------------------------------------//
void ALCF_RobotWait(void *FP,FActAttrStr *FAAP,RobotWaitCondStr *RWCP,U8 WaitCondNum);	//等待机械手信号	公共函数
void AL_RobotCycStart(void *FP,FActAttrStr *FAAP);										//循环启动信号
	#define mASID_AL_RobotWait_Wait		10				//等待
	
void AL_RobotWaitTi(void *FP,FActAttrStr *FAAP);										//循环启动信号	20190320
	#define mASID_AL_RobotWaitTi_Wait	10				//等待	20190320	

void Robot_Pcs(void);							//机械手处理			本函数于主循环执行

Bool Get_EjetRet2End(void);						//顶针2退到位	20200629
Bool Get_R_RobotRetEnd(void);					//机械手回到位
Bool Get_R_RobotUse(void);						//机械手使用
Bool Get_R_EmerStop(void);						//R.机械手紧停
Bool Get_R_CycStart(void);						//R.循环启动
Bool Get_R_MoldAreaFree(void);					//R.模区安全
Bool Get_R_EnClamp(void);						//R.关模允许
Bool Get_R_EnMoldOpen(void);					//R.开模允许
Bool Get_R_EnEjeFor(void);						//R.托模进允许
Bool Get_R_EnEjeRet(void);						//R.托模退允许
Bool Get_R_EnCoreIn(void);						//R.中子进允许
Bool Get_R_EnCoreOut(void);						//R.中子退允许
Bool Get_R_EnFullMoldOpen(void);				//R.全开模允许检查

void AL_RobotWaitChk_MoldClsStart(void *FP,FActAttrStr *FAAP);	//机械手等待检查	关模前		由AL_MoldCls()调用
U8 RobotEnChk_MoldClsMid(void);									//机械手允许检查	关模中		由AL_MoldCls()调用
void RobotOutPcs_MoldCls(void *FP,FActAttrStr *FAAP);			//机械手输出处理	关模		由AU_MoldCls()、AU_MoldCls_AM()调用


void AL_RobotWaitChk_MoldOpenStart(void *FP,FActAttrStr *FAAP);	//机械手等待检查	开模前		由AL_MoldOpen()调用
U8 RobotEnChk_MoldOpenMid(void);								//机械手允许检查	开模中		由AL_MoldOpen()调用
void RobotOutPcs_MoldOpen(void *FP,FActAttrStr *FAAP);			//机械手输出处理	开模		由AU_MoldOpen()、AU_MoldOpen_AM()调用


void AL_RobotWaitChk_CoreInStart(void *FP,FActAttrStr *FAAP);	//机械手等待检查	中子进前	由AL_CoreIn()调用
U8 RobotEnChk_CoreInMid(void);									//机械手允许检查	中子进中	由AL_CoreIn()调用
void RobotOutPcs_CoreIn(void *FP,FActAttrStr *FAAP);			//机械手输出处理	中子进		由AU_CoreIn()调用

void AL_RobotWaitChk_CoreOutStart(void *FP,FActAttrStr *FAAP);	//机械手等待检查	中子进前	由AL_CoreOut()调用
U8 RobotEnChk_CoreOutMid(void);									//机械手允许检查	中子进中	由AL_CoreOut()调用
void RobotOutPcs_CoreOut(void *FP,FActAttrStr *FAAP);			//机械手输出处理	中子进		由AU_CoreOut()调用

void AL_RobotWaitChk_EjeRetStart(void *FP,FActAttrStr *FAAP);	//机械手等待检查	托退前		由AL_EjectRet()调用
U8 RobotEnChk_EjeRetMid(void);									//机械手允许检查	托退中		由AL_EjectRet()调用
void RobotOutPcs_EjeRet(void *FP,FActAttrStr *FAAP);			//机械手输出处理	托退		由AU_EjectRet()调用

void RobotPcs_EjeFor(void *FP,FActAttrStr *FAAP,Bool EFSec,Bool ERSec);	//机械手相关处理	托进		由AU_EjectFor()调用		完成信号检查、相应输出全部

#endif

