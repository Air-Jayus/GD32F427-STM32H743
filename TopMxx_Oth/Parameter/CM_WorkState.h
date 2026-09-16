/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_WorkState.h    工作状态文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0x782F  
****************************************************************************************************/
#ifndef CM_WorkState_h
    #define CM_WorkState_h

#ifdef RPHA_c
    #define CM_WorkState_ext
#else
    #define CM_WorkState_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//工作状态数量
#define mWorkStateNum   384  //工作状态数量

//工作状态类型对应开始序号及长度
#define mWSSN_Fast      0    //快速开始序号
#define mWSSN_Mid       128  //中速开始序号
#define mWSSN_Slow      256  //低速开始序号
#define mWSL_Fast       128  //快速长度
#define mWSL_Mid        128  //中速长度
#define mWSL_Slow       128  //低速长度

//工作状态数组定义
CM_WorkState_ext U16 WorkState[mWorkStateNum];  //工作状态数组

//工作状态序号宏定义
#define mState_0                 0              //                                    
#define mState_WorkStateLinkCode 1              //互连代码                                辅助用，参数互连代码
#define mState_WorkStateVer      2              //版本号                                 辅助用，参数版本号
#define mState_WorkStateID       3              //标识                                  辅助用，用于售后维护
#define mState_4                 4              //                                    
#define mState_SysWorkMode       5              //系统模式                                手动/半自动/时间/电眼/粗调模/自动调模/紧停/测试，Boot程序中也用到，序号改变时要一起改
#define mState_SysAction         6              //系统动作                                
#define mState_MCAlarm           7              //手清警报                                
#define mState_ACAlarm           8              //任清警报                                
#define mState_Prompt            9              //提示信息                                Boot程序中也用到，序号改变时要一起改
#define mState_CombAlarmSn       10             //组合警报的警报显示序号                         与警报配合使用(序号组合+警报文字显示)
#define mState_11                11             //                                    
#define mState_CycleTi           12             //全程计时                                
#define mState_CycleTiNoStop     13             //全程计时                                专用于热固机，计时不会因转手动而停止
#define mState_SysActOptTi       14             //动作操作时间                              
#define mState_SysActSetTi       15             //动作设定时间                              
#define mState_16                16             //                                    
#define mState_ShotCntLW         17             //产品数                                 已生产产品数（模数*每模产品数），低字
#define mState_ShotCntHW         18             //产品数                                 已生产产品数（模数*每模产品数），高字
#define mState_PackageCnt        19             //装模计数                                
#define mState_ShotBadCnt        20             //不良品数                                
#define mState_CylPos            21             //油缸位置                                有符号数，非实时，经100ms滤波
#define mState_ScrewPos          22             //螺杆位置                                有符号数，非实时，经100ms滤波
#define mState_MoldPos           23             //模板位置                                有符号数，非实时，经100ms滤波
#define mState_EjectPos          24             //顶针位置                                有符号数，非实时，经100ms滤波
#define mState_NozzlePos         25             //座台位置                                有符号数，非实时，经100ms滤波
#define mState_HAI1Value         26             //模拟量1值                               有符号数，非实时，经100ms滤波
#define mState_HAI2Value         27             //模拟量2值                               有符号数，非实时，经100ms滤波
#define mState_HAI3Value         28             //模拟量3值                               有符号数，非实时，经100ms滤波
#define mState_MoldThickValue    29             //模厚值                                 有符号数，非实时，经100ms滤波
#define mState_HoldPresPos       30             //保压尺位置                               有符号数，非实时，经100ms滤波
#define mState_PVMainPresOut     31             //主压力阀压力输出                            
#define mState_PVMainFlowOut     32             //主流量阀流量输出                            
#define mState_PVBackPresOut     33             //背压阀压力输出                             
#define mState_PVMoldOpenClsFlowOut 34          //开合模流量输出                             
#define mState_PVInjSuckFlowOut  35             //注射射退流量输出                            
#define mState_36                36             //                                    
#define mState_RealSys3Pres      37             //实时系统3压力                             有符号数，实时，无滤波
#define mState_RealLinkPres      38             //实时联动压力                              有符号数，实时，无滤波，应天剑快速机加
#define mState_RealSysPres       39             //实时系统压力                              有符号数，实时，无滤波
#define mState_RealSysFlow       40             //实时系统流量                              有符号数，实时，无滤波
#define mState_RealInjPres       41             //实时注射压力                              有符号数，实时，无滤波
#define mState_RealMoldPres      42             //实时模板压力                              有符号数，实时，无滤波
#define mState_MCHPPresHold      43             //高压锁模压力峰值                            
#define mState_ScrewRPM          44             //螺杆转数                                
#define mState_DIn01_16          45             //输入状态                                输入点01-16的状态：0-无输入 1-输入
#define mState_DIn17_32          46             //输入状态                                
#define mState_DIn33_48          47             //输入状态                                
#define mState_DIn49_64          48             //输入状态                                
#define mState_DIn65_80          49             //输入状态                                
#define mState_DIn81_96          50             //输入状态                                
#define mState_ProdShotCntLW     51             //生产模数                                已生产模数，低字
#define mState_ProdShotCntHW     52             //生产模数                                已生产模数，高字
#define mState_DOut01_16         53             //输出状态                                输出点01-16的状态：0-无输出 1-输出
#define mState_DOut17_32         54             //输出状态                                
#define mState_DOut33_48         55             //输出状态                                
#define mState_DOut49_64         56             //输出状态                                
#define mState_DOut65_80         57             //输出状态                                
#define mState_DOut81_96         58             //输出状态                                
#define mState_59                59             //                                    
#define mState_60                60             //                                    
#define mState_HtrRealOut        61             //加热器实时输出                             一位对应一通道，0-加热器闭合，1-加热器放开
#define mState_Motor3Temp        62             //马达三温度                               
#define mState_MotorState        63             //马达状态                                0-关 1-开 2-正在开启
#define mState_HtrState          64             //电热状态                                0-关 1-开 2-预热
#define mState_MonAlarmState     65             //监测警报状态                              0-关 1-开
#define mState_OilMotTempState   66             //油箱和电机温度状态                           Bit0-3:油箱 Bit4-7:电机  状态：关闭、断电、断偶…
#define mState_Zone1_4TempState  67             //1～4段温度状态                            每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define mState_Zone5_8TempState  68             //5～8段温度状态                            每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define mState_Zone9_12TempState 69             //9～12段温度状态                           每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define mState_Zone13_16TempState 70            //13～16段温度状态                          每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define mState_71                71             //                                    
#define mState_OilMotTempStaDisp 72             //油箱和电机温度状态显示                         B0-1:油箱 B2-3:电机 B4-5:驱动器 状态:关闭、正常、偏差、异常
#define mState_Zone1_8TempStaDisp 73            //1～8段温度状态显示                          每2位代表一段温度的状态：关闭、正常、偏差、异常
#define mState_Zone9_16TempStaDisp 74           //9～16段温度状态显示                         每2位代表一段温度的状态：关闭、正常、偏差、异常
#define mState_Motor2Temp        75             //马达二温度                               
#define mState_Zone1_16Upd       76             //料筒温度更新                              1位对应1段，通过取反告知界面温度数据更新，曲线显示用
#define mState_MotorTemp         77             //马达温度                                
#define mState_OilTemp           78             //油箱温度                                
#define mState_Zone1Temp         79             //料筒1段温度                              
#define mState_Zone2Temp         80             //料筒2段温度                              
#define mState_Zone3Temp         81             //料筒3段温度                              
#define mState_Zone4Temp         82             //料筒4段温度                              
#define mState_Zone5Temp         83             //料筒5段温度                              
#define mState_Zone6Temp         84             //料筒6段温度                              
#define mState_Zone7Temp         85             //料筒7段温度                              
#define mState_Zone8Temp         86             //料筒8段温度                              
#define mState_Zone9Temp         87             //料筒9段温度                              
#define mState_Zone10Temp        88             //料筒10段温度                             
#define mState_Zone11Temp        89             //料筒11段温度                             
#define mState_Zone12Temp        90             //料筒12段温度                             
#define mState_Zone13Temp        91             //料筒13段温度                             
#define mState_Zone14Temp        92             //料筒14段温度                             
#define mState_Zone15Temp        93             //料筒15段温度                             
#define mState_Zone16Temp        94             //料筒16段温度                             
#define mState_J5_PID_CanQ       95             //J5多组PID的CAN通讯质量                     B15-通讯正常标志 B14B13-通讯质量  B11～B0-丢包数
#define mState_DAC1Out           96             //DA通道1输出                             通道当前输出
#define mState_DAC2Out           97             //DA通道2输出                             通道当前输出
#define mState_DAC3Out           98             //DA通道3输出                             通道当前输出
#define mState_DAC4Out           99             //DA通道4输出                             通道当前输出
#define mState_DAC5Out           100            //DA通道5输出                             通道当前输出
#define mState_DAC6Out           101            //DA通道6输出                             通道当前输出
#define mState_DAC7Out           102            //DA通道7输出                             通道当前输出
#define mState_DAC8Out           103            //DA通道8输出                             通道当前输出
#define mState_DAC1_2CurrOut     104            //DA通道1、2电流输出                         高字节为通道2、低字节为通道1
#define mState_DAC3_4CurrOut     105            //DA通道3、4电流输出                         高字节为通道3、低字节为通道4
#define mState_DAC5_6CurrOut     106            //DA通道5、6电流输出                         高字节为通道5、低字节为通道6
#define mState_DAC7_8CurrOut     107            //DA通道7、8电流输出                         高字节为通道7、低字节为通道8
#define mState_108               108            //                                    
#define mState_MoldAdjSnrCnt     109            //调模电眼计数                              
#define mState_Inject1TiReal     110            //射出1段时间                              实际
#define mState_Inject2TiReal     111            //射出2段时间                              实际
#define mState_Inject3TiReal     112            //射出3段时间                              实际
#define mState_Inject4TiReal     113            //射出4段时间                              实际
#define mState_Inject5TiReal     114            //射出5段时间                              实际
#define mState_Inject6TiReal     115            //射出6段时间                              实际
#define mState_Inject7TiReal     116            //射出7段时间                              实际
#define mState_Inject8TiReal     117            //射出8段时间                              实际
#define mState_Inject9TiReal     118            //射出9段时间                              实际
#define mState_Inject10TiReal    119            //射出10段时间                             实际
#define mState_ChgGearTemp       120            //储料齿轮温度                              储料齿轮温度
#define mState_CanDatWaitReadLen 121            //待界面读取的CAN数据长度                       主机从CBox接收待界面读取的CAN数据长度
#define mState_SDSn              122            //驱动器序号                               多个驱动器时，用以逐个反馈驱动器数据
#define mState_SDHistEnerConsL   123            //驱动器累计能耗（低位）                         
#define mState_SDHistEnerConsH   124            //驱动器累计能耗（高位）                         
#define mState_SDTtlRunTime      125            //累计运行时间                              驱动器累计运行时间
#define mState_SDTtlOLRunTime    126            //累计过载运行时间                            驱动器累计过载运行时间
#define mState_SDTemp            127            //驱动器温度                               
#define mState_SDMotWindTemp     128            //电机绕组温度                              
#define mState_SDOutTorque       129            //驱动器输出转矩                             
#define mState_SDErrCode         130            //故障代号                                高字节驱动器号、低字节故障代码
#define mState_SDCommQ           131            //通讯质量                                B15-通讯联机标志 B14B13-通讯质量  B11～B0-丢包数
#define mState_SDRunState        132            //运行状态                                1-正转 2-反转 3-停机
#define mState_SDBusVol          133            //母线电压                                
#define mState_SDOutVol          134            //输出电压                                
#define mState_SDOutCurr         135            //输出电流                                
#define mState_SDOutPwr          136            //输出功率                                
#define mState_SDDIState         137            //DI输入                                
#define mState_SDDOState         138            //DO输出                                
#define mState_SDAI1Vol          139            //AI1电压                               
#define mState_SDAI2Vol          140            //AI2电压                               
#define mState_SDAI3Vol          141            //AI3电压                               
#define mState_SDRealAngle       142            //实时角度                                范围0.0～359.9
#define mState_SDSetPres         143            //给定油压                                
#define mState_SDRealPres        144            //反馈油压                                
#define mState_SDSetFlow         145            //给定流量                                
#define mState_SDRealFlow        146            //反馈流量                                
#define mState_SDRealRPM         147            //负载转速                                
#define mState_148               148            //                                    
#define mState_149               149            //                                    
#define mState_E1DIn01_16        150            //输入状态                                CAN模块1，输入点01-16的状态：0-无输入 1-输入
#define mState_E2DIn01_16        151            //输入状态                                
#define mState_E3DIn01_16        152            //输入状态                                
#define mState_E4DIn01_16        153            //输入状态                                
#define mState_E5DIn01_16        154            //输入状态                                
#define mState_E6DIn01_16        155            //输入状态                                
#define mState_E1DOut01_16       156            //输出状态                                CAN模块1，输出点01-16的状态：0-无输出 1-输出
#define mState_E2DOut01_16       157            //输出状态                                
#define mState_E3DOut01_16       158            //输出状态                                
#define mState_E4DOut01_16       159            //输出状态                                
#define mState_E5DOut01_16       160            //输出状态                                
#define mState_E6DOut01_16       161            //输出状态                                
#define mState_WaveDataAttr      162            //波形数据属性                              D15:触发、D12-D8:当前数据指针、D7-D0：数据序号
#define mState_WaveData0         163            //波形数据0                               根据设置，灵活构成5组、3组、2组、1组波形
#define mState_WaveData1         164            //波形数据1                               
#define mState_WaveData2         165            //波形数据2                               
#define mState_WaveData3         166            //波形数据3                               
#define mState_WaveData4         167            //波形数据4                               
#define mState_WaveData5         168            //波形数据5                               
#define mState_WaveData6         169            //波形数据6                               
#define mState_WaveData7         170            //波形数据7                               
#define mState_WaveData8         171            //波形数据8                               
#define mState_WaveData9         172            //波形数据9                               
#define mState_WaveData10        173            //波形数据10                              
#define mState_WaveData11        174            //波形数据11                              
#define mState_WaveData12        175            //波形数据12                              
#define mState_WaveData13        176            //波形数据13                              
#define mState_WaveData14        177            //波形数据14                              
#define mState_WaveData15        178            //波形数据15                              
#define mState_WaveData16        179            //波形数据16                              
#define mState_WaveData17        180            //波形数据17                              
#define mState_WaveData18        181            //波形数据18                              
#define mState_WaveData19        182            //波形数据19                              
#define mState_WaveData20        183            //波形数据20                              
#define mState_WaveData21        184            //波形数据21                              
#define mState_WaveData22        185            //波形数据22                              
#define mState_WaveData23        186            //波形数据23                              
#define mState_WaveData24        187            //波形数据24                              
#define mState_WaveData25        188            //波形数据25                              
#define mState_WaveData26        189            //波形数据26                              
#define mState_WaveData27        190            //波形数据27                              
#define mState_WaveData28        191            //波形数据28                              
#define mState_WaveData29        192            //波形数据29                              
#define mState_CycTiReal         193            //循环时间                                实际
#define mState_CycTiLast         194            //循环时间                                上一模
#define mState_CycTiOL           195            //循环时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoldClsTiReal     196            //关模时间                                实际
#define mState_MoldClsTiLast     197            //关模时间                                上一模
#define mState_MoldClsTiOL       198            //关模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoldClsLPTiReal   199            //关模低压时间                              实际
#define mState_MoldClsLPTiLast   200            //关模低压时间                              上一模
#define mState_MoldClsLPTiOL     201            //关模低压时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoldClsHPTiReal   202            //关模高压时间                              实际
#define mState_MoldClsHPTiLast   203            //关模高压时间                              上一模
#define mState_MoldClsHPTiOL     204            //关模高压时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoldOpenTiReal    205            //开模时间                                实际
#define mState_MoldOpenTiLast    206            //开模时间                                上一模
#define mState_MoldOpenTiOL      207            //开模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoldOpenEPosReal   208           //开模结束位置                              实际
#define mState_MoldOpenEPosLast   209           //开模结束位置                              上一模
#define mState_MoldOpenEPosOL     210           //开模结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_InjectTiReal      211            //射出时间                                实际
#define mState_InjectTiLast      212            //射出时间                                上一模
#define mState_InjectTiOL        213            //射出时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_InjectEPosReal    214            //射出结束位置                              实际
#define mState_InjectEPosLast    215            //射出结束位置                              上一模
#define mState_InjectEPosOL      216            //射出结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_InjectSpdReal     217            //射出最高速度                              实际
#define mState_InjectSpdLast     218            //射出最高速度                              上一模
#define mState_InjectSpdOL       219            //射出最高速度                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_ChargeTiReal      220            //储料时间                                实际
#define mState_ChargeTiLast      221            //储料时间                                上一模
#define mState_ChargeTiOL        222            //储料时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_ChargeEPosReal    223            //储料结束位置                              实际
#define mState_ChargeEPosLast    224            //储料结束位置                              上一模
#define mState_ChargeEPosOL      225            //储料结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_ChargeRPMReal     226            //储料最高转速                              实际
#define mState_ChargeRPMLast     227            //储料最高转速                              上一模
#define mState_ChargeRPMOL         228          //储料最高转速                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_SuckBackTiReal    229            //射退时间                                实际
#define mState_SuckBackTiLast    230            //射退时间                                上一模
#define mState_SuckBackTiOL      231            //射退时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_HoldPresSPosReal   232           //保压转换位置                              实际
#define mState_HoldPresSPosLast   233           //保压转换位置                              上一模
#define mState_HoldPresSPosOL     234           //保压转换位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_HoldPresTiReal    235            //保压转换时间                              实际
#define mState_HoldPresTiLast    236            //保压转换时间                              上一模
#define mState_HoldPresTiOL      237            //保压转换时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_HoldPresSPresReal   238          //保压转换压力                              实际
#define mState_HoldPresSPresLast   239          //保压转换压力                              上一模
#define mState_HoldPresSPresOL     240          //保压转换压力                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_EjeForTiReal      241            //托模时间                                实际
#define mState_EjeForTiLast      242            //托模时间                                上一模
#define mState_EjeForTiOL        243            //托模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define mState_MoniDataState     244            //监测数据状态                              B0-监测数据更新，该位取反(与模数变化相比，迟开关安全门、电眼检物或循环延迟时间，即略晚)
#define mState_InjPeakPresReal   245            //注射峰值压力                              实际
#define mState_InjPeakPresLast   246            //注射峰值压力                              上一模
#define mState_InjPeakPresOL     247            //注射峰值压力                              超限标志，B0-当前模  B1-上一模，为1超限
#define mState_248               248            //                                    
#define mState_249               249            //                                    
#define mState_250               250            //                                    
#define mState_InjPeakPresStd    251            //注射峰值 压力                             标准值
#define mState_CycTiStd          252            //循环时间                                标准值
#define mState_MoldClsTiStd      253            //关模时间                                标准值
#define mState_MoldClsLPTiStd    254            //关模低压时间                              标准值
#define mState_MoldClsHPTiStd    255            //关模高压时间                              标准值
#define mState_MoldOpenTiStd     256            //开模时间                                标准值
#define mState_MoldOpenEPosStd   257            //开模结束位置                              标准值
#define mState_InjectTiStd       258            //射出时间                                标准值
#define mState_InjectEPosStd     259            //射出结束位置                              标准值
#define mState_InjectSpdStd      260            //射出最高速度                              标准值
#define mState_ChargeTiStd       261            //储料时间                                标准值
#define mState_ChargeEPosStd     262            //储料结束位置                              标准值
#define mState_ChargeRPMStd      263            //储料最高转速                              标准值
#define mState_SuckBackTiStd     264            //射退时间                                标准值
#define mState_HoldPresSPosStd   265            //保压转换位置                              标准值
#define mState_HoldPresTiStd     266            //保压转换时间                              标准值
#define mState_HoldPresSPresStd  267            //保压转换压力                              标准值
#define mState_EjeForTiStd       268            //托模时间                                标准值
#define mState_MoniStdDataUpdate 269            //监测数据标准值更新                           0-不更新 1-更新到生产参数相应标准值
#define mState_SDRdData_Info     270            //驱动器读取数据的信息                          B15:1数据有效 B7-B4:驱动器号 B3-B0:数据长度(字节为单位)
#define mState_SDRdData_Addr     271            //驱动器读取数据的地址                          
#define mState_SDRdData_DataL    272            //驱动器读取数据的数据低字                        
#define mState_SDRdData_DataH    273            //驱动器读取数据的数据高字                        
#define mState_SmallMotRPM       274            //小电机转速                               
#define mState_275               275            //                                    
#define mState_276               276            //                                    
#define mState_277               277            //                                    
#define mState_278               278            //                                    
#define mState_279               279            //                                    
#define mState_ParaGenl          280            //开模参数自学习状态                           0-没有进行开模参数自学习 1-正在进行开模参数自学习
#define mState_MODstPos          281            //主机返回的开模目标位置                         
#define mState_DAC1OutLim        282            //DA通道1输出限值                           DA通道输出限值
#define mState_DAC2OutLim        283            //DA通道2输出限值                           DA通道输出限值
#define mState_DAC3OutLim        284            //DA通道3输出限值                           DA通道输出限值
#define mState_DAC4OutLim        285            //DA通道4输出限值                           DA通道输出限值
#define mState_DAC5OutLim        286            //DA通道5输出限值                           DA通道输出限值
#define mState_DAC6OutLim        287            //DA通道6输出限值                           DA通道输出限值
#define mState_DAC7OutLim        288            //DA通道7输出限值                           DA通道输出限值
#define mState_DAC8OutLim        289            //DA通道8输出限值                           DA通道输出限值
#define mState_290               290            //                                    
#define mState_291               291            //                                    
#define mState_292               292            //                                    
#define mState_293               293            //                                    
#define mState_294               294            //                                    
#define mState_295               295            //                                    
#define mState_296               296            //                                    
#define mState_297               297            //                                    
#define mState_298               298            //                                    
#define mState_299               299            //                                    
#define mState_Power_TtlKWhLW    300            //累计用电量                               电表测得累计用电量(低字)
#define mState_Power_TtlKWhHW    301            //累计用电量                               电表测得累计用电量(高字)
#define mState_302               302            //                                    
#define mState_303               303            //                                    
#define mState_304               304            //                                    
#define mState_305               305            //                                    
#define mState_306               306            //                                    
#define mState_307               307            //                                    
#define mState_308               308            //                                    
#define mState_ZoneCoolProtRemTi 309            //料筒防冷剩余时间                            
#define mState_HtrTtlTimeSN      310            //累计加热时间序号                            累计加热时间对应的通道号, 高字节对应HtrTtlTimeA、低字节对应HtrTTlTimeB
#define mState_HtrTtlTimeA       311            //加热累计时间                              电热x通道累计加热输出时间，x由HtrTtlTimeSN高字节给出
#define mState_HtrTtlTimeB       312            //加热累计时间                              电热x通道累计加热输出时间，x由HtrTtlTimeSN低字节给出
#define mState_HtrTtlOnTime      313            //电热累计开启时间                            电热累计开启时间
#define mState_Lubr1NextUnitCnt  314            //润滑1下次润滑模数                           
#define mState_Lubr2NextUnitCnt  315            //润滑2下次润滑模数                           
#define mState_LubrCnt_1W        316            //润滑计数到1万模标志                          0-未到1万模，1-到1万模，用于润滑参数管理模式为区分前后10000模时
#define mState_HoldPresSnrVol    317            //保压尺传感器电压                            
#define mState_InjPeakPresUpLim  318            //注射峰值压力                              上限
#define mState_InjPeakPresLowLim 319            //注射峰值压力                              下限
#define mState_CycTiUpLim        320            //循环时间                                上限
#define mState_CycTiLowLim       321            //循环时间                                下限
#define mState_MoldClsTiUpLim    322            //关模时间                                上限
#define mState_MoldClsTiLowLim   323            //关模时间                                下限
#define mState_MoldClsLPTiUpLim  324            //关模低压时间                              上限
#define mState_MoldClsLPTiLowLim 325            //关模低压时间                              下限
#define mState_MoldClsHPTiUpLim  326            //关模高压时间                              上限
#define mState_MoldClsHPTiLowLim 327            //关模高压时间                              下限
#define mState_MoldOpenTiUpLim   328            //开模时间                                上限
#define mState_MoldOpenTiLowLim  329            //开模时间                                下限
#define mState_MoldOpenEPosUpLim  330           //开模结束位置                              上限
#define mState_MoldOpenEPosLowLim 331           //开模结束位置                              下限
#define mState_InjectTiUpLim     332            //射出时间                                上限
#define mState_InjectTiLowLim    333            //射出时间                                下限
#define mState_InjectEPosUpLim   334            //射出结束位置                              上限
#define mState_InjectEPosLowLim  335            //射出结束位置                              下限
#define mState_InjectSpdUpLim    336            //射出最高速度                              上限
#define mState_InjectSpdLowLim   337            //射出最高速度                              下限
#define mState_ChargeTiUpLim     338            //储料时间                                上限
#define mState_ChargeTiLowLim    339            //储料时间                                下限
#define mState_ChargeEPosUpLim   340            //储料结束位置                              上限
#define mState_ChargeEPosLowLim  341            //储料结束位置                              下限
#define mState_ChargeRPMUpLim    342            //储料最高转速                              上限
#define mState_ChargeRPMLowLim   343            //储料最高转速                              下限
#define mState_SuckBackTiUpLim   344            //射退时间                                上限
#define mState_SuckBackTiLowLim  345            //射退时间                                下限
#define mState_HoldPresSPosUpLim  346           //保压转换位置                              上限
#define mState_HoldPresSPosLowLim 347           //保压转换位置                              下限
#define mState_HoldPresTiUpLim   348            //保压转换时间                              上限
#define mState_HoldPresTiLowLim  349            //保压转换时间                              下限
#define mState_HoldPresSPresUpLim  350          //保压转换压力                              上限
#define mState_HoldPresSPresLowLim 351          //保压转换压力                              下限
#define mState_EjeForTiUpLim     352            //托模时间                                上限
#define mState_EjeForTiLowLim    353            //托模时间                                下限
#define mState_MoldThickSnrVol   354            //模厚传感器电压                             
#define mState_CMPartSN_LW       355            //主机器件流水号                             主机芯片的流水号（低字）
#define mState_CMPartSN_HW       356            //主机器件流水号                             主机芯片的流水号（高字）
#define mState_CMAuthorized1_LW  357            //主机授权1                               主机程序授权1（低字）,授权1为基本授权，无此授权禁止自动运行
#define mState_CMAuthorized1_HW  358            //主机授权1                               主机程序授权1（高字）,授权1为基本授权，无此授权禁止自动运行
#define mState_CMAuthorized2_LW  359            //主机授权2                               主机程序授权2（低字）,该授权暂保留
#define mState_CMAuthorized2_HW  360            //主机授权2                               主机程序授权2（高字）,该授权暂保留
#define mState_ScrewSnrVol       361            //螺杆传感器电压                             
#define mState_MoldSnrVol        362            //模板传感器电压                             
#define mState_EjeSnrVol         363            //顶针传感器电压                             
#define mState_NozSnrVol         364            //座台传感器电压                             
#define mState_HAI1Vol           365            //模拟量1电压                              
#define mState_HAI2Vol           366            //模拟量2电压                              
#define mState_HAI3Vol           367            //模拟量3电压                              
#define mState_ZoneAccStaSN_A    368            //料筒附加状态对应段号                          与下二项状态配合用，本状态指明对应段，其它的是段信息
#define mState_ZoneHrtTime_A     369            //某段加热时间                              
#define mState_ZoneTemp01C_A     370            //某段温度                                
#define mState_ZoneAccStaSN_B    371            //料筒附加状态对应段号                          用2组，原因是这部分状态刷新周期为0.5s，慢于温度更新速度
#define mState_ZoneHrtTime_B     372            //某段加热时间                              
#define mState_ZoneTemp01C_B     373            //某段温度                                
#define mState_CMWorkShotCntLW   374            //主机工作模数                              主机开机工作累计打产品模数(低字)，也用于标识一模完成
#define mState_CMWorkShotCntHW   375            //主机工作模数                              主机开机工作累计打产品模数(高字)
#define mState_CMWorkTimeLW      376            //主机工作时间                              主机开机工作累计时间（低字）
#define mState_CMWorkTimeHW      377            //主机工作时间                              主机开机工作累计时间(高字)
#define mState_CMBootVer         378            //主机Boot版本                            Boot程序中也用到，序号改变时要一起改
#define mState_CMSoftLinkCode    379            //主机软件互连代号                            
#define mState_CMSoftSer         380            //主机软件系列                              
#define mState_CMSoftVer         381            //主机软件版本                              
#define mState_CMProdBatch       382            //主机生产批号                              
#define mState_CMProdSN          383            //主机生产序号                              

