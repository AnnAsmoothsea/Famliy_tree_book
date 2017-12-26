#include "MemberInfo.h"
#include "FamilyInfo.h"

typedef struct Node//树单个节点的定义
{

	MemberInfo memberInfo;//家庭单个成员信息
	struct Node *child[10];//孩子指针数组
	struct Node *parent;//父节点指针
	struct Node *couple;//配偶指针
	int level;			//记录节点层次
	int childNum;		//记录孩子数量
}MemberNode,*Member;

typedef struct node
{
	Member ancestor;//祖先节点
	FamilyInfo familyInfo;//记录家族总体信息
}Family;
