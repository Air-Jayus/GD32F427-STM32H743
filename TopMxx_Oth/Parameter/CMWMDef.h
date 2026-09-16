/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：CMWMDef.h
文件说明：定义主机、界面共用的宏定义。

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================

*****************************************************************************************************


****************************************************************************************************/
#ifndef CMWMDef_h
	#define CMWMDef_h


/*========================================= 全局有效宏定义 ========================================*/
//工作方式定义	SysState.CurrMode、State_SysMode
#define	mMode_Manu			0	//手动
#define	mMode_SemiAuto		1	//半自动
#define mMode_SenrAuto		2	//电眼自动
#define mMode_TimeAuto		3	//时间自动
#define	mMode_ManuMoldAdj	4	//手动调模模式
#define	mMode_AutoMoldAdj	5	//自动调模模式
#define mMode_Test			6	//调试模式
#define	mMode_SysStop		7	//紧急停止模式
#define mMode_Boot			8	//Boot模式						与Boot_IAP相关，注意同步修改

//马达状态		State_MotorState
#define mMS_Off				0	//关
#define mMS_On				1	//开
#define mMS_JustOn			2	//正在开
#define mMS_JustOff			3	//正在关
	
//电热状态		State_HtrState
#define	mHS_Off				0	//关
#define mHS_On				1	//开
#define mHS_KeepWarm		2	//保温

//警报状态		State_AlarmState
#define mAS_Off				0	//关
#define mAS_On				1	//开

//温度状态		State_Z1_4TempState、State_Z5_8TempState、State_Zone9_12TempState、State_Zone13_16TempState
#define mTS_Off			0	//关闭	通道关闭或加热关闭			3		料筒、油温、马达
#define mTS_FullHeat	1	//快升								2		料筒
#define mTS_FullCool	2	//快降								2		料筒
#define mTS_PIDHeat		3	//控温								2		料筒
#define mTS_ManuHeat	4	//手动	固定比例控温					2		料筒
#define mTS_HtrFail		5	//失败	全加热时3分种的温升不够		2		料筒
#define mTS_PwrOff		6	//断电								1		料筒、油温、马达
#define mTS_TherBrk		7	//断偶								1		料筒、油温、马达
#define mTS_OverRange	8	//超温	料管温度超过量程				1		料筒、油温、马达
#define mTS_Normal		9	//正常								   		料筒、油温、马达
#define mTS_OverUpLim	10	//过高								     	      油温、马达
#define mTS_OverLowLim	11	//过低									 	      油温
//#define mTS_NegTemp	12	//负温										料筒、油温、马达

//温度状态显示	State_Zone1_8TempStaDisp、State_Zone9_16TempStaDisp、State_OilMotTempStaDisp
#define mTSD_Off		0	//关闭	
#define mTSD_Normal		1	//正常	在料管偏差报警温度范围内		蓝色
#define	mTSD_Over		2	//偏差	在料管偏差报警温度范围外		黄色
#define	mTSD_Fail		3	//异常	断电、断偶、超温或加热失败	红色

//超差处理	Para_xxxxOLP
#define mOLP_Ignore	0	//忽略
#define mOLP_Prompt	1	//提示
#define mOLP_Alarm	2	//警报	停机转手动

//托模方式	Para_EjeecMode
#define	mEjeMode_Null	0	//不用
#define mEjeMode_Hold	1	//停留
#define mEjeMode_Cnt	2	//定次
#define mEjeMode_Vib	3	//震动

//保压切换方式	Para_HoldPresSwtMode
#define mHPSM_PosTi		0	//位置	即位置＋时间
#define mHPSM_Ti		1	//时间
#define mHPSM_Pres		2	//压力

//射退时机		Para_SuckBackOc
#define mSBO_AftChg		0	//储后
#define mSBO_AftCool	1	//冷后	即产品冷却后

