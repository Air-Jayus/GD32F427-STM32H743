/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：Code.h
文件说明：本文件CM和WM共用，共同定义通迅相关指令。

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
#ifndef Code_h
	#define Code_h

#ifdef Code_c
	#define Code_ext
#else
	#define Code_ext extern
#endif

/*======================================== 全局有效函数声明 =======================================*/
#ifdef mProg_CM		//主机程序用到函数
	void Code_Pcs(void);		//指令处理		于主循环

	Bool IsAnyKeyPush(void);	//任意键按下		包括：方式键、动作键
	Bool IsModeKeyPush(void);	//模式键按下		包括：手动、半自动、时间自动、电眼自动、调模方式
	Bool IsActKeyPush(void);	//动作键按下		包括：开模、关模、马达、电热……等动作键
	Bool IsManuKeyPush(void);	//手动键按下		专指：手动键
#endif
/*======================================== 全局有效变量定义 =======================================*/

/*========================================= 全局有效宏定义 ========================================*/
//调试和校零指令
#define CC_BootOperate	0x19//Boot操作
	#define mBO_Startup_0		0xA6	//启动Boot参数0
	#define mBO_Startup_1		0x55	//启动Boot参数1
	#define mBO_Return_0		0xA6	//退出Boot参数0
	#define mBO_Return_1		0x66	//退出Boot参数11
#define CC_AppOperate	0x1a//App操作
	#define mAO_Erase_0			0xB7	//擦除
	#define mAO_Erase_1			0x77
	#define mAO_Program_0		0xB7	//编程下载
	#define mAO_Program_1		0x88
	#define mAO_ReadHead_0		0xC8	//读取头
	#define mAO_ReadHead_1		0x99
	#define mAO_ReadProg_0		0xC8	//读取程序
	#define mAO_ReadProg_1		0x99
#define CC_Debug_Set	0x20//调试设置 格式：CC_Debug_Set DBT DBP----DBT为类型、DBP为IO序号或DA值
	#define mDBT_DO				0	//强制输出
	#define mDBT_DI				1	//强制输入
	#define mDBT_DA_DAChan1		2	//DA通道1
	#define mDBT_DA_DAChan2		3	//DA通道2
	#define mDBT_DA_DAChan3		4	//DA通道3
	#define mDBT_DA_DAChan4		5	//DA通道4
	#define mDBT_DA_DAChan5		6	//DA通道5
	#define mDBT_DA_DAChan6		7	//DA通道6
	#define mDBT_DA_DAChan7		8	//DA通道7
	#define mDBT_DA_DAChan8		9	//DA通道8
	#define mDBT_DO_CM1			10	//CAN模块强制输出
	#define mDBT_DO_CM2			11	//CAN模块强制输出
	#define mDBT_DO_CM3			12	//CAN模块强制输出
	#define mDBT_DO_CM4			13	//CAN模块强制输出
	#define mDBT_DO_CM5			14	//CAN模块强制输出
	#define mDBT_DO_CM6			15	//CAN模块强制输出
	#define mDBT_DO_CM7			16	//CAN模块强制输出
	#define mDBT_DO_CM8			17	//CAN模块强制输出	
	#define mDBT_DA_DAChan1_Neg	18	//DA通道1	负压		保留，硬件不支持	20120822加
	#define mDBT_DA_DAChan2_Neg	19	//DA通道2	负压		保留，硬件不支持
	#define mDBT_DA_DAChan3_Neg	20	//DA通道3	负压		保留，硬件不支持
	#define mDBT_DA_DAChan4_Neg	21	//DA通道4	负压		保留，硬件不支持
	#define mDBT_DA_DAChan5_Neg	22	//DA通道5	负压		保留，硬件不支持
	#define mDBT_DA_DAChan6_Neg	23	//DA通道6	负压		保留，硬件不支持
	#define mDBT_DA_DAChan7_Neg	24	//DA通道7	负压
	#define mDBT_DA_DAChan8_Neg	25	//DA通道8	负压
	#define mDBT_SysPresFlow	31  	//系统压力流量强制输出  20200103应用J6H强制输出
#define CC_Debug_Mode	0x21//调试模式 格式: CC_Debug_Mode DBM   ----DBM为IO调试模式	0-退出 1-普通 2-高级
	#define mDBM_Exit		0	//结束
	#define mDBM_Nor		1	//普通
	#define mDBM_Sup		2	//高级
