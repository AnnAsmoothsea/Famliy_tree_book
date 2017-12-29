#include "StdAfx.h"
#include "MemberInfo.h"


CMemberInfo::CMemberInfo(void)
{

	this->sex  = 'm';//性别
	age = 0;//年龄
	birthYear = 0;
	birthMonth = 0;
	birthDay = 0;//出生年月日
	isAlive = true;//是否健在
	isMarrige = false;//婚否
	deadYear = 0;
	deadMonth = 0;
	deadDay = 0;//死亡年月日
}


CMemberInfo::~CMemberInfo(void)
{
}
