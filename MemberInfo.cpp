// MemberInfo.cpp: implementation of the MemberInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "MemberInfo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
MemberInfo::MemberInfo()
{
//	name = " ";
//	birthPlace = " ";//出生地
	char sex = 'w';//性别
	int age = 0;//年龄
	birthYear = 1900;
	birthMonth = 1;
	birthDay = 1;//出生年月日

    isAlive = true;//是否健在
    isMarrige = false;//婚否

	deadYear = 1900;
	deadMonth = 1;
	deadDay = 1;//出生年月日
}

MemberInfo::~MemberInfo()
{

}
void MemberInfo::PrintInfo()
{
	cout<<"Name: "<<this->name<<endl;				//输出姓名
	cout<<"Sex:  "<<this->sex<<endl;				//输出性别
	cout<<"Age:  "<<this->age<<endl;				//输出年龄
	cout<<"Birthplace: "<<this->birthPlace<<endl;	//输出出生地
	cout<<"Birthday: "<<this->birthYear<<"-"<<this->birthMonth<<"-"<<this->birthDay<<endl;		//输出出生日期
	if(this->isAlive == false)
		cout<<"Deadhday: "<<this->deadMonth<<"-"<<this->deadMonth<<"-"<<this->deadDay<<endl;	//输出死亡日期
}