//射退模式		Para_SuckBackCtrlMode、Para_SBBefChgCtrlMode
#define mSBCM_Pos		0	//位置
#define mSBCM_Ti		1	//时间

//再次储料模式	Para_ReChgCtrlMode
#define mRCCM_Pos		0	//位置
#define mRCCM_Ti		1	//时间

//座台退模式	Para_NozRetMode
#define mNRM_NoBack		0	//不退
#define mNRM_AftChg		1	//储后
#define	mNRM_BefMO		2	//开模前
#define mNRM_AftInj		3	//射后

//马达启动模式	Para_MotorOnMode
#define mMOM_YA			0	//星-三角启动
#define mMOM_Dir		1	//直接启动
#define	mMOM_DirHold	2	//直接启动且MotorOn继电器保持

//自动模式关模时安全门开处理	Para_AMMoldClsSGOpenPcs
#define	mAMMCSGOP_Stop			0	//停止
#define	mAMMCSGOP_InsMoldOpen	1	//开模
#define mAMMCSGOP_InsMO_ReMC	2	//开模后、重新关模	(暂不支持)

//后安全门开处理	Para_SGBackOpenPcs	
#define mBSGOP_Def			0	//不影响 
#define mBSGOP_ToManu		1	//1-转手动 
#define mBSGOP_ToManu_FSG	2	//2-转手动，但前安全门开则不影响
#define mBSGOP_OffMot		3	//3-转手动且切马达 
#define mBSGOP_OffMot_FSG	4	//4-转手动且切马达，但前安全门开则不影响

//润滑油液位传感器类型	Para_LubrOilLessSnrType
#define mLOLST_Null			0	//无
#define mLOLST_NC			1	//常闭
#define mLOLST_NO			2	//常开

//中子类型		Para_CoreXFun
#define mCF_Off			0	//不用
#define mCF_Core		1	//中子
#define mCF_Screw		2	//绞牙

//中子控制方式	Para_CoreXCtrlMode
#define	mCCM_Sensor		0	//行程
#define	mCCM_Time		1	//时间
#define	mCCM_Count		0	//计数

//中子动作时机	Para_CoreXInOcc、Para_CoreXOutOcc		本宏顺序不能改，会影响程序
#define mCO_Start		0	//起始执行
#define mCO_Mid			1	//中途执行	具体依据动作位置	
#define mCO_End			2	//动作执行

//特殊中子代码	Para_CoreSpecFunCode
#define mCSFC_Std					0	//标准
#define mCSFC_A_EjeFor_Out			1	//中子A	 托进->出芯
#define mCSFC_B_EjeFor_Out			2	//中子B	 托进->出芯
#define mCSFC_A_EjeFor_Out_In		3	//中子A	 托进->出芯->入芯		
#define mCSFC_B_EjeFor_Out_In		4	//中子B	 托进->出芯->入芯
#define mCSFC_A_Out_In				5	//中子A	 出芯->入芯			出芯后立即入芯，动作时机取决于设置		主要是出芯后立即入芯
#define mCSFC_B_Out_In				6	//中子B	 出芯->入芯
#define mCSFC_AB_EjeFor_Out			7	//中子AB 托进->出芯
#define mCSFC_A_Inject_In			8	//中子A	 注射-入芯			用于切料柄	20121117加
#define mCSFC_B_Inject_In			9	//中子B	 注射-入芯			用于切料柄	20121117加
#define mCSFC_B_EjeFor_Out_Gate_In	10	//中子B  托进-出芯-取件-入芯（托退动作中检查执行）	20130412加
#define mCSFC_A_EjeFor_SOut_EjeRet_Out	11	//中子A	 托进-特殊出芯-托退-出芯				20130724加
#define mCSFC_A_Inject_Out				12	//中子A	 注射-出芯								20150923加
#define mCSFC_C_Inject_LinkIn			13	//中子C	 注射-入芯连动	用于眼镜机	20160407加
#define mCSFC_B_In_EjeFor				14	//中子B  入芯-托进					20170525加
//#define mCSFC_						15	//