#define CC_SnrSetZero	0x24//归零		 格式：CC_SnrSetZero Chan ----Chan为尺序号，0-射出尺 1-动模尺 2-顶针尺
							//												     	3-座台尺 4-模拟量1 
	#define mScrewSnrSetZero		0	//螺杆尺归零
	#define mMoldSnrSetZero			1	//模板尺归零
	#define mEjeSnrSetZero			2	//顶针尺归零
	#define	mNozSnrSetZero			3	//座台尺归零
	#define mHAI1SetZero			4	//模拟量1归零
	#define mHAI2SetZero			5	//模拟量2归零
	#define mHAI3SetZero			6	//模拟量3归零	
	#define mMoldThickSnrSetZero	7	//模厚尺归零
#define CC_CntClr		0x25//计数清0	格式：CC_CntClr   Cntn	  ----Cntn为序号，0-开模数 1-装模数 2-不良品数
	#define mShotCntClr			0	//开模数清零
	#define mPackCntClr			1	//包装数清零
	#define mShotBadCntClr		2	//不良品数清零 
	#define mWorkCnt			3	//工作计数清零		包括累计开模数和工作时数
	#define mHtrTtlTime			4	//电热输出时间
	#define mLubr1CntSet		5	//润滑1计数设置		20121026加：设置离下次润滑模数	注意特殊，不是简单的清零，后面需再加4字节参数，0xffffffff即已经润滑模数清0，同时润滑1万模计数也会一并清0
	#define mLubr2CntSet		6	//润滑2计数设置		20121026加：设置离下次润滑模数	注意特殊，不是简单的清零，后面需再加4字节参数，0xffffffff即已经润滑模数清0，同时润滑1万模计数也会一并清0
#define CC_ParaRst		0x26//参数重置	格式：CC_ParaRst  RstType ----RstType为重置类型
	#define mHardConfRst		0	//硬件配置重置
	#define mMachParaRst		1	//机器参数重置
	#define mDA1ParaRst			2	//比例阀1曲线参数重置	压力阀
	#define mDA2ParaRst			3	//比例阀2曲线参数重置	流量阀
	#define mDA3ParaRst			4	//比例阀3曲线参数重置	背压阀
	#define mDA4ParaRst			5	//比例阀4曲线参数重置	
	#define mRulParaRst			20	//电子尺数据重置	(暂不用)
	#define mPlastMachTypeRst	30	//注塑机型号重置	20081012增
#define CC_SnrSetLen	0x27//长度设置	格式：CC_SnrSetLen Chan Len1 Len2 Len3 Len4
	#define mScrewSnrSetLen		0	//螺杆尺校长度
	#define mMoldSnrSetLen		1	//模板尺校长度
	#define mEjeSnrSetLen		2	//顶针尺校长度
	#define	mNozSnrSetLen		3	//座台尺校长度
	#define mHAI1SetLen			4	//模拟量1校长度
	#define mHAI2SetLen			5	//模拟量2校长度
	#define mHAI3SetLen			6	//模拟量3校长度	
	#define mMoldThickSnrSetLen	7	//模厚尺长度
	#define mScrewSnrSetLen_CP		128	//螺杆尺校长度		通过设置当前长度来校准尺长度
	#define mMoldSnrSetLen_CP		129	//模板尺校长度		通过设置当前长度来校准尺长度
	#define mEjeSnrSetLen_CP		130	//顶针尺校长度		通过设置当前长度来校准尺长度
	#define	mNozSnrSetLen_CP		131	//座台尺校长度		通过设置当前长度来校准尺长度
	#define mHAI1SetLen_CP			132	//模拟量1校长度		通过设置当前长度来校准尺长度
	#define mHAI2SetLen_CP			133	//模拟量2校长度		通过设置当前长度来校准尺长度
	#define mHAI3SetLen_CP			134	//模拟量3校长度		通过设置当前长度来校准尺长度
	#define mMoldThickSnrSetLen_CP	135	//模厚尺长度			通过设置当前长度来校准尺长度
#define CC_SetBatchSN	0x28//批号序号设置	格式：CC_SetBatchSN BatchH BatchL SNH SNL
#define CC_MonAlarmOpt	0x29//监测警报操作	格式：CC_MonAlarmSel Sel
	#define mMAS_Off			0	//关闭
	#define mMAS_Sample			1	//开启、重新取样

