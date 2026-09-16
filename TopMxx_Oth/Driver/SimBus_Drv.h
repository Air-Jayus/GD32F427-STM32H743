/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：xxxx.h
文件说明：模拟总线的文件

作    者：WLZ
编写时间：2014.5
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================



****************************************************************************************************/
#ifndef SimBus_Drv_h
	#define SimBus_Drv_h

#ifdef SimBus_Drv_c
	#define SimBus_Drv_ext
#else
	#define SimBus_Drv_ext extern
#endif
/*========================================= 全局有效宏定义 ========================================*/

#define mSBA_DOOutReg0			0x0001	//CPLD DO	W	DO输出寄存器0
#define mSBA_DOOutReg1			0x0002	//			W	DO输出寄存器1
#define mSBA_DOOutReg2			0x0003	//			W	DO输出寄存器2
#define mSBA_DOOutReg3			0x0004	//			W	DO输出寄存器3
#define mSBA_DOOutReg4			0x0005	//			W	DO输出寄存器4
#define mSBA_DOOutReg5			0x0006	//			W	DO输出寄存器5
#define mSBA_DOOutReg6			0x0007	//			W	DO输出寄存器6

#define mSBA_DIDOPwrProtRst	0x0008  //			W	IO电源保护复位	即状态Bit0位复位
#define mSBA_DIDOPwrSta			0x0008	//			R	IO电源状态		Bit1:电源正常标志(0-正常 1-异常)	Bit0:输出禁止标志(0-允许 1-禁止)  
										//(未加电DO不允许输出，不然无电时DO输出MOS管短路在那里，上电后一直保存短路，H+24_OLP引脚不会变高，无法检出上电过程)
#define mSBA_PlatLinkCodeReg 0x000B //			R	硬件平台互连代码寄存器	
	
#define mSBA_DIInReg0				0x000C	//CPLD DI	R	DI输入寄存器0	IN00~IN07
#define mSBA_DIInReg1				0x000D	//			R	DI输入寄存器1	IN08~IN15
#define mSBA_DIInReg2				0x000E	//			R	DI输入寄存器2	IN16~IN23
#define mSBA_DIInReg3				0x000F	//			R	DI输入寄存器3	IN24~IN31
#define mSBA_DIInReg4				0x0010	//			R	DI输入寄存器4	IN32~IN39
#define mSBA_ReserveReg			0x0011	//			R	备用
#define	mSBA_Counter1				0x0013	//			R	计数器1			B18点	调模电眼计数		4位、双向计数（上升沿和下降沿均计数）
#define	mSBA_Counter2				0x0014	//			R	计数器2			B17点	螺杆转速电眼计数
#define mSBA_ProdSnrTri			0x0015	//			RW	检物电眼触发器	Bit0:对应X18		Bit1:对应X29

#define	mSBA_RlyOutReg0			0x0016	//			W	继电器输出寄存器0
#define	mSBA_RlyOutReg1			0x0017	//			W	继电器输出寄存器1

#define mSBA_DAC1DataL			0x0018	//			W	DAC通道0 数据寄存器低字节
#define mSBA_DAC1DataH			0x0019	//			W	DAC通道0 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC2DataL			0x001A	//			W	DAC通道1 数据寄存器低字节	
#define mSBA_DAC2DataH			0x001B	//			W	DAC通道1 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC3DataL			0x001C	//			W	DAC通道2 数据寄存器低字节	
#define mSBA_DAC3DataH			0x001D	//			W	DAC通道2 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC4DataL			0x001E	//			W	DAC通道3 数据寄存器低字节	
#define mSBA_DAC4DataH			0x001F	//			W	DAC通道3 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC5DataL			0x0020	//			W	DAC通道4 数据寄存器低字节	
#define mSBA_DAC5DataH			0x0021	//			W	DAC通道4 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC6DataL			0x0022	//			W	DAC通道5 数据寄存器低字节	
#define mSBA_DAC6DataH			0x0023	//			W	DAC通道5 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC7DataL			0x0024	//			W	DAC通道6 数据寄存器低字节	
#define mSBA_DAC7DataH			0x0025	//			W	DAC通道6 数据寄存器高字节（最高位代表极性0-正极）
#define mSBA_DAC8DataL			0x0026	//			W	DAC通道7 数据寄存器低字节	
#define mSBA_DAC8DataH			0x0027	//			W	DAC通道7 数据寄存器高字节（最高位代表极性0-正极）

/*======================================== 全局有效变量定义 =======================================*/


/*======================================== 全局有效函数声明 =======================================*/
void SimBus_Drv_Init(void);				//模拟总线初始化
U8 SB_ReadData(U16 Addr);				//模拟总线读数据		
void SB_WriteData(U16 Addr,U8 Buff);	//模拟总线写数据		

#endif

