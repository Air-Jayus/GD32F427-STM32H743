/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：DAC_Drv.c
文件说明：DAC驱动，包含压力/流量设置、斜率发生、电流曲线的转换，实际上是DAC驱动、比例阀驱动二合一。

作    者：WLZ
编写时间：2025.4
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
##系统资源
1、DAC由DAC124S085实现，共4个通道，12bit分辨率，DAC数据由CPU直接写到DAC芯片。
#define mDAC124S_SEL0		(0<<14)	//选择通道 0
#define mDAC124S_SEL1		(1<<14)	//选择通道 1
#define mDAC124S_SEL2		(2<<14)	//选择通道 2
#define mDAC124S_SEL3		(3<<14)	//选择通道 3

#define mDAC124S_SAL0		(2<<12)	//所有通道全部置 0 
#define mDAC124S_SIGM		(1<<12)	//每次更新一个通道 需配合通道

初始化首先将所有通道输出0，在每一个主循环更新一次输出值。利用中断发送后续数据

##其它说明
1、DAC124S085共4通道
	0通道   电压/电流输出
	1-3通道 0-10V电压输出
2、12位分辨率，串行总线时钟最高1MHz，本项目中使用的时钟频率为781.25KHz，更新一个通道需要16bit串行数据，即20.48us + 6ns。
3、本文件实际上是DAC驱动、比例阀驱动二合一，两者配合如下：
	比例阀驱动：设置压力、流量、斜率
				根据斜率，计算产生当前输出的压力、流量
				当前输出值写入资源中
	DAC驱动：	根据硬件配置，从对应资源读取输出
				根据曲线表，计算输出的DA值
				DA值更新到对应通道
	资源定义：	RU_PV_DAC1……RU_PV_DAC8		对应通道	输出值、最高位表示极性
	工作状态：	State_DAC1Out…State_DAC8Out	对应通道	高8位为通道限值、低8位为通道当前输出值

	注：1)DAC驱动与阀功能不相关，即无所谓压力、或流量比例阀
	    2)RU_PV_DAC1的最高位为极性位，为1即负输出
	    3)RU_PV_DAC1的含义与相应比例阀对应起来才有意义
				
4、本驱动在主循环中利用定时器进行斜率产生，与在定时器进行斜率产生比，线性度略差(很小)，但程序的独立性好、实
   时性好。
5、斜率算法有二，程序配置可选：
	1）斜率=最大值/斜率时间					特点：斜率是一致的、易调整、易计算实现
	2）斜率=（目标值-当前值）/斜率时间		特点：行业普遍使用，如宏讯；实际斜率随模具数据改变而改变
6、某个时刻的输出，通过计算获得，公式：当前值+斜率*时间。（T6F2是先计算出5ms的变化量，然后加、减变化量）
7、增加一路比例阀，需要增加内容有：
	Resource.h中增加比例阀资源定义；
	HardConf.h中将该资源关联到相应DA通道；
	本文件中增加PropVal类型变量定义；
	本文件中加入SetPV_XXX函数，设置输出值及斜率等；
	本文件中DA_Drv_Pcs()函数中，加入该通道的限值更新处理；
	DAC_Drv.h文件中，enum eDAC{}变量加入该PropVal的引用定义；

   一路DA通道，包含内容有：
	MachPara.h中比例阀曲线；
	本文件中DAChanStr结构中增加通道
	本文件中DA_Drv_2_5ms()函数中，加入该通道的PWM刷新输出。

	
???6-7通道双极性应用时：极性突变限制是否需要、输出关闭时极性是否要固定
???如果目标值未到（斜率引起）,设置新的输出值，现程序中：当前值做为新的起点，意味着斜率可能会不固定

****************************************************************************************************/
//#define mSysDebug		

#ifndef DAC_Drv_c
	#define DAC_Drv_c
#endif

#include "Include.h"
/*======================================= 模块内有效函数声明 ======================================*/
U16 PropVal_TranDAData(U8 TabNum,U32 * SetPointTab,U32 * DADataTab,U32 Range,U32 ValOut);	//比例阀DA数据转换

void SetPV_BackPres(U32 Pres,U32 RampTime,U32 Scale);		//设置比例阀		背压压力

void SetPV_InjectFlow(U32 Flow,U32 RampTime,U32 Scale);		//设置比例阀		注射流量		-10V～+10V比例阀
void SetPV_SuckBackFlow(U32 Flow,U32 RampTime,U32 Scale);	//设置比例阀		射退流量		-10V～+10V比例阀

void SetPV_LinkPres(U32 Pres,U32 RampTime,U32 Scale);		//设置比例阀		连动压力
void SetPV_LinkFlow(U32 Flow,U32 RampTime,U32 Scale);		//设置比例阀		连动流量

void SetPV_SDLinkPres(U32 Pres,U32 RampTime,U32 Scale);		//设置比例阀		伺服连动压力
void SetPV_SDLinkFlow(U32 Flow,U32 RampTime,U32 Scale);		//设置比例阀		伺服连动流量

void SetPV_SetPID(U32 Flow,U32 RampTime,U32 Scale);			//设置比例阀		J5-PID

void SetPV_Pres2(U32 Pres,U32 RampTime,U32 Scale);			//设置比例阀		压力2		20130504加，大机变量泵动力为“变量泵+定量泵”
void SetPV_Flow2(U32 Flow,U32 RampTime,U32 Scale);			//设置比例阀		流量2		20130504加，大机变量泵动力为“变量泵+定量泵”

void SetPV_HoldPresRel(U32 Pres,U32 RampTime,U32 Scale);	//设置比例阀		保压溢流	20130621加，双阶机长时间保压溢流用，防止油温过高

void SetPV_InjectPres(U32 Pres,U32 RampTime,U32 Scale);		//设置比例阀		注射压力	20130517加，天剑快速机用

void VarPumpQuanPumpSys_Pcs(void);							//变量泵+定量泵系统处理 		20130504加，大机变量泵动力为“变量泵+定量泵”
void PVHoldPresRel_Pcs(void);								//保压溢流阀处理				20140722加，应双阶机
void PVInjectPres_Pcs(void);								//注射压力比例阀处理			20130517加，天剑快速机用

/*======================================== 模块内有效宏定义 =======================================*/
//比例阀相关
#define mRM_TtoC		0		//斜率模式			(目标-起始)/时间
#define mRM_Range		1		//斜率模式			范围/时间

#define mRampCalPeriod	1*100	//斜率计算周期		即DA刷新间隔时间

#define mPropValNum		14		//比例阀数量


//DAC相关
#define mDACMaxNum		8		//最大DA通道数		实际使用通道数取决于HardConf_DANum

#define mDADataMax		4095	//DA最大值

//DAC124S相关
#define mDAC124S_SEL0		(0<<14)	//选择通道 0
#define mDAC124S_SEL1		(1<<14)	//选择通道 1
#define mDAC124S_SEL2		(2<<14)	//选择通道 2
#define mDAC124S_SEL3		(3<<14)	//选择通道 3

#define mDAC124S_SAL0		(2<<12)	//所有通道全部置 0 
#define mDAC124S_SIGM		(1<<12)	//每次更新一个通道 需配合通道
#define mDAC124MaxNum		4

#define DA124x_CS_Set() 	//GPIO_BOP(GPIOC) = mBit6 //CS置高，非选中
#define DA124x_CS_Clr()		//GPIO_BC(GPIOC) = mBit6	//选中
/*======================================= 模块内有效变量定义 ======================================*/
Bool DACSpiOrCpld; //DAC控制选择，mTrue:SPI,mFalse:CPLD
U16 DACChan_CMRTab[]={	//通道输出值DAC12x 
	mDAC124S_SEL0,mDAC124S_SEL1,mDAC124S_SEL2,mDAC124S_SEL3};
U8 NextChannel;
uint16_t DAC_SPI_SendData(void);  //开始发送函数	
U8 DACChanNum;
	
U16 State_Null;				//状态		辅助用

//比例阀相关
typedef struct 
{
	U16 *StateAddr;			//状态地址			比例阀当前输出显示
	U16 ResSN;				//资源序号
	U16	Limit;				//限值				比例阀的最大值	
	U32 *MinRampTime;		//最小斜率时间		20110914加:针对伺服驱动器，限制最小斜率，否则压力流量变化太快，易损坏泵或不稳定

	U16 DisOut;				//显示输出      
	U32 CurrOut;			//当前输出			20191021改：放大10000倍
	U32 StartOut;			//起始输出			即斜率起点		20191021改：放大10000倍
	U32 DstOut;				//目标输出			即斜率终点		20191021改：放大10000倍
	U16 RampRange;			//斜率范围			斜率时间对应的范围，mRM_Range算法用
	U32 RampTime;			//斜率时间			单位10us
	G10usTimer RampTimer;	//斜率计时器
	U32 NextRampCalTime;	//下一斜率计算时间	单位10us
	Bool CurrPol;			//当前极性			-10V～+10V双向比例阀时用，mTrue--负方向	mFalse--正方向
	Bool DstPol;			//目标极性
}PropValStr; 	

