#include "MemberInfo.h"
#include "FamilyInfo.h"

typedef struct Node//�������ڵ�Ķ���
{

	MemberInfo memberInfo;//��ͥ������Ա��Ϣ
	struct Node *child[10];//����ָ������
	struct Node *parent;//���ڵ�ָ��
	struct Node *couple;//��żָ��
	int level;			//��¼�ڵ���
	int childNum;		//��¼��������
}MemberNode,*Member;

typedef struct node
{
	Member ancestor;//���Ƚڵ�
	FamilyInfo familyInfo;//��¼����������Ϣ
}Family;
