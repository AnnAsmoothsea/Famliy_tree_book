// FamilyInfo.h: interface for the FamilyInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FAMILYINFO_H__4A2C20D9_F073_4335_8DAF_DB4CCFAF0B5F__INCLUDED_)
#define AFX_FAMILYINFO_H__4A2C20D9_F073_4335_8DAF_DB4CCFAF0B5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FamilyInfo  
{
public:
	FamilyInfo();
	virtual ~FamilyInfo();
	void PrinInfo();//��ʾ��Ϣ
	int familyNumber;//��ͥ������
	int wNumber;//Ů������
	int mNumber;//��������
	int maxAge;//��С����
	int minAge;//�������
};

#endif // !defined(AFX_FAMILYINFO_H__4A2C20D9_F073_4335_8DAF_DB4CCFAF0B5F__INCLUDED_)
