/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_ActDisp.h    动作显示定义文件
适用范围：主机
建立时间：2026-1-23 14:45:52
RPHA版本：V208
特征代码：0xC9C5    
****************************************************************************************************/
#ifndef CM_ActDisp_h
    #define CM_ActDisp_h

#ifdef CM_ActDisp_c
    #define CM_ActDisp_ext
#else
    #define CM_ActDisp_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//动作显示数量
#define mActDispNum 256  //动作显示数量

//动作显示序号宏定义
#define mActDisp_Transparent     0              //待机                                  特殊用途，透明显示，即显示优先级最低
#define mActDisp_Null            1              //                                    特殊用途，空白显示
#define mActDisp_Idle            2              //待机                                  
#define mActDisp_MoldCls         3              //关模                                  
#define mActDisp_MoldCls1        4              //关模一段                                
#define mActDisp_MoldCls2        5              //关模二段                                
#define mActDisp_MoldCls3        6              //关模三段                                
#define mActDisp_MoldClsLP       7              //低压关模                                
#define mActDisp_MoldClsHP       8              //高压关模                                
#define mActDisp_MoldOpen        9              //开模                                  
#define mActDisp_MoldOpen1       10             //开模一段                                
#define mActDisp_MoldOpen2       11             //开模二段                                
#define mActDisp_MoldOpen3       12             //开模三段                                
#define mActDisp_MoldOpen4       13             //开模四段                                
#define mActDisp_MoldOpen5       14             //开模五段                                
#define mActDisp_Inject          15             //注射                                  
#define mActDisp_HoldPres        16             //保压                                  
#define mActDisp_Inject1         17             //注射一                                 
#define mActDisp_Inject2         18             //注射二                                 
#define mActDisp_Inject3         19             //注射三                                 
#define mActDisp_Inject4         20             //注射四                                 
#define mActDisp_Inject5         21             //注射五                                 
#define mActDisp_Inject6         22             //注射六                                 
#define mActDisp_Inject7         23             //注射七                                 
#define mActDisp_Inject8         24             //注射八                                 
#define mActDisp_Inject9         25             //注射九                                 
#define mActDisp_Inject10        26             //注射十                                 
#define mActDisp_HoldPres1       27             //保压一                                 
#define mActDisp_HoldPres2       28             //保压二                                 
#define mActDisp_HoldPres3       29             //保压三                                 
#define mActDisp_HoldPres4       30             //保压四                                 
#define mActDisp_HoldPres5       31             //保压五                                 
#define mActDisp_HoldPres6       32             //保压六                                 
#define mActDisp_HoldPres7       33             //保压七                                 
#define mActDisp_HoldPres8       34             //保压八                                 
#define mActDisp_HoldPres9       35             //保压九                                 
#define mActDisp_HoldPres10      36             //保压十                                 
#define mActDisp_Charge          37             //储料                                  
#define mActDisp_Charge1         38             //储料一                                 
#define mActDisp_Charge2         39             //储料二                                 
#define mActDisp_Charge3         40             //储料三                                 
#define mActDisp_Charge4         41             //储料四                                 
#define mActDisp_Charge5         42             //储料五                                 
#define mActDisp_Charge6         43             //储料六                                 
#define mActDisp_Charge7         44             //储料七                                 
#define mActDisp_Charge8         45             //储料八                                 
#define mActDisp_Charge9         46             //储料九                                 
#define mActDisp_Charge10        47             //储料十                                 
#define mActDisp_SuckBack        48             //射退                                  
#define mActDisp_Purge           49             //清料                                  
#define mActDisp_NozOn           50             //喷嘴开                                 
#define mActDisp_NozOff          51             //喷嘴关                                 
#define mActDisp_Eject           52             //托模                                  
#define mActDisp_EjectFor        53             //托模进                                 
#define mActDisp_EjectRet        54             //托模退                                 
#define mActDisp_EjectRet1       55             //托模退一                                
#define mActDisp_EjectRet2       56             //托模退二                                
#define mActDisp_EjectFor1       57             //托模进一                                
#define mActDisp_EjectFor2       58             //托模进二                                
#define mActDisp_EjectDly        59             //托模延时                                
#define mActDisp_Air             60             //吹气                                  
#define mActDisp_AirA            61             //吹气A                                 
#define mActDisp_AirB            62             //吹气B                                 
#define mActDisp_AirC            63             //吹气C                                 
#define mActDisp_AirD            64             //吹气D                                 
#define mActDisp_AirE            65             //吹气E                                 
#define mActDisp_AirF            66             //吹气F                                 
#define mActDisp_AirMov          67             //公模吹气                                
#define mActDisp_AirStn          68             //母模吹气                                
#define mActDisp_MoldThick       69             //调模退                                 
#define mActDisp_MoldThin        70             //调模进                                 
#define mActDisp_Nozzle          71             //座台                                  
#define mActDisp_NozForSlow      72             //座进慢速                                
#define mActDisp_NozForFast      73             //座进快速                                
#define mActDisp_NozRetSlow      74             //座退慢速                                
#define mActDisp_NozRetFast      75             //座退快速                                
#define mActDisp_NozFor1         76             //座进一                                 
#define mActDisp_NozFor2         77             //座进二                                 
#define mActDisp_NozRet1         78             //座退一                                 
#define mActDisp_NozRet2         79             //座退二                                 
#define mActDisp_NozRet          80             //座台退                                 
#define mActDisp_NozFor          81             //座台进                                 
#define mActDisp_MotorOff        82             //马达关                                 
#define mActDisp_MotorOn         83             //马达开                                 
#define mActDisp_OilHeater       84             //油温预热                                
#define mActDisp_Robot           85             //机械手                                 
#define mActDisp_PhotoSen        86             //电眼检物                                
#define mActDisp_Lubr1           87             //润滑                                  
#define mActDisp_Lubr2           88             //润滑二                                 
#define mActDisp_Cool            89             //产品冷却                                
#define mActDisp_CoolBefChg      90             //储前冷却                                
#define mActDisp_CycDly          91             //循环延时                                
#define mActDisp_Acc             92             //蓄能                                  
#define mActDisp_Delay           93             //延时                                  
#define mActDisp_ClsDoor         94             //关安全门                                
#define mActDisp_OpenDoor        95             //开安全门                                
#define mActDisp_CoreIn          96             //中子 进                                
#define mActDisp_CoreOut         97             //中子 退                                
#define mActDisp_CoreAIn         98             //中子A进                                
#define mActDisp_CoreAOut        99             //中子A退                                
#define mActDisp_CoreBIn         100            //中子B进                                
#define mActDisp_CoreBOut        101            //中子B退                                
#define mActDisp_CoreCIn         102            //中子C进                                
#define mActDisp_CoreCOut        103            //中子C退                                
#define mActDisp_CoreDIn         104            //中子D进                                
#define mActDisp_CoreDOut        105            //中子D退                                
#define mActDisp_CoreEIn         106            //中子E进                                
#define mActDisp_CoreEOut        107            //中子E退                                
#define mActDisp_CoreFIn         108            //中子F进                                
#define mActDisp_CoreFOut        109            //中子F退                                
#define mActDisp_CoreGIn         110            //中子G进                                
#define mActDisp_CoreGOut        111            //中子G退                                
#define mActDisp_CoreHIn         112            //中子H进                                
#define mActDisp_CoreHOut        113            //中子H退                                
#define mActDisp_CoreIIn         114            //中子I进                                
#define mActDisp_CoreIOut        115            //中子I退                                
#define mActDisp_CoreJIn         116            //中子J进                                
#define mActDisp_CoreJOut        117            //中子J退                                
#define mActDisp_CoreKIn         118            //中子K进                                
#define mActDisp_CoreKOut        119            //中子K退                                
#define mActDisp_CoreLIn         120            //中子L进                                
#define mActDisp_CoreLOut        121            //中子L退                                
#define mActDisp_SrwIn           122            //绞牙 进                                
#define mActDisp_SrwOut          123            //绞牙 退                                
#define mActDisp_SrwAIn          124            //绞牙A进                                
#define mActDisp_SrwAOut         125            //绞牙A退                                
#define mActDisp_SrwBIn          126            //绞牙B进                                
#define mActDisp_SrwBOut         127            //绞牙B退                                
#define mActDisp_SrwCIn          128            //绞牙C进                                
#define mActDisp_SrwCOut         129            //绞牙C退                                
#define mActDisp_SrwDIn          130            //绞牙D进                                
#define mActDisp_SrwDOut         131            //绞牙D退                                
#define mActDisp_SrwEIn          132            //绞牙E进                                
#define mActDisp_SrwEOut         133            //绞牙E退                                
#define mActDisp_SrwFIn          134            //绞牙F进                                
#define mActDisp_SrwFOut         135            //绞牙F退                                
#define mActDisp_SrwGIn          136            //绞牙G进                                
#define mActDisp_SrwGOut         137            //绞牙G退                                
#define mActDisp_SrwHIn          138            //绞牙H进                                
#define mActDisp_SrwHOut         139            //绞牙H退                                
#define mActDisp_SrwIIn          140            //绞牙I进                                
#define mActDisp_SrwIOut         141            //绞牙I退                                
#define mActDisp_SrwJIn          142            //绞牙J进                                
#define mActDisp_SrwJOut         143            //绞牙J退                                
#define mActDisp_SrwKIn          144            //绞牙K进                                
#define mActDisp_SrwKOut         145            //绞牙K退                                
#define mActDisp_SrwLIn          146            //绞牙L进                                
#define mActDisp_SrwLOut         147            //绞牙L退                                
#define mActDisp_148             148            //                                    
#define mActDisp_149             149            //                                    
#define mActDisp_150             150            //                                    
#define mActDisp_Exhaust         151            //排气                                  
#define mActDisp_PilotOilAcc     152            //先导储能                                注射、合模插装阀油路机器（通常装配于1600T以上大机），先导油蓄能器储能
#define mActDisp_BMCFeedIn       153            //加料进                                 
#define mActDisp_BMCFeedOut      154            //加料退                                 
#define mActDisp_BMCCoverOpen    155            //压料盖开                                
#define mActDisp_BMCCoverCls     156            //压料盖关                                
#define mActDisp_RelPres         157            //卸压                                  中子、阀门卸压
#define mActDisp_158             158            //                                    
#define mActDisp_159             159            //                                    
#define mActDisp_160             160            //                                    
#define mActDisp_161             161            //                                    
#define mActDisp_162             162            //                                    
#define mActDisp_163             163            //                                    
#define mActDisp_164             164            //                                    
#define mActDisp_165             165            //                                    
#define mActDisp_FrtBrkIn        166            //头闸板进                                用于抽拉杆功能
#define mActDisp_FrtBrkOut       167            //头闸板退                                用于抽拉杆功能
#define mActDisp_ReBrkIn         168            //尾闸板进                                用于抽拉杆功能
#define mActDisp_ReBrkOut        169            //尾闸板退                                用于抽拉杆功能
#define mActDisp_TieBarFw        170            //拉杆进                                 用于抽拉杆功能
#define mActDisp_TieBarBw        171            //拉杆退                                 用于抽拉杆功能
#define mActDisp_MoldAdjLubr     172            //调模润滑                                应调模润滑
#define mActDisp_HPVC_In         173            //阀芯进                                 保压阀芯进
#define mActDisp_HPVC_Out        174            //阀芯退                                 保压阀芯退
#define mActDisp_HoldPresOut     175            //保压退                                 保压退
#define mActDisp_176             176            //                                    
#define mActDisp_177             177            //                                    
#define mActDisp_178             178            //                                    
#define mActDisp_179             179            //                                    
#define mActDisp_180             180            //                                    
#define mActDisp_181             181            //                                    
#define mActDisp_182             182            //                                    
#define mActDisp_183             183            //                                    
#define mActDisp_184             184            //                                    
#define mActDisp_185             185            //                                    
#define mActDisp_186             186            //                                    
#define mActDisp_187             187            //                                    
#define mActDisp_188             188            //                                    
#define mActDisp_189             189            //                                    
#define mActDisp_190             190            //                                    
#define mActDisp_191             191            //                                    
#define mActDisp_192             192            //                                    
#define mActDisp_193             193            //                                    
#define mActDisp_194             194            //                                    
#define mActDisp_195             195            //                                    
#define mActDisp_196             196            //                                    
#define mActDisp_197             197            //                                    
#define mActDisp_198             198            //                                    
#define mActDisp_199             199            //                                    
#define mActDisp_200             200            //                                    
#define mActDisp_201             201            //                                    
#define mActDisp_202             202            //                                    
#define mActDisp_203             203            //                                    
#define mActDisp_204             204            //                                    
#define mActDisp_205             205            //                                    
#define mActDisp_206             206            //                                    
#define mActDisp_207             207            //                                    
#define mActDisp_208             208            //                                    
#define mActDisp_209             209            //                                    
#define mActDisp_210             210            //                                    
#define mActDisp_211             211            //                                    
#define mActDisp_212             212            //                                    
#define mActDisp_213             213            //                                    
#define mActDisp_214             214            //                                    
#define mActDisp_215             215            //                                    
#define mActDisp_216             216            //                                    
#define mActDisp_217             217            //                                    
#define mActDisp_218             218            //                                    
#define mActDisp_219             219            //                                    
#define mActDisp_220             220            //                                    
#define mActDisp_221             221            //                                    
#define mActDisp_222             222            //                                    
#define mActDisp_223             223            //                                    
#define mActDisp_224             224            //                                    
#define mActDisp_225             225            //                                    
#define mActDisp_226             226            //                                    
#define mActDisp_227             227            //                                    
#define mActDisp_228             228            //                                    
#define mActDisp_229             229            //                                    
#define mActDisp_230             230            //                                    
#define mActDisp_231             231            //                                    
#define mActDisp_232             232            //                                    
#define mActDisp_233             233            //                                    
#define mActDisp_234             234            //                                    
#define mActDisp_235             235            //                                    
#define mActDisp_236             236            //                                    
#define mActDisp_237             237            //                                    
#define mActDisp_238             238            //                                    
#define mActDisp_239             239            //                                    
#define mActDisp_240             240            //                                    
#define mActDisp_241             241            //                                    
#define mActDisp_242             242            //                                    
#define mActDisp_243             243            //                                    
#define mActDisp_244             244            //                                    
#define mActDisp_245             245            //                                    
#define mActDisp_246             246            //                                    
#define mActDisp_247             247            //                                    
#define mActDisp_248             248            //                                    
#define mActDisp_249             249            //                                    
#define mActDisp_250             250            //                                    
#define mActDisp_251             251            //                                    
#define mActDisp_252             252            //                                    
#define mActDisp_253             253            //                                    
#define mActDisp_254             254            //                                    
#define mActDisp_255             255            //                                    

#endif
