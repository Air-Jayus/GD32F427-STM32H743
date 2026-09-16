/* Copyright (C) 2009 *******************************************************************************
									 杭州科强智能控制系统有限公司
=====================================================================================================
项目名称：T6F5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 =========================================
文件名称：动作程序配置
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
#ifndef ActConf_h
	#define ActConf_h

#ifdef ActConf_c
	#define ActConf_ext
#else
	#define ActConf_ext extern
#endif

//-------------------------------------------------------------------------------------------------//
//动作配置文件定义
#define mActConf_Std				//标准动作程序	适用：常规全液压式注塑机，例海天SA系列机、天剑PL系列机
//#define mActConf_xxx
//……

//动作配置文件选择	.h文件
#ifdef mActConf_Std
	#include "ActConf_Std.h"		//标准动作程序	适用：常规全液压式注塑机，例海天SA系列机、天剑PL系列机
//#elif mActConf_xxx
//	#include "ActConf_xxx.h"
//……
#endif

//-------------------------------------------------------------------------------------------------//
//动作组定义	ActGroup	在ActConf.h定义
//1)表示非常接近的一类动作，通常运动的部件、对象或性质是相同的，只是动作的执行前提、模式等有所区别。
//2)如注射动作，包括：手动模式下注射、调模模式下注射、储料前注射、排气时注射。又如开模动作，包括：手动模式下开模、调模模式下开模。
//3)主要给动作监控函数使用，如GB22530需要对某一部件进行监控，如禁止注射（螺杆前进），如果没有Group属性，则要监控上述4个注射动作，
//  很麻烦且不利于新增动作（会影响到相减动作监控函数）。
//
//动作ID		ActFunID	在ActConf.h定义
//1)全局唯一表示某动作函数（注意函数而不是动作）。
//2)如果手动、调模、自动模式下是不同动作函数，则要区别为不同ID；如上述注射，有多种情况下的注射，应各有不同的ID；如果手动和调模
//  模式下共用一个动作函数，则是同一个ID即可。
//3)同一属一组的ID尽量分配在一起，因此考虑以4或8为分配间隔。
//
//动作细分		ActSeg		在ActConf.h定义
//1)同一动作函数，可能多种情况下被调用执行，此时通过本属性区分。如手动模式开模动作函数，会因按下开模键、关模失败转开模、排气开模
//  等情况而调用执行，此时通过本属性加以区分。
//
//段ID			SecID		在各动作文件定义
//1)在动作函数中唯一表示某动作段。
//
//注意：新增某动作函数时，通常应重新定义、分配上述几项属性；但是修改、替换动作函数时，则应保持上述属性与原函数的一致性，这是因为
//     动作监控函数依赖这些属性进行判断，更改了则可能出错。

//ActGroup、ActSeg、ActFunID、SecID
//以下宏系统标准、统一定义使用，不可更改
#define mAG_Null		1	//空		ActGroup
//#define mAG_Any		255	//任意								在Action.h中定义
#define	mAFID_Null		1	//空		ActFunID	全局唯一
//#define mAFID_Any		255	//任意								在Action.h中定义

						
#define mASID_TStartN	2	//真正开始			约定：此步骤只能被引用于检查动作开始，不能据此进入插入动作等，共同保证第一步真正执行完整、且一个动作中只会执行一次该步骤
#define mASID_TStartS	3	//真正开始S步骤			  此步骤可以被引用、并据此插入动作前进行的动作，如关模前中子、机械手等
#define mASID_TStartM	4	//真正开始M步骤			  同上
#define mASID_TStartE	5	//真正开始E步骤			  同上    注：开始设立多步，目的是区分插入优先级，不过实际意义不大，除中子、机械手并行外基本不这么用

#define mASID_LStart	6	//逻辑开始步骤			  动作被插入且重新开始时，恢复时开始执行的步骤

#define mASID_NorMax	245	//正常最大SecID			  正常段最大段ID值，主要给AL中使用，避免把HangRdy包含在内

#define mASID_OutDly	246	//切阀延时				  DO、DA一起结束，以DO时间为准，即DO延时到DA一起关闭
#define mASID_EndDly	247	//动作结束延时	
#define mASID_LEnd		248	//逻辑结束步骤			  动作被插入进行挂起准备时，执行的最后步骤

#define mASID_TEndS		249	//真正结束S步骤			  此步骤可以被引用、并据此插入动作后进行的动作，如关模后中子等
#define mASID_TEndM		250	//真正结束M步骤			  同上
#define mASID_TEndE		251	//真正结束E步骤			  同上
#define mASID_TEndN		252	//真正结束				  此步骤只能被引用于检查动作结束，不能据此进入插入动作等，共同保证第一步真正执行完整、且一个动作中只会执行一次该步骤

#define mASID_RSEnd		253	//RunState为End时步骤	  用于识别动作最后一个循环
#define	mASID_Null		254	//空				新建动作时使用，表示步骤尚无意义
//#define mASID_Any		255	//任意				在Action.h中定义


#define mASEG_Stand		1	//标准		ActSeg		正常、默认、标准情况下执行


//以下宏根据动作及相应函数规划定义，可按需更改
//mAFID_AL_xx与mAFID_AU_xx共用相应的mASEG_xx、mASEG_xx_AM
#define mAG_MoldOpen						0x10					//动作组	开模
	#define mAFID_AL_MoldOpen					0x0010				//函数ID	开模		动作逻辑	
	#define mAFID_AU_MoldOpen					0x0011				//函数ID	开模		动作单元	手动、自动等
	#define mAFID_AU_MoldOpen_AM				0x0012				//函数ID	开模		调模
	#define mAFID_AL_MoldOpen_AMA				0x0013				//函数ID	开模		动作逻辑	自动调模时关模	
	#define mAFID_AU_MoldOpen_AMA				0x0014				//函数ID	开模		动作单元	自动调模时开模
		#define mASEG_MoldOpen_Std					mASEG_Stand		//细  分	标准
		#define mASEG_MoldOpen_MoldCls				0x10			//细  分	关模调用
		#define mASEG_MoldOpen_Exhaust				0x11			//细  分	排气		中子不动作
		#define mASEG_MoldOpen_Cool					0x12			//细  分	冷却开模	中子不动作	20150804加，应锐能

#define mAG_MoldClose						0x11					//动作组	关模						
	#define mAFID_AL_MoldClose					0x0020				//函数ID	关模		动作逻辑
	#define mAFID_AU_MoldClose					0x0021				//函数ID	关模		动作单元	手动、自动等
	#define mAFID_AU_MoldClose_AM				0x0022				//函数ID	关模		调模
	#define mAFID_AL_MoldClose_AMA				0x0023				//函数ID	关模		动作逻辑	自动调模时关模
	#define mAFID_AU_MoldClose_AMA				0x0024				//函数ID	关模		动作单元	自动调模时关模
		#define mASEG_MoldClose_Std					mASEG_Stand		//细  分	标准
		#define mASEG_MoldClose_Exhaust				0x10			//细  分	排气		中子不动作
	
#define mAG_Inject							0x12					//动作组	射出						
	#define mAFID_AL_Inject  					0x0030				//函数ID	射出		动作逻辑
	#define mAFID_AU_Inject  					0x0031				//函数ID	射出		动作单元	手动、自动等
	#define mAFID_AU_Inject_AM  				0x0032				//函数ID	射出		调模		
		#define mASEG_Inject_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_InjBefNozFor				0x0036				//函数ID	座进前射出
	#define mAFID_AU_InjBefNozFor				0x0037				//函数ID	座进前射出
		#define mASEG_InjBefNozFor_Std				mASEG_Stand		//细  分	标准
	#define mAFID_AL_PrgInject					0x003A				//函数ID	清料射出
	#define mAFID_AU_PrgInject					0x003B				//函数ID	清料射出
		#define mASEG_PrgInject_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_InjComp					0x003C				//函数ID	压缩注射
	#define mAFID_AU_InjComp					0x003D				//函数ID	压缩注射
		#define mASEG_InjComp_Std					mASEG_Stand		//细  分	标准

#define mAG_SuckBack						0x13					//动作组	射退						
	#define mAFID_AL_SuckBack					0x0040				//函数ID	射退		动作逻辑			
	#define mAFID_AL_SuckBackBefChg				0x0041				//函数ID	储前射退	动作逻辑
	#define mAFID_AL_SuckBackAftChg				0x0042				//函数ID	储后射退	动作逻辑	自动		
	#define mAFID_AL_SuckBackAftCool			0x0043				//函数ID	冷后射退	动作逻辑	自动	
	#define mAFID_AU_SuckBack					0x0044				//函数ID	射退		动作单元	手动、自动等
	#define mAFID_AU_SuckBack_AM				0x0045				//函数ID	射退		调模
		#define mASEG_SuckBack_Std					mASEG_Stand		//细  分	标准
		#define mASEG_SuckBack_BefChg				0x10			//细  分	储料前		
		#define mASEG_SuckBack_AftChg				0x11			//细  分	储料后		自动
		#define mASEG_SuckBack_AftCool				0x12			//细  分	冷后		自动
	#define mAFID_AL_PrgSuckBack				0x0048				//函数ID	清料射退 	动作单元
	#define mAFID_AU_PrgSuckBack				0x0049				//函数ID	清料射退 	动作单元
		#define mASEG_PrgSuckBack_Std				mASEG_Stand		//细  分	标准

#define mAG_EjectRet						0x14					//动作组	托退
	#define mAFID_AL_EjectRet					0x0050				//函数ID	托退		动作逻辑
	#define mAFID_AU_EjectRet					0x0051				//函数ID	托退		动作单元	手动、自动等
	#define mAFID_AU_EjectRet_AM				0x0052				//函数ID	托退		调模
		#define mASEG_EjectRet_Std					mASEG_Stand		//细  分	标准				
		#define mASEG_EjectRet_MoldCls				0x10			//细  分	关模前
			
#define mAG_EjectFor						0x15					//动作组	托进						
	#define mAFID_AL_EjectFor					0x0060				//函数ID	托进		动作逻辑
	#define mAFID_AU_EjectFor					0x0061				//函数ID	托进		动作单元	手动、自动等
	#define mAFID_AU_EjectFor_AM				0x0062				//函数ID	托进		调模
	#define mAFID_AU_EjectForLinkEndCore		0x0063				//函数ID	托进		动作单元	连动托模进时托进后中子处理
	#define mAFID_AL_EjeFor1PauseTi				0x0064				//函数ID	托进1段暂停	逻辑单元	20170508
	#define mAFID_AU_EjeFor1PauseTi				0x0065				//函数ID	托进1段暂停	动作单元	20170508
		#define mASEG_EjectFor_Std					mASEG_Stand		//细  分	标准
		#define mASEG_EjectFor_ReEjdFor				0x10			//细  分	再次托模(电眼自动)
	#define mAFID_AL_EjectForLink				0x0068				//函数ID	托进		动作逻辑
	#define mAFID_AU_EjectForLink				0x0069				//函数ID	托进		动作单元	连动
		#define mASEG_EjectForLink_Std				mASEG_Stand		//细  分	标准
		
#define mAG_NozzleFor						0x16					//动作组	座进
	#define mAFID_AL_NozzleFor					0x0070				//函数ID	座进		动作逻辑
	#define mAFID_AU_NozzleFor					0x0071				//函数ID	座进		动作单元	手动、自动等
	#define mAFID_AU_NozzleFor_AM				0x0072				//函数ID	座进		调模
		#define mASEG_NozzleFor_Std					mASEG_Stand		//细  分	标准

#define mAG_NozzleRet						0x17					//动作组	座退
	#define mAFID_AL_NozzleRet					0x0080				//函数ID	座退		动作逻辑
	#define mAFID_AL_NozzleRetAftInj			0x0081				//函数ID	座退		动作逻辑
	#define mAFID_AL_NozzleRetAftChg			0x0082				//函数ID	座退		动作逻辑
	#define mAFID_AL_NozzleRetBefMO				0x0083				//函数ID	座退		动作逻辑
	#define mAFID_AU_NozzleRet					0x0084				//函数ID	座退		动作单元	手动、自动等
	#define mAFID_AU_NozzleRet_AM				0x0085				//函数ID	座退		调模
		#define mASEG_NozzleRet_Std					mASEG_Stand		//细  分	标准
		#define mASEG_NozzleRet_AftInj				0x10			//细  分	射后
		#define mASEG_NozzleRet_AftChg				0x11			//细  分	储后
		#define mASEG_NozzleRet_BefMO				0x12			//细  分	开模前

#define mAG_Charge							0x18					//动作组	储料
	#define mAFID_AL_Charge						0x0090				//函数ID	储料		动作逻辑
	#define mAFID_AU_Charge						0x0091				//函数ID	储料		动作单元	手动、自动等
	#define mAFID_AU_Charge_AM					0x0092				//函数ID	储料		调模
		#define mASEG_Charge_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_ReCharge					0x0096				//函数ID	再次储料	动作逻辑
	#define mAFID_AU_ReCharge					0x0097				//函数ID	再次储料	动作单元
		#define mASEG_ReCharge_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_PrgCharge					0x009A				//函数ID	清料储料	动作逻辑
	#define mAFID_AU_PrgCharge					0x009B				//函数ID	清料储料	动作单元
		#define mASEG_PrgCharge_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_EjeCharge					0x009C				//函数ID	托模后储料	动作逻辑//20220819
		#define mASEG_EjeCharge_AftEje				0x10			//细  分	托模后	

#define mAG_Air								0x19					//动作组	吹气
	#define mAFID_AL_StartParaAir				0x00A0				//函数ID	启动并行吹气	动作逻辑		
	#define mAFID_AL_ParaAir					0x00A1				//函数ID	并行吹气		动作逻辑		
	#define mAFID_AU_ParaAir					0x00A2				//函数ID	并行吹气		动作单元	
		#define mASEG_ParaAir_Std					mASEG_Stand		//细  分	标准		
	#define mAFID_AL_KeyAir1					0x00A3				//函数ID	按键吹气1	动作逻辑
	#define mAFID_AL_KeyAir2					0x00A4				//函数ID	按键吹气2	动作逻辑
	#define mAFID_AL_KeyAir3					0x00A5				//函数ID	按键吹气3	动作逻辑
	#define mAFID_AL_KeyAir4					0x00A6				//函数ID	按键吹气4	动作逻辑
	#define mAFID_AL_KeyAir5					0x00A7				//函数ID	按键吹气5	动作逻辑
	#define mAFID_AL_KeyAir6					0x00A8				//函数ID	按键吹气6	动作逻辑
	#define mAFID_AU_KeyAir						0x00A9				//函数ID	按键吹气		动作逻辑
		#define mASEG_KeyAir_Std					mASEG_Stand		//细  分	标准
		#define mASEG_KeyAir1						0x10			//细  分	吹气1
		#define mASEG_KeyAir2						0x20			//细  分	吹气2
		#define mASEG_KeyAir3						0x30			//细  分	吹气3
		#define mASEG_KeyAir4						0x40			//细  分	吹气4
		#define mASEG_KeyAir5						0x50			//细  分	吹气5
		#define mASEG_KeyAir6						0x60			//细  分	吹气6
	
#define mAG_CoreIn							0x1A					//动作组	中子进
	#define mAFID_AL_KeyCore1In					0x00B0				//函数ID	中子1进		动作逻辑	按键中子进
	#define mAFID_AL_KeyCore2In					0x00B1				//函数ID	中子2进		动作逻辑
	#define mAFID_AL_KeyCore3In					0x00B2				//函数ID	中子3进		动作逻辑
	#define mAFID_AL_KeyCore4In					0x00B3				//函数ID	中子4进		动作逻辑
	#define mAFID_AL_KeyCore5In					0x00B4				//函数ID	中子5进		动作逻辑
	#define mAFID_AL_KeyCore6In					0x00B5				//函数ID	中子6进		动作逻辑
	#define mAFID_AL_KeyCore7In					0x00B6				//函数ID	中子7进		动作逻辑
	#define mAFID_AL_KeyCore8In					0x00B7				//函数ID	中子8进		动作逻辑
	#define mAFID_AL_Core1In					0x00C0				//函数ID	中子1进		动作逻辑	动作中连带中子进
	#define mAFID_AL_Core2In					0x00C1				//函数ID	中子2进		动作逻辑
	#define mAFID_AL_Core3In					0x00C2				//函数ID	中子3进		动作逻辑
	#define mAFID_AL_Core4In					0x00C3				//函数ID	中子4进		动作逻辑
	#define mAFID_AL_Core5In					0x00C4				//函数ID	中子5进		动作逻辑
	#define mAFID_AL_Core6In					0x00C5				//函数ID	中子6进		动作逻辑
	#define mAFID_AL_Core7In					0x00C6				//函数ID	中子7进		动作逻辑
	#define mAFID_AL_Core8In					0x00C7				//函数ID	中子8进		动作逻辑
	#define mAFID_AL_LinkCore1In				0x00D0				//函数ID	中子1进		动作逻辑	连动中子进
	#define mAFID_AL_LinkCore2In				0x00D1				//函数ID	中子2进		动作逻辑
	#define mAFID_AL_LinkCore3In				0x00D2				//函数ID	中子3进		动作逻辑
	#define mAFID_AL_LinkCore4In				0x00D3				//函数ID	中子4进		动作逻辑
	#define mAFID_AL_LinkCore5In				0x00D4				//函数ID	中子5进		动作逻辑
	#define mAFID_AL_LinkCore6In				0x00D5				//函数ID	中子6进		动作逻辑
	#define mAFID_AL_LinkCore7In				0x00D6				//函数ID	中子7进		动作逻辑
	#define mAFID_AL_LinkCore8In				0x00D7				//函数ID	中子8进		动作逻辑
	#define mAFID_AU_CoreIn						0x00E0				//函数ID	中子进		动作单元	标准中子进
	#define mAFID_AU_LinkCoreIn					0x00E1				//函数ID	中子进		动作单元	连动中子进
		#define mASEG_Core1In						0x10			//细  分	中子1进
		#define mASEG_Core2In						0x20			//细  分	中子2进
		#define mASEG_Core3In						0x30			//细  分	中子3进
		#define mASEG_Core4In						0x40			//细  分	中子4进
		#define mASEG_Core5In						0x50			//细  分	中子5进
		#define mASEG_Core6In						0x60			//细  分	中子6进
		#define mASEG_Core7In						0x70			//细  分	中子7进
		#define mASEG_Core8In						0x80			//细  分	中子8进

#define mAG_CoreOut							0x1B					//动作组	中子退
	#define mAFID_AL_KeyCore1Out				0x00F0				//函数ID	中子1退		动作逻辑	按键中子退
	#define mAFID_AL_KeyCore2Out				0x00F1				//函数ID	中子2退		动作逻辑		
	#define mAFID_AL_KeyCore3Out				0x00F2				//函数ID	中子3退		动作逻辑		
	#define mAFID_AL_KeyCore4Out				0x00F3				//函数ID	中子4退		动作逻辑		
	#define mAFID_AL_KeyCore5Out				0x00F4				//函数ID	中子5退		动作逻辑		
	#define mAFID_AL_KeyCore6Out				0x00F5				//函数ID	中子6退		动作逻辑		
	#define mAFID_AL_KeyCore7Out				0x00F6				//函数ID	中子7退		动作逻辑		
	#define mAFID_AL_KeyCore8Out				0x00F7				//函数ID	中子8退		动作逻辑		
	#define mAFID_AL_Core1Out					0x0100				//函数ID	中子1退		动作逻辑	动作中连带中子退
	#define mAFID_AL_Core2Out					0x0101				//函数ID	中子2退		动作逻辑		
	#define mAFID_AL_Core3Out					0x0102				//函数ID	中子3退		动作逻辑		
	#define mAFID_AL_Core4Out					0x0103				//函数ID	中子4退		动作逻辑		
	#define mAFID_AL_Core5Out					0x0104				//函数ID	中子5退		动作逻辑		
	#define mAFID_AL_Core6Out					0x0105				//函数ID	中子6退		动作逻辑		
	#define mAFID_AL_Core7Out					0x0106				//函数ID	中子7退		动作逻辑		
	#define mAFID_AL_Core8Out					0x0107				//函数ID	中子8退		动作逻辑		
	#define mAFID_AL_LinkCore1Out				0x0110				//函数ID	中子1退		动作逻辑	连动中子退
	#define mAFID_AL_LinkCore2Out				0x0111				//函数ID	中子2退		动作逻辑		
	#define mAFID_AL_LinkCore3Out				0x0112				//函数ID	中子3退		动作逻辑		
	#define mAFID_AL_LinkCore4Out				0x0113				//函数ID	中子4退		动作逻辑		
	#define mAFID_AL_LinkCore5Out				0x0114				//函数ID	中子5退		动作逻辑		
	#define mAFID_AL_LinkCore6Out				0x0115				//函数ID	中子6退		动作逻辑		
	#define mAFID_AL_LinkCore7Out				0x0116				//函数ID	中子7退		动作逻辑		
	#define mAFID_AL_LinkCore8Out				0x0117				//函数ID	中子8退		动作逻辑
	#define mAFID_AL_Srw1EndOut					0x0118				//函数ID	中子1退二	动作逻辑	绞牙退二
	#define mAFID_AU_CoreOut					0x0120				//函数ID	中子退		动作单元	标准中子退
	#define mAFID_AU_LinkCoreOut				0x0121				//函数ID	中子退		动作单元	连动中子退
	#define mAFID_AU_SrwEndOut					0x0122				//函数ID	中子退二	动作单元	绞牙退二
		#define mASEG_Core1Out						0x10			//细  分	中子1退
		#define mASEG_Core2Out						0x20			//细  分	中子2退
		#define mASEG_Core3Out						0x30			//细  分	中子3退
		#define mASEG_Core4Out						0x40			//细  分	中子4退
		#define mASEG_Core5Out						0x50			//细  分	中子5退
		#define mASEG_Core6Out						0x60			//细  分	中子6退
		#define mASEG_Core7Out						0x70			//细  分	中子7退
		#define mASEG_Core8Out						0x80			//细  分	中子8退

#define mAG_LinkWait						0x1C					//动作组	连动等待
	#define mAFID_AL_CoreLinkWait				0x0130				//函数ID	中子连动等待	动作逻辑	中子连动时辅助用
	#define mAFID_AU_CoreLinkWait				0x0131				//函数ID	中子连动等待	动作单元	中子连动时辅助用
		#define mASEG_CoreLinkWait_Std				mASEG_Stand		//细  分	标准
	#define mAFID_AL_EjeForLinkWait				0x0132				//函数ID	托进连动等待	动作逻辑	托进连动时辅助用
	#define mAFID_AU_EjeForLinkWait				0x0133				//函数ID	托进连动等待	动作单元	托进连动时辅助用
		#define mASEG_EjeForLinkWait_Std			mASEG_Stand		//细  分	标准
	#define mAFID_AL_Lubr2WaitLubr1				0x0134				//函数ID	润滑2等待润滑1结束	动作逻辑	润滑2等待润滑1结束辅助用
	#define mAFID_AU_Lubr2WaitLubr1				0x0135				//函数ID	润滑2等待润滑1结束	动作单元	润滑2等待润滑1结束辅助用
			#define mASEG_Lubr2WaitLubr1_Std			mASEG_Stand		//细  分	标准
			
#define mAG_Core1Out_S0						0x1D					//动作组	中子1特殊退								20130724加
	#define mAFID_AL_Core1Out_S0				0x0125				//函数ID	中子1特殊退		动作逻辑	特殊中子退	20130724加
	#define mAFID_AU_Core1Out_S0				0x0126				//函数ID	中子1特殊退		动作单元	特殊中子退	20130724加
		#define mASEG_Core1Out_S0					0x10			//细  分	中子1特殊退

#define mAG_MoldThick						0x80					//动作组	调模退
	#define mAFID_AL_MoldThick					0x0140				//函数ID	调模退   	动作逻辑
	#define mAFID_AU_MoldThick					0x0141				//函数ID	调模退      动作单元
		#define mASEG_MoldThick_Std					mASEG_Stand		//细  分	标准				
	#define mAFID_AL_MoldThick_AMA				0x0142				//函数ID	调模退   	动作逻辑		自动调模时
	#define mAFID_AU_MoldThick_AMA				0x0143				//函数ID	调模退      动作单元		自动调模时
		#define mASEG_MoldThick_AMA_Std				mASEG_Stand		//细  分	标准				
	#define mAFID_AL_MoldThick_AMT				0x0144				//函数ID	调模退   	动作逻辑		自动调模厚时
	#define mAFID_AU_MoldThick_AMT				0x0145				//函数ID	调模退      动作单元		自动调模厚时
		#define mASEG_MoldThick_AMT_Std				mASEG_Stand		//细  分	标准				
	#define mAFID_AL_MoldThick_AMP				0x0146				//函数ID	调模退   	动作逻辑		锁模力纠偏时
	#define mAFID_AU_MoldThick_AMP				0x0147				//函数ID	调模退      动作单元		锁模力纠偏时
		#define mASEG_MoldThick_AMP_Std				mASEG_Stand		//细  分	标准					
		
#define mAG_MoldThin						0x81					//动作组	调模进
	#define mAFID_AL_MoldThin					0x0150				//函数ID	调模进    	动作逻辑 
	#define mAFID_AU_MoldThin					0x0151				//函数ID	调模进      动作单元
		#define mASEG_MoldThin_Std					mASEG_Stand		//细  分	标准				
	#define mAFID_AL_MoldThin_AMA				0x0152				//函数ID	调模进    	动作逻辑 		自动调模时	
	#define mAFID_AU_MoldThin_AMA				0x0153				//函数ID	调模进      动作单元		自动调模时
		#define mASEG_MoldThin_AMA_Std				mASEG_Stand		//细  分	标准
		#define mASEG_MoldThin_AMA_Con				0x10			//细  分	连续调进					不会输出"电眼无反应"警报
	#define mAFID_AL_MoldThin_AMT				0x0154				//函数ID	调模进    	动作逻辑 	自动调模厚时	
	#define mAFID_AU_MoldThin_AMT				0x0155				//函数ID	调模进      动作单元		自动调模厚时
		#define mASEG_MoldThin_AMT_Std				mASEG_Stand		//细  分	标准
	#define mAFID_AL_MoldThin_AMP				0x0156				//函数ID	调模退   	动作逻辑		锁模力纠偏时
	#define mAFID_AU_MoldThin_AMP				0x0157				//函数ID	调模退      动作单元		锁模力纠偏时
		#define mASEG_MoldThin_AMP_Std				mASEG_Stand		//细  分	标准				
		
#define mAG_Purge							0x82					//动作组	清料
	#define mAFID_AL_Purge						0x0160				//函数ID	清料		动作逻辑

#define mAG_Lubr							0x83					//动作组	润滑
	#define mAFID_AL_KeyLubr					0x0170				//函数ID	按键润滑	动作逻辑
	#define mAFID_AU_KeyLubr					0x0171				//函数ID	按键润滑	动作逻辑
		#define mASEG_KeyLubr_Std					mASEG_Stand		//细  分	标准			
	#define mAFID_AL_Lubr1						0x0172				//函数ID	润滑1		动作逻辑
	#define mAFID_AU_Lubr1						0x0173				//函数ID	润滑1     	动作单元
		#define mASEG_Lubr1_Std						mASEG_Stand		//细  分	标准
		#define mASEG_Lubr1_AutoLubr				0x10			//细  分	自动润滑
		#define mASEG_Lubr1_PwrOnLubr				0x11			//细  分	开机润滑	20260124
	#define mAFID_AL_Lubr2						0x0174				//函数ID	润滑2		动作逻辑
	#define mAFID_AU_Lubr2						0x0175				//函数ID	润滑2     	动作单元
		#define mASEG_Lubr2_Std						mASEG_Stand		//细  分	标准			
		#define mASEG_Lubr2_AutoLubr				0x10			//细  分	自动润滑
		#define mASEG_Lubr2_PwrOnLubr				0x11			//细  分	开机润滑	20260124
	#define mAFID_AL_MoldAdjLubr				0x0176				//函数ID	调模润滑	动作逻辑		20150327加
	#define mAFID_AU_MoldAdjLubr				0x0177				//函数ID	调模润滑    动作单元
		#define mASEG_MoldAdjLubr_Std				mASEG_Stand		//细  分	标准			
	
			
#define mAG_MotorOn							0x84					//动作组	马达开
	#define mAFID_AL_MotorOn					0x0180				//函数ID	马达开     	动作逻辑
	#define mAFID_AU_MotorOn					0x0181				//函数ID	马达开     	动作单元
		#define mASEG_MotorOn_Std					mASEG_Stand		//			标准				

#define mAG_MotorOff						0x85					//动作组	马达关
	#define mAFID_AL_MotorOff					0x0190				//函数ID	马达关     	动作逻辑
	#define mAFID_AU_MotorOff					0x0191				//函数ID	马达关     	动作单元
		#define mASEG_MotorOff_Std					mASEG_Stand		//细  分	标准

#define mAG_OilHtr							0x90					//动作组	油温加热		
	#define mAFID_AL_OilHtr						0x01A0				//函数ID	油温加热    动作逻辑
	#define mAFID_AU_OilHtr						0x01A1				//函数ID	油温加热    动作单元
		#define mASEG_OilHtr_Std					mASEG_Stand		//细  分	标准
		#define mASEG_OilHtr_MotOn					0x10			//细  分	马达开时

#define mAG_AutoAdjMold						0x91					//动作组	自动调模
	#define mAFID_AL_AutoAdjMold				0x01B0				//函数ID	自动调模    动作逻辑
	#define mAFID_AU_AutoAdjMold				0x01B1				//函数ID	自动调模    动作单元
		#define mASEG_AutoAdjMold_Std				mASEG_Stand		//细  分	标准				
	#define mAFID_AL_AutoAdjMoldThick			0x01B2				//函数ID	自动调模厚   动作逻辑
	#define mAFID_AU_AutoAdjMoldThick			0x01B3				//函数ID	自动调模厚   动作单元
		#define mASEG_AutoAdjMoldThick_Std			mASEG_Stand		//细  分	标准	


#define mAG_SafeGate						0x92					//动作组	安全门
	#define mAFID_AL_SafeGateCls				0x01C0				//函数ID	关安全门    动作逻辑
	#define mAFID_AU_SafeGateCls				0x01C1				//函数ID	关安全门    动作单元
		#define mASEG_SafeGateCls_Std				mASEG_Stand		//细  分	标准
		#define mASEG_SafeGateCls_MoldCls			0x10			//细  分	关模时
		#define mASEG_SafeGateCls_MoldThin			0x11			//细  分	调模进时
	#define mAFID_AL_SafeGateOpen				0x01C2				//函数ID	开安全门    动作逻辑
	#define mAFID_AU_SafeGateOpen				0x01C3				//函数ID	开安全门    动作单元
		#define mASEG_SafeGateOpen_Std				mASEG_Stand		//细  分	标准		
	#define mAFID_AL_SafeGateOpenCls			0x01C4				//函数ID	开关安全门  动作逻辑
	#define mAFID_AU_SafeGateOpenCls			0x01C5				//函数ID	开关安全门  动作单元
		#define mASEG_SafeGateOpenCls_Std			mASEG_Stand		//细  分	标准
		#define mASEG_SafeGateOpenCls_AutoModeStart	0x10			//细  分	自动模式开始
		#define mASEG_SafeGateOpenCls_CycEnd		0x11			//细  分	循环结束(半自动)
		#define mASEG_SafeGateOpenCls_AMA			0x12			//细  分	自动调模

#define mAG_MotDrvOn						0x93					//动作组	驱动器开
	#define mAFID_AL_MotDrvOn					0x01D0				//函数ID	驱动器开    动作逻辑
	#define mAFID_AU_MotDrvOn					0x01D1				//函数ID	驱动器开    动作单元
		#define mASEG_MotDrvOn_Std					mASEG_Stand		//细  分	标准

#define mAG_MotDrvOff						0x94					//动作组	驱动器关
	#define mAFID_AL_MotDrvOff					0x01E0				//函数ID	驱动器关    动作逻辑
	#define mAFID_AU_MotDrvOff					0x01E1				//函数ID	驱动器关    动作单元
		#define mASEG_MotDrvOff_Std					mASEG_Stand		//细  分	标准
		#define mASEG_MotDrvOff_MotOff				0x10			//细  分	马达关时

#define mAG_NozSafeGate						0x95					//动作组	注射防护罩
	#define mAFID_AL_NozSGCls					0x01F0				//函数ID	防护罩关    动作逻辑
	#define mAFID_AU_NozSGCls					0x01F1				//函数ID	防护罩关    动作单元
		#define mASEG_NozSGCls_Std					mASEG_Stand		//细  分	标准		注射时

#define mAG_AutoModeAssAct					0xA0					//动作组	自动模式辅助动作	该组允许闲转手动
	#define mAFID_AL_AutoModeStart				0x0200				//函数ID	自动模式开始		动作逻辑
		#define mASEG_AutoModeStart_Std				mASEG_Stand		//细  分	标准
	#define mAFID_AL_CycStart					0x0201				//函数ID	循环开始    		动作逻辑
		#define mASEG_CycStart_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_CycEnd						0x0202				//函数ID	循环结束    		动作逻辑
		#define mASEG_CycEnd_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AU_FlowGroupEndChk			0x0203				//函数ID	同组流程结束检查   动作单元
		#define mASEG_FlowGroupEndChk_Std			mASEG_Stand		//细  分	标准
	#define mAFID_AU_CycEndCnt					0x0204				//函数ID	循环结束计数	   动作单元
		#define mASEG_CycEndCnt_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AU_ProdDrop					0x0205				//函数ID	电眼检物		   动作单元
		#define mASEG_ProdDrop_Std					mASEG_Stand		//细  分	标准
		#define	mASEG_ProdDrop_ReProdDrop			0x10			//细  分	再次电眼检物
	#define mAFID_AU_CycDly						0x0206				//函数ID	循环延时		   动作单元
		#define mASEG_CycDly_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_SenrAutoCycEnd				0x0207				//函数ID	电眼自动循环结束   动作单元
		#define mASEG_SenrAutoCycEnd_Std			mASEG_Stand		//细  分	标准

#define mAG_Cool							0xA1					//动作组	冷却
	#define mAFID_AL_CoolEndWait				0x0210				//函数ID	产品冷却结束等待
	#define mAFID_AU_CoolEndWait				0x0211				//函数ID	产品冷却结束等待
		#define mASEG_CoolEndWait_Std				mASEG_Stand		//细  分	标准			
	#define mAFID_AL_ChgCool					0x0212				//函数ID	储前冷却
	#define mAFID_AU_ChgCool					0x0213				//函数ID	储前冷却
		#define mASEG_ChgCool_Std					mASEG_Stand		//细  分	标准			
	
#define mAG_AirInj							0xA2					//动作组	气辅注射
	#define mAFID_AL_StartAirInj				0x0220				//函数ID	启动气辅注射
	#define mAFID_AL_FinAirInj					0x0221				//函数ID	结束气辅注射
	#define mAFID_AL_AirInj						0x0222				//函数ID	气辅注射
	#define mAFID_AU_AirInj						0x0223				//函数ID	气辅注射
		#define mASEG_AirInj_Std					mASEG_Stand		//细  分	标准			

#define mAG_SysStop							0xA3					//动作组	紧急停止
	#define mAFID_AL_SysStop					0x0230				//函数ID	紧急停止
	#define mAFID_AU_SysStop					0x0231				//函数ID	紧急停止
		#define mASEG_SysStop_Std					mASEG_Stand		//细  分	标准			

#define mAG_MachProt						0xA4					//动作组	机械保险
	#define mAFID_AL_MachProt					0x0240				//函数ID	机械保险
	#define mAFID_AU_MachProt					0x0241				//函数ID	机械保险
		#define mASEG_MachProt_Std					mASEG_Stand		//细  分	标准

#define mAG_CycStartKey						0xA5					//动作组	循环启动键
	#define mAFID_AL_CycStartKey				0x0250				//函数ID	循环启动键  动作单元
	#define mAFID_AU_CycStartKey				0x0251				//函数ID	循环启动键  动作单元
		#define mASEG_CycStartKey_Std				mASEG_Stand		//细  分	标准

#define mAG_SafeRelay						0xA6					//动作组	安全继电器
	#define mAFID_AL_SafeRelayRstChk			0x0260				//函数ID	安全继电器复位检查
	#define mAFID_AU_SafeRelayRstChk			0x0261				//函数ID	安全继电器复位检查
		#define mASEG_SafeRelayRstChk_Std			mASEG_Stand		//细  分	标准

#define mAG_Acc								0xA7					//动作组	蓄能器
	#define mAFID_AL_AccBefInj					0x0270				//函数ID	注射前蓄能
	#define mAFID_AU_AccBefInj					0x0271				//函数ID	注射前蓄能
		#define mASEG_AccBefInj_Std					mASEG_Stand		//细  分	标准			
	#define mAFID_AL_AccAtCool					0x0272				//函数ID	冷却时蓄能
	#define mAFID_AU_AccAtCool					0x0273				//函数ID	冷却时蓄能
		#define mASEG_AccAtCool_Std					mASEG_Stand		//细  分	标准			

#define mAG_Nozzle							0xA8					//动作组	喷嘴
	#define mAFID_AL_NozzleOn					0x0280				//函数ID	喷嘴开
	#define mAFID_AU_SPNozzleOn					0x0281				//函数ID	单向喷嘴开
	#define mAFID_AU_DPNozzleOn					0x0282				//函数ID	双向喷嘴开
		#define mASEG_NozzleOn_Std					mASEG_Stand		//细  分	标准			
	#define mAFID_AL_NozzleOff					0x0283				//函数ID	喷嘴关
	#define mAFID_AU_SPNozzleOff				0x0284				//函数ID	单向喷嘴关
	#define mAFID_AU_DPNozzleOff				0x0285				//函数ID	双向喷嘴关
		#define mASEG_NozzleOff_Std					mASEG_Stand		//细  分	标准			

#define mAG_Robot							0xA9					//动作组	机械手
	#define mAFID_AL_RobotWait					0x0290				//函数ID	等待机械手信号
	#define mAFID_AU_RobotWait					0x0291				//函数ID	等待机械手信号
		#define mASEG_RobotWait_Std					mASEG_Stand		//细  分	标准
	#define mAFID_AL_RobotCycStart				0x0292				//函数ID	机械手循环启动
	#define mAFID_AU_RobotCycStart				0x0293				//函数ID	机械手循环启动
		#define mASEG_RobotCycStart_Std				mASEG_Stand		//细  分	标准

#define mAG_AutoMoldAdj						0xAA					//动作组	自动调模
	#define mAFID_AL_AutoMoldAdj				0x02A0				//函数ID
	#define mAFID_AU_AutoMoldAdj				0x02A1				//函数ID
		#define mASEG_AutoMoldAdj					mASEG_Stand		//细  分	标准			

#define mAG_Exhaust							0xAB					//动作组	排气
	#define mAFID_AL_Exhaust					0x02B0				//函数ID	排气
	#define mAFID_AU_ExhaustDly					0x02B1				//函数ID	排气延时
		#define mASEG_ExhaustDly_Dly				0x10			//细  分	排气前延时
		#define mASEG_ExhaustDly_HoldTi				0x11			//细  分	排气时间

#define mAG_EjeCutHandle					0xAC					//动作组	托模切料柄
	#define mAFID_AL_EjeCutHandle				0x02C0				//函数ID	托模切料柄
	#define mAFID_AU_EjeCutHandle				0x02C1				//函数ID	托模切料柄
		#define mASEG_EjeCutHandle_Std				mASEG_Stand		//细  分	标准			

#define mAG_AutoGate						0xAD					//动作组	
	#define mAFID_AL_AutoGateCls				0x02D0				//函数ID
	#define mAFID_AU_AutoGateCls				0x02D1				//函数ID
		#define mASEG_AutoGateCls_Std				mASEG_Stand		//细  分	标准			
		#define mASEG_AutoGateCls_Auto				0x10			//细  分	自动方式中关门		
	#define mAFID_AL_AutoGateOpen				0x02D2				//函数ID
	#define mAFID_AU_AutoGateOpen				0x02D3				//函数ID
		#define mASEG_AutoGateOpen_Std				mASEG_Stand		//细  分	标准			
		#define mASEG_AutoGateOpen_Auto				0x10			//细  分	自动方式中开门			
		#define mASEG_AutoGateOpen_Link				0x11			//细  分	自动方式、且连动开门			

#define mAG_Jig								0xAE					//动作组	模具夹具
	#define mAFID_AL_Jig						0x02E0				//函数ID
	#define mAFID_AU_Jig						0x02E1				//函数ID
		#define mASEG_Jig							mASEG_Stand		//细  分	标准			

#define mAG_PilotOilAcc						0xAF					//动作组	先导油蓄能器
	#define mAFID_AL_PilotOilAcc				0x02F0				//函数ID
	#define mAFID_AU_PilotOilAcc				0x02F1				//函数ID
		#define mASEG_PilotOilAcc					mASEG_Stand		//细  分	标准			
		#define mASEG_PilotOilAcc_MotOn				0x10			//细  分	马达开时			

#define mAG_BMC								0xB0					//动作组	BMC
	#define mAFID_AL_BMCFeedIn					0x0300				//函数ID	加料进
	#define mAFID_AU_BMCFeedIn					0x0301				//函数ID
		#define mASEG_BMCFeedIn						mASEG_Stand		//细  分	标准			
	#define mAFID_AL_BMCFeedOut					0x0306				//函数ID	加料退
	#define mAFID_AU_BMCFeedOut					0x0307				//函数ID
		#define mASEG_BMCFeedOut					mASEG_Stand		//细  分	标准			
	#define mAFID_AL_BMCFeedInLink				0x030A				//函数ID	加料进连动
	#define mAFID_AU_BMCFeedInLink				0x030B				//函数ID
		#define mASEG_BMCFeedInLink					mASEG_Stand		//细  分	标准			

#define mAG_RelPres							0xB1					//动作组	中子、阀门卸压
	#define mAFID_AL_RelPres					0x0310				//函数ID
	#define mAFID_AU_RelPres					0x0311				//函数ID
		#define mASEG_RelPres						mASEG_Stand		//细  分	标准			

#define mAG_SteamInj						0xB2					//动作组	蒸汽注射
	#define mAFID_AL_SteamInj					0x0320				//函数ID
	#define mAFID_AU_SteamInj					0x0321				//函数ID
		#define mASEG_SteamInj						mASEG_Stand		//细  分	标准			
		#define mASEG_SteamInj_MoldOpen				0x10			//细  分	开模时
		#define mASEG_SteamInj_Inject				0x20			//细  分	注射	时	

#define mAG_TieBar							0xB3					//动作组	拉杆
	#define mAFID_AL_TieBarIn					0x0330				//函数ID	拉杆进
	#define mAFID_AU_TieBarIn					0x0331				//函数ID
		#define mASEG_TieBarIn						mASEG_Stand		//细  分	标准			
	#define mAFID_AL_TieBarOut					0x0332				//函数ID	拉杆退
	#define mAFID_AU_TieBarOut					0x0333				//函数ID
		#define mASEG_TieBarOut						mASEG_Stand		//细  分	标准			
	#define mAFID_AL_BrkIn						0x0336				//函数ID	闸板进
	#define mAFID_AU_BrkIn						0x0337				//函数ID
		#define mASEG_BrkIn							mASEG_Stand		//细  分	标准	
	#define mAFID_AL_BrkOut						0x033A				//函数ID	闸板退
	#define mAFID_AU_BrkOut						0x033B				//函数ID
		#define mASEG_BrkOut						mASEG_Stand		//细  分	标准			

//#define mAG_								0xB4					//动作组	
//	#define mAFID_AL_							0x0340				//函数ID
//	#define mAFID_AU_							0x0341				//函数ID
//		#define mASEG_								mASEG_Stand		//细  分	标准			

//-------------------------------------------------------------------------------------------------//
//变量定义
ActConf_ext U32 MoldClsPresBuff[5],MoldClsFlowBuff[6];				//关模压力与流量实际执行值			辅助变量
ActConf_ext U32 MoldClsPresRampBuff[6],MoldClsFlowRampBuff[6];		//关模压力与流量斜率实际执行值		辅助变量
ActConf_ext U32 MoldClsPosBuff[4];									//关模各段位置实际执行值			辅助变量
#define		mMoldClsLPSPos		MoldClsPosBuff[2]		//关模低压位置
#define		mMoldClsLPFlow		MoldClsFlowBuff[3]		//关模低压流量
#define		mMoldClsLPPres		MoldClsPresBuff[3]		//关模低压压力
#define		mMoldClsSec1Pres	MoldClsPresBuff[0]		//关模一段压力

ActConf_ext U32 MoldOpnPresBuff[5],MoldOpnFlowBuff[5];				//开模压力与流量实际执行值			辅助变量
ActConf_ext U32 MoldOpnPresRampBuff[6],MoldOpnFlowRampBuff[6];		//开模压力与流量斜率实际执行值		辅助变量
ActConf_ext U32 MoldOpnPosBuff[5];									//开模各段位置实际执行值			辅助变量
#define		mMoldOpen2SPos		MoldOpnPosBuff[0]		//开模二段起始位置
#define		mMoldOpen2Pres		MoldOpnPresBuff[1]		//开模二段压力
#define		mMoldOpen2Flow		MoldOpnFlowBuff[1]		//开模二段流量
#define		mMoldOpenEPos		MoldOpnPosBuff[4]		//开模结束位置

//固定值变量		以下变量相当于常量，只可引用不可写入，主要供段、动作结构定义使用
#ifdef ActConf_c
	U32 Para_0=0;
	U32 Para_100=100;
	U32 Para_10000=10000;
	U32 Para_20000=20000;
	U32 Para_50000=50000;
	U32 Para_100000=100000;	
	U32 Para_H80000000=0x80000000;

	U32 Para_180s=T1sTo10us(3*60);	//3分钟
	U32 Para_30=30;
	
	Bool DryCycFlag;			//20200713		干循环是否使能
#else
	ActConf_ext	U32 Para_0;
	ActConf_ext U32 Para_100;
	ActConf_ext U32 Para_10000;
	ActConf_ext U32 Para_20000;
	ActConf_ext U32 Para_50000;
	ActConf_ext U32 Para_100000;	
	ActConf_ext	U32 Para_H80000000;

	ActConf_ext	U32 Para_180s;		//3分钟
	ActConf_ext	U32 Para_30;
	
	ActConf_ext Bool DryCycFlag;	//20200713		干循环是否使能
#endif

//-------------------------------------------------------------------------------------------------//
//资源RI信号滤波
//结构定义
typedef struct 
{
	U8 ResSN;					//对应资源序号
	Bool FValue;				//值
	U8 FltTime;					//滤波时间		单位：10ms
	G10msTimer FltTimer;		//滤波定时器
}RIFltStr;
	#define mRIF_ResSN_Null	0	//空		该项滤波未使用

//变量定义及初始化
#define mRIFltNum	33
#ifdef ActConf_c
	RIFltStr RIFlt[mRIFltNum]=	//RI滤波
	{	//资源序号				值			滤波时间	滤波定时器
		{mRI_EmerButton     ,	mFalse,		10,			0		},	//0		紧急停止   		滤波时间100ms
		{mRI_SafeGateFrontNO,	mFalse,		10,			0		},	//1 	安全门开
		{mRI_SafeGateFront	,	mFalse,		10,			0		},	//2     安全门关   
		{mRI_SafeGateFront2	,	mFalse,		10,			0		},	//3     安全门关二 
		{mRI_SafeGateBack	,	mFalse,		10,			0		},	//4     后安全门关 
		{mRI_SafeGateTop	,	mFalse,		10,			0		},	//5     上顶盖关   
		{mRI_SafeGateBut	,	mFalse,		10,			0		},	//6	    底板关     
		{mRI_ServoDrvErr	,	mFalse,		10,			0		},	//7		伺服驱动器异常
		{mRI_NozSafeGate	,	mFalse,		10,			0		},	//8		注射防护罩
		{mRI_HopperSnr		,	mFalse,		10,			0		},	//9		料斗检知
		{mRI_OilLessSnr		,	mFalse,		100,		0		},	//10	油位检知			滤波时间1s
		{mRI_OilFilterJam	,	mFalse,		100,		0		},	//11	滤网检知			滤波时间1s
		{mRI_MachProtSnr    ,	mFalse,		10,			0		},	//12    机械保险检知
		{mRI_HydProtSnr     ,	mFalse,		10,			0		},	//13    液压保险检知
		{mRI_AirSrcPresSnr  ,	mFalse,		10,			0		},	//14	气源压力检知
		{mRI_SafeRelayRst	,	mFalse,		10,			0		},	//15	安全继电器复位
		{mRI_NozLimitSwitch ,	mFalse,		3,			0		},	//16	射台限位			20110922加
		{mRI_CycStopKey,		mFalse,		3,			0		},	//17	循环停止键		20111106加
		{mRI_AutoGateOpenButt,	mFalse,		10,			0		},	//18	自动门开按钮		20120330加
		{mRI_AutoGateClsButt,	mFalse,		10,			0		},	//19	自动门关按钮		20120330加
		{mRI_J_EnClamp,			mFalse,		5,			0		},	//20	夹具允许关模		20120604加
		{mRI_J_EnMoldOpen,		mFalse,		5,			0		},	//21	夹具允许开模		20120604加
		{mRI_PilotOilPresSnr,	mFalse,		10,			0		},	//22	先导油压检测		20120804加
		{mRI_BMCFeedInButt,		mFalse,		10,			0		},	//23	BMC加料进按钮	20120805加
		{mRI_BMCFeedOutButt,	mFalse,		10,			0		},	//24	BMC加料退按钮	20120805加
		{mRI_SafePlate,			mFalse,		10,			0		},	//25	安全踏板			20120805加
		{mRI_CorePresRelButt,	mFalse,		10,			0		},	//26	中子卸压按钮		20120811加
		{mRI_CycStartKey,		mFalse,		10,			0		},	//27	循环启动键		20120814加
		{mRI_MotorErr,			mFalse,		10,			0		},	//28	电机异常			20130423加
		{mRI_SafeGateFixBack,	mFalse,		10,			0		},	//29	固定门关			20150422加
		{mRI_SafePlug,			mFalse,		10,			0		},	//30	安全插头			20150504加
		{mRI_ExtAlarm,			mFalse,		10,			0		},	//31	外部警报			20170605加
		{mRI_PowerMon,			mFalse,		10,			0		}	//32	电源确认			20220509加
		//{mRIF_xxx,			mFalse,		10,			0		}	//33
	};
#else
	ActConf_ext RIFltStr RIFlt[mRIFltNum];
#endif

//引用
#define FRI_EmerButton			RIFlt[0].FValue		//紧急停止
#define FRI_SafeGateFrontNO 	RIFlt[1].FValue		//安全门开
#define FRI_SafeGateFront		RIFlt[2].FValue		//安全门关
#define FRI_SafeGateFront2		RIFlt[3].FValue		//安全门关二
#define FRI_SafeGateBack		RIFlt[4].FValue		//后安全门关
#define FRI_SafeGateTop	    	RIFlt[5].FValue		//上顶盖关
#define FRI_SafeGateBut	    	RIFlt[6].FValue		//底板关
#define FRI_ServoDrvErr	    	RIFlt[7].FValue		//伺服驱动器异常
#define FRI_NozSafeGate	    	RIFlt[8].FValue		//注射防护罩
#define FRI_HopperSnr	    	RIFlt[9].FValue		//料斗检知
#define FRI_OilLessSnr			RIFlt[10].FValue	//油位检知
#define FRI_OilFilterJam		RIFlt[11].FValue	//滤网检知
#define FRI_MachProtSnr			RIFlt[12].FValue	//机械保险检知
#define FRI_HydProtSnr			RIFlt[13].FValue	//液压保险检知
#define FRI_AirSrcPresSnr		RIFlt[14].FValue	//气源压力检知
#define FRI_SafeRelayRst		RIFlt[15].FValue	//安全继电器复位
#define FRI_NozLimitSwitch		RIFlt[16].FValue	//射台限位			20110922加
#define FRI_CycStopKey			RIFlt[17].FValue	//循环停止键			20111106加
#define FRI_AutoGateOpenButt	RIFlt[18].FValue	//自动门开按钮		20120330加
#define FRI_AutoGateClsButt		RIFlt[19].FValue	//自动门关按钮		20120330加
#define FRI_J_EnClamp			RIFlt[20].FValue	//夹具允许关模		20120604加
#define FRI_J_EnMoldOpen		RIFlt[21].FValue	//夹具允许开模		20120604加
#define FRI_PilotOilPresSnr		RIFlt[22].FValue	//先导油压检测		20120804加
#define FRI_BMCFeedInButt		RIFlt[23].FValue	//BMC加料进按钮		20120805加
#define FRI_BMCFeedOutButt		RIFlt[24].FValue	//BMC加料退按钮		20120805加
#define FRI_SafePlate			RIFlt[25].FValue	//安全踏板			20120805加
#define FRI_CorePresRelButt		RIFlt[26].FValue	//中子卸压按钮		20120811加
#define FRI_CycStartKey			RIFlt[27].FValue	//循环启动键		20120814加
#define FRI_MotorErr			RIFlt[28].FValue	//电机异常			20130423加
#define FRI_SafeGateFixBack		RIFlt[29].FValue	//固定门关			20150422加
#define FRI_SafePlug			RIFlt[30].FValue	//安全插头			20150504加
#define FRI_ExtAlarm			RIFlt[31].FValue	//外部警报			20170605加
#define FRI_PowerMon			RIFlt[32].FValue	//电源确认			20220509加
//#define FRI_xxx				RIFlt[33].FValue	//


//新增一个RI滤波方法：	1）RIFlt[]数组中初始化资源序号及滤波时间
//						2）在引用中定义该RI的宏
//使用方法：FDI_xxx即滤波后的值、&FDI_xxx即变量地址，如果用在段结束条件中时，应注意此时是U8变量类型，而非RI了。

void RIFilterPcs(void);		//滤波处理			主循环执行，在ActConf_xx.c的ActConf_Pcs()中调用执行

void ScrewRPM_Meas(void);	//储料转速测量		主循环执行，在ActConf_xx.c的ActConf_Pcs()中调用执行

#endif

