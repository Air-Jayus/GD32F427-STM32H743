/***************************************************************
						常 用 定 义
说    明:定义一些常用常量，常用数据类型
文 件 名:Userdef.h
编制时间:2006.06.08
编 制 人:cxq
***************************************************************/
#ifndef AuxDef_h
	#define AuxDef_h



typedef	unsigned char  Bit;		/*位变量	*/
typedef	unsigned char  Bool;	/*布尔变量	*/
typedef unsigned char  U8;		/* defined for unsigned 8-bits integer variable 	无符号8位整型变量  */
typedef signed   char  S8;		/* defined for signed 8-bits integer variable		有符号8位整型变量  */
typedef unsigned short U16;		/* defined for unsigned 16-bits integer variable 	无符号16位整型变量 */
typedef signed   short S16;		/* defined for signed 16-bits integer variable 		有符号16位整型变量 */
typedef unsigned int   U32;		/* defined for unsigned 32-bits integer variable 	无符号32位整型变量 */
typedef signed   int   S32;		/* defined for signed 32-bits integer variable 		有符号32位整型变量 */
typedef unsigned long long U64;	/* defined for unsigned 64-bits integer variable 	无符号64位整型变量 */
typedef signed   long long S64;	/* defined for signed 32-bits integer variable 		有符号64位整型变量 */
typedef float          F32;		/* single precision floating point variable (32bits) 单精度浮点数（32位长度） */
typedef double         D64;		/* double precision floating point variable (64bits) 双精度浮点数（64位长度） */

#define SetBit(d,n)	d=d|((U32)1<<n)			//位设置
#define ClrBit(d,n)	d=d&(~((U32)1<<n))		//位清除
#define GetBit(d,n)	(d&((U32)1<<n))			//位读取：得到某位的值
#define ChkBit(d,n) (d&((U32)1<<n))			//位检查：判断某位是否为1
	
#define GetU8_L1(d) ((U8)d)				//得到最低字节
#define	GetU8_L2(d) ((U8)(d>>8))		//得到次低字节
#define	GetU8_L3(d) ((U8)(d>>16))		//得到次高字节
#define	GetU8_L4(d) ((U8)(d>>24))		//得到最敲字节

#define GetU16_L1(d) ((U16)d)			//得到最低字
#define GetU16_L2(d) ((U16)(d>>16))		//得到次低字


#define mBit0	0x00000001
#define mBit1	0x00000002
#define mBit2	0x00000004
#define mBit3	0x00000008
#define mBit4	0x00000010 
#define mBit5	0x00000020
#define mBit6	0x00000040
#define mBit7	0x00000080
#define mBit8	0x00000100
#define mBit9	0x00000200
#define mBit10	0x00000400
#define mBit11	0x00000800
#define mBit12	0x00001000
#define mBit13	0x00002000
#define mBit14	0x00004000
#define mBit15	0x00008000
                 
#define mBit16	0x00010000
#define mBit17	0x00020000
#define mBit18	0x00040000
#define mBit19	0x00080000
#define mBit20	0x00100000
#define mBit21	0x00200000
#define mBit22	0x00400000
#define mBit23	0x00800000
#define mBit24	0x01000000
#define mBit25	0x02000000
#define mBit26	0x04000000
#define mBit27	0x08000000
#define mBit28	0x10000000
#define mBit29	0x20000000
#define mBit30	0x40000000
#define mBit31	0x80000000

#define mBitA	0x00000400
#define mBitB	0x00000800
#define mBitC	0x00001000
#define mBitD	0x00002000
#define mBitE	0x00004000
#define mBitF	0x00008000

#define FALSE	0
#define TRUE	1

#define mFalse	0
#define mTrue	1

#define False	0
#define True	1

#define mLow	0
#define mHigh	1

#define mNull	0

#define Min(a,b)	(((a)<(b))?(a):(b))
#define Max(a,b)	(((a)>(b))?(a):(b))
	
#define Sub_Abs(a,b)		(((a)>(b))?((a)-(b)):((b)-(a)))	//减		绝对值
#define Sub_MinZero(a,b) 	(((a)>(b))?((a)-(b)):0)			//减		最小为0		相减为负则返回0

#define Abs(x)		((x<0)?(0-x):x)


#define DisableIRQ()		__disable_irq()		//禁止全部中断
#define EnableIRQ()			__enable_irq()		//使能全部中断
#define DisPerIRQ(a)		NVIC_DisableIRQ(a)	//禁止某个中断
#define EnPerIRQ(a)			NVIC_EnableIRQ(a)	//使能某个中断

#endif