PropValStr PropVal[mPropValNum]={	//比例阀		虚拟的，需要HardConf.h中定义到对应硬件
	{&State_PVMainPresOut,		    mRU_PVMainPres,			14000,&Para_PresMinRamp	},	//主压力阀  20191021改：压力流量放大100倍 
	{&State_PVMainFlowOut,		    mRU_PVMainFlow,			9900,	&Para_FlowMinRamp	},	//主流量阀   
	{&State_PVBackPresOut,		    mRU_PVBackPres,			6000,	&Para_0				},	//背压阀     
	{&State_PVMoldOpenClsFlowOut,	mRU_PVMoldOpenClsFlow,	9900,	&Para_0				},	//开合模     
	{&State_PVInjSuckFlowOut,		mRU_PVInjSuckFlow,		9900,	&Para_0				},	//射进射退   
	{&State_Null,					mRU_PVLinkPres,			14000,&Para_PresMinRamp	},	//连动压力阀		输出值状态不直接显示，可以通过通道的输出查看到
	{&State_Null,					mRU_PVLinkFlow,			9900,	&Para_FlowMinRamp	},	//连动流量阀		输出值状态不直接显示，可以通过通道的输出查看到
	{&State_Null,					mRU_PVSDLinkPres,		14000,&Para_PresMinRamp	},	//伺服连动压力阀	输出值状态不直接显示，可以通过通道的输出查看到
	{&State_Null,					mRU_PVSDLinkFlow,		9900,	&Para_FlowMinRamp	},	//伺服连动流量阀	输出值状态不直接显示，可以通过通道的输出查看到
	{&State_Null,					mRU_PVSetPID,			9900,	&Para_0				},	//J5-PID		输出值状态不直接显示，可以通过通道的输出查看到
	{&State_Null,					mRU_PVPres2,			14000,&Para_PresMinRamp	},	//压力阀2		输出值状态不直接显示，可以通过通道的输出查看到	20130504加，大机变量泵动力为“变量泵+定量泵”
	{&State_Null,					mRU_PVFlow2,			9900,	&Para_FlowMinRamp	},	//流量阀2		输出值状态不直接显示，可以通过通道的输出查看到	20130504加，大机变量泵动力为“变量泵+定量泵”
	{&State_Null,					mRU_PVRelief,			14000,&Para_PresMinRamp	},	//保压溢流		输出值状态不直接显示，可以通过通道的输出查看到	20130621加，双阶机长时间保压时溢流用，以降低油温
	{&State_Null,					mRU_PVInjSuckPres,14000,&Para_PresMinRamp	}};	//注射压力		输出值状态不直接显示，可以通过通道的输出查看到	20130504加，大机变量泵动力为“变量泵+定量泵”

	#define mPV_MainPres		0		//主压力阀
	#define mPV_MainFlow		1		//主流量阀
	#define mPV_BackPres		2		//背压阀
	#define mPV_MCMOFlow		3		//开合模
	#define mPV_InjSuckFlow		4		//射进射退
	#define mPV_LinkPres		5		//连动压力阀			
	#define mPV_LinkFlow		6		//连动流量阀
	#define mPV_SDLinkPres		7		//伺服连动压力阀		与mPV_LinkPres区别：mPV_LinkPres在非连动动作时还当泵使用，相关程序在DAC_Pcs()中
	#define mPV_SDLinkFlow		8		//伺服连动流量阀
	#define mPV_SetPID			9		//J5-PID
	#define mPV_Pres2			10		//压力阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	#define mPV_Flow2			11		//流量阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	#define mPV_HoldPresRel		12		//保压溢流			20130621加，双阶机长时间保压时溢流用，以降低油温
	#define mPV_InjectPres		13		//注射压力			20130517加，天剑快速机
	
//注：如果连动比例阀要并流当“泵”使用，则应选用eDAC_LinkPres，多用于类似定量泵的系统
//   如果连动比例阀是独立的，或由硬件电路完成并流的，则应选用eDAC_SDLinkPres，多用于伺服机（由硬件电路完成并流）


typedef void (* TSetPVFunP)(U32,U32,U32);	//动作函数指针类型	形参1:设置输出值	形参2:斜率	形参3:比例因子

TSetPVFunP const SetPVFun[]={	//与enum eDAC相对应
	SetPV_MainPres,			//	eDAC_Null		无效
	SetPV_MainPres,			//	eDAC_MainPres	主压力阀
	SetPV_MainFlow,			//	eDAC_MainFlow	主流量阀
	SetPV_BackPres,			//	eDAC_BackPres	背压阀
	SetPV_MoldOpenFlow,		//	eDAC_MOFlow		开模阀（双向）	
	SetPV_MoldClsFlow,		//	eDAC_MCFlow		关模阀（双向）	
	SetPV_SuckBackFlow,		//	eDAC_SBFlow		射退阀（双向）
	SetPV_InjectFlow,		//	eDAC_InjFlow	注射阀（双向）	
	SetPV_LinkPres,			//	eDAC_LinkPres	连动压力阀
	SetPV_LinkFlow,			//	eDAC_LinkFlow	连动流量阀
	SetPV_SDLinkPres,		//	eDAC_SDLinkPres	伺服连动压力阀
	SetPV_SDLinkFlow,		//	eDAC_SDLinkFlow	伺服连动流量阀
	SetPV_SetPID,			//	eDAC_SetPID		J5-PID
	SetPV_Pres2,			//	eDAC_Pres2		压力阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	SetPV_Flow2,			//	eDAC_Flow2		流量阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	SetPV_HoldPresRel,		//	eDAC_HoldPresRel保压溢流		20130621加，双阶机长时间保压时溢流用，以降低油温
	SetPV_InjectPres};		//	eDAC_InjectPres	注射压力		20130517加，天剑快速机用
	
U8 const PropVal_eDAC_mPV_Tab[]={//与enum eDAC、mPV对应表		20120928加，用于获取eDAC_xx对应的PropVal[]数组序号，即mPV_xx
	mPV_MainPres,			//	eDAC_Null		无效
	mPV_MainPres,			//	eDAC_MainPres	主压力阀
	mPV_MainFlow,			//	eDAC_MainFlow	主流量阀
	mPV_BackPres,			//	eDAC_BackPres	背压阀
	mPV_MCMOFlow,			//	eDAC_MOFlow		开模阀（双向）	
	mPV_MCMOFlow,			//	eDAC_MCFlow		关模阀（双向）	
	mPV_InjSuckFlow,		//	eDAC_SBFlow		射退阀（双向）
	mPV_InjSuckFlow,		//	eDAC_InjFlow	注射阀（双向）	
	mPV_LinkPres,			//	eDAC_LinkPres	连动压力阀
	mPV_LinkFlow,			//	eDAC_LinkFlow	连动流量阀
	mPV_SDLinkPres,			//	eDAC_SDLinkPres	伺服连动压力阀
	mPV_SDLinkFlow,			//	eDAC_SDLinkFlow	伺服连动流量阀
	mPV_SetPID,				//	eDAC_SetPID		J5-PID
	mPV_Pres2,				//	eDAC_Pres2		压力阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	mPV_Flow2,				//	eDAC_Flow2		流量阀2			20130504加，大机变量泵动力为“变量泵+定量泵”
	mPV_HoldPresRel,		//	eDAC_HoldPresRel保压溢流		20130621加，双阶机长时间保压时溢流用，以降低油温
	mPV_InjectPres};		//	eDAC_InjectPres	注射压力		20130517加，天剑快速机用

//DAC相关
typedef const struct
{
	U32 *SetPointNum;		//曲线表点数
	U32 *SetPointTab;		//设置点表
	U32 *DADataTab;			//DA值表
	
	U16 *LimitAddr;			//限值地址			通道输出上限值	20260507加
	U16 *StateAddr;			//状态地址			通道当前输出显示
	U16 *HardConfAddr;		//硬件配置地址		通道对应硬件配置
}DACAttrStr;	//通道属性

DACAttrStr DACAttr[mDACMaxNum]={
	{&Para_DAC1PointNum,	&Para_DAC1SetPoint0,	&Para_DAC1DA0,	&State_DAC1OutLim,	&State_DAC1Out,	&Hard_DA01},
	{&Para_DAC2PointNum,	&Para_DAC2SetPoint0,	&Para_DAC2DA0,	&State_DAC2OutLim,	&State_DAC2Out,	&Hard_DA02},
	{&Para_DAC3PointNum,	&Para_DAC3SetPoint0,	&Para_DAC3DA0,	&State_DAC3OutLim,	&State_DAC3Out,	&Hard_DA03},
	{&Para_DAC4PointNum,	&Para_DAC4SetPoint0,	&Para_DAC4DA0,	&State_DAC4OutLim,	&State_DAC4Out,	&Hard_DA04},
	{&Para_DAC5PointNum,	&Para_DAC5SetPoint0,	&Para_DAC5DA0,	&State_DAC5OutLim,	&State_DAC5Out,	&Hard_DA05},
	{&Para_DAC6PointNum,	&Para_DAC6SetPoint0,	&Para_DAC6DA0,	&State_DAC6OutLim,	&State_DAC6Out,	&Hard_DA06},
	{&Para_DAC7PointNum,	&Para_DAC7SetPoint0,	&Para_DAC7DA0,	&State_DAC7OutLim,	&State_DAC7Out,	&Hard_DA07},
	{&Para_DAC8PointNum,	&Para_DAC8SetPoint0,	&Para_DAC8DA0,	&State_DAC8OutLim,	&State_DAC8Out,	&Hard_DA08}};	

