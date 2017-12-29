#include "MemberInfo.h"
#include "FamilyInfo.h"

#ifndef	 _TreeDefined_
#define  _TreeDefined_

typedef struct Node1//树单个节点的定义
{

	CMemberInfo memberInfo;//家庭单个成员信息
	struct Node1 *child[10];//孩子指针数组
	struct Node1 *parent;//父节点指针
	struct Node1 *couple;//配偶指针
	int level;			//记录节点层次
	int childNum;		//记录孩子数量
}MemberNode,*Member;

typedef struct node1
{
	Member ancestor;//祖先节点
	FamilyInfo familyInfo;//记录家族总体信息
}Family;

#endif