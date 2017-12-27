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
	void PrintInfo();//��ʾ��Ϣ

    char name[50];//����
	char birthPlace[100];//������ַ
	char sex;//�Ա�
	int mark;//���
	int age;//����
	int birthYear;
	int birthMonth;
	int birthDay;//����������
	bool isAlive;//�Ƿ���
	bool isMarrige;//���
	int deadYear,deadMonth,deadDay;//����������
	
};

#endif // !defined(AFX_MEMBERINFO_H__E09E10B4_70C3_4042_843D_30BD3AB66487__INCLUDED_)
