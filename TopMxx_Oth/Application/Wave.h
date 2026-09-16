/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：Wave.h
文件说明：波形处理等。

作    者：BSH
编写时间：2020.3
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================



****************************************************************************************************/
#ifndef Wave_h
	#define Wave_h

#ifdef Wave_c
	#define Wave_ext
#else
	#define Wave_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/

//触发模式定义如下：
	#define mWTM_Off			0	//关闭
	#define mWTM_Con			1	//连续
	#define mWTM_Cyc			2	//循环
		#define mWTM_CycN			3	//循环N	也表示循环模式，通过值变化让界面知道一个新循环
	#define mWTM_MoldOpen		10	//开模
	#define mWTM_MoldCls		11	//关模
	#define mWTM_Inject			20	//注射
	#define mWTM_Charge			21	//储料
	#define mWTM_SuckBack		22	//射退
	#define mWTM_Eject			30	//托模
	#define mWTM_MoldAct		60	//模板动作		包括开、关模
		#define mWTM_MoldActOpn		61	//模板动作--开模
		#define mWTM_MoldActCls		62	//模板动作--关模
	#define mWTM_ScrewAct		70	//螺杆动作		包括注射、储料、射退
		#define mWTM_ScrewActInj	71	//螺杆动作--注射
		#define mWTM_ScrewActChg	72	//螺杆动作--储料
		#define mWTM_ScrewActSB		73	//螺杆动作--射退
	#define mWTM_EjectAct		80	//顶针动作		包括托进、托退
		#define mWTM_EjectActFor	81	//顶针动作--托进
		#define mWTM_EjectActRev	82	//顶针动作--托退
	#define mWTM_PosSnr			90	//电尺
	#define mWTM_IO				100	//IO
		
//取样间隔时间
	#define mWST_10ms			0	//10ms		一组数据，D0-D5、D6-D10……D26-D29
	#define mWST_20ms			1	//20ms		二组数据，D0-D14、D15-D29
	#define mWST_50ms			2	//50ms		五组数据，D0-D29

//波形X配置的D7-D4…数据类型，宏定义如下
	#define mWDT_Null			(0<<4)	//空
	#define mWDT_Resource		(1<<4)	//资源
	#define mWDT_WorkState		(2<<4)	//工作状态
	#define mWDT_MachPara		(3<<4)	//机器参数		正常不会使用
	#define mWDT_MaunPara		(4<<4)	//生产参数		正常不会使用
	#define mWDT_HardConf		(5<<4)	//硬件配置		正常不会使用
	#define mWDT_SpeData		(15<<4)	//特殊数据		由序号决定，如模板速度之类
//波形X配置的D3-D0…缩放比例，定义如下
              	
//波形X序号为16位数据，当数据配置mWDT_SpeData，其功能定义如下：
	#define mWSD_RealMoldPos	0	//实时模板位置
	#define mWSD_RealScrewPos	1	//实时螺杆位置
	#define mWSD_RealEjectPos	2	//实时顶针位置
	#define mWSD_RealNozPos		3	//实时座台位置
	#define mWSD_RealHAI1		4	//实时模拟量一
	#define mWSD_RealHAI2		5	//实时模拟量二
	#define mWSD_RealHAI3		6	//实时模拟量三
	#define mWSD_MoldSpeed		10	//模板速度
	#define mWSD_ScrewSpeed		11	//螺杆速度
	#define mWSD_EjectSpeed		12	//顶针速度
	#define mWSD_NozSpeed		13	//座台速度
	#define mWSD_SDRealPres		14	//驱动器实时压力			20210608加：适应多个蒙德驱动器波形显示
	#define mWSD_SDRealFlow		15	//驱动器实时流量			20210608加：适应多个蒙德驱动器波形显示
	#define mWSD_TDRealPres		16	//台达驱动器实时压力		
	#define mWSD_TDRealFlow		17	//台达驱动器实时流量		
	#define mWSD_ESRealPres		18	//艾普驱动器实时压力		
	#define mWSD_ESRealFlow		19	//艾普驱动器实时流量	
	#define mWSD_InjSrwPos_HPTime	20	//注射动作时为螺杆位置、保压时为时间	用于注射曲线画面，实现注射动作时用位置轴、保压动作时用时间轴，即X轴要随动作切换；由于时间轴实际中不需要，因此时间轴时波形数据固定为0xffff，以与位置轴区分
	
//波形参数数量
	#define mWaveParaNum  2048   //波形参数数量	20210917
	#define mWaveParaMask 0x7ff  //波形参数掩码	20210917

/*======================================== 全局有效变量定义 =======================================*/
//波形参数数组定义
Wave_ext U8  WaveNum;												//波形组数
Wave_ext U16 WaveParaBuff[mWaveParaNum];    //波形参数数组
Wave_ext U16 WaveParaStart,WaveParaEnd;     //波形参数起始结束位置

Wave_ext U8  WaveCurTrigMode;		//当前波形触发模式
Wave_ext U8  WaveCurTrigModeSave;	//当前波形触发模式保存
/*======================================== 全局有效函数声明 =======================================*/
void Wave_Init(void);					//初始化		
void Wave_Pcs(void);					//处理					于主循环


#endif

