#ifndef Include_h 
	#define Include_h
	
	//#include <stdio.h>
	//#include <string.h>
	
	#include "AuxDef.h"				//常用宏、数据类型定义
	#include "SysDef.h"				//系统宏定义
	#include "Fun.h"					//功能函数
	
	#include "gd32f4xx.h"
	//#include "SysInit.h" 

	#include "Boot_IAP.h"				//BOOT、IAP、REMAP
	#include "License.h"				//License

	#include "CMWMDef.h"			//主机、界面共用宏定义
	#include "RPHA.h"			//RPHA
	#include "CM_Resource.h"		//资源
	#include "CM_HardConf.h"		//硬件配置
	#include "CM_WorkState.h"	//工作状态
	#include "CM_MachPara.h"		//机器参数
	#include "CM_PeriPara.h"		//外设参数
	#include "CM_ManuPara.h"		//生产参数
	#include "CM_Alarm.h"			//警报定义
	#include "CM_ActDisp.h"		//动作显示定义
	
	//驱动
	#include "WDT_Drv.h"				//看门狗驱动
	#include "IIC_Drv.h"				//IIC驱动
	//#include "Mpu_Drv.h"				//存储保护单元驱动
	#include "Time_Drv.h"				//时间驱动
	#include "SimBus_Drv.h"			//模拟总线驱动
	#include "HardPlat_Drv.h"		//硬件平台驱动
	#include "DigiLed_Drv.h"		//数码LED驱动
	#include "DIDO_Drv.h"				//IO驱动
	#include "HADC_Drv.h"				//HADC驱动
	#include "MADC_Drv.h"				//MADC驱动
	#include "LADC_Drv.h"				//LADC驱动 
	#include "DAC_Drv.h"				//DAC驱动
	#include "Comm_Drv.h"				//通讯驱动
	//#include "RS485_Drv.h"			//485驱动
	//#include "Wave485_Drv.h"			//485波形硬件驱动
	#include "Can_Drv.h"				//CAN驱动
	#include "CanModule_Drv.h"		//CAN模块驱动
	//#include "Enet_Drv.h"			//以太网驱动
	//#include "Ecat_Drv.h"			//EtherCAT驱动
	#include "HCIS300SD_Drv.h"		//汇川伺服驱动器驱动
	#include "ModrolSD_Drv.h"			//蒙德伺服驱动器驱动		20210608
    #include "Enet_Drv.h"			//以太网驱动
	#include "Ecat_Drv.h"			//EtherCAT驱动
	#include "License_Drv.h"			//License驱动
	//#include "PropValCurrMeas_Drv.h"	//比例阀电流测量驱动
	#include "J5_PID_Drv.h"				//J5多组PID
	#include "KWhMeter_Drv.h"			//电表			20150611 
	//#include "J6_Drv.h"         //J6卡驱动
	//#include "CanForward_Drv.h"		//20170705		增加界面与CBox之间数据传送，由主机通过CAN口转发功能
	#include "CanOpen_Drv.h"		//CANOpen驱动
	#include "TDSD_Drv.h"			//TDSD台达伺服驱动
	#include "ESSD_Drv.h"			//ESSD台达伺服驱动
	#include "EuRaSD_Drv.h"		//伺服驱动
	#include "VEICHISD_Drv.h"		//伟创伺服驱动
	#include "HiLectroSD_Drv.h"	//海天伺服驱动
	#include "HiLectroM6_Drv.h"	//海天M6卡
	#include "RobotCommunication_Drv.h"	//海天M6卡
	
	//内核
	#include "Scheduler.h"			//调度
	#include "Action.h"				//动作
	#include "main.h"					//
	
	#include "Position.h"				//电子尺
	#include "Temp.h"					//温度
	#include "Alarm.h"				//警报
	#include "Monitor.h"				//监测
	#include "Code.h"					//指令
	#include "Wave.h"					//波形
	#include "HAI.h"					//模拟量		如实时注射压力、锁模压力测量等
	#include "DateTime.h"				//日期时间		20150609
	
	//动作
	#include "ActConf.h"				//动作配置	
	#include "MoldOpenClsAlg.h"	
	
	//注：其它动作的.h文件由ActConf_xx.h文件根据机器类别等情况按需包含

#endif 
