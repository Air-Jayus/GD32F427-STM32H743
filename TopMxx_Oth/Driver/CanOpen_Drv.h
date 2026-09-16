/* Copyright (C) 2019 *******************************************************************************
									 1
=====================================================================================================
项目名称：流程控制器
项目简介：

======================================== 文   件    信   息 ========================================
文件名称：CanOpen_Drv.h
文件说明：CanOpen驱动

作    者：
编写时间：
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================



****************************************************************************************************/
#ifndef CanOpen_Drv_h
	#define CanOpen_Drv_h

#ifdef CanOpen_Drv_c
	#define CanOpen_Drv_ext
#else
	#define CanOpen_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/

#define mSDOOverTime			5000			//SDO返回超时间定义

	#define mCO_PDO1Ret			0x180	//功能码	PDO1接收ID
	#define mCO_PDO2Ret			0x280	//功能码	PDO2接收ID
	#define mCO_PDO3Ret			0x380	//功能码	PDO3接收ID
	#define mCO_PDO4Ret			0x480	//功能码	PDO4接收ID
	#define mCO_PDORetMask		0x780	//PDO答复滤波掩码
	
	#define mCO_SDOCode		0x600	//功能码	SDO写功能码
	#define mCO_SDORet			0x580	//功能码	SDO接收ID
	#define mCO_SDORetMask		0x780	//SDO答复滤波掩码
	
	#define mCO_NodeGuard		0x700	//功能码	节点保护接收ID
	#define mCO_NodeGuardMask	0x780	//SDO答复滤波掩码

typedef void (* PDOPcsFunP)(CanMessStr);	//动作函数指针类型--PDO接收数据回调
typedef void (* OverTPcsFunP)(void );		//动作函数指针类型--节点保护超时回调


enum eSDORlt{eSDORlt_Null,eSDORlt_Fail,eSDORlt_OverT,eSDORlt_Succ,eSDORlt_Wait};

enum eRlt{eRlt_Ok,eRlt_Fail,eRlt_Wait};			//执行结果

enum eCanWR{eCanWR_NO,eCanWR_RO,eCanWR_WO,eCanWR_RW};
//eEcWR_NO    SDO参数不可读可写
//eEcWR_RO    SDO参数只读
//eEcWR_WO    SDO参数只写
//eEcWR_RW    SDO参数可读可写
typedef const struct
{
	F32				Scale;		//比例因子
	enum eCanWR		ParaWR;		//参数读写权限
	//U16				SalveSn;	//从站编号
	U16				Index;		//索引
	U16				SubIndex;	//子索引
	U16             DataSize;	//数据长度	
	
	U16				*pDa;		//数据
}CanSdoStateStr;		//状态SDO结构定义

typedef const struct
{
	F32				Scale;		//比例因子
	enum eCanWR		ParaWR;		//参数读写权限
	//U16				SalveSn;	//从站编号
	U16				Index;		//索引
	U16				SubIndex;	//子索引
	U16             DataSize;	//数据长度	
	
	U32				*pDa;		//数据
}CanSdoParaStr;		//参数结构定义
	
/*======================================== 全局有效变量定义 =======================================*/

CanOpen_Drv_ext	U8 CanOpenComStep[2];		//CANOpen运行状态
	#define mCO_Inition		0		//初始化状态
	#define mCO_PreOption	1		//预运行状态
	#define mCO_Option		2		//运行状态
	#define mCO_WaitReinit	3		//等待重新进行  初始化->预运行->运行状态

typedef const struct
{
	U16	InhtTime;	//抑制时间
	U16	EvenTime;	//事件时间
	U8	TranType;	//传输类型
}PDOParaConfStr;	//PDO参数配置

typedef const struct
{
	U16	Index;		//索引
	U8	SubIndex;	//子索引
	U8	BitNum;		//数据位数
}PDOMapConfStr;		//PDO映射配置

/*======================================== 全局有效函数声明 =======================================*/
void CanOpenDrv_Init(U8 CanSn);
Bool CanOpenAddPDOCallBack(U8 CanChan,U32 PDOID,PDOPcsFunP CallBack);
Bool CanOpenAddNodeGuardCallBack(U8 CanChan,U32 ID,U32 OverT,OverTPcsFunP CallBack);
enum eSDORlt CanOpenSDOReadSuccChk(U8 CanChan,U32 *Dat);
Bool CanOpenSDORead(U8 CanChan,U32 Ind,U8 SubInd,U8 Len,U32 Dat,U8 Add);
enum eSDORlt CanOpenSDOWriteSuccChk(U8 CanChan);
Bool CanOpenSDOWrite(U8 CanChan,U32 Ind,U8 SubInd,U8 Len,U32 Dat,U8 Add);
enum eRlt CanOpenClrPDOConfigPcs(U8 CanSn,U8 Add,U8 PdoSn,U8 PdoNum);
enum eRlt CanOpenSPDOMapConfPcs(U8 CanSn,U8 PDOSn,U8 Add,Bool StartFlag,U8 ObjNum,PDOMapConfStr* pPDOP);
enum eRlt CanOpenSPDOParaConfPcs(U8 CanSn,U8 PDOSn,U8 Add,Bool StartFlag,PDOParaConfStr* pPDOP);
enum eRlt CanOpenRPDOMapConfPcs(U8 CanSn,U8 PDOSn,U8 Add,Bool StartFlag,U8 ObjNum,PDOMapConfStr* pPDOP);
enum eRlt CanOpenRPDOParaConfPcs(U8 CanSn,U8 PDOSn,U8 Add,Bool StartFlag,PDOParaConfStr* pPDOP);
void CanOpenDrv_Pcs(void);
Bool CanOpenNodePre(U8 CanChan);
Bool CanOpenNodeOpt(U8 CanChan);
Bool CanOpenSYNC(U8 CanChan,U32 ID);
Bool CanOpenNodeGuard(U8 CanChan,U32 ID);
Bool CanOpenPDO(U8 CanChan,CanMessStr * CanBuff);
void StartNodeGuard(U8 CanSn);

#endif

