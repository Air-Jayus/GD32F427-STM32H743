/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_Resource.h    资源定义文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0x00AB  
****************************************************************************************************/
#ifndef CM_Resource_h
    #define CM_Resource_h

#ifdef RPHA_c
    #define CM_Resource_ext
#else
    #define CM_Resource_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//资源数量
#define mResBitNum 1024  //Bit类型资源数量
#define mResU32Num 256   //U32类型资源数量
#define mResNum    1280	 //资源数量

//资源序号分配
#define mResBitStaNum  0                            //Bit类型资源变量起始序号
#define mResBitEndNum  (mResBitNum-1)               //Bit类型资源变量结束序号
#define mResU32StaNum  (mResBitEndNum+1)            //U32类型资源变量起始序号
#define mResU32EndNum  (mResU32StaNum+mResU32Num-1) //U32类型资源变量结束序号

//资源引用宏定义
#define OpenResBit(Sn) ResBit[Sn]=mTrue                         //Bit类型资源 打开-mTrue   针对输出资源变量
#define ClsResBit(Sn)  ResBit[Sn]=mFalse                        //Bit类型资源 关闭--mFalse 针对输出资源变量
#define SetResBit(Sn)  ResBit[Sn]=mTrue                         //Bit类型资源 置位--mTrue  针对输入资源变量
#define RstResBit(Sn)  ResBit[Sn]=mFalse                        //Bit类型资源 复位--mFalse 针对输入资源变量
#define RdResBit(Sn)   ResBit[Sn]                               //Bit类型资源 获取         输出、输入资源变量均可
#define GetResBit(Sn)  ResBit[Sn]                               //Bit类型资源 获取         输出、输入资源变量均可

#define RdResU32(Sn)       ResU32[Sn-mResU32StaNum]             //读U32类型资源
#define WrResU32(Sn,Value) ResU32[Sn-mResU32StaNum]=Value       //写U32类型资源

#define GetAddr_ResBit(Sn) (&ResBit[Sn])                        //获取Bit类型资源变量地址
#define GetAddr_ResU32(Sn) (&ResU32[Sn-mResU32StaNum])          //获取U32类型资源变量地址

//资源数组定义及初始化
#ifndef RPHA_c
    extern U8 ResBit[mResBitNum];    //Bit类型资源数组定义
    extern U32 ResU32[mResU32Num];   //U32类型资源数组定义
