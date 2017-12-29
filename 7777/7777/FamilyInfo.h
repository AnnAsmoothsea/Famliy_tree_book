#pragma once
class FamilyInfo
{
public:
	FamilyInfo(void);
	~FamilyInfo(void);

	int familyNumber;//家庭总人数
	int wNumber;//女性数量
	int mNumber;//男性数量
	int maxAge;//最小年龄
	int minAge;//最大年龄
	char historyDesease[500];//家庭疾病史
	char anotherInfo[500];//家庭其它描述信息

};

