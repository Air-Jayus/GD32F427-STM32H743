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
#ifndef VEICHISD_Drv_h
	#define VEICHISD_Drv_h


#ifdef VEICHISD_Drv_c
	#define VEICHISD_Drv_ext
#else
	#define VEICHISD_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/



/*======================================== 全局有效变量定义 =======================================*/
//以下参数CANOpen驱动器共用
VEICHISD_Drv_ext U8 RestAlarmCnt,RestAlarmCode,SDAlamBuff;					//复位警报计数、复位警报代码、多个驱动器警报
VEICHISD_Drv_ext U8 EnableDisableStep,EnableDisableSDSN,EnableDisableCode;	//上下使能驱动器号，上下使能代码

VEICHISD_Drv_ext U16 SDWorkState_Buff[mState_SDRealRPM-mState_SDSn+1];//驱动器工作状态缓存		定义同 mState_SDSn 到 mState_SDRealRPM
VEICHISD_Drv_ext U16 SDMaxRpmCal;				//驱动器最大转速

VEICHISD_Drv_ext U16 CurrSDPres;	//蒙德当前伺服驱动器压力		主要用于波形显示	单位0.01mPa
VEICHISD_Drv_ext U16 CurrSDFlow;	//蒙德当前伺服驱动器流量		主要用于波形显示	单位0.01%

//SDO当前操作类型	高的可以打断低的操作
#define		mSdoOptNull				0
#define		mSdoOptParaRead			1
#define		mSdoOptParaWrite		2
#define		mSdoOptPidSend			3
#define		mSdoOptEnableDisable	4
#define		mSdoOptRestAlarm		5
VEICHISD_Drv_ext U8 			SDSDOOptSel;	//SDO当前操作类型
VEICHISD_Drv_ext U8 			SDSDOStep;		//SDO操作步骤
VEICHISD_Drv_ext G10usTimer 	SDRecDataTimer;	//接收正确数据定时器
VEICHISD_Drv_ext U32 			SDSdoRDat;				//SDO读取的参数

VEICHISD_Drv_ext U8 SDMainActBuff;		//伟创主动作PID选择            
VEICHISD_Drv_ext U8 SDMainActBuffLast;	//伟创主动作PID选择上次保存值  
VEICHISD_Drv_ext U8 SDLinkActBuff;		//伟创联动动作PID选择          
VEICHISD_Drv_ext U8 SDLinkActBuffLast;	//伟创联动动作PID选择上次保存值
VEICHISD_Drv_ext U8	SDInjtFlowClosLoop;//伟创主动作注射动作流量闭环选择 

VEICHISD_Drv_ext U8 WorkState_MonCnt;	//驱动器工作状态计数

/*======================================== 全局有效函数声明 =======================================*/
void VeiSD_Drv_Init(void);			//CAN 模块初始化
void VeiSD_Drv_Pcs(void);			//CAN 模块处理
U16 VeiSD_GetCurrSDRealPres(void);	//当前驱动器反馈压力
U16 VeiSD_GetCurrSDRealFlow(void);	//当前驱动器反馈流量

#endif