#else
    U8 ResBit[mResBitNum]={          //Bit类型资源数组定义
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    U32 ResU32[mResU32Num]={         //U32类型资源数组定义
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif

//Bit类型资源序号宏定义
#define mRI_StartSN              0              //                                    辅助用，禁止修改
#define mRI_Null                 1              //                                    辅助用，DI类型空资源，程序中可写入但禁止引用
#define mRI_2                    2              //                                    
#define mRI_EmerButton           3              //紧急停止                                
#define mRI_MoldClsEnd           4              //关模终止                                
#define mRI_MoldAdjThinEnd       5              //调模进终                                
#define mRI_MoldAdjThickEnd      6              //调模退终                                
#define mRI_NozForEnd            7              //座台进终                                
#define mRI_NozRetEnd            8              //座台退终                                
#define mRI_EjeForEnd            9              //顶针进终                                
#define mRI_EjeRetEnd            10             //顶针退终                                
#define mRI_NozSafeGate          11             //射出防护                                
#define mRI_NozSafeGate2         12             //射出防护二                               GB22530安全标准
#define mRI_NozLimitSwitch       13             //射退限位                                射退限位:为ON则禁止座退、储料、射退。用于注射加厂机器，避免撞到座台的限位档块
#define mRI_MoldAdjSnr           14             //调模电眼                                
#define mRI_ProdSnr              15             //检物电眼                                
#define mRI_ScrewRPMSnr          16             //螺杆转速电眼                              
#define mRI_OilLessSnr           17             //油位检知                                
#define mRI_OilFilterJam         18             //滤网检知                                
#define mRI_HopperSnr            19             //料斗检知                                
#define mRI_Lubr1PresSnr         20             //润滑检知                                润滑压力到 
#define mRI_Lubr1OilLessSnr      21             //润滑液位检知                              
#define mRI_Lubr2PresSnr         22             //润滑2检知                               润滑压力到 
#define mRI_Lubr2OilLessSnr      23             //润滑2液位检知                             
#define mRI_Lubr3PresSnr         24             //润滑3检知                               润滑压力到 
#define mRI_ScrewRPMSnr2         25             //螺杆转速2                               双阶机用，二组螺杆电眼
#define mRI_LubrMB2PresSnr       26             //二板润滑检知                              润滑压力到 
#define mRI_PilotOilPresSnr      27             //先导油压检测                              注射、合模插装阀油路机器，先导油蓄能器压力检测，通常装配于1600T以上大机
#define mRI_AccPresSnr           28             //蓄能压力                                
#define mRI_HydProtSnr           29             //液压保险检测                              
#define mRI_MachProtSnr          30             //机械保险检测                              
#define mRI_SafeRelayRst         31             //安全继电器                               GB22530安全标准，安全继电器复位信号
#define mRI_SrwASnr              32             //绞牙A电眼                               
#define mRI_CycStartKey          33             //循环启动键                               GB22530安全标准，半自动安上安全门，还需按一下该键才可
#define mRI_ServoDrvErr          34             //驱动器警报                               伺服驱动器警报，反逻辑，0-警报、1-正常
#define mRI_AirSrcPresSnr        35             //气源压力检知                              机械保险用气源压力不足信号
#define mRI_HandShankSnr         36             //手柄检测                                
#define mRI_ToggleProtSnr        37             //开模区防护                               
#define mRI_ServoDrvTempSta      38             //驱动器温度                               伺服驱动器警报，逻辑，1-正常、0-超温、变化-偏高
#define mRI_CycStopKey           39             //循环停止键                               GB22530安全标准，类似手动键。平时为1，自动方式时如果变为0，则转手动
#define mRI_TieRodsMon           40             //拉杆受力监测                              拉杆受力监测。常闭型，即：1-正常、0-报警
#define mRI_PropValState         41             //比例阀警报                               带自检功能的高级比例阀，有故障时报警信号。（保留，程序暂不支持）
#define mRI_J_EnClamp            42             //J.关模允许                              模具夹具用，允许合模信号，ON则允许关模
#define mRI_J_EnMoldOpen         43             //J.开模允许                              模具夹具用，允许开模信号，ON则允许开模
#define mRI_MotorErr             44             //电机异常                                电机异常，常闭，OFF则警报:电机相位或风扇异常
#define mRI_SafeGateFixBack      45             //固定门关                                大机后安全门有二个，一个活动、一个固定，此即固定门
#define mRI_SafePlug             46             //安全插头                                常闭，逻辑同紧急停止
#define mRI_MotorTempOL          47             //电机过热                                应北化眼镜机
#define mRI_OilFilterJam0        48             //滤油网检测#0                             
#define mRI_OilLessSnr2          49             //                                    油位检知2：用于提示油位不足；与“油位检知”的区别在于后者是报警、停动作。
#define mRI_SafeGateFrontNO      50             //安全门开                                常开
#define mRI_SafeGateFront        51             //安全门关                                
#define mRI_SafeGateFront2       52             //安全门关二                               
#define mRI_SafeGateBack         53             //后安全门关                               
#define mRI_SafeGateTop          54             //上顶盖关                                
#define mRI_SafeGateBut          55             //底板关                                 
#define mRI_SafeGateEnd          56             //尾板小门                                尾板处的检修小门，常闭，天剑快速机程序专用，标准机不使用
#define mRI_MoldSlidBlockMon     57             //                                    模具滑块确认
#define mRI_ChgMotorCoolValUnCls 58             //                                    电储料冷却水阀未关
#define mRI_ChgMotorGearErr      59             //                                    电储料齿轮异常
#define mRI_Core01InEnd          60             //中子A进终                               
#define mRI_Core01OutEnd         61             //中子A退终                               
#define mRI_Core02InEnd          62             //中子B进终                               
#define mRI_Core02OutEnd         63             //中子B退终                               
#define mRI_Core03InEnd          64             //中子C进终                               
#define mRI_Core03OutEnd         65             //中子C退终                               
#define mRI_Core04InEnd          66             //中子D进终                               
#define mRI_Core04OutEnd         67             //中子D退终                               
#define mRI_Core05InEnd          68             //中子E进终                               
#define mRI_Core05OutEnd         69             //中子E退终                               
#define mRI_Core06InEnd          70             //中子F进终                               
#define mRI_Core06OutEnd         71             //中子F退终                               
#define mRI_Core07InEnd          72             //中子G进终                               
#define mRI_Core07OutEnd         73             //中子G退终                               
#define mRI_Core08InEnd          74             //中子H进终                               
#define mRI_Core08OutEnd         75             //中子H退终                               
#define mRI_Core09InEnd          76             //中子I进终                               
#define mRI_Core09OutEnd         77             //中子I退终                               
#define mRI_Core10InEnd          78             //中子J进终                               
#define mRI_Core10OutEnd         79             //中子J退终                               
#define mRI_Core11InEnd          80             //中子K进终                               
#define mRI_Core11OutEnd         81             //中子K退终                               
#define mRI_Core12InEnd          82             //中子L进终                               
#define mRI_Core12OutEnd         83             //中子L退终                               
#define mRI_Core01SrwSnr         84             //                                    绞牙A电眼
#define mRI_ProdSnr1             85             //检物电眼1                               检物电眼1
#define mRI_ProdSnr2             86             //检物电眼2                               检物电眼2
#define mRI_ProdSnr3             87             //检物电眼3                               检物电眼3
#define mRI_ProdSnr4             88             //检物电眼4                               检物电眼4
#define mRI_89                   89             //                                    
#define mRI_R_RobotRetEnd        90             //机械手回到位                              简易机械手、Start：1-允许关模
#define mRI_R_RobotOptMode       91             //R.机械手不用                             Euro 67/12：1-机械手不使用  0-使用
#define mRI_R_EmerStop           92             //R.机械手紧停                             Euro 67/12、Start：1-正常   0-机械手按下紧急停止
#define mRI_R_CycStart           93             //R.循环启动                              Start：1-立即启动新的循环   一个循环中应能检测到信号0
#define mRI_R_MoldAreaFree       94             //R.模区安全                              Euro 67/12：1-允许开、合模
#define mRI_R_EnClamp            95             //R.关模允许                              Euro 67/12：1-允许关模
#define mRI_R_EnMoldOpen         96             //R.开模允许                              Start：1-允许开模
#define mRI_R_EnFullMoldOpen     97             //R.全开模允许                             Euro 67/12：1-中途取件时，允许继续开模
#define mRI_R_EnEjeFor           98             //R.托模进允许                             Euro 67/12、Start：1-允许托模进
#define mRI_R_EnEjeRet           99             //R.托模退允许                             Euro 67/12、Start：1-允许托模退
#define mRI_R_EnCoreIn           100            //R.中子进允许                             Euro 67/12：1-允许中子进
#define mRI_R_EnCoreOut          101            //R.中子退允许                             Euro 67/12：1-允许中子退
#define mRI_R_EnClamp_AutoMode   102            //R.自动关模允                             特殊机械手：1-允许关模，只在自动模式时有效。与R_EnClamp区别：该点只在自动时检查，手动时不检查
#define mRI_ExtAlarm             103            //外部警报                                
#define mRI_BMCFeedInButt        104            //加料进                                 
#define mRI_BMCFeedOutButt       105            //加料退                                 
#define mRI_BMCFeedInEnd         106            //加料进终                                
#define mRI_BMCFeedOutEnd        107            //加料退终                                
#define mRI_BMCCoverClsEnd       108            //压料盖关到位                              
#define mRI_BMCCoverOpenEnd      109            //压料盖开到位                              
#define mRI_BMCNoMaterial        110            //缺料警报                                
#define mRI_PresOfMvPlt          111            //动板充液检知                              
#define mRI_SafePlate            112            //安全踏板                                
#define mRI_Steam_EnInject       113            //S.允许注射                              
#define mRI_Steam_EnMoldOpen     114            //S.允许开模                              
#define mRI_CorePresRelButt      115            //泄压按键                                
#define mRI_MoldRst              116            //                                    模具复位
#define mRI_PumpLevel            117            //泵站液位                                泵站液位,液位不足报警(只提示)
#define mRI_BypassRlyFeed        118            //旁路反馈                                CE土标要求,旁路继电器
#define mRI_SafeGateSenor        119            //安全门检知                               安全门检知，该信号为ON，则禁止自动门关闭，避免安全门夹到异物，通常该信号来自安全门电眼
#define mRI_AutoGateOpenButt     120            //自动门开按钮                              按一下，自动门开，再按则停
#define mRI_AutoGateClsButt      121            //自动门关按钮                              按一下，自动门关，再按则停
#define mRI_AutoGateOpenSlow     122            //自动门开慢速                              主要用于气动门。自动门开时，该信号ON，则输出慢速信号1秒时间
#define mRI_AutoGateClsSlow      123            //自动门关慢速                              主要用于气动门。自动门关时，该信号ON，则输出慢速信号1秒时间
#define mRI_AutoGateOpenEnd      124            //自动门开到位                              自动门开到位
#define mRI_AutoGatErr           125            //自动门警报                               自动门警报
#define mRI_AutoGatePulseSign    126            //自动门脉冲                               KEB门机用
#define mRI_EjeRetEnd2           127            //顶针退终2                               顶针退终2
#define mRI_FrtBrkInEnd          128            //头闸板进终                               用于抽拉杆功能
#define mRI_FrtBrkOutEnd         129            //头闸板退终                               用于抽拉杆功能
#define mRI_ReBrkInEnd           130            //尾闸板进终                               用于抽拉杆功能
#define mRI_ReBrkOutEnd          131            //尾闸板退终                               用于抽拉杆功能
#define mRI_TieBarFwEnd          132            //拉杆进终                                用于抽拉杆功能
#define mRI_TieBarBwEnd          133            //拉杆退终                                用于抽拉杆功能
#define mRI_BtwBrkInKey          134            //闸板进按钮                               用于抽拉杆功能
#define mRI_BtwBrkOutKey         135            //闸板退按钮                               用于抽拉杆功能
#define mRI_BarFwKey             136            //拉杆进按钮                               用于抽拉杆功能
#define mRI_BarBwKey             137            //拉杆退按钮                               用于抽拉杆功能
#define mRI_TieBarSelKey         138            //抽拉杆使用                               用于抽拉杆功能
#define mRI_TieBarSafeVal        139            //安全阀反馈                               用于抽拉杆功能
#define mRI_MoldAdjLubrPres      140            //调模润滑压力                              应调模润滑功能
#define mRI_ChgServoDrvErr       141            //                                    伺服驱动器警报，反逻辑，0-警报、1-正常
#define mRI_PowerMon             142            //电源确认                                电源确认
#define mRI_MotorOverload        143            //马达过载                                马达过载
#define mRI_MoldProtect          144            //模具保护                                模具保护
#define mRI_SmallMotRPMSnr       145            //小电机转速                               科隆格：小电机转速
#define mRI_HoldPresRetButt      146            //                                    保压退按钮
#define mRI_BMCFeedLadd          147            //加料爬梯                                加料爬梯
#define mRI_HandSign_R           148            //应答信号(R)                             锐能：应答信号，未收到该信号则警报
#define mRI_149                  149            //                                    
#define mRI_150                  150            //                                    
#define mRI_151                  151            //                                    
#define mRI_152                  152            //                                    
#define mRI_153                  153            //                                    
#define mRI_154                  154            //                                    
#define mRI_155                  155            //                                    
#define mRI_156                  156            //                                    
#define mRI_157                  157            //                                    
#define mRI_158                  158            //                                    
#define mRI_159                  159            //                                    
#define mRI_160                  160            //                                    
#define mRI_161                  161            //                                    
#define mRI_162                  162            //                                    
#define mRI_163                  163            //                                    
#define mRI_164                  164            //                                    
#define mRI_165                  165            //                                    
#define mRI_166                  166            //                                    
#define mRI_167                  167            //                                    
#define mRI_168                  168            //                                    
#define mRI_169                  169            //                                    
#define mRI_170                  170            //                                    
#define mRI_171                  171            //                                    
#define mRI_172                  172            //                                    
#define mRI_173                  173            //                                    
#define mRI_174                  174            //                                    
#define mRI_175                  175            //                                    
#define mRI_176                  176            //                                    
#define mRI_177                  177            //                                    
#define mRI_178                  178            //                                    
#define mRI_179                  179            //                                    
#define mRI_180                  180            //                                    
#define mRI_181                  181            //                                    
#define mRI_182                  182            //                                    
#define mRI_183                  183            //                                    
#define mRI_184                  184            //                                    
#define mRI_185                  185            //                                    
#define mRI_186                  186            //                                    
#define mRI_187                  187            //                                    
#define mRI_188                  188            //                                    
#define mRI_189                  189            //                                    
#define mRI_190                  190            //                                    
#define mRI_191                  191            //                                    
#define mRI_192                  192            //                                    
#define mRI_193                  193            //                                    
#define mRI_194                  194            //                                    
#define mRI_195                  195            //                                    
#define mRI_196                  196            //                                    
#define mRI_197                  197            //                                    
#define mRI_198                  198            //                                    
#define mRI_199                  199            //                                    
#define mRI_200                  200            //                                    
#define mRI_201                  201            //                                    
#define mRI_202                  202            //                                    
#define mRI_203                  203            //                                    
#define mRI_204                  204            //                                    
#define mRI_205                  205            //                                    
#define mRI_206                  206            //                                    
#define mRI_207                  207            //                                    
#define mRI_208                  208            //                                    
#define mRI_209                  209            //                                    
#define mRI_210                  210            //                                    
#define mRI_211                  211            //                                    
#define mRI_212                  212            //                                    
#define mRI_213                  213            //                                    
#define mRI_214                  214            //                                    
#define mRI_215                  215            //                                    
#define mRI_216                  216            //                                    
#define mRI_217                  217            //                                    
#define mRI_218                  218            //                                    
#define mRI_219                  219            //                                    
#define mRI_220                  220            //                                    
#define mRI_221                  221            //                                    
#define mRI_222                  222            //                                    
#define mRI_223                  223            //                                    
#define mRI_224                  224            //                                    
#define mRI_225                  225            //                                    
#define mRI_226                  226            //                                    
#define mRI_227                  227            //                                    
#define mRI_228                  228            //                                    
#define mRI_229                  229            //                                    
#define mRI_230                  230            //                                    
#define mRI_231                  231            //                                    
#define mRI_232                  232            //                                    
#define mRI_233                  233            //                                    
#define mRI_234                  234            //                                    
#define mRI_235                  235            //                                    
#define mRI_236                  236            //                                    
#define mRI_237                  237            //                                    
#define mRI_238                  238            //                                    
#define mRI_239                  239            //                                    
#define mRI_240                  240            //                                    
#define mRI_241                  241            //                                    
#define mRI_242                  242            //                                    
#define mRI_243                  243            //                                    
#define mRI_244                  244            //                                    
#define mRI_245                  245            //                                    
#define mRI_246                  246            //                                    
#define mRI_247                  247            //                                    
#define mRI_248                  248            //                                    
#define mRI_249                  249            //                                    
#define mRI_250                  250            //                                    
#define mRI_251                  251            //                                    
#define mRI_252                  252            //                                    
#define mRI_253                  253            //                                    
#define mRI_254                  254            //                                    
#define mRI_255                  255            //                                    
#define mRI_256                  256            //                                    
#define mRI_257                  257            //                                    
#define mRI_258                  258            //                                    
#define mRI_259                  259            //                                    
#define mRI_260                  260            //                                    
#define mRI_261                  261            //                                    
#define mRI_262                  262            //                                    
#define mRI_263                  263            //                                    
#define mRI_264                  264            //                                    
#define mRI_265                  265            //                                    
#define mRI_266                  266            //                                    
#define mRI_267                  267            //                                    
#define mRI_268                  268            //                                    
#define mRI_269                  269            //                                    
#define mRI_270                  270            //                                    
#define mRI_271                  271            //                                    
#define mRI_272                  272            //                                    
#define mRI_273                  273            //                                    
#define mRI_274                  274            //                                    
#define mRI_275                  275            //                                    
#define mRI_276                  276            //                                    
#define mRI_277                  277            //                                    
#define mRI_278                  278            //                                    
#define mRI_279                  279            //                                    
#define mRI_280                  280            //                                    
#define mRI_281                  281            //                                    
#define mRI_282                  282            //                                    
#define mRI_283                  283            //                                    
#define mRI_284                  284            //                                    
#define mRI_285                  285            //                                    
#define mRI_286                  286            //                                    
#define mRI_287                  287            //                                    
#define mRI_288                  288            //                                    
#define mRI_289                  289            //                                    
#define mRI_290                  290            //                                    
#define mRI_291                  291            //                                    
#define mRI_292                  292            //                                    
#define mRI_293                  293            //                                    
#define mRI_294                  294            //                                    
#define mRI_295                  295            //                                    
#define mRI_296                  296            //                                    
#define mRI_297                  297            //                                    
#define mRI_298                  298            //                                    
#define mRI_299                  299            //                                    
#define mRI_300                  300            //                                    
#define mRI_301                  301            //                                    
#define mRI_302                  302            //                                    
#define mRI_303                  303            //                                    
#define mRI_304                  304            //                                    
#define mRI_305                  305            //                                    
#define mRI_306                  306            //                                    
#define mRI_307                  307            //                                    
#define mRI_308                  308            //                                    
#define mRI_309                  309            //                                    
#define mRI_310                  310            //                                    
#define mRI_311                  311            //                                    
#define mRI_312                  312            //                                    
#define mRI_313                  313            //                                    
#define mRI_314                  314            //                                    
#define mRI_315                  315            //                                    
#define mRI_316                  316            //                                    
#define mRI_317                  317            //                                    
#define mRI_318                  318            //                                    
#define mRI_319                  319            //                                    
#define mRI_320                  320            //                                    
#define mRI_321                  321            //                                    
#define mRI_322                  322            //                                    
#define mRI_323                  323            //                                    
#define mRI_324                  324            //                                    
#define mRI_325                  325            //                                    
#define mRI_326                  326            //                                    
#define mRI_327                  327            //                                    
#define mRI_328                  328            //                                    
#define mRI_329                  329            //                                    
#define mRI_330                  330            //                                    
#define mRI_331                  331            //                                    
#define mRI_332                  332            //                                    
#define mRI_333                  333            //                                    
#define mRI_334                  334            //                                    
#define mRI_335                  335            //                                    
#define mRI_336                  336            //                                    
#define mRI_337                  337            //                                    
#define mRI_338                  338            //                                    
#define mRI_339                  339            //                                    
#define mRI_340                  340            //                                    
#define mRI_341                  341            //                                    
#define mRI_342                  342            //                                    
#define mRI_343                  343            //                                    
#define mRI_344                  344            //                                    
#define mRI_345                  345            //                                    
#define mRI_346                  346            //                                    
#define mRI_347                  347            //                                    
#define mRI_348                  348            //                                    
#define mRI_349                  349            //                                    
#define mRI_350                  350            //                                    
#define mRI_351                  351            //                                    
#define mRI_352                  352            //                                    
#define mRI_353                  353            //                                    
#define mRI_354                  354            //                                    
#define mRI_355                  355            //                                    
#define mRI_356                  356            //                                    
#define mRI_357                  357            //                                    
#define mRI_358                  358            //                                    
#define mRI_359                  359            //                                    
#define mRI_360                  360            //                                    
#define mRI_361                  361            //                                    
#define mRI_362                  362            //                                    
#define mRI_363                  363            //                                    
#define mRI_364                  364            //                                    
#define mRI_365                  365            //                                    
#define mRI_366                  366            //                                    
#define mRI_367                  367            //                                    
#define mRI_368                  368            //                                    
#define mRI_369                  369            //                                    
#define mRI_370                  370            //                                    
#define mRI_371                  371            //                                    
#define mRI_372                  372            //                                    
#define mRI_373                  373            //                                    
#define mRI_374                  374            //                                    
#define mRI_375                  375            //                                    
#define mRI_376                  376            //                                    
#define mRI_377                  377            //                                    
#define mRI_378                  378            //                                    
#define mRI_379                  379            //                                    
#define mRI_380                  380            //                                    
#define mRI_381                  381            //                                    
#define mRI_382                  382            //                                    
#define mRI_383                  383            //                                    
#define mRI_384                  384            //                                    
#define mRI_385                  385            //                                    
#define mRI_386                  386            //                                    
#define mRI_387                  387            //                                    
#define mRI_388                  388            //                                    
#define mRI_389                  389            //                                    
#define mRI_390                  390            //                                    
#define mRI_391                  391            //                                    
#define mRI_392                  392            //                                    
#define mRI_393                  393            //                                    
#define mRI_394                  394            //                                    
#define mRI_395                  395            //                                    
#define mRI_396                  396            //                                    
#define mRI_397                  397            //                                    
#define mRI_398                  398            //                                    
#define mRI_399                  399            //                                    
#define mRI_400                  400            //                                    
#define mRI_401                  401            //                                    
#define mRI_402                  402            //                                    
#define mRI_403                  403            //                                    
#define mRI_404                  404            //                                    
#define mRI_405                  405            //                                    
#define mRI_406                  406            //                                    
#define mRI_407                  407            //                                    
#define mRI_408                  408            //                                    
#define mRI_409                  409            //                                    
#define mRI_410                  410            //                                    
#define mRI_411                  411            //                                    
#define mRI_412                  412            //                                    
#define mRI_413                  413            //                                    
#define mRI_414                  414            //                                    
#define mRI_415                  415            //                                    
#define mRI_416                  416            //                                    
#define mRI_417                  417            //                                    
#define mRI_418                  418            //                                    
#define mRI_419                  419            //                                    
#define mRI_420                  420            //                                    
#define mRI_421                  421            //                                    
#define mRI_422                  422            //                                    
#define mRI_423                  423            //                                    
#define mRI_424                  424            //                                    
#define mRI_425                  425            //                                    
#define mRI_426                  426            //                                    
#define mRI_427                  427            //                                    
#define mRI_428                  428            //                                    
#define mRI_429                  429            //                                    
#define mRI_430                  430            //                                    
#define mRI_431                  431            //                                    
#define mRI_432                  432            //                                    
#define mRI_433                  433            //                                    
#define mRI_434                  434            //                                    
#define mRI_435                  435            //                                    
#define mRI_436                  436            //                                    
#define mRI_437                  437            //                                    
#define mRI_438                  438            //                                    
#define mRI_439                  439            //                                    
#define mRI_440                  440            //                                    
#define mRI_441                  441            //                                    
#define mRI_442                  442            //                                    
#define mRI_443                  443            //                                    
#define mRI_444                  444            //                                    
#define mRI_445                  445            //                                    
#define mRI_446                  446            //                                    
#define mRI_447                  447            //                                    
#define mRI_448                  448            //                                    
#define mRI_449                  449            //                                    
#define mRI_450                  450            //                                    
#define mRI_451                  451            //                                    
#define mRI_452                  452            //                                    
#define mRI_453                  453            //                                    
#define mRI_454                  454            //                                    
#define mRI_455                  455            //                                    
#define mRI_456                  456            //                                    
#define mRI_457                  457            //                                    
#define mRI_458                  458            //                                    
#define mRI_459                  459            //                                    
#define mRI_460                  460            //                                    
#define mRI_461                  461            //                                    
#define mRI_462                  462            //                                    
#define mRI_463                  463            //                                    
#define mRI_464                  464            //                                    
#define mRI_465                  465            //                                    
#define mRI_466                  466            //                                    
#define mRI_467                  467            //                                    
#define mRI_468                  468            //                                    
#define mRI_469                  469            //                                    
#define mRI_470                  470            //                                    
#define mRI_471                  471            //                                    
#define mRI_472                  472            //                                    
#define mRI_473                  473            //                                    
#define mRI_474                  474            //                                    
#define mRI_475                  475            //                                    
#define mRI_476                  476            //                                    
#define mRI_477                  477            //                                    
#define mRI_478                  478            //                                    
#define mRI_479                  479            //                                    
#define mRI_480                  480            //                                    
#define mRI_481                  481            //                                    
#define mRI_482                  482            //                                    
#define mRI_483                  483            //                                    
#define mRI_484                  484            //                                    
#define mRI_485                  485            //                                    
#define mRI_486                  486            //                                    
#define mRI_487                  487            //                                    
#define mRI_488                  488            //                                    
#define mRI_489                  489            //                                    
#define mRI_490                  490            //                                    
#define mRI_491                  491            //                                    
#define mRI_492                  492            //                                    
#define mRI_493                  493            //                                    
#define mRI_494                  494            //                                    
#define mRI_495                  495            //                                    
#define mRI_496                  496            //                                    
#define mRI_497                  497            //                                    
#define mRI_498                  498            //                                    
#define mRI_499                  499            //                                    
#define mRI_500                  500            //                                    
#define mRI_501                  501            //                                    
#define mRI_502                  502            //                                    
#define mRI_503                  503            //                                    
#define mRI_504                  504            //                                    
#define mRI_505                  505            //                                    
#define mRI_506                  506            //                                    
#define mRI_507                  507            //                                    
#define mRI_508                  508            //                                    
#define mRI_509                  509            //                                    
#define mRI_510                  510            //                                    
#define mRI_EndSN                511            //                                    辅助用，禁止修改

#define mRO_StartSN              512            //                                    辅助用，禁止修改
#define mRO_Null                 513            //                                    辅助用，DO类型空资源，程序中禁止写入
#define mRO_514                  514            //                                    
#define mRO_515                  515            //                                    
#define mRO_MoldCls              516            //关模                                  
#define mRO_MoldOpen             517            //开模                                  
#define mRO_Inject               518            //注射                                  
#define mRO_Charge               519            //储料                                  
#define mRO_SuckBack             520            //射退                                  
#define mRO_EjeFor               521            //托模进                                 
#define mRO_EjeRet               522            //托模退                                 
#define mRO_NozFor               523            //座台进                                 
#define mRO_NozRet               524            //座台退                                 
#define mRO_MoldAdjThin          525            //调模进                                 
#define mRO_MoldAdjThick         526            //调模退                                 
#define mRO_527                  527            //机械手                                 
#define mRO_AutoGateSlow         528            //自动门慢速                               主要用于气动门
#define mRO_AutoGateOpen         529            //自动门开启                               自动门打开
#define mRO_AutoGateCls_Air      530            //自动门关闭                               主要用于气动门，当自动门关到位后，继续保持ON，以防门弹开
#define mRO_AutoGateCls          531            //自动门关闭                               主要用于电动门，当自动门到位后OFF，由电动门的抱闸等装置来防止门弹开
#define mRO_MoldClsDiff_MoldOpen 532            //差动                                  差动阀，开模全程也ON，主要用于MA-II和HTFX的120及以下机器油路
#define mRO_MoldClsDiff          533            //差动                                  
#define mRO_MoldClsDiff_CH       534            //差动                                  开模快速时ON，专用于CH机型
#define mRO_MoldClsLowPres       535            //关模低压                                关模低压时ON
#define mRO_MoldClsHighPres      536            //关模高压                                关模高压时ON，主要用于二板机
#define mRO_MoldClsFast          537            //关模快速                                关模快速时ON，主要用于2000t以上大机
#define mRO_MoldOpenFast         538            //开模快速                                开模快速时ON
#define mRO_MoldOpenLowPres      539            //开模低压                                开模一慢、二慢时ON
#define mRO_MoldOpenLowPres_F120 540            //开模低压                                开模一慢时ON，又用作差动，专用于F120X1机型
#define mRO_MoldOpenSlow         541            //开模慢速                                开模一慢时ON
#define mRO_MoldOpenSlow_CH      542            //开模慢速                                开模一慢、二慢时ON，又用作差动，专用于CH机型
#define mRO_MoldOpen_MoldClsDiff 543            //开模                                  开模阀、亦用作差动阀，主要用于大机(用开模阀作关模差动的机型)
#define mRO_MoldCls2             544            //关模始末                                同关模完全同步，主要是关模要驱动2个阀，故分出二个输出点
#define mRO_MoldOpenBackPres     545            //开模背压                                开模背压阀，关模时与差动同步，开模时不动作，主要用于MA-II和HTFX的120及以下机型
#define mRO_ChgRelPres           546            //储料卸压                                甬江机器：射退后执行储料卸压
#define mRO_InjChg               547            //注射+储料                               注射、保压、储料时动作，用于某些特殊的注射比例方向阀
#define mRO_InjSuckBack          548            //注射+射退                               注射、保压、射退时动作，用于某些特殊的注射比例方向阀
#define mRO_InjChgSuckBack       549            //注射+射退+储                             注射、保压、储料、射退时动作，用于某些特殊的注射比例方向阀
#define mRO_AirInj               550            //气辅注射                                
#define mRO_InjHighPres          551            //射出增压                                注射二时释放蓄能器能量
#define mRO_Acc                  552            //蓄能                                  给蓄能器补充能量
#define mRO_HydNozOff            553            //喷嘴关                                 
#define mRO_HydNozOn             554            //喷嘴开                                 
#define mRO_HoldPresRel          555            //保压泄压                                CH机型用
#define mRO_Lubr1                556            //润滑                                  
#define mRO_Lubr2                557            //润滑二                                 
#define mRO_Lubr3                558            //润滑三                                 
#define mRO_LubrMB2              559            //二板润滑                                
#define mRO_AlarmLgt_Grn         560            //绿色警灯                                
#define mRO_AlarmLgt_Red         561            //红色警灯                                
#define mRO_AlarmLgt_Ylw         562            //黄色警灯                                
#define mRO_AlarmLgt             563            //警灯                                  
#define mRO_AlarmBell            564            //警铃                                  
#define mRO_MotDrvEn             565            //使能                                  伺服机使用
#define mRO_MotorFan             566            //电机冷却                                伺服机使用
#define mRO_Inject2              567            //注射二                                 530以上机器油路要求，在注射、储料时该阀输出
#define mRO_InjHPRel             568            //注射保压解压                              注射保压时解压
#define mRO_ChgBackPres          569            //背压阀                                 零背压时使用
#define mRO_Link                 570            //联动阀                                 开模联动时使用
#define mRO_SDLink               571            //伺服联动转换                              伺服机联动时使用，避免冲击，开模时提前让驱动器切到联动模式
#define mRO_SDSmallFlow          572            //伺服小流量                               
#define mRO_InjectSign           573            //注射信号                                注射信号：射一～十，不包括保压，且只在标准注射动作时输出，即调模方式下注射等时不输出
#define mRO_HoldPresSign         574            //保压信号                                保压信号：保压一～十，不包括注射，且只在标准注射动作时输出，即调模方式下注射等时不输出
#define mRO_FlowFeedBackCtrl     575            //流量闭环                                流量反馈控制:主要用于伺服机，在部分需要流量闭环的动作一起输出，使驱动器流量闭环控制
#define mRO_PackCnt              576            //包装数到                                包装数到的时候，该信号有效（持续一模时间），提示用户进行包装
#define mRO_MotorOn              577            //马达开                                 
#define mRO_MotorYToA            578            //Y - A                               
#define mRO_MotorOff             579            //马达停                                 
#define mRO_MotDrvRst            580            //驱动器复位                               驱动器复位:驱动器警报时，按手动键，该信号输出0.2秒，以复位驱动器
#define mRO_InjectLogA           581            //注射逻辑A                               注射逻辑A、B组合应用：00-注射、01-保压、10-储料、11-射退，应用于高级注射比例阀，实现闭环控制
#define mRO_InjectLogB           582            //注射逻辑B                               注射逻辑A、B组合应用：00-注射、01-保压、10-储料、11-射退，应用于高级注射比例阀，实现闭环控制
#define mRO_MotDrvEn_Rst         583            //驱动器使能(R)                            宏讯伺服机专用，该使能信号在手动键消警报时会复位一下
#define mRO_J_NozRetEnd          584            //J.座退到底                              模具夹具用，座退到底时ON
#define mRO_Air1                 585            //A组吹气                                
#define mRO_Air2                 586            //B组吹气                                
#define mRO_Air3                 587            //C组吹气                                
#define mRO_Air4                 588            //D组吹气                                
#define mRO_Air5                 589            //E组吹气                                
#define mRO_Air6                 590            //F组吹气                                
#define mRO_591                  591            //                                    
#define mRO_592                  592            //                                    
#define mRO_593                  593            //                                    
#define mRO_594                  594            //                                    
#define mRO_CoreIn               595            //中子进                                 辅助用，以实现中子相关程序，不可实际定义与某硬件点
#define mRO_CoreOut              596            //中子退                                 辅助用，以实现中子相关程序，不可实际定义与某硬件点
#define mRO_Core01In             597            //中子A进                                
#define mRO_Core01Out            598            //中子A退                                
#define mRO_Core02In             599            //中子B进                                
#define mRO_Core02Out            600            //中子B退                                
#define mRO_Core03In             601            //中子C进                                
#define mRO_Core03Out            602            //中子C退                                
#define mRO_Core04In             603            //中子D进                                
#define mRO_Core04Out            604            //中子D退                                
#define mRO_Core05In             605            //中子E进                                
#define mRO_Core05Out            606            //中子E退                                
#define mRO_Core06In             607            //中子F进                                
#define mRO_Core06Out            608            //中子F退                                
#define mRO_Core07In             609            //中子G进                                
#define mRO_Core07Out            610            //中子G退                                
#define mRO_Core08In             611            //中子H进                                
#define mRO_Core08Out            612            //中子H退                                
#define mRO_Core09In             613            //中子I进                                
#define mRO_Core09Out            614            //中子I退                                
#define mRO_Core10In             615            //中子J进                                
#define mRO_Core10Out            616            //中子J退                                
#define mRO_Core11In             617            //中子K进                                
#define mRO_Core11Out            618            //中子K退                                
#define mRO_Core12In             619            //中子L进                                
#define mRO_Core12Out            620            //中子L退                                
#define mRO_AlarmLgt_SGUnCls     621            //黄色警灯                                黄色灯：安全门未关。特殊定义的三色灯。
#define mRO_AlarmLgt_Nor         622            //绿色警灯                                绿色灯：正常灯。特殊定义的三色灯。
#define mRO_AlarmLgt_Auto        623            //自动灯                                 三色灯，逻辑同"AlarmLgt_Grn--绿色警灯"，主要是显示文字不同
#define mRO_AlarmLgt_Manu        624            //手动灯                                 三色灯，逻辑同"AlarmLgt_Ylw--黄色警灯"，主要是显示文字不同
#define mRO_AlarmLgt_Alarm       625            //报警灯                                 三色灯，逻辑同"AlarmLgt_Red--红色警灯"，主要是显示文字不同
#define mRO_AlarmLgt_MoldOpen    626            //开模报警灯                               开模动作时输出,且ON-0.5s、OFF-0.5s）
#define mRO_Pump01               627            //泵一                                  
#define mRO_Pump02               628            //泵二                                  
#define mRO_Pump03               629            //泵三                                  
#define mRO_Pump04               630            //泵四                                  
#define mRO_Pump05               631            //泵五                                  
#define mRO_Pump06               632            //泵六                                  
#define mRO_Pump07               633            //泵七                                  
#define mRO_Pump08               634            //泵八                                  
#define mRO_Pump09               635            //泵九                                  
#define mRO_Pump10               636            //泵十                                  
#define mRO_Pump11               637            //泵十一                                 
#define mRO_Pump12               638            //泵十二                                 
#define mRO_Pump13               639            //泵十三                                 
#define mRO_Pump14               640            //泵十四                                 
#define mRO_Pump15               641            //泵十五                                 
#define mRO_Pump16               642            //泵十六                                 
#define mRO_MCHPPresRst          643            //锁模压力复位                              锁模压力复位
#define mRO_644                  644            //                                    
#define mRO_Vacuumize            645            //抽真空                                 抽真空
#define mRO_OilPreHtrVal         646            //油温预热阀                               油温预热时ON
#define mRO_OilCool              647            //油温冷却                                
#define mRO_Zone01Cool           648            //第一段冷却                               
#define mRO_Zone02Cool           649            //第二段冷却                               
#define mRO_Zone03Cool           650            //第三段冷却                               
#define mRO_Zone04Cool           651            //第四段冷却                               
#define mRO_Zone05Cool           652            //第五段冷却                               
#define mRO_Zone06Cool           653            //第六段冷却                               
#define mRO_Zone07Cool           654            //第七段冷却                               
#define mRO_Zone08Cool           655            //第八段冷却                               
#define mRO_Zone09Cool           656            //第九段冷却                               
#define mRO_Zone10Cool           657            //第十段冷却                               
#define mRO_Zone11Cool           658            //第十一段冷却                              
#define mRO_Zone12Cool           659            //第十二段冷却                              
#define mRO_Zone13Cool           660            //第十三段冷却                              
#define mRO_Zone14Cool           661            //第十四段冷却                              
#define mRO_Zone15Cool           662            //第十五段冷却                              
#define mRO_Zone16Cool           663            //第十六段冷却                              
#define mRO_664                  664            //                                    
#define mRO_665                  665            //                                    
#define mRO_666                  666            //                                    
#define mRO_HeaterOn             667            //电热开启                                
#define mRO_Heater01             668            //电热一                                 
#define mRO_Heater02             669            //电热二                                 
#define mRO_Heater03             670            //电热三                                 
#define mRO_Heater04             671            //电热四                                 
#define mRO_Heater05             672            //电热五                                 
#define mRO_Heater06             673            //电热六                                 
#define mRO_Heater07             674            //电热七                                 
#define mRO_Heater08             675            //电热八                                 
#define mRO_Heater09             676            //电热九                                 
#define mRO_Heater10             677            //电热十                                 
#define mRO_Heater11             678            //电热十一                                
#define mRO_Heater12             679            //电热十二                                
#define mRO_Heater13             680            //电热十三                                
#define mRO_Heater14             681            //电热十四                                
#define mRO_Heater15             682            //电热十五                                
#define mRO_Heater16             683            //电热十六                                
#define mRO_684                  684            //                                    
#define mRO_R_RobotMidRun        685            //机械手                                 简易机械手：在开模中途设定位置即输出，以驱动执行机械手
#define mRO_R_RobotRun           686            //机械手                                 简易机械手：1-开模动作结束，可以执行机械手
#define mRO_R_EmerStopOut        687            //R.紧急停止                              Euro 67/12、Start：0-系统紧急停止，包括通讯出错、紧停按下
#define mRO_R_SafeGate           688            //R.安全门关                              Euro 67/12、Start：1-所有安全门关着
#define mRO_R_AutoMode           689            //R.自动方式                              Euro 67/12
#define mRO_R_ClampEnd           690            //R.关模到位                              Euro 67/12、Start：1-模板到达关模终
#define mRO_R_MoldOpenEnd        691            //R.开模到位                              Euro 67/12、Start：1-模板到达开模终
#define mRO_R_MidMoldOpen        692            //R.开模中途位                             Euro 67/12：1-中途取件时，取件位置到
#define mRO_R_EjeForEnd          693            //R.托模进到位                             Euro 67/12、Start：1-顶针到达托模进终
#define mRO_R_EjeRetEnd          694            //R.托模退到位                             Euro 67/12：1-顶针到达托模退终
#define mRO_R_CoreInEnd          695            //R.中子进到位                             Euro 67/12：1-中子进到位
#define mRO_R_CoreOutEnd         696            //R.中子退到位                             Euro 67/12：1-中子退到位
#define mRO_R_Reject             697            //R.不良品                               Euro 67/12、Start：1-注塑过程异常
#define mRO_R_FullAutoMode       698            //R.全自动方式                             Start：1-时间自动、电眼自动（不包括半自动）
#define mRO_Lubr2Val             699            //润滑二阀                                润滑二阀
#define mRO_BypassRly            700            //旁路继电器                               CE土标要求,旁路继电器
#define mRO_OilSuppMotorPresRel  701            //自动门快速                               补油电机泄压  电预塑使用
#define mRO_ChgMotorOff          702            //特殊泵阀                                电预塑切断阀  电预塑使用
#define mRO_MotOnState           703            //                                    马达开启状态
#define mRO_HydrSafe             704            //液压安全                                液压安全
#define mRO_705                  705            //                                    
#define mRO_Core01_02Out         706            //中子A+B退                              实现中子A、B组合使用，应对某些特殊中子应用
#define mRO_Core01_02In          707            //中子A+B进                              实现中子A、B组合使用，应对某些特殊中子应用
#define mRO_Core01_03Out         708            //中子A+C退                              实现中子A、C组合使用，应对某些特殊中子应用
#define mRO_Core01_03In          709            //中子A+C进                              实现中子A、C组合使用，应对某些特殊中子应用
#define mRO_HotRunValve1         710            //热流道.阀01                             热流道:控制输出阀门1
#define mRO_HotRunValve2         711            //热流道.阀02                             热流道:控制输出阀门2
#define mRO_HotRunValve3         712            //热流道.阀03                             热流道:控制输出阀门3
#define mRO_HotRunValve4         713            //热流道.阀04                             热流道:控制输出阀门4
#define mRO_HotRunValve5         714            //热流道.阀05                             热流道:控制输出阀门5
#define mRO_HotRunValve6         715            //热流道.阀06                             热流道:控制输出阀门6
#define mRO_HotRunValve7         716            //热流道.阀07                             热流道:控制输出阀门7
#define mRO_HotRunValve8         717            //热流道.阀08                             热流道:控制输出阀门8
#define mRO_HotRunValve9         718            //热流道.阀09                             热流道:控制输出阀门9
#define mRO_HotRunValve10        719            //热流道.阀10                             热流道:控制输出阀门10
#define mRO_HotRunValve11        720            //热流道.阀11                             
#define mRO_HotRunValve12        721            //热流道.阀12                             
#define mRO_HotRunValve13        722            //热流道.阀13                             
#define mRO_HotRunValve14        723            //热流道.阀14                             
#define mRO_HotRunValve15        724            //热流道.阀15                             
#define mRO_HotRunValve16        725            //热流道.阀16                             
#define mRO_HotRunValve17        726            //热流道.阀17                             
#define mRO_HotRunValve18        727            //热流道.阀18                             
#define mRO_HotRunValve19        728            //热流道.阀19                             
#define mRO_HotRunValve20        729            //热流道.阀20                             
#define mRO_BMCFeedIn            730            //加料进                                 
#define mRO_BMCFeedOut           731            //加料退                                 
#define mRO_BMCCoverOpen         732            //压料盖开                                
#define mRO_BMCCoverCls          733            //压料盖关                                
#define mRO_MvPltOfMold          734            //二板滑脚                                
#define mRO_Steam_MoldClsDly     735            //S.合模延迟                              
#define mRO_Steam_InjectDly      736            //S.注射延迟                              
#define mRO_Steam_MoldOpnDly     737            //S.开模延迟                              
#define mRO_AutoMode             738            //自动模式                                
#define mRO_RelPres              739            //卸压阀                                 
#define mRO_MoldOpen2            740            //开模始末                                同开模完全同步，主要是开模要驱动2个阀，故分出二个输出点
#define mRO_AutoGatePWMSign      741            //自动门脉冲                               用于计算自动门开门距离。周期1s,ON时间：开门距离/开门总距离
#define mRO_AutoGateFast         742            //自动门快速                               自动门快速
#define mRO_SpcPump              743            //特殊泵阀                                特殊泵阀
#define mRO_744                  744            //                                    
#define mRO_745                  745            //                                    
#define mRO_Charge2              746            //储料2                                 双阶机用，二组储料
#define mRO_AutoGateOpenSlow_KEB 747            //自动门开慢速                              KEB门机的开门结束抱闸信号
#define mRO_FrtBrkIn             748            //头板闸板进                               用于抽拉杆功能
#define mRO_FrtBrkOut            749            //头板闸板退                               用于抽拉杆功能
#define mRO_ReBrkIn              750            //尾板闸板进                               用于抽拉杆功能
#define mRO_ReBrkOut             751            //尾板闸板退                               用于抽拉杆功能
#define mRO_TieBarFw             752            //拉杆进                                 用于抽拉杆功能
#define mRO_TieBarBw             753            //拉杆退                                 用于抽拉杆功能
#define mRO_MoldAdjLubr          754            //调模润滑                                应调模润滑功能
#define mRO_PrgOutput1           755            //                                    可编程自由输出点
#define mRO_PrgOutput2           756            //                                    可编程自由输出点
#define mRO_PrgOutput3           757            //                                    可编程自由输出点
#define mRO_PrgOutput4           758            //                                    可编程自由输出点
#define mRO_MoldClsOpen2         759            //开关模始末                               应HA机，逻辑基本为：关模始末+开模始末，但与开模始末略有区别
#define mRO_LinkMot              760            //独立电机                                注射-中子连动  该特殊中子选择使用且马达开时，该点有效
#define mRO_SemiAutoMode         761            //半自动模式                               半自动模式时输出
#define mRO_ChgBackPres2         762            //背压阀2                                与ChgBackPres背压阀逻辑相反
#define mRO_ChgBackPresCls       763            //零背压阀                                储料背压封闭阀
#define mRO_ValMot               764            //阀门电机                                阀电机
#define mRO_MoldOpenSlow_GS      765            //开模缓冲                                光塑：该点根据设置，可在一慢、二慢或二者都动作
#define mRO_SI_Inject            766            //                                    从射台注射启动
#define mRO_MoldOpenFast_KY      767            //开模快速                                开宇塑机:开模2-4段时ON，且受控生产参数“开模快速选择”
#define mRO_InjectFast_MN        768            //注射快速                                迈诺塑机：快速机油路，在注射过程与注射阀同步输出
#define mRO_Motor2Fan            769            //电机二冷却                               
#define mRO_Motor3Fan            770            //电机三冷却                               
#define mRO_HPVC_In              771            //                                    阀芯进
#define mRO_HPVC_Out             772            //                                    阀芯退
#define mRO_HoldPres_In          773            //                                    保压进
#define mRO_HoldPres_Out         774            //                                    保压退
#define mRO_InjectN              775            //注射N                                 注射的反逻辑,即注射有输出时此点不输出,否则此点输出
#define mRO_MoldOpenFast_RN      776            //开模快速                                锐能塑机：差动关闭,关模全程输出;差动开启,关模1-4-5段输出
#define mRO_HandSign_S           777            //应答信号(S)                             锐能：应答信号，马达启动后，按一定规律输出
#define mRO_MoldClsDiff_BX       778            //差动                                  博祥塑机：差动阀开、关由位置控制
#define mRO_EjeCoreSync          779            //同步托模                                同步托模：与托模进退、中子进退同步输出
#define mRO_MoldOpenClsLowPres   780            //开合模低压                               开合模低压：关模低压和开模1段输出
#define mRO_MoldOpenBrake        781            //开模刹车   	                            开模刹车
#define mRO_MoldOpenAuxil        782            //开模辅助   	                            开模辅助：开模1、2、3段输出
#define mRO_ColorMastMach        783            //色母机输出                               色母机输出
#define mRO_AlarmLgt_Buzzer      784            //蜂鸣                                  蜂鸣
#define mRO_MoldClsInj           785            //注射+关模                               关模、注射时动作
#define mRO_SprueOpen            786            //浇口开                                 浇口开
#define mRO_SprueCls             787            //浇口关                                 浇口关
#define mRO_InjIncrPres          788            //                                    射出增力
#define mRO_MoldClsDiff_YH       789            //差动                                  甬辉机械：开模时差动阀用时间控制,关模同标准差动
#define mRO_MoldOpenClsLowPres_LN 790           //开合模低压                               开合模低压：关模低压和开模1-3段输出
#define mRO_MoldClsDiff_LN       791            //差动                                  乐能机械：开模1段时差动阀用位置控制,关模同标准差动
#define mRO_MoldOpenAuxil_BJ     792            //开模辅助   	                            博劲开模辅助：开模同时输出，时间可调
#define mRO_MoldOpenClsAuxil     793            //开关模辅助                               开关模辅助：开模2、3、4段输出，关模1、2、3、高压段输出
#define mRO_MoldOpenFast_OT      794            //开模快速                                欧泰机械:受控生产参数“开模快速选择”开模全程开,一段不开,五段不开。
#define mRO_MoldOpenBrake_HX     795            //开模刹车   	                            宁波汇欣:开模刹车,开模缓冲（可选择一慢/二慢）+关模差动输出
#define mRO_MoldOpenClsLowPres_HX 796           //开合模低压                               宁波汇欣:开合模低压，开模缓冲（可选择一慢/二慢）+关模低压
#define mRO_MoldOpenClsMid       797            //开合模中位                               宁波汇欣:开合模中位,开模2.3.4段输出,5段输出可选,合模时1.2.3.5段输出
#define mRO_MoldClsDiff_MOFast   798            //差动                                  差动阀，开模快速也ON
#define mRO_ChgSuckBack          799            //储料+射退                               储料、射退时动作
#define mRO_ChgBackPres_HX       800            //背压阀                                 宁波汇欣:储料背压阀 背压设定0不输出，非0就输出
#define mRO_TotalPres            801            //总压阀                                 总压阀
#define mRO_MoldOpenClsFast      802            //快速阀                                 快速阀
#define mRO_MoldOpenBackPres_YT  803            //开模背压                                盈泰：根据Para_MoldOpenBPLog选择输出
#define mRO_SmallMotor           804            //小电机                                 科隆格:小电机
#define mRO_MoldOpen_YT          805            //开模                                  盈泰：根据Para_MoldOpenBPLog选择输出
#define mRO_806                  806            //                                    
#define mRO_807                  807            //                                    
#define mRO_808                  808            //                                    
#define mRO_809                  809            //                                    
#define mRO_810                  810            //                                    
#define mRO_811                  811            //                                    
#define mRO_812                  812            //                                    
#define mRO_813                  813            //                                    
#define mRO_814                  814            //                                    
#define mRO_815                  815            //                                    
#define mRO_816                  816            //                                    
#define mRO_817                  817            //                                    
#define mRO_818                  818            //                                    
#define mRO_819                  819            //                                    
#define mRO_820                  820            //                                    
#define mRO_821                  821            //                                    
#define mRO_822                  822            //                                    
#define mRO_823                  823            //                                    
#define mRO_824                  824            //                                    
#define mRO_825                  825            //                                    
#define mRO_826                  826            //                                    
#define mRO_827                  827            //                                    
#define mRO_828                  828            //                                    
#define mRO_829                  829            //                                    
#define mRO_830                  830            //                                    
#define mRO_831                  831            //                                    
#define mRO_832                  832            //                                    
#define mRO_833                  833            //                                    
#define mRO_834                  834            //                                    
#define mRO_835                  835            //                                    
#define mRO_836                  836            //                                    
#define mRO_837                  837            //                                    
#define mRO_838                  838            //                                    
#define mRO_839                  839            //                                    
#define mRO_840                  840            //                                    
#define mRO_841                  841            //                                    
#define mRO_842                  842            //                                    
#define mRO_843                  843            //                                    
#define mRO_844                  844            //                                    
#define mRO_845                  845            //                                    
#define mRO_846                  846            //                                    
#define mRO_847                  847            //                                    
#define mRO_848                  848            //                                    
#define mRO_849                  849            //                                    
#define mRO_SpcRelPresVal        850            //特殊泄压阀                               海天企业定义:特殊泄压阀，北化眼镜机专用，当独立中子液压泵时使用
#define mRO_851                  851            //                                    海天企业定义
#define mRO_852                  852            //                                    海天企业定义
#define mRO_853                  853            //                                    海天企业定义
#define mRO_854                  854            //                                    海天企业定义
#define mRO_855                  855            //                                    海天企业定义
#define mRO_856                  856            //                                    海天企业定义
#define mRO_857                  857            //                                    海天企业定义
#define mRO_858                  858            //                                    海天企业定义
#define mRO_859                  859            //                                    海天企业定义
#define mRO_860                  860            //                                    
#define mRO_861                  861            //                                    
#define mRO_862                  862            //                                    
#define mRO_863                  863            //                                    
#define mRO_864                  864            //                                    
#define mRO_865                  865            //                                    
#define mRO_866                  866            //                                    
#define mRO_867                  867            //                                    
#define mRO_868                  868            //                                    
#define mRO_869                  869            //                                    
#define mRO_870                  870            //                                    
#define mRO_871                  871            //                                    
#define mRO_872                  872            //                                    
#define mRO_873                  873            //                                    
#define mRO_874                  874            //                                    
#define mRO_875                  875            //                                    
#define mRO_876                  876            //                                    
#define mRO_877                  877            //                                    
#define mRO_878                  878            //                                    
#define mRO_879                  879            //                                    
#define mRO_880                  880            //                                    
#define mRO_881                  881            //                                    
#define mRO_882                  882            //                                    
#define mRO_883                  883            //                                    
#define mRO_884                  884            //                                    
#define mRO_885                  885            //                                    
#define mRO_886                  886            //                                    
#define mRO_887                  887            //                                    
#define mRO_888                  888            //                                    
#define mRO_889                  889            //                                    
#define mRO_890                  890            //                                    
#define mRO_891                  891            //                                    
#define mRO_892                  892            //                                    
#define mRO_893                  893            //                                    
#define mRO_894                  894            //                                    
#define mRO_895                  895            //                                    
#define mRO_896                  896            //                                    
#define mRO_897                  897            //                                    
#define mRO_898                  898            //                                    
#define mRO_899                  899            //                                    
#define mRO_900                  900            //                                    
#define mRO_901                  901            //                                    
#define mRO_902                  902            //                                    
#define mRO_903                  903            //                                    
#define mRO_904                  904            //                                    
#define mRO_905                  905            //                                    
#define mRO_906                  906            //                                    
#define mRO_907                  907            //                                    
#define mRO_908                  908            //                                    
#define mRO_909                  909            //                                    
#define mRO_910                  910            //                                    
#define mRO_911                  911            //                                    
#define mRO_912                  912            //                                    
#define mRO_913                  913            //                                    
#define mRO_914                  914            //                                    
#define mRO_915                  915            //                                    
#define mRO_916                  916            //                                    
#define mRO_917                  917            //                                    
#define mRO_918                  918            //                                    
#define mRO_919                  919            //                                    
#define mRO_920                  920            //                                    
#define mRO_921                  921            //                                    
#define mRO_922                  922            //                                    
#define mRO_923                  923            //                                    
#define mRO_924                  924            //                                    
#define mRO_925                  925            //                                    
#define mRO_926                  926            //                                    
#define mRO_927                  927            //                                    
#define mRO_928                  928            //                                    
#define mRO_929                  929            //                                    
#define mRO_930                  930            //                                    
#define mRO_931                  931            //                                    
#define mRO_932                  932            //                                    
#define mRO_933                  933            //                                    
#define mRO_934                  934            //                                    
#define mRO_935                  935            //                                    
#define mRO_936                  936            //                                    
#define mRO_937                  937            //                                    
#define mRO_938                  938            //                                    
#define mRO_939                  939            //                                    
#define mRO_940                  940            //                                    
#define mRO_941                  941            //                                    
#define mRO_942                  942            //                                    
#define mRO_943                  943            //                                    
#define mRO_944                  944            //                                    
#define mRO_945                  945            //                                    
#define mRO_946                  946            //                                    
#define mRO_947                  947            //                                    
#define mRO_948                  948            //                                    
#define mRO_949                  949            //                                    
#define mRO_950                  950            //                                    
#define mRO_951                  951            //                                    
#define mRO_952                  952            //                                    
#define mRO_953                  953            //                                    
#define mRO_954                  954            //                                    
#define mRO_955                  955            //                                    
#define mRO_956                  956            //                                    
#define mRO_957                  957            //                                    
#define mRO_958                  958            //                                    
#define mRO_959                  959            //                                    
#define mRO_960                  960            //                                    
#define mRO_961                  961            //                                    
#define mRO_962                  962            //                                    
#define mRO_963                  963            //                                    
#define mRO_964                  964            //                                    
#define mRO_965                  965            //                                    
#define mRO_966                  966            //                                    
#define mRO_967                  967            //                                    
#define mRO_968                  968            //                                    
#define mRO_969                  969            //                                    
#define mRO_970                  970            //                                    
#define mRO_971                  971            //                                    
#define mRO_972                  972            //                                    
#define mRO_973                  973            //                                    
#define mRO_974                  974            //                                    
#define mRO_975                  975            //                                    
#define mRO_976                  976            //                                    
#define mRO_977                  977            //                                    
#define mRO_978                  978            //                                    
#define mRO_979                  979            //                                    
#define mRO_980                  980            //                                    
#define mRO_981                  981            //                                    
#define mRO_982                  982            //                                    
#define mRO_983                  983            //                                    
#define mRO_984                  984            //                                    
#define mRO_985                  985            //                                    
#define mRO_986                  986            //                                    
#define mRO_987                  987            //                                    
#define mRO_988                  988            //                                    
#define mRO_989                  989            //                                    
#define mRO_990                  990            //                                    
#define mRO_991                  991            //                                    
#define mRO_992                  992            //                                    
#define mRO_993                  993            //                                    
#define mRO_994                  994            //                                    
#define mRO_995                  995            //                                    
#define mRO_996                  996            //                                    
#define mRO_997                  997            //                                    
#define mRO_998                  998            //                                    
#define mRO_999                  999            //                                    
#define mRO_1000                 1000           //                                    
#define mRO_1001                 1001           //                                    
#define mRO_1002                 1002           //                                    
#define mRO_1003                 1003           //                                    
#define mRO_1004                 1004           //                                    
#define mRO_1005                 1005           //                                    
#define mRO_1006                 1006           //                                    
#define mRO_1007                 1007           //                                    
#define mRO_1008                 1008           //                                    
#define mRO_1009                 1009           //                                    
#define mRO_1010                 1010           //                                    
#define mRO_1011                 1011           //                                    
#define mRO_1012                 1012           //                                    
#define mRO_1013                 1013           //                                    
#define mRO_1014                 1014           //                                    
#define mRO_1015                 1015           //                                    
#define mRO_1016                 1016           //                                    
#define mRO_1017                 1017           //                                    
#define mRO_1018                 1018           //                                    
#define mRO_1019                 1019           //                                    
#define mRO_1020                 1020           //                                    
#define mRO_1021                 1021           //                                    
#define mRO_1022                 1022           //                                    
#define mRO_EndSN                1023           //                                    辅助用，禁止修改

#define mRU_StartSN              1024           //                                    辅助用，禁止修改
#define mRU_InNull               1025           //                                    辅助用，U32类型输入空资源，程序中可写入但禁止引用
#define mRU_OutNull              1026           //                                    辅助用，DO类型输入空资源，程序中禁止写入
#define mRU_1027                 1027           //                                    
#define mRU_1028                 1028           //                                    
#define mRU_1029                 1029           //                                    
#define mRU_1030                 1030           //                                    
#define mRU_1031                 1031           //                                    
#define mRU_1032                 1032           //                                    
#define mRU_1033                 1033           //                                    
#define mRU_1034                 1034           //                                    
#define mRU_1035                 1035           //                                    
#define mRU_1036                 1036           //                                    
#define mRU_1037                 1037           //                                    
#define mRU_1038                 1038           //                                    
#define mRU_1039                 1039           //                                    
#define mRU_1040                 1040           //                                    
#define mRU_1041                 1041           //                                    
#define mRU_1042                 1042           //                                    
#define mRU_1043                 1043           //                                    
#define mRU_1044                 1044           //                                    
#define mRU_1045                 1045           //                                    
#define mRU_MoldSnrAD            1046           //                                    16位AD值，0x0ffff对应最大值
#define mRU_ScrewSnrAD           1047           //                                    16位AD值，0x0ffff对应最大值
#define mRU_EjeSnrAD             1048           //                                    16位AD值，0x0ffff对应最大值
#define mRU_NozSnrAD             1049           //                                    16位AD值，0x0ffff对应最大值
#define mRU_HAI1AD               1050           //                                    16位AD值，0x0ffff对应最大值
#define mRU_HAI2AD               1051           //                                    16位AD值，0x0ffff对应最大值
#define mRU_HAI3AD               1052           //                                    16位AD值，0x0ffff对应最大值
#define mRU_MoldThickSnrAD       1053           //                                    16位AD值，0x0ffff对应最大值
#define mRU_HoldPresSnrAD        1054           //                                    16位AD值，0x0ffff对应最大值
#define mRU_ScrewSnrBAD          1055           //                                    16位AD值，0x0ffff对应最大值
#define mRU_EjeSnrBAD            1056           //                                    16位AD值，0x0ffff对应最大值
#define mRU_1057                 1057           //                                    
#define mRU_1058                 1058           //                                    
#define mRU_1059                 1059           //                                    
#define mRU_1060                 1060           //                                    
#define mRU_1061                 1061           //                                    
#define mRU_PVMainPres           1062           //主压力                                 其中mBit31为极性位，放大100倍
#define mRU_PVMainFlow           1063           //主流量                                 其中mBit31为极性位，放大100倍
#define mRU_PVBackPres           1064           //背压                                  其中mBit31为极性位，放大100倍
#define mRU_PVMoldOpenClsFlow    1065           //开合模                                 其中mBit31为极性位，放大100倍
#define mRU_PVInjSuckFlow        1066           //注射流量                                其中mBit31为极性位，放大100倍
#define mRU_PVLinkPres           1067           //连动压力                                其中mBit31为极性位，放大100倍
#define mRU_PVLinkFlow           1068           //连动流量                                其中mBit31为极性位，放大100倍
#define mRU_PVSDLinkPres         1069           //伺连压力                                其中mBit31为极性位，放大100倍
#define mRU_PVSDLinkFlow         1070           //伺连流量                                其中mBit31为极性位，放大100倍
#define mRU_PVSetPID             1071           //J5-PID                              J5机利用该模拟量实现多组PID，方法为不同电压代表不同的PID
#define mRU_PVInjSuckPres        1072           //注射压力                                其中mBit31为极性位，放大100倍，在标准程序中暂未使用
#define mRU_PVPres2              1073           //压力二                                 其中mBit31为极性位，放大100倍
#define mRU_PVFlow2              1074           //流量二                                 其中mBit31为极性位，放大100倍
#define mRU_PVRelief             1075           //溢流                                  其中mBit31为极性位，放大100倍，暂主要用于特殊双节机
#define mRU_ChgMotor             1076           //                                    电储料
#define mRU_1077                 1077           //                                    
#define mRU_1078                 1078           //                                    
#define mRU_1079                 1079           //                                    
#define mRU_1080                 1080           //                                    
#define mRU_1081                 1081           //                                    
#define mRU_ScrewRPM             1082           //                                    单位转每分钟                              
#define mRU_ScrewRPMCnt          1083           //                                    单位1clk，计数器值
#define mRU_MoldAdjSnrCnt        1084           //                                    单位1clk，计数器值
#define mRU_ScrewRPMCnt2         1085           //                                    单位1clk，计数器值
#define mRU_ChgGearTemp          1086           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Motor3Temp           1087           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_1088                 1088           //                                    
#define mRU_Motor2Temp           1089           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_OilTemp              1090           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_MotorTemp            1091           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone01Temp           1092           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone02Temp           1093           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone03Temp           1094           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone04Temp           1095           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone05Temp           1096           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone06Temp           1097           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone07Temp           1098           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone08Temp           1099           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone09Temp           1100           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone10Temp           1101           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone11Temp           1102           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone12Temp           1103           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone13Temp           1104           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone14Temp           1105           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone15Temp           1106           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_Zone16Temp           1107           //                                    单位0.001c，777777-断电、888888-超温、999999-断偶
#define mRU_1108                 1108           //                                    
#define mRU_1109                 1109           //                                    
#define mRU_1110                 1110           //                                    
#define mRU_1111                 1111           //                                    
#define mRU_1112                 1112           //                                    
#define mRU_1113                 1113           //                                    
#define mRU_1114                 1114           //                                    
#define mRU_1115                 1115           //                                    
#define mRU_1116                 1116           //                                    
#define mRU_1117                 1117           //                                    
#define mRU_1118                 1118           //                                    
#define mRU_1119                 1119           //                                    
#define mRU_1120                 1120           //                                    
#define mRU_1121                 1121           //                                    
#define mRU_1122                 1122           //                                    
#define mRU_1123                 1123           //                                    
#define mRU_1124                 1124           //                                    
#define mRU_1125                 1125           //                                    
#define mRU_1126                 1126           //                                    
#define mRU_1127                 1127           //                                    
#define mRU_1128                 1128           //                                    
#define mRU_1129                 1129           //                                    
#define mRU_1130                 1130           //                                    
#define mRU_1131                 1131           //                                    
#define mRU_1132                 1132           //                                    
#define mRU_1133                 1133           //                                    
#define mRU_1134                 1134           //                                    
#define mRU_1135                 1135           //                                    
#define mRU_1136                 1136           //                                    
#define mRU_1137                 1137           //                                    
#define mRU_1138                 1138           //                                    
#define mRU_1139                 1139           //                                    
#define mRU_1140                 1140           //                                    
#define mRU_1141                 1141           //                                    
#define mRU_1142                 1142           //                                    
#define mRU_1143                 1143           //                                    
#define mRU_1144                 1144           //                                    
#define mRU_1145                 1145           //                                    
#define mRU_1146                 1146           //                                    
#define mRU_1147                 1147           //                                    
#define mRU_1148                 1148           //                                    
#define mRU_1149                 1149           //                                    
#define mRU_1150                 1150           //                                    
#define mRU_1151                 1151           //                                    
#define mRU_1152                 1152           //                                    
#define mRU_1153                 1153           //                                    
#define mRU_1154                 1154           //                                    
#define mRU_1155                 1155           //                                    
#define mRU_1156                 1156           //                                    
#define mRU_1157                 1157           //                                    
#define mRU_1158                 1158           //                                    
#define mRU_1159                 1159           //                                    
#define mRU_1160                 1160           //                                    
#define mRU_1161                 1161           //                                    
#define mRU_1162                 1162           //                                    
#define mRU_1163                 1163           //                                    
#define mRU_1164                 1164           //                                    
#define mRU_1165                 1165           //                                    
#define mRU_1166                 1166           //                                    
#define mRU_1167                 1167           //                                    
#define mRU_1168                 1168           //                                    
#define mRU_1169                 1169           //                                    
#define mRU_1170                 1170           //                                    
#define mRU_1171                 1171           //                                    
#define mRU_1172                 1172           //                                    
#define mRU_1173                 1173           //                                    
#define mRU_1174                 1174           //                                    
#define mRU_1175                 1175           //                                    
#define mRU_1176                 1176           //                                    
#define mRU_1177                 1177           //                                    
#define mRU_1178                 1178           //                                    
#define mRU_1179                 1179           //                                    
#define mRU_1180                 1180           //                                    
#define mRU_1181                 1181           //                                    
#define mRU_1182                 1182           //                                    
#define mRU_1183                 1183           //                                    
#define mRU_1184                 1184           //                                    
#define mRU_1185                 1185           //                                    
#define mRU_1186                 1186           //                                    
#define mRU_1187                 1187           //                                    
#define mRU_1188                 1188           //                                    
#define mRU_1189                 1189           //                                    
#define mRU_1190                 1190           //                                    
#define mRU_1191                 1191           //                                    
#define mRU_1192                 1192           //                                    
#define mRU_1193                 1193           //                                    
#define mRU_1194                 1194           //                                    
#define mRU_1195                 1195           //                                    
#define mRU_1196                 1196           //                                    
#define mRU_1197                 1197           //                                    
#define mRU_1198                 1198           //                                    
#define mRU_1199                 1199           //                                    
#define mRU_1200                 1200           //                                    
#define mRU_1201                 1201           //                                    
#define mRU_1202                 1202           //                                    
#define mRU_1203                 1203           //                                    
#define mRU_1204                 1204           //                                    
#define mRU_1205                 1205           //                                    
#define mRU_1206                 1206           //                                    
#define mRU_1207                 1207           //                                    
#define mRU_1208                 1208           //                                    
#define mRU_1209                 1209           //                                    
#define mRU_1210                 1210           //                                    
#define mRU_1211                 1211           //                                    
#define mRU_1212                 1212           //                                    
#define mRU_1213                 1213           //                                    
#define mRU_1214                 1214           //                                    
#define mRU_1215                 1215           //                                    
#define mRU_1216                 1216           //                                    
#define mRU_1217                 1217           //                                    
#define mRU_1218                 1218           //                                    
#define mRU_1219                 1219           //                                    
#define mRU_1220                 1220           //                                    
#define mRU_1221                 1221           //                                    
#define mRU_1222                 1222           //                                    
#define mRU_1223                 1223           //                                    
#define mRU_1224                 1224           //                                    
#define mRU_1225                 1225           //                                    
#define mRU_1226                 1226           //                                    
#define mRU_1227                 1227           //                                    
#define mRU_1228                 1228           //                                    
#define mRU_1229                 1229           //                                    
#define mRU_1230                 1230           //                                    
#define mRU_1231                 1231           //                                    
#define mRU_1232                 1232           //                                    
#define mRU_1233                 1233           //                                    
#define mRU_1234                 1234           //                                    
#define mRU_1235                 1235           //                                    
#define mRU_1236                 1236           //                                    
#define mRU_1237                 1237           //                                    
#define mRU_1238                 1238           //                                    
#define mRU_1239                 1239           //                                    
#define mRU_1240                 1240           //                                    
#define mRU_1241                 1241           //                                    
#define mRU_1242                 1242           //                                    
#define mRU_1243                 1243           //                                    
#define mRU_1244                 1244           //                                    
#define mRU_1245                 1245           //                                    
#define mRU_1246                 1246           //                                    
#define mRU_1247                 1247           //                                    
#define mRU_1248                 1248           //                                    
#define mRU_1249                 1249           //                                    
#define mRU_1250                 1250           //                                    
#define mRU_1251                 1251           //                                    
#define mRU_1252                 1252           //                                    
#define mRU_1253                 1253           //                                    
#define mRU_1254                 1254           //                                    
#define mRU_1255                 1255           //                                    
#define mRU_1256                 1256           //                                    
#define mRU_1257                 1257           //                                    
#define mRU_1258                 1258           //                                    
#define mRU_1259                 1259           //                                    
#define mRU_1260                 1260           //                                    
#define mRU_1261                 1261           //                                    
#define mRU_1262                 1262           //                                    
#define mRU_1263                 1263           //                                    
#define mRU_1264                 1264           //                                    
#define mRU_1265                 1265           //                                    
#define mRU_1266                 1266           //                                    
#define mRU_1267                 1267           //                                    
#define mRU_1268                 1268           //                                    
#define mRU_1269                 1269           //                                    
#define mRU_1270                 1270           //                                    
#define mRU_1271                 1271           //                                    
#define mRU_1272                 1272           //                                    
#define mRU_1273                 1273           //                                    
#define mRU_1274                 1274           //                                    
#define mRU_1275                 1275           //                                    
#define mRU_1276                 1276           //                                    
#define mRU_1277                 1277           //                                    
#define mRU_1278                 1278           //                                    
#define mRU_EndSN                1279           //                                    辅助用，禁止修改

#endif
