#pragma once
class CMemberInfo
{
public:
	CMemberInfo(void);
	~CMemberInfo(void);

	char name[100];//����
	char sex;//�Ա�
	int age;//����
	char nation[10];//��������
	int birthYear,birthMonth,birthDay;//����������
	bool isAlive;//�Ƿ���
	bool isMarrige;//���
	int deadYear,deadMonth,deadDay;//����������

	char eduDegree[10];//ѧ��
	char birthPlace[50];//����
	char policy[50];//������ò
	char number[20];//��ϵ��ʽ
	char adress[500];//��ͥסַ
	char anotherInfo[500];//����������Ϣ


};

