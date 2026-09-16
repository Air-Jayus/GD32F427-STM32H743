/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：xxxxxx
文件说明：xxxxxx

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================



****************************************************************************************************/
#ifndef DAC_Drv_h
	#define DAC_Drv_h

#ifdef DAC_Drv_c
	#define DAC_Drv_ext
#else
	#define DAC_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/


/*======================================== 全局有效变量定义 =======================================*/
enum eDAC{eDAC_Null,eDAC_MainPres,eDAC_MainFlow,eDAC_BackPres,eDAC_MOFlow,eDAC_MCFlow,eDAC_SBFlow,eDAC_InjFlow,
	      eDAC_LinkPres,eDAC_LinkFlow,eDAC_SDLinkPres,eDAC_SDLinkFlow,eDAC_SetPID,eDAC_Pres2,eDAC_Flow2,eDAC_HoldPresRel,eDAC_InjectPres};
//OutRecTabStr.DAChan
//	eDAC_Null		无效
//	eDAC_MainPres	主压力阀
//	eDAC_MainFlow	主流量阀
//	eDAC_BackPres	背压阀
//	eDAC_MOFlow		开模阀（双向）	
//	eDAC_MCFlow		关模阀（双向）	
//	eDAC_SBFlow		射退阀（双向）
//	eDAC_InjFlow	注射阀（双向）	
//	eDAC_LinkPres	连动压力阀
//	eDAC_LinkFlow	连动流量阀
//	eDAC_SDLinkPres	伺服连动压力阀	与mPV_LinkPres区别：mPV_LinkPres在非连动动作时还当泵使用，相关程序在DAC_Pcs()中
//	eDAC_SDLinkFlow	伺服连动流量阀
//	eDAC_SetPID		J5-PID
//	eDAC_Pres2		压力阀2
//	eDAC_Flow2		流量阀2
//	eDAC_HoldPresRel保压溢流
//  eDAC_InjectPres	注射压力

//注：如果连动比例阀要并流当“泵”使用，则应选用eDAC_LinkPres，多用于类似定量泵的系统
//   如果连动比例阀是独立的，或由硬件电路完成并流的，则应选用eDAC_SDLinkPres，多用于伺服机（由硬件电路完成并流）

/*======================================== 全局有效函数声明 =======================================*/
void DAC_Drv_Init(void);		//DAC初始化
void DAC_Drv_Pcs(void);			//DAC处理		于主循环

void DADebugSetMode(U8 Mode);			//DA调试模式设置
Bool DADebugSetOut(U8 DAChan,U16 DAOut);	//DA调试输出设置
U32 GetDACDebugOut(U16 DACResSN);		//获取DA调试输出	主要由驱动器相关程序调用(如HCIS300SD_Drv.c)用以获取调试情况

void SetPV(enum eDAC Chan,U32 Out,U32 RampTime,U32 Scale);	//设置比例阀		通道可选

U16 GetDAChan_CurrDA(U8 Chan);			//获取指定硬件配置的当前DA值					20161122加
U32 GetDAChan_DAPercentage(U8 Chan);	//获取DA通道的输出PWM值其占空比(相对量程)		主要是PropValCurrMeas_Drv.c中引用
U32 GetDAChan_DAPer_001(U8 Chan);		//获取DA通道的输出PWM值其占空比(相对量程)		放大10000，即2位小数					20191212加
U32 GetPropVal_DstOut(enum eDAC Chan);	//获取比例阀的目标输出值						主要是AU_EjeRet.c、AU_EjeFor.c中引用	20120928加
U32 GetPropVal_CurrOut(enum eDAC Chan);	//获取比例阀的当前输出值  20200303

U8 GetPropVal_DAChan(U32 PropValRes);	//获取比例阀对应通道							20161122加

void SetPV_MoldClsFlow(U32 Flow,U32 RampTime,U32 Scale);	//设置比例阀		关模流量		-10V～+10V比例阀
void SetPV_MoldOpenFlow(U32 Flow,U32 RampTime,U32 Scale);	//设置比例阀		开模流量		-10V～+10V比例阀
//void SetPV_MainFlow_100(U32 Flow,U32 RampTime,U32 Scale);	//20171214加,与SetPV_MainFlow()的区别在于U32 Flow放大了100倍，精度更高，暂主要用于开模算法
//void SetPV_MainPres_100(U32 Pres,U32 RampTime,U32 Scale);	//20171214加,与SetPV_MainPres()的区别在于U32 Pres放大了100倍，精度更高，暂主要用于开模算法
void SetPV_MainPres(U32 Pres,U32 RampTime,U32 Scale);		//设置比例阀		主压力 20191024加，开模算法MoldOpenAlg.c中要用到
void SetPV_MainFlow(U32 Flow,U32 RampTime,U32 Scale);		//设置比例阀		主流量 20191024加，开模算法MoldOpenAlg.c中要用到

#endif