//20210608：增加以下三条蒙德驱动器相关指令
#define CC_MDDrv_RdyData		0x2A	//准备n（0-3）驱动器的第x地址数据：主机启动向驱动器读取第X地址数据
										//格式：CC_MDDrv_RdyData   SDSN  HAddr  Ladd  Len
										//注：通过工作状态State_SDRdData_Info、State_SDRdData_Addr、State_SDRdData_DataL、State_SDRdData_DataH返回，即界面发该指令后，然后延时回读工作状态得到。

#define CC_MDDrv_MdyData		0x2B	//修改n（0-3）驱动器的第x地址数据：
										//格式：CC_MDDrv_MdyData  SDSN  HAddr  Ladd  Len  Data1-Data4
#define CC_MDDrv_SetCurrSDSN	0x2C	//设置当前驱动器：
										//格式：CC_MDDrv_SetCurrSDSN  SDSN

#define CC_MachParaUnInitRst 0x30	//主机参数未初始化标志复位
#define CC_WaveSet		0x31//示波器设置	格式：CC_WaveSet TrigMode SampTime Resever WaveAConf WaveASN WaveBConf WaveBSN WaveCConf WaveCSN WaveDConf WaveDSN WaveEConf WaveESN
	//#define 						//在Wave.h中定义
		
#define CC_ServoDrvSet	0x32//伺服驱动器设置	格式：CC_ServoDrvSet SetFun Mode ParaH ParaL
	#define mSDS_MotTune		1	//电机参数调谐	Mode=1静态调谐	Mode=2动态调谐
	#define mSDS_Stop			5	//停机		Mode=1自由停机	Mode=2减速停机	SDSN=0xff则所有驱动器有效
	#define mSDS_Run			6	//运行		Mode=1正转运行	Mode=2正转点动	Mode=3反转运行 Mode=4点动反转	SDSN=0xff则所有驱动器有效	
	#define mSDS_AISetZero		10	//模拟量校零
	#define mSDS_ParaSyn		20	//参数同步	Mode=0，所有参数下载到驱动器(更新驱动器)					此项暂不支持
									//			Mode=1，所有参数从驱动器读取(更新主机)
									//			Mode=2，ParaH ParaL为参数序号，该序号参数更新到驱动器
									//			Mode=3，ParaH ParaL为参数序号，该序号参数从驱动器读取
#define CC_LicenseSet	0x33//License设置	格式：CC_LicenseSet Level License1 License2 License3 License4
	#define mLS_License0		0	//设置License 0
	#define mLS_License1		1	//设置License 1
#define CC_MoldAdjLubr	0x34//调模润滑	格式：CC_MoldAdjLubr mMAL_LubrFin/mMAL_LubrStart		20150327加
	#define mMAL_LubrFin		0	//结束
	#define mMAL_LubrStart		1	//开始
#define CC_SetDateTime  0x35//设置日期、时间 格式：CC_SetDateTime YY MM DD HH MM SS				20150327加

#define CC_MOParaAutoGenl	0x36//开模参数自学习	20171214
	#define mMOPAG_Start	1	//开模参数自学习开始
	#define mMOPAG_Finish	0	//开模参数自学习结束
	#define mMOPAG_PraGenAss	10	//智能辅助开模时，初始参数产生
	
#define CC_MOLineGenl	0x37//开模参数线性生成		20171214
//#define CC_ReadManuPara 0x38	//读取生产参数	在Comm_Drv.c中定义
#define CC_ProdTaskFin	0x39	//生产任务完成	20170705
#define CC_DryCycCont	0x3A	//干周期功能开关指令	CC_DryCycCont OnOff   ----OnOff为开关控制	0-Off 1-On		20200713

//动作指令
//#define mPictCode	0x00	//画面切换键
//#define mNumCode	0x10	//数字键(0-9)
//#define mEditCode	0x20	//编辑键(方向键、确认、取消键、＊、.)
#define mModeCode	0x60	//模式切换指令
#define mActCode	0x70	//动作指令
#define mActCodeA	0x70	//动作指令A		对应停止指令0xa0
#define mActCodeB	0x80	//动作指令B		对应停止指令0xb0
#define mActCodeC	0x90	//动作指令C		对应停止指令0xc0

#define mActStopCode 0x30	//动作停止代码与动作代码相差的值