//开模连动		Para_MoldOpenLinkSel
#define mMOLS_Off					0	//关闭
#define mMOLS_EjeFor				1	//托模
#define mMOLS_Core1					2	//中子A
#define mMOLS_Core2					3	//中子B
#define mMOLS_Core3					4	//中子C

//液压喷嘴类型	Para_HydNozType
#define mHNT_UnOpt		0		//未配备
#define mHNT_SigPos		1		//单位	自已会复位
#define mHNT_DouPos		2		//双位	需要关闭

//欧规机械手开模中途取物模式	Para_MOMedRobotMode
#define mMOMRM_Null		0		//不用	
#define mMOMRM_NoStop	1		//不停取物
#define mMOMRM_StopPB	2		//PB控制停留
#define mMOMRM_StopTi	2		//计时停留

//欧规机械手配合机械手的中子	Para_RobotCoreSel
#define mRCS_Null		0		//无
#define mRCS_CoreA		1		//中子A
#define mRCS_CoreB		2		//中子B

//排气模式		Para_ExhaustMode
#define mEXM_Off		0		//不用
#define mEXM_InjEnd		1		//注射后
#define mEXM_HP1End		2		//保一后
#define mEXM_HP2End		3		//保二后
#define mEXM_HPEnd		4		//保压后
#define mEXM_Inject		5		//注射中	20210618加

//测量传感器选择	Para_SysFlowMeasSnrSel、Para_SysPresMeasSnrSel、Para_InjPresMeasSnrSel、Para_MoldPresMeasSnrSel
#define	mMSS_Null		0		//无配备
#define	mMSS_HAI1		1		//HAI1
#define	mMSS_HAI2		2		//HAI2
#define	mMSS_HAI3		3		//HAI3
#define	mMSS_HCSDCan	4		//汇川驱动器经CAN读取的状态中
#define	mMSS_HiM6Car	5		//海天驱动M6卡	20250515	加

//注射失败时顶针机械手处理 Para_AlarmEjePcs			注：如果是连动托模，则不受本参数影响，即固定会托模
#define mAEP_Eject			 0	//顶出
#define mAEP_ShotBadNoEje	 1	//注射失败不顶出
#define mAEP_FreeToManuNoEje 2	//闲转手动警报就不顶出

//热流道功能		Para_HRVxx_Function
#define mHRF_Off			0	//关闭
#define mHRF_TiOnTiOff		1	//时间开、时间关
#define mHRF_PosOnPosOff	2	//位置开、位置关
#define mHRF_TiOnPosOff		3	//时间开、位置关
#define mHRF_PosOnTiOff		4	//位置开、时间关

//托模切料功能选择	Para_EjeCutMatSel
#define mECMS_Off		0		//不用
#define mECMS_InjEnd	1		//注射后
#define mECMS_HP1End	2		//保一后
#define mECMS_HP2End	3		//保二后
#define mECMS_HPEnd		4		//保压后
#define mECMS_HoldPres	5		//保压时（保压时打开托模阀，压力和流量同保压）

//座退控制方式		Para_NozRetCtrlMode
#define mNRCM_Time		0		//时间
#define mNRCM_Senor		1		//位置		行程开关、或位置尺

//F组吹气时机		Para_Air6Occ
#define mAO_Nor			0		//正常		开模时
#define mAO_Charge		1		//储料时

//夹具类型			Para_JigType
#define mJT_Off			0		//关闭
#define mJT_Hyd			1		//液压
#define mJT_Mag			2		//磁力		备用

//油温预热模式		Para_OilPreHtrMode
#define mOPHM_Nor		0		//正常
#define mOPHM_TwoPrd	1		//2级预热	主要海天J5机