typedef struct
{
	DACAttrStr *DACAP;		//通道属性
	PropValStr *PVP;		//关联的比例阀		即HardConf.h中定义的对应比例阀		主要要用到比例阀的限值
	U32 CurrOut;			//当前输出			最高位为极性
	
	U16 CurrOutDA;			//当前输出DA值		PWM值
	Bool CurrOutPol;		//当前输出极性		mFalse-正	mTrue-负
}DAChanStr;

DAChanStr DAChan[mDACMaxNum]={	//DA通道
	{&DACAttr[0],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[1],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[2],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[3],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[4],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[5],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[6],	&PropVal[0],	0xffffffff,	0,	mFalse},
	{&DACAttr[7],	&PropVal[0],	0xffffffff,	0,	mFalse}};	

	#define mDAChan1		0			//通道1
	#define mDAChan2		1			//通道2
	#define mDAChan3		2			//通道3
	#define mDAChan4		3			//通道4
	#define mDAChan5		4			//通道5
	#define mDAChan6		5			//通道6
	#define mDAChan7		6			//通道7
	#define mDAChan8		7			//通道8


//DA调试相关
struct 
{
	U8 	Mode;							//模式			0-退出	1-普通	2-高级
	U32 SetOut[mDACMaxNum];				//强制输出值		当前值，20191021改：放大10000倍
	Bool SetPol[mDACMaxNum];			//强制输出极性		mTrue--负		20120822加：强制负压输出
	
	U32 DstOut[mDACMaxNum];				//目标值		20191021改：放大10000倍		20110915加：PQ强制输出时也有斜率
	U32 StartOut[mDACMaxNum];			//起始值		20191021改：放大10000倍		20110915加：PQ强制输出时也有斜率

	U32 RampTime;						//斜率时间		单位10us			20110915加：PQ强制输出时也有斜率
	G10usTimer RampTimer;				//斜率计时器						20110915加：PQ强制输出时也有斜率
}DADebug;	//DA调试

void __inline PropValSet(PropValStr *PV,U32 Pres,U32 RampTime,U32 Scale,Bool Pol);			//设置比例阀
//void __inline PropValSet_100(PropValStr *PV,U32 Pres_100,U32 RampTime,U32 Scale,Bool Pol);	//设置比例阀	20171214加,与上面PropValSet()的区别在于U32 Pres放大了100倍，精度更高，暂主要用于开模算法