#define	mMACode_Start		0x60		//模式、动作指令		起始代码
#define mMACode_End			0x9f		//模式、动作指令		结束代码

#define mActCode_Start		0x70		//动作指令按下		起始代码
#define mActCode_End		0x9f		//动作指令按下		结束代码

#define mActCodePop_Start	(0x70+0x30)	//动作指令放开		起始代码
#define mActCodePop_End		(0x9f+0x30)	//动作指令放开		结束代码


//方式切换指令
#define mCode_Manual		mModeCode+0	//手动方式
#define mCode_SemiAuto		mModeCode+1	//半自动方式
#define mCode_SenrAuto		mModeCode+2	//电眼自动方式
#define mCode_TimeAuto		mModeCode+3	//时间自动方式
#define mCode_MoldAdj		mModeCode+4	//调模方式

//动作指令
#define mCode_MoldOpen		mActCode+0	//开模
#define mCode_MoldColse		mActCode+1	//关模
#define mCode_Inject  		mActCode+2 	//射出
#define mCode_SuckBack		mActCode+3 	//射退
#define mCode_EjectRet		mActCode+4 	//脱退
#define mCode_EjectAdv		mActCode+5 	//脱进
#define mCode_NozzleAdv		mActCode+6 	//座进
#define mCode_NozzleBack	mActCode+7 	//座退
#define mCode_Charge		mActCode+8 	//储料
#define mCode_AutoPurge		mActCode+9 	//自动清料
#define mCode_Air1			mActCode+10	//吹气1
#define mCode_Air2			mActCode+11	//吹气2
#define mCode_Air3			mActCode+12	//吹气3
#define mCode_Air4			mActCode+13	//吹气4
#define mCode_Air5			mActCode+14	//吹气5
#define mCode_Air6			mActCode+15	//吹气6
#define mCode_Air7			mActCode+16	//吹气7
#define mCode_Air8			mActCode+17	//吹气8
#define mCode_CoreAIn		mActCode+18	//中子A进
#define mCode_CoreAOut		mActCode+19	//中子A退
#define mCode_CoreBIn		mActCode+20	//中子B进
#define mCode_CoreBOut		mActCode+21	//中子B退
#define mCode_CoreCIn		mActCode+22	//中子C进
#define mCode_CoreCOut		mActCode+23	//中子C退
#define mCode_CoreDIn		mActCode+24	//中子D进
#define mCode_CoreDOut		mActCode+25	//中子D退
#define mCode_CoreEIn		mActCode+26	//中子E进
#define mCode_CoreEOut		mActCode+27	//中子E退
#define mCode_CoreFIn		mActCode+28	//中子F进
#define mCode_CoreFOut		mActCode+29	//中子F退
#define mCode_CoreGIn		mActCode+30	//中子G进
#define mCode_CoreGOut		mActCode+31	//中子G退
#define mCode_CoreHIn		mActCode+32	//中子H进
#define mCode_CoreHOut		mActCode+33	//中子H退
#define mCode_MoldThick		mActCode+34	//调模退
#define mCode_MoldThin		mActCode+35	//调模进
#define mCode_Lubr			mActCode+36	//润滑
#define mCode_MotorOn		mActCode+37	//马达开
#define mCode_MotorOff		mActCode+38	//马达关
#define mCode_HeaterOn		mActCode+39	//电热开
#define mCode_HeaterOff		mActCode+40	//电热关
#define mCode_HalfHeat		mActCode+41	//半温加热
#define mCode_DoorOpen		mActCode+42	//安全门开
#define mCode_DoorClose		mActCode+43	//安全门关
#define mCode_OilHtr		mActCode+44	//油温加热	特殊：暂无对应按键，为了油温加热时允许开关马达和电热而增设
#define mCode_AutoMoldAdj	mActCode+45	//自动调模	特殊：暂无对应按键

