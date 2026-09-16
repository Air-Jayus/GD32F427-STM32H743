/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：xxxxxx
文件说明：xxxxxx

作    者：CXQ
编写时间：2009.11
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================



****************************************************************************************************/
#ifndef Position_h
	#define Position_h

#ifdef Position_c
	#define Position_ext
#else
	#define Position_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
#define PosMdlOKChk()				(HADC_PwrChk()&&HADC_ModuleChk())	//位置尺模块工作正常检查	mTrue--正常

/*======================================== 全局有效变量定义 =======================================*/
Position_ext U16 MoldThickValue_NO;		//无偏移的模厚值		画面显示模厚值需要加上偏移量，故设该变量中转
Position_ext S32 CurMoldCylSped;		//当前模板油缸速度 速度单位为	um/10mS   正数表示开模，负数表示关模	20171214

Position_ext U32	KalmanAD;
/*======================================== 全局有效函数声明 =======================================*/
void Position_Init(void);						//位置初始化		
void Position_Pcs(void);						//位置处理					于主循环


void PosRefReq(void);							//位置刷新请求	位置尺归零或长度修改后发出，申请立即刷新位置

Bool PosOverChk_CM(U32 SetPos);					//关模时过某位置检查
Bool PosOverChk_OM(U32 SetPos);					//开模时过某位置检查

Bool PosOverChk_Inj(U32 SetPos);				//射出时过某位置检查
Bool PosOverChk_Chg(U32 SetPos);				//储料时过某位置检查
Bool PosOverChk_Suck(U32 SetPos);				//射退时过某位置检查

Bool PosOverChk_EjeRet(U32 SetPos);				//顶退时过某位置检查
Bool PosOverChk_EjeFor(U32 SetPos);				//顶进时过某位置检查

Bool PosOverChk_NozRet(U32 SetPos);				//座退时过某位置检查
Bool PosOverChk_NozFor(U32 SetPos);				//座进时过某位置检查

Bool PosOverChk_MoldThick(U32 SetPos);			//模具调厚时过某位置检查		函数内与不含偏移量的位置比较，因此SetPos要额外减去偏移量
Bool PosOverChk_MoldThin(U32 SetPos);			//模具调薄时过某位置检查		函数内与不含偏移量的位置比较，因此SetPos要额外减去偏移量

Bool PosInAreaChk_Mold(U32 SetPos,U32 Area);	//模板在某范围内检查
Bool PosInAreaChk_Screw(U32 SetPos,U32 Area);	//螺杆在某范围内检查
Bool PosInAreaChk_Eje(U32 SetPos,U32 Area);		//顶针在某范围内检查
Bool PosInAreaChk_Noz(U32 SetPos,U32 Area);		//座台在某范围内检查

S32 GetMold_MoldPos(void);		//获取位置		单位1um	相对零点,有符号		模板位置，安装在油缸则会转换到模板
S32 GetMold_CylPos(void);		//获取位置		单位1um	相对零点,有符号		油缸位置				主要归零时调用
U32 GetMold_CylAbsPos(void);	//获取绝对位置	单位1um	无符号				油缸位置				主要归零时调用
S32 GetScrewPos(void);			//获取位置		单位1um	相对零点,有符号								主要归零时调用
U32 GetScrewAbsPos(void);		//获取绝对位置	单位1um	无符号										主要归零时调用
S32 GetEjectPos(void);			//获取位置		单位1um	相对零点,有符号								主要归零时调用
U32 GetEjectAbsPos(void);		//获取绝对位置	单位1um	无符号										主要归零时调用
S32 GetNozPos(void);			//获取位置		单位1um	相对零点,有符号								主要归零时调用
U32 GetNozAbsPos(void);			//获取绝对位置	单位1um	无符号										主要归零时调用
S32 GetMoldThickPos(void);		//获取位置		单位1um	相对零点,有符号								主要归零时调用
U32 GetMoldThickAbsPos(void);	//获取绝对位置	单位1um	无符号										主要归零时调用

S32 GetHAI1Value(void);			//获取模拟量1值			相对零点,有符号		模拟量HAI1-3，借用位置尺一并处理
U32 GetHAI1AbsValue(void);		//获取模拟量1绝对值		无符号
S32 GetHAI2Value(void);			//获取模拟量2值			相对零点,有符号
U32 GetHAI2AbsValue(void);		//获取模拟量2绝对值		无符号
S32 GetHAI3Value(void);			//获取模拟量3值			相对零点,有符号
U32 GetHAI3AbsValue(void);		//获取模拟量3绝对值		无符号



//以下函数不建议直接引用，最好通过上面的宏定义进行调用

S32 CylPosToMoldPos(S32 CPos);	//油缸位置转换成模板位置		主要用于模板位置显示、位置在范围内比较
U32 MoldPosToCylPos(U32 MPos);	//模板位置转换成油缸位置

void MoldCylSpedCalInit(void);	//模板油缸速度计算初始化	20171214 增加
void MoldCylSpedCalPcs(void);	//模板油缸速度计算主函数	20171214 增加

#endif

