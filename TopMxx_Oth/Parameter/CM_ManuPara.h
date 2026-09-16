/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_ManuPara.h    生产参数文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0xDD17  
****************************************************************************************************/
#ifndef CM_ManuPara_h
    #define CM_ManuPara_h

#ifdef RPHA_c
    #define CM_ManuPara_ext
#else
    #define CM_ManuPara_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//生产参数数量
#define mManuParaNum 2048  //生产参数数量

//生产参数数组定义
CM_ManuPara_ext U32 ManuPara[mManuParaNum];      //生产参数数组

//生产参数序号宏定义
#define mPara_ManuParaSum        0              //累加和校验码                              辅助用，下述参数累加和
#define mPara_ManuParaLinkCode   1              //互连代码                                辅助用，生产参数互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效
#define mPara_ManuParaVer        2              //版本号                                 辅助用，生产参数版本号
#define mPara_ManuParaID         3              //标识                                  辅助用，用于售后维护
#define mPara_Manu_4             4              //                                    
#define mPara_MoldDataValid      5              //模具资料无效                              模具资料管理用，0-模具资料无效 1-有效
#define mPara_MoldNameC0         6              //模具名称字符0                             模具资料管理用
#define mPara_MoldNameC1         7              //模具名称字符1                             模具资料管理用
#define mPara_MoldNameC2         8              //模具名称字符2                             模具资料管理用
#define mPara_MoldNameC3         9              //模具名称字符3                             模具资料管理用
#define mPara_MoldNameC4         10             //模具名称字符4                             模具资料管理用
#define mPara_MoldNameC5         11             //模具名称字符5                             模具资料管理用
#define mPara_MoldNameC6         12             //模具名称字符6                             模具资料管理用
#define mPara_MoldNameC7         13             //模具名称字符7                             模具资料管理用
#define mPara_MoldNameC8         14             //模具名称字符8                             模具资料管理用
#define mPara_MoldNameC9         15             //模具名称字符9                             模具资料管理用
#define mPara_MoldNameC10        16             //模具名称字符10                            模具资料管理用
#define mPara_MoldNameC11        17             //模具名称字符11                            模具资料管理用
#define mPara_MaterialC0         18             //产品材料字符0                             模具资料管理用
#define mPara_MaterialC1         19             //产品材料字符1                             模具资料管理用
#define mPara_MaterialC2         20             //产品材料字符2                             模具资料管理用
#define mPara_MaterialC3         21             //产品材料字符3                             模具资料管理用
#define mPara_MaterialC4         22             //产品材料字符4                             模具资料管理用
#define mPara_MaterialC5         23             //产品材料字符5                             模具资料管理用
#define mPara_MaterialC6         24             //产品材料字符6                             模具资料管理用
#define mPara_MaterialC7         25             //产品材料字符7                             模具资料管理用
#define mPara_ColourC0           26             //产品颜色字符0                             模具资料管理用
#define mPara_ColourC1           27             //产品颜色字符1                             模具资料管理用
#define mPara_ColourC2           28             //产品颜色字符2                             模具资料管理用
#define mPara_ColourC3           29             //产品颜色字符3                             模具资料管理用
#define mPara_ColourC4           30             //产品颜色字符4                             模具资料管理用
#define mPara_ColourC5           31             //产品颜色字符5                             模具资料管理用
#define mPara_ColourC6           32             //产品颜色字符6                             模具资料管理用
#define mPara_ColourC7           33             //产品颜色字符7                             模具资料管理用
#define mPara_SaveDateC0         34             //保存日期字符0                             模具资料管理用
#define mPara_SaveDateC1         35             //保存日期字符1                             模具资料管理用
#define mPara_SaveDateC2         36             //保存日期字符2                             模具资料管理用
#define mPara_SaveDateC3         37             //保存日期字符3                             模具资料管理用
#define mPara_SaveDateC4         38             //保存日期字符4                             模具资料管理用
#define mPara_SaveDateC5         39             //保存日期字符5                             模具资料管理用
#define mPara_SaveDateC6         40             //保存日期字符6                             模具资料管理用
#define mPara_SaveDateC7         41             //保存日期字符7                             模具资料管理用
#define mPara_Manu_42            42             //                                    
#define mPara_Manu_43            43             //                                    
#define mPara_Manu_44            44             //                                    
#define mPara_Manu_45            45             //                                    
#define mPara_Manu_46            46             //                                    
#define mPara_Manu_47            47             //                                    
#define mPara_Manu_48            48             //                                    
#define mPara_Manu_49            49             //                                    
#define mPara_Manu_50            50             //                                    
#define mPara_Manu_51            51             //                                    
#define mPara_Manu_52            52             //                                    
#define mPara_Manu_53            53             //                                    
#define mPara_Manu_54            54             //                                    
#define mPara_Manu_55            55             //                                    
#define mPara_Manu_56            56             //                                    
#define mPara_Manu_57            57             //                                    
#define mPara_Manu_58            58             //                                    
#define mPara_Manu_59            59             //                                    
#define mPara_Manu_60            60             //                                    
#define mPara_Manu_61            61             //                                    
#define mPara_Manu_62            62             //                                    
#define mPara_Manu_63            63             //                                    
#define mPara_MoldCls1Pres       64             //关模一段压力                              
#define mPara_MoldCls1Flow       65             //关模一段流量                              
#define mPara_MoldCls2Pres       66             //关模二段压力                              
#define mPara_MoldCls2Flow       67             //关模二段流量                              
#define mPara_MoldCls2SPos       68             //关模二段起始位置                            
#define mPara_MoldCls3Pres       69             //关模三段压力                              根据机型选用
#define mPara_MoldCls3Flow       70             //关模三段流量                              根据机型选用
#define mPara_MoldCls3SPos       71             //关模三段起始位置                            根据机型选用
#define mPara_MoldClsLPPres      72             //关模低压压力                              
#define mPara_MoldClsLPFlow      73             //关模低压流量                              
#define mPara_MoldClsLPSPos      74             //关模低压起始位置                            
#define mPara_MoldClsHPPres      75             //关模高压压力                              
#define mPara_MoldClsHPFlow      76             //关模高压流量                              
#define mPara_MoldClsHPSPos      77             //关模高压起始位置                            画面可设0.01mm，用以提高模保精度
#define mPara_Manu_78            78             //                                    
#define mPara_MoldClsDiffSel     79             //关模差动选择                              0-不用 1-使用
#define mPara_MoldClsFastSel     80             //关模快速选择                              0-不用 1-使用
#define mPara_Manu_81            81             //                                    
#define mPara_Manu_82            82             //                                    
#define mPara_Manu_83            83             //                                    
#define mPara_MoldOpen1Pres      84             //开模一段压力                              
#define mPara_MoldOpen1Flow      85             //开模一段流量                              
#define mPara_MoldOpen2Pres      86             //开模二段压力                              
#define mPara_MoldOpen2Flow      87             //开模二段流量                              
#define mPara_MoldOpen2SPos      88             //开模二段起始位置                            
#define mPara_MoldOpen3Pres      89             //开模三段压力                              根据机型选用
#define mPara_MoldOpen3Flow      90             //开模三段流量                              根据机型选用
#define mPara_MoldOpen3SPos      91             //开模三段起始位置                            根据机型选用
#define mPara_MoldOpen4Pres      92             //开模四段压力                              
#define mPara_MoldOpen4Flow      93             //开模四段流量                              
#define mPara_MoldOpen4SPos      94             //开模四段起始位置                            
#define mPara_MoldOpen5Pres      95             //开模五段压力                              
#define mPara_MoldOpen5Flow      96             //开模五段流量                              
#define mPara_MoldOpen5SPos      97             //开模五段起始位置                            
#define mPara_MoldOpenEPos       98             //开模结束位置                              
#define mPara_MoldOpenDiffSel    99             //开模差动选择                              0-不用 1-二~四段 2-二~五段 3-一~五段
#define mPara_MoldOpenLinkSel    100            //开模连动选择                              0-不用 1-顶针 2-中子A 3-中子B 4-中子C
#define mPara_MoldOpenLinkPos    101            //开模连动位置                              中子连动时，连动位置用中子出芯位置
#define mPara_MoldOpenFastSel    102            //开模快速选择                              0-不用 1-使用
#define mPara_MOMedRobotStopTi   103            //开模中途取件停留时间                          欧规机械手，中途取件停留时间
#define mPara_MOMedRobotPos      104            //开模中途取件位置                            欧规机械手，中途取件时位置
#define mPara_MOMedRobotMode     105            //开模中途取件模式                            欧规机械手，中途取件时模式：0-不用 1-不停取物 2-PB控制停留 3-计时停留
#define mPara_MoldOpenMidEjeSel  106            //开模中途托模选择                            特殊程序：开模中途插入托模动作 0-关 1-开-托-开 2-开-托-开-托
#define mPara_MoldOpenMidEjePos  107            //开模中途托模位置                            特殊程序：开模中途插入托模动作
#define mPara_Inject1Pres        108            //注射一段压力                              
#define mPara_Inject1Flow        109            //注射一段流量                              
#define mPara_Inject2Pres        110            //注射二段压力                              
#define mPara_Inject2Flow        111            //注射二段流量                              
#define mPara_Inject2SPos        112            //注射二段起始位置                            
#define mPara_Inject3Pres        113            //注射三段压力                              
#define mPara_Inject3Flow        114            //注射三段流量                              
#define mPara_Inject3SPos        115            //注射三段起始位置                            
#define mPara_Inject4Pres        116            //注射四段压力                              
#define mPara_Inject4Flow        117            //注射四段流量                              
#define mPara_Inject4SPos        118            //注射四段起始位置                            
#define mPara_Inject5Pres        119            //注射五段压力                              
#define mPara_Inject5Flow        120            //注射五段流量                              
#define mPara_Inject5SPos        121            //注射五段起始位置                            
#define mPara_Inject6Pres        122            //注射六段压力                              
#define mPara_Inject6Flow        123            //注射六段流量                              
#define mPara_Inject6SPos        124            //注射六段起始位置                            
#define mPara_Inject7Pres        125            //注射七段压力                              
#define mPara_Inject7Flow        126            //注射七段流量                              
#define mPara_Inject7SPos        127            //注射七段起始位置                            
#define mPara_Inject8Pres        128            //注射八段压力                              
#define mPara_Inject8Flow        129            //注射八段流量                              
#define mPara_Inject8SPos        130            //注射八段起始位置                            
#define mPara_Inject9Pres        131            //注射九段压力                              
#define mPara_Inject9Flow        132            //注射九段流量                              
#define mPara_Inject9SPos        133            //注射九段起始位置                            
#define mPara_Inject10Pres       134            //注射十段压力                              
#define mPara_Inject10Flow       135            //注射十段流量                              
#define mPara_Inject10SPos       136            //注射十段起始位置                            
#define mPara_InjectEPos         137            //注射结束位置                              
#define mPara_InjectTi           138            //注射时间                                注射一～十段总时间
#define mPara_Manu_139           139            //                                    
#define mPara_Manu_140           140            //                                    
#define mPara_HoldPres1Pres      141            //保压一段压力                              
#define mPara_HoldPres1Flow      142            //保压一段流量                              
#define mPara_HoldPres1Ti        143            //保压一段时间                              
#define mPara_HoldPres2Pres      144            //保压二段压力                              
#define mPara_HoldPres2Flow      145            //保压二段流量                              
#define mPara_HoldPres2Ti        146            //保压二段时间                              
#define mPara_HoldPres3Pres      147            //保压三段压力                              
#define mPara_HoldPres3Flow      148            //保压三段流量                              
#define mPara_HoldPres3Ti        149            //保压三段时间                              
#define mPara_HoldPres4Pres      150            //保压四段压力                              
#define mPara_HoldPres4Flow      151            //保压四段流量                              
#define mPara_HoldPres4Ti        152            //保压四段时间                              
#define mPara_HoldPres5Pres      153            //保压五段压力                              
#define mPara_HoldPres5Flow      154            //保压五段流量                              
#define mPara_HoldPres5Ti        155            //保压五段时间                              
#define mPara_HoldPres6Pres      156            //保压六段压力                              
#define mPara_HoldPres6Flow      157            //保压六段流量                              
#define mPara_HoldPres6Ti        158            //保压六段时间                              
#define mPara_HoldPres7Pres      159            //保压七段压力                              
#define mPara_HoldPres7Flow      160            //保压七段流量                              
#define mPara_HoldPres7Ti        161            //保压七段时间                              
#define mPara_HoldPres8Pres      162            //保压八段压力                              
#define mPara_HoldPres8Flow      163            //保压八段流量                              
#define mPara_HoldPres8Ti        164            //保压八段时间                              
#define mPara_HoldPres9Pres      165            //保压九段压力                              
#define mPara_HoldPres9Flow      166            //保压九段流量                              
#define mPara_HoldPres9Ti        167            //保压九段时间                              
#define mPara_HoldPres10Pres     168            //保压十段压力                              
#define mPara_HoldPres10Flow     169            //保压十段流量                              
#define mPara_HoldPres10Ti       170            //保压十段时间                              
#define mPara_HoldPresSwtMode    171            //保压切换模式                              0-位置时间 1-时间 2-压力
#define mPara_HoldPresSwtPres    172            //保压切换压力                              
#define mPara_InjBefNozOffset    173            //座进前注射距离                             座台进前先用射一注射该距离
#define mPara_InjBefNozTi        174            //座进前注射计时                             座台进前先用射一注射该时间
#define mPara_InjFastSel         175            //射出快速功能                              0-不用 1-使用
#define mPara_AccSel             176            //射出增压功能                              即蓄能器使用选择，0-不用 1-使用
#define mPara_InjHPRelSel        177            //保压解压功能                              0-不用 1-使用，保压动作时“保压解压”阀也开
#define mPara_Manu_178           178            //                                    
#define mPara_Manu_179           179            //                                    
#define mPara_Manu_180           180            //                                    
#define mPara_ChargeLink         181            //储料连动选择                              
#define mPara_Charge1Pres        182            //储料一段压力                              
#define mPara_Charge1Flow        183            //储料一段流量                              
#define mPara_Charge1BPres       184            //储料一段背压                              实际上限为40或60
#define mPara_Charge2Pres        185            //储料二段压力                              
#define mPara_Charge2Flow        186            //储料二段流量                              
#define mPara_Charge2BPres       187            //储料二段背压                              
#define mPara_Charge2SPos        188            //储料二段起始位置                            
#define mPara_Charge3Pres        189            //储料三段压力                              
#define mPara_Charge3Flow        190            //储料三段流量                              
#define mPara_Charge3BPres       191            //储料三段背压                              
#define mPara_Charge3SPos        192            //储料三段起始位置                            
#define mPara_Charge4Pres        193            //储料四段压力                              
#define mPara_Charge4Flow        194            //储料四段流量                              
#define mPara_Charge4BPres       195            //储料四段背压                              
#define mPara_Charge4SPos        196            //储料四段起始位置                            
#define mPara_Charge5Pres        197            //储料五段压力                              
#define mPara_Charge5Flow        198            //储料五段流量                              
#define mPara_Charge5BPres       199            //储料五段背压                              
#define mPara_Charge5SPos        200            //储料五段起始位置                            
#define mPara_Charge6Pres        201            //储料六段压力                              
#define mPara_Charge6Flow        202            //储料六段流量                              
#define mPara_Charge6BPres       203            //储料六段背压                              
#define mPara_Charge6SPos        204            //储料六段起始位置                            
#define mPara_Charge7Pres        205            //储料七段压力                              
#define mPara_Charge7Flow        206            //储料七段流量                              
#define mPara_Charge7BPres       207            //储料七段背压                              
#define mPara_Charge7SPos        208            //储料七段起始位置                            
#define mPara_Charge8Pres        209            //储料八段压力                              
#define mPara_Charge8Flow        210            //储料八段流量                              
#define mPara_Charge8BPres       211            //储料八段背压                              
#define mPara_Charge8SPos        212            //储料八段起始位置                            
#define mPara_Charge9Pres        213            //储料九段压力                              
#define mPara_Charge9Flow        214            //储料九段流量                              
#define mPara_Charge9BPres       215            //储料九段背压                              
#define mPara_Charge9SPos        216            //储料九段起始位置                            
#define mPara_Charge10Pres       217            //储料十段压力                              
#define mPara_Charge10Flow       218            //储料十段流量                              
#define mPara_Charge10BPres      219            //储料十段背压                              
#define mPara_Charge10SPos       220            //储料十段起始位置                            
#define mPara_ChargeEPos         221            //储料结束位置                              
#define mPara_Manu_222           222            //                                    
#define mPara_ProdCoolTi         223            //模具冷却时间                              即产品冷却时间，从保压结束后开始计时
#define mPara_CoolBefChgTi       224            //储前冷却时间                              
#define mPara_ReChgCtrlMode      225            //再次储料控制模式                            0-位置 1-时间
#define mPara_ReChgEPos          226            //再次储料结束位置                            
#define mPara_ReChgTi            227            //再次储料时间                              
#define mPara_ChgBackPresValSel  228            //储料背压阀                               0-不用 1-使用，用于实现储料零背压 2-自动时使用
#define mPara_SemiAutoChgAftEjeMode 229         //半自动二次储料模式                           0-关闭 1-时间 2-位置，半自动时储料分二次进行，冷却期间一次、顶出后再次（利用开关门的时间）
#define mPara_SemiAutoChgFirstTi 230            //半自动二次储料首次时间                         
#define mPara_SemiAutoChgFirstPos 231           //半自动二次储料首次位置                         
#define mPara_SuckBackPres       232            //射退压力                                
#define mPara_SuckBackFlow       233            //射退流量                                
#define mPara_SuckBackTi         234            //射退时间                                
#define mPara_SuckBackOffset     235            //射退距离                                为相对位置，限值：行程-储料终止位置
#define mPara_SuckBackCtrlMode   236            //射退控制方式                              0-位置 1-时间
#define mPara_SuckBackOcc        237            //射退时机                                0-储后 1-冷后
#define mPara_EjeForPauseOcc     238            //托模暂停时机                              0-托模一段暂停	1-1次托进完	2-2次托进完	3-1次托退完	4-2次托退完
#define mPara_SBBefChgOffset     239            //储料前射退距离                             为相对位置，限值：行程-储料终止位置
#define mPara_SBBefChgTi         240            //储料前射退时间                             
#define mPara_SBBefChgCtrlMode   241            //储前射退控制方式                            0-位置 1-时间
#define mPara_EjeFor1PauseTi     242            //托进一段暂停时间                            应制笔模具：托进一段、停顿该时间(等机械手)、再托进二段(机械手一起前进)
#define mPara_EjeFor2StepSel     243            //二级托模进选择                             特殊托模：托进分二次完成，避免产品顶出太快。（第一次顶进到一段结束，第二次才顶到位）
#define mPara_EjeCutMatDly       244            //托模切料延时                              
#define mPara_EjeCutMatRetPres   245            //托模切料退压力                             
#define mPara_EjeCutMatRetFlow   246            //托模切料退流量                             
#define mPara_EjeFor1Pres        247            //托进一段压力                              
#define mPara_EjeFor1Flow        248            //托进一段流量                              
#define mPara_EjeFor2Pres        249            //托进二段压力                              
#define mPara_EjeFor2Flow        250            //托进二段流量                              
#define mPara_EjeFor2SPos        251            //托进二段起始位置                            
#define mPara_EjeForEPos         252            //托进结束位置                              
#define mPara_EjeRet1Pres        253            //托退一段压力                              
#define mPara_EjeRet1Flow        254            //托退一段流量                              
#define mPara_EjeRet2Pres        255            //托退二段压力                              
#define mPara_EjeRet2Flow        256            //托退二段流量                              
#define mPara_EjeRet2SPos        257            //托退二段起始位置                            
#define mPara_EjeRetEPos         258            //托退结束位置                              
#define mPara_EjeForDly          259            //托进延时时间                              托进前延时
#define mPara_EjeRetDly          260            //托退延时时间                              托退前延时
#define mPara_EjectMode          261            //托模方式                                0-不用 1-停留 2-定次 3-震动
#define mPara_EjectCnt           262            //托模次数                                
#define mPara_ReEjeSel           263            //再次托模选择                              0-不用 1-使用
#define mPara_EjeRetMode         264            //托退模式                                0-标准 1-二段托退(特殊托退：退到托退一即结束) 2-不托退(特殊托退：类似停留，但允许自动方式)
#define mPara_ProdSnrSel         265            //电眼检出功能                              即电眼方式选择，0-不用 1-使用
#define mPara_RobotSel           266            //机械手选择                               0-不用 1-使用
#define mPara_AutoCycDly         267            //再循环延时                               
#define mPara_AutoGateSel        268            //自动安全门选择                             0-不用 1-使用
#define mPara_HydNozSel          269            //液压喷嘴使用                              0-不用 1-使用
#define mPara_DisAutoMode        270            //禁止全自动模式                             0-允许 1-禁止，如果禁止，则只允许半自动，保护特殊模具
#define mPara_SMMOAutoGateLinkSel 271           //半自动开模时自动门连动                         0-不连动、1-连动、2-开模后连动
#define mPara_AMoldShotNum       272            //每模产品数                               
#define mPara_PackageNum         273            //包装产品数                               
#define mPara_DstShotNum         274            //生产产品数                               模数*每模产品数
#define mPara_EjeStepMode        275            //逐步托模模式                              0-不用、1-使用。托模阻力很大的模具，分多次逐步顶进。即托进到顶针不会前进了，退回再次托进。
#define mPara_EjeCutMatSel       276            //托模切料功能选择                            0-关闭,1-注射后,2-保一后,3-保二后,4-保压后,5-保压时(即保压时托模阀ON，压力流量同保压)
#define mPara_EjeCutMatPres      277            //托模切料压力                              
#define mPara_EjeCutMatFlow      278            //托模切料流量                              
#define mPara_EjeCutMatEPos      279            //托模切料位置                              结束位置
#define mPara_EjeCutMatMode      280            //托模切料模式                              0-只托进 1-托进后托退
#define mPara_NozFor1Pres        281            //座进一段压力                              
#define mPara_NozFor1Flow        282            //座进一段流量                              
#define mPara_NozFor2Pres        283            //座进二段压力                              
#define mPara_NozFor2Flow        284            //座进二段流量                              
#define mPara_NozFor2SPos        285            //座进二段起始位置                            
#define mPara_NozForEPos         286            //座进结束位置                              
#define mPara_NozForSlowPres     287            //座进慢速压力                              
#define mPara_NozForSlowFlow     288            //座进慢速流量                              
#define mPara_NozForSlowTi       289            //座进慢速时间                              
#define mPara_NozRet1Pres        290            //座退一段压力                              
#define mPara_NozRet1Flow        291            //座退一段流量                              
#define mPara_NozRet2Pres        292            //座退二段压力                              
#define mPara_NozRet2Flow        293            //座退二段流量                              
#define mPara_NozRet2SPos        294            //座退二段起始位置                            
#define mPara_NozRetEPos         295            //座退结束位置                              
#define mPara_NozRetTi           296            //座退时间                                
#define mPara_NozRetDly          297            //座退延时                                
#define mPara_NozRetMode         298            //座退模式                                0-不用 1-储后 2-开模前 3-射后
#define mPara_NozRetCtrlMode     299            //座退控制模式                              0-时间 1-位置
#define mPara_Manu_300           300            //                                    
#define mPara_Manu_301           301            //                                    
#define mPara_MoldThinPres       302            //调模进压力                               
#define mPara_MoldThinFlow       303            //调模进流量                               
#define mPara_MoldThickPres      304            //调模退压力                               
#define mPara_MoldThickFlow      305            //调模退流量                               
#define mPara_MoldAdjSlowFlow    306            //调模慢速流量                              
#define mPara_MoldThickSet       307            //设置模厚                                装配模厚尺时，设置模厚
#define mPara_Manu_308           308            //                                    
#define mPara_Manu_309           309            //                                    
#define mPara_Air1Ti             310            //A组吹气时间                              
#define mPara_Air1Dly            311            //A组吹气延迟时间                            
#define mPara_Air1SPos           312            //A组吹气起始位置                            
#define mPara_Air2Ti             313            //B组吹气时间                              
#define mPara_Air2Dly            314            //B组吹气延迟时间                            
#define mPara_Air2SPos           315            //B组吹气起始位置                            
#define mPara_Air3Ti             316            //C组吹气时间                              
#define mPara_Air3Dly            317            //C组吹气延迟时间                            
#define mPara_Air3SPos           318            //C组吹气起始位置                            
#define mPara_Air4Ti             319            //D组吹气时间                              
#define mPara_Air4Dly            320            //D组吹气延迟时间                            
#define mPara_Air4SPos           321            //D组吹气起始位置                            
#define mPara_Air5Ti             322            //E组吹气时间                              
#define mPara_Air5Dly            323            //E组吹气延迟时间                            
#define mPara_Air5SPos           324            //E组吹气起始位置                            
#define mPara_Air6Ti             325            //F组吹气时间                              
#define mPara_Air6Dly            326            //F组吹气延迟时间                            
#define mPara_Air6SPos           327            //F组吹气起始位置                            
#define mPara_Air1KeySel         328            //吹气1键选择                              0-吹气1   1-吹气3   2-吹气4
#define mPara_Air2KeySel         329            //吹气2键选择                              0-吹气2   1-吹气4   2-吹气5
#define mPara_Air6Occ            330            //F组吹气时机                              0-正常 1-储料
#define mPara_Manu_331           331            //                                    
#define mPara_Manu_332           332            //                                    
#define mPara_AirInjSPos         333            //气辅射出起始位置                            
#define mPara_AirInjTi           334            //气辅射出时间                              
#define mPara_InjCompMode        335            //压缩注射模式                              压缩注射模式:合模到设定位置－注射－继续合模
#define mPara_InjCompMoldPos     336            //压缩注射模板位置                            压缩注射时合模到该位置结束合模，进行注射，然后合模。
#define mPara_InjCompInjEPos     337            //压缩注射注射结束位置                          压缩注射时注射到该位置结束，然后合模。如果该位置=保压位置，则继续注射时直接转保压。
#define mPara_ExhMode            338            //排气模式                                0-不用 1-射后 2-保一后 3-保二后 4-保压后 5-注射中
#define mPara_ExhHoldTi          339            //排气后延时                               排气保持时间
#define mPara_ExhDly             340            //排气前延时                               经该延时后开始排气开模
#define mPara_ExhMoldOpenEPos    341            //排气开模位置                              排气开模结束位置
#define mPara_ExhMoldOpenTi      342            //排气开模时间                              排气开模的时间
#define mPara_ExhInjSPos1        343            //注射排气位置1                             注射排气起始位置1，注射中排气使用
#define mPara_ExhInjSPos2        344            //注射排气位置2                             注射排气起始位置2，注射中排气使用
#define mPara_PrgChgPres         345            //清料储料压力                              
#define mPara_PrgChgFlow         346            //清料储料流量                              
#define mPara_PrgChgTi           347            //清料储料时间                              
#define mPara_PrgInjPres         348            //清料注射压力                              
#define mPara_PrgInjFlow         349            //清料注射流量                              
#define mPara_PrgInjTi           350            //清料注射时间                              
#define mPara_PrgSuckPres        351            //清料射退压力                              
#define mPara_PrgSuckFlow        352            //清料射退流量                              
#define mPara_PrgSuckTi          353            //清料射退时间                              
#define mPara_PurgeSel           354            //清料功能选择                              0-不用 1-使用
#define mPara_PurgeCnt           355            //清料次数                                清料动作循环的次数，时间或次数到结束清料
#define mPara_PurgeTi            356            //清料时间                                清料动作的总时间，时间或次数到结束清料
#define mPara_Manu_357           357            //                                    
#define mPara_BMCMode            358            //BMC模式                               0-关闭、1-使用
#define mPara_BMC_FeedInPres     359            //加料进压力                               BMC机器
#define mPara_BMC_FeedInFlow     360            //加料进流量                               BMC机器
#define mPara_BMC_FeedOutPres    361            //加料退压力                               BMC机器
#define mPara_BMC_FeedOutFlow    362            //加料退流量                               BMC机器
#define mPara_SteamInjMode       363            //蒸汽注射模式                              0-关闭、1-使用
#define mPara_SteamHtrOnDly      364            //蒸汽加热开延时                             蒸汽注射
#define mPara_SteamCoolOnDly     365            //蒸汽冷却开延时                             蒸汽注射
#define mPara_SteamCoolOffDly    366            //蒸汽冷却关延时                             蒸汽注射
#define mPara_Manu_367           367            //                                    
#define mPara_Manu_368           368            //                                    
#define mPara_Manu_369           369            //                                    
#define mPara_Zone1HtrCtrlMode   370            //一段加热控温模式                            0-自动 1-比例
#define mPara_Zone1HtrPeriod     371            //一段加热周期                              
#define mPara_Zone1HtrPercent    372            //一段加热比例                              
#define mPara_Zone1SetTemp       373            //一段设置温度                              
#define mPara_Zone2SetTemp       374            //二段设置温度                              
#define mPara_Zone3SetTemp       375            //三段设置温度                              
#define mPara_Zone4SetTemp       376            //四段设置温度                              
#define mPara_Zone5SetTemp       377            //五段设置温度                              
#define mPara_Zone6SetTemp       378            //六段设置温度                              
#define mPara_Zone7SetTemp       379            //七段设置温度                              
#define mPara_Zone8SetTemp       380            //八段设置温度                              
#define mPara_Zone9SetTemp       381            //九段设置温度                              
#define mPara_Zone10SetTemp      382            //十段设置温度                              
#define mPara_Zone11SetTemp      383            //十一段设置温度                             
#define mPara_Zone12SetTemp      384            //十二段设置温度                             
#define mPara_Zone13SetTemp      385            //十三段设置温度                             
#define mPara_Zone14SetTemp      386            //十四段设置温度                             
#define mPara_Zone15SetTemp      387            //十五段设置温度                             
#define mPara_Zone16SetTemp      388            //十六段设置温度                             
#define mPara_Manu_389           389            //                                    
#define mPara_Manu_390           390            //                                    
#define mPara_Manu_391           391            //                                    
#define mPara_Manu_392           392            //                                    
#define mPara_Manu_393           393            //                                    
#define mPara_Manu_394           394            //                                    
#define mPara_Manu_395           395            //                                    
#define mPara_Manu_396           396            //                                    
#define mPara_Manu_397           397            //                                    
#define mPara_Manu_398           398            //                                    
#define mPara_Manu_399           399            //                                    
#define mPara_Manu_400           400            //                                    
#define mPara_Manu_401           401            //                                    
#define mPara_Manu_402           402            //                                    
#define mPara_Manu_403           403            //                                    
#define mPara_Manu_404           404            //                                    
#define mPara_Manu_405           405            //                                    
#define mPara_Manu_406           406            //                                    
#define mPara_Manu_407           407            //                                    
#define mPara_Manu_408           408            //                                    
#define mPara_Manu_409           409            //                                    
#define mPara_KeepWarmSel        410            //保温选择                                0-不用 1-使用
#define mPara_KeepWarmTemp       411            //保温温度                                
#define mPara_ZoneCoolProtTi     412            //防冷启动时间                              各段温度进入偏差范围后开始此计时
#define mPara_Manu_413           413            //                                    
#define mPara_Manu_414           414            //                                    
#define mPara_Manu_415           415            //                                    
#define mPara_ProdSnr1Sel        416            //检物电眼1使用                             0-不用 1使用
#define mPara_ProdSnr2Sel        417            //检物电眼2使用                             0-不用 1使用
#define mPara_ProdSnr3Sel        418            //检物电眼3使用                             0-不用 1使用
#define mPara_ProdSnr4Sel        419            //检物电眼4使用                             0-不用 1使用
#define mPara_Manu_420           420            //                                    
#define mPara_Manu_421           421            //                                    
#define mPara_RobotCoreSel       422            //配合机械手中子                             0-不用 1-中子A 2-中子B
#define mPara_Manu_423           423            //                                    
#define mPara_CoreSpecFunCode    424            //特殊中子代码                              0-标准 1-A:托-出 3-A:托-出-入 5-A:出-入 7-AB:托-出 8-A:注射-入芯 9-B:注射-入芯 10-B:托-出-取-入
#define mPara_CoreSpecPara1      425            //特殊中子参数一                             通常用于时间
#define mPara_CoreSpecPara2      426            //特殊中子参数二                             通常用于时间
#define mPara_Manu_427           427            //                                    
#define mPara_Core3KeySel        428            //中子C键选择                              中子C进、退键对应的中子号：0-中子C  1-中子D
#define mPara_ScrewEndSlowCnt    429            //绞牙结束前慢速齿数                           绞牙结束前，以慢速绞牙该计数
#define mPara_ScrewSlowFlow      430            //绞牙慢速流量                              慢速绞牙时流量
#define mPara_Manu_431           431            //                                    
#define mPara_CoreInSeq1         432            //第1个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq2         433            //第2个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq3         434            //第3个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq4         435            //第4个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq5         436            //第5个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq6         437            //第6个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq7         438            //第7个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_CoreInSeq8         439            //第8个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define mPara_Manu_440           440            //                                    
#define mPara_Manu_441           441            //                                    
#define mPara_CoreOutSeq1        442            //第1个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq2        443            //第2个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq3        444            //第3个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq4        445            //第4个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq5        446            //第5个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq6        447            //第6个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq7        448            //第7个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_CoreOutSeq8        449            //第8个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define mPara_Manu_450           450            //                                    
#define mPara_Manu_451           451            //                                    
#define mPara_Core1Fun           452            //中子1功能                               0-不用 1-中子 2-绞牙
#define mPara_Core1InjHold       453            //中子1注射保持                             0-不保持 1-保持
#define mPara_Core1Reverse       454            //中子1反向                               0-不用 1-使用
#define mPara_Manu_455           455            //                                    
#define mPara_Manu_456           456            //                                    
#define mPara_Core1InOcc         457            //中子1进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core1InCtrlMode    458            //中子1进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core1InPres        459            //中子1进压力                              
#define mPara_Core1InFlow        460            //中子1进流量                              
#define mPara_Core1InTi          461            //中子1进时间                              
#define mPara_Core1InCnt         462            //中子1进计数                              
#define mPara_Core1InSPos        463            //中子1进起始位置                            
#define mPara_Core1InStartDly    464            //中子1进前延时                             
#define mPara_Manu_465           465            //                                    
#define mPara_Core1OutOcc        466            //中子1出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core1OutCtrlMode   467            //中子1出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core1OutPres       468            //中子1出压力                              
#define mPara_Core1OutFlow       469            //中子1出流量                              
#define mPara_Core1OutTi         470            //中子1出时间                              
#define mPara_Core1OutCnt        471            //中子1出计数                              
#define mPara_Core1OutSPos       472            //中子1出起始位置                            
#define mPara_Core1OutECnt       473            //中子1退二计数                             
#define mPara_Core1OutETi        474            //中子1退二计时                             
#define mPara_Core1OutStartDly   475            //中子1退前延时                             
#define mPara_Manu_476           476            //                                    
#define mPara_Manu_477           477            //                                    
#define mPara_Core2Fun           478            //中子2功能                               0-不用 1-中子 2-绞牙
#define mPara_Core2InjHold       479            //中子2注射保持                             0-不保持 1-保持
#define mPara_Core2Reverse       480            //中子2反向                               0-不用 1-使用
#define mPara_Manu_481           481            //                                    
#define mPara_Manu_482           482            //                                    
#define mPara_Core2InOcc         483            //中子2进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core2InCtrlMode    484            //中子2进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core2InPres        485            //中子2进压力                              
#define mPara_Core2InFlow        486            //中子2进流量                              
#define mPara_Core2InTi          487            //中子2进时间                              
#define mPara_Core2InCnt         488            //中子2进计数                              
#define mPara_Core2InSPos        489            //中子2进起始位置                            
#define mPara_Core2InStartDly    490            //中子2进前延时                             
#define mPara_Manu_491           491            //                                    
#define mPara_Core2OutOcc        492            //中子2出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core2OutCtrlMode   493            //中子2出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core2OutPres       494            //中子2出压力                              
#define mPara_Core2OutFlow       495            //中子2出流量                              
#define mPara_Core2OutTi         496            //中子2出时间                              
#define mPara_Core2OutCnt        497            //中子2出计数                              
#define mPara_Core2OutSPos       498            //中子2出起始位置                            
#define mPara_Core2OutStartDly   499            //中子2退前延时                             
#define mPara_Manu_500           500            //                                    
#define mPara_Manu_501           501            //                                    
#define mPara_Manu_502           502            //                                    
#define mPara_Core3Fun           503            //中子3功能                               0-不用 1-中子 2-绞牙
#define mPara_Core3InjHold       504            //中子3注射保持                             0-不保持 1-保持
#define mPara_Core3Reverse       505            //中子3反向                               0-不用 1-使用
#define mPara_Manu_506           506            //                                    
#define mPara_Manu_507           507            //                                    
#define mPara_Core3InOcc         508            //中子3进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core3InCtrlMode    509            //中子3进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core3InPres        510            //中子3进压力                              
#define mPara_Core3InFlow        511            //中子3进流量                              
#define mPara_Core3InTi          512            //中子3进时间                              
#define mPara_Core3InCnt         513            //中子3进计数                              
#define mPara_Core3InSPos        514            //中子3进起始位置                            
#define mPara_Core3InStartDly    515            //中子3进前延时                             
#define mPara_Manu_516           516            //                                    
#define mPara_Core3OutOcc        517            //中子3出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core3OutCtrlMode   518            //中子3出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core3OutPres       519            //中子3出压力                              
#define mPara_Core3OutFlow       520            //中子3出流量                              
#define mPara_Core3OutTi         521            //中子3出时间                              
#define mPara_Core3OutCnt        522            //中子3出计数                              
#define mPara_Core3OutSPos       523            //中子3出起始位置                            
#define mPara_Core3OutStartDly   524            //中子3退前延时                             
#define mPara_Manu_525           525            //                                    
#define mPara_Manu_526           526            //                                    
#define mPara_Manu_527           527            //                                    
#define mPara_Core4Fun           528            //中子4功能                               0-不用 1-中子 2-绞牙
#define mPara_Core4InjHold       529            //中子4注射保持                             0-不保持 1-保持
#define mPara_Core4Reverse       530            //中子4反向                               0-不用 1-使用
#define mPara_Manu_531           531            //                                    
#define mPara_Manu_532           532            //                                    
#define mPara_Core4InOcc         533            //中子4进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core4InCtrlMode    534            //中子4进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core4InPres        535            //中子4进压力                              
#define mPara_Core4InFlow        536            //中子4进流量                              
#define mPara_Core4InTi          537            //中子4进时间                              
#define mPara_Core4InCnt         538            //中子4进计数                              
#define mPara_Core4InSPos        539            //中子4进起始位置                            
#define mPara_Core4InStartDly    540            //中子4进前延时                             
#define mPara_Manu_541           541            //                                    
#define mPara_Core4OutOcc        542            //中子4出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core4OutCtrlMode   543            //中子4出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core4OutPres       544            //中子4出压力                              
#define mPara_Core4OutFlow       545            //中子4出流量                              
#define mPara_Core4OutTi         546            //中子4出时间                              
#define mPara_Core4OutCnt        547            //中子4出计数                              
#define mPara_Core4OutSPos       548            //中子4出起始位置                            
#define mPara_Core4OutStartDly   549            //中子4退前延时                             
#define mPara_Manu_550           550            //                                    
#define mPara_Manu_551           551            //                                    
#define mPara_Manu_552           552            //                                    
#define mPara_Core5Fun           553            //中子5功能                               0-不用 1-中子 2-绞牙
#define mPara_Core5InjHold       554            //中子5注射保持                             0-不保持 1-保持
#define mPara_Core5Reverse       555            //中子5反向                               0-不用 1-使用
#define mPara_Manu_556           556            //                                    
#define mPara_Manu_557           557            //                                    
#define mPara_Core5InOcc         558            //中子5进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core5InCtrlMode    559            //中子5进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core5InPres        560            //中子5进压力                              
#define mPara_Core5InFlow        561            //中子5进流量                              
#define mPara_Core5InTi          562            //中子5进时间                              
#define mPara_Core5InCnt         563            //中子5进计数                              
#define mPara_Core5InSPos        564            //中子5进起始位置                            
#define mPara_Core5InStartDly    565            //中子5进前延时                             
#define mPara_Manu_566           566            //                                    
#define mPara_Core5OutOcc        567            //中子5出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core5OutCtrlMode   568            //中子5出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core5OutPres       569            //中子5出压力                              
#define mPara_Core5OutFlow       570            //中子5出流量                              
#define mPara_Core5OutTi         571            //中子5出时间                              
#define mPara_Core5OutCnt        572            //中子5出计数                              
#define mPara_Core5OutSPos       573            //中子5出起始位置                            
#define mPara_Core5OutStartDly   574            //中子5退前延时                             
#define mPara_Manu_575           575            //                                    
#define mPara_Manu_576           576            //                                    
#define mPara_Manu_577           577            //                                    
#define mPara_Core6Fun           578            //中子6功能                               0-不用 1-中子 2-绞牙
#define mPara_Core6InjHold       579            //中子6注射保持                             0-不保持 1-保持
#define mPara_Core6Reverse       580            //中子6反向                               0-不用 1-使用
#define mPara_Manu_581           581            //                                    
#define mPara_Manu_582           582            //                                    
#define mPara_Core6InOcc         583            //中子6进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core6InCtrlMode    584            //中子6进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core6InPres        585            //中子6进压力                              
#define mPara_Core6InFlow        586            //中子6进流量                              
#define mPara_Core6InTi          587            //中子6进时间                              
#define mPara_Core6InCnt         588            //中子6进计数                              
#define mPara_Core6InSPos        589            //中子6进起始位置                            
#define mPara_Core6InStartDly    590            //中子6进前延时                             
#define mPara_Manu_591           591            //                                    
#define mPara_Core6OutOcc        592            //中子6出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core6OutCtrlMode   593            //中子6出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core6OutPres       594            //中子6出压力                              
#define mPara_Core6OutFlow       595            //中子6出流量                              
#define mPara_Core6OutTi         596            //中子6出时间                              
#define mPara_Core6OutCnt        597            //中子6出计数                              
#define mPara_Core6OutSPos       598            //中子6出起始位置                            
#define mPara_Core6OutStartDly   599            //中子6退前延时                             
#define mPara_Manu_600           600            //                                    
#define mPara_Manu_601           601            //                                    
#define mPara_Manu_602           602            //                                    
#define mPara_Core7Fun           603            //中子7功能                               0-不用 1-中子 2-绞牙
#define mPara_Core7InjHold       604            //中子7注射保持                             0-不保持 1-保持
#define mPara_Core7Reverse       605            //中子7反向                               0-不用 1-使用
#define mPara_Manu_606           606            //                                    
#define mPara_Manu_607           607            //                                    
#define mPara_Core7InOcc         608            //中子7进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core7InCtrlMode    609            //中子7进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core7InPres        610            //中子7进压力                              
#define mPara_Core7InFlow        611            //中子7进流量                              
#define mPara_Core7InTi          612            //中子7进时间                              
#define mPara_Core7InCnt         613            //中子7进计数                              
#define mPara_Core7InSPos        614            //中子7进起始位置                            
#define mPara_Core7InStartDly    615            //中子7进前延时                             
#define mPara_Manu_616           616            //                                    
#define mPara_Core7OutOcc        617            //中子7出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core7OutCtrlMode   618            //中子7出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core7OutPres       619            //中子7出压力                              
#define mPara_Core7OutFlow       620            //中子7出流量                              
#define mPara_Core7OutTi         621            //中子7出时间                              
#define mPara_Core7OutCnt        622            //中子7出计数                              
#define mPara_Core7OutSPos       623            //中子7出起始位置                            
#define mPara_Core7OutStartDly   624            //中子7退前延时                             
#define mPara_Manu_625           625            //                                    
#define mPara_Manu_626           626            //                                    
#define mPara_Manu_627           627            //                                    
#define mPara_Core8Fun           628            //中子8功能                               0-不用 1-中子 2-绞牙
#define mPara_Core8InjHold       629            //中子8注射保持                             0-不保持 1-保持
#define mPara_Core8Reverse       630            //中子8反向                               0-不用 1-使用
#define mPara_Manu_631           631            //                                    
#define mPara_Manu_632           632            //                                    
#define mPara_Core8InOcc         633            //中子8进时机                              0-关模前 1-中途 2-关模后 
#define mPara_Core8InCtrlMode    634            //中子8进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core8InPres        635            //中子8进压力                              
#define mPara_Core8InFlow        636            //中子8进流量                              
#define mPara_Core8InTi          637            //中子8进时间                              
#define mPara_Core8InCnt         638            //中子8进计数                              
#define mPara_Core8InSPos        639            //中子8进起始位置                            
#define mPara_Core8InStartDly    640            //中子8进前延时                             
#define mPara_Manu_641           641            //                                    
#define mPara_Core8OutOcc        642            //中子8出时机                              0-开模前 1-中途 2-开模后 
#define mPara_Core8OutCtrlMode   643            //中子8出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define mPara_Core8OutPres       644            //中子8出压力                              
#define mPara_Core8OutFlow       645            //中子8出流量                              
#define mPara_Core8OutTi         646            //中子8出时间                              
#define mPara_Core8OutCnt        647            //中子8出计数                              
#define mPara_Core8OutSPos       648            //中子8出起始位置                            
#define mPara_Core8OutStartDly   649            //中子8退前延时                             
#define mPara_Manu_650           650            //                                    
#define mPara_Manu_651           651            //                                    
#define mPara_Manu_652           652            //                                    
#define mPara_Manu_653           653            //                                    
#define mPara_Manu_654           654            //                                    
#define mPara_CoreOutMoldOpenTi  655            //出芯开模时间                              海天北化眼镜脚套机专用：开模中途出芯,但动作位置采用时间控制
#define mPara_CoreOutMoldOpenPosMode 656        //出芯开模方式                              海天北化眼镜脚套机专用：开模出芯的动作位置选择使用模板位置或油缸位置 0-模板 1-油缸
#define mPara_InjCoreInLinkDly   657            //注射入芯连动延时                            海天北化眼镜脚套机专用：特殊中子 A:注射-入芯连动 时，延时该时间再入芯连动
#define mPara_Manu_658           658            //                                    
#define mPara_Manu_659           659            //                                    
#define mPara_POut1OnOcc         660            //自由输出点1ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut2OnOcc         661            //自由输出点2ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut3OnOcc         662            //自由输出点3ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut4OnOcc         663            //自由输出点4ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut1OffOcc        664            //自由输出点1OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut2OffOcc        665            //自由输出点2OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut3OffOcc        666            //自由输出点3OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut4OffOcc        667            //自由输出点4OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define mPara_POut1OnDly         668            //自由输出点1On延时                          
#define mPara_POut2OnDly         669            //自由输出点2On延时                          
#define mPara_POut3OnDly         670            //自由输出点3On延时                          
#define mPara_POut4OnDly         671            //自由输出点4On延时                          
#define mPara_POut1OnTi          672            //自由输出点1On时间                          
#define mPara_POut2OnTi          673            //自由输出点2On时间                          
#define mPara_POut3OnTi          674            //自由输出点3On时间                          
#define mPara_POut4OnTi          675            //自由输出点4On时间                          
#define mPara_Manu_676           676            //                                    
#define mPara_Manu_677           677            //                                    
#define mPara_Manu_678           678            //                                    
#define mPara_Manu_679           679            //                                    
#define mPara_VacuumizeSel       680            //抽真空启动方式选择                           0-不用；1-时间；2-位置
#define mPara_VacuumizeDly       681            //抽真空启动延时                             抽真空启动延时
#define mPara_VacuumizePos       682            //抽真空启动位置                             抽真空启动位置
#define mPara_Manu_683           683            //                                    
#define mPara_Manu_684           684            //                                    
#define mPara_Manu_685           685            //                                    
#define mPara_EjeChargeSel       686            //托模后储料选择                             0-不用 1-使用
#define mPara_AutoRejectCnt      687            //转自动不良品输出模数                          手动转自动后不良品输出模数；0-不输出，非0-输出
#define mPara_MoldSlidBlockMonPos 688           //滑块监控位置                              模具滑块监控位置
#define mPara_MoldOpenAuxil_BJTi 689            //开模辅助输出时间                            博劲开模辅助：开模同时输出，时间可调
#define mPara_MD6InjectMode      690            //注射模式                                MD6卡注射模式：0-不用 1-使用
#define mPara_InjDiffSel         691            //注射差动选择                              0-不用 1-使用
#define mPara_MoldClsLPRelSel    692            //模保泄压                                盈泰：0-不用 1-使用
#define mPara_MoldOpenBPTi_YT    693            //开模背压计时                              盈泰
#define mPara_Manu_694           694            //                                    
#define mPara_Manu_695           695            //                                    
#define mPara_Manu_696           696            //                                    
#define mPara_Manu_697           697            //                                    
#define mPara_Manu_698           698            //                                    
#define mPara_Manu_699           699            //                                    
#define mPara_SemiAutoChkBackSG  700            //半自动后安全门模式                           应特殊机：0-半自动循环开始检查前安全门；1-半自动循环开始检查后安全门
#define mPara_SGOpenCls2ndTimeSel 701           //安全门开关第2次选择                          0-不用 1-使用。托模选停留，托模进后提示开关安全门。该功能选使用后，关模前会提示第二次开关安全门
#define mPara_Manu_702           702            //                                    
#define mPara_Manu_703           703            //                                    
#define mPara_Manu_704           704            //                                    
#define mPara_Manu_705           705            //                                    
#define mPara_Manu_706           706            //                                    
#define mPara_Manu_707           707            //                                    
#define mPara_Manu_708           708            //                                    
#define mPara_Manu_709           709            //                                    
#define mPara_Manu_710           710            //                                    
#define mPara_Manu_711           711            //                                    
#define mPara_Manu_712           712            //                                    
#define mPara_Manu_713           713            //                                    
#define mPara_CycTiOLP           714            //循环时间超差处理                            0-不用 1-提示 2-警报
#define mPara_MoldClsTiOLP       715            //关模时间超差处理                            0-不用 1-提示 2-警报
#define mPara_MoldClsHPTiOLP     716            //关模高压时间超差处理                          0-不用 1-提示 2-警报
#define mPara_MoldClsLPTiOLP     717            //关模低压时间超差处理                          0-不用 1-提示 2-警报
#define mPara_MoldOpenTiOLP      718            //开模时间超差处理                            0-不用 1-提示 2-警报
#define mPara_MoldOpenEPosOLP    719            //开模结束位置超差处理                          0-不用 1-提示 2-警报
#define mPara_EjeForTiOLP        720            //托模时间超差处理                            0-不用 1-提示 2-警报
#define mPara_InjectTiOLP        721            //注射时间超差处理                            0-不用 1-提示 2-警报
#define mPara_InjectEPosOLP      722            //注射结束位置超差处理                          0-不用 1-提示 2-警报
#define mPara_InjectSpdOLP       723            //注射速度超差处理                            0-不用 1-提示 2-警报
#define mPara_HoldPresTiOLP      724            //保压时间超差处理                            0-不用 1-提示 2-警报
#define mPara_HoldPresSPosOLP    725            //保压起始位置超差处理                          0-不用 1-提示 2-警报
#define mPara_HoldPresSPresOLP   726            //保压起始压力超差处理                          0-不用 1-提示 2-警报
#define mPara_SuckBackTiOLP      727            //射退时间超差处理                            0-不用 1-提示 2-警报
#define mPara_ChargeTiOLP        728            //储料时间超差处理                            0-不用 1-提示 2-警报
#define mPara_ChargeEPosOLP      729            //储料结束位置超差处理                          0-不用 1-提示 2-警报
#define mPara_ChargeRPMOLP       730            //储料最高转速超差处理                          0-不用 1-提示 2-警报
#define mPara_InjPeakPresOLP     731            //注射峰值压力超差处理                          0-不用 1-提示 2-警报
#define mPara_Manu_732           732            //                                    
#define mPara_Manu_733           733            //                                    
#define mPara_Manu_734           734            //                                    
#define mPara_Manu_735           735            //                                    
#define mPara_Manu_736           736            //                                    
#define mPara_Manu_737           737            //                                    
#define mPara_Manu_738           738            //                                    
#define mPara_CycTiDev           739            //循环时间允许偏差                            
#define mPara_MoldClsTiDev       740            //关模时间允许偏差                            
#define mPara_MoldClsHPTiDev     741            //关模高压时间允许偏差                          
#define mPara_MoldClsLPTiDev     742            //关模低压时间允许偏差                          
#define mPara_MoldOpenTiDev      743            //开模时间允许偏差                            
#define mPara_MoldOpenEPosDev    744            //开模结束位置允许偏差                          
#define mPara_EjeForTiDev        745            //托模时间允许偏差                            
#define mPara_InjectTiDev        746            //注射时间允许偏差                            射出及保压时间允许偏差
#define mPara_InjectEPosDev      747            //注射结束位置允许偏差                          射出及保压结束位置允许偏差，即射出监测
#define mPara_InjectSpdDev       748            //注射速度允许偏差                            射出最高速度允许偏差
#define mPara_HoldPresTiDev      749            //保压时间允许偏差                            注射(不含保压)时间允许偏差，即转保压前注射时间
#define mPara_HoldPresSPosDev    750            //保压起始位置允许偏差                          
#define mPara_HoldPresSPresDev   751            //保压起始压力允许偏差                          转保压压力允许偏差
#define mPara_SuckBackTiDev      752            //射退时间允许偏差                            
#define mPara_ChargeTiDev        753            //储料时间允许偏差                            
#define mPara_ChargeEPosDev      754            //储料结束位置允许偏差                          
#define mPara_ChargeRPMDev       755            //储料最高转速允许偏差                          
#define mPara_InjPeakPresDev     756            //注射峰值压力允许偏差                          注射峰值压力允许偏差
#define mPara_Manu_757           757            //                                    
#define mPara_Manu_758           758            //                                    
#define mPara_Manu_759           759            //                                    
#define mPara_Manu_760           760            //                                    
#define mPara_Manu_761           761            //                                    
#define mPara_Manu_762           762            //                                    
#define mPara_Manu_763           763            //                                    
#define mPara_CycTiStd           764            //循环标准时间                              监测数据由用户输入生成方式时引用
#define mPara_MoldClsTiStd       765            //关模标准时间                              监测数据由用户输入生成方式时引用
#define mPara_MoldClsHPTiStd     766            //关模高压标准时间                            监测数据由用户输入生成方式时引用
#define mPara_MoldClsLPTiStd     767            //关模低压标准时间                            监测数据由用户输入生成方式时引用
#define mPara_MoldOpenTiStd      768            //开模标准时间                              监测数据由用户输入生成方式时引用
#define mPara_MoldOpenEPosStd    769            //开模标准结束位置                            监测数据由用户输入生成方式时引用
#define mPara_EjeForTiStd        770            //托模标准时间                              监测数据由用户输入生成方式时引用
#define mPara_InjectTiStd        771            //注射标准时间                              监测数据由用户输入生成方式时引用
#define mPara_InjectEPosStd      772            //注射标准结束位置                            射出及保压结束位置，即射出监测
#define mPara_InjectSpdStd       773            //注射标准速度                              射出最高速度
#define mPara_HoldPresTiStd      774            //保压标准时间                              注射(不含保压)时间，即转保压前注射时间
#define mPara_HoldPresSPosStd    775            //保压标准起始位置                            
#define mPara_HoldPresSPresStd   776            //保压标准起始压力                            转保压压力
#define mPara_SuckBackTiStd      777            //射退标准时间                              
#define mPara_ChargeTiStd        778            //储料标准时间                              
#define mPara_ChargeEPosStd      779            //储料标准结束位置                            
#define mPara_ChargeRPMStd       780            //储料标准最高转速                            
#define mPara_InjPeakPresStd     781            //注射峰值标准压力                            
#define mPara_Manu_782           782            //                                    
#define mPara_Manu_783           783            //                                    
#define mPara_Manu_784           784            //                                    
#define mPara_Manu_785           785            //                                    
#define mPara_Manu_786           786            //                                    
#define mPara_Manu_787           787            //                                    
#define mPara_Manu_788           788            //                                    
#define mPara_Manu_789           789            //                                    
#define mPara_Manu_790           790            //                                    
#define mPara_Manu_791           791            //                                    
#define mPara_Manu_792           792            //                                    
#define mPara_Manu_793           793            //                                    
#define mPara_Manu_794           794            //                                    
#define mPara_Manu_795           795            //                                    
#define mPara_Manu_796           796            //                                    
#define mPara_Manu_797           797            //                                    
#define mPara_Manu_798           798            //                                    
#define mPara_Manu_799           799            //                                    
#define mPara_CurrSevroDrvSN     800            //当前伺服驱动器                             
#define mPara_Manu_801           801            //                                    
#define mPara_Manu_802           802            //                                    
#define mPara_Manu_803           803            //                                    
#define mPara_Manu_804           804            //                                    
#define mPara_Manu_805           805            //                                    
#define mPara_Manu_806           806            //                                    
#define mPara_Manu_807           807            //                                    
#define mPara_Manu_808           808            //                                    
#define mPara_Manu_809           809            //                                    
#define mPara_EjeFor3StepSel     810            //三级托模选择                              特殊托模：定次托模时,托模3次每次位置都不一样
#define mPara_EjeForStep2Pos     811            //三级托模2级位置                            特殊托模：定次托模时,托模3次每次位置都不一样,第2次托模结束位置
#define mPara_EjeForStep3Pos     812            //三级托模3级位置                            特殊托模：定次托模时,托模3次每次位置都不一样,第3次托模结束位置
#define mPara_Manu_813           813            //                                    
#define mPara_Manu_814           814            //                                    
#define mPara_Manu_815           815            //                                    
#define mPara_Manu_816           816            //                                    
#define mPara_Manu_817           817            //                                    
#define mPara_Manu_818           818            //                                    
#define mPara_DryCycAutoCycDly   819            //干循环再循环延时                            
#define mPara_DryCycMC1Pres      820            //干循环关模一段压力                           
#define mPara_DryCycMC1Flow      821            //干循环关模一段流量                           
#define mPara_DryCycMC2Pres      822            //干循环关模二段压力                           
#define mPara_DryCycMC2Flow      823            //干循环关模二段流量                           
#define mPara_DryCycMC2SPos      824            //干循环关模二段起始位置                         
#define mPara_DryCycMC3Pres      825            //干循环关模三段压力                           
#define mPara_DryCycMC3Flow      826            //干循环关模三段流量                           
#define mPara_DryCycMC3SPos      827            //干循环关模三段起始位置                         
#define mPara_DryCycMCLPPres     828            //干循环关模低压段压力                          
#define mPara_DryCycMCLPFlow     829            //干循环关模低压段流量                          
#define mPara_DryCycMCLPSPos     830            //干循环关模低压段起始位置                        
#define mPara_DryCycMCHPPres     831            //干循环关模高压段压力                          
#define mPara_DryCycMCHPFlow     832            //干循环关模高压段流量                          
#define mPara_DryCycMCHPSPos     833            //干循环关模高压段起始位置                        
#define mPara_Manu_834           834            //                                    
#define mPara_Manu_835           835            //                                    
#define mPara_Manu_836           836            //                                    
#define mPara_Manu_837           837            //                                    
#define mPara_DryCycMO1Pres      838            //干循环开模一段压力                           
#define mPara_DryCycMO1Flow      839            //干循环开模一段流量                           
#define mPara_DryCycMO2Pres      840            //干循环开模二段压力                           
#define mPara_DryCycMO2Flow      841            //干循环开模二段流量                           
#define mPara_DryCycMO2SPos      842            //干循环开模二段起始位置                         
#define mPara_DryCycMO3Pres      843            //干循环开模三段压力                           
#define mPara_DryCycMO3Flow      844            //干循环开模三段流量                           
#define mPara_DryCycMO3SPos      845            //干循环开模三段起始位置                         
#define mPara_DryCycMO4Pres      846            //干循环开模四段压力                           
#define mPara_DryCycMO4Flow      847            //干循环开模四段流量                           
#define mPara_DryCycMO4SPos      848            //干循环开模四段起始位置                         
#define mPara_DryCycMO5Pres      849            //干循环开模五段压力                           
#define mPara_DryCycMO5Flow      850            //干循环开模五段流量                           
#define mPara_DryCycMO5SPos      851            //干循环开模五段起始位置                         
#define mPara_DryCycMOEPos       852            //干循环开模结束位置                           
#define mPara_Manu_853           853            //                                    
#define mPara_Manu_854           854            //                                    
#define mPara_MCHPPresTrgTon     855            //目标锁模吨数                              
#define mPara_AutoAdjMoldMode    856            //自动调模模式                              0-锁模高压 1-锁模吨数
#define mPara_Manu_857           857            //                                    
#define mPara_Manu_858           858            //                                    
#define mPara_Manu_859           859            //                                    
#define mPara_NozLeakageSnrSel   860            //喷嘴漏料检测功能                            0-不用 1-使用
#define mPara_NozLeakTempDev1    861            //喷嘴漏料警报偏差1                           温度偏差1
#define mPara_NozLeakTempDev2    862            //喷嘴漏料警报偏差2                           温度偏差2
#define mPara_Manu_863           863            //                                    
#define mPara_Manu_864           864            //                                    
#define mPara_Manu_865           865            //                                    
#define mPara_Manu_866           866            //                                    
#define mPara_Manu_867           867            //                                    
#define mPara_Manu_868           868            //                                    
#define mPara_Manu_869           869            //                                    
#define mPara_Manu_870           870            //                                    
#define mPara_Manu_871           871            //                                    
#define mPara_Manu_872           872            //                                    
#define mPara_Manu_873           873            //                                    
#define mPara_Manu_874           874            //                                    
#define mPara_Manu_875           875            //                                    
#define mPara_Manu_876           876            //                                    
#define mPara_Manu_877           877            //                                    
#define mPara_Manu_878           878            //                                    
#define mPara_Manu_879           879            //                                    
#define mPara_Manu_880           880            //                                    
#define mPara_Manu_881           881            //                                    
#define mPara_Manu_882           882            //                                    
#define mPara_Manu_883           883            //                                    
#define mPara_Manu_884           884            //                                    
#define mPara_Manu_885           885            //                                    
#define mPara_Manu_886           886            //                                    
#define mPara_Manu_887           887            //                                    
#define mPara_Manu_888           888            //                                    
#define mPara_Manu_889           889            //                                    
#define mPara_Manu_890           890            //                                    
#define mPara_Manu_891           891            //                                    
#define mPara_Manu_892           892            //                                    
#define mPara_Manu_893           893            //                                    
#define mPara_SprueOpenOcc       894            //浇口开时机                               0-关闭，1-合模过时间，2-顶退过时间，3-开模终过时间，4-注射过时间，5-合模高压过时间
#define mPara_SprueOpenPos       895            //浇口开位置                               动作超过这个位置后就开启浇口
#define mPara_SprueOpenTime      896            //浇口开时间                               动作超过这个时间后就开启浇口
#define mPara_SprueClsOcc        897            //浇口关时机                               0-浇口关不起作用；1-注射结束；2-保压结束；3-储料结束；4-射退结束
#define mPara_Manu_898           898            //                                    
#define mPara_Manu_899           899            //                                    
#define mPara_HRV01_Function     900            //热流道阀门一功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV02_Function     901            //热流道阀门二功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV03_Function     902            //热流道阀门三功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV04_Function     903            //热流道阀门四功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV05_Function     904            //热流道阀门五功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV06_Function     905            //热流道阀门六功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV07_Function     906            //热流道阀门七功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV08_Function     907            //热流道阀门八功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV09_Function     908            //热流道阀门九功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV10_Function     909            //热流道阀门十功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV01_Inj_OnTi     910            //阀门一射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV02_Inj_OnTi     911            //阀门二射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV03_Inj_OnTi     912            //阀门三射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV04_Inj_OnTi     913            //阀门四射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV05_Inj_OnTi     914            //阀门五射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV06_Inj_OnTi     915            //阀门六射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV07_Inj_OnTi     916            //阀门七射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV08_Inj_OnTi     917            //阀门八射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV09_Inj_OnTi     918            //阀门九射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV10_Inj_OnTi     919            //阀门十射出开时间                            阀门:射出执行到该时间开启阀门
#define mPara_HRV01_Inj_OffTi    920            //阀门一射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV02_Inj_OffTi    921            //阀门二射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV03_Inj_OffTi    922            //阀门三射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV04_Inj_OffTi    923            //阀门四射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV05_Inj_OffTi    924            //阀门五射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV06_Inj_OffTi    925            //阀门六射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV07_Inj_OffTi    926            //阀门七射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV08_Inj_OffTi    927            //阀门八射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV09_Inj_OffTi    928            //阀门九射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV10_Inj_OffTi    929            //阀门十射出关时间                            阀门:射出执行到该时间关闭阀门
#define mPara_HRV01_Inj_OnPos    930            //阀门一射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV02_Inj_OnPos    931            //阀门二射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV03_Inj_OnPos    932            //阀门三射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV04_Inj_OnPos    933            //阀门四射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV05_Inj_OnPos    934            //阀门五射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV06_Inj_OnPos    935            //阀门六射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV07_Inj_OnPos    936            //阀门七射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV08_Inj_OnPos    937            //阀门八射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV09_Inj_OnPos    938            //阀门九射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV10_Inj_OnPos    939            //阀门十射出开位置                            阀门:射出执行到该位置开启阀门
#define mPara_HRV01_Inj_OffPos   940            //阀门一射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV02_Inj_OffPos   941            //阀门二射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV03_Inj_OffPos   942            //阀门三射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV04_Inj_OffPos   943            //阀门四射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV05_Inj_OffPos   944            //阀门五射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV06_Inj_OffPos   945            //阀门六射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV07_Inj_OffPos   946            //阀门七射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV08_Inj_OffPos   947            //阀门八射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV09_Inj_OffPos   948            //阀门九射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV10_Inj_OffPos   949            //阀门十射出关位置                            阀门:射出执行到该位置关闭阀门
#define mPara_HRV01_HP_OnTi      950            //阀门一保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV02_HP_OnTi      951            //阀门二保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV03_HP_OnTi      952            //阀门三保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV04_HP_OnTi      953            //阀门四保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV05_HP_OnTi      954            //阀门五保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV06_HP_OnTi      955            //阀门六保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV07_HP_OnTi      956            //阀门七保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV08_HP_OnTi      957            //阀门八保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV09_HP_OnTi      958            //阀门九保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV10_HP_OnTi      959            //阀门十保压开时间                            阀门:保压执行到该时间开启阀门
#define mPara_HRV01_HP_OffTi     960            //阀门一保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV02_HP_OffTi     961            //阀门二保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV03_HP_OffTi     962            //阀门三保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV04_HP_OffTi     963            //阀门四保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV05_HP_OffTi     964            //阀门五保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV06_HP_OffTi     965            //阀门六保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV07_HP_OffTi     966            //阀门七保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV08_HP_OffTi     967            //阀门八保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV09_HP_OffTi     968            //阀门九保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_HRV10_HP_OffTi     969            //阀门十保压关时间                            阀门:保压执行到该时间关闭阀门
#define mPara_Manu_970           970            //                                    
#define mPara_Manu_971           971            //                                    
#define mPara_Manu_972           972            //                                    
#define mPara_Manu_973           973            //                                    
#define mPara_Manu_974           974            //                                    
#define mPara_Manu_975           975            //                                    
#define mPara_Manu_976           976            //                                    
#define mPara_Manu_977           977            //                                    
#define mPara_Manu_978           978            //                                    
#define mPara_Manu_979           979            //                                    
#define mPara_Manu_980           980            //                                    
#define mPara_Manu_981           981            //                                    
#define mPara_Manu_982           982            //                                    
#define mPara_Manu_983           983            //                                    
#define mPara_Manu_984           984            //                                    
#define mPara_Manu_985           985            //                                    
#define mPara_Manu_986           986            //                                    
#define mPara_Manu_987           987            //                                    
#define mPara_Manu_988           988            //                                    
#define mPara_Manu_989           989            //                                    
#define mPara_Manu_990           990            //                                    
#define mPara_Manu_991           991            //                                    
#define mPara_Manu_992           992            //                                    
#define mPara_Manu_993           993            //                                    
#define mPara_Manu_994           994            //                                    
#define mPara_Manu_995           995            //                                    
#define mPara_Manu_996           996            //                                    
#define mPara_Manu_997           997            //                                    
#define mPara_Manu_998           998            //                                    
#define mPara_Manu_999           999            //                                    
#define mPara_HRV11_Function     1000           //热流道阀门十一功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV12_Function     1001           //热流道阀门十二功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV13_Function     1002           //热流道阀门十三功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV14_Function     1003           //热流道阀门十四功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV15_Function     1004           //热流道阀门十五功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV16_Function     1005           //热流道阀门十六功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV17_Function     1006           //热流道阀门十七功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV18_Function     1007           //热流道阀门十八功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV19_Function     1008           //热流道阀门十九功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV20_Function     1009           //热流道阀门二十功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define mPara_HRV11_Inj_OnTi     1010           //阀门11射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV12_Inj_OnTi     1011           //阀门12射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV13_Inj_OnTi     1012           //阀门13射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV14_Inj_OnTi     1013           //阀门14射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV15_Inj_OnTi     1014           //阀门15射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV16_Inj_OnTi     1015           //阀门16射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV17_Inj_OnTi     1016           //阀门17射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV18_Inj_OnTi     1017           //阀门18射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV19_Inj_OnTi     1018           //阀门19射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV20_Inj_OnTi     1019           //阀门20射出开时间                           阀门:射出执行到该时间开启阀门
#define mPara_HRV11_Inj_OffTi    1020           //阀门11射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV12_Inj_OffTi    1021           //阀门12射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV13_Inj_OffTi    1022           //阀门13射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV14_Inj_OffTi    1023           //阀门14射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV15_Inj_OffTi    1024           //阀门15射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV16_Inj_OffTi    1025           //阀门16射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV17_Inj_OffTi    1026           //阀门17射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV18_Inj_OffTi    1027           //阀门18射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV19_Inj_OffTi    1028           //阀门19射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV20_Inj_OffTi    1029           //阀门20射出关时间                           阀门:射出执行到该时间关闭阀门
#define mPara_HRV11_Inj_OnPos    1030           //阀门11射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV12_Inj_OnPos    1031           //阀门12射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV13_Inj_OnPos    1032           //阀门13射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV14_Inj_OnPos    1033           //阀门14射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV15_Inj_OnPos    1034           //阀门15射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV16_Inj_OnPos    1035           //阀门16射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV17_Inj_OnPos    1036           //阀门17射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV18_Inj_OnPos    1037           //阀门18射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV19_Inj_OnPos    1038           //阀门19射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV20_Inj_OnPos    1039           //阀门20射出开位置                           阀门:射出执行到该位置开启阀门
#define mPara_HRV11_Inj_OffPos   1040           //阀门11射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV12_Inj_OffPos   1041           //阀门12射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV13_Inj_OffPos   1042           //阀门13射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV14_Inj_OffPos   1043           //阀门14射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV15_Inj_OffPos   1044           //阀门15射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV16_Inj_OffPos   1045           //阀门16射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV17_Inj_OffPos   1046           //阀门17射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV18_Inj_OffPos   1047           //阀门18射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV19_Inj_OffPos   1048           //阀门19射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV20_Inj_OffPos   1049           //阀门20射出关位置                           阀门:射出执行到该位置关闭阀门
#define mPara_HRV11_HP_OnTi      1050           //阀门11保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV12_HP_OnTi      1051           //阀门12保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV13_HP_OnTi      1052           //阀门13保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV14_HP_OnTi      1053           //阀门14保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV15_HP_OnTi      1054           //阀门15保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV16_HP_OnTi      1055           //阀门16保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV17_HP_OnTi      1056           //阀门17保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV18_HP_OnTi      1057           //阀门18保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV19_HP_OnTi      1058           //阀门19保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV20_HP_OnTi      1059           //阀门20保压开时间                           阀门:保压执行到该时间开启阀门
#define mPara_HRV11_HP_OffTi     1060           //阀门11保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV12_HP_OffTi     1061           //阀门12保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV13_HP_OffTi     1062           //阀门13保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV14_HP_OffTi     1063           //阀门14保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV15_HP_OffTi     1064           //阀门15保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV16_HP_OffTi     1065           //阀门16保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV17_HP_OffTi     1066           //阀门17保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV18_HP_OffTi     1067           //阀门18保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV19_HP_OffTi     1068           //阀门19保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_HRV20_HP_OffTi     1069           //阀门20保压关时间                           阀门:保压执行到该时间关闭阀门
#define mPara_Manu_1070          1070           //                                    
#define mPara_Manu_1071          1071           //                                    
#define mPara_Manu_1072          1072           //                                    
#define mPara_Manu_1073          1073           //                                    
#define mPara_Manu_1074          1074           //                                    
#define mPara_Manu_1075          1075           //                                    
#define mPara_Manu_1076          1076           //                                    
#define mPara_Manu_1077          1077           //                                    
#define mPara_Manu_1078          1078           //                                    
#define mPara_Manu_1079          1079           //                                    
#define mPara_LinkHoldPresFun    1080           //连动保压功能                              0-连动保压功能关闭；1-连动保压功能打开
#define mPara_HPVC_ForPres       1081           //阀芯进压力                               阀芯进压力
#define mPara_HPVC_ForFlow       1082           //阀芯进流量                               阀芯进流量
#define mPara_HPVC_RetPres       1083           //阀芯退压力                               阀芯退压力
#define mPara_HPVC_RetFlow       1084           //阀芯退流量                               阀芯退流量
#define mPara_HoldPresRetPres    1085           //保压退压力                               保压退压力
#define mPara_HoldPresRetFlow    1086           //保压退流量                               保压退流量
#define mPara_HoldPresRetEndPos  1087           //保压退结束位置                             保压退结束位置
#define mPara_HoldPresEndPos     1088           //保压结束位置                              保压结束位置
#define mPara_InjectSecSel       1089           //注射分段选择                              0-位置 1-时间
#define mPara_Inject1Ti          1090           //注射一段时间                              
#define mPara_Inject2Ti          1091           //注射二段时间                              
#define mPara_Inject3Ti          1092           //注射三段时间                              
#define mPara_Inject4Ti          1093           //注射四段时间                              
#define mPara_Inject5Ti          1094           //注射五段时间                              
#define mPara_Inject6Ti          1095           //注射六段时间                              
#define mPara_Inject7Ti          1096           //注射七段时间                              
#define mPara_Inject8Ti          1097           //注射八段时间                              
#define mPara_Inject9Ti          1098           //注射九段时间                              
#define mPara_Inject10Ti         1099           //注射十段时间                              
#define mPara_Inj1IncrPresSel    1100           //注射一段增力选择                            0-不用 1使用
#define mPara_Inj2IncrPresSel    1101           //注射二段增力选择                            0-不用 1使用
#define mPara_Inj3IncrPresSel    1102           //注射三段增力选择                            0-不用 1使用
#define mPara_Inj4IncrPresSel    1103           //注射四段增力选择                            0-不用 1使用
#define mPara_Inj5IncrPresSel    1104           //注射五段增力选择                            0-不用 1使用
#define mPara_Inj6IncrPresSel    1105           //注射六段增力选择                            0-不用 1使用
#define mPara_Inj7IncrPresSel    1106           //注射七段增力选择                            0-不用 1使用
#define mPara_Inj8IncrPresSel    1107           //注射八段增力选择                            0-不用 1使用
#define mPara_Inj9IncrPresSel    1108           //注射九段增力选择                            0-不用 1使用
#define mPara_Inj10IncrPresSel   1109           //注射十段增力选择                            0-不用 1使用
#define mPara_Inj1IncrSpeedSel   1110           //注射一段增速选择                            0-不用 1使用
#define mPara_Inj2IncrSpeedSel   1111           //注射二段增速选择                            0-不用 1使用
#define mPara_Inj3IncrSpeedSel   1112           //注射三段增速选择                            0-不用 1使用
#define mPara_Inj4IncrSpeedSel   1113           //注射四段增速选择                            0-不用 1使用
#define mPara_Inj5IncrSpeedSel   1114           //注射五段增速选择                            0-不用 1使用
#define mPara_Inj6IncrSpeedSel   1115           //注射六段增速选择                            0-不用 1使用
#define mPara_Inj7IncrSpeedSel   1116           //注射七段增速选择                            0-不用 1使用
#define mPara_Inj8IncrSpeedSel   1117           //注射八段增速选择                            0-不用 1使用
#define mPara_Inj9IncrSpeedSel   1118           //注射九段增速选择                            0-不用 1使用
#define mPara_Inj10IncrSpeedSel  1119           //注射十段增速选择                            0-不用 1使用
#define mPara_Air1ActOcc         1120           //A组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Air2ActOcc         1121           //B组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Air3ActOcc         1122           //C组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Air4ActOcc         1123           //D组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Air5ActOcc         1124           //E组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Air6ActOcc         1125           //F组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define mPara_Manu_1126          1126           //                                    
#define mPara_Manu_1127          1127           //                                    
#define mPara_Manu_1128          1128           //                                    
#define mPara_Manu_1129          1129           //                                    
#define mPara_Manu_1130          1130           //                                    
#define mPara_Manu_1131          1131           //                                    
#define mPara_Manu_1132          1132           //                                    
#define mPara_Manu_1133          1133           //                                    
#define mPara_Manu_1134          1134           //                                    
#define mPara_Manu_1135          1135           //                                    
#define mPara_Manu_1136          1136           //                                    
#define mPara_Manu_1137          1137           //                                    
#define mPara_Manu_1138          1138           //                                    
#define mPara_Manu_1139          1139           //                                    
#define mPara_Manu_1140          1140           //                                    
#define mPara_Manu_1141          1141           //                                    
#define mPara_Manu_1142          1142           //                                    
#define mPara_Manu_1143          1143           //                                    
#define mPara_Manu_1144          1144           //                                    
#define mPara_Manu_1145          1145           //                                    
#define mPara_Manu_1146          1146           //                                    
#define mPara_Manu_1147          1147           //                                    
#define mPara_Manu_1148          1148           //                                    
#define mPara_Manu_1149          1149           //                                    
#define mPara_Manu_1150          1150           //                                    
#define mPara_Manu_1151          1151           //                                    
#define mPara_Manu_1152          1152           //                                    
#define mPara_Manu_1153          1153           //                                    
#define mPara_Manu_1154          1154           //                                    
#define mPara_Manu_1155          1155           //                                    
#define mPara_Manu_1156          1156           //                                    
#define mPara_Manu_1157          1157           //                                    
#define mPara_Manu_1158          1158           //                                    
#define mPara_Manu_1159          1159           //                                    
#define mPara_Manu_1160          1160           //                                    
#define mPara_Manu_1161          1161           //                                    
#define mPara_Manu_1162          1162           //                                    
#define mPara_Manu_1163          1163           //                                    
#define mPara_Manu_1164          1164           //                                    
#define mPara_Manu_1165          1165           //                                    
#define mPara_Manu_1166          1166           //                                    
#define mPara_Manu_1167          1167           //                                    
#define mPara_Manu_1168          1168           //                                    
#define mPara_Manu_1169          1169           //                                    
#define mPara_Manu_1170          1170           //                                    
#define mPara_Manu_1171          1171           //                                    
#define mPara_Manu_1172          1172           //                                    
#define mPara_Manu_1173          1173           //                                    
#define mPara_Manu_1174          1174           //                                    
#define mPara_Manu_1175          1175           //                                    
#define mPara_Manu_1176          1176           //                                    
#define mPara_Manu_1177          1177           //                                    
#define mPara_Manu_1178          1178           //                                    
#define mPara_Manu_1179          1179           //                                    
#define mPara_Manu_1180          1180           //                                    
#define mPara_Manu_1181          1181           //                                    
#define mPara_Manu_1182          1182           //                                    
#define mPara_Manu_1183          1183           //                                    
#define mPara_Manu_1184          1184           //                                    
#define mPara_Manu_1185          1185           //                                    
#define mPara_Manu_1186          1186           //                                    
#define mPara_Manu_1187          1187           //                                    
#define mPara_Manu_1188          1188           //                                    
#define mPara_Manu_1189          1189           //                                    
#define mPara_Manu_1190          1190           //                                    
#define mPara_Manu_1191          1191           //                                    
#define mPara_Manu_1192          1192           //                                    
#define mPara_Manu_1193          1193           //                                    
#define mPara_Manu_1194          1194           //                                    
#define mPara_Manu_1195          1195           //                                    
#define mPara_Manu_1196          1196           //                                    
#define mPara_Manu_1197          1197           //                                    
#define mPara_Manu_1198          1198           //                                    
#define mPara_Manu_1199          1199           //                                    
#define mPara_Manu_1200          1200           //                                    
#define mPara_Manu_1201          1201           //                                    
#define mPara_Manu_1202          1202           //                                    
#define mPara_Manu_1203          1203           //                                    
#define mPara_Manu_1204          1204           //                                    
#define mPara_Manu_1205          1205           //                                    
#define mPara_Manu_1206          1206           //                                    
#define mPara_Manu_1207          1207           //                                    
#define mPara_Manu_1208          1208           //                                    
#define mPara_Manu_1209          1209           //                                    
#define mPara_Manu_1210          1210           //                                    
#define mPara_Manu_1211          1211           //                                    
#define mPara_Manu_1212          1212           //                                    
#define mPara_Manu_1213          1213           //                                    
#define mPara_Manu_1214          1214           //                                    
#define mPara_Manu_1215          1215           //                                    
#define mPara_Manu_1216          1216           //                                    
#define mPara_Manu_1217          1217           //                                    
#define mPara_Manu_1218          1218           //                                    
#define mPara_Manu_1219          1219           //                                    
#define mPara_HotRunrSwitch      1220           //热流道总开关                              热流道总开关:0-关，1-开
#define mPara_HotRunrHoldTempSel 1221           //热流道保温功能                             热流道保温功能：0-不用 1-选用
#define mPara_HotRunrHoldTemp    1222           //热流道保温温度                             热流道保温温度
#define mPara_HotRunrSenrType    1223           //热流道传感器类型                            热流道传感器类型：0-J 1-K 2-E
#define mPara_HotRunrSoftStatSwih 1224          //热流道软启动开关                            热流道软启动开关:0-关，1-开
#define mPara_HotRunrSoftStatTemp 1225          //热流道软启动温度                            热流道软启动温度
#define mPara_HotRunrSoftStatPowr 1226          //热流道软启动功率                            热流道软启动功率
#define mPara_HotRunrSoftStatTime 1227          //热流道软启动时间                            热流道软启动时间
#define mPara_Manu_1228          1228           //                                    
#define mPara_Manu_1229          1229           //                                    
#define mPara_HotRunr1SetTemp    1230           //热流道1设置温度                            热流道1设置温度
#define mPara_HotRunr2SetTemp    1231           //热流道2设置温度                            热流道2设置温度
#define mPara_HotRunr3SetTemp    1232           //热流道3设置温度                            热流道3设置温度
#define mPara_HotRunr4SetTemp    1233           //热流道4设置温度                            热流道4设置温度
#define mPara_HotRunr5SetTemp    1234           //热流道5设置温度                            热流道5设置温度
#define mPara_HotRunr6SetTemp    1235           //热流道6设置温度                            热流道6设置温度
#define mPara_HotRunr7SetTemp    1236           //热流道7设置温度                            热流道7设置温度
#define mPara_HotRunr8SetTemp    1237           //热流道8设置温度                            热流道8设置温度
#define mPara_HotRunr9SetTemp    1238           //热流道9设置温度                            热流道9设置温度
#define mPara_HotRunr10SetTemp   1239           //热流道10设置温度                           热流道10设置温度
#define mPara_HotRunr11SetTemp   1240           //热流道11设置温度                           热流道11设置温度
#define mPara_HotRunr12SetTemp   1241           //热流道12设置温度                           热流道12设置温度
#define mPara_HotRunr13SetTemp   1242           //热流道13设置温度                           热流道13设置温度
#define mPara_HotRunr14SetTemp   1243           //热流道14设置温度                           热流道14设置温度
#define mPara_HotRunr15SetTemp   1244           //热流道15设置温度                           热流道15设置温度
#define mPara_HotRunr16SetTemp   1245           //热流道16设置温度                           热流道16设置温度
#define mPara_HotRunr17SetTemp   1246           //热流道17设置温度                           热流道17设置温度
#define mPara_HotRunr18SetTemp   1247           //热流道18设置温度                           热流道18设置温度
#define mPara_HotRunr19SetTemp   1248           //热流道19设置温度                           热流道19设置温度
#define mPara_HotRunr20SetTemp   1249           //热流道20设置温度                           热流道20设置温度
#define mPara_HotRunr21SetTemp   1250           //热流道21设置温度                           热流道21设置温度
#define mPara_HotRunr22SetTemp   1251           //热流道22设置温度                           热流道22设置温度
#define mPara_HotRunr23SetTemp   1252           //热流道23设置温度                           热流道23设置温度
#define mPara_HotRunr24SetTemp   1253           //热流道24设置温度                           热流道24设置温度
#define mPara_HotRunr25SetTemp   1254           //热流道25设置温度                           热流道25设置温度
#define mPara_HotRunr26SetTemp   1255           //热流道26设置温度                           热流道26设置温度
#define mPara_HotRunr27SetTemp   1256           //热流道27设置温度                           热流道27设置温度
#define mPara_HotRunr28SetTemp   1257           //热流道28设置温度                           热流道28设置温度
#define mPara_HotRunr29SetTemp   1258           //热流道29设置温度                           热流道29设置温度
#define mPara_HotRunr30SetTemp   1259           //热流道30设置温度                           热流道30设置温度
#define mPara_HotRunr31SetTemp   1260           //热流道31设置温度                           热流道31设置温度
#define mPara_HotRunr32SetTemp   1261           //热流道32设置温度                           热流道32设置温度
#define mPara_HotRunr33SetTemp   1262           //热流道33设置温度                           热流道33设置温度
#define mPara_HotRunr34SetTemp   1263           //热流道34设置温度                           热流道34设置温度
#define mPara_HotRunr35SetTemp   1264           //热流道35设置温度                           热流道35设置温度
#define mPara_HotRunr36SetTemp   1265           //热流道36设置温度                           热流道36设置温度
#define mPara_HotRunr37SetTemp   1266           //热流道37设置温度                           热流道37设置温度
#define mPara_HotRunr38SetTemp   1267           //热流道38设置温度                           热流道38设置温度
#define mPara_HotRunr39SetTemp   1268           //热流道39设置温度                           热流道39设置温度
#define mPara_HotRunr40SetTemp   1269           //热流道40设置温度                           热流道40设置温度
#define mPara_HotRunr41SetTemp   1270           //热流道41设置温度                           热流道41设置温度
#define mPara_HotRunr42SetTemp   1271           //热流道42设置温度                           热流道42设置温度
#define mPara_HotRunr43SetTemp   1272           //热流道43设置温度                           热流道43设置温度
#define mPara_HotRunr44SetTemp   1273           //热流道44设置温度                           热流道44设置温度
#define mPara_HotRunr45SetTemp   1274           //热流道45设置温度                           热流道45设置温度
#define mPara_HotRunr46SetTemp   1275           //热流道46设置温度                           热流道46设置温度
#define mPara_HotRunr47SetTemp   1276           //热流道47设置温度                           热流道47设置温度
#define mPara_HotRunr48SetTemp   1277           //热流道48设置温度                           热流道48设置温度
#define mPara_HotRunr49SetTemp   1278           //热流道49设置温度                           热流道49设置温度
#define mPara_HotRunr50SetTemp   1279           //热流道50设置温度                           热流道50设置温度
#define mPara_HotRunr51SetTemp   1280           //热流道51设置温度                           热流道51设置温度
#define mPara_HotRunr52SetTemp   1281           //热流道52设置温度                           热流道52设置温度
#define mPara_HotRunr53SetTemp   1282           //热流道53设置温度                           热流道53设置温度
#define mPara_HotRunr54SetTemp   1283           //热流道54设置温度                           热流道54设置温度
#define mPara_HotRunr55SetTemp   1284           //热流道55设置温度                           热流道55设置温度
#define mPara_HotRunr56SetTemp   1285           //热流道56设置温度                           热流道56设置温度
#define mPara_HotRunr57SetTemp   1286           //热流道57设置温度                           热流道57设置温度
#define mPara_HotRunr58SetTemp   1287           //热流道58设置温度                           热流道58设置温度
#define mPara_HotRunr59SetTemp   1288           //热流道59设置温度                           热流道59设置温度
#define mPara_HotRunr60SetTemp   1289           //热流道60设置温度                           热流道60设置温度
#define mPara_HotRunr1AlgSel     1290           //热流道1控温算法选择                          热流道1控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr2AlgSel     1291           //热流道2控温算法选择                          热流道2控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr3AlgSel     1292           //热流道3控温算法选择                          热流道3控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr4AlgSel     1293           //热流道4控温算法选择                          热流道4控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr5AlgSel     1294           //热流道5控温算法选择                          热流道5控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr6AlgSel     1295           //热流道6控温算法选择                          热流道6控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr7AlgSel     1296           //热流道7控温算法选择                          热流道7控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr8AlgSel     1297           //热流道8控温算法选择                          热流道8控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr9AlgSel     1298           //热流道9控温算法选择                          热流道9控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr10AlgSel    1299           //热流道10控温算法选择                         热流道10控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr11AlgSel    1300           //热流道11控温算法选择                         热流道11控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr12AlgSel    1301           //热流道12控温算法选择                         热流道12控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr13AlgSel    1302           //热流道13控温算法选择                         热流道13控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr14AlgSel    1303           //热流道14控温算法选择                         热流道14控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr15AlgSel    1304           //热流道15控温算法选择                         热流道15控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr16AlgSel    1305           //热流道16控温算法选择                         热流道16控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr17AlgSel    1306           //热流道17控温算法选择                         热流道17控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr18AlgSel    1307           //热流道18控温算法选择                         热流道18控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr19AlgSel    1308           //热流道19控温算法选择                         热流道19控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr20AlgSel    1309           //热流道20控温算法选择                         热流道20控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr21AlgSel    1310           //热流道21控温算法选择                         热流道21控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr22AlgSel    1311           //热流道22控温算法选择                         热流道22控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr23AlgSel    1312           //热流道23控温算法选择                         热流道23控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr24AlgSel    1313           //热流道24控温算法选择                         热流道24控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr25AlgSel    1314           //热流道25控温算法选择                         热流道25控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr26AlgSel    1315           //热流道26控温算法选择                         热流道26控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr27AlgSel    1316           //热流道27控温算法选择                         热流道27控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr28AlgSel    1317           //热流道28控温算法选择                         热流道28控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr29AlgSel    1318           //热流道29控温算法选择                         热流道29控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr30AlgSel    1319           //热流道30控温算法选择                         热流道30控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr31AlgSel    1320           //热流道31控温算法选择                         热流道31控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr32AlgSel    1321           //热流道32控温算法选择                         热流道32控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr33AlgSel    1322           //热流道33控温算法选择                         热流道33控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr34AlgSel    1323           //热流道34控温算法选择                         热流道34控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr35AlgSel    1324           //热流道35控温算法选择                         热流道35控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr36AlgSel    1325           //热流道36控温算法选择                         热流道36控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr37AlgSel    1326           //热流道37控温算法选择                         热流道37控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr38AlgSel    1327           //热流道38控温算法选择                         热流道38控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr39AlgSel    1328           //热流道39控温算法选择                         热流道39控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr40AlgSel    1329           //热流道40控温算法选择                         热流道40控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr41AlgSel    1330           //热流道41控温算法选择                         热流道41控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr42AlgSel    1331           //热流道42控温算法选择                         热流道42控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr43AlgSel    1332           //热流道43控温算法选择                         热流道43控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr44AlgSel    1333           //热流道44控温算法选择                         热流道44控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr45AlgSel    1334           //热流道45控温算法选择                         热流道45控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr46AlgSel    1335           //热流道46控温算法选择                         热流道46控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr47AlgSel    1336           //热流道47控温算法选择                         热流道47控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr48AlgSel    1337           //热流道48控温算法选择                         热流道48控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr49AlgSel    1338           //热流道49控温算法选择                         热流道49控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr50AlgSel    1339           //热流道50控温算法选择                         热流道50控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr51AlgSel    1340           //热流道51控温算法选择                         热流道51控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr52AlgSel    1341           //热流道52控温算法选择                         热流道52控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr53AlgSel    1342           //热流道53控温算法选择                         热流道53控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr54AlgSel    1343           //热流道54控温算法选择                         热流道54控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr55AlgSel    1344           //热流道55控温算法选择                         热流道55控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr56AlgSel    1345           //热流道56控温算法选择                         热流道56控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr57AlgSel    1346           //热流道57控温算法选择                         热流道57控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr58AlgSel    1347           //热流道58控温算法选择                         热流道58控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr59AlgSel    1348           //热流道59控温算法选择                         热流道59控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_HotRunr60AlgSel    1349           //热流道60控温算法选择                         热流道60控温算法选择:0-不用，1-低速，2-中速，3-高速
#define mPara_Manu_1350          1350           //                                    
#define mPara_Manu_1351          1351           //                                    
#define mPara_Manu_1352          1352           //                                    
#define mPara_Manu_1353          1353           //                                    
#define mPara_Manu_1354          1354           //                                    
#define mPara_Manu_1355          1355           //                                    
#define mPara_Manu_1356          1356           //                                    
#define mPara_Manu_1357          1357           //                                    
#define mPara_Manu_1358          1358           //                                    
#define mPara_Manu_1359          1359           //                                    
#define mPara_Manu_1360          1360           //                                    
#define mPara_Manu_1361          1361           //                                    
#define mPara_Manu_1362          1362           //                                    
#define mPara_Manu_1363          1363           //                                    
#define mPara_Manu_1364          1364           //                                    
#define mPara_Manu_1365          1365           //                                    
#define mPara_Manu_1366          1366           //                                    
#define mPara_Manu_1367          1367           //                                    
#define mPara_Manu_1368          1368           //                                    
#define mPara_Manu_1369          1369           //                                    
#define mPara_Manu_1370          1370           //                                    
#define mPara_Manu_1371          1371           //                                    
#define mPara_Manu_1372          1372           //                                    
#define mPara_Manu_1373          1373           //                                    
#define mPara_Manu_1374          1374           //                                    
#define mPara_Manu_1375          1375           //                                    
#define mPara_Manu_1376          1376           //                                    
#define mPara_Manu_1377          1377           //                                    
#define mPara_Manu_1378          1378           //                                    
#define mPara_Manu_1379          1379           //                                    
#define mPara_Manu_1380          1380           //                                    
#define mPara_Manu_1381          1381           //                                    
#define mPara_Manu_1382          1382           //                                    
#define mPara_Manu_1383          1383           //                                    
#define mPara_Manu_1384          1384           //                                    
#define mPara_Manu_1385          1385           //                                    
#define mPara_Manu_1386          1386           //                                    
#define mPara_Manu_1387          1387           //                                    
#define mPara_Manu_1388          1388           //                                    
#define mPara_Manu_1389          1389           //                                    
#define mPara_Manu_1390          1390           //                                    
#define mPara_Manu_1391          1391           //                                    
#define mPara_Manu_1392          1392           //                                    
#define mPara_Manu_1393          1393           //                                    
#define mPara_Manu_1394          1394           //                                    
#define mPara_Manu_1395          1395           //                                    
#define mPara_Manu_1396          1396           //                                    
#define mPara_Manu_1397          1397           //                                    
#define mPara_Manu_1398          1398           //                                    
#define mPara_Manu_1399          1399           //                                    
#define mPara_Manu_1400          1400           //                                    
#define mPara_Manu_1401          1401           //                                    
#define mPara_Manu_1402          1402           //                                    
#define mPara_Manu_1403          1403           //                                    
#define mPara_Manu_1404          1404           //                                    
#define mPara_Manu_1405          1405           //                                    
#define mPara_Manu_1406          1406           //                                    
#define mPara_Manu_1407          1407           //                                    
#define mPara_Manu_1408          1408           //                                    
#define mPara_Manu_1409          1409           //                                    
#define mPara_Manu_1410          1410           //                                    
#define mPara_Manu_1411          1411           //                                    
#define mPara_Manu_1412          1412           //                                    
#define mPara_Manu_1413          1413           //                                    
#define mPara_Manu_1414          1414           //                                    
#define mPara_Manu_1415          1415           //                                    
#define mPara_Manu_1416          1416           //                                    
#define mPara_Manu_1417          1417           //                                    
#define mPara_Manu_1418          1418           //                                    
#define mPara_Manu_1419          1419           //                                    
#define mPara_Manu_1420          1420           //                                    
#define mPara_Manu_1421          1421           //                                    
#define mPara_Manu_1422          1422           //                                    
#define mPara_Manu_1423          1423           //                                    
#define mPara_Manu_1424          1424           //                                    
#define mPara_Manu_1425          1425           //                                    
#define mPara_Manu_1426          1426           //                                    
#define mPara_Manu_1427          1427           //                                    
#define mPara_Manu_1428          1428           //                                    
#define mPara_Manu_1429          1429           //                                    
#define mPara_Manu_1430          1430           //                                    
#define mPara_Manu_1431          1431           //                                    
#define mPara_Manu_1432          1432           //                                    
#define mPara_Manu_1433          1433           //                                    
#define mPara_Manu_1434          1434           //                                    
#define mPara_Manu_1435          1435           //                                    
#define mPara_Manu_1436          1436           //                                    
#define mPara_Manu_1437          1437           //                                    
#define mPara_Manu_1438          1438           //                                    
#define mPara_Manu_1439          1439           //                                    
#define mPara_Manu_1440          1440           //                                    
#define mPara_Manu_1441          1441           //                                    
#define mPara_Manu_1442          1442           //                                    
#define mPara_Manu_1443          1443           //                                    
#define mPara_Manu_1444          1444           //                                    
#define mPara_Manu_1445          1445           //                                    
#define mPara_Manu_1446          1446           //                                    
#define mPara_Manu_1447          1447           //                                    
#define mPara_Manu_1448          1448           //                                    
#define mPara_Manu_1449          1449           //                                    
#define mPara_Manu_1450          1450           //                                    
#define mPara_Manu_1451          1451           //                                    
#define mPara_Manu_1452          1452           //                                    
#define mPara_Manu_1453          1453           //                                    
#define mPara_Manu_1454          1454           //                                    
#define mPara_Manu_1455          1455           //                                    
#define mPara_Manu_1456          1456           //                                    
#define mPara_Manu_1457          1457           //                                    
#define mPara_Manu_1458          1458           //                                    
#define mPara_Manu_1459          1459           //                                    
#define mPara_Manu_1460          1460           //                                    
#define mPara_Manu_1461          1461           //                                    
#define mPara_Manu_1462          1462           //                                    
#define mPara_Manu_1463          1463           //                                    
#define mPara_Manu_1464          1464           //                                    
#define mPara_Manu_1465          1465           //                                    
#define mPara_Manu_1466          1466           //                                    
#define mPara_Manu_1467          1467           //                                    
#define mPara_Manu_1468          1468           //                                    
#define mPara_Manu_1469          1469           //                                    
#define mPara_Manu_1470          1470           //                                    
#define mPara_Manu_1471          1471           //                                    
#define mPara_Manu_1472          1472           //                                    
#define mPara_Manu_1473          1473           //                                    
#define mPara_Manu_1474          1474           //                                    
#define mPara_Manu_1475          1475           //                                    
#define mPara_Manu_1476          1476           //                                    
#define mPara_Manu_1477          1477           //                                    
#define mPara_Manu_1478          1478           //                                    
#define mPara_Manu_1479          1479           //                                    
#define mPara_Manu_1480          1480           //                                    
#define mPara_Manu_1481          1481           //                                    
#define mPara_Manu_1482          1482           //                                    
#define mPara_Manu_1483          1483           //                                    
#define mPara_Manu_1484          1484           //                                    
#define mPara_Manu_1485          1485           //                                    
#define mPara_Manu_1486          1486           //                                    
#define mPara_Manu_1487          1487           //                                    
#define mPara_Manu_1488          1488           //                                    
#define mPara_Manu_1489          1489           //                                    
#define mPara_Manu_1490          1490           //                                    
#define mPara_Manu_1491          1491           //                                    
#define mPara_Manu_1492          1492           //                                    
#define mPara_Manu_1493          1493           //                                    
#define mPara_Manu_1494          1494           //                                    
#define mPara_Manu_1495          1495           //                                    
#define mPara_Manu_1496          1496           //                                    
#define mPara_Manu_1497          1497           //                                    
#define mPara_Manu_1498          1498           //                                    
#define mPara_Manu_1499          1499           //                                    
#define mPara_Manu_1500          1500           //                                    
#define mPara_Manu_1501          1501           //                                    
#define mPara_Manu_1502          1502           //                                    
#define mPara_Manu_1503          1503           //                                    
#define mPara_Manu_1504          1504           //                                    
#define mPara_Manu_1505          1505           //                                    
#define mPara_Manu_1506          1506           //                                    
#define mPara_Manu_1507          1507           //                                    
#define mPara_Manu_1508          1508           //                                    
#define mPara_Manu_1509          1509           //                                    
#define mPara_Manu_1510          1510           //                                    
#define mPara_Manu_1511          1511           //                                    
#define mPara_Manu_1512          1512           //                                    
#define mPara_Manu_1513          1513           //                                    
#define mPara_Manu_1514          1514           //                                    
#define mPara_Manu_1515          1515           //                                    
#define mPara_Manu_1516          1516           //                                    
#define mPara_Manu_1517          1517           //                                    
#define mPara_Manu_1518          1518           //                                    
#define mPara_Manu_1519          1519           //                                    
#define mPara_Manu_1520          1520           //                                    
#define mPara_Manu_1521          1521           //                                    
#define mPara_Manu_1522          1522           //                                    
#define mPara_Manu_1523          1523           //                                    
#define mPara_Manu_1524          1524           //                                    
#define mPara_Manu_1525          1525           //                                    
#define mPara_Manu_1526          1526           //                                    
#define mPara_Manu_1527          1527           //                                    
#define mPara_Manu_1528          1528           //                                    
#define mPara_Manu_1529          1529           //                                    
#define mPara_Manu_1530          1530           //                                    
#define mPara_Manu_1531          1531           //                                    
#define mPara_Manu_1532          1532           //                                    
#define mPara_Manu_1533          1533           //                                    
#define mPara_Manu_1534          1534           //                                    
#define mPara_Manu_1535          1535           //                                    
#define mPara_Manu_1536          1536           //                                    
#define mPara_Manu_1537          1537           //                                    
#define mPara_Manu_1538          1538           //                                    
#define mPara_Manu_1539          1539           //                                    
#define mPara_Manu_1540          1540           //                                    
#define mPara_Manu_1541          1541           //                                    
#define mPara_Manu_1542          1542           //                                    
#define mPara_Manu_1543          1543           //                                    
#define mPara_Manu_1544          1544           //                                    
#define mPara_Manu_1545          1545           //                                    
#define mPara_Manu_1546          1546           //                                    
#define mPara_Manu_1547          1547           //                                    
#define mPara_Manu_1548          1548           //                                    
#define mPara_Manu_1549          1549           //                                    
#define mPara_Manu_1550          1550           //                                    
#define mPara_Manu_1551          1551           //                                    
#define mPara_Manu_1552          1552           //                                    
#define mPara_Manu_1553          1553           //                                    
#define mPara_Manu_1554          1554           //                                    
#define mPara_Manu_1555          1555           //                                    
#define mPara_Manu_1556          1556           //                                    
#define mPara_Manu_1557          1557           //                                    
#define mPara_Manu_1558          1558           //                                    
#define mPara_Manu_1559          1559           //                                    
#define mPara_Manu_1560          1560           //                                    
#define mPara_Manu_1561          1561           //                                    
#define mPara_Manu_1562          1562           //                                    
#define mPara_Manu_1563          1563           //                                    
#define mPara_Manu_1564          1564           //                                    
#define mPara_Manu_1565          1565           //                                    
#define mPara_Manu_1566          1566           //                                    
#define mPara_Manu_1567          1567           //                                    
#define mPara_Manu_1568          1568           //                                    
#define mPara_Manu_1569          1569           //                                    
#define mPara_Manu_1570          1570           //                                    
#define mPara_Manu_1571          1571           //                                    
#define mPara_Manu_1572          1572           //                                    
#define mPara_Manu_1573          1573           //                                    
#define mPara_Manu_1574          1574           //                                    
#define mPara_Manu_1575          1575           //                                    
#define mPara_Manu_1576          1576           //                                    
#define mPara_Manu_1577          1577           //                                    
#define mPara_Manu_1578          1578           //                                    
#define mPara_Manu_1579          1579           //                                    
#define mPara_Manu_1580          1580           //                                    
#define mPara_Manu_1581          1581           //                                    
#define mPara_Manu_1582          1582           //                                    
#define mPara_Manu_1583          1583           //                                    
#define mPara_Manu_1584          1584           //                                    
#define mPara_Manu_1585          1585           //                                    
#define mPara_Manu_1586          1586           //                                    
#define mPara_Manu_1587          1587           //                                    
#define mPara_Manu_1588          1588           //                                    
#define mPara_Manu_1589          1589           //                                    
#define mPara_Manu_1590          1590           //                                    
#define mPara_Manu_1591          1591           //                                    
#define mPara_Manu_1592          1592           //                                    
#define mPara_Manu_1593          1593           //                                    
#define mPara_Manu_1594          1594           //                                    
#define mPara_Manu_1595          1595           //                                    
#define mPara_Manu_1596          1596           //                                    
#define mPara_Manu_1597          1597           //                                    
#define mPara_Manu_1598          1598           //                                    
#define mPara_Manu_1599          1599           //                                    
#define mPara_Manu_1600          1600           //                                    
#define mPara_Manu_1601          1601           //                                    
#define mPara_Manu_1602          1602           //                                    
#define mPara_Manu_1603          1603           //                                    
#define mPara_Manu_1604          1604           //                                    
#define mPara_Manu_1605          1605           //                                    
#define mPara_Manu_1606          1606           //                                    
#define mPara_Manu_1607          1607           //                                    
#define mPara_Manu_1608          1608           //                                    
#define mPara_Manu_1609          1609           //                                    
#define mPara_Manu_1610          1610           //                                    
#define mPara_Manu_1611          1611           //                                    
#define mPara_Manu_1612          1612           //                                    
#define mPara_Manu_1613          1613           //                                    
#define mPara_Manu_1614          1614           //                                    
#define mPara_Manu_1615          1615           //                                    
#define mPara_Manu_1616          1616           //                                    
#define mPara_Manu_1617          1617           //                                    
#define mPara_Manu_1618          1618           //                                    
#define mPara_Manu_1619          1619           //                                    
#define mPara_Manu_1620          1620           //                                    
#define mPara_Manu_1621          1621           //                                    
#define mPara_Manu_1622          1622           //                                    
#define mPara_Manu_1623          1623           //                                    
#define mPara_Manu_1624          1624           //                                    
#define mPara_Manu_1625          1625           //                                    
#define mPara_Manu_1626          1626           //                                    
#define mPara_Manu_1627          1627           //                                    
#define mPara_Manu_1628          1628           //                                    
#define mPara_Manu_1629          1629           //                                    
#define mPara_Manu_1630          1630           //                                    
#define mPara_Manu_1631          1631           //                                    
#define mPara_Manu_1632          1632           //                                    
#define mPara_Manu_1633          1633           //                                    
#define mPara_Manu_1634          1634           //                                    
#define mPara_Manu_1635          1635           //                                    
#define mPara_Manu_1636          1636           //                                    
#define mPara_Manu_1637          1637           //                                    
#define mPara_Manu_1638          1638           //                                    
#define mPara_Manu_1639          1639           //                                    
#define mPara_Manu_1640          1640           //                                    
#define mPara_Manu_1641          1641           //                                    
#define mPara_Manu_1642          1642           //                                    
#define mPara_Manu_1643          1643           //                                    
#define mPara_Manu_1644          1644           //                                    
#define mPara_Manu_1645          1645           //                                    
#define mPara_Manu_1646          1646           //                                    
#define mPara_Manu_1647          1647           //                                    
#define mPara_Manu_1648          1648           //                                    
#define mPara_Manu_1649          1649           //                                    
#define mPara_Manu_1650          1650           //                                    
#define mPara_Manu_1651          1651           //                                    
#define mPara_Manu_1652          1652           //                                    
#define mPara_Manu_1653          1653           //                                    
#define mPara_Manu_1654          1654           //                                    
#define mPara_Manu_1655          1655           //                                    
#define mPara_Manu_1656          1656           //                                    
#define mPara_Manu_1657          1657           //                                    
#define mPara_Manu_1658          1658           //                                    
#define mPara_Manu_1659          1659           //                                    
#define mPara_Manu_1660          1660           //                                    
#define mPara_Manu_1661          1661           //                                    
#define mPara_Manu_1662          1662           //                                    
#define mPara_Manu_1663          1663           //                                    
#define mPara_Manu_1664          1664           //                                    
#define mPara_Manu_1665          1665           //                                    
#define mPara_Manu_1666          1666           //                                    
#define mPara_Manu_1667          1667           //                                    
#define mPara_Manu_1668          1668           //                                    
#define mPara_Manu_1669          1669           //                                    
#define mPara_Manu_1670          1670           //                                    
#define mPara_Manu_1671          1671           //                                    
#define mPara_Manu_1672          1672           //                                    
#define mPara_Manu_1673          1673           //                                    
#define mPara_Manu_1674          1674           //                                    
#define mPara_Manu_1675          1675           //                                    
#define mPara_Manu_1676          1676           //                                    
#define mPara_Manu_1677          1677           //                                    
#define mPara_Manu_1678          1678           //                                    
#define mPara_Manu_1679          1679           //                                    
#define mPara_Manu_1680          1680           //                                    
#define mPara_Manu_1681          1681           //                                    
#define mPara_Manu_1682          1682           //                                    
#define mPara_Manu_1683          1683           //                                    
#define mPara_Manu_1684          1684           //                                    
#define mPara_Manu_1685          1685           //                                    
#define mPara_Manu_1686          1686           //                                    
#define mPara_Manu_1687          1687           //                                    
#define mPara_Manu_1688          1688           //                                    
#define mPara_Manu_1689          1689           //                                    
#define mPara_Manu_1690          1690           //                                    
#define mPara_Manu_1691          1691           //                                    
#define mPara_Manu_1692          1692           //                                    
#define mPara_Manu_1693          1693           //                                    
#define mPara_Manu_1694          1694           //                                    
#define mPara_Manu_1695          1695           //                                    
#define mPara_Manu_1696          1696           //                                    
#define mPara_Manu_1697          1697           //                                    
#define mPara_Manu_1698          1698           //                                    
#define mPara_Manu_1699          1699           //                                    
#define mPara_Manu_1700          1700           //                                    
#define mPara_Manu_1701          1701           //                                    
#define mPara_Manu_1702          1702           //                                    
#define mPara_Manu_1703          1703           //                                    
#define mPara_Manu_1704          1704           //                                    
#define mPara_Manu_1705          1705           //                                    
#define mPara_Manu_1706          1706           //                                    
#define mPara_Manu_1707          1707           //                                    
#define mPara_Manu_1708          1708           //                                    
#define mPara_Manu_1709          1709           //                                    
#define mPara_Manu_1710          1710           //                                    
#define mPara_Manu_1711          1711           //                                    
#define mPara_Manu_1712          1712           //                                    
#define mPara_Manu_1713          1713           //                                    
#define mPara_Manu_1714          1714           //                                    
#define mPara_Manu_1715          1715           //                                    
#define mPara_Manu_1716          1716           //                                    
#define mPara_Manu_1717          1717           //                                    
#define mPara_Manu_1718          1718           //                                    
#define mPara_Manu_1719          1719           //                                    
#define mPara_Manu_1720          1720           //                                    
#define mPara_Manu_1721          1721           //                                    
#define mPara_Manu_1722          1722           //                                    
#define mPara_Manu_1723          1723           //                                    
#define mPara_Manu_1724          1724           //                                    
#define mPara_Manu_1725          1725           //                                    
#define mPara_Manu_1726          1726           //                                    
#define mPara_Manu_1727          1727           //                                    
#define mPara_Manu_1728          1728           //                                    
#define mPara_Manu_1729          1729           //                                    
#define mPara_Manu_1730          1730           //                                    
#define mPara_Manu_1731          1731           //                                    
#define mPara_Manu_1732          1732           //                                    
#define mPara_Manu_1733          1733           //                                    
#define mPara_Manu_1734          1734           //                                    
#define mPara_Manu_1735          1735           //                                    
#define mPara_Manu_1736          1736           //                                    
#define mPara_Manu_1737          1737           //                                    
#define mPara_Manu_1738          1738           //                                    
#define mPara_Manu_1739          1739           //                                    
#define mPara_Manu_1740          1740           //                                    
#define mPara_Manu_1741          1741           //                                    
#define mPara_Manu_1742          1742           //                                    
#define mPara_Manu_1743          1743           //                                    
#define mPara_Manu_1744          1744           //                                    
#define mPara_Manu_1745          1745           //                                    
#define mPara_Manu_1746          1746           //                                    
#define mPara_Manu_1747          1747           //                                    
#define mPara_Manu_1748          1748           //                                    
#define mPara_Manu_1749          1749           //                                    
#define mPara_Manu_1750          1750           //                                    
#define mPara_Manu_1751          1751           //                                    
#define mPara_Manu_1752          1752           //                                    
#define mPara_Manu_1753          1753           //                                    
#define mPara_Manu_1754          1754           //                                    
#define mPara_Manu_1755          1755           //                                    
#define mPara_Manu_1756          1756           //                                    
#define mPara_Manu_1757          1757           //                                    
#define mPara_Manu_1758          1758           //                                    
#define mPara_Manu_1759          1759           //                                    
#define mPara_Manu_1760          1760           //                                    
#define mPara_Manu_1761          1761           //                                    
#define mPara_Manu_1762          1762           //                                    
#define mPara_Manu_1763          1763           //                                    
#define mPara_Manu_1764          1764           //                                    
#define mPara_Manu_1765          1765           //                                    
#define mPara_Manu_1766          1766           //                                    
#define mPara_Manu_1767          1767           //                                    
#define mPara_Manu_1768          1768           //                                    
#define mPara_Manu_1769          1769           //                                    
#define mPara_Manu_1770          1770           //                                    
#define mPara_Manu_1771          1771           //                                    
#define mPara_Manu_1772          1772           //                                    
#define mPara_Manu_1773          1773           //                                    
#define mPara_Manu_1774          1774           //                                    
#define mPara_Manu_1775          1775           //                                    
#define mPara_Manu_1776          1776           //                                    
#define mPara_Manu_1777          1777           //                                    
#define mPara_Manu_1778          1778           //                                    
#define mPara_Manu_1779          1779           //                                    
#define mPara_Manu_1780          1780           //                                    
#define mPara_Manu_1781          1781           //                                    
#define mPara_Manu_1782          1782           //                                    
#define mPara_Manu_1783          1783           //                                    
#define mPara_Manu_1784          1784           //                                    
#define mPara_Manu_1785          1785           //                                    
#define mPara_Manu_1786          1786           //                                    
#define mPara_Manu_1787          1787           //                                    
#define mPara_Manu_1788          1788           //                                    
#define mPara_Manu_1789          1789           //                                    
#define mPara_Manu_1790          1790           //                                    
#define mPara_Manu_1791          1791           //                                    
#define mPara_Manu_1792          1792           //                                    
#define mPara_Manu_1793          1793           //                                    
#define mPara_Manu_1794          1794           //                                    
#define mPara_Manu_1795          1795           //                                    
#define mPara_Manu_1796          1796           //                                    
#define mPara_Manu_1797          1797           //                                    
#define mPara_Manu_1798          1798           //                                    
#define mPara_Manu_1799          1799           //                                    
#define mPara_Manu_1800          1800           //                                    
#define mPara_Manu_1801          1801           //                                    
#define mPara_Manu_1802          1802           //                                    
#define mPara_Manu_1803          1803           //                                    
#define mPara_Manu_1804          1804           //                                    
#define mPara_Manu_1805          1805           //                                    
#define mPara_Manu_1806          1806           //                                    
#define mPara_Manu_1807          1807           //                                    
#define mPara_Manu_1808          1808           //                                    
#define mPara_Manu_1809          1809           //                                    
#define mPara_Manu_1810          1810           //                                    
#define mPara_Manu_1811          1811           //                                    
#define mPara_Manu_1812          1812           //                                    
#define mPara_Manu_1813          1813           //                                    
#define mPara_Manu_1814          1814           //                                    
#define mPara_Manu_1815          1815           //                                    
#define mPara_Manu_1816          1816           //                                    
#define mPara_Manu_1817          1817           //                                    
#define mPara_Manu_1818          1818           //                                    
#define mPara_Manu_1819          1819           //                                    
#define mPara_Manu_1820          1820           //                                    
#define mPara_Manu_1821          1821           //                                    
#define mPara_Manu_1822          1822           //                                    
#define mPara_Manu_1823          1823           //                                    
#define mPara_Manu_1824          1824           //                                    
#define mPara_Manu_1825          1825           //                                    
#define mPara_Manu_1826          1826           //                                    
#define mPara_Manu_1827          1827           //                                    
#define mPara_Manu_1828          1828           //                                    
#define mPara_Manu_1829          1829           //                                    
#define mPara_Manu_1830          1830           //                                    
#define mPara_Manu_1831          1831           //                                    
#define mPara_Manu_1832          1832           //                                    
#define mPara_Manu_1833          1833           //                                    
#define mPara_Manu_1834          1834           //                                    
#define mPara_Manu_1835          1835           //                                    
#define mPara_Manu_1836          1836           //                                    
#define mPara_Manu_1837          1837           //                                    
#define mPara_Manu_1838          1838           //                                    
#define mPara_Manu_1839          1839           //                                    
#define mPara_Manu_1840          1840           //                                    
#define mPara_Manu_1841          1841           //                                    
#define mPara_Manu_1842          1842           //                                    
#define mPara_Manu_1843          1843           //                                    
#define mPara_Manu_1844          1844           //                                    
#define mPara_Manu_1845          1845           //                                    
#define mPara_Manu_1846          1846           //                                    
#define mPara_Manu_1847          1847           //                                    
#define mPara_Manu_1848          1848           //                                    
#define mPara_Manu_1849          1849           //                                    
#define mPara_Manu_1850          1850           //                                    
#define mPara_Manu_1851          1851           //                                    
#define mPara_Manu_1852          1852           //                                    
#define mPara_Manu_1853          1853           //                                    
#define mPara_Manu_1854          1854           //                                    
#define mPara_Manu_1855          1855           //                                    
#define mPara_Manu_1856          1856           //                                    
#define mPara_Manu_1857          1857           //                                    
#define mPara_Manu_1858          1858           //                                    
#define mPara_Manu_1859          1859           //                                    
#define mPara_Manu_1860          1860           //                                    
#define mPara_Manu_1861          1861           //                                    
#define mPara_Manu_1862          1862           //                                    
#define mPara_Manu_1863          1863           //                                    
#define mPara_Manu_1864          1864           //                                    
#define mPara_Manu_1865          1865           //                                    
#define mPara_Manu_1866          1866           //                                    
#define mPara_Manu_1867          1867           //                                    
#define mPara_Manu_1868          1868           //                                    
#define mPara_Manu_1869          1869           //                                    
#define mPara_Manu_1870          1870           //                                    
#define mPara_Manu_1871          1871           //                                    
#define mPara_Manu_1872          1872           //                                    
#define mPara_Manu_1873          1873           //                                    
#define mPara_Manu_1874          1874           //                                    
#define mPara_Manu_1875          1875           //                                    
#define mPara_Manu_1876          1876           //                                    
#define mPara_Manu_1877          1877           //                                    
#define mPara_Manu_1878          1878           //                                    
#define mPara_Manu_1879          1879           //                                    
#define mPara_Manu_1880          1880           //                                    
#define mPara_Manu_1881          1881           //                                    
#define mPara_Manu_1882          1882           //                                    
#define mPara_Manu_1883          1883           //                                    
#define mPara_Manu_1884          1884           //                                    
#define mPara_Manu_1885          1885           //                                    
#define mPara_Manu_1886          1886           //                                    
#define mPara_Manu_1887          1887           //                                    
#define mPara_Manu_1888          1888           //                                    
#define mPara_Manu_1889          1889           //                                    
#define mPara_Manu_1890          1890           //                                    
#define mPara_Manu_1891          1891           //                                    
#define mPara_Manu_1892          1892           //                                    
#define mPara_Manu_1893          1893           //                                    
#define mPara_Manu_1894          1894           //                                    
#define mPara_Manu_1895          1895           //                                    
#define mPara_Manu_1896          1896           //                                    
#define mPara_Manu_1897          1897           //                                    
#define mPara_Manu_1898          1898           //                                    
#define mPara_MC_AricChange      1899           //关模算法选择                              关模算法：0-标准 1-智能关模
#define mPara_MO_AricChange      1900           //开模算法选择                              开模算法：0-标准 1-智能开模 2-智能辅助
#define mPara_MO_Sec1Pres        1901           //开模1段压力                              
#define mPara_MO_Sec1Flow        1902           //开模1段流量                              
#define mPara_MO_Sec2Pres        1903           //开模2段压力                              
#define mPara_MO_Sec2Flow        1904           //开模2段流量                              
#define mPara_MO_Sec2SPos        1905           //开模2段起始位置                            
#define mPara_MO_Sec3Flow        1906           //开模3段流量                              
#define mPara_MO_Sec3SPos        1907           //开模3段起始位置                            
#define mPara_MO_Sec4Flow        1908           //开模4段流量                              
#define mPara_MO_Sec4SPos        1909           //开模4段起始位置                            
#define mPara_MO_Sec5Flow        1910           //开模5段流量                              
#define mPara_MO_Sec5SPos        1911           //开模5段起始位置                            
#define mPara_Manu_1912          1912           //                                    
#define mPara_Manu_1913          1913           //                                    
#define mPara_MoldOpenDeceFlow   1914           //开模减速流量                              
#define mPara_MOAlg1_EndAcceRamp 1915           //算法1开模结束减速斜率                         开模结束减速斜率
#define mPara_Manu_1916          1916           //                                    
#define mPara_Manu_1917          1917           //                                    
#define mPara_Manu_1918          1918           //                                    
#define mPara_Manu_1919          1919           //                                    
#define mPara_Manu_1920          1920           //                                    
#define mPara_Manu_1921          1921           //                                    
#define mPara_Manu_1922          1922           //                                    
#define mPara_Manu_1923          1923           //                                    
#define mPara_Manu_1924          1924           //                                    
#define mPara_Manu_1925          1925           //                                    
#define mPara_Manu_1926          1926           //                                    
#define mPara_Manu_1927          1927           //                                    
#define mPara_Manu_1928          1928           //                                    
#define mPara_Manu_1929          1929           //                                    
#define mPara_Manu_1930          1930           //                                    
#define mPara_Manu_1931          1931           //                                    
#define mPara_Manu_1932          1932           //                                    
#define mPara_Manu_1933          1933           //                                    
#define mPara_Manu_1934          1934           //                                    
#define mPara_Manu_1935          1935           //                                    
#define mPara_Manu_1936          1936           //                                    
#define mPara_Manu_1937          1937           //                                    
#define mPara_Manu_1938          1938           //                                    
#define mPara_Manu_1939          1939           //                                    
#define mPara_Manu_1940          1940           //                                    
#define mPara_Manu_1941          1941           //                                    
#define mPara_Manu_1942          1942           //                                    
#define mPara_Manu_1943          1943           //                                    
#define mPara_Manu_1944          1944           //                                    
#define mPara_Manu_1945          1945           //                                    
#define mPara_Manu_1946          1946           //                                    
#define mPara_Manu_1947          1947           //                                    
#define mPara_Manu_1948          1948           //                                    
#define mPara_Manu_1949          1949           //                                    
#define mPara_Manu_1950          1950           //                                    
#define mPara_Manu_1951          1951           //                                    
#define mPara_Manu_1952          1952           //                                    
#define mPara_Manu_1953          1953           //                                    
#define mPara_Manu_1954          1954           //                                    
#define mPara_Manu_1955          1955           //                                    
#define mPara_Manu_1956          1956           //                                    
#define mPara_Manu_1957          1957           //                                    
#define mPara_Manu_1958          1958           //                                    
#define mPara_Manu_1959          1959           //                                    
#define mPara_Manu_1960          1960           //                                    
#define mPara_Manu_1961          1961           //                                    
#define mPara_Manu_1962          1962           //                                    
#define mPara_Manu_1963          1963           //                                    
#define mPara_Manu_1964          1964           //                                    
#define mPara_Manu_1965          1965           //                                    
#define mPara_Manu_1966          1966           //                                    
#define mPara_Manu_1967          1967           //                                    
#define mPara_Manu_1968          1968           //                                    
#define mPara_Manu_1969          1969           //                                    
#define mPara_Manu_1970          1970           //                                    
#define mPara_Manu_1971          1971           //                                    
#define mPara_Manu_1972          1972           //                                    
#define mPara_Manu_1973          1973           //                                    
#define mPara_Manu_1974          1974           //                                    
#define mPara_Manu_1975          1975           //                                    
#define mPara_Manu_1976          1976           //                                    
#define mPara_Manu_1977          1977           //                                    
#define mPara_Manu_1978          1978           //                                    
#define mPara_Manu_1979          1979           //                                    
#define mPara_Manu_1980          1980           //                                    
#define mPara_Manu_1981          1981           //                                    
#define mPara_Manu_1982          1982           //                                    
#define mPara_Manu_1983          1983           //                                    
#define mPara_Manu_1984          1984           //                                    
#define mPara_Manu_1985          1985           //                                    
#define mPara_Manu_1986          1986           //                                    
#define mPara_Manu_1987          1987           //                                    
#define mPara_Manu_1988          1988           //                                    
#define mPara_Manu_1989          1989           //                                    
#define mPara_Manu_1990          1990           //                                    
#define mPara_Manu_1991          1991           //                                    
#define mPara_Manu_1992          1992           //                                    
#define mPara_Manu_1993          1993           //                                    
#define mPara_Manu_1994          1994           //                                    
#define mPara_Manu_1995          1995           //                                    
#define mPara_Manu_1996          1996           //                                    
#define mPara_Manu_1997          1997           //                                    
#define mPara_Manu_1998          1998           //                                    
#define mPara_Manu_1999          1999           //                                    
#define mPara_Manu_2000          2000           //                                    
#define mPara_Manu_2001          2001           //                                    
#define mPara_Manu_2002          2002           //                                    
#define mPara_Manu_2003          2003           //                                    
#define mPara_Manu_2004          2004           //                                    
#define mPara_Manu_2005          2005           //                                    
#define mPara_Manu_2006          2006           //                                    
#define mPara_Manu_2007          2007           //                                    
#define mPara_Manu_2008          2008           //                                    
#define mPara_Manu_2009          2009           //                                    
#define mPara_Manu_2010          2010           //                                    
#define mPara_Manu_2011          2011           //                                    
#define mPara_Manu_2012          2012           //                                    
#define mPara_Manu_2013          2013           //                                    
#define mPara_Manu_2014          2014           //                                    
#define mPara_Manu_2015          2015           //                                    
#define mPara_Manu_2016          2016           //                                    
#define mPara_Manu_2017          2017           //                                    
#define mPara_Manu_2018          2018           //                                    
#define mPara_Manu_2019          2019           //                                    
#define mPara_Manu_2020          2020           //                                    
#define mPara_Manu_2021          2021           //                                    
#define mPara_Manu_2022          2022           //                                    
#define mPara_Manu_2023          2023           //                                    
#define mPara_Manu_2024          2024           //                                    
#define mPara_Manu_2025          2025           //                                    
#define mPara_Manu_2026          2026           //                                    
#define mPara_Manu_2027          2027           //                                    
#define mPara_Manu_2028          2028           //                                    
#define mPara_Manu_2029          2029           //                                    
#define mPara_CoolMoldOpenSel    2030           //冷却时开模选择                             应锐能加
#define mPara_CoolMoldOpenDly    2031           //冷却时开模延时                             应锐能加
#define mPara_CoolMoldOpenPos    2032           //冷却时开模距离                             应锐能加,指油缸距离
#define mPara_Manu_2033          2033           //                                    
#define mPara_Manu_2034          2034           //                                    
#define mPara_Manu_2035          2035           //                                    
#define mPara_Manu_2036          2036           //                                    
#define mPara_Manu_2037          2037           //                                    
#define mPara_Manu_2038          2038           //                                    
#define mPara_Manu_2039          2039           //                                    
#define mPara_Manu_2040          2040           //                                    
#define mPara_Manu_2041          2041           //                                    
#define mPara_Manu_2042          2042           //                                    
#define mPara_Manu_2043          2043           //                                    
#define mPara_Manu_2044          2044           //                                    
#define mPara_Manu_2045          2045           //                                    
#define mPara_Manu_2046          2046           //                                    
#define mPara_Manu_2047          2047           //                                    