#define mCode_MoldOpenStop		mCode_MoldOpen		+mActStopCode//开模
#define mCode_MoldCloseStop		mCode_MoldColse		+mActStopCode//关模
#define mCode_InjectStop  		mCode_Inject  		+mActStopCode//射出
#define mCode_SuckBackStop		mCode_SuckBack		+mActStopCode//射退
#define mCode_EjectRetStop		mCode_EjectRet		+mActStopCode//脱退
#define mCode_EjectAdvStop		mCode_EjectBack		+mActStopCode//脱进
#define mCode_NozzleAdvStop		mCode_NozzleAdv		+mActStopCode//座进
#define mCode_NozzleRetStop		mCode_NozzleBack	+mActStopCode//座退
#define mCode_ChargeStop		mCode_Charge		+mActStopCode//储料
#define mCode_AutoPurgeStop		mCode_AutoPurge		+mActStopCode//自动清料
#define mCode_Air1Stop			mCode_Air1			+mActStopCode//吹气1
#define mCode_Air2Stop			mCode_Air2			+mActStopCode//吹气2
#define mCode_Air3Stop			mCode_Air3			+mActStopCode//吹气3
#define mCode_Air4Stop			mCode_Air4			+mActStopCode//吹气4
#define mCode_Air5Stop			mCode_Air5			+mActStopCode//吹气5
#define mCode_Air6Stop			mCode_Air6			+mActStopCode//吹气6
#define mCode_Air7Stop			mCode_Air7			+mActStopCode//吹气7
#define mCode_Air8Stop			mCode_Air8			+mActStopCode//吹气8
#define mCode_CoreAInStop		mCode_CoreAIn		+mActStopCode//中子A进
#define mCode_CoreAOutStop		mCode_CoreAOut		+mActStopCode//中子A退
#define mCode_CoreBInStop		mCode_CoreBIn		+mActStopCode//中子B进
#define mCode_CoreBOutStop		mCode_CoreBOut		+mActStopCode//中子B退
#define mCode_CoreCInStop		mCode_CoreCIn		+mActStopCode//中子C进
#define mCode_CoreCOutStop		mCode_CoreCOut		+mActStopCode//中子C退
#define mCode_CoreDInStop		mCode_CoreDIn		+mActStopCode//中子D进
#define mCode_CoreDOutStop		mCode_CoreDOut		+mActStopCode//中子D退
#define mCode_CoreEInStop		mCode_CoreEIn		+mActStopCode//中子E进
#define mCode_CoreEOutStop		mCode_CoreEOut		+mActStopCode//中子E退
#define mCode_CoreFInStop		mCode_CoreFIn		+mActStopCode//中子F进
#define mCode_CoreFOutStop		mCode_CoreFOut		+mActStopCode//中子F退
#define mCode_CoreGInStop		mCode_CoreGIn		+mActStopCode//中子G进
#define mCode_CoreGOutStop		mCode_CoreGOut		+mActStopCode//中子G退
#define mCode_CoreHInStop		mCode_CoreHIn		+mActStopCode//中子H进
#define mCode_CoreHOutStop		mCode_CoreHOut		+mActStopCode//中子H退
#define mCode_MoldThickStop		mCode_MoldThick		+mActStopCode//调模退
#define mCode_MoldThinStop		mCode_MoldThin		+mActStopCode//调模进
#define mCode_LubrStop			mCode_Lubr			+mActStopCode//润滑
#define mCode_MotorOnStop 		mCode_MotorOn		+mActStopCode//马达开
#define mCode_MotorOffStop 		mCode_MotorOff		+mActStopCode//马达关
#define mCode_HeaterOnStop		mCode_HeaterOn		+mActStopCode//电热开
#define mCode_HeaterOffStop		mCode_HeaterOff		+mActStopCode//电热关
#define mCode_HalfHeatStop		mCode_HalfHeat		+mActStopCode//半温加热  
#define mCode_DoorOpenStop		mCode_DoorOpen		+mActStopCode//安全门开
#define mCode_DoorCloseStop		mCode_DoorClose		+mActStopCode//安全门关
#define mCode_OilHtrStop		mCode_OilHtr		+mActStopCode//油温加热	特殊：暂无对应按键
#define mCode_AutoMoldAdjStop	mCode_AutoMoldAdj	+mActStopCode//自动调模	特殊：暂无对应按键


//指令、动作对应关系转换				
//在Action.c中定义了ManuModeCodeActTab[mActCodeMaxNum]、MoldAdjModeCodeActTab[mActCodeMaxNum]两个数组，反应指令对应的动作
#define mActCodeMaxNum			48					//动作指令最大数		Action.c中利用此宏定义数组长度		实际使用31，如果超出40则要修改本宏，
#define CodeToActSN(c)			(c-mActCode)		//指令对应动作序号	Action.c中利用此宏获取数组中的序号


#endif