/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug
int main(void)
{           
	do{
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
函数名称：DAC初始化
函数说明：
输入参数：
返 回 值：
其    它：
SPI_MISO  PC2	没有用到
SPI_MOSI  PC3
SPI_SCK   PB10
SPI_CS    PC6			
DAC_Load  PA8	测试用引脚
通道7极性选择信号
通道8极性选择信号
****************************************************************************************************/
void DAC_Drv_Init(void)
{
	//spi_parameter_struct spi_init_struct;
	U32 i;
	volatile U32 Buff;
	/*if((GetHardPlatLinkCode()==0x5C)||(GetHardPlatLinkCode()==0x60))//P01硬件,通过CPLD控制DAC	20210524	
		DACSpiOrCpld=mFalse;
	else//T6H3硬件直接通过SPI控制DAC
	{
		DACSpiOrCpld=mTrue;
		
		rcu_periph_clock_enable(RCU_GPIOB);
		rcu_periph_clock_enable(RCU_GPIOC);
   		rcu_periph_clock_enable(RCU_SPI1);
		//PB10 复用功能	SPI_SCK
		gpio_af_set(GPIOB, GPIO_AF_5, GPIO_PIN_10);
    	gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_10);
    	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);    	
    	//PC3 复用功能	SPI_MOSI
		gpio_af_set(GPIOC, GPIO_AF_5, GPIO_PIN_3);
    	gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_3);
    	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3);
    	//PC6	CS	输出IO
    	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO_PIN_6);
    	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_6);
    	
		DA124x_CS_Set();
		
		//SPI初始化
    	spi_init_struct.trans_mode           = SPI_TRANSMODE_FULLDUPLEX;//全双工模式	
    	spi_init_struct.device_mode          = SPI_MASTER;				//SPI主机 
    	spi_init_struct.frame_size           = SPI_FRAMESIZE_16BIT;		//16位数据格式
    	spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_2EDGE;	//空闲模式下SCK为0 CPOL=0;CPHA=1,数据采样从第2个时间边沿开始
    	spi_init_struct.nss                  = SPI_NSS_SOFT;			//软件nss管理
    	spi_init_struct.prescale             = SPI_PSC_64;				//Fsck=Fpclk1/64
    	spi_init_struct.endian               = SPI_ENDIAN_MSB;			//MSB First  
    	spi_init(SPI1, &spi_init_struct);
    	
    	spi_ti_mode_disable(SPI1);										//禁用TI模式(摩托罗拉模式)
    	spi_i2s_interrupt_enable(SPI1,SPI_I2S_INT_RBNE);				//接收中断开
    	nvic_irq_enable(SPI1_IRQn, mIRQPriorityL,mIRQPriorityL);		//配置NVIC
    	
		spi_enable(SPI1);
		
		for(i=0;i<mDAC124MaxNum;i++)
		{
			DACChan_CMRTab[i]= mDAC124S_SAL0;
		}
		NextChannel =0;
		DAC_SPI_SendData();
	}*/
	
	
	//比例阀相关初始化
	for(i=0;i<(sizeof(SetPVFun)/sizeof(TSetPVFunP));i++)
		SetPV((enum eDAC)i,0,0,100);						//利用关来初始化比例阀，特别是生成其限值
}
/****************************************************************************************************
函数名称：DACspi开始发送
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
/*U16 DAC_SPI_SendData(void)
{
	if(NextChannel >= DACChanNum)//所有通道发送完成，退出发送
	{
		G10usTimerRes(&DAC_ChanResTimer);	//DAC通道复位定时器	20220811
		NextChannel =0;
		return (SPI_DATA(SPI1));
	}
	__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();
	DA124x_CS_Clr();
	__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();
	SPI_DATA(SPI1) = DACChan_CMRTab[NextChannel++];
	return (SPI_DATA(SPI1));
}*/
/****************************************************************************************************
函数名称：DACspi接收中断处理
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
/*void SPI1_IRQHandler(void)
{
	if(SPI_STAT(SPI1)&SPI_STAT_RBNE)
	{	//SPI接收中断
		//(void) SPI_DATA(SPI1);					
		DA124x_CS_Set();						//使能输出
		DAC_SPI_SendData();
	}
}*/
/****************************************************************************************************
函数名称：DAC处理
函数说明：
输入参数：
返 回 值：
其    它：
1、置于主循环。
****************************************************************************************************/
void DAC_Drv_Pcs(void)
{
	static Bool DACInitFlag=mTrue;	//DA通道初始化标志
	PropValStr *PV;
	U32 i,j,Buff;
	U32 TimeBuff;
	U32 LinkPumpSN;					//连动泵序号

	static ActMonStr AM_MoldOpen={	//开模动作监控
		mAG_MoldOpen,				//动作组			开模
		mAFID_AU_MoldOpen,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{mFARS_Any},				//运行状态		任意
		{mFARR_Any},				//运行结果		任意
		{mASID_Any}};				//段ID区间		任意
	static ActMonStr AM_Charge={	//储料动作监控
		mAG_Charge,					//动作组			储料
		mAFID_Any,					//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{mFARS_Any},				//运行状态		任意
		{mFARR_Any},				//运行结果		任意
		{mASID_Any}};				//段ID区间		任意
	static ActMonStr AM_BMC={		//BMC动作监控
		mAG_BMC,					//动作组			BMC
		mAFID_Any,					//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{mFARS_Any},				//运行状态		任意
		{mFARR_Any},				//运行结果		任意
		{mASID_Any}};				//段ID区间		任意

	
	//比例阀相关处理
	if(MachParaIsModify()||DACInitFlag)
	{	//机器参数有修改、或刚开始
		//更新各比例阀限值
		PropVal[mPV_MainPres].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);		//限值更新	主压力阀	20130331加上“保压压力最大值”，下面两处同
		PropVal[mPV_MainFlow].Limit=mSysFlowMax;														//限值更新	主流量阀
		PropVal[mPV_BackPres].Limit=Min(Para_SysPresMax,Max(Para_BackPresMax,Para_BackPresValMax));		//限值更新	背压
		PropVal[mPV_MCMOFlow].Limit=mSysFlowMax;														//限值更新	开合模流量
		PropVal[mPV_InjSuckFlow].Limit=mSysFlowMax;								//限值更新	注射射退流量
		PropVal[mPV_LinkPres].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);		//限值更新	连动压力阀
		PropVal[mPV_LinkFlow].Limit=mSysFlowMax;								//限值更新	连动流量阀
		PropVal[mPV_SDLinkPres].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);		//限值更新	伺服连动压力阀
		PropVal[mPV_SDLinkFlow].Limit=mSysFlowMax;								//限值更新	伺服连动流量阀
		PropVal[mPV_SetPID].Limit=mSysFlowMax;									//限值更新	J5-PID
		PropVal[mPV_Pres2].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);		//限值更新	压力阀2	20130504加，大机变量泵动力为“变量泵+定量泵”
		PropVal[mPV_Flow2].Limit=mSysFlowMax;															//限值更新	流量阀2	20130504加，大机变量泵动力为“变量泵+定量泵”
		PropVal[mPV_HoldPresRel].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);	//限值更新	保压溢流20130621加，双阶机长时间保压时溢流，以降低油温
		PropVal[mPV_InjectPres].Limit=Max(Max(Para_SysPresMax,Para_InjPresMax),Para_HoldPresPresMax);	//限值更新	注射压力20130517加，天剑快速机
		//记录DAC配置通道数
		DACChanNum=Min(HardConf_DANum,mDACMaxNum);//获取使用的通道数量	
	}
	
	for(i=0;i<mPropValNum;i++)
	{
		PV=&PropVal[i];
		if(G10usTimerOver(&PV->RampTimer,PV->NextRampCalTime))
		{	//斜率计算更新时间到		正常为1ms
			PV->NextRampCalTime+=mRampCalPeriod;
		
			if((PV->CurrOut!=PV->DstOut)||(PV->CurrPol!=PV->DstPol))
			{	//当前和目标不等		计算斜率、更新输出值
				//斜率计算
				TimeBuff=G10usTimerCal(&PV->RampTimer);
				if((PV->RampTime==0)||(TimeBuff>=PV->RampTime))
				{	//斜率时间为0或斜率时间到			斜率结束
					PV->CurrOut=PV->DstOut;
				}
				else if(Para_PropValRampMode==mRM_TtoC)
				{	//斜率模式			(目标-起始)/时间
					if(PV->DstOut>=PV->StartOut)
						PV->CurrOut=PV->StartOut+(U64)(PV->DstOut-PV->StartOut)*TimeBuff/PV->RampTime;
					else
						PV->CurrOut=PV->StartOut-(U64)(PV->StartOut-PV->DstOut)*TimeBuff/PV->RampTime;
				}
				else // if(Para_PropValRampMode==mRM_Range)
				{	//斜率模式			范围/时间
					Buff=(U64)PV->RampRange*100*TimeBuff/PV->RampTime;
					if(PV->DstOut>PV->StartOut)	
					{
						PV->CurrOut=PV->StartOut+Buff;
						if(PV->CurrOut>PV->DstOut)	PV->CurrOut=PV->DstOut;	
					}
					else	
						PV->CurrOut=Sub_MinZero(PV->StartOut,Buff);			//相减，最小为0
				}
				//生成资源输出值
				Buff=PV->CurrOut;
				//极性处理
				PV->CurrPol	=PV->DstPol;
				if(PV->CurrPol)Buff|=mBit31;
				//写入资源
				WrResU32(PV->ResSN,Buff);
				//更新状态
				if(Para_PVOutDispMode)	*PV->StateAddr=PV->DisOut;			//直接输出目标值  20250711改：有2位小数
				else					*PV->StateAddr=PV->CurrOut/100;		//实时输出  20191021改：放大了100倍，除以100显示	20250711改：有2位小数
			}
		}
	}

	//DA通道相关处理
	//DA通道关联到比例阀
	if(HardConfIsModify()||DACInitFlag)
	{	//硬件配置有修改、或未完成初始化
		for(i=0;i<mDACMaxNum;i++)
		{
			for(j=0;j<mPropValNum;j++)
			{
				if(HardConf[mHard_DA01+i]==PropVal[j].ResSN)
				{
					DAChan[i].PVP=&PropVal[j];		//DA通道关联到比例阀
					break;
				}
			}
		}
	}
	
		
	//读取资源，曲线转换为PWM输出值
	for(i=0;i<DACChanNum;i++)
	{
		Buff=RdResU32(*(DAChan[i].DACAP->HardConfAddr));	//读取资源		通道输出
		
		if(SysSta_IsTestMode()&&(DADebug.Mode==mDBM_Nor))
		{	//调试模式		通过改变“读取资源”的结果，实现强制DA输出
			Buff=(U32)DADebug.SetOut[i];
			if(DADebug.SetPol[i])Buff|=mBit31;	//20120822加：负压检查
		}
		
		if(Buff!=DAChan[i].CurrOut)
		{	//有变化	根据曲线，重新计算PWM输出值
			DAChan[i].CurrOut=Buff;
			DAChan[i].CurrOutPol=(Buff&mBit31)?mTrue:mFalse;
			DAChan[i].CurrOutDA =PropVal_TranDAData(*DAChan[i].DACAP->SetPointNum,
													DAChan[i].DACAP->SetPointTab,
													DAChan[i].DACAP->DADataTab,
													DAChan[i].PVP->Limit,
													DAChan[i].CurrOut&(~mBit31));					//返回值为12位
		}
			
		//*DAChan[i].DACAP->StateAddr=(((DAChan[i].CurrOut&(~mBit31))/100)&0x00ff)|((DAChan[i].PVP->Limit & 0x00ff)<<8);	//状态高8位为通道限值
		*DAChan[i].DACAP->LimitAddr=DAChan[i].PVP->Limit;								//通道输出限值，有2位小数	20260507加
		*DAChan[i].DACAP->StateAddr=(DAChan[i].CurrOut&(~mBit31))/100;	//通道当前输出，有2位小数	20260507改
	}
	//更新到硬件
	
	/*if(DACSpiOrCpld)//通过SPI控制DAC
	{
		if(G10usTimerOver(&DAC_ChanResTimer,T1msTo10us(5)))	//20220811
		{
			NextChannel=0;
			G10usTimerRes(&DAC_ChanResTimer);
		}
		if(NextChannel==0)//前一次所有通道输出完成
		{
			for(i=0;(i < DACChanNum) ; i++)
			{
				DACChan_CMRTab[i] = mDAC124S_SIGM | (i << 14) | (DAChan[i].CurrOutDA & 0xfff);
			}
			DAC_SPI_SendData();//开始发送DAC数据	
		}
	}
	else//通过CPLD控制DAC*/
	{
		if(DACChanNum>0)
		{	//通道1		0～+10V
			if(DAChan[0].CurrOutPol)		DAChan[0].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[0].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC1DataL,DAChan[0].CurrOutDA);				//低字节,通过CPLD输出DA时，必须先写低8位，再写高8位。因为CPLD通过高8位锁存数据。
			SB_WriteData(mSBA_DAC1DataH,(DAChan[0].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>1)
		{	//通道2		0～+10V
			if(DAChan[1].CurrOutPol)		DAChan[1].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[1].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC2DataL,DAChan[1].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC2DataH,(DAChan[1].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>2)
		{	//通道3		0～+10V
			if(DAChan[2].CurrOutPol)		DAChan[2].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[2].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC3DataL,DAChan[2].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC3DataH,(DAChan[2].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>3)
		{	//通道4		0～+10V
			if(DAChan[3].CurrOutPol)		DAChan[3].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[3].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC4DataL,DAChan[3].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC4DataH,(DAChan[3].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>4)
		{	//通道5		0～+10V
			if(DAChan[4].CurrOutPol)		DAChan[4].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[4].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC5DataL,DAChan[4].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC5DataH,(DAChan[4].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>5)
		{	//通道6		0～+10V
			if(DAChan[5].CurrOutPol)		DAChan[5].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[5].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC6DataL,DAChan[5].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC6DataH,(DAChan[5].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>6)
		{	//通道7		0～+10V
			if(DAChan[6].CurrOutPol)		DAChan[6].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[6].CurrOutDA&=(~mBit15);	//正极性，最高位清零
			SB_WriteData(mSBA_DAC7DataL,DAChan[6].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC7DataH,(DAChan[6].CurrOutDA>>8));	//高字节
		}
		if(DACChanNum>7)
		{	//通道8		0～+10V
			if(DAChan[7].CurrOutPol)		DAChan[7].CurrOutDA|=mBit15;//负极性，最高位置1
			else 										DAChan[7].CurrOutDA&=(~mBit15); //正极性，最高位清零
			SB_WriteData(mSBA_DAC8DataL,DAChan[7].CurrOutDA);				//低字节
			SB_WriteData(mSBA_DAC8DataH,(DAChan[7].CurrOutDA>>8));	//高字节
		}
	}
	
	//DA调试输出结束处理
	if(!SysSta_IsTestMode())
	{	//非调试模式				出现紧急停止时会用到此处
		if((DADebug.Mode!=mDBM_Exit))
		{	//刚进行过调试输出		复位输出
			DADebug.Mode=mDBM_Exit;
			for(i=0;i<mDACMaxNum;i++)
				DADebug.SetOut[i]=0,DADebug.DstOut[i]=0;
		}
	}

	//DA调试斜率相关处理		20110915加：PQ强制输出时有斜率
	if(SysSta_IsTestMode()&&(DADebug.Mode==mDBM_Nor))
	{	//普通DA调试模式
		if(G10usTimerOver(&DADebug.RampTimer,T1msTo10us(5)))
		{
			TimeBuff=G10usTimerCal(&DADebug.RampTimer);
			G10usTimerRes(&DADebug.RampTimer);
			for(i=0;i<mDACMaxNum;i++)
			{
				if((DADebug.RampTime==0)||(TimeBuff>=DADebug.RampTime))
				{	//斜率时间为0或斜率时间到			斜率结束
					DADebug.SetOut[i]=DADebug.DstOut[i];
				}
				else
				{	//斜率模式			(目标-起始)/时间
					if(DADebug.DstOut[i]>DADebug.SetOut[i])
					{
						DADebug.SetOut[i]=DADebug.SetOut[i]+(U64)Sub_Abs(DADebug.DstOut[i],DADebug.StartOut[i])*TimeBuff/DADebug.RampTime;
						if(DADebug.DstOut[i]<DADebug.SetOut[i])	
							DADebug.SetOut[i]=DADebug.DstOut[i];
					}
					else if(DADebug.DstOut[i]<DADebug.SetOut[i])
					{
						DADebug.SetOut[i]=DADebug.SetOut[i]-(U64)Sub_Abs(DADebug.StartOut[i],DADebug.DstOut[i])*TimeBuff/DADebug.RampTime;
						if((DADebug.DstOut[i]>DADebug.SetOut[i])||((S16)DADebug.SetOut[i]<0))
							DADebug.SetOut[i]=DADebug.DstOut[i];						
					}
					//else if(DADebug.DstOut[i]==DADebug.SetOut[i])
				}
			}
		}
	}
	else
		G10usTimerRes(&DADebug.RampTimer);
	
	//泵处理
	//暂使用8个泵
	//****泵开启有两种方法：一是根据实际流量输出，二是根据设定目标值直接开
	//****宏讯是两种方法可选（默认是方式一）
	//****注意新版程序增加上述特性
	//****未考虑泵借用功能（蓄能器借用蓄能）
	//if(!SysStaIsTestMode())
	//{	//非DA调试模式			在DA调试模式下，不执行下面检查
		if(Para_PumpType==0)
		{	//0-叠加泵
			Buff=PropVal[mPV_MainFlow].CurrOut/100;

			if(SysSta_IsTestMode()&&(DADebug.Mode!=mDBM_Exit))
			{	//调试模式		直接引用MainFlow对应DA通道的输出
				for(i=0;i<mDACMaxNum;i++)
				{
					if(*(DAChan[i].DACAP->HardConfAddr)==mRU_PVMainFlow)
					{	//主流量通道
						Buff=(DAChan[i].CurrOut&(~mBit31))/100;
						break;
					}
				}
			}
			
			if(GetResBit(mRO_Link))	LinkPumpSN=Para_LinkPumpSel;	//连动有效			连动时，需要某个泵也一起开启
			else					LinkPumpSN=0;
			
			if(LinkPumpSN==1)				OpenResBit(mRO_Pump01);	//受连动要求开启
			else if(Buff>Para_Pump1OnFlow)	OpenResBit(mRO_Pump01);	//开启流量到
			else							ClsResBit(mRO_Pump01);

			if(LinkPumpSN==2)				OpenResBit(mRO_Pump02);	//受连动要求开启
			else if(Buff>Para_Pump2OnFlow)	OpenResBit(mRO_Pump02);	//开启流量到
			else							ClsResBit(mRO_Pump02);

			if(LinkPumpSN==3)				OpenResBit(mRO_Pump03);	//受连动要求开启
			else if(Buff>Para_Pump3OnFlow)	OpenResBit(mRO_Pump03);	//开启流量到
			else							ClsResBit(mRO_Pump03);

			if(LinkPumpSN==4)				OpenResBit(mRO_Pump04);	//受连动要求开启
			else if(Buff>Para_Pump4OnFlow)	OpenResBit(mRO_Pump04);	//开启流量到
			else							ClsResBit(mRO_Pump04);

			if(LinkPumpSN==5)				OpenResBit(mRO_Pump05);	//受连动要求开启
			else if(Buff>Para_Pump5OnFlow)	OpenResBit(mRO_Pump05);	//开启流量到
			else							ClsResBit(mRO_Pump05);

			if(LinkPumpSN==6)				OpenResBit(mRO_Pump06);	//受连动要求开启
			else if(Buff>Para_Pump6OnFlow)	OpenResBit(mRO_Pump06);	//开启流量到
			else							ClsResBit(mRO_Pump06);

			if(LinkPumpSN==7)				OpenResBit(mRO_Pump07);	//受连动要求开启
			else if(Buff>Para_Pump7OnFlow)	OpenResBit(mRO_Pump07);	//开启流量到
			else							ClsResBit(mRO_Pump07);

			if(LinkPumpSN==8)				OpenResBit(mRO_Pump08);	//受连动要求开启
			else if(Buff>Para_Pump8OnFlow)	OpenResBit(mRO_Pump08);	//开启流量到
			else							ClsResBit(mRO_Pump08);
		}
		//else
		//{	//1-组合泵
		//}
	//}	
	
	//连动压力比例阀	
	//20110526增加，以顶针为例说明逻辑
	//1)顶针连动执行时，该连动压力比例阀按顶针设定的压力输出
	//2)其它动作时，该比例阀相当于“泵”，起到并流作用，即流量到“连动压力比例阀开启流量”参数时ON
	//3)为避免冲击，在开模动作时如果连动使用，则该比例阀只按上述逻辑1)执行，即停止“泵”并流作用
	//注：新增“连动压力比例阀开启流量”参数
	//	  如注射之类连动，则下面程序还要作修改			BMC机器储料连动时已加			???
	/*20120806改下面程序，增加BMC机器储料连动
	if((!APM_ActMon(&AM_MoldOpen))||										//非开模动作
	   (!((Para_LinkOilWayOpt==1)&&(Para_MoldOpenLinkSel!=mMOLS_Off))))		//连动油路未配备、或连动关
	{
		if(Buff>Para_LinkPresOnFlow)
			PropValSet(&PropVal[mPV_LinkPres],PropVal[mPV_LinkPres].Limit,0,100,mFalse);
		else
			PropValSet(&PropVal[mPV_LinkPres],0,0,100,mFalse);
	}*/
	if(((Para_LinkOilWayOpt==1)&&(Para_MoldOpenLinkSel!=mMOLS_Off)&&APM_ActMon(&AM_MoldOpen))||	//开模动作、且连动油路配备、且连动开
	   ((Para_BMCOpt==1       )&&(Para_BMCMode==1                )&&APM_ActMon(&AM_Charge  ))||	//储料动作、且BMC配备、且BMC使用	
	   ((Para_BMCOpt==1       )&&(Para_BMCMode==1                )&&APM_ActMon(&AM_BMC     )))	//BMC动作
	{	//连动类动作，连动比例阀正常做连动
	}
	else
	{	//连动比例阀做泵使用
		if(Buff>Para_LinkPresOnFlow)
			PropValSet(&PropVal[mPV_LinkPres],PropVal[mPV_LinkPres].Limit,0,100,mFalse);
		else
			PropValSet(&PropVal[mPV_LinkPres],0,0,100,mFalse);
	}
		
	DACInitFlag=mFalse;	
	
	VarPumpQuanPumpSys_Pcs();	//20130504加，大机变量泵动力为“变量泵+定量泵”
	PVHoldPresRel_Pcs();		//20140722加，应双阶机
	PVInjectPres_Pcs();			//20130517加，天剑快速机用，“注射压力比例阀”处理
}
/****************************************************************************************************
函数名称：	DA调试设置模式
函数说明：
输入参数：	
返 回 值：
其    它：
1)本函数主要由Code.c根据界面指令调用。
****************************************************************************************************/
void DADebugSetMode(U8 Mode)
{
	U32 i;

	if(Mode==mDBM_Nor)
		DADebug.Mode=mDBM_Nor;
	else//(Mode==mDBM_Exit)
	{	//退出调试指令
		if(DADebug.Mode!=mDBM_Exit)
		{	//当前为调试模式	关闭输出
			DADebug.Mode=mDBM_Exit;
			for(i=0;i<mDACMaxNum;i++)
				DADebug.SetOut[i]=0,DADebug.DstOut[i]=0;
		}
	}
}
/****************************************************************************************************
函数名称：	DA调试设置通道
函数说明：
输入参数：
返 回 值：
其    它：
1)本函数主要由Code.c根据界面指令调用。
****************************************************************************************************/
Bool DADebugSetOut(U8 DAChan,U16 DAOut)
{
	if(SysSta_IsTestMode()&&(DADebug.Mode==mDBM_Nor))
	{	//普通DA调试模式
		//20120822加：负压强制输出
		if((DAChan>=(mDBT_DA_DAChan1_Neg-mDBT_DA_DAChan1))&&(DAChan<=(mDBT_DA_DAChan8_Neg-mDBT_DA_DAChan1)))
		{	//负电压
			DAChan-=(mDBT_DA_DAChan1_Neg-mDBT_DA_DAChan1);
			
			if(DAChan<mDACMaxNum)	DADebug.SetPol[DAChan]=mTrue;
		}
		else if(DAChan<mDACMaxNum)
		{	//正电压
			DADebug.SetPol[DAChan]=mFalse;
		}

		if(DAChan<mDACMaxNum)	
		{
			DADebug.StartOut[DAChan]=DADebug.SetOut[DAChan];
			DADebug.DstOut[DAChan]=DAOut*100;     //20260507改：调试界面下发的压力流量数据由U8改为U16
			//DADebug.SetOut[DAChan];			
			DADebug.RampTime=Para_DADbRamp;					//斜率时间
			//DADebug.RampTimer;
			
			RstDbgModeTimer();			//复位调试模式计时器			实现强制输出时间到自动结束
			return mTrue;
		}
	}
	return mFalse;
}
/****************************************************************************************************
函数名称：	获取DA调试输出
函数说明：
输入参数：	DACResSN------DA通道对应资源
返 回 值：	0xffffffff----未在调试模式
其    它：
1)本函数主要由驱动器相关程序调用(如HCIS300SD_Drv.c)用以获取调试情况。
****************************************************************************************************/
U32 GetDACDebugOut(U16 DACResSN)
{
	U32 i;

	if(SysSta_IsTestMode()&&(DADebug.Mode==mDBM_Nor))
	{	//调试模式		通过改变“读取资源”的结果，实现强制DA输出
		for(i=0;i<mDACMaxNum;i++)
			if(*(DAChan[i].DACAP->HardConfAddr)==DACResSN)
				return (U32)DADebug.SetOut[i];
	}
	
	return 0xffffffff;		
}
/****************************************************************************************************
函数名称：设置比例阀
函数说明：
输入参数：	enum eDAC Chan	通道
			U16 Out			输出值
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV(enum eDAC Chan,U32 Out,U32 RampTime,U32 Scale)
{
	if(Chan == eDAC_Null)	return;
	if(Chan >= (sizeof(SetPVFun)/sizeof(TSetPVFunP)) )	return;
	
	SetPVFun[Chan](Out,RampTime,Scale);	//函数指针数组		调用相应SetPV_xxx()
}
/****************************************************************************************************
函数名称：设置主压力阀压力
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_MainPres(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_MainPres],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
//20171214加,与上面SetPV_MainPres()的区别在于U32 Pres放大了100倍，精度更高，暂主要用于开模算法
//void SetPV_MainPres_100(U32 Pres,U32 RampTime,U32 Scale)
//{
//	PropValSet_100(&PropVal[mPV_MainPres],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
//}
/****************************************************************************************************
函数名称：设置主流量
函数说明：
输入参数：	U8 Flow			流量
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_MainFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制
	
	PropValSet(&PropVal[mPV_MainFlow],Flow,RampTime,Scale,mFalse);			//极性		0～+10V
}
//20171214加,与上面SetPV_MainFlow()的区别在于U32 Flow放大了100倍，精度更高，暂主要用于开模算法
//void SetPV_MainFlow_100(U32 Flow,U32 RampTime,U32 Scale)
//{
//	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow*100);	//调模方式流量限制
//	
//	PropValSet_100(&PropVal[mPV_MainFlow],Flow,RampTime,Scale,mFalse);			//极性		0～+10V
//}
/****************************************************************************************************
函数名称：	设置背压
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：	无
其    它：
****************************************************************************************************/
void SetPV_BackPres(U32 Pres,U32 RampTime,U32 Scale)
{
	if(!Para_BackPresPVOpt)	Pres=0,RampTime=0;						//比例背压阀未配备
		
	PropValSet(&PropVal[mPV_BackPres],Pres,RampTime,Scale,mFalse);	//极性			0～+10V
}
/****************************************************************************************************
函数名称：	设置关模比例流量
函数说明：
输入参数：	U8 Flow			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：	无
其    它：
****************************************************************************************************/
void SetPV_MoldClsFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制

	PropValSet(&PropVal[mPV_MCMOFlow],Flow,RampTime,Scale,mFalse);	//极性			0～+10V
}
/****************************************************************************************************
函数名称：	设置开模比例流量
函数说明：
输入参数：	U8 Flow			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：	无
其    它：
****************************************************************************************************/
void SetPV_MoldOpenFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制

	PropValSet(&PropVal[mPV_MCMOFlow],Flow,RampTime,Scale,mTrue);	//极性			-10V～0	
}
/****************************************************************************************************
函数名称：	设置注射比例流量
函数说明：
输入参数：	U8 Flow			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：	无
其    它：
****************************************************************************************************/
void SetPV_InjectFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制

	PropValSet(&PropVal[mPV_InjSuckFlow],Flow,RampTime,Scale,mFalse);	//极性		0～+10V	
}
/****************************************************************************************************
函数名称：	设置射退比例流量
函数说明：
输入参数：	U8 Flow			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：	无
其    它：
****************************************************************************************************/
void SetPV_SuckBackFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制

	PropValSet(&PropVal[mPV_InjSuckFlow],Flow,RampTime,Scale,mTrue);	//极性		-10V～0	
}
/****************************************************************************************************
函数名称：设置连动压力阀压力
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_LinkPres(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_LinkPres],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置连动流量阀流量
函数说明：
输入参数：	U8 Flow			流量
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_LinkFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制
	
	PropValSet(&PropVal[mPV_LinkFlow],Flow,RampTime,Scale,mFalse);			//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置伺服连动压力阀压力
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_SDLinkPres(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_SDLinkPres],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置伺服连动流量阀流量
函数说明：
输入参数：	U8 Flow			流量
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_SDLinkFlow(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制
	
	PropValSet(&PropVal[mPV_SDLinkFlow],Flow,RampTime,Scale,mFalse);			//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置J5-PID
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
****************************************************************************************************/
void SetPV_SetPID(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_SetPID],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置压力阀压力2
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：

20130504加，大机变量泵动力为“变量泵+定量泵”
****************************************************************************************************/
void SetPV_Pres2(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_Pres2],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置流量阀流量2
函数说明：
输入参数：	U8 Flow			流量
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：

20130504加，大机变量泵动力为“变量泵+定量泵”
****************************************************************************************************/
void SetPV_Flow2(U32 Flow,U32 RampTime,U32 Scale)
{
	if(SysSta_IsManuMoldAdjMode())	Flow=Min(Flow,Para_AdjMoldActMaxFlow);	//调模方式流量限制
	
	PropValSet(&PropVal[mPV_Flow2],Flow,RampTime,Scale,mFalse);			//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置保压溢流
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：

20130621加，双阶机长时间保压时溢流，以降低油温
****************************************************************************************************/
void SetPV_HoldPresRel(U32 Pres,U32 RampTime,U32 Scale)
{
	PropValSet(&PropVal[mPV_HoldPresRel],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置注射压力
函数说明：
输入参数：	U8 Pres			压力	
			U16 RampTime	斜率时间		单位10us
			U8 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：

20130517加，天剑快速机用
****************************************************************************************************/
void SetPV_InjectPres(U32 Pres,U32 RampTime,U32 Scale)
{
	if(Para_InjFlowFeedSel)//注射流量闭环选择使用，按设置输出；选择不用时，不输出。
		PropValSet(&PropVal[mPV_InjectPres],Pres,RampTime,Scale,mFalse);		//极性		0～+10V
	else
		PropValSet(&PropVal[mPV_InjectPres],0,0,100,mFalse);		//极性		0～+10V
}
/****************************************************************************************************
函数名称：设置比例阀
函数说明：
输入参数：	U16 Pres		压力	
			U16 RampTime	斜率时间		单位10us
			U16 Scale		比例因子		范围50%-120%
返 回 值：无
其    它：
1)当输出值还未到目标值时，如果要设置新的输出，有三种处理方式：
  A）当前值为斜率起点，优点在于输出不跳变，但斜率可能会不确定
  B）原目标值作为斜率起点，优点在于斜率固定，但会有一次跳变（当前值会跳变到原目标值）
  C）当前值为斜率起点，同时修正斜率时间（扣减未到的部分），优点在于斜率固定、不跳变，但程序麻烦
  T6F2采用方式B，本程序暂采用方式A。
****************************************************************************************************/
void __inline PropValSet(PropValStr *PV,U32 Pres,U32 RampTime,U32 Scale,Bool Pol)
{
	Pres=Min(PV->Limit,Pres);						//超限检查
	Scale=((Scale<50)||(Scale>120))?100:Scale;		//比例因子范围检查
	PV->DisOut	=Pres;								//显示输出
	
	if(PV->CurrPol==Pol)PV->StartOut=PV->CurrOut;	//极性相同		PV->StartOut=PV->DstOut	见注1
	else				PV->StartOut=0;				//极性变化

	PV->DstOut	=Pres*Scale;						//目标输出		实际放大100位，因为Scale应除100才是正常缩放比例
	PV->DstPol	=Pol;								//目标极性	

	G10usTimerRes(&PV->RampTimer);					//斜率计时器
	PV->RampTime=Max(RampTime,
	                 (*PV->MinRampTime)*(Sub_Abs(PV->DstOut,PV->StartOut)/Scale)/PV->Limit);	
	                 								//斜率时间			单位10us		20110914改：限制最小斜率时间：变化量/最大变化范围*MinRampTime
	PV->NextRampCalTime=0;							//下一斜率计算时间	单位10us		为0即立即启动一次计算

	//PV->CurrOut=PV->StartOut;						//当前输出	立即调整为起始输出		不可以
	//PV->CurrPol=PV->DstPol;						//当前极性	立即调整为目标极性		不可以
	
	//斜率范围			根据斜率算法
	if(Para_PropValRampMode==mRM_Range)	PV->RampRange=PV->Limit;
	//else								PV->RampRange=Sub_Abs(PV->DstOut,PV->StartOut);	
}

//20171214加,与上面PropValSet()的区别在于U32 Pres放大了100倍，精度更高，暂主要用于开模算法
//void __inline PropValSet_100(PropValStr *PV,U32 Pres_100,U32 RampTime,U32 Scale,Bool Pol)
//{
//	U32 Pres;
//	Pres=Pres_100/100;
//	
//	Pres=Min(PV->Limit,Pres);						//超限检查
//	Scale=((Scale<50)||(Scale>120))?100:Scale;		//比例因子范围检查
//	PV->DisOut	=Pres;								//显示输出
//	
//	if(PV->CurrPol==Pol)PV->StartOut=PV->CurrOut;	//极性相同		PV->StartOut=PV->DstOut	见注1
//	else				PV->StartOut=0;				//极性变化

//	PV->DstOut	=Pres_100*Scale/100;				//目标输出		实际放大100位，因为Scale应除100才是正常缩放比例
//	PV->DstPol	=Pol;								//目标极性	

//	G10usTimerRes(&PV->RampTimer);					//斜率计时器
//	PV->RampTime=Max(RampTime,
//	                 (*PV->MinRampTime)*(Sub_Abs(PV->DstOut,PV->StartOut)/Scale)/PV->Limit);	
//	                 								//斜率时间			单位10us		20110914改：限制最小斜率时间：变化量/最大变化范围*MinRampTime
//	PV->NextRampCalTime=0;							//下一斜率计算时间	单位10us		为0即立即启动一次计算

//	//PV->CurrOut=PV->StartOut;						//当前输出	立即调整为起始输出		不可以
//	//PV->CurrPol=PV->DstPol;						//当前极性	立即调整为目标极性		不可以
//	
//	//斜率范围			根据斜率算法
//	if(Para_PropValRampMode==mRM_Range)	PV->RampRange=PV->Limit;
//	//else								PV->RampRange=Sub_Abs(PV->DstOut,PV->StartOut);	
//}
/****************************************************************************************************
名称:	DAC值转换
说明:	将压力或流量转换成对应的DAC数据
参数:	U8 TabNum			表长度
		U16 * SetPointTab	设置点表，是比例点
		U16 * DACDataTab	DAC值表
		U16 Range			量程，SetPoint*n/100即某设置点的值，如流量为99、系统压力通常为140
		U16 ValOut			比例阀输出，即需要转换成DAC的输出
返回：	DAC输出值			12位
其它：
1) 如果阀曲线出现负斜率，一般是用户设置出错了，但在本函数中不给出出错信息
2) 当输出计算出负时则输出0，当输出超过mDACDataMax时输出mDACDataMax
3) 允许起始电流存在，以提高阀响应的速度
4) 曲线必须从0Bar或0%开始，且按序递增排列，点数取决于TabNum
5) 计算公式：(Y1-Y0)*(x-X0)/(X1-X0)+Y0
6) 允许ValOut大于Range，此时按延长线计算，如果超出mDADataMax，则仍输出mDADataMax
7) 执行时间：	11个点		1次查找		用时1.9us
							最大查找		用时2.9us
   程序中查表时，先进行一次二分，节约时间约0.6us
****************************************************************************************************/
U16 PropVal_TranDAData(U8 TabNum,U32 * SetPointTab,U32 * DADataTab,U32 Range,U32 ValOut)
{
	U8 i;
	U32 SetPoint1,SetPoint0;
	U32 Buff;
	//找出曲线上对应点
	if(ValOut*10 > SetPointTab[TabNum/2]*Range)			//先进行一次二分	准确是ValOut*1000/100，其中*1000是因为对照表放大了1000倍、/100是因为ValOut放大了100倍
		i=TabNum/2;
	else
		i=1;
	for(;i<TabNum-1;i++)
		if(ValOut*10 <= SetPointTab[i]*Range)	
			break;

	//换算成DA值
	SetPoint1=SetPointTab[i]*Range/10;					//准确是ValOut*1000/100，其中*1000是因为对照表放大了1000倍、/100是因为ValOut放大了100倍
	SetPoint0=SetPointTab[i-1]*Range/10;				//准确是ValOut*1000/100，其中*1000是因为对照表放大了1000倍、/100是因为ValOut放大了100倍
			
	if(SetPoint1==SetPoint0)	
		return DADataTab[i-1];		//计算中的除数将为0		故直接返回值

	if(DADataTab[i]>=DADataTab[i-1])
		Buff=(DADataTab[i]-DADataTab[i-1])*(ValOut-SetPoint0)/(SetPoint1-SetPoint0)+DADataTab[i-1];
	else	//曲线斜率为负，通常设置出错
		Buff=DADataTab[i-1]-(DADataTab[i-1]-DADataTab[i])*(ValOut-SetPoint0)/(SetPoint1-SetPoint0);
			
	if(Buff&mBit31)	
		return 0;					//负值	返回0
	
	return Min(mDADataMax,Buff);	
}
/****************************************************************************************************
函数名称：	获取DA通道的输出当前DA值
函数说明：
输入参数：	U8 Chan			通道号	
返 回 值：	U16				12位DA
			                Bit15为极性	1--负极性
其    它：
1)主要是PropValCurrMeas_Drv.c中引用。
2)20161122加
****************************************************************************************************/
U16 GetDAChan_CurrDA(U8 Chan)
{	
	U32 Buff;
	
	Buff=DAChan[Chan].CurrOutDA;						//12位DA值 20201027改
	if(DAChan[Chan].CurrOutPol)		Buff|=mBit15;		//负极性
		
	return(Buff);
}
/****************************************************************************************************
函数名称：	获取DA通道的输出PWM值其占空比(相对量程)
函数说明：
输入参数：	U8 Chan			通道号	
返 回 值：	U32				占空比，放大1024倍
其    它：
1)主要是PropValCurrMeas_Drv.c中引用。
****************************************************************************************************/
U32 GetDAChan_DAPercentage(U8 Chan)
{
	return (DAChan[Chan].CurrOutDA<<11)/mDADataMax;
}
U32 GetDAChan_DAPer_001(U8 Chan)		//放大10000，即2位小数   20191212加
{
	if(Chan>=mDACMaxNum)//通道无效，返回0	20210926加
		return 0x00000000;
	else 
		return (DAChan[Chan].CurrOutDA*10000)/mDADataMax;
}
/****************************************************************************************************
函数名称：	获取比例阀的目标输出值
函数说明：
输入参数：	enum eDAC Chan	通道号	
返 回 值：	U32				目标输出值
其    它：
1)主要是AU_EjeRet.c、AU_EjeFor.c中引用，知道目标输出值，以判断是否需提前变换流量减速。
注：20120928加
    PropVal与enum eDAC Chan不能直接对应，必须经PropVal_eDAC_mPV_Tab[]转换
****************************************************************************************************/
U32 GetPropVal_DstOut(enum eDAC Chan)
{
	return (PropVal[PropVal_eDAC_mPV_Tab[Chan]].DstOut / 100);		//100是因为放大了100倍
}
/****************************************************************************************************
函数名称：	获取比例阀的当前输出值
函数说明：
输入参数：	enum eDAC Chan	通道号	
返 回 值：	U32				比例阀当前实际输出值
其    它：
1)20190815加	主要是螺杆曲线功能中使用
2)放大了100倍即单位是0.01Bar
****************************************************************************************************/
U32 GetPropVal_CurrOut(enum eDAC Chan)
{	
	return (PropVal[PropVal_eDAC_mPV_Tab[Chan]].CurrOut/100);		
}
/****************************************************************************************************
函数名称：	获取比例阀对应通道
函数说明：
输入参数：	enum eDAC Chan	通道号	
返 回 值：	U32				目标输出值
其    它：
1、20161122加
****************************************************************************************************/
U8 GetPropVal_DAChan(U32 PropValRes)
{
	U8 i;
	
	for(i=0;i<Min(HardConf_DANum,mDACMaxNum);i++)
	{
		if(HardConf[mHard_DA01+i]==PropValRes)	
			return i;
	}
	
	return 0xff;
}
/****************************************************************************************************
函数名称：	“变量泵+定量泵”系统处理
函数说明：
输入参数：	
返 回 值：	
其    它：
1、包括：压力2、流量2比例阀处理……注射(不含保压)、储料、开模2-4段、关模1-3段，该4个动作时输出同主压力和流量
                                 其它动作及这4个动作的调模状态下，则压力输出最大（无斜率）、流量输出关闭，如无动作进行时则均关
		泵……只在“注射(不含保压)、储料、开模2-4段、关模1-3段”四个动作及“油温预热”时执行叠加逻辑（逻辑不变），其余均不输出

20130504加，大机变量泵动力为“变量泵+定量泵”
****************************************************************************************************/
void VarPumpQuanPumpSys_Pcs(void)
{
	static ActMonStr AM_MoldCls={	//关模动作监控
		mAG_MoldClose,				//动作组			关模
		mAFID_AU_MoldClose,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{eFARS_Run},				//运行状态		
		{mFARR_Any},				//运行结果		任意
		{mASID_AU_MoldCls_MC1,mASID_AU_MoldCls_MC3}};				//段ID区间		1-3段
			
	static ActMonStr AM_MoldOpen={	//开模动作监控
		mAG_MoldOpen,				//动作组			开模
		mAFID_AU_MoldOpen,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{eFARS_Run},				//运行状态		
		{mFARR_Any},				//运行结果		任意
		{mASID_AU_MoldOpen_MO2,mASID_AU_MoldOpen_MO4}};				//段ID区间		2-4段
			
	static ActMonStr AM_Charge={	//储料动作监控
		mAG_Charge,					//动作组			储料
		mAFID_AU_Charge,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{eFARS_Run},				//运行状态		
		{mFARR_Any},				//运行结果		任意
		{mASID_Any}};				//段ID区间		任意
			
	static ActMonStr AM_Inject={	//注射动作监控
		mAG_Inject,					//动作组			注射
		mAFID_AU_Inject,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{eFARS_Run},				//运行状态		
		{mFARR_Any},				//运行结果		任意
		{mASID_AU_Inject_Inj1,mASID_AU_Inject_Inj10}};				//段ID区间		1-10段
	/*		
	static ActMonStr AU_OilHtr={	//油温预热动作监控
		mAG_OilHtr,					//动作组			油温预热
		mAFID_AU_OilHtr,			//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{eFARS_Run},				//运行状态		
		{mFARR_Any},				//运行结果		任意
		{mASID_Any}};				//段ID区间		任意*/
	
	static ActMonStr AM_VarDly={	//切阀延时监控
		mAG_Any,					//动作组			任意
		mAFID_Any,					//动作函数ID	
		{mASEG_Any},				//动作细分		任意
		{mFARR_Any},				//运行状态		任意
		{mFARR_Any},				//运行结果		任意
		{mASID_OutDly,mASID_OutDly}};	//段ID区间	切阀延时
	static Bool LastHighFlowActFlag;	//刚才大流量动作
	
	

	if(Para_VarPumpQuanPumpSys!=1)	return;		//非“变量泵+定量泵”系统
		
	if(APM_ActMon(&AM_MoldCls)||APM_ActMon(&AM_MoldOpen)||APM_ActMon(&AM_Charge)||APM_ActMon(&AM_Inject)||
	   (LastHighFlowActFlag&&APM_ActMon(&AM_VarDly)))	//大流量动作连着进行切阀延时，则继续保持与主压力同步，否则“压力2”切阀延时时会开一下
	{	//大流量动作			“压力2、流量2”同“主压力、主流量”输出
		PropVal[mPV_Pres2].DisOut	=PropVal[mPV_MainPres].DisOut;	//显示输出
		PropVal[mPV_Pres2].DstOut	=PropVal[mPV_MainPres].CurrOut;	//目标输出
		PropVal[mPV_Pres2].StartOut	=PropVal[mPV_MainPres].CurrOut;	//起始输出
		PropVal[mPV_Pres2].RampTime	=0;								//斜率
		PropVal[mPV_Pres2].NextRampCalTime=0;
		
		PropVal[mPV_Flow2].DisOut	=PropVal[mPV_MainFlow].DisOut;	//显示输出
		PropVal[mPV_Flow2].DstOut	=PropVal[mPV_MainFlow].CurrOut;	//目标输出
		PropVal[mPV_Flow2].StartOut	=PropVal[mPV_MainFlow].CurrOut;	//起始输出
		PropVal[mPV_Flow2].RampTime	=0;								//斜率
		PropVal[mPV_Flow2].NextRampCalTime=0;
		
		LastHighFlowActFlag=mTrue;
	}
	else
	{	//小流量动作或无动作	
		LastHighFlowActFlag=mFalse;


		if(Act_MainFlow_DAUseChk(eDAC_MainPres))
		{	//正在使用主压力阀
			SetPV(eDAC_Pres2,PropVal[mPV_Pres2].Limit,	0,100);	//最大输出
			SetPV(eDAC_Flow2,0,							0,100);	//关闭
		}
		else
		{
			SetPV(eDAC_Pres2,0,							0,100);	//关闭
			SetPV(eDAC_Flow2,0,							0,100);	//关闭
		}
		
		//泵全关
		ClsResBit(mRO_Pump01);
		ClsResBit(mRO_Pump02);
		ClsResBit(mRO_Pump03);
		ClsResBit(mRO_Pump04);
		ClsResBit(mRO_Pump05);
		ClsResBit(mRO_Pump06);
		ClsResBit(mRO_Pump07);
		ClsResBit(mRO_Pump08);			
	}	
}
/****************************************************************************************************
函数名称：	“保压溢流比例阀”处理
函数说明：
输入参数：	
返 回 值：	
其    它：
1、保压溢流比例阀：应双阶机油路
				   当保压1－10时按照系统压力输出
                   其它时候如果马达已开启，则根据机参“注射压力比例阀工作模式”输出，通常是最大输出
注：20140722加
****************************************************************************************************/
void PVHoldPresRel_Pcs(void)
{
	if(!Act_MainFlow_DAUseChk(eDAC_HoldPresRel))
	{	//保压溢流比例阀未使用：非保压1-10
		if(MotorIsOn())
		{	//马达开
			//工作模式：0-保压时同步输出，其它时候不输出
			//			1-保压时同步输出，其它时候最大输出（马达开后）
			//			2-保压时同步输出，有动作时最大输出（马达开后）
			if(Para_HoldPresPropRelMode==1)
			{	
				if(PropVal[mPV_HoldPresRel].DstOut!=PropVal[mPV_HoldPresRel].Limit)
					SetPV(eDAC_HoldPresRel,PropVal[mPV_HoldPresRel].Limit,0,100);		//最大输出
			}
			else if(Para_HoldPresPropRelMode==2)
			{	
				if(Act_MainFlow_DAUseChk(eDAC_MainPres))
				{	//主压力阀工作
					if(PropVal[mPV_HoldPresRel].DstOut!=PropVal[mPV_HoldPresRel].Limit)
						SetPV(eDAC_HoldPresRel,PropVal[mPV_HoldPresRel].Limit,0,100);	//最大输出
				}
				else
				{
					if(PropVal[mPV_HoldPresRel].DstOut!=0)
						SetPV(eDAC_HoldPresRel,0,0,100);								//关闭输出
				}
			}
			else//if(Para_HoldPresPropRelMode==0)
			{
				if(PropVal[mPV_HoldPresRel].DstOut!=0)
					SetPV(eDAC_HoldPresRel,0,0,100);									//关闭输出
			}
		}
		else
		{	//马达关
			if(PropVal[mPV_HoldPresRel].DstOut!=0)
				SetPV(eDAC_HoldPresRel,0,0,100);										//关闭输出
		}
	}
	else
	{	//保压溢流比例阀使用：保压1-10，eDAC_HoldPresRel在AU_Inject.c中与保压动作同步输出
	}
}
/****************************************************************************************************
函数名称：	“注射压力比例阀”处理
函数说明：
输入参数：	
返 回 值：	
其    它：
1、注射压力比例阀：天剑快速机用，当注射1－10时按照系统压力输出（此时驱动器工作于流量模式，压力由该比例
                   阀控制，以模拟定量泵工作方式），其它时候根据机参“注射压力比例阀工作模式”输出，通常
                   是常开。

注：20130517加。
****************************************************************************************************/
void PVInjectPres_Pcs(void)
{
	if(!Act_MainFlow_DAUseChk(eDAC_InjectPres))
	{	//未使用注射压力比例阀，即非注射动作
		if(MotorIsOn())
		{	//马达开
			
			//工作模式：0＝平常最大 	1＝平常关闭		2＝有动作最大
			if(Para_InjPresPropValMode==0)
			{	
				if(PropVal[mPV_InjectPres].DstOut!=PropVal[mPV_InjectPres].Limit)
					SetPV(eDAC_InjectPres,PropVal[mPV_InjectPres].Limit,0,100);		//最大输出
			}
			else if(Para_InjPresPropValMode==2)
			{	
				if(Act_MainFlow_DAUseChk(eDAC_MainPres))
				{	//主压力阀工作
					if(PropVal[mPV_InjectPres].DstOut!=PropVal[mPV_InjectPres].Limit)
						SetPV(eDAC_InjectPres,PropVal[mPV_InjectPres].Limit,0,100);	//最大输出
				}
				else
				{
					if(PropVal[mPV_InjectPres].DstOut!=0)
						SetPV(eDAC_InjectPres,0,0,100);								//关闭输出
				}
			}
			else//if(Para_InjPresPropValMode==1)
			{
				if(PropVal[mPV_InjectPres].DstOut!=0)
					SetPV(eDAC_InjectPres,0,0,100);									//关闭输出
			}
		}
		else
		{	//马达关
			if(PropVal[mPV_InjectPres].DstOut!=0)
				SetPV(eDAC_InjectPres,0,0,100);								//关闭输出
		}
	}
	else
	{	//使用注射压力比例阀，即注射1-10时		该比例阀输出根据注射1－10压力（在AU_Inject.c中）
	}
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
