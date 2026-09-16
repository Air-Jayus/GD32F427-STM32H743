/* Copyright (C) 2018 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：TopMxx型注塑机控制器
项目简介：

======================================== 文   件    信   息 ========================================
文件名称：Time_Drv.h
文件说明：定时器驱动文件

作    者：WLZ
编写时间：2025.01
======================================== 修   改    历   史 ========================================
版 本 号：
修 改 人：
修改日期：
修改说明：

版 本 号：
修 改 人：
修改日期：
修改说明：

版 本 号：
修 改 人：
修改日期：
修改说明：

======================================== 其   它    说   明 ========================================


****************************************************************************************************/
#ifndef Time_Drv_h
	#define Time_Drv_h

#ifdef Time_Drv_c
	#define Time_Drv_ext
#else
	#define Time_Drv_ext extern
#endif

/*========================================= 全局有效宏定义 ========================================*/
#define SysTime			TIMER_CNT(TIMER1)	     //系统时间		实际直接使用Tim2中的值，计时单位10us
#define GetSysTime()	SysTime		   //读取系统时间

#define mTimer2Clk			100000		 //Tim2的时钟频率	100kHz	10us
#define mTimer2Max			0					 //Tim2计数最大值	实际上是0x100000000，但溢出变0

#define Get10nSTime()		TIMER_CNT(TIMER4)	 //TIM5设置到100MHz计数，计时单位10ns

#define mTime1ms_Period		(mTimer2Clk/1000*  1)	//  1ms定时周期
#define mTime2ms_Period		(mTimer2Clk/1000*  2)	//  2ms定时周期
#define mTime2_5ms_Period	(mTimer2Clk/1000*5/2)	//2.5ms定时周期
#define mTime5ms_Period		(mTimer2Clk/1000*  5)	//  5ms定时周期
#define mTime10ms_Period	(mTimer2Clk/1000* 10)	// 10ms定时周期
#define mTime15ms_Period	(mTimer2Clk/1000* 15)	// 15ms定时周期
#define mTime20ms_Period	(mTimer2Clk/1000* 20)	// 20ms定时周期
#define mTime80ms_Period	(mTimer2Clk/1000* 80)	// 80ms定时周期
#define mTime160ms_Period	(mTimer2Clk/1000*160)	//160ms定时周期
#define mTime625ms_Period	(mTimer2Clk/1000*625)	//625ms定时周期
#define mTime1500ms_Period	(mTimer2Clk/1000*1500)	// 1.5s定时周期

#define T1msTo10us(t)		((t)*1*100)					//时间单位转换	1ms		转10us
#define T10msTo10us(t)	((t)*10*100)				//时间单位转换	10ms	转10us
#define T100msTo10us(t)	((t)*100*100)				//				100ms	转10us
#define T1sTo10us(t)		((t)*1000*100)			//				1s		转10us

#define T10usTo1ms(t)		((t)/(1*100))  			//时间单位转换	10us	转1ms
#define T10usTo10ms(t)	((t)/(10*100))  		//时间单位转换	10us	转10ms
#define T10usTo100ms(t)	((t)/(100*100))			//				10us	转100ms
#define T10usTo1s(t)		((t)/(1000*100))		//				10us	转1s

#define T1msTo10ns(t)		((t)*1000*100)			//时间单位转换	1ms		转10ns
#define T10msTo10ns(t)	((t)*10*1000*100)		//时间单位转换	10ms	转10ns
#define T100msTo10ns(t)	((t)*100*1000*100)	//				100ms	转10ns
#define T1sTo10ns(t)		((t)*1000*1000*100)	//				1s		转10ns  

