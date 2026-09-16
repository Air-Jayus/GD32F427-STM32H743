/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：RPHA.h
文件说明：

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================
**名词定义、概述**
**与界面关系**

**使用方法**

**修改方法**

**注意事项**

默认单位：时间0.1s	位置0.1mm	压力1bar		流量1%	计数1clk		电流1mA		电压1mV		温度1c
****************************************************************************************************/
#ifndef RPHA_h
	#define RPHA_h

#ifdef RPHA_c
	#define RPHA_ext
#else
	#define RPHA_ext extern
#endif

/*========================================= 全局有效宏定义 ========================================*/



/*======================================== 全局有效变量定义 =======================================*/
typedef struct {
	Bool UpdateFlag;		//需要保存标志
	U16 StartSN;			//开始序号
	U16 Len;				//保存长度
} EP_Modify;	//EEPROM中参数有修改标志：如果有效，则参数写到EEPROM并重新读出		

#ifdef RPHA_c
	RPHA_ext EP_Modify MachParaSave={mFalse,0,0};	//机器参数修改	主要在修改加载或位置尺归零、长度修改时用	注：尽量避免RPHA.c、Comm_Drv.c以外文件中直接修改机器参数，多了可能冲突导致写入失败
	RPHA_ext EP_Modify HardConfSave={mFalse,0,0};	//硬件配置修改	主要在修改加载时用
	RPHA_ext EP_Modify PeriParaSave={mFalse,0,0};
#else
	RPHA_ext EP_Modify MachParaSave;
	RPHA_ext EP_Modify HardConfSave;	
	RPHA_ext EP_Modify PeriParaSave;
#endif	


typedef struct{	//
	U16 Pack;		//包装数
	U16 ShotBad;	//不良品数
	U32 Shot;		//开模计数
	U32 Lubr1;		//润滑1模数
	U32 Lubr2;		//润滑2模数
	U32 WorkShot;	//工作模数		主机累计工作模数
	U32 WorkTime;	//工作时数		主机累计工作时间	单位：S
	
	U16 LubrCnt_1W;	//润滑1万模计数	20121027加：用于实现区分润滑前后1W模
	U16 MoldAdjSnr;	//调模电眼计数	20260112加：调模电眼计数
	
	U32 ProdShot;		//生产模数（模号）	20250325加
	
	U16 SaveSn;		//保存序号
	U16 ChkSum;		//校验和
}CntDataStr;	//结构总长度须为4的倍数

RPHA_ext CntDataStr CntData;//计数数据：需要保存到EEPROM的计数数据


/*======================================== 全局有效函数声明 =======================================*/
void RPHA_Init(void);				//RPHA初始化
void RPHA_Pcs(void);				//RPHA处理		置于主循环

void CntDataSave(void);				//计数数据保存

U32 ReadLicense0(void);				//读取License 0
U32 ReadLicense1(void);				//读取License 1
Bool SaveLicense0(U32 License);		//保存License 0
Bool SaveLicense1(U32 License);		//保存License 1

#endif