//润滑参数管理模式	Para_LubrParaMangMode
#define mLPMM_Std		0		//标准,
#define mLPMM_1W		1		//海天模式（前后10000模采用不同参数，可设范围限定，通过U盘配置）
#define mLPMM_5W		2		//海天模式（前后50000模采用不同参数，可设范围限定，通过U盘配置）
#define mLPMM_1W_5W		3		//海天模式（润滑1前后润滑区分10000模，润滑2前后润滑区分50000模）20181008
#define mLPMM_5W_1W		4		//海天模式（润滑1前后润滑区分50000模，润滑2前后润滑区分10000模）

//半自动时允许开模连动	Para_SMMOAutoGateLinkSel
#define mSMMOAGLS_Off			0	//关闭
#define mSMMOAGLS_StdLink		1	//标准连动
#define mSMMOAGLS_AftMoldOpen	2	//开模后连动

//托模切料模式 		Para_EjeCutMatMode
#define mECMM_For		0		//托进切料
#define mECMM_ForRet	1		//托进后托退

//托退模式 		Para_EjeRetMode
#define mERM_Stand		0		//标准
#define mERM_TwoRet		1		//二次托退
#define mERM_NoRet		2		//不托退

//自动门类型	Para_AutoGateType
//#define mAGT_			0		//待定义
#define mAGT_KEB		1		//KEB电动门
//#define mAGT_			2		//待定义

/*======================================== 全局有效变量定义 =======================================*/


/*======================================== 全局有效函数声明 =======================================*/



#endif

/*




//监测情况	State_AutoMoni_HW、State_AutoMoni_LW	每位对应一种监测结果 0-正常 1-异常
#define	mMo_MCTi		mBit0	//关模时间
#define	mMo_MCLPTi		mBit1	//关模低压时间
#define	mMo_MCHPTi		mBit2	//关模高压时间
#define mMo_MOTi		mBit3	//开模时间
#define mMo_MOEPos		mBit4	//开模结束位置
#define mMo_EjeTi		mBit5	//托模时间
#define mMo_CycleTi		mBit6	//循环时间
#define mMo_ChgTi		mBit7	//储料时间
#define mMo_ChgEPos		mBit8	//储料结束位置
#define mMo_SuckBackTi	mBit9	//射退时间
#define mMo_ChgRPM		mBit10	//储料最高转速
#define mMo_InjTi		mBit11	//注射时间		即注射连同保压的时间
#define mMo_InjEPos		mBit12	//注射结束位置	即保压结束位置
#define mMo_InjSpd		mBit13	//射出最高速度	
#define mMo_HPPos		mBit14	//转保压位置
#define mMo_HPPrs		mBit15	//转保压压力
#define mMo_HPTi		mBit0	//转保压时间	在State_AutoMoni_HW

//超差处理	Para_xx_OverPcs
#define mOP_Ignore	0	//忽略
#define mOP_Prompt	1	//提示
#define mOP_Alam	2	//警报	停机转手动

//自动监测	Para_AutoMoniPcs
#define mAMP_Off		0	//关闭
#define	mAMP_On			1	//开启
#define	mAMP_ReSample	2	//重取


//波形动作状态	State_Wave_ActState
#define mWAS_MoldOpen	mBit8   //开模	为1表示正在开模，为0表示开模结束
#define mWAS_MoldCls	mBit9   //关模	同上                            
#define mWAS_Inject		mBit10  //注射	同上                            
#define mWAS_HoldPres	mBit11  //保压	同上                            
#define mWAS_Charge		mBit12  //储料	同上                            
#define mWAS_EjeFor		mBit13	//顶针	同上
#define mWAS_EjeRet		mBit14	//项针	同上

//润滑模式
#define mLM_Time		0		//定阻式
#define mLM_Pres		1		//定量加压式
#define mLM_Cnt			2		//定次式


//座台退模式	Para_NozBackMode
#define mNBM_NoBack		0		//不退
#define mNBM_AfterChg	1		//储后
#define	mNBM_AfterCool	2		//冷后
#define mNBM_AfterInj	3		//射后

*/












