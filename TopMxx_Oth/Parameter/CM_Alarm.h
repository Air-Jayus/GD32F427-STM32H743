/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_Alarm.h    警报定义文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0x391D  
****************************************************************************************************/
#ifndef CM_Alarm_h
    #define CM_Alarm_h

#ifdef RPHA_c
    #define CM_Alarm_ext
#else
    #define CM_Alarm_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//警报属性定义
#define mAA_Beep        mBit0   //发声提示
#define mAA_Save        mBit1   //记录保存
#define mAA_PulseDisp   mBit2   //脉冲显示
#define mAA_DlyDispSave mBit3   //延时显示和保存
#define mAA_DisScrewAct mBit4   //禁止螺杆动作
#define mAA_DisMoldAct  mBit5   //禁止开合模动作
#define mAA_DisAllAct   mBit6   //禁止所有动作
#define mAA_Light       mBit7   //警灯
#define mAA_HtrOff      mBit8   //关电热
#define mAA_MotOff      mBit9   //关马达
#define mAA_FreeToManu  mBitA   //闲转手动
#define mAA_ImmToManu   mBitB   //立转手动
#define mAA_AMIntOut    mBitC   //自动模式综合输出
#define mAA_ACAlarm     mBitD   //任清警报
#define mAA_MCAlarm     mBitE   //手动警报
#define mAA_Prompt      mBitF   //提示信息

//警报数量
#define mAlarmNum 512  //警报数量

//警报数组定义及初始化
#ifndef RPHA_c
    extern const U16 AlarmAttr[mAlarmNum];    //警报属性数组定义