//生产参数引用宏定义
#define Para_ManuParaSum         ManuPara[0]    //累加和校验码                              辅助用，下述参数累加和
#define Para_ManuParaLinkCode    ManuPara[1]    //互连代码                                辅助用，生产参数互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效
#define Para_ManuParaVer         ManuPara[2]    //版本号                                 辅助用，生产参数版本号
#define Para_ManuParaID          ManuPara[3]    //标识                                  辅助用，用于售后维护
#define Para_Manu_4              ManuPara[4]    //                                    
#define Para_MoldDataValid       ManuPara[5]    //模具资料无效                              模具资料管理用，0-模具资料无效 1-有效
#define Para_MoldNameC0          ManuPara[6]    //模具名称字符0                             模具资料管理用
#define Para_MoldNameC1          ManuPara[7]    //模具名称字符1                             模具资料管理用
#define Para_MoldNameC2          ManuPara[8]    //模具名称字符2                             模具资料管理用
#define Para_MoldNameC3          ManuPara[9]    //模具名称字符3                             模具资料管理用
#define Para_MoldNameC4          ManuPara[10]   //模具名称字符4                             模具资料管理用
#define Para_MoldNameC5          ManuPara[11]   //模具名称字符5                             模具资料管理用
#define Para_MoldNameC6          ManuPara[12]   //模具名称字符6                             模具资料管理用
#define Para_MoldNameC7          ManuPara[13]   //模具名称字符7                             模具资料管理用
#define Para_MoldNameC8          ManuPara[14]   //模具名称字符8                             模具资料管理用
#define Para_MoldNameC9          ManuPara[15]   //模具名称字符9                             模具资料管理用
#define Para_MoldNameC10         ManuPara[16]   //模具名称字符10                            模具资料管理用
#define Para_MoldNameC11         ManuPara[17]   //模具名称字符11                            模具资料管理用
#define Para_MaterialC0          ManuPara[18]   //产品材料字符0                             模具资料管理用
#define Para_MaterialC1          ManuPara[19]   //产品材料字符1                             模具资料管理用
#define Para_MaterialC2          ManuPara[20]   //产品材料字符2                             模具资料管理用
#define Para_MaterialC3          ManuPara[21]   //产品材料字符3                             模具资料管理用
#define Para_MaterialC4          ManuPara[22]   //产品材料字符4                             模具资料管理用
#define Para_MaterialC5          ManuPara[23]   //产品材料字符5                             模具资料管理用
#define Para_MaterialC6          ManuPara[24]   //产品材料字符6                             模具资料管理用
#define Para_MaterialC7          ManuPara[25]   //产品材料字符7                             模具资料管理用
#define Para_ColourC0            ManuPara[26]   //产品颜色字符0                             模具资料管理用
#define Para_ColourC1            ManuPara[27]   //产品颜色字符1                             模具资料管理用
#define Para_ColourC2            ManuPara[28]   //产品颜色字符2                             模具资料管理用
#define Para_ColourC3            ManuPara[29]   //产品颜色字符3                             模具资料管理用
#define Para_ColourC4            ManuPara[30]   //产品颜色字符4                             模具资料管理用
#define Para_ColourC5            ManuPara[31]   //产品颜色字符5                             模具资料管理用
#define Para_ColourC6            ManuPara[32]   //产品颜色字符6                             模具资料管理用
#define Para_ColourC7            ManuPara[33]   //产品颜色字符7                             模具资料管理用
#define Para_SaveDateC0          ManuPara[34]   //保存日期字符0                             模具资料管理用
#define Para_SaveDateC1          ManuPara[35]   //保存日期字符1                             模具资料管理用
#define Para_SaveDateC2          ManuPara[36]   //保存日期字符2                             模具资料管理用
#define Para_SaveDateC3          ManuPara[37]   //保存日期字符3                             模具资料管理用
#define Para_SaveDateC4          ManuPara[38]   //保存日期字符4                             模具资料管理用
#define Para_SaveDateC5          ManuPara[39]   //保存日期字符5                             模具资料管理用
#define Para_SaveDateC6          ManuPara[40]   //保存日期字符6                             模具资料管理用
#define Para_SaveDateC7          ManuPara[41]   //保存日期字符7                             模具资料管理用
#define Para_Manu_42             ManuPara[42]   //                                    
#define Para_Manu_43             ManuPara[43]   //                                    
#define Para_Manu_44             ManuPara[44]   //                                    
#define Para_Manu_45             ManuPara[45]   //                                    
#define Para_Manu_46             ManuPara[46]   //                                    
#define Para_Manu_47             ManuPara[47]   //                                    
#define Para_Manu_48             ManuPara[48]   //                                    
#define Para_Manu_49             ManuPara[49]   //                                    
#define Para_Manu_50             ManuPara[50]   //                                    
#define Para_Manu_51             ManuPara[51]   //                                    
#define Para_Manu_52             ManuPara[52]   //                                    
#define Para_Manu_53             ManuPara[53]   //                                    
#define Para_Manu_54             ManuPara[54]   //                                    
#define Para_Manu_55             ManuPara[55]   //                                    
#define Para_Manu_56             ManuPara[56]   //                                    
#define Para_Manu_57             ManuPara[57]   //                                    
#define Para_Manu_58             ManuPara[58]   //                                    
#define Para_Manu_59             ManuPara[59]   //                                    
#define Para_Manu_60             ManuPara[60]   //                                    
#define Para_Manu_61             ManuPara[61]   //                                    
#define Para_Manu_62             ManuPara[62]   //                                    
#define Para_Manu_63             ManuPara[63]   //                                    
#define Para_MoldCls1Pres        ManuPara[64]   //关模一段压力                              
#define Para_MoldCls1Flow        ManuPara[65]   //关模一段流量                              
#define Para_MoldCls2Pres        ManuPara[66]   //关模二段压力                              
#define Para_MoldCls2Flow        ManuPara[67]   //关模二段流量                              
#define Para_MoldCls2SPos        ManuPara[68]   //关模二段起始位置                            
#define Para_MoldCls3Pres        ManuPara[69]   //关模三段压力                              根据机型选用
#define Para_MoldCls3Flow        ManuPara[70]   //关模三段流量                              根据机型选用
#define Para_MoldCls3SPos        ManuPara[71]   //关模三段起始位置                            根据机型选用
#define Para_MoldClsLPPres       ManuPara[72]   //关模低压压力                              
#define Para_MoldClsLPFlow       ManuPara[73]   //关模低压流量                              
#define Para_MoldClsLPSPos       ManuPara[74]   //关模低压起始位置                            
#define Para_MoldClsHPPres       ManuPara[75]   //关模高压压力                              
#define Para_MoldClsHPFlow       ManuPara[76]   //关模高压流量                              
#define Para_MoldClsHPSPos       ManuPara[77]   //关模高压起始位置                            画面可设0.01mm，用以提高模保精度
#define Para_Manu_78             ManuPara[78]   //                                    
#define Para_MoldClsDiffSel      ManuPara[79]   //关模差动选择                              0-不用 1-使用
#define Para_MoldClsFastSel      ManuPara[80]   //关模快速选择                              0-不用 1-使用
#define Para_Manu_81             ManuPara[81]   //                                    
#define Para_Manu_82             ManuPara[82]   //                                    
#define Para_Manu_83             ManuPara[83]   //                                    
#define Para_MoldOpen1Pres       ManuPara[84]   //开模一段压力                              
#define Para_MoldOpen1Flow       ManuPara[85]   //开模一段流量                              
#define Para_MoldOpen2Pres       ManuPara[86]   //开模二段压力                              
#define Para_MoldOpen2Flow       ManuPara[87]   //开模二段流量                              
#define Para_MoldOpen2SPos       ManuPara[88]   //开模二段起始位置                            
#define Para_MoldOpen3Pres       ManuPara[89]   //开模三段压力                              根据机型选用
#define Para_MoldOpen3Flow       ManuPara[90]   //开模三段流量                              根据机型选用
#define Para_MoldOpen3SPos       ManuPara[91]   //开模三段起始位置                            根据机型选用
#define Para_MoldOpen4Pres       ManuPara[92]   //开模四段压力                              
#define Para_MoldOpen4Flow       ManuPara[93]   //开模四段流量                              
#define Para_MoldOpen4SPos       ManuPara[94]   //开模四段起始位置                            
#define Para_MoldOpen5Pres       ManuPara[95]   //开模五段压力                              
#define Para_MoldOpen5Flow       ManuPara[96]   //开模五段流量                              
#define Para_MoldOpen5SPos       ManuPara[97]   //开模五段起始位置                            
#define Para_MoldOpenEPos        ManuPara[98]   //开模结束位置                              
#define Para_MoldOpenDiffSel     ManuPara[99]   //开模差动选择                              0-不用 1-二~四段 2-二~五段 3-一~五段
#define Para_MoldOpenLinkSel     ManuPara[100]  //开模连动选择                              0-不用 1-顶针 2-中子A 3-中子B 4-中子C
#define Para_MoldOpenLinkPos     ManuPara[101]  //开模连动位置                              中子连动时，连动位置用中子出芯位置
#define Para_MoldOpenFastSel     ManuPara[102]  //开模快速选择                              0-不用 1-使用
#define Para_MOMedRobotStopTi    ManuPara[103]  //开模中途取件停留时间                          欧规机械手，中途取件停留时间
#define Para_MOMedRobotPos       ManuPara[104]  //开模中途取件位置                            欧规机械手，中途取件时位置
#define Para_MOMedRobotMode      ManuPara[105]  //开模中途取件模式                            欧规机械手，中途取件时模式：0-不用 1-不停取物 2-PB控制停留 3-计时停留
#define Para_MoldOpenMidEjeSel   ManuPara[106]  //开模中途托模选择                            特殊程序：开模中途插入托模动作 0-关 1-开-托-开 2-开-托-开-托
#define Para_MoldOpenMidEjePos   ManuPara[107]  //开模中途托模位置                            特殊程序：开模中途插入托模动作
#define Para_Inject1Pres         ManuPara[108]  //注射一段压力                              
#define Para_Inject1Flow         ManuPara[109]  //注射一段流量                              
#define Para_Inject2Pres         ManuPara[110]  //注射二段压力                              
#define Para_Inject2Flow         ManuPara[111]  //注射二段流量                              
#define Para_Inject2SPos         ManuPara[112]  //注射二段起始位置                            
#define Para_Inject3Pres         ManuPara[113]  //注射三段压力                              
#define Para_Inject3Flow         ManuPara[114]  //注射三段流量                              
#define Para_Inject3SPos         ManuPara[115]  //注射三段起始位置                            
#define Para_Inject4Pres         ManuPara[116]  //注射四段压力                              
#define Para_Inject4Flow         ManuPara[117]  //注射四段流量                              
#define Para_Inject4SPos         ManuPara[118]  //注射四段起始位置                            
#define Para_Inject5Pres         ManuPara[119]  //注射五段压力                              
#define Para_Inject5Flow         ManuPara[120]  //注射五段流量                              
#define Para_Inject5SPos         ManuPara[121]  //注射五段起始位置                            
#define Para_Inject6Pres         ManuPara[122]  //注射六段压力                              
#define Para_Inject6Flow         ManuPara[123]  //注射六段流量                              
#define Para_Inject6SPos         ManuPara[124]  //注射六段起始位置                            
#define Para_Inject7Pres         ManuPara[125]  //注射七段压力                              
#define Para_Inject7Flow         ManuPara[126]  //注射七段流量                              
#define Para_Inject7SPos         ManuPara[127]  //注射七段起始位置                            
#define Para_Inject8Pres         ManuPara[128]  //注射八段压力                              
#define Para_Inject8Flow         ManuPara[129]  //注射八段流量                              
#define Para_Inject8SPos         ManuPara[130]  //注射八段起始位置                            
#define Para_Inject9Pres         ManuPara[131]  //注射九段压力                              
#define Para_Inject9Flow         ManuPara[132]  //注射九段流量                              
#define Para_Inject9SPos         ManuPara[133]  //注射九段起始位置                            
#define Para_Inject10Pres        ManuPara[134]  //注射十段压力                              
#define Para_Inject10Flow        ManuPara[135]  //注射十段流量                              
#define Para_Inject10SPos        ManuPara[136]  //注射十段起始位置                            
#define Para_InjectEPos          ManuPara[137]  //注射结束位置                              
#define Para_InjectTi            ManuPara[138]  //注射时间                                注射一～十段总时间
#define Para_Manu_139            ManuPara[139]  //                                    
#define Para_Manu_140            ManuPara[140]  //                                    
#define Para_HoldPres1Pres       ManuPara[141]  //保压一段压力                              
#define Para_HoldPres1Flow       ManuPara[142]  //保压一段流量                              
#define Para_HoldPres1Ti         ManuPara[143]  //保压一段时间                              
#define Para_HoldPres2Pres       ManuPara[144]  //保压二段压力                              
#define Para_HoldPres2Flow       ManuPara[145]  //保压二段流量                              
#define Para_HoldPres2Ti         ManuPara[146]  //保压二段时间                              
#define Para_HoldPres3Pres       ManuPara[147]  //保压三段压力                              
#define Para_HoldPres3Flow       ManuPara[148]  //保压三段流量                              
#define Para_HoldPres3Ti         ManuPara[149]  //保压三段时间                              
#define Para_HoldPres4Pres       ManuPara[150]  //保压四段压力                              
#define Para_HoldPres4Flow       ManuPara[151]  //保压四段流量                              
#define Para_HoldPres4Ti         ManuPara[152]  //保压四段时间                              
#define Para_HoldPres5Pres       ManuPara[153]  //保压五段压力                              
#define Para_HoldPres5Flow       ManuPara[154]  //保压五段流量                              
#define Para_HoldPres5Ti         ManuPara[155]  //保压五段时间                              
#define Para_HoldPres6Pres       ManuPara[156]  //保压六段压力                              
#define Para_HoldPres6Flow       ManuPara[157]  //保压六段流量                              
#define Para_HoldPres6Ti         ManuPara[158]  //保压六段时间                              
#define Para_HoldPres7Pres       ManuPara[159]  //保压七段压力                              
#define Para_HoldPres7Flow       ManuPara[160]  //保压七段流量                              
#define Para_HoldPres7Ti         ManuPara[161]  //保压七段时间                              
#define Para_HoldPres8Pres       ManuPara[162]  //保压八段压力                              
#define Para_HoldPres8Flow       ManuPara[163]  //保压八段流量                              
#define Para_HoldPres8Ti         ManuPara[164]  //保压八段时间                              
#define Para_HoldPres9Pres       ManuPara[165]  //保压九段压力                              
#define Para_HoldPres9Flow       ManuPara[166]  //保压九段流量                              
#define Para_HoldPres9Ti         ManuPara[167]  //保压九段时间                              
#define Para_HoldPres10Pres      ManuPara[168]  //保压十段压力                              
#define Para_HoldPres10Flow      ManuPara[169]  //保压十段流量                              
#define Para_HoldPres10Ti        ManuPara[170]  //保压十段时间                              
#define Para_HoldPresSwtMode     ManuPara[171]  //保压切换模式                              0-位置时间 1-时间 2-压力
#define Para_HoldPresSwtPres     ManuPara[172]  //保压切换压力                              
#define Para_InjBefNozOffset     ManuPara[173]  //座进前注射距离                             座台进前先用射一注射该距离
#define Para_InjBefNozTi         ManuPara[174]  //座进前注射计时                             座台进前先用射一注射该时间
#define Para_InjFastSel          ManuPara[175]  //射出快速功能                              0-不用 1-使用
#define Para_AccSel              ManuPara[176]  //射出增压功能                              即蓄能器使用选择，0-不用 1-使用
#define Para_InjHPRelSel         ManuPara[177]  //保压解压功能                              0-不用 1-使用，保压动作时“保压解压”阀也开
#define Para_Manu_178            ManuPara[178]  //                                    
#define Para_Manu_179            ManuPara[179]  //                                    
#define Para_Manu_180            ManuPara[180]  //                                    
#define Para_ChargeLink          ManuPara[181]  //储料连动选择                              
#define Para_Charge1Pres         ManuPara[182]  //储料一段压力                              
#define Para_Charge1Flow         ManuPara[183]  //储料一段流量                              
#define Para_Charge1BPres        ManuPara[184]  //储料一段背压                              实际上限为40或60
#define Para_Charge2Pres         ManuPara[185]  //储料二段压力                              
#define Para_Charge2Flow         ManuPara[186]  //储料二段流量                              
#define Para_Charge2BPres        ManuPara[187]  //储料二段背压                              
#define Para_Charge2SPos         ManuPara[188]  //储料二段起始位置                            
#define Para_Charge3Pres         ManuPara[189]  //储料三段压力                              
#define Para_Charge3Flow         ManuPara[190]  //储料三段流量                              
#define Para_Charge3BPres        ManuPara[191]  //储料三段背压                              
#define Para_Charge3SPos         ManuPara[192]  //储料三段起始位置                            
#define Para_Charge4Pres         ManuPara[193]  //储料四段压力                              
#define Para_Charge4Flow         ManuPara[194]  //储料四段流量                              
#define Para_Charge4BPres        ManuPara[195]  //储料四段背压                              
#define Para_Charge4SPos         ManuPara[196]  //储料四段起始位置                            
#define Para_Charge5Pres         ManuPara[197]  //储料五段压力                              
#define Para_Charge5Flow         ManuPara[198]  //储料五段流量                              
#define Para_Charge5BPres        ManuPara[199]  //储料五段背压                              
#define Para_Charge5SPos         ManuPara[200]  //储料五段起始位置                            
#define Para_Charge6Pres         ManuPara[201]  //储料六段压力                              
#define Para_Charge6Flow         ManuPara[202]  //储料六段流量                              
#define Para_Charge6BPres        ManuPara[203]  //储料六段背压                              
#define Para_Charge6SPos         ManuPara[204]  //储料六段起始位置                            
#define Para_Charge7Pres         ManuPara[205]  //储料七段压力                              
#define Para_Charge7Flow         ManuPara[206]  //储料七段流量                              
#define Para_Charge7BPres        ManuPara[207]  //储料七段背压                              
#define Para_Charge7SPos         ManuPara[208]  //储料七段起始位置                            
#define Para_Charge8Pres         ManuPara[209]  //储料八段压力                              
#define Para_Charge8Flow         ManuPara[210]  //储料八段流量                              
#define Para_Charge8BPres        ManuPara[211]  //储料八段背压                              
#define Para_Charge8SPos         ManuPara[212]  //储料八段起始位置                            
#define Para_Charge9Pres         ManuPara[213]  //储料九段压力                              
#define Para_Charge9Flow         ManuPara[214]  //储料九段流量                              
#define Para_Charge9BPres        ManuPara[215]  //储料九段背压                              
#define Para_Charge9SPos         ManuPara[216]  //储料九段起始位置                            
#define Para_Charge10Pres        ManuPara[217]  //储料十段压力                              
#define Para_Charge10Flow        ManuPara[218]  //储料十段流量                              
#define Para_Charge10BPres       ManuPara[219]  //储料十段背压                              
#define Para_Charge10SPos        ManuPara[220]  //储料十段起始位置                            
#define Para_ChargeEPos          ManuPara[221]  //储料结束位置                              
#define Para_Manu_222            ManuPara[222]  //                                    
#define Para_ProdCoolTi          ManuPara[223]  //模具冷却时间                              即产品冷却时间，从保压结束后开始计时
#define Para_CoolBefChgTi        ManuPara[224]  //储前冷却时间                              
#define Para_ReChgCtrlMode       ManuPara[225]  //再次储料控制模式                            0-位置 1-时间
#define Para_ReChgEPos           ManuPara[226]  //再次储料结束位置                            
#define Para_ReChgTi             ManuPara[227]  //再次储料时间                              
#define Para_ChgBackPresValSel   ManuPara[228]  //储料背压阀                               0-不用 1-使用，用于实现储料零背压 2-自动时使用
#define Para_SemiAutoChgAftEjeMode ManuPara[229]//半自动二次储料模式                           0-关闭 1-时间 2-位置，半自动时储料分二次进行，冷却期间一次、顶出后再次（利用开关门的时间）
#define Para_SemiAutoChgFirstTi  ManuPara[230]  //半自动二次储料首次时间                         
#define Para_SemiAutoChgFirstPos ManuPara[231]  //半自动二次储料首次位置                         
#define Para_SuckBackPres        ManuPara[232]  //射退压力                                
#define Para_SuckBackFlow        ManuPara[233]  //射退流量                                
#define Para_SuckBackTi          ManuPara[234]  //射退时间                                
#define Para_SuckBackOffset      ManuPara[235]  //射退距离                                为相对位置，限值：行程-储料终止位置
#define Para_SuckBackCtrlMode    ManuPara[236]  //射退控制方式                              0-位置 1-时间
#define Para_SuckBackOcc         ManuPara[237]  //射退时机                                0-储后 1-冷后
#define Para_EjeForPauseOcc      ManuPara[238]  //托模暂停时机                              0-托模一段暂停	1-1次托进完	2-2次托进完	3-1次托退完	4-2次托退完
#define Para_SBBefChgOffset      ManuPara[239]  //储料前射退距离                             为相对位置，限值：行程-储料终止位置
#define Para_SBBefChgTi          ManuPara[240]  //储料前射退时间                             
#define Para_SBBefChgCtrlMode    ManuPara[241]  //储前射退控制方式                            0-位置 1-时间
#define Para_EjeFor1PauseTi      ManuPara[242]  //托进一段暂停时间                            应制笔模具：托进一段、停顿该时间(等机械手)、再托进二段(机械手一起前进)
#define Para_EjeFor2StepSel      ManuPara[243]  //二级托模进选择                             特殊托模：托进分二次完成，避免产品顶出太快。（第一次顶进到一段结束，第二次才顶到位）
#define Para_EjeCutMatDly        ManuPara[244]  //托模切料延时                              
#define Para_EjeCutMatRetPres    ManuPara[245]  //托模切料退压力                             
#define Para_EjeCutMatRetFlow    ManuPara[246]  //托模切料退流量                             
#define Para_EjeFor1Pres         ManuPara[247]  //托进一段压力                              
#define Para_EjeFor1Flow         ManuPara[248]  //托进一段流量                              
#define Para_EjeFor2Pres         ManuPara[249]  //托进二段压力                              
#define Para_EjeFor2Flow         ManuPara[250]  //托进二段流量                              
#define Para_EjeFor2SPos         ManuPara[251]  //托进二段起始位置                            
#define Para_EjeForEPos          ManuPara[252]  //托进结束位置                              
#define Para_EjeRet1Pres         ManuPara[253]  //托退一段压力                              
#define Para_EjeRet1Flow         ManuPara[254]  //托退一段流量                              
#define Para_EjeRet2Pres         ManuPara[255]  //托退二段压力                              
#define Para_EjeRet2Flow         ManuPara[256]  //托退二段流量                              
#define Para_EjeRet2SPos         ManuPara[257]  //托退二段起始位置                            
#define Para_EjeRetEPos          ManuPara[258]  //托退结束位置                              
#define Para_EjeForDly           ManuPara[259]  //托进延时时间                              托进前延时
#define Para_EjeRetDly           ManuPara[260]  //托退延时时间                              托退前延时
#define Para_EjectMode           ManuPara[261]  //托模方式                                0-不用 1-停留 2-定次 3-震动
#define Para_EjectCnt            ManuPara[262]  //托模次数                                
#define Para_ReEjeSel            ManuPara[263]  //再次托模选择                              0-不用 1-使用
#define Para_EjeRetMode          ManuPara[264]  //托退模式                                0-标准 1-二段托退(特殊托退：退到托退一即结束) 2-不托退(特殊托退：类似停留，但允许自动方式)
#define Para_ProdSnrSel          ManuPara[265]  //电眼检出功能                              即电眼方式选择，0-不用 1-使用
#define Para_RobotSel            ManuPara[266]  //机械手选择                               0-不用 1-使用
#define Para_AutoCycDly          ManuPara[267]  //再循环延时                               
#define Para_AutoGateSel         ManuPara[268]  //自动安全门选择                             0-不用 1-使用
#define Para_HydNozSel           ManuPara[269]  //液压喷嘴使用                              0-不用 1-使用
#define Para_DisAutoMode         ManuPara[270]  //禁止全自动模式                             0-允许 1-禁止，如果禁止，则只允许半自动，保护特殊模具
#define Para_SMMOAutoGateLinkSel ManuPara[271]  //半自动开模时自动门连动                         0-不连动、1-连动、2-开模后连动
#define Para_AMoldShotNum        ManuPara[272]  //每模产品数                               
#define Para_PackageNum          ManuPara[273]  //包装产品数                               
#define Para_DstShotNum          ManuPara[274]  //生产产品数                               模数*每模产品数
#define Para_EjeStepMode         ManuPara[275]  //逐步托模模式                              0-不用、1-使用。托模阻力很大的模具，分多次逐步顶进。即托进到顶针不会前进了，退回再次托进。
#define Para_EjeCutMatSel        ManuPara[276]  //托模切料功能选择                            0-关闭,1-注射后,2-保一后,3-保二后,4-保压后,5-保压时(即保压时托模阀ON，压力流量同保压)
#define Para_EjeCutMatPres       ManuPara[277]  //托模切料压力                              
#define Para_EjeCutMatFlow       ManuPara[278]  //托模切料流量                              
#define Para_EjeCutMatEPos       ManuPara[279]  //托模切料位置                              结束位置
#define Para_EjeCutMatMode       ManuPara[280]  //托模切料模式                              0-只托进 1-托进后托退
#define Para_NozFor1Pres         ManuPara[281]  //座进一段压力                              
#define Para_NozFor1Flow         ManuPara[282]  //座进一段流量                              
#define Para_NozFor2Pres         ManuPara[283]  //座进二段压力                              
#define Para_NozFor2Flow         ManuPara[284]  //座进二段流量                              
#define Para_NozFor2SPos         ManuPara[285]  //座进二段起始位置                            
#define Para_NozForEPos          ManuPara[286]  //座进结束位置                              
#define Para_NozForSlowPres      ManuPara[287]  //座进慢速压力                              
#define Para_NozForSlowFlow      ManuPara[288]  //座进慢速流量                              
#define Para_NozForSlowTi        ManuPara[289]  //座进慢速时间                              
#define Para_NozRet1Pres         ManuPara[290]  //座退一段压力                              
#define Para_NozRet1Flow         ManuPara[291]  //座退一段流量                              
#define Para_NozRet2Pres         ManuPara[292]  //座退二段压力                              
#define Para_NozRet2Flow         ManuPara[293]  //座退二段流量                              
#define Para_NozRet2SPos         ManuPara[294]  //座退二段起始位置                            
#define Para_NozRetEPos          ManuPara[295]  //座退结束位置                              
#define Para_NozRetTi            ManuPara[296]  //座退时间                                
#define Para_NozRetDly           ManuPara[297]  //座退延时                                
#define Para_NozRetMode          ManuPara[298]  //座退模式                                0-不用 1-储后 2-开模前 3-射后
#define Para_NozRetCtrlMode      ManuPara[299]  //座退控制模式                              0-时间 1-位置
#define Para_Manu_300            ManuPara[300]  //                                    
#define Para_Manu_301            ManuPara[301]  //                                    
#define Para_MoldThinPres        ManuPara[302]  //调模进压力                               
#define Para_MoldThinFlow        ManuPara[303]  //调模进流量                               
#define Para_MoldThickPres       ManuPara[304]  //调模退压力                               
#define Para_MoldThickFlow       ManuPara[305]  //调模退流量                               
#define Para_MoldAdjSlowFlow     ManuPara[306]  //调模慢速流量                              
#define Para_MoldThickSet        ManuPara[307]  //设置模厚                                装配模厚尺时，设置模厚
#define Para_Manu_308            ManuPara[308]  //                                    
#define Para_Manu_309            ManuPara[309]  //                                    
#define Para_Air1Ti              ManuPara[310]  //A组吹气时间                              
#define Para_Air1Dly             ManuPara[311]  //A组吹气延迟时间                            
#define Para_Air1SPos            ManuPara[312]  //A组吹气起始位置                            
#define Para_Air2Ti              ManuPara[313]  //B组吹气时间                              
#define Para_Air2Dly             ManuPara[314]  //B组吹气延迟时间                            
#define Para_Air2SPos            ManuPara[315]  //B组吹气起始位置                            
#define Para_Air3Ti              ManuPara[316]  //C组吹气时间                              
#define Para_Air3Dly             ManuPara[317]  //C组吹气延迟时间                            
#define Para_Air3SPos            ManuPara[318]  //C组吹气起始位置                            
#define Para_Air4Ti              ManuPara[319]  //D组吹气时间                              
#define Para_Air4Dly             ManuPara[320]  //D组吹气延迟时间                            
#define Para_Air4SPos            ManuPara[321]  //D组吹气起始位置                            
#define Para_Air5Ti              ManuPara[322]  //E组吹气时间                              
#define Para_Air5Dly             ManuPara[323]  //E组吹气延迟时间                            
#define Para_Air5SPos            ManuPara[324]  //E组吹气起始位置                            
#define Para_Air6Ti              ManuPara[325]  //F组吹气时间                              
#define Para_Air6Dly             ManuPara[326]  //F组吹气延迟时间                            
#define Para_Air6SPos            ManuPara[327]  //F组吹气起始位置                            
#define Para_Air1KeySel          ManuPara[328]  //吹气1键选择                              0-吹气1   1-吹气3   2-吹气4
#define Para_Air2KeySel          ManuPara[329]  //吹气2键选择                              0-吹气2   1-吹气4   2-吹气5
#define Para_Air6Occ             ManuPara[330]  //F组吹气时机                              0-正常 1-储料
#define Para_Manu_331            ManuPara[331]  //                                    
#define Para_Manu_332            ManuPara[332]  //                                    
#define Para_AirInjSPos          ManuPara[333]  //气辅射出起始位置                            
#define Para_AirInjTi            ManuPara[334]  //气辅射出时间                              
#define Para_InjCompMode         ManuPara[335]  //压缩注射模式                              压缩注射模式:合模到设定位置－注射－继续合模
#define Para_InjCompMoldPos      ManuPara[336]  //压缩注射模板位置                            压缩注射时合模到该位置结束合模，进行注射，然后合模。
#define Para_InjCompInjEPos      ManuPara[337]  //压缩注射注射结束位置                          压缩注射时注射到该位置结束，然后合模。如果该位置=保压位置，则继续注射时直接转保压。
#define Para_ExhMode             ManuPara[338]  //排气模式                                0-不用 1-射后 2-保一后 3-保二后 4-保压后 5-注射中
#define Para_ExhHoldTi           ManuPara[339]  //排气后延时                               排气保持时间
#define Para_ExhDly              ManuPara[340]  //排气前延时                               经该延时后开始排气开模
#define Para_ExhMoldOpenEPos     ManuPara[341]  //排气开模位置                              排气开模结束位置
#define Para_ExhMoldOpenTi       ManuPara[342]  //排气开模时间                              排气开模的时间
#define Para_ExhInjSPos1         ManuPara[343]  //注射排气位置1                             注射排气起始位置1，注射中排气使用
#define Para_ExhInjSPos2         ManuPara[344]  //注射排气位置2                             注射排气起始位置2，注射中排气使用
#define Para_PrgChgPres          ManuPara[345]  //清料储料压力                              
#define Para_PrgChgFlow          ManuPara[346]  //清料储料流量                              
#define Para_PrgChgTi            ManuPara[347]  //清料储料时间                              
#define Para_PrgInjPres          ManuPara[348]  //清料注射压力                              
#define Para_PrgInjFlow          ManuPara[349]  //清料注射流量                              
#define Para_PrgInjTi            ManuPara[350]  //清料注射时间                              
#define Para_PrgSuckPres         ManuPara[351]  //清料射退压力                              
#define Para_PrgSuckFlow         ManuPara[352]  //清料射退流量                              
#define Para_PrgSuckTi           ManuPara[353]  //清料射退时间                              
#define Para_PurgeSel            ManuPara[354]  //清料功能选择                              0-不用 1-使用
#define Para_PurgeCnt            ManuPara[355]  //清料次数                                清料动作循环的次数，时间或次数到结束清料
#define Para_PurgeTi             ManuPara[356]  //清料时间                                清料动作的总时间，时间或次数到结束清料
#define Para_Manu_357            ManuPara[357]  //                                    
#define Para_BMCMode             ManuPara[358]  //BMC模式                               0-关闭、1-使用
#define Para_BMC_FeedInPres      ManuPara[359]  //加料进压力                               BMC机器
#define Para_BMC_FeedInFlow      ManuPara[360]  //加料进流量                               BMC机器
#define Para_BMC_FeedOutPres     ManuPara[361]  //加料退压力                               BMC机器
#define Para_BMC_FeedOutFlow     ManuPara[362]  //加料退流量                               BMC机器
#define Para_SteamInjMode        ManuPara[363]  //蒸汽注射模式                              0-关闭、1-使用
#define Para_SteamHtrOnDly       ManuPara[364]  //蒸汽加热开延时                             蒸汽注射
#define Para_SteamCoolOnDly      ManuPara[365]  //蒸汽冷却开延时                             蒸汽注射
#define Para_SteamCoolOffDly     ManuPara[366]  //蒸汽冷却关延时                             蒸汽注射
#define Para_Manu_367            ManuPara[367]  //                                    
#define Para_Manu_368            ManuPara[368]  //                                    
#define Para_Manu_369            ManuPara[369]  //                                    
#define Para_Zone1HtrCtrlMode    ManuPara[370]  //一段加热控温模式                            0-自动 1-比例
#define Para_Zone1HtrPeriod      ManuPara[371]  //一段加热周期                              
#define Para_Zone1HtrPercent     ManuPara[372]  //一段加热比例                              
#define Para_Zone1SetTemp        ManuPara[373]  //一段设置温度                              
#define Para_Zone2SetTemp        ManuPara[374]  //二段设置温度                              
#define Para_Zone3SetTemp        ManuPara[375]  //三段设置温度                              
#define Para_Zone4SetTemp        ManuPara[376]  //四段设置温度                              
#define Para_Zone5SetTemp        ManuPara[377]  //五段设置温度                              
#define Para_Zone6SetTemp        ManuPara[378]  //六段设置温度                              
#define Para_Zone7SetTemp        ManuPara[379]  //七段设置温度                              
#define Para_Zone8SetTemp        ManuPara[380]  //八段设置温度                              
#define Para_Zone9SetTemp        ManuPara[381]  //九段设置温度                              
#define Para_Zone10SetTemp       ManuPara[382]  //十段设置温度                              
#define Para_Zone11SetTemp       ManuPara[383]  //十一段设置温度                             
#define Para_Zone12SetTemp       ManuPara[384]  //十二段设置温度                             
#define Para_Zone13SetTemp       ManuPara[385]  //十三段设置温度                             
#define Para_Zone14SetTemp       ManuPara[386]  //十四段设置温度                             
#define Para_Zone15SetTemp       ManuPara[387]  //十五段设置温度                             
#define Para_Zone16SetTemp       ManuPara[388]  //十六段设置温度                             
#define Para_Manu_389            ManuPara[389]  //                                    
#define Para_Manu_390            ManuPara[390]  //                                    
#define Para_Manu_391            ManuPara[391]  //                                    
#define Para_Manu_392            ManuPara[392]  //                                    
#define Para_Manu_393            ManuPara[393]  //                                    
#define Para_Manu_394            ManuPara[394]  //                                    
#define Para_Manu_395            ManuPara[395]  //                                    
#define Para_Manu_396            ManuPara[396]  //                                    
#define Para_Manu_397            ManuPara[397]  //                                    
#define Para_Manu_398            ManuPara[398]  //                                    
#define Para_Manu_399            ManuPara[399]  //                                    
#define Para_Manu_400            ManuPara[400]  //                                    
#define Para_Manu_401            ManuPara[401]  //                                    
#define Para_Manu_402            ManuPara[402]  //                                    
#define Para_Manu_403            ManuPara[403]  //                                    
#define Para_Manu_404            ManuPara[404]  //                                    
#define Para_Manu_405            ManuPara[405]  //                                    
#define Para_Manu_406            ManuPara[406]  //                                    
#define Para_Manu_407            ManuPara[407]  //                                    
#define Para_Manu_408            ManuPara[408]  //                                    
#define Para_Manu_409            ManuPara[409]  //                                    
#define Para_KeepWarmSel         ManuPara[410]  //保温选择                                0-不用 1-使用
#define Para_KeepWarmTemp        ManuPara[411]  //保温温度                                
#define Para_ZoneCoolProtTi      ManuPara[412]  //防冷启动时间                              各段温度进入偏差范围后开始此计时
#define Para_Manu_413            ManuPara[413]  //                                    
#define Para_Manu_414            ManuPara[414]  //                                    
#define Para_Manu_415            ManuPara[415]  //                                    
#define Para_ProdSnr1Sel         ManuPara[416]  //检物电眼1使用                             0-不用 1使用
#define Para_ProdSnr2Sel         ManuPara[417]  //检物电眼2使用                             0-不用 1使用
#define Para_ProdSnr3Sel         ManuPara[418]  //检物电眼3使用                             0-不用 1使用
#define Para_ProdSnr4Sel         ManuPara[419]  //检物电眼4使用                             0-不用 1使用
#define Para_Manu_420            ManuPara[420]  //                                    
#define Para_Manu_421            ManuPara[421]  //                                    
#define Para_RobotCoreSel        ManuPara[422]  //配合机械手中子                             0-不用 1-中子A 2-中子B
#define Para_Manu_423            ManuPara[423]  //                                    
#define Para_CoreSpecFunCode     ManuPara[424]  //特殊中子代码                              0-标准 1-A:托-出 3-A:托-出-入 5-A:出-入 7-AB:托-出 8-A:注射-入芯 9-B:注射-入芯 10-B:托-出-取-入
#define Para_CoreSpecPara1       ManuPara[425]  //特殊中子参数一                             通常用于时间
#define Para_CoreSpecPara2       ManuPara[426]  //特殊中子参数二                             通常用于时间
#define Para_Manu_427            ManuPara[427]  //                                    
#define Para_Core3KeySel         ManuPara[428]  //中子C键选择                              中子C进、退键对应的中子号：0-中子C  1-中子D
#define Para_ScrewEndSlowCnt     ManuPara[429]  //绞牙结束前慢速齿数                           绞牙结束前，以慢速绞牙该计数
#define Para_ScrewSlowFlow       ManuPara[430]  //绞牙慢速流量                              慢速绞牙时流量
#define Para_Manu_431            ManuPara[431]  //                                    
#define Para_CoreInSeq1          ManuPara[432]  //第1个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq2          ManuPara[433]  //第2个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq3          ManuPara[434]  //第3个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq4          ManuPara[435]  //第4个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq5          ManuPara[436]  //第5个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq6          ManuPara[437]  //第6个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq7          ManuPara[438]  //第7个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_CoreInSeq8          ManuPara[439]  //第8个进中子                              中子进顺序，对应第x个进的中子号，必须连续且顺序排列
#define Para_Manu_440            ManuPara[440]  //                                    
#define Para_Manu_441            ManuPara[441]  //                                    
#define Para_CoreOutSeq1         ManuPara[442]  //第1个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq2         ManuPara[443]  //第2个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq3         ManuPara[444]  //第3个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq4         ManuPara[445]  //第4个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq5         ManuPara[446]  //第5个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq6         ManuPara[447]  //第6个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq7         ManuPara[448]  //第7个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_CoreOutSeq8         ManuPara[449]  //第8个退中子                              中子进顺序，对应第x个退的中子号，必须连续且顺序排列
#define Para_Manu_450            ManuPara[450]  //                                    
#define Para_Manu_451            ManuPara[451]  //                                    
#define Para_Core1Fun            ManuPara[452]  //中子1功能                               0-不用 1-中子 2-绞牙
#define Para_Core1InjHold        ManuPara[453]  //中子1注射保持                             0-不保持 1-保持
#define Para_Core1Reverse        ManuPara[454]  //中子1反向                               0-不用 1-使用
#define Para_Manu_455            ManuPara[455]  //                                    
#define Para_Manu_456            ManuPara[456]  //                                    
#define Para_Core1InOcc          ManuPara[457]  //中子1进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core1InCtrlMode     ManuPara[458]  //中子1进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core1InPres         ManuPara[459]  //中子1进压力                              
#define Para_Core1InFlow         ManuPara[460]  //中子1进流量                              
#define Para_Core1InTi           ManuPara[461]  //中子1进时间                              
#define Para_Core1InCnt          ManuPara[462]  //中子1进计数                              
#define Para_Core1InSPos         ManuPara[463]  //中子1进起始位置                            
#define Para_Core1InStartDly     ManuPara[464]  //中子1进前延时                             
#define Para_Manu_465            ManuPara[465]  //                                    
#define Para_Core1OutOcc         ManuPara[466]  //中子1出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core1OutCtrlMode    ManuPara[467]  //中子1出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core1OutPres        ManuPara[468]  //中子1出压力                              
#define Para_Core1OutFlow        ManuPara[469]  //中子1出流量                              
#define Para_Core1OutTi          ManuPara[470]  //中子1出时间                              
#define Para_Core1OutCnt         ManuPara[471]  //中子1出计数                              
#define Para_Core1OutSPos        ManuPara[472]  //中子1出起始位置                            
#define Para_Core1OutECnt        ManuPara[473]  //中子1退二计数                             
#define Para_Core1OutETi         ManuPara[474]  //中子1退二计时                             
#define Para_Core1OutStartDly    ManuPara[475]  //中子1退前延时                             
#define Para_Manu_476            ManuPara[476]  //                                    
#define Para_Manu_477            ManuPara[477]  //                                    
#define Para_Core2Fun            ManuPara[478]  //中子2功能                               0-不用 1-中子 2-绞牙
#define Para_Core2InjHold        ManuPara[479]  //中子2注射保持                             0-不保持 1-保持
#define Para_Core2Reverse        ManuPara[480]  //中子2反向                               0-不用 1-使用
#define Para_Manu_481            ManuPara[481]  //                                    
#define Para_Manu_482            ManuPara[482]  //                                    
#define Para_Core2InOcc          ManuPara[483]  //中子2进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core2InCtrlMode     ManuPara[484]  //中子2进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core2InPres         ManuPara[485]  //中子2进压力                              
#define Para_Core2InFlow         ManuPara[486]  //中子2进流量                              
#define Para_Core2InTi           ManuPara[487]  //中子2进时间                              
#define Para_Core2InCnt          ManuPara[488]  //中子2进计数                              
#define Para_Core2InSPos         ManuPara[489]  //中子2进起始位置                            
#define Para_Core2InStartDly     ManuPara[490]  //中子2进前延时                             
#define Para_Manu_491            ManuPara[491]  //                                    
#define Para_Core2OutOcc         ManuPara[492]  //中子2出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core2OutCtrlMode    ManuPara[493]  //中子2出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core2OutPres        ManuPara[494]  //中子2出压力                              
#define Para_Core2OutFlow        ManuPara[495]  //中子2出流量                              
#define Para_Core2OutTi          ManuPara[496]  //中子2出时间                              
#define Para_Core2OutCnt         ManuPara[497]  //中子2出计数                              
#define Para_Core2OutSPos        ManuPara[498]  //中子2出起始位置                            
#define Para_Core2OutStartDly    ManuPara[499]  //中子2退前延时                             
#define Para_Manu_500            ManuPara[500]  //                                    
#define Para_Manu_501            ManuPara[501]  //                                    
#define Para_Manu_502            ManuPara[502]  //                                    
#define Para_Core3Fun            ManuPara[503]  //中子3功能                               0-不用 1-中子 2-绞牙
#define Para_Core3InjHold        ManuPara[504]  //中子3注射保持                             0-不保持 1-保持
#define Para_Core3Reverse        ManuPara[505]  //中子3反向                               0-不用 1-使用
#define Para_Manu_506            ManuPara[506]  //                                    
#define Para_Manu_507            ManuPara[507]  //                                    
#define Para_Core3InOcc          ManuPara[508]  //中子3进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core3InCtrlMode     ManuPara[509]  //中子3进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core3InPres         ManuPara[510]  //中子3进压力                              
#define Para_Core3InFlow         ManuPara[511]  //中子3进流量                              
#define Para_Core3InTi           ManuPara[512]  //中子3进时间                              
#define Para_Core3InCnt          ManuPara[513]  //中子3进计数                              
#define Para_Core3InSPos         ManuPara[514]  //中子3进起始位置                            
#define Para_Core3InStartDly     ManuPara[515]  //中子3进前延时                             
#define Para_Manu_516            ManuPara[516]  //                                    
#define Para_Core3OutOcc         ManuPara[517]  //中子3出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core3OutCtrlMode    ManuPara[518]  //中子3出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core3OutPres        ManuPara[519]  //中子3出压力                              
#define Para_Core3OutFlow        ManuPara[520]  //中子3出流量                              
#define Para_Core3OutTi          ManuPara[521]  //中子3出时间                              
#define Para_Core3OutCnt         ManuPara[522]  //中子3出计数                              
#define Para_Core3OutSPos        ManuPara[523]  //中子3出起始位置                            
#define Para_Core3OutStartDly    ManuPara[524]  //中子3退前延时                             
#define Para_Manu_525            ManuPara[525]  //                                    
#define Para_Manu_526            ManuPara[526]  //                                    
#define Para_Manu_527            ManuPara[527]  //                                    
#define Para_Core4Fun            ManuPara[528]  //中子4功能                               0-不用 1-中子 2-绞牙
#define Para_Core4InjHold        ManuPara[529]  //中子4注射保持                             0-不保持 1-保持
#define Para_Core4Reverse        ManuPara[530]  //中子4反向                               0-不用 1-使用
#define Para_Manu_531            ManuPara[531]  //                                    
#define Para_Manu_532            ManuPara[532]  //                                    
#define Para_Core4InOcc          ManuPara[533]  //中子4进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core4InCtrlMode     ManuPara[534]  //中子4进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core4InPres         ManuPara[535]  //中子4进压力                              
#define Para_Core4InFlow         ManuPara[536]  //中子4进流量                              
#define Para_Core4InTi           ManuPara[537]  //中子4进时间                              
#define Para_Core4InCnt          ManuPara[538]  //中子4进计数                              
#define Para_Core4InSPos         ManuPara[539]  //中子4进起始位置                            
#define Para_Core4InStartDly     ManuPara[540]  //中子4进前延时                             
#define Para_Manu_541            ManuPara[541]  //                                    
#define Para_Core4OutOcc         ManuPara[542]  //中子4出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core4OutCtrlMode    ManuPara[543]  //中子4出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core4OutPres        ManuPara[544]  //中子4出压力                              
#define Para_Core4OutFlow        ManuPara[545]  //中子4出流量                              
#define Para_Core4OutTi          ManuPara[546]  //中子4出时间                              
#define Para_Core4OutCnt         ManuPara[547]  //中子4出计数                              
#define Para_Core4OutSPos        ManuPara[548]  //中子4出起始位置                            
#define Para_Core4OutStartDly    ManuPara[549]  //中子4退前延时                             
#define Para_Manu_550            ManuPara[550]  //                                    
#define Para_Manu_551            ManuPara[551]  //                                    
#define Para_Manu_552            ManuPara[552]  //                                    
#define Para_Core5Fun            ManuPara[553]  //中子5功能                               0-不用 1-中子 2-绞牙
#define Para_Core5InjHold        ManuPara[554]  //中子5注射保持                             0-不保持 1-保持
#define Para_Core5Reverse        ManuPara[555]  //中子5反向                               0-不用 1-使用
#define Para_Manu_556            ManuPara[556]  //                                    
#define Para_Manu_557            ManuPara[557]  //                                    
#define Para_Core5InOcc          ManuPara[558]  //中子5进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core5InCtrlMode     ManuPara[559]  //中子5进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core5InPres         ManuPara[560]  //中子5进压力                              
#define Para_Core5InFlow         ManuPara[561]  //中子5进流量                              
#define Para_Core5InTi           ManuPara[562]  //中子5进时间                              
#define Para_Core5InCnt          ManuPara[563]  //中子5进计数                              
#define Para_Core5InSPos         ManuPara[564]  //中子5进起始位置                            
#define Para_Core5InStartDly     ManuPara[565]  //中子5进前延时                             
#define Para_Manu_566            ManuPara[566]  //                                    
#define Para_Core5OutOcc         ManuPara[567]  //中子5出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core5OutCtrlMode    ManuPara[568]  //中子5出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core5OutPres        ManuPara[569]  //中子5出压力                              
#define Para_Core5OutFlow        ManuPara[570]  //中子5出流量                              
#define Para_Core5OutTi          ManuPara[571]  //中子5出时间                              
#define Para_Core5OutCnt         ManuPara[572]  //中子5出计数                              
#define Para_Core5OutSPos        ManuPara[573]  //中子5出起始位置                            
#define Para_Core5OutStartDly    ManuPara[574]  //中子5退前延时                             
#define Para_Manu_575            ManuPara[575]  //                                    
#define Para_Manu_576            ManuPara[576]  //                                    
#define Para_Manu_577            ManuPara[577]  //                                    
#define Para_Core6Fun            ManuPara[578]  //中子6功能                               0-不用 1-中子 2-绞牙
#define Para_Core6InjHold        ManuPara[579]  //中子6注射保持                             0-不保持 1-保持
#define Para_Core6Reverse        ManuPara[580]  //中子6反向                               0-不用 1-使用
#define Para_Manu_581            ManuPara[581]  //                                    
#define Para_Manu_582            ManuPara[582]  //                                    
#define Para_Core6InOcc          ManuPara[583]  //中子6进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core6InCtrlMode     ManuPara[584]  //中子6进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core6InPres         ManuPara[585]  //中子6进压力                              
#define Para_Core6InFlow         ManuPara[586]  //中子6进流量                              
#define Para_Core6InTi           ManuPara[587]  //中子6进时间                              
#define Para_Core6InCnt          ManuPara[588]  //中子6进计数                              
#define Para_Core6InSPos         ManuPara[589]  //中子6进起始位置                            
#define Para_Core6InStartDly     ManuPara[590]  //中子6进前延时                             
#define Para_Manu_591            ManuPara[591]  //                                    
#define Para_Core6OutOcc         ManuPara[592]  //中子6出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core6OutCtrlMode    ManuPara[593]  //中子6出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core6OutPres        ManuPara[594]  //中子6出压力                              
#define Para_Core6OutFlow        ManuPara[595]  //中子6出流量                              
#define Para_Core6OutTi          ManuPara[596]  //中子6出时间                              
#define Para_Core6OutCnt         ManuPara[597]  //中子6出计数                              
#define Para_Core6OutSPos        ManuPara[598]  //中子6出起始位置                            
#define Para_Core6OutStartDly    ManuPara[599]  //中子6退前延时                             
#define Para_Manu_600            ManuPara[600]  //                                    
#define Para_Manu_601            ManuPara[601]  //                                    
#define Para_Manu_602            ManuPara[602]  //                                    
#define Para_Core7Fun            ManuPara[603]  //中子7功能                               0-不用 1-中子 2-绞牙
#define Para_Core7InjHold        ManuPara[604]  //中子7注射保持                             0-不保持 1-保持
#define Para_Core7Reverse        ManuPara[605]  //中子7反向                               0-不用 1-使用
#define Para_Manu_606            ManuPara[606]  //                                    
#define Para_Manu_607            ManuPara[607]  //                                    
#define Para_Core7InOcc          ManuPara[608]  //中子7进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core7InCtrlMode     ManuPara[609]  //中子7进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core7InPres         ManuPara[610]  //中子7进压力                              
#define Para_Core7InFlow         ManuPara[611]  //中子7进流量                              
#define Para_Core7InTi           ManuPara[612]  //中子7进时间                              
#define Para_Core7InCnt          ManuPara[613]  //中子7进计数                              
#define Para_Core7InSPos         ManuPara[614]  //中子7进起始位置                            
#define Para_Core7InStartDly     ManuPara[615]  //中子7进前延时                             
#define Para_Manu_616            ManuPara[616]  //                                    
#define Para_Core7OutOcc         ManuPara[617]  //中子7出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core7OutCtrlMode    ManuPara[618]  //中子7出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core7OutPres        ManuPara[619]  //中子7出压力                              
#define Para_Core7OutFlow        ManuPara[620]  //中子7出流量                              
#define Para_Core7OutTi          ManuPara[621]  //中子7出时间                              
#define Para_Core7OutCnt         ManuPara[622]  //中子7出计数                              
#define Para_Core7OutSPos        ManuPara[623]  //中子7出起始位置                            
#define Para_Core7OutStartDly    ManuPara[624]  //中子7退前延时                             
#define Para_Manu_625            ManuPara[625]  //                                    
#define Para_Manu_626            ManuPara[626]  //                                    
#define Para_Manu_627            ManuPara[627]  //                                    
#define Para_Core8Fun            ManuPara[628]  //中子8功能                               0-不用 1-中子 2-绞牙
#define Para_Core8InjHold        ManuPara[629]  //中子8注射保持                             0-不保持 1-保持
#define Para_Core8Reverse        ManuPara[630]  //中子8反向                               0-不用 1-使用
#define Para_Manu_631            ManuPara[631]  //                                    
#define Para_Manu_632            ManuPara[632]  //                                    
#define Para_Core8InOcc          ManuPara[633]  //中子8进时机                              0-关模前 1-中途 2-关模后 
#define Para_Core8InCtrlMode     ManuPara[634]  //中子8进控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core8InPres         ManuPara[635]  //中子8进压力                              
#define Para_Core8InFlow         ManuPara[636]  //中子8进流量                              
#define Para_Core8InTi           ManuPara[637]  //中子8进时间                              
#define Para_Core8InCnt          ManuPara[638]  //中子8进计数                              
#define Para_Core8InSPos         ManuPara[639]  //中子8进起始位置                            
#define Para_Core8InStartDly     ManuPara[640]  //中子8进前延时                             
#define Para_Manu_641            ManuPara[641]  //                                    
#define Para_Core8OutOcc         ManuPara[642]  //中子8出时机                              0-开模前 1-中途 2-开模后 
#define Para_Core8OutCtrlMode    ManuPara[643]  //中子8出控制方式                            0-行程 1-时间 0-计数(绞牙时)
#define Para_Core8OutPres        ManuPara[644]  //中子8出压力                              
#define Para_Core8OutFlow        ManuPara[645]  //中子8出流量                              
#define Para_Core8OutTi          ManuPara[646]  //中子8出时间                              
#define Para_Core8OutCnt         ManuPara[647]  //中子8出计数                              
#define Para_Core8OutSPos        ManuPara[648]  //中子8出起始位置                            
#define Para_Core8OutStartDly    ManuPara[649]  //中子8退前延时                             
#define Para_Manu_650            ManuPara[650]  //                                    
#define Para_Manu_651            ManuPara[651]  //                                    
#define Para_Manu_652            ManuPara[652]  //                                    
#define Para_Manu_653            ManuPara[653]  //                                    
#define Para_Manu_654            ManuPara[654]  //                                    
#define Para_CoreOutMoldOpenTi   ManuPara[655]  //出芯开模时间                              海天北化眼镜脚套机专用：开模中途出芯,但动作位置采用时间控制
#define Para_CoreOutMoldOpenPosMode ManuPara[656]//出芯开模方式                             海天北化眼镜脚套机专用：开模出芯的动作位置选择使用模板位置或油缸位置 0-模板 1-油缸
#define Para_InjCoreInLinkDly    ManuPara[657]  //注射入芯连动延时                            海天北化眼镜脚套机专用：特殊中子 A:注射-入芯连动 时，延时该时间再入芯连动
#define Para_Manu_658            ManuPara[658]  //                                    
#define Para_Manu_659            ManuPara[659]  //                                    
#define Para_POut1OnOcc          ManuPara[660]  //自由输出点1ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut2OnOcc          ManuPara[661]  //自由输出点2ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut3OnOcc          ManuPara[662]  //自由输出点3ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut4OnOcc          ManuPara[663]  //自由输出点4ON时机                          0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut1OffOcc         ManuPara[664]  //自由输出点1OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut2OffOcc         ManuPara[665]  //自由输出点2OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut3OffOcc         ManuPara[666]  //自由输出点3OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut4OffOcc         ManuPara[667]  //自由输出点4OFF时机                         0-关闭 1-合始 2-合终 3-射始 4-射终 5-储始 6-储终 7-开始 8-开终 9-托始 10-顶进时 11-托终
#define Para_POut1OnDly          ManuPara[668]  //自由输出点1On延时                          
#define Para_POut2OnDly          ManuPara[669]  //自由输出点2On延时                          
#define Para_POut3OnDly          ManuPara[670]  //自由输出点3On延时                          
#define Para_POut4OnDly          ManuPara[671]  //自由输出点4On延时                          
#define Para_POut1OnTi           ManuPara[672]  //自由输出点1On时间                          
#define Para_POut2OnTi           ManuPara[673]  //自由输出点2On时间                          
#define Para_POut3OnTi           ManuPara[674]  //自由输出点3On时间                          
#define Para_POut4OnTi           ManuPara[675]  //自由输出点4On时间                          
#define Para_Manu_676            ManuPara[676]  //                                    
#define Para_Manu_677            ManuPara[677]  //                                    
#define Para_Manu_678            ManuPara[678]  //                                    
#define Para_Manu_679            ManuPara[679]  //                                    
#define Para_VacuumizeSel        ManuPara[680]  //抽真空启动方式选择                           0-不用；1-时间；2-位置
#define Para_VacuumizeDly        ManuPara[681]  //抽真空启动延时                             抽真空启动延时
#define Para_VacuumizePos        ManuPara[682]  //抽真空启动位置                             抽真空启动位置
#define Para_Manu_683            ManuPara[683]  //                                    
#define Para_Manu_684            ManuPara[684]  //                                    
#define Para_Manu_685            ManuPara[685]  //                                    
#define Para_EjeChargeSel        ManuPara[686]  //托模后储料选择                             0-不用 1-使用
#define Para_AutoRejectCnt       ManuPara[687]  //转自动不良品输出模数                          手动转自动后不良品输出模数；0-不输出，非0-输出
#define Para_MoldSlidBlockMonPos ManuPara[688]  //滑块监控位置                              模具滑块监控位置
#define Para_MoldOpenAuxil_BJTi  ManuPara[689]  //开模辅助输出时间                            博劲开模辅助：开模同时输出，时间可调
#define Para_MD6InjectMode       ManuPara[690]  //注射模式                                MD6卡注射模式：0-不用 1-使用
#define Para_InjDiffSel          ManuPara[691]  //注射差动选择                              0-不用 1-使用
#define Para_MoldClsLPRelSel     ManuPara[692]  //模保泄压                                盈泰：0-不用 1-使用
#define Para_MoldOpenBPTi_YT     ManuPara[693]  //开模背压计时                              盈泰
#define Para_Manu_694            ManuPara[694]  //                                    
#define Para_Manu_695            ManuPara[695]  //                                    
#define Para_Manu_696            ManuPara[696]  //                                    
#define Para_Manu_697            ManuPara[697]  //                                    
#define Para_Manu_698            ManuPara[698]  //                                    
#define Para_Manu_699            ManuPara[699]  //                                    
#define Para_SemiAutoChkBackSG   ManuPara[700]  //半自动后安全门模式                           应特殊机：0-半自动循环开始检查前安全门；1-半自动循环开始检查后安全门
#define Para_SGOpenCls2ndTimeSel ManuPara[701]  //安全门开关第2次选择                          0-不用 1-使用。托模选停留，托模进后提示开关安全门。该功能选使用后，关模前会提示第二次开关安全门
#define Para_Manu_702            ManuPara[702]  //                                    
#define Para_Manu_703            ManuPara[703]  //                                    
#define Para_Manu_704            ManuPara[704]  //                                    
#define Para_Manu_705            ManuPara[705]  //                                    
#define Para_Manu_706            ManuPara[706]  //                                    
#define Para_Manu_707            ManuPara[707]  //                                    
#define Para_Manu_708            ManuPara[708]  //                                    
#define Para_Manu_709            ManuPara[709]  //                                    
#define Para_Manu_710            ManuPara[710]  //                                    
#define Para_Manu_711            ManuPara[711]  //                                    
#define Para_Manu_712            ManuPara[712]  //                                    
#define Para_Manu_713            ManuPara[713]  //                                    
#define Para_CycTiOLP            ManuPara[714]  //循环时间超差处理                            0-不用 1-提示 2-警报
#define Para_MoldClsTiOLP        ManuPara[715]  //关模时间超差处理                            0-不用 1-提示 2-警报
#define Para_MoldClsHPTiOLP      ManuPara[716]  //关模高压时间超差处理                          0-不用 1-提示 2-警报
#define Para_MoldClsLPTiOLP      ManuPara[717]  //关模低压时间超差处理                          0-不用 1-提示 2-警报
#define Para_MoldOpenTiOLP       ManuPara[718]  //开模时间超差处理                            0-不用 1-提示 2-警报
#define Para_MoldOpenEPosOLP     ManuPara[719]  //开模结束位置超差处理                          0-不用 1-提示 2-警报
#define Para_EjeForTiOLP         ManuPara[720]  //托模时间超差处理                            0-不用 1-提示 2-警报
#define Para_InjectTiOLP         ManuPara[721]  //注射时间超差处理                            0-不用 1-提示 2-警报
#define Para_InjectEPosOLP       ManuPara[722]  //注射结束位置超差处理                          0-不用 1-提示 2-警报
#define Para_InjectSpdOLP        ManuPara[723]  //注射速度超差处理                            0-不用 1-提示 2-警报
#define Para_HoldPresTiOLP       ManuPara[724]  //保压时间超差处理                            0-不用 1-提示 2-警报
#define Para_HoldPresSPosOLP     ManuPara[725]  //保压起始位置超差处理                          0-不用 1-提示 2-警报
#define Para_HoldPresSPresOLP    ManuPara[726]  //保压起始压力超差处理                          0-不用 1-提示 2-警报
#define Para_SuckBackTiOLP       ManuPara[727]  //射退时间超差处理                            0-不用 1-提示 2-警报
#define Para_ChargeTiOLP         ManuPara[728]  //储料时间超差处理                            0-不用 1-提示 2-警报
#define Para_ChargeEPosOLP       ManuPara[729]  //储料结束位置超差处理                          0-不用 1-提示 2-警报
#define Para_ChargeRPMOLP        ManuPara[730]  //储料最高转速超差处理                          0-不用 1-提示 2-警报
#define Para_InjPeakPresOLP      ManuPara[731]  //注射峰值压力超差处理                          0-不用 1-提示 2-警报
#define Para_Manu_732            ManuPara[732]  //                                    
#define Para_Manu_733            ManuPara[733]  //                                    
#define Para_Manu_734            ManuPara[734]  //                                    
#define Para_Manu_735            ManuPara[735]  //                                    
#define Para_Manu_736            ManuPara[736]  //                                    
#define Para_Manu_737            ManuPara[737]  //                                    
#define Para_Manu_738            ManuPara[738]  //                                    
#define Para_CycTiDev            ManuPara[739]  //循环时间允许偏差                            
#define Para_MoldClsTiDev        ManuPara[740]  //关模时间允许偏差                            
#define Para_MoldClsHPTiDev      ManuPara[741]  //关模高压时间允许偏差                          
#define Para_MoldClsLPTiDev      ManuPara[742]  //关模低压时间允许偏差                          
#define Para_MoldOpenTiDev       ManuPara[743]  //开模时间允许偏差                            
#define Para_MoldOpenEPosDev     ManuPara[744]  //开模结束位置允许偏差                          
#define Para_EjeForTiDev         ManuPara[745]  //托模时间允许偏差                            
#define Para_InjectTiDev         ManuPara[746]  //注射时间允许偏差                            射出及保压时间允许偏差
#define Para_InjectEPosDev       ManuPara[747]  //注射结束位置允许偏差                          射出及保压结束位置允许偏差，即射出监测
#define Para_InjectSpdDev        ManuPara[748]  //注射速度允许偏差                            射出最高速度允许偏差
#define Para_HoldPresTiDev       ManuPara[749]  //保压时间允许偏差                            注射(不含保压)时间允许偏差，即转保压前注射时间
#define Para_HoldPresSPosDev     ManuPara[750]  //保压起始位置允许偏差                          
#define Para_HoldPresSPresDev    ManuPara[751]  //保压起始压力允许偏差                          转保压压力允许偏差
#define Para_SuckBackTiDev       ManuPara[752]  //射退时间允许偏差                            
#define Para_ChargeTiDev         ManuPara[753]  //储料时间允许偏差                            
#define Para_ChargeEPosDev       ManuPara[754]  //储料结束位置允许偏差                          
#define Para_ChargeRPMDev        ManuPara[755]  //储料最高转速允许偏差                          
#define Para_InjPeakPresDev      ManuPara[756]  //注射峰值压力允许偏差                          注射峰值压力允许偏差
#define Para_Manu_757            ManuPara[757]  //                                    
#define Para_Manu_758            ManuPara[758]  //                                    
#define Para_Manu_759            ManuPara[759]  //                                    
#define Para_Manu_760            ManuPara[760]  //                                    
#define Para_Manu_761            ManuPara[761]  //                                    
#define Para_Manu_762            ManuPara[762]  //                                    
#define Para_Manu_763            ManuPara[763]  //                                    
#define Para_CycTiStd            ManuPara[764]  //循环标准时间                              监测数据由用户输入生成方式时引用
#define Para_MoldClsTiStd        ManuPara[765]  //关模标准时间                              监测数据由用户输入生成方式时引用
#define Para_MoldClsHPTiStd      ManuPara[766]  //关模高压标准时间                            监测数据由用户输入生成方式时引用
#define Para_MoldClsLPTiStd      ManuPara[767]  //关模低压标准时间                            监测数据由用户输入生成方式时引用
#define Para_MoldOpenTiStd       ManuPara[768]  //开模标准时间                              监测数据由用户输入生成方式时引用
#define Para_MoldOpenEPosStd     ManuPara[769]  //开模标准结束位置                            监测数据由用户输入生成方式时引用
#define Para_EjeForTiStd         ManuPara[770]  //托模标准时间                              监测数据由用户输入生成方式时引用
#define Para_InjectTiStd         ManuPara[771]  //注射标准时间                              监测数据由用户输入生成方式时引用
#define Para_InjectEPosStd       ManuPara[772]  //注射标准结束位置                            射出及保压结束位置，即射出监测
#define Para_InjectSpdStd        ManuPara[773]  //注射标准速度                              射出最高速度
#define Para_HoldPresTiStd       ManuPara[774]  //保压标准时间                              注射(不含保压)时间，即转保压前注射时间
#define Para_HoldPresSPosStd     ManuPara[775]  //保压标准起始位置                            
#define Para_HoldPresSPresStd    ManuPara[776]  //保压标准起始压力                            转保压压力
#define Para_SuckBackTiStd       ManuPara[777]  //射退标准时间                              
#define Para_ChargeTiStd         ManuPara[778]  //储料标准时间                              
#define Para_ChargeEPosStd       ManuPara[779]  //储料标准结束位置                            
#define Para_ChargeRPMStd        ManuPara[780]  //储料标准最高转速                            
#define Para_InjPeakPresStd      ManuPara[781]  //注射峰值标准压力                            
#define Para_Manu_782            ManuPara[782]  //                                    
#define Para_Manu_783            ManuPara[783]  //                                    
#define Para_Manu_784            ManuPara[784]  //                                    
#define Para_Manu_785            ManuPara[785]  //                                    
#define Para_Manu_786            ManuPara[786]  //                                    
#define Para_Manu_787            ManuPara[787]  //                                    
#define Para_Manu_788            ManuPara[788]  //                                    
#define Para_Manu_789            ManuPara[789]  //                                    
#define Para_Manu_790            ManuPara[790]  //                                    
#define Para_Manu_791            ManuPara[791]  //                                    
#define Para_Manu_792            ManuPara[792]  //                                    
#define Para_Manu_793            ManuPara[793]  //                                    
#define Para_Manu_794            ManuPara[794]  //                                    
#define Para_Manu_795            ManuPara[795]  //                                    
#define Para_Manu_796            ManuPara[796]  //                                    
#define Para_Manu_797            ManuPara[797]  //                                    
#define Para_Manu_798            ManuPara[798]  //                                    
#define Para_Manu_799            ManuPara[799]  //                                    
#define Para_CurrSevroDrvSN      ManuPara[800]  //当前伺服驱动器                             
#define Para_Manu_801            ManuPara[801]  //                                    
#define Para_Manu_802            ManuPara[802]  //                                    
#define Para_Manu_803            ManuPara[803]  //                                    
#define Para_Manu_804            ManuPara[804]  //                                    
#define Para_Manu_805            ManuPara[805]  //                                    
#define Para_Manu_806            ManuPara[806]  //                                    
#define Para_Manu_807            ManuPara[807]  //                                    
#define Para_Manu_808            ManuPara[808]  //                                    
#define Para_Manu_809            ManuPara[809]  //                                    
#define Para_EjeFor3StepSel      ManuPara[810]  //三级托模选择                              特殊托模：定次托模时,托模3次每次位置都不一样
#define Para_EjeForStep2Pos      ManuPara[811]  //三级托模2级位置                            特殊托模：定次托模时,托模3次每次位置都不一样,第2次托模结束位置
#define Para_EjeForStep3Pos      ManuPara[812]  //三级托模3级位置                            特殊托模：定次托模时,托模3次每次位置都不一样,第3次托模结束位置
#define Para_Manu_813            ManuPara[813]  //                                    
#define Para_Manu_814            ManuPara[814]  //                                    
#define Para_Manu_815            ManuPara[815]  //                                    
#define Para_Manu_816            ManuPara[816]  //                                    
#define Para_Manu_817            ManuPara[817]  //                                    
#define Para_Manu_818            ManuPara[818]  //                                    
#define Para_DryCycAutoCycDly    ManuPara[819]  //干循环再循环延时                            
#define Para_DryCycMC1Pres       ManuPara[820]  //干循环关模一段压力                           
#define Para_DryCycMC1Flow       ManuPara[821]  //干循环关模一段流量                           
#define Para_DryCycMC2Pres       ManuPara[822]  //干循环关模二段压力                           
#define Para_DryCycMC2Flow       ManuPara[823]  //干循环关模二段流量                           
#define Para_DryCycMC2SPos       ManuPara[824]  //干循环关模二段起始位置                         
#define Para_DryCycMC3Pres       ManuPara[825]  //干循环关模三段压力                           
#define Para_DryCycMC3Flow       ManuPara[826]  //干循环关模三段流量                           
#define Para_DryCycMC3SPos       ManuPara[827]  //干循环关模三段起始位置                         
#define Para_DryCycMCLPPres      ManuPara[828]  //干循环关模低压段压力                          
#define Para_DryCycMCLPFlow      ManuPara[829]  //干循环关模低压段流量                          
#define Para_DryCycMCLPSPos      ManuPara[830]  //干循环关模低压段起始位置                        
#define Para_DryCycMCHPPres      ManuPara[831]  //干循环关模高压段压力                          
#define Para_DryCycMCHPFlow      ManuPara[832]  //干循环关模高压段流量                          
#define Para_DryCycMCHPSPos      ManuPara[833]  //干循环关模高压段起始位置                        
#define Para_Manu_834            ManuPara[834]  //                                    
#define Para_Manu_835            ManuPara[835]  //                                    
#define Para_Manu_836            ManuPara[836]  //                                    
#define Para_Manu_837            ManuPara[837]  //                                    
#define Para_DryCycMO1Pres       ManuPara[838]  //干循环开模一段压力                           
#define Para_DryCycMO1Flow       ManuPara[839]  //干循环开模一段流量                           
#define Para_DryCycMO2Pres       ManuPara[840]  //干循环开模二段压力                           
#define Para_DryCycMO2Flow       ManuPara[841]  //干循环开模二段流量                           
#define Para_DryCycMO2SPos       ManuPara[842]  //干循环开模二段起始位置                         
#define Para_DryCycMO3Pres       ManuPara[843]  //干循环开模三段压力                           
#define Para_DryCycMO3Flow       ManuPara[844]  //干循环开模三段流量                           
#define Para_DryCycMO3SPos       ManuPara[845]  //干循环开模三段起始位置                         
#define Para_DryCycMO4Pres       ManuPara[846]  //干循环开模四段压力                           
#define Para_DryCycMO4Flow       ManuPara[847]  //干循环开模四段流量                           
#define Para_DryCycMO4SPos       ManuPara[848]  //干循环开模四段起始位置                         
#define Para_DryCycMO5Pres       ManuPara[849]  //干循环开模五段压力                           
#define Para_DryCycMO5Flow       ManuPara[850]  //干循环开模五段流量                           
#define Para_DryCycMO5SPos       ManuPara[851]  //干循环开模五段起始位置                         
#define Para_DryCycMOEPos        ManuPara[852]  //干循环开模结束位置                           
#define Para_Manu_853            ManuPara[853]  //                                    
#define Para_Manu_854            ManuPara[854]  //                                    
#define Para_MCHPPresTrgTon      ManuPara[855]  //目标锁模吨数                              
#define Para_AutoAdjMoldMode     ManuPara[856]  //自动调模模式                              0-锁模高压 1-锁模吨数
#define Para_Manu_857            ManuPara[857]  //                                    
#define Para_Manu_858            ManuPara[858]  //                                    
#define Para_Manu_859            ManuPara[859]  //                                    
#define Para_NozLeakageSnrSel    ManuPara[860]  //喷嘴漏料检测功能                            0-不用 1-使用
#define Para_NozLeakTempDev1     ManuPara[861]  //喷嘴漏料警报偏差1                           温度偏差1
#define Para_NozLeakTempDev2     ManuPara[862]  //喷嘴漏料警报偏差2                           温度偏差2
#define Para_Manu_863            ManuPara[863]  //                                    
#define Para_Manu_864            ManuPara[864]  //                                    
#define Para_Manu_865            ManuPara[865]  //                                    
#define Para_Manu_866            ManuPara[866]  //                                    
#define Para_Manu_867            ManuPara[867]  //                                    
#define Para_Manu_868            ManuPara[868]  //                                    
#define Para_Manu_869            ManuPara[869]  //                                    
#define Para_Manu_870            ManuPara[870]  //                                    
#define Para_Manu_871            ManuPara[871]  //                                    
#define Para_Manu_872            ManuPara[872]  //                                    
#define Para_Manu_873            ManuPara[873]  //                                    
#define Para_Manu_874            ManuPara[874]  //                                    
#define Para_Manu_875            ManuPara[875]  //                                    
#define Para_Manu_876            ManuPara[876]  //                                    
#define Para_Manu_877            ManuPara[877]  //                                    
#define Para_Manu_878            ManuPara[878]  //                                    
#define Para_Manu_879            ManuPara[879]  //                                    
#define Para_Manu_880            ManuPara[880]  //                                    
#define Para_Manu_881            ManuPara[881]  //                                    
#define Para_Manu_882            ManuPara[882]  //                                    
#define Para_Manu_883            ManuPara[883]  //                                    
#define Para_Manu_884            ManuPara[884]  //                                    
#define Para_Manu_885            ManuPara[885]  //                                    
#define Para_Manu_886            ManuPara[886]  //                                    
#define Para_Manu_887            ManuPara[887]  //                                    
#define Para_Manu_888            ManuPara[888]  //                                    
#define Para_Manu_889            ManuPara[889]  //                                    
#define Para_Manu_890            ManuPara[890]  //                                    
#define Para_Manu_891            ManuPara[891]  //                                    
#define Para_Manu_892            ManuPara[892]  //                                    
#define Para_Manu_893            ManuPara[893]  //                                    
#define Para_SprueOpenOcc        ManuPara[894]  //浇口开时机                               0-关闭，1-合模过时间，2-顶退过时间，3-开模终过时间，4-注射过时间，5-合模高压过时间
#define Para_SprueOpenPos        ManuPara[895]  //浇口开位置                               动作超过这个位置后就开启浇口
#define Para_SprueOpenTime       ManuPara[896]  //浇口开时间                               动作超过这个时间后就开启浇口
#define Para_SprueClsOcc         ManuPara[897]  //浇口关时机                               0-浇口关不起作用；1-注射结束；2-保压结束；3-储料结束；4-射退结束
#define Para_Manu_898            ManuPara[898]  //                                    
#define Para_Manu_899            ManuPara[899]  //                                    
#define Para_HRV01_Function      ManuPara[900]  //热流道阀门一功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV02_Function      ManuPara[901]  //热流道阀门二功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV03_Function      ManuPara[902]  //热流道阀门三功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV04_Function      ManuPara[903]  //热流道阀门四功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV05_Function      ManuPara[904]  //热流道阀门五功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV06_Function      ManuPara[905]  //热流道阀门六功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV07_Function      ManuPara[906]  //热流道阀门七功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV08_Function      ManuPara[907]  //热流道阀门八功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV09_Function      ManuPara[908]  //热流道阀门九功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV10_Function      ManuPara[909]  //热流道阀门十功能                            0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV01_Inj_OnTi      ManuPara[910]  //阀门一射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV02_Inj_OnTi      ManuPara[911]  //阀门二射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV03_Inj_OnTi      ManuPara[912]  //阀门三射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV04_Inj_OnTi      ManuPara[913]  //阀门四射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV05_Inj_OnTi      ManuPara[914]  //阀门五射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV06_Inj_OnTi      ManuPara[915]  //阀门六射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV07_Inj_OnTi      ManuPara[916]  //阀门七射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV08_Inj_OnTi      ManuPara[917]  //阀门八射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV09_Inj_OnTi      ManuPara[918]  //阀门九射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV10_Inj_OnTi      ManuPara[919]  //阀门十射出开时间                            阀门:射出执行到该时间开启阀门
#define Para_HRV01_Inj_OffTi     ManuPara[920]  //阀门一射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV02_Inj_OffTi     ManuPara[921]  //阀门二射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV03_Inj_OffTi     ManuPara[922]  //阀门三射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV04_Inj_OffTi     ManuPara[923]  //阀门四射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV05_Inj_OffTi     ManuPara[924]  //阀门五射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV06_Inj_OffTi     ManuPara[925]  //阀门六射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV07_Inj_OffTi     ManuPara[926]  //阀门七射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV08_Inj_OffTi     ManuPara[927]  //阀门八射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV09_Inj_OffTi     ManuPara[928]  //阀门九射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV10_Inj_OffTi     ManuPara[929]  //阀门十射出关时间                            阀门:射出执行到该时间关闭阀门
#define Para_HRV01_Inj_OnPos     ManuPara[930]  //阀门一射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV02_Inj_OnPos     ManuPara[931]  //阀门二射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV03_Inj_OnPos     ManuPara[932]  //阀门三射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV04_Inj_OnPos     ManuPara[933]  //阀门四射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV05_Inj_OnPos     ManuPara[934]  //阀门五射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV06_Inj_OnPos     ManuPara[935]  //阀门六射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV07_Inj_OnPos     ManuPara[936]  //阀门七射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV08_Inj_OnPos     ManuPara[937]  //阀门八射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV09_Inj_OnPos     ManuPara[938]  //阀门九射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV10_Inj_OnPos     ManuPara[939]  //阀门十射出开位置                            阀门:射出执行到该位置开启阀门
#define Para_HRV01_Inj_OffPos    ManuPara[940]  //阀门一射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV02_Inj_OffPos    ManuPara[941]  //阀门二射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV03_Inj_OffPos    ManuPara[942]  //阀门三射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV04_Inj_OffPos    ManuPara[943]  //阀门四射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV05_Inj_OffPos    ManuPara[944]  //阀门五射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV06_Inj_OffPos    ManuPara[945]  //阀门六射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV07_Inj_OffPos    ManuPara[946]  //阀门七射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV08_Inj_OffPos    ManuPara[947]  //阀门八射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV09_Inj_OffPos    ManuPara[948]  //阀门九射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV10_Inj_OffPos    ManuPara[949]  //阀门十射出关位置                            阀门:射出执行到该位置关闭阀门
#define Para_HRV01_HP_OnTi       ManuPara[950]  //阀门一保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV02_HP_OnTi       ManuPara[951]  //阀门二保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV03_HP_OnTi       ManuPara[952]  //阀门三保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV04_HP_OnTi       ManuPara[953]  //阀门四保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV05_HP_OnTi       ManuPara[954]  //阀门五保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV06_HP_OnTi       ManuPara[955]  //阀门六保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV07_HP_OnTi       ManuPara[956]  //阀门七保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV08_HP_OnTi       ManuPara[957]  //阀门八保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV09_HP_OnTi       ManuPara[958]  //阀门九保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV10_HP_OnTi       ManuPara[959]  //阀门十保压开时间                            阀门:保压执行到该时间开启阀门
#define Para_HRV01_HP_OffTi      ManuPara[960]  //阀门一保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV02_HP_OffTi      ManuPara[961]  //阀门二保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV03_HP_OffTi      ManuPara[962]  //阀门三保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV04_HP_OffTi      ManuPara[963]  //阀门四保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV05_HP_OffTi      ManuPara[964]  //阀门五保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV06_HP_OffTi      ManuPara[965]  //阀门六保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV07_HP_OffTi      ManuPara[966]  //阀门七保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV08_HP_OffTi      ManuPara[967]  //阀门八保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV09_HP_OffTi      ManuPara[968]  //阀门九保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_HRV10_HP_OffTi      ManuPara[969]  //阀门十保压关时间                            阀门:保压执行到该时间关闭阀门
#define Para_Manu_970            ManuPara[970]  //                                    
#define Para_Manu_971            ManuPara[971]  //                                    
#define Para_Manu_972            ManuPara[972]  //                                    
#define Para_Manu_973            ManuPara[973]  //                                    
#define Para_Manu_974            ManuPara[974]  //                                    
#define Para_Manu_975            ManuPara[975]  //                                    
#define Para_Manu_976            ManuPara[976]  //                                    
#define Para_Manu_977            ManuPara[977]  //                                    
#define Para_Manu_978            ManuPara[978]  //                                    
#define Para_Manu_979            ManuPara[979]  //                                    
#define Para_Manu_980            ManuPara[980]  //                                    
#define Para_Manu_981            ManuPara[981]  //                                    
#define Para_Manu_982            ManuPara[982]  //                                    
#define Para_Manu_983            ManuPara[983]  //                                    
#define Para_Manu_984            ManuPara[984]  //                                    
#define Para_Manu_985            ManuPara[985]  //                                    
#define Para_Manu_986            ManuPara[986]  //                                    
#define Para_Manu_987            ManuPara[987]  //                                    
#define Para_Manu_988            ManuPara[988]  //                                    
#define Para_Manu_989            ManuPara[989]  //                                    
#define Para_Manu_990            ManuPara[990]  //                                    
#define Para_Manu_991            ManuPara[991]  //                                    
#define Para_Manu_992            ManuPara[992]  //                                    
#define Para_Manu_993            ManuPara[993]  //                                    
#define Para_Manu_994            ManuPara[994]  //                                    
#define Para_Manu_995            ManuPara[995]  //                                    
#define Para_Manu_996            ManuPara[996]  //                                    
#define Para_Manu_997            ManuPara[997]  //                                    
#define Para_Manu_998            ManuPara[998]  //                                    
#define Para_Manu_999            ManuPara[999]  //                                    
#define Para_HRV11_Function      ManuPara[1000] //热流道阀门十一功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV12_Function      ManuPara[1001] //热流道阀门十二功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV13_Function      ManuPara[1002] //热流道阀门十三功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV14_Function      ManuPara[1003] //热流道阀门十四功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV15_Function      ManuPara[1004] //热流道阀门十五功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV16_Function      ManuPara[1005] //热流道阀门十六功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV17_Function      ManuPara[1006] //热流道阀门十七功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV18_Function      ManuPara[1007] //热流道阀门十八功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV19_Function      ManuPara[1008] //热流道阀门十九功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV20_Function      ManuPara[1009] //热流道阀门二十功能                           0-不用 1-时开时关 2-位开位关 3-时开位关 4-位开时
#define Para_HRV11_Inj_OnTi      ManuPara[1010] //阀门11射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV12_Inj_OnTi      ManuPara[1011] //阀门12射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV13_Inj_OnTi      ManuPara[1012] //阀门13射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV14_Inj_OnTi      ManuPara[1013] //阀门14射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV15_Inj_OnTi      ManuPara[1014] //阀门15射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV16_Inj_OnTi      ManuPara[1015] //阀门16射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV17_Inj_OnTi      ManuPara[1016] //阀门17射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV18_Inj_OnTi      ManuPara[1017] //阀门18射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV19_Inj_OnTi      ManuPara[1018] //阀门19射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV20_Inj_OnTi      ManuPara[1019] //阀门20射出开时间                           阀门:射出执行到该时间开启阀门
#define Para_HRV11_Inj_OffTi     ManuPara[1020] //阀门11射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV12_Inj_OffTi     ManuPara[1021] //阀门12射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV13_Inj_OffTi     ManuPara[1022] //阀门13射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV14_Inj_OffTi     ManuPara[1023] //阀门14射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV15_Inj_OffTi     ManuPara[1024] //阀门15射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV16_Inj_OffTi     ManuPara[1025] //阀门16射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV17_Inj_OffTi     ManuPara[1026] //阀门17射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV18_Inj_OffTi     ManuPara[1027] //阀门18射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV19_Inj_OffTi     ManuPara[1028] //阀门19射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV20_Inj_OffTi     ManuPara[1029] //阀门20射出关时间                           阀门:射出执行到该时间关闭阀门
#define Para_HRV11_Inj_OnPos     ManuPara[1030] //阀门11射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV12_Inj_OnPos     ManuPara[1031] //阀门12射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV13_Inj_OnPos     ManuPara[1032] //阀门13射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV14_Inj_OnPos     ManuPara[1033] //阀门14射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV15_Inj_OnPos     ManuPara[1034] //阀门15射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV16_Inj_OnPos     ManuPara[1035] //阀门16射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV17_Inj_OnPos     ManuPara[1036] //阀门17射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV18_Inj_OnPos     ManuPara[1037] //阀门18射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV19_Inj_OnPos     ManuPara[1038] //阀门19射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV20_Inj_OnPos     ManuPara[1039] //阀门20射出开位置                           阀门:射出执行到该位置开启阀门
#define Para_HRV11_Inj_OffPos    ManuPara[1040] //阀门11射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV12_Inj_OffPos    ManuPara[1041] //阀门12射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV13_Inj_OffPos    ManuPara[1042] //阀门13射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV14_Inj_OffPos    ManuPara[1043] //阀门14射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV15_Inj_OffPos    ManuPara[1044] //阀门15射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV16_Inj_OffPos    ManuPara[1045] //阀门16射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV17_Inj_OffPos    ManuPara[1046] //阀门17射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV18_Inj_OffPos    ManuPara[1047] //阀门18射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV19_Inj_OffPos    ManuPara[1048] //阀门19射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV20_Inj_OffPos    ManuPara[1049] //阀门20射出关位置                           阀门:射出执行到该位置关闭阀门
#define Para_HRV11_HP_OnTi       ManuPara[1050] //阀门11保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV12_HP_OnTi       ManuPara[1051] //阀门12保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV13_HP_OnTi       ManuPara[1052] //阀门13保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV14_HP_OnTi       ManuPara[1053] //阀门14保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV15_HP_OnTi       ManuPara[1054] //阀门15保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV16_HP_OnTi       ManuPara[1055] //阀门16保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV17_HP_OnTi       ManuPara[1056] //阀门17保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV18_HP_OnTi       ManuPara[1057] //阀门18保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV19_HP_OnTi       ManuPara[1058] //阀门19保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV20_HP_OnTi       ManuPara[1059] //阀门20保压开时间                           阀门:保压执行到该时间开启阀门
#define Para_HRV11_HP_OffTi      ManuPara[1060] //阀门11保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV12_HP_OffTi      ManuPara[1061] //阀门12保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV13_HP_OffTi      ManuPara[1062] //阀门13保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV14_HP_OffTi      ManuPara[1063] //阀门14保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV15_HP_OffTi      ManuPara[1064] //阀门15保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV16_HP_OffTi      ManuPara[1065] //阀门16保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV17_HP_OffTi      ManuPara[1066] //阀门17保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV18_HP_OffTi      ManuPara[1067] //阀门18保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV19_HP_OffTi      ManuPara[1068] //阀门19保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_HRV20_HP_OffTi      ManuPara[1069] //阀门20保压关时间                           阀门:保压执行到该时间关闭阀门
#define Para_Manu_1070           ManuPara[1070] //                                    
#define Para_Manu_1071           ManuPara[1071] //                                    
#define Para_Manu_1072           ManuPara[1072] //                                    
#define Para_Manu_1073           ManuPara[1073] //                                    
#define Para_Manu_1074           ManuPara[1074] //                                    
#define Para_Manu_1075           ManuPara[1075] //                                    
#define Para_Manu_1076           ManuPara[1076] //                                    
#define Para_Manu_1077           ManuPara[1077] //                                    
#define Para_Manu_1078           ManuPara[1078] //                                    
#define Para_Manu_1079           ManuPara[1079] //                                    
#define Para_LinkHoldPresFun     ManuPara[1080] //连动保压功能                              0-连动保压功能关闭；1-连动保压功能打开
#define Para_HPVC_ForPres        ManuPara[1081] //阀芯进压力                               阀芯进压力
#define Para_HPVC_ForFlow        ManuPara[1082] //阀芯进流量                               阀芯进流量
#define Para_HPVC_RetPres        ManuPara[1083] //阀芯退压力                               阀芯退压力
#define Para_HPVC_RetFlow        ManuPara[1084] //阀芯退流量                               阀芯退流量
#define Para_HoldPresRetPres     ManuPara[1085] //保压退压力                               保压退压力
#define Para_HoldPresRetFlow     ManuPara[1086] //保压退流量                               保压退流量
#define Para_HoldPresRetEndPos   ManuPara[1087] //保压退结束位置                             保压退结束位置
#define Para_HoldPresEndPos      ManuPara[1088] //保压结束位置                              保压结束位置
#define Para_InjectSecSel        ManuPara[1089] //注射分段选择                              0-位置 1-时间
#define Para_Inject1Ti           ManuPara[1090] //注射一段时间                              
#define Para_Inject2Ti           ManuPara[1091] //注射二段时间                              
#define Para_Inject3Ti           ManuPara[1092] //注射三段时间                              
#define Para_Inject4Ti           ManuPara[1093] //注射四段时间                              
#define Para_Inject5Ti           ManuPara[1094] //注射五段时间                              
#define Para_Inject6Ti           ManuPara[1095] //注射六段时间                              
#define Para_Inject7Ti           ManuPara[1096] //注射七段时间                              
#define Para_Inject8Ti           ManuPara[1097] //注射八段时间                              
#define Para_Inject9Ti           ManuPara[1098] //注射九段时间                              
#define Para_Inject10Ti          ManuPara[1099] //注射十段时间                              
#define Para_Inj1IncrPresSel     ManuPara[1100] //注射一段增力选择                            0-不用 1使用
#define Para_Inj2IncrPresSel     ManuPara[1101] //注射二段增力选择                            0-不用 1使用
#define Para_Inj3IncrPresSel     ManuPara[1102] //注射三段增力选择                            0-不用 1使用
#define Para_Inj4IncrPresSel     ManuPara[1103] //注射四段增力选择                            0-不用 1使用
#define Para_Inj5IncrPresSel     ManuPara[1104] //注射五段增力选择                            0-不用 1使用
#define Para_Inj6IncrPresSel     ManuPara[1105] //注射六段增力选择                            0-不用 1使用
#define Para_Inj7IncrPresSel     ManuPara[1106] //注射七段增力选择                            0-不用 1使用
#define Para_Inj8IncrPresSel     ManuPara[1107] //注射八段增力选择                            0-不用 1使用
#define Para_Inj9IncrPresSel     ManuPara[1108] //注射九段增力选择                            0-不用 1使用
#define Para_Inj10IncrPresSel    ManuPara[1109] //注射十段增力选择                            0-不用 1使用
#define Para_Inj1IncrSpeedSel    ManuPara[1110] //注射一段增速选择                            0-不用 1使用
#define Para_Inj2IncrSpeedSel    ManuPara[1111] //注射二段增速选择                            0-不用 1使用
#define Para_Inj3IncrSpeedSel    ManuPara[1112] //注射三段增速选择                            0-不用 1使用
#define Para_Inj4IncrSpeedSel    ManuPara[1113] //注射四段增速选择                            0-不用 1使用
#define Para_Inj5IncrSpeedSel    ManuPara[1114] //注射五段增速选择                            0-不用 1使用
#define Para_Inj6IncrSpeedSel    ManuPara[1115] //注射六段增速选择                            0-不用 1使用
#define Para_Inj7IncrSpeedSel    ManuPara[1116] //注射七段增速选择                            0-不用 1使用
#define Para_Inj8IncrSpeedSel    ManuPara[1117] //注射八段增速选择                            0-不用 1使用
#define Para_Inj9IncrSpeedSel    ManuPara[1118] //注射九段增速选择                            0-不用 1使用
#define Para_Inj10IncrSpeedSel   ManuPara[1119] //注射十段增速选择                            0-不用 1使用
#define Para_Air1ActOcc          ManuPara[1120] //A组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Air2ActOcc          ManuPara[1121] //B组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Air3ActOcc          ManuPara[1122] //C组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Air4ActOcc          ManuPara[1123] //D组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Air5ActOcc          ManuPara[1124] //E组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Air6ActOcc          ManuPara[1125] //F组吹气时机                              0-关闭 1-开模 2-托进 3-关模 4-注射 5-冷却 6-托退 7-储料
#define Para_Manu_1126           ManuPara[1126] //                                    
#define Para_Manu_1127           ManuPara[1127] //                                    
#define Para_Manu_1128           ManuPara[1128] //                                    
#define Para_Manu_1129           ManuPara[1129] //                                    
#define Para_Manu_1130           ManuPara[1130] //                                    
#define Para_Manu_1131           ManuPara[1131] //                                    
#define Para_Manu_1132           ManuPara[1132] //                                    
#define Para_Manu_1133           ManuPara[1133] //                                    
#define Para_Manu_1134           ManuPara[1134] //                                    
#define Para_Manu_1135           ManuPara[1135] //                                    
#define Para_Manu_1136           ManuPara[1136] //                                    
#define Para_Manu_1137           ManuPara[1137] //                                    
#define Para_Manu_1138           ManuPara[1138] //                                    
#define Para_Manu_1139           ManuPara[1139] //                                    
#define Para_Manu_1140           ManuPara[1140] //                                    
#define Para_Manu_1141           ManuPara[1141] //                                    
#define Para_Manu_1142           ManuPara[1142] //                                    
#define Para_Manu_1143           ManuPara[1143] //                                    
#define Para_Manu_1144           ManuPara[1144] //                                    
#define Para_Manu_1145           ManuPara[1145] //                                    
#define Para_Manu_1146           ManuPara[1146] //                                    
#define Para_Manu_1147           ManuPara[1147] //                                    
#define Para_Manu_1148           ManuPara[1148] //                                    
#define Para_Manu_1149           ManuPara[1149] //                                    
#define Para_Manu_1150           ManuPara[1150] //                                    
#define Para_Manu_1151           ManuPara[1151] //                                    
#define Para_Manu_1152           ManuPara[1152] //                                    
#define Para_Manu_1153           ManuPara[1153] //                                    
#define Para_Manu_1154           ManuPara[1154] //                                    
#define Para_Manu_1155           ManuPara[1155] //                                    
#define Para_Manu_1156           ManuPara[1156] //                                    
#define Para_Manu_1157           ManuPara[1157] //                                    
#define Para_Manu_1158           ManuPara[1158] //                                    
#define Para_Manu_1159           ManuPara[1159] //                                    
#define Para_Manu_1160           ManuPara[1160] //                                    
#define Para_Manu_1161           ManuPara[1161] //                                    
#define Para_Manu_1162           ManuPara[1162] //                                    
#define Para_Manu_1163           ManuPara[1163] //                                    
#define Para_Manu_1164           ManuPara[1164] //                                    
#define Para_Manu_1165           ManuPara[1165] //                                    
#define Para_Manu_1166           ManuPara[1166] //                                    
#define Para_Manu_1167           ManuPara[1167] //                                    
#define Para_Manu_1168           ManuPara[1168] //                                    
#define Para_Manu_1169           ManuPara[1169] //                                    
#define Para_Manu_1170           ManuPara[1170] //                                    
#define Para_Manu_1171           ManuPara[1171] //                                    
#define Para_Manu_1172           ManuPara[1172] //                                    
#define Para_Manu_1173           ManuPara[1173] //                                    
#define Para_Manu_1174           ManuPara[1174] //                                    
#define Para_Manu_1175           ManuPara[1175] //                                    
#define Para_Manu_1176           ManuPara[1176] //                                    
#define Para_Manu_1177           ManuPara[1177] //                                    
#define Para_Manu_1178           ManuPara[1178] //                                    
#define Para_Manu_1179           ManuPara[1179] //                                    
#define Para_Manu_1180           ManuPara[1180] //                                    
#define Para_Manu_1181           ManuPara[1181] //                                    
#define Para_Manu_1182           ManuPara[1182] //                                    
#define Para_Manu_1183           ManuPara[1183] //                                    
#define Para_Manu_1184           ManuPara[1184] //                                    
#define Para_Manu_1185           ManuPara[1185] //                                    
#define Para_Manu_1186           ManuPara[1186] //                                    
#define Para_Manu_1187           ManuPara[1187] //                                    
#define Para_Manu_1188           ManuPara[1188] //                                    
#define Para_Manu_1189           ManuPara[1189] //                                    
#define Para_Manu_1190           ManuPara[1190] //                                    
#define Para_Manu_1191           ManuPara[1191] //                                    
#define Para_Manu_1192           ManuPara[1192] //                                    
#define Para_Manu_1193           ManuPara[1193] //                                    
#define Para_Manu_1194           ManuPara[1194] //                                    
#define Para_Manu_1195           ManuPara[1195] //                                    
#define Para_Manu_1196           ManuPara[1196] //                                    
#define Para_Manu_1197           ManuPara[1197] //                                    
#define Para_Manu_1198           ManuPara[1198] //                                    
#define Para_Manu_1199           ManuPara[1199] //                                    
#define Para_Manu_1200           ManuPara[1200] //                                    
#define Para_Manu_1201           ManuPara[1201] //                                    
#define Para_Manu_1202           ManuPara[1202] //                                    
#define Para_Manu_1203           ManuPara[1203] //                                    
#define Para_Manu_1204           ManuPara[1204] //                                    
#define Para_Manu_1205           ManuPara[1205] //                                    
#define Para_Manu_1206           ManuPara[1206] //                                    
#define Para_Manu_1207           ManuPara[1207] //                                    
#define Para_Manu_1208           ManuPara[1208] //                                    
#define Para_Manu_1209           ManuPara[1209] //                                    
#define Para_Manu_1210           ManuPara[1210] //                                    
#define Para_Manu_1211           ManuPara[1211] //                                    
#define Para_Manu_1212           ManuPara[1212] //                                    
#define Para_Manu_1213           ManuPara[1213] //                                    
#define Para_Manu_1214           ManuPara[1214] //                                    
#define Para_Manu_1215           ManuPara[1215] //                                    
#define Para_Manu_1216           ManuPara[1216] //                                    
#define Para_Manu_1217           ManuPara[1217] //                                    
#define Para_Manu_1218           ManuPara[1218] //                                    
#define Para_Manu_1219           ManuPara[1219] //                                    
#define Para_HotRunrSwitch       ManuPara[1220] //热流道总开关                              热流道总开关:0-关，1-开
#define Para_HotRunrHoldTempSel  ManuPara[1221] //热流道保温功能                             热流道保温功能：0-不用 1-选用
#define Para_HotRunrHoldTemp     ManuPara[1222] //热流道保温温度                             热流道保温温度
#define Para_HotRunrSenrType     ManuPara[1223] //热流道传感器类型                            热流道传感器类型：0-J 1-K 2-E
#define Para_HotRunrSoftStatSwih ManuPara[1224] //热流道软启动开关                            热流道软启动开关:0-关，1-开
#define Para_HotRunrSoftStatTemp ManuPara[1225] //热流道软启动温度                            热流道软启动温度
#define Para_HotRunrSoftStatPowr ManuPara[1226] //热流道软启动功率                            热流道软启动功率
#define Para_HotRunrSoftStatTime ManuPara[1227] //热流道软启动时间                            热流道软启动时间
#define Para_Manu_1228           ManuPara[1228] //                                    
#define Para_Manu_1229           ManuPara[1229] //                                    
#define Para_HotRunr1SetTemp     ManuPara[1230] //热流道1设置温度                            热流道1设置温度
#define Para_HotRunr2SetTemp     ManuPara[1231] //热流道2设置温度                            热流道2设置温度
#define Para_HotRunr3SetTemp     ManuPara[1232] //热流道3设置温度                            热流道3设置温度
#define Para_HotRunr4SetTemp     ManuPara[1233] //热流道4设置温度                            热流道4设置温度
#define Para_HotRunr5SetTemp     ManuPara[1234] //热流道5设置温度                            热流道5设置温度
#define Para_HotRunr6SetTemp     ManuPara[1235] //热流道6设置温度                            热流道6设置温度
#define Para_HotRunr7SetTemp     ManuPara[1236] //热流道7设置温度                            热流道7设置温度
#define Para_HotRunr8SetTemp     ManuPara[1237] //热流道8设置温度                            热流道8设置温度
#define Para_HotRunr9SetTemp     ManuPara[1238] //热流道9设置温度                            热流道9设置温度
#define Para_HotRunr10SetTemp    ManuPara[1239] //热流道10设置温度                           热流道10设置温度
#define Para_HotRunr11SetTemp    ManuPara[1240] //热流道11设置温度                           热流道11设置温度
#define Para_HotRunr12SetTemp    ManuPara[1241] //热流道12设置温度                           热流道12设置温度
#define Para_HotRunr13SetTemp    ManuPara[1242] //热流道13设置温度                           热流道13设置温度
#define Para_HotRunr14SetTemp    ManuPara[1243] //热流道14设置温度                           热流道14设置温度
#define Para_HotRunr15SetTemp    ManuPara[1244] //热流道15设置温度                           热流道15设置温度
#define Para_HotRunr16SetTemp    ManuPara[1245] //热流道16设置温度                           热流道16设置温度
#define Para_HotRunr17SetTemp    ManuPara[1246] //热流道17设置温度                           热流道17设置温度
#define Para_HotRunr18SetTemp    ManuPara[1247] //热流道18设置温度                           热流道18设置温度
#define Para_HotRunr19SetTemp    ManuPara[1248] //热流道19设置温度                           热流道19设置温度
#define Para_HotRunr20SetTemp    ManuPara[1249] //热流道20设置温度                           热流道20设置温度
#define Para_HotRunr21SetTemp    ManuPara[1250] //热流道21设置温度                           热流道21设置温度
#define Para_HotRunr22SetTemp    ManuPara[1251] //热流道22设置温度                           热流道22设置温度
#define Para_HotRunr23SetTemp    ManuPara[1252] //热流道23设置温度                           热流道23设置温度
#define Para_HotRunr24SetTemp    ManuPara[1253] //热流道24设置温度                           热流道24设置温度
#define Para_HotRunr25SetTemp    ManuPara[1254] //热流道25设置温度                           热流道25设置温度
#define Para_HotRunr26SetTemp    ManuPara[1255] //热流道26设置温度                           热流道26设置温度
#define Para_HotRunr27SetTemp    ManuPara[1256] //热流道27设置温度                           热流道27设置温度
#define Para_HotRunr28SetTemp    ManuPara[1257] //热流道28设置温度                           热流道28设置温度
#define Para_HotRunr29SetTemp    ManuPara[1258] //热流道29设置温度                           热流道29设置温度
#define Para_HotRunr30SetTemp    ManuPara[1259] //热流道30设置温度                           热流道30设置温度
#define Para_HotRunr31SetTemp    ManuPara[1260] //热流道31设置温度                           热流道31设置温度
#define Para_HotRunr32SetTemp    ManuPara[1261] //热流道32设置温度                           热流道32设置温度
#define Para_HotRunr33SetTemp    ManuPara[1262] //热流道33设置温度                           热流道33设置温度
#define Para_HotRunr34SetTemp    ManuPara[1263] //热流道34设置温度                           热流道34设置温度
#define Para_HotRunr35SetTemp    ManuPara[1264] //热流道35设置温度                           热流道35设置温度
#define Para_HotRunr36SetTemp    ManuPara[1265] //热流道36设置温度                           热流道36设置温度
#define Para_HotRunr37SetTemp    ManuPara[1266] //热流道37设置温度                           热流道37设置温度
#define Para_HotRunr38SetTemp    ManuPara[1267] //热流道38设置温度                           热流道38设置温度
#define Para_HotRunr39SetTemp    ManuPara[1268] //热流道39设置温度                           热流道39设置温度
#define Para_HotRunr40SetTemp    ManuPara[1269] //热流道40设置温度                           热流道40设置温度
#define Para_HotRunr41SetTemp    ManuPara[1270] //热流道41设置温度                           热流道41设置温度
#define Para_HotRunr42SetTemp    ManuPara[1271] //热流道42设置温度                           热流道42设置温度
#define Para_HotRunr43SetTemp    ManuPara[1272] //热流道43设置温度                           热流道43设置温度
#define Para_HotRunr44SetTemp    ManuPara[1273] //热流道44设置温度                           热流道44设置温度
#define Para_HotRunr45SetTemp    ManuPara[1274] //热流道45设置温度                           热流道45设置温度
#define Para_HotRunr46SetTemp    ManuPara[1275] //热流道46设置温度                           热流道46设置温度
#define Para_HotRunr47SetTemp    ManuPara[1276] //热流道47设置温度                           热流道47设置温度
#define Para_HotRunr48SetTemp    ManuPara[1277] //热流道48设置温度                           热流道48设置温度
#define Para_HotRunr49SetTemp    ManuPara[1278] //热流道49设置温度                           热流道49设置温度
#define Para_HotRunr50SetTemp    ManuPara[1279] //热流道50设置温度                           热流道50设置温度
#define Para_HotRunr51SetTemp    ManuPara[1280] //热流道51设置温度                           热流道51设置温度
#define Para_HotRunr52SetTemp    ManuPara[1281] //热流道52设置温度                           热流道52设置温度
#define Para_HotRunr53SetTemp    ManuPara[1282] //热流道53设置温度                           热流道53设置温度
#define Para_HotRunr54SetTemp    ManuPara[1283] //热流道54设置温度                           热流道54设置温度
#define Para_HotRunr55SetTemp    ManuPara[1284] //热流道55设置温度                           热流道55设置温度
#define Para_HotRunr56SetTemp    ManuPara[1285] //热流道56设置温度                           热流道56设置温度
#define Para_HotRunr57SetTemp    ManuPara[1286] //热流道57设置温度                           热流道57设置温度
#define Para_HotRunr58SetTemp    ManuPara[1287] //热流道58设置温度                           热流道58设置温度
#define Para_HotRunr59SetTemp    ManuPara[1288] //热流道59设置温度                           热流道59设置温度
#define Para_HotRunr60SetTemp    ManuPara[1289] //热流道60设置温度                           热流道60设置温度
#define Para_HotRunr1AlgSel      ManuPara[1290] //热流道1控温算法选择                          热流道1控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr2AlgSel      ManuPara[1291] //热流道2控温算法选择                          热流道2控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr3AlgSel      ManuPara[1292] //热流道3控温算法选择                          热流道3控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr4AlgSel      ManuPara[1293] //热流道4控温算法选择                          热流道4控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr5AlgSel      ManuPara[1294] //热流道5控温算法选择                          热流道5控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr6AlgSel      ManuPara[1295] //热流道6控温算法选择                          热流道6控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr7AlgSel      ManuPara[1296] //热流道7控温算法选择                          热流道7控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr8AlgSel      ManuPara[1297] //热流道8控温算法选择                          热流道8控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr9AlgSel      ManuPara[1298] //热流道9控温算法选择                          热流道9控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr10AlgSel     ManuPara[1299] //热流道10控温算法选择                         热流道10控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr11AlgSel     ManuPara[1300] //热流道11控温算法选择                         热流道11控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr12AlgSel     ManuPara[1301] //热流道12控温算法选择                         热流道12控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr13AlgSel     ManuPara[1302] //热流道13控温算法选择                         热流道13控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr14AlgSel     ManuPara[1303] //热流道14控温算法选择                         热流道14控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr15AlgSel     ManuPara[1304] //热流道15控温算法选择                         热流道15控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr16AlgSel     ManuPara[1305] //热流道16控温算法选择                         热流道16控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr17AlgSel     ManuPara[1306] //热流道17控温算法选择                         热流道17控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr18AlgSel     ManuPara[1307] //热流道18控温算法选择                         热流道18控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr19AlgSel     ManuPara[1308] //热流道19控温算法选择                         热流道19控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr20AlgSel     ManuPara[1309] //热流道20控温算法选择                         热流道20控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr21AlgSel     ManuPara[1310] //热流道21控温算法选择                         热流道21控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr22AlgSel     ManuPara[1311] //热流道22控温算法选择                         热流道22控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr23AlgSel     ManuPara[1312] //热流道23控温算法选择                         热流道23控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr24AlgSel     ManuPara[1313] //热流道24控温算法选择                         热流道24控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr25AlgSel     ManuPara[1314] //热流道25控温算法选择                         热流道25控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr26AlgSel     ManuPara[1315] //热流道26控温算法选择                         热流道26控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr27AlgSel     ManuPara[1316] //热流道27控温算法选择                         热流道27控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr28AlgSel     ManuPara[1317] //热流道28控温算法选择                         热流道28控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr29AlgSel     ManuPara[1318] //热流道29控温算法选择                         热流道29控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr30AlgSel     ManuPara[1319] //热流道30控温算法选择                         热流道30控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr31AlgSel     ManuPara[1320] //热流道31控温算法选择                         热流道31控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr32AlgSel     ManuPara[1321] //热流道32控温算法选择                         热流道32控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr33AlgSel     ManuPara[1322] //热流道33控温算法选择                         热流道33控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr34AlgSel     ManuPara[1323] //热流道34控温算法选择                         热流道34控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr35AlgSel     ManuPara[1324] //热流道35控温算法选择                         热流道35控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr36AlgSel     ManuPara[1325] //热流道36控温算法选择                         热流道36控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr37AlgSel     ManuPara[1326] //热流道37控温算法选择                         热流道37控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr38AlgSel     ManuPara[1327] //热流道38控温算法选择                         热流道38控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr39AlgSel     ManuPara[1328] //热流道39控温算法选择                         热流道39控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr40AlgSel     ManuPara[1329] //热流道40控温算法选择                         热流道40控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr41AlgSel     ManuPara[1330] //热流道41控温算法选择                         热流道41控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr42AlgSel     ManuPara[1331] //热流道42控温算法选择                         热流道42控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr43AlgSel     ManuPara[1332] //热流道43控温算法选择                         热流道43控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr44AlgSel     ManuPara[1333] //热流道44控温算法选择                         热流道44控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr45AlgSel     ManuPara[1334] //热流道45控温算法选择                         热流道45控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr46AlgSel     ManuPara[1335] //热流道46控温算法选择                         热流道46控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr47AlgSel     ManuPara[1336] //热流道47控温算法选择                         热流道47控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr48AlgSel     ManuPara[1337] //热流道48控温算法选择                         热流道48控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr49AlgSel     ManuPara[1338] //热流道49控温算法选择                         热流道49控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr50AlgSel     ManuPara[1339] //热流道50控温算法选择                         热流道50控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr51AlgSel     ManuPara[1340] //热流道51控温算法选择                         热流道51控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr52AlgSel     ManuPara[1341] //热流道52控温算法选择                         热流道52控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr53AlgSel     ManuPara[1342] //热流道53控温算法选择                         热流道53控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr54AlgSel     ManuPara[1343] //热流道54控温算法选择                         热流道54控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr55AlgSel     ManuPara[1344] //热流道55控温算法选择                         热流道55控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr56AlgSel     ManuPara[1345] //热流道56控温算法选择                         热流道56控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr57AlgSel     ManuPara[1346] //热流道57控温算法选择                         热流道57控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr58AlgSel     ManuPara[1347] //热流道58控温算法选择                         热流道58控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr59AlgSel     ManuPara[1348] //热流道59控温算法选择                         热流道59控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_HotRunr60AlgSel     ManuPara[1349] //热流道60控温算法选择                         热流道60控温算法选择:0-不用，1-低速，2-中速，3-高速
#define Para_Manu_1350           ManuPara[1350] //                                    
#define Para_Manu_1351           ManuPara[1351] //                                    
#define Para_Manu_1352           ManuPara[1352] //                                    
#define Para_Manu_1353           ManuPara[1353] //                                    
#define Para_Manu_1354           ManuPara[1354] //                                    
#define Para_Manu_1355           ManuPara[1355] //                                    
#define Para_Manu_1356           ManuPara[1356] //                                    
#define Para_Manu_1357           ManuPara[1357] //                                    
#define Para_Manu_1358           ManuPara[1358] //                                    
#define Para_Manu_1359           ManuPara[1359] //                                    
#define Para_Manu_1360           ManuPara[1360] //                                    
#define Para_Manu_1361           ManuPara[1361] //                                    
#define Para_Manu_1362           ManuPara[1362] //                                    
#define Para_Manu_1363           ManuPara[1363] //                                    
#define Para_Manu_1364           ManuPara[1364] //                                    
#define Para_Manu_1365           ManuPara[1365] //                                    
#define Para_Manu_1366           ManuPara[1366] //                                    
#define Para_Manu_1367           ManuPara[1367] //                                    
#define Para_Manu_1368           ManuPara[1368] //                                    
#define Para_Manu_1369           ManuPara[1369] //                                    
#define Para_Manu_1370           ManuPara[1370] //                                    
#define Para_Manu_1371           ManuPara[1371] //                                    
#define Para_Manu_1372           ManuPara[1372] //                                    
#define Para_Manu_1373           ManuPara[1373] //                                    
#define Para_Manu_1374           ManuPara[1374] //                                    
#define Para_Manu_1375           ManuPara[1375] //                                    
#define Para_Manu_1376           ManuPara[1376] //                                    
#define Para_Manu_1377           ManuPara[1377] //                                    
#define Para_Manu_1378           ManuPara[1378] //                                    
#define Para_Manu_1379           ManuPara[1379] //                                    
#define Para_Manu_1380           ManuPara[1380] //                                    
#define Para_Manu_1381           ManuPara[1381] //                                    
#define Para_Manu_1382           ManuPara[1382] //                                    
#define Para_Manu_1383           ManuPara[1383] //                                    
#define Para_Manu_1384           ManuPara[1384] //                                    
#define Para_Manu_1385           ManuPara[1385] //                                    
#define Para_Manu_1386           ManuPara[1386] //                                    
#define Para_Manu_1387           ManuPara[1387] //                                    
#define Para_Manu_1388           ManuPara[1388] //                                    
#define Para_Manu_1389           ManuPara[1389] //                                    
#define Para_Manu_1390           ManuPara[1390] //                                    
#define Para_Manu_1391           ManuPara[1391] //                                    
#define Para_Manu_1392           ManuPara[1392] //                                    
#define Para_Manu_1393           ManuPara[1393] //                                    
#define Para_Manu_1394           ManuPara[1394] //                                    
#define Para_Manu_1395           ManuPara[1395] //                                    
#define Para_Manu_1396           ManuPara[1396] //                                    
#define Para_Manu_1397           ManuPara[1397] //                                    
#define Para_Manu_1398           ManuPara[1398] //                                    
#define Para_Manu_1399           ManuPara[1399] //                                    
#define Para_Manu_1400           ManuPara[1400] //                                    
#define Para_Manu_1401           ManuPara[1401] //                                    
#define Para_Manu_1402           ManuPara[1402] //                                    
#define Para_Manu_1403           ManuPara[1403] //                                    
#define Para_Manu_1404           ManuPara[1404] //                                    
#define Para_Manu_1405           ManuPara[1405] //                                    
#define Para_Manu_1406           ManuPara[1406] //                                    
#define Para_Manu_1407           ManuPara[1407] //                                    
#define Para_Manu_1408           ManuPara[1408] //                                    
#define Para_Manu_1409           ManuPara[1409] //                                    
#define Para_Manu_1410           ManuPara[1410] //                                    
#define Para_Manu_1411           ManuPara[1411] //                                    
#define Para_Manu_1412           ManuPara[1412] //                                    
#define Para_Manu_1413           ManuPara[1413] //                                    
#define Para_Manu_1414           ManuPara[1414] //                                    
#define Para_Manu_1415           ManuPara[1415] //                                    
#define Para_Manu_1416           ManuPara[1416] //                                    
#define Para_Manu_1417           ManuPara[1417] //                                    
#define Para_Manu_1418           ManuPara[1418] //                                    
#define Para_Manu_1419           ManuPara[1419] //                                    
#define Para_Manu_1420           ManuPara[1420] //                                    
#define Para_Manu_1421           ManuPara[1421] //                                    
#define Para_Manu_1422           ManuPara[1422] //                                    
#define Para_Manu_1423           ManuPara[1423] //                                    
#define Para_Manu_1424           ManuPara[1424] //                                    
#define Para_Manu_1425           ManuPara[1425] //                                    
#define Para_Manu_1426           ManuPara[1426] //                                    
#define Para_Manu_1427           ManuPara[1427] //                                    
#define Para_Manu_1428           ManuPara[1428] //                                    
#define Para_Manu_1429           ManuPara[1429] //                                    
#define Para_Manu_1430           ManuPara[1430] //                                    
#define Para_Manu_1431           ManuPara[1431] //                                    
#define Para_Manu_1432           ManuPara[1432] //                                    
#define Para_Manu_1433           ManuPara[1433] //                                    
#define Para_Manu_1434           ManuPara[1434] //                                    
#define Para_Manu_1435           ManuPara[1435] //                                    
#define Para_Manu_1436           ManuPara[1436] //                                    
#define Para_Manu_1437           ManuPara[1437] //                                    
#define Para_Manu_1438           ManuPara[1438] //                                    
#define Para_Manu_1439           ManuPara[1439] //                                    
#define Para_Manu_1440           ManuPara[1440] //                                    
#define Para_Manu_1441           ManuPara[1441] //                                    
#define Para_Manu_1442           ManuPara[1442] //                                    
#define Para_Manu_1443           ManuPara[1443] //                                    
#define Para_Manu_1444           ManuPara[1444] //                                    
#define Para_Manu_1445           ManuPara[1445] //                                    
#define Para_Manu_1446           ManuPara[1446] //                                    
#define Para_Manu_1447           ManuPara[1447] //                                    
#define Para_Manu_1448           ManuPara[1448] //                                    
#define Para_Manu_1449           ManuPara[1449] //                                    
#define Para_Manu_1450           ManuPara[1450] //                                    
#define Para_Manu_1451           ManuPara[1451] //                                    
#define Para_Manu_1452           ManuPara[1452] //                                    
#define Para_Manu_1453           ManuPara[1453] //                                    
#define Para_Manu_1454           ManuPara[1454] //                                    
#define Para_Manu_1455           ManuPara[1455] //                                    
#define Para_Manu_1456           ManuPara[1456] //                                    
#define Para_Manu_1457           ManuPara[1457] //                                    
#define Para_Manu_1458           ManuPara[1458] //                                    
#define Para_Manu_1459           ManuPara[1459] //                                    
#define Para_Manu_1460           ManuPara[1460] //                                    
#define Para_Manu_1461           ManuPara[1461] //                                    
#define Para_Manu_1462           ManuPara[1462] //                                    
#define Para_Manu_1463           ManuPara[1463] //                                    
#define Para_Manu_1464           ManuPara[1464] //                                    
#define Para_Manu_1465           ManuPara[1465] //                                    
#define Para_Manu_1466           ManuPara[1466] //                                    
#define Para_Manu_1467           ManuPara[1467] //                                    
#define Para_Manu_1468           ManuPara[1468] //                                    
#define Para_Manu_1469           ManuPara[1469] //                                    
#define Para_Manu_1470           ManuPara[1470] //                                    
#define Para_Manu_1471           ManuPara[1471] //                                    
#define Para_Manu_1472           ManuPara[1472] //                                    
#define Para_Manu_1473           ManuPara[1473] //                                    
#define Para_Manu_1474           ManuPara[1474] //                                    
#define Para_Manu_1475           ManuPara[1475] //                                    
#define Para_Manu_1476           ManuPara[1476] //                                    
#define Para_Manu_1477           ManuPara[1477] //                                    
#define Para_Manu_1478           ManuPara[1478] //                                    
#define Para_Manu_1479           ManuPara[1479] //                                    
#define Para_Manu_1480           ManuPara[1480] //                                    
#define Para_Manu_1481           ManuPara[1481] //                                    
#define Para_Manu_1482           ManuPara[1482] //                                    
#define Para_Manu_1483           ManuPara[1483] //                                    
#define Para_Manu_1484           ManuPara[1484] //                                    
#define Para_Manu_1485           ManuPara[1485] //                                    
#define Para_Manu_1486           ManuPara[1486] //                                    
#define Para_Manu_1487           ManuPara[1487] //                                    
#define Para_Manu_1488           ManuPara[1488] //                                    
#define Para_Manu_1489           ManuPara[1489] //                                    
#define Para_Manu_1490           ManuPara[1490] //                                    
#define Para_Manu_1491           ManuPara[1491] //                                    
#define Para_Manu_1492           ManuPara[1492] //                                    
#define Para_Manu_1493           ManuPara[1493] //                                    
#define Para_Manu_1494           ManuPara[1494] //                                    
#define Para_Manu_1495           ManuPara[1495] //                                    
#define Para_Manu_1496           ManuPara[1496] //                                    
#define Para_Manu_1497           ManuPara[1497] //                                    
#define Para_Manu_1498           ManuPara[1498] //                                    
#define Para_Manu_1499           ManuPara[1499] //                                    
#define Para_Manu_1500           ManuPara[1500] //                                    
#define Para_Manu_1501           ManuPara[1501] //                                    
#define Para_Manu_1502           ManuPara[1502] //                                    
#define Para_Manu_1503           ManuPara[1503] //                                    
#define Para_Manu_1504           ManuPara[1504] //                                    
#define Para_Manu_1505           ManuPara[1505] //                                    
#define Para_Manu_1506           ManuPara[1506] //                                    
#define Para_Manu_1507           ManuPara[1507] //                                    
#define Para_Manu_1508           ManuPara[1508] //                                    
#define Para_Manu_1509           ManuPara[1509] //                                    
#define Para_Manu_1510           ManuPara[1510] //                                    
#define Para_Manu_1511           ManuPara[1511] //                                    
#define Para_Manu_1512           ManuPara[1512] //                                    
#define Para_Manu_1513           ManuPara[1513] //                                    
#define Para_Manu_1514           ManuPara[1514] //                                    
#define Para_Manu_1515           ManuPara[1515] //                                    
#define Para_Manu_1516           ManuPara[1516] //                                    
#define Para_Manu_1517           ManuPara[1517] //                                    
#define Para_Manu_1518           ManuPara[1518] //                                    
#define Para_Manu_1519           ManuPara[1519] //                                    
#define Para_Manu_1520           ManuPara[1520] //                                    
#define Para_Manu_1521           ManuPara[1521] //                                    
#define Para_Manu_1522           ManuPara[1522] //                                    
#define Para_Manu_1523           ManuPara[1523] //                                    
#define Para_Manu_1524           ManuPara[1524] //                                    
#define Para_Manu_1525           ManuPara[1525] //                                    
#define Para_Manu_1526           ManuPara[1526] //                                    
#define Para_Manu_1527           ManuPara[1527] //                                    
#define Para_Manu_1528           ManuPara[1528] //                                    
#define Para_Manu_1529           ManuPara[1529] //                                    
#define Para_Manu_1530           ManuPara[1530] //                                    
#define Para_Manu_1531           ManuPara[1531] //                                    
#define Para_Manu_1532           ManuPara[1532] //                                    
#define Para_Manu_1533           ManuPara[1533] //                                    
#define Para_Manu_1534           ManuPara[1534] //                                    
#define Para_Manu_1535           ManuPara[1535] //                                    
#define Para_Manu_1536           ManuPara[1536] //                                    
#define Para_Manu_1537           ManuPara[1537] //                                    
#define Para_Manu_1538           ManuPara[1538] //                                    
#define Para_Manu_1539           ManuPara[1539] //                                    
#define Para_Manu_1540           ManuPara[1540] //                                    
#define Para_Manu_1541           ManuPara[1541] //                                    
#define Para_Manu_1542           ManuPara[1542] //                                    
#define Para_Manu_1543           ManuPara[1543] //                                    
#define Para_Manu_1544           ManuPara[1544] //                                    
#define Para_Manu_1545           ManuPara[1545] //                                    
#define Para_Manu_1546           ManuPara[1546] //                                    
#define Para_Manu_1547           ManuPara[1547] //                                    
#define Para_Manu_1548           ManuPara[1548] //                                    
#define Para_Manu_1549           ManuPara[1549] //                                    
#define Para_Manu_1550           ManuPara[1550] //                                    
#define Para_Manu_1551           ManuPara[1551] //                                    
#define Para_Manu_1552           ManuPara[1552] //                                    
#define Para_Manu_1553           ManuPara[1553] //                                    
#define Para_Manu_1554           ManuPara[1554] //                                    
#define Para_Manu_1555           ManuPara[1555] //                                    
#define Para_Manu_1556           ManuPara[1556] //                                    
#define Para_Manu_1557           ManuPara[1557] //                                    
#define Para_Manu_1558           ManuPara[1558] //                                    
#define Para_Manu_1559           ManuPara[1559] //                                    
#define Para_Manu_1560           ManuPara[1560] //                                    
#define Para_Manu_1561           ManuPara[1561] //                                    
#define Para_Manu_1562           ManuPara[1562] //                                    
#define Para_Manu_1563           ManuPara[1563] //                                    
#define Para_Manu_1564           ManuPara[1564] //                                    
#define Para_Manu_1565           ManuPara[1565] //                                    
#define Para_Manu_1566           ManuPara[1566] //                                    
#define Para_Manu_1567           ManuPara[1567] //                                    
#define Para_Manu_1568           ManuPara[1568] //                                    
#define Para_Manu_1569           ManuPara[1569] //                                    
#define Para_Manu_1570           ManuPara[1570] //                                    
#define Para_Manu_1571           ManuPara[1571] //                                    
#define Para_Manu_1572           ManuPara[1572] //                                    
#define Para_Manu_1573           ManuPara[1573] //                                    
#define Para_Manu_1574           ManuPara[1574] //                                    
#define Para_Manu_1575           ManuPara[1575] //                                    
#define Para_Manu_1576           ManuPara[1576] //                                    
#define Para_Manu_1577           ManuPara[1577] //                                    
#define Para_Manu_1578           ManuPara[1578] //                                    
#define Para_Manu_1579           ManuPara[1579] //                                    
#define Para_Manu_1580           ManuPara[1580] //                                    
#define Para_Manu_1581           ManuPara[1581] //                                    
#define Para_Manu_1582           ManuPara[1582] //                                    
#define Para_Manu_1583           ManuPara[1583] //                                    
#define Para_Manu_1584           ManuPara[1584] //                                    
#define Para_Manu_1585           ManuPara[1585] //                                    
#define Para_Manu_1586           ManuPara[1586] //                                    
#define Para_Manu_1587           ManuPara[1587] //                                    
#define Para_Manu_1588           ManuPara[1588] //                                    
#define Para_Manu_1589           ManuPara[1589] //                                    
#define Para_Manu_1590           ManuPara[1590] //                                    
#define Para_Manu_1591           ManuPara[1591] //                                    
#define Para_Manu_1592           ManuPara[1592] //                                    
#define Para_Manu_1593           ManuPara[1593] //                                    
#define Para_Manu_1594           ManuPara[1594] //                                    
#define Para_Manu_1595           ManuPara[1595] //                                    
#define Para_Manu_1596           ManuPara[1596] //                                    
#define Para_Manu_1597           ManuPara[1597] //                                    
#define Para_Manu_1598           ManuPara[1598] //                                    
#define Para_Manu_1599           ManuPara[1599] //                                    
#define Para_Manu_1600           ManuPara[1600] //                                    
#define Para_Manu_1601           ManuPara[1601] //                                    
#define Para_Manu_1602           ManuPara[1602] //                                    
#define Para_Manu_1603           ManuPara[1603] //                                    
#define Para_Manu_1604           ManuPara[1604] //                                    
#define Para_Manu_1605           ManuPara[1605] //                                    
#define Para_Manu_1606           ManuPara[1606] //                                    
#define Para_Manu_1607           ManuPara[1607] //                                    
#define Para_Manu_1608           ManuPara[1608] //                                    
#define Para_Manu_1609           ManuPara[1609] //                                    
#define Para_Manu_1610           ManuPara[1610] //                                    
#define Para_Manu_1611           ManuPara[1611] //                                    
#define Para_Manu_1612           ManuPara[1612] //                                    
#define Para_Manu_1613           ManuPara[1613] //                                    
#define Para_Manu_1614           ManuPara[1614] //                                    
#define Para_Manu_1615           ManuPara[1615] //                                    
#define Para_Manu_1616           ManuPara[1616] //                                    
#define Para_Manu_1617           ManuPara[1617] //                                    
#define Para_Manu_1618           ManuPara[1618] //                                    
#define Para_Manu_1619           ManuPara[1619] //                                    
#define Para_Manu_1620           ManuPara[1620] //                                    
#define Para_Manu_1621           ManuPara[1621] //                                    
#define Para_Manu_1622           ManuPara[1622] //                                    
#define Para_Manu_1623           ManuPara[1623] //                                    
#define Para_Manu_1624           ManuPara[1624] //                                    
#define Para_Manu_1625           ManuPara[1625] //                                    
#define Para_Manu_1626           ManuPara[1626] //                                    
#define Para_Manu_1627           ManuPara[1627] //                                    
#define Para_Manu_1628           ManuPara[1628] //                                    
#define Para_Manu_1629           ManuPara[1629] //                                    
#define Para_Manu_1630           ManuPara[1630] //                                    
#define Para_Manu_1631           ManuPara[1631] //                                    
#define Para_Manu_1632           ManuPara[1632] //                                    
#define Para_Manu_1633           ManuPara[1633] //                                    
#define Para_Manu_1634           ManuPara[1634] //                                    
#define Para_Manu_1635           ManuPara[1635] //                                    
#define Para_Manu_1636           ManuPara[1636] //                                    
#define Para_Manu_1637           ManuPara[1637] //                                    
#define Para_Manu_1638           ManuPara[1638] //                                    
#define Para_Manu_1639           ManuPara[1639] //                                    
#define Para_Manu_1640           ManuPara[1640] //                                    
#define Para_Manu_1641           ManuPara[1641] //                                    
#define Para_Manu_1642           ManuPara[1642] //                                    
#define Para_Manu_1643           ManuPara[1643] //                                    
#define Para_Manu_1644           ManuPara[1644] //                                    
#define Para_Manu_1645           ManuPara[1645] //                                    
#define Para_Manu_1646           ManuPara[1646] //                                    
#define Para_Manu_1647           ManuPara[1647] //                                    
#define Para_Manu_1648           ManuPara[1648] //                                    
#define Para_Manu_1649           ManuPara[1649] //                                    
#define Para_Manu_1650           ManuPara[1650] //                                    
#define Para_Manu_1651           ManuPara[1651] //                                    
#define Para_Manu_1652           ManuPara[1652] //                                    
#define Para_Manu_1653           ManuPara[1653] //                                    
#define Para_Manu_1654           ManuPara[1654] //                                    
#define Para_Manu_1655           ManuPara[1655] //                                    
#define Para_Manu_1656           ManuPara[1656] //                                    
#define Para_Manu_1657           ManuPara[1657] //                                    
#define Para_Manu_1658           ManuPara[1658] //                                    
#define Para_Manu_1659           ManuPara[1659] //                                    
#define Para_Manu_1660           ManuPara[1660] //                                    
#define Para_Manu_1661           ManuPara[1661] //                                    
#define Para_Manu_1662           ManuPara[1662] //                                    
#define Para_Manu_1663           ManuPara[1663] //                                    
#define Para_Manu_1664           ManuPara[1664] //                                    
#define Para_Manu_1665           ManuPara[1665] //                                    
#define Para_Manu_1666           ManuPara[1666] //                                    
#define Para_Manu_1667           ManuPara[1667] //                                    
#define Para_Manu_1668           ManuPara[1668] //                                    
#define Para_Manu_1669           ManuPara[1669] //                                    
#define Para_Manu_1670           ManuPara[1670] //                                    
#define Para_Manu_1671           ManuPara[1671] //                                    
#define Para_Manu_1672           ManuPara[1672] //                                    
#define Para_Manu_1673           ManuPara[1673] //                                    
#define Para_Manu_1674           ManuPara[1674] //                                    
#define Para_Manu_1675           ManuPara[1675] //                                    
#define Para_Manu_1676           ManuPara[1676] //                                    
#define Para_Manu_1677           ManuPara[1677] //                                    
#define Para_Manu_1678           ManuPara[1678] //                                    
#define Para_Manu_1679           ManuPara[1679] //                                    
#define Para_Manu_1680           ManuPara[1680] //                                    
#define Para_Manu_1681           ManuPara[1681] //                                    
#define Para_Manu_1682           ManuPara[1682] //                                    
#define Para_Manu_1683           ManuPara[1683] //                                    
#define Para_Manu_1684           ManuPara[1684] //                                    
#define Para_Manu_1685           ManuPara[1685] //                                    
#define Para_Manu_1686           ManuPara[1686] //                                    
#define Para_Manu_1687           ManuPara[1687] //                                    
#define Para_Manu_1688           ManuPara[1688] //                                    
#define Para_Manu_1689           ManuPara[1689] //                                    
#define Para_Manu_1690           ManuPara[1690] //                                    
#define Para_Manu_1691           ManuPara[1691] //                                    
#define Para_Manu_1692           ManuPara[1692] //                                    
#define Para_Manu_1693           ManuPara[1693] //                                    
#define Para_Manu_1694           ManuPara[1694] //                                    
#define Para_Manu_1695           ManuPara[1695] //                                    
#define Para_Manu_1696           ManuPara[1696] //                                    
#define Para_Manu_1697           ManuPara[1697] //                                    
#define Para_Manu_1698           ManuPara[1698] //                                    
#define Para_Manu_1699           ManuPara[1699] //                                    
#define Para_Manu_1700           ManuPara[1700] //                                    
#define Para_Manu_1701           ManuPara[1701] //                                    
#define Para_Manu_1702           ManuPara[1702] //                                    
#define Para_Manu_1703           ManuPara[1703] //                                    
#define Para_Manu_1704           ManuPara[1704] //                                    
#define Para_Manu_1705           ManuPara[1705] //                                    
#define Para_Manu_1706           ManuPara[1706] //                                    
#define Para_Manu_1707           ManuPara[1707] //                                    
#define Para_Manu_1708           ManuPara[1708] //                                    
#define Para_Manu_1709           ManuPara[1709] //                                    
#define Para_Manu_1710           ManuPara[1710] //                                    
#define Para_Manu_1711           ManuPara[1711] //                                    
#define Para_Manu_1712           ManuPara[1712] //                                    
#define Para_Manu_1713           ManuPara[1713] //                                    
#define Para_Manu_1714           ManuPara[1714] //                                    
#define Para_Manu_1715           ManuPara[1715] //                                    
#define Para_Manu_1716           ManuPara[1716] //                                    
#define Para_Manu_1717           ManuPara[1717] //                                    
#define Para_Manu_1718           ManuPara[1718] //                                    
#define Para_Manu_1719           ManuPara[1719] //                                    
#define Para_Manu_1720           ManuPara[1720] //                                    
#define Para_Manu_1721           ManuPara[1721] //                                    
#define Para_Manu_1722           ManuPara[1722] //                                    
#define Para_Manu_1723           ManuPara[1723] //                                    
#define Para_Manu_1724           ManuPara[1724] //                                    
#define Para_Manu_1725           ManuPara[1725] //                                    
#define Para_Manu_1726           ManuPara[1726] //                                    
#define Para_Manu_1727           ManuPara[1727] //                                    
#define Para_Manu_1728           ManuPara[1728] //                                    
#define Para_Manu_1729           ManuPara[1729] //                                    
#define Para_Manu_1730           ManuPara[1730] //                                    
#define Para_Manu_1731           ManuPara[1731] //                                    
#define Para_Manu_1732           ManuPara[1732] //                                    
#define Para_Manu_1733           ManuPara[1733] //                                    
#define Para_Manu_1734           ManuPara[1734] //                                    
#define Para_Manu_1735           ManuPara[1735] //                                    
#define Para_Manu_1736           ManuPara[1736] //                                    
#define Para_Manu_1737           ManuPara[1737] //                                    
#define Para_Manu_1738           ManuPara[1738] //                                    
#define Para_Manu_1739           ManuPara[1739] //                                    
#define Para_Manu_1740           ManuPara[1740] //                                    
#define Para_Manu_1741           ManuPara[1741] //                                    
#define Para_Manu_1742           ManuPara[1742] //                                    
#define Para_Manu_1743           ManuPara[1743] //                                    
#define Para_Manu_1744           ManuPara[1744] //                                    
#define Para_Manu_1745           ManuPara[1745] //                                    
#define Para_Manu_1746           ManuPara[1746] //                                    
#define Para_Manu_1747           ManuPara[1747] //                                    
#define Para_Manu_1748           ManuPara[1748] //                                    
#define Para_Manu_1749           ManuPara[1749] //                                    
#define Para_Manu_1750           ManuPara[1750] //                                    
#define Para_Manu_1751           ManuPara[1751] //                                    
#define Para_Manu_1752           ManuPara[1752] //                                    
#define Para_Manu_1753           ManuPara[1753] //                                    
#define Para_Manu_1754           ManuPara[1754] //                                    
#define Para_Manu_1755           ManuPara[1755] //                                    
#define Para_Manu_1756           ManuPara[1756] //                                    
#define Para_Manu_1757           ManuPara[1757] //                                    
#define Para_Manu_1758           ManuPara[1758] //                                    
#define Para_Manu_1759           ManuPara[1759] //                                    
#define Para_Manu_1760           ManuPara[1760] //                                    
#define Para_Manu_1761           ManuPara[1761] //                                    
#define Para_Manu_1762           ManuPara[1762] //                                    
#define Para_Manu_1763           ManuPara[1763] //                                    
#define Para_Manu_1764           ManuPara[1764] //                                    
#define Para_Manu_1765           ManuPara[1765] //                                    
#define Para_Manu_1766           ManuPara[1766] //                                    
#define Para_Manu_1767           ManuPara[1767] //                                    
#define Para_Manu_1768           ManuPara[1768] //                                    
#define Para_Manu_1769           ManuPara[1769] //                                    
#define Para_Manu_1770           ManuPara[1770] //                                    
#define Para_Manu_1771           ManuPara[1771] //                                    
#define Para_Manu_1772           ManuPara[1772] //                                    
#define Para_Manu_1773           ManuPara[1773] //                                    
#define Para_Manu_1774           ManuPara[1774] //                                    
#define Para_Manu_1775           ManuPara[1775] //                                    
#define Para_Manu_1776           ManuPara[1776] //                                    
#define Para_Manu_1777           ManuPara[1777] //                                    
#define Para_Manu_1778           ManuPara[1778] //                                    
#define Para_Manu_1779           ManuPara[1779] //                                    
#define Para_Manu_1780           ManuPara[1780] //                                    
#define Para_Manu_1781           ManuPara[1781] //                                    
#define Para_Manu_1782           ManuPara[1782] //                                    
#define Para_Manu_1783           ManuPara[1783] //                                    
#define Para_Manu_1784           ManuPara[1784] //                                    
#define Para_Manu_1785           ManuPara[1785] //                                    
#define Para_Manu_1786           ManuPara[1786] //                                    
#define Para_Manu_1787           ManuPara[1787] //                                    
#define Para_Manu_1788           ManuPara[1788] //                                    
#define Para_Manu_1789           ManuPara[1789] //                                    
#define Para_Manu_1790           ManuPara[1790] //                                    
#define Para_Manu_1791           ManuPara[1791] //                                    
#define Para_Manu_1792           ManuPara[1792] //                                    
#define Para_Manu_1793           ManuPara[1793] //                                    
#define Para_Manu_1794           ManuPara[1794] //                                    
#define Para_Manu_1795           ManuPara[1795] //                                    
#define Para_Manu_1796           ManuPara[1796] //                                    
#define Para_Manu_1797           ManuPara[1797] //                                    
#define Para_Manu_1798           ManuPara[1798] //                                    
#define Para_Manu_1799           ManuPara[1799] //                                    
#define Para_Manu_1800           ManuPara[1800] //                                    
#define Para_Manu_1801           ManuPara[1801] //                                    
#define Para_Manu_1802           ManuPara[1802] //                                    
#define Para_Manu_1803           ManuPara[1803] //                                    
#define Para_Manu_1804           ManuPara[1804] //                                    
#define Para_Manu_1805           ManuPara[1805] //                                    
#define Para_Manu_1806           ManuPara[1806] //                                    
#define Para_Manu_1807           ManuPara[1807] //                                    
#define Para_Manu_1808           ManuPara[1808] //                                    
#define Para_Manu_1809           ManuPara[1809] //                                    
#define Para_Manu_1810           ManuPara[1810] //                                    
#define Para_Manu_1811           ManuPara[1811] //                                    
#define Para_Manu_1812           ManuPara[1812] //                                    
#define Para_Manu_1813           ManuPara[1813] //                                    
#define Para_Manu_1814           ManuPara[1814] //                                    
#define Para_Manu_1815           ManuPara[1815] //                                    
#define Para_Manu_1816           ManuPara[1816] //                                    
#define Para_Manu_1817           ManuPara[1817] //                                    
#define Para_Manu_1818           ManuPara[1818] //                                    
#define Para_Manu_1819           ManuPara[1819] //                                    
#define Para_Manu_1820           ManuPara[1820] //                                    
#define Para_Manu_1821           ManuPara[1821] //                                    
#define Para_Manu_1822           ManuPara[1822] //                                    
#define Para_Manu_1823           ManuPara[1823] //                                    
#define Para_Manu_1824           ManuPara[1824] //                                    
#define Para_Manu_1825           ManuPara[1825] //                                    
#define Para_Manu_1826           ManuPara[1826] //                                    
#define Para_Manu_1827           ManuPara[1827] //                                    
#define Para_Manu_1828           ManuPara[1828] //                                    
#define Para_Manu_1829           ManuPara[1829] //                                    
#define Para_Manu_1830           ManuPara[1830] //                                    
#define Para_Manu_1831           ManuPara[1831] //                                    
#define Para_Manu_1832           ManuPara[1832] //                                    
#define Para_Manu_1833           ManuPara[1833] //                                    
#define Para_Manu_1834           ManuPara[1834] //                                    
#define Para_Manu_1835           ManuPara[1835] //                                    
#define Para_Manu_1836           ManuPara[1836] //                                    
#define Para_Manu_1837           ManuPara[1837] //                                    
#define Para_Manu_1838           ManuPara[1838] //                                    
#define Para_Manu_1839           ManuPara[1839] //                                    
#define Para_Manu_1840           ManuPara[1840] //                                    
#define Para_Manu_1841           ManuPara[1841] //                                    
#define Para_Manu_1842           ManuPara[1842] //                                    
#define Para_Manu_1843           ManuPara[1843] //                                    
#define Para_Manu_1844           ManuPara[1844] //                                    
#define Para_Manu_1845           ManuPara[1845] //                                    
#define Para_Manu_1846           ManuPara[1846] //                                    
#define Para_Manu_1847           ManuPara[1847] //                                    
#define Para_Manu_1848           ManuPara[1848] //                                    
#define Para_Manu_1849           ManuPara[1849] //                                    
#define Para_Manu_1850           ManuPara[1850] //                                    
#define Para_Manu_1851           ManuPara[1851] //                                    
#define Para_Manu_1852           ManuPara[1852] //                                    
#define Para_Manu_1853           ManuPara[1853] //                                    
#define Para_Manu_1854           ManuPara[1854] //                                    
#define Para_Manu_1855           ManuPara[1855] //                                    
#define Para_Manu_1856           ManuPara[1856] //                                    
#define Para_Manu_1857           ManuPara[1857] //                                    
#define Para_Manu_1858           ManuPara[1858] //                                    
#define Para_Manu_1859           ManuPara[1859] //                                    
#define Para_Manu_1860           ManuPara[1860] //                                    
#define Para_Manu_1861           ManuPara[1861] //                                    
#define Para_Manu_1862           ManuPara[1862] //                                    
#define Para_Manu_1863           ManuPara[1863] //                                    
#define Para_Manu_1864           ManuPara[1864] //                                    
#define Para_Manu_1865           ManuPara[1865] //                                    
#define Para_Manu_1866           ManuPara[1866] //                                    
#define Para_Manu_1867           ManuPara[1867] //                                    
#define Para_Manu_1868           ManuPara[1868] //                                    
#define Para_Manu_1869           ManuPara[1869] //                                    
#define Para_Manu_1870           ManuPara[1870] //                                    
#define Para_Manu_1871           ManuPara[1871] //                                    
#define Para_Manu_1872           ManuPara[1872] //                                    
#define Para_Manu_1873           ManuPara[1873] //                                    
#define Para_Manu_1874           ManuPara[1874] //                                    
#define Para_Manu_1875           ManuPara[1875] //                                    
#define Para_Manu_1876           ManuPara[1876] //                                    
#define Para_Manu_1877           ManuPara[1877] //                                    
#define Para_Manu_1878           ManuPara[1878] //                                    
#define Para_Manu_1879           ManuPara[1879] //                                    
#define Para_Manu_1880           ManuPara[1880] //                                    
#define Para_Manu_1881           ManuPara[1881] //                                    
#define Para_Manu_1882           ManuPara[1882] //                                    
#define Para_Manu_1883           ManuPara[1883] //                                    
#define Para_Manu_1884           ManuPara[1884] //                                    
#define Para_Manu_1885           ManuPara[1885] //                                    
#define Para_Manu_1886           ManuPara[1886] //                                    
#define Para_Manu_1887           ManuPara[1887] //                                    
#define Para_Manu_1888           ManuPara[1888] //                                    
#define Para_Manu_1889           ManuPara[1889] //                                    
#define Para_Manu_1890           ManuPara[1890] //                                    
#define Para_Manu_1891           ManuPara[1891] //                                    
#define Para_Manu_1892           ManuPara[1892] //                                    
#define Para_Manu_1893           ManuPara[1893] //                                    
#define Para_Manu_1894           ManuPara[1894] //                                    
#define Para_Manu_1895           ManuPara[1895] //                                    
#define Para_Manu_1896           ManuPara[1896] //                                    
#define Para_Manu_1897           ManuPara[1897] //                                    
#define Para_Manu_1898           ManuPara[1898] //                                    
#define Para_MC_AricChange       ManuPara[1899] //关模算法选择                              关模算法：0-标准 1-智能关模
#define Para_MO_AricChange       ManuPara[1900] //开模算法选择                              开模算法：0-标准 1-智能开模 2-智能辅助
#define Para_MO_Sec1Pres         ManuPara[1901] //开模1段压力                              
#define Para_MO_Sec1Flow         ManuPara[1902] //开模1段流量                              
#define Para_MO_Sec2Pres         ManuPara[1903] //开模2段压力                              
#define Para_MO_Sec2Flow         ManuPara[1904] //开模2段流量                              
#define Para_MO_Sec2SPos         ManuPara[1905] //开模2段起始位置                            
#define Para_MO_Sec3Flow         ManuPara[1906] //开模3段流量                              
#define Para_MO_Sec3SPos         ManuPara[1907] //开模3段起始位置                            
#define Para_MO_Sec4Flow         ManuPara[1908] //开模4段流量                              
#define Para_MO_Sec4SPos         ManuPara[1909] //开模4段起始位置                            
#define Para_MO_Sec5Flow         ManuPara[1910] //开模5段流量                              
#define Para_MO_Sec5SPos         ManuPara[1911] //开模5段起始位置                            
#define Para_Manu_1912           ManuPara[1912] //                                    
#define Para_Manu_1913           ManuPara[1913] //                                    
#define Para_MoldOpenDeceFlow    ManuPara[1914] //开模减速流量                              
#define Para_MOAlg1_EndAcceRamp  ManuPara[1915] //算法1开模结束减速斜率                         开模结束减速斜率
#define Para_Manu_1916           ManuPara[1916] //                                    
#define Para_Manu_1917           ManuPara[1917] //                                    
#define Para_Manu_1918           ManuPara[1918] //                                    
#define Para_Manu_1919           ManuPara[1919] //                                    
#define Para_Manu_1920           ManuPara[1920] //                                    
#define Para_Manu_1921           ManuPara[1921] //                                    
#define Para_Manu_1922           ManuPara[1922] //                                    
#define Para_Manu_1923           ManuPara[1923] //                                    
#define Para_Manu_1924           ManuPara[1924] //                                    
#define Para_Manu_1925           ManuPara[1925] //                                    
#define Para_Manu_1926           ManuPara[1926] //                                    
#define Para_Manu_1927           ManuPara[1927] //                                    
#define Para_Manu_1928           ManuPara[1928] //                                    
#define Para_Manu_1929           ManuPara[1929] //                                    
#define Para_Manu_1930           ManuPara[1930] //                                    
#define Para_Manu_1931           ManuPara[1931] //                                    
#define Para_Manu_1932           ManuPara[1932] //                                    
#define Para_Manu_1933           ManuPara[1933] //                                    
#define Para_Manu_1934           ManuPara[1934] //                                    
#define Para_Manu_1935           ManuPara[1935] //                                    
#define Para_Manu_1936           ManuPara[1936] //                                    
#define Para_Manu_1937           ManuPara[1937] //                                    
#define Para_Manu_1938           ManuPara[1938] //                                    
#define Para_Manu_1939           ManuPara[1939] //                                    
#define Para_Manu_1940           ManuPara[1940] //                                    
#define Para_Manu_1941           ManuPara[1941] //                                    
#define Para_Manu_1942           ManuPara[1942] //                                    
#define Para_Manu_1943           ManuPara[1943] //                                    
#define Para_Manu_1944           ManuPara[1944] //                                    
#define Para_Manu_1945           ManuPara[1945] //                                    
#define Para_Manu_1946           ManuPara[1946] //                                    
#define Para_Manu_1947           ManuPara[1947] //                                    
#define Para_Manu_1948           ManuPara[1948] //                                    
#define Para_Manu_1949           ManuPara[1949] //                                    
#define Para_Manu_1950           ManuPara[1950] //                                    
#define Para_Manu_1951           ManuPara[1951] //                                    
#define Para_Manu_1952           ManuPara[1952] //                                    
#define Para_Manu_1953           ManuPara[1953] //                                    
#define Para_Manu_1954           ManuPara[1954] //                                    
#define Para_Manu_1955           ManuPara[1955] //                                    
#define Para_Manu_1956           ManuPara[1956] //                                    
#define Para_Manu_1957           ManuPara[1957] //                                    
#define Para_Manu_1958           ManuPara[1958] //                                    
#define Para_Manu_1959           ManuPara[1959] //                                    
#define Para_Manu_1960           ManuPara[1960] //                                    
#define Para_Manu_1961           ManuPara[1961] //                                    
#define Para_Manu_1962           ManuPara[1962] //                                    
#define Para_Manu_1963           ManuPara[1963] //                                    
#define Para_Manu_1964           ManuPara[1964] //                                    
#define Para_Manu_1965           ManuPara[1965] //                                    
#define Para_Manu_1966           ManuPara[1966] //                                    
#define Para_Manu_1967           ManuPara[1967] //                                    
#define Para_Manu_1968           ManuPara[1968] //                                    
#define Para_Manu_1969           ManuPara[1969] //                                    
#define Para_Manu_1970           ManuPara[1970] //                                    
#define Para_Manu_1971           ManuPara[1971] //                                    
#define Para_Manu_1972           ManuPara[1972] //                                    
#define Para_Manu_1973           ManuPara[1973] //                                    
#define Para_Manu_1974           ManuPara[1974] //                                    
#define Para_Manu_1975           ManuPara[1975] //                                    
#define Para_Manu_1976           ManuPara[1976] //                                    
#define Para_Manu_1977           ManuPara[1977] //                                    
#define Para_Manu_1978           ManuPara[1978] //                                    
#define Para_Manu_1979           ManuPara[1979] //                                    
#define Para_Manu_1980           ManuPara[1980] //                                    
#define Para_Manu_1981           ManuPara[1981] //                                    
#define Para_Manu_1982           ManuPara[1982] //                                    
#define Para_Manu_1983           ManuPara[1983] //                                    
#define Para_Manu_1984           ManuPara[1984] //                                    
#define Para_Manu_1985           ManuPara[1985] //                                    
#define Para_Manu_1986           ManuPara[1986] //                                    
#define Para_Manu_1987           ManuPara[1987] //                                    
#define Para_Manu_1988           ManuPara[1988] //                                    
#define Para_Manu_1989           ManuPara[1989] //                                    
#define Para_Manu_1990           ManuPara[1990] //                                    
#define Para_Manu_1991           ManuPara[1991] //                                    
#define Para_Manu_1992           ManuPara[1992] //                                    
#define Para_Manu_1993           ManuPara[1993] //                                    
#define Para_Manu_1994           ManuPara[1994] //                                    
#define Para_Manu_1995           ManuPara[1995] //                                    
#define Para_Manu_1996           ManuPara[1996] //                                    
#define Para_Manu_1997           ManuPara[1997] //                                    
#define Para_Manu_1998           ManuPara[1998] //                                    
#define Para_Manu_1999           ManuPara[1999] //                                    
#define Para_Manu_2000           ManuPara[2000] //                                    
#define Para_Manu_2001           ManuPara[2001] //                                    
#define Para_Manu_2002           ManuPara[2002] //                                    
#define Para_Manu_2003           ManuPara[2003] //                                    
#define Para_Manu_2004           ManuPara[2004] //                                    
#define Para_Manu_2005           ManuPara[2005] //                                    
#define Para_Manu_2006           ManuPara[2006] //                                    
#define Para_Manu_2007           ManuPara[2007] //                                    
#define Para_Manu_2008           ManuPara[2008] //                                    
#define Para_Manu_2009           ManuPara[2009] //                                    
#define Para_Manu_2010           ManuPara[2010] //                                    
#define Para_Manu_2011           ManuPara[2011] //                                    
#define Para_Manu_2012           ManuPara[2012] //                                    
#define Para_Manu_2013           ManuPara[2013] //                                    
#define Para_Manu_2014           ManuPara[2014] //                                    
#define Para_Manu_2015           ManuPara[2015] //                                    
#define Para_Manu_2016           ManuPara[2016] //                                    
#define Para_Manu_2017           ManuPara[2017] //                                    
#define Para_Manu_2018           ManuPara[2018] //                                    
#define Para_Manu_2019           ManuPara[2019] //                                    
#define Para_Manu_2020           ManuPara[2020] //                                    
#define Para_Manu_2021           ManuPara[2021] //                                    
#define Para_Manu_2022           ManuPara[2022] //                                    
#define Para_Manu_2023           ManuPara[2023] //                                    
#define Para_Manu_2024           ManuPara[2024] //                                    
#define Para_Manu_2025           ManuPara[2025] //                                    
#define Para_Manu_2026           ManuPara[2026] //                                    
#define Para_Manu_2027           ManuPara[2027] //                                    
#define Para_Manu_2028           ManuPara[2028] //                                    
#define Para_Manu_2029           ManuPara[2029] //                                    
#define Para_CoolMoldOpenSel     ManuPara[2030] //冷却时开模选择                             应锐能加
#define Para_CoolMoldOpenDly     ManuPara[2031] //冷却时开模延时                             应锐能加
#define Para_CoolMoldOpenPos     ManuPara[2032] //冷却时开模距离                             应锐能加,指油缸距离
#define Para_Manu_2033           ManuPara[2033] //                                    
#define Para_Manu_2034           ManuPara[2034] //                                    
#define Para_Manu_2035           ManuPara[2035] //                                    
#define Para_Manu_2036           ManuPara[2036] //                                    
#define Para_Manu_2037           ManuPara[2037] //                                    
#define Para_Manu_2038           ManuPara[2038] //                                    
#define Para_Manu_2039           ManuPara[2039] //                                    
#define Para_Manu_2040           ManuPara[2040] //                                    
#define Para_Manu_2041           ManuPara[2041] //                                    
#define Para_Manu_2042           ManuPara[2042] //                                    
#define Para_Manu_2043           ManuPara[2043] //                                    
#define Para_Manu_2044           ManuPara[2044] //                                    
#define Para_Manu_2045           ManuPara[2045] //                                    
#define Para_Manu_2046           ManuPara[2046] //                                    
#define Para_Manu_2047           ManuPara[2047] //                                    

#endif
