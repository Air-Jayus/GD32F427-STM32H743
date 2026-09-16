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
#ifndef Alarm_h
	#define Alarm_h


#ifdef Alarm_c
	#define Alarm_ext
#else
	#define Alarm_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/

/*======================================== 全局有效变量定义 =======================================*/


/*======================================== 全局有效函数声明 =======================================*/
void Alarm_Pcs(void);				//警报处理						于主循环

void AlarmCodeClrPcs(void);			//指令清除警报处理				Code.c中调用
Bool AlarmDisCodeChk(U16 Code);		//指令是否受限制检查			Code.c中调用


void SetBackAlarm(U16 AlarmSN);		//设置背景警报					
void SetBackAlarm_NoLgt(U16 AlarmSN);	//设置背景警报				20150322加，不闪警灯

void SetAlarm_Attr_DisCode(U16 AlarmSN,U16 Attr,U16 DisCode);		//设置警报
	#define mDAC_Null		0xffff		//动作不限制
	#define	mAA_Def			0xffff		//默认属性
	#define mAA_MonAlarmDefAttr	mAA_ACAlarm+mAA_Light+mAA_Save+mAA_Beep		//监测提示用默认属性

#define SetAlarm(SN)	SetAlarm_Attr_DisCode(SN,mAA_Def,mDAC_Null)	//设置警报	采用默认属性、无动作限制


void ClrAlarm(U16 AlarmSN);				//清除警报、提示
	#define mCA_All		0xffff				//清除所有警报、提示
#define ClrAllAlarm 	ClrAlarm(mCA_All)	//清除所有警报、提示

void ClrAlarmTab(U16 * AlamSNTab);		//清除列表中包含的警报、提示		遇0则结束列表

U16 GetAlarmSN(void);					//获取当前警报代码					20150422加

#endif
