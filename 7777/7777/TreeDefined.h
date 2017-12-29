#include "MemberInfo.h"
#include "FamilyInfo.h"

#ifndef	 _TreeDefined_
#define  _TreeDefined_

typedef struct Node1//�������ڵ�Ķ���
{

	CMemberInfo memberInfo;//��ͥ������Ա��Ϣ
	struct Node1 *child[10];//����ָ������
	struct Node1 *parent;//���ڵ�ָ��
	struct Node1 *couple;//��żָ��
	int level;			//��¼�ڵ���
	int childNum;		//��¼��������
}MemberNode,*Member;

typedef struct node1
{
	Member ancestor;//���Ƚڵ�
	FamilyInfo familyInfo;//��¼����������Ϣ
}Family;

#endif