#define GTimer_Copy(t1,t2)	(t2.StartTime=t1.StartTime)	//时钟复制		
/*======================================== 全局有效变量定义 =======================================*/
typedef struct		//定义超级定时器类型	只能通过指定函数操作，并且要注意操作顺序：复位－暂停－重启
{
	Bool PauseFlag;		//计时暂停标志
	U32 StartTime;		//开始时间	以系统时间为参考
	U32	TotalTime;		//累计时间	单位10us
} S10msTimer;			
typedef struct		//定义超级定时器类型	只能通过指定函数操作，并且要注意操作顺序：复位－暂停－重启
{
	Bool PauseFlag;		//计时暂停标志
	U32 StartTime;		//开始时间	以系统时间为参考
	U32	TotalTime;		//累计时间	单位10us
} S100msTimer;	
		
typedef struct		//定义普通定时器类型	只能通过指定函数操作
{
	U32	StartTime;		//开始时间	以系统时间为参考
} G10nsTimer;
#define ec_timet G10nsTimer		//EtherCAT用定时器结构

typedef struct		//定义普通定时器类型	只能通过指定函数操作
{
	U32	StartTime;		//开始时间	以系统时间为参考
} G10usTimer;
typedef struct		//定义普通定时器类型	只能通过指定函数操作
{
	U32	StartTime;		//开始时间	以系统时间为参考
} G10msTimer;
typedef struct		//定义普通定时器类型	只能通过指定函数操作
{
	U32	StartTime;		//开始时间	以系统时间为参考
} G100msTimer;


/*======================================== 全局有效函数声明 =======================================*/
void Time_Drv_Init(void);					//时间驱动初始化

void G10nsTimerRes(G10nsTimer *);			//普通10ns定时器		复位
U32 G10nsTimerCal(G10nsTimer *);			//					计算时间
Bool G10nsTimerOver(G10nsTimer *,U32 );		//					超过比较
Bool G10nsTimerLess(G10nsTimer *,U32 );		//					未到比较
void Dly1us(U32 DlyTi);
void GetCurrentTime(G10nsTimer *Timer);

//void G5nsTimerRes(G5nsTimer *);			//普通10ns定时器		复位			实际为10.4ns
//U32 G5nsTimerCal(G5nsTimer *);			//					计算时间

void G10usTimerRes(G10usTimer *);			//普通10us定时器		复位
U32 G10usTimerCal(G10usTimer *);			//					计算时间
Bool G10usTimerOver(G10usTimer *,U32 );		//					超过比较
Bool G10usTimerLess(G10usTimer *,U32 );		//					未到比较

void G10msTimerRes(G10msTimer *);			//普通10ms定时器		复位
U32 G10msTimerCal(G10msTimer *);			//					计算时间
Bool G10msTimerOver(G10msTimer *,U32 );		//					超过比较
Bool G10msTimerLess(G10msTimer *,U32 );		//					未到比较

void G100msTimerRes(G100msTimer *);			//普通100ms定时器	复位
U32 G100msTimerCal(G100msTimer *);			//					计算时间
Bool G100msTimerOver(G100msTimer *,U32 );	//					超过比较
Bool G100msTimerLess(G100msTimer *,U32 );	//					未到比较

void S10msTimerRes(S10msTimer *);			//超级10ms定时器		复位
void S10msTimerResume(S10msTimer *);		//					继续计时
void S10msTimerPause(S10msTimer *);			//					暂停计时
U32 S10msTimerCal(S10msTimer *);			//					计算时间
Bool S10msTimerOver(S10msTimer *,U32 );		//					超过比较
Bool S10msTimerLess(S10msTimer *,U32 );		//					未到比较

void S100msTimerRes(S100msTimer *);			//超级100ms定时器	复位
void S100msTimerResume(S100msTimer *);		//					继续计时
void S100msTimerPause(S100msTimer *);		//					暂停计时
U32 S100msTimerCal(S100msTimer *);			//					计算时间
Bool S100msTimerOver(S100msTimer *,U32 );	//					超过比较
Bool S100msTimerLess(S100msTimer *,U32 );	//					未到比较

void Dly1ms(U32 DlyTi);						//延时n*1ms
void Dly10us(U32);							//延时n*10us
U32 RunTimeMeas_10us(Bool MeasStartFlag);	//测量运行时间		单位10us	
void clock_output_config(void);

#endif

