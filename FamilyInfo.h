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
	FamilyInfo operator =(FamilyInfo &p)
	{
		
		familyNumber=p.familyNumber;
		wNumber=p.wNumber;
		maxAge=p.maxAge;
		maxAge=p.maxAge;
		minAge=p.minAge;
		return *this;
	}
	void PrinInfo();//显示信息
	int familyNumber;//家庭总人数
	int wNumber;//女性数量
	int mNumber;//男性数量
	int maxAge;//最小年龄
	int minAge;//最大年龄
};

#endif // !defined(AFX_FAMILYINFO_H__4A2C20D9_F073_4335_8DAF_DB4CCFAF0B5F__INCLUDED_)
