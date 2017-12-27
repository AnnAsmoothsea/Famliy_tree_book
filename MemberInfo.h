// MemberInfo.h: interface for the MemberInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEMBERINFO_H__E09E10B4_70C3_4042_843D_30BD3AB66487__INCLUDED_)
#define AFX_MEMBERINFO_H__E09E10B4_70C3_4042_843D_30BD3AB66487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "iostream"
#include "string"
using namespace std;

class MemberInfo  
{
public:
	MemberInfo();
	virtual ~MemberInfo();
	void PrintInfo();//显示信息

    char name[50];//姓名
	char birthPlace[100];//出生地址
	char sex;//性别
	int mark;//标记
	int age;//年龄
	int birthYear;
	int birthMonth;
	int birthDay;//出生年月日
	bool isAlive;//是否健在
	bool isMarrige;//婚否
	int deadYear,deadMonth,deadDay;//死亡年月日
	
};

#endif // !defined(AFX_MEMBERINFO_H__E09E10B4_70C3_4042_843D_30BD3AB66487__INCLUDED_)
