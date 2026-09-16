/* Copyright (C) 2019 *****************************************************************************
                                     杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：main.c
文件说明：主函数文件

作    者：LC
编写时间：2019.9
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================


****************************************************************************************************/
#define mSysDebug                

#ifndef Main_c
    #define Main_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/

#ifdef mProgDebug            //程序调试            WDT不开启
    #define mCycTimeMeas    1    //测量循环时间
    #define mResMaxMinMeas    mRU_HAI1AD    //测量某个资源最大与最小值 

#endif                                    
/*======================================= 模块内有效变量定义 ======================================*/


/*======================================= 模块内有效函数声明 ======================================*/


/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug    


//允许测量资源的最大与最小值
#ifdef mResMaxMinMeas
    U32 ResMax=0,ResMin=0xffffffff; 
    G10usTimer ResMeasTimer;
#endif

/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：0、M0映像检查不匹配   1、M0映像检查匹配   
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
int main(void)
{    
    /*****以下调试数据*****/
    #ifdef mProgDebug            //程序调试
        
        State_CMSoftVer=9999;        //识别调试版本用
        
    //--------------------------------
    #endif
    /*****以上调试数据*****/     
    clock_output_config();        //时钟输出
    IntVectTabRemap();    //中断向量表重映射  Boot_IAP.c        
    //CanRS485_IO_Init();            //CAN和RS485默认IO初始化    Can_Drv.c
    Time_Drv_Init();            //时间驱动初始化        Time_Drv.c                执行顺序固定
    I2Cx_Drv_Init();            //I2C总线初始化        I2C_Drv.c                执行顺序固定
    SimBus_Drv_Init();            //模拟总线初始化        SimBus_Drv.c            执行顺序固定
    HardPlat_Drv_Init();        //硬件平台初始化        HardPlat_Drv.c            执行顺序固定
    RPHA_Init();                //RPHA初始化            RPHA.c                    执行顺序固定

    DigiLed_Init();                //数码LED初始化        DigiLed_Drv.c
    DIDO_Drv_Init();            //DIDO驱动初始化        DIDO_Drv.c
    DAC_Drv_Init();                //DAC驱动初始化        DAC_Drv.c
    HADC_Drv_Init();            //HADC驱动初始化        HADC_Drv.c
    MADC_Drv_Init();            //MADC驱动初始化        MADC_Drv.c            20171203
    LADC_Drv_Init();            //LADC驱动初始化        LADC_Drv.c
    //HCIS300SDT_Drv_Init();        //汇川驱动器初始化    HCIS300SDT_Drv.c    20210816        必须在CanModule_Drv_Init()前初始化，否则FullCAN无法开启
    CanModule_Drv_Init();        //CAN模块初始化        CanModule_Drv_Init.c
    //CanForward_Drv_Init();        //CAN数据转发初始化 CanForward_Drv.c        20170705    必须在CanModule_Drv_Init()之后，因FullCAN
    KWhMeter_Drv_Init();        //电表初始化        KWhMeter_Drv.c            20150611
    //Ecat_Drv_Init();      //EtherCAT初始化   Ecat_Drv.c
    
    Position_Init();            //位置初始化            Position.c
    Temp_Init();                //温度实始化            Temp.c
    
    HAI_Init();                    //模拟量初始化        HAI.c                    如注射压力、锁模压力测量等
    Wave_Init();                //波形初始化            Wave.c                    波形曲线相关处理
    DateTime_Init();            //日期时间初始化        DateTime.c            20150609
    
    Monitor_Init();                //监测初始化            Monitor.c
    Action_Init();                //动作初始化            Action.c
    Scheduler_Init();            //调度初始化            Scheduler.c
    ActConf_Init();                //动作程序配置初始化    ActConf_xx.c            配置动作程序,依据机器类型、厂家等
    
    License_Init();                //License初始化        License.c
/*    J5_PID_Drv_Init();            //J5多组PID            J5_PID_Drv.c
*/
    Comm_Drv_Init();            //通讯驱动初始化        Comm_Drv.c                尽量靠后执行
    TDSD_Drv_Init();            //台达伺服驱动    
    ESSD_Drv_Init();            //艾普伺服驱动    
    EuRaSD_Drv_Init();            //伺服驱动
    VeiSD_Drv_Init();            //伟创驱动 
    HiSD_Drv_Init();            //海天伺服驱动
    HiM6_Drv_Init();            //海天MD6卡驱动
    RobotComm_Drv_Init();        //机械手通讯驱动
        
    EnWDT();                    //启动WDT            WDT_Drv.c
    
        /*****以下调试数据*****/
    #ifdef mProgDebug            //程序调试
       
        State_CMSoftVer=9999;        //识别调试版本用        
        
        /*if(CntData.WorkTime<500*24*3600)
        {
            CntData.WorkTime+=500*24*3600;
            CntDataSave();
        }*/
    #endif
    /*****以上调试数据*****/
    
    do{    
        /*****以下调试数据*****/
        #ifdef mProgDebug        //程序调试
            
        #endif
        /*****以上调试数据*****/        

        FeedWDT();                    //复位WDT                WDT_Drv.c        周期应小于10ms
        Comm_Drv_Pcs();                //通讯处理                Comm_Drv.c
        //Ecat_Drv_Pcs();                //EtherCAT驱动        
        HardPlat_Drv_Pcs();            //硬件平台处理            HardPlat_Drv.c    
        DigiLed_Pcs();                //数码LED显示处理        DigiLed_Drv.c    
        //if(FMSA_RstFlag==mTrue)        //未重置铁电    不执行外设
        {
            DIDO_Drv_Pcs();                //DIDO驱动处理            DIDO_Drv.c    
            RobotComm_Drv_Pcs();        //机械手通讯驱动处理    RobotComm_Drv.c        
            DAC_Drv_Pcs();                //DAC驱动处理            DAC_Drv.c        
            HADC_Drv_Pcs();                //HADC驱动处理            HADC_Drv.c
            MADC_Drv_Pcs();                //MADC驱动处理            MADC_Drv.c
            LADC_Drv_Pcs();                //LADC驱动处理            LADC_Drv.c
        }
        CanModule_Drv_Pcs();        //CAN模块处理            CanModule_Drv.c
        //CanForward_Drv_Pcs();        //CAN数据转发处理        CanForward_Drv.c    20170705
        //HCIS300SDT_Drv_Pcs();        //汇川驱动器处理        HCIS300SDT_Drv.c    20210816
        //J5_PID_Drv_Pcs();            //J5多组PID                J5_PID_Drv.c
        KWhMeter_Drv_Pcs();            //电表处理            KWhMeter_Drv.c            20150611
        CanOpenDrv_Pcs();            //CANOPEN驱动
        TDSD_Drv_Pcs();                //台达伺服驱动
        ESSD_Drv_Pcs();                //艾普伺服驱动
        EuRaSD_Drv_Pcs();            //伺服驱动
        VeiSD_Drv_Pcs();            //伟创驱动 
        HiSD_Drv_Pcs();                //海天伺服驱动
        HiM6_Drv_Pcs();                //海天M6卡驱动
        
        Temp_Pcs();                    //温度处理                Temp.c
        Position_Pcs();                //位置处理                Position.c
        HAI_Pcs();                    //模拟量处理                HAI.c            如注射压力、锁模压力测量等
        Wave_Pcs();                    //波形初始化                Wave.c            波形曲线相关处理
        RPHA_Pcs();                    //RPHA参数处理            RPHA.c            机器参数保存时，最长周期用时约460us（累加和计算并保存周期）
        DateTime_Pcs();                //日期时间处理            DateTime.c        20150609
        
        Monitor_Pcs();                //监测处理                Monitor.c
        Alarm_Pcs();                //警报处理                Alarm.c            
        Code_Pcs();                    //指令处理                Code.c            紧跟 Alarm_Pcs()后面

        Boot_IAP_Pcs();                //Boot相关处理            Boot_IAP.c
        License_Pcs();                //License处理            License.c
        
        Scheduler_Pcs();            //调度处理                Scheduler.c        
        Action_Pcs();                //动作处理                Action.c        
        ActConf_Pcs();                //动作程序处理            ActConf_xx.c    调用执行各动作监控等
        
        //测量循环时间        辅助
        #if mCycTimeMeas
            //if((CycCnt==0)||(!(State_DIn01_16&mBit0)))
            if(CycCnt==0)
            {
                CycTime_Max=0;
                CycTime_Min=0xffffffff;
                CycTime_Average=0;

                CycCnt=1;
                RunTimeMeas_10us(1);
                G10usTimerRes(&AverageTimer);
            }
            else
            {
                CycBuff=RunTimeMeas_10us(0)*10;
                if(CycBuff<20000)
                {    //循环时间不可能超出20ms，如果超出通常是调试中断，本次不计入
                    if(CycBuff>CycTime_Max)    CycTime_Max=CycBuff;
                    if(CycBuff<CycTime_Min)    CycTime_Min=CycBuff;

                    CycTime_Average=(U64)G10usTimerCal(&AverageTimer)*10/CycCnt;
                    CycCnt++;
                }
                RunTimeMeas_10us(1);
            }
        #endif
        //测量某一资源的最大与最小值，资源序号由mResMaxMinMeas指定，这个值为0则不测量        辅助
        #ifdef mResMaxMinMeas
            if(G10usTimerOver(&ResMeasTimer,T1sTo10us(30)) )
            {
                G10usTimerRes(&ResMeasTimer);
                ResMax=0,ResMin=0xffffffff; 
            }
            else
            {
                if(RdResU32(mResMaxMinMeas)>ResMax)            ResMax=RdResU32(mResMaxMinMeas);
                else if(RdResU32(mResMaxMinMeas)<ResMin)    ResMin=RdResU32(mResMaxMinMeas);
                
                //State_HAI1Value=ResMin,State_HAI2Value=ResMax;
                State_HAI1Value=ResMax-ResMin;
            }
        #endif
    }while(1); 
}

#endif  //mSysDebug

