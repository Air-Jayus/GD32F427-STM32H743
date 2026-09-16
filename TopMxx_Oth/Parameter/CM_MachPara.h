/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_MachPara.h    机器参数文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0xE502  
****************************************************************************************************/
#ifndef CM_MachPara_h
    #define CM_MachPara_h

#ifdef RPHA_c
    #define CM_MachPara_ext
#else
    #define CM_MachPara_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//机器参数数量
#define mMachParaNum 2048  //机器参数数量

//机器参数数组定义
CM_MachPara_ext U32 MachPara[mMachParaNum];      //机器参数数组

//机器参数序号宏定义
#define mPara_MachParaSum        0              //累加和校验码                              辅助用，下述机器参数累加和
#define mPara_MachParaLinkCode   1              //互连代码                                辅助用，机器参数互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效
#define mPara_MachParaVer        2              //版本号                                 辅助用，版本号，用于识别建置文件版本是否一致，当重要参数增减时一并修改版本号
#define mPara_MachParaID         3              //标识                                  辅助用，与版本号一起用于识别建置文件是否一致，当某个机型的配置有更改时，其标识号应一并修改
#define mPara_Mach_4             4              //                                    
#define mPara_Mach_5             5              //                                    
#define mPara_Mach_6             6              //                                    
#define mPara_Mach_7             7              //                                    
#define mPara_Mach_8             8              //                                    
#define mPara_Mach_9             9              //                                    
#define mPara_SysPresMax         10             //系统压力最大值                             除注射动作以外压力最大值
#define mPara_InjPresMax         11             //射出压力最大值                             注射1-10的压力最大值
#define mPara_MoldClsLPPresMax   12             //关模低压压力最大值                           
#define mPara_MoldClsLPFlowMax   13             //关模低压流量最大值                           
#define mPara_MoldClsHPFlowMax   14             //关模高压流量最大值                           
#define mPara_MoldOpen1PresMax   15             //开模一慢压力最大值                           
#define mPara_MoldOpen1FlowMax   16             //开模一慢流量最大值                           
#define mPara_MoldAdjPresMax     17             //调模压力上限                              调模进、退压力最大值
#define mPara_MoldAdjFlowMax     18             //调模流量上限                              调模进、退流量最大值
#define mPara_NozForMaxPres      19             //座台进压力最大值                            
#define mPara_NozMaxFlow         20             //座台流量最大值                             
#define mPara_SuckBackPresMax    21             //射退压力最大值                             
#define mPara_SuckBackFlowMax    22             //射退流量最大值                             
#define mPara_EjePresMax         23             //托模压力最大值                             
#define mPara_EjeFlowMax         24             //托模流量最大值                             
#define mPara_CorePresMax        25             //中子压力最大值                             
#define mPara_CoreFlowMax        26             //中子流量最大值                             
#define mPara_ChgPresMax         27             //储料压力最大值                             
#define mPara_ChgFlowMax         28             //储料流量最大值                             
#define mPara_BackPresMax        29             //背压压力最大值                             用于生产画面中储料背压的限值，背压阀的最大压力取决于下面的“背压阀压力最大值”
#define mPara_NozRetMaxPres      30             //座台退压力最大值                            
#define mPara_ChgFlowEnMax       31             //储料流量允许最大值                           设定储料流量大于此值，按此值输出，主要是因天剑机器缺陷而加。
#define mPara_BackPresValMax     32             //背压阀压力最大值                            背压比例阀的最大压力
#define mPara_HoldPresPresMax    33             //保压压力最大值                             保压1-10的压力最大值
#define mPara_MoldClsHPPresMax   34             //关模高压压力最大值                           
#define mPara_FrontSGUnClsDisSemiAuto 35        //前安全门未关禁止半自动                         0-允许 1-禁止   前安全门未关禁止半自动
#define mPara_SafeGateFront2Opt  36             //安全门二关配备                             0-没有 1-有
#define mPara_SafeGateBackOpt    37             //后安全门配备                              0-没有 1-有
#define mPara_SafeGateTopOpt     38             //上顶盖配备                               0-没有 1-有
#define mPara_SafeGateButOpt     39             //底板安全门配备                             0-没有 1-有
#define mPara_NozSafeGateOpt     40             //射嘴防护罩配备                             0-没有 1-有
#define mPara_EjeRetEndSnrOpt    41             //托退终行程开关配备                           0-没有 1-有
#define mPara_HopperSnrOpt       42             //料斗检知配备                              0-没有 1-有
#define mPara_MoldAdjSnrOpt      43             //调模电眼配备                              0-没有 1-有，无调模电眼时禁止自动调模
#define mPara_MachProtSnrOpt     44             //机械保险检测配备                            0-没有 1-有，HT常规机械保险
#define mPara_HydProtSnrOpt      45             //液压保险检测配备                            0-没有 1-有，HT常规液压保险
#define mPara_CycStartKeyOpt     46             //循环启动键配备                             0-没有 1-有
#define mPara_AirSrcPresSnrOpt   47             //气源压力检测配备                            0-没有 1-有，气动机械保险时气源压力检测
#define mPara_CycStopKeyOpt      48             //循环停止键配备                             0-没有 1-有，循环停止键：平时为1，自动方式时如变为0，则转手动
#define mPara_BackPresPVOpt      49             //背压比例阀配备                             0-没有 1-有
#define mPara_AccOpt             50             //蓄能器配备                               0-没有 1-有
#define mPara_AirInjOpt          51             //气辅射出配备                              0-没有 1-有
#define mPara_Lubr2Opt           52             //润滑2配备                               0-没有 1-有
#define mPara_ExhaustOpt         53             //热固机配备                               0-没有 1-有
#define mPara_LinkOilWayOpt      54             //连动油路配备                              0-没有 1-有
#define mPara_PilotOilAccOpt     55             //先导油储能器配备                            0-没有 1-有，先导油储能器配备，用于中大机合模区安全
#define mPara_MoldClsFastOpt     56             //关模快速油路配备                            0-没有 1-有
#define mPara_MoldOpenFastOpt    57             //开模快速油路配备                            0-没有 1-有
#define mPara_InjFastOpt         58             //注射快速油路配备                            0-没有 1-有
#define mPara_JigType            59             //模具夹具类型                              0-无 1-液压 2-(磁力)……
#define mPara_CanModuleOpt       60             //CAN模块配备                             通过CAN总线扩展的CAN模块是否配备
#define mPara_TieRodsMonOpt      61             //拉杆受力监测配备                            0-没有 1-有
#define mPara_NozSnrOpt          62             //座台尺配备                               0-没有 1-有
#define mPara_MotTempSnrOpt      63             //马达测温配备                              0-没有 1-有
#define mPara_ServoDrvOpt        64             //驱动器配备                               驱动器配备选项，主要影响电机使能信号、风扇信号、温度信号、异常信号
#define mPara_ToggleProtSnrOpt   65             //曲肘防护配备                              0-没有 1-有
#define mPara_OilLessSnrOpt      66             //油位传感器配备                             0-没有 1-有
#define mPara_OilLessSnrLog      67             //油位传感器逻辑                             0-正逻辑(ON-油位低、Off-油位正常)、1-负逻辑(ON-油位正常、OFF-油位低)
#define mPara_J5_PID_DA_Sel      68             //J5_PID_DA选择                         0-关闭 1-使用，J5多组PID功能通过DA通道实现
#define mPara_J5_PID_CAN_Sel     69             //J5_PID_CAN选择                        0-关闭 1-使用，J5多组PID功能通过CAN通讯实现
#define mPara_MotorOnMode        70             //马达开启模式                              0-星三角启动  1-直接启动  2-直接启动且MOTON继电器保持输出
#define mPara_MoldSnrInCyl       71             //模板尺安装在油缸上                           模板尺安装位置：0-模板 1-油缸
#define mPara_LubrMode           72             //自动润滑模式                              0-定阻 1-定量加压 2-定次（只支持2-定次）
#define mPara_Lubr1OilLessSnrType 73            //润滑1油位传感器类型                          0-没有 1-常闭油位正常 2-常开油位正常
#define mPara_GRYLightMode       74             //三色报警灯模式                             0-国标 1-欧标
#define mPara_HydNozType         75             //液压喷嘴类型                              0-没有 1-单向 2-双向
#define mPara_PumpType           76             //泵类型                                 0-叠加泵 1-组合泵
#define mPara_ScrewRPMSnrGear    77             //螺杆转速盘齿数                             
#define mPara_ScrewRPMSoftCnt    78             //螺杆转速软件计数                            若螺杆电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define mPara_MoldAdjSnrSoftCnt  79             //调模电眼用软件计数                           若调模电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define mPara_ProdSnrSoftTri     80             //检物电眼软件触发                            若检物电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define mPara_OilPreHtrMode      81             //油温预热模式                              0-正常,1-二级预热(主要针对海天J5机),2～9-保留
#define mPara_CoreNum            82             //中子组数                                0-没有 N-1～N组有效
#define mPara_AirNum             83             //吹气组数                                0-没有 N-1～N组有效
#define mPara_InjectNum          84             //注射段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到6段)
#define mPara_HoldPresNum        85             //保压段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到6段)
#define mPara_ChargeNum          86             //储料段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到5段)
#define mPara_MoldCls3Sel        87             //关模3段选择                              0-不用 1-使用
#define mPara_MoldOpen3Sel       88             //开模3段选择                              0-不用 1-使用
#define mPara_MCEjeOnSel         89             //关模时托退阀开选择                           1-开：无论顶针用否，关模时顶针吸一下，持续“关模时托退阀开时间”；0-不开：只在顶针不用，关模时吸
#define mPara_AlarmEjePcs        90             //警报时顶针处理                             闲转手动警报时托模(不含连动)处理:0-顶出 1-注射失败则不顶出 2-闲转手动警报则不顶出
#define mPara_AMMoldClsSGOpenPcs 91             //关模中安全门打开处理                          自动时关模安全门打开：0-立停 1-开模后结束 2-开模等再次关门
#define mPara_SGBackOpenPcs      92             //后安全门打开处理                            0-不影响 1、2-转手动 3、4-转手动且切马达(2、4如前安全门开则不影响)
#define mPara_SGOpenEnEjeFor     93             //安全门开允许托进                            0-不允许 1-允许（下面还有一个“安全门未关禁止托退”参数）
#define mPara_ProdDropEjeFin     94             //电眼检物结束托模                            1-电眼方式时，检查到物品掉落，立即结束托模
#define mPara_ManuModeDisLink    95             //手动模式下禁止连动                           0-手动方式下，开、关模时连动会进行 1-不会进行
#define mPara_MCHPPresMeasMode   96             //锁模压力测量模式                            0-高压锁模时测量、1-高压锁模延时后再测量
#define mPara_MCHPPresMeasDly    97             //锁模压力测量延时                            
#define mPara_LinkPumpSel        98             //连动时泵选择                              连动时对应需要一起开启的泵选择，0-无泵打开、1-泵一、2-泵二……
#define mPara_EjeCutMatFunEn     99             //托模切料功能允许                            0-禁止,1-允许,即在注射或保压的某时机,托模进一点，以切断料柄
#define mPara_DrvEnSigRstDrv     100            //通过使能信号复位驱动器                         1-驱动器警报时，通过断开使能信号来复位驱动器
#define mPara_SnrDropTi          101            //电眼检物时间                              电眼检物时间
#define mPara_MCEjeOnTi          102            //关模时托退阀开时间                           顶针不用时，关模时顶针吸一下
#define mPara_HydProtChkDly      103            //液压保护检查延时                            液压保护检查延迟时间，HT常规液压保险时逻辑
#define mPara_HydProtLog         104            //液压保险逻辑                              0-小机(门开有信号) 1-大机(门关有信号)，HT常规液压保险时逻辑 2-关模时常闭 3-关模时常开
#define mPara_AutoGateOpt        105            //自动安全门配备                             0-未配备 1-配备
#define mPara_AutoGateType       106            //自动安全门类型                             1-KEB门机     其它待定义
#define mPara_AutoMoniStdDataGenMode 107        //监测数据生成方式                            0-自动采样 1-用户设置 2-用户设置+自动采样
#define mPara_HADPriNum          108            //HAD优先级数                             0-1路优先 1-2路优先
#define mPara_PropValRampMode    109            //比例阀斜率模式                             0-(目标-当前)/时间 1-最大值/时间
#define mPara_MoldClsFlowScale   110            //关模流量降低比例                            关模时，实际流量为设定值乘以该比例
#define mPara_MoldOpenFlowScale  111            //开模流量降低比例                            开模时，实际流量为设定值乘以该比例
#define mPara_PVOutDispMode      112            //比例阀输出显示模式                           0-显示当前实际输出值（可以看到斜率过程） 1-显示目标值
#define mPara_PropValCurrMeasOpt 113            //比例阀电流测量配备                           T6F3控制器配备阀电流测量电路，可以监控比例阀的电流
#define mPara_PropValCurrEnDev   114            //比例阀电流允许偏差                           比例阀测得电流 + 本偏差 >设置输出电流，则报警。其中，设置输出电流=1000mA*占空比
#define mPara_FlowFBCtrl_Inj     115            //注射流量闭环选择                            1-注射一～十时（仅标准注射、不包括保压），“FlowFeedBackCtrl 流量闭环”信号ON
#define mPara_FlowFBCtrl_MO1     116            //开模一慢流量闭环选择                          1-开模一慢时（仅标准开模），“FlowFeedBackCtrl 流量闭环”信号ON
#define mPara_FlowFBCtrl_MCHP    117            //关模高压流量闭环选择                          1-关模高压时（仅标准关模），“FlowFeedBackCtrl 流量闭环”信号ON
#define mPara_InjPropValMargin   118            //注射比例阀裕度                             特殊注射比例阀，系统压力、流量适当提高，以使该比例阀稳定控制输出
#define mPara_EjectFlowScale     119            //顶针流量降低比例                            顶针时，实际流量为设定值乘以该比例
#define mPara_R_RobotRetEndOpt   120            //机械手回到位配备                            简易机械手、Start
#define mPara_R_RobotOptModeOpt  121            //机械手不用配备                             Euro 67/12
#define mPara_R_EmerStopOpt      122            //机械手紧停配备                             Euro 67/12、Start
#define mPara_R_CycStartOpt      123            //循环启动配备                              Start
#define mPara_R_MoldAreaFreeOpt  124            //模区安全配备                              Euro 67/12
#define mPara_R_EnClampOpt       125            //关模允许配备                              Euro 67/12
#define mPara_R_EnMoldOpenOpt    126            //开模允许配备                              Start
#define mPara_R_EnFullMoldOpenOpt 127           //全开模允许配备                             Euro 67/12
#define mPara_R_EnEjeForOpt      128            //托模进允许配备                             Euro 67/12、Start
#define mPara_R_EnEjeRetOpt      129            //托模退允许配备                             Euro 67/12、Start
#define mPara_R_EnCoreInOpt      130            //中子进允许配备                             Euro 67/12
#define mPara_R_EnCoreOutOpt     131            //中子退允许配备                             Euro 67/12
#define mPara_ChgFlowScale       132            //储料流量降低比例                            储料时，实际流量为设定值乘以该比例
#define mPara_HoldPresPropRelPresDiff 133       //保压溢流压力差                             暂主要用于双节机，保压动作时比例溢流阀降低输出的压力值
#define mPara_BMCOpt             134            //BMC功能配备                             0-未配备 1-配备
#define mPara_SteamInjOpt        135            //蒸汽注射配备                              0-未配备 1-配备
#define mPara_MoldThickSnrOpt    136            //模厚尺配备                               0-未配备 1-配备
#define mPara_MoldThickMax       137            //最大模厚                                机器容纳模具最大尺寸
#define mPara_MoldThickMin       138            //最小模厚                                机器容纳模具最小尺寸
#define mPara_InjPresSnrOpt      139            //注射压力传感器配备                           0-未配备 1-配备,主要界面使用，影响“压力转保压”是否有效及主画面显示注射压力
#define mPara_ZoneTempMax        140            //料筒温度最大值                             料筒允许最高温度，超过则报警、停电热
#define mPara_ZoneTempDispCalK   141            //温度显示修正系数                            温度显示用：当实测温度超出时，超出部分乘以该系数送画面显示
#define mPara_GB_SafeRelayRstChk 142            //安全继电器复位检查                           0-不用 1-检查   检查安全继电器是否正确复位   
#define mPara_GB_HydProtStd      143            //液压检测安全标准                            液压检测安全标准 0-不用 1-模式一
#define mPara_GB_NozGateLoopChk  144            //防护罩安全回路检查                           注射防护罩安全回路检查 0-不用 1-模式一
#define mPara_NozGateUnClsDisInj 145            //防护罩未关禁止注射                           0-允许 1-禁止   主要用于GB22530安全标准
#define mPara_NozGateUnClsDisChg 146            //防护罩未关禁止储料                           0-允许 1-禁止   主要用于GB22530安全标准
#define mPara_NozGateUnClsDisNozFor 147         //防护罩未关禁止座进                           0-允许 1-禁止   主要用于GB22530安全标准
#define mPara_FrontSGUnClsDisAuto 148           //前安全门未关禁止自动                          0-允许 1-禁止   主要用于GB22530安全标准，如果是半自动则不受影响
#define mPara_FrontSGUnClsDisInj 149            //前安全门未关禁止注射                          0-允许 1-禁止   主要用于GB22530安全标准
#define mPara_FrontSGUnClsDisChg 150            //前安全门未关禁止储料                          0-允许 1-禁止,与"是否已经安装模具"参数配合,主要用于GB22530安全标准
#define mPara_FrontSGUnClsDisNozFor 151         //前安全门未关禁止座进                          0-允许 1-禁止   主要用于GB22530安全标准
#define mPara_SGUnClsDisMoldThin 152            //安全门未关禁止调模进                          0-允许 1-禁止
#define mPara_SGUnClsDisCoreIn   153            //安全门未关禁止中子进                          0-允许 1-禁止
#define mPara_SGUnClsDisCoreOut  154            //安全门未关禁止中子出                          0-允许 1-禁止
#define mPara_SGUnClsDisEjeRet   155            //安全门未关禁止托模退                          0-允许 1-禁止
#define mPara_SGUnClsDisMoldThick 156           //安全门未关禁止调模退                          0-允许 1-禁止
#define mPara_FrontSGUnClsDisChg_ExSemi 157     //半自动前门开允许储料                          0-半自动禁止储料 1-半自动允许储料，画面显示"是否已经安装模"  主要用于GB22530安全标准
#define mPara_CANModuleCANPort   158            //扩展模块CAN端口                           0-CAN1、1-CAN2
#define mPara_Lubr2OilLessSnrType 159           //润滑2油位传感器类型                          0-没有 1-常闭油位正常 2-常开油位正常
#define mPara_AutoGateOpenStrokeMax 160         //自动门开门距离(上限)                         
#define mPara_AutoGateOpenStrokeMin 161         //自动门开门距离(下限)                         
#define mPara_AutoGateOpenDistance 162          //自动门开门距离                             
#define mPara_MotorErrOpt        163            //电机异常检测配备                            1-"PC 电机异常"输入点配备，当该点为OFF时，警报"电机相位或风扇异常"
#define mPara_VarPumpQuanPumpSys 164            //变量泵+定量泵系统                           6500V以上变量泵机器，动力为“变量泵+定量泵”，泵仅在大流量动作时才检查输出
#define mPara_SysFlowMeasSnrSel  165            //系统流量对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealFlow(由CAN从驱动器直接读取)
#define mPara_SysPresMeasSnrSel  166            //系统压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define mPara_InjPresMeasSnrSel  167            //注射压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define mPara_MoldPresMeasSnrSel 168            //模板压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define mPara_LinkPresMeasSnrSel 169            //联动压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define mPara_ScrewSnrLen        170            //螺杆尺长度                               螺杆尺长度
#define mPara_ScrewSnrZero       171            //螺杆尺零点                               螺杆尺零点位置，必须紧跟在长度后面，长度校准时要求
#define mPara_ScrewSnrStroke     172            //螺杆机械行程                              螺杆尺机械行程
#define mPara_MoldSnrLen         173            //模板尺长度                               模板尺长度
#define mPara_MoldSnrZero        174            //模板尺零点                               模板尺零点位置，必须紧跟在长度后面，长度校准时要求
#define mPara_MoldSnrStroke      175            //模板机械行程                              模板尺机械行程
#define mPara_EjeSnrLen          176            //顶针尺长度                               顶针尺长度
#define mPara_EjeSnrZero         177            //顶针尺零点                               顶针尺零点位置，必须紧跟在长度后面，长度校准时要求
#define mPara_EjeSnrStroke       178            //顶针机械行程                              顶针尺机械行程
#define mPara_NozSnrLen          179            //座台尺长度                               座台尺长度
#define mPara_NozSnrZero         180            //座台尺零点                               座台尺零点位置，必须紧跟在长度后面，长度校准时要求
#define mPara_NozSnrStroke       181            //座台机械行程                              座台尺机械行程
#define mPara_HAI1Len            182            //模拟量1长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define mPara_HAI1Zero           183            //模拟量1零点                              模拟量0V电压对应的值
#define mPara_HAI1Stroke         184            //模拟量1限值                              模拟量对应的限值
#define mPara_HAI2Len            185            //模拟量2长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define mPara_HAI2Zero           186            //模拟量2零点                              模拟量0V电压对应的值
#define mPara_HAI2Stroke         187            //模拟量2限值                              模拟量对应的限值
#define mPara_HAI3Len            188            //模拟量3长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define mPara_HAI3Zero           189            //模拟量3零点                              模拟量0V电压对应的值
#define mPara_HAI3Stroke         190            //模拟量3限值                              模拟量对应的限值
#define mPara_MoldThickSnrLen    191            //模厚尺长度                               模厚尺长度
#define mPara_MoldThickSnrZero   192            //模厚尺零点                               模厚尺零点位置，必须紧跟在长度后面，长度校准时要求
#define mPara_MoldThickSnrStroke 193            //模厚尺机械行程                             模厚尺机械行程,预留，实际用不到
#define mPara_MoldThickSnrOffset 194            //模厚尺偏移                               模厚尺偏移值：模厚不可能为0，即归零点已经有一定的模厚了，即此偏移值
#define mPara_CANForwardCANPort  195            //CAN转发端口                             与BOX通讯：0-关闭、1-CAN1、2-CAN2
#define mPara_ProdTaskFinPcs     196            //生产任务单完成处理                           针对管工厂，产品数到时：0-不处理 1-提示 2-结束生产
#define mPara_FilterSen0Log      197            //滤油网检测0#逻辑                           0-不检查 1-常开 2-常闭
#define mPara_FilterSen0ChkTemp  198            //滤油网检测0#检测温度                         
#define mPara_LastCoolProtFlag   199            //                                    上次断电时的防冷启状态
#define mPara_TempCalB_N         200            //温度校准调低B                             温度校准调低的度数
#define mPara_TempCalB_P         201            //温度校准调高B                             温度校准调高的度数
#define mPara_TempCalK           202            //温度校准K                               有效范围0.85-1.15，超此范围则为1.00
#define mPara_TempCtrlIntegRange 203            //PID控温积分范围                           PID控温积分范围,温在此参数偏差之内进行积分计算
#define mPara_TempCtrlPIDSel     204            //PID控温算法选择                           0-适用普通热筒  1-适用大惯性模具
#define mPara_TempCtrlPID0HtrScale 205          //PID控温算法0加热系数                        在TempCon_PID_Sel=0时有效
#define mPara_TempCtrlPID1HtrScale 206          //PID控温算法1加热系数                        在TempCon_PID_Sel=1时有效
#define mPara_Mach_207           207            //                                    
#define mPara_Zone1TCPID_P       208            //PID控温算法P                            
#define mPara_Zone1TCPID_I       209            //PID控温算法I                            
#define mPara_Zone1TCPID_D       210            //PID控温算法D                            
#define mPara_Zone2TCPID_P       211            //PID控温算法P                            
#define mPara_Zone2TCPID_I       212            //PID控温算法I                            
#define mPara_Zone2TCPID_D       213            //PID控温算法D                            
#define mPara_Zone3TCPID_P       214            //PID控温算法P                            
#define mPara_Zone3TCPID_I       215            //PID控温算法I                            
#define mPara_Zone3TCPID_D       216            //PID控温算法D                            
#define mPara_Zone4TCPID_P       217            //PID控温算法P                            
#define mPara_Zone4TCPID_I       218            //PID控温算法I                            
#define mPara_Zone4TCPID_D       219            //PID控温算法D                            
#define mPara_Zone5TCPID_P       220            //PID控温算法P                            
#define mPara_Zone5TCPID_I       221            //PID控温算法I                            
#define mPara_Zone5TCPID_D       222            //PID控温算法D                            
#define mPara_Zone6TCPID_P       223            //PID控温算法P                            
#define mPara_Zone6TCPID_I       224            //PID控温算法I                            
#define mPara_Zone6TCPID_D       225            //PID控温算法D                            
#define mPara_Zone7TCPID_P       226            //PID控温算法P                            
#define mPara_Zone7TCPID_I       227            //PID控温算法I                            
#define mPara_Zone7TCPID_D       228            //PID控温算法D                            
#define mPara_Zone8TCPID_P       229            //PID控温算法P                            
#define mPara_Zone8TCPID_I       230            //PID控温算法I                            
#define mPara_Zone8TCPID_D       231            //PID控温算法D                            
#define mPara_Zone9TCPID_P       232            //PID控温算法P                            
#define mPara_Zone9TCPID_I       233            //PID控温算法I                            
#define mPara_Zone9TCPID_D       234            //PID控温算法D                            
#define mPara_Zone10TCPID_P      235            //PID控温算法P                            
#define mPara_Zone10TCPID_I      236            //PID控温算法I                            
#define mPara_Zone10TCPID_D      237            //PID控温算法D                            
#define mPara_Zone11TCPID_P      238            //PID控温算法P                            
#define mPara_Zone11TCPID_I      239            //PID控温算法I                            
#define mPara_Zone11TCPID_D      240            //PID控温算法D                            
#define mPara_Zone12TCPID_P      241            //PID控温算法P                            
#define mPara_Zone12TCPID_I      242            //PID控温算法I                            
#define mPara_Zone12TCPID_D      243            //PID控温算法D                            
#define mPara_Zone13TCPID_P      244            //PID控温算法P                            
#define mPara_Zone13TCPID_I      245            //PID控温算法I                            
#define mPara_Zone13TCPID_D      246            //PID控温算法D                            
#define mPara_Zone14TCPID_P      247            //PID控温算法P                            
#define mPara_Zone14TCPID_I      248            //PID控温算法I                            
#define mPara_Zone14TCPID_D      249            //PID控温算法D                            
#define mPara_Zone15TCPID_P      250            //PID控温算法P                            
#define mPara_Zone15TCPID_I      251            //PID控温算法I                            
#define mPara_Zone15TCPID_D      252            //PID控温算法D                            
#define mPara_Zone16TCPID_P      253            //PID控温算法P                            
#define mPara_Zone16TCPID_I      254            //PID控温算法I                            
#define mPara_Zone16TCPID_D      255            //PID控温算法D                            
#define mPara_HeatUpPowerScale   256            //快升功率比例                              快升阶段加热功率下降比例
#define mPara_Mach_257           257            //                                    
#define mPara_HCIS300ServoDrv1Opt 258           //汇川IS300伺服驱动器1配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define mPara_HCIS300ServoDrv2Opt 259           //汇川IS300伺服驱动器2配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define mPara_HCIS300ServoDrv3Opt 260           //汇川IS300伺服驱动器3配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define mPara_HCIS300ServoDrv4Opt 261           //汇川IS300伺服驱动器4配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define mPara_HCIS300ServoDrv5Opt 262           //汇川IS300伺服驱动器5配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define mPara_HCIS300ServoDrv1Mode 263          //汇川IS300伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define mPara_HCIS300ServoDrv2Mode 264          //汇川IS301伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define mPara_HCIS300ServoDrv3Mode 265          //汇川IS302伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define mPara_HCIS300ServoDrv4Mode 266          //汇川IS303伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define mPara_HCIS300ServoDrv5Mode 267          //汇川IS304伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define mPara_HCIS300ServoDrvCANPort 268        //汇川IS300伺服驱动器CAN端口                   0-CAN1、1-CAN2
#define mPara_Mach_269           269            //                                    
#define mPara_SDCanBanud         270            //波特率选择                               
#define mPara_SDCanAddr          271            //CAN通讯地址                             
#define mPara_SDCanBrkTime       272            //CAN连续通讯时间                           即通讯中断检测时间，检出则结束输出、报ERR42故障
#define mPara_SDCtrlMode         273            //油压控制方式                              0-非油压控制模式 1-由CAN控制 2-由模拟通道控制 3-CAN油压模式(专用)
#define mPara_SDMotType          274            //电机类型选择                              0-普通异步 1-变频异步 2-永磁同步伺服
#define mPara_SDMotRatedPwr      275            //额定功率                                
#define mPara_SDMotRatedVol      276            //额定电压                                
#define mPara_SDMotRatedCurr     277            //额定电流                                
#define mPara_SDMotRatedFrq      278            //额定频率                                
#define mPara_SDMotRatedSpd      279            //额定转速                                
#define mPara_SDResPolPair       280            //旋转变压器极对数                            
#define mPara_Mach_281           281            //                                    
#define mPara_SDAI1MinVol        282            //AI1最小输入                             
#define mPara_SDAI1MinValue      283            //AI1最小输入对应设定                         
#define mPara_SDAI1MaxVol        284            //AI1最大输入                             
#define mPara_SDAI1MaxValue      285            //AI1最大输入对应设定                         
#define mPara_SDAI1FiltTime      286            //AI1输入滤波时间                           
#define mPara_SDAI2MinVol        287            //AI2最小输入                             
#define mPara_SDAI2MinValue      288            //AI2最小输入对应设定                         
#define mPara_SDAI2MaxVol        289            //AI2最大输入                             
#define mPara_SDAI2MaxValue      290            //AI2最大输入对应设定                         
#define mPara_SDAI2FiltTime      291            //AI2输入滤波时间                           
#define mPara_SDAI3MinVol        292            //AI3最小输入                             
#define mPara_SDAI3MinValue      293            //AI3最小输入对应设定                         
#define mPara_SDAI3MaxVol        294            //AI3最大输入                             
#define mPara_SDAI3MaxValue      295            //AI3最大输入对应设定                         
#define mPara_SDAI3FiltTime      296            //AI3输入滤波时间                           
#define mPara_SDPresSensErrTime  297            //油压传感器故障检测时间                         
#define mPara_SDPresSensMaxPres  298            //压力传感器压力量程                           
#define mPara_Mach_299           299            //                                    
#define mPara_SDSysMaxSpeed      300            //最大转速                                对应系统输出流量设定电机运行的最高转速
#define mPara_SDSysMaxPres       301            //系统油压                                
#define mPara_SDMaxBrakSpeed     302            //最大反向转速                              
#define mPara_SDUnderFlow        303            //底流                                  
#define mPara_SDUnderPres        304            //底压                                  
#define mPara_Mach_305           305            //                                    
#define mPara_SDDAxisInd         306            //D轴电感                                
#define mPara_SDQAxisInd         307            //Q轴电感                                
#define mPara_SDStatorRes        308            //定子电阻                                
#define mPara_SDMotIndResUnit    309            //单位                                  
#define mPara_SDBackVol          310            //反电动势                                
#define mPara_SDCoderAngle       311            //编码器安装角度                             
#define mPara_Mach_312           312            //                                    
#define mPara_SDPID_SuckBack     313            //射退动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_HoldPres     314            //保压动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SpdWaveAveFiltEn   315            //速度曲线平均滤波                            速度曲线平均滤波次数
#define mPara_SpdWaveFiltEn      316            //速度曲线滑动滤波                            速度曲线滑动滤波次数
#define mPara_Mach_317           317            //                                    
#define mPara_CoreFlowScale      318            //中子流量降低比例                            中子时，实际流量为设定值乘以该比例
#define mPara_InjectFlowScale    319            //注射流量降低比例                            注射时，实际流量为设定值乘以该比例
#define mPara_SDInjActRespLevel  320            //注射动作响应模式                            0-平稳S 1-均衡M 2-快速F，主要是油压控制参数Kp1、Ti1等的选择
#define mPara_Mach_321           321            //                                    
#define mPara_SDSpeedKP1         322            //速度环比例增益1                            
#define mPara_SDSpeedTI1         323            //速度环积分时间1                            
#define mPara_SDSpdSwtFrq1       324            //切换频率1                               上限受控于SDSpdSwtFrq2
#define mPara_SDSpeedKP2         325            //速度环比例增益2                            
#define mPara_SDSpeedTI2         326            //速度环积分时间2                            
#define mPara_SDSpdSwtFrq2       327            //切换频率2                               上限受控于最大频率
#define mPara_SDSpeedFiltTime    328            //速度环滤波时间常数                           
#define mPara_SDMaxTorque        329            //转矩上限                                
#define mPara_Mach_330           330            //                                    
#define mPara_SDCanSetPresRamp   331            //油压指令上升时间(上升斜率)                      
#define mPara_SDCanSetPresSFiltTime 332         //给定油压S滤波时间                           
#define mPara_SDActPidSel        333            //伺服驱动器动作PID功能选择                      
#define mPara_SDPresCtrlKP1      334            //油压控制Kp1                             注射压力响应参数……平稳模式
#define mPara_SDPresCtrlTI1      335            //油压控制Ti1                             
#define mPara_SDPresCtrlTD1      336            //油压控制Td1                             
#define mPara_Mach_337           337            //                                    
#define mPara_SDPresCtrlKP2      338            //油压控制Kp2                             注射压力响应参数……均衡模式
#define mPara_SDPresCtrlTI2      339            //油压控制Ti2                             
#define mPara_SDPresCtrlTD2      340            //油压控制Td2                             
#define mPara_Mach_341           341            //                                    
#define mPara_SDPresCtrlKP3      342            //油压控制Kp3                             注射压力响应参数……快速模式
#define mPara_SDPresCtrlTI3      343            //油压控制Ti3                             
#define mPara_SDPresCtrlTD3      344            //油压控制Td3                             
#define mPara_Mach_345           345            //                                    
#define mPara_SDPresCtrlKP4      346            //油压控制Kp4                             顶针压力响应参数
#define mPara_SDPresCtrlTI4      347            //油压控制Ti4                             
#define mPara_SDPresCtrlTD4      348            //油压控制Td4                             
#define mPara_Mach_349           349            //                                    
#define mPara_SDPresCtrlKP5      350            //油压控制Kp5                             开合模压力响应参数
#define mPara_SDPresCtrlTI5      351            //油压控制Ti5                             
#define mPara_SDPresCtrlTD5      352            //油压控制Td5                             
#define mPara_Mach_353           353            //                                    
#define mPara_SDPresCtrlKP6      354            //油压控制Kp6                             其它动作压力响应参数
#define mPara_SDPresCtrlTI6      355            //油压控制Ti6                             
#define mPara_SDPresCtrlTD6      356            //油压控制Td6                             
#define mPara_VacuumizeOpt       357            //抽真空配备                               0-抽真空未配备；1-抽真空配备
#define mPara_EjeRetEnd2Opt      358            //顶针退终2配备                             
#define mPara_Sys3PresMeasSnrSel 359            //系统3压力对应传感器                          0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)
#define mPara_InjCylDia          360            //注射油缸直径                              应天剑，用于换算注射的压力
#define mPara_InjRodDia          361            //注射活塞杆直径                             应天剑，用于换算注射的压力
#define mPara_ScrewDia           362            //螺杆直径                                应天剑，用于换算注射的压力
#define mPara_HotRunnerCanPart   363            //热流道CAN端口                            热流道CAN端口：0-未配备；1-CAN0；2-CAN1
#define mPara_HotRunner1Opt      364            //热流道控制板1配备                           热流道控制板1配备：0-未配备；1-配备
#define mPara_HotRunner2Opt      365            //热流道控制板2配备                           热流道控制板2配备：0-未配备；1-配备
#define mPara_HotRunner3Opt      366            //热流道控制板3配备                           热流道控制板3配备：0-未配备；1-配备
#define mPara_HotRunner4Opt      367            //热流道控制板4配备                           热流道控制板4配备：0-未配备；1-配备
#define mPara_HotRunner5Opt      368            //热流道控制板5配备                           热流道控制板5配备：0-未配备；1-配备
#define mPara_Mach_369           369            //                                    
#define mPara_Pump1Out           370            //泵1排量                                用于伺服电机根据转速计算流量，（实际未用，程序中用最大转速计算得流量）
#define mPara_Pump2Out           371            //泵2排量                                流量=排量*转速*泄漏系数，其中排量单位mL/r、转速单位rpm、泄漏系数约0.9
#define mPara_Pump3Out           372            //泵3排量                                TJ86/120排量为31.5mL/r、TJ160排量为40mL/r、TJ200排量为63mL/r
#define mPara_Pump4Out           373            //泵4排量                                
#define mPara_Pump5Out           374            //泵5排量                                
#define mPara_SuckBackLargeFlow  375            //射退使用大流量                             0-使用小流量（输出小流量信号）、1-使用大流量（不输出小流量信号）
#define mPara_BMCFeedLaddOpt     376            //加料爬梯配备                              加料爬梯配备:0-未配备;1-配备
#define mPara_PowerMonOpt        377            //电源确认配备                              0-不配备 1-配备
#define mPara_MotOffServoDrvErr  378            //马达关时监视驱动器异常                         0-不用 1-使用
#define mPara_Mot2TempSnrOpt     379            //马达二测温配备                             
#define mPara_SafeGateEndOpt     380            //尾板小门配备                              天剑快速机程序专用，标准机不使用,0-没有 1-有
#define mPara_HtrOutMode         381            //加热输出模式                              天剑快速机程序专用，标准机不使用,0-标准 1-5s周期
#define mPara_InjPresPropValMode 382            //注射压力比例阀模式                           天剑快速机程序专用，标准机不使用,0-平常最大 1-平常关闭 2-有动作最大
#define mPara_MoldOpenBrakeDist  383            //开模刹车距离                              
#define mPara_MachProtLog        384            //机械保险逻辑                              0-有信号锁模(检查复位) 1-有信号锁模(不检查复位) 2-无信号锁模
#define mPara_TempCanMod1CalK    385            //温度模块1校准系数K                          CAN-B温度模块的校准系数K
#define mPara_TempCanMod1CalPB   386            //温度模块1校准系数PB                         CAN-B温度模块的校准系数调高值
#define mPara_TempCanMod1CalNB   387            //温度模块1校准系数NB                         CAN-B温度模块的校准系数调低值
#define mPara_MoldThickPosScale  388            //位置调模比                               模厚位置调模齿轮比
#define mPara_KWhMeterOpt        389            //电表配备                                0-未配备 1-脉冲 2-RS485通过CAN转接(DLT645-97版) 3-RS485 4-CAN
#define mPara_EjeRetUnEndChkTi   390            //托退未到位检查时间                           托退未到位时，持续该时间才确认报警
#define mPara_EjeRetModeEn       391            //特殊托退模式允许                            1-生产参数“托退模式”有效
#define mPara_R_EnClamp_AutoMode_Opt 392        //自动关模允许配备                            特殊机械手“R_EnClamp_AutoMode”信号配备
#define mPara_R_RobotRunChk      393            //机械手运行检查                             1-“R_RobotRetEnd”机械手回到位信号在一个循环中应检出“0”变化
#define mPara_EjeStepModeEn      394            //逐步托模模式允许                            托模阻力很大的模具，分多次逐步顶进。即托进到顶针不会前进了，退回再次托进。
#define mPara_EjeStepModeChkTi   395            //逐步托模确认时间                            逐步顶进模式：检查确认顶针不会前进了的时间。
#define mPara_EjeStepModeChkDly  396            //逐步托模检查延时                            逐步顶进模式：延时该时间再进行检查确认顶针不会前进。
#define mPara_EjeFor2StepModeEn  397            //二级托模进模式允许                           特殊托模：托进分二次完成，避免产品顶出太快。（第一次顶进到一段结束，第二次才顶到位）
#define mPara_InjCompOpt         398            //压缩注射配备                              压缩注射模式:合模到设定位置－注射－继续合模
#define mPara_HoldPresPropRelMode 399           //保压溢流比例阀模式                           双阶机的保压溢流比例阀：0-非保压关闭、1-非保压最大输出、2-非保压且有动作时最大输出
#define mPara_InjEndNozForHold   400            //注射结束座进阀保持                           海天：1-注射结束座进阀保持，以避免储料时漏料。主要是大机有此问题。
#define mPara_CoolAutoPilotOilAcc 401           //冷却时先导油自动补油                          应双阶机加，双阶机冷却时间可能达30分钟或更多，导致先导油蓄能器泄漏，或用此功能自动补油
#define mPara_MoldOpenClsPresMax 402            //开关模压力最大值                            
#define mPara_InjAdvDecBaseF     403            //注射提前减速底流                            
#define mPara_InjAdvDecT         404            //注射提前减速时间                            
#define mPara_Mot3TempSnrOpt     405            //马达三测温配备                             配备三电机
#define mPara_MonCANPort         406            //监测功能对应CAN端口                         0-关闭 1-CAN1、2-CAN2
#define mPara_AutoGatePulseSingSpa 407          //脉冲间距                                KEB门机使用，一个齿代表的门移动距离
#define mPara_AutoGateSlowPulseNum 408          //减速脉冲数                               KEB门机使用，开门提前减速的脉冲数
#define mPara_AutoGateErrSignLog 409            //自动门警报信号逻辑                           0－Off报警   1-ON报警
#define mPara_SGUnClsDisSuckBack 410            //安全门未关禁止射退                           0-允许 1-禁止
#define mPara_SGUnClsDisNozRet   411            //安全门未关禁止座退                           0-允许 1-禁止
#define mPara_SGUnClsDisMoldOpen 412            //安全门未关禁止开模                           0-允许 1-禁止
#define mPara_SGUnClsDisMoldCls  413            //安全门未关禁止关模                           0-允许 1-禁止
#define mPara_SGUnClsDisAir      414            //安全门未关禁止吹气                           0-允许 1-禁止
#define mPara_ChgLinkOilWayOpt   415            //储料连动油路配备                            
#define mPara_MoldSlidBlockMonOpt 416           //滑块监控配备                              0-配备；1-未配备
#define mPara_ChgEndNozForHold   417            //储料结束座进阀保持                           1-储料结束座进阀保持，以避免射退时漏料。
#define mPara_SuckBackNozForSel  418            //射退时座进阀选择                            1-射退时座进阀动作
#define mPara_RobotOutAlValid    419            //机械手输出点始终有效                          0-机械手不用时，"R.开模到位"、"R.开模中途"不输出 1-无论机械手是否使用,均会输出
#define mPara_SemiAutoChgAftEjeEn 420           //半自动二次储料允许                           0-禁止 1-允许
#define mPara_TieBarEn           421            //抽插拉杆允许                              应抽拉杆功能加
#define mPara_BrkInPres          422            //闸板进压力                               应抽拉杆功能加
#define mPara_BrkInFlow          423            //闸板进流量                               应抽拉杆功能加
#define mPara_BrkOutPres         424            //闸板退压力                               应抽拉杆功能加
#define mPara_BrkOutFlow         425            //闸板退流量                               应抽拉杆功能加
#define mPara_TieBarInPres       426            //拉杆进压力                               应抽拉杆功能加
#define mPara_TieBarInFlow       427            //拉杆进流量                               应抽拉杆功能加
#define mPara_TieBarOutPres      428            //拉杆退压力                               应抽拉杆功能加
#define mPara_TieBarOutFlow      429            //拉杆退流量                               应抽拉杆功能加
#define mPara_MoldOpenMinStroke  430            //开模行程下限                              应抽拉杆功能加
#define mPara_AutoMoldAdjMode    431            //自动模厚调整                              0-不用 1-使用，即0-自动调模用压力方式、1-自动调模用模厚尺或调模电眼
#define mPara_SGUnClsDisTieBar   432            //安全门未关禁止抽拉杆                          应抽拉杆功能加
#define mPara_MoldAdjLubrOpt     433            //调模润滑配备                              应调模润滑功能，0-未配备 1-配备
#define mPara_MoldAdjLubrSpaTi   434            //调模润滑间隔时间                            应调模润滑功能
#define mPara_MoldAdjLubrHldTi   435            //调模润滑保持时间                            应调模润滑功能
#define mPara_MoldAdjLubrAlarmTi 436            //调模润滑警报时间                            应调模润滑功能
#define mPara_MoldAdjLubrDateTime 437           //调模润滑时间                              最近一次调模润滑的时间，Byte3:年、Byte2：月、Byte1：日、Byte0：时
#define mPara_ToggleProtAlarmMode 438           //曲肘防护报警模式                            0-立即 1-开关模动作时报警
#define mPara_FixSafeGateBackOpt 439            //固定门配备                               大机后安全门有二个，一个活动、一个固定，此即固定门
#define mPara_PrgOutputOpt       440            //自由编程输出点配备                           自由编程输出点功能有效
#define mPara_SafePlugOpt        441            //安全插头配备                              1-配备
#define mPara_KWhM1AddrH         442            //电表1地址高字节                            RS485电表地址（共6字节）
#define mPara_KWhM1AddrL         443            //电表1地址低字节                            RS485电表地址（共6字节）
#define mPara_KWhM2AddrH         444            //电表2地址高字节                            RS485电表地址（共6字节）
#define mPara_KWhM2AddrL         445            //电表2地址低字节                            RS485电表地址（共6字节）
#define mPara_KWhM3AddrH         446            //电表3地址高字节                            RS485电表地址（共6字节）
#define mPara_KWhM3AddrL         447            //电表3地址低字节                            RS485电表地址（共6字节）
#define mPara_KWhMeter_Can485_CANPort 448       //电表CAN端口                             
#define mPara_MoldAdjLubrDly     449            //调模润滑延迟时间                            应调模润滑功能
#define mPara_MoldAdjLubrCnt     450            //调模润滑次数                              应调模润滑功能
#define mPara_MoldOpenMidEjeEn   451            //开模中途托模允许                            特殊程序：开模中途插入托模动作
#define mPara_CycOTOffAlarmLgt   452            //全程超时不亮警灯                            应特殊客户:三色灯中，如是循环超时警报，亮手动灯(不亮报警灯)
#define mPara_ManuModeDisAir     453            //手动时不吹气                              
#define mPara_SpcSafeGateMode    454            //特殊安全门模式                             天剑快速机：1-土耳其安全标准，半自动前门开允许中子、顶针和开模
#define mPara_FrontSGUnClsDisAllAct 455         //前安全门未关禁止所有动作                        天剑快速机：1-出口标准，前安全门未关禁止所有动作（马达、润滑除外）
#define mPara_NozGateUnClsDisAllAct 456         //前安射出防护未关禁止所有动作                      天剑快速机：1-出口标准，射出防护未关禁止所有动作（马达、润滑除外）
#define mPara_SpcSafeGateModeOpt 457            //特殊安全门模式配备                           天剑快速机：1-土耳其安全标准，半自动前门开允许中子、顶针和开模
#define mPara_InjFlowFeedSel     458            //注射流量闭环                              1-使用，即注射信号在注射1-10时有效输出
#define mPara_MoldOpenEndEnMoldAdj 459          //开模终才允许调模                            0-不用 1-使用
#define mPara_HydrSafeOutLog     460            //液压安全输出逻辑                            0-安全门关输出 1-安全门关不输出
#define mPara_SafeRlyErrOffMot   461            //安全继电器异常切马达                          CE安全标准:安全继电器异常切马达  1-切马达
#define mPara_InjMaxSpdSampTime  462            //注射峰速取样时间                            注射峰速取样周期
#define mPara_MotOnGrnLgt        463            //马达开亮绿灯                              马达开亮绿灯: 0-不亮 1-亮
#define mPara_NozRetMainPos      464            //座退维护位置                              天剑快速机：CE认证要求，到该位置座退限速
#define mPara_NozRetMainFlow     465            //座退维护流量                              天剑快速机：CE认证要求，到该位置座退限速
#define mPara_OilLessSnr2Log     466            //油位传感器2逻辑                            0-没有、1-正逻辑（ON-油位低,Off-油位正常）、2-负逻辑(ON-油位正常、OFF-油位低)
#define mPara_InjFlowFeedPresChkDly 467         //流量闭环压力转保压延时                         天剑快速机：流量闭环时经该延时检查压力，压力到转保压
#define mPara_InjFlowFeedPCDValid 468           //流量闭环压力转保压延时有效                       天剑快速机：Para_InjFlowFeedPresChkDly参数是否有效
#define mPara_MoldRstOpt         469            //模具复位配备                              0-未配备 1-配备
#define mPara_SDPID_StdAct       470            //普通动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_Eject        471            //托模动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_Inject       472            //注射动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_Charge       473            //储料动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_Mold         474            //开合模动作PID选择                          0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_MoldHP       475            //关模高压动作PID选择                         0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_MoldLP       476            //关模低压动作PID选择                         0-极速 1-快速 2-平稳 3-柔和
#define mPara_SDPID_MoldOpen     477            //开模动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define mPara_MDServoDrvAlarmPcsMode 478        //蒙德驱动器警报处理模式                         0-不处理 1-仅提示 2-转手动
#define mPara_MDServoDrvCANErrPcsMode 479       //蒙德驱动器CAN出错处理模                       0-不处理 1-仅提示 2-转手动
#define mPara_MDServoDrvCANPort  480            //蒙德伺服驱动器CAN端口                        0-关闭 1-CAN1、2-CAN2
#define mPara_MDServoDrv1Opt     481            //蒙德伺服驱动器1配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define mPara_MDServoDrv2Opt     482            //蒙德伺服驱动器2配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define mPara_MDServoDrv3Opt     483            //蒙德伺服驱动器3配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define mPara_MDServoDrv4Opt     484            //蒙德伺服驱动器4配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define mPara_MDServoDrv1Mode    485            //蒙德伺服驱动器1控制模式                        0-CAN控制模式 1-CAN监视模式
#define mPara_MDServoDrv2Mode    486            //蒙德伺服驱动器2控制模式                        0-CAN控制模式 1-CAN监视模式
#define mPara_MDServoDrv3Mode    487            //蒙德伺服驱动器3控制模式                        0-CAN控制模式 1-CAN监视模式
#define mPara_MDServoDrv4Mode    488            //蒙德伺服驱动器4控制模式                        0-CAN控制模式 1-CAN监视模式
#define mPara_HydProtChkMCTi     489            //关模中液压保险检查时                          关模进行中液压保险检查时间
#define mPara_OilSuppMotorCycCoolSel 490        //补油电机循环冷却选择                          补油电机循环冷却选择：0-关闭；1-开启；
#define mPara_OilSuppCycPres     491            //补油循环压力                              补油循环压力
#define mPara_OilSuppCycFlow     492            //补油循环流量                              补油循环流量
#define mPara_ChgMotorOilSuppSel 493            //电储料补油选择                             电储料补油选择：0-关闭；1-开启；
#define mPara_ChgMotorOilSuppPresMax 494        //电储料补油压力上限                           电储料补油压力上限
#define mPara_ChgMotorOilSuppFlowMax 495        //电储料补油流量上限                           电储料补油流量上限
#define mPara_ChgMotorOilSuppPres 496           //电储料补油压力                             电储料补油压力
#define mPara_ChgMotorOilSuppFlow 497           //电储料补油流量                             电储料补油流量
#define mPara_ChgGearTempSnrOpt  498            //电储料齿轮箱温度传感器配备                       电储料齿轮箱温度传感器配备：0-未配备；1-配备
#define mPara_ChgGearTempAlarm   499            //电储料齿轮箱报警温度                          电储料齿轮箱报警温度
#define mPara_DAC1LineType       500            //DAC1线性                              
#define mPara_DAC2LineType       501            //DAC2线性                              
#define mPara_DAC3LineType       502            //DAC3线性                              
#define mPara_DAC4LineType       503            //DAC4线性                              
#define mPara_DAC5LineType       504            //DAC5线性                              
#define mPara_DAC6LineType       505            //DAC6线性                              
#define mPara_DAC7LineType       506            //DAC7线性                              
#define mPara_DAC8LineType       507            //DAC8线性                              
#define mPara_Mach_508           508            //                                    
#define mPara_Mach_509           509            //                                    
#define mPara_Mach_510           510            //                                    
#define mPara_Mach_511           511            //                                    
#define mPara_DAC1PointNum       512            //DA通道1设置点数                           以下DA通道曲线:15点*2+1(点数/设置点/DA值)
#define mPara_DAC1SetPoint0      513            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC1SetPoint1      514            //设置点1                                
#define mPara_DAC1SetPoint2      515            //设置点2                                
#define mPara_DAC1SetPoint3      516            //设置点3                                
#define mPara_DAC1SetPoint4      517            //设置点4                                
#define mPara_DAC1SetPoint5      518            //设置点5                                
#define mPara_DAC1SetPoint6      519            //设置点6                                
#define mPara_DAC1SetPoint7      520            //设置点7                                
#define mPara_DAC1SetPoint8      521            //设置点8                                
#define mPara_DAC1SetPoint9      522            //设置点9                                
#define mPara_DAC1SetPoint10     523            //设置点10                               
#define mPara_DAC1SetPoint11     524            //设置点11                               
#define mPara_DAC1SetPoint12     525            //设置点12                               
#define mPara_DAC1SetPoint13     526            //设置点13                               
#define mPara_DAC1SetPoint14     527            //设置点14                               
#define mPara_DAC1DA0            528            //DA值0                                DA值，12位
#define mPara_DAC1DA1            529            //DA值1                                
#define mPara_DAC1DA2            530            //DA值2                                
#define mPara_DAC1DA3            531            //DA值3                                
#define mPara_DAC1DA4            532            //DA值4                                
#define mPara_DAC1DA5            533            //DA值5                                
#define mPara_DAC1DA6            534            //DA值6                                
#define mPara_DAC1DA7            535            //DA值7                                
#define mPara_DAC1DA8            536            //DA值8                                
#define mPara_DAC1DA9            537            //DA值9                                
#define mPara_DAC1DA10           538            //DA值10                               
#define mPara_DAC1DA11           539            //DA值11                               
#define mPara_DAC1DA12           540            //DA值12                               
#define mPara_DAC1DA13           541            //DA值13                               
#define mPara_DAC1DA14           542            //DA值14                               
#define mPara_DAC2PointNum       543            //DA通道2设置点数                           
#define mPara_DAC2SetPoint0      544            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC2SetPoint1      545            //设置点1                                
#define mPara_DAC2SetPoint2      546            //设置点2                                
#define mPara_DAC2SetPoint3      547            //设置点3                                
#define mPara_DAC2SetPoint4      548            //设置点4                                
#define mPara_DAC2SetPoint5      549            //设置点5                                
#define mPara_DAC2SetPoint6      550            //设置点6                                
#define mPara_DAC2SetPoint7      551            //设置点7                                
#define mPara_DAC2SetPoint8      552            //设置点8                                
#define mPara_DAC2SetPoint9      553            //设置点9                                
#define mPara_DAC2SetPoint10     554            //设置点10                               
#define mPara_DAC2SetPoint11     555            //设置点11                               
#define mPara_DAC2SetPoint12     556            //设置点12                               
#define mPara_DAC2SetPoint13     557            //设置点13                               
#define mPara_DAC2SetPoint14     558            //设置点14                               
#define mPara_DAC2DA0            559            //DA值0                                DA值，12位
#define mPara_DAC2DA1            560            //DA值1                                
#define mPara_DAC2DA2            561            //DA值2                                
#define mPara_DAC2DA3            562            //DA值3                                
#define mPara_DAC2DA4            563            //DA值4                                
#define mPara_DAC2DA5            564            //DA值5                                
#define mPara_DAC2DA6            565            //DA值6                                
#define mPara_DAC2DA7            566            //DA值7                                
#define mPara_DAC2DA8            567            //DA值8                                
#define mPara_DAC2DA9            568            //DA值9                                
#define mPara_DAC2DA10           569            //DA值10                               
#define mPara_DAC2DA11           570            //DA值11                               
#define mPara_DAC2DA12           571            //DA值12                               
#define mPara_DAC2DA13           572            //DA值13                               
#define mPara_DAC2DA14           573            //DA值14                               
#define mPara_DAC3PointNum       574            //DA通道3设置点数                           
#define mPara_DAC3SetPoint0      575            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC3SetPoint1      576            //设置点1                                
#define mPara_DAC3SetPoint2      577            //设置点2                                
#define mPara_DAC3SetPoint3      578            //设置点3                                
#define mPara_DAC3SetPoint4      579            //设置点4                                
#define mPara_DAC3SetPoint5      580            //设置点5                                
#define mPara_DAC3SetPoint6      581            //设置点6                                
#define mPara_DAC3SetPoint7      582            //设置点7                                
#define mPara_DAC3SetPoint8      583            //设置点8                                
#define mPara_DAC3SetPoint9      584            //设置点9                                
#define mPara_DAC3SetPoint10     585            //设置点10                               
#define mPara_DAC3SetPoint11     586            //设置点11                               
#define mPara_DAC3SetPoint12     587            //设置点12                               
#define mPara_DAC3SetPoint13     588            //设置点13                               
#define mPara_DAC3SetPoint14     589            //设置点14                               
#define mPara_DAC3DA0            590            //DA值0                                DA值，12位
#define mPara_DAC3DA1            591            //DA值1                                
#define mPara_DAC3DA2            592            //DA值2                                
#define mPara_DAC3DA3            593            //DA值3                                
#define mPara_DAC3DA4            594            //DA值4                                
#define mPara_DAC3DA5            595            //DA值5                                
#define mPara_DAC3DA6            596            //DA值6                                
#define mPara_DAC3DA7            597            //DA值7                                
#define mPara_DAC3DA8            598            //DA值8                                
#define mPara_DAC3DA9            599            //DA值9                                
#define mPara_DAC3DA10           600            //DA值10                               
#define mPara_DAC3DA11           601            //DA值11                               
#define mPara_DAC3DA12           602            //DA值12                               
#define mPara_DAC3DA13           603            //DA值13                               
#define mPara_DAC3DA14           604            //DA值14                               
#define mPara_DAC4PointNum       605            //DA通道4设置点数                           
#define mPara_DAC4SetPoint0      606            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC4SetPoint1      607            //设置点1                                
#define mPara_DAC4SetPoint2      608            //设置点2                                
#define mPara_DAC4SetPoint3      609            //设置点3                                
#define mPara_DAC4SetPoint4      610            //设置点4                                
#define mPara_DAC4SetPoint5      611            //设置点5                                
#define mPara_DAC4SetPoint6      612            //设置点6                                
#define mPara_DAC4SetPoint7      613            //设置点7                                
#define mPara_DAC4SetPoint8      614            //设置点8                                
#define mPara_DAC4SetPoint9      615            //设置点9                                
#define mPara_DAC4SetPoint10     616            //设置点10                               
#define mPara_DAC4SetPoint11     617            //设置点11                               
#define mPara_DAC4SetPoint12     618            //设置点12                               
#define mPara_DAC4SetPoint13     619            //设置点13                               
#define mPara_DAC4SetPoint14     620            //设置点14                               
#define mPara_DAC4DA0            621            //DA值0                                DA值，12位
#define mPara_DAC4DA1            622            //DA值1                                
#define mPara_DAC4DA2            623            //DA值2                                
#define mPara_DAC4DA3            624            //DA值3                                
#define mPara_DAC4DA4            625            //DA值4                                
#define mPara_DAC4DA5            626            //DA值5                                
#define mPara_DAC4DA6            627            //DA值6                                
#define mPara_DAC4DA7            628            //DA值7                                
#define mPara_DAC4DA8            629            //DA值8                                
#define mPara_DAC4DA9            630            //DA值9                                
#define mPara_DAC4DA10           631            //DA值10                               
#define mPara_DAC4DA11           632            //DA值11                               
#define mPara_DAC4DA12           633            //DA值12                               
#define mPara_DAC4DA13           634            //DA值13                               
#define mPara_DAC4DA14           635            //DA值14                               
#define mPara_DAC5PointNum       636            //DA通道5设置点数                           
#define mPara_DAC5SetPoint0      637            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC5SetPoint1      638            //设置点1                                
#define mPara_DAC5SetPoint2      639            //设置点2                                
#define mPara_DAC5SetPoint3      640            //设置点3                                
#define mPara_DAC5SetPoint4      641            //设置点4                                
#define mPara_DAC5SetPoint5      642            //设置点5                                
#define mPara_DAC5SetPoint6      643            //设置点6                                
#define mPara_DAC5SetPoint7      644            //设置点7                                
#define mPara_DAC5SetPoint8      645            //设置点8                                
#define mPara_DAC5SetPoint9      646            //设置点9                                
#define mPara_DAC5SetPoint10     647            //设置点10                               
#define mPara_DAC5SetPoint11     648            //设置点11                               
#define mPara_DAC5SetPoint12     649            //设置点12                               
#define mPara_DAC5SetPoint13     650            //设置点13                               
#define mPara_DAC5SetPoint14     651            //设置点14                               
#define mPara_DAC5DA0            652            //DA值0                                DA值，12位
#define mPara_DAC5DA1            653            //DA值1                                
#define mPara_DAC5DA2            654            //DA值2                                
#define mPara_DAC5DA3            655            //DA值3                                
#define mPara_DAC5DA4            656            //DA值4                                
#define mPara_DAC5DA5            657            //DA值5                                
#define mPara_DAC5DA6            658            //DA值6                                
#define mPara_DAC5DA7            659            //DA值7                                
#define mPara_DAC5DA8            660            //DA值8                                
#define mPara_DAC5DA9            661            //DA值9                                
#define mPara_DAC5DA10           662            //DA值10                               
#define mPara_DAC5DA11           663            //DA值11                               
#define mPara_DAC5DA12           664            //DA值12                               
#define mPara_DAC5DA13           665            //DA值13                               
#define mPara_DAC5DA14           666            //DA值14                               
#define mPara_DAC6PointNum       667            //DA通道6设置点数                           
#define mPara_DAC6SetPoint0      668            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC6SetPoint1      669            //设置点1                                
#define mPara_DAC6SetPoint2      670            //设置点2                                
#define mPara_DAC6SetPoint3      671            //设置点3                                
#define mPara_DAC6SetPoint4      672            //设置点4                                
#define mPara_DAC6SetPoint5      673            //设置点5                                
#define mPara_DAC6SetPoint6      674            //设置点6                                
#define mPara_DAC6SetPoint7      675            //设置点7                                
#define mPara_DAC6SetPoint8      676            //设置点8                                
#define mPara_DAC6SetPoint9      677            //设置点9                                
#define mPara_DAC6SetPoint10     678            //设置点10                               
#define mPara_DAC6SetPoint11     679            //设置点11                               
#define mPara_DAC6SetPoint12     680            //设置点12                               
#define mPara_DAC6SetPoint13     681            //设置点13                               
#define mPara_DAC6SetPoint14     682            //设置点14                               
#define mPara_DAC6DA0            683            //DA值0                                DA值，12位
#define mPara_DAC6DA1            684            //DA值1                                
#define mPara_DAC6DA2            685            //DA值2                                
#define mPara_DAC6DA3            686            //DA值3                                
#define mPara_DAC6DA4            687            //DA值4                                
#define mPara_DAC6DA5            688            //DA值5                                
#define mPara_DAC6DA6            689            //DA值6                                
#define mPara_DAC6DA7            690            //DA值7                                
#define mPara_DAC6DA8            691            //DA值8                                
#define mPara_DAC6DA9            692            //DA值9                                
#define mPara_DAC6DA10           693            //DA值10                               
#define mPara_DAC6DA11           694            //DA值11                               
#define mPara_DAC6DA12           695            //DA值12                               
#define mPara_DAC6DA13           696            //DA值13                               
#define mPara_DAC6DA14           697            //DA值14                               
#define mPara_DAC7PointNum       698            //DA通道7设置点数                           
#define mPara_DAC7SetPoint0      699            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC7SetPoint1      700            //设置点1                                
#define mPara_DAC7SetPoint2      701            //设置点2                                
#define mPara_DAC7SetPoint3      702            //设置点3                                
#define mPara_DAC7SetPoint4      703            //设置点4                                
#define mPara_DAC7SetPoint5      704            //设置点5                                
#define mPara_DAC7SetPoint6      705            //设置点6                                
#define mPara_DAC7SetPoint7      706            //设置点7                                
#define mPara_DAC7SetPoint8      707            //设置点8                                
#define mPara_DAC7SetPoint9      708            //设置点9                                
#define mPara_DAC7SetPoint10     709            //设置点10                               
#define mPara_DAC7SetPoint11     710            //设置点11                               
#define mPara_DAC7SetPoint12     711            //设置点12                               
#define mPara_DAC7SetPoint13     712            //设置点13                               
#define mPara_DAC7SetPoint14     713            //设置点14                               
#define mPara_DAC7DA0            714            //DA值0                                DA值，12位
#define mPara_DAC7DA1            715            //DA值1                                
#define mPara_DAC7DA2            716            //DA值2                                
#define mPara_DAC7DA3            717            //DA值3                                
#define mPara_DAC7DA4            718            //DA值4                                
#define mPara_DAC7DA5            719            //DA值5                                
#define mPara_DAC7DA6            720            //DA值6                                
#define mPara_DAC7DA7            721            //DA值7                                
#define mPara_DAC7DA8            722            //DA值8                                
#define mPara_DAC7DA9            723            //DA值9                                
#define mPara_DAC7DA10           724            //DA值10                               
#define mPara_DAC7DA11           725            //DA值11                               
#define mPara_DAC7DA12           726            //DA值12                               
#define mPara_DAC7DA13           727            //DA值13                               
#define mPara_DAC7DA14           728            //DA值14                               
#define mPara_DAC8PointNum       729            //DA通道8设置点数                           
#define mPara_DAC8SetPoint0      730            //设置点0                                比例值，即n‰，设置点0固定为0‰
#define mPara_DAC8SetPoint1      731            //设置点1                                
#define mPara_DAC8SetPoint2      732            //设置点2                                
#define mPara_DAC8SetPoint3      733            //设置点3                                
#define mPara_DAC8SetPoint4      734            //设置点4                                
#define mPara_DAC8SetPoint5      735            //设置点5                                
#define mPara_DAC8SetPoint6      736            //设置点6                                
#define mPara_DAC8SetPoint7      737            //设置点7                                
#define mPara_DAC8SetPoint8      738            //设置点8                                
#define mPara_DAC8SetPoint9      739            //设置点9                                
#define mPara_DAC8SetPoint10     740            //设置点10                               
#define mPara_DAC8SetPoint11     741            //设置点11                               
#define mPara_DAC8SetPoint12     742            //设置点12                               
#define mPara_DAC8SetPoint13     743            //设置点13                               
#define mPara_DAC8SetPoint14     744            //设置点14                               
#define mPara_DAC8DA0            745            //DA值0                                DA值，12位
#define mPara_DAC8DA1            746            //DA值1                                
#define mPara_DAC8DA2            747            //DA值2                                
#define mPara_DAC8DA3            748            //DA值3                                
#define mPara_DAC8DA4            749            //DA值4                                
#define mPara_DAC8DA5            750            //DA值5                                
#define mPara_DAC8DA6            751            //DA值6                                
#define mPara_DAC8DA7            752            //DA值7                                
#define mPara_DAC8DA8            753            //DA值8                                
#define mPara_DAC8DA9            754            //DA值9                                
#define mPara_DAC8DA10           755            //DA值10                               
#define mPara_DAC8DA11           756            //DA值11                               
#define mPara_DAC8DA12           757            //DA值12                               
#define mPara_DAC8DA13           758            //DA值13                               
#define mPara_DAC8DA14           759            //DA值14                               
#define mPara_Mach_760           760            //                                    
#define mPara_Mach_761           761            //                                    
#define mPara_Mach_762           762            //                                    
#define mPara_Mach_763           763            //                                    
#define mPara_Mach_764           764            //                                    
#define mPara_Mach_765           765            //                                    
#define mPara_MoldCylPosTabNum   766            //模块油缸位置表点数                           油缸-模块转换表：128点*4字节*2(油缸、模板)、U32类型
#define mPara_CylPosP0           767            //油缸位置点0                              
#define mPara_CylPosP1           768            //油缸位置点1                              
#define mPara_CylPosP2           769            //油缸位置点2                              
#define mPara_CylPosP3           770            //油缸位置点3                              
#define mPara_CylPosP4           771            //油缸位置点4                              
#define mPara_CylPosP5           772            //油缸位置点5                              
#define mPara_CylPosP6           773            //油缸位置点6                              
#define mPara_CylPosP7           774            //油缸位置点7                              
#define mPara_CylPosP8           775            //油缸位置点8                              
#define mPara_CylPosP9           776            //油缸位置点9                              
#define mPara_CylPosP10          777            //油缸位置点10                             
#define mPara_CylPosP11          778            //油缸位置点11                             
#define mPara_CylPosP12          779            //油缸位置点12                             
#define mPara_CylPosP13          780            //油缸位置点13                             
#define mPara_CylPosP14          781            //油缸位置点14                             
#define mPara_CylPosP15          782            //油缸位置点15                             
#define mPara_CylPosP16          783            //油缸位置点16                             
#define mPara_CylPosP17          784            //油缸位置点17                             
#define mPara_CylPosP18          785            //油缸位置点18                             
#define mPara_CylPosP19          786            //油缸位置点19                             
#define mPara_CylPosP20          787            //油缸位置点20                             
#define mPara_CylPosP21          788            //油缸位置点21                             
#define mPara_CylPosP22          789            //油缸位置点22                             
#define mPara_CylPosP23          790            //油缸位置点23                             
#define mPara_CylPosP24          791            //油缸位置点24                             
#define mPara_CylPosP25          792            //油缸位置点25                             
#define mPara_CylPosP26          793            //油缸位置点26                             
#define mPara_CylPosP27          794            //油缸位置点27                             
#define mPara_CylPosP28          795            //油缸位置点28                             
#define mPara_CylPosP29          796            //油缸位置点29                             
#define mPara_CylPosP30          797            //油缸位置点30                             
#define mPara_CylPosP31          798            //油缸位置点31                             
#define mPara_CylPosP32          799            //油缸位置点32                             
#define mPara_CylPosP33          800            //油缸位置点33                             
#define mPara_CylPosP34          801            //油缸位置点34                             
#define mPara_CylPosP35          802            //油缸位置点35                             
#define mPara_CylPosP36          803            //油缸位置点36                             
#define mPara_CylPosP37          804            //油缸位置点37                             
#define mPara_CylPosP38          805            //油缸位置点38                             
#define mPara_CylPosP39          806            //油缸位置点39                             
#define mPara_CylPosP40          807            //油缸位置点40                             
#define mPara_CylPosP41          808            //油缸位置点41                             
#define mPara_CylPosP42          809            //油缸位置点42                             
#define mPara_CylPosP43          810            //油缸位置点43                             
#define mPara_CylPosP44          811            //油缸位置点44                             
#define mPara_CylPosP45          812            //油缸位置点45                             
#define mPara_CylPosP46          813            //油缸位置点46                             
#define mPara_CylPosP47          814            //油缸位置点47                             
#define mPara_CylPosP48          815            //油缸位置点48                             
#define mPara_CylPosP49          816            //油缸位置点49                             
#define mPara_CylPosP50          817            //油缸位置点50                             
#define mPara_CylPosP51          818            //油缸位置点51                             
#define mPara_CylPosP52          819            //油缸位置点52                             
#define mPara_CylPosP53          820            //油缸位置点53                             
#define mPara_CylPosP54          821            //油缸位置点54                             
#define mPara_CylPosP55          822            //油缸位置点55                             
#define mPara_CylPosP56          823            //油缸位置点56                             
#define mPara_CylPosP57          824            //油缸位置点57                             
#define mPara_CylPosP58          825            //油缸位置点58                             
#define mPara_CylPosP59          826            //油缸位置点59                             
#define mPara_CylPosP60          827            //油缸位置点60                             
#define mPara_CylPosP61          828            //油缸位置点61                             
#define mPara_CylPosP62          829            //油缸位置点62                             
#define mPara_CylPosP63          830            //油缸位置点63                             
#define mPara_CylPosP64          831            //油缸位置点64                             
#define mPara_CylPosP65          832            //油缸位置点65                             
#define mPara_CylPosP66          833            //油缸位置点66                             
#define mPara_CylPosP67          834            //油缸位置点67                             
#define mPara_CylPosP68          835            //油缸位置点68                             
#define mPara_CylPosP69          836            //油缸位置点69                             
#define mPara_CylPosP70          837            //油缸位置点70                             
#define mPara_CylPosP71          838            //油缸位置点71                             
#define mPara_CylPosP72          839            //油缸位置点72                             
#define mPara_CylPosP73          840            //油缸位置点73                             
#define mPara_CylPosP74          841            //油缸位置点74                             
#define mPara_CylPosP75          842            //油缸位置点75                             
#define mPara_CylPosP76          843            //油缸位置点76                             
#define mPara_CylPosP77          844            //油缸位置点77                             
#define mPara_CylPosP78          845            //油缸位置点78                             
#define mPara_CylPosP79          846            //油缸位置点79                             
#define mPara_CylPosP80          847            //油缸位置点80                             
#define mPara_CylPosP81          848            //油缸位置点81                             
#define mPara_CylPosP82          849            //油缸位置点82                             
#define mPara_CylPosP83          850            //油缸位置点83                             
#define mPara_CylPosP84          851            //油缸位置点84                             
#define mPara_CylPosP85          852            //油缸位置点85                             
#define mPara_CylPosP86          853            //油缸位置点86                             
#define mPara_CylPosP87          854            //油缸位置点87                             
#define mPara_CylPosP88          855            //油缸位置点88                             
#define mPara_CylPosP89          856            //油缸位置点89                             
#define mPara_CylPosP90          857            //油缸位置点90                             
#define mPara_CylPosP91          858            //油缸位置点91                             
#define mPara_CylPosP92          859            //油缸位置点92                             
#define mPara_CylPosP93          860            //油缸位置点93                             
#define mPara_CylPosP94          861            //油缸位置点94                             
#define mPara_CylPosP95          862            //油缸位置点95                             
#define mPara_CylPosP96          863            //油缸位置点96                             
#define mPara_CylPosP97          864            //油缸位置点97                             
#define mPara_CylPosP98          865            //油缸位置点98                             
#define mPara_CylPosP99          866            //油缸位置点99                             
#define mPara_CylPosP100         867            //油缸位置点100                            
#define mPara_CylPosP101         868            //油缸位置点101                            
#define mPara_CylPosP102         869            //油缸位置点102                            
#define mPara_CylPosP103         870            //油缸位置点103                            
#define mPara_CylPosP104         871            //油缸位置点104                            
#define mPara_CylPosP105         872            //油缸位置点105                            
#define mPara_CylPosP106         873            //油缸位置点106                            
#define mPara_CylPosP107         874            //油缸位置点107                            
#define mPara_CylPosP108         875            //油缸位置点108                            
#define mPara_CylPosP109         876            //油缸位置点109                            
#define mPara_CylPosP110         877            //油缸位置点110                            
#define mPara_CylPosP111         878            //油缸位置点111                            
#define mPara_CylPosP112         879            //油缸位置点112                            
#define mPara_CylPosP113         880            //油缸位置点113                            
#define mPara_CylPosP114         881            //油缸位置点114                            
#define mPara_CylPosP115         882            //油缸位置点115                            
#define mPara_CylPosP116         883            //油缸位置点116                            
#define mPara_CylPosP117         884            //油缸位置点117                            
#define mPara_CylPosP118         885            //油缸位置点118                            
#define mPara_CylPosP119         886            //油缸位置点119                            
#define mPara_CylPosP120         887            //油缸位置点120                            
#define mPara_CylPosP121         888            //油缸位置点121                            
#define mPara_CylPosP122         889            //油缸位置点122                            
#define mPara_CylPosP123         890            //油缸位置点123                            
#define mPara_CylPosP124         891            //油缸位置点124                            
#define mPara_CylPosP125         892            //油缸位置点125                            
#define mPara_CylPosP126         893            //油缸位置点126                            
#define mPara_CylPosP127         894            //油缸位置点127                            
#define mPara_CylPosP128         895            //油缸位置点128                            
#define mPara_MoldPosP0          896            //模板位置点0                              
#define mPara_MoldPosP1          897            //模板位置点1                              
#define mPara_MoldPosP2          898            //模板位置点2                              
#define mPara_MoldPosP3          899            //模板位置点3                              
#define mPara_MoldPosP4          900            //模板位置点4                              
#define mPara_MoldPosP5          901            //模板位置点5                              
#define mPara_MoldPosP6          902            //模板位置点6                              
#define mPara_MoldPosP7          903            //模板位置点7                              
#define mPara_MoldPosP8          904            //模板位置点8                              
#define mPara_MoldPosP9          905            //模板位置点9                              
#define mPara_MoldPosP10         906            //模板位置点10                             
#define mPara_MoldPosP11         907            //模板位置点11                             
#define mPara_MoldPosP12         908            //模板位置点12                             
#define mPara_MoldPosP13         909            //模板位置点13                             
#define mPara_MoldPosP14         910            //模板位置点14                             
#define mPara_MoldPosP15         911            //模板位置点15                             
#define mPara_MoldPosP16         912            //模板位置点16                             
#define mPara_MoldPosP17         913            //模板位置点17                             
#define mPara_MoldPosP18         914            //模板位置点18                             
#define mPara_MoldPosP19         915            //模板位置点19                             
#define mPara_MoldPosP20         916            //模板位置点20                             
#define mPara_MoldPosP21         917            //模板位置点21                             
#define mPara_MoldPosP22         918            //模板位置点22                             
#define mPara_MoldPosP23         919            //模板位置点23                             
#define mPara_MoldPosP24         920            //模板位置点24                             
#define mPara_MoldPosP25         921            //模板位置点25                             
#define mPara_MoldPosP26         922            //模板位置点26                             
#define mPara_MoldPosP27         923            //模板位置点27                             
#define mPara_MoldPosP28         924            //模板位置点28                             
#define mPara_MoldPosP29         925            //模板位置点29                             
#define mPara_MoldPosP30         926            //模板位置点30                             
#define mPara_MoldPosP31         927            //模板位置点31                             
#define mPara_MoldPosP32         928            //模板位置点32                             
#define mPara_MoldPosP33         929            //模板位置点33                             
#define mPara_MoldPosP34         930            //模板位置点34                             
#define mPara_MoldPosP35         931            //模板位置点35                             
#define mPara_MoldPosP36         932            //模板位置点36                             
#define mPara_MoldPosP37         933            //模板位置点37                             
#define mPara_MoldPosP38         934            //模板位置点38                             
#define mPara_MoldPosP39         935            //模板位置点39                             
#define mPara_MoldPosP40         936            //模板位置点40                             
#define mPara_MoldPosP41         937            //模板位置点41                             
#define mPara_MoldPosP42         938            //模板位置点42                             
#define mPara_MoldPosP43         939            //模板位置点43                             
#define mPara_MoldPosP44         940            //模板位置点44                             
#define mPara_MoldPosP45         941            //模板位置点45                             
#define mPara_MoldPosP46         942            //模板位置点46                             
#define mPara_MoldPosP47         943            //模板位置点47                             
#define mPara_MoldPosP48         944            //模板位置点48                             
#define mPara_MoldPosP49         945            //模板位置点49                             
#define mPara_MoldPosP50         946            //模板位置点50                             
#define mPara_MoldPosP51         947            //模板位置点51                             
#define mPara_MoldPosP52         948            //模板位置点52                             
#define mPara_MoldPosP53         949            //模板位置点53                             
#define mPara_MoldPosP54         950            //模板位置点54                             
#define mPara_MoldPosP55         951            //模板位置点55                             
#define mPara_MoldPosP56         952            //模板位置点56                             
#define mPara_MoldPosP57         953            //模板位置点57                             
#define mPara_MoldPosP58         954            //模板位置点58                             
#define mPara_MoldPosP59         955            //模板位置点59                             
#define mPara_MoldPosP60         956            //模板位置点60                             
#define mPara_MoldPosP61         957            //模板位置点61                             
#define mPara_MoldPosP62         958            //模板位置点62                             
#define mPara_MoldPosP63         959            //模板位置点63                             
#define mPara_MoldPosP64         960            //模板位置点64                             
#define mPara_MoldPosP65         961            //模板位置点65                             
#define mPara_MoldPosP66         962            //模板位置点66                             
#define mPara_MoldPosP67         963            //模板位置点67                             
#define mPara_MoldPosP68         964            //模板位置点68                             
#define mPara_MoldPosP69         965            //模板位置点69                             
#define mPara_MoldPosP70         966            //模板位置点70                             
#define mPara_MoldPosP71         967            //模板位置点71                             
#define mPara_MoldPosP72         968            //模板位置点72                             
#define mPara_MoldPosP73         969            //模板位置点73                             
#define mPara_MoldPosP74         970            //模板位置点74                             
#define mPara_MoldPosP75         971            //模板位置点75                             
#define mPara_MoldPosP76         972            //模板位置点76                             
#define mPara_MoldPosP77         973            //模板位置点77                             
#define mPara_MoldPosP78         974            //模板位置点78                             
#define mPara_MoldPosP79         975            //模板位置点79                             
#define mPara_MoldPosP80         976            //模板位置点80                             
#define mPara_MoldPosP81         977            //模板位置点81                             
#define mPara_MoldPosP82         978            //模板位置点82                             
#define mPara_MoldPosP83         979            //模板位置点83                             
#define mPara_MoldPosP84         980            //模板位置点84                             
#define mPara_MoldPosP85         981            //模板位置点85                             
#define mPara_MoldPosP86         982            //模板位置点86                             
#define mPara_MoldPosP87         983            //模板位置点87                             
#define mPara_MoldPosP88         984            //模板位置点88                             
#define mPara_MoldPosP89         985            //模板位置点89                             
#define mPara_MoldPosP90         986            //模板位置点90                             
#define mPara_MoldPosP91         987            //模板位置点91                             
#define mPara_MoldPosP92         988            //模板位置点92                             
#define mPara_MoldPosP93         989            //模板位置点93                             
#define mPara_MoldPosP94         990            //模板位置点94                             
#define mPara_MoldPosP95         991            //模板位置点95                             
#define mPara_MoldPosP96         992            //模板位置点96                             
#define mPara_MoldPosP97         993            //模板位置点97                             
#define mPara_MoldPosP98         994            //模板位置点98                             
#define mPara_MoldPosP99         995            //模板位置点99                             
#define mPara_MoldPosP100        996            //模板位置点100                            
#define mPara_MoldPosP101        997            //模板位置点101                            
#define mPara_MoldPosP102        998            //模板位置点102                            
#define mPara_MoldPosP103        999            //模板位置点103                            
#define mPara_MoldPosP104        1000           //模板位置点104                            
#define mPara_MoldPosP105        1001           //模板位置点105                            
#define mPara_MoldPosP106        1002           //模板位置点106                            
#define mPara_MoldPosP107        1003           //模板位置点107                            
#define mPara_MoldPosP108        1004           //模板位置点108                            
#define mPara_MoldPosP109        1005           //模板位置点109                            
#define mPara_MoldPosP110        1006           //模板位置点110                            
#define mPara_MoldPosP111        1007           //模板位置点111                            
#define mPara_MoldPosP112        1008           //模板位置点112                            
#define mPara_MoldPosP113        1009           //模板位置点113                            
#define mPara_MoldPosP114        1010           //模板位置点114                            
#define mPara_MoldPosP115        1011           //模板位置点115                            
#define mPara_MoldPosP116        1012           //模板位置点116                            
#define mPara_MoldPosP117        1013           //模板位置点117                            
#define mPara_MoldPosP118        1014           //模板位置点118                            
#define mPara_MoldPosP119        1015           //模板位置点119                            
#define mPara_MoldPosP120        1016           //模板位置点120                            
#define mPara_MoldPosP121        1017           //模板位置点121                            
#define mPara_MoldPosP122        1018           //模板位置点122                            
#define mPara_MoldPosP123        1019           //模板位置点123                            
#define mPara_MoldPosP124        1020           //模板位置点124                            
#define mPara_MoldPosP125        1021           //模板位置点125                            
#define mPara_MoldPosP126        1022           //模板位置点126                            
#define mPara_MoldPosP127        1023           //模板位置点127                            
#define mPara_MoldClsInPosUseCyl 1024           //关模算法输入位置选择                          使用油缸或模板位置进行开模算法:0-模板；1-油缸
#define mPara_MoldOpenInPosUseCyl 1025          //开模算法输入位置选择                          使用油缸或模板位置进行开模算法:0-模板；1-油缸
#define mPara_Mach_1026          1026           //                                    
#define mPara_Mach_1027          1027           //                                    
#define mPara_Mach_1028          1028           //                                    
#define mPara_Mach_1029          1029           //                                    
#define mPara_MoldClsAdjPres     1030           //关模调模压力                              
#define mPara_MoldClsAdjFlow     1031           //关模调模流量                              
#define mPara_MoldCls1PresRamp   1032           //关模1段压力斜率                            关模起始压力斜率
#define mPara_MoldCls1FlowRamp   1033           //关模1段流量斜率                            关模起始流量斜率
#define mPara_MoldCls2PresRamp   1034           //关模2段压力斜率                            
#define mPara_MoldCls2FlowRamp   1035           //关模2段流量斜率                            
#define mPara_MoldCls3PresRamp   1036           //关模3段压力斜率                            
#define mPara_MoldCls3FlowRamp   1037           //关模3段流量斜率                            
#define mPara_MoldClsLPPresRamp  1038           //关模低压压力斜率                            
#define mPara_MoldClsLPFlowRamp  1039           //关模低压流量斜率                            
#define mPara_MoldClsHPPresRamp  1040           //关模高压压力斜率                            
#define mPara_MoldClsHPFlowRamp  1041           //关模高压流量斜率                            
#define mPara_MoldClsEndPresRamp 1042           //关模结束压力斜率                            
#define mPara_MoldClsEndFlowRamp 1043           //关模结束压力斜率                            
#define mPara_Mach_1044          1044           //                                    
#define mPara_Mach_1045          1045           //                                    
#define mPara_MoldClsEndDly      1046           //关模完延迟计时                             动作完动作延时结束
#define mPara_MoldClsDVOffDly    1047           //关模方向阀关延时                            动作后方向阀延时关闭
#define mPara_MoldClsPVOnDly     1048           //关模比例阀开延时                            动作前比例阀延时输出
#define mPara_MoldClsDiffValOnDly 1049          //差动阀延迟开计时                            差动阀经该延时后打开
#define mPara_MoldClsDiffValOffDly 1050         //差动阀延迟关计时                            差动阀经该延时后关闭
#define mPara_MoldClsLPValOnDly  1051           //关模低压阀延迟开计时                          关模低压阀经此延时后动作
#define mPara_MoldClsHPValOnDly  1052           //关模高压阀延迟开计时                          关模高压阀经此延时后动作
#define mPara_Mach_1053          1053           //                                    
#define mPara_MoldClsHPHoldTi    1054           //关模高压保持计时                            
#define mPara_MoldClsLPDiffValOn 1055           //低压模保差动阀开                            低压锁模时打开差动阀
#define mPara_MCHPNozForValOn    1056           //关模高压允许座进选择                          0-不用 1-使用
#define mPara_MoldClsMidHoldTi   1057           //关模中途保持时间                            关模中途时间
#define mPara_MoldClsStartTi     1058           //关模起始段时间                             关模起始段时间，关模起始段是时间控制的最先一段关模
#define mPara_MoldClsStartPres   1059           //关模起始段压力                             关模起始段压力
#define mPara_MoldClsStartFlow   1060           //关模起始段流量                             关模起始段压力
#define mPara_ValMotOpt          1061           //阀门电机配备                              有阀门在输出，打开阀门电机。1-此功能配备；0-此功能未配备
#define mPara_MoldClsMidPres     1062           //关模中途压力                              关模中途压力
#define mPara_MoldClsMidFlow     1063           //关模中途流量                              关模中途流量
#define mPara_MoldOpenAlgSel     1064           //开模算法选择                              0-默认，无算法；1-位置斜率；2-保留
#define mPara_MOAlg1_Pos         1065           //算法1开模距离                             
#define mPara_MOAlgEndAcceSel    1066           //智能开模功能                              0-不用 1使用
#define mPara_MOAlg1_BaseFlow    1067           //算法1开模底流                             
#define mPara_MoldOpenAdjPres    1068           //开模调模压力                              
#define mPara_MoldOpenAdjFlow    1069           //开模调模流量                              
#define mPara_MoldOpen1PresRamp  1070           //开模1段压力斜率                            开模起始压力斜率
#define mPara_MoldOpen1FlowRamp  1071           //开模1段流量斜率                            开模起始流量斜率
#define mPara_MoldOpen2PresRamp  1072           //开模2段压力斜率                            
#define mPara_MoldOpen2FlowRamp  1073           //开模2段流量斜率                            
#define mPara_MoldOpen3PresRamp  1074           //开模3段压力斜率                            
#define mPara_MoldOpen3FlowRamp  1075           //开模3段流量斜率                            
#define mPara_MoldOpen4PresRamp  1076           //开模4压力斜率                             
#define mPara_MoldOpen4FlowRamp  1077           //开模4流量斜率                             
#define mPara_MoldOpen5PresRamp  1078           //开模5压力斜率                             
#define mPara_MoldOpen5FlowRamp  1079           //开模5流量斜率                             
#define mPara_MoldOpenEndPresRamp 1080          //开模结束压力斜率                            
#define mPara_MoldOpenEndFlowRamp 1081          //开模结束压力斜率                            
#define mPara_Mach_1082          1082           //                                    
#define mPara_Mach_1083          1083           //                                    
#define mPara_MoldOpenEndDly     1084           //开模完延迟计时                             动作完动作延时结束
#define mPara_MoldOpenDVOffDly   1085           //开模方向阀关延时                            动作后方向阀延时关闭
#define mPara_MoldOpenPVOnDly    1086           //开模比例阀开延时                            动作前比例阀延时输出
#define mPara_MoldOpen1LPValOnDly 1087          //开模一慢低压阀延迟开                          开模一慢低压阀经此延时后动作
#define mPara_MoldOpen1LPValOnTi 1088           //开模一慢低压阀动作时间                         开模一慢低压阀动作时间
#define mPara_MoldOpen1SlowValOnDly 1089        //开模一慢慢速阀延迟开                          用于CH机，一慢时慢速阀经此延时动作
#define mPara_MoldOpen5SlowValOnDly 1090        //开模二慢慢速阀延迟开                          用于CH机，二慢时慢速阀经此延时动作
#define mPara_MoldOpenFastValOnDly 1091         //开模快速差动阀延迟开                          用于CH机，快速差动阀经此延时动作
#define mPara_Mach_1092          1092           //                                    
#define mPara_MoldOpenEffArea    1093           //开模位置有效区                             过“开终位置-位置有效区”即认为开模到位
#define mPara_MoldOpenMidPres    1094           //开模中途压力                              开模中途压力
#define mPara_MoldOpenMidFlow    1095           //开模中途流量                              开模中途流量
#define mPara_MoldOpenStartTi    1096           //开模起始段时间                             开模起始段时间，时间控制最先一段开模，在一慢则不用
#define mPara_MoldOpenStartPres  1097           //开模起始段压力                             关模起始段压力
#define mPara_MoldOpenStartFlow  1098           //开模起始段流量                             关模起始段压力
#define mPara_MoldOpenMidHoldTi  1099           //开模中途保持时间                            开模中途时间
#define mPara_InjStartPos        1100           //注射起始段位置                             注射起始段距离，与起始段时间采用或逻辑，任一满足结束起始段
#define mPara_InjStartTi         1101           //注射起始段时间                             注射起始段时间，时间控制最先一段注射，让先导阀先动作，以减小冲击
#define mPara_InjStartPres       1102           //注射起始段压力                             注射起始段压力
#define mPara_InjStartFlow       1103           //注射起始段流量                             注射起始段流量
#define mPara_InjMaxVel          1104           //注射最大速度                              注射最大速度
#define mPara_InjAdjPres         1105           //注射调模压力                              
#define mPara_InjAdjFlow         1106           //注射调模流量                              
#define mPara_Inj1PresRamp       1107           //注射1压力斜率                             
#define mPara_Inj1FlowRamp       1108           //注射1流量斜率                             
#define mPara_Inj2PresRamp       1109           //注射2压力斜率                             
#define mPara_Inj2FlowRamp       1110           //注射2流量斜率                             
#define mPara_Inj3PresRamp       1111           //注射3压力斜率                             
#define mPara_Inj3FlowRamp       1112           //注射3流量斜率                             
#define mPara_Inj4PresRamp       1113           //注射4压力斜率                             
#define mPara_Inj4FlowRamp       1114           //注射4流量斜率                             
#define mPara_Inj5PresRamp       1115           //注射5压力斜率                             
#define mPara_Inj5FlowRamp       1116           //注射5流量斜率                             
#define mPara_Inj6PresRamp       1117           //注射6压力斜率                             
#define mPara_Inj6FlowRamp       1118           //注射6流量斜率                             
#define mPara_Inj7PresRamp       1119           //注射7压力斜率                             
#define mPara_Inj7FlowRamp       1120           //注射7流量斜率                             
#define mPara_Inj8PresRamp       1121           //注射8压力斜率                             
#define mPara_Inj8FlowRamp       1122           //注射8流量斜率                             
#define mPara_Inj9PresRamp       1123           //注射9压力斜率                             
#define mPara_Inj9FlowRamp       1124           //注射9流量斜率                             
#define mPara_Inj10PresRamp      1125           //注射10压力斜率                            
#define mPara_Inj10FlowRamp      1126           //注射10流量斜率                            
#define mPara_HoldPres1PresRamp  1127           //保压1压力斜率                             
#define mPara_HoldPres1FlowRamp  1128           //保压1流量斜率                             
#define mPara_HoldPres2PresRamp  1129           //保压2压力斜率                             
#define mPara_HoldPres2FlowRamp  1130           //保压2流量斜率                             
#define mPara_HoldPres3PresRamp  1131           //保压3压力斜率                             
#define mPara_HoldPres3FlowRamp  1132           //保压3流量斜率                             
#define mPara_HoldPres4PresRamp  1133           //保压4压力斜率                             
#define mPara_HoldPres4FlowRamp  1134           //保压4流量斜率                             
#define mPara_HoldPres5PresRamp  1135           //保压5压力斜率                             
#define mPara_HoldPres5FlowRamp  1136           //保压5流量斜率                             
#define mPara_HoldPres6PresRamp  1137           //保压6压力斜率                             
#define mPara_HoldPres6FlowRamp  1138           //保压6流量斜率                             
#define mPara_HoldPres7PresRamp  1139           //保压7压力斜率                             
#define mPara_HoldPres7FlowRamp  1140           //保压7流量斜率                             
#define mPara_HoldPres8PresRamp  1141           //保压8压力斜率                             
#define mPara_HoldPres8FlowRamp  1142           //保压8流量斜率                             
#define mPara_HoldPres9PresRamp  1143           //保压9压力斜率                             
#define mPara_HoldPres9FlowRamp  1144           //保压9流量斜率                             
#define mPara_HoldPres10PresRamp 1145           //保压10压力斜率                            
#define mPara_HoldPres10FlowRamp 1146           //保压10流量斜率                            
#define mPara_HoldPresEndPresRamp 1147          //保压结束压力斜率                            
#define mPara_HoldPresEndFlowRamp 1148          //保压结束流量斜率                            设较大斜率，实现保压后泄压作用
#define mPara_Mach_1149          1149           //                                    
#define mPara_Mach_1150          1150           //                                    
#define mPara_InjEndDly          1151           //注射完延迟计时                             动作完动作延时结束
#define mPara_InjDVOffDly        1152           //注射方向阀关延时                            动作后方向阀延时关闭
#define mPara_InjPVOnDly         1153           //注射比例阀开延时                            动作前比例阀延时输出
#define mPara_InjStartDly        1154           //注射开始延时                              座进完，射出前延时
#define mPara_InjDVOnDly         1155           //注射方向阀开延时                            注射方向阀延时开启，即让油路压力先建立，再开阀注射，以提高注射速度
#define mPara_InjectSafePos      1156           //注射安全位置                              射出结束位置设定不得小于此位置
#define mPara_HoldPresRelTi      1157           //保压泄压时间                              CH机用，保压后，切阀延时期间，保压泄压阀动作时间
#define mPara_InjEPOLToManuNum   1158           //连续注射超差转手动次数                         连续注射超差提示到该次数，则转手动并警报，如果为0，则不转
#define mPara_InjPVOthActON      1159           //注射比例阀其他动作开                          注射比例阀在注射保压动作时按设置输出，其他动作最大输出
#define mPara_AccPres            1160           //蓄能器蓄能压力                             蓄能器在补充能量时的使用压力
#define mPara_AccFlow            1161           //蓄能器蓄能流量                             蓄能器在补充能量时的使用流量
#define mPara_AccInPresRamp      1162           //蓄能器蓄能压力斜率                           
#define mPara_AccInFlowRamp      1163           //蓄能器蓄能流量斜率                           
#define mPara_AccOutPresRamp     1164           //蓄能器放能压力斜率                           
#define mPara_AccOutFlowRamp     1165           //蓄能器放能流量斜率                           
#define mPara_InjDiffOnDly       1166           //注射差动开延时计时                           
#define mPara_InjDiffOffDly      1167           //注射差动关延时计时                           
#define mPara_InjAccDly          1168           //射出增压延迟计时                            射出增压阀延迟动作时间
#define mPara_AccDVOffDly        1169           //蓄能器方向阀关延迟                           蓄能器蓄能后方向阀延时关
#define mPara_AccInMaxTi         1170           //蓄能器最大蓄能时间                           超过该时间警报“蓄能失败”
#define mPara_NozLeakageSnrChan  1171           //喷嘴漏料检测通道                            喷嘴漏料检测通道选择，0：关闭；1-16：分别选择1-16段料筒作为喷嘴漏料检测
#define mPara_NozLeakageWarnPcs  1172           //喷嘴漏料警报处理                            0-提示、1-闲转手动、2立转手动
#define mPara_InjDiffOpt         1173           //注射差动配备                              0-不配备 1-配备
#define mPara_ChargeAlgSel       1174           //储料算法选择                              0-无；1-智能储料,优化储料时间
#define mPara_ChgAdjPres         1175           //储料调模压力                              
#define mPara_ChgAdjFlow         1176           //储料调模流量                              
#define mPara_Chg1PresRamp       1177           //储料1压力斜率                             
#define mPara_Chg1FlowRamp       1178           //储料1流量斜率                             
#define mPara_Chg2PresRamp       1179           //储料2压力斜率                             
#define mPara_Chg2FlowRamp       1180           //储料2流量斜率                             
#define mPara_Chg3PresRamp       1181           //储料3压力斜率                             
#define mPara_Chg3FlowRamp       1182           //储料3流量斜率                             
#define mPara_Chg4PresRamp       1183           //储料4压力斜率                             
#define mPara_Chg4FlowRamp       1184           //储料4流量斜率                             
#define mPara_Chg5PresRamp       1185           //储料5压力斜率                             
#define mPara_Chg5FlowRamp       1186           //储料5流量斜率                             
#define mPara_Chg6PresRamp       1187           //储料6压力斜率                             
#define mPara_Chg6FlowRamp       1188           //储料6流量斜率                             
#define mPara_Chg7PresRamp       1189           //储料7压力斜率                             
#define mPara_Chg7FlowRamp       1190           //储料7流量斜率                             
#define mPara_Chg8PresRamp       1191           //储料8压力斜率                             
#define mPara_Chg8FlowRamp       1192           //储料8流量斜率                             
#define mPara_Chg9PresRamp       1193           //储料9压力斜率                             
#define mPara_Chg9FlowRamp       1194           //储料9流量斜率                             
#define mPara_Chg10PresRamp      1195           //储料10压力斜率                            
#define mPara_Chg10FlowRamp      1196           //储料10流量斜率                            
#define mPara_ChgEndPresRamp     1197           //储料结束压力斜率                            
#define mPara_ChgEndFlowRamp     1198           //储料结束流量斜率                            
#define mPara_Mach_1199          1199           //                                    
#define mPara_ChgStartDly        1200           //储料起始延迟计时                            动作起始动作延时开始
#define mPara_ChgEndDly          1201           //储料完延迟计时                             动作完动作延时结束
#define mPara_ChgDVOffDly        1202           //储料方向阀关延时                            动作后方向阀延时关闭
#define mPara_ChgPVOnDly         1203           //储料比例阀开延时                            动作前比例阀延时输出
#define mPara_Mach_1204          1204           //                                    
#define mPara_ChgSuckBackRelTi   1205           //储前射退泄压计时                            储料前先打开射退阀泄压该时间，实际未使用
#define mPara_ChgRelAftSuckBackTi 1206          //射退后储料泄压计时                           甬江机器使用，在射退后“储料泄压阀”动作该计时
#define mPara_Chg1BackPresRamp   1207           //储料背压斜率                              
#define mPara_ChgMotorOpt        1208           //电储料配备                               主要用于电储料画面压力不可设
#define mPara_Mach_1209          1209           //                                    
#define mPara_Mach_1210          1210           //                                    
#define mPara_Mach_1211          1211           //                                    
#define mPara_SuckBackAdjPres    1212           //射退调模压力                              
#define mPara_SuckBackAdjFlow    1213           //射退调模流量                              
#define mPara_SuckBackPresRamp   1214           //射退压力斜率                              
#define mPara_SuckBackFlowRamp   1215           //射退流量斜率                              
#define mPara_Mach_1216          1216           //                                    
#define mPara_SuckBackEndDly     1217           //射退完延迟计时                             动作完动作延时结束
#define mPara_SuckBackDVOffDly   1218           //射退方向阀关延时                            动作后方向阀延时关闭
#define mPara_SuckBackPVOnDly    1219           //射退比例阀开延时                            动作前比例阀延时输出
#define mPara_Mach_1220          1220           //                                    
#define mPara_Mach_1221          1221           //                                    
#define mPara_Mach_1222          1222           //                                    
#define mPara_Mach_1223          1223           //                                    
#define mPara_Mach_1224          1224           //                                    
#define mPara_EjeAdjPres         1225           //托模调模压力                              
#define mPara_EjeAdjFlow         1226           //托模调模流量                              
#define mPara_EjeFor1PresRamp    1227           //托模进1压力斜率                            
#define mPara_EjeFor1FlowRamp    1228           //托模进1流量斜率                            
#define mPara_EjeFor2PresRamp    1229           //托模进2压力斜率                            
#define mPara_EjeFor2FlowRamp    1230           //托模进2流量斜率                            
#define mPara_EjeForEndPresRamp  1231           //托模进结束压力斜率                           
#define mPara_EjeForEndFlowRamp  1232           //托模进结束流量斜率                           
#define mPara_EjeRet1PresRamp    1233           //托模退1压力斜率                            
#define mPara_EjeRet1FlowRamp    1234           //托模退1流量斜率                            
#define mPara_EjeRet2PresRamp    1235           //托模退2压力斜率                            
#define mPara_EjeRet2FlowRamp    1236           //托模退2流量斜率                            
#define mPara_EjeRetEndPresRamp  1237           //托模退结束压力斜率                           
#define mPara_EjeRetEndFlowRamp  1238           //托模退结束流量斜率                           
#define mPara_Mach_1239          1239           //                                    
#define mPara_EjeForEHoldPresTi  1240           //托模进终保压计时                            托模进到位保压计时
#define mPara_EjeForEndDly       1241           //托模进完延迟计时                            动作完动作延时结束
#define mPara_EjeForDVOffDly     1242           //托模进方向阀关延时                           动作后方向阀延时关闭
#define mPara_EjeForPVOnDly      1243           //托模进比例阀开延时                           动作前比例阀延时输出
#define mPara_EjeRetEndDly       1244           //托模退完延迟计时                            动作完动作延时结束
#define mPara_EjeRetDVOffDly     1245           //托模退方向阀关延时                           动作后方向阀延时关闭
#define mPara_EjeRetPVOnDly      1246           //托模退比例阀开延时                           动作前比例阀延时输出
#define mPara_EjeForRetSwtDly    1247           //托模进退转换延时                            托进、托退之间转换延时
#define mPara_Mach_1248          1248           //                                    
#define mPara_EjeVibCtrlMode     1249           //震动托模控制模式                            0-时间 1-位置(使用托退二段起始位置)
#define mPara_EjeVibRetTi        1250           //震动托模时间                              
#define mPara_Mach_1251          1251           //                                    
#define mPara_EjeRetEffArea      1252           //托模退位置有效区                            顶针小于“托退终止位置+有效区”即认为到位
#define mPara_EjeRetMaxPos       1253           //托模退位置允许最大值                          允许设定的托退终止位置限值
#define mPara_EjeRetSlowSPos     1254           //托退提前减速位置                            为减小油路冲击，托退时提前该位置切换到小流量
#define mPara_EjeRetSlowFlow     1255           //托退提前减速流量                            为减小油路冲击，托退时提前切换到该流量
#define mPara_EjeRetMinPos       1256           //托模退位置允许最小值                          允许设定的托退终止位置限值
#define mPara_Mach_1257          1257           //                                    
#define mPara_NozAdjPres         1258           //座台调模压力                              
#define mPara_NozAdjFlow         1259           //座台调模流量                              
#define mPara_NozFor1PresRamp    1260           //座进1压力斜率                             
#define mPara_NozFor1FlowRamp    1261           //座进1流量斜率                             
#define mPara_NozFor2PresRamp    1262           //座进2压力斜率                             
#define mPara_NozFor2FlowRamp    1263           //座进2流量斜率                             
#define mPara_NozForSlowPresRamp 1264           //座进慢速压力斜率                            
#define mPara_NozForSlowFlowRamp 1265           //座进慢速流量斜率                            
#define mPara_NozForEndPresRamp  1266           //座进结束压力斜率                            
#define mPara_NozForEndFlowRamp  1267           //座进结束流量斜率                            
#define mPara_NozRet1PresRamp    1268           //座退1压力斜率                             
#define mPara_NozRet1FlowRamp    1269           //座退1流量斜率                             
#define mPara_NozRet2PresRamp    1270           //座退2压力斜率                             
#define mPara_NozRet2FlowRamp    1271           //座退2流量斜率                             
#define mPara_NozRetEndPresRamp  1272           //座退结束压力斜率                            
#define mPara_NozRetEndFlowRamp  1273           //座退结束流量斜率                            
#define mPara_Mach_1274          1274           //                                    
#define mPara_Mach_1275          1275           //                                    
#define mPara_NozForEndDly       1276           //座台进完延迟计时                            动作完动作延时结束
#define mPara_NozForDVOffDly     1277           //座台进方向阀关延时                           动作后方向阀延时关闭
#define mPara_NozForPVOnDly      1278           //座台进比例阀开延时                           动作前比例阀延时输出
#define mPara_NozRetEndDly       1279           //座台退完延迟计时                            动作完动作延时结束
#define mPara_NozRetDVOffDly     1280           //座台退方向阀关延时                           动作后方向阀延时关闭
#define mPara_NozRetPVOnDly      1281           //座台退比例阀开延时                           动作前比例阀延时输出
#define mPara_Mach_1282          1282           //                                    
#define mPara_Mach_1283          1283           //                                    
#define mPara_SlaveNozOpt        1284           //从射台配备                               0-从射台未配备，1-从射台配备
#define mPara_HydNozOnTi         1285           //液压喷嘴开计时                             
#define mPara_HydNozOffTi        1286           //液压喷嘴关计时                             
#define mPara_HydNozPres         1287           //液压喷嘴动作压力                            
#define mPara_HydNozFlow         1288           //液压喷嘴动作流量                            
#define mPara_Mach_1289          1289           //                                    
#define mPara_Mach_1290          1290           //                                    
#define mPara_Mach_1291          1291           //                                    
#define mPara_TimeCoreRunAlway   1292           //时间中子一直执行                            0-不用,1-使用 时间中子时无论是否已经到位，在关模、或开模时都会重新执行一次
#define mPara_Mach_1293          1293           //                                    
#define mPara_Mach_1294          1294           //                                    
#define mPara_Core1InPresRamp    1295           //中子1进压力斜率                            
#define mPara_Core1InFlowRamp    1296           //中子1进流量斜率                            
#define mPara_Core2InPresRamp    1297           //中子2进压力斜率                            
#define mPara_Core2InFlowRamp    1298           //中子2进流量斜率                            
#define mPara_Core3InPresRamp    1299           //中子3进压力斜率                            
#define mPara_Core3InFlowRamp    1300           //中子3进流量斜率                            
#define mPara_Core4InPresRamp    1301           //中子4进压力斜率                            
#define mPara_Core4InFlowRamp    1302           //中子4进流量斜率                            
#define mPara_Core5InPresRamp    1303           //中子5进压力斜率                            
#define mPara_Core5InFlowRamp    1304           //中子5进流量斜率                            
#define mPara_Core6InPresRamp    1305           //中子6进压力斜率                            
#define mPara_Core6InFlowRamp    1306           //中子6进流量斜率                            
#define mPara_Core7InPresRamp    1307           //中子7进压力斜率                            
#define mPara_Core7InFlowRamp    1308           //中子7进流量斜率                            
#define mPara_Core8InPresRamp    1309           //中子8进压力斜率                            
#define mPara_Core8InFlowRamp    1310           //中子8进流量斜率                            
#define mPara_Mach_1311          1311           //                                    
#define mPara_Mach_1312          1312           //                                    
#define mPara_Mach_1313          1313           //                                    
#define mPara_Mach_1314          1314           //                                    
#define mPara_Mach_1315          1315           //                                    
#define mPara_Mach_1316          1316           //                                    
#define mPara_Core1OutPresRamp   1317           //中子1出压力斜率                            
#define mPara_Core1OutFlowRamp   1318           //中子1出流量斜率                            
#define mPara_Core2OutPresRamp   1319           //中子2出压力斜率                            
#define mPara_Core2OutFlowRamp   1320           //中子2出流量斜率                            
#define mPara_Core3OutPresRamp   1321           //中子3出压力斜率                            
#define mPara_Core3OutFlowRamp   1322           //中子3出流量斜率                            
#define mPara_Core4OutPresRamp   1323           //中子4出压力斜率                            
#define mPara_Core4OutFlowRamp   1324           //中子4出流量斜率                            
#define mPara_Core5OutPresRamp   1325           //中子5出压力斜率                            
#define mPara_Core5OutFlowRamp   1326           //中子5出流量斜率                            
#define mPara_Core6OutPresRamp   1327           //中子6出压力斜率                            
#define mPara_Core6OutFlowRamp   1328           //中子6出流量斜率                            
#define mPara_Core7OutPresRamp   1329           //中子7出压力斜率                            
#define mPara_Core7OutFlowRamp   1330           //中子7出流量斜率                            
#define mPara_Core8OutPresRamp   1331           //中子8出压力斜率                            
#define mPara_Core8OutFlowRamp   1332           //中子8出流量斜率                            
#define mPara_Mach_1333          1333           //                                    
#define mPara_Mach_1334          1334           //                                    
#define mPara_Mach_1335          1335           //                                    
#define mPara_Mach_1336          1336           //                                    
#define mPara_Mach_1337          1337           //                                    
#define mPara_Mach_1338          1338           //                                    
#define mPara_CoreInEndDly       1339           //中子进完延迟计时                            动作完动作延时结束
#define mPara_CoreInDVOffDly     1340           //中子进方向阀关延时                           动作后方向阀延时关闭
#define mPara_CoreInPVOnDly      1341           //中子进比例阀开延时                           动作前比例阀延时输出
#define mPara_CoreOutEndDly      1342           //中子出完延迟计时                            动作完动作延时结束
#define mPara_CoreOutDVOffDly    1343           //中子出方向阀关延时                           动作后方向阀延时关闭
#define mPara_CoreOutPVOnDly     1344           //中子出比例阀开延时                           动作前比例阀延时输出
#define mPara_CoreInStartDly     1345           //中子进前延迟计时                            经此延时后开始中子进动作
#define mPara_CoreOutStartDly    1346           //中子退前延迟计时                            经此延时后开始中子退动作
#define mPara_CoreProtSel        1347           //中子保护功能                              0-不用 1-使用
#define mPara_CoreSnrErrChk      1348           //中子进退到位开关异常检查                        0-不检查 1-检查，即进、退终行程开关同时压合时报警
#define mPara_PresRelTi          1349           //中子阀门泄压时间                            中子、热流道阀门的泄压时间
#define mPara_CoreReverseSel     1350           //中子反向功能                              0-不用 1-使用
#define mPara_Mach_1351          1351           //                                    
#define mPara_Mach_1352          1352           //                                    
#define mPara_CoreEndChkMode_MCMO 1353          //开关模中子到位检查模式                         0-动作开始时检查，1-全程实时检查
#define mPara_CoreEndChkMode_EjeFor 1354        //托模中子到位检查模式                          0-动作开始时检查，1-全程实时检查
#define mPara_CoreEndChkMode_Inject 1355        //注射中子到位检查模式                          0-动作开始时检查，1-全程实时检查
#define mPara_Mach_1356          1356           //                                    
#define mPara_Mach_1357          1357           //                                    
#define mPara_ZoneHtrSoftStartSel 1358          //料筒加热软启动选择                           1-料筒温度软启动：先加热到“阶梯温度”，持续“保持时间”，然后加热到目标温度
#define mPara_ZoneHtrSoftStartTemp 1359         //料筒加热软启动温度                           
#define mPara_ZoneHtrSoftStartHoldTi 1360       //料筒加热软启动保持时间                         
#define mPara_Mach_1361          1361           //                                    
#define mPara_Mach_1362          1362           //                                    
#define mPara_SyncWarmDeviTemp   1363           //同步温升偏差温度                            同步温升偏差温度
#define mPara_SyncWarmEndMinDevi 1364           //同步温升结束温度下限                          同步温升结束温度下限
#define mPara_Zone1TempBuff      1365           //一段温度缓冲区                             为0表示关闭
#define mPara_Zone2TempBuff      1366           //二段温度缓冲区                             为0表示关闭
#define mPara_Zone3TempBuff      1367           //三段温度缓冲区                             为0表示关闭
#define mPara_Zone4TempBuff      1368           //四段温度缓冲区                             为0表示关闭
#define mPara_Zone5TempBuff      1369           //五段温度缓冲区                             为0表示关闭
#define mPara_Zone6TempBuff      1370           //六段温度缓冲区                             为0表示关闭
#define mPara_Zone7TempBuff      1371           //七段温度缓冲区                             为0表示关闭
#define mPara_Zone8TempBuff      1372           //八段温度缓冲区                             为0表示关闭
#define mPara_Zone9TempBuff      1373           //九段温度缓冲区                             为0表示关闭
#define mPara_Zone10TempBuff     1374           //十段温度缓冲区                             为0表示关闭
#define mPara_Zone11TempBuff     1375           //十一段温度缓冲区                            为0表示关闭
#define mPara_Zone12TempBuff     1376           //十二段温度缓冲区                            为0表示关闭
#define mPara_Zone13TempBuff     1377           //十三段温度缓冲区                            为0表示关闭
#define mPara_Zone14TempBuff     1378           //十四段温度缓冲区                            为0表示关闭
#define mPara_Zone15TempBuff     1379           //十五段温度缓冲区                            为0表示关闭
#define mPara_Zone16TempBuff     1380           //十六段温度缓冲区                            为0表示关闭
#define mPara_Mach_1381          1381           //                                    
#define mPara_Mach_1382          1382           //                                    
#define mPara_ZoneEnUpDevTemp    1383           //料管温度允许上偏差                           应国标要求，偏差温度超过该值，报警、关电热
#define mPara_ZoneCoolProtMinTi  1384           //防冷启动时间下限                            限制画面中料筒防冷启动时间可设的下限
#define mPara_ZoneUpDevTemp      1385           //料管温度上限警报值                           
#define mPara_ZoneDnDevTemp      1386           //料管温度下限警报值                           
#define mPara_ZoneCoolOnDevTemp  1387           //料管冷却开偏差温度                           偏差高于该值，开启料管冷却。为0冷却器不用
#define mPara_ZoneCoolOffDevTemp 1388           //料管冷却关偏差温度                           偏差低于该值，关闭料管冷却
#define mPara_HtrOffZoneCoolTi   1389           //电热关料筒冷却时间                           电热关后，料筒冷却开启，持续该时间才结束
#define mPara_HtrFailChkTemp     1390           //电热加温检查最小温升                          加热器全速开时，每3分钟最少温升。为0不检查
#define mPara_HtrFreeKeepWarmTi  1391           //电热空闲转保温时间                           为0则空闲不转保温
#define mPara_EmerStopImmKeepWarm 1392          //紧急停止按下立转保温                          1-紧停按下立即转保温 0-紧停按下后，闲转保温时间到才转保温
#define mPara_OilTempMax         1393           //油箱油温上限                              为0表示油箱测温关闭
#define mPara_OilTempMin         1394           //油箱油温下限                              
#define mPara_OilCoolOffTemp     1395           //油温低关冷却器                             油温低于该温度，关闭油温冷却器
#define mPara_OilCoolOnTemp      1396           //油温高开冷却器                             油温超过该温度，开冷却器，为0不用冷却器
#define mPara_OilPreHtrSel       1397           //油温预热开启                              0-关闭预热功能 1-开启预热功能
#define mPara_OilPreHtrPres      1398           //油温预热压力                              预先加热压力
#define mPara_OilPreHtrFlow      1399           //油温预热流量                              预先加热流量
#define mPara_OilPreHtrTrgTemp   1400           //预热油温                                油温预热目标温度
#define mPara_OilPreHtrTrgDevTemp 1401          //油温偏差                                油温预热目标温度+油温偏差=预热结束温度
#define mPara_HtrFreeOffTi       1402           //电热空闲关闭时间                            为0则空闲不关电热
#define mPara_MotCoolOnTemp      1403           //马达冷却开温度                             用于伺服电机，温度超过开冷却器(伺服电机"冷却风扇"输出点)
#define mPara_MotCoolOffTemp     1404           //马达冷却关温度                             用于伺服电机，温度小于关冷却器(伺服电机"冷却风扇"输出点)
#define mPara_MotTempMax         1405           //马达温度警报上限                            温度超过，立即报警
#define mPara_MotHoldTi          1406           //马达保护计时                              启动完成后，经该时间后稳定了，允许动作
#define mPara_MotYTi             1407           //马达启始时间                              马达Y形启动时间
#define mPara_MotYToASpaTi       1408           //马达间歇时间                              马达Y到A转换的空歇时间
#define mPara_MotFreeOffTi       1409           //马达空闲关闭时间                            为0则空闲不关马达
#define mPara_Mach_1410          1410           //                                    
#define mPara_Mach_1411          1411           //                                    
#define mPara_Mach_1412          1412           //                                    
#define mPara_Mach_1413          1413           //                                    
#define mPara_AutoSG1Pres        1414           //自动安全门1压力                            
#define mPara_AutoSG1Flow        1415           //自动安全门1流量                            
#define mPara_AutoSG2Pres        1416           //自动安全门2压力                            慢速
#define mPara_AutoSG2Flow        1417           //自动安全门2流量                            慢速
#define mPara_Mach_1418          1418           //                                    
#define mPara_AutoSG1PresRamp    1419           //自动安全门1压力斜率                          
#define mPara_AutoSG1FlowRamp    1420           //自动安全门1流量斜率                          
#define mPara_AutoSG2PresRamp    1421           //自动安全门2压力斜率                          
#define mPara_AutoSG2FlowRamp    1422           //自动安全门2流量斜率                          
#define mPara_AutoSGEPresRamp    1423           //自动安全门结束压力斜率                         
#define mPara_AutoSGEFlowRamp    1424           //自动安全门结束流量斜率                         
#define mPara_Mach_1425          1425           //                                    
#define mPara_AutoSGOpenTi       1426           //自动安全门开计时                            
#define mPara_AutoSGEndDly       1427           //自动安全门延迟计时                           动作完动作延时结束
#define mPara_AutoSGDVOffDly     1428           //自动安全门方向阀关延时                         动作后方向阀延时关闭
#define mPara_AutoSGPVOnDly      1429           //自动安全门比例阀开延时                         动作前比例阀延时输出
#define mPara_Lubr1UnitCntMax    1430           //润滑1模数最大值                            
#define mPara_Lubr1PartCnt       1431           //润滑1前后分隔模数                           
#define mPara_Lubr1UnitCnt       1432           //润滑1模数                               
#define mPara_Lubr1TtlTi         1433           //润滑1总时间                              定阻、定压润滑时总时间
#define mPara_Lubr1TtlCnt        1434           //润滑1次数                               定次润滑时，润滑的次数
#define mPara_Lubr1MaxTi         1435           //润滑1警报时间                             超过该时间未检测到“润滑压力”则润滑失败
#define mPara_Lubr1Dly           1436           //润滑1延迟                               两次润滑之间的延时
#define mPara_Lubr1HoldPresTi    1437           //润滑1保压时间                             检测到“润滑压力”后继续保持润滑输出时间
#define mPara_Lubr1SpaTi         1438           //润滑1润滑间隔时间                           
#define mPara_Lubr2PartCnt       1439           //润滑2前后分隔模数                           
#define mPara_Lubr2UnitCnt       1440           //润滑2模数                               
#define mPara_Lubr2TtlTi         1441           //润滑2总时间                              定阻、定压润滑时总时间
#define mPara_Lubr2TtlCnt        1442           //润滑2次数                               定次润滑时，润滑的次数
#define mPara_Lubr2MaxTi         1443           //润滑2警报时间                             超过该时间未检测到“润滑压力”则润滑失败
#define mPara_Lubr2Dly           1444           //润滑2延迟                               两次润滑之间的延时
#define mPara_Lubr2HoldPresTi    1445           //润滑2保压时间                             检测到“润滑压力”后继续保持润滑输出时间
#define mPara_Lubr2SpaTi         1446           //润滑2润滑间隔时间                           
#define mPara_Mach_1447          1447           //                                    
#define mPara_PwrOnAutoLubrDays  1448           //开机自动润滑天数                            保留，机器未进行润滑达到该天数则开机后自动润滑，通常是机器停机了较长时间
#define mPara_Lubr1DataTime      1449           //润滑1润滑时间                             最近一次润滑1润滑的时间，以S为单位记录
#define mPara_Lubr2DataTime      1450           //润滑2润滑时间                             最近一次润滑1润滑的时间，以S为单位记录
#define mPara_Pump1OnFlow        1451           //泵1开启流量                              
#define mPara_Pump2OnFlow        1452           //泵2开启流量                              
#define mPara_Pump3OnFlow        1453           //泵3开启流量                              
#define mPara_Pump4OnFlow        1454           //泵4开启流量                              
#define mPara_Pump5OnFlow        1455           //泵5开启流量                              
#define mPara_Pump6OnFlow        1456           //泵6开启流量                              
#define mPara_Pump7OnFlow        1457           //泵7开启流量                              
#define mPara_Pump8OnFlow        1458           //泵8开启流量                              
#define mPara_Pump9OnFlow        1459           //泵9开启流量                              
#define mPara_Pump10OnFlow       1460           //泵10开启流量                             
#define mPara_Pump11OnFlow       1461           //泵11开启流量                             
#define mPara_Pump12OnFlow       1462           //泵12开启流量                             
#define mPara_Pump13OnFlow       1463           //泵13开启流量                             
#define mPara_Pump14OnFlow       1464           //泵14开启流量                             
#define mPara_Pump15OnFlow       1465           //泵15开启流量                             
#define mPara_Pump16OnFlow       1466           //泵16开启流量                             
#define mPara_Mach_1467          1467           //                                    
#define mPara_PrmpOnDly          1468           //泵开启延时                               
#define mPara_SpcPumpSel         1469           //特殊泵选择                               0-不用 1-使用
#define mPara_LinkPresOnFlow     1470           //连动压力比例阀开流量                          连动压力比例阀在非开模动作时又作泵使用，此即作为泵使用时的开启流量
#define mPara_ShutdownPlsMOOpt   1471           //关机开模提醒配备                            0-未配备 1-配备
#define mPara_PresMinRamp        1472           //压力最小斜率                              伺服机压力流量变化不宜太快,易振荡及损坏泵,故设此最小斜率
#define mPara_FlowMinRamp        1473           //流量最小斜率                              伺服机压力流量变化不宜太快,易振荡及损坏泵,故设此最小斜率
#define mPara_DADbRamp           1474           //DA调试输出时斜率                           DA调试强制输出时的斜率，特别是伺服机，不宜太快，易振荡及损坏泵
#define mPara_AdjMoldActMaxFlow  1475           //调模方式动作最大流量                          调模方式下，各动作最大流量
#define mPara_MoldAdjDotCnt      1476           //点动调模齿数                              点动调模时，调模进退的齿数
#define mPara_AMASnrChkTi        1477           //自动调模信号检测时间                          自动调模时电眼、位置不移动检查确认时间
#define mPara_AMAMoldOpenSpa     1478           //自动调模开模距离                            自动调模时开模后退距离
#define mPara_AMAStartPulseNum   1479           //自动调模起始脉冲数                           自动调模起始脉冲数
#define mPara_LinkValOnDly       1480           //连动阀延迟开计时                            预留
#define mPara_CycTiNoStopSel     1481           //全程计时不停选择                            热固机，允许全程计时在结束自动时也不停
#define mPara_SpcRelPresValOffDly 1482          //特殊泄压关延时                             应北化眼镜机：特殊泄压关延时
#define mPara_MoniToManuOff      1483           //监测功能常开                              0-转手动时即关闭 1-一直有效
#define mPara_ExtAlarmLog        1484           //外部警报逻辑                              0-未配备、1-ON有效,报警、2-OFF有效,报警
#define mPara_ExtAlarmPcs        1485           //外部警报处理                              0-立转手动+切马达、1-闲转手动+切马达、2-立转手动、3-闲转手动
#define mPara_AutoMoniOnUnitCnt  1486           //自动警报开启模数                            该模数到达后，自动监测功能开启
#define mPara_SGBackOpenAlarmLgt 1487           //后安全门开不亮警灯                           0-亮灯 1-不亮警灯
#define mPara_CycMaxTi           1488           //全程计时警报上限                            
#define mPara_MoldClsLPMaxTi     1489           //关模低压计时警报上限                          
#define mPara_MoldClsHPMaxTi     1490           //关模高压计时警报上限                          
#define mPara_ChgMaxTi           1491           //储料计时警报上限                            
#define mPara_SuckBackMaxTi      1492           //射退计时警报上限                            
#define mPara_SGOpenClsMaxTi     1493           //安全门开关警报时间                           
#define mPara_MOMedRobotPosMin   1494           //开模中途取件位置下限                          欧规机械手，中途取件时位置下限
#define mPara_AlarmOutDly        1495           //警报输出延迟时间                            
#define mPara_AlarmOutTi         1496           //警报输出时间                              警报持续输出的时间
#define mPara_AlarmClsHtrTi      1497           //警报切电热时间                             为0不关
#define mPara_AlarmClsMotTi      1498           //警报切马达时间                             为0不关
#define mPara_AlarmOutTiCtrlSel  1499           //警报输出时间可设                            0-警报持续输出 1-警报持续输出时间按AlarmOutTi设置
#define mPara_RobotWaitMaxTi     1500           //机械手超时时间                             等待机械手信号有效最长等待时间
#define mPara_PackCntOnTi        1501           //包装数到输出时间                            包装数到输出时间
#define mPara_IODbgOutTime       1502           //IO强制输出时间                            
#define mPara_DADbgOutTime       1503           //DA强制输出时间                            
#define mPara_PumpLevelOpt       1504           //泵站液位检测配备                            海天北化眼镜机专用：0-未配备 1-负逻辑 2-正逻辑
#define mPara_ChutesChan         1505           //落料口通道                               落料口通道选择，0：关闭；1-16：分别选择1-16料料筒作为落料口控温用
#define mPara_ChutesUpDevTemp    1506           //落料口温度上限警报值                          
#define mPara_ChutesDnDevTemp    1507           //落料口温度下限警报值                          
#define mPara_ChutesCoolOnDevTemp 1508          //落料口冷却开偏差温度                          偏差高于该值，开启料管冷却。为0冷却器不用
#define mPara_ChutesCoolOffDevTemp 1509         //落料口冷却关偏差温度                          偏差低于该值，关闭料管冷却
#define mPara_Htr1Power          1510           //电热1功率                               
#define mPara_Htr2Power          1511           //电热2功率                               
#define mPara_Htr3Power          1512           //电热3功率                               
#define mPara_Htr4Power          1513           //电热4功率                               
#define mPara_Htr5Power          1514           //电热5功率                               
#define mPara_Htr6Power          1515           //电热6功率                               
#define mPara_Htr7Power          1516           //电热7功率                               
#define mPara_Htr8Power          1517           //电热8功率                               
#define mPara_Htr9Power          1518           //电热9功率                               
#define mPara_Htr10Power         1519           //电热10功率                              
#define mPara_Htr11Power         1520           //电热11功率                              
#define mPara_Htr12Power         1521           //电热12功率                              
#define mPara_Htr13Power         1522           //电热13功率                              
#define mPara_Htr14Power         1523           //电热14功率                              
#define mPara_Htr15Power         1524           //电热15功率                              
#define mPara_Htr16Power         1525           //电热16功率                              
#define mPara_Mach_1526          1526           //                                    
#define mPara_Mach_1527          1527           //                                    
#define mPara_PFL_FlowLimit1     1528           //流量限制1                               PVC二代机压力流量相互限制
#define mPara_PFL_FlowLimit2     1529           //流量限制2                               PVC二代机压力流量相互限制
#define mPara_PFL_FlowLimit3     1530           //流量限制3                               PVC二代机压力流量相互限制
#define mPara_PFL_PresLimit1     1531           //压力限制1                               PVC二代机压力流量相互限制
#define mPara_PFL_PresLimit2     1532           //压力限制2                               PVC二代机压力流量相互限制
#define mPara_PFL_PresLimit3     1533           //压力限制3                               PVC二代机压力流量相互限制
#define mPara_Mach_1534          1534           //                                    
#define mPara_Mach_1535          1535           //                                    
#define mPara_Mach_1536          1536           //                                    
#define mPara_Mach_1537          1537           //                                    
#define mPara_Mach_1538          1538           //                                    
#define mPara_Mach_1539          1539           //                                    
#define mPara_Lubr1UnitCnt_B1W   1540           //润滑1模数                               应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1TtlTi_B1W     1541           //润滑1总时间                              定阻、定压润滑时总时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1TtlCnt_B1W    1542           //润滑1次数                               定次润滑时，润滑的次数；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1MaxTi_B1W     1543           //润滑1警报时间                             超过该时间未检测到“润滑压力”则润滑失败；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1Dly_B1W       1544           //润滑1延迟                               ；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1HoldPresTi_B1W 1545          //润滑1保压时间                             检测到“润滑压力”后继续保持润滑输出时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr1RelPresChk    1546           //润滑1压力泄压检查                           润滑1压力泄压检查，1-检查；0-不检查
#define mPara_Mach_1547          1547           //                                    
#define mPara_Lubr2UnitCnt_B1W   1548           //润滑2模数                               应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2TtlTi_B1W     1549           //润滑2总时间                              定阻、定压润滑时总时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2TtlCnt_B1W    1550           //润滑2次数                               定次润滑时，润滑的次数；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2MaxTi_B1W     1551           //润滑2警报时间                             超过该时间未检测到“润滑压力”则润滑失败；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2Dly_B1W       1552           //润滑2延迟                               两次润滑之间的延时；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2HoldPresTi_B1W 1553          //润滑2保压时间                             检测到“润滑压力”后继续保持润滑输出时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define mPara_Lubr2RelPresChk    1554           //润滑2压力泄压检查                           润滑2压力泄压检查，1-检查；0-不检查
#define mPara_Lubr2SharLubr1Pump 1555           //润滑2共用润滑1润滑泵                         润滑2共用润滑1润滑泵
#define mPara_LubrParaMangMode   1556           //润滑参数管理模式                            0-标准,1-海天模式（前后10000模采用不同参数，可设范围限定，通过U盘配置）,2-海天模式(50000模为界)
#define mPara_AutoLubrDisBrk     1557           //自动润滑中断继续功能                          1-自动润滑被中断，下次自动润滑会继续进行
#define mPara_MoldAdjLubrSharLubr1Pump 1558     //调模润滑共用润滑1润滑泵                        调模润滑共用润滑1润滑泵
#define mPara_MoldAdjLubrSnrNoOpt 1559          //调模润滑检知未配备                           调模润滑检知未配备
#define mPara_LubrMotorOnSel     1560           //开马达即润滑选择                            0-不用，1-使用
#define mPara_RobComCANPort      1561           //机械手通讯CAN端口号                         0-关闭、1-CAN1、2-CAN2
#define mPara_MotOffServoDrvCanEn 1562          //驱动器关马达CAN通讯使能                       
#define mPara_HiMD6CANPort       1563           //海天MD6卡CAN端口号                        
#define mPara_PwrOnLubrSel       1564           //开机润滑选择                              0-不用 1-使用
#define mPara_Mach_1565          1565           //                                    
#define mPara_VeiServoDrvCANPort 1566           //伟创驱动器CAN端口号                         
#define mPara_VeiServoDrv1Opt    1567           //伟创驱动器1配备                            
#define mPara_VeiServoDrv2Opt    1568           //伟创驱动器2配备                            
#define mPara_VeiServoDrv3Opt    1569           //伟创驱动器3配备                            
#define mPara_VeiServoDrv4Opt    1570           //伟创驱动器4配备                            
#define mPara_ESServoDrv1Mode    1571           //艾普希隆驱动器1接口模式                        
#define mPara_ESServoDrv2Mode    1572           //艾普希隆驱动器2接口模式                        
#define mPara_ESServoDrv3Mode    1573           //艾普希隆驱动器3接口模式                        
#define mPara_ESServoDrv4Mode    1574           //艾普希隆驱动器4接口模式                        
#define mPara_ESServoDrvCANPort  1575           //艾普希隆驱动器CAN端口号                       
#define mPara_ESServoDrv1Opt     1576           //艾普希隆驱动器1配备                          0-不配备 1-配备
#define mPara_ESServoDrv2Opt     1577           //艾普希隆驱动器2配备                          0-不配备 1-配备
#define mPara_ESServoDrv3Opt     1578           //艾普希隆驱动器3配备                          0-不配备 1-配备
#define mPara_ESServoDrv4Opt     1579           //艾普希隆驱动器4配备                          0-不配备 1-配备
#define mPara_HiServoDrv1Opt     1580           //海天驱动器1配备                            0-不配备 1-配备
#define mPara_HiServoDrv2Opt     1581           //海天驱动器2配备                            0-不配备 1-配备
#define mPara_HiServoDrv3Opt     1582           //海天驱动器3配备                            0-不配备 1-配备
#define mPara_HiServoDrv4Opt     1583           //海天驱动器4配备                            0-不配备 1-配备
#define mPara_EuRaServoDrvCANPort 1584          //瑞欧驱动器CAN端口号                         
#define mPara_EuRaServoDrv1Opt   1585           //瑞欧驱动器1配备                            
#define mPara_EuRaServoDrv2Opt   1586           //瑞欧驱动器2配备                            
#define mPara_EuRaServoDrv3Opt   1587           //瑞欧驱动器3配备                            
#define mPara_EuRaServoDrv4Opt   1588           //瑞欧驱动器4配备                            
#define mPara_HiServoDrvCANPort  1589           //海天驱动器CAN端口号                         
#define mPara_TDServoDrvNorEnMode 1590          //台达驱动器默认使能模式                         0-数字面板；1-外部DI；2-通讯RS485；3-CANOpen
#define mPara_TDServoDrv1Mode    1591           //台达驱动器1接口模式                          
#define mPara_TDServoDrv2Mode    1592           //台达驱动器2接口模式                          
#define mPara_TDServoDrv3Mode    1593           //台达驱动器3接口模式                          
#define mPara_TDServoDrv4Mode    1594           //台达驱动器4接口模式                          
#define mPara_TDServoDrvCANPort  1595           //台达驱动器CAN端口号                         
#define mPara_TDServoDrv1Opt     1596           //台达驱动器1配备                            0-不配备 1-配备
#define mPara_TDServoDrv2Opt     1597           //台达驱动器2配备                            0-不配备 1-配备
#define mPara_TDServoDrv3Opt     1598           //台达驱动器3配备                            0-不配备 1-配备
#define mPara_TDServoDrv4Opt     1599           //台达驱动器4配备                            0-不配备 1-配备
#define mPara_Zone1TCPID_Ps      1600           //PID控温算法Ps                           静态PID参数
#define mPara_Zone1TCPID_Is      1601           //PID控温算法Is                           静态PID参数
#define mPara_Zone1TCPID_Ds      1602           //PID控温算法Ds                           静态PID参数
#define mPara_Zone2TCPID_Ps      1603           //PID控温算法Ps                           静态PID参数
#define mPara_Zone2TCPID_Is      1604           //PID控温算法Is                           静态PID参数
#define mPara_Zone2TCPID_Ds      1605           //PID控温算法Ds                           静态PID参数
#define mPara_Zone3TCPID_Ps      1606           //PID控温算法Ps                           静态PID参数
#define mPara_Zone3TCPID_Is      1607           //PID控温算法Is                           静态PID参数
#define mPara_Zone3TCPID_Ds      1608           //PID控温算法Ds                           静态PID参数
#define mPara_Zone4TCPID_Ps      1609           //PID控温算法Ps                           静态PID参数
#define mPara_Zone4TCPID_Is      1610           //PID控温算法Is                           静态PID参数
#define mPara_Zone4TCPID_Ds      1611           //PID控温算法Ds                           静态PID参数
#define mPara_Zone5TCPID_Ps      1612           //PID控温算法Ps                           静态PID参数
#define mPara_Zone5TCPID_Is      1613           //PID控温算法Is                           静态PID参数
#define mPara_Zone5TCPID_Ds      1614           //PID控温算法Ds                           静态PID参数
#define mPara_Zone6TCPID_Ps      1615           //PID控温算法Ps                           静态PID参数
#define mPara_Zone6TCPID_Is      1616           //PID控温算法Is                           静态PID参数
#define mPara_Zone6TCPID_Ds      1617           //PID控温算法Ds                           静态PID参数
#define mPara_Zone7TCPID_Ps      1618           //PID控温算法Ps                           静态PID参数
#define mPara_Zone7TCPID_Is      1619           //PID控温算法Is                           静态PID参数
#define mPara_Zone7TCPID_Ds      1620           //PID控温算法Ds                           静态PID参数
#define mPara_Zone8TCPID_Ps      1621           //PID控温算法Ps                           静态PID参数
#define mPara_Zone8TCPID_Is      1622           //PID控温算法Is                           静态PID参数
#define mPara_Zone8TCPID_Ds      1623           //PID控温算法Ds                           静态PID参数
#define mPara_Zone9TCPID_Ps      1624           //PID控温算法Ps                           静态PID参数
#define mPara_Zone9TCPID_Is      1625           //PID控温算法Is                           静态PID参数
#define mPara_Zone9TCPID_Ds      1626           //PID控温算法Ds                           静态PID参数
#define mPara_Zone10TCPID_Ps     1627           //PID控温算法Ps                           静态PID参数
#define mPara_Zone10TCPID_Is     1628           //PID控温算法Is                           静态PID参数
#define mPara_Zone10TCPID_Ds     1629           //PID控温算法Ds                           静态PID参数
#define mPara_Zone11TCPID_Ps     1630           //PID控温算法Ps                           静态PID参数
#define mPara_Zone11TCPID_Is     1631           //PID控温算法Is                           静态PID参数
#define mPara_Zone11TCPID_Ds     1632           //PID控温算法Ds                           静态PID参数
#define mPara_Zone12TCPID_Ps     1633           //PID控温算法Ps                           静态PID参数
#define mPara_Zone12TCPID_Is     1634           //PID控温算法Is                           静态PID参数
#define mPara_Zone12TCPID_Ds     1635           //PID控温算法Ds                           静态PID参数
#define mPara_Zone13TCPID_Ps     1636           //PID控温算法Ps                           静态PID参数
#define mPara_Zone13TCPID_Is     1637           //PID控温算法Is                           静态PID参数
#define mPara_Zone13TCPID_Ds     1638           //PID控温算法Ds                           静态PID参数
#define mPara_Zone14TCPID_Ps     1639           //PID控温算法Ps                           静态PID参数
#define mPara_Zone14TCPID_Is     1640           //PID控温算法Is                           静态PID参数
#define mPara_Zone14TCPID_Ds     1641           //PID控温算法Ds                           静态PID参数
#define mPara_Zone15TCPID_Ps     1642           //PID控温算法Ps                           静态PID参数
#define mPara_Zone15TCPID_Is     1643           //PID控温算法Is                           静态PID参数
#define mPara_Zone15TCPID_Ds     1644           //PID控温算法Ds                           静态PID参数
#define mPara_Zone16TCPID_Ps     1645           //PID控温算法Ps                           静态PID参数
#define mPara_Zone16TCPID_Is     1646           //PID控温算法Is                           静态PID参数
#define mPara_Zone16TCPID_Ds     1647           //PID控温算法Ds                           静态PID参数
#define mPara_Mach_1648          1648           //                                    
#define mPara_Mach_1649          1649           //                                    
#define mPara_DryCycMC1PresRamp  1650           //干循环关模1段压力斜率                         干循环关模1段压力斜率
#define mPara_DryCycMC1FlowRamp  1651           //干循环关模1段流量斜率                         干循环关模1段流量斜率
#define mPara_DryCycMC2PresRamp  1652           //干循环关模2段压力斜率                         干循环关模2段压力斜率
#define mPara_DryCycMC2FlowRamp  1653           //干循环关模2段流量斜率                         干循环关模2段流量斜率
#define mPara_DryCycMC3PresRamp  1654           //干循环关模3段压力斜率                         干循环关模3段压力斜率
#define mPara_DryCycMC3FlowRamp  1655           //干循环关模2段流量斜率                         干循环关模3段流量斜率
#define mPara_DryCycMCLPPresRamp 1656           //干循环关模LP段压力斜率                        干循环关模LP段压力斜率
#define mPara_DryCycMCLPFlowRamp 1657           //干循环关模LP段流量斜率                        干循环关模LP段流量斜率
#define mPara_DryCycMCHPPresRamp 1658           //干循环关模HP段压力斜率                        干循环关模HP段压力斜率
#define mPara_DryCycMCHPFlowRamp 1659           //干循环关模HP段流量斜率                        干循环关模HP段流量斜率
#define mPara_DryCycMCEndPresRamp 1660          //干循环关模结束压力斜率                         
#define mPara_DryCycMCEndFlowRamp 1661          //干循环关模结束流量斜率                         
#define mPara_DryCycMCPVOnDly    1662           //干循环关模比例阀开延时                         动作前比例阀延时输出
#define mPara_DryCycMCDVOffDly   1663           //干循环关模方向阀关延时                         动作后方向阀延时关闭
#define mPara_Mach_1664          1664           //                                    
#define mPara_DryCycMO1PresRamp  1665           //干循环开模1段压力斜率                         干循环开模1段压力斜率
#define mPara_DryCycMO1FlowRamp  1666           //干循环开模1段流量斜率                         干循环开模1段流量斜率
#define mPara_DryCycMO2PresRamp  1667           //干循环开模2段压力斜率                         干循环开模2段压力斜率
#define mPara_DryCycMO2FlowRamp  1668           //干循环开模2段流量斜率                         干循环开模2段流量斜率
#define mPara_DryCycMO3PresRamp  1669           //干循环开模3段压力斜率                         干循环开模3段压力斜率
#define mPara_DryCycMO3FlowRamp  1670           //干循环开模3段流量斜率                         干循环开模3段流量斜率
#define mPara_DryCycMO4PresRamp  1671           //干循环开模4段压力斜率                         干循环开模4段压力斜率
#define mPara_DryCycMO4FlowRamp  1672           //干循环开模4段流量斜率                         干循环开模4段流量斜率
#define mPara_DryCycMO5PresRamp  1673           //干循环开模5段压力斜率                         干循环开模5段压力斜率
#define mPara_DryCycMO5FlowRamp  1674           //干循环开模5段流量斜率                         干循环开模5段流量斜率
#define mPara_DryCycMOEndPresRamp 1675          //干循环开模结束段压力斜率                        干循环开模结束段压力斜率
#define mPara_DryCycMOEndFlowRamp 1676          //干循环开模结束段流量斜率                        干循环开模结束段流量斜率
#define mPara_DryCycMOPVOnDly    1677           //干循环开模比例阀开延时                         干循环开模比例阀开延时
#define mPara_DryCycMODVOffDly   1678           //开模方向阀关延时                            动作后方向阀延时关闭
#define mPara_MCHPPresSuprPres   1679           //锁模力纠偏憋压压力                           
#define mPara_MCHPPresSuprFlow   1680           //锁模力纠偏憋压流量                           
#define mPara_MCHPPresHoldDiff   1681           //锁模力纠偏保持压力差                          
#define mPara_MCHPPresMonSel     1682           //锁模力监控选择                             0-不用 1-使用
#define mPara_MCHPPresMonUpDev   1683           //锁模力监控上偏差                            默认值=机器吨位*40%
#define mPara_MCHPPresMonDnDev   1684           //锁模力监控下偏差                            默认值=机器吨位*40%
#define mPara_MCHPPresHoldSel    1685           //锁模力保持选择                             0-不用 1-使用
#define mPara_MCHPPresHoldUpDev  1686           //锁模力保持上偏差                            默认值=机器吨位*20%
#define mPara_MCHPPresHoldDnDev  1687           //锁模力保持下偏差                            默认值=机器吨位*20%
#define mPara_Mach_1688          1688           //                                    
#define mPara_Mach_1689          1689           //                                    
#define mPara_Zone2UpDevTemp     1690           //2段料管温度上限警报值                         
#define mPara_Zone2DnDevTemp     1691           //2段料管温度下限警报值                         
#define mPara_Zone3UpDevTemp     1692           //3段料管温度上限警报值                         
#define mPara_Zone3DnDevTemp     1693           //3段料管温度下限警报值                         
#define mPara_Zone4UpDevTemp     1694           //4段料管温度上限警报值                         
#define mPara_Zone4DnDevTemp     1695           //4段料管温度下限警报值                         
#define mPara_Zone5UpDevTemp     1696           //5段料管温度上限警报值                         
#define mPara_Zone5DnDevTemp     1697           //5段料管温度下限警报值                         
#define mPara_Zone6UpDevTemp     1698           //6段料管温度上限警报值                         
#define mPara_Zone6DnDevTemp     1699           //6段料管温度下限警报值                         
#define mPara_Zone7UpDevTemp     1700           //7段料管温度上限警报值                         
#define mPara_Zone7DnDevTemp     1701           //7段料管温度下限警报值                         
#define mPara_Zone8UpDevTemp     1702           //8段料管温度上限警报值                         
#define mPara_Zone8DnDevTemp     1703           //8段料管温度下限警报值                         
#define mPara_Zone9UpDevTemp     1704           //9段料管温度上限警报值                         
#define mPara_Zone9DnDevTemp     1705           //9段料管温度下限警报值                         
#define mPara_Zone10UpDevTemp    1706           //10段料管温度上限警报值                        
#define mPara_Zone10DnDevTemp    1707           //10段料管温度下限警报值                        
#define mPara_Zone11UpDevTemp    1708           //11段料管温度上限警报值                        
#define mPara_Zone11DnDevTemp    1709           //11段料管温度下限警报值                        
#define mPara_Zone12UpDevTemp    1710           //12段料管温度上限警报值                        
#define mPara_Zone12DnDevTemp    1711           //12段料管温度下限警报值                        
#define mPara_Zone13UpDevTemp    1712           //13段料管温度上限警报值                        
#define mPara_Zone13DnDevTemp    1713           //13段料管温度下限警报值                        
#define mPara_Zone14UpDevTemp    1714           //14段料管温度上限警报值                        
#define mPara_Zone14DnDevTemp    1715           //14段料管温度下限警报值                        
#define mPara_Zone15UpDevTemp    1716           //15段料管温度上限警报值                        
#define mPara_Zone15DnDevTemp    1717           //15段料管温度下限警报值                        
#define mPara_Zone16UpDevTemp    1718           //16段料管温度上限警报值                        
#define mPara_Zone16DnDevTemp    1719           //16段料管温度下限警报值                        
#define mPara_ESA100SDcCanChan   1720           //日业电储料CAN端口                          
#define mPara_ESA100SDc1Add      1721           //日业电储料CAN站点号                         
#define mPara_Mach_1722          1722           //                                    
#define mPara_Mach_1723          1723           //                                    
#define mPara_Mach_1724          1724           //                                    
#define mPara_Mach_1725          1725           //                                    
#define mPara_Mach_1726          1726           //                                    
#define mPara_Mach_1727          1727           //                                    
#define mPara_Mach_1728          1728           //                                    
#define mPara_Mach_1729          1729           //                                    
#define mPara_Mach_1730          1730           //                                    
#define mPara_Mach_1731          1731           //                                    
#define mPara_Mach_1732          1732           //                                    
#define mPara_Mach_1733          1733           //                                    
#define mPara_Mach_1734          1734           //                                    
#define mPara_Mach_1735          1735           //                                    
#define mPara_Mach_1736          1736           //                                    
#define mPara_Mach_1737          1737           //                                    
#define mPara_Mach_1738          1738           //                                    
#define mPara_Mach_1739          1739           //                                    
#define mPara_Mach_1740          1740           //                                    
#define mPara_Mach_1741          1741           //                                    
#define mPara_Mach_1742          1742           //                                    
#define mPara_Mach_1743          1743           //                                    
#define mPara_Mach_1744          1744           //                                    
#define mPara_Mach_1745          1745           //                                    
#define mPara_Mach_1746          1746           //                                    
#define mPara_Mach_1747          1747           //                                    
#define mPara_Mach_1748          1748           //                                    
#define mPara_Mach_1749          1749           //                                    
#define mPara_Mach_1750          1750           //                                    
#define mPara_Mach_1751          1751           //                                    
#define mPara_Mach_1752          1752           //                                    
#define mPara_Mach_1753          1753           //                                    
#define mPara_Mach_1754          1754           //                                    
#define mPara_Mach_1755          1755           //                                    
#define mPara_Mach_1756          1756           //                                    
#define mPara_Mach_1757          1757           //                                    
#define mPara_Mach_1758          1758           //                                    
#define mPara_Mach_1759          1759           //                                    
#define mPara_Mach_1760          1760           //                                    
#define mPara_Mach_1761          1761           //                                    
#define mPara_Mach_1762          1762           //                                    
#define mPara_Mach_1763          1763           //                                    
#define mPara_Mach_1764          1764           //                                    
#define mPara_Mach_1765          1765           //                                    
#define mPara_Mach_1766          1766           //                                    
#define mPara_Mach_1767          1767           //                                    
#define mPara_MO_RefrArryAdatPos1 1768          //参考参数组1适用机械行程                        
#define mPara_MO_RefrArryAdatPos2 1769          //参考参数组2适用机械行程                        
#define mPara_MiddMoldOpenRamp   1770           //开模中途斜率                              
#define mPara_MiddMoldClsRamp    1771           //关模中途斜率                              
#define mPara_MoldOpenValFlowScale 1772         //开模阀流量降低比例                           开合模比例阀开模时流量降低比例
#define mPara_MoldClsValFlowScale 1773          //关模阀流量降低比例                           开合模比例阀关模时流量降低比例
#define mPara_MoldOpenParaLineGen 1774          //开模参数性线使能                            开模参数性线使能：0-不使能；1-使能
#define mPara_MC_DecePresRamp    1775           //关模压力减速斜率                            关模压力减速斜率
#define mPara_MO_DeceSec1Ramp1   1776           //开模减速1段斜率1                           第1机械行程分段，开模减速1段斜率
#define mPara_MO_DeceSec2Ramp1   1777           //开模减速2段斜率1                           第1机械行程分段，开模减速2段斜率
#define mPara_MO_DeceSec2SFlow1  1778           //开模减速2段启始流量1                         第1机械行程分段，开模减速2段启始流量
#define mPara_MO_DeceBaseFlow1   1779           //开模减速底流量1                            第1机械行程分段，开模减速底流量
#define mPara_MO_DeceSec1Ramp2   1780           //开模减速1段斜率2                           第2机械行程分段，开模减速1段斜率
#define mPara_MO_DeceSec2Ramp2   1781           //开模减速2段斜率2                           第2机械行程分段，开模减速2段斜率
#define mPara_MO_DeceSec2SFlow2  1782           //开模减速2段启始流量2                         第2机械行程分段，开模减速2段启始流量
#define mPara_MO_DeceBaseFlow2   1783           //开模减速底流量2                            第2机械行程分段，开模减速底流量
#define mPara_MO_DeceSec1Ramp3   1784           //开模减速1段斜率3                           第3机械行程分段，开模减速1段斜率
#define mPara_MO_DeceSec2Ramp3   1785           //开模减速2段斜率3                           第3机械行程分段，开模减速2段斜率
#define mPara_MO_DeceSec2SFlow3  1786           //开模减速2段启始流量3                         第3机械行程分段，开模减速2段启始流量
#define mPara_MO_DeceBaseFlow3   1787           //开模减速底流量3                            第3机械行程分段，开模减速底流量
#define mPara_MC_DeceSec1Ramp    1788           //关模减速1段斜率                            关模减速1段斜率
#define mPara_MC_DeceSec2Ramp    1789           //关模减速2段斜率                            关模减速2段斜率
#define mPara_MC_DeceSec2SFlow   1790           //关模减速2段启始流量                          关模减速2段启始流量
#define mPara_MO_DeceDist1       1791           //开模减速距离1                             第1机械行程分段，开模减速距离
#define mPara_MO_DeceDist2       1792           //开模减速距离2                             第2机械行程分段，开模减速距离
#define mPara_MO_DeceDist3       1793           //开模减速距离3                             第3机械行程分段，开模减速距离
#define mPara_MO_AcceDist1       1794           //开模加速距离1                             第1机械行程分段，开模加速距离
#define mPara_MO_AcceDist2       1795           //开模加速距离2                             第2机械行程分段，开模加速距离
#define mPara_MO_AcceDist3       1796           //开模加速距离3                             第3机械行程分段，开模加速距离
#define mPara_MC_AcceDist        1797           //关模加速距离                              关模加速距离
#define mPara_MC_UniformDist     1798           //关模匀速距离                              关模匀速距离
#define mPara_Mach_1799          1799           //                                    
#define mPara_TCTunMode          1800           //温度整定模式                              0-关 1-立整一次所有 2－整一次缓冲区 3-条件符合就整缓冲区 4-条件符合就整所有
#define mPara_TCTunMinHeatTemp   1801           //PID整定最小加热温度                         整定过程加热引起温升应大于该温度值整定才有效
#define mPara_TCTunMinTrgTemp    1802           //PID整定最低目标温度                         PID整定最低目标温度，即整定设置的目标温度应高于该温度
#define mPara_TCTunPCoef         1803           //PID整定时P系数                           PID整定时根据经验公式得到P时，再乘以该系数进行修正
#define mPara_TCTunICoef         1804           //PID整定时I系数                           PID整定时根据经验公式得到I时，再乘以该系数进行修正
#define mPara_TCTunDCoef         1805           //PID整定时D系数                           PID整定时根据经验公式得到D时，再乘以该系数进行修正
#define mPara_TCTunBuffMax       1806           //PID整定缓冲区上限                          整出的缓冲区应小于该值，超则丢弃本次整定
#define mPara_TCTunBuffMin       1807           //PID整定缓冲区下限                          整出的缓冲区应大于该值，超则丢弃本次整定
#define mPara_TCTunBuffOver      1808           //PID整定缓冲区超调量                         整出的缓冲区要略低，该超调量即该故意低的温度
#define mPara_TCTunBuffThre      1809           //PID整定缓冲区起调量                         整出的缓冲区与原先值小于该起调量，则不调整，即保持缓冲区不变
#define mPara_TCPID_MaxUin       1810           //PID单次最大积分量                          PID单次最大积分量，超过按该值累加
#define mPara_TCTunRateThre      1811           //PID整定升温速率门限                         升温速度降到该值时，判断过冲结束，用于缓冲区整定、过冲温度和时间整定
#define mPara_Mach_1812          1812           //                                    
#define mPara_Mach_1813          1813           //                                    
#define mPara_Mach_1814          1814           //                                    
#define mPara_Mach_1815          1815           //                                    
#define mPara_Mach_1816          1816           //                                    
#define mPara_Mach_1817          1817           //                                    
#define mPara_Mach_1818          1818           //                                    
#define mPara_Mach_1819          1819           //                                    
#define mPara_Zone1OnFlag        1820           //1段料筒开启                              X段料筒开启
#define mPara_Zone2OnFlag        1821           //2段料筒开启                              X段料筒开启
#define mPara_Zone3OnFlag        1822           //3段料筒开启                              X段料筒开启
#define mPara_Zone4OnFlag        1823           //4段料筒开启                              X段料筒开启
#define mPara_Zone5OnFlag        1824           //5段料筒开启                              X段料筒开启
#define mPara_Zone6OnFlag        1825           //6段料筒开启                              X段料筒开启
#define mPara_Zone7OnFlag        1826           //7段料筒开启                              X段料筒开启
#define mPara_Zone8OnFlag        1827           //8段料筒开启                              X段料筒开启
#define mPara_Zone9OnFlag        1828           //9段料筒开启                              X段料筒开启
#define mPara_Zone10OnFlag       1829           //10段料筒开启                             X段料筒开启
#define mPara_Zone11OnFlag       1830           //11段料筒开启                             X段料筒开启
#define mPara_Zone12OnFlag       1831           //12段料筒开启                             X段料筒开启
#define mPara_Zone13OnFlag       1832           //13段料筒开启                             X段料筒开启
#define mPara_Zone14OnFlag       1833           //14段料筒开启                             X段料筒开启
#define mPara_Zone15OnFlag       1834           //15段料筒开启                             X段料筒开启
#define mPara_Zone16OnFlag       1835           //16段料筒开启                             X段料筒开启
#define mPara_Zone1TCT_TunTemp   1836           //1段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone2TCT_TunTemp   1837           //2段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone3TCT_TunTemp   1838           //3段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone4TCT_TunTemp   1839           //4段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone5TCT_TunTemp   1840           //5段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone6TCT_TunTemp   1841           //6段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone7TCT_TunTemp   1842           //7段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone8TCT_TunTemp   1843           //8段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone9TCT_TunTemp   1844           //9段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone10TCT_TunTemp  1845           //10段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone11TCT_TunTemp  1846           //11段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone12TCT_TunTemp  1847           //12段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone13TCT_TunTemp  1848           //13段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone14TCT_TunTemp  1849           //14段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone15TCT_TunTemp  1850           //15段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone16TCT_TunTemp  1851           //16段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define mPara_Zone1TCT_HeatRate  1852           //1段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone2TCT_HeatRate  1853           //2段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone3TCT_HeatRate  1854           //3段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone4TCT_HeatRate  1855           //4段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone5TCT_HeatRate  1856           //5段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone6TCT_HeatRate  1857           //6段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone7TCT_HeatRate  1858           //7段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone8TCT_HeatRate  1859           //8段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone9TCT_HeatRate  1860           //9段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone10TCT_HeatRate 1861           //10段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone11TCT_HeatRate 1862           //11段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone12TCT_HeatRate 1863           //12段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone13TCT_HeatRate 1864           //13段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone14TCT_HeatRate 1865           //14段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone15TCT_HeatRate 1866           //15段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone16TCT_HeatRate 1867           //16段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define mPara_Zone1TCT_OverTemp  1868           //1段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone2TCT_OverTemp  1869           //2段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone3TCT_OverTemp  1870           //3段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone4TCT_OverTemp  1871           //4段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone5TCT_OverTemp  1872           //5段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone6TCT_OverTemp  1873           //6段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone7TCT_OverTemp  1874           //7段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone8TCT_OverTemp  1875           //8段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone9TCT_OverTemp  1876           //9段过冲温度                              X段整定得到热惯性引起过冲温度
#define mPara_Zone10TCT_OverTemp 1877           //10段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone11TCT_OverTemp 1878           //11段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone12TCT_OverTemp 1879           //12段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone13TCT_OverTemp 1880           //13段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone14TCT_OverTemp 1881           //14段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone15TCT_OverTemp 1882           //15段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone16TCT_OverTemp 1883           //16段过冲温度                             X段整定得到热惯性引起过冲温度
#define mPara_Zone1TCT_OverTime  1884           //1段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone2TCT_OverTime  1885           //2段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone3TCT_OverTime  1886           //3段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone4TCT_OverTime  1887           //4段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone5TCT_OverTime  1888           //5段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone6TCT_OverTime  1889           //6段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone7TCT_OverTime  1890           //7段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone8TCT_OverTime  1891           //8段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone9TCT_OverTime  1892           //9段过冲时间                              X段整定得到热惯性引起过冲时间
#define mPara_Zone10TCT_OverTime 1893           //10段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone11TCT_OverTime 1894           //11段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone12TCT_OverTime 1895           //12段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone13TCT_OverTime 1896           //13段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone14TCT_OverTime 1897           //14段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone15TCT_OverTime 1898           //15段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone16TCT_OverTime 1899           //16段过冲时间                             X段整定得到热惯性引起过冲时间
#define mPara_Zone1TCPID_P_Dyn   1900           //1段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone2TCPID_P_Dyn   1901           //2段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone3TCPID_P_Dyn   1902           //3段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone4TCPID_P_Dyn   1903           //4段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone5TCPID_P_Dyn   1904           //5段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone6TCPID_P_Dyn   1905           //6段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone7TCPID_P_Dyn   1906           //7段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone8TCPID_P_Dyn   1907           //8段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone9TCPID_P_Dyn   1908           //9段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone10TCPID_P_Dyn  1909           //10段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone11TCPID_P_Dyn  1910           //11段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone12TCPID_P_Dyn  1911           //12段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone13TCPID_P_Dyn  1912           //13段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone14TCPID_P_Dyn  1913           //14段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone15TCPID_P_Dyn  1914           //15段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone16TCPID_P_Dyn  1915           //16段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone1TCPID_P_Sta   1916           //1段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone2TCPID_P_Sta   1917           //2段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone3TCPID_P_Sta   1918           //3段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone4TCPID_P_Sta   1919           //4段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone5TCPID_P_Sta   1920           //5段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone6TCPID_P_Sta   1921           //6段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone7TCPID_P_Sta   1922           //7段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone8TCPID_P_Sta   1923           //8段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone9TCPID_P_Sta   1924           //9段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define mPara_Zone10TCPID_P_Sta  1925           //10段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone11TCPID_P_Sta  1926           //11段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone12TCPID_P_Sta  1927           //12段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone13TCPID_P_Sta  1928           //13段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone14TCPID_P_Sta  1929           //14段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone15TCPID_P_Sta  1930           //15段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone16TCPID_P_Sta  1931           //16段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define mPara_Zone1TempBuff_Up   1932           //1段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone2TempBuff_Up   1933           //2段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone3TempBuff_Up   1934           //3段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone4TempBuff_Up   1935           //4段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone5TempBuff_Up   1936           //5段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone6TempBuff_Up   1937           //6段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone7TempBuff_Up   1938           //7段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone8TempBuff_Up   1939           //8段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone9TempBuff_Up   1940           //9段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define mPara_Zone10TempBuff_Up  1941           //10段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone11TempBuff_Up  1942           //11段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone12TempBuff_Up  1943           //12段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone13TempBuff_Up  1944           //13段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone14TempBuff_Up  1945           //14段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone15TempBuff_Up  1946           //15段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Zone16TempBuff_Up  1947           //16段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define mPara_Mach_1948          1948           //                                    
#define mPara_Mach_1949          1949           //                                    
#define mPara_EtherCATCyc        1950           //EtherCAT通讯周期                        EtherCAT通讯周期
#define mPara_EcSlave1Type       1951           //第1个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave2Type       1952           //第2个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave3Type       1953           //第3个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave4Type       1954           //第4个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave5Type       1955           //第5个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave6Type       1956           //第6个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave7Type       1957           //第7个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcSlave8Type       1958           //第8个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define mPara_EcWRSlave1Bytes    1959           //写第1个EtherCAT从站字节数                   写第1个EtherCAT从站字节数
#define mPara_EcWRSlave2Bytes    1960           //写第2个EtherCAT从站字节数                   写第2个EtherCAT从站字节数
#define mPara_EcWRSlave3Bytes    1961           //写第3个EtherCAT从站字节数                   写第3个EtherCAT从站字节数
#define mPara_EcWRSlave4Bytes    1962           //写第4个EtherCAT从站字节数                   写第4个EtherCAT从站字节数
#define mPara_EcWRSlave5Bytes    1963           //写第5个EtherCAT从站字节数                   写第5个EtherCAT从站字节数
#define mPara_EcWRSlave6Bytes    1964           //写第6个EtherCAT从站字节数                   写第6个EtherCAT从站字节数
#define mPara_EcWRSlave7Bytes    1965           //写第7个EtherCAT从站字节数                   写第7个EtherCAT从站字节数
#define mPara_EcWRSlave8Bytes    1966           //写第8个EtherCAT从站字节数                   写第8个EtherCAT从站字节数
#define mPara_EcRDSlave1Bytes    1967           //读第1个EtherCAT从站字节数                   读第1个EtherCAT从站字节数
#define mPara_EcRDSlave2Bytes    1968           //读第2个EtherCAT从站字节数                   读第2个EtherCAT从站字节数
#define mPara_EcRDSlave3Bytes    1969           //读第3个EtherCAT从站字节数                   读第3个EtherCAT从站字节数
#define mPara_EcRDSlave4Bytes    1970           //读第4个EtherCAT从站字节数                   读第4个EtherCAT从站字节数
#define mPara_EcRDSlave5Bytes    1971           //读第5个EtherCAT从站字节数                   读第5个EtherCAT从站字节数
#define mPara_EcRDSlave6Bytes    1972           //读第6个EtherCAT从站字节数                   读第6个EtherCAT从站字节数
#define mPara_EcRDSlave7Bytes    1973           //读第7个EtherCAT从站字节数                   读第7个EtherCAT从站字节数
#define mPara_EcRDSlave8Bytes    1974           //读第8个EtherCAT从站字节数                   读第8个EtherCAT从站字节数
#define mPara_J6H_Opt            1975           //J6H卡配备                              J6H卡配备几块
#define mPara_InovServoDriverNum 1976           //汇川伺服驱动器实际使用个数                       汇川伺服驱动器实际使用个数
#define mPara_KebServoDriverNum  1977           //KEB伺服驱动器实际使用个数                      KEB伺服驱动器实际使用个数
#define mPara_Mach_1978          1978           //                                    
#define mPara_Mach_1979          1979           //                                    
#define mPara_Mach_1980          1980           //                                    
#define mPara_Mach_1981          1981           //                                    
#define mPara_Mach_1982          1982           //                                    
#define mPara_Mach_1983          1983           //                                    
#define mPara_Mach_1984          1984           //                                    
#define mPara_Mach_1985          1985           //                                    
#define mPara_Mach_1986          1986           //                                    
#define mPara_Mach_1987          1987           //                                    
#define mPara_Mach_1988          1988           //                                    
#define mPara_Mach_1989          1989           //                                    
#define mPara_Mach_1990          1990           //                                    
#define mPara_Mach_1991          1991           //                                    
#define mPara_Mach_1992          1992           //                                    
#define mPara_Mach_1993          1993           //                                    
#define mPara_Mach_1994          1994           //                                    
#define mPara_Mach_1995          1995           //                                    
#define mPara_Mach_1996          1996           //                                    
#define mPara_Mach_1997          1997           //                                    
#define mPara_Mach_1998          1998           //                                    
#define mPara_Mach_1999          1999           //                                    
#define mPara_Mach_2000          2000           //                                    老化测试中用到，尽量避免定义使用
#define mPara_Mach_2001          2001           //                                    老化测试中用到，尽量避免定义使用
#define mPara_Mach_2002          2002           //                                    老化测试中用到，尽量避免定义使用
#define mPara_Mach_2003          2003           //                                    老化测试中用到，尽量避免定义使用
#define mPara_Mach_2004          2004           //                                    
#define mPara_Mach_2005          2005           //                                    
#define mPara_Mach_2006          2006           //                                    
#define mPara_Mach_2007          2007           //                                    
#define mPara_Mach_2008          2008           //                                    
#define mPara_Mach_2009          2009           //                                    
#define mPara_Mach_2010          2010           //                                    
#define mPara_Mach_2011          2011           //                                    
#define mPara_Mach_2012          2012           //                                    
#define mPara_Mach_2013          2013           //                                    
#define mPara_MoldClsEPos        2014           //关模终位置                               锐能：关模终位置，使用油缸位置
#define mPara_MoldClsEPosEN      2015           //关模终位置使能                             锐能：关模终位置有效，即到位采用行程开关+位置
#define mPara_HandSignOpt        2016           //应答信号配备                              锐能：增加一对应答信号，用于驱动器之间握手
#define mPara_CoolMoldOpenEn     2017           //冷却时开模使能                             锐能：冷却时松开模具，避免长时间冷却导致开模困难
#define mPara_Mach_2018          2018           //                                    
#define mPara_Mach_2019          2019           //                                    
#define mPara_MoldOpenSlowValMode 2020          //开模缓冲阀模式                             光塑：mRO_MoldOpenSlow_GS阀的输出模式：0-关闭、1-一慢、2-二慢、3-一慢+二慢
#define mPara_MoldOpenClsMidMode 2021           //开合模中位模式                             宁波汇欣:0-开模5段不输出，1-开模5段输出
#define mPara_SmallMotorZoneChan 2022           //小电机料筒通道                             小电机对应料筒通道，0：关闭；1-16：分别选择1-16段料筒作为小电机通道
#define mPara_SmallMotorOnDly    2023           //小电机输出延时                             
#define mPara_SmallMotSnrChkTi   2024           //小电机检测时间                             
#define mPara_SmallMotSnrFiltTime 2025          //小电机滤波时间                             
#define mPara_Mach_2026          2026           //                                    
#define mPara_Mach_2027          2027           //                                    
#define mPara_Mach_2028          2028           //                                    
#define mPara_ScrewRPMMeasCal    2029           //螺杆转速测量方法                            0-依齿数自动选算法，用“1/t”或“cnt/1s”，1-测一圈用时，然后“1/t*齿数”，满足齿少、且分布不均
#define mPara_Mach_2030          2030           //                                    
#define mPara_Mach_2031          2031           //                                    
#define mPara_Mach_2032          2032           //                                    
#define mPara_Mach_2033          2033           //                                    
#define mPara_MoldClsDiffValOnPos 2034          //差动阀开位置                              博祥塑机：差动阀ON位置(暂保留未用)
#define mPara_MoldClsDiffValOffPos 2035         //差动阀关位置                              博祥塑机：差动阀Off位置
#define mPara_MoldOpenDiffValOnTi 2036          //开模差动阀开时间                            甬辉机械：开模时差动阀用时间控制,关模同标准差动
#define mPara_MoldOpenDiffValOffPos 2037        //开模差动阀关位置                            乐能机械：开模1段时差动阀用位置控制,关模同标准差动
#define mPara_MoldOpenBPLog      2038           //开模背压逻辑                              盈泰：0-小机，开模始计时输出后面不输出；1-大机，开模始计时不输出后面输出
#define mPara_Mach_2039          2039           //                                    
#define mPara_ServoDrvErrSignOpt 2040           //驱动器报警信号配备                           0-无、1－常闭、2－常开
#define mPara_ServoDrvTempStaOpt 2041           //驱动器温度信号配备                           0-无、1-配备
#define mPara_Mach_2042          2042           //                                    
#define mPara_Mach_2043          2043           //                                    
#define mPara_Mach_2044          2044           //                                    
#define mPara_MachSoftLockOpt    2045           //界面主机维护互锁配备                          0-主机不配备 1-主机配备
#define mPara_MachWMProdBatch    2046           //界面生产批号                              
#define mPara_MachWMProdSN       2047           //界面生产序号                              

//机器参数引用宏定义
#define Para_MachParaSum         MachPara[0]    //累加和校验码                              辅助用，下述机器参数累加和
#define Para_MachParaLinkCode    MachPara[1]    //互连代码                                辅助用，机器参数互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效
#define Para_MachParaVer         MachPara[2]    //版本号                                 辅助用，版本号，用于识别建置文件版本是否一致，当重要参数增减时一并修改版本号
#define Para_MachParaID          MachPara[3]    //标识                                  辅助用，与版本号一起用于识别建置文件是否一致，当某个机型的配置有更改时，其标识号应一并修改
#define Para_Mach_4              MachPara[4]    //                                    
#define Para_Mach_5              MachPara[5]    //                                    
#define Para_Mach_6              MachPara[6]    //                                    
#define Para_Mach_7              MachPara[7]    //                                    
#define Para_Mach_8              MachPara[8]    //                                    
#define Para_Mach_9              MachPara[9]    //                                    
#define Para_SysPresMax          MachPara[10]   //系统压力最大值                             除注射动作以外压力最大值
#define Para_InjPresMax          MachPara[11]   //射出压力最大值                             注射1-10的压力最大值
#define Para_MoldClsLPPresMax    MachPara[12]   //关模低压压力最大值                           
#define Para_MoldClsLPFlowMax    MachPara[13]   //关模低压流量最大值                           
#define Para_MoldClsHPFlowMax    MachPara[14]   //关模高压流量最大值                           
#define Para_MoldOpen1PresMax    MachPara[15]   //开模一慢压力最大值                           
#define Para_MoldOpen1FlowMax    MachPara[16]   //开模一慢流量最大值                           
#define Para_MoldAdjPresMax      MachPara[17]   //调模压力上限                              调模进、退压力最大值
#define Para_MoldAdjFlowMax      MachPara[18]   //调模流量上限                              调模进、退流量最大值
#define Para_NozForMaxPres       MachPara[19]   //座台进压力最大值                            
#define Para_NozMaxFlow          MachPara[20]   //座台流量最大值                             
#define Para_SuckBackPresMax     MachPara[21]   //射退压力最大值                             
#define Para_SuckBackFlowMax     MachPara[22]   //射退流量最大值                             
#define Para_EjePresMax          MachPara[23]   //托模压力最大值                             
#define Para_EjeFlowMax          MachPara[24]   //托模流量最大值                             
#define Para_CorePresMax         MachPara[25]   //中子压力最大值                             
#define Para_CoreFlowMax         MachPara[26]   //中子流量最大值                             
#define Para_ChgPresMax          MachPara[27]   //储料压力最大值                             
#define Para_ChgFlowMax          MachPara[28]   //储料流量最大值                             
#define Para_BackPresMax         MachPara[29]   //背压压力最大值                             用于生产画面中储料背压的限值，背压阀的最大压力取决于下面的“背压阀压力最大值”
#define Para_NozRetMaxPres       MachPara[30]   //座台退压力最大值                            
#define Para_ChgFlowEnMax        MachPara[31]   //储料流量允许最大值                           设定储料流量大于此值，按此值输出，主要是因天剑机器缺陷而加。
#define Para_BackPresValMax      MachPara[32]   //背压阀压力最大值                            背压比例阀的最大压力
#define Para_HoldPresPresMax     MachPara[33]   //保压压力最大值                             保压1-10的压力最大值
#define Para_MoldClsHPPresMax    MachPara[34]   //关模高压压力最大值                           
#define Para_FrontSGUnClsDisSemiAuto MachPara[35]//前安全门未关禁止半自动                        0-允许 1-禁止   前安全门未关禁止半自动
#define Para_SafeGateFront2Opt   MachPara[36]   //安全门二关配备                             0-没有 1-有
#define Para_SafeGateBackOpt     MachPara[37]   //后安全门配备                              0-没有 1-有
#define Para_SafeGateTopOpt      MachPara[38]   //上顶盖配备                               0-没有 1-有
#define Para_SafeGateButOpt      MachPara[39]   //底板安全门配备                             0-没有 1-有
#define Para_NozSafeGateOpt      MachPara[40]   //射嘴防护罩配备                             0-没有 1-有
#define Para_EjeRetEndSnrOpt     MachPara[41]   //托退终行程开关配备                           0-没有 1-有
#define Para_HopperSnrOpt        MachPara[42]   //料斗检知配备                              0-没有 1-有
#define Para_MoldAdjSnrOpt       MachPara[43]   //调模电眼配备                              0-没有 1-有，无调模电眼时禁止自动调模
#define Para_MachProtSnrOpt      MachPara[44]   //机械保险检测配备                            0-没有 1-有，HT常规机械保险
#define Para_HydProtSnrOpt       MachPara[45]   //液压保险检测配备                            0-没有 1-有，HT常规液压保险
#define Para_CycStartKeyOpt      MachPara[46]   //循环启动键配备                             0-没有 1-有
#define Para_AirSrcPresSnrOpt    MachPara[47]   //气源压力检测配备                            0-没有 1-有，气动机械保险时气源压力检测
#define Para_CycStopKeyOpt       MachPara[48]   //循环停止键配备                             0-没有 1-有，循环停止键：平时为1，自动方式时如变为0，则转手动
#define Para_BackPresPVOpt       MachPara[49]   //背压比例阀配备                             0-没有 1-有
#define Para_AccOpt              MachPara[50]   //蓄能器配备                               0-没有 1-有
#define Para_AirInjOpt           MachPara[51]   //气辅射出配备                              0-没有 1-有
#define Para_Lubr2Opt            MachPara[52]   //润滑2配备                               0-没有 1-有
#define Para_ExhaustOpt          MachPara[53]   //热固机配备                               0-没有 1-有
#define Para_LinkOilWayOpt       MachPara[54]   //连动油路配备                              0-没有 1-有
#define Para_PilotOilAccOpt      MachPara[55]   //先导油储能器配备                            0-没有 1-有，先导油储能器配备，用于中大机合模区安全
#define Para_MoldClsFastOpt      MachPara[56]   //关模快速油路配备                            0-没有 1-有
#define Para_MoldOpenFastOpt     MachPara[57]   //开模快速油路配备                            0-没有 1-有
#define Para_InjFastOpt          MachPara[58]   //注射快速油路配备                            0-没有 1-有
#define Para_JigType             MachPara[59]   //模具夹具类型                              0-无 1-液压 2-(磁力)……
#define Para_CanModuleOpt        MachPara[60]   //CAN模块配备                             通过CAN总线扩展的CAN模块是否配备
#define Para_TieRodsMonOpt       MachPara[61]   //拉杆受力监测配备                            0-没有 1-有
#define Para_NozSnrOpt           MachPara[62]   //座台尺配备                               0-没有 1-有
#define Para_MotTempSnrOpt       MachPara[63]   //马达测温配备                              0-没有 1-有
#define Para_ServoDrvOpt         MachPara[64]   //驱动器配备                               驱动器配备选项，主要影响电机使能信号、风扇信号、温度信号、异常信号
#define Para_ToggleProtSnrOpt    MachPara[65]   //曲肘防护配备                              0-没有 1-有
#define Para_OilLessSnrOpt       MachPara[66]   //油位传感器配备                             0-没有 1-有
#define Para_OilLessSnrLog       MachPara[67]   //油位传感器逻辑                             0-正逻辑(ON-油位低、Off-油位正常)、1-负逻辑(ON-油位正常、OFF-油位低)
#define Para_J5_PID_DA_Sel       MachPara[68]   //J5_PID_DA选择                         0-关闭 1-使用，J5多组PID功能通过DA通道实现
#define Para_J5_PID_CAN_Sel      MachPara[69]   //J5_PID_CAN选择                        0-关闭 1-使用，J5多组PID功能通过CAN通讯实现
#define Para_MotorOnMode         MachPara[70]   //马达开启模式                              0-星三角启动  1-直接启动  2-直接启动且MOTON继电器保持输出
#define Para_MoldSnrInCyl        MachPara[71]   //模板尺安装在油缸上                           模板尺安装位置：0-模板 1-油缸
#define Para_LubrMode            MachPara[72]   //自动润滑模式                              0-定阻 1-定量加压 2-定次（只支持2-定次）
#define Para_Lubr1OilLessSnrType MachPara[73]   //润滑1油位传感器类型                          0-没有 1-常闭油位正常 2-常开油位正常
#define Para_GRYLightMode        MachPara[74]   //三色报警灯模式                             0-国标 1-欧标
#define Para_HydNozType          MachPara[75]   //液压喷嘴类型                              0-没有 1-单向 2-双向
#define Para_PumpType            MachPara[76]   //泵类型                                 0-叠加泵 1-组合泵
#define Para_ScrewRPMSnrGear     MachPara[77]   //螺杆转速盘齿数                             
#define Para_ScrewRPMSoftCnt     MachPara[78]   //螺杆转速软件计数                            若螺杆电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define Para_MoldAdjSnrSoftCnt   MachPara[79]   //调模电眼用软件计数                           若调模电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define Para_ProdSnrSoftTri      MachPara[80]   //检物电眼软件触发                            若检物电眼在CAN模块，即无硬件计数器，则需此项为1，且硬件配置中删去计数资源关联
#define Para_OilPreHtrMode       MachPara[81]   //油温预热模式                              0-正常,1-二级预热(主要针对海天J5机),2～9-保留
#define Para_CoreNum             MachPara[82]   //中子组数                                0-没有 N-1～N组有效
#define Para_AirNum              MachPara[83]   //吹气组数                                0-没有 N-1～N组有效
#define Para_InjectNum           MachPara[84]   //注射段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到6段)
#define Para_HoldPresNum         MachPara[85]   //保压段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到6段)
#define Para_ChargeNum           MachPara[86]   //储料段数                                0-没有 N-1～N组有效(主机程序允许到10段、Q8C画面允许到5段)
#define Para_MoldCls3Sel         MachPara[87]   //关模3段选择                              0-不用 1-使用
#define Para_MoldOpen3Sel        MachPara[88]   //开模3段选择                              0-不用 1-使用
#define Para_MCEjeOnSel          MachPara[89]   //关模时托退阀开选择                           1-开：无论顶针用否，关模时顶针吸一下，持续“关模时托退阀开时间”；0-不开：只在顶针不用，关模时吸
#define Para_AlarmEjePcs         MachPara[90]   //警报时顶针处理                             闲转手动警报时托模(不含连动)处理:0-顶出 1-注射失败则不顶出 2-闲转手动警报则不顶出
#define Para_AMMoldClsSGOpenPcs  MachPara[91]   //关模中安全门打开处理                          自动时关模安全门打开：0-立停 1-开模后结束 2-开模等再次关门
#define Para_SGBackOpenPcs       MachPara[92]   //后安全门打开处理                            0-不影响 1、2-转手动 3、4-转手动且切马达(2、4如前安全门开则不影响)
#define Para_SGOpenEnEjeFor      MachPara[93]   //安全门开允许托进                            0-不允许 1-允许（下面还有一个“安全门未关禁止托退”参数）
#define Para_ProdDropEjeFin      MachPara[94]   //电眼检物结束托模                            1-电眼方式时，检查到物品掉落，立即结束托模
#define Para_ManuModeDisLink     MachPara[95]   //手动模式下禁止连动                           0-手动方式下，开、关模时连动会进行 1-不会进行
#define Para_MCHPPresMeasMode    MachPara[96]   //锁模压力测量模式                            0-高压锁模时测量、1-高压锁模延时后再测量
#define Para_MCHPPresMeasDly     MachPara[97]   //锁模压力测量延时                            
#define Para_LinkPumpSel         MachPara[98]   //连动时泵选择                              连动时对应需要一起开启的泵选择，0-无泵打开、1-泵一、2-泵二……
#define Para_EjeCutMatFunEn      MachPara[99]   //托模切料功能允许                            0-禁止,1-允许,即在注射或保压的某时机,托模进一点，以切断料柄
#define Para_DrvEnSigRstDrv      MachPara[100]  //通过使能信号复位驱动器                         1-驱动器警报时，通过断开使能信号来复位驱动器
#define Para_SnrDropTi           MachPara[101]  //电眼检物时间                              电眼检物时间
#define Para_MCEjeOnTi           MachPara[102]  //关模时托退阀开时间                           顶针不用时，关模时顶针吸一下
#define Para_HydProtChkDly       MachPara[103]  //液压保护检查延时                            液压保护检查延迟时间，HT常规液压保险时逻辑
#define Para_HydProtLog          MachPara[104]  //液压保险逻辑                              0-小机(门开有信号) 1-大机(门关有信号)，HT常规液压保险时逻辑 2-关模时常闭 3-关模时常开
#define Para_AutoGateOpt         MachPara[105]  //自动安全门配备                             0-未配备 1-配备
#define Para_AutoGateType        MachPara[106]  //自动安全门类型                             1-KEB门机     其它待定义
#define Para_AutoMoniStdDataGenMode MachPara[107]//监测数据生成方式                           0-自动采样 1-用户设置 2-用户设置+自动采样
#define Para_HADPriNum           MachPara[108]  //HAD优先级数                             0-1路优先 1-2路优先
#define Para_PropValRampMode     MachPara[109]  //比例阀斜率模式                             0-(目标-当前)/时间 1-最大值/时间
#define Para_MoldClsFlowScale    MachPara[110]  //关模流量降低比例                            关模时，实际流量为设定值乘以该比例
#define Para_MoldOpenFlowScale   MachPara[111]  //开模流量降低比例                            开模时，实际流量为设定值乘以该比例
#define Para_PVOutDispMode       MachPara[112]  //比例阀输出显示模式                           0-显示当前实际输出值（可以看到斜率过程） 1-显示目标值
#define Para_PropValCurrMeasOpt  MachPara[113]  //比例阀电流测量配备                           T6F3控制器配备阀电流测量电路，可以监控比例阀的电流
#define Para_PropValCurrEnDev    MachPara[114]  //比例阀电流允许偏差                           比例阀测得电流 + 本偏差 >设置输出电流，则报警。其中，设置输出电流=1000mA*占空比
#define Para_FlowFBCtrl_Inj      MachPara[115]  //注射流量闭环选择                            1-注射一～十时（仅标准注射、不包括保压），“FlowFeedBackCtrl 流量闭环”信号ON
#define Para_FlowFBCtrl_MO1      MachPara[116]  //开模一慢流量闭环选择                          1-开模一慢时（仅标准开模），“FlowFeedBackCtrl 流量闭环”信号ON
#define Para_FlowFBCtrl_MCHP     MachPara[117]  //关模高压流量闭环选择                          1-关模高压时（仅标准关模），“FlowFeedBackCtrl 流量闭环”信号ON
#define Para_InjPropValMargin    MachPara[118]  //注射比例阀裕度                             特殊注射比例阀，系统压力、流量适当提高，以使该比例阀稳定控制输出
#define Para_EjectFlowScale      MachPara[119]  //顶针流量降低比例                            顶针时，实际流量为设定值乘以该比例
#define Para_R_RobotRetEndOpt    MachPara[120]  //机械手回到位配备                            简易机械手、Start
#define Para_R_RobotOptModeOpt   MachPara[121]  //机械手不用配备                             Euro 67/12
#define Para_R_EmerStopOpt       MachPara[122]  //机械手紧停配备                             Euro 67/12、Start
#define Para_R_CycStartOpt       MachPara[123]  //循环启动配备                              Start
#define Para_R_MoldAreaFreeOpt   MachPara[124]  //模区安全配备                              Euro 67/12
#define Para_R_EnClampOpt        MachPara[125]  //关模允许配备                              Euro 67/12
#define Para_R_EnMoldOpenOpt     MachPara[126]  //开模允许配备                              Start
#define Para_R_EnFullMoldOpenOpt MachPara[127]  //全开模允许配备                             Euro 67/12
#define Para_R_EnEjeForOpt       MachPara[128]  //托模进允许配备                             Euro 67/12、Start
#define Para_R_EnEjeRetOpt       MachPara[129]  //托模退允许配备                             Euro 67/12、Start
#define Para_R_EnCoreInOpt       MachPara[130]  //中子进允许配备                             Euro 67/12
#define Para_R_EnCoreOutOpt      MachPara[131]  //中子退允许配备                             Euro 67/12
#define Para_ChgFlowScale        MachPara[132]  //储料流量降低比例                            储料时，实际流量为设定值乘以该比例
#define Para_HoldPresPropRelPresDiff MachPara[133]//保压溢流压力差                           暂主要用于双节机，保压动作时比例溢流阀降低输出的压力值
#define Para_BMCOpt              MachPara[134]  //BMC功能配备                             0-未配备 1-配备
#define Para_SteamInjOpt         MachPara[135]  //蒸汽注射配备                              0-未配备 1-配备
#define Para_MoldThickSnrOpt     MachPara[136]  //模厚尺配备                               0-未配备 1-配备
#define Para_MoldThickMax        MachPara[137]  //最大模厚                                机器容纳模具最大尺寸
#define Para_MoldThickMin        MachPara[138]  //最小模厚                                机器容纳模具最小尺寸
#define Para_InjPresSnrOpt       MachPara[139]  //注射压力传感器配备                           0-未配备 1-配备,主要界面使用，影响“压力转保压”是否有效及主画面显示注射压力
#define Para_ZoneTempMax         MachPara[140]  //料筒温度最大值                             料筒允许最高温度，超过则报警、停电热
#define Para_ZoneTempDispCalK    MachPara[141]  //温度显示修正系数                            温度显示用：当实测温度超出时，超出部分乘以该系数送画面显示
#define Para_GB_SafeRelayRstChk  MachPara[142]  //安全继电器复位检查                           0-不用 1-检查   检查安全继电器是否正确复位   
#define Para_GB_HydProtStd       MachPara[143]  //液压检测安全标准                            液压检测安全标准 0-不用 1-模式一
#define Para_GB_NozGateLoopChk   MachPara[144]  //防护罩安全回路检查                           注射防护罩安全回路检查 0-不用 1-模式一
#define Para_NozGateUnClsDisInj  MachPara[145]  //防护罩未关禁止注射                           0-允许 1-禁止   主要用于GB22530安全标准
#define Para_NozGateUnClsDisChg  MachPara[146]  //防护罩未关禁止储料                           0-允许 1-禁止   主要用于GB22530安全标准
#define Para_NozGateUnClsDisNozFor MachPara[147]//防护罩未关禁止座进                           0-允许 1-禁止   主要用于GB22530安全标准
#define Para_FrontSGUnClsDisAuto MachPara[148]  //前安全门未关禁止自动                          0-允许 1-禁止   主要用于GB22530安全标准，如果是半自动则不受影响
#define Para_FrontSGUnClsDisInj  MachPara[149]  //前安全门未关禁止注射                          0-允许 1-禁止   主要用于GB22530安全标准
#define Para_FrontSGUnClsDisChg  MachPara[150]  //前安全门未关禁止储料                          0-允许 1-禁止,与"是否已经安装模具"参数配合,主要用于GB22530安全标准
#define Para_FrontSGUnClsDisNozFor MachPara[151]//前安全门未关禁止座进                          0-允许 1-禁止   主要用于GB22530安全标准
#define Para_SGUnClsDisMoldThin  MachPara[152]  //安全门未关禁止调模进                          0-允许 1-禁止
#define Para_SGUnClsDisCoreIn    MachPara[153]  //安全门未关禁止中子进                          0-允许 1-禁止
#define Para_SGUnClsDisCoreOut   MachPara[154]  //安全门未关禁止中子出                          0-允许 1-禁止
#define Para_SGUnClsDisEjeRet    MachPara[155]  //安全门未关禁止托模退                          0-允许 1-禁止
#define Para_SGUnClsDisMoldThick MachPara[156]  //安全门未关禁止调模退                          0-允许 1-禁止
#define Para_FrontSGUnClsDisChg_ExSemi MachPara[157]//半自动前门开允许储料                      0-半自动禁止储料 1-半自动允许储料，画面显示"是否已经安装模"  主要用于GB22530安全标准
#define Para_CANModuleCANPort    MachPara[158]  //扩展模块CAN端口                           0-CAN1、1-CAN2
#define Para_Lubr2OilLessSnrType MachPara[159]  //润滑2油位传感器类型                          0-没有 1-常闭油位正常 2-常开油位正常
#define Para_AutoGateOpenStrokeMax MachPara[160]//自动门开门距离(上限)                         
#define Para_AutoGateOpenStrokeMin MachPara[161]//自动门开门距离(下限)                         
#define Para_AutoGateOpenDistance MachPara[162] //自动门开门距离                             
#define Para_MotorErrOpt         MachPara[163]  //电机异常检测配备                            1-"PC 电机异常"输入点配备，当该点为OFF时，警报"电机相位或风扇异常"
#define Para_VarPumpQuanPumpSys  MachPara[164]  //变量泵+定量泵系统                           6500V以上变量泵机器，动力为“变量泵+定量泵”，泵仅在大流量动作时才检查输出
#define Para_SysFlowMeasSnrSel   MachPara[165]  //系统流量对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealFlow(由CAN从驱动器直接读取)
#define Para_SysPresMeasSnrSel   MachPara[166]  //系统压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define Para_InjPresMeasSnrSel   MachPara[167]  //注射压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define Para_MoldPresMeasSnrSel  MachPara[168]  //模板压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define Para_LinkPresMeasSnrSel  MachPara[169]  //联动压力对应传感器                           0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)、5-MD6卡
#define Para_ScrewSnrLen         MachPara[170]  //螺杆尺长度                               螺杆尺长度
#define Para_ScrewSnrZero        MachPara[171]  //螺杆尺零点                               螺杆尺零点位置，必须紧跟在长度后面，长度校准时要求
#define Para_ScrewSnrStroke      MachPara[172]  //螺杆机械行程                              螺杆尺机械行程
#define Para_MoldSnrLen          MachPara[173]  //模板尺长度                               模板尺长度
#define Para_MoldSnrZero         MachPara[174]  //模板尺零点                               模板尺零点位置，必须紧跟在长度后面，长度校准时要求
#define Para_MoldSnrStroke       MachPara[175]  //模板机械行程                              模板尺机械行程
#define Para_EjeSnrLen           MachPara[176]  //顶针尺长度                               顶针尺长度
#define Para_EjeSnrZero          MachPara[177]  //顶针尺零点                               顶针尺零点位置，必须紧跟在长度后面，长度校准时要求
#define Para_EjeSnrStroke        MachPara[178]  //顶针机械行程                              顶针尺机械行程
#define Para_NozSnrLen           MachPara[179]  //座台尺长度                               座台尺长度
#define Para_NozSnrZero          MachPara[180]  //座台尺零点                               座台尺零点位置，必须紧跟在长度后面，长度校准时要求
#define Para_NozSnrStroke        MachPara[181]  //座台机械行程                              座台尺机械行程
#define Para_HAI1Len             MachPara[182]  //模拟量1长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define Para_HAI1Zero            MachPara[183]  //模拟量1零点                              模拟量0V电压对应的值
#define Para_HAI1Stroke          MachPara[184]  //模拟量1限值                              模拟量对应的限值
#define Para_HAI2Len             MachPara[185]  //模拟量2长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define Para_HAI2Zero            MachPara[186]  //模拟量2零点                              模拟量0V电压对应的值
#define Para_HAI2Stroke          MachPara[187]  //模拟量2限值                              模拟量对应的限值
#define Para_HAI3Len             MachPara[188]  //模拟量3长度                              模拟量10V电压对应的值（注：模拟量对应的含义取决于“注射压力对应传感器”等参数）
#define Para_HAI3Zero            MachPara[189]  //模拟量3零点                              模拟量0V电压对应的值
#define Para_HAI3Stroke          MachPara[190]  //模拟量3限值                              模拟量对应的限值
#define Para_MoldThickSnrLen     MachPara[191]  //模厚尺长度                               模厚尺长度
#define Para_MoldThickSnrZero    MachPara[192]  //模厚尺零点                               模厚尺零点位置，必须紧跟在长度后面，长度校准时要求
#define Para_MoldThickSnrStroke  MachPara[193]  //模厚尺机械行程                             模厚尺机械行程,预留，实际用不到
#define Para_MoldThickSnrOffset  MachPara[194]  //模厚尺偏移                               模厚尺偏移值：模厚不可能为0，即归零点已经有一定的模厚了，即此偏移值
#define Para_CANForwardCANPort   MachPara[195]  //CAN转发端口                             与BOX通讯：0-关闭、1-CAN1、2-CAN2
#define Para_ProdTaskFinPcs      MachPara[196]  //生产任务单完成处理                           针对管工厂，产品数到时：0-不处理 1-提示 2-结束生产
#define Para_FilterSen0Log       MachPara[197]  //滤油网检测0#逻辑                           0-不检查 1-常开 2-常闭
#define Para_FilterSen0ChkTemp   MachPara[198]  //滤油网检测0#检测温度                         
#define Para_LastCoolProtFlag    MachPara[199]  //                                    上次断电时的防冷启状态
#define Para_TempCalB_N          MachPara[200]  //温度校准调低B                             温度校准调低的度数
#define Para_TempCalB_P          MachPara[201]  //温度校准调高B                             温度校准调高的度数
#define Para_TempCalK            MachPara[202]  //温度校准K                               有效范围0.85-1.15，超此范围则为1.00
#define Para_TempCtrlIntegRange  MachPara[203]  //PID控温积分范围                           PID控温积分范围,温在此参数偏差之内进行积分计算
#define Para_TempCtrlPIDSel      MachPara[204]  //PID控温算法选择                           0-适用普通热筒  1-适用大惯性模具
#define Para_TempCtrlPID0HtrScale MachPara[205] //PID控温算法0加热系数                        在TempCon_PID_Sel=0时有效
#define Para_TempCtrlPID1HtrScale MachPara[206] //PID控温算法1加热系数                        在TempCon_PID_Sel=1时有效
#define Para_Mach_207            MachPara[207]  //                                    
#define Para_Zone1TCPID_P        MachPara[208]  //PID控温算法P                            
#define Para_Zone1TCPID_I        MachPara[209]  //PID控温算法I                            
#define Para_Zone1TCPID_D        MachPara[210]  //PID控温算法D                            
#define Para_Zone2TCPID_P        MachPara[211]  //PID控温算法P                            
#define Para_Zone2TCPID_I        MachPara[212]  //PID控温算法I                            
#define Para_Zone2TCPID_D        MachPara[213]  //PID控温算法D                            
#define Para_Zone3TCPID_P        MachPara[214]  //PID控温算法P                            
#define Para_Zone3TCPID_I        MachPara[215]  //PID控温算法I                            
#define Para_Zone3TCPID_D        MachPara[216]  //PID控温算法D                            
#define Para_Zone4TCPID_P        MachPara[217]  //PID控温算法P                            
#define Para_Zone4TCPID_I        MachPara[218]  //PID控温算法I                            
#define Para_Zone4TCPID_D        MachPara[219]  //PID控温算法D                            
#define Para_Zone5TCPID_P        MachPara[220]  //PID控温算法P                            
#define Para_Zone5TCPID_I        MachPara[221]  //PID控温算法I                            
#define Para_Zone5TCPID_D        MachPara[222]  //PID控温算法D                            
#define Para_Zone6TCPID_P        MachPara[223]  //PID控温算法P                            
#define Para_Zone6TCPID_I        MachPara[224]  //PID控温算法I                            
#define Para_Zone6TCPID_D        MachPara[225]  //PID控温算法D                            
#define Para_Zone7TCPID_P        MachPara[226]  //PID控温算法P                            
#define Para_Zone7TCPID_I        MachPara[227]  //PID控温算法I                            
#define Para_Zone7TCPID_D        MachPara[228]  //PID控温算法D                            
#define Para_Zone8TCPID_P        MachPara[229]  //PID控温算法P                            
#define Para_Zone8TCPID_I        MachPara[230]  //PID控温算法I                            
#define Para_Zone8TCPID_D        MachPara[231]  //PID控温算法D                            
#define Para_Zone9TCPID_P        MachPara[232]  //PID控温算法P                            
#define Para_Zone9TCPID_I        MachPara[233]  //PID控温算法I                            
#define Para_Zone9TCPID_D        MachPara[234]  //PID控温算法D                            
#define Para_Zone10TCPID_P       MachPara[235]  //PID控温算法P                            
#define Para_Zone10TCPID_I       MachPara[236]  //PID控温算法I                            
#define Para_Zone10TCPID_D       MachPara[237]  //PID控温算法D                            
#define Para_Zone11TCPID_P       MachPara[238]  //PID控温算法P                            
#define Para_Zone11TCPID_I       MachPara[239]  //PID控温算法I                            
#define Para_Zone11TCPID_D       MachPara[240]  //PID控温算法D                            
#define Para_Zone12TCPID_P       MachPara[241]  //PID控温算法P                            
#define Para_Zone12TCPID_I       MachPara[242]  //PID控温算法I                            
#define Para_Zone12TCPID_D       MachPara[243]  //PID控温算法D                            
#define Para_Zone13TCPID_P       MachPara[244]  //PID控温算法P                            
#define Para_Zone13TCPID_I       MachPara[245]  //PID控温算法I                            
#define Para_Zone13TCPID_D       MachPara[246]  //PID控温算法D                            
#define Para_Zone14TCPID_P       MachPara[247]  //PID控温算法P                            
#define Para_Zone14TCPID_I       MachPara[248]  //PID控温算法I                            
#define Para_Zone14TCPID_D       MachPara[249]  //PID控温算法D                            
#define Para_Zone15TCPID_P       MachPara[250]  //PID控温算法P                            
#define Para_Zone15TCPID_I       MachPara[251]  //PID控温算法I                            
#define Para_Zone15TCPID_D       MachPara[252]  //PID控温算法D                            
#define Para_Zone16TCPID_P       MachPara[253]  //PID控温算法P                            
#define Para_Zone16TCPID_I       MachPara[254]  //PID控温算法I                            
#define Para_Zone16TCPID_D       MachPara[255]  //PID控温算法D                            
#define Para_HeatUpPowerScale    MachPara[256]  //快升功率比例                              快升阶段加热功率下降比例
#define Para_Mach_257            MachPara[257]  //                                    
#define Para_HCIS300ServoDrv1Opt MachPara[258]  //汇川IS300伺服驱动器1配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define Para_HCIS300ServoDrv2Opt MachPara[259]  //汇川IS300伺服驱动器2配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define Para_HCIS300ServoDrv3Opt MachPara[260]  //汇川IS300伺服驱动器3配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define Para_HCIS300ServoDrv4Opt MachPara[261]  //汇川IS300伺服驱动器4配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define Para_HCIS300ServoDrv5Opt MachPara[262]  //汇川IS300伺服驱动器5配备                     汇川IS300伺服驱动器配备，该驱动器允许CAN接口，Para_ServoDrvOpt也要为开启
#define Para_HCIS300ServoDrv1Mode MachPara[263] //汇川IS300伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define Para_HCIS300ServoDrv2Mode MachPara[264] //汇川IS301伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define Para_HCIS300ServoDrv3Mode MachPara[265] //汇川IS302伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define Para_HCIS300ServoDrv4Mode MachPara[266] //汇川IS303伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define Para_HCIS300ServoDrv5Mode MachPara[267] //汇川IS304伺服驱动器接口模式                    0-完全CAN模式 1-CAN设置模式(只修改设置、通过DA控制输出)，暂未使用
#define Para_HCIS300ServoDrvCANPort MachPara[268]//汇川IS300伺服驱动器CAN端口                  0-CAN1、1-CAN2
#define Para_Mach_269            MachPara[269]  //                                    
#define Para_SDCanBanud          MachPara[270]  //波特率选择                               
#define Para_SDCanAddr           MachPara[271]  //CAN通讯地址                             
#define Para_SDCanBrkTime        MachPara[272]  //CAN连续通讯时间                           即通讯中断检测时间，检出则结束输出、报ERR42故障
#define Para_SDCtrlMode          MachPara[273]  //油压控制方式                              0-非油压控制模式 1-由CAN控制 2-由模拟通道控制 3-CAN油压模式(专用)
#define Para_SDMotType           MachPara[274]  //电机类型选择                              0-普通异步 1-变频异步 2-永磁同步伺服
#define Para_SDMotRatedPwr       MachPara[275]  //额定功率                                
#define Para_SDMotRatedVol       MachPara[276]  //额定电压                                
#define Para_SDMotRatedCurr      MachPara[277]  //额定电流                                
#define Para_SDMotRatedFrq       MachPara[278]  //额定频率                                
#define Para_SDMotRatedSpd       MachPara[279]  //额定转速                                
#define Para_SDResPolPair        MachPara[280]  //旋转变压器极对数                            
#define Para_Mach_281            MachPara[281]  //                                    
#define Para_SDAI1MinVol         MachPara[282]  //AI1最小输入                             
#define Para_SDAI1MinValue       MachPara[283]  //AI1最小输入对应设定                         
#define Para_SDAI1MaxVol         MachPara[284]  //AI1最大输入                             
#define Para_SDAI1MaxValue       MachPara[285]  //AI1最大输入对应设定                         
#define Para_SDAI1FiltTime       MachPara[286]  //AI1输入滤波时间                           
#define Para_SDAI2MinVol         MachPara[287]  //AI2最小输入                             
#define Para_SDAI2MinValue       MachPara[288]  //AI2最小输入对应设定                         
#define Para_SDAI2MaxVol         MachPara[289]  //AI2最大输入                             
#define Para_SDAI2MaxValue       MachPara[290]  //AI2最大输入对应设定                         
#define Para_SDAI2FiltTime       MachPara[291]  //AI2输入滤波时间                           
#define Para_SDAI3MinVol         MachPara[292]  //AI3最小输入                             
#define Para_SDAI3MinValue       MachPara[293]  //AI3最小输入对应设定                         
#define Para_SDAI3MaxVol         MachPara[294]  //AI3最大输入                             
#define Para_SDAI3MaxValue       MachPara[295]  //AI3最大输入对应设定                         
#define Para_SDAI3FiltTime       MachPara[296]  //AI3输入滤波时间                           
#define Para_SDPresSensErrTime   MachPara[297]  //油压传感器故障检测时间                         
#define Para_SDPresSensMaxPres   MachPara[298]  //压力传感器压力量程                           
#define Para_Mach_299            MachPara[299]  //                                    
#define Para_SDSysMaxSpeed       MachPara[300]  //最大转速                                对应系统输出流量设定电机运行的最高转速
#define Para_SDSysMaxPres        MachPara[301]  //系统油压                                
#define Para_SDMaxBrakSpeed      MachPara[302]  //最大反向转速                              
#define Para_SDUnderFlow         MachPara[303]  //底流                                  
#define Para_SDUnderPres         MachPara[304]  //底压                                  
#define Para_Mach_305            MachPara[305]  //                                    
#define Para_SDDAxisInd          MachPara[306]  //D轴电感                                
#define Para_SDQAxisInd          MachPara[307]  //Q轴电感                                
#define Para_SDStatorRes         MachPara[308]  //定子电阻                                
#define Para_SDMotIndResUnit     MachPara[309]  //单位                                  
#define Para_SDBackVol           MachPara[310]  //反电动势                                
#define Para_SDCoderAngle        MachPara[311]  //编码器安装角度                             
#define Para_Mach_312            MachPara[312]  //                                    
#define Para_SDPID_SuckBack      MachPara[313]  //射退动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_HoldPres      MachPara[314]  //保压动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SpdWaveAveFiltEn    MachPara[315]  //速度曲线平均滤波                            速度曲线平均滤波次数
#define Para_SpdWaveFiltEn       MachPara[316]  //速度曲线滑动滤波                            速度曲线滑动滤波次数
#define Para_Mach_317            MachPara[317]  //                                    
#define Para_CoreFlowScale       MachPara[318]  //中子流量降低比例                            中子时，实际流量为设定值乘以该比例
#define Para_InjectFlowScale     MachPara[319]  //注射流量降低比例                            注射时，实际流量为设定值乘以该比例
#define Para_SDInjActRespLevel   MachPara[320]  //注射动作响应模式                            0-平稳S 1-均衡M 2-快速F，主要是油压控制参数Kp1、Ti1等的选择
#define Para_Mach_321            MachPara[321]  //                                    
#define Para_SDSpeedKP1          MachPara[322]  //速度环比例增益1                            
#define Para_SDSpeedTI1          MachPara[323]  //速度环积分时间1                            
#define Para_SDSpdSwtFrq1        MachPara[324]  //切换频率1                               上限受控于SDSpdSwtFrq2
#define Para_SDSpeedKP2          MachPara[325]  //速度环比例增益2                            
#define Para_SDSpeedTI2          MachPara[326]  //速度环积分时间2                            
#define Para_SDSpdSwtFrq2        MachPara[327]  //切换频率2                               上限受控于最大频率
#define Para_SDSpeedFiltTime     MachPara[328]  //速度环滤波时间常数                           
#define Para_SDMaxTorque         MachPara[329]  //转矩上限                                
#define Para_Mach_330            MachPara[330]  //                                    
#define Para_SDCanSetPresRamp    MachPara[331]  //油压指令上升时间(上升斜率)                      
#define Para_SDCanSetPresSFiltTime MachPara[332]//给定油压S滤波时间                           
#define Para_SDActPidSel         MachPara[333]  //伺服驱动器动作PID功能选择                      
#define Para_SDPresCtrlKP1       MachPara[334]  //油压控制Kp1                             注射压力响应参数……平稳模式
#define Para_SDPresCtrlTI1       MachPara[335]  //油压控制Ti1                             
#define Para_SDPresCtrlTD1       MachPara[336]  //油压控制Td1                             
#define Para_Mach_337            MachPara[337]  //                                    
#define Para_SDPresCtrlKP2       MachPara[338]  //油压控制Kp2                             注射压力响应参数……均衡模式
#define Para_SDPresCtrlTI2       MachPara[339]  //油压控制Ti2                             
#define Para_SDPresCtrlTD2       MachPara[340]  //油压控制Td2                             
#define Para_Mach_341            MachPara[341]  //                                    
#define Para_SDPresCtrlKP3       MachPara[342]  //油压控制Kp3                             注射压力响应参数……快速模式
#define Para_SDPresCtrlTI3       MachPara[343]  //油压控制Ti3                             
#define Para_SDPresCtrlTD3       MachPara[344]  //油压控制Td3                             
#define Para_Mach_345            MachPara[345]  //                                    
#define Para_SDPresCtrlKP4       MachPara[346]  //油压控制Kp4                             顶针压力响应参数
#define Para_SDPresCtrlTI4       MachPara[347]  //油压控制Ti4                             
#define Para_SDPresCtrlTD4       MachPara[348]  //油压控制Td4                             
#define Para_Mach_349            MachPara[349]  //                                    
#define Para_SDPresCtrlKP5       MachPara[350]  //油压控制Kp5                             开合模压力响应参数
#define Para_SDPresCtrlTI5       MachPara[351]  //油压控制Ti5                             
#define Para_SDPresCtrlTD5       MachPara[352]  //油压控制Td5                             
#define Para_Mach_353            MachPara[353]  //                                    
#define Para_SDPresCtrlKP6       MachPara[354]  //油压控制Kp6                             其它动作压力响应参数
#define Para_SDPresCtrlTI6       MachPara[355]  //油压控制Ti6                             
#define Para_SDPresCtrlTD6       MachPara[356]  //油压控制Td6                             
#define Para_VacuumizeOpt        MachPara[357]  //抽真空配备                               0-抽真空未配备；1-抽真空配备
#define Para_EjeRetEnd2Opt       MachPara[358]  //顶针退终2配备                             
#define Para_Sys3PresMeasSnrSel  MachPara[359]  //系统3压力对应传感器                          0-无、1-HAI1、2-HAI2、3-HAI3、4-State_SDRealPres(由CAN从驱动器直接读取)
#define Para_InjCylDia           MachPara[360]  //注射油缸直径                              应天剑，用于换算注射的压力
#define Para_InjRodDia           MachPara[361]  //注射活塞杆直径                             应天剑，用于换算注射的压力
#define Para_ScrewDia            MachPara[362]  //螺杆直径                                应天剑，用于换算注射的压力
#define Para_HotRunnerCanPart    MachPara[363]  //热流道CAN端口                            热流道CAN端口：0-未配备；1-CAN0；2-CAN1
#define Para_HotRunner1Opt       MachPara[364]  //热流道控制板1配备                           热流道控制板1配备：0-未配备；1-配备
#define Para_HotRunner2Opt       MachPara[365]  //热流道控制板2配备                           热流道控制板2配备：0-未配备；1-配备
#define Para_HotRunner3Opt       MachPara[366]  //热流道控制板3配备                           热流道控制板3配备：0-未配备；1-配备
#define Para_HotRunner4Opt       MachPara[367]  //热流道控制板4配备                           热流道控制板4配备：0-未配备；1-配备
#define Para_HotRunner5Opt       MachPara[368]  //热流道控制板5配备                           热流道控制板5配备：0-未配备；1-配备
#define Para_Mach_369            MachPara[369]  //                                    
#define Para_Pump1Out            MachPara[370]  //泵1排量                                用于伺服电机根据转速计算流量，（实际未用，程序中用最大转速计算得流量）
#define Para_Pump2Out            MachPara[371]  //泵2排量                                流量=排量*转速*泄漏系数，其中排量单位mL/r、转速单位rpm、泄漏系数约0.9
#define Para_Pump3Out            MachPara[372]  //泵3排量                                TJ86/120排量为31.5mL/r、TJ160排量为40mL/r、TJ200排量为63mL/r
#define Para_Pump4Out            MachPara[373]  //泵4排量                                
#define Para_Pump5Out            MachPara[374]  //泵5排量                                
#define Para_SuckBackLargeFlow   MachPara[375]  //射退使用大流量                             0-使用小流量（输出小流量信号）、1-使用大流量（不输出小流量信号）
#define Para_BMCFeedLaddOpt      MachPara[376]  //加料爬梯配备                              加料爬梯配备:0-未配备;1-配备
#define Para_PowerMonOpt         MachPara[377]  //电源确认配备                              0-不配备 1-配备
#define Para_MotOffServoDrvErr   MachPara[378]  //马达关时监视驱动器异常                         0-不用 1-使用
#define Para_Mot2TempSnrOpt      MachPara[379]  //马达二测温配备                             
#define Para_SafeGateEndOpt      MachPara[380]  //尾板小门配备                              天剑快速机程序专用，标准机不使用,0-没有 1-有
#define Para_HtrOutMode          MachPara[381]  //加热输出模式                              天剑快速机程序专用，标准机不使用,0-标准 1-5s周期
#define Para_InjPresPropValMode  MachPara[382]  //注射压力比例阀模式                           天剑快速机程序专用，标准机不使用,0-平常最大 1-平常关闭 2-有动作最大
#define Para_MoldOpenBrakeDist   MachPara[383]  //开模刹车距离                              
#define Para_MachProtLog         MachPara[384]  //机械保险逻辑                              0-有信号锁模(检查复位) 1-有信号锁模(不检查复位) 2-无信号锁模
#define Para_TempCanMod1CalK     MachPara[385]  //温度模块1校准系数K                          CAN-B温度模块的校准系数K
#define Para_TempCanMod1CalPB    MachPara[386]  //温度模块1校准系数PB                         CAN-B温度模块的校准系数调高值
#define Para_TempCanMod1CalNB    MachPara[387]  //温度模块1校准系数NB                         CAN-B温度模块的校准系数调低值
#define Para_MoldThickPosScale   MachPara[388]  //位置调模比                               模厚位置调模齿轮比
#define Para_KWhMeterOpt         MachPara[389]  //电表配备                                0-未配备 1-脉冲 2-RS485通过CAN转接(DLT645-97版) 3-RS485 4-CAN
#define Para_EjeRetUnEndChkTi    MachPara[390]  //托退未到位检查时间                           托退未到位时，持续该时间才确认报警
#define Para_EjeRetModeEn        MachPara[391]  //特殊托退模式允许                            1-生产参数“托退模式”有效
#define Para_R_EnClamp_AutoMode_Opt MachPara[392]//自动关模允许配备                           特殊机械手“R_EnClamp_AutoMode”信号配备
#define Para_R_RobotRunChk       MachPara[393]  //机械手运行检查                             1-“R_RobotRetEnd”机械手回到位信号在一个循环中应检出“0”变化
#define Para_EjeStepModeEn       MachPara[394]  //逐步托模模式允许                            托模阻力很大的模具，分多次逐步顶进。即托进到顶针不会前进了，退回再次托进。
#define Para_EjeStepModeChkTi    MachPara[395]  //逐步托模确认时间                            逐步顶进模式：检查确认顶针不会前进了的时间。
#define Para_EjeStepModeChkDly   MachPara[396]  //逐步托模检查延时                            逐步顶进模式：延时该时间再进行检查确认顶针不会前进。
#define Para_EjeFor2StepModeEn   MachPara[397]  //二级托模进模式允许                           特殊托模：托进分二次完成，避免产品顶出太快。（第一次顶进到一段结束，第二次才顶到位）
#define Para_InjCompOpt          MachPara[398]  //压缩注射配备                              压缩注射模式:合模到设定位置－注射－继续合模
#define Para_HoldPresPropRelMode MachPara[399]  //保压溢流比例阀模式                           双阶机的保压溢流比例阀：0-非保压关闭、1-非保压最大输出、2-非保压且有动作时最大输出
#define Para_InjEndNozForHold    MachPara[400]  //注射结束座进阀保持                           海天：1-注射结束座进阀保持，以避免储料时漏料。主要是大机有此问题。
#define Para_CoolAutoPilotOilAcc MachPara[401]  //冷却时先导油自动补油                          应双阶机加，双阶机冷却时间可能达30分钟或更多，导致先导油蓄能器泄漏，或用此功能自动补油
#define Para_MoldOpenClsPresMax  MachPara[402]  //开关模压力最大值                            
#define Para_InjAdvDecBaseF      MachPara[403]  //注射提前减速底流                            
#define Para_InjAdvDecT          MachPara[404]  //注射提前减速时间                            
#define Para_Mot3TempSnrOpt      MachPara[405]  //马达三测温配备                             配备三电机
#define Para_MonCANPort          MachPara[406]  //监测功能对应CAN端口                         0-关闭 1-CAN1、2-CAN2
#define Para_AutoGatePulseSingSpa MachPara[407] //脉冲间距                                KEB门机使用，一个齿代表的门移动距离
#define Para_AutoGateSlowPulseNum MachPara[408] //减速脉冲数                               KEB门机使用，开门提前减速的脉冲数
#define Para_AutoGateErrSignLog  MachPara[409]  //自动门警报信号逻辑                           0－Off报警   1-ON报警
#define Para_SGUnClsDisSuckBack  MachPara[410]  //安全门未关禁止射退                           0-允许 1-禁止
#define Para_SGUnClsDisNozRet    MachPara[411]  //安全门未关禁止座退                           0-允许 1-禁止
#define Para_SGUnClsDisMoldOpen  MachPara[412]  //安全门未关禁止开模                           0-允许 1-禁止
#define Para_SGUnClsDisMoldCls   MachPara[413]  //安全门未关禁止关模                           0-允许 1-禁止
#define Para_SGUnClsDisAir       MachPara[414]  //安全门未关禁止吹气                           0-允许 1-禁止
#define Para_ChgLinkOilWayOpt    MachPara[415]  //储料连动油路配备                            
#define Para_MoldSlidBlockMonOpt MachPara[416]  //滑块监控配备                              0-配备；1-未配备
#define Para_ChgEndNozForHold    MachPara[417]  //储料结束座进阀保持                           1-储料结束座进阀保持，以避免射退时漏料。
#define Para_SuckBackNozForSel   MachPara[418]  //射退时座进阀选择                            1-射退时座进阀动作
#define Para_RobotOutAlValid     MachPara[419]  //机械手输出点始终有效                          0-机械手不用时，"R.开模到位"、"R.开模中途"不输出 1-无论机械手是否使用,均会输出
#define Para_SemiAutoChgAftEjeEn MachPara[420]  //半自动二次储料允许                           0-禁止 1-允许
#define Para_TieBarEn            MachPara[421]  //抽插拉杆允许                              应抽拉杆功能加
#define Para_BrkInPres           MachPara[422]  //闸板进压力                               应抽拉杆功能加
#define Para_BrkInFlow           MachPara[423]  //闸板进流量                               应抽拉杆功能加
#define Para_BrkOutPres          MachPara[424]  //闸板退压力                               应抽拉杆功能加
#define Para_BrkOutFlow          MachPara[425]  //闸板退流量                               应抽拉杆功能加
#define Para_TieBarInPres        MachPara[426]  //拉杆进压力                               应抽拉杆功能加
#define Para_TieBarInFlow        MachPara[427]  //拉杆进流量                               应抽拉杆功能加
#define Para_TieBarOutPres       MachPara[428]  //拉杆退压力                               应抽拉杆功能加
#define Para_TieBarOutFlow       MachPara[429]  //拉杆退流量                               应抽拉杆功能加
#define Para_MoldOpenMinStroke   MachPara[430]  //开模行程下限                              应抽拉杆功能加
#define Para_AutoMoldAdjMode     MachPara[431]  //自动模厚调整                              0-不用 1-使用，即0-自动调模用压力方式、1-自动调模用模厚尺或调模电眼
#define Para_SGUnClsDisTieBar    MachPara[432]  //安全门未关禁止抽拉杆                          应抽拉杆功能加
#define Para_MoldAdjLubrOpt      MachPara[433]  //调模润滑配备                              应调模润滑功能，0-未配备 1-配备
#define Para_MoldAdjLubrSpaTi    MachPara[434]  //调模润滑间隔时间                            应调模润滑功能
#define Para_MoldAdjLubrHldTi    MachPara[435]  //调模润滑保持时间                            应调模润滑功能
#define Para_MoldAdjLubrAlarmTi  MachPara[436]  //调模润滑警报时间                            应调模润滑功能
#define Para_MoldAdjLubrDateTime MachPara[437]  //调模润滑时间                              最近一次调模润滑的时间，Byte3:年、Byte2：月、Byte1：日、Byte0：时
#define Para_ToggleProtAlarmMode MachPara[438]  //曲肘防护报警模式                            0-立即 1-开关模动作时报警
#define Para_FixSafeGateBackOpt  MachPara[439]  //固定门配备                               大机后安全门有二个，一个活动、一个固定，此即固定门
#define Para_PrgOutputOpt        MachPara[440]  //自由编程输出点配备                           自由编程输出点功能有效
#define Para_SafePlugOpt         MachPara[441]  //安全插头配备                              1-配备
#define Para_KWhM1AddrH          MachPara[442]  //电表1地址高字节                            RS485电表地址（共6字节）
#define Para_KWhM1AddrL          MachPara[443]  //电表1地址低字节                            RS485电表地址（共6字节）
#define Para_KWhM2AddrH          MachPara[444]  //电表2地址高字节                            RS485电表地址（共6字节）
#define Para_KWhM2AddrL          MachPara[445]  //电表2地址低字节                            RS485电表地址（共6字节）
#define Para_KWhM3AddrH          MachPara[446]  //电表3地址高字节                            RS485电表地址（共6字节）
#define Para_KWhM3AddrL          MachPara[447]  //电表3地址低字节                            RS485电表地址（共6字节）
#define Para_KWhMeter_Can485_CANPort MachPara[448]//电表CAN端口                           
#define Para_MoldAdjLubrDly      MachPara[449]  //调模润滑延迟时间                            应调模润滑功能
#define Para_MoldAdjLubrCnt      MachPara[450]  //调模润滑次数                              应调模润滑功能
#define Para_MoldOpenMidEjeEn    MachPara[451]  //开模中途托模允许                            特殊程序：开模中途插入托模动作
#define Para_CycOTOffAlarmLgt    MachPara[452]  //全程超时不亮警灯                            应特殊客户:三色灯中，如是循环超时警报，亮手动灯(不亮报警灯)
#define Para_ManuModeDisAir      MachPara[453]  //手动时不吹气                              
#define Para_SpcSafeGateMode     MachPara[454]  //特殊安全门模式                             天剑快速机：1-土耳其安全标准，半自动前门开允许中子、顶针和开模
#define Para_FrontSGUnClsDisAllAct MachPara[455]//前安全门未关禁止所有动作                        天剑快速机：1-出口标准，前安全门未关禁止所有动作（马达、润滑除外）
#define Para_NozGateUnClsDisAllAct MachPara[456]//前安射出防护未关禁止所有动作                      天剑快速机：1-出口标准，射出防护未关禁止所有动作（马达、润滑除外）
#define Para_SpcSafeGateModeOpt  MachPara[457]  //特殊安全门模式配备                           天剑快速机：1-土耳其安全标准，半自动前门开允许中子、顶针和开模
#define Para_InjFlowFeedSel      MachPara[458]  //注射流量闭环                              1-使用，即注射信号在注射1-10时有效输出
#define Para_MoldOpenEndEnMoldAdj MachPara[459] //开模终才允许调模                            0-不用 1-使用
#define Para_HydrSafeOutLog      MachPara[460]  //液压安全输出逻辑                            0-安全门关输出 1-安全门关不输出
#define Para_SafeRlyErrOffMot    MachPara[461]  //安全继电器异常切马达                          CE安全标准:安全继电器异常切马达  1-切马达
#define Para_InjMaxSpdSampTime   MachPara[462]  //注射峰速取样时间                            注射峰速取样周期
#define Para_MotOnGrnLgt         MachPara[463]  //马达开亮绿灯                              马达开亮绿灯: 0-不亮 1-亮
#define Para_NozRetMainPos       MachPara[464]  //座退维护位置                              天剑快速机：CE认证要求，到该位置座退限速
#define Para_NozRetMainFlow      MachPara[465]  //座退维护流量                              天剑快速机：CE认证要求，到该位置座退限速
#define Para_OilLessSnr2Log      MachPara[466]  //油位传感器2逻辑                            0-没有、1-正逻辑（ON-油位低,Off-油位正常）、2-负逻辑(ON-油位正常、OFF-油位低)
#define Para_InjFlowFeedPresChkDly MachPara[467]//流量闭环压力转保压延时                         天剑快速机：流量闭环时经该延时检查压力，压力到转保压
#define Para_InjFlowFeedPCDValid MachPara[468]  //流量闭环压力转保压延时有效                       天剑快速机：Para_InjFlowFeedPresChkDly参数是否有效
#define Para_MoldRstOpt          MachPara[469]  //模具复位配备                              0-未配备 1-配备
#define Para_SDPID_StdAct        MachPara[470]  //普通动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_Eject         MachPara[471]  //托模动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_Inject        MachPara[472]  //注射动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_Charge        MachPara[473]  //储料动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_Mold          MachPara[474]  //开合模动作PID选择                          0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_MoldHP        MachPara[475]  //关模高压动作PID选择                         0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_MoldLP        MachPara[476]  //关模低压动作PID选择                         0-极速 1-快速 2-平稳 3-柔和
#define Para_SDPID_MoldOpen      MachPara[477]  //开模动作PID选择                           0-极速 1-快速 2-平稳 3-柔和
#define Para_MDServoDrvAlarmPcsMode MachPara[478]//蒙德驱动器警报处理模式                        0-不处理 1-仅提示 2-转手动
#define Para_MDServoDrvCANErrPcsMode MachPara[479]//蒙德驱动器CAN出错处理模                     0-不处理 1-仅提示 2-转手动
#define Para_MDServoDrvCANPort   MachPara[480]  //蒙德伺服驱动器CAN端口                        0-关闭 1-CAN1、2-CAN2
#define Para_MDServoDrv1Opt      MachPara[481]  //蒙德伺服驱动器1配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define Para_MDServoDrv2Opt      MachPara[482]  //蒙德伺服驱动器2配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define Para_MDServoDrv3Opt      MachPara[483]  //蒙德伺服驱动器3配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define Para_MDServoDrv4Opt      MachPara[484]  //蒙德伺服驱动器4配备                          0-未配备 1-从泵 2-联动泵 3-主泵
#define Para_MDServoDrv1Mode     MachPara[485]  //蒙德伺服驱动器1控制模式                        0-CAN控制模式 1-CAN监视模式
#define Para_MDServoDrv2Mode     MachPara[486]  //蒙德伺服驱动器2控制模式                        0-CAN控制模式 1-CAN监视模式
#define Para_MDServoDrv3Mode     MachPara[487]  //蒙德伺服驱动器3控制模式                        0-CAN控制模式 1-CAN监视模式
#define Para_MDServoDrv4Mode     MachPara[488]  //蒙德伺服驱动器4控制模式                        0-CAN控制模式 1-CAN监视模式
#define Para_HydProtChkMCTi      MachPara[489]  //关模中液压保险检查时                          关模进行中液压保险检查时间
#define Para_OilSuppMotorCycCoolSel MachPara[490]//补油电机循环冷却选择                         补油电机循环冷却选择：0-关闭；1-开启；
#define Para_OilSuppCycPres      MachPara[491]  //补油循环压力                              补油循环压力
#define Para_OilSuppCycFlow      MachPara[492]  //补油循环流量                              补油循环流量
#define Para_ChgMotorOilSuppSel  MachPara[493]  //电储料补油选择                             电储料补油选择：0-关闭；1-开启；
#define Para_ChgMotorOilSuppPresMax MachPara[494]//电储料补油压力上限                          电储料补油压力上限
#define Para_ChgMotorOilSuppFlowMax MachPara[495]//电储料补油流量上限                          电储料补油流量上限
#define Para_ChgMotorOilSuppPres MachPara[496]  //电储料补油压力                             电储料补油压力
#define Para_ChgMotorOilSuppFlow MachPara[497]  //电储料补油流量                             电储料补油流量
#define Para_ChgGearTempSnrOpt   MachPara[498]  //电储料齿轮箱温度传感器配备                       电储料齿轮箱温度传感器配备：0-未配备；1-配备
#define Para_ChgGearTempAlarm    MachPara[499]  //电储料齿轮箱报警温度                          电储料齿轮箱报警温度
#define Para_DAC1LineType        MachPara[500]  //DAC1线性                              
#define Para_DAC2LineType        MachPara[501]  //DAC2线性                              
#define Para_DAC3LineType        MachPara[502]  //DAC3线性                              
#define Para_DAC4LineType        MachPara[503]  //DAC4线性                              
#define Para_DAC5LineType        MachPara[504]  //DAC5线性                              
#define Para_DAC6LineType        MachPara[505]  //DAC6线性                              
#define Para_DAC7LineType        MachPara[506]  //DAC7线性                              
#define Para_DAC8LineType        MachPara[507]  //DAC8线性                              
#define Para_Mach_508            MachPara[508]  //                                    
#define Para_Mach_509            MachPara[509]  //                                    
#define Para_Mach_510            MachPara[510]  //                                    
#define Para_Mach_511            MachPara[511]  //                                    
#define Para_DAC1PointNum        MachPara[512]  //DA通道1设置点数                           以下DA通道曲线:15点*2+1(点数/设置点/DA值)
#define Para_DAC1SetPoint0       MachPara[513]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC1SetPoint1       MachPara[514]  //设置点1                                
#define Para_DAC1SetPoint2       MachPara[515]  //设置点2                                
#define Para_DAC1SetPoint3       MachPara[516]  //设置点3                                
#define Para_DAC1SetPoint4       MachPara[517]  //设置点4                                
#define Para_DAC1SetPoint5       MachPara[518]  //设置点5                                
#define Para_DAC1SetPoint6       MachPara[519]  //设置点6                                
#define Para_DAC1SetPoint7       MachPara[520]  //设置点7                                
#define Para_DAC1SetPoint8       MachPara[521]  //设置点8                                
#define Para_DAC1SetPoint9       MachPara[522]  //设置点9                                
#define Para_DAC1SetPoint10      MachPara[523]  //设置点10                               
#define Para_DAC1SetPoint11      MachPara[524]  //设置点11                               
#define Para_DAC1SetPoint12      MachPara[525]  //设置点12                               
#define Para_DAC1SetPoint13      MachPara[526]  //设置点13                               
#define Para_DAC1SetPoint14      MachPara[527]  //设置点14                               
#define Para_DAC1DA0             MachPara[528]  //DA值0                                DA值，12位
#define Para_DAC1DA1             MachPara[529]  //DA值1                                
#define Para_DAC1DA2             MachPara[530]  //DA值2                                
#define Para_DAC1DA3             MachPara[531]  //DA值3                                
#define Para_DAC1DA4             MachPara[532]  //DA值4                                
#define Para_DAC1DA5             MachPara[533]  //DA值5                                
#define Para_DAC1DA6             MachPara[534]  //DA值6                                
#define Para_DAC1DA7             MachPara[535]  //DA值7                                
#define Para_DAC1DA8             MachPara[536]  //DA值8                                
#define Para_DAC1DA9             MachPara[537]  //DA值9                                
#define Para_DAC1DA10            MachPara[538]  //DA值10                               
#define Para_DAC1DA11            MachPara[539]  //DA值11                               
#define Para_DAC1DA12            MachPara[540]  //DA值12                               
#define Para_DAC1DA13            MachPara[541]  //DA值13                               
#define Para_DAC1DA14            MachPara[542]  //DA值14                               
#define Para_DAC2PointNum        MachPara[543]  //DA通道2设置点数                           
#define Para_DAC2SetPoint0       MachPara[544]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC2SetPoint1       MachPara[545]  //设置点1                                
#define Para_DAC2SetPoint2       MachPara[546]  //设置点2                                
#define Para_DAC2SetPoint3       MachPara[547]  //设置点3                                
#define Para_DAC2SetPoint4       MachPara[548]  //设置点4                                
#define Para_DAC2SetPoint5       MachPara[549]  //设置点5                                
#define Para_DAC2SetPoint6       MachPara[550]  //设置点6                                
#define Para_DAC2SetPoint7       MachPara[551]  //设置点7                                
#define Para_DAC2SetPoint8       MachPara[552]  //设置点8                                
#define Para_DAC2SetPoint9       MachPara[553]  //设置点9                                
#define Para_DAC2SetPoint10      MachPara[554]  //设置点10                               
#define Para_DAC2SetPoint11      MachPara[555]  //设置点11                               
#define Para_DAC2SetPoint12      MachPara[556]  //设置点12                               
#define Para_DAC2SetPoint13      MachPara[557]  //设置点13                               
#define Para_DAC2SetPoint14      MachPara[558]  //设置点14                               
#define Para_DAC2DA0             MachPara[559]  //DA值0                                DA值，12位
#define Para_DAC2DA1             MachPara[560]  //DA值1                                
#define Para_DAC2DA2             MachPara[561]  //DA值2                                
#define Para_DAC2DA3             MachPara[562]  //DA值3                                
#define Para_DAC2DA4             MachPara[563]  //DA值4                                
#define Para_DAC2DA5             MachPara[564]  //DA值5                                
#define Para_DAC2DA6             MachPara[565]  //DA值6                                
#define Para_DAC2DA7             MachPara[566]  //DA值7                                
#define Para_DAC2DA8             MachPara[567]  //DA值8                                
#define Para_DAC2DA9             MachPara[568]  //DA值9                                
#define Para_DAC2DA10            MachPara[569]  //DA值10                               
#define Para_DAC2DA11            MachPara[570]  //DA值11                               
#define Para_DAC2DA12            MachPara[571]  //DA值12                               
#define Para_DAC2DA13            MachPara[572]  //DA值13                               
#define Para_DAC2DA14            MachPara[573]  //DA值14                               
#define Para_DAC3PointNum        MachPara[574]  //DA通道3设置点数                           
#define Para_DAC3SetPoint0       MachPara[575]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC3SetPoint1       MachPara[576]  //设置点1                                
#define Para_DAC3SetPoint2       MachPara[577]  //设置点2                                
#define Para_DAC3SetPoint3       MachPara[578]  //设置点3                                
#define Para_DAC3SetPoint4       MachPara[579]  //设置点4                                
#define Para_DAC3SetPoint5       MachPara[580]  //设置点5                                
#define Para_DAC3SetPoint6       MachPara[581]  //设置点6                                
#define Para_DAC3SetPoint7       MachPara[582]  //设置点7                                
#define Para_DAC3SetPoint8       MachPara[583]  //设置点8                                
#define Para_DAC3SetPoint9       MachPara[584]  //设置点9                                
#define Para_DAC3SetPoint10      MachPara[585]  //设置点10                               
#define Para_DAC3SetPoint11      MachPara[586]  //设置点11                               
#define Para_DAC3SetPoint12      MachPara[587]  //设置点12                               
#define Para_DAC3SetPoint13      MachPara[588]  //设置点13                               
#define Para_DAC3SetPoint14      MachPara[589]  //设置点14                               
#define Para_DAC3DA0             MachPara[590]  //DA值0                                DA值，12位
#define Para_DAC3DA1             MachPara[591]  //DA值1                                
#define Para_DAC3DA2             MachPara[592]  //DA值2                                
#define Para_DAC3DA3             MachPara[593]  //DA值3                                
#define Para_DAC3DA4             MachPara[594]  //DA值4                                
#define Para_DAC3DA5             MachPara[595]  //DA值5                                
#define Para_DAC3DA6             MachPara[596]  //DA值6                                
#define Para_DAC3DA7             MachPara[597]  //DA值7                                
#define Para_DAC3DA8             MachPara[598]  //DA值8                                
#define Para_DAC3DA9             MachPara[599]  //DA值9                                
#define Para_DAC3DA10            MachPara[600]  //DA值10                               
#define Para_DAC3DA11            MachPara[601]  //DA值11                               
#define Para_DAC3DA12            MachPara[602]  //DA值12                               
#define Para_DAC3DA13            MachPara[603]  //DA值13                               
#define Para_DAC3DA14            MachPara[604]  //DA值14                               
#define Para_DAC4PointNum        MachPara[605]  //DA通道4设置点数                           
#define Para_DAC4SetPoint0       MachPara[606]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC4SetPoint1       MachPara[607]  //设置点1                                
#define Para_DAC4SetPoint2       MachPara[608]  //设置点2                                
#define Para_DAC4SetPoint3       MachPara[609]  //设置点3                                
#define Para_DAC4SetPoint4       MachPara[610]  //设置点4                                
#define Para_DAC4SetPoint5       MachPara[611]  //设置点5                                
#define Para_DAC4SetPoint6       MachPara[612]  //设置点6                                
#define Para_DAC4SetPoint7       MachPara[613]  //设置点7                                
#define Para_DAC4SetPoint8       MachPara[614]  //设置点8                                
#define Para_DAC4SetPoint9       MachPara[615]  //设置点9                                
#define Para_DAC4SetPoint10      MachPara[616]  //设置点10                               
#define Para_DAC4SetPoint11      MachPara[617]  //设置点11                               
#define Para_DAC4SetPoint12      MachPara[618]  //设置点12                               
#define Para_DAC4SetPoint13      MachPara[619]  //设置点13                               
#define Para_DAC4SetPoint14      MachPara[620]  //设置点14                               
#define Para_DAC4DA0             MachPara[621]  //DA值0                                DA值，12位
#define Para_DAC4DA1             MachPara[622]  //DA值1                                
#define Para_DAC4DA2             MachPara[623]  //DA值2                                
#define Para_DAC4DA3             MachPara[624]  //DA值3                                
#define Para_DAC4DA4             MachPara[625]  //DA值4                                
#define Para_DAC4DA5             MachPara[626]  //DA值5                                
#define Para_DAC4DA6             MachPara[627]  //DA值6                                
#define Para_DAC4DA7             MachPara[628]  //DA值7                                
#define Para_DAC4DA8             MachPara[629]  //DA值8                                
#define Para_DAC4DA9             MachPara[630]  //DA值9                                
#define Para_DAC4DA10            MachPara[631]  //DA值10                               
#define Para_DAC4DA11            MachPara[632]  //DA值11                               
#define Para_DAC4DA12            MachPara[633]  //DA值12                               
#define Para_DAC4DA13            MachPara[634]  //DA值13                               
#define Para_DAC4DA14            MachPara[635]  //DA值14                               
#define Para_DAC5PointNum        MachPara[636]  //DA通道5设置点数                           
#define Para_DAC5SetPoint0       MachPara[637]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC5SetPoint1       MachPara[638]  //设置点1                                
#define Para_DAC5SetPoint2       MachPara[639]  //设置点2                                
#define Para_DAC5SetPoint3       MachPara[640]  //设置点3                                
#define Para_DAC5SetPoint4       MachPara[641]  //设置点4                                
#define Para_DAC5SetPoint5       MachPara[642]  //设置点5                                
#define Para_DAC5SetPoint6       MachPara[643]  //设置点6                                
#define Para_DAC5SetPoint7       MachPara[644]  //设置点7                                
#define Para_DAC5SetPoint8       MachPara[645]  //设置点8                                
#define Para_DAC5SetPoint9       MachPara[646]  //设置点9                                
#define Para_DAC5SetPoint10      MachPara[647]  //设置点10                               
#define Para_DAC5SetPoint11      MachPara[648]  //设置点11                               
#define Para_DAC5SetPoint12      MachPara[649]  //设置点12                               
#define Para_DAC5SetPoint13      MachPara[650]  //设置点13                               
#define Para_DAC5SetPoint14      MachPara[651]  //设置点14                               
#define Para_DAC5DA0             MachPara[652]  //DA值0                                DA值，12位
#define Para_DAC5DA1             MachPara[653]  //DA值1                                
#define Para_DAC5DA2             MachPara[654]  //DA值2                                
#define Para_DAC5DA3             MachPara[655]  //DA值3                                
#define Para_DAC5DA4             MachPara[656]  //DA值4                                
#define Para_DAC5DA5             MachPara[657]  //DA值5                                
#define Para_DAC5DA6             MachPara[658]  //DA值6                                
#define Para_DAC5DA7             MachPara[659]  //DA值7                                
#define Para_DAC5DA8             MachPara[660]  //DA值8                                
#define Para_DAC5DA9             MachPara[661]  //DA值9                                
#define Para_DAC5DA10            MachPara[662]  //DA值10                               
#define Para_DAC5DA11            MachPara[663]  //DA值11                               
#define Para_DAC5DA12            MachPara[664]  //DA值12                               
#define Para_DAC5DA13            MachPara[665]  //DA值13                               
#define Para_DAC5DA14            MachPara[666]  //DA值14                               
#define Para_DAC6PointNum        MachPara[667]  //DA通道6设置点数                           
#define Para_DAC6SetPoint0       MachPara[668]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC6SetPoint1       MachPara[669]  //设置点1                                
#define Para_DAC6SetPoint2       MachPara[670]  //设置点2                                
#define Para_DAC6SetPoint3       MachPara[671]  //设置点3                                
#define Para_DAC6SetPoint4       MachPara[672]  //设置点4                                
#define Para_DAC6SetPoint5       MachPara[673]  //设置点5                                
#define Para_DAC6SetPoint6       MachPara[674]  //设置点6                                
#define Para_DAC6SetPoint7       MachPara[675]  //设置点7                                
#define Para_DAC6SetPoint8       MachPara[676]  //设置点8                                
#define Para_DAC6SetPoint9       MachPara[677]  //设置点9                                
#define Para_DAC6SetPoint10      MachPara[678]  //设置点10                               
#define Para_DAC6SetPoint11      MachPara[679]  //设置点11                               
#define Para_DAC6SetPoint12      MachPara[680]  //设置点12                               
#define Para_DAC6SetPoint13      MachPara[681]  //设置点13                               
#define Para_DAC6SetPoint14      MachPara[682]  //设置点14                               
#define Para_DAC6DA0             MachPara[683]  //DA值0                                DA值，12位
#define Para_DAC6DA1             MachPara[684]  //DA值1                                
#define Para_DAC6DA2             MachPara[685]  //DA值2                                
#define Para_DAC6DA3             MachPara[686]  //DA值3                                
#define Para_DAC6DA4             MachPara[687]  //DA值4                                
#define Para_DAC6DA5             MachPara[688]  //DA值5                                
#define Para_DAC6DA6             MachPara[689]  //DA值6                                
#define Para_DAC6DA7             MachPara[690]  //DA值7                                
#define Para_DAC6DA8             MachPara[691]  //DA值8                                
#define Para_DAC6DA9             MachPara[692]  //DA值9                                
#define Para_DAC6DA10            MachPara[693]  //DA值10                               
#define Para_DAC6DA11            MachPara[694]  //DA值11                               
#define Para_DAC6DA12            MachPara[695]  //DA值12                               
#define Para_DAC6DA13            MachPara[696]  //DA值13                               
#define Para_DAC6DA14            MachPara[697]  //DA值14                               
#define Para_DAC7PointNum        MachPara[698]  //DA通道7设置点数                           
#define Para_DAC7SetPoint0       MachPara[699]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC7SetPoint1       MachPara[700]  //设置点1                                
#define Para_DAC7SetPoint2       MachPara[701]  //设置点2                                
#define Para_DAC7SetPoint3       MachPara[702]  //设置点3                                
#define Para_DAC7SetPoint4       MachPara[703]  //设置点4                                
#define Para_DAC7SetPoint5       MachPara[704]  //设置点5                                
#define Para_DAC7SetPoint6       MachPara[705]  //设置点6                                
#define Para_DAC7SetPoint7       MachPara[706]  //设置点7                                
#define Para_DAC7SetPoint8       MachPara[707]  //设置点8                                
#define Para_DAC7SetPoint9       MachPara[708]  //设置点9                                
#define Para_DAC7SetPoint10      MachPara[709]  //设置点10                               
#define Para_DAC7SetPoint11      MachPara[710]  //设置点11                               
#define Para_DAC7SetPoint12      MachPara[711]  //设置点12                               
#define Para_DAC7SetPoint13      MachPara[712]  //设置点13                               
#define Para_DAC7SetPoint14      MachPara[713]  //设置点14                               
#define Para_DAC7DA0             MachPara[714]  //DA值0                                DA值，12位
#define Para_DAC7DA1             MachPara[715]  //DA值1                                
#define Para_DAC7DA2             MachPara[716]  //DA值2                                
#define Para_DAC7DA3             MachPara[717]  //DA值3                                
#define Para_DAC7DA4             MachPara[718]  //DA值4                                
#define Para_DAC7DA5             MachPara[719]  //DA值5                                
#define Para_DAC7DA6             MachPara[720]  //DA值6                                
#define Para_DAC7DA7             MachPara[721]  //DA值7                                
#define Para_DAC7DA8             MachPara[722]  //DA值8                                
#define Para_DAC7DA9             MachPara[723]  //DA值9                                
#define Para_DAC7DA10            MachPara[724]  //DA值10                               
#define Para_DAC7DA11            MachPara[725]  //DA值11                               
#define Para_DAC7DA12            MachPara[726]  //DA值12                               
#define Para_DAC7DA13            MachPara[727]  //DA值13                               
#define Para_DAC7DA14            MachPara[728]  //DA值14                               
#define Para_DAC8PointNum        MachPara[729]  //DA通道8设置点数                           
#define Para_DAC8SetPoint0       MachPara[730]  //设置点0                                比例值，即n‰，设置点0固定为0‰
#define Para_DAC8SetPoint1       MachPara[731]  //设置点1                                
#define Para_DAC8SetPoint2       MachPara[732]  //设置点2                                
#define Para_DAC8SetPoint3       MachPara[733]  //设置点3                                
#define Para_DAC8SetPoint4       MachPara[734]  //设置点4                                
#define Para_DAC8SetPoint5       MachPara[735]  //设置点5                                
#define Para_DAC8SetPoint6       MachPara[736]  //设置点6                                
#define Para_DAC8SetPoint7       MachPara[737]  //设置点7                                
#define Para_DAC8SetPoint8       MachPara[738]  //设置点8                                
#define Para_DAC8SetPoint9       MachPara[739]  //设置点9                                
#define Para_DAC8SetPoint10      MachPara[740]  //设置点10                               
#define Para_DAC8SetPoint11      MachPara[741]  //设置点11                               
#define Para_DAC8SetPoint12      MachPara[742]  //设置点12                               
#define Para_DAC8SetPoint13      MachPara[743]  //设置点13                               
#define Para_DAC8SetPoint14      MachPara[744]  //设置点14                               
#define Para_DAC8DA0             MachPara[745]  //DA值0                                DA值，12位
#define Para_DAC8DA1             MachPara[746]  //DA值1                                
#define Para_DAC8DA2             MachPara[747]  //DA值2                                
#define Para_DAC8DA3             MachPara[748]  //DA值3                                
#define Para_DAC8DA4             MachPara[749]  //DA值4                                
#define Para_DAC8DA5             MachPara[750]  //DA值5                                
#define Para_DAC8DA6             MachPara[751]  //DA值6                                
#define Para_DAC8DA7             MachPara[752]  //DA值7                                
#define Para_DAC8DA8             MachPara[753]  //DA值8                                
#define Para_DAC8DA9             MachPara[754]  //DA值9                                
#define Para_DAC8DA10            MachPara[755]  //DA值10                               
#define Para_DAC8DA11            MachPara[756]  //DA值11                               
#define Para_DAC8DA12            MachPara[757]  //DA值12                               
#define Para_DAC8DA13            MachPara[758]  //DA值13                               
#define Para_DAC8DA14            MachPara[759]  //DA值14                               
#define Para_Mach_760            MachPara[760]  //                                    
#define Para_Mach_761            MachPara[761]  //                                    
#define Para_Mach_762            MachPara[762]  //                                    
#define Para_Mach_763            MachPara[763]  //                                    
#define Para_Mach_764            MachPara[764]  //                                    
#define Para_Mach_765            MachPara[765]  //                                    
#define Para_MoldCylPosTabNum    MachPara[766]  //模块油缸位置表点数                           油缸-模块转换表：128点*4字节*2(油缸、模板)、U32类型
#define Para_CylPosP0            MachPara[767]  //油缸位置点0                              
#define Para_CylPosP1            MachPara[768]  //油缸位置点1                              
#define Para_CylPosP2            MachPara[769]  //油缸位置点2                              
#define Para_CylPosP3            MachPara[770]  //油缸位置点3                              
#define Para_CylPosP4            MachPara[771]  //油缸位置点4                              
#define Para_CylPosP5            MachPara[772]  //油缸位置点5                              
#define Para_CylPosP6            MachPara[773]  //油缸位置点6                              
#define Para_CylPosP7            MachPara[774]  //油缸位置点7                              
#define Para_CylPosP8            MachPara[775]  //油缸位置点8                              
#define Para_CylPosP9            MachPara[776]  //油缸位置点9                              
#define Para_CylPosP10           MachPara[777]  //油缸位置点10                             
#define Para_CylPosP11           MachPara[778]  //油缸位置点11                             
#define Para_CylPosP12           MachPara[779]  //油缸位置点12                             
#define Para_CylPosP13           MachPara[780]  //油缸位置点13                             
#define Para_CylPosP14           MachPara[781]  //油缸位置点14                             
#define Para_CylPosP15           MachPara[782]  //油缸位置点15                             
#define Para_CylPosP16           MachPara[783]  //油缸位置点16                             
#define Para_CylPosP17           MachPara[784]  //油缸位置点17                             
#define Para_CylPosP18           MachPara[785]  //油缸位置点18                             
#define Para_CylPosP19           MachPara[786]  //油缸位置点19                             
#define Para_CylPosP20           MachPara[787]  //油缸位置点20                             
#define Para_CylPosP21           MachPara[788]  //油缸位置点21                             
#define Para_CylPosP22           MachPara[789]  //油缸位置点22                             
#define Para_CylPosP23           MachPara[790]  //油缸位置点23                             
#define Para_CylPosP24           MachPara[791]  //油缸位置点24                             
#define Para_CylPosP25           MachPara[792]  //油缸位置点25                             
#define Para_CylPosP26           MachPara[793]  //油缸位置点26                             
#define Para_CylPosP27           MachPara[794]  //油缸位置点27                             
#define Para_CylPosP28           MachPara[795]  //油缸位置点28                             
#define Para_CylPosP29           MachPara[796]  //油缸位置点29                             
#define Para_CylPosP30           MachPara[797]  //油缸位置点30                             
#define Para_CylPosP31           MachPara[798]  //油缸位置点31                             
#define Para_CylPosP32           MachPara[799]  //油缸位置点32                             
#define Para_CylPosP33           MachPara[800]  //油缸位置点33                             
#define Para_CylPosP34           MachPara[801]  //油缸位置点34                             
#define Para_CylPosP35           MachPara[802]  //油缸位置点35                             
#define Para_CylPosP36           MachPara[803]  //油缸位置点36                             
#define Para_CylPosP37           MachPara[804]  //油缸位置点37                             
#define Para_CylPosP38           MachPara[805]  //油缸位置点38                             
#define Para_CylPosP39           MachPara[806]  //油缸位置点39                             
#define Para_CylPosP40           MachPara[807]  //油缸位置点40                             
#define Para_CylPosP41           MachPara[808]  //油缸位置点41                             
#define Para_CylPosP42           MachPara[809]  //油缸位置点42                             
#define Para_CylPosP43           MachPara[810]  //油缸位置点43                             
#define Para_CylPosP44           MachPara[811]  //油缸位置点44                             
#define Para_CylPosP45           MachPara[812]  //油缸位置点45                             
#define Para_CylPosP46           MachPara[813]  //油缸位置点46                             
#define Para_CylPosP47           MachPara[814]  //油缸位置点47                             
#define Para_CylPosP48           MachPara[815]  //油缸位置点48                             
#define Para_CylPosP49           MachPara[816]  //油缸位置点49                             
#define Para_CylPosP50           MachPara[817]  //油缸位置点50                             
#define Para_CylPosP51           MachPara[818]  //油缸位置点51                             
#define Para_CylPosP52           MachPara[819]  //油缸位置点52                             
#define Para_CylPosP53           MachPara[820]  //油缸位置点53                             
#define Para_CylPosP54           MachPara[821]  //油缸位置点54                             
#define Para_CylPosP55           MachPara[822]  //油缸位置点55                             
#define Para_CylPosP56           MachPara[823]  //油缸位置点56                             
#define Para_CylPosP57           MachPara[824]  //油缸位置点57                             
#define Para_CylPosP58           MachPara[825]  //油缸位置点58                             
#define Para_CylPosP59           MachPara[826]  //油缸位置点59                             
#define Para_CylPosP60           MachPara[827]  //油缸位置点60                             
#define Para_CylPosP61           MachPara[828]  //油缸位置点61                             
#define Para_CylPosP62           MachPara[829]  //油缸位置点62                             
#define Para_CylPosP63           MachPara[830]  //油缸位置点63                             
#define Para_CylPosP64           MachPara[831]  //油缸位置点64                             
#define Para_CylPosP65           MachPara[832]  //油缸位置点65                             
#define Para_CylPosP66           MachPara[833]  //油缸位置点66                             
#define Para_CylPosP67           MachPara[834]  //油缸位置点67                             
#define Para_CylPosP68           MachPara[835]  //油缸位置点68                             
#define Para_CylPosP69           MachPara[836]  //油缸位置点69                             
#define Para_CylPosP70           MachPara[837]  //油缸位置点70                             
#define Para_CylPosP71           MachPara[838]  //油缸位置点71                             
#define Para_CylPosP72           MachPara[839]  //油缸位置点72                             
#define Para_CylPosP73           MachPara[840]  //油缸位置点73                             
#define Para_CylPosP74           MachPara[841]  //油缸位置点74                             
#define Para_CylPosP75           MachPara[842]  //油缸位置点75                             
#define Para_CylPosP76           MachPara[843]  //油缸位置点76                             
#define Para_CylPosP77           MachPara[844]  //油缸位置点77                             
#define Para_CylPosP78           MachPara[845]  //油缸位置点78                             
#define Para_CylPosP79           MachPara[846]  //油缸位置点79                             
#define Para_CylPosP80           MachPara[847]  //油缸位置点80                             
#define Para_CylPosP81           MachPara[848]  //油缸位置点81                             
#define Para_CylPosP82           MachPara[849]  //油缸位置点82                             
#define Para_CylPosP83           MachPara[850]  //油缸位置点83                             
#define Para_CylPosP84           MachPara[851]  //油缸位置点84                             
#define Para_CylPosP85           MachPara[852]  //油缸位置点85                             
#define Para_CylPosP86           MachPara[853]  //油缸位置点86                             
#define Para_CylPosP87           MachPara[854]  //油缸位置点87                             
#define Para_CylPosP88           MachPara[855]  //油缸位置点88                             
#define Para_CylPosP89           MachPara[856]  //油缸位置点89                             
#define Para_CylPosP90           MachPara[857]  //油缸位置点90                             
#define Para_CylPosP91           MachPara[858]  //油缸位置点91                             
#define Para_CylPosP92           MachPara[859]  //油缸位置点92                             
#define Para_CylPosP93           MachPara[860]  //油缸位置点93                             
#define Para_CylPosP94           MachPara[861]  //油缸位置点94                             
#define Para_CylPosP95           MachPara[862]  //油缸位置点95                             
#define Para_CylPosP96           MachPara[863]  //油缸位置点96                             
#define Para_CylPosP97           MachPara[864]  //油缸位置点97                             
#define Para_CylPosP98           MachPara[865]  //油缸位置点98                             
#define Para_CylPosP99           MachPara[866]  //油缸位置点99                             
#define Para_CylPosP100          MachPara[867]  //油缸位置点100                            
#define Para_CylPosP101          MachPara[868]  //油缸位置点101                            
#define Para_CylPosP102          MachPara[869]  //油缸位置点102                            
#define Para_CylPosP103          MachPara[870]  //油缸位置点103                            
#define Para_CylPosP104          MachPara[871]  //油缸位置点104                            
#define Para_CylPosP105          MachPara[872]  //油缸位置点105                            
#define Para_CylPosP106          MachPara[873]  //油缸位置点106                            
#define Para_CylPosP107          MachPara[874]  //油缸位置点107                            
#define Para_CylPosP108          MachPara[875]  //油缸位置点108                            
#define Para_CylPosP109          MachPara[876]  //油缸位置点109                            
#define Para_CylPosP110          MachPara[877]  //油缸位置点110                            
#define Para_CylPosP111          MachPara[878]  //油缸位置点111                            
#define Para_CylPosP112          MachPara[879]  //油缸位置点112                            
#define Para_CylPosP113          MachPara[880]  //油缸位置点113                            
#define Para_CylPosP114          MachPara[881]  //油缸位置点114                            
#define Para_CylPosP115          MachPara[882]  //油缸位置点115                            
#define Para_CylPosP116          MachPara[883]  //油缸位置点116                            
#define Para_CylPosP117          MachPara[884]  //油缸位置点117                            
#define Para_CylPosP118          MachPara[885]  //油缸位置点118                            
#define Para_CylPosP119          MachPara[886]  //油缸位置点119                            
#define Para_CylPosP120          MachPara[887]  //油缸位置点120                            
#define Para_CylPosP121          MachPara[888]  //油缸位置点121                            
#define Para_CylPosP122          MachPara[889]  //油缸位置点122                            
#define Para_CylPosP123          MachPara[890]  //油缸位置点123                            
#define Para_CylPosP124          MachPara[891]  //油缸位置点124                            
#define Para_CylPosP125          MachPara[892]  //油缸位置点125                            
#define Para_CylPosP126          MachPara[893]  //油缸位置点126                            
#define Para_CylPosP127          MachPara[894]  //油缸位置点127                            
#define Para_CylPosP128          MachPara[895]  //油缸位置点128                            
#define Para_MoldPosP0           MachPara[896]  //模板位置点0                              
#define Para_MoldPosP1           MachPara[897]  //模板位置点1                              
#define Para_MoldPosP2           MachPara[898]  //模板位置点2                              
#define Para_MoldPosP3           MachPara[899]  //模板位置点3                              
#define Para_MoldPosP4           MachPara[900]  //模板位置点4                              
#define Para_MoldPosP5           MachPara[901]  //模板位置点5                              
#define Para_MoldPosP6           MachPara[902]  //模板位置点6                              
#define Para_MoldPosP7           MachPara[903]  //模板位置点7                              
#define Para_MoldPosP8           MachPara[904]  //模板位置点8                              
#define Para_MoldPosP9           MachPara[905]  //模板位置点9                              
#define Para_MoldPosP10          MachPara[906]  //模板位置点10                             
#define Para_MoldPosP11          MachPara[907]  //模板位置点11                             
#define Para_MoldPosP12          MachPara[908]  //模板位置点12                             
#define Para_MoldPosP13          MachPara[909]  //模板位置点13                             
#define Para_MoldPosP14          MachPara[910]  //模板位置点14                             
#define Para_MoldPosP15          MachPara[911]  //模板位置点15                             
#define Para_MoldPosP16          MachPara[912]  //模板位置点16                             
#define Para_MoldPosP17          MachPara[913]  //模板位置点17                             
#define Para_MoldPosP18          MachPara[914]  //模板位置点18                             
#define Para_MoldPosP19          MachPara[915]  //模板位置点19                             
#define Para_MoldPosP20          MachPara[916]  //模板位置点20                             
#define Para_MoldPosP21          MachPara[917]  //模板位置点21                             
#define Para_MoldPosP22          MachPara[918]  //模板位置点22                             
#define Para_MoldPosP23          MachPara[919]  //模板位置点23                             
#define Para_MoldPosP24          MachPara[920]  //模板位置点24                             
#define Para_MoldPosP25          MachPara[921]  //模板位置点25                             
#define Para_MoldPosP26          MachPara[922]  //模板位置点26                             
#define Para_MoldPosP27          MachPara[923]  //模板位置点27                             
#define Para_MoldPosP28          MachPara[924]  //模板位置点28                             
#define Para_MoldPosP29          MachPara[925]  //模板位置点29                             
#define Para_MoldPosP30          MachPara[926]  //模板位置点30                             
#define Para_MoldPosP31          MachPara[927]  //模板位置点31                             
#define Para_MoldPosP32          MachPara[928]  //模板位置点32                             
#define Para_MoldPosP33          MachPara[929]  //模板位置点33                             
#define Para_MoldPosP34          MachPara[930]  //模板位置点34                             
#define Para_MoldPosP35          MachPara[931]  //模板位置点35                             
#define Para_MoldPosP36          MachPara[932]  //模板位置点36                             
#define Para_MoldPosP37          MachPara[933]  //模板位置点37                             
#define Para_MoldPosP38          MachPara[934]  //模板位置点38                             
#define Para_MoldPosP39          MachPara[935]  //模板位置点39                             
#define Para_MoldPosP40          MachPara[936]  //模板位置点40                             
#define Para_MoldPosP41          MachPara[937]  //模板位置点41                             
#define Para_MoldPosP42          MachPara[938]  //模板位置点42                             
#define Para_MoldPosP43          MachPara[939]  //模板位置点43                             
#define Para_MoldPosP44          MachPara[940]  //模板位置点44                             
#define Para_MoldPosP45          MachPara[941]  //模板位置点45                             
#define Para_MoldPosP46          MachPara[942]  //模板位置点46                             
#define Para_MoldPosP47          MachPara[943]  //模板位置点47                             
#define Para_MoldPosP48          MachPara[944]  //模板位置点48                             
#define Para_MoldPosP49          MachPara[945]  //模板位置点49                             
#define Para_MoldPosP50          MachPara[946]  //模板位置点50                             
#define Para_MoldPosP51          MachPara[947]  //模板位置点51                             
#define Para_MoldPosP52          MachPara[948]  //模板位置点52                             
#define Para_MoldPosP53          MachPara[949]  //模板位置点53                             
#define Para_MoldPosP54          MachPara[950]  //模板位置点54                             
#define Para_MoldPosP55          MachPara[951]  //模板位置点55                             
#define Para_MoldPosP56          MachPara[952]  //模板位置点56                             
#define Para_MoldPosP57          MachPara[953]  //模板位置点57                             
#define Para_MoldPosP58          MachPara[954]  //模板位置点58                             
#define Para_MoldPosP59          MachPara[955]  //模板位置点59                             
#define Para_MoldPosP60          MachPara[956]  //模板位置点60                             
#define Para_MoldPosP61          MachPara[957]  //模板位置点61                             
#define Para_MoldPosP62          MachPara[958]  //模板位置点62                             
#define Para_MoldPosP63          MachPara[959]  //模板位置点63                             
#define Para_MoldPosP64          MachPara[960]  //模板位置点64                             
#define Para_MoldPosP65          MachPara[961]  //模板位置点65                             
#define Para_MoldPosP66          MachPara[962]  //模板位置点66                             
#define Para_MoldPosP67          MachPara[963]  //模板位置点67                             
#define Para_MoldPosP68          MachPara[964]  //模板位置点68                             
#define Para_MoldPosP69          MachPara[965]  //模板位置点69                             
#define Para_MoldPosP70          MachPara[966]  //模板位置点70                             
#define Para_MoldPosP71          MachPara[967]  //模板位置点71                             
#define Para_MoldPosP72          MachPara[968]  //模板位置点72                             
#define Para_MoldPosP73          MachPara[969]  //模板位置点73                             
#define Para_MoldPosP74          MachPara[970]  //模板位置点74                             
#define Para_MoldPosP75          MachPara[971]  //模板位置点75                             
#define Para_MoldPosP76          MachPara[972]  //模板位置点76                             
#define Para_MoldPosP77          MachPara[973]  //模板位置点77                             
#define Para_MoldPosP78          MachPara[974]  //模板位置点78                             
#define Para_MoldPosP79          MachPara[975]  //模板位置点79                             
#define Para_MoldPosP80          MachPara[976]  //模板位置点80                             
#define Para_MoldPosP81          MachPara[977]  //模板位置点81                             
#define Para_MoldPosP82          MachPara[978]  //模板位置点82                             
#define Para_MoldPosP83          MachPara[979]  //模板位置点83                             
#define Para_MoldPosP84          MachPara[980]  //模板位置点84                             
#define Para_MoldPosP85          MachPara[981]  //模板位置点85                             
#define Para_MoldPosP86          MachPara[982]  //模板位置点86                             
#define Para_MoldPosP87          MachPara[983]  //模板位置点87                             
#define Para_MoldPosP88          MachPara[984]  //模板位置点88                             
#define Para_MoldPosP89          MachPara[985]  //模板位置点89                             
#define Para_MoldPosP90          MachPara[986]  //模板位置点90                             
#define Para_MoldPosP91          MachPara[987]  //模板位置点91                             
#define Para_MoldPosP92          MachPara[988]  //模板位置点92                             
#define Para_MoldPosP93          MachPara[989]  //模板位置点93                             
#define Para_MoldPosP94          MachPara[990]  //模板位置点94                             
#define Para_MoldPosP95          MachPara[991]  //模板位置点95                             
#define Para_MoldPosP96          MachPara[992]  //模板位置点96                             
#define Para_MoldPosP97          MachPara[993]  //模板位置点97                             
#define Para_MoldPosP98          MachPara[994]  //模板位置点98                             
#define Para_MoldPosP99          MachPara[995]  //模板位置点99                             
#define Para_MoldPosP100         MachPara[996]  //模板位置点100                            
#define Para_MoldPosP101         MachPara[997]  //模板位置点101                            
#define Para_MoldPosP102         MachPara[998]  //模板位置点102                            
#define Para_MoldPosP103         MachPara[999]  //模板位置点103                            
#define Para_MoldPosP104         MachPara[1000] //模板位置点104                            
#define Para_MoldPosP105         MachPara[1001] //模板位置点105                            
#define Para_MoldPosP106         MachPara[1002] //模板位置点106                            
#define Para_MoldPosP107         MachPara[1003] //模板位置点107                            
#define Para_MoldPosP108         MachPara[1004] //模板位置点108                            
#define Para_MoldPosP109         MachPara[1005] //模板位置点109                            
#define Para_MoldPosP110         MachPara[1006] //模板位置点110                            
#define Para_MoldPosP111         MachPara[1007] //模板位置点111                            
#define Para_MoldPosP112         MachPara[1008] //模板位置点112                            
#define Para_MoldPosP113         MachPara[1009] //模板位置点113                            
#define Para_MoldPosP114         MachPara[1010] //模板位置点114                            
#define Para_MoldPosP115         MachPara[1011] //模板位置点115                            
#define Para_MoldPosP116         MachPara[1012] //模板位置点116                            
#define Para_MoldPosP117         MachPara[1013] //模板位置点117                            
#define Para_MoldPosP118         MachPara[1014] //模板位置点118                            
#define Para_MoldPosP119         MachPara[1015] //模板位置点119                            
#define Para_MoldPosP120         MachPara[1016] //模板位置点120                            
#define Para_MoldPosP121         MachPara[1017] //模板位置点121                            
#define Para_MoldPosP122         MachPara[1018] //模板位置点122                            
#define Para_MoldPosP123         MachPara[1019] //模板位置点123                            
#define Para_MoldPosP124         MachPara[1020] //模板位置点124                            
#define Para_MoldPosP125         MachPara[1021] //模板位置点125                            
#define Para_MoldPosP126         MachPara[1022] //模板位置点126                            
#define Para_MoldPosP127         MachPara[1023] //模板位置点127                            
#define Para_MoldClsInPosUseCyl  MachPara[1024] //关模算法输入位置选择                          使用油缸或模板位置进行开模算法:0-模板；1-油缸
#define Para_MoldOpenInPosUseCyl MachPara[1025] //开模算法输入位置选择                          使用油缸或模板位置进行开模算法:0-模板；1-油缸
#define Para_Mach_1026           MachPara[1026] //                                    
#define Para_Mach_1027           MachPara[1027] //                                    
#define Para_Mach_1028           MachPara[1028] //                                    
#define Para_Mach_1029           MachPara[1029] //                                    
#define Para_MoldClsAdjPres      MachPara[1030] //关模调模压力                              
#define Para_MoldClsAdjFlow      MachPara[1031] //关模调模流量                              
#define Para_MoldCls1PresRamp    MachPara[1032] //关模1段压力斜率                            关模起始压力斜率
#define Para_MoldCls1FlowRamp    MachPara[1033] //关模1段流量斜率                            关模起始流量斜率
#define Para_MoldCls2PresRamp    MachPara[1034] //关模2段压力斜率                            
#define Para_MoldCls2FlowRamp    MachPara[1035] //关模2段流量斜率                            
#define Para_MoldCls3PresRamp    MachPara[1036] //关模3段压力斜率                            
#define Para_MoldCls3FlowRamp    MachPara[1037] //关模3段流量斜率                            
#define Para_MoldClsLPPresRamp   MachPara[1038] //关模低压压力斜率                            
#define Para_MoldClsLPFlowRamp   MachPara[1039] //关模低压流量斜率                            
#define Para_MoldClsHPPresRamp   MachPara[1040] //关模高压压力斜率                            
#define Para_MoldClsHPFlowRamp   MachPara[1041] //关模高压流量斜率                            
#define Para_MoldClsEndPresRamp  MachPara[1042] //关模结束压力斜率                            
#define Para_MoldClsEndFlowRamp  MachPara[1043] //关模结束压力斜率                            
#define Para_Mach_1044           MachPara[1044] //                                    
#define Para_Mach_1045           MachPara[1045] //                                    
#define Para_MoldClsEndDly       MachPara[1046] //关模完延迟计时                             动作完动作延时结束
#define Para_MoldClsDVOffDly     MachPara[1047] //关模方向阀关延时                            动作后方向阀延时关闭
#define Para_MoldClsPVOnDly      MachPara[1048] //关模比例阀开延时                            动作前比例阀延时输出
#define Para_MoldClsDiffValOnDly MachPara[1049] //差动阀延迟开计时                            差动阀经该延时后打开
#define Para_MoldClsDiffValOffDly MachPara[1050]//差动阀延迟关计时                            差动阀经该延时后关闭
#define Para_MoldClsLPValOnDly   MachPara[1051] //关模低压阀延迟开计时                          关模低压阀经此延时后动作
#define Para_MoldClsHPValOnDly   MachPara[1052] //关模高压阀延迟开计时                          关模高压阀经此延时后动作
#define Para_Mach_1053           MachPara[1053] //                                    
#define Para_MoldClsHPHoldTi     MachPara[1054] //关模高压保持计时                            
#define Para_MoldClsLPDiffValOn  MachPara[1055] //低压模保差动阀开                            低压锁模时打开差动阀
#define Para_MCHPNozForValOn     MachPara[1056] //关模高压允许座进选择                          0-不用 1-使用
#define Para_MoldClsMidHoldTi    MachPara[1057] //关模中途保持时间                            关模中途时间
#define Para_MoldClsStartTi      MachPara[1058] //关模起始段时间                             关模起始段时间，关模起始段是时间控制的最先一段关模
#define Para_MoldClsStartPres    MachPara[1059] //关模起始段压力                             关模起始段压力
#define Para_MoldClsStartFlow    MachPara[1060] //关模起始段流量                             关模起始段压力
#define Para_ValMotOpt           MachPara[1061] //阀门电机配备                              有阀门在输出，打开阀门电机。1-此功能配备；0-此功能未配备
#define Para_MoldClsMidPres      MachPara[1062] //关模中途压力                              关模中途压力
#define Para_MoldClsMidFlow      MachPara[1063] //关模中途流量                              关模中途流量
#define Para_MoldOpenAlgSel      MachPara[1064] //开模算法选择                              0-默认，无算法；1-位置斜率；2-保留
#define Para_MOAlg1_Pos          MachPara[1065] //算法1开模距离                             
#define Para_MOAlgEndAcceSel     MachPara[1066] //智能开模功能                              0-不用 1使用
#define Para_MOAlg1_BaseFlow     MachPara[1067] //算法1开模底流                             
#define Para_MoldOpenAdjPres     MachPara[1068] //开模调模压力                              
#define Para_MoldOpenAdjFlow     MachPara[1069] //开模调模流量                              
#define Para_MoldOpen1PresRamp   MachPara[1070] //开模1段压力斜率                            开模起始压力斜率
#define Para_MoldOpen1FlowRamp   MachPara[1071] //开模1段流量斜率                            开模起始流量斜率
#define Para_MoldOpen2PresRamp   MachPara[1072] //开模2段压力斜率                            
#define Para_MoldOpen2FlowRamp   MachPara[1073] //开模2段流量斜率                            
#define Para_MoldOpen3PresRamp   MachPara[1074] //开模3段压力斜率                            
#define Para_MoldOpen3FlowRamp   MachPara[1075] //开模3段流量斜率                            
#define Para_MoldOpen4PresRamp   MachPara[1076] //开模4压力斜率                             
#define Para_MoldOpen4FlowRamp   MachPara[1077] //开模4流量斜率                             
#define Para_MoldOpen5PresRamp   MachPara[1078] //开模5压力斜率                             
#define Para_MoldOpen5FlowRamp   MachPara[1079] //开模5流量斜率                             
#define Para_MoldOpenEndPresRamp MachPara[1080] //开模结束压力斜率                            
#define Para_MoldOpenEndFlowRamp MachPara[1081] //开模结束压力斜率                            
#define Para_Mach_1082           MachPara[1082] //                                    
#define Para_Mach_1083           MachPara[1083] //                                    
#define Para_MoldOpenEndDly      MachPara[1084] //开模完延迟计时                             动作完动作延时结束
#define Para_MoldOpenDVOffDly    MachPara[1085] //开模方向阀关延时                            动作后方向阀延时关闭
#define Para_MoldOpenPVOnDly     MachPara[1086] //开模比例阀开延时                            动作前比例阀延时输出
#define Para_MoldOpen1LPValOnDly MachPara[1087] //开模一慢低压阀延迟开                          开模一慢低压阀经此延时后动作
#define Para_MoldOpen1LPValOnTi  MachPara[1088] //开模一慢低压阀动作时间                         开模一慢低压阀动作时间
#define Para_MoldOpen1SlowValOnDly MachPara[1089]//开模一慢慢速阀延迟开                         用于CH机，一慢时慢速阀经此延时动作
#define Para_MoldOpen5SlowValOnDly MachPara[1090]//开模二慢慢速阀延迟开                         用于CH机，二慢时慢速阀经此延时动作
#define Para_MoldOpenFastValOnDly MachPara[1091]//开模快速差动阀延迟开                          用于CH机，快速差动阀经此延时动作
#define Para_Mach_1092           MachPara[1092] //                                    
#define Para_MoldOpenEffArea     MachPara[1093] //开模位置有效区                             过“开终位置-位置有效区”即认为开模到位
#define Para_MoldOpenMidPres     MachPara[1094] //开模中途压力                              开模中途压力
#define Para_MoldOpenMidFlow     MachPara[1095] //开模中途流量                              开模中途流量
#define Para_MoldOpenStartTi     MachPara[1096] //开模起始段时间                             开模起始段时间，时间控制最先一段开模，在一慢则不用
#define Para_MoldOpenStartPres   MachPara[1097] //开模起始段压力                             关模起始段压力
#define Para_MoldOpenStartFlow   MachPara[1098] //开模起始段流量                             关模起始段压力
#define Para_MoldOpenMidHoldTi   MachPara[1099] //开模中途保持时间                            开模中途时间
#define Para_InjStartPos         MachPara[1100] //注射起始段位置                             注射起始段距离，与起始段时间采用或逻辑，任一满足结束起始段
#define Para_InjStartTi          MachPara[1101] //注射起始段时间                             注射起始段时间，时间控制最先一段注射，让先导阀先动作，以减小冲击
#define Para_InjStartPres        MachPara[1102] //注射起始段压力                             注射起始段压力
#define Para_InjStartFlow        MachPara[1103] //注射起始段流量                             注射起始段流量
#define Para_InjMaxVel           MachPara[1104] //注射最大速度                              注射最大速度
#define Para_InjAdjPres          MachPara[1105] //注射调模压力                              
#define Para_InjAdjFlow          MachPara[1106] //注射调模流量                              
#define Para_Inj1PresRamp        MachPara[1107] //注射1压力斜率                             
#define Para_Inj1FlowRamp        MachPara[1108] //注射1流量斜率                             
#define Para_Inj2PresRamp        MachPara[1109] //注射2压力斜率                             
#define Para_Inj2FlowRamp        MachPara[1110] //注射2流量斜率                             
#define Para_Inj3PresRamp        MachPara[1111] //注射3压力斜率                             
#define Para_Inj3FlowRamp        MachPara[1112] //注射3流量斜率                             
#define Para_Inj4PresRamp        MachPara[1113] //注射4压力斜率                             
#define Para_Inj4FlowRamp        MachPara[1114] //注射4流量斜率                             
#define Para_Inj5PresRamp        MachPara[1115] //注射5压力斜率                             
#define Para_Inj5FlowRamp        MachPara[1116] //注射5流量斜率                             
#define Para_Inj6PresRamp        MachPara[1117] //注射6压力斜率                             
#define Para_Inj6FlowRamp        MachPara[1118] //注射6流量斜率                             
#define Para_Inj7PresRamp        MachPara[1119] //注射7压力斜率                             
#define Para_Inj7FlowRamp        MachPara[1120] //注射7流量斜率                             
#define Para_Inj8PresRamp        MachPara[1121] //注射8压力斜率                             
#define Para_Inj8FlowRamp        MachPara[1122] //注射8流量斜率                             
#define Para_Inj9PresRamp        MachPara[1123] //注射9压力斜率                             
#define Para_Inj9FlowRamp        MachPara[1124] //注射9流量斜率                             
#define Para_Inj10PresRamp       MachPara[1125] //注射10压力斜率                            
#define Para_Inj10FlowRamp       MachPara[1126] //注射10流量斜率                            
#define Para_HoldPres1PresRamp   MachPara[1127] //保压1压力斜率                             
#define Para_HoldPres1FlowRamp   MachPara[1128] //保压1流量斜率                             
#define Para_HoldPres2PresRamp   MachPara[1129] //保压2压力斜率                             
#define Para_HoldPres2FlowRamp   MachPara[1130] //保压2流量斜率                             
#define Para_HoldPres3PresRamp   MachPara[1131] //保压3压力斜率                             
#define Para_HoldPres3FlowRamp   MachPara[1132] //保压3流量斜率                             
#define Para_HoldPres4PresRamp   MachPara[1133] //保压4压力斜率                             
#define Para_HoldPres4FlowRamp   MachPara[1134] //保压4流量斜率                             
#define Para_HoldPres5PresRamp   MachPara[1135] //保压5压力斜率                             
#define Para_HoldPres5FlowRamp   MachPara[1136] //保压5流量斜率                             
#define Para_HoldPres6PresRamp   MachPara[1137] //保压6压力斜率                             
#define Para_HoldPres6FlowRamp   MachPara[1138] //保压6流量斜率                             
#define Para_HoldPres7PresRamp   MachPara[1139] //保压7压力斜率                             
#define Para_HoldPres7FlowRamp   MachPara[1140] //保压7流量斜率                             
#define Para_HoldPres8PresRamp   MachPara[1141] //保压8压力斜率                             
#define Para_HoldPres8FlowRamp   MachPara[1142] //保压8流量斜率                             
#define Para_HoldPres9PresRamp   MachPara[1143] //保压9压力斜率                             
#define Para_HoldPres9FlowRamp   MachPara[1144] //保压9流量斜率                             
#define Para_HoldPres10PresRamp  MachPara[1145] //保压10压力斜率                            
#define Para_HoldPres10FlowRamp  MachPara[1146] //保压10流量斜率                            
#define Para_HoldPresEndPresRamp MachPara[1147] //保压结束压力斜率                            
#define Para_HoldPresEndFlowRamp MachPara[1148] //保压结束流量斜率                            设较大斜率，实现保压后泄压作用
#define Para_Mach_1149           MachPara[1149] //                                    
#define Para_Mach_1150           MachPara[1150] //                                    
#define Para_InjEndDly           MachPara[1151] //注射完延迟计时                             动作完动作延时结束
#define Para_InjDVOffDly         MachPara[1152] //注射方向阀关延时                            动作后方向阀延时关闭
#define Para_InjPVOnDly          MachPara[1153] //注射比例阀开延时                            动作前比例阀延时输出
#define Para_InjStartDly         MachPara[1154] //注射开始延时                              座进完，射出前延时
#define Para_InjDVOnDly          MachPara[1155] //注射方向阀开延时                            注射方向阀延时开启，即让油路压力先建立，再开阀注射，以提高注射速度
#define Para_InjectSafePos       MachPara[1156] //注射安全位置                              射出结束位置设定不得小于此位置
#define Para_HoldPresRelTi       MachPara[1157] //保压泄压时间                              CH机用，保压后，切阀延时期间，保压泄压阀动作时间
#define Para_InjEPOLToManuNum    MachPara[1158] //连续注射超差转手动次数                         连续注射超差提示到该次数，则转手动并警报，如果为0，则不转
#define Para_InjPVOthActON       MachPara[1159] //注射比例阀其他动作开                          注射比例阀在注射保压动作时按设置输出，其他动作最大输出
#define Para_AccPres             MachPara[1160] //蓄能器蓄能压力                             蓄能器在补充能量时的使用压力
#define Para_AccFlow             MachPara[1161] //蓄能器蓄能流量                             蓄能器在补充能量时的使用流量
#define Para_AccInPresRamp       MachPara[1162] //蓄能器蓄能压力斜率                           
#define Para_AccInFlowRamp       MachPara[1163] //蓄能器蓄能流量斜率                           
#define Para_AccOutPresRamp      MachPara[1164] //蓄能器放能压力斜率                           
#define Para_AccOutFlowRamp      MachPara[1165] //蓄能器放能流量斜率                           
#define Para_InjDiffOnDly        MachPara[1166] //注射差动开延时计时                           
#define Para_InjDiffOffDly       MachPara[1167] //注射差动关延时计时                           
#define Para_InjAccDly           MachPara[1168] //射出增压延迟计时                            射出增压阀延迟动作时间
#define Para_AccDVOffDly         MachPara[1169] //蓄能器方向阀关延迟                           蓄能器蓄能后方向阀延时关
#define Para_AccInMaxTi          MachPara[1170] //蓄能器最大蓄能时间                           超过该时间警报“蓄能失败”
#define Para_NozLeakageSnrChan   MachPara[1171] //喷嘴漏料检测通道                            喷嘴漏料检测通道选择，0：关闭；1-16：分别选择1-16段料筒作为喷嘴漏料检测
#define Para_NozLeakageWarnPcs   MachPara[1172] //喷嘴漏料警报处理                            0-提示、1-闲转手动、2立转手动
#define Para_InjDiffOpt          MachPara[1173] //注射差动配备                              0-不配备 1-配备
#define Para_ChargeAlgSel        MachPara[1174] //储料算法选择                              0-无；1-智能储料,优化储料时间
#define Para_ChgAdjPres          MachPara[1175] //储料调模压力                              
#define Para_ChgAdjFlow          MachPara[1176] //储料调模流量                              
#define Para_Chg1PresRamp        MachPara[1177] //储料1压力斜率                             
#define Para_Chg1FlowRamp        MachPara[1178] //储料1流量斜率                             
#define Para_Chg2PresRamp        MachPara[1179] //储料2压力斜率                             
#define Para_Chg2FlowRamp        MachPara[1180] //储料2流量斜率                             
#define Para_Chg3PresRamp        MachPara[1181] //储料3压力斜率                             
#define Para_Chg3FlowRamp        MachPara[1182] //储料3流量斜率                             
#define Para_Chg4PresRamp        MachPara[1183] //储料4压力斜率                             
#define Para_Chg4FlowRamp        MachPara[1184] //储料4流量斜率                             
#define Para_Chg5PresRamp        MachPara[1185] //储料5压力斜率                             
#define Para_Chg5FlowRamp        MachPara[1186] //储料5流量斜率                             
#define Para_Chg6PresRamp        MachPara[1187] //储料6压力斜率                             
#define Para_Chg6FlowRamp        MachPara[1188] //储料6流量斜率                             
#define Para_Chg7PresRamp        MachPara[1189] //储料7压力斜率                             
#define Para_Chg7FlowRamp        MachPara[1190] //储料7流量斜率                             
#define Para_Chg8PresRamp        MachPara[1191] //储料8压力斜率                             
#define Para_Chg8FlowRamp        MachPara[1192] //储料8流量斜率                             
#define Para_Chg9PresRamp        MachPara[1193] //储料9压力斜率                             
#define Para_Chg9FlowRamp        MachPara[1194] //储料9流量斜率                             
#define Para_Chg10PresRamp       MachPara[1195] //储料10压力斜率                            
#define Para_Chg10FlowRamp       MachPara[1196] //储料10流量斜率                            
#define Para_ChgEndPresRamp      MachPara[1197] //储料结束压力斜率                            
#define Para_ChgEndFlowRamp      MachPara[1198] //储料结束流量斜率                            
#define Para_Mach_1199           MachPara[1199] //                                    
#define Para_ChgStartDly         MachPara[1200] //储料起始延迟计时                            动作起始动作延时开始
#define Para_ChgEndDly           MachPara[1201] //储料完延迟计时                             动作完动作延时结束
#define Para_ChgDVOffDly         MachPara[1202] //储料方向阀关延时                            动作后方向阀延时关闭
#define Para_ChgPVOnDly          MachPara[1203] //储料比例阀开延时                            动作前比例阀延时输出
#define Para_Mach_1204           MachPara[1204] //                                    
#define Para_ChgSuckBackRelTi    MachPara[1205] //储前射退泄压计时                            储料前先打开射退阀泄压该时间，实际未使用
#define Para_ChgRelAftSuckBackTi MachPara[1206] //射退后储料泄压计时                           甬江机器使用，在射退后“储料泄压阀”动作该计时
#define Para_Chg1BackPresRamp    MachPara[1207] //储料背压斜率                              
#define Para_ChgMotorOpt         MachPara[1208] //电储料配备                               主要用于电储料画面压力不可设
#define Para_Mach_1209           MachPara[1209] //                                    
#define Para_Mach_1210           MachPara[1210] //                                    
#define Para_Mach_1211           MachPara[1211] //                                    
#define Para_SuckBackAdjPres     MachPara[1212] //射退调模压力                              
#define Para_SuckBackAdjFlow     MachPara[1213] //射退调模流量                              
#define Para_SuckBackPresRamp    MachPara[1214] //射退压力斜率                              
#define Para_SuckBackFlowRamp    MachPara[1215] //射退流量斜率                              
#define Para_Mach_1216           MachPara[1216] //                                    
#define Para_SuckBackEndDly      MachPara[1217] //射退完延迟计时                             动作完动作延时结束
#define Para_SuckBackDVOffDly    MachPara[1218] //射退方向阀关延时                            动作后方向阀延时关闭
#define Para_SuckBackPVOnDly     MachPara[1219] //射退比例阀开延时                            动作前比例阀延时输出
#define Para_Mach_1220           MachPara[1220] //                                    
#define Para_Mach_1221           MachPara[1221] //                                    
#define Para_Mach_1222           MachPara[1222] //                                    
#define Para_Mach_1223           MachPara[1223] //                                    
#define Para_Mach_1224           MachPara[1224] //                                    
#define Para_EjeAdjPres          MachPara[1225] //托模调模压力                              
#define Para_EjeAdjFlow          MachPara[1226] //托模调模流量                              
#define Para_EjeFor1PresRamp     MachPara[1227] //托模进1压力斜率                            
#define Para_EjeFor1FlowRamp     MachPara[1228] //托模进1流量斜率                            
#define Para_EjeFor2PresRamp     MachPara[1229] //托模进2压力斜率                            
#define Para_EjeFor2FlowRamp     MachPara[1230] //托模进2流量斜率                            
#define Para_EjeForEndPresRamp   MachPara[1231] //托模进结束压力斜率                           
#define Para_EjeForEndFlowRamp   MachPara[1232] //托模进结束流量斜率                           
#define Para_EjeRet1PresRamp     MachPara[1233] //托模退1压力斜率                            
#define Para_EjeRet1FlowRamp     MachPara[1234] //托模退1流量斜率                            
#define Para_EjeRet2PresRamp     MachPara[1235] //托模退2压力斜率                            
#define Para_EjeRet2FlowRamp     MachPara[1236] //托模退2流量斜率                            
#define Para_EjeRetEndPresRamp   MachPara[1237] //托模退结束压力斜率                           
#define Para_EjeRetEndFlowRamp   MachPara[1238] //托模退结束流量斜率                           
#define Para_Mach_1239           MachPara[1239] //                                    
#define Para_EjeForEHoldPresTi   MachPara[1240] //托模进终保压计时                            托模进到位保压计时
#define Para_EjeForEndDly        MachPara[1241] //托模进完延迟计时                            动作完动作延时结束
#define Para_EjeForDVOffDly      MachPara[1242] //托模进方向阀关延时                           动作后方向阀延时关闭
#define Para_EjeForPVOnDly       MachPara[1243] //托模进比例阀开延时                           动作前比例阀延时输出
#define Para_EjeRetEndDly        MachPara[1244] //托模退完延迟计时                            动作完动作延时结束
#define Para_EjeRetDVOffDly      MachPara[1245] //托模退方向阀关延时                           动作后方向阀延时关闭
#define Para_EjeRetPVOnDly       MachPara[1246] //托模退比例阀开延时                           动作前比例阀延时输出
#define Para_EjeForRetSwtDly     MachPara[1247] //托模进退转换延时                            托进、托退之间转换延时
#define Para_Mach_1248           MachPara[1248] //                                    
#define Para_EjeVibCtrlMode      MachPara[1249] //震动托模控制模式                            0-时间 1-位置(使用托退二段起始位置)
#define Para_EjeVibRetTi         MachPara[1250] //震动托模时间                              
#define Para_Mach_1251           MachPara[1251] //                                    
#define Para_EjeRetEffArea       MachPara[1252] //托模退位置有效区                            顶针小于“托退终止位置+有效区”即认为到位
#define Para_EjeRetMaxPos        MachPara[1253] //托模退位置允许最大值                          允许设定的托退终止位置限值
#define Para_EjeRetSlowSPos      MachPara[1254] //托退提前减速位置                            为减小油路冲击，托退时提前该位置切换到小流量
#define Para_EjeRetSlowFlow      MachPara[1255] //托退提前减速流量                            为减小油路冲击，托退时提前切换到该流量
#define Para_EjeRetMinPos        MachPara[1256] //托模退位置允许最小值                          允许设定的托退终止位置限值
#define Para_Mach_1257           MachPara[1257] //                                    
#define Para_NozAdjPres          MachPara[1258] //座台调模压力                              
#define Para_NozAdjFlow          MachPara[1259] //座台调模流量                              
#define Para_NozFor1PresRamp     MachPara[1260] //座进1压力斜率                             
#define Para_NozFor1FlowRamp     MachPara[1261] //座进1流量斜率                             
#define Para_NozFor2PresRamp     MachPara[1262] //座进2压力斜率                             
#define Para_NozFor2FlowRamp     MachPara[1263] //座进2流量斜率                             
#define Para_NozForSlowPresRamp  MachPara[1264] //座进慢速压力斜率                            
#define Para_NozForSlowFlowRamp  MachPara[1265] //座进慢速流量斜率                            
#define Para_NozForEndPresRamp   MachPara[1266] //座进结束压力斜率                            
#define Para_NozForEndFlowRamp   MachPara[1267] //座进结束流量斜率                            
#define Para_NozRet1PresRamp     MachPara[1268] //座退1压力斜率                             
#define Para_NozRet1FlowRamp     MachPara[1269] //座退1流量斜率                             
#define Para_NozRet2PresRamp     MachPara[1270] //座退2压力斜率                             
#define Para_NozRet2FlowRamp     MachPara[1271] //座退2流量斜率                             
#define Para_NozRetEndPresRamp   MachPara[1272] //座退结束压力斜率                            
#define Para_NozRetEndFlowRamp   MachPara[1273] //座退结束流量斜率                            
#define Para_Mach_1274           MachPara[1274] //                                    
#define Para_Mach_1275           MachPara[1275] //                                    
#define Para_NozForEndDly        MachPara[1276] //座台进完延迟计时                            动作完动作延时结束
#define Para_NozForDVOffDly      MachPara[1277] //座台进方向阀关延时                           动作后方向阀延时关闭
#define Para_NozForPVOnDly       MachPara[1278] //座台进比例阀开延时                           动作前比例阀延时输出
#define Para_NozRetEndDly        MachPara[1279] //座台退完延迟计时                            动作完动作延时结束
#define Para_NozRetDVOffDly      MachPara[1280] //座台退方向阀关延时                           动作后方向阀延时关闭
#define Para_NozRetPVOnDly       MachPara[1281] //座台退比例阀开延时                           动作前比例阀延时输出
#define Para_Mach_1282           MachPara[1282] //                                    
#define Para_Mach_1283           MachPara[1283] //                                    
#define Para_SlaveNozOpt         MachPara[1284] //从射台配备                               0-从射台未配备，1-从射台配备
#define Para_HydNozOnTi          MachPara[1285] //液压喷嘴开计时                             
#define Para_HydNozOffTi         MachPara[1286] //液压喷嘴关计时                             
#define Para_HydNozPres          MachPara[1287] //液压喷嘴动作压力                            
#define Para_HydNozFlow          MachPara[1288] //液压喷嘴动作流量                            
#define Para_Mach_1289           MachPara[1289] //                                    
#define Para_Mach_1290           MachPara[1290] //                                    
#define Para_Mach_1291           MachPara[1291] //                                    
#define Para_TimeCoreRunAlway    MachPara[1292] //时间中子一直执行                            0-不用,1-使用 时间中子时无论是否已经到位，在关模、或开模时都会重新执行一次
#define Para_Mach_1293           MachPara[1293] //                                    
#define Para_Mach_1294           MachPara[1294] //                                    
#define Para_Core1InPresRamp     MachPara[1295] //中子1进压力斜率                            
#define Para_Core1InFlowRamp     MachPara[1296] //中子1进流量斜率                            
#define Para_Core2InPresRamp     MachPara[1297] //中子2进压力斜率                            
#define Para_Core2InFlowRamp     MachPara[1298] //中子2进流量斜率                            
#define Para_Core3InPresRamp     MachPara[1299] //中子3进压力斜率                            
#define Para_Core3InFlowRamp     MachPara[1300] //中子3进流量斜率                            
#define Para_Core4InPresRamp     MachPara[1301] //中子4进压力斜率                            
#define Para_Core4InFlowRamp     MachPara[1302] //中子4进流量斜率                            
#define Para_Core5InPresRamp     MachPara[1303] //中子5进压力斜率                            
#define Para_Core5InFlowRamp     MachPara[1304] //中子5进流量斜率                            
#define Para_Core6InPresRamp     MachPara[1305] //中子6进压力斜率                            
#define Para_Core6InFlowRamp     MachPara[1306] //中子6进流量斜率                            
#define Para_Core7InPresRamp     MachPara[1307] //中子7进压力斜率                            
#define Para_Core7InFlowRamp     MachPara[1308] //中子7进流量斜率                            
#define Para_Core8InPresRamp     MachPara[1309] //中子8进压力斜率                            
#define Para_Core8InFlowRamp     MachPara[1310] //中子8进流量斜率                            
#define Para_Mach_1311           MachPara[1311] //                                    
#define Para_Mach_1312           MachPara[1312] //                                    
#define Para_Mach_1313           MachPara[1313] //                                    
#define Para_Mach_1314           MachPara[1314] //                                    
#define Para_Mach_1315           MachPara[1315] //                                    
#define Para_Mach_1316           MachPara[1316] //                                    
#define Para_Core1OutPresRamp    MachPara[1317] //中子1出压力斜率                            
#define Para_Core1OutFlowRamp    MachPara[1318] //中子1出流量斜率                            
#define Para_Core2OutPresRamp    MachPara[1319] //中子2出压力斜率                            
#define Para_Core2OutFlowRamp    MachPara[1320] //中子2出流量斜率                            
#define Para_Core3OutPresRamp    MachPara[1321] //中子3出压力斜率                            
#define Para_Core3OutFlowRamp    MachPara[1322] //中子3出流量斜率                            
#define Para_Core4OutPresRamp    MachPara[1323] //中子4出压力斜率                            
#define Para_Core4OutFlowRamp    MachPara[1324] //中子4出流量斜率                            
#define Para_Core5OutPresRamp    MachPara[1325] //中子5出压力斜率                            
#define Para_Core5OutFlowRamp    MachPara[1326] //中子5出流量斜率                            
#define Para_Core6OutPresRamp    MachPara[1327] //中子6出压力斜率                            
#define Para_Core6OutFlowRamp    MachPara[1328] //中子6出流量斜率                            
#define Para_Core7OutPresRamp    MachPara[1329] //中子7出压力斜率                            
#define Para_Core7OutFlowRamp    MachPara[1330] //中子7出流量斜率                            
#define Para_Core8OutPresRamp    MachPara[1331] //中子8出压力斜率                            
#define Para_Core8OutFlowRamp    MachPara[1332] //中子8出流量斜率                            
#define Para_Mach_1333           MachPara[1333] //                                    
#define Para_Mach_1334           MachPara[1334] //                                    
#define Para_Mach_1335           MachPara[1335] //                                    
#define Para_Mach_1336           MachPara[1336] //                                    
#define Para_Mach_1337           MachPara[1337] //                                    
#define Para_Mach_1338           MachPara[1338] //                                    
#define Para_CoreInEndDly        MachPara[1339] //中子进完延迟计时                            动作完动作延时结束
#define Para_CoreInDVOffDly      MachPara[1340] //中子进方向阀关延时                           动作后方向阀延时关闭
#define Para_CoreInPVOnDly       MachPara[1341] //中子进比例阀开延时                           动作前比例阀延时输出
#define Para_CoreOutEndDly       MachPara[1342] //中子出完延迟计时                            动作完动作延时结束
#define Para_CoreOutDVOffDly     MachPara[1343] //中子出方向阀关延时                           动作后方向阀延时关闭
#define Para_CoreOutPVOnDly      MachPara[1344] //中子出比例阀开延时                           动作前比例阀延时输出
#define Para_CoreInStartDly      MachPara[1345] //中子进前延迟计时                            经此延时后开始中子进动作
#define Para_CoreOutStartDly     MachPara[1346] //中子退前延迟计时                            经此延时后开始中子退动作
#define Para_CoreProtSel         MachPara[1347] //中子保护功能                              0-不用 1-使用
#define Para_CoreSnrErrChk       MachPara[1348] //中子进退到位开关异常检查                        0-不检查 1-检查，即进、退终行程开关同时压合时报警
#define Para_PresRelTi           MachPara[1349] //中子阀门泄压时间                            中子、热流道阀门的泄压时间
#define Para_CoreReverseSel      MachPara[1350] //中子反向功能                              0-不用 1-使用
#define Para_Mach_1351           MachPara[1351] //                                    
#define Para_Mach_1352           MachPara[1352] //                                    
#define Para_CoreEndChkMode_MCMO MachPara[1353] //开关模中子到位检查模式                         0-动作开始时检查，1-全程实时检查
#define Para_CoreEndChkMode_EjeFor MachPara[1354]//托模中子到位检查模式                         0-动作开始时检查，1-全程实时检查
#define Para_CoreEndChkMode_Inject MachPara[1355]//注射中子到位检查模式                         0-动作开始时检查，1-全程实时检查
#define Para_Mach_1356           MachPara[1356] //                                    
#define Para_Mach_1357           MachPara[1357] //                                    
#define Para_ZoneHtrSoftStartSel MachPara[1358] //料筒加热软启动选择                           1-料筒温度软启动：先加热到“阶梯温度”，持续“保持时间”，然后加热到目标温度
#define Para_ZoneHtrSoftStartTemp MachPara[1359]//料筒加热软启动温度                           
#define Para_ZoneHtrSoftStartHoldTi MachPara[1360]//料筒加热软启动保持时间                       
#define Para_Mach_1361           MachPara[1361] //                                    
#define Para_Mach_1362           MachPara[1362] //                                    
#define Para_SyncWarmDeviTemp    MachPara[1363] //同步温升偏差温度                            同步温升偏差温度
#define Para_SyncWarmEndMinDevi  MachPara[1364] //同步温升结束温度下限                          同步温升结束温度下限
#define Para_Zone1TempBuff       MachPara[1365] //一段温度缓冲区                             为0表示关闭
#define Para_Zone2TempBuff       MachPara[1366] //二段温度缓冲区                             为0表示关闭
#define Para_Zone3TempBuff       MachPara[1367] //三段温度缓冲区                             为0表示关闭
#define Para_Zone4TempBuff       MachPara[1368] //四段温度缓冲区                             为0表示关闭
#define Para_Zone5TempBuff       MachPara[1369] //五段温度缓冲区                             为0表示关闭
#define Para_Zone6TempBuff       MachPara[1370] //六段温度缓冲区                             为0表示关闭
#define Para_Zone7TempBuff       MachPara[1371] //七段温度缓冲区                             为0表示关闭
#define Para_Zone8TempBuff       MachPara[1372] //八段温度缓冲区                             为0表示关闭
#define Para_Zone9TempBuff       MachPara[1373] //九段温度缓冲区                             为0表示关闭
#define Para_Zone10TempBuff      MachPara[1374] //十段温度缓冲区                             为0表示关闭
#define Para_Zone11TempBuff      MachPara[1375] //十一段温度缓冲区                            为0表示关闭
#define Para_Zone12TempBuff      MachPara[1376] //十二段温度缓冲区                            为0表示关闭
#define Para_Zone13TempBuff      MachPara[1377] //十三段温度缓冲区                            为0表示关闭
#define Para_Zone14TempBuff      MachPara[1378] //十四段温度缓冲区                            为0表示关闭
#define Para_Zone15TempBuff      MachPara[1379] //十五段温度缓冲区                            为0表示关闭
#define Para_Zone16TempBuff      MachPara[1380] //十六段温度缓冲区                            为0表示关闭
#define Para_Mach_1381           MachPara[1381] //                                    
#define Para_Mach_1382           MachPara[1382] //                                    
#define Para_ZoneEnUpDevTemp     MachPara[1383] //料管温度允许上偏差                           应国标要求，偏差温度超过该值，报警、关电热
#define Para_ZoneCoolProtMinTi   MachPara[1384] //防冷启动时间下限                            限制画面中料筒防冷启动时间可设的下限
#define Para_ZoneUpDevTemp       MachPara[1385] //料管温度上限警报值                           
#define Para_ZoneDnDevTemp       MachPara[1386] //料管温度下限警报值                           
#define Para_ZoneCoolOnDevTemp   MachPara[1387] //料管冷却开偏差温度                           偏差高于该值，开启料管冷却。为0冷却器不用
#define Para_ZoneCoolOffDevTemp  MachPara[1388] //料管冷却关偏差温度                           偏差低于该值，关闭料管冷却
#define Para_HtrOffZoneCoolTi    MachPara[1389] //电热关料筒冷却时间                           电热关后，料筒冷却开启，持续该时间才结束
#define Para_HtrFailChkTemp      MachPara[1390] //电热加温检查最小温升                          加热器全速开时，每3分钟最少温升。为0不检查
#define Para_HtrFreeKeepWarmTi   MachPara[1391] //电热空闲转保温时间                           为0则空闲不转保温
#define Para_EmerStopImmKeepWarm MachPara[1392] //紧急停止按下立转保温                          1-紧停按下立即转保温 0-紧停按下后，闲转保温时间到才转保温
#define Para_OilTempMax          MachPara[1393] //油箱油温上限                              为0表示油箱测温关闭
#define Para_OilTempMin          MachPara[1394] //油箱油温下限                              
#define Para_OilCoolOffTemp      MachPara[1395] //油温低关冷却器                             油温低于该温度，关闭油温冷却器
#define Para_OilCoolOnTemp       MachPara[1396] //油温高开冷却器                             油温超过该温度，开冷却器，为0不用冷却器
#define Para_OilPreHtrSel        MachPara[1397] //油温预热开启                              0-关闭预热功能 1-开启预热功能
#define Para_OilPreHtrPres       MachPara[1398] //油温预热压力                              预先加热压力
#define Para_OilPreHtrFlow       MachPara[1399] //油温预热流量                              预先加热流量
#define Para_OilPreHtrTrgTemp    MachPara[1400] //预热油温                                油温预热目标温度
#define Para_OilPreHtrTrgDevTemp MachPara[1401] //油温偏差                                油温预热目标温度+油温偏差=预热结束温度
#define Para_HtrFreeOffTi        MachPara[1402] //电热空闲关闭时间                            为0则空闲不关电热
#define Para_MotCoolOnTemp       MachPara[1403] //马达冷却开温度                             用于伺服电机，温度超过开冷却器(伺服电机"冷却风扇"输出点)
#define Para_MotCoolOffTemp      MachPara[1404] //马达冷却关温度                             用于伺服电机，温度小于关冷却器(伺服电机"冷却风扇"输出点)
#define Para_MotTempMax          MachPara[1405] //马达温度警报上限                            温度超过，立即报警
#define Para_MotHoldTi           MachPara[1406] //马达保护计时                              启动完成后，经该时间后稳定了，允许动作
#define Para_MotYTi              MachPara[1407] //马达启始时间                              马达Y形启动时间
#define Para_MotYToASpaTi        MachPara[1408] //马达间歇时间                              马达Y到A转换的空歇时间
#define Para_MotFreeOffTi        MachPara[1409] //马达空闲关闭时间                            为0则空闲不关马达
#define Para_Mach_1410           MachPara[1410] //                                    
#define Para_Mach_1411           MachPara[1411] //                                    
#define Para_Mach_1412           MachPara[1412] //                                    
#define Para_Mach_1413           MachPara[1413] //                                    
#define Para_AutoSG1Pres         MachPara[1414] //自动安全门1压力                            
#define Para_AutoSG1Flow         MachPara[1415] //自动安全门1流量                            
#define Para_AutoSG2Pres         MachPara[1416] //自动安全门2压力                            慢速
#define Para_AutoSG2Flow         MachPara[1417] //自动安全门2流量                            慢速
#define Para_Mach_1418           MachPara[1418] //                                    
#define Para_AutoSG1PresRamp     MachPara[1419] //自动安全门1压力斜率                          
#define Para_AutoSG1FlowRamp     MachPara[1420] //自动安全门1流量斜率                          
#define Para_AutoSG2PresRamp     MachPara[1421] //自动安全门2压力斜率                          
#define Para_AutoSG2FlowRamp     MachPara[1422] //自动安全门2流量斜率                          
#define Para_AutoSGEPresRamp     MachPara[1423] //自动安全门结束压力斜率                         
#define Para_AutoSGEFlowRamp     MachPara[1424] //自动安全门结束流量斜率                         
#define Para_Mach_1425           MachPara[1425] //                                    
#define Para_AutoSGOpenTi        MachPara[1426] //自动安全门开计时                            
#define Para_AutoSGEndDly        MachPara[1427] //自动安全门延迟计时                           动作完动作延时结束
#define Para_AutoSGDVOffDly      MachPara[1428] //自动安全门方向阀关延时                         动作后方向阀延时关闭
#define Para_AutoSGPVOnDly       MachPara[1429] //自动安全门比例阀开延时                         动作前比例阀延时输出
#define Para_Lubr1UnitCntMax     MachPara[1430] //润滑1模数最大值                            
#define Para_Lubr1PartCnt        MachPara[1431] //润滑1前后分隔模数                           
#define Para_Lubr1UnitCnt        MachPara[1432] //润滑1模数                               
#define Para_Lubr1TtlTi          MachPara[1433] //润滑1总时间                              定阻、定压润滑时总时间
#define Para_Lubr1TtlCnt         MachPara[1434] //润滑1次数                               定次润滑时，润滑的次数
#define Para_Lubr1MaxTi          MachPara[1435] //润滑1警报时间                             超过该时间未检测到“润滑压力”则润滑失败
#define Para_Lubr1Dly            MachPara[1436] //润滑1延迟                               两次润滑之间的延时
#define Para_Lubr1HoldPresTi     MachPara[1437] //润滑1保压时间                             检测到“润滑压力”后继续保持润滑输出时间
#define Para_Lubr1SpaTi          MachPara[1438] //润滑1润滑间隔时间                           
#define Para_Lubr2PartCnt        MachPara[1439] //润滑2前后分隔模数                           
#define Para_Lubr2UnitCnt        MachPara[1440] //润滑2模数                               
#define Para_Lubr2TtlTi          MachPara[1441] //润滑2总时间                              定阻、定压润滑时总时间
#define Para_Lubr2TtlCnt         MachPara[1442] //润滑2次数                               定次润滑时，润滑的次数
#define Para_Lubr2MaxTi          MachPara[1443] //润滑2警报时间                             超过该时间未检测到“润滑压力”则润滑失败
#define Para_Lubr2Dly            MachPara[1444] //润滑2延迟                               两次润滑之间的延时
#define Para_Lubr2HoldPresTi     MachPara[1445] //润滑2保压时间                             检测到“润滑压力”后继续保持润滑输出时间
#define Para_Lubr2SpaTi          MachPara[1446] //润滑2润滑间隔时间                           
#define Para_Mach_1447           MachPara[1447] //                                    
#define Para_PwrOnAutoLubrDays   MachPara[1448] //开机自动润滑天数                            保留，机器未进行润滑达到该天数则开机后自动润滑，通常是机器停机了较长时间
#define Para_Lubr1DataTime       MachPara[1449] //润滑1润滑时间                             最近一次润滑1润滑的时间，以S为单位记录
#define Para_Lubr2DataTime       MachPara[1450] //润滑2润滑时间                             最近一次润滑1润滑的时间，以S为单位记录
#define Para_Pump1OnFlow         MachPara[1451] //泵1开启流量                              
#define Para_Pump2OnFlow         MachPara[1452] //泵2开启流量                              
#define Para_Pump3OnFlow         MachPara[1453] //泵3开启流量                              
#define Para_Pump4OnFlow         MachPara[1454] //泵4开启流量                              
#define Para_Pump5OnFlow         MachPara[1455] //泵5开启流量                              
#define Para_Pump6OnFlow         MachPara[1456] //泵6开启流量                              
#define Para_Pump7OnFlow         MachPara[1457] //泵7开启流量                              
#define Para_Pump8OnFlow         MachPara[1458] //泵8开启流量                              
#define Para_Pump9OnFlow         MachPara[1459] //泵9开启流量                              
#define Para_Pump10OnFlow        MachPara[1460] //泵10开启流量                             
#define Para_Pump11OnFlow        MachPara[1461] //泵11开启流量                             
#define Para_Pump12OnFlow        MachPara[1462] //泵12开启流量                             
#define Para_Pump13OnFlow        MachPara[1463] //泵13开启流量                             
#define Para_Pump14OnFlow        MachPara[1464] //泵14开启流量                             
#define Para_Pump15OnFlow        MachPara[1465] //泵15开启流量                             
#define Para_Pump16OnFlow        MachPara[1466] //泵16开启流量                             
#define Para_Mach_1467           MachPara[1467] //                                    
#define Para_PrmpOnDly           MachPara[1468] //泵开启延时                               
#define Para_SpcPumpSel          MachPara[1469] //特殊泵选择                               0-不用 1-使用
#define Para_LinkPresOnFlow      MachPara[1470] //连动压力比例阀开流量                          连动压力比例阀在非开模动作时又作泵使用，此即作为泵使用时的开启流量
#define Para_ShutdownPlsMOOpt    MachPara[1471] //关机开模提醒配备                            0-未配备 1-配备
#define Para_PresMinRamp         MachPara[1472] //压力最小斜率                              伺服机压力流量变化不宜太快,易振荡及损坏泵,故设此最小斜率
#define Para_FlowMinRamp         MachPara[1473] //流量最小斜率                              伺服机压力流量变化不宜太快,易振荡及损坏泵,故设此最小斜率
#define Para_DADbRamp            MachPara[1474] //DA调试输出时斜率                           DA调试强制输出时的斜率，特别是伺服机，不宜太快，易振荡及损坏泵
#define Para_AdjMoldActMaxFlow   MachPara[1475] //调模方式动作最大流量                          调模方式下，各动作最大流量
#define Para_MoldAdjDotCnt       MachPara[1476] //点动调模齿数                              点动调模时，调模进退的齿数
#define Para_AMASnrChkTi         MachPara[1477] //自动调模信号检测时间                          自动调模时电眼、位置不移动检查确认时间
#define Para_AMAMoldOpenSpa      MachPara[1478] //自动调模开模距离                            自动调模时开模后退距离
#define Para_AMAStartPulseNum    MachPara[1479] //自动调模起始脉冲数                           自动调模起始脉冲数
#define Para_LinkValOnDly        MachPara[1480] //连动阀延迟开计时                            预留
#define Para_CycTiNoStopSel      MachPara[1481] //全程计时不停选择                            热固机，允许全程计时在结束自动时也不停
#define Para_SpcRelPresValOffDly MachPara[1482] //特殊泄压关延时                             应北化眼镜机：特殊泄压关延时
#define Para_MoniToManuOff       MachPara[1483] //监测功能常开                              0-转手动时即关闭 1-一直有效
#define Para_ExtAlarmLog         MachPara[1484] //外部警报逻辑                              0-未配备、1-ON有效,报警、2-OFF有效,报警
#define Para_ExtAlarmPcs         MachPara[1485] //外部警报处理                              0-立转手动+切马达、1-闲转手动+切马达、2-立转手动、3-闲转手动
#define Para_AutoMoniOnUnitCnt   MachPara[1486] //自动警报开启模数                            该模数到达后，自动监测功能开启
#define Para_SGBackOpenAlarmLgt  MachPara[1487] //后安全门开不亮警灯                           0-亮灯 1-不亮警灯
#define Para_CycMaxTi            MachPara[1488] //全程计时警报上限                            
#define Para_MoldClsLPMaxTi      MachPara[1489] //关模低压计时警报上限                          
#define Para_MoldClsHPMaxTi      MachPara[1490] //关模高压计时警报上限                          
#define Para_ChgMaxTi            MachPara[1491] //储料计时警报上限                            
#define Para_SuckBackMaxTi       MachPara[1492] //射退计时警报上限                            
#define Para_SGOpenClsMaxTi      MachPara[1493] //安全门开关警报时间                           
#define Para_MOMedRobotPosMin    MachPara[1494] //开模中途取件位置下限                          欧规机械手，中途取件时位置下限
#define Para_AlarmOutDly         MachPara[1495] //警报输出延迟时间                            
#define Para_AlarmOutTi          MachPara[1496] //警报输出时间                              警报持续输出的时间
#define Para_AlarmClsHtrTi       MachPara[1497] //警报切电热时间                             为0不关
#define Para_AlarmClsMotTi       MachPara[1498] //警报切马达时间                             为0不关
#define Para_AlarmOutTiCtrlSel   MachPara[1499] //警报输出时间可设                            0-警报持续输出 1-警报持续输出时间按AlarmOutTi设置
#define Para_RobotWaitMaxTi      MachPara[1500] //机械手超时时间                             等待机械手信号有效最长等待时间
#define Para_PackCntOnTi         MachPara[1501] //包装数到输出时间                            包装数到输出时间
#define Para_IODbgOutTime        MachPara[1502] //IO强制输出时间                            
#define Para_DADbgOutTime        MachPara[1503] //DA强制输出时间                            
#define Para_PumpLevelOpt        MachPara[1504] //泵站液位检测配备                            海天北化眼镜机专用：0-未配备 1-负逻辑 2-正逻辑
#define Para_ChutesChan          MachPara[1505] //落料口通道                               落料口通道选择，0：关闭；1-16：分别选择1-16料料筒作为落料口控温用
#define Para_ChutesUpDevTemp     MachPara[1506] //落料口温度上限警报值                          
#define Para_ChutesDnDevTemp     MachPara[1507] //落料口温度下限警报值                          
#define Para_ChutesCoolOnDevTemp MachPara[1508] //落料口冷却开偏差温度                          偏差高于该值，开启料管冷却。为0冷却器不用
#define Para_ChutesCoolOffDevTemp MachPara[1509]//落料口冷却关偏差温度                          偏差低于该值，关闭料管冷却
#define Para_Htr1Power           MachPara[1510] //电热1功率                               
#define Para_Htr2Power           MachPara[1511] //电热2功率                               
#define Para_Htr3Power           MachPara[1512] //电热3功率                               
#define Para_Htr4Power           MachPara[1513] //电热4功率                               
#define Para_Htr5Power           MachPara[1514] //电热5功率                               
#define Para_Htr6Power           MachPara[1515] //电热6功率                               
#define Para_Htr7Power           MachPara[1516] //电热7功率                               
#define Para_Htr8Power           MachPara[1517] //电热8功率                               
#define Para_Htr9Power           MachPara[1518] //电热9功率                               
#define Para_Htr10Power          MachPara[1519] //电热10功率                              
#define Para_Htr11Power          MachPara[1520] //电热11功率                              
#define Para_Htr12Power          MachPara[1521] //电热12功率                              
#define Para_Htr13Power          MachPara[1522] //电热13功率                              
#define Para_Htr14Power          MachPara[1523] //电热14功率                              
#define Para_Htr15Power          MachPara[1524] //电热15功率                              
#define Para_Htr16Power          MachPara[1525] //电热16功率                              
#define Para_Mach_1526           MachPara[1526] //                                    
#define Para_Mach_1527           MachPara[1527] //                                    
#define Para_PFL_FlowLimit1      MachPara[1528] //流量限制1                               PVC二代机压力流量相互限制
#define Para_PFL_FlowLimit2      MachPara[1529] //流量限制2                               PVC二代机压力流量相互限制
#define Para_PFL_FlowLimit3      MachPara[1530] //流量限制3                               PVC二代机压力流量相互限制
#define Para_PFL_PresLimit1      MachPara[1531] //压力限制1                               PVC二代机压力流量相互限制
#define Para_PFL_PresLimit2      MachPara[1532] //压力限制2                               PVC二代机压力流量相互限制
#define Para_PFL_PresLimit3      MachPara[1533] //压力限制3                               PVC二代机压力流量相互限制
#define Para_Mach_1534           MachPara[1534] //                                    
#define Para_Mach_1535           MachPara[1535] //                                    
#define Para_Mach_1536           MachPara[1536] //                                    
#define Para_Mach_1537           MachPara[1537] //                                    
#define Para_Mach_1538           MachPara[1538] //                                    
#define Para_Mach_1539           MachPara[1539] //                                    
#define Para_Lubr1UnitCnt_B1W    MachPara[1540] //润滑1模数                               应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1TtlTi_B1W      MachPara[1541] //润滑1总时间                              定阻、定压润滑时总时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1TtlCnt_B1W     MachPara[1542] //润滑1次数                               定次润滑时，润滑的次数；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1MaxTi_B1W      MachPara[1543] //润滑1警报时间                             超过该时间未检测到“润滑压力”则润滑失败；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1Dly_B1W        MachPara[1544] //润滑1延迟                               ；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1HoldPresTi_B1W MachPara[1545] //润滑1保压时间                             检测到“润滑压力”后继续保持润滑输出时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr1RelPresChk     MachPara[1546] //润滑1压力泄压检查                           润滑1压力泄压检查，1-检查；0-不检查
#define Para_Mach_1547           MachPara[1547] //                                    
#define Para_Lubr2UnitCnt_B1W    MachPara[1548] //润滑2模数                               应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2TtlTi_B1W      MachPara[1549] //润滑2总时间                              定阻、定压润滑时总时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2TtlCnt_B1W     MachPara[1550] //润滑2次数                               定次润滑时，润滑的次数；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2MaxTi_B1W      MachPara[1551] //润滑2警报时间                             超过该时间未检测到“润滑压力”则润滑失败；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2Dly_B1W        MachPara[1552] //润滑2延迟                               两次润滑之间的延时；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2HoldPresTi_B1W MachPara[1553] //润滑2保压时间                             检测到“润滑压力”后继续保持润滑输出时间；应海天：润滑区分前后一万模，这是一万模前的参数
#define Para_Lubr2RelPresChk     MachPara[1554] //润滑2压力泄压检查                           润滑2压力泄压检查，1-检查；0-不检查
#define Para_Lubr2SharLubr1Pump  MachPara[1555] //润滑2共用润滑1润滑泵                         润滑2共用润滑1润滑泵
#define Para_LubrParaMangMode    MachPara[1556] //润滑参数管理模式                            0-标准,1-海天模式（前后10000模采用不同参数，可设范围限定，通过U盘配置）,2-海天模式(50000模为界)
#define Para_AutoLubrDisBrk      MachPara[1557] //自动润滑中断继续功能                          1-自动润滑被中断，下次自动润滑会继续进行
#define Para_MoldAdjLubrSharLubr1Pump MachPara[1558]//调模润滑共用润滑1润滑泵                    调模润滑共用润滑1润滑泵
#define Para_MoldAdjLubrSnrNoOpt MachPara[1559] //调模润滑检知未配备                           调模润滑检知未配备
#define Para_LubrMotorOnSel      MachPara[1560] //开马达即润滑选择                            0-不用，1-使用
#define Para_RobComCANPort       MachPara[1561] //机械手通讯CAN端口号                         0-关闭、1-CAN1、2-CAN2
#define Para_MotOffServoDrvCanEn MachPara[1562] //驱动器关马达CAN通讯使能                       
#define Para_HiMD6CANPort        MachPara[1563] //海天MD6卡CAN端口号                        
#define Para_PwrOnLubrSel        MachPara[1564] //开机润滑选择                              0-不用 1-使用
#define Para_Mach_1565           MachPara[1565] //                                    
#define Para_VeiServoDrvCANPort  MachPara[1566] //伟创驱动器CAN端口号                         
#define Para_VeiServoDrv1Opt     MachPara[1567] //伟创驱动器1配备                            
#define Para_VeiServoDrv2Opt     MachPara[1568] //伟创驱动器2配备                            
#define Para_VeiServoDrv3Opt     MachPara[1569] //伟创驱动器3配备                            
#define Para_VeiServoDrv4Opt     MachPara[1570] //伟创驱动器4配备                            
#define Para_ESServoDrv1Mode     MachPara[1571] //艾普希隆驱动器1接口模式                        
#define Para_ESServoDrv2Mode     MachPara[1572] //艾普希隆驱动器2接口模式                        
#define Para_ESServoDrv3Mode     MachPara[1573] //艾普希隆驱动器3接口模式                        
#define Para_ESServoDrv4Mode     MachPara[1574] //艾普希隆驱动器4接口模式                        
#define Para_ESServoDrvCANPort   MachPara[1575] //艾普希隆驱动器CAN端口号                       
#define Para_ESServoDrv1Opt      MachPara[1576] //艾普希隆驱动器1配备                          0-不配备 1-配备
#define Para_ESServoDrv2Opt      MachPara[1577] //艾普希隆驱动器2配备                          0-不配备 1-配备
#define Para_ESServoDrv3Opt      MachPara[1578] //艾普希隆驱动器3配备                          0-不配备 1-配备
#define Para_ESServoDrv4Opt      MachPara[1579] //艾普希隆驱动器4配备                          0-不配备 1-配备
#define Para_HiServoDrv1Opt      MachPara[1580] //海天驱动器1配备                            0-不配备 1-配备
#define Para_HiServoDrv2Opt      MachPara[1581] //海天驱动器2配备                            0-不配备 1-配备
#define Para_HiServoDrv3Opt      MachPara[1582] //海天驱动器3配备                            0-不配备 1-配备
#define Para_HiServoDrv4Opt      MachPara[1583] //海天驱动器4配备                            0-不配备 1-配备
#define Para_EuRaServoDrvCANPort MachPara[1584] //瑞欧驱动器CAN端口号                         
#define Para_EuRaServoDrv1Opt    MachPara[1585] //瑞欧驱动器1配备                            
#define Para_EuRaServoDrv2Opt    MachPara[1586] //瑞欧驱动器2配备                            
#define Para_EuRaServoDrv3Opt    MachPara[1587] //瑞欧驱动器3配备                            
#define Para_EuRaServoDrv4Opt    MachPara[1588] //瑞欧驱动器4配备                            
#define Para_HiServoDrvCANPort   MachPara[1589] //海天驱动器CAN端口号                         
#define Para_TDServoDrvNorEnMode MachPara[1590] //台达驱动器默认使能模式                         0-数字面板；1-外部DI；2-通讯RS485；3-CANOpen
#define Para_TDServoDrv1Mode     MachPara[1591] //台达驱动器1接口模式                          
#define Para_TDServoDrv2Mode     MachPara[1592] //台达驱动器2接口模式                          
#define Para_TDServoDrv3Mode     MachPara[1593] //台达驱动器3接口模式                          
#define Para_TDServoDrv4Mode     MachPara[1594] //台达驱动器4接口模式                          
#define Para_TDServoDrvCANPort   MachPara[1595] //台达驱动器CAN端口号                         
#define Para_TDServoDrv1Opt      MachPara[1596] //台达驱动器1配备                            0-不配备 1-配备
#define Para_TDServoDrv2Opt      MachPara[1597] //台达驱动器2配备                            0-不配备 1-配备
#define Para_TDServoDrv3Opt      MachPara[1598] //台达驱动器3配备                            0-不配备 1-配备
#define Para_TDServoDrv4Opt      MachPara[1599] //台达驱动器4配备                            0-不配备 1-配备
#define Para_Zone1TCPID_Ps       MachPara[1600] //PID控温算法Ps                           静态PID参数
#define Para_Zone1TCPID_Is       MachPara[1601] //PID控温算法Is                           静态PID参数
#define Para_Zone1TCPID_Ds       MachPara[1602] //PID控温算法Ds                           静态PID参数
#define Para_Zone2TCPID_Ps       MachPara[1603] //PID控温算法Ps                           静态PID参数
#define Para_Zone2TCPID_Is       MachPara[1604] //PID控温算法Is                           静态PID参数
#define Para_Zone2TCPID_Ds       MachPara[1605] //PID控温算法Ds                           静态PID参数
#define Para_Zone3TCPID_Ps       MachPara[1606] //PID控温算法Ps                           静态PID参数
#define Para_Zone3TCPID_Is       MachPara[1607] //PID控温算法Is                           静态PID参数
#define Para_Zone3TCPID_Ds       MachPara[1608] //PID控温算法Ds                           静态PID参数
#define Para_Zone4TCPID_Ps       MachPara[1609] //PID控温算法Ps                           静态PID参数
#define Para_Zone4TCPID_Is       MachPara[1610] //PID控温算法Is                           静态PID参数
#define Para_Zone4TCPID_Ds       MachPara[1611] //PID控温算法Ds                           静态PID参数
#define Para_Zone5TCPID_Ps       MachPara[1612] //PID控温算法Ps                           静态PID参数
#define Para_Zone5TCPID_Is       MachPara[1613] //PID控温算法Is                           静态PID参数
#define Para_Zone5TCPID_Ds       MachPara[1614] //PID控温算法Ds                           静态PID参数
#define Para_Zone6TCPID_Ps       MachPara[1615] //PID控温算法Ps                           静态PID参数
#define Para_Zone6TCPID_Is       MachPara[1616] //PID控温算法Is                           静态PID参数
#define Para_Zone6TCPID_Ds       MachPara[1617] //PID控温算法Ds                           静态PID参数
#define Para_Zone7TCPID_Ps       MachPara[1618] //PID控温算法Ps                           静态PID参数
#define Para_Zone7TCPID_Is       MachPara[1619] //PID控温算法Is                           静态PID参数
#define Para_Zone7TCPID_Ds       MachPara[1620] //PID控温算法Ds                           静态PID参数
#define Para_Zone8TCPID_Ps       MachPara[1621] //PID控温算法Ps                           静态PID参数
#define Para_Zone8TCPID_Is       MachPara[1622] //PID控温算法Is                           静态PID参数
#define Para_Zone8TCPID_Ds       MachPara[1623] //PID控温算法Ds                           静态PID参数
#define Para_Zone9TCPID_Ps       MachPara[1624] //PID控温算法Ps                           静态PID参数
#define Para_Zone9TCPID_Is       MachPara[1625] //PID控温算法Is                           静态PID参数
#define Para_Zone9TCPID_Ds       MachPara[1626] //PID控温算法Ds                           静态PID参数
#define Para_Zone10TCPID_Ps      MachPara[1627] //PID控温算法Ps                           静态PID参数
#define Para_Zone10TCPID_Is      MachPara[1628] //PID控温算法Is                           静态PID参数
#define Para_Zone10TCPID_Ds      MachPara[1629] //PID控温算法Ds                           静态PID参数
#define Para_Zone11TCPID_Ps      MachPara[1630] //PID控温算法Ps                           静态PID参数
#define Para_Zone11TCPID_Is      MachPara[1631] //PID控温算法Is                           静态PID参数
#define Para_Zone11TCPID_Ds      MachPara[1632] //PID控温算法Ds                           静态PID参数
#define Para_Zone12TCPID_Ps      MachPara[1633] //PID控温算法Ps                           静态PID参数
#define Para_Zone12TCPID_Is      MachPara[1634] //PID控温算法Is                           静态PID参数
#define Para_Zone12TCPID_Ds      MachPara[1635] //PID控温算法Ds                           静态PID参数
#define Para_Zone13TCPID_Ps      MachPara[1636] //PID控温算法Ps                           静态PID参数
#define Para_Zone13TCPID_Is      MachPara[1637] //PID控温算法Is                           静态PID参数
#define Para_Zone13TCPID_Ds      MachPara[1638] //PID控温算法Ds                           静态PID参数
#define Para_Zone14TCPID_Ps      MachPara[1639] //PID控温算法Ps                           静态PID参数
#define Para_Zone14TCPID_Is      MachPara[1640] //PID控温算法Is                           静态PID参数
#define Para_Zone14TCPID_Ds      MachPara[1641] //PID控温算法Ds                           静态PID参数
#define Para_Zone15TCPID_Ps      MachPara[1642] //PID控温算法Ps                           静态PID参数
#define Para_Zone15TCPID_Is      MachPara[1643] //PID控温算法Is                           静态PID参数
#define Para_Zone15TCPID_Ds      MachPara[1644] //PID控温算法Ds                           静态PID参数
#define Para_Zone16TCPID_Ps      MachPara[1645] //PID控温算法Ps                           静态PID参数
#define Para_Zone16TCPID_Is      MachPara[1646] //PID控温算法Is                           静态PID参数
#define Para_Zone16TCPID_Ds      MachPara[1647] //PID控温算法Ds                           静态PID参数
#define Para_Mach_1648           MachPara[1648] //                                    
#define Para_Mach_1649           MachPara[1649] //                                    
#define Para_DryCycMC1PresRamp   MachPara[1650] //干循环关模1段压力斜率                         干循环关模1段压力斜率
#define Para_DryCycMC1FlowRamp   MachPara[1651] //干循环关模1段流量斜率                         干循环关模1段流量斜率
#define Para_DryCycMC2PresRamp   MachPara[1652] //干循环关模2段压力斜率                         干循环关模2段压力斜率
#define Para_DryCycMC2FlowRamp   MachPara[1653] //干循环关模2段流量斜率                         干循环关模2段流量斜率
#define Para_DryCycMC3PresRamp   MachPara[1654] //干循环关模3段压力斜率                         干循环关模3段压力斜率
#define Para_DryCycMC3FlowRamp   MachPara[1655] //干循环关模2段流量斜率                         干循环关模3段流量斜率
#define Para_DryCycMCLPPresRamp  MachPara[1656] //干循环关模LP段压力斜率                        干循环关模LP段压力斜率
#define Para_DryCycMCLPFlowRamp  MachPara[1657] //干循环关模LP段流量斜率                        干循环关模LP段流量斜率
#define Para_DryCycMCHPPresRamp  MachPara[1658] //干循环关模HP段压力斜率                        干循环关模HP段压力斜率
#define Para_DryCycMCHPFlowRamp  MachPara[1659] //干循环关模HP段流量斜率                        干循环关模HP段流量斜率
#define Para_DryCycMCEndPresRamp MachPara[1660] //干循环关模结束压力斜率                         
#define Para_DryCycMCEndFlowRamp MachPara[1661] //干循环关模结束流量斜率                         
#define Para_DryCycMCPVOnDly     MachPara[1662] //干循环关模比例阀开延时                         动作前比例阀延时输出
#define Para_DryCycMCDVOffDly    MachPara[1663] //干循环关模方向阀关延时                         动作后方向阀延时关闭
#define Para_Mach_1664           MachPara[1664] //                                    
#define Para_DryCycMO1PresRamp   MachPara[1665] //干循环开模1段压力斜率                         干循环开模1段压力斜率
#define Para_DryCycMO1FlowRamp   MachPara[1666] //干循环开模1段流量斜率                         干循环开模1段流量斜率
#define Para_DryCycMO2PresRamp   MachPara[1667] //干循环开模2段压力斜率                         干循环开模2段压力斜率
#define Para_DryCycMO2FlowRamp   MachPara[1668] //干循环开模2段流量斜率                         干循环开模2段流量斜率
#define Para_DryCycMO3PresRamp   MachPara[1669] //干循环开模3段压力斜率                         干循环开模3段压力斜率
#define Para_DryCycMO3FlowRamp   MachPara[1670] //干循环开模3段流量斜率                         干循环开模3段流量斜率
#define Para_DryCycMO4PresRamp   MachPara[1671] //干循环开模4段压力斜率                         干循环开模4段压力斜率
#define Para_DryCycMO4FlowRamp   MachPara[1672] //干循环开模4段流量斜率                         干循环开模4段流量斜率
#define Para_DryCycMO5PresRamp   MachPara[1673] //干循环开模5段压力斜率                         干循环开模5段压力斜率
#define Para_DryCycMO5FlowRamp   MachPara[1674] //干循环开模5段流量斜率                         干循环开模5段流量斜率
#define Para_DryCycMOEndPresRamp MachPara[1675] //干循环开模结束段压力斜率                        干循环开模结束段压力斜率
#define Para_DryCycMOEndFlowRamp MachPara[1676] //干循环开模结束段流量斜率                        干循环开模结束段流量斜率
#define Para_DryCycMOPVOnDly     MachPara[1677] //干循环开模比例阀开延时                         干循环开模比例阀开延时
#define Para_DryCycMODVOffDly    MachPara[1678] //开模方向阀关延时                            动作后方向阀延时关闭
#define Para_MCHPPresSuprPres    MachPara[1679] //锁模力纠偏憋压压力                           
#define Para_MCHPPresSuprFlow    MachPara[1680] //锁模力纠偏憋压流量                           
#define Para_MCHPPresHoldDiff    MachPara[1681] //锁模力纠偏保持压力差                          
#define Para_MCHPPresMonSel      MachPara[1682] //锁模力监控选择                             0-不用 1-使用
#define Para_MCHPPresMonUpDev    MachPara[1683] //锁模力监控上偏差                            默认值=机器吨位*40%
#define Para_MCHPPresMonDnDev    MachPara[1684] //锁模力监控下偏差                            默认值=机器吨位*40%
#define Para_MCHPPresHoldSel     MachPara[1685] //锁模力保持选择                             0-不用 1-使用
#define Para_MCHPPresHoldUpDev   MachPara[1686] //锁模力保持上偏差                            默认值=机器吨位*20%
#define Para_MCHPPresHoldDnDev   MachPara[1687] //锁模力保持下偏差                            默认值=机器吨位*20%
#define Para_Mach_1688           MachPara[1688] //                                    
#define Para_Mach_1689           MachPara[1689] //                                    
#define Para_Zone2UpDevTemp      MachPara[1690] //2段料管温度上限警报值                         
#define Para_Zone2DnDevTemp      MachPara[1691] //2段料管温度下限警报值                         
#define Para_Zone3UpDevTemp      MachPara[1692] //3段料管温度上限警报值                         
#define Para_Zone3DnDevTemp      MachPara[1693] //3段料管温度下限警报值                         
#define Para_Zone4UpDevTemp      MachPara[1694] //4段料管温度上限警报值                         
#define Para_Zone4DnDevTemp      MachPara[1695] //4段料管温度下限警报值                         
#define Para_Zone5UpDevTemp      MachPara[1696] //5段料管温度上限警报值                         
#define Para_Zone5DnDevTemp      MachPara[1697] //5段料管温度下限警报值                         
#define Para_Zone6UpDevTemp      MachPara[1698] //6段料管温度上限警报值                         
#define Para_Zone6DnDevTemp      MachPara[1699] //6段料管温度下限警报值                         
#define Para_Zone7UpDevTemp      MachPara[1700] //7段料管温度上限警报值                         
#define Para_Zone7DnDevTemp      MachPara[1701] //7段料管温度下限警报值                         
#define Para_Zone8UpDevTemp      MachPara[1702] //8段料管温度上限警报值                         
#define Para_Zone8DnDevTemp      MachPara[1703] //8段料管温度下限警报值                         
#define Para_Zone9UpDevTemp      MachPara[1704] //9段料管温度上限警报值                         
#define Para_Zone9DnDevTemp      MachPara[1705] //9段料管温度下限警报值                         
#define Para_Zone10UpDevTemp     MachPara[1706] //10段料管温度上限警报值                        
#define Para_Zone10DnDevTemp     MachPara[1707] //10段料管温度下限警报值                        
#define Para_Zone11UpDevTemp     MachPara[1708] //11段料管温度上限警报值                        
#define Para_Zone11DnDevTemp     MachPara[1709] //11段料管温度下限警报值                        
#define Para_Zone12UpDevTemp     MachPara[1710] //12段料管温度上限警报值                        
#define Para_Zone12DnDevTemp     MachPara[1711] //12段料管温度下限警报值                        
#define Para_Zone13UpDevTemp     MachPara[1712] //13段料管温度上限警报值                        
#define Para_Zone13DnDevTemp     MachPara[1713] //13段料管温度下限警报值                        
#define Para_Zone14UpDevTemp     MachPara[1714] //14段料管温度上限警报值                        
#define Para_Zone14DnDevTemp     MachPara[1715] //14段料管温度下限警报值                        
#define Para_Zone15UpDevTemp     MachPara[1716] //15段料管温度上限警报值                        
#define Para_Zone15DnDevTemp     MachPara[1717] //15段料管温度下限警报值                        
#define Para_Zone16UpDevTemp     MachPara[1718] //16段料管温度上限警报值                        
#define Para_Zone16DnDevTemp     MachPara[1719] //16段料管温度下限警报值                        
#define Para_ESA100SDcCanChan    MachPara[1720] //日业电储料CAN端口                          
#define Para_ESA100SDc1Add       MachPara[1721] //日业电储料CAN站点号                         
#define Para_Mach_1722           MachPara[1722] //                                    
#define Para_Mach_1723           MachPara[1723] //                                    
#define Para_Mach_1724           MachPara[1724] //                                    
#define Para_Mach_1725           MachPara[1725] //                                    
#define Para_Mach_1726           MachPara[1726] //                                    
#define Para_Mach_1727           MachPara[1727] //                                    
#define Para_Mach_1728           MachPara[1728] //                                    
#define Para_Mach_1729           MachPara[1729] //                                    
#define Para_Mach_1730           MachPara[1730] //                                    
#define Para_Mach_1731           MachPara[1731] //                                    
#define Para_Mach_1732           MachPara[1732] //                                    
#define Para_Mach_1733           MachPara[1733] //                                    
#define Para_Mach_1734           MachPara[1734] //                                    
#define Para_Mach_1735           MachPara[1735] //                                    
#define Para_Mach_1736           MachPara[1736] //                                    
#define Para_Mach_1737           MachPara[1737] //                                    
#define Para_Mach_1738           MachPara[1738] //                                    
#define Para_Mach_1739           MachPara[1739] //                                    
#define Para_Mach_1740           MachPara[1740] //                                    
#define Para_Mach_1741           MachPara[1741] //                                    
#define Para_Mach_1742           MachPara[1742] //                                    
#define Para_Mach_1743           MachPara[1743] //                                    
#define Para_Mach_1744           MachPara[1744] //                                    
#define Para_Mach_1745           MachPara[1745] //                                    
#define Para_Mach_1746           MachPara[1746] //                                    
#define Para_Mach_1747           MachPara[1747] //                                    
#define Para_Mach_1748           MachPara[1748] //                                    
#define Para_Mach_1749           MachPara[1749] //                                    
#define Para_Mach_1750           MachPara[1750] //                                    
#define Para_Mach_1751           MachPara[1751] //                                    
#define Para_Mach_1752           MachPara[1752] //                                    
#define Para_Mach_1753           MachPara[1753] //                                    
#define Para_Mach_1754           MachPara[1754] //                                    
#define Para_Mach_1755           MachPara[1755] //                                    
#define Para_Mach_1756           MachPara[1756] //                                    
#define Para_Mach_1757           MachPara[1757] //                                    
#define Para_Mach_1758           MachPara[1758] //                                    
#define Para_Mach_1759           MachPara[1759] //                                    
#define Para_Mach_1760           MachPara[1760] //                                    
#define Para_Mach_1761           MachPara[1761] //                                    
#define Para_Mach_1762           MachPara[1762] //                                    
#define Para_Mach_1763           MachPara[1763] //                                    
#define Para_Mach_1764           MachPara[1764] //                                    
#define Para_Mach_1765           MachPara[1765] //                                    
#define Para_Mach_1766           MachPara[1766] //                                    
#define Para_Mach_1767           MachPara[1767] //                                    
#define Para_MO_RefrArryAdatPos1 MachPara[1768] //参考参数组1适用机械行程                        
#define Para_MO_RefrArryAdatPos2 MachPara[1769] //参考参数组2适用机械行程                        
#define Para_MiddMoldOpenRamp    MachPara[1770] //开模中途斜率                              
#define Para_MiddMoldClsRamp     MachPara[1771] //关模中途斜率                              
#define Para_MoldOpenValFlowScale MachPara[1772]//开模阀流量降低比例                           开合模比例阀开模时流量降低比例
#define Para_MoldClsValFlowScale MachPara[1773] //关模阀流量降低比例                           开合模比例阀关模时流量降低比例
#define Para_MoldOpenParaLineGen MachPara[1774] //开模参数性线使能                            开模参数性线使能：0-不使能；1-使能
#define Para_MC_DecePresRamp     MachPara[1775] //关模压力减速斜率                            关模压力减速斜率
#define Para_MO_DeceSec1Ramp1    MachPara[1776] //开模减速1段斜率1                           第1机械行程分段，开模减速1段斜率
#define Para_MO_DeceSec2Ramp1    MachPara[1777] //开模减速2段斜率1                           第1机械行程分段，开模减速2段斜率
#define Para_MO_DeceSec2SFlow1   MachPara[1778] //开模减速2段启始流量1                         第1机械行程分段，开模减速2段启始流量
#define Para_MO_DeceBaseFlow1    MachPara[1779] //开模减速底流量1                            第1机械行程分段，开模减速底流量
#define Para_MO_DeceSec1Ramp2    MachPara[1780] //开模减速1段斜率2                           第2机械行程分段，开模减速1段斜率
#define Para_MO_DeceSec2Ramp2    MachPara[1781] //开模减速2段斜率2                           第2机械行程分段，开模减速2段斜率
#define Para_MO_DeceSec2SFlow2   MachPara[1782] //开模减速2段启始流量2                         第2机械行程分段，开模减速2段启始流量
#define Para_MO_DeceBaseFlow2    MachPara[1783] //开模减速底流量2                            第2机械行程分段，开模减速底流量
#define Para_MO_DeceSec1Ramp3    MachPara[1784] //开模减速1段斜率3                           第3机械行程分段，开模减速1段斜率
#define Para_MO_DeceSec2Ramp3    MachPara[1785] //开模减速2段斜率3                           第3机械行程分段，开模减速2段斜率
#define Para_MO_DeceSec2SFlow3   MachPara[1786] //开模减速2段启始流量3                         第3机械行程分段，开模减速2段启始流量
#define Para_MO_DeceBaseFlow3    MachPara[1787] //开模减速底流量3                            第3机械行程分段，开模减速底流量
#define Para_MC_DeceSec1Ramp     MachPara[1788] //关模减速1段斜率                            关模减速1段斜率
#define Para_MC_DeceSec2Ramp     MachPara[1789] //关模减速2段斜率                            关模减速2段斜率
#define Para_MC_DeceSec2SFlow    MachPara[1790] //关模减速2段启始流量                          关模减速2段启始流量
#define Para_MO_DeceDist1        MachPara[1791] //开模减速距离1                             第1机械行程分段，开模减速距离
#define Para_MO_DeceDist2        MachPara[1792] //开模减速距离2                             第2机械行程分段，开模减速距离
#define Para_MO_DeceDist3        MachPara[1793] //开模减速距离3                             第3机械行程分段，开模减速距离
#define Para_MO_AcceDist1        MachPara[1794] //开模加速距离1                             第1机械行程分段，开模加速距离
#define Para_MO_AcceDist2        MachPara[1795] //开模加速距离2                             第2机械行程分段，开模加速距离
#define Para_MO_AcceDist3        MachPara[1796] //开模加速距离3                             第3机械行程分段，开模加速距离
#define Para_MC_AcceDist         MachPara[1797] //关模加速距离                              关模加速距离
#define Para_MC_UniformDist      MachPara[1798] //关模匀速距离                              关模匀速距离
#define Para_Mach_1799           MachPara[1799] //                                    
#define Para_TCTunMode           MachPara[1800] //温度整定模式                              0-关 1-立整一次所有 2－整一次缓冲区 3-条件符合就整缓冲区 4-条件符合就整所有
#define Para_TCTunMinHeatTemp    MachPara[1801] //PID整定最小加热温度                         整定过程加热引起温升应大于该温度值整定才有效
#define Para_TCTunMinTrgTemp     MachPara[1802] //PID整定最低目标温度                         PID整定最低目标温度，即整定设置的目标温度应高于该温度
#define Para_TCTunPCoef          MachPara[1803] //PID整定时P系数                           PID整定时根据经验公式得到P时，再乘以该系数进行修正
#define Para_TCTunICoef          MachPara[1804] //PID整定时I系数                           PID整定时根据经验公式得到I时，再乘以该系数进行修正
#define Para_TCTunDCoef          MachPara[1805] //PID整定时D系数                           PID整定时根据经验公式得到D时，再乘以该系数进行修正
#define Para_TCTunBuffMax        MachPara[1806] //PID整定缓冲区上限                          整出的缓冲区应小于该值，超则丢弃本次整定
#define Para_TCTunBuffMin        MachPara[1807] //PID整定缓冲区下限                          整出的缓冲区应大于该值，超则丢弃本次整定
#define Para_TCTunBuffOver       MachPara[1808] //PID整定缓冲区超调量                         整出的缓冲区要略低，该超调量即该故意低的温度
#define Para_TCTunBuffThre       MachPara[1809] //PID整定缓冲区起调量                         整出的缓冲区与原先值小于该起调量，则不调整，即保持缓冲区不变
#define Para_TCPID_MaxUin        MachPara[1810] //PID单次最大积分量                          PID单次最大积分量，超过按该值累加
#define Para_TCTunRateThre       MachPara[1811] //PID整定升温速率门限                         升温速度降到该值时，判断过冲结束，用于缓冲区整定、过冲温度和时间整定
#define Para_Mach_1812           MachPara[1812] //                                    
#define Para_Mach_1813           MachPara[1813] //                                    
#define Para_Mach_1814           MachPara[1814] //                                    
#define Para_Mach_1815           MachPara[1815] //                                    
#define Para_Mach_1816           MachPara[1816] //                                    
#define Para_Mach_1817           MachPara[1817] //                                    
#define Para_Mach_1818           MachPara[1818] //                                    
#define Para_Mach_1819           MachPara[1819] //                                    
#define Para_Zone1OnFlag         MachPara[1820] //1段料筒开启                              X段料筒开启
#define Para_Zone2OnFlag         MachPara[1821] //2段料筒开启                              X段料筒开启
#define Para_Zone3OnFlag         MachPara[1822] //3段料筒开启                              X段料筒开启
#define Para_Zone4OnFlag         MachPara[1823] //4段料筒开启                              X段料筒开启
#define Para_Zone5OnFlag         MachPara[1824] //5段料筒开启                              X段料筒开启
#define Para_Zone6OnFlag         MachPara[1825] //6段料筒开启                              X段料筒开启
#define Para_Zone7OnFlag         MachPara[1826] //7段料筒开启                              X段料筒开启
#define Para_Zone8OnFlag         MachPara[1827] //8段料筒开启                              X段料筒开启
#define Para_Zone9OnFlag         MachPara[1828] //9段料筒开启                              X段料筒开启
#define Para_Zone10OnFlag        MachPara[1829] //10段料筒开启                             X段料筒开启
#define Para_Zone11OnFlag        MachPara[1830] //11段料筒开启                             X段料筒开启
#define Para_Zone12OnFlag        MachPara[1831] //12段料筒开启                             X段料筒开启
#define Para_Zone13OnFlag        MachPara[1832] //13段料筒开启                             X段料筒开启
#define Para_Zone14OnFlag        MachPara[1833] //14段料筒开启                             X段料筒开启
#define Para_Zone15OnFlag        MachPara[1834] //15段料筒开启                             X段料筒开启
#define Para_Zone16OnFlag        MachPara[1835] //16段料筒开启                             X段料筒开启
#define Para_Zone1TCT_TunTemp    MachPara[1836] //1段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone2TCT_TunTemp    MachPara[1837] //2段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone3TCT_TunTemp    MachPara[1838] //3段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone4TCT_TunTemp    MachPara[1839] //4段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone5TCT_TunTemp    MachPara[1840] //5段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone6TCT_TunTemp    MachPara[1841] //6段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone7TCT_TunTemp    MachPara[1842] //7段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone8TCT_TunTemp    MachPara[1843] //8段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone9TCT_TunTemp    MachPara[1844] //9段整定温度                              X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone10TCT_TunTemp   MachPara[1845] //10段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone11TCT_TunTemp   MachPara[1846] //11段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone12TCT_TunTemp   MachPara[1847] //12段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone13TCT_TunTemp   MachPara[1848] //13段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone14TCT_TunTemp   MachPara[1849] //14段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone15TCT_TunTemp   MachPara[1850] //15段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone16TCT_TunTemp   MachPara[1851] //16段整定温度                             X段整定时所对应的目标温度,0-即未整定过
#define Para_Zone1TCT_HeatRate   MachPara[1852] //1段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone2TCT_HeatRate   MachPara[1853] //2段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone3TCT_HeatRate   MachPara[1854] //3段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone4TCT_HeatRate   MachPara[1855] //4段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone5TCT_HeatRate   MachPara[1856] //5段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone6TCT_HeatRate   MachPara[1857] //6段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone7TCT_HeatRate   MachPara[1858] //7段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone8TCT_HeatRate   MachPara[1859] //8段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone9TCT_HeatRate   MachPara[1860] //9段温升速率                              X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone10TCT_HeatRate  MachPara[1861] //10段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone11TCT_HeatRate  MachPara[1862] //11段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone12TCT_HeatRate  MachPara[1863] //12段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone13TCT_HeatRate  MachPara[1864] //13段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone14TCT_HeatRate  MachPara[1865] //14段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone15TCT_HeatRate  MachPara[1866] //15段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone16TCT_HeatRate  MachPara[1867] //16段温升速率                             X段整定得到的最大升温速率，单位0.001℃/10s
#define Para_Zone1TCT_OverTemp   MachPara[1868] //1段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone2TCT_OverTemp   MachPara[1869] //2段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone3TCT_OverTemp   MachPara[1870] //3段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone4TCT_OverTemp   MachPara[1871] //4段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone5TCT_OverTemp   MachPara[1872] //5段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone6TCT_OverTemp   MachPara[1873] //6段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone7TCT_OverTemp   MachPara[1874] //7段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone8TCT_OverTemp   MachPara[1875] //8段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone9TCT_OverTemp   MachPara[1876] //9段过冲温度                              X段整定得到热惯性引起过冲温度
#define Para_Zone10TCT_OverTemp  MachPara[1877] //10段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone11TCT_OverTemp  MachPara[1878] //11段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone12TCT_OverTemp  MachPara[1879] //12段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone13TCT_OverTemp  MachPara[1880] //13段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone14TCT_OverTemp  MachPara[1881] //14段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone15TCT_OverTemp  MachPara[1882] //15段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone16TCT_OverTemp  MachPara[1883] //16段过冲温度                             X段整定得到热惯性引起过冲温度
#define Para_Zone1TCT_OverTime   MachPara[1884] //1段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone2TCT_OverTime   MachPara[1885] //2段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone3TCT_OverTime   MachPara[1886] //3段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone4TCT_OverTime   MachPara[1887] //4段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone5TCT_OverTime   MachPara[1888] //5段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone6TCT_OverTime   MachPara[1889] //6段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone7TCT_OverTime   MachPara[1890] //7段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone8TCT_OverTime   MachPara[1891] //8段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone9TCT_OverTime   MachPara[1892] //9段过冲时间                              X段整定得到热惯性引起过冲时间
#define Para_Zone10TCT_OverTime  MachPara[1893] //10段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone11TCT_OverTime  MachPara[1894] //11段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone12TCT_OverTime  MachPara[1895] //12段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone13TCT_OverTime  MachPara[1896] //13段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone14TCT_OverTime  MachPara[1897] //14段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone15TCT_OverTime  MachPara[1898] //15段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone16TCT_OverTime  MachPara[1899] //16段过冲时间                             X段整定得到热惯性引起过冲时间
#define Para_Zone1TCPID_P_Dyn    MachPara[1900] //1段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone2TCPID_P_Dyn    MachPara[1901] //2段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone3TCPID_P_Dyn    MachPara[1902] //3段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone4TCPID_P_Dyn    MachPara[1903] //4段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone5TCPID_P_Dyn    MachPara[1904] //5段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone6TCPID_P_Dyn    MachPara[1905] //6段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone7TCPID_P_Dyn    MachPara[1906] //7段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone8TCPID_P_Dyn    MachPara[1907] //8段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone9TCPID_P_Dyn    MachPara[1908] //9段PID的动态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone10TCPID_P_Dyn   MachPara[1909] //10段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone11TCPID_P_Dyn   MachPara[1910] //11段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone12TCPID_P_Dyn   MachPara[1911] //12段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone13TCPID_P_Dyn   MachPara[1912] //13段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone14TCPID_P_Dyn   MachPara[1913] //14段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone15TCPID_P_Dyn   MachPara[1914] //15段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone16TCPID_P_Dyn   MachPara[1915] //16段PID的动态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone1TCPID_P_Sta    MachPara[1916] //1段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone2TCPID_P_Sta    MachPara[1917] //2段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone3TCPID_P_Sta    MachPara[1918] //3段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone4TCPID_P_Sta    MachPara[1919] //4段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone5TCPID_P_Sta    MachPara[1920] //5段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone6TCPID_P_Sta    MachPara[1921] //6段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone7TCPID_P_Sta    MachPara[1922] //7段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone8TCPID_P_Sta    MachPara[1923] //8段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone9TCPID_P_Sta    MachPara[1924] //9段PID的静态P                           X段PID的动态P值，单位1ms/℃
#define Para_Zone10TCPID_P_Sta   MachPara[1925] //10段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone11TCPID_P_Sta   MachPara[1926] //11段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone12TCPID_P_Sta   MachPara[1927] //12段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone13TCPID_P_Sta   MachPara[1928] //13段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone14TCPID_P_Sta   MachPara[1929] //14段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone15TCPID_P_Sta   MachPara[1930] //15段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone16TCPID_P_Sta   MachPara[1931] //16段PID的静态P                          X段PID的动态P值，单位1ms/℃
#define Para_Zone1TempBuff_Up    MachPara[1932] //1段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone2TempBuff_Up    MachPara[1933] //2段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone3TempBuff_Up    MachPara[1934] //3段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone4TempBuff_Up    MachPara[1935] //4段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone5TempBuff_Up    MachPara[1936] //5段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone6TempBuff_Up    MachPara[1937] //6段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone7TempBuff_Up    MachPara[1938] //7段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone8TempBuff_Up    MachPara[1939] //8段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone9TempBuff_Up    MachPara[1940] //9段温度缓冲区(上面)                         X段温度缓冲区(超出目标温度)
#define Para_Zone10TempBuff_Up   MachPara[1941] //10段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone11TempBuff_Up   MachPara[1942] //11段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone12TempBuff_Up   MachPara[1943] //12段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone13TempBuff_Up   MachPara[1944] //13段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone14TempBuff_Up   MachPara[1945] //14段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone15TempBuff_Up   MachPara[1946] //15段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Zone16TempBuff_Up   MachPara[1947] //16段温度缓冲区(上面)                        X段温度缓冲区(超出目标温度)
#define Para_Mach_1948           MachPara[1948] //                                    
#define Para_Mach_1949           MachPara[1949] //                                    
#define Para_EtherCATCyc         MachPara[1950] //EtherCAT通讯周期                        EtherCAT通讯周期
#define Para_EcSlave1Type        MachPara[1951] //第1个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave2Type        MachPara[1952] //第2个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave3Type        MachPara[1953] //第3个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave4Type        MachPara[1954] //第4个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave5Type        MachPara[1955] //第5个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave6Type        MachPara[1956] //第6个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave7Type        MachPara[1957] //第7个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcSlave8Type        MachPara[1958] //第8个EtherCAT从站类型                     从站类型：0-无；1-J6H卡液压机应用
#define Para_EcWRSlave1Bytes     MachPara[1959] //写第1个EtherCAT从站字节数                   写第1个EtherCAT从站字节数
#define Para_EcWRSlave2Bytes     MachPara[1960] //写第2个EtherCAT从站字节数                   写第2个EtherCAT从站字节数
#define Para_EcWRSlave3Bytes     MachPara[1961] //写第3个EtherCAT从站字节数                   写第3个EtherCAT从站字节数
#define Para_EcWRSlave4Bytes     MachPara[1962] //写第4个EtherCAT从站字节数                   写第4个EtherCAT从站字节数
#define Para_EcWRSlave5Bytes     MachPara[1963] //写第5个EtherCAT从站字节数                   写第5个EtherCAT从站字节数
#define Para_EcWRSlave6Bytes     MachPara[1964] //写第6个EtherCAT从站字节数                   写第6个EtherCAT从站字节数
#define Para_EcWRSlave7Bytes     MachPara[1965] //写第7个EtherCAT从站字节数                   写第7个EtherCAT从站字节数
#define Para_EcWRSlave8Bytes     MachPara[1966] //写第8个EtherCAT从站字节数                   写第8个EtherCAT从站字节数
#define Para_EcRDSlave1Bytes     MachPara[1967] //读第1个EtherCAT从站字节数                   读第1个EtherCAT从站字节数
#define Para_EcRDSlave2Bytes     MachPara[1968] //读第2个EtherCAT从站字节数                   读第2个EtherCAT从站字节数
#define Para_EcRDSlave3Bytes     MachPara[1969] //读第3个EtherCAT从站字节数                   读第3个EtherCAT从站字节数
#define Para_EcRDSlave4Bytes     MachPara[1970] //读第4个EtherCAT从站字节数                   读第4个EtherCAT从站字节数
#define Para_EcRDSlave5Bytes     MachPara[1971] //读第5个EtherCAT从站字节数                   读第5个EtherCAT从站字节数
#define Para_EcRDSlave6Bytes     MachPara[1972] //读第6个EtherCAT从站字节数                   读第6个EtherCAT从站字节数
#define Para_EcRDSlave7Bytes     MachPara[1973] //读第7个EtherCAT从站字节数                   读第7个EtherCAT从站字节数
#define Para_EcRDSlave8Bytes     MachPara[1974] //读第8个EtherCAT从站字节数                   读第8个EtherCAT从站字节数
#define Para_J6H_Opt             MachPara[1975] //J6H卡配备                              J6H卡配备几块
#define Para_InovServoDriverNum  MachPara[1976] //汇川伺服驱动器实际使用个数                       汇川伺服驱动器实际使用个数
#define Para_KebServoDriverNum   MachPara[1977] //KEB伺服驱动器实际使用个数                      KEB伺服驱动器实际使用个数
#define Para_Mach_1978           MachPara[1978] //                                    
#define Para_Mach_1979           MachPara[1979] //                                    
#define Para_Mach_1980           MachPara[1980] //                                    
#define Para_Mach_1981           MachPara[1981] //                                    
#define Para_Mach_1982           MachPara[1982] //                                    
#define Para_Mach_1983           MachPara[1983] //                                    
#define Para_Mach_1984           MachPara[1984] //                                    
#define Para_Mach_1985           MachPara[1985] //                                    
#define Para_Mach_1986           MachPara[1986] //                                    
#define Para_Mach_1987           MachPara[1987] //                                    
#define Para_Mach_1988           MachPara[1988] //                                    
#define Para_Mach_1989           MachPara[1989] //                                    
#define Para_Mach_1990           MachPara[1990] //                                    
#define Para_Mach_1991           MachPara[1991] //                                    
#define Para_Mach_1992           MachPara[1992] //                                    
#define Para_Mach_1993           MachPara[1993] //                                    
#define Para_Mach_1994           MachPara[1994] //                                    
#define Para_Mach_1995           MachPara[1995] //                                    
#define Para_Mach_1996           MachPara[1996] //                                    
#define Para_Mach_1997           MachPara[1997] //                                    
#define Para_Mach_1998           MachPara[1998] //                                    
#define Para_Mach_1999           MachPara[1999] //                                    
#define Para_Mach_2000           MachPara[2000] //                                    老化测试中用到，尽量避免定义使用
#define Para_Mach_2001           MachPara[2001] //                                    老化测试中用到，尽量避免定义使用
#define Para_Mach_2002           MachPara[2002] //                                    老化测试中用到，尽量避免定义使用
#define Para_Mach_2003           MachPara[2003] //                                    老化测试中用到，尽量避免定义使用
#define Para_Mach_2004           MachPara[2004] //                                    
#define Para_Mach_2005           MachPara[2005] //                                    
#define Para_Mach_2006           MachPara[2006] //                                    
#define Para_Mach_2007           MachPara[2007] //                                    
#define Para_Mach_2008           MachPara[2008] //                                    
#define Para_Mach_2009           MachPara[2009] //                                    
#define Para_Mach_2010           MachPara[2010] //                                    
#define Para_Mach_2011           MachPara[2011] //                                    
#define Para_Mach_2012           MachPara[2012] //                                    
#define Para_Mach_2013           MachPara[2013] //                                    
#define Para_MoldClsEPos         MachPara[2014] //关模终位置                               锐能：关模终位置，使用油缸位置
#define Para_MoldClsEPosEN       MachPara[2015] //关模终位置使能                             锐能：关模终位置有效，即到位采用行程开关+位置
#define Para_HandSignOpt         MachPara[2016] //应答信号配备                              锐能：增加一对应答信号，用于驱动器之间握手
#define Para_CoolMoldOpenEn      MachPara[2017] //冷却时开模使能                             锐能：冷却时松开模具，避免长时间冷却导致开模困难
#define Para_Mach_2018           MachPara[2018] //                                    
#define Para_Mach_2019           MachPara[2019] //                                    
#define Para_MoldOpenSlowValMode MachPara[2020] //开模缓冲阀模式                             光塑：mRO_MoldOpenSlow_GS阀的输出模式：0-关闭、1-一慢、2-二慢、3-一慢+二慢
#define Para_MoldOpenClsMidMode  MachPara[2021] //开合模中位模式                             宁波汇欣:0-开模5段不输出，1-开模5段输出
#define Para_SmallMotorZoneChan  MachPara[2022] //小电机料筒通道                             小电机对应料筒通道，0：关闭；1-16：分别选择1-16段料筒作为小电机通道
#define Para_SmallMotorOnDly     MachPara[2023] //小电机输出延时                             
#define Para_SmallMotSnrChkTi    MachPara[2024] //小电机检测时间                             
#define Para_SmallMotSnrFiltTime MachPara[2025] //小电机滤波时间                             
#define Para_Mach_2026           MachPara[2026] //                                    
#define Para_Mach_2027           MachPara[2027] //                                    
#define Para_Mach_2028           MachPara[2028] //                                    
#define Para_ScrewRPMMeasCal     MachPara[2029] //螺杆转速测量方法                            0-依齿数自动选算法，用“1/t”或“cnt/1s”，1-测一圈用时，然后“1/t*齿数”，满足齿少、且分布不均
#define Para_Mach_2030           MachPara[2030] //                                    
#define Para_Mach_2031           MachPara[2031] //                                    
#define Para_Mach_2032           MachPara[2032] //                                    
#define Para_Mach_2033           MachPara[2033] //                                    
#define Para_MoldClsDiffValOnPos MachPara[2034] //差动阀开位置                              博祥塑机：差动阀ON位置(暂保留未用)
#define Para_MoldClsDiffValOffPos MachPara[2035]//差动阀关位置                              博祥塑机：差动阀Off位置
#define Para_MoldOpenDiffValOnTi MachPara[2036] //开模差动阀开时间                            甬辉机械：开模时差动阀用时间控制,关模同标准差动
#define Para_MoldOpenDiffValOffPos MachPara[2037]//开模差动阀关位置                           乐能机械：开模1段时差动阀用位置控制,关模同标准差动
#define Para_MoldOpenBPLog       MachPara[2038] //开模背压逻辑                              盈泰：0-小机，开模始计时输出后面不输出；1-大机，开模始计时不输出后面输出
#define Para_Mach_2039           MachPara[2039] //                                    
#define Para_ServoDrvErrSignOpt  MachPara[2040] //驱动器报警信号配备                           0-无、1－常闭、2－常开
#define Para_ServoDrvTempStaOpt  MachPara[2041] //驱动器温度信号配备                           0-无、1-配备
#define Para_Mach_2042           MachPara[2042] //                                    
#define Para_Mach_2043           MachPara[2043] //                                    
#define Para_Mach_2044           MachPara[2044] //                                    
#define Para_MachSoftLockOpt     MachPara[2045] //界面主机维护互锁配备                          0-主机不配备 1-主机配备
#define Para_MachWMProdBatch     MachPara[2046] //界面生产批号                              
#define Para_MachWMProdSN        MachPara[2047] //界面生产序号                              

#endif
