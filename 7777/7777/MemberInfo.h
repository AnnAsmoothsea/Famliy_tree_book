#pragma once
class CMemberInfo
{
public:
	CMemberInfo(void);
	~CMemberInfo(void);

	char name[100];//姓名
	char sex;//性别
	int age;//年龄
	char nation[10];//名族数组
	int birthYear,birthMonth,birthDay;//出生年月日
	bool isAlive;//是否健在
	bool isMarrige;//婚否
	int deadYear,deadMonth,deadDay;//死亡年月日

	char eduDegree[10];//学历
	char birthPlace[50];//籍贯
	char policy[50];//政治面貌
	char number[20];//联系方式
	char adress[500];//家庭住址
	char anotherInfo[500];//其它描述信息


};

