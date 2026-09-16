/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：Ecat_Drv.h
文件说明：EathrCAT驱动

作    者：LC
编写时间：2019.9
======================================== 修   改    历   史 =========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 =========================================


****************************************************************************************************/
#ifndef Ecat_Drv_h
	#define Ecat_Drv_h

#ifdef Ecat_Drv_c
	#define Ecat_Drv_ext
#else
	#define Ecat_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/
#define PhaseOffsetTime 250000		//EtherCAT同步时钟相位偏移调整目标值

//EtherCAT 时钟
#define EcTimeClk			100000000			//EtherCAT时钟系统频率	1MHz的整数倍，至少要10MHz
#define EcSysTime			TIMER_CNT(TIMER4)	//EtherCAT系统时间		实际直接使用Time3中的值，计时单位1us
#define GetEcSysTime()		EcSysTime
#define	SetEcatTimerMateOffset(a)	TIMER_CH0CV(TIMER4)=(TIMER_CNT(TIMER4)+(a))	//设置定时器2匹配偏移值

#define mTime1usTran1ns(a)	(a*1000)				//时间1us到1nS转换

//#define mEcatPDOCycle		1000LL		//EcatPDO循环周期为1000uS，即控制周期 
//#define mEcatTimerPDOCycle	(mEcatPDOCycle*(EcTimeClk/1000000))		//EcatPDO循环周期为1000uS转换成Timer3定时器值
//#define mEcatTimerPDOAdjMin	((mEcatPDOCycle-2)*(EcTimeClk/1000000))	//EcatPDO主站时钟同步调节下限-2uS
//#define mEcatTimerPDOAdjMax	((mEcatPDOCycle+2)*(EcTimeClk/1000000))	//EcatPDO主站时钟同步调节上限+2uS
#define mEcatTimerPDOCycle	(Para_EtherCATCyc*(EcTimeClk/1000000))		//EcatPDO循环周期为1000uS转换成Timer5定时器值
#define mEcatTimerPDOAdjMin	((Para_EtherCATCyc-2)*(EcTimeClk/1000000))	//EcatPDO主站时钟同步调节下限-2uS
#define mEcatTimerPDOAdjMax	((Para_EtherCATCyc+2)*(EcTimeClk/1000000))	//EcatPDO主站时钟同步调节上限+2uS


#define Time_now         (DCt32(0))                     //分布时钟的当前时间


//从Slave角度定义
#define mSlaveEcatNumMax	EC_MAXSLAVE		//系统中Ecat从站数量最大值  4

//从站类型	1-KEB驱动器全电应用，2-汇川驱动器全电应用，10-J6卡混电应用，11-J6卡液压机应用
#define	mSType_Null				0	//无
#define mSType_J6H				1	//J6H卡液压机应用

/*======================================== 全局有效变量定义 =======================================*/
enum eEcSR{eEcSR_Ok,eEcSR_Fail,eEcSR_Do,};
//eEcSR_Do		SDO正在读写操作过程中
//eEcSR_Ok		SDO读写成功
//eEcSR_Fail	SDO读写失败
//PDO帧中读写SDO
enum eEcWR{eEcWR_NO,eEcWR_RO,eEcWR_WO,eEcWR_RW};
//eEcWR_NO    SDO参数不可读可写
//eEcWR_R0    SDO参数只读
//eEcWR_WO    SDO参数只写
//eEcWR_RW    SDO参数可读可写
typedef struct
{
	//enum eEcOT		SdoType;	//0-无SDO在读写		1-将要进行SDO读		2-将要进行SDO写
	enum eEcSR		Result;		//SDO操作执行结果	
	enum eEcSR	* 	UseResult;	//SDO操作执行结果--应用程序调用
	enum eEcWR		ParaWR;//参数读写权限
	U16				SalveSn;	//从站编号
	U16				Index;		//索引
	U16				SubIndex;	//子索引
	U16             DataSize;	//数据长度
	
	U32				*pDa;		//数据
}EcSdoStr;

Ecat_Drv_ext EcSdoStr	EcSdo;

typedef struct
{
	enum eEcSR		Result;		//SDO操作执行结果	
	enum eEcSR	* 	UseResult;	//SDO操作执行结果--应用程序调用
	enum eEcWR		ParaWR;//参数读写权限
	U16				SalveSn;	//从站编号
	U16				Index;		//索引
	U16				SubIndex;	//子索引
	U16             DataSize;	//数据长度
	F32				Scale;		//比例因子
	
	U32				*pDa;		//数据
}EcTSdoStr;
/** define struct of DC time  */
typedef union 
{
	U64  d; 
	U32  a[2];
	U16  b[4];
	U8   c[8];
} ec_SYT;
Ecat_Drv_ext ec_SYT      pdo_SYtime;
#define SYt64       pdo_SYtime.d
#define SYt32(x)    pdo_SYtime.a[x]
#define SYt16(x)    pdo_SYtime.b[x]
#define SYt8(x)     pdo_SYtime.c[x]
#define SY_t        pdo_SYtime.c

Ecat_Drv_ext U8 mapmbx;
Ecat_Drv_ext U8 RecIdx;
Ecat_Drv_ext U16 SlaveState;		//当前从站工作状态，所有从站求或得到
								//1-初始化；2-预运行；4-安全运行；8-运行状态

#ifdef Ecat_Drv_c
	Ecat_Drv_ext U8 CurrEcatState=0;	//当前Ecat总线状态
#else
	Ecat_Drv_ext U8 CurrEcatState;		//当前Ecat总线状态
#endif
	#define mEcatPhyOff		0		//网口断开
	#define mEcatPhyOnDly	1		//Phy芯片连接后等待
	#define mEcatSyncPDO	2		//从安全运行模式请求进入运行模式
	#define mEcatCheckOP	3		//检查等待从站进入OP模式
	#define mEcatOpertion	4		//进入OP，进行运行控制模式
	#define mEcatFail		5		//EtherCAT从站连接失败或无没有检测到从站

Ecat_Drv_ext Bool EPDO_SendFlag;		//EtherCAT PDO数据启动发送标志
Ecat_Drv_ext Bool EPDO_RecFlag;			//EtherCAT PDO数据接收完成标志
Ecat_Drv_ext U32  EPDO_SendTime;		//EtherCAT PDO数据启动发送时间
Ecat_Drv_ext U32  EPDO_RecTime;			//EtherCAT PDO数据接收完成时间
Ecat_Drv_ext U8   SetSlaveNum;      //设置连接的Ecat从站数量
/*======================================== 全局有效函数声明 =======================================*/
U32 GetEcatSlaveSlaveType(U8 Slave);
U32 GetEcatSlavePdoInSize(U8 Slave);
U32 GetEcatSlavePdoOutSize(U8 Slave);
U8 * GetEcatSlavePdoInBuff(U8 Slave);
U8 * GetEcatSlavePdoOutBuff(U8 Slave);
void Ecat_Drv_Init(void);	//Ecat_Mast初始化
void Ecat_Drv_Pcs(void);		//Ecat_Mast处理函数
Bool Sync(void);
Bool Ecat_Pdo_Send(U8 num); //PDO发送函数	

void EcPdo_SdoWrite(enum eEcSR *Result,U16 Sn,U16 Index,U16 SubIndex,U16 psize,U32 *pDa);
void EcPdo_SdoRead(enum eEcSR *Result,U16 Sn,U16 Index,U16 SubIndex,U32 *pDa);

#define EcatLinkChk()	(CurrEcatState==mEcatOpertion)

#endif

