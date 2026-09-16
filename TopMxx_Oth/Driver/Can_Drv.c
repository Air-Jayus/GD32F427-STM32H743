/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：Can_Drv.c
文件说明：CAN驱动文件

作    者：WLZ
编写时间：2025.4
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：

CiA推荐的采样点位置：  
75% 	when 波特率> 800K 
80% 	when 波特率> 500K 
87.5% 	when 波特率<= 500K 
采样点位置计算公式：
(BS1+1)/(BS1+BS2+1)

总线错误配置成硬件自动恢复，总线关闭后一旦监测到 128 次连续 11 个隐性位，即通过硬件自动退出总线关闭状态。
MCR寄存中的ABOM位设置成1即可。
总线关闭后，CAN仍可缓存3帧数，待总线恢复后发出。即总线关闭后前3次调用CanSendMessage函数回返回True。
======================================== 其   它    说   明 ========================================


****************************************************************************************************/
//#define mSysDebug		

#ifndef Can_Drv_c
	#define Can_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
//20170113	增加界面与CBox之间数据传送，由主机通过CAN口转发功能
typedef void (* RxCanCallBackP)(CanMessStr*);
typedef void (* TxCanCallBackP)(void);

#define mIRQHandlerNum	2			//20170705	允许同时有效IRQ回调函数的个数
struct
{
	RxCanCallBackP RxIRQHandlerP[mIRQHandlerNum];	//CAN接收中断回调函数	B
	U8   RxIRQHandlerCnt;							//CAN接收中断个数（回调函数个数）
}CanRxIRQ[2];							//20170705	CAN接收中断配置
struct
{
	TxCanCallBackP TxIRQHandlerP[mIRQHandlerNum];	//CAN发送中断回调函数	
	U8   TxIRQHandlerCnt;							//CAN发送收中断个数（回调函数个数）
}CanTxIRQ[2];							//20170705	CAN发送中断配置

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
int main(void)
{           
	do{
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
函数名称：	开关发送中断使能
函数说明：
输入参数：	U8 CanSN	……CAN通道，1-CAN1、2-CAN2
返 回 值：
其    它：
****************************************************************************************************/
void CanSendIrqEn(U32 CanSN)
{
	if(CanSN==mCC_CAN1)			can_interrupt_enable(CAN0, CAN_INTEN_TMEIE);		//发送邮箱空中断
	else if(CanSN==mCC_CAN2)	can_interrupt_enable(CAN1, CAN_INTEN_TMEIE);		//发送邮箱空中断
}
void CanSendIrqDis(U32 CanSN)
{
	if(CanSN==mCC_CAN1)			can_interrupt_disable(CAN0, CAN_INTEN_TMEIE);		//禁止发送中断
	else if(CanSN==mCC_CAN2)	can_interrupt_disable(CAN1, CAN_INTEN_TMEIE);		//禁止发送中断
}
/****************************************************************************************************
函数名称：	CAN初始化
函数说明：
输入参数：	U8 CanSN	……CAN通道，1-CAN1、2-CAN2
			U32 FIFO_C	……FIFO选择，0-FIFO_0; 1-FIFO_1;
			U32 Id		……滤波ID
			U32 Mask	……滤波掩码
			U32 Mode	……模式	0-32位ID+掩码模式，1-32位ID表（2个ID）,2-2组16位ID+掩码模式，3-16位ID表（4个ID）
返 回 值：
其    它：
1、CAN滤波器接收数据固定到FIFO0去，FIFO1暂时未用
2、4种滤波模式说明：
	0-32位ID+掩码模式；
	1-32位ID表（2个ID），
	2-2组16位ID+掩码模式，
	3-16位ID表，32位ID分为2个16位ID，
	考虑际使用情况，只做了16位ID+掩码模式，一个滤波块可以支持两个ID标准帧滤波，使用方法：
		例：Can_AddAnFilter(mCC_CAN1,0x1ff,0x7ff,0)，表示ID部分为1FF，表示掩码部分为7FE		
****************************************************************************************************/
Bool Can_AddAnFilter(U32 CanSN,U32 Id,U32 Mask,U32 Mode)
{	
	static U8 FilterCnt1=0,FilterCnt2=CAN2_StartBank;
	static U16 LastID1,LastMask1,LastID2,LastMask2;
    can_filter_parameter_struct can_filter;
    
	Mode=Mode;
	if(CanSN==mCC_CAN1)
	{
		if((FilterCnt1>>1)<CAN2_StartBank)
		{	
			//initialize filter 
    		can_filter.filter_number = FilterCnt1>>1;
    		can_filter.filter_mode = CAN_FILTERMODE_MASK;
    		can_filter.filter_bits = CAN_FILTERBITS_16BIT;
    		if((FilterCnt1&mBit0)==0)
    		{
    			can_filter.filter_list_low = (Id<<5);
    			can_filter.filter_mask_low = (Mask<<5);
    			can_filter.filter_list_high = (0x0000<<5);           //左对齐
    			can_filter.filter_mask_high = (0x0000<<5);
    			LastID1=Id;
				LastMask1=Mask;
    		}
    		else
    		{
    			can_filter.filter_list_low = (LastID1<<5);
    			can_filter.filter_mask_low = (LastMask1<<5);
    			can_filter.filter_list_high = (Id<<5);           //左对齐
    			can_filter.filter_mask_high = (Mask<<5);
    		}
    		can_filter.filter_fifo_number = CAN_FIFO0;	//只使用FIFO0
    		can_filter.filter_enable = ENABLE;
    		can_filter_init(&can_filter);
			FilterCnt1++;
		}
		else
			return mFalse;
	}
	else if(CanSN==mCC_CAN2)
	{
		if((FilterCnt2>>1)<CAN_FiltBankEnd)
		{	
			//initialize filter 
    		can_filter.filter_number = CAN2_StartBank+((FilterCnt2-CAN2_StartBank)>>1);
    		can_filter.filter_mode = CAN_FILTERMODE_MASK;
    		can_filter.filter_bits = CAN_FILTERBITS_16BIT;
    		if((FilterCnt2&mBit0)==0)
    		{
    			can_filter.filter_list_low = (Id<<5);
    			can_filter.filter_mask_low = (Mask<<5);
    			can_filter.filter_list_high = (0x0000<<5);           //左对齐
    			can_filter.filter_mask_high = (0x0000<<5);
    			LastID2=Id;
				LastMask2=Mask;
    		}
    		else
    		{
    			can_filter.filter_list_low = (LastID2<<5);
    			can_filter.filter_mask_low = (LastMask2<<5);
    			can_filter.filter_list_high = (Id<<5);           //左对齐
    			can_filter.filter_mask_high = (Mask<<5);
    		}
    		can_filter.filter_fifo_number = CAN_FIFO0;	//只使用FIFO0
    		can_filter.filter_enable = ENABLE;
    		can_filter_init(&can_filter);
			FilterCnt2++;
		}
		else
			return mFalse;
	}
	else
		return mFalse;
	return mTrue;
}
/****************************************************************************************************
函数名称：CAN发送报文
函数说明：
输入参数：

返 回 值：mTrue		发送成功，即加载到任一发送缓存
		  mFalse	发送失败，所有发送缓存在使用
其    它：
		最多可以缓存3帧待发送的帧
****************************************************************************************************/
Bool CanSendMessage(U32 CanSN,CanMessStr *CMP)
{
	U32 pCAN;
	U8 MailBox;
	
	if(CanSN==mCC_CAN1)		pCAN=CAN0;
	else if(CanSN==mCC_CAN2)pCAN=CAN1;
	else					return mFalse;
	
	/* select one empty mailbox */
    if(CAN_TSTAT_TME0 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME0)) 
        MailBox = CAN_MAILBOX0;
    else if(CAN_TSTAT_TME1 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME1)) 
        MailBox = CAN_MAILBOX1;
    else if(CAN_TSTAT_TME2 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME2)) 
        MailBox = CAN_MAILBOX2;
   	else	
   		return mFalse;
  	
  	CAN_TMI(pCAN, MailBox) 		&=CAN_TMI_TEN;	
  	
  	CAN_TMDATA0(pCAN, MailBox) 	=CMP->LData;
 	CAN_TMDATA1(pCAN, MailBox) 	=CMP->HData;
 	CAN_TMP(pCAN, MailBox)		=CMP->Head;
	CAN_TMI(pCAN, MailBox) 		=(TMI_SFID(CMP->ID)|CAN_TMI_TEN);
	return mTrue;
}
/****************************************************************************************************
函数名称：CAN远程报文
函数说明：
输入参数：

返 回 值：mTrue		发送成功，即加载到任一发送缓存
		  mFalse	发送失败，所有发送缓存在使用
其    它：
		最多可以缓存3帧待发送的帧
****************************************************************************************************/
Bool CanSendMessageRTR(U32 CanSN,U32 ID)
{
	U32 pCAN;
	U8 MailBox;
	
	if(CanSN==mCC_CAN1)		pCAN=CAN0;
	else if(CanSN==mCC_CAN2)pCAN=CAN1;
	else					return mFalse;
	
	/* select one empty mailbox */
    if(CAN_TSTAT_TME0 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME0)) 
        MailBox = CAN_MAILBOX0;
    else if(CAN_TSTAT_TME1 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME1)) 
        MailBox = CAN_MAILBOX1;
    else if(CAN_TSTAT_TME2 == (CAN_TSTAT(pCAN)&CAN_TSTAT_TME2)) 
        MailBox = CAN_MAILBOX2;
   	else	
   		return mFalse;
  	
  	CAN_TMI(pCAN, MailBox) 		&=CAN_TMI_TEN;	
  	
  	//CAN_TMDATA0(pCAN, MailBox) 	=CMP->LData;
 	//CAN_TMDATA1(pCAN, MailBox) 	=CMP->HData;
 	CAN_TMP(pCAN, MailBox)		=0;
	CAN_TMI(pCAN, MailBox) 		=(TMI_SFID(ID)|CAN_TMI_FT|CAN_TMI_TEN);
	return mTrue;
}
/****************************************************************************************************
函数名称：CAN接收报文
函数说明：
输入参数：MailSN	指定接收邮箱序号 0--邮箱0(FIFO0)    1--邮箱1(FIFO1)

返 回 值：mTrue		接收成功，即加载到任一发送缓存
		  mFalse	接收失败，所有FIFO的帧都已经被读出
其    它：
		  ID右移21位已经处理
****************************************************************************************************/
Bool CanRecMessage(U32 CanSN,U8 MailSN,CanMessStr *CMP)
{
	U32	pCAN;	
	
	if(CanSN==mCC_CAN1)		pCAN=CAN0;
	else if(CanSN==mCC_CAN2)pCAN=CAN1;
	else					return mFalse;	
  	
  	if((MailSN==0)&&(CAN_RFIFO0(pCAN) & CAN_RFIF_RFL_MASK))
  	{	
  		CMP->LData	=CAN_RFIFOMDATA0(pCAN, MailSN);
 		CMP->HData	=CAN_RFIFOMDATA1(pCAN, MailSN);
 		CMP->Head	=GET_RFIFOMP_DLENC(CAN_RFIFOMP(pCAN, MailSN));
		CMP->ID		=GET_RFIFOMI_SFID(CAN_RFIFOMI(pCAN, MailSN));
		CAN_RFIFO0(pCAN) |= CAN_RFIFO0_RFD0;//释放
		return mTrue;
	}
	else if((MailSN==1)&&(CAN_RFIFO1(pCAN) & CAN_RFIF_RFL_MASK))
  	{	
  		CMP->LData	=CAN_RFIFOMDATA0(pCAN, MailSN);
 		CMP->HData	=CAN_RFIFOMDATA1(pCAN, MailSN);
 		CMP->Head	=GET_RFIFOMP_DLENC(CAN_RFIFOMP(pCAN, MailSN));
		CMP->ID		=GET_RFIFOMI_SFID(CAN_RFIFOMI(pCAN, MailSN));
		CAN_RFIFO1(pCAN) |= CAN_RFIFO1_RFD1;//释放
		return mTrue;
	}
	else
		return mFalse;
}
/****************************************************************************************************
函数名称：	添加一个接收中断回调函数
函数说明：
输入参数：	U8 CanSN	……CAN通道，1-CAN1、2-CAN2
			void (*IRQHandler)()……中断服务程序入口地址
返 回 值：
其    它：
			固定使用FIFO0中断
****************************************************************************************************/
Bool AddAnCanRxIrq(U32 CanSN, void (* CallBackP)())
{
	if((CanSN<2)&&(CanRxIRQ[CanSN].RxIRQHandlerCnt<mIRQHandlerNum))
	{	
		CanRxIRQ[CanSN].RxIRQHandlerP[CanRxIRQ[CanSN].RxIRQHandlerCnt]=CallBackP;	//CAN接收中断回调函数
		CanRxIRQ[CanSN].RxIRQHandlerCnt++;											//CAN接收中断个数（回调函数个数）
		
		if(CanSN==mCC_CAN1)
		{
			nvic_irq_enable(CAN0_RX0_IRQn, mIRQPriorityL, mIRQPriorityL);
			can_interrupt_enable(CAN0, CAN_INTEN_RFNEIE0);		//FIFO0中
		}
		else //if(CanSN==mCC_CAN2)
		{
			nvic_irq_enable(CAN1_RX0_IRQn, mIRQPriorityL, mIRQPriorityL);
			can_interrupt_enable(CAN1, CAN_INTEN_RFNEIE0);		//FIFO0中
		}	
		
		return mTrue;
	}
	return mFalse;
}
/****************************************************************************************************
函数名称：	添加一个发送中断回调函数
函数说明：
输入参数：	U8 CanSN	……CAN通道，1-CAN1、2-CAN2
			void (*IRQHandler)()……中断服务程序入口地址
返 回 值：
其    它：
****************************************************************************************************/
Bool AddAnCanTxIrq(U32 CanSN, void (* CallBackP)())
{
	if((CanSN<2)&&(CanTxIRQ[CanSN].TxIRQHandlerCnt<mIRQHandlerNum))
	{	
		CanTxIRQ[CanSN].TxIRQHandlerP[CanTxIRQ[CanSN].TxIRQHandlerCnt]=CallBackP;	//CAN接收中断回调函数
		CanTxIRQ[CanSN].TxIRQHandlerCnt++;											//CAN接收中断个数（回调函数个数）
			
		if(CanSN==mCC_CAN1)
		{
			nvic_irq_enable(CAN0_TX_IRQn, mIRQPriorityL, mIRQPriorityL);
			can_interrupt_enable(CAN0, CAN_INTEN_TMEIE);		//发送邮箱空中断
		}
		else //if(CanSN==mCC_CAN2)
		{
			nvic_irq_enable(CAN1_TX_IRQn, mIRQPriorityL, mIRQPriorityL);
			can_interrupt_enable(CAN1, CAN_INTEN_TMEIE);		//发送邮箱空中断
		}			
		return mTrue;
	}
	return mFalse;
}
/****************************************************************************************************
函数名称：	CAN和RS485默认IO初始化
函数说明：
输入参数：	
返 回 值：
其    它：
CAN和RS485接口不使用时，TX引脚默认配置为上拉输入状态，使TX指示灯默认熄灭
该函数在主函数中调用，放在定时器初始化前。20211214加
****************************************************************************************************/
void CanRS485_IO_Init(void)
{
	
}
/****************************************************************************************************
函数名称：	CAN初始化
函数说明：
输入参数：	U8 CanSN	……CAN通道，1-CAN1、2-CAN2
			U32 Baud	……波特率			
返 回 值：
其    它：
CAN1、CAN2使用的是APB1的时钟50M
****************************************************************************************************/
void Can_Drv_Init(U32 CanSN,U32 Baud)
{	
	can_parameter_struct can_parameter;
	U32 pCAN;
	
	//管脚、中断等初始化
	if(CanSN==mCC_CAN1)
	{	
		pCAN=CAN0;		
		
		//引脚	PA11	PA12
		// enable can clock 
    	rcu_periph_clock_enable(RCU_CAN0);
    	rcu_periph_clock_enable(RCU_GPIOA);

    	// configure CAN0 GPIO, CAN0_TX(PA12) and CAN0_RX(PA11)
    	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11);
    	gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11);
    	gpio_af_set(GPIOA, GPIO_AF_9, GPIO_PIN_11);

    	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
    	gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_12);
    	gpio_af_set(GPIOA, GPIO_AF_9, GPIO_PIN_12);
	}
	else if(CanSN==mCC_CAN2)
	{	
		pCAN=CAN1;		
		
		//引脚	PB5	PB6
		// enable can clock 
		rcu_periph_clock_enable(RCU_CAN0);
    	rcu_periph_clock_enable(RCU_CAN1);
    	rcu_periph_clock_enable(RCU_GPIOB);

    	// configure CAN1 GPIO, CAN1_TX(PB6) and CAN1_RX(PB5)
    	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5);
    	gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_5);
    	gpio_af_set(GPIOB, GPIO_AF_9, GPIO_PIN_5);

    	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    	gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_6);
    	gpio_af_set(GPIOB, GPIO_AF_9, GPIO_PIN_6);
	}
	else
		return;		
		
	//initialize CAN register
    can_deinit(pCAN);

    //initialize CAN
    can_parameter.time_triggered = DISABLE;
    can_parameter.auto_bus_off_recovery = ENABLE;
    can_parameter.auto_wake_up = DISABLE;
    can_parameter.auto_retrans = ENABLE;
    can_parameter.rec_fifo_overwrite = DISABLE;
    can_parameter.trans_fifo_order = DISABLE;
    can_parameter.working_mode = CAN_NORMAL_MODE;
    can_parameter.resync_jump_width = CAN_BT_SJW_1TQ;
    can_parameter.time_segment_1 = CAN_BT_BS1_7TQ;
    can_parameter.time_segment_2 = CAN_BT_BS2_2TQ;
    //AHP1时钟1/4主频	50MHz		10个时钟1位数据
    can_parameter.prescaler = (50000000/10)/Baud;
    can_init(pCAN, &can_parameter);
	//中断开启	由调用函数开启
	/*if(CanSN==mCC_CAN1)
	{	//
		NVIC_Init(mIRQPriorityL,mIRQPriorityL,CAN1_SCE_IRQn,mIRQGroup);		//抢占0，子优先级0，组0
	}
	else //if(CanSN==mCC_CAN1)
	{
		NVIC_Init(mIRQPriorityL,mIRQPriorityL,CAN1_SCE_IRQn,mIRQGroup);		//抢占0，子优先级0，组0
	}	*/
}
/****************************************************************************************************
函数名称：	
函数说明：CAN1 发送中断
输入参数：			
返 回 值：
其    它：
****************************************************************************************************/
void CAN0_TX_IRQHandler(void)
{
	U32 i;
	
	for(i=0;i<CanTxIRQ[0].TxIRQHandlerCnt;i++)
	{
		if(CanTxIRQ[0].TxIRQHandlerP[i]!=0)
			CanTxIRQ[0].TxIRQHandlerP[i]();
	}	
}
/****************************************************************************************************
函数名称：	
函数说明：CAN2 发送中断
输入参数：			
返 回 值：
其    它：
****************************************************************************************************/
void CAN1_TX_IRQHandler(void)
{
	U32 i;
	
	for(i=0;i<CanTxIRQ[1].TxIRQHandlerCnt;i++)
	{
		if(CanTxIRQ[1].TxIRQHandlerP[i]!=0)
			CanTxIRQ[1].TxIRQHandlerP[i]();
	}	
}
/****************************************************************************************************
函数名称：	
函数说明：CAN1 接收中断
输入参数：			
返 回 值：
其    它：
****************************************************************************************************/
void CAN0_RX0_IRQHandler(void)
{
	U32 i;
	CanMessStr RecMsg;	//接收到的信息
	
	while(CanRecMessage(mCC_CAN1,0,	&RecMsg))
	{	//有数据接收
		for(i=0;i<CanRxIRQ[0].RxIRQHandlerCnt;i++)
		{
			if(CanRxIRQ[0].RxIRQHandlerP[i]!=0)
				CanRxIRQ[0].RxIRQHandlerP[i](&RecMsg);
		}	
	}
}
/****************************************************************************************************
函数名称：	
函数说明：CAN2 接收中断
输入参数：			
返 回 值：
其    它：
****************************************************************************************************/
void CAN1_RX0_IRQHandler(void)
{
	U32 i;
	CanMessStr RecMsg;	//接收到的信息
	
	while(CanRecMessage(mCC_CAN2,0,	&RecMsg))
	{	//有数据接收
		for(i=0;i<CanRxIRQ[1].RxIRQHandlerCnt;i++)
		{
			if(CanRxIRQ[1].RxIRQHandlerP[i]!=0)
				CanRxIRQ[1].RxIRQHandlerP[i](&RecMsg);
		}	
	}
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