//工作状态引用宏定义
#define State_0                  WorkState[0]   //                                    
#define State_WorkStateLinkCode  WorkState[1]   //互连代码                                辅助用，参数互连代码
#define State_WorkStateVer       WorkState[2]   //版本号                                 辅助用，参数版本号
#define State_WorkStateID        WorkState[3]   //标识                                  辅助用，用于售后维护
#define State_4                  WorkState[4]   //                                    
#define State_SysWorkMode        WorkState[5]   //系统模式                                手动/半自动/时间/电眼/粗调模/自动调模/紧停/测试，Boot程序中也用到，序号改变时要一起改
#define State_SysAction          WorkState[6]   //系统动作                                
#define State_MCAlarm            WorkState[7]   //手清警报                                
#define State_ACAlarm            WorkState[8]   //任清警报                                
#define State_Prompt             WorkState[9]   //提示信息                                Boot程序中也用到，序号改变时要一起改
#define State_CombAlarmSn        WorkState[10]  //组合警报的警报显示序号                         与警报配合使用(序号组合+警报文字显示)
#define State_11                 WorkState[11]  //                                    
#define State_CycleTi            WorkState[12]  //全程计时                                
#define State_CycleTiNoStop      WorkState[13]  //全程计时                                专用于热固机，计时不会因转手动而停止
#define State_SysActOptTi        WorkState[14]  //动作操作时间                              
#define State_SysActSetTi        WorkState[15]  //动作设定时间                              
#define State_16                 WorkState[16]  //                                    
#define State_ShotCntLW          WorkState[17]  //产品数                                 已生产产品数（模数*每模产品数），低字
#define State_ShotCntHW          WorkState[18]  //产品数                                 已生产产品数（模数*每模产品数），高字
#define State_PackageCnt         WorkState[19]  //装模计数                                
#define State_ShotBadCnt         WorkState[20]  //不良品数                                
#define State_CylPos             WorkState[21]  //油缸位置                                有符号数，非实时，经100ms滤波
#define State_ScrewPos           WorkState[22]  //螺杆位置                                有符号数，非实时，经100ms滤波
#define State_MoldPos            WorkState[23]  //模板位置                                有符号数，非实时，经100ms滤波
#define State_EjectPos           WorkState[24]  //顶针位置                                有符号数，非实时，经100ms滤波
#define State_NozzlePos          WorkState[25]  //座台位置                                有符号数，非实时，经100ms滤波
#define State_HAI1Value          WorkState[26]  //模拟量1值                               有符号数，非实时，经100ms滤波
#define State_HAI2Value          WorkState[27]  //模拟量2值                               有符号数，非实时，经100ms滤波
#define State_HAI3Value          WorkState[28]  //模拟量3值                               有符号数，非实时，经100ms滤波
#define State_MoldThickValue     WorkState[29]  //模厚值                                 有符号数，非实时，经100ms滤波
#define State_HoldPresPos        WorkState[30]  //保压尺位置                               有符号数，非实时，经100ms滤波
#define State_PVMainPresOut      WorkState[31]  //主压力阀压力输出                            
#define State_PVMainFlowOut      WorkState[32]  //主流量阀流量输出                            
#define State_PVBackPresOut      WorkState[33]  //背压阀压力输出                             
#define State_PVMoldOpenClsFlowOut WorkState[34]//开合模流量输出                             
#define State_PVInjSuckFlowOut   WorkState[35]  //注射射退流量输出                            
#define State_36                 WorkState[36]  //                                    
#define State_RealSys3Pres       WorkState[37]  //实时系统3压力                             有符号数，实时，无滤波
#define State_RealLinkPres       WorkState[38]  //实时联动压力                              有符号数，实时，无滤波，应天剑快速机加
#define State_RealSysPres        WorkState[39]  //实时系统压力                              有符号数，实时，无滤波
#define State_RealSysFlow        WorkState[40]  //实时系统流量                              有符号数，实时，无滤波
#define State_RealInjPres        WorkState[41]  //实时注射压力                              有符号数，实时，无滤波
#define State_RealMoldPres       WorkState[42]  //实时模板压力                              有符号数，实时，无滤波
#define State_MCHPPresHold       WorkState[43]  //高压锁模压力峰值                            
#define State_ScrewRPM           WorkState[44]  //螺杆转数                                
#define State_DIn01_16           WorkState[45]  //输入状态                                输入点01-16的状态：0-无输入 1-输入
#define State_DIn17_32           WorkState[46]  //输入状态                                
#define State_DIn33_48           WorkState[47]  //输入状态                                
#define State_DIn49_64           WorkState[48]  //输入状态                                
#define State_DIn65_80           WorkState[49]  //输入状态                                
#define State_DIn81_96           WorkState[50]  //输入状态                                
#define State_ProdShotCntLW      WorkState[51]  //生产模数                                已生产模数，低字
#define State_ProdShotCntHW      WorkState[52]  //生产模数                                已生产模数，高字
#define State_DOut01_16          WorkState[53]  //输出状态                                输出点01-16的状态：0-无输出 1-输出
#define State_DOut17_32          WorkState[54]  //输出状态                                
#define State_DOut33_48          WorkState[55]  //输出状态                                
#define State_DOut49_64          WorkState[56]  //输出状态                                
#define State_DOut65_80          WorkState[57]  //输出状态                                
#define State_DOut81_96          WorkState[58]  //输出状态                                
#define State_59                 WorkState[59]  //                                    
#define State_60                 WorkState[60]  //                                    
#define State_HtrRealOut         WorkState[61]  //加热器实时输出                             一位对应一通道，0-加热器闭合，1-加热器放开
#define State_Motor3Temp         WorkState[62]  //马达三温度                               
#define State_MotorState         WorkState[63]  //马达状态                                0-关 1-开 2-正在开启
#define State_HtrState           WorkState[64]  //电热状态                                0-关 1-开 2-预热
#define State_MonAlarmState      WorkState[65]  //监测警报状态                              0-关 1-开
#define State_OilMotTempState    WorkState[66]  //油箱和电机温度状态                           Bit0-3:油箱 Bit4-7:电机  状态：关闭、断电、断偶…
#define State_Zone1_4TempState   WorkState[67]  //1～4段温度状态                            每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define State_Zone5_8TempState   WorkState[68]  //5～8段温度状态                            每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define State_Zone9_12TempState  WorkState[69]  //9～12段温度状态                           每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define State_Zone13_16TempState WorkState[70]  //13～16段温度状态                          每4位代表一段温度的状态：关闭、断电、断偶、快升、快降…
#define State_71                 WorkState[71]  //                                    
#define State_OilMotTempStaDisp  WorkState[72]  //油箱和电机温度状态显示                         B0-1:油箱 B2-3:电机 B4-5:驱动器 状态:关闭、正常、偏差、异常
#define State_Zone1_8TempStaDisp WorkState[73]  //1～8段温度状态显示                          每2位代表一段温度的状态：关闭、正常、偏差、异常
#define State_Zone9_16TempStaDisp WorkState[74] //9～16段温度状态显示                         每2位代表一段温度的状态：关闭、正常、偏差、异常
#define State_Motor2Temp         WorkState[75]  //马达二温度                               
#define State_Zone1_16Upd        WorkState[76]  //料筒温度更新                              1位对应1段，通过取反告知界面温度数据更新，曲线显示用
#define State_MotorTemp          WorkState[77]  //马达温度                                
#define State_OilTemp            WorkState[78]  //油箱温度                                
#define State_Zone1Temp          WorkState[79]  //料筒1段温度                              
#define State_Zone2Temp          WorkState[80]  //料筒2段温度                              
#define State_Zone3Temp          WorkState[81]  //料筒3段温度                              
#define State_Zone4Temp          WorkState[82]  //料筒4段温度                              
#define State_Zone5Temp          WorkState[83]  //料筒5段温度                              
#define State_Zone6Temp          WorkState[84]  //料筒6段温度                              
#define State_Zone7Temp          WorkState[85]  //料筒7段温度                              
#define State_Zone8Temp          WorkState[86]  //料筒8段温度                              
#define State_Zone9Temp          WorkState[87]  //料筒9段温度                              
#define State_Zone10Temp         WorkState[88]  //料筒10段温度                             
#define State_Zone11Temp         WorkState[89]  //料筒11段温度                             
#define State_Zone12Temp         WorkState[90]  //料筒12段温度                             
#define State_Zone13Temp         WorkState[91]  //料筒13段温度                             
#define State_Zone14Temp         WorkState[92]  //料筒14段温度                             
#define State_Zone15Temp         WorkState[93]  //料筒15段温度                             
#define State_Zone16Temp         WorkState[94]  //料筒16段温度                             
#define State_J5_PID_CanQ        WorkState[95]  //J5多组PID的CAN通讯质量                     B15-通讯正常标志 B14B13-通讯质量  B11～B0-丢包数
#define State_DAC1Out            WorkState[96]  //DA通道1输出                             通道当前输出
#define State_DAC2Out            WorkState[97]  //DA通道2输出                             通道当前输出
#define State_DAC3Out            WorkState[98]  //DA通道3输出                             通道当前输出
#define State_DAC4Out            WorkState[99]  //DA通道4输出                             通道当前输出
#define State_DAC5Out            WorkState[100] //DA通道5输出                             通道当前输出
#define State_DAC6Out            WorkState[101] //DA通道6输出                             通道当前输出
#define State_DAC7Out            WorkState[102] //DA通道7输出                             通道当前输出
#define State_DAC8Out            WorkState[103] //DA通道8输出                             通道当前输出
#define State_DAC1_2CurrOut      WorkState[104] //DA通道1、2电流输出                         高字节为通道2、低字节为通道1
#define State_DAC3_4CurrOut      WorkState[105] //DA通道3、4电流输出                         高字节为通道3、低字节为通道4
#define State_DAC5_6CurrOut      WorkState[106] //DA通道5、6电流输出                         高字节为通道5、低字节为通道6
#define State_DAC7_8CurrOut      WorkState[107] //DA通道7、8电流输出                         高字节为通道7、低字节为通道8
#define State_108                WorkState[108] //                                    
#define State_MoldAdjSnrCnt      WorkState[109] //调模电眼计数                              
#define State_Inject1TiReal      WorkState[110] //射出1段时间                              实际
#define State_Inject2TiReal      WorkState[111] //射出2段时间                              实际
#define State_Inject3TiReal      WorkState[112] //射出3段时间                              实际
#define State_Inject4TiReal      WorkState[113] //射出4段时间                              实际
#define State_Inject5TiReal      WorkState[114] //射出5段时间                              实际
#define State_Inject6TiReal      WorkState[115] //射出6段时间                              实际
#define State_Inject7TiReal      WorkState[116] //射出7段时间                              实际
#define State_Inject8TiReal      WorkState[117] //射出8段时间                              实际
#define State_Inject9TiReal      WorkState[118] //射出9段时间                              实际
#define State_Inject10TiReal     WorkState[119] //射出10段时间                             实际
#define State_ChgGearTemp        WorkState[120] //储料齿轮温度                              储料齿轮温度
#define State_CanDatWaitReadLen  WorkState[121] //待界面读取的CAN数据长度                       主机从CBox接收待界面读取的CAN数据长度
#define State_SDSn               WorkState[122] //驱动器序号                               多个驱动器时，用以逐个反馈驱动器数据
#define State_SDHistEnerConsL    WorkState[123] //驱动器累计能耗（低位）                         
#define State_SDHistEnerConsH    WorkState[124] //驱动器累计能耗（高位）                         
#define State_SDTtlRunTime       WorkState[125] //累计运行时间                              驱动器累计运行时间
#define State_SDTtlOLRunTime     WorkState[126] //累计过载运行时间                            驱动器累计过载运行时间
#define State_SDTemp             WorkState[127] //驱动器温度                               
#define State_SDMotWindTemp      WorkState[128] //电机绕组温度                              
#define State_SDOutTorque        WorkState[129] //驱动器输出转矩                             
#define State_SDErrCode          WorkState[130] //故障代号                                高字节驱动器号、低字节故障代码
#define State_SDCommQ            WorkState[131] //通讯质量                                B15-通讯联机标志 B14B13-通讯质量  B11～B0-丢包数
#define State_SDRunState         WorkState[132] //运行状态                                1-正转 2-反转 3-停机
#define State_SDBusVol           WorkState[133] //母线电压                                
#define State_SDOutVol           WorkState[134] //输出电压                                
#define State_SDOutCurr          WorkState[135] //输出电流                                
#define State_SDOutPwr           WorkState[136] //输出功率                                
#define State_SDDIState          WorkState[137] //DI输入                                
#define State_SDDOState          WorkState[138] //DO输出                                
#define State_SDAI1Vol           WorkState[139] //AI1电压                               
#define State_SDAI2Vol           WorkState[140] //AI2电压                               
#define State_SDAI3Vol           WorkState[141] //AI3电压                               
#define State_SDRealAngle        WorkState[142] //实时角度                                范围0.0～359.9
#define State_SDSetPres          WorkState[143] //给定油压                                
#define State_SDRealPres         WorkState[144] //反馈油压                                
#define State_SDSetFlow          WorkState[145] //给定流量                                
#define State_SDRealFlow         WorkState[146] //反馈流量                                
#define State_SDRealRPM          WorkState[147] //负载转速                                
#define State_148                WorkState[148] //                                    
#define State_149                WorkState[149] //                                    
#define State_E1DIn01_16         WorkState[150] //输入状态                                CAN模块1，输入点01-16的状态：0-无输入 1-输入
#define State_E2DIn01_16         WorkState[151] //输入状态                                
#define State_E3DIn01_16         WorkState[152] //输入状态                                
#define State_E4DIn01_16         WorkState[153] //输入状态                                
#define State_E5DIn01_16         WorkState[154] //输入状态                                
#define State_E6DIn01_16         WorkState[155] //输入状态                                
#define State_E1DOut01_16        WorkState[156] //输出状态                                CAN模块1，输出点01-16的状态：0-无输出 1-输出
#define State_E2DOut01_16        WorkState[157] //输出状态                                
#define State_E3DOut01_16        WorkState[158] //输出状态                                
#define State_E4DOut01_16        WorkState[159] //输出状态                                
#define State_E5DOut01_16        WorkState[160] //输出状态                                
#define State_E6DOut01_16        WorkState[161] //输出状态                                
#define State_WaveDataAttr       WorkState[162] //波形数据属性                              D15:触发、D12-D8:当前数据指针、D7-D0：数据序号
#define State_WaveData0          WorkState[163] //波形数据0                               根据设置，灵活构成5组、3组、2组、1组波形
#define State_WaveData1          WorkState[164] //波形数据1                               
#define State_WaveData2          WorkState[165] //波形数据2                               
#define State_WaveData3          WorkState[166] //波形数据3                               
#define State_WaveData4          WorkState[167] //波形数据4                               
#define State_WaveData5          WorkState[168] //波形数据5                               
#define State_WaveData6          WorkState[169] //波形数据6                               
#define State_WaveData7          WorkState[170] //波形数据7                               
#define State_WaveData8          WorkState[171] //波形数据8                               
#define State_WaveData9          WorkState[172] //波形数据9                               
#define State_WaveData10         WorkState[173] //波形数据10                              
#define State_WaveData11         WorkState[174] //波形数据11                              
#define State_WaveData12         WorkState[175] //波形数据12                              
#define State_WaveData13         WorkState[176] //波形数据13                              
#define State_WaveData14         WorkState[177] //波形数据14                              
#define State_WaveData15         WorkState[178] //波形数据15                              
#define State_WaveData16         WorkState[179] //波形数据16                              
#define State_WaveData17         WorkState[180] //波形数据17                              
#define State_WaveData18         WorkState[181] //波形数据18                              
#define State_WaveData19         WorkState[182] //波形数据19                              
#define State_WaveData20         WorkState[183] //波形数据20                              
#define State_WaveData21         WorkState[184] //波形数据21                              
#define State_WaveData22         WorkState[185] //波形数据22                              
#define State_WaveData23         WorkState[186] //波形数据23                              
#define State_WaveData24         WorkState[187] //波形数据24                              
#define State_WaveData25         WorkState[188] //波形数据25                              
#define State_WaveData26         WorkState[189] //波形数据26                              
#define State_WaveData27         WorkState[190] //波形数据27                              
#define State_WaveData28         WorkState[191] //波形数据28                              
#define State_WaveData29         WorkState[192] //波形数据29                              
#define State_CycTiReal          WorkState[193] //循环时间                                实际
#define State_CycTiLast          WorkState[194] //循环时间                                上一模
#define State_CycTiOL            WorkState[195] //循环时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoldClsTiReal      WorkState[196] //关模时间                                实际
#define State_MoldClsTiLast      WorkState[197] //关模时间                                上一模
#define State_MoldClsTiOL        WorkState[198] //关模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoldClsLPTiReal    WorkState[199] //关模低压时间                              实际
#define State_MoldClsLPTiLast    WorkState[200] //关模低压时间                              上一模
#define State_MoldClsLPTiOL      WorkState[201] //关模低压时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoldClsHPTiReal    WorkState[202] //关模高压时间                              实际
#define State_MoldClsHPTiLast    WorkState[203] //关模高压时间                              上一模
#define State_MoldClsHPTiOL      WorkState[204] //关模高压时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoldOpenTiReal     WorkState[205] //开模时间                                实际
#define State_MoldOpenTiLast     WorkState[206] //开模时间                                上一模
#define State_MoldOpenTiOL       WorkState[207] //开模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoldOpenEPosReal   WorkState[208] //开模结束位置                              实际
#define State_MoldOpenEPosLast   WorkState[209] //开模结束位置                              上一模
#define State_MoldOpenEPosOL     WorkState[210] //开模结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_InjectTiReal       WorkState[211] //射出时间                                实际
#define State_InjectTiLast       WorkState[212] //射出时间                                上一模
#define State_InjectTiOL         WorkState[213] //射出时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_InjectEPosReal     WorkState[214] //射出结束位置                              实际
#define State_InjectEPosLast     WorkState[215] //射出结束位置                              上一模
#define State_InjectEPosOL       WorkState[216] //射出结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_InjectSpdReal      WorkState[217] //射出最高速度                              实际
#define State_InjectSpdLast      WorkState[218] //射出最高速度                              上一模
#define State_InjectSpdOL        WorkState[219] //射出最高速度                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_ChargeTiReal       WorkState[220] //储料时间                                实际
#define State_ChargeTiLast       WorkState[221] //储料时间                                上一模
#define State_ChargeTiOL         WorkState[222] //储料时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_ChargeEPosReal     WorkState[223] //储料结束位置                              实际
#define State_ChargeEPosLast     WorkState[224] //储料结束位置                              上一模
#define State_ChargeEPosOL       WorkState[225] //储料结束位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_ChargeRPMReal      WorkState[226] //储料最高转速                              实际
#define State_ChargeRPMLast      WorkState[227] //储料最高转速                              上一模
#define State_ChargeRPMOL         WorkState[228]//储料最高转速                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_SuckBackTiReal     WorkState[229] //射退时间                                实际
#define State_SuckBackTiLast     WorkState[230] //射退时间                                上一模
#define State_SuckBackTiOL       WorkState[231] //射退时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_HoldPresSPosReal   WorkState[232] //保压转换位置                              实际
#define State_HoldPresSPosLast   WorkState[233] //保压转换位置                              上一模
#define State_HoldPresSPosOL     WorkState[234] //保压转换位置                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_HoldPresTiReal     WorkState[235] //保压转换时间                              实际
#define State_HoldPresTiLast     WorkState[236] //保压转换时间                              上一模
#define State_HoldPresTiOL       WorkState[237] //保压转换时间                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_HoldPresSPresReal   WorkState[238]//保压转换压力                              实际
#define State_HoldPresSPresLast   WorkState[239]//保压转换压力                              上一模
#define State_HoldPresSPresOL     WorkState[240]//保压转换压力                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_EjeForTiReal       WorkState[241] //托模时间                                实际
#define State_EjeForTiLast       WorkState[242] //托模时间                                上一模
#define State_EjeForTiOL         WorkState[243] //托模时间                                超限标志，B0-当前模  B1-上一模，为1超限
#define State_MoniDataState      WorkState[244] //监测数据状态                              B0-监测数据更新，该位取反(与模数变化相比，迟开关安全门、电眼检物或循环延迟时间，即略晚)
#define State_InjPeakPresReal    WorkState[245] //注射峰值压力                              实际
#define State_InjPeakPresLast    WorkState[246] //注射峰值压力                              上一模
#define State_InjPeakPresOL      WorkState[247] //注射峰值压力                              超限标志，B0-当前模  B1-上一模，为1超限
#define State_248                WorkState[248] //                                    
#define State_249                WorkState[249] //                                    
#define State_250                WorkState[250] //                                    
#define State_InjPeakPresStd     WorkState[251] //注射峰值 压力                             标准值
#define State_CycTiStd           WorkState[252] //循环时间                                标准值
#define State_MoldClsTiStd       WorkState[253] //关模时间                                标准值
#define State_MoldClsLPTiStd     WorkState[254] //关模低压时间                              标准值
#define State_MoldClsHPTiStd     WorkState[255] //关模高压时间                              标准值
#define State_MoldOpenTiStd      WorkState[256] //开模时间                                标准值
#define State_MoldOpenEPosStd    WorkState[257] //开模结束位置                              标准值
#define State_InjectTiStd        WorkState[258] //射出时间                                标准值
#define State_InjectEPosStd      WorkState[259] //射出结束位置                              标准值
#define State_InjectSpdStd       WorkState[260] //射出最高速度                              标准值
#define State_ChargeTiStd        WorkState[261] //储料时间                                标准值
#define State_ChargeEPosStd      WorkState[262] //储料结束位置                              标准值
#define State_ChargeRPMStd       WorkState[263] //储料最高转速                              标准值
#define State_SuckBackTiStd      WorkState[264] //射退时间                                标准值
#define State_HoldPresSPosStd    WorkState[265] //保压转换位置                              标准值
#define State_HoldPresTiStd      WorkState[266] //保压转换时间                              标准值
#define State_HoldPresSPresStd   WorkState[267] //保压转换压力                              标准值
#define State_EjeForTiStd        WorkState[268] //托模时间                                标准值
#define State_MoniStdDataUpdate  WorkState[269] //监测数据标准值更新                           0-不更新 1-更新到生产参数相应标准值
#define State_SDRdData_Info      WorkState[270] //驱动器读取数据的信息                          B15:1数据有效 B7-B4:驱动器号 B3-B0:数据长度(字节为单位)
#define State_SDRdData_Addr      WorkState[271] //驱动器读取数据的地址                          
#define State_SDRdData_DataL     WorkState[272] //驱动器读取数据的数据低字                        
#define State_SDRdData_DataH     WorkState[273] //驱动器读取数据的数据高字                        
#define State_SmallMotRPM        WorkState[274] //小电机转速                               
#define State_275                WorkState[275] //                                    
#define State_276                WorkState[276] //                                    
#define State_277                WorkState[277] //                                    
#define State_278                WorkState[278] //                                    
#define State_279                WorkState[279] //                                    
#define State_ParaGenl           WorkState[280] //开模参数自学习状态                           0-没有进行开模参数自学习 1-正在进行开模参数自学习
#define State_MODstPos           WorkState[281] //主机返回的开模目标位置                         
#define State_DAC1OutLim         WorkState[282] //DA通道1输出限值                           DA通道输出限值
#define State_DAC2OutLim         WorkState[283] //DA通道2输出限值                           DA通道输出限值
#define State_DAC3OutLim         WorkState[284] //DA通道3输出限值                           DA通道输出限值
#define State_DAC4OutLim         WorkState[285] //DA通道4输出限值                           DA通道输出限值
#define State_DAC5OutLim         WorkState[286] //DA通道5输出限值                           DA通道输出限值
#define State_DAC6OutLim         WorkState[287] //DA通道6输出限值                           DA通道输出限值
#define State_DAC7OutLim         WorkState[288] //DA通道7输出限值                           DA通道输出限值
#define State_DAC8OutLim         WorkState[289] //DA通道8输出限值                           DA通道输出限值
#define State_290                WorkState[290] //                                    
#define State_291                WorkState[291] //                                    
#define State_292                WorkState[292] //                                    
#define State_293                WorkState[293] //                                    
#define State_294                WorkState[294] //                                    
#define State_295                WorkState[295] //                                    
#define State_296                WorkState[296] //                                    
#define State_297                WorkState[297] //                                    
#define State_298                WorkState[298] //                                    
#define State_299                WorkState[299] //                                    
#define State_Power_TtlKWhLW     WorkState[300] //累计用电量                               电表测得累计用电量(低字)
#define State_Power_TtlKWhHW     WorkState[301] //累计用电量                               电表测得累计用电量(高字)
#define State_302                WorkState[302] //                                    
#define State_303                WorkState[303] //                                    
#define State_304                WorkState[304] //                                    
#define State_305                WorkState[305] //                                    
#define State_306                WorkState[306] //                                    
#define State_307                WorkState[307] //                                    
#define State_308                WorkState[308] //                                    
#define State_ZoneCoolProtRemTi  WorkState[309] //料筒防冷剩余时间                            
#define State_HtrTtlTimeSN       WorkState[310] //累计加热时间序号                            累计加热时间对应的通道号, 高字节对应HtrTtlTimeA、低字节对应HtrTTlTimeB
#define State_HtrTtlTimeA        WorkState[311] //加热累计时间                              电热x通道累计加热输出时间，x由HtrTtlTimeSN高字节给出
#define State_HtrTtlTimeB        WorkState[312] //加热累计时间                              电热x通道累计加热输出时间，x由HtrTtlTimeSN低字节给出
#define State_HtrTtlOnTime       WorkState[313] //电热累计开启时间                            电热累计开启时间
#define State_Lubr1NextUnitCnt   WorkState[314] //润滑1下次润滑模数                           
#define State_Lubr2NextUnitCnt   WorkState[315] //润滑2下次润滑模数                           
#define State_LubrCnt_1W         WorkState[316] //润滑计数到1万模标志                          0-未到1万模，1-到1万模，用于润滑参数管理模式为区分前后10000模时
#define State_HoldPresSnrVol     WorkState[317] //保压尺传感器电压                            
#define State_InjPeakPresUpLim   WorkState[318] //注射峰值压力                              上限
#define State_InjPeakPresLowLim  WorkState[319] //注射峰值压力                              下限
#define State_CycTiUpLim         WorkState[320] //循环时间                                上限
#define State_CycTiLowLim        WorkState[321] //循环时间                                下限
#define State_MoldClsTiUpLim     WorkState[322] //关模时间                                上限
#define State_MoldClsTiLowLim    WorkState[323] //关模时间                                下限
#define State_MoldClsLPTiUpLim   WorkState[324] //关模低压时间                              上限
#define State_MoldClsLPTiLowLim  WorkState[325] //关模低压时间                              下限
#define State_MoldClsHPTiUpLim   WorkState[326] //关模高压时间                              上限
#define State_MoldClsHPTiLowLim  WorkState[327] //关模高压时间                              下限
#define State_MoldOpenTiUpLim    WorkState[328] //开模时间                                上限
#define State_MoldOpenTiLowLim   WorkState[329] //开模时间                                下限
#define State_MoldOpenEPosUpLim  WorkState[330] //开模结束位置                              上限
#define State_MoldOpenEPosLowLim WorkState[331] //开模结束位置                              下限
#define State_InjectTiUpLim      WorkState[332] //射出时间                                上限
#define State_InjectTiLowLim     WorkState[333] //射出时间                                下限
#define State_InjectEPosUpLim    WorkState[334] //射出结束位置                              上限
#define State_InjectEPosLowLim   WorkState[335] //射出结束位置                              下限
#define State_InjectSpdUpLim     WorkState[336] //射出最高速度                              上限
#define State_InjectSpdLowLim    WorkState[337] //射出最高速度                              下限
#define State_ChargeTiUpLim      WorkState[338] //储料时间                                上限
#define State_ChargeTiLowLim     WorkState[339] //储料时间                                下限
#define State_ChargeEPosUpLim    WorkState[340] //储料结束位置                              上限
#define State_ChargeEPosLowLim   WorkState[341] //储料结束位置                              下限
#define State_ChargeRPMUpLim     WorkState[342] //储料最高转速                              上限
#define State_ChargeRPMLowLim    WorkState[343] //储料最高转速                              下限
#define State_SuckBackTiUpLim    WorkState[344] //射退时间                                上限
#define State_SuckBackTiLowLim   WorkState[345] //射退时间                                下限
#define State_HoldPresSPosUpLim  WorkState[346] //保压转换位置                              上限
#define State_HoldPresSPosLowLim WorkState[347] //保压转换位置                              下限
#define State_HoldPresTiUpLim    WorkState[348] //保压转换时间                              上限
#define State_HoldPresTiLowLim   WorkState[349] //保压转换时间                              下限
#define State_HoldPresSPresUpLim  WorkState[350]//保压转换压力                              上限
#define State_HoldPresSPresLowLim WorkState[351]//保压转换压力                              下限
#define State_EjeForTiUpLim      WorkState[352] //托模时间                                上限
#define State_EjeForTiLowLim     WorkState[353] //托模时间                                下限
#define State_MoldThickSnrVol    WorkState[354] //模厚传感器电压                             
#define State_CMPartSN_LW        WorkState[355] //主机器件流水号                             主机芯片的流水号（低字）
#define State_CMPartSN_HW        WorkState[356] //主机器件流水号                             主机芯片的流水号（高字）
#define State_CMAuthorized1_LW   WorkState[357] //主机授权1                               主机程序授权1（低字）,授权1为基本授权，无此授权禁止自动运行
#define State_CMAuthorized1_HW   WorkState[358] //主机授权1                               主机程序授权1（高字）,授权1为基本授权，无此授权禁止自动运行
#define State_CMAuthorized2_LW   WorkState[359] //主机授权2                               主机程序授权2（低字）,该授权暂保留
#define State_CMAuthorized2_HW   WorkState[360] //主机授权2                               主机程序授权2（高字）,该授权暂保留
#define State_ScrewSnrVol        WorkState[361] //螺杆传感器电压                             
#define State_MoldSnrVol         WorkState[362] //模板传感器电压                             
#define State_EjeSnrVol          WorkState[363] //顶针传感器电压                             
#define State_NozSnrVol          WorkState[364] //座台传感器电压                             
#define State_HAI1Vol            WorkState[365] //模拟量1电压                              
#define State_HAI2Vol            WorkState[366] //模拟量2电压                              
#define State_HAI3Vol            WorkState[367] //模拟量3电压                              
#define State_ZoneAccStaSN_A     WorkState[368] //料筒附加状态对应段号                          与下二项状态配合用，本状态指明对应段，其它的是段信息
#define State_ZoneHrtTime_A      WorkState[369] //某段加热时间                              
#define State_ZoneTemp01C_A      WorkState[370] //某段温度                                
#define State_ZoneAccStaSN_B     WorkState[371] //料筒附加状态对应段号                          用2组，原因是这部分状态刷新周期为0.5s，慢于温度更新速度
#define State_ZoneHrtTime_B      WorkState[372] //某段加热时间                              
#define State_ZoneTemp01C_B      WorkState[373] //某段温度                                
#define State_CMWorkShotCntLW    WorkState[374] //主机工作模数                              主机开机工作累计打产品模数(低字)，也用于标识一模完成
#define State_CMWorkShotCntHW    WorkState[375] //主机工作模数                              主机开机工作累计打产品模数(高字)
#define State_CMWorkTimeLW       WorkState[376] //主机工作时间                              主机开机工作累计时间（低字）
#define State_CMWorkTimeHW       WorkState[377] //主机工作时间                              主机开机工作累计时间(高字)
#define State_CMBootVer          WorkState[378] //主机Boot版本                            Boot程序中也用到，序号改变时要一起改
#define State_CMSoftLinkCode     WorkState[379] //主机软件互连代号                            
#define State_CMSoftSer          WorkState[380] //主机软件系列                              
#define State_CMSoftVer          WorkState[381] //主机软件版本                              
#define State_CMProdBatch        WorkState[382] //主机生产批号                              
#define State_CMProdSN           WorkState[383] //主机生产序号                              

#endif
