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
//	birthPlace = " ";//������
	char sex = 'w';//�Ա�
	int age = 0;//����
	birthYear = 1900;
	birthMonth = 1;
	birthDay = 1;//����������

    isAlive = true;//�Ƿ���
    isMarrige = false;//���

	deadYear = 1900;
	deadMonth = 1;
	deadDay = 1;//����������
}

MemberInfo::~MemberInfo()
{

}
void MemberInfo::PrintInfo()
{
	cout<<"Name: "<<this->name<<endl;				//�������
	cout<<"Sex:  "<<this->sex<<endl;				//����Ա�
	cout<<"Age:  "<<this->age<<endl;				//�������
	cout<<"Birthplace: "<<this->birthPlace<<endl;	//���������
	cout<<"Birthday: "<<this->birthYear<<"-"<<this->birthMonth<<"-"<<this->birthDay<<endl;		//�����������
	if(this->isAlive == false)
		cout<<"Deadhday: "<<this->deadMonth<<"-"<<this->deadMonth<<"-"<<this->deadDay<<endl;	//�����������
}