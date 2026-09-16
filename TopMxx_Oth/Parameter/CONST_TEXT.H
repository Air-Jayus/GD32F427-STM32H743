#ifndef _CONST_TEXT_H
#define _CONST_TEXT_H
#include "fromcm.h"
//增加字符串需要增加下列定义
#define	OtherCaptionMax		49
#define ResCaptionMax		420
#define AlamCaptionMax		360
#define ActCaptionMax		180
#define WorkModeCaptionMax	9

#define ALARM_TEXT_LEN	23


//#define GetCaption(type,index)	(*((char **)(((void *)(type))+index*LANGUAGE_NUM)))


#define GetOtherCaption(index)		(index<=OtherCaptionMax?		(*((char **)OtherCaption+index*LANGUAGE_NUM+Para_LanguageSel))		:(*((char **)OtherCaption+Para_LanguageSel)))
#define GetWorkModeCaption(index)	(index<=WorkModeCaptionMax?		(*((char **)WorkModeCaption+index*LANGUAGE_NUM+Para_LanguageSel))	:(*((char **)WorkModeCaption+Para_LanguageSel)))
#define GetResCaption(index)		(index<=ResCaptionMax?			(*((char **)ResCaption+index*LANGUAGE_NUM+Para_LanguageSel))		:(*((char **)ResCaption+Para_LanguageSel)))
#define GetAlamCaption(index)		(index<=AlamCaptionMax?			(*((char **)AlamCaption+index*LANGUAGE_NUM+Para_LanguageSel))		:(*((char **)AlamCaption+Para_LanguageSel)))
#define GetActCaption(index)		(index<=ActCaptionMax?			(*((char **)ActCaption+index*LANGUAGE_NUM+Para_LanguageSel))		:(*((char **)ActCaption+Para_LanguageSel)))

//其他字符的位置定义
#define OtherCaption_MINV		0
#define OtherCaption_MAXV		1
#define OtherCaption_PASSWORD	2
#define OtherCaption_MAXV_MINV	3
#define OtherCaption_PROMPT		4
#define OtherCaption_DEFV		5
#define OtherCaption_STOP_MODE0	6
#define OtherCaption_STOP_MODE1	7
#define OtherCaption_MAKE_SURE	8
#define OtherCaption_PASSWORD1	9
#define OtherCaption_PASSWORD2	10
#define OtherCaption_PASSWORD3	11
#define OtherCaption_PASSWORD4	12
#define OtherCaption_PASSWORD5	13
#define OtherCaption_SAVETO_USB	14
#define OtherCaption_DianJi_JT	15
#define OtherCaption_DianJi_DT	16
#define OtherCaption_DianJi_XiaoLing	17
#define OtherCaption_MAKE_SURE_L		18
#define OtherCaption_RESET0				19		//立即重置稍后重置取消重置
#define OtherCaption_RESET1				20
#define OtherCaption_RESET2				21
#define OtherCaption_REBOOT				22		//重新启动
#define OtherCaption_CLR_WARM			23		//清警报记录
#define OtherCaption_CLR_EDIT			24		//清修改记录
#define OtherCaption_CHECK_WORK			25		//上下班登记
#define OtherCaption_CHECK_OK			26		//登记成功
#define OtherCaption_CHECK_ERR			27		//登记失败
#define OtherCaption_28					28	//清除
#define OtherCaption_29					29	//单次
#define OtherCaption_30					30	//重绘
#define OtherCaption_31					31//暂停
#define OtherCaption_32					32//开启
#define OtherCaption_33					33//是否保存到已有模号
#define OtherCaption_34					34//是否保存当前模号
#define OtherCaption_35					35//是
#define OtherCaption_36					36//否
#define OtherCaption_37					37//版本不同,可能出错,是否继续?
#define OtherCaption_38					38//删除U盘文件
#define OtherCaption_39					39//U盘中文件已存在,是否覆盖?	
#define OtherCaption_40					40//复位	
#define OtherCaption_41					41//所有点是否线性调整
#define OtherCaption_42					42//所有点是否补偿调整
#define OtherCaption_43					43//清零
#define OtherCaption_44					44//10000前
#define OtherCaption_45					45//10000后
#define OtherCaption_46					46//50000前
#define OtherCaption_47					47//50000后
#define OtherCaption_48					48//导入
extern inter_const char * inter_const AlamCaption[][LANGUAGE_NUM];
#endif