#else
    const U16 AlarmAttr[mAlarmNum]={          //警报属性数组定义
        0,35595,32771,32775,32775,32775,32775,32775,32773,32775,32775,32775,32775,32775,32775,32771,32771,32775,32775,32771,16386,16386,32769,32769,32769,8192,32768,32771,32770,8323,15171,15171,15171,22594,22594,22595,22595,22595,22595,21571,21571,32771,32771,23242,23242,22730,22730,23234,22722,14786,15042,15042,12738,12482,12482,12482,12482,12482,12482,12482,8322,8258,32786,32786,
        8258,8195,8195,32768,32768,32768,32768,32768,32896,12482,12482,12482,12482,12482,12482,14530,12482,12482,8194,8322,12482,14530,12482,12354,12482,12482,12482,12482,12482,12482,12482,12482,12482,13506,13506,13506,13506,13506,13506,13506,13506,13506,13506,32768,13506,8321,13506,13506,12482,12482,8322,8192,8195,32768,20642,20642,12482,32898,22722,12482,32768,12482,32768,12482,
        12482,12482,12482,32898,12482,12866,12482,10306,12610,10243,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,8322,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,12482,32768,32768,32768,32768,32768,32768,32768,
        32768,32768,32768,12482,32768,12482,22722,12482,12482,13506,8322,12482,32768,13506,32770,32770,12482,12482,14530,12482,14530,32898,22722,22722,22722,22722,22722,22722,22722,22722,14530,14530,14530,14530,14530,14530,14530,14530,0,0,12482,12482,0,0,21954,32770,32770,32770,32770,32896,32770,12482,12482,12482,12482,12482,12482,12482,34850,12482,12482,32768,8322,22722,
        22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22722,22530,32770,20675,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32770,32770,0,0,22210,0,0,0,14530,22722,23234,32770,32770,12482,14530,12482,12482,14530,32773,32771,32768,17408,17408,32768,17408,32768,12482,12482,13506,13506,8194,12434,12482,32771,
        22722,10434,10434,10434,10434,14530,12482,32770,12482,22674,32768,0,14482,0,0,14530,8194,8194,8194,8194,8194,8194,22722,22722,8194,0,0,0,0,0,0,0,0,0,0,0,32899,0,0,0,0,0,0,0,0,0,13442,32770,32770,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif

//警报序号宏定义
#define mAlarm_NoAlarm           0              //                                    无警报
#define mAlarm_CommLink          1              //101正在通讯联机...                        界面、主机共用
#define mAlarm_SoftLinkCodeErr   2              //102程序互连代码不匹配                        界面：主机、界面程序不匹配
#define mAlarm_ParaLoadErr       3              //103参数读取出错                           界面：EEPROM读取生产、系统参数出错
#define mAlarm_ParaSaveErr       4              //104参数保存出错                           界面：EEPROM保存生产、系统参数出错
#define mAlarm_ParaLimErr        5              //105参数超出限值                           界面：EEPROM存取生产、系统参数超限
#define mAlarm_MoldDataLoadErr   6              //106模具资料读取出错                         界面：AT45DB读取模具资料出错
#define mAlarm_MoldDataSaveErr   7              //107模具资料保存出错                         界面：AT45DB保存模具资料出错
#define mAlarm_PasswordErr       8              //108密码输入错误                           界面：输入密码错误
#define mAlarm_MoldDataNoLoadErr 9              //109模具资料不存在,失败                       界面：读取时发现模具号不存在
#define mAlarm_MoldDataNoSaveErr 10             //110模具资料已存在,失败                       界面：保存时发现模具号已经存在
#define mAlarm_MoldDataNoDel     11             //111当前模具号不能删除                        界面：删除时发现删的为当前模具
#define mAlarm_USBFileLoadErr    12             //112USB文件读取出错                        
#define mAlarm_USBFileSaveErr    13             //113USB文件保存出错                        
#define mAlarm_PlsSwitchManuMode 14             //114请在手动模式下操作                        
#define mAlarm_HtrTimeOn         15             //115电热定时开启                           
#define mAlarm_PowerUp           16             //116机器加电开启                           界面：机器加电开启时保存到警报记录，以记录开机时间
#define mAlarm_TempBuffTooSmall  17             //117缓冲区偏小(一般>10)                     温度缓冲区设置值在1-5度时提示
#define mAlarm_FileChkCodeErr    18             //118文件校验码出错,失败                       界面：文件校验码出错，失败。主要用于MCH建置文件导入时校验码异常
#define mAlarm_HtrAutoOnAftPwrOn 19             //119电热延时自动开启                         界面：电热开机后经延时自动开启
#define mAlarm_CMBootModeAppErr  20             //120主机Boot模式程序无效                     主机BOOT用，如果更改序号，注意BOOT程序一起改
#define mAlarm_CMBootModeWaitCode 21            //121主机Boot模式等待指令                     主机BOOT用，如果更改序号，注意BOOT程序一起改
#define mAlarm_ENetLicenseErr    22             //122网络授权码无效                          
#define mAlarm_ENetLicenseExpire 23             //123网络授权码过期                          
#define mAlarm_ProgUpdate        24             //124服务器上程序已更新                        
#define mAlarm_CMLicenseInvalid  25             //125主机程序未授权                          主机程序未经授权，注意须任清属性
#define mAlarm_WMLicenseInvalid  26             //126界面程序未授权                          界面：面板程序未经授权
#define mAlarm_ENetLicenseInvalid 27            //127网络功能未授权                          界面：网络功能未经授权
#define mAlarm_BoxCanErr         28             //128BOX通讯异常                          CAN与BOX通讯出错
#define mAlarm_ProdTaskFin       29             //129生产任务达成                           主要针对管工厂：完成产品生产
#define mAlarm_SoftParaLinkCodeErr 30           //200程序和参数不匹配                         
#define mAlarm_PlatLinkCodeErr   31             //201平台和硬件配置不匹配                       硬件配置(HardConf)与主机平台不匹配
#define mAlarm_IICMemoryErr      32             //202IIC存储器异常                         FM24CLxx出错
#define mAlarm_FlowLevelOL       33             //203流程嵌套溢出                           Flow调度中，动作嵌套级数太多
#define mAlarm_MachParaUnRst     34             //204主程升级后参数未重置                       主机程序升级后，机器参数未重置
#define mAlarm_HardConfReadErr   35             //205硬件配置读取出错                         
#define mAlarm_HardConfSaveErr   36             //206硬件配置保存出错                         
#define mAlarm_MachParaReadErr   37             //207机器参数读取出错                         
#define mAlarm_MachParaSaveErr   38             //208机器参数保存出错                         
#define mAlarm_CntDataReadErr    39             //209计数数据读取出错                         
#define mAlarm_CntDataSaveErr    40             //210计数数据保存出错                         
#define mAlarm_KeyErr            41             //211按键异常                             按键持续按下超过60秒，则报该警
#define mAlarm_LowBattery        42             //212请更换电池并校准时间                       锂电池电量不足，提示更换电池
#define mAlarm_DIDOPwrErr        43             //213H24V阀电源异常                        
#define mAlarm_DIDOPwrOLProt     44             //214H24V阀电源过载保护                      
#define mAlarm_PosPwrErr         45             //215电子尺电源异常                          
#define mAlarm_PosMdlErr         46             //216电子尺模块异常                          
#define mAlarm_PropValCurrOL     47             //217比例阀电流超限                          
#define mAlarm_MoldCylPosTabErr  48             //218曲臂转换表异常                          非连续重复触发
#define mAlarm_ZoneTempOL        49             //219料筒温度超过最高值                        
#define mAlarm_OilTempOL         50             //220油温超过最高值                          
#define mAlarm_MotTempOL         51             //221电机温度超过最高值                        
#define mAlarm_ZoneTempErr       52             //222料筒温度异常                           断电或断偶
#define mAlarm_OilTempErr        53             //223油温异常                             断电或断偶，闲转手动、切马达属性程序中加
#define mAlarm_MotTempErr        54             //224电机温度异常                           断电或断偶，闲转手动、切马达属性程序中加
#define mAlarm_HeaterErr         55             //225电热加温异常                           3分钟温升检查失败
#define mAlarm_ZoneTempWarp      56             //226料筒温度偏差                           
#define mAlarm_ZoneTempCoolProt  57             //227料筒防冷启保护                          
#define mAlarm_OilTempWarp       58             //228油温偏差                             闲转手动、切马达属性程序中加
#define mAlarm_MotTempWarp       59             //229电机温度偏差                           闲转手动、切马达属性程序中加
#define mAlarm_OilTempLow        60             //230油温偏低                             
#define mAlarm_PlsOnMotor        61             //231请先开马达                            
#define mAlarm_HtrKeepWarm       62             //232正在保温中...                         提示属性，以避开紧急停止按下警报
#define mAlarm_HtrAutoKeepWarm   63             //233按手动键退出保温                         提示属性，以避开紧急停止按下警报
#define mAlarm_OilHtr            64             //234按手动键退出油温预热                       任清属性即可
#define mAlarm_PlsOffMotor       65             //235请在手动状态且马达关                       
#define mAlarm_PlsOffHeater      66             //236请先关闭电热                           
#define mAlarm_PlsClsSafeGate    67             //237请关安全门                            提示信息，不应选禁XX属性，否则异常
#define mAlarm_PlsOpenSafeGate   68             //238请开安全门                            提示信息，不应选禁XX属性，否则异常
#define mAlarm_PlsClsBackSafeGate 69            //239请关后安全门                           提示信息，不应选禁XX属性，否则异常
#define mAlarm_PlsClsTopSafeGate 70             //240请关顶盖                             提示信息，不应选禁XX属性，否则异常
#define mAlarm_PlsClsButSafeGate 71             //241请关底板                             提示信息，不应选禁XX属性，否则异常
#define mAlarm_PlsClsNozSafeGate 72             //242请关注射防护罩                          
#define mAlarm_SafeGateUnCls     73             //243安全门未关                            
#define mAlarm_BackSafeGateUnCls 74             //244后安全门未关                           
#define mAlarm_TopSafeGateUnCls  75             //245顶盖未关                             
#define mAlarm_ButSafeGateUnCls  76             //246底板未关                             
#define mAlarm_OpenClsSafeGateOT 77             //247开关安全门超时                          
#define mAlarm_EjeRetUnEnd       78             //248顶针未退到位                           
#define mAlarm_ServoDrvTempOL    79             //249电机驱动器超温                          
#define mAlarm_MoldOpenUnEnd     80             //250开模未到位                            
#define mAlarm_NozSafeGateUnCls  81             //251注射防护罩未关                          
#define mAlarm_ChargeEnd         82             //252储料完成                             
#define mAlarm_PurgeEnd          83             //253清料完成                             
#define mAlarm_HopperUnEnd       84             //254料斗未到位                            
#define mAlarm_ServoDrvErr       85             //255电机驱动器异常                          
#define mAlarm_ProdDropErr       86             //256落料电眼检出失败                         
#define mAlarm_ReEjeFor          87             //257正在再次托模                           
#define mAlarm_AccOT             88             //258蓄能器蓄能超时                          
#define mAlarm_TieRodsLoadErr    89             //259拉杆受力异常                           拉杆受力异常
#define mAlarm_CycTiOL           90             //260全程超时                             
#define mAlarm_MoldClsTiOL       91             //261关模超时                             
#define mAlarm_MoldClsLPTiOL     92             //262关模低压超时                           
#define mAlarm_MoldClsHPTiOL     93             //263关模高压超时                           
#define mAlarm_MoldOpenTiOL      94             //264开模超时                             
#define mAlarm_MoldOpenEPosOL    95             //265开模终位置超差                          
#define mAlarm_EjectTiOL         96             //266托模超时                             
#define mAlarm_InjectTiOL        97             //267射出时间超差                           
#define mAlarm_InjectEPosOL      98             //268射出监控失败                           注射（含保压）结束位置偏差
#define mAlarm_InjectMaxSpdOL    99             //269射出最高速超差                          
#define mAlarm_HoldPresTiOL      100            //270保压时间超差                           注射转保压前的时间偏差
#define mAlarm_HoldPresSPosOL    101            //271转保压位置超差                          
#define mAlarm_HoldPresSPresOL   102            //272转保压压力超差                          
#define mAlarm_ChargeTiOL        103            //273储料超时                             
#define mAlarm_ChargeEPosOL      104            //274储料终位置超差                          
#define mAlarm_ChargeRPMOL       105            //275储料转速超差                           
#define mAlarm_SuckBackTiOL      106            //276射退超时                             
#define mAlarm_EjeRetUnEndPrompt 107            //277顶针未退到位                           与“EjeRetUnEnd”警报不同，为提示用，主要在关模时执行托退，提示一下
#define mAlarm_ShotCntOL         108            //278产品生产模数到                          
#define mAlarm_PackCntOL         109            //279产品装模数到                           
#define mAlarm_LubrErr           110            //280润滑失败                             
#define mAlarm_LubrOilLess       111            //281润滑油不足                            闲转手动、切马达属性程序中加
#define mAlarm_FilterSenErr      112            //282滤油网阻塞                            闲转手动、切马达属性程序中加
#define mAlarm_OilLess           113            //283油位偏低                             闲转手动、切马达属性程序中加
#define mAlarm_EmerButtonPush    114            //284紧急停止被按下                          
#define mAlarm_JustPurge         115            //285正在清料中...                         
#define mAlarm_PlsPushEmerButt   116            //286请按下紧停按钮                          转Boot模式时
#define mAlarm_WaitMachProt      117            //287等待机械保险到位                         
#define mAlarm_MachProtErr       118            //288机械保险失败                           手清、禁止开合模
#define mAlarm_HydProtErr        119            //289液压保险失败                           手清、禁止开合模，GB22530中还会改属性
#define mAlarm_AirSrcPresErr     120            //290气源压力异常                           
#define mAlarm_SafeRlyUnRst      121            //291安全异常,重开安全门                       GB22530中还会改属性
#define mAlarm_NozGateLoopErr    122            //292注射防护安全回路异常                       手清、立转手动
#define mAlarm_HandShankErr      123            //293安全门手柄装置异常                        
#define mAlarm_PlsOptHandShank   124            //294请操作安全门手柄                         
#define mAlarm_ToggleProt        125            //295曲肘区域防护                           
#define mAlarm_PlsPushCycStartKey 126           //296请按循环启动键                          
#define mAlarm_MoldThinEnd       127            //297调模进到终                            
#define mAlarm_MoldThickEnd      128            //298调模退到终                            
#define mAlarm_MoldOverSize      129            //299模具太大                             
#define mAlarm_MoldLessSize      130            //300模具太小                             
#define mAlarm_AutoMoldAdjOK     131            //301自动调模完成                           
#define mAlarm_MoldAdjSnrErr     132            //302调模电眼无反应                          
#define mAlarm_MotFreeOff        133            //303空闲自动关闭马达                         
#define mAlarm_PresNozLimitSwitch 134           //304射台限位开关压合                         射台限位开关压合
#define mAlarm_CycStopKeyPush    135            //305循环停止键被按下                         自动运行时，循环停止键按下，立转手动
#define mAlarm_HtrFreeOff        136            //306空闲自动关闭电热                         
#define mAlarm_DebugAutoStop     137            //307强制输出时间到结束                        强制输出时间到结束，利用立转手动属性实现结束调试模式
#define mAlarm_J5_PID_CAN_Err    138            //308J5卡CAN通讯出错                       J5卡CAN通讯出错（主要是多组PID时）
#define mAlarm_PropValErr        139            //309比例阀故障                            某些高组比例阀故障指示，如注射比例阀、MOOG比例阀
#define mAlarm_Core1UnInEnd      140            //310中子A未进到位                          
#define mAlarm_Core1UnOutEnd     141            //311中子A未退到位                          
#define mAlarm_Core1PosOL        142            //312中子A动作位置偏差                        
#define mAlarm_Core1Err          143            //313中子A异常                            限位器异常、中子被弹出等
#define mAlarm_Core2UnInEnd      144            //314中子B未进到位                          
#define mAlarm_Core2UnOutEnd     145            //315中子B未退到位                          
#define mAlarm_Core2PosOL        146            //316中子B动作位置偏差                        
#define mAlarm_Core2Err          147            //317中子B异常                            
#define mAlarm_Core3UnInEnd      148            //318中子C未进到位                          
#define mAlarm_Core3UnOutEnd     149            //319中子C未退到位                          
#define mAlarm_Core3PosOL        150            //320中子C动作位置偏差                        
#define mAlarm_Core3Err          151            //321中子C异常                            
#define mAlarm_Core4UnInEnd      152            //322中子D未进到位                          
#define mAlarm_Core4UnOutEnd     153            //323中子D未退到位                          
#define mAlarm_Core4PosOL        154            //324中子D动作位置偏差                        
#define mAlarm_Core4Err          155            //325中子D异常                            
#define mAlarm_Core5UnInEnd      156            //326中子E未进到位                          
#define mAlarm_Core5UnOutEnd     157            //327中子E未退到位                          
#define mAlarm_Core5PosOL        158            //328中子E动作位置偏差                        
#define mAlarm_Core5Err          159            //329中子E异常                            
#define mAlarm_Core6UnInEnd      160            //330中子F未进到位                          
#define mAlarm_Core6UnOutEnd     161            //331中子F未退到位                          
#define mAlarm_Core6PosOL        162            //332中子F动作位置偏差                        
#define mAlarm_Core6Err          163            //333中子F异常                            
#define mAlarm_Core7UnInEnd      164            //334中子G未进到位                          
#define mAlarm_Core7UnOutEnd     165            //335中子G未退到位                          
#define mAlarm_Core7PosOL        166            //336中子G动作位置偏差                        
#define mAlarm_Core7Err          167            //337中子G异常                            
#define mAlarm_Core8UnInEnd      168            //338中子H未进到位                          
#define mAlarm_Core8UnOutEnd     169            //339中子H未退到位                          
#define mAlarm_Core8PosOL        170            //340中子H动作位置偏差                        
#define mAlarm_Core8Err          171            //341中子H异常                            
#define mAlarm_SafeGateSnrErr    172            //342安全门检知异常                          用于自动安全门，自动安全门关时发现“安全门检知”信号ON，避免安全门夹到异物
#define mAlarm_R_EmerStop        173            //343R.机械手紧急停止                        
#define mAlarm_R_RobotOT         174            //344R.机械手超时                          
#define mAlarm_R_MoldAreaFreeErr 175            //345R.模区安全信号异常                       
#define mAlarm_R_EnClampErr      176            //346R.关模允许信号异常                       
#define mAlarm_R_EnFullMoldOpenErr 177          //347R.全开模允许信号异常                      
#define mAlarm_R_EnEjeForErr     178            //348R.托模进允许信号异常                      
#define mAlarm_R_EnEjeRetErr     179            //349R.托模退允许信号异常                      
#define mAlarm_R_EnCoreInErr     180            //350R.中子进允许信号异常                      
#define mAlarm_R_EnCoreOutErr    181            //351R.中子退允许信号异常                      
#define mAlarm_R_EnMoldOpenErr   182            //352R.开模允许信号异常                       
#define mAlarm_R_CycStartErr     183            //353R.循环启动信号异常                       
#define mAlarm_R_RobotUnEnd      184            //354机械手未退到位                          
#define mAlarm_R_MoldAreaFreeWait 185           //355R.等待模区安全                         
#define mAlarm_R_EnClampWait     186            //356R.等待允许关模                         
#define mAlarm_R_EnFullMoldOpenWait 187         //357R.等待允许完全开模                       
#define mAlarm_R_EnEjeForWait    188            //358R.等待允许托模进                        
#define mAlarm_R_EnEjeRetWait    189            //359R.等待允许托模退                        
#define mAlarm_R_EnCoreInWait    190            //360R.等待允许中子进                        
#define mAlarm_R_EnCoreOutWait   191            //361R.等待允许中子退                        
#define mAlarm_R_EnMoldOpenWait  192            //362R.等待允许开模                         
#define mAlarm_R_CycStartWait    193            //363R.等待循环启动                         
#define mAlarm_R_RobotEndWait    194            //364等待机械手退回到位                        
#define mAlarm_PilotOilAccErr    195            //365先导油储能器储能失败                       注射、合模插装阀油路机器（通常装配于1600T以上大机），先导油蓄能器储能超时
#define mAlarm_J_JigWait         196            //366等待模具夹具信号                         
#define mAlarm_J_JigSignErr      197            //367模具夹具信号异常                         
#define mAlarm_PilotOilAccPresLow 198           //368先导油储能器压力低                        注射、合模插装阀油路机器（通常装配于1600T以上大机），先导油蓄能器压力不足
#define mAlarm_BMCCoverErr       199            //369BMC压料盖异常                         
#define mAlarm_BMCFeedInEnd      200            //370BMC加料进终                          
#define mAlarm_BMCNoMaterial     201            //371BMC缺料                            
#define mAlarm_SafePlateFail     202            //372安全踏板踩下                           
#define mAlarm_SteamErr          203            //373蒸汽设备异常                           
#define mAlarm_WatiSteamSignal   204            //374等待蒸汽设备信号                         
#define mAlarm_InjPresPeakOL     205            //375注射峰值压力超差                         
#define mAlarm_AtRelPress        206            //376正在卸压...                          
#define mAlarm_AtMoldThickAdj    207            //377正在自动调整模厚...                      
#define mAlarm_EjeForUnEnd       208            //378顶针未进到位                           
#define mAlarm_AutoGateErr       209            //379自动门门机异常                          
#define mAlarm_MotPhaOrFanErr    210            //380电机相位或风扇异常                        "PC-电机异常"时输出该警报，表示电机相位或风扇异常
#define mAlarm_EndSafeGateunCls  211            //381尾板小门未关                           天剑快速机程序专用，标准机不使用
#define mAlarm_RobotUnAct        212            //382机械手未动作                           机械手使用时，一个循环中应检出“机械手回到位”信号有变化，否则该警报
#define mAlarm_CanBusErr         213            //383CAN总线通讯异常                        
#define mAlarm_CanMod1AddrErr    214            //384模块1地址冲突                          
#define mAlarm_CanMod2AddrErr    215            //385模块2地址冲突                          
#define mAlarm_CanMod3AddrErr    216            //386模块3地址冲突                          
#define mAlarm_CanMod4AddrErr    217            //387模块4地址冲突                          
#define mAlarm_CanMod5AddrErr    218            //388模块5地址冲突                          
#define mAlarm_CanMod6AddrErr    219            //389模块6地址冲突                          
#define mAlarm_CanMod7AddrErr    220            //390模块7地址冲突                          
#define mAlarm_CanMod8AddrErr    221            //391模块8地址冲突                          
#define mAlarm_CanMod1CommErr    222            //392模块1通讯异常                          
#define mAlarm_CanMod2CommErr    223            //393模块2通讯异常                          
#define mAlarm_CanMod3CommErr    224            //394模块3通讯异常                          
#define mAlarm_CanMod4CommErr    225            //395模块4通讯异常                          
#define mAlarm_CanMod5CommErr    226            //396模块5通讯异常                          
#define mAlarm_CanMod6CommErr    227            //397模块6通讯异常                          
#define mAlarm_CanMod7CommErr    228            //398模块7通讯异常                          
#define mAlarm_CanMod8CommErr    229            //399模块8通讯异常                          
#define mAlarm_230               230            //400拉杆拉力超限                           
#define mAlarm_231               231            //401拉杆间拉力超差                          
#define mAlarm_Mot2TempErr       232            //402电机二温度异常                          
#define mAlarm_Mot2TempWarp      233            //403电机二温度偏差                          
#define mAlarm_234               234            //404配电箱温度过高                          
#define mAlarm_235               235            //405配电箱温度异常                          
#define mAlarm_ZoneTempDevOL     236            //406超过料温允许上限                         
#define mAlarm_ZonePIDTuning     237            //407温度整定中,手动键返                       
#define mAlarm_ZonePIDTunSucc    238            //408温度整定成功                           
#define mAlarm_ZonePIDFail1      239            //409整定失败:段温差太大                       
#define mAlarm_ZonePIDFail2      240            //410整定失败:目标温度低                       
#define mAlarm_PumpLowLevel      241            //411泵站液位不足                           当"mRI_PumpLevel泵站液位"信号有效时输出
#define mAlarm_PlsClsGateToEnd   242            //412齿数丢失,请关门到底                       
#define mAlarm_MoldOpenLessMinStroke 243        //413开模未到行程下限以上                       应抽拉杆功能加
#define mAlarm_NozBackUnEnd      244            //414座台未退到位                           应抽拉杆功能加能
#define mAlarm_MoldThickErr      245            //415模厚异常                             应抽拉杆功能加
#define mAlarm_BrkOutUnEnd       246            //416闸板未退终                            应抽拉杆功能加
#define mAlarm_TieBarInUnEnd     247            //417拉杆未进终                            应抽拉杆功能加
#define mAlarm_BrkInUnEnd        248            //418闸板未进终                            应抽拉杆功能加
#define mAlarm_SafeValFeedErr    249            //419安全阀反馈异常                          应抽拉杆功能加
#define mAlarm_AtTieBar          250            //420正在抽插拉杆......                     应抽拉杆功能加
#define mAlarm_MoldAdjLubrErr    251            //421调模润滑失败                           
#define mAlarm_FixBackSafeGateUnCls 252         //422固定门未关                            
#define mAlarm_PlsClsFixBackSafeGate 253        //423请关固定门                            提示信息，不应选禁XX属性，否则异常
#define mAlarm_SafePlugErr       254            //424安全插头未插入                          
#define mAlarm_SDError           255            //425SD.驱动器警报                         
#define mAlarm_SDCanErr          256            //426SD.驱动器CAN通讯异常                    
#define mAlarm_SDErrorCode1      257            //427SD.逆变单元保护                        
#define mAlarm_SDErrorCode2      258            //428SD.加速过电流                         
#define mAlarm_SDErrorCode3      259            //429SD.减速过电路                         
#define mAlarm_SDErrorCode4      260            //430SD.恒速过电流                         
#define mAlarm_SDErrorCode5      261            //431SD.加速过电压                         
#define mAlarm_SDErrorCode6      262            //432SD.减速过电压                         
#define mAlarm_SDErrorCode7      263            //433SD.恒速过电压                         
#define mAlarm_SDErrorCode8      264            //434SD.未命名故障                         
#define mAlarm_SDErrorCode9      265            //435SD.欠压故障                          
#define mAlarm_SDErrorCode10     266            //436SD.变频器过载                         
#define mAlarm_SDErrorCode11     267            //437SD.电机过载                          
#define mAlarm_SDErrorCode12     268            //438SD.输入缺相                          
#define mAlarm_SDErrorCode13     269            //439SD.输出缺相                          
#define mAlarm_SDErrorCode14     270            //440SD.散热器过热                         
#define mAlarm_SDErrorCode15     271            //441SD.外部故障                          
#define mAlarm_SDErrorCode16     272            //442SD.485通讯超时                       
#define mAlarm_SDErrorCode17     273            //443SD.接触器故障                         
#define mAlarm_SDErrorCode18     274            //444SD.电流检测故障                        
#define mAlarm_SDErrorCode19     275            //445SD.电机调谐故障                        
#define mAlarm_SDErrorCode20     276            //446SD.未命名故障                         
#define mAlarm_SDErrorCode21     277            //447SD.EEPORM读写故障                    
#define mAlarm_SDErrorCode22     278            //448SD.未命名故障                         
#define mAlarm_SDErrorCode23     279            //449SD.电机对地短路故障                      
#define mAlarm_SDErrorCode24     280            //450SD.未命名故障                         
#define mAlarm_SDErrorCode25     281            //451SD.未命名故障                         
#define mAlarm_SDErrorCode26     282            //452SD.定时运行时间到达                      
#define mAlarm_SDErrorCode27     283            //453SD.未命名故障                         
#define mAlarm_SDErrorCode28     284            //454SD.未命名故障                         
#define mAlarm_SDErrorCode29     285            //455SD.未命名故障                         
#define mAlarm_SDErrorCode30     286            //456SD.未命名故障                         
#define mAlarm_SDErrorCode31     287            //457SD.未命名故障                         
#define mAlarm_SDErrorCode32     288            //458SD.未命名故障                         
#define mAlarm_SDErrorCode33     289            //459SD.未命名故障                         
#define mAlarm_SDErrorCode34     290            //460SD.未命名故障                         
#define mAlarm_SDErrorCode35     291            //461SD.未命名故障                         
#define mAlarm_SDErrorCode36     292            //462SD.未命名故障                         
#define mAlarm_SDErrorCode37     293            //463SD.未命名故障                         
#define mAlarm_SDErrorCode38     294            //464SD.未命名故障                         
#define mAlarm_SDErrorCode39     295            //465SD.未命名故障                         
#define mAlarm_SDErrorCode40     296            //466SD.未命名故障                         
#define mAlarm_SDErrorCode41     297            //467SD.未命名故障                         
#define mAlarm_SDErrorCode42     298            //468SD.CAN通讯故障                       
#define mAlarm_SDErrorCode43     299            //469SD.未命名故障                         
#define mAlarm_SDErrorCode44     300            //470SD.速度偏差保护故障                      
#define mAlarm_SDErrorCode45     301            //471SD.电机温度故障                        
#define mAlarm_SDErrorCode46     302            //472SD.压力传感器故障                       
#define mAlarm_SDErrorCode47     303            //473SD.多泵控制从机故障                      
#define mAlarm_SDErrorCode48     304            //474SD.CAN地址冲突故障                     
#define mAlarm_SDErrorCode49     305            //475SD.旋变PG断线故障                      
#define mAlarm_MO_RetPosOver     306            //476模板反弹超限                           在算法开模时，反弹量过大则报警并停机，防止机械手碰上模具
#define mAlarm_MO_ParaGenlFail   307            //477开模参数自学习失败                        开模参数自学习失败
#define mAlarm_SpcSafeGateModeErr 308           //478特殊安全门模式异常                        土耳其安全标准中使用，特殊安全门模式异常
#define mAlarm_309               309            //479模厚异常                             
#define mAlarm_310               310            //480锁模力异常                            
#define mAlarm_311               311            //481调谐失败须重新自学习                       
#define mAlarm_312               312            //482机械手防撞                            
#define mAlarm_313               313            //483转台模板碰撞预警                         
#define mAlarm_314               314            //484转台防撞设定未用                         
#define mAlarm_315               315            //485转台零位丢失                           
#define mAlarm_316               316            //486转台伺服报警                           
#define mAlarm_317               317            //487转台归零完成                           
#define mAlarm_318               318            //488转台尺归零完成                          
#define mAlarm_319               319            //489转台电眼同时有效                         
#define mAlarm_320               320            //490转台动作超时                           
#define mAlarm_321               321            //491转台未转到位                           
#define mAlarm_322               322            //492转台尺结束位置超限                        
#define mAlarm_323               323            //493转台未进终                            
#define mAlarm_324               324            //494转台未退终                            
#define mAlarm_325               325            //495开模终位置超限                          
#define mAlarm_326               326            //496电注射卡CAN通讯超时                      
#define mAlarm_327               327            //497电注射卡执行动作失败                       
#define mAlarm_328               328            //498电注射卡压力超范围                        
#define mAlarm_329               329            //499电注射伺服驱动器报警                       
#define mAlarm_330               330            //500M4停止工作                           
#define mAlarm_331               331            //501M0停止工作                           
#define mAlarm_332               332            //502iPQ数据版本错误                        
#define mAlarm_333               333            //503iPQ_HADC内部温度出错                   
#define mAlarm_334               334            //504iPQ_主电源故障                        
#define mAlarm_335               335            //505iPQ_IO源故障                        
#define mAlarm_336               336            //506iPQ_压力超范围                        
#define mAlarm_337               337            //507iPQ_动作执行失败                       
#define mAlarm_338               338            //508iPQ_动作段数超限                       
#define mAlarm_339               339            //509iPQ_注射超时                         
#define mAlarm_340               340            //520iPQ_储料超时                         序号：340－359，供海天以外企业定义使用
#define mAlarm_341               341            //521iPQ_指令错误                         
#define mAlarm_342               342            //522iPQ_通讯超时                         
#define mAlarm_343               343            //523任务控制器错误                          
#define mAlarm_344               344            //524任务控制器警告                          
#define mAlarm_345               345            //525运动控制器错误                          
#define mAlarm_346               346            //526运动控制器警告                          
#define mAlarm_347               347            //527PLC控制器错误                         
#define mAlarm_348               348            //528PLC控制器警告                         
#define mAlarm_349               349            //529PLC控制器应用警告                       
#define mAlarm_MotorOn           350            //510马达开启                             警报记录中使用，记录马达开启时间
#define mAlarm_MotorOff          351            //511马达关闭                             警报记录中使用，记录马达关闭时间
#define mAlarm_352               352            //512机械手485通讯故障                       
#define mAlarm_353               353            //513机械手模号未同步                         
#define mAlarm_HandSignErr       354            //514应答信号异常                           
#define mAlarm_355               355            //515电动门保护                            
#define mAlarm_356               356            //516油压安全阀异常                          
#define mAlarm_357               357            //517马达启动失败                           
#define mAlarm_MotorUnOn         358            //518马达未启动                            
#define mAlarm_MotorOverloadErr  359            //519马达过载                             序号：340－359，供海天以外企业定义使用
#define mAlarm_ExtAlarm          360            //560外部警报                             
#define mAlarm_FilterSen0Err     361            //521滤油网检测#0失败                        
#define mAlarm_EncounterNetAttack 362           //600网络异常(疑似攻击)                       遭遇网络攻击
#define mAlarm_MoldSlidBolck     363            //                                    
#define mAlarm_ChgServoDrvErr    364            //                                    
#define mAlarm_Mot3TempErr       365            //                                    
#define mAlarm_Mot3TempWarp      366            //                                    
#define mAlarm_ChgGearTempOL     367            //                                    
#define mAlarm_DataLocked        368            //130资料锁已锁定                           资料锁已锁定
#define mAlarm_CMUpgradeAppErr   369            //                                    主机平台和升级程序不匹配
#define mAlarm_SI_EnMoldOpenWait 370            //                                    等待从射台开模允许
#define mAlarm_HotRunrOverRang   371            //                                    XX段热流道超量程
#define mAlarm_HotRunrTempErr    372            //                                    XX段热流道断偶
#define mAlarm_HotRunrTempWamp   373            //                                    XX段热流道温度偏差
#define mAlarm_HotRunrHotFail    374            //                                    XX段热流道加热失败
#define mAlarm_HotRunrCommFail   375            //                                    XX号热流道通信失败
#define mAlarm_HPVC_UnInEnd      376            //                                    保压阀芯未进终
#define mAlarm_HPVC_UnOutEnd     377            //                                    保压阀芯未退终
#define mAlarm_Lubr1RelPresFail  378            //577润滑一压力未泄                          润滑一压力未泄
#define mAlarm_Lubr2RelPresFail  379            //578润滑二压力未泄                          润滑二压力未泄
#define mAlarm_ChgMotorCoolValUnCls 380         //                                    电储料冷却水阀未关
#define mAlarm_ChgMotorGearErr   381            //                                    储料齿轮箱异常
#define mAlarm_BMCFeedBreak      382            //542加料爬梯信号中断                         加料爬梯信号中断
#define mAlarm_CMSoftlocking     383            //550主机锁定                             主机软件锁定，用于分期锁定主机报警
#define mAlarm_PowerMonErr       384            //总电源异常                               总电源异常
#define mAlarm_ProdSnr1Fail      385            //1号产品托模失败    		                      1号产品脱模失败
#define mAlarm_ProdSnr2Fail      386            //2号产品托模失败    		                      2号产品脱模失败
#define mAlarm_ProdSnr3Fail      387            //3号产品托模失败    		                      3号产品脱模失败
#define mAlarm_ProdSnr4Fail      388            //4号产品托模失败    		                      4号产品脱模失败
#define mAlarm_RobComErr         389            //570机械手通讯错误                          机械手通讯错误
#define mAlarm_MoldNotRst        390            //652模具未复位                            模具未复位
#define mAlarm_ShutdownPlsMO     391            //651关机前,请开模                          关机前，请开模
#define mAlarm_MoldProtectErr    392            //                                    模具保护异常
#define mAlarm_SmallMotSnrErr    393            //                                    小电机检测异常
#define mAlarm_PlsRestart        394            //132请重新开机                            请重启
#define mAlarm_395               395            //                                    
#define mAlarm_HeaterUnOn        396            //653电热未启动                            电热未启动
#define mAlarm_397               397            //                                    
#define mAlarm_398               398            //                                    
#define mAlarm_EcatCommFail      399            //551ETHERCAT通讯错误                     EtherCat通讯错误
#define mAlarm_ZeroSeekSucc      400            //552寻零成功                             寻零成功
#define mAlarm_ZeroSeekFail      401            //553寻零失败                             寻零失败
#define mAlarm_ZeroSeekWait      402            //554寻零中请稍等...                        寻零中，请稍等...
#define mAlarm_AutoAdjSucc       403            //555自学习成功                            自学习成功
#define mAlarm_AutoAdjFail       404            //556自学习失败                            自学习失败
#define mAlarm_AutoAdjWait       405            //557自学习中请稍等...                       自学习中，请稍等...
#define mAlarm_J6hMotionErr      406            //558     J6卡Error                    XXXXJ6卡Error
#define mAlarm_J6hDrvErr         407            //559   驱动器警报                         XX驱动器警报
#define mAlarm_AutoAdjEnd        408            //549自学习完成      	                     自学习完成
#define mAlarm_409               409            //                                    
#define mAlarm_410               410            //                                    
#define mAlarm_411               411            //                                    
#define mAlarm_412               412            //                                    
#define mAlarm_413               413            //                                    
#define mAlarm_414               414            //                                    
#define mAlarm_415               415            //                                    
#define mAlarm_416               416            //                                    
#define mAlarm_417               417            //                                    
#define mAlarm_418               418            //                                    
#define mAlarm_419               419            //                                    
#define mAlarm_NozLeakageRiskWarn 420           //585喷嘴漏料风险提示                         喷嘴漏料风险提示
#define mAlarm_421               421            //                                    
#define mAlarm_422               422            //                                    
#define mAlarm_423               423            //                                    
#define mAlarm_424               424            //                                    
#define mAlarm_425               425            //                                    
#define mAlarm_426               426            //                                    
#define mAlarm_427               427            //                                    
#define mAlarm_428               428            //                                    
#define mAlarm_429               429            //                                    
#define mAlarm_MCHPPresOL        430            //648锁模压力超差                           锁模压力超差
#define mAlarm_MCHPPresHoldMoldThin 431         //649锁模力保持调模进                         锁模力保持调模进
#define mAlarm_MCHPPresHoldMoldThick 432        //650锁模力保持调模退                         锁模力保持调模退
#define mAlarm_433               433            //                                    
#define mAlarm_434               434            //                                    
#define mAlarm_435               435            //                                    
#define mAlarm_436               436            //                                    
#define mAlarm_437               437            //                                    
#define mAlarm_438               438            //                                    
#define mAlarm_439               439            //                                    
#define mAlarm_440               440            //                                    
#define mAlarm_441               441            //                                    
#define mAlarm_442               442            //                                    
#define mAlarm_443               443            //                                    
#define mAlarm_444               444            //                                    
#define mAlarm_445               445            //                                    
#define mAlarm_446               446            //                                    
#define mAlarm_447               447            //                                    
#define mAlarm_448               448            //                                    
#define mAlarm_449               449            //                                    
#define mAlarm_450               450            //                                    
#define mAlarm_451               451            //                                    
#define mAlarm_452               452            //                                    
#define mAlarm_453               453            //                                    
#define mAlarm_454               454            //                                    
#define mAlarm_455               455            //                                    
#define mAlarm_456               456            //                                    
#define mAlarm_457               457            //                                    
#define mAlarm_458               458            //                                    
#define mAlarm_459               459            //                                    
#define mAlarm_460               460            //                                    
#define mAlarm_461               461            //                                    
#define mAlarm_462               462            //                                    
#define mAlarm_463               463            //                                    
#define mAlarm_464               464            //                                    
#define mAlarm_465               465            //                                    
#define mAlarm_466               466            //                                    
#define mAlarm_467               467            //                                    
#define mAlarm_468               468            //                                    
#define mAlarm_469               469            //                                    
#define mAlarm_470               470            //                                    
#define mAlarm_471               471            //                                    
#define mAlarm_472               472            //                                    
#define mAlarm_473               473            //                                    
#define mAlarm_474               474            //                                    
#define mAlarm_475               475            //                                    
#define mAlarm_476               476            //                                    
#define mAlarm_477               477            //                                    
#define mAlarm_478               478            //                                    
#define mAlarm_479               479            //                                    
#define mAlarm_480               480            //                                    
#define mAlarm_481               481            //                                    
#define mAlarm_482               482            //                                    
#define mAlarm_483               483            //                                    
#define mAlarm_484               484            //                                    
#define mAlarm_485               485            //                                    
#define mAlarm_486               486            //                                    
#define mAlarm_487               487            //                                    
#define mAlarm_488               488            //                                    
#define mAlarm_489               489            //                                    
#define mAlarm_490               490            //                                    
#define mAlarm_491               491            //                                    
#define mAlarm_492               492            //                                    
#define mAlarm_493               493            //                                    
#define mAlarm_494               494            //                                    
#define mAlarm_495               495            //                                    
#define mAlarm_496               496            //                                    
#define mAlarm_497               497            //                                    
#define mAlarm_498               498            //                                    
#define mAlarm_499               499            //                                    
#define mAlarm_500               500            //                                    
#define mAlarm_501               501            //                                    
#define mAlarm_502               502            //                                    
#define mAlarm_503               503            //                                    
#define mAlarm_504               504            //                                    
#define mAlarm_505               505            //                                    
#define mAlarm_506               506            //                                    
#define mAlarm_507               507            //                                    
#define mAlarm_508               508            //                                    
#define mAlarm_509               509            //                                    
#define mAlarm_510               510            //                                    
#define mAlarm_511               511            //                                    

#endif
