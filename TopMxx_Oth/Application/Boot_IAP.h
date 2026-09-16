/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：Boot_IAP.h
文件说明：部分基础函数。

作    者：WLZ
编写时间：2017.09
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================


****************************************************************************************************/
#ifndef Boot_IAP_h
	#define Boot_IAP_h


#ifdef Boot_IAP_c
	#define Boot_IAP_ext 
#else
	#define Boot_IAP_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/

//空间地址分配
#define mBootCodeAddr				0x08000000			//Boot程序开始地址				Flash
#define mBootCodeSize				0x8000				//            长度						32K

#define mAppMessAddr				0x08008000			//应用程序信息开始地址			Flash
#define mAppMessSize				0x8000				//                长度  				32K

#define mAppCodeAddr				0x08010000			//应用程序开始地址				Flash
#define mAppCodeSize				0x70000				//            长度          			448K

#define mAppIntVectTabSrcAddr		mAppCodeAddr		//应用程序中断向量表源地址		Flash
#define mAppIntVectTabDsrAddr		0x20000000			//应用程序中断向量表目的地址			SRAM
#define mAppIntVectTabSize			496					//应用程序中断向量表长度

#define mAppSRAMAddr				0x20000200			//应用程序SRAM开始地址			SRAM	64*1024-256-16

#define mAppMainFunAddr				(*((U32 *)(mAppCodeAddr+4)))	//应用程序主函数入口地址
//注：由于Cortex-M7核采用的是中断向量表机制，因此入口地址不是PC复位值(0x0004)，实际上是*PC(该地址内容对应的数据)
//    Cortex-M7中断向量表机制：向量表中存放跳转地址，中断产生时读取表中地址到PC，即跳转到中断函数，中断号与向量表地址对应
//    ARM核中断机制：向量表中存放的是代码，中断时直接执行向量中的相应代码，即跳转到中断函数

#define mFMSA_MachParaUnRst			0x0000				//参数未重置
	#define mMachParaRstCode			0x5869				//参数已经重置代码

//扇区分配
#define mSTM32F7xx_AppCodeMessSec	1					//应用程序信息扇区				Flash
#define mSTM32F7xx_AppCodeStartSec	2					//应用程序启始扇区				Flash
#define mSTM32F7xx_AppCodeEndSec	5					//应用程序结束扇区				Flash

#define mCommBlockSize				1024				//通讯块长度

//特殊变量定义
#define mMem_AppValidCodeAddr		0x08008FF0
#define mMem_AppCodeSizeAddr		0x08008FF4
#define mMem_AppCodeChkSumAddr		0x08008FF8

#define Mem_CMAppCode				*((U32 *)(mAppCodeAddr+0x02FC))	//主机应用程序有效特殊代码	定义在.s文件中
	#define mCMAppCode					0x35483654						//有效特殊代码			即"T6H5"的ASCII码
#define Mem_AppValidCode			*((U32 *)mMem_AppValidCodeAddr)	//应用程序有效特殊代码
	#define mAppValidCode				0x11223344						//有效特殊代码
#define Mem_AppCodeSize				*((U32 *)mMem_AppCodeSizeAddr)	//应用程序长度
#define Mem_AppCodeChkSum			*((U32 *)mMem_AppCodeChkSumAddr)//应用程序校验和

#define Mem_BootState				*((U32 *)0x20000000)			//Boot状态
	#define mBS_BootNor					0x5858F001						//Boot正常启动后跳转应用程序
	#define mBS_BootReturn				0x5858F002						//Boot收到退出指令
	#define mBS_ProgDnLdSucc			0x5858F003						//Boot程序升级成功后跳转应用程序
	#define mBS_AppToBoot				0x69690F08						//应用程序跳转Boot
#define Mem_BootVer					*((U32 *)0x20000004)			//Boot版本			指本Boot程序的版本，非器件内Boot Code的版本
#define Mem_PartSN					*((U32 *)0x20000008)			//器件流水号

#define GetBootVer()				Mem_BootVer						//获取Boot版本
/*======================================== 全局有效变量定义 =======================================*/

/*======================================== 全局有效函数声明 =======================================*/

#ifdef mT6H5_Basic		//用于T6F5_Basic工程
	void IntVectTabRemap(void);			//中断向量表重映射			必须在中断开启前调用执行
	void Boot_IAP_Pcs(void);			//Boot_IAP相关处理
#endif

#ifdef mT6H5_Boot_IAP	//用于T6F5_Boot_IAP工程
	Boot_IAP_ext U16 Boot_IAP_Step;	//步骤
		#define mBIS_Start		0		//刚开始
		#define mBIS_Erase		1		//擦除
		#define mBIS_Program	2		//写入
		#define mBIS_ReadHead	3		//读取头
		#define mBIS_ReadProg	4		//读取程序
	Boot_IAP_ext Bool AppErrFlag;	//App异常标志
	Boot_IAP_ext U16 Boot_IAP_Mess;	//提示信息
		#define mMess_AppErr		20	//主机程序无效			同CM_Alarm.h中mAlarm_CMBootModeAppErr
		#define mMess_WaitCode		21	//Boot模式等待指令		同CM_Alarm.h中mAlarm_CMBootModeAWaitCode
		
	#define mWorkState_Prompt		9	//工作状态提示变量序号	同CM_WorkState.h中State_Prompt
	#define mWorkState_SysMode		5	//工作状态	工作模式序号	同CM_WorkState.h中State_SysMode
		#define mMode_Boot				8	//Boot模式				与CMWMDef.h中定义一致，注意同步更改
	#define mWorkState_BootVer		378	//工作状态	Boot版本序号	同CM_WorkState.h中State_CMBootVer
		

	void BootInit(void);							//Boot初始处理
	void Boot_IAP_Pcs(void);						//Boot_IAP处理

	U8 Boot_IAP_Startup(void);						//启动Boot模式
	U8 Boot_IAP_Return(void);						//退出Boot模式
	U8 Boot_IAP_Erase(U32 CodeSize);				//擦除
	U8 Boot_IAP_Program(U16 BlockSN,U8 *ProgDataP);	//编程

		#define mAOR_UnErase		0xE0	//程序尚未擦除		下载指令时
		#define mAOR_SizeOL			0xE1	//程序长度溢出		擦除指令时
		#define mAOR_BolckSNErr		0xE2	//程序块序号出错	下载、读取指令时
		#define mAOR_AppErr			0xE3	//无有效应用程序	读取头、读取指令时
	
#endif

#endif
