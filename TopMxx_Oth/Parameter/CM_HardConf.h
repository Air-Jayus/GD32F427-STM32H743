/* Copyright (C) 2010 *******************************************************************************
                                    杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5平台注塑机控制系统
项目简介：
======================================== 文   件    信   息 =========================================
文件名称：CM_HardConf.h    硬件配置文件
适用范围：主机
建立时间：2026-5-7 9:20:15
RPHA版本：V208
特征代码：  0x85FE  
****************************************************************************************************/
#ifndef CM_HardConf_h
    #define CM_HardConf_h

#ifdef RPHA_c
    #define CM_HardConf_ext
#else
    #define CM_HardConf_ext extern
#endif

/*====================================== 全局有效宏及变量定义 ======================================*/
//硬件配置数量
#define mHardConfNum 1024  //硬件配置数量

//硬件配置数组定义
CM_HardConf_ext U16 HardConf[mHardConfNum];        //硬件配置数组

//硬件接口序号宏定义
#define mHardConf_HardConfSum    0              //辅助用，下述硬件配置累加和                       
#define mHardConf_HardConfLinkCode 1            //辅助用，硬件配置互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效 
#define mHardConf_HardConfVer    2              //辅助用，硬件配置版本号                         
#define mHardConf_HardConfID     3              //辅助用，硬件配置ID，用于售后维护                   
#define mHardConf_PlatLinkCode   4              //辅助用，硬件平台互连代码(0x11-F5 0x22-F3 0x33-F1s 0x55-F3s 0x66-h3 0xE1-H1 0xE3-H3 0xE5-H5) 
#define mHardConf_PlatTypeC0     5              //辅助用，硬件平台型号字符0                       
#define mHardConf_PlatTypeC1     6              //辅助用，硬件平台型号字符1                       
#define mHardConf_PlatTypeC2     7              //辅助用，硬件平台型号字符2                       
#define mHardConf_PlatTypeC3     8              //辅助用，硬件平台型号字符3                       
#define mHardConf_PlatTypeC4     9              //辅助用，硬件平台型号字符4                       
#define mHardConf_PlatTypeC5     10             //辅助用，硬件平台型号字符5                       
#define mHardConf_PlatTypeC6     11             //辅助用，硬件平台型号字符6                       
#define mHardConf_PlatTypeC7     12             //辅助用，硬件平台型号字符7                       
#define mHardConf_CMPlatTypeSN   13             //辅助用，主机硬件平台型号序号(0～5,其中F3=1、P01=2、F1s=3、F3s=5、h3=6、H1=7、H3=8、H5=9) 
#define mHardConf_DINum          14             //辅助用，DI点数                            
#define mHardConf_DONum          15             //辅助用，DO点数                            
#define mHardConf_RLYNum         16             //辅助用，继电器路数(模块中计入DO)                  
#define mHardConf_DANum          17             //辅助用，DA路数                            
#define mHardConf_HADNum         18             //辅助用，HAD路数                           
#define mHardConf_LADNum         19             //辅助用，LAD路数(一般选择8通道或11通道)             
#define mHardConf_CNTNum         20             //辅助用，CNT路数(暂未使用)                     
#define mHardConf_MADNum         21             //辅助用，MAD路数                           
#define mHardConf_E1Use          22             //辅助用，模块1是否使用                         
#define mHardConf_E1DINum        23             //辅助用，模块1的DI点数，必须配置DI/LAD/HAD/CNT中至少一项，否则程序有BUG(总线断开不报警) 
#define mHardConf_E1DONum        24             //辅助用，模块1的DO点数                        
#define mHardConf_E1DANum        25             //辅助用，模块1的DA路数                        
#define mHardConf_E1HADNum       26             //辅助用，模块1的HAD路数                       
#define mHardConf_E1LADNum       27             //辅助用，模块1的LAD路数                       
#define mHardConf_E1CNTNum       28             //辅助用，模块1的CNT路数                       
#define mHardConf_29             29             //                                    
#define mHardConf_30             30             //                                    
#define mHardConf_E2Use          31             //辅助用，模块2是否使用                         
#define mHardConf_E2DINum        32             //辅助用，模块2的DI点数                        
#define mHardConf_E2DONum        33             //辅助用，模块2的DO点数                        
#define mHardConf_E2DANum        34             //辅助用，模块2的DA路数                        
#define mHardConf_E2HADNum       35             //辅助用，模块2的HAD路数                       
#define mHardConf_E2LADNum       36             //辅助用，模块2的LAD路数                       
#define mHardConf_E2CNTNum       37             //辅助用，模块2的CNT路数                       
#define mHardConf_38             38             //                                    
#define mHardConf_39             39             //                                    
#define mHardConf_E3Use          40             //辅助用，模块3是否使用                         
#define mHardConf_E3DINum        41             //辅助用，模块3的DI点数                        
#define mHardConf_E3DONum        42             //辅助用，模块3的DO点数                        
#define mHardConf_E3DANum        43             //辅助用，模块3的DA路数                        
#define mHardConf_E3HADNum       44             //辅助用，模块3的HAD路数                       
#define mHardConf_E3LADNum       45             //辅助用，模块3的LAD路数                       
#define mHardConf_E3CNTNum       46             //辅助用，模块3的CNT路数                       
#define mHardConf_47             47             //                                    
#define mHardConf_48             48             //                                    
#define mHardConf_E4Use          49             //辅助用，模块4是否使用                         
#define mHardConf_E4DINum        50             //辅助用，模块4的DI点数                        
#define mHardConf_E4DONum        51             //辅助用，模块4的DO点数                        
#define mHardConf_E4DANum        52             //辅助用，模块4的DA路数                        
#define mHardConf_E4HADNum       53             //辅助用，模块4的HAD路数                       
#define mHardConf_E4LADNum       54             //辅助用，模块4的LAD路数                       
#define mHardConf_E4CNTNum       55             //辅助用，模块4的CNT路数                       
#define mHardConf_56             56             //                                    
#define mHardConf_57             57             //                                    
#define mHardConf_E5Use          58             //辅助用，模块5是否使用                         
#define mHardConf_E5DINum        59             //辅助用，模块5的DI点数                        
#define mHardConf_E5DONum        60             //辅助用，模块5的DO点数                        
#define mHardConf_E5DANum        61             //辅助用，模块5的DA路数                        
#define mHardConf_E5HADNum       62             //辅助用，模块5的HAD路数                       
#define mHardConf_E5LADNum       63             //辅助用，模块5的LAD路数                       
#define mHardConf_E5CNTNum       64             //辅助用，模块5的CNT路数                       
#define mHardConf_65             65             //                                    
#define mHardConf_66             66             //                                    
#define mHardConf_E6Use          67             //辅助用，模块6是否使用                         
#define mHardConf_E6DINum        68             //辅助用，模块6的DI点数                        
#define mHardConf_E6DONum        69             //辅助用，模块6的DO点数                        
#define mHardConf_E6DANum        70             //辅助用，模块6的DA路数                        
#define mHardConf_E6HADNum       71             //辅助用，模块6的HAD路数                       
#define mHardConf_E6LADNum       72             //辅助用，模块6的LAD路数                       
#define mHardConf_E6CNTNum       73             //辅助用，模块6的CNT路数                       
#define mHardConf_74             74             //                                    
#define mHardConf_HardConfStart  75             //辅助用，用于定位，禁止修改                       

#define mHard_DI01               76             //DI输入点                               DI
#define mHard_DI02               77             //DI输入点                               DI
#define mHard_DI03               78             //DI输入点                               DI
#define mHard_DI04               79             //DI输入点                               DI
#define mHard_DI05               80             //DI输入点                               DI
#define mHard_DI06               81             //DI输入点                               DI
#define mHard_DI07               82             //DI输入点                               DI
#define mHard_DI08               83             //DI输入点                               DI
#define mHard_DI09               84             //DI输入点                               DI
#define mHard_DI10               85             //DI输入点                               DI
#define mHard_DI11               86             //DI输入点                               DI
#define mHard_DI12               87             //DI输入点                               DI
#define mHard_DI13               88             //DI输入点                               DI
#define mHard_DI14               89             //DI输入点                               DI
#define mHard_DI15               90             //DI输入点                               DI
#define mHard_DI16               91             //DI输入点                               DI
#define mHard_DI17               92             //DI输入点，电路相关，禁止更改对应资源                 DI
#define mHard_DI18               93             //DI输入点，电路相关，禁止更改对应资源                 DI
#define mHard_DI19               94             //DI输入点，电路相关，禁止更改对应资源                 DI
#define mHard_DI20               95             //DI输入点                               DI
#define mHard_DI21               96             //DI输入点                               DI
#define mHard_DI22               97             //DI输入点                               DI
#define mHard_DI23               98             //DI输入点                               DI
#define mHard_DI24               99             //DI输入点                               DI
#define mHard_DI25               100            //DI输入点                               DI
#define mHard_DI26               101            //DI输入点                               DI
#define mHard_DI27               102            //DI输入点                               DI
#define mHard_DI28               103            //DI输入点                               DI
#define mHard_DI29               104            //DI输入点                               DI
#define mHard_DI30               105            //DI输入点                               DI
#define mHard_DI31               106            //DI输入点                               DI
#define mHard_DI32               107            //DI输入点                               DI
#define mHard_DI33               108            //DI输入点                               DI
#define mHard_DI34               109            //DI输入点                               DI
#define mHard_DI35               110            //DI输入点                               DI
#define mHard_DI36               111            //DI输入点                               DI
#define mHard_DI37               112            //DI输入点                               DI
#define mHard_DI38               113            //DI输入点                               DI
#define mHard_DI39               114            //DI输入点                               DI
#define mHard_DI40               115            //DI输入点                               DI
#define mHard_DI41               116            //DI输入点                               DI
#define mHard_DI42               117            //DI输入点                               DI
#define mHard_DI43               118            //DI输入点                               DI
#define mHard_DI44               119            //DI输入点                               DI
#define mHard_DI45               120            //DI输入点                               DI
#define mHard_DI46               121            //DI输入点                               DI
#define mHard_DI47               122            //DI输入点                               DI
#define mHard_DI48               123            //DI输入点                               DI
#define mHard_DI49               124            //DI输入点                               DI
#define mHard_DI50               125            //DI输入点                               DI
#define mHard_DI51               126            //DI输入点                               DI
#define mHard_DI52               127            //DI输入点                               DI
#define mHard_DI53               128            //DI输入点                               DI
#define mHard_DI54               129            //DI输入点                               DI
#define mHard_DI55               130            //DI输入点                               DI
#define mHard_DI56               131            //DI输入点                               DI
#define mHard_DI57               132            //DI输入点                               DI
#define mHard_DI58               133            //DI输入点                               DI
#define mHard_DI59               134            //DI输入点                               DI
#define mHard_DI60               135            //DI输入点                               DI
#define mHard_DI61               136            //DI输入点                               DI
#define mHard_DI62               137            //DI输入点                               DI
#define mHard_DI63               138            //DI输入点                               DI
#define mHard_DI64               139            //DI输入点                               DI
#define mHard_DO01               140            //DO输出点，电路相关，禁止更改对应资源                 DO
#define mHard_DO02               141            //DO输出点                               DO
#define mHard_DO03               142            //DO输出点                               DO
#define mHard_DO04               143            //DO输出点                               DO
#define mHard_DO05               144            //DO输出点                               DO
#define mHard_DO06               145            //DO输出点                               DO
#define mHard_DO07               146            //DO输出点                               DO
#define mHard_DO08               147            //DO输出点                               DO
#define mHard_DO09               148            //DO输出点                               DO
#define mHard_DO10               149            //DO输出点                               DO
#define mHard_DO11               150            //DO输出点                               DO
#define mHard_DO12               151            //DO输出点                               DO
#define mHard_DO13               152            //DO输出点                               DO
#define mHard_DO14               153            //DO输出点                               DO
#define mHard_DO15               154            //DO输出点                               DO
#define mHard_DO16               155            //DO输出点                               DO
#define mHard_DO17               156            //DO输出点                               DO
#define mHard_DO18               157            //DO输出点                               DO
#define mHard_DO19               158            //DO输出点                               DO
#define mHard_DO20               159            //DO输出点                               DO
#define mHard_DO21               160            //DO输出点                               DO
#define mHard_DO22               161            //DO输出点                               DO
#define mHard_DO23               162            //DO输出点                               DO
#define mHard_DO24               163            //DO输出点                               DO
#define mHard_DO25               164            //DO输出点                               DO
#define mHard_DO26               165            //DO输出点                               DO
#define mHard_DO27               166            //DO输出点                               DO
#define mHard_DO28               167            //DO输出点                               DO
#define mHard_DO29               168            //DO输出点                               DO
#define mHard_DO30               169            //DO输出点                               DO
#define mHard_DO31               170            //DO输出点                               DO
#define mHard_DO32               171            //DO输出点                               DO
#define mHard_DO33               172            //DO输出点                               DO
#define mHard_DO34               173            //DO输出点                               DO
#define mHard_DO35               174            //DO输出点                               DO
#define mHard_DO36               175            //DO输出点                               DO
#define mHard_DO37               176            //DO输出点                               DO
#define mHard_DO38               177            //DO输出点                               DO
#define mHard_DO39               178            //DO输出点                               DO
#define mHard_DO40               179            //DO输出点                               DO
#define mHard_DO41               180            //DO输出点                               DO
#define mHard_DO42               181            //DO输出点                               DO
#define mHard_DO43               182            //DO输出点                               DO
#define mHard_DO44               183            //DO输出点                               DO
#define mHard_DO45               184            //DO输出点                               DO
#define mHard_DO46               185            //DO输出点                               DO
#define mHard_DO47               186            //DO输出点                               DO
#define mHard_DO48               187            //DO输出点                               DO
#define mHard_DO49               188            //DO输出点                               DO
#define mHard_DO50               189            //DO输出点                               DO
#define mHard_DO51               190            //DO输出点                               DO
#define mHard_DO52               191            //DO输出点                               DO
#define mHard_DO53               192            //DO输出点                               DO
#define mHard_DO54               193            //DO输出点                               DO
#define mHard_DO55               194            //DO输出点                               DO
#define mHard_DO56               195            //DO输出点                               DO
#define mHard_DO57               196            //DO输出点                               DO
#define mHard_DO58               197            //DO输出点                               DO
#define mHard_DO59               198            //DO输出点                               DO
#define mHard_DO60               199            //DO输出点                               DO
#define mHard_DO61               200            //DO输出点                               DO
#define mHard_DO62               201            //DO输出点                               DO
#define mHard_DO63               202            //DO输出点                               DO
#define mHard_DO64               203            //DO输出点                               DO
#define mHard_DO65               204            //继电器输出                               DO
#define mHard_DO66               205            //继电器输出                               DO
#define mHard_DO67               206            //继电器输出                               DO
#define mHard_DO68               207            //继电器输出                               DO
#define mHard_DO69               208            //继电器输出                               DO
#define mHard_DO70               209            //继电器输出                               DO
#define mHard_DO71               210            //继电器输出                               DO
#define mHard_DO72               211            //继电器输出                               DO
#define mHard_DO73               212            //继电器输出                               DO
#define mHard_DO74               213            //继电器输出                               DO
#define mHard_DO75               214            //继电器输出                               DO
#define mHard_DO76               215            //继电器输出                               DO
#define mHard_DO77               216            //继电器输出                               DO
#define mHard_DO78               217            //继电器输出                               DO
#define mHard_DO79               218            //继电器输出                               DO
#define mHard_DO80               219            //继电器输出                               DO
#define mHard_DO81               220            //继电器输出                               DO
#define mHard_DO82               221            //继电器输出                               DO
#define mHard_DO83               222            //继电器输出                               DO
#define mHard_DO84               223            //继电器输出                               DO
#define mHard_DO85               224            //继电器输出                               DO
#define mHard_DO86               225            //继电器输出                               DO
#define mHard_DO87               226            //继电器输出                               DO
#define mHard_DO88               227            //继电器输出                               DO
#define mHard_DO89               228            //继电器输出                               DO
#define mHard_DO90               229            //继电器输出                               DO
#define mHard_DO91               230            //继电器输出                               DO
#define mHard_DO92               231            //继电器输出                               DO
#define mHard_DO93               232            //继电器输出                               DO
#define mHard_DO94               233            //继电器输出                               DO
#define mHard_DO95               234            //继电器输出                               DO
#define mHard_DO96               235            //继电器输出                               DO
#define mHard_DA01               236            //DA输出                                U32
#define mHard_DA02               237            //DA输出                                U32
#define mHard_DA03               238            //DA输出                                U32
#define mHard_DA04               239            //DA输出                                U32
#define mHard_DA05               240            //DA输出                                U32
#define mHard_DA06               241            //DA输出                                U32
#define mHard_DA07               242            //DA输出                                U32
#define mHard_DA08               243            //DA输出                                U32
#define mHard_DA09               244            //DA输出                                U32
#define mHard_DA10               245            //DA输出                                U32
#define mHard_DA11               246            //DA输出                                U32
#define mHard_DA12               247            //DA输出                                U32
#define mHard_DA13               248            //DA输出                                U32
#define mHard_DA14               249            //DA输出                                U32
#define mHard_DA15               250            //DA输出                                U32
#define mHard_DA16               251            //DA输出                                U32
#define mHard_HAD01              252            //HAD输入                               U32
#define mHard_HAD02              253            //HAD输入                               U32
#define mHard_HAD03              254            //HAD输入                               U32
#define mHard_HAD04              255            //HAD输入                               U32
#define mHard_HAD05              256            //HAD输入                               U32
#define mHard_HAD06              257            //HAD输入                               U32
#define mHard_HAD07              258            //HAD输入                               U32
#define mHard_HAD08              259            //HAD输入                               U32
#define mHard_HAD09              260            //HAD输入,这里作为MAD1输入，接压力传感器             U32
#define mHard_HAD10              261            //HAD输入                               U32
#define mHard_HAD11              262            //HAD输入                               U32
#define mHard_HAD12              263            //HAD输入                               U32
#define mHard_HAD13              264            //HAD输入                               U32
#define mHard_HAD14              265            //HAD输入                               U32
#define mHard_HAD15              266            //HAD输入                               U32
#define mHard_HAD16              267            //HAD输入                               U32
#define mHard_LAD01              268            //LAD输入                               U32
#define mHard_LAD02              269            //LAD输入                               U32
#define mHard_LAD03              270            //LAD输入                               U32
#define mHard_LAD04              271            //LAD输入                               U32
#define mHard_LAD05              272            //LAD输入                               U32
#define mHard_LAD06              273            //LAD输入                               U32
#define mHard_LAD07              274            //LAD输入                               U32
#define mHard_LAD08              275            //LAD输入                               U32
#define mHard_LAD09              276            //LAD输入                               U32
#define mHard_LAD10              277            //LAD输入                               U32
#define mHard_LAD11              278            //LAD输入                               U32
#define mHard_LAD12              279            //LAD输入                               U32
#define mHard_LAD13              280            //LAD输入                               U32
#define mHard_LAD14              281            //LAD输入                               U32
#define mHard_LAD15              282            //LAD输入                               U32
#define mHard_LAD16              283            //LAD输入                               U32
#define mHard_CNT01              284            //计数输入                                U32
#define mHard_CNT02              285            //计数输入                                U32
#define mHard_CNT03              286            //计数输入                                U32
#define mHard_CNT04              287            //计数输入                                U32
#define mHard_CNT05              288            //计数输入                                U32
#define mHard_CNT06              289            //计数输入                                U32
#define mHard_CNT07              290            //计数输入                                U32
#define mHard_CNT08              291            //计数输入                                U32
#define mHard_SDDrv1Pres         292            //伺服驱动器1输出压力                          U32
#define mHard_SDDrv1Flow         293            //伺服驱动器1输出流量                          U32
#define mHard_SDDrv2Pres         294            //伺服驱动器2输出压力                          U32
#define mHard_SDDrv2Flow         295            //伺服驱动器2输出流量                          U32
#define mHard_SDDrv3Pres         296            //伺服驱动器3输出压力                          U32
#define mHard_SDDrv3Flow         297            //伺服驱动器3输出流量                          U32
#define mHard_SDDrv4Pres         298            //伺服驱动器4输出压力                          U32
#define mHard_SDDrv4Flow         299            //伺服驱动器4输出流量                          U32
#define mHard_300                300            //                                    U32
#define mHard_301                301            //                                    U32
#define mHard_302                302            //                                    U32
#define mHard_303                303            //                                    U32
#define mHard_304                304            //                                    U32
#define mHard_305                305            //                                    U32
#define mHard_306                306            //                                    U32
#define mHard_307                307            //                                    U32
#define mHard_308                308            //                                    U32
#define mHard_309                309            //                                    U32
#define mHard_310                310            //                                    U32
#define mHard_311                311            //                                    U32
#define mHard_312                312            //                                    U32
#define mHard_313                313            //                                    U32
#define mHard_314                314            //                                    U32
#define mHard_315                315            //                                    U32
#define mHard_316                316            //                                    U32
#define mHard_317                317            //                                    U32
#define mHard_318                318            //                                    U32
#define mHard_319                319            //                                    U32
#define mHard_320                320            //                                    U32
#define mHard_321                321            //                                    U32
#define mHard_322                322            //                                    U32
#define mHard_323                323            //                                    U32
#define mHard_324                324            //                                    U32
#define mHard_325                325            //                                    U32
#define mHard_326                326            //                                    U32
#define mHard_327                327            //                                    U32
#define mHard_328                328            //                                    U32
#define mHard_329                329            //                                    U32
#define mHard_330                330            //                                    U32
#define mHard_331                331            //                                    U32
#define mHard_E1DI01             332            //模块n输入点                              DI
#define mHard_E1DI02             333            //模块n输入点                              DI
#define mHard_E1DI03             334            //模块n输入点                              DI
#define mHard_E1DI04             335            //模块n输入点                              DI
#define mHard_E1DI05             336            //模块n输入点                              DI
#define mHard_E1DI06             337            //模块n输入点                              DI
#define mHard_E1DI07             338            //模块n输入点                              DI
#define mHard_E1DI08             339            //模块n输入点                              DI
#define mHard_E1DI09             340            //模块n输入点                              DI
#define mHard_E1DI10             341            //模块n输入点                              DI
#define mHard_E1DI11             342            //模块n输入点                              DI
#define mHard_E1DI12             343            //模块n输入点                              DI
#define mHard_E1DI13             344            //模块n输入点                              DI
#define mHard_E1DI14             345            //模块n输入点                              DI
#define mHard_E1DI15             346            //模块n输入点                              DI
#define mHard_E1DI16             347            //模块n输入点                              DI
#define mHard_E1DO01             348            //模块n输出点                              DO
#define mHard_E1DO02             349            //模块n输出点                              DO
#define mHard_E1DO03             350            //模块n输出点                              DO
#define mHard_E1DO04             351            //模块n输出点                              DO
#define mHard_E1DO05             352            //模块n输出点                              DO
#define mHard_E1DO06             353            //模块n输出点                              DO
#define mHard_E1DO07             354            //模块n输出点                              DO
#define mHard_E1DO08             355            //模块n输出点                              DO
#define mHard_E1DO09             356            //模块n输出点                              DO
#define mHard_E1DO10             357            //模块n输出点                              DO
#define mHard_E1DO11             358            //模块n输出点                              DO
#define mHard_E1DO12             359            //模块n输出点                              DO
#define mHard_E1DO13             360            //模块n输出点                              DO
#define mHard_E1DO14             361            //模块n输出点                              DO
#define mHard_E1DO15             362            //模块n输出点                              DO
#define mHard_E1DO16             363            //模块n输出点                              DO
#define mHard_E1DA01             364            //模块n DA输出                            U32
#define mHard_E1DA02             365            //模块n DA输出                            U32
#define mHard_E1DA03             366            //模块n DA输出                            U32
#define mHard_E1DA04             367            //模块n DA输出                            U32
#define mHard_E1DA05             368            //模块n DA输出                            U32
#define mHard_E1DA06             369            //模块n DA输出                            U32
#define mHard_E1DA07             370            //模块n DA输出                            U32
#define mHard_E1DA08             371            //模块n DA输出                            U32
#define mHard_E1HAD01            372            //模块n HAD输入                           U32
#define mHard_E1HAD02            373            //模块n HAD输入                           U32
#define mHard_E1HAD03            374            //模块n HAD输入                           U32
#define mHard_E1HAD04            375            //模块n HAD输入                           U32
#define mHard_E1HAD05            376            //模块n HAD输入                           U32
#define mHard_E1HAD06            377            //模块n HAD输入                           U32
#define mHard_E1HAD07            378            //模块n HAD输入                           U32
#define mHard_E1HAD08            379            //模块n HAD输入                           U32
#define mHard_E1LAD01            380            //模块n LAD输入                           U32
#define mHard_E1LAD02            381            //模块n LAD输入                           U32
#define mHard_E1LAD03            382            //模块n LAD输入                           U32
#define mHard_E1LAD04            383            //模块n LAD输入                           U32
#define mHard_E1LAD05            384            //模块n LAD输入                           U32
#define mHard_E1LAD06            385            //模块n LAD输入                           U32
#define mHard_E1LAD07            386            //模块n LAD输入                           U32
#define mHard_E1LAD08            387            //模块n LAD输入                           U32
#define mHard_E1LAD09            388            //模块n LAD输入                           U32
#define mHard_E1LAD10            389            //模块n LAD输入                           U32
#define mHard_E1LAD11            390            //模块n LAD输入                           U32
#define mHard_E1LAD12            391            //模块n LAD输入                           U32
#define mHard_E1LAD13            392            //模块n LAD输入                           U32
#define mHard_E1LAD14            393            //模块n LAD输入                           U32
#define mHard_E1LAD15            394            //模块n LAD输入                           U32
#define mHard_E1LAD16            395            //模块n LAD输入                           U32
#define mHard_E1CNT01            396            //模块n计数输入                             U32
#define mHard_E1CNT02            397            //模块n计数输入                             U32
#define mHard_E1CNT03            398            //模块n计数输入                             U32
#define mHard_E1CNT04            399            //模块n计数输入                             U32
#define mHard_E1CNT05            400            //模块n计数输入                             U32
#define mHard_E1CNT06            401            //模块n计数输入                             U32
#define mHard_E1CNT07            402            //模块n计数输入                             U32
#define mHard_E1CNT08            403            //模块n计数输入                             U32
#define mHard_404                404            //                                    U32
#define mHard_405                405            //                                    U32
#define mHard_406                406            //                                    U32
#define mHard_407                407            //                                    U32
#define mHard_408                408            //                                    U32
#define mHard_409                409            //                                    U32
#define mHard_410                410            //                                    U32
#define mHard_411                411            //                                    U32
#define mHard_E2DI01             412            //模块n输入点                              DI
#define mHard_E2DI02             413            //模块n输入点                              DI
#define mHard_E2DI03             414            //模块n输入点                              DI
#define mHard_E2DI04             415            //模块n输入点                              DI
#define mHard_E2DI05             416            //模块n输入点                              DI
#define mHard_E2DI06             417            //模块n输入点                              DI
#define mHard_E2DI07             418            //模块n输入点                              DI
#define mHard_E2DI08             419            //模块n输入点                              DI
#define mHard_E2DI09             420            //模块n输入点                              DI
#define mHard_E2DI10             421            //模块n输入点                              DI
#define mHard_E2DI11             422            //模块n输入点                              DI
#define mHard_E2DI12             423            //模块n输入点                              DI
#define mHard_E2DI13             424            //模块n输入点                              DI
#define mHard_E2DI14             425            //模块n输入点                              DI
#define mHard_E2DI15             426            //模块n输入点                              DI
#define mHard_E2DI16             427            //模块n输入点                              DI
#define mHard_E2DO01             428            //模块n输出点                              DO
#define mHard_E2DO02             429            //模块n输出点                              DO
#define mHard_E2DO03             430            //模块n输出点                              DO
#define mHard_E2DO04             431            //模块n输出点                              DO
#define mHard_E2DO05             432            //模块n输出点                              DO
#define mHard_E2DO06             433            //模块n输出点                              DO
#define mHard_E2DO07             434            //模块n输出点                              DO
#define mHard_E2DO08             435            //模块n输出点                              DO
#define mHard_E2DO09             436            //模块n输出点                              DO
#define mHard_E2DO10             437            //模块n输出点                              DO
#define mHard_E2DO11             438            //模块n输出点                              DO
#define mHard_E2DO12             439            //模块n输出点                              DO
#define mHard_E2DO13             440            //模块n输出点                              DO
#define mHard_E2DO14             441            //模块n输出点                              DO
#define mHard_E2DO15             442            //模块n输出点                              DO
#define mHard_E2DO16             443            //模块n输出点                              DO
#define mHard_E2DA01             444            //模块n DA输出                            U32
#define mHard_E2DA02             445            //模块n DA输出                            U32
#define mHard_E2DA03             446            //模块n DA输出                            U32
#define mHard_E2DA04             447            //模块n DA输出                            U32
#define mHard_E2DA05             448            //模块n DA输出                            U32
#define mHard_E2DA06             449            //模块n DA输出                            U32
#define mHard_E2DA07             450            //模块n DA输出                            U32
#define mHard_E2DA08             451            //模块n DA输出                            U32
#define mHard_E2HAD01            452            //模块n HAD输入                           U32
#define mHard_E2HAD02            453            //模块n HAD输入                           U32
#define mHard_E2HAD03            454            //模块n HAD输入                           U32
#define mHard_E2HAD04            455            //模块n HAD输入                           U32
#define mHard_E2HAD05            456            //模块n HAD输入                           U32
#define mHard_E2HAD06            457            //模块n HAD输入                           U32
#define mHard_E2HAD07            458            //模块n HAD输入                           U32
#define mHard_E2HAD08            459            //模块n HAD输入                           U32
#define mHard_E2LAD01            460            //模块n LAD输入                           U32
#define mHard_E2LAD02            461            //模块n LAD输入                           U32
#define mHard_E2LAD03            462            //模块n LAD输入                           U32
#define mHard_E2LAD04            463            //模块n LAD输入                           U32
#define mHard_E2LAD05            464            //模块n LAD输入                           U32
#define mHard_E2LAD06            465            //模块n LAD输入                           U32
#define mHard_E2LAD07            466            //模块n LAD输入                           U32
#define mHard_E2LAD08            467            //模块n LAD输入                           U32
#define mHard_E2LAD09            468            //模块n LAD输入                           U32
#define mHard_E2LAD10            469            //模块n LAD输入                           U32
#define mHard_E2LAD11            470            //模块n LAD输入                           U32
#define mHard_E2LAD12            471            //模块n LAD输入                           U32
#define mHard_E2LAD13            472            //模块n LAD输入                           U32
#define mHard_E2LAD14            473            //模块n LAD输入                           U32
#define mHard_E2LAD15            474            //模块n LAD输入                           U32
#define mHard_E2LAD16            475            //模块n LAD输入                           U32
#define mHard_E2CNT01            476            //模块n计数输入                             U32
#define mHard_E2CNT02            477            //模块n计数输入                             U32
#define mHard_E2CNT03            478            //模块n计数输入                             U32
#define mHard_E2CNT04            479            //模块n计数输入                             U32
#define mHard_E2CNT05            480            //模块n计数输入                             U32
#define mHard_E2CNT06            481            //模块n计数输入                             U32
#define mHard_E2CNT07            482            //模块n计数输入                             U32
#define mHard_E2CNT08            483            //模块n计数输入                             U32
#define mHard_484                484            //                                    U32
#define mHard_485                485            //                                    U32
#define mHard_486                486            //                                    U32
#define mHard_487                487            //                                    U32
#define mHard_488                488            //                                    U32
#define mHard_489                489            //                                    U32
#define mHard_490                490            //                                    U32
#define mHard_491                491            //                                    U32
#define mHard_E3DI01             492            //模块n输入点                              DI
#define mHard_E3DI02             493            //模块n输入点                              DI
#define mHard_E3DI03             494            //模块n输入点                              DI
#define mHard_E3DI04             495            //模块n输入点                              DI
#define mHard_E3DI05             496            //模块n输入点                              DI
#define mHard_E3DI06             497            //模块n输入点                              DI
#define mHard_E3DI07             498            //模块n输入点                              DI
#define mHard_E3DI08             499            //模块n输入点                              DI
#define mHard_E3DI09             500            //模块n输入点                              DI
#define mHard_E3DI10             501            //模块n输入点                              DI
#define mHard_E3DI11             502            //模块n输入点                              DI
#define mHard_E3DI12             503            //模块n输入点                              DI
#define mHard_E3DI13             504            //模块n输入点                              DI
#define mHard_E3DI14             505            //模块n输入点                              DI
#define mHard_E3DI15             506            //模块n输入点                              DI
#define mHard_E3DI16             507            //模块n输入点                              DI
#define mHard_E3DO01             508            //模块n输出点                              DO
#define mHard_E3DO02             509            //模块n输出点                              DO
#define mHard_E3DO03             510            //模块n输出点                              DO
#define mHard_E3DO04             511            //模块n输出点                              DO
#define mHard_E3DO05             512            //模块n输出点                              DO
#define mHard_E3DO06             513            //模块n输出点                              DO
#define mHard_E3DO07             514            //模块n输出点                              DO
#define mHard_E3DO08             515            //模块n输出点                              DO
#define mHard_E3DO09             516            //模块n输出点                              DO
#define mHard_E3DO10             517            //模块n输出点                              DO
#define mHard_E3DO11             518            //模块n输出点                              DO
#define mHard_E3DO12             519            //模块n输出点                              DO
#define mHard_E3DO13             520            //模块n输出点                              DO
#define mHard_E3DO14             521            //模块n输出点                              DO
#define mHard_E3DO15             522            //模块n输出点                              DO
#define mHard_E3DO16             523            //模块n输出点                              DO
#define mHard_E3DA01             524            //模块n DA输出                            U32
#define mHard_E3DA02             525            //模块n DA输出                            U32
#define mHard_E3DA03             526            //模块n DA输出                            U32
#define mHard_E3DA04             527            //模块n DA输出                            U32
#define mHard_E3DA05             528            //模块n DA输出                            U32
#define mHard_E3DA06             529            //模块n DA输出                            U32
#define mHard_E3DA07             530            //模块n DA输出                            U32
#define mHard_E3DA08             531            //模块n DA输出                            U32
#define mHard_E3HAD01            532            //模块n HAD输入                           U32
#define mHard_E3HAD02            533            //模块n HAD输入                           U32
#define mHard_E3HAD03            534            //模块n HAD输入                           U32
#define mHard_E3HAD04            535            //模块n HAD输入                           U32
#define mHard_E3HAD05            536            //模块n HAD输入                           U32
#define mHard_E3HAD06            537            //模块n HAD输入                           U32
#define mHard_E3HAD07            538            //模块n HAD输入                           U32
#define mHard_E3HAD08            539            //模块n HAD输入                           U32
#define mHard_E3LAD01            540            //模块n LAD输入                           U32
#define mHard_E3LAD02            541            //模块n LAD输入                           U32
#define mHard_E3LAD03            542            //模块n LAD输入                           U32
#define mHard_E3LAD04            543            //模块n LAD输入                           U32
#define mHard_E3LAD05            544            //模块n LAD输入                           U32
#define mHard_E3LAD06            545            //模块n LAD输入                           U32
#define mHard_E3LAD07            546            //模块n LAD输入                           U32
#define mHard_E3LAD08            547            //模块n LAD输入                           U32
#define mHard_E3LAD09            548            //模块n LAD输入                           U32
#define mHard_E3LAD10            549            //模块n LAD输入                           U32
#define mHard_E3LAD11            550            //模块n LAD输入                           U32
#define mHard_E3LAD12            551            //模块n LAD输入                           U32
#define mHard_E3LAD13            552            //模块n LAD输入                           U32
#define mHard_E3LAD14            553            //模块n LAD输入                           U32
#define mHard_E3LAD15            554            //模块n LAD输入                           U32
#define mHard_E3LAD16            555            //模块n LAD输入                           U32
#define mHard_E3CNT01            556            //模块n计数输入                             U32
#define mHard_E3CNT02            557            //模块n计数输入                             U32
#define mHard_E3CNT03            558            //模块n计数输入                             U32
#define mHard_E3CNT04            559            //模块n计数输入                             U32
#define mHard_E3CNT05            560            //模块n计数输入                             U32
#define mHard_E3CNT06            561            //模块n计数输入                             U32
#define mHard_E3CNT07            562            //模块n计数输入                             U32
#define mHard_E3CNT08            563            //模块n计数输入                             U32
#define mHard_564                564            //                                    U32
#define mHard_565                565            //                                    U32
#define mHard_566                566            //                                    U32
#define mHard_567                567            //                                    U32
#define mHard_568                568            //                                    U32
#define mHard_569                569            //                                    U32
#define mHard_570                570            //                                    U32
#define mHard_571                571            //                                    U32
#define mHard_E4DI01             572            //模块n输入点                              DI
#define mHard_E4DI02             573            //模块n输入点                              DI
#define mHard_E4DI03             574            //模块n输入点                              DI
#define mHard_E4DI04             575            //模块n输入点                              DI
#define mHard_E4DI05             576            //模块n输入点                              DI
#define mHard_E4DI06             577            //模块n输入点                              DI
#define mHard_E4DI07             578            //模块n输入点                              DI
#define mHard_E4DI08             579            //模块n输入点                              DI
#define mHard_E4DI09             580            //模块n输入点                              DI
#define mHard_E4DI10             581            //模块n输入点                              DI
#define mHard_E4DI11             582            //模块n输入点                              DI
#define mHard_E4DI12             583            //模块n输入点                              DI
#define mHard_E4DI13             584            //模块n输入点                              DI
#define mHard_E4DI14             585            //模块n输入点                              DI
#define mHard_E4DI15             586            //模块n输入点                              DI
#define mHard_E4DI16             587            //模块n输入点                              DI
#define mHard_E4DO01             588            //模块n输出点                              DO
#define mHard_E4DO02             589            //模块n输出点                              DO
#define mHard_E4DO03             590            //模块n输出点                              DO
#define mHard_E4DO04             591            //模块n输出点                              DO
#define mHard_E4DO05             592            //模块n输出点                              DO
#define mHard_E4DO06             593            //模块n输出点                              DO
#define mHard_E4DO07             594            //模块n输出点                              DO
#define mHard_E4DO08             595            //模块n输出点                              DO
#define mHard_E4DO09             596            //模块n输出点                              DO
#define mHard_E4DO10             597            //模块n输出点                              DO
#define mHard_E4DO11             598            //模块n输出点                              DO
#define mHard_E4DO12             599            //模块n输出点                              DO
#define mHard_E4DO13             600            //模块n输出点                              DO
#define mHard_E4DO14             601            //模块n输出点                              DO
#define mHard_E4DO15             602            //模块n输出点                              DO
#define mHard_E4DO16             603            //模块n输出点                              DO
#define mHard_E4DA01             604            //模块n DA输出                            U32
#define mHard_E4DA02             605            //模块n DA输出                            U32
#define mHard_E4DA03             606            //模块n DA输出                            U32
#define mHard_E4DA04             607            //模块n DA输出                            U32
#define mHard_E4DA05             608            //模块n DA输出                            U32
#define mHard_E4DA06             609            //模块n DA输出                            U32
#define mHard_E4DA07             610            //模块n DA输出                            U32
#define mHard_E4DA08             611            //模块n DA输出                            U32
#define mHard_E4HAD01            612            //模块n HAD输入                           U32
#define mHard_E4HAD02            613            //模块n HAD输入                           U32
#define mHard_E4HAD03            614            //模块n HAD输入                           U32
#define mHard_E4HAD04            615            //模块n HAD输入                           U32
#define mHard_E4HAD05            616            //模块n HAD输入                           U32
#define mHard_E4HAD06            617            //模块n HAD输入                           U32
#define mHard_E4HAD07            618            //模块n HAD输入                           U32
#define mHard_E4HAD08            619            //模块n HAD输入                           U32
#define mHard_E4LAD01            620            //模块n LAD输入                           U32
#define mHard_E4LAD02            621            //模块n LAD输入                           U32
#define mHard_E4LAD03            622            //模块n LAD输入                           U32
#define mHard_E4LAD04            623            //模块n LAD输入                           U32
#define mHard_E4LAD05            624            //模块n LAD输入                           U32
#define mHard_E4LAD06            625            //模块n LAD输入                           U32
#define mHard_E4LAD07            626            //模块n LAD输入                           U32
#define mHard_E4LAD08            627            //模块n LAD输入                           U32
#define mHard_E4LAD09            628            //模块n LAD输入                           U32
#define mHard_E4LAD10            629            //模块n LAD输入                           U32
#define mHard_E4LAD11            630            //模块n LAD输入                           U32
#define mHard_E4LAD12            631            //模块n LAD输入                           U32
#define mHard_E4LAD13            632            //模块n LAD输入                           U32
#define mHard_E4LAD14            633            //模块n LAD输入                           U32
#define mHard_E4LAD15            634            //模块n LAD输入                           U32
#define mHard_E4LAD16            635            //模块n LAD输入                           U32
#define mHard_E4CNT01            636            //模块n计数输入                             U32
#define mHard_E4CNT02            637            //模块n计数输入                             U32
#define mHard_E4CNT03            638            //模块n计数输入                             U32
#define mHard_E4CNT04            639            //模块n计数输入                             U32
#define mHard_E4CNT05            640            //模块n计数输入                             U32
#define mHard_E4CNT06            641            //模块n计数输入                             U32
#define mHard_E4CNT07            642            //模块n计数输入                             U32
#define mHard_E4CNT08            643            //模块n计数输入                             U32
#define mHard_644                644            //                                    U32
#define mHard_645                645            //                                    U32
#define mHard_646                646            //                                    U32
#define mHard_647                647            //                                    U32
#define mHard_648                648            //                                    U32
#define mHard_649                649            //                                    U32
#define mHard_650                650            //                                    U32
#define mHard_651                651            //                                    U32
#define mHard_E5DI01             652            //模块n输入点                              DI
#define mHard_E5DI02             653            //模块n输入点                              DI
#define mHard_E5DI03             654            //模块n输入点                              DI
#define mHard_E5DI04             655            //模块n输入点                              DI
#define mHard_E5DI05             656            //模块n输入点                              DI
#define mHard_E5DI06             657            //模块n输入点                              DI
#define mHard_E5DI07             658            //模块n输入点                              DI
#define mHard_E5DI08             659            //模块n输入点                              DI
#define mHard_E5DI09             660            //模块n输入点                              DI
#define mHard_E5DI10             661            //模块n输入点                              DI
#define mHard_E5DI11             662            //模块n输入点                              DI
#define mHard_E5DI12             663            //模块n输入点                              DI
#define mHard_E5DI13             664            //模块n输入点                              DI
#define mHard_E5DI14             665            //模块n输入点                              DI
#define mHard_E5DI15             666            //模块n输入点                              DI
#define mHard_E5DI16             667            //模块n输入点                              DI
#define mHard_E5DO01             668            //模块n输出点                              DO
#define mHard_E5DO02             669            //模块n输出点                              DO
#define mHard_E5DO03             670            //模块n输出点                              DO
#define mHard_E5DO04             671            //模块n输出点                              DO
#define mHard_E5DO05             672            //模块n输出点                              DO
#define mHard_E5DO06             673            //模块n输出点                              DO
#define mHard_E5DO07             674            //模块n输出点                              DO
#define mHard_E5DO08             675            //模块n输出点                              DO
#define mHard_E5DO09             676            //模块n输出点                              DO
#define mHard_E5DO10             677            //模块n输出点                              DO
#define mHard_E5DO11             678            //模块n输出点                              DO
#define mHard_E5DO12             679            //模块n输出点                              DO
#define mHard_E5DO13             680            //模块n输出点                              DO
#define mHard_E5DO14             681            //模块n输出点                              DO
#define mHard_E5DO15             682            //模块n输出点                              DO
#define mHard_E5DO16             683            //模块n输出点                              DO
#define mHard_E5DA01             684            //模块n DA输出                            U32
#define mHard_E5DA02             685            //模块n DA输出                            U32
#define mHard_E5DA03             686            //模块n DA输出                            U32
#define mHard_E5DA04             687            //模块n DA输出                            U32
#define mHard_E5DA05             688            //模块n DA输出                            U32
#define mHard_E5DA06             689            //模块n DA输出                            U32
#define mHard_E5DA07             690            //模块n DA输出                            U32
#define mHard_E5DA08             691            //模块n DA输出                            U32
#define mHard_E5HAD01            692            //模块n HAD输入                           U32
#define mHard_E5HAD02            693            //模块n HAD输入                           U32
#define mHard_E5HAD03            694            //模块n HAD输入                           U32
#define mHard_E5HAD04            695            //模块n HAD输入                           U32
#define mHard_E5HAD05            696            //模块n HAD输入                           U32
#define mHard_E5HAD06            697            //模块n HAD输入                           U32
#define mHard_E5HAD07            698            //模块n HAD输入                           U32
#define mHard_E5HAD08            699            //模块n HAD输入                           U32
#define mHard_E5LAD01            700            //模块n LAD输入                           U32
#define mHard_E5LAD02            701            //模块n LAD输入                           U32
#define mHard_E5LAD03            702            //模块n LAD输入                           U32
#define mHard_E5LAD04            703            //模块n LAD输入                           U32
#define mHard_E5LAD05            704            //模块n LAD输入                           U32
#define mHard_E5LAD06            705            //模块n LAD输入                           U32
#define mHard_E5LAD07            706            //模块n LAD输入                           U32
#define mHard_E5LAD08            707            //模块n LAD输入                           U32
#define mHard_E5LAD09            708            //模块n LAD输入                           U32
#define mHard_E5LAD10            709            //模块n LAD输入                           U32
#define mHard_E5LAD11            710            //模块n LAD输入                           U32
#define mHard_E5LAD12            711            //模块n LAD输入                           U32
#define mHard_E5LAD13            712            //模块n LAD输入                           U32
#define mHard_E5LAD14            713            //模块n LAD输入                           U32
#define mHard_E5LAD15            714            //模块n LAD输入                           U32
#define mHard_E5LAD16            715            //模块n LAD输入                           U32
#define mHard_E5CNT01            716            //模块n计数输入                             U32
#define mHard_E5CNT02            717            //模块n计数输入                             U32
#define mHard_E5CNT03            718            //模块n计数输入                             U32
#define mHard_E5CNT04            719            //模块n计数输入                             U32
#define mHard_E5CNT05            720            //模块n计数输入                             U32
#define mHard_E5CNT06            721            //模块n计数输入                             U32
#define mHard_E5CNT07            722            //模块n计数输入                             U32
#define mHard_E5CNT08            723            //模块n计数输入                             U32
#define mHard_724                724            //                                    U32
#define mHard_725                725            //                                    U32
#define mHard_726                726            //                                    U32
#define mHard_727                727            //                                    U32
#define mHard_728                728            //                                    U32
#define mHard_729                729            //                                    U32
#define mHard_730                730            //                                    U32
#define mHard_731                731            //                                    U32
#define mHard_E6DI01             732            //模块n输入点                              DI
#define mHard_E6DI02             733            //模块n输入点                              DI
#define mHard_E6DI03             734            //模块n输入点                              DI
#define mHard_E6DI04             735            //模块n输入点                              DI
#define mHard_E6DI05             736            //模块n输入点                              DI
#define mHard_E6DI06             737            //模块n输入点                              DI
#define mHard_E6DI07             738            //模块n输入点                              DI
#define mHard_E6DI08             739            //模块n输入点                              DI
#define mHard_E6DI09             740            //模块n输入点                              DI
#define mHard_E6DI10             741            //模块n输入点                              DI
#define mHard_E6DI11             742            //模块n输入点                              DI
#define mHard_E6DI12             743            //模块n输入点                              DI
#define mHard_E6DI13             744            //模块n输入点                              DI
#define mHard_E6DI14             745            //模块n输入点                              DI
#define mHard_E6DI15             746            //模块n输入点                              DI
#define mHard_E6DI16             747            //模块n输入点                              DI
#define mHard_E6DO01             748            //模块n输出点                              DO
#define mHard_E6DO02             749            //模块n输出点                              DO
#define mHard_E6DO03             750            //模块n输出点                              DO
#define mHard_E6DO04             751            //模块n输出点                              DO
#define mHard_E6DO05             752            //模块n输出点                              DO
#define mHard_E6DO06             753            //模块n输出点                              DO
#define mHard_E6DO07             754            //模块n输出点                              DO
#define mHard_E6DO08             755            //模块n输出点                              DO
#define mHard_E6DO09             756            //模块n输出点                              DO
#define mHard_E6DO10             757            //模块n输出点                              DO
#define mHard_E6DO11             758            //模块n输出点                              DO
#define mHard_E6DO12             759            //模块n输出点                              DO
#define mHard_E6DO13             760            //模块n输出点                              DO
#define mHard_E6DO14             761            //模块n输出点                              DO
#define mHard_E6DO15             762            //模块n输出点                              DO
#define mHard_E6DO16             763            //模块n输出点                              DO
#define mHard_E6DA01             764            //模块n DA输出                            U32
#define mHard_E6DA02             765            //模块n DA输出                            U32
#define mHard_E6DA03             766            //模块n DA输出                            U32
#define mHard_E6DA04             767            //模块n DA输出                            U32
#define mHard_E6DA05             768            //模块n DA输出                            U32
#define mHard_E6DA06             769            //模块n DA输出                            U32
#define mHard_E6DA07             770            //模块n DA输出                            U32
#define mHard_E6DA08             771            //模块n DA输出                            U32
#define mHard_E6HAD01            772            //模块n HAD输入                           U32
#define mHard_E6HAD02            773            //模块n HAD输入                           U32
#define mHard_E6HAD03            774            //模块n HAD输入                           U32
#define mHard_E6HAD04            775            //模块n HAD输入                           U32
#define mHard_E6HAD05            776            //模块n HAD输入                           U32
#define mHard_E6HAD06            777            //模块n HAD输入                           U32
#define mHard_E6HAD07            778            //模块n HAD输入                           U32
#define mHard_E6HAD08            779            //模块n HAD输入                           U32
#define mHard_E6LAD01            780            //模块n LAD输入                           U32
#define mHard_E6LAD02            781            //模块n LAD输入                           U32
#define mHard_E6LAD03            782            //模块n LAD输入                           U32
#define mHard_E6LAD04            783            //模块n LAD输入                           U32
#define mHard_E6LAD05            784            //模块n LAD输入                           U32
#define mHard_E6LAD06            785            //模块n LAD输入                           U32
#define mHard_E6LAD07            786            //模块n LAD输入                           U32
#define mHard_E6LAD08            787            //模块n LAD输入                           U32
#define mHard_E6LAD09            788            //模块n LAD输入                           U32
#define mHard_E6LAD10            789            //模块n LAD输入                           U32
#define mHard_E6LAD11            790            //模块n LAD输入                           U32
#define mHard_E6LAD12            791            //模块n LAD输入                           U32
#define mHard_E6LAD13            792            //模块n LAD输入                           U32
#define mHard_E6LAD14            793            //模块n LAD输入                           U32
#define mHard_E6LAD15            794            //模块n LAD输入                           U32
#define mHard_E6LAD16            795            //模块n LAD输入                           U32
#define mHard_E6CNT01            796            //模块n计数输入                             U32
#define mHard_E6CNT02            797            //模块n计数输入                             U32
#define mHard_E6CNT03            798            //模块n计数输入                             U32
#define mHard_E6CNT04            799            //模块n计数输入                             U32
#define mHard_E6CNT05            800            //模块n计数输入                             U32
#define mHard_E6CNT06            801            //模块n计数输入                             U32
#define mHard_E6CNT07            802            //模块n计数输入                             U32
#define mHard_E6CNT08            803            //模块n计数输入                             U32
#define mHard_804                804            //                                    U32
#define mHard_805                805            //                                    U32
#define mHard_806                806            //                                    U32
#define mHard_807                807            //                                    U32
#define mHard_808                808            //                                    U32
#define mHard_809                809            //                                    U32
#define mHard_810                810            //                                    U32
#define mHard_811                811            //                                    U32
#define mHard_812                812            //                                    U32
#define mHard_813                813            //                                    U32
#define mHard_814                814            //                                    U32
#define mHard_815                815            //                                    U32
#define mHard_816                816            //                                    U32
#define mHard_817                817            //                                    U32
#define mHard_818                818            //                                    U32
#define mHard_819                819            //                                    U32
#define mHard_820                820            //                                    U32
#define mHard_821                821            //                                    U32
#define mHard_822                822            //                                    U32
#define mHard_823                823            //                                    U32
#define mHard_824                824            //                                    U32
#define mHard_825                825            //                                    U32
#define mHard_826                826            //                                    U32
#define mHard_827                827            //                                    U32
#define mHard_828                828            //                                    U32
#define mHard_829                829            //                                    U32
#define mHard_830                830            //                                    U32
#define mHard_831                831            //                                    U32
#define mHard_832                832            //                                    U32
#define mHard_833                833            //                                    U32
#define mHard_834                834            //                                    U32
#define mHard_835                835            //                                    U32
#define mHard_836                836            //                                    U32
#define mHard_837                837            //                                    U32
#define mHard_838                838            //                                    U32
#define mHard_839                839            //                                    U32
#define mHard_840                840            //                                    U32
#define mHard_841                841            //                                    U32
#define mHard_842                842            //                                    U32
#define mHard_843                843            //                                    U32
#define mHard_844                844            //                                    U32
#define mHard_845                845            //                                    U32
#define mHard_846                846            //                                    U32
#define mHard_847                847            //                                    U32
#define mHard_848                848            //                                    U32
#define mHard_849                849            //                                    U32
#define mHard_850                850            //                                    U32
#define mHard_851                851            //                                    U32
#define mHard_852                852            //                                    U32
#define mHard_853                853            //                                    U32
#define mHard_854                854            //                                    U32
#define mHard_855                855            //                                    U32
#define mHard_856                856            //                                    U32
#define mHard_857                857            //                                    U32
#define mHard_858                858            //                                    U32
#define mHard_859                859            //                                    U32
#define mHard_860                860            //                                    U32
#define mHard_861                861            //                                    U32
#define mHard_862                862            //                                    U32
#define mHard_863                863            //                                    U32
#define mHard_864                864            //                                    U32
#define mHard_865                865            //                                    U32
#define mHard_866                866            //                                    U32
#define mHard_867                867            //                                    U32
#define mHard_868                868            //                                    U32
#define mHard_869                869            //                                    U32
#define mHard_870                870            //                                    U32
#define mHard_871                871            //                                    U32
#define mHard_872                872            //                                    U32
#define mHard_873                873            //                                    U32
#define mHard_874                874            //                                    U32
#define mHard_875                875            //                                    U32
#define mHard_876                876            //                                    U32
#define mHard_877                877            //                                    U32
#define mHard_878                878            //                                    U32
#define mHard_879                879            //                                    U32
#define mHard_880                880            //                                    U32
#define mHard_881                881            //                                    U32
#define mHard_882                882            //                                    U32
#define mHard_883                883            //                                    U32
#define mHard_884                884            //                                    U32
#define mHard_885                885            //                                    U32
#define mHard_886                886            //                                    U32
#define mHard_887                887            //                                    U32
#define mHard_888                888            //                                    U32
#define mHard_889                889            //                                    U32
#define mHard_890                890            //                                    U32
#define mHard_891                891            //                                    U32
#define mHard_892                892            //                                    U32
#define mHard_893                893            //                                    U32
#define mHard_894                894            //                                    U32
#define mHard_895                895            //                                    U32
#define mHard_896                896            //                                    U32
#define mHard_897                897            //                                    U32
#define mHard_898                898            //                                    U32
#define mHard_899                899            //                                    U32
#define mHard_900                900            //                                    U32
#define mHard_901                901            //                                    U32
#define mHard_902                902            //                                    U32
#define mHard_903                903            //                                    U32
#define mHard_904                904            //                                    U32
#define mHard_905                905            //                                    U32
#define mHard_906                906            //                                    U32
#define mHard_907                907            //                                    U32
#define mHard_908                908            //                                    U32
#define mHard_909                909            //                                    U32
#define mHard_910                910            //                                    U32
#define mHard_911                911            //                                    U32
#define mHard_912                912            //                                    U32
#define mHard_913                913            //                                    U32
#define mHard_914                914            //                                    U32
#define mHard_915                915            //                                    U32
#define mHard_916                916            //                                    U32
#define mHard_917                917            //                                    U32
#define mHard_918                918            //                                    U32
#define mHard_919                919            //                                    U32
#define mHard_920                920            //                                    U32
#define mHard_921                921            //                                    U32
#define mHard_922                922            //                                    U32
#define mHard_923                923            //                                    U32
#define mHard_924                924            //                                    U32
#define mHard_925                925            //                                    U32
#define mHard_926                926            //                                    U32
#define mHard_927                927            //                                    U32
#define mHard_928                928            //                                    U32
#define mHard_929                929            //                                    U32
#define mHard_930                930            //                                    U32
#define mHard_931                931            //                                    U32
#define mHard_932                932            //                                    U32
#define mHard_933                933            //                                    U32
#define mHard_934                934            //                                    U32
#define mHard_935                935            //                                    U32
#define mHard_936                936            //                                    U32
#define mHard_937                937            //                                    U32
#define mHard_938                938            //                                    U32
#define mHard_939                939            //                                    U32
#define mHard_940                940            //                                    U32
#define mHard_941                941            //                                    U32
#define mHard_942                942            //                                    U32
#define mHard_943                943            //                                    U32
#define mHard_944                944            //                                    U32
#define mHard_945                945            //                                    U32
#define mHard_946                946            //                                    U32
#define mHard_947                947            //                                    U32
#define mHard_948                948            //                                    U32
#define mHard_949                949            //                                    U32
#define mHard_950                950            //                                    U32
#define mHard_951                951            //                                    U32
#define mHard_952                952            //                                    U32
#define mHard_953                953            //                                    U32
#define mHard_954                954            //                                    U32
#define mHard_955                955            //                                    U32
#define mHard_956                956            //                                    U32
#define mHard_957                957            //                                    U32
#define mHard_958                958            //                                    U32
#define mHard_959                959            //                                    U32
#define mHard_960                960            //                                    U32
#define mHard_961                961            //                                    U32
#define mHard_962                962            //                                    U32
#define mHard_963                963            //                                    U32
#define mHard_964                964            //                                    U32
#define mHard_965                965            //                                    U32
#define mHard_966                966            //                                    U32
#define mHard_967                967            //                                    U32
#define mHard_968                968            //                                    U32
#define mHard_969                969            //                                    U32
#define mHard_970                970            //                                    U32
#define mHard_971                971            //                                    U32
#define mHard_972                972            //                                    U32
#define mHard_973                973            //                                    U32
#define mHard_974                974            //                                    U32
#define mHard_975                975            //                                    U32
#define mHard_976                976            //                                    U32
#define mHard_977                977            //                                    U32
#define mHard_978                978            //                                    U32
#define mHard_979                979            //                                    U32
#define mHard_980                980            //                                    U32
#define mHard_981                981            //                                    U32
#define mHard_982                982            //                                    U32
#define mHard_983                983            //                                    U32
#define mHard_984                984            //                                    U32
#define mHard_985                985            //                                    U32
#define mHard_986                986            //                                    U32
#define mHard_987                987            //                                    U32
#define mHard_988                988            //                                    U32
#define mHard_989                989            //                                    U32
#define mHard_990                990            //                                    U32
#define mHard_991                991            //                                    U32
#define mHard_992                992            //                                    U32
#define mHard_993                993            //                                    U32
#define mHard_994                994            //                                    U32
#define mHard_995                995            //                                    U32
#define mHard_996                996            //                                    U32
#define mHard_997                997            //                                    U32
#define mHard_998                998            //                                    U32
#define mHard_999                999            //                                    U32
#define mHard_1000               1000           //                                    U32
#define mHard_1001               1001           //                                    U32
#define mHard_1002               1002           //                                    U32
#define mHard_1003               1003           //                                    U32
#define mHard_1004               1004           //                                    U32
#define mHard_1005               1005           //                                    U32
#define mHard_1006               1006           //                                    U32
#define mHard_1007               1007           //                                    U32
#define mHard_1008               1008           //                                    U32
#define mHard_1009               1009           //                                    U32
#define mHard_1010               1010           //                                    U32
#define mHard_1011               1011           //                                    U32
#define mHard_1012               1012           //                                    U32
#define mHard_1013               1013           //                                    U32
#define mHard_1014               1014           //                                    U32
#define mHard_1015               1015           //                                    U32
#define mHard_1016               1016           //                                    U32
#define mHard_1017               1017           //                                    U32
#define mHard_1018               1018           //                                    U32
#define mHard_1019               1019           //                                    U32
#define mHard_1020               1020           //                                    U32
#define mHard_1021               1021           //                                    U32
#define mHard_1022               1022           //                                    U32
#define mHard_1023               1023           //                                    U32

//硬件接口引用宏定义
#define HardConf_HardConfSum     HardConf[0]    //辅助用，下述硬件配置累加和                       辅助
#define HardConf_HardConfLinkCode HardConf[1]   //辅助用，硬件配置互连代码，简单参数增删避免更改，否则用户资料会因程序升级而失效 辅助
#define HardConf_HardConfVer     HardConf[2]    //辅助用，硬件配置版本号                         辅助
#define HardConf_HardConfID      HardConf[3]    //辅助用，硬件配置ID，用于售后维护                   辅助
#define HardConf_PlatLinkCode    HardConf[4]    //辅助用，硬件平台互连代码(0x11-F5 0x22-F3 0x33-F1s 0x55-F3s 0x66-h3 0xE1-H1 0xE3-H3 0xE5-H5) 辅助
#define HardConf_PlatTypeC0      HardConf[5]    //辅助用，硬件平台型号字符0                       辅助
#define HardConf_PlatTypeC1      HardConf[6]    //辅助用，硬件平台型号字符1                       辅助
#define HardConf_PlatTypeC2      HardConf[7]    //辅助用，硬件平台型号字符2                       辅助
#define HardConf_PlatTypeC3      HardConf[8]    //辅助用，硬件平台型号字符3                       辅助
#define HardConf_PlatTypeC4      HardConf[9]    //辅助用，硬件平台型号字符4                       辅助
#define HardConf_PlatTypeC5      HardConf[10]   //辅助用，硬件平台型号字符5                       辅助
#define HardConf_PlatTypeC6      HardConf[11]   //辅助用，硬件平台型号字符6                       辅助
#define HardConf_PlatTypeC7      HardConf[12]   //辅助用，硬件平台型号字符7                       辅助
#define HardConf_CMPlatTypeSN    HardConf[13]   //辅助用，主机硬件平台型号序号(0～5,其中F3=1、P01=2、F1s=3、F3s=5、h3=6、H1=7、H3=8、H5=9) 辅助
#define HardConf_DINum           HardConf[14]   //辅助用，DI点数                            辅助
#define HardConf_DONum           HardConf[15]   //辅助用，DO点数                            辅助
#define HardConf_RLYNum          HardConf[16]   //辅助用，继电器路数(模块中计入DO)                  辅助
#define HardConf_DANum           HardConf[17]   //辅助用，DA路数                            辅助
#define HardConf_HADNum          HardConf[18]   //辅助用，HAD路数                           辅助
#define HardConf_LADNum          HardConf[19]   //辅助用，LAD路数(一般选择8通道或11通道)             辅助
#define HardConf_CNTNum          HardConf[20]   //辅助用，CNT路数(暂未使用)                     辅助
#define HardConf_MADNum          HardConf[21]   //辅助用，MAD路数                           辅助
#define HardConf_E1Use           HardConf[22]   //辅助用，模块1是否使用                         辅助
#define HardConf_E1DINum         HardConf[23]   //辅助用，模块1的DI点数，必须配置DI/LAD/HAD/CNT中至少一项，否则程序有BUG(总线断开不报警) 辅助
#define HardConf_E1DONum         HardConf[24]   //辅助用，模块1的DO点数                        辅助
#define HardConf_E1DANum         HardConf[25]   //辅助用，模块1的DA路数                        辅助
#define HardConf_E1HADNum        HardConf[26]   //辅助用，模块1的HAD路数                       辅助
#define HardConf_E1LADNum        HardConf[27]   //辅助用，模块1的LAD路数                       辅助
#define HardConf_E1CNTNum        HardConf[28]   //辅助用，模块1的CNT路数                       辅助
#define HardConf_HardConf29      HardConf[29]   //                                    辅助
#define HardConf_HardConf30      HardConf[30]   //                                    辅助
#define HardConf_E2Use           HardConf[31]   //辅助用，模块2是否使用                         辅助
#define HardConf_E2DINum         HardConf[32]   //辅助用，模块2的DI点数                        辅助
#define HardConf_E2DONum         HardConf[33]   //辅助用，模块2的DO点数                        辅助
#define HardConf_E2DANum         HardConf[34]   //辅助用，模块2的DA路数                        辅助
#define HardConf_E2HADNum        HardConf[35]   //辅助用，模块2的HAD路数                       辅助
#define HardConf_E2LADNum        HardConf[36]   //辅助用，模块2的LAD路数                       辅助
#define HardConf_E2CNTNum        HardConf[37]   //辅助用，模块2的CNT路数                       辅助
#define HardConf_HardConf38      HardConf[38]   //                                    辅助
#define HardConf_HardConf39      HardConf[39]   //                                    辅助
#define HardConf_E3Use           HardConf[40]   //辅助用，模块3是否使用                         辅助
#define HardConf_E3DINum         HardConf[41]   //辅助用，模块3的DI点数                        辅助
#define HardConf_E3DONum         HardConf[42]   //辅助用，模块3的DO点数                        辅助
#define HardConf_E3DANum         HardConf[43]   //辅助用，模块3的DA路数                        辅助
#define HardConf_E3HADNum        HardConf[44]   //辅助用，模块3的HAD路数                       辅助
#define HardConf_E3LADNum        HardConf[45]   //辅助用，模块3的LAD路数                       辅助
#define HardConf_E3CNTNum        HardConf[46]   //辅助用，模块3的CNT路数                       辅助
#define HardConf_HardConf47      HardConf[47]   //                                    辅助
#define HardConf_HardConf48      HardConf[48]   //                                    辅助
#define HardConf_E4Use           HardConf[49]   //辅助用，模块4是否使用                         辅助
#define HardConf_E4DINum         HardConf[50]   //辅助用，模块4的DI点数                        辅助
#define HardConf_E4DONum         HardConf[51]   //辅助用，模块4的DO点数                        辅助
#define HardConf_E4DANum         HardConf[52]   //辅助用，模块4的DA路数                        辅助
#define HardConf_E4HADNum        HardConf[53]   //辅助用，模块4的HAD路数                       辅助
#define HardConf_E4LADNum        HardConf[54]   //辅助用，模块4的LAD路数                       辅助
#define HardConf_E4CNTNum        HardConf[55]   //辅助用，模块4的CNT路数                       辅助
#define HardConf_HardConf56      HardConf[56]   //                                    辅助
#define HardConf_HardConf57      HardConf[57]   //                                    辅助
#define HardConf_E5Use           HardConf[58]   //辅助用，模块5是否使用                         辅助
#define HardConf_E5DINum         HardConf[59]   //辅助用，模块5的DI点数                        辅助
#define HardConf_E5DONum         HardConf[60]   //辅助用，模块5的DO点数                        辅助
#define HardConf_E5DANum         HardConf[61]   //辅助用，模块5的DA路数                        辅助
#define HardConf_E5HADNum        HardConf[62]   //辅助用，模块5的HAD路数                       辅助
#define HardConf_E5LADNum        HardConf[63]   //辅助用，模块5的LAD路数                       辅助
#define HardConf_E5CNTNum        HardConf[64]   //辅助用，模块5的CNT路数                       辅助
#define HardConf_HardConf65      HardConf[65]   //                                    辅助
#define HardConf_HardConf66      HardConf[66]   //                                    辅助
#define HardConf_E6Use           HardConf[67]   //辅助用，模块6是否使用                         辅助
#define HardConf_E6DINum         HardConf[68]   //辅助用，模块6的DI点数                        辅助
#define HardConf_E6DONum         HardConf[69]   //辅助用，模块6的DO点数                        辅助
#define HardConf_E6DANum         HardConf[70]   //辅助用，模块6的DA路数                        辅助
#define HardConf_E6HADNum        HardConf[71]   //辅助用，模块6的HAD路数                       辅助
#define HardConf_E6LADNum        HardConf[72]   //辅助用，模块6的LAD路数                       辅助
#define HardConf_E6CNTNum        HardConf[73]   //辅助用，模块6的CNT路数                       辅助
#define HardConf_HardConf74      HardConf[74]   //                                    辅助
#define HardConf_HardConfStart   HardConf[75]   //辅助用，用于定位，禁止修改                       辅助

#define Hard_DI01                HardConf[76]   //DI输入点                               DI
#define Hard_DI02                HardConf[77]   //DI输入点                               DI
#define Hard_DI03                HardConf[78]   //DI输入点                               DI
#define Hard_DI04                HardConf[79]   //DI输入点                               DI
#define Hard_DI05                HardConf[80]   //DI输入点                               DI
#define Hard_DI06                HardConf[81]   //DI输入点                               DI
#define Hard_DI07                HardConf[82]   //DI输入点                               DI
#define Hard_DI08                HardConf[83]   //DI输入点                               DI
#define Hard_DI09                HardConf[84]   //DI输入点                               DI
#define Hard_DI10                HardConf[85]   //DI输入点                               DI
#define Hard_DI11                HardConf[86]   //DI输入点                               DI
#define Hard_DI12                HardConf[87]   //DI输入点                               DI
#define Hard_DI13                HardConf[88]   //DI输入点                               DI
#define Hard_DI14                HardConf[89]   //DI输入点                               DI
#define Hard_DI15                HardConf[90]   //DI输入点                               DI
#define Hard_DI16                HardConf[91]   //DI输入点                               DI
#define Hard_DI17                HardConf[92]   //DI输入点，电路相关，禁止更改对应资源                 DI
#define Hard_DI18                HardConf[93]   //DI输入点，电路相关，禁止更改对应资源                 DI
#define Hard_DI19                HardConf[94]   //DI输入点，电路相关，禁止更改对应资源                 DI
#define Hard_DI20                HardConf[95]   //DI输入点                               DI
#define Hard_DI21                HardConf[96]   //DI输入点                               DI
#define Hard_DI22                HardConf[97]   //DI输入点                               DI
#define Hard_DI23                HardConf[98]   //DI输入点                               DI
#define Hard_DI24                HardConf[99]   //DI输入点                               DI
#define Hard_DI25                HardConf[100]  //DI输入点                               DI
#define Hard_DI26                HardConf[101]  //DI输入点                               DI
#define Hard_DI27                HardConf[102]  //DI输入点                               DI
#define Hard_DI28                HardConf[103]  //DI输入点                               DI
#define Hard_DI29                HardConf[104]  //DI输入点                               DI
#define Hard_DI30                HardConf[105]  //DI输入点                               DI
#define Hard_DI31                HardConf[106]  //DI输入点                               DI
#define Hard_DI32                HardConf[107]  //DI输入点                               DI
#define Hard_DI33                HardConf[108]  //DI输入点                               DI
#define Hard_DI34                HardConf[109]  //DI输入点                               DI
#define Hard_DI35                HardConf[110]  //DI输入点                               DI
#define Hard_DI36                HardConf[111]  //DI输入点                               DI
#define Hard_DI37                HardConf[112]  //DI输入点                               DI
#define Hard_DI38                HardConf[113]  //DI输入点                               DI
#define Hard_DI39                HardConf[114]  //DI输入点                               DI
#define Hard_DI40                HardConf[115]  //DI输入点                               DI
#define Hard_DI41                HardConf[116]  //DI输入点                               DI
#define Hard_DI42                HardConf[117]  //DI输入点                               DI
#define Hard_DI43                HardConf[118]  //DI输入点                               DI
#define Hard_DI44                HardConf[119]  //DI输入点                               DI
#define Hard_DI45                HardConf[120]  //DI输入点                               DI
#define Hard_DI46                HardConf[121]  //DI输入点                               DI
#define Hard_DI47                HardConf[122]  //DI输入点                               DI
#define Hard_DI48                HardConf[123]  //DI输入点                               DI
#define Hard_DI49                HardConf[124]  //DI输入点                               DI
#define Hard_DI50                HardConf[125]  //DI输入点                               DI
#define Hard_DI51                HardConf[126]  //DI输入点                               DI
#define Hard_DI52                HardConf[127]  //DI输入点                               DI
#define Hard_DI53                HardConf[128]  //DI输入点                               DI
#define Hard_DI54                HardConf[129]  //DI输入点                               DI
#define Hard_DI55                HardConf[130]  //DI输入点                               DI
#define Hard_DI56                HardConf[131]  //DI输入点                               DI
#define Hard_DI57                HardConf[132]  //DI输入点                               DI
#define Hard_DI58                HardConf[133]  //DI输入点                               DI
#define Hard_DI59                HardConf[134]  //DI输入点                               DI
#define Hard_DI60                HardConf[135]  //DI输入点                               DI
#define Hard_DI61                HardConf[136]  //DI输入点                               DI
#define Hard_DI62                HardConf[137]  //DI输入点                               DI
#define Hard_DI63                HardConf[138]  //DI输入点                               DI
#define Hard_DI64                HardConf[139]  //DI输入点                               DI
#define Hard_DO01                HardConf[140]  //DO输出点，电路相关，禁止更改对应资源                 DO
#define Hard_DO02                HardConf[141]  //DO输出点                               DO
#define Hard_DO03                HardConf[142]  //DO输出点                               DO
#define Hard_DO04                HardConf[143]  //DO输出点                               DO
#define Hard_DO05                HardConf[144]  //DO输出点                               DO
#define Hard_DO06                HardConf[145]  //DO输出点                               DO
#define Hard_DO07                HardConf[146]  //DO输出点                               DO
#define Hard_DO08                HardConf[147]  //DO输出点                               DO
#define Hard_DO09                HardConf[148]  //DO输出点                               DO
#define Hard_DO10                HardConf[149]  //DO输出点                               DO
#define Hard_DO11                HardConf[150]  //DO输出点                               DO
#define Hard_DO12                HardConf[151]  //DO输出点                               DO
#define Hard_DO13                HardConf[152]  //DO输出点                               DO
#define Hard_DO14                HardConf[153]  //DO输出点                               DO
#define Hard_DO15                HardConf[154]  //DO输出点                               DO
#define Hard_DO16                HardConf[155]  //DO输出点                               DO
#define Hard_DO17                HardConf[156]  //DO输出点                               DO
#define Hard_DO18                HardConf[157]  //DO输出点                               DO
#define Hard_DO19                HardConf[158]  //DO输出点                               DO
#define Hard_DO20                HardConf[159]  //DO输出点                               DO
#define Hard_DO21                HardConf[160]  //DO输出点                               DO
#define Hard_DO22                HardConf[161]  //DO输出点                               DO
#define Hard_DO23                HardConf[162]  //DO输出点                               DO
#define Hard_DO24                HardConf[163]  //DO输出点                               DO
#define Hard_DO25                HardConf[164]  //DO输出点                               DO
#define Hard_DO26                HardConf[165]  //DO输出点                               DO
#define Hard_DO27                HardConf[166]  //DO输出点                               DO
#define Hard_DO28                HardConf[167]  //DO输出点                               DO
#define Hard_DO29                HardConf[168]  //DO输出点                               DO
#define Hard_DO30                HardConf[169]  //DO输出点                               DO
#define Hard_DO31                HardConf[170]  //DO输出点                               DO
#define Hard_DO32                HardConf[171]  //DO输出点                               DO
#define Hard_DO33                HardConf[172]  //DO输出点                               DO
#define Hard_DO34                HardConf[173]  //DO输出点                               DO
#define Hard_DO35                HardConf[174]  //DO输出点                               DO
#define Hard_DO36                HardConf[175]  //DO输出点                               DO
#define Hard_DO37                HardConf[176]  //DO输出点                               DO
#define Hard_DO38                HardConf[177]  //DO输出点                               DO
#define Hard_DO39                HardConf[178]  //DO输出点                               DO
#define Hard_DO40                HardConf[179]  //DO输出点                               DO
#define Hard_DO41                HardConf[180]  //DO输出点                               DO
#define Hard_DO42                HardConf[181]  //DO输出点                               DO
#define Hard_DO43                HardConf[182]  //DO输出点                               DO
#define Hard_DO44                HardConf[183]  //DO输出点                               DO
#define Hard_DO45                HardConf[184]  //DO输出点                               DO
#define Hard_DO46                HardConf[185]  //DO输出点                               DO
#define Hard_DO47                HardConf[186]  //DO输出点                               DO
#define Hard_DO48                HardConf[187]  //DO输出点                               DO
#define Hard_DO49                HardConf[188]  //DO输出点                               DO
#define Hard_DO50                HardConf[189]  //DO输出点                               DO
#define Hard_DO51                HardConf[190]  //DO输出点                               DO
#define Hard_DO52                HardConf[191]  //DO输出点                               DO
#define Hard_DO53                HardConf[192]  //DO输出点                               DO
#define Hard_DO54                HardConf[193]  //DO输出点                               DO
#define Hard_DO55                HardConf[194]  //DO输出点                               DO
#define Hard_DO56                HardConf[195]  //DO输出点                               DO
#define Hard_DO57                HardConf[196]  //DO输出点                               DO
#define Hard_DO58                HardConf[197]  //DO输出点                               DO
#define Hard_DO59                HardConf[198]  //DO输出点                               DO
#define Hard_DO60                HardConf[199]  //DO输出点                               DO
#define Hard_DO61                HardConf[200]  //DO输出点                               DO
#define Hard_DO62                HardConf[201]  //DO输出点                               DO
#define Hard_DO63                HardConf[202]  //DO输出点                               DO
#define Hard_DO64                HardConf[203]  //DO输出点                               DO
#define Hard_DO65                HardConf[204]  //继电器输出                               DO
#define Hard_DO66                HardConf[205]  //继电器输出                               DO
#define Hard_DO67                HardConf[206]  //继电器输出                               DO
#define Hard_DO68                HardConf[207]  //继电器输出                               DO
#define Hard_DO69                HardConf[208]  //继电器输出                               DO
#define Hard_DO70                HardConf[209]  //继电器输出                               DO
#define Hard_DO71                HardConf[210]  //继电器输出                               DO
#define Hard_DO72                HardConf[211]  //继电器输出                               DO
#define Hard_DO73                HardConf[212]  //继电器输出                               DO
#define Hard_DO74                HardConf[213]  //继电器输出                               DO
#define Hard_DO75                HardConf[214]  //继电器输出                               DO
#define Hard_DO76                HardConf[215]  //继电器输出                               DO
#define Hard_DO77                HardConf[216]  //继电器输出                               DO
#define Hard_DO78                HardConf[217]  //继电器输出                               DO
#define Hard_DO79                HardConf[218]  //继电器输出                               DO
#define Hard_DO80                HardConf[219]  //继电器输出                               DO
#define Hard_DO81                HardConf[220]  //继电器输出                               DO
#define Hard_DO82                HardConf[221]  //继电器输出                               DO
#define Hard_DO83                HardConf[222]  //继电器输出                               DO
#define Hard_DO84                HardConf[223]  //继电器输出                               DO
#define Hard_DO85                HardConf[224]  //继电器输出                               DO
#define Hard_DO86                HardConf[225]  //继电器输出                               DO
#define Hard_DO87                HardConf[226]  //继电器输出                               DO
#define Hard_DO88                HardConf[227]  //继电器输出                               DO
#define Hard_DO89                HardConf[228]  //继电器输出                               DO
#define Hard_DO90                HardConf[229]  //继电器输出                               DO
#define Hard_DO91                HardConf[230]  //继电器输出                               DO
#define Hard_DO92                HardConf[231]  //继电器输出                               DO
#define Hard_DO93                HardConf[232]  //继电器输出                               DO
#define Hard_DO94                HardConf[233]  //继电器输出                               DO
#define Hard_DO95                HardConf[234]  //继电器输出                               DO
#define Hard_DO96                HardConf[235]  //继电器输出                               DO
#define Hard_DA01                HardConf[236]  //DA输出                                U32
#define Hard_DA02                HardConf[237]  //DA输出                                U32
#define Hard_DA03                HardConf[238]  //DA输出                                U32
#define Hard_DA04                HardConf[239]  //DA输出                                U32
#define Hard_DA05                HardConf[240]  //DA输出                                U32
#define Hard_DA06                HardConf[241]  //DA输出                                U32
#define Hard_DA07                HardConf[242]  //DA输出                                U32
#define Hard_DA08                HardConf[243]  //DA输出                                U32
#define Hard_DA09                HardConf[244]  //DA输出                                U32
#define Hard_DA10                HardConf[245]  //DA输出                                U32
#define Hard_DA11                HardConf[246]  //DA输出                                U32
#define Hard_DA12                HardConf[247]  //DA输出                                U32
#define Hard_DA13                HardConf[248]  //DA输出                                U32
#define Hard_DA14                HardConf[249]  //DA输出                                U32
#define Hard_DA15                HardConf[250]  //DA输出                                U32
#define Hard_DA16                HardConf[251]  //DA输出                                U32
#define Hard_HAD01               HardConf[252]  //HAD输入                               U32
#define Hard_HAD02               HardConf[253]  //HAD输入                               U32
#define Hard_HAD03               HardConf[254]  //HAD输入                               U32
#define Hard_HAD04               HardConf[255]  //HAD输入                               U32
#define Hard_HAD05               HardConf[256]  //HAD输入                               U32
#define Hard_HAD06               HardConf[257]  //HAD输入                               U32
#define Hard_HAD07               HardConf[258]  //HAD输入                               U32
#define Hard_HAD08               HardConf[259]  //HAD输入                               U32
#define Hard_HAD09               HardConf[260]  //HAD输入,这里作为MAD1输入，接压力传感器             U32
#define Hard_HAD10               HardConf[261]  //HAD输入                               U32
#define Hard_HAD11               HardConf[262]  //HAD输入                               U32
#define Hard_HAD12               HardConf[263]  //HAD输入                               U32
#define Hard_HAD13               HardConf[264]  //HAD输入                               U32
#define Hard_HAD14               HardConf[265]  //HAD输入                               U32
#define Hard_HAD15               HardConf[266]  //HAD输入                               U32
#define Hard_HAD16               HardConf[267]  //HAD输入                               U32
#define Hard_LAD01               HardConf[268]  //LAD输入                               U32
#define Hard_LAD02               HardConf[269]  //LAD输入                               U32
#define Hard_LAD03               HardConf[270]  //LAD输入                               U32
#define Hard_LAD04               HardConf[271]  //LAD输入                               U32
#define Hard_LAD05               HardConf[272]  //LAD输入                               U32
#define Hard_LAD06               HardConf[273]  //LAD输入                               U32
#define Hard_LAD07               HardConf[274]  //LAD输入                               U32
#define Hard_LAD08               HardConf[275]  //LAD输入                               U32
#define Hard_LAD09               HardConf[276]  //LAD输入                               U32
#define Hard_LAD10               HardConf[277]  //LAD输入                               U32
#define Hard_LAD11               HardConf[278]  //LAD输入                               U32
#define Hard_LAD12               HardConf[279]  //LAD输入                               U32
#define Hard_LAD13               HardConf[280]  //LAD输入                               U32
#define Hard_LAD14               HardConf[281]  //LAD输入                               U32
#define Hard_LAD15               HardConf[282]  //LAD输入                               U32
#define Hard_LAD16               HardConf[283]  //LAD输入                               U32
#define Hard_CNT01               HardConf[284]  //计数输入                                U32
#define Hard_CNT02               HardConf[285]  //计数输入                                U32
#define Hard_CNT03               HardConf[286]  //计数输入                                U32
#define Hard_CNT04               HardConf[287]  //计数输入                                U32
#define Hard_CNT05               HardConf[288]  //计数输入                                U32
#define Hard_CNT06               HardConf[289]  //计数输入                                U32
#define Hard_CNT07               HardConf[290]  //计数输入                                U32
#define Hard_CNT08               HardConf[291]  //计数输入                                U32
#define Hard_SDDrv1Pres          HardConf[292]  //伺服驱动器1输出压力                          U32
#define Hard_SDDrv1Flow          HardConf[293]  //伺服驱动器1输出流量                          U32
#define Hard_SDDrv2Pres          HardConf[294]  //伺服驱动器2输出压力                          U32
#define Hard_SDDrv2Flow          HardConf[295]  //伺服驱动器2输出流量                          U32
#define Hard_SDDrv3Pres          HardConf[296]  //伺服驱动器3输出压力                          U32
#define Hard_SDDrv3Flow          HardConf[297]  //伺服驱动器3输出流量                          U32
#define Hard_SDDrv4Pres          HardConf[298]  //伺服驱动器4输出压力                          U32
#define Hard_SDDrv4Flow          HardConf[299]  //伺服驱动器4输出流量                          U32
#define Hard_300                 HardConf[300]  //                                    U32
#define Hard_301                 HardConf[301]  //                                    U32
#define Hard_302                 HardConf[302]  //                                    U32
#define Hard_303                 HardConf[303]  //                                    U32
#define Hard_304                 HardConf[304]  //                                    U32
#define Hard_305                 HardConf[305]  //                                    U32
#define Hard_306                 HardConf[306]  //                                    U32
#define Hard_307                 HardConf[307]  //                                    U32
#define Hard_308                 HardConf[308]  //                                    U32
#define Hard_309                 HardConf[309]  //                                    U32
#define Hard_310                 HardConf[310]  //                                    U32
#define Hard_311                 HardConf[311]  //                                    U32
#define Hard_312                 HardConf[312]  //                                    U32
#define Hard_313                 HardConf[313]  //                                    U32
#define Hard_314                 HardConf[314]  //                                    U32
#define Hard_315                 HardConf[315]  //                                    U32
#define Hard_316                 HardConf[316]  //                                    U32
#define Hard_317                 HardConf[317]  //                                    U32
#define Hard_318                 HardConf[318]  //                                    U32
#define Hard_319                 HardConf[319]  //                                    U32
#define Hard_320                 HardConf[320]  //                                    U32
#define Hard_321                 HardConf[321]  //                                    U32
#define Hard_322                 HardConf[322]  //                                    U32
#define Hard_323                 HardConf[323]  //                                    U32
#define Hard_324                 HardConf[324]  //                                    U32
#define Hard_325                 HardConf[325]  //                                    U32
#define Hard_326                 HardConf[326]  //                                    U32
#define Hard_327                 HardConf[327]  //                                    U32
#define Hard_328                 HardConf[328]  //                                    U32
#define Hard_329                 HardConf[329]  //                                    U32
#define Hard_330                 HardConf[330]  //                                    U32
#define Hard_331                 HardConf[331]  //                                    U32
#define Hard_E1DI01              HardConf[332]  //模块n输入点                              DI
#define Hard_E1DI02              HardConf[333]  //模块n输入点                              DI
#define Hard_E1DI03              HardConf[334]  //模块n输入点                              DI
#define Hard_E1DI04              HardConf[335]  //模块n输入点                              DI
#define Hard_E1DI05              HardConf[336]  //模块n输入点                              DI
#define Hard_E1DI06              HardConf[337]  //模块n输入点                              DI
#define Hard_E1DI07              HardConf[338]  //模块n输入点                              DI
#define Hard_E1DI08              HardConf[339]  //模块n输入点                              DI
#define Hard_E1DI09              HardConf[340]  //模块n输入点                              DI
#define Hard_E1DI10              HardConf[341]  //模块n输入点                              DI
#define Hard_E1DI11              HardConf[342]  //模块n输入点                              DI
#define Hard_E1DI12              HardConf[343]  //模块n输入点                              DI
#define Hard_E1DI13              HardConf[344]  //模块n输入点                              DI
#define Hard_E1DI14              HardConf[345]  //模块n输入点                              DI
#define Hard_E1DI15              HardConf[346]  //模块n输入点                              DI
#define Hard_E1DI16              HardConf[347]  //模块n输入点                              DI
#define Hard_E1DO01              HardConf[348]  //模块n输出点                              DO
#define Hard_E1DO02              HardConf[349]  //模块n输出点                              DO
#define Hard_E1DO03              HardConf[350]  //模块n输出点                              DO
#define Hard_E1DO04              HardConf[351]  //模块n输出点                              DO
#define Hard_E1DO05              HardConf[352]  //模块n输出点                              DO
#define Hard_E1DO06              HardConf[353]  //模块n输出点                              DO
#define Hard_E1DO07              HardConf[354]  //模块n输出点                              DO
#define Hard_E1DO08              HardConf[355]  //模块n输出点                              DO
#define Hard_E1DO09              HardConf[356]  //模块n输出点                              DO
#define Hard_E1DO10              HardConf[357]  //模块n输出点                              DO
#define Hard_E1DO11              HardConf[358]  //模块n输出点                              DO
#define Hard_E1DO12              HardConf[359]  //模块n输出点                              DO
#define Hard_E1DO13              HardConf[360]  //模块n输出点                              DO
#define Hard_E1DO14              HardConf[361]  //模块n输出点                              DO
#define Hard_E1DO15              HardConf[362]  //模块n输出点                              DO
#define Hard_E1DO16              HardConf[363]  //模块n输出点                              DO
#define Hard_E1DA01              HardConf[364]  //模块n DA输出                            U32
#define Hard_E1DA02              HardConf[365]  //模块n DA输出                            U32
#define Hard_E1DA03              HardConf[366]  //模块n DA输出                            U32
#define Hard_E1DA04              HardConf[367]  //模块n DA输出                            U32
#define Hard_E1DA05              HardConf[368]  //模块n DA输出                            U32
#define Hard_E1DA06              HardConf[369]  //模块n DA输出                            U32
#define Hard_E1DA07              HardConf[370]  //模块n DA输出                            U32
#define Hard_E1DA08              HardConf[371]  //模块n DA输出                            U32
#define Hard_E1HAD01             HardConf[372]  //模块n HAD输入                           U32
#define Hard_E1HAD02             HardConf[373]  //模块n HAD输入                           U32
#define Hard_E1HAD03             HardConf[374]  //模块n HAD输入                           U32
#define Hard_E1HAD04             HardConf[375]  //模块n HAD输入                           U32
#define Hard_E1HAD05             HardConf[376]  //模块n HAD输入                           U32
#define Hard_E1HAD06             HardConf[377]  //模块n HAD输入                           U32
#define Hard_E1HAD07             HardConf[378]  //模块n HAD输入                           U32
#define Hard_E1HAD08             HardConf[379]  //模块n HAD输入                           U32
#define Hard_E1LAD01             HardConf[380]  //模块n LAD输入                           U32
#define Hard_E1LAD02             HardConf[381]  //模块n LAD输入                           U32
#define Hard_E1LAD03             HardConf[382]  //模块n LAD输入                           U32
#define Hard_E1LAD04             HardConf[383]  //模块n LAD输入                           U32
#define Hard_E1LAD05             HardConf[384]  //模块n LAD输入                           U32
#define Hard_E1LAD06             HardConf[385]  //模块n LAD输入                           U32
#define Hard_E1LAD07             HardConf[386]  //模块n LAD输入                           U32
#define Hard_E1LAD08             HardConf[387]  //模块n LAD输入                           U32
#define Hard_E1LAD09             HardConf[388]  //模块n LAD输入                           U32
#define Hard_E1LAD10             HardConf[389]  //模块n LAD输入                           U32
#define Hard_E1LAD11             HardConf[390]  //模块n LAD输入                           U32
#define Hard_E1LAD12             HardConf[391]  //模块n LAD输入                           U32
#define Hard_E1LAD13             HardConf[392]  //模块n LAD输入                           U32
#define Hard_E1LAD14             HardConf[393]  //模块n LAD输入                           U32
#define Hard_E1LAD15             HardConf[394]  //模块n LAD输入                           U32
#define Hard_E1LAD16             HardConf[395]  //模块n LAD输入                           U32
#define Hard_E1CNT01             HardConf[396]  //模块n计数输入                             U32
#define Hard_E1CNT02             HardConf[397]  //模块n计数输入                             U32
#define Hard_E1CNT03             HardConf[398]  //模块n计数输入                             U32
#define Hard_E1CNT04             HardConf[399]  //模块n计数输入                             U32
#define Hard_E1CNT05             HardConf[400]  //模块n计数输入                             U32
#define Hard_E1CNT06             HardConf[401]  //模块n计数输入                             U32
#define Hard_E1CNT07             HardConf[402]  //模块n计数输入                             U32
#define Hard_E1CNT08             HardConf[403]  //模块n计数输入                             U32
#define Hard_404                 HardConf[404]  //                                    U32
#define Hard_405                 HardConf[405]  //                                    U32
#define Hard_406                 HardConf[406]  //                                    U32
#define Hard_407                 HardConf[407]  //                                    U32
#define Hard_408                 HardConf[408]  //                                    U32
#define Hard_409                 HardConf[409]  //                                    U32
#define Hard_410                 HardConf[410]  //                                    U32
#define Hard_411                 HardConf[411]  //                                    U32
#define Hard_E2DI01              HardConf[412]  //模块n输入点                              DI
#define Hard_E2DI02              HardConf[413]  //模块n输入点                              DI
#define Hard_E2DI03              HardConf[414]  //模块n输入点                              DI
#define Hard_E2DI04              HardConf[415]  //模块n输入点                              DI
#define Hard_E2DI05              HardConf[416]  //模块n输入点                              DI
#define Hard_E2DI06              HardConf[417]  //模块n输入点                              DI
#define Hard_E2DI07              HardConf[418]  //模块n输入点                              DI
#define Hard_E2DI08              HardConf[419]  //模块n输入点                              DI
#define Hard_E2DI09              HardConf[420]  //模块n输入点                              DI
#define Hard_E2DI10              HardConf[421]  //模块n输入点                              DI
#define Hard_E2DI11              HardConf[422]  //模块n输入点                              DI
#define Hard_E2DI12              HardConf[423]  //模块n输入点                              DI
#define Hard_E2DI13              HardConf[424]  //模块n输入点                              DI
#define Hard_E2DI14              HardConf[425]  //模块n输入点                              DI
#define Hard_E2DI15              HardConf[426]  //模块n输入点                              DI
#define Hard_E2DI16              HardConf[427]  //模块n输入点                              DI
#define Hard_E2DO01              HardConf[428]  //模块n输出点                              DO
#define Hard_E2DO02              HardConf[429]  //模块n输出点                              DO
#define Hard_E2DO03              HardConf[430]  //模块n输出点                              DO
#define Hard_E2DO04              HardConf[431]  //模块n输出点                              DO
#define Hard_E2DO05              HardConf[432]  //模块n输出点                              DO
#define Hard_E2DO06              HardConf[433]  //模块n输出点                              DO
#define Hard_E2DO07              HardConf[434]  //模块n输出点                              DO
#define Hard_E2DO08              HardConf[435]  //模块n输出点                              DO
#define Hard_E2DO09              HardConf[436]  //模块n输出点                              DO
#define Hard_E2DO10              HardConf[437]  //模块n输出点                              DO
#define Hard_E2DO11              HardConf[438]  //模块n输出点                              DO
#define Hard_E2DO12              HardConf[439]  //模块n输出点                              DO
#define Hard_E2DO13              HardConf[440]  //模块n输出点                              DO
#define Hard_E2DO14              HardConf[441]  //模块n输出点                              DO
#define Hard_E2DO15              HardConf[442]  //模块n输出点                              DO
#define Hard_E2DO16              HardConf[443]  //模块n输出点                              DO
#define Hard_E2DA01              HardConf[444]  //模块n DA输出                            U32
#define Hard_E2DA02              HardConf[445]  //模块n DA输出                            U32
#define Hard_E2DA03              HardConf[446]  //模块n DA输出                            U32
#define Hard_E2DA04              HardConf[447]  //模块n DA输出                            U32
#define Hard_E2DA05              HardConf[448]  //模块n DA输出                            U32
#define Hard_E2DA06              HardConf[449]  //模块n DA输出                            U32
#define Hard_E2DA07              HardConf[450]  //模块n DA输出                            U32
#define Hard_E2DA08              HardConf[451]  //模块n DA输出                            U32
#define Hard_E2HAD01             HardConf[452]  //模块n HAD输入                           U32
#define Hard_E2HAD02             HardConf[453]  //模块n HAD输入                           U32
#define Hard_E2HAD03             HardConf[454]  //模块n HAD输入                           U32
#define Hard_E2HAD04             HardConf[455]  //模块n HAD输入                           U32
#define Hard_E2HAD05             HardConf[456]  //模块n HAD输入                           U32
#define Hard_E2HAD06             HardConf[457]  //模块n HAD输入                           U32
#define Hard_E2HAD07             HardConf[458]  //模块n HAD输入                           U32
#define Hard_E2HAD08             HardConf[459]  //模块n HAD输入                           U32
#define Hard_E2LAD01             HardConf[460]  //模块n LAD输入                           U32
#define Hard_E2LAD02             HardConf[461]  //模块n LAD输入                           U32
#define Hard_E2LAD03             HardConf[462]  //模块n LAD输入                           U32
#define Hard_E2LAD04             HardConf[463]  //模块n LAD输入                           U32
#define Hard_E2LAD05             HardConf[464]  //模块n LAD输入                           U32
#define Hard_E2LAD06             HardConf[465]  //模块n LAD输入                           U32
#define Hard_E2LAD07             HardConf[466]  //模块n LAD输入                           U32
#define Hard_E2LAD08             HardConf[467]  //模块n LAD输入                           U32
#define Hard_E2LAD09             HardConf[468]  //模块n LAD输入                           U32
#define Hard_E2LAD10             HardConf[469]  //模块n LAD输入                           U32
#define Hard_E2LAD11             HardConf[470]  //模块n LAD输入                           U32
#define Hard_E2LAD12             HardConf[471]  //模块n LAD输入                           U32
#define Hard_E2LAD13             HardConf[472]  //模块n LAD输入                           U32
#define Hard_E2LAD14             HardConf[473]  //模块n LAD输入                           U32
#define Hard_E2LAD15             HardConf[474]  //模块n LAD输入                           U32
#define Hard_E2LAD16             HardConf[475]  //模块n LAD输入                           U32
#define Hard_E2CNT01             HardConf[476]  //模块n计数输入                             U32
#define Hard_E2CNT02             HardConf[477]  //模块n计数输入                             U32
#define Hard_E2CNT03             HardConf[478]  //模块n计数输入                             U32
#define Hard_E2CNT04             HardConf[479]  //模块n计数输入                             U32
#define Hard_E2CNT05             HardConf[480]  //模块n计数输入                             U32
#define Hard_E2CNT06             HardConf[481]  //模块n计数输入                             U32
#define Hard_E2CNT07             HardConf[482]  //模块n计数输入                             U32
#define Hard_E2CNT08             HardConf[483]  //模块n计数输入                             U32
#define Hard_484                 HardConf[484]  //                                    U32
#define Hard_485                 HardConf[485]  //                                    U32
#define Hard_486                 HardConf[486]  //                                    U32
#define Hard_487                 HardConf[487]  //                                    U32
#define Hard_488                 HardConf[488]  //                                    U32
#define Hard_489                 HardConf[489]  //                                    U32
#define Hard_490                 HardConf[490]  //                                    U32
#define Hard_491                 HardConf[491]  //                                    U32
#define Hard_E3DI01              HardConf[492]  //模块n输入点                              DI
#define Hard_E3DI02              HardConf[493]  //模块n输入点                              DI
#define Hard_E3DI03              HardConf[494]  //模块n输入点                              DI
#define Hard_E3DI04              HardConf[495]  //模块n输入点                              DI
#define Hard_E3DI05              HardConf[496]  //模块n输入点                              DI
#define Hard_E3DI06              HardConf[497]  //模块n输入点                              DI
#define Hard_E3DI07              HardConf[498]  //模块n输入点                              DI
#define Hard_E3DI08              HardConf[499]  //模块n输入点                              DI
#define Hard_E3DI09              HardConf[500]  //模块n输入点                              DI
#define Hard_E3DI10              HardConf[501]  //模块n输入点                              DI
#define Hard_E3DI11              HardConf[502]  //模块n输入点                              DI
#define Hard_E3DI12              HardConf[503]  //模块n输入点                              DI
#define Hard_E3DI13              HardConf[504]  //模块n输入点                              DI
#define Hard_E3DI14              HardConf[505]  //模块n输入点                              DI
#define Hard_E3DI15              HardConf[506]  //模块n输入点                              DI
#define Hard_E3DI16              HardConf[507]  //模块n输入点                              DI
#define Hard_E3DO01              HardConf[508]  //模块n输出点                              DO
#define Hard_E3DO02              HardConf[509]  //模块n输出点                              DO
#define Hard_E3DO03              HardConf[510]  //模块n输出点                              DO
#define Hard_E3DO04              HardConf[511]  //模块n输出点                              DO
#define Hard_E3DO05              HardConf[512]  //模块n输出点                              DO
#define Hard_E3DO06              HardConf[513]  //模块n输出点                              DO
#define Hard_E3DO07              HardConf[514]  //模块n输出点                              DO
#define Hard_E3DO08              HardConf[515]  //模块n输出点                              DO
#define Hard_E3DO09              HardConf[516]  //模块n输出点                              DO
#define Hard_E3DO10              HardConf[517]  //模块n输出点                              DO
#define Hard_E3DO11              HardConf[518]  //模块n输出点                              DO
#define Hard_E3DO12              HardConf[519]  //模块n输出点                              DO
#define Hard_E3DO13              HardConf[520]  //模块n输出点                              DO
#define Hard_E3DO14              HardConf[521]  //模块n输出点                              DO
#define Hard_E3DO15              HardConf[522]  //模块n输出点                              DO
#define Hard_E3DO16              HardConf[523]  //模块n输出点                              DO
#define Hard_E3DA01              HardConf[524]  //模块n DA输出                            U32
#define Hard_E3DA02              HardConf[525]  //模块n DA输出                            U32
#define Hard_E3DA03              HardConf[526]  //模块n DA输出                            U32
#define Hard_E3DA04              HardConf[527]  //模块n DA输出                            U32
#define Hard_E3DA05              HardConf[528]  //模块n DA输出                            U32
#define Hard_E3DA06              HardConf[529]  //模块n DA输出                            U32
#define Hard_E3DA07              HardConf[530]  //模块n DA输出                            U32
#define Hard_E3DA08              HardConf[531]  //模块n DA输出                            U32
#define Hard_E3HAD01             HardConf[532]  //模块n HAD输入                           U32
#define Hard_E3HAD02             HardConf[533]  //模块n HAD输入                           U32
#define Hard_E3HAD03             HardConf[534]  //模块n HAD输入                           U32
#define Hard_E3HAD04             HardConf[535]  //模块n HAD输入                           U32
#define Hard_E3HAD05             HardConf[536]  //模块n HAD输入                           U32
#define Hard_E3HAD06             HardConf[537]  //模块n HAD输入                           U32
#define Hard_E3HAD07             HardConf[538]  //模块n HAD输入                           U32
#define Hard_E3HAD08             HardConf[539]  //模块n HAD输入                           U32
#define Hard_E3LAD01             HardConf[540]  //模块n LAD输入                           U32
#define Hard_E3LAD02             HardConf[541]  //模块n LAD输入                           U32
#define Hard_E3LAD03             HardConf[542]  //模块n LAD输入                           U32
#define Hard_E3LAD04             HardConf[543]  //模块n LAD输入                           U32
#define Hard_E3LAD05             HardConf[544]  //模块n LAD输入                           U32
#define Hard_E3LAD06             HardConf[545]  //模块n LAD输入                           U32
#define Hard_E3LAD07             HardConf[546]  //模块n LAD输入                           U32
#define Hard_E3LAD08             HardConf[547]  //模块n LAD输入                           U32
#define Hard_E3LAD09             HardConf[548]  //模块n LAD输入                           U32
#define Hard_E3LAD10             HardConf[549]  //模块n LAD输入                           U32
#define Hard_E3LAD11             HardConf[550]  //模块n LAD输入                           U32
#define Hard_E3LAD12             HardConf[551]  //模块n LAD输入                           U32
#define Hard_E3LAD13             HardConf[552]  //模块n LAD输入                           U32
#define Hard_E3LAD14             HardConf[553]  //模块n LAD输入                           U32
#define Hard_E3LAD15             HardConf[554]  //模块n LAD输入                           U32
#define Hard_E3LAD16             HardConf[555]  //模块n LAD输入                           U32
#define Hard_E3CNT01             HardConf[556]  //模块n计数输入                             U32
#define Hard_E3CNT02             HardConf[557]  //模块n计数输入                             U32
#define Hard_E3CNT03             HardConf[558]  //模块n计数输入                             U32
#define Hard_E3CNT04             HardConf[559]  //模块n计数输入                             U32
#define Hard_E3CNT05             HardConf[560]  //模块n计数输入                             U32
#define Hard_E3CNT06             HardConf[561]  //模块n计数输入                             U32
#define Hard_E3CNT07             HardConf[562]  //模块n计数输入                             U32
#define Hard_E3CNT08             HardConf[563]  //模块n计数输入                             U32
#define Hard_564                 HardConf[564]  //                                    U32
#define Hard_565                 HardConf[565]  //                                    U32
#define Hard_566                 HardConf[566]  //                                    U32
#define Hard_567                 HardConf[567]  //                                    U32
#define Hard_568                 HardConf[568]  //                                    U32
#define Hard_569                 HardConf[569]  //                                    U32
#define Hard_570                 HardConf[570]  //                                    U32
#define Hard_571                 HardConf[571]  //                                    U32
#define Hard_E4DI01              HardConf[572]  //模块n输入点                              DI
#define Hard_E4DI02              HardConf[573]  //模块n输入点                              DI
#define Hard_E4DI03              HardConf[574]  //模块n输入点                              DI
#define Hard_E4DI04              HardConf[575]  //模块n输入点                              DI
#define Hard_E4DI05              HardConf[576]  //模块n输入点                              DI
#define Hard_E4DI06              HardConf[577]  //模块n输入点                              DI
#define Hard_E4DI07              HardConf[578]  //模块n输入点                              DI
#define Hard_E4DI08              HardConf[579]  //模块n输入点                              DI
#define Hard_E4DI09              HardConf[580]  //模块n输入点                              DI
#define Hard_E4DI10              HardConf[581]  //模块n输入点                              DI
#define Hard_E4DI11              HardConf[582]  //模块n输入点                              DI
#define Hard_E4DI12              HardConf[583]  //模块n输入点                              DI
#define Hard_E4DI13              HardConf[584]  //模块n输入点                              DI
#define Hard_E4DI14              HardConf[585]  //模块n输入点                              DI
#define Hard_E4DI15              HardConf[586]  //模块n输入点                              DI
#define Hard_E4DI16              HardConf[587]  //模块n输入点                              DI
#define Hard_E4DO01              HardConf[588]  //模块n输出点                              DO
#define Hard_E4DO02              HardConf[589]  //模块n输出点                              DO
#define Hard_E4DO03              HardConf[590]  //模块n输出点                              DO
#define Hard_E4DO04              HardConf[591]  //模块n输出点                              DO
#define Hard_E4DO05              HardConf[592]  //模块n输出点                              DO
#define Hard_E4DO06              HardConf[593]  //模块n输出点                              DO
#define Hard_E4DO07              HardConf[594]  //模块n输出点                              DO
#define Hard_E4DO08              HardConf[595]  //模块n输出点                              DO
#define Hard_E4DO09              HardConf[596]  //模块n输出点                              DO
#define Hard_E4DO10              HardConf[597]  //模块n输出点                              DO
#define Hard_E4DO11              HardConf[598]  //模块n输出点                              DO
#define Hard_E4DO12              HardConf[599]  //模块n输出点                              DO
#define Hard_E4DO13              HardConf[600]  //模块n输出点                              DO
#define Hard_E4DO14              HardConf[601]  //模块n输出点                              DO
#define Hard_E4DO15              HardConf[602]  //模块n输出点                              DO
#define Hard_E4DO16              HardConf[603]  //模块n输出点                              DO
#define Hard_E4DA01              HardConf[604]  //模块n DA输出                            U32
#define Hard_E4DA02              HardConf[605]  //模块n DA输出                            U32
#define Hard_E4DA03              HardConf[606]  //模块n DA输出                            U32
#define Hard_E4DA04              HardConf[607]  //模块n DA输出                            U32
#define Hard_E4DA05              HardConf[608]  //模块n DA输出                            U32
#define Hard_E4DA06              HardConf[609]  //模块n DA输出                            U32
#define Hard_E4DA07              HardConf[610]  //模块n DA输出                            U32
#define Hard_E4DA08              HardConf[611]  //模块n DA输出                            U32
#define Hard_E4HAD01             HardConf[612]  //模块n HAD输入                           U32
#define Hard_E4HAD02             HardConf[613]  //模块n HAD输入                           U32
#define Hard_E4HAD03             HardConf[614]  //模块n HAD输入                           U32
#define Hard_E4HAD04             HardConf[615]  //模块n HAD输入                           U32
#define Hard_E4HAD05             HardConf[616]  //模块n HAD输入                           U32
#define Hard_E4HAD06             HardConf[617]  //模块n HAD输入                           U32
#define Hard_E4HAD07             HardConf[618]  //模块n HAD输入                           U32
#define Hard_E4HAD08             HardConf[619]  //模块n HAD输入                           U32
#define Hard_E4LAD01             HardConf[620]  //模块n LAD输入                           U32
#define Hard_E4LAD02             HardConf[621]  //模块n LAD输入                           U32
#define Hard_E4LAD03             HardConf[622]  //模块n LAD输入                           U32
#define Hard_E4LAD04             HardConf[623]  //模块n LAD输入                           U32
#define Hard_E4LAD05             HardConf[624]  //模块n LAD输入                           U32
#define Hard_E4LAD06             HardConf[625]  //模块n LAD输入                           U32
#define Hard_E4LAD07             HardConf[626]  //模块n LAD输入                           U32
#define Hard_E4LAD08             HardConf[627]  //模块n LAD输入                           U32
#define Hard_E4LAD09             HardConf[628]  //模块n LAD输入                           U32
#define Hard_E4LAD10             HardConf[629]  //模块n LAD输入                           U32
#define Hard_E4LAD11             HardConf[630]  //模块n LAD输入                           U32
#define Hard_E4LAD12             HardConf[631]  //模块n LAD输入                           U32
#define Hard_E4LAD13             HardConf[632]  //模块n LAD输入                           U32
#define Hard_E4LAD14             HardConf[633]  //模块n LAD输入                           U32
#define Hard_E4LAD15             HardConf[634]  //模块n LAD输入                           U32
#define Hard_E4LAD16             HardConf[635]  //模块n LAD输入                           U32
#define Hard_E4CNT01             HardConf[636]  //模块n计数输入                             U32
#define Hard_E4CNT02             HardConf[637]  //模块n计数输入                             U32
#define Hard_E4CNT03             HardConf[638]  //模块n计数输入                             U32
#define Hard_E4CNT04             HardConf[639]  //模块n计数输入                             U32
#define Hard_E4CNT05             HardConf[640]  //模块n计数输入                             U32
#define Hard_E4CNT06             HardConf[641]  //模块n计数输入                             U32
#define Hard_E4CNT07             HardConf[642]  //模块n计数输入                             U32
#define Hard_E4CNT08             HardConf[643]  //模块n计数输入                             U32
#define Hard_644                 HardConf[644]  //                                    U32
#define Hard_645                 HardConf[645]  //                                    U32
#define Hard_646                 HardConf[646]  //                                    U32
#define Hard_647                 HardConf[647]  //                                    U32
#define Hard_648                 HardConf[648]  //                                    U32
#define Hard_649                 HardConf[649]  //                                    U32
#define Hard_650                 HardConf[650]  //                                    U32
#define Hard_651                 HardConf[651]  //                                    U32
#define Hard_E5DI01              HardConf[652]  //模块n输入点                              DI
#define Hard_E5DI02              HardConf[653]  //模块n输入点                              DI
#define Hard_E5DI03              HardConf[654]  //模块n输入点                              DI
#define Hard_E5DI04              HardConf[655]  //模块n输入点                              DI
#define Hard_E5DI05              HardConf[656]  //模块n输入点                              DI
#define Hard_E5DI06              HardConf[657]  //模块n输入点                              DI
#define Hard_E5DI07              HardConf[658]  //模块n输入点                              DI
#define Hard_E5DI08              HardConf[659]  //模块n输入点                              DI
#define Hard_E5DI09              HardConf[660]  //模块n输入点                              DI
#define Hard_E5DI10              HardConf[661]  //模块n输入点                              DI
#define Hard_E5DI11              HardConf[662]  //模块n输入点                              DI
#define Hard_E5DI12              HardConf[663]  //模块n输入点                              DI
#define Hard_E5DI13              HardConf[664]  //模块n输入点                              DI
#define Hard_E5DI14              HardConf[665]  //模块n输入点                              DI
#define Hard_E5DI15              HardConf[666]  //模块n输入点                              DI
#define Hard_E5DI16              HardConf[667]  //模块n输入点                              DI
#define Hard_E5DO01              HardConf[668]  //模块n输出点                              DO
#define Hard_E5DO02              HardConf[669]  //模块n输出点                              DO
#define Hard_E5DO03              HardConf[670]  //模块n输出点                              DO
#define Hard_E5DO04              HardConf[671]  //模块n输出点                              DO
#define Hard_E5DO05              HardConf[672]  //模块n输出点                              DO
#define Hard_E5DO06              HardConf[673]  //模块n输出点                              DO
#define Hard_E5DO07              HardConf[674]  //模块n输出点                              DO
#define Hard_E5DO08              HardConf[675]  //模块n输出点                              DO
#define Hard_E5DO09              HardConf[676]  //模块n输出点                              DO
#define Hard_E5DO10              HardConf[677]  //模块n输出点                              DO
#define Hard_E5DO11              HardConf[678]  //模块n输出点                              DO
#define Hard_E5DO12              HardConf[679]  //模块n输出点                              DO
#define Hard_E5DO13              HardConf[680]  //模块n输出点                              DO
#define Hard_E5DO14              HardConf[681]  //模块n输出点                              DO
#define Hard_E5DO15              HardConf[682]  //模块n输出点                              DO
#define Hard_E5DO16              HardConf[683]  //模块n输出点                              DO
#define Hard_E5DA01              HardConf[684]  //模块n DA输出                            U32
#define Hard_E5DA02              HardConf[685]  //模块n DA输出                            U32
#define Hard_E5DA03              HardConf[686]  //模块n DA输出                            U32
#define Hard_E5DA04              HardConf[687]  //模块n DA输出                            U32
#define Hard_E5DA05              HardConf[688]  //模块n DA输出                            U32
#define Hard_E5DA06              HardConf[689]  //模块n DA输出                            U32
#define Hard_E5DA07              HardConf[690]  //模块n DA输出                            U32
#define Hard_E5DA08              HardConf[691]  //模块n DA输出                            U32
#define Hard_E5HAD01             HardConf[692]  //模块n HAD输入                           U32
#define Hard_E5HAD02             HardConf[693]  //模块n HAD输入                           U32
#define Hard_E5HAD03             HardConf[694]  //模块n HAD输入                           U32
#define Hard_E5HAD04             HardConf[695]  //模块n HAD输入                           U32
#define Hard_E5HAD05             HardConf[696]  //模块n HAD输入                           U32
#define Hard_E5HAD06             HardConf[697]  //模块n HAD输入                           U32
#define Hard_E5HAD07             HardConf[698]  //模块n HAD输入                           U32
#define Hard_E5HAD08             HardConf[699]  //模块n HAD输入                           U32
#define Hard_E5LAD01             HardConf[700]  //模块n LAD输入                           U32
#define Hard_E5LAD02             HardConf[701]  //模块n LAD输入                           U32
#define Hard_E5LAD03             HardConf[702]  //模块n LAD输入                           U32
#define Hard_E5LAD04             HardConf[703]  //模块n LAD输入                           U32
#define Hard_E5LAD05             HardConf[704]  //模块n LAD输入                           U32
#define Hard_E5LAD06             HardConf[705]  //模块n LAD输入                           U32
#define Hard_E5LAD07             HardConf[706]  //模块n LAD输入                           U32
#define Hard_E5LAD08             HardConf[707]  //模块n LAD输入                           U32
#define Hard_E5LAD09             HardConf[708]  //模块n LAD输入                           U32
#define Hard_E5LAD10             HardConf[709]  //模块n LAD输入                           U32
#define Hard_E5LAD11             HardConf[710]  //模块n LAD输入                           U32
#define Hard_E5LAD12             HardConf[711]  //模块n LAD输入                           U32
#define Hard_E5LAD13             HardConf[712]  //模块n LAD输入                           U32
#define Hard_E5LAD14             HardConf[713]  //模块n LAD输入                           U32
#define Hard_E5LAD15             HardConf[714]  //模块n LAD输入                           U32
#define Hard_E5LAD16             HardConf[715]  //模块n LAD输入                           U32
#define Hard_E5CNT01             HardConf[716]  //模块n计数输入                             U32
#define Hard_E5CNT02             HardConf[717]  //模块n计数输入                             U32
#define Hard_E5CNT03             HardConf[718]  //模块n计数输入                             U32
#define Hard_E5CNT04             HardConf[719]  //模块n计数输入                             U32
#define Hard_E5CNT05             HardConf[720]  //模块n计数输入                             U32
#define Hard_E5CNT06             HardConf[721]  //模块n计数输入                             U32
#define Hard_E5CNT07             HardConf[722]  //模块n计数输入                             U32
#define Hard_E5CNT08             HardConf[723]  //模块n计数输入                             U32
#define Hard_724                 HardConf[724]  //                                    U32
#define Hard_725                 HardConf[725]  //                                    U32
#define Hard_726                 HardConf[726]  //                                    U32
#define Hard_727                 HardConf[727]  //                                    U32
#define Hard_728                 HardConf[728]  //                                    U32
#define Hard_729                 HardConf[729]  //                                    U32
#define Hard_730                 HardConf[730]  //                                    U32
#define Hard_731                 HardConf[731]  //                                    U32
#define Hard_E6DI01              HardConf[732]  //模块n输入点                              DI
#define Hard_E6DI02              HardConf[733]  //模块n输入点                              DI
#define Hard_E6DI03              HardConf[734]  //模块n输入点                              DI
#define Hard_E6DI04              HardConf[735]  //模块n输入点                              DI
#define Hard_E6DI05              HardConf[736]  //模块n输入点                              DI
#define Hard_E6DI06              HardConf[737]  //模块n输入点                              DI
#define Hard_E6DI07              HardConf[738]  //模块n输入点                              DI
#define Hard_E6DI08              HardConf[739]  //模块n输入点                              DI
#define Hard_E6DI09              HardConf[740]  //模块n输入点                              DI
#define Hard_E6DI10              HardConf[741]  //模块n输入点                              DI
#define Hard_E6DI11              HardConf[742]  //模块n输入点                              DI
#define Hard_E6DI12              HardConf[743]  //模块n输入点                              DI
#define Hard_E6DI13              HardConf[744]  //模块n输入点                              DI
#define Hard_E6DI14              HardConf[745]  //模块n输入点                              DI
#define Hard_E6DI15              HardConf[746]  //模块n输入点                              DI
#define Hard_E6DI16              HardConf[747]  //模块n输入点                              DI
#define Hard_E6DO01              HardConf[748]  //模块n输出点                              DO
#define Hard_E6DO02              HardConf[749]  //模块n输出点                              DO
#define Hard_E6DO03              HardConf[750]  //模块n输出点                              DO
#define Hard_E6DO04              HardConf[751]  //模块n输出点                              DO
#define Hard_E6DO05              HardConf[752]  //模块n输出点                              DO
#define Hard_E6DO06              HardConf[753]  //模块n输出点                              DO
#define Hard_E6DO07              HardConf[754]  //模块n输出点                              DO
#define Hard_E6DO08              HardConf[755]  //模块n输出点                              DO
#define Hard_E6DO09              HardConf[756]  //模块n输出点                              DO
#define Hard_E6DO10              HardConf[757]  //模块n输出点                              DO
#define Hard_E6DO11              HardConf[758]  //模块n输出点                              DO
#define Hard_E6DO12              HardConf[759]  //模块n输出点                              DO
#define Hard_E6DO13              HardConf[760]  //模块n输出点                              DO
#define Hard_E6DO14              HardConf[761]  //模块n输出点                              DO
#define Hard_E6DO15              HardConf[762]  //模块n输出点                              DO
#define Hard_E6DO16              HardConf[763]  //模块n输出点                              DO
#define Hard_E6DA01              HardConf[764]  //模块n DA输出                            U32
#define Hard_E6DA02              HardConf[765]  //模块n DA输出                            U32
#define Hard_E6DA03              HardConf[766]  //模块n DA输出                            U32
#define Hard_E6DA04              HardConf[767]  //模块n DA输出                            U32
#define Hard_E6DA05              HardConf[768]  //模块n DA输出                            U32
#define Hard_E6DA06              HardConf[769]  //模块n DA输出                            U32
#define Hard_E6DA07              HardConf[770]  //模块n DA输出                            U32
#define Hard_E6DA08              HardConf[771]  //模块n DA输出                            U32
#define Hard_E6HAD01             HardConf[772]  //模块n HAD输入                           U32
#define Hard_E6HAD02             HardConf[773]  //模块n HAD输入                           U32
#define Hard_E6HAD03             HardConf[774]  //模块n HAD输入                           U32
#define Hard_E6HAD04             HardConf[775]  //模块n HAD输入                           U32
#define Hard_E6HAD05             HardConf[776]  //模块n HAD输入                           U32
#define Hard_E6HAD06             HardConf[777]  //模块n HAD输入                           U32
#define Hard_E6HAD07             HardConf[778]  //模块n HAD输入                           U32
#define Hard_E6HAD08             HardConf[779]  //模块n HAD输入                           U32
#define Hard_E6LAD01             HardConf[780]  //模块n LAD输入                           U32
#define Hard_E6LAD02             HardConf[781]  //模块n LAD输入                           U32
#define Hard_E6LAD03             HardConf[782]  //模块n LAD输入                           U32
#define Hard_E6LAD04             HardConf[783]  //模块n LAD输入                           U32
#define Hard_E6LAD05             HardConf[784]  //模块n LAD输入                           U32
#define Hard_E6LAD06             HardConf[785]  //模块n LAD输入                           U32
#define Hard_E6LAD07             HardConf[786]  //模块n LAD输入                           U32
#define Hard_E6LAD08             HardConf[787]  //模块n LAD输入                           U32
#define Hard_E6LAD09             HardConf[788]  //模块n LAD输入                           U32
#define Hard_E6LAD10             HardConf[789]  //模块n LAD输入                           U32
#define Hard_E6LAD11             HardConf[790]  //模块n LAD输入                           U32
#define Hard_E6LAD12             HardConf[791]  //模块n LAD输入                           U32
#define Hard_E6LAD13             HardConf[792]  //模块n LAD输入                           U32
#define Hard_E6LAD14             HardConf[793]  //模块n LAD输入                           U32
#define Hard_E6LAD15             HardConf[794]  //模块n LAD输入                           U32
#define Hard_E6LAD16             HardConf[795]  //模块n LAD输入                           U32
#define Hard_E6CNT01             HardConf[796]  //模块n计数输入                             U32
#define Hard_E6CNT02             HardConf[797]  //模块n计数输入                             U32
#define Hard_E6CNT03             HardConf[798]  //模块n计数输入                             U32
#define Hard_E6CNT04             HardConf[799]  //模块n计数输入                             U32
#define Hard_E6CNT05             HardConf[800]  //模块n计数输入                             U32
#define Hard_E6CNT06             HardConf[801]  //模块n计数输入                             U32
#define Hard_E6CNT07             HardConf[802]  //模块n计数输入                             U32
#define Hard_E6CNT08             HardConf[803]  //模块n计数输入                             U32
#define Hard_804                 HardConf[804]  //                                    U32
#define Hard_805                 HardConf[805]  //                                    U32
#define Hard_806                 HardConf[806]  //                                    U32
#define Hard_807                 HardConf[807]  //                                    U32
#define Hard_808                 HardConf[808]  //                                    U32
#define Hard_809                 HardConf[809]  //                                    U32
#define Hard_810                 HardConf[810]  //                                    U32
#define Hard_811                 HardConf[811]  //                                    U32
#define Hard_812                 HardConf[812]  //                                    U32
#define Hard_813                 HardConf[813]  //                                    U32
#define Hard_814                 HardConf[814]  //                                    U32
#define Hard_815                 HardConf[815]  //                                    U32
#define Hard_816                 HardConf[816]  //                                    U32
#define Hard_817                 HardConf[817]  //                                    U32
#define Hard_818                 HardConf[818]  //                                    U32
#define Hard_819                 HardConf[819]  //                                    U32
#define Hard_820                 HardConf[820]  //                                    U32
#define Hard_821                 HardConf[821]  //                                    U32
#define Hard_822                 HardConf[822]  //                                    U32
#define Hard_823                 HardConf[823]  //                                    U32
#define Hard_824                 HardConf[824]  //                                    U32
#define Hard_825                 HardConf[825]  //                                    U32
#define Hard_826                 HardConf[826]  //                                    U32
#define Hard_827                 HardConf[827]  //                                    U32
#define Hard_828                 HardConf[828]  //                                    U32
#define Hard_829                 HardConf[829]  //                                    U32
#define Hard_830                 HardConf[830]  //                                    U32
#define Hard_831                 HardConf[831]  //                                    U32
#define Hard_832                 HardConf[832]  //                                    U32
#define Hard_833                 HardConf[833]  //                                    U32
#define Hard_834                 HardConf[834]  //                                    U32
#define Hard_835                 HardConf[835]  //                                    U32
#define Hard_836                 HardConf[836]  //                                    U32
#define Hard_837                 HardConf[837]  //                                    U32
#define Hard_838                 HardConf[838]  //                                    U32
#define Hard_839                 HardConf[839]  //                                    U32
#define Hard_840                 HardConf[840]  //                                    U32
#define Hard_841                 HardConf[841]  //                                    U32
#define Hard_842                 HardConf[842]  //                                    U32
#define Hard_843                 HardConf[843]  //                                    U32
#define Hard_844                 HardConf[844]  //                                    U32
#define Hard_845                 HardConf[845]  //                                    U32
#define Hard_846                 HardConf[846]  //                                    U32
#define Hard_847                 HardConf[847]  //                                    U32
#define Hard_848                 HardConf[848]  //                                    U32
#define Hard_849                 HardConf[849]  //                                    U32
#define Hard_850                 HardConf[850]  //                                    U32
#define Hard_851                 HardConf[851]  //                                    U32
#define Hard_852                 HardConf[852]  //                                    U32
#define Hard_853                 HardConf[853]  //                                    U32
#define Hard_854                 HardConf[854]  //                                    U32
#define Hard_855                 HardConf[855]  //                                    U32
#define Hard_856                 HardConf[856]  //                                    U32
#define Hard_857                 HardConf[857]  //                                    U32
#define Hard_858                 HardConf[858]  //                                    U32
#define Hard_859                 HardConf[859]  //                                    U32
#define Hard_860                 HardConf[860]  //                                    U32
#define Hard_861                 HardConf[861]  //                                    U32
#define Hard_862                 HardConf[862]  //                                    U32
#define Hard_863                 HardConf[863]  //                                    U32
#define Hard_864                 HardConf[864]  //                                    U32
#define Hard_865                 HardConf[865]  //                                    U32
#define Hard_866                 HardConf[866]  //                                    U32
#define Hard_867                 HardConf[867]  //                                    U32
#define Hard_868                 HardConf[868]  //                                    U32
#define Hard_869                 HardConf[869]  //                                    U32
#define Hard_870                 HardConf[870]  //                                    U32
#define Hard_871                 HardConf[871]  //                                    U32
#define Hard_872                 HardConf[872]  //                                    U32
#define Hard_873                 HardConf[873]  //                                    U32
#define Hard_874                 HardConf[874]  //                                    U32
#define Hard_875                 HardConf[875]  //                                    U32
#define Hard_876                 HardConf[876]  //                                    U32
#define Hard_877                 HardConf[877]  //                                    U32
#define Hard_878                 HardConf[878]  //                                    U32
#define Hard_879                 HardConf[879]  //                                    U32
#define Hard_880                 HardConf[880]  //                                    U32
#define Hard_881                 HardConf[881]  //                                    U32
#define Hard_882                 HardConf[882]  //                                    U32
#define Hard_883                 HardConf[883]  //                                    U32
#define Hard_884                 HardConf[884]  //                                    U32
#define Hard_885                 HardConf[885]  //                                    U32
#define Hard_886                 HardConf[886]  //                                    U32
#define Hard_887                 HardConf[887]  //                                    U32
#define Hard_888                 HardConf[888]  //                                    U32
#define Hard_889                 HardConf[889]  //                                    U32
#define Hard_890                 HardConf[890]  //                                    U32
#define Hard_891                 HardConf[891]  //                                    U32
#define Hard_892                 HardConf[892]  //                                    U32
#define Hard_893                 HardConf[893]  //                                    U32
#define Hard_894                 HardConf[894]  //                                    U32
#define Hard_895                 HardConf[895]  //                                    U32
#define Hard_896                 HardConf[896]  //                                    U32
#define Hard_897                 HardConf[897]  //                                    U32
#define Hard_898                 HardConf[898]  //                                    U32
#define Hard_899                 HardConf[899]  //                                    U32
#define Hard_900                 HardConf[900]  //                                    U32
#define Hard_901                 HardConf[901]  //                                    U32
#define Hard_902                 HardConf[902]  //                                    U32
#define Hard_903                 HardConf[903]  //                                    U32
#define Hard_904                 HardConf[904]  //                                    U32
#define Hard_905                 HardConf[905]  //                                    U32
#define Hard_906                 HardConf[906]  //                                    U32
#define Hard_907                 HardConf[907]  //                                    U32
#define Hard_908                 HardConf[908]  //                                    U32
#define Hard_909                 HardConf[909]  //                                    U32
#define Hard_910                 HardConf[910]  //                                    U32
#define Hard_911                 HardConf[911]  //                                    U32
#define Hard_912                 HardConf[912]  //                                    U32
#define Hard_913                 HardConf[913]  //                                    U32
#define Hard_914                 HardConf[914]  //                                    U32
#define Hard_915                 HardConf[915]  //                                    U32
#define Hard_916                 HardConf[916]  //                                    U32
#define Hard_917                 HardConf[917]  //                                    U32
#define Hard_918                 HardConf[918]  //                                    U32
#define Hard_919                 HardConf[919]  //                                    U32
#define Hard_920                 HardConf[920]  //                                    U32
#define Hard_921                 HardConf[921]  //                                    U32
#define Hard_922                 HardConf[922]  //                                    U32
#define Hard_923                 HardConf[923]  //                                    U32
#define Hard_924                 HardConf[924]  //                                    U32
#define Hard_925                 HardConf[925]  //                                    U32
#define Hard_926                 HardConf[926]  //                                    U32
#define Hard_927                 HardConf[927]  //                                    U32
#define Hard_928                 HardConf[928]  //                                    U32
#define Hard_929                 HardConf[929]  //                                    U32
#define Hard_930                 HardConf[930]  //                                    U32
#define Hard_931                 HardConf[931]  //                                    U32
#define Hard_932                 HardConf[932]  //                                    U32
#define Hard_933                 HardConf[933]  //                                    U32
#define Hard_934                 HardConf[934]  //                                    U32
#define Hard_935                 HardConf[935]  //                                    U32
#define Hard_936                 HardConf[936]  //                                    U32
#define Hard_937                 HardConf[937]  //                                    U32
#define Hard_938                 HardConf[938]  //                                    U32
#define Hard_939                 HardConf[939]  //                                    U32
#define Hard_940                 HardConf[940]  //                                    U32
#define Hard_941                 HardConf[941]  //                                    U32
#define Hard_942                 HardConf[942]  //                                    U32
#define Hard_943                 HardConf[943]  //                                    U32
#define Hard_944                 HardConf[944]  //                                    U32
#define Hard_945                 HardConf[945]  //                                    U32
#define Hard_946                 HardConf[946]  //                                    U32
#define Hard_947                 HardConf[947]  //                                    U32
#define Hard_948                 HardConf[948]  //                                    U32
#define Hard_949                 HardConf[949]  //                                    U32
#define Hard_950                 HardConf[950]  //                                    U32
#define Hard_951                 HardConf[951]  //                                    U32
#define Hard_952                 HardConf[952]  //                                    U32
#define Hard_953                 HardConf[953]  //                                    U32
#define Hard_954                 HardConf[954]  //                                    U32
#define Hard_955                 HardConf[955]  //                                    U32
#define Hard_956                 HardConf[956]  //                                    U32
#define Hard_957                 HardConf[957]  //                                    U32
#define Hard_958                 HardConf[958]  //                                    U32
#define Hard_959                 HardConf[959]  //                                    U32
#define Hard_960                 HardConf[960]  //                                    U32
#define Hard_961                 HardConf[961]  //                                    U32
#define Hard_962                 HardConf[962]  //                                    U32
#define Hard_963                 HardConf[963]  //                                    U32
#define Hard_964                 HardConf[964]  //                                    U32
#define Hard_965                 HardConf[965]  //                                    U32
#define Hard_966                 HardConf[966]  //                                    U32
#define Hard_967                 HardConf[967]  //                                    U32
#define Hard_968                 HardConf[968]  //                                    U32
#define Hard_969                 HardConf[969]  //                                    U32
#define Hard_970                 HardConf[970]  //                                    U32
#define Hard_971                 HardConf[971]  //                                    U32
#define Hard_972                 HardConf[972]  //                                    U32
#define Hard_973                 HardConf[973]  //                                    U32
#define Hard_974                 HardConf[974]  //                                    U32
#define Hard_975                 HardConf[975]  //                                    U32
#define Hard_976                 HardConf[976]  //                                    U32
#define Hard_977                 HardConf[977]  //                                    U32
#define Hard_978                 HardConf[978]  //                                    U32
#define Hard_979                 HardConf[979]  //                                    U32
#define Hard_980                 HardConf[980]  //                                    U32
#define Hard_981                 HardConf[981]  //                                    U32
#define Hard_982                 HardConf[982]  //                                    U32
#define Hard_983                 HardConf[983]  //                                    U32
#define Hard_984                 HardConf[984]  //                                    U32
#define Hard_985                 HardConf[985]  //                                    U32
#define Hard_986                 HardConf[986]  //                                    U32
#define Hard_987                 HardConf[987]  //                                    U32
#define Hard_988                 HardConf[988]  //                                    U32
#define Hard_989                 HardConf[989]  //                                    U32
#define Hard_990                 HardConf[990]  //                                    U32
#define Hard_991                 HardConf[991]  //                                    U32
#define Hard_992                 HardConf[992]  //                                    U32
#define Hard_993                 HardConf[993]  //                                    U32
#define Hard_994                 HardConf[994]  //                                    U32
#define Hard_995                 HardConf[995]  //                                    U32
#define Hard_996                 HardConf[996]  //                                    U32
#define Hard_997                 HardConf[997]  //                                    U32
#define Hard_998                 HardConf[998]  //                                    U32
#define Hard_999                 HardConf[999]  //                                    U32
#define Hard_1000                HardConf[1000] //                                    U32
#define Hard_1001                HardConf[1001] //                                    U32
#define Hard_1002                HardConf[1002] //                                    U32
#define Hard_1003                HardConf[1003] //                                    U32
#define Hard_1004                HardConf[1004] //                                    U32
#define Hard_1005                HardConf[1005] //                                    U32
#define Hard_1006                HardConf[1006] //                                    U32
#define Hard_1007                HardConf[1007] //                                    U32
#define Hard_1008                HardConf[1008] //                                    U32
#define Hard_1009                HardConf[1009] //                                    U32
#define Hard_1010                HardConf[1010] //                                    U32
#define Hard_1011                HardConf[1011] //                                    U32
#define Hard_1012                HardConf[1012] //                                    U32
#define Hard_1013                HardConf[1013] //                                    U32
#define Hard_1014                HardConf[1014] //                                    U32
#define Hard_1015                HardConf[1015] //                                    U32
#define Hard_1016                HardConf[1016] //                                    U32
#define Hard_1017                HardConf[1017] //                                    U32
#define Hard_1018                HardConf[1018] //                                    U32
#define Hard_1019                HardConf[1019] //                                    U32
#define Hard_1020                HardConf[1020] //                                    U32
#define Hard_1021                HardConf[1021] //                                    U32
#define Hard_1022                HardConf[1022] //                                    U32
#define Hard_1023                HardConf[1023] //                                    U32

#endif
