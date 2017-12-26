#include "iostream"
#include "string"
using namespace std;

/*
完成八个函数
删除未完成  -------邱洁琳
保存为完成  -------仲治宇
界面优化，英文提示    ------蒋思月，邹鑫
资料搜集，拍照，需求分析文档整理，根据需求分析写流程图   ------李晨雪
*/
void Show()
{
	cout<<"            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
    cout<<"            *                                                           *"<<endl;
	cout<<"            *             1.Create a family genealogy                   *"<<endl;   //完成
	cout<<"            *             2.Show the family genealogy                   *"<<endl;   //完成
	cout<<"            *             3.Insert family genealogy                     *"<<endl;   //完成
	cout<<"            *             4.Delete the family genealogy                 *"<<endl;   //未完成  ---邱洁琳
	cout<<"            *             5.Search the family genealogy                 *"<<endl;   //完成
	cout<<"            *             6.Revise the member's information             *"<<endl;	 //未完成  ---仲治宇（邹鑫，蒋思月练手）
	cout<<"            *             7.Save                                        *"<<endl;   //未完成  ---仲治宇
	cout<<"            *             8.Read                                        *"<<endl;
	cout<<"            *             0.Exit                                        *"<<endl;
	cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
	cout<<"            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
}
/*status InitEmpty(Family &T)
{
	int i;
	T.ancestor = (Member)malloc(sizeof(MemberNode));//祖先申请节点空间
	if(!T.ancestor) return OVERFLOW;//若节点申请失败，返回OVERFLOW
	T.ancestor=NULL;
	T.ancestor->couple = NULL;
	T.ancestor->parent = NULL;		//将祖先的父节点置空
	for(i = 0; i < 10 ;i++)			//遍历祖先节点孩子节点
		T.ancestor->child[i] = NULL;//将祖先节点的孩子节点置空
	return OK;
}*/
status InitFamily(Family &T)																//函数一：初始化祖先及家族信息
{

	int i;
	T.ancestor = (Member)malloc(sizeof(MemberNode));//祖先申请节点空间
	if(!T.ancestor) return OVERFLOW;//若节点申请失败，返回OVERFLOW


    /*******祖先的基本信息及家庭基本信息输入**********/

	T.ancestor->parent=NULL;
	cout<<"                    Please input ancestor's name：";
	cin>>T.ancestor->memberInfo.name;//祖先姓名
	T.ancestor->memberInfo.sex='m';

	cout<<"                    Please input ancestor's birthdate：";//祖先出生年月日
	cin>>T.ancestor->memberInfo.birthYear;
	cout<<"                                                       ";
	cin>>T.ancestor->memberInfo.birthMonth;
	cout<<"                                                       ";
	cin>>T.ancestor->memberInfo.birthDay;
   

	cout<<"                    Please input ancestor's age：";//祖先年龄
	cin>>T.ancestor->memberInfo.age;
	T.familyInfo.maxAge = T.familyInfo.maxAge = T.ancestor->memberInfo.age;//将家庭最大最小年龄初始化


	cout<<"                    Please input ancestor's birthplace：";						//祖先出生地
	cin>>T.ancestor->memberInfo.birthPlace;


	cout<<"                    Is the ancestor still alive (0:No，1:Yes)：";			//祖先是否健在
	cin>>(bool)T.ancestor->memberInfo.isAlive;

	if(T.ancestor->memberInfo.isAlive == false) //若祖先不健在
	{
		cout<<"                    Please input ancestor's deathdate：";       //祖先死亡日期
		cin>>T.ancestor->memberInfo.deadYear;
		cin>>T.ancestor->memberInfo.deadMonth;
		cin>>T.ancestor->memberInfo.deadDay;
	}

	cout<<"                    Is the ancestor married(0:No，1:Yes)：";				//祖先是否有配偶
	cin>>(bool)T.ancestor->memberInfo.isMarrige;

	if(T.ancestor->memberInfo.isMarrige == true) //若祖先有配偶
	{
		T.ancestor->couple = (Member)malloc(sizeof(MemberNode));//配偶节点分配空间
		if(!T.ancestor->couple) return OVERFLOW;

		cout<<"                    Please input the name of the ancestor's wife：";			//配偶姓名
		cin>>T.ancestor->couple->memberInfo.name;

		cout<<"                    Please input the birthdate of the ancestor's wife：";		//配偶出生年月日
		cin>>T.ancestor->couple->memberInfo.birthYear;
		cout<<"                                                       ";
		cin>>T.ancestor->couple->memberInfo.birthMonth;
		cout<<"                                                       ";
		cin>>T.ancestor->couple->memberInfo.birthDay;

		cout<<"                    Please input the age of the ancestor's wife：";			//配偶年龄
		cin>>T.ancestor->couple->memberInfo.age;

		cout<<"                    Please input the birthplace of the ancestor's wife：";					//配偶出生地
		cin>>T.ancestor->couple->memberInfo.birthPlace;

		cout<<"                    Is the ancestor's wife still alive (0:No，1:Yes)：";   //配偶是否健在
		cin>>T.ancestor->couple->memberInfo.isAlive;

		if(T.ancestor->couple->memberInfo.isAlive == false)  //若配偶不健在
		{
			cout<<"                    Please input the deathdate of the ancestor's wife：";   //配偶死亡日期
			cin>>T.ancestor->couple->memberInfo.deadYear;
			cin>>T.ancestor->couple->memberInfo.deadMonth;
			cin>>T.ancestor->couple->memberInfo.deadDay;
			cout<<"                    hhhhh"<<endl;
		}
		T.familyInfo.wNumber++;					//女性成员数+1
		T.familyInfo.familyNumber++;			//家庭成员数加1
	}
	else										//若无配偶
		T.ancestor->couple = NULL;				//将配偶指针置空

	T.familyInfo.familyNumber++;				//家庭成员数加1
	T.familyInfo.mNumber++;						//男性成员数+1

   /*******祖先的基本信息及家庭基本信息输入完毕**********/

	T.ancestor->level = 0;						//根节点层次为0
	T.ancestor->childNum = 0;					//孩子数量为0

    /*********指针域初始化**********/
	T.ancestor->parent = NULL;		//将祖先的父节点置空
	for(i = 0; i < 10 ;i++)			//遍历祖先节点孩子节点
		T.ancestor->child[i] = NULL;//将祖先节点的孩子节点置空
	return OK;

}
	
status InitMember(Member &m,Family &T)					     									//函数二：初始化家族成员；
{
	int i;
	m = (Member)malloc(sizeof(MemberNode));//为成员节点申请空间
	if(!m) return OVERFLOW;					//若节点申请失败，返回OVERFLOW

    /*******成员的基本信息输入**********/

	cout<<"                    Please input the member's name：";
	cin>>m->memberInfo.name;				//成员姓名

	cout<<"                    Please input the member's birthdate：";		//成员出生年月日
	cin>>m->memberInfo.birthYear;
	cout<<"                                                       ";
	cin>>m->memberInfo.birthMonth;
	cout<<"                                                       ";
	cin>>m->memberInfo.birthDay;
   

	cout<<"                    Please input the member's age：";				//成员年龄
	cin>>m->memberInfo.age;

	cout<<"                    Please input the member's birthplace：";					 //成员出生地
	cin>>m->memberInfo.birthPlace;


	cout<<"                    Is the member still alive (0:No，1:Yes)：";	 //成员是否健在
	cin>>(bool)m->memberInfo.isAlive;

	if(m->memberInfo.isAlive == false)       //若成员不健在
	{
		cout<<"                    Please input the member's deathdate：";  //成员死亡日期
		cin>>m->memberInfo.deadYear;
		cin>>m->memberInfo.deadMonth;
		cin>>m->memberInfo.deadDay;
	}

	cout<<"                    Please input the member's sex (w:female，m:male)：";	 //成员性别
	cin>>m->memberInfo.sex;

	if(m->memberInfo.sex == 'm')				//若为男性
	{
		cout<<"                    Is the member married (0:No，1:Yes)：";	 //成员是否有配偶
		cin>>(bool)m->memberInfo.isMarrige;

		if(m->memberInfo.isMarrige == true)       //若成员有配偶
		{
			Member q;
			q = (Member)malloc(sizeof(MemberNode));//成员配偶节点分配空间
			m->couple=q;
			if(!q) return OVERFLOW;

			cout<<"                    Please input the name of the member's wife：";			//成员配偶姓名
			cin>>q->memberInfo.name;

			cout<<"                    Please input the birthdate of the member's wife：";		//成员配偶出生年月日
			cin>>q->memberInfo.birthYear;
			cout<<"                                                       ";
			cin>>q->memberInfo.birthMonth;
			cout<<"                                                       ";
			cin>>q->memberInfo.birthDay;

			cout<<"                    Please input the age of the member's wife：";		    	//成员配偶年龄
			cin>>q->memberInfo.age;

			cout<<"                    Please input the birthplace of the member's wife：";					//配偶出生地
			cin>>q->memberInfo.birthPlace;

			cout<<"                    Is the member's wife still alive (0:No，1:Yes)：";    //配偶是否健在
			cin>>q->memberInfo.isAlive;

			T.familyInfo.familyNumber++;

			if(q->memberInfo.isAlive == false)  //若成员配偶不健在
			{
				cout<<"                    Please input the deathdate of the ancestor's wife：";   //配偶死亡日期
				cin>>q->memberInfo.deadYear;
				cin>>q->memberInfo.deadMonth;
				cin>>q->memberInfo.deadDay;
				T.familyInfo.familyNumber--;
			}
		}
		else
			m->couple = NULL;

	}
	else					
	{
		m->couple = NULL;					    //将配偶指针置空
	}

	/*******成员的基本信息输入完毕**********/

	m->childNum = 0;							//孩子数量初始化为0

	/*********指针域初始化**********/

	m->parent = NULL;	   //将成员的父节点置空
	for(i = 0; i < 10 ;i++)//遍历成员节点的孩子节点
		m->child[i] = NULL;//将成员的孩子节点置空

	/*********指针域初始化完毕**********/

	return OK;

}
status InsertMember(Family &T,Member &pMember,Member m)											//函数三：插入家族成员
{
	pMember->child[pMember->childNum] = m;  //将成员节点插在第i个孩子后面
	m->level = pMember->level+1;			//该成员层次等于父节点层次+1
	m->parent = pMember;                    //将孩子节点的父指针指向父节点
	T.familyInfo.familyNumber ++;			//家庭总人数+1

	if(m->memberInfo.sex = 'w')  T.familyInfo.wNumber ++;	//若为女性，则家庭女性人数+1
	else  T.familyInfo.mNumber ++;							//若无男性，家庭男性人数+1
	pMember->childNum ++;									//父节点的孩子数量+1
    
	return 0;
}

status DeleteMember(Member m)	//函数四：删除家族成员
{

	if(m->childNum != 0)    //如果有孩子
	 {
		int i = 0;//若当前节点存在孩子节点,则递归调用此函数,利用树的深度搜索的思想来删除以第i棵整棵子树
			for (i = 0; i < m->childNum; i++)
			{
				DeleteMember(m->child[i]);
			}
			m->childNum = 0;//为了防止访问时孩子节点与其下标之间的关系发生错误，删除每一棵完整的小子树后再将childNum置为0
			return OK;
	 }
	else                   //如果无孩子
	{
		if (m->couple != NULL)  //如果有妻子
		{
			free(m->couple);
			m->couple=NULL;

			if(m->parent!=NULL)
			    m->parent->childNum--;
			free(m);
			m=NULL;
			return OK;
		}						//如果没有妻子
		else
		{
			if(m->parent!=NULL)
			    m->parent->childNum--;
			free(m);
			m=NULL;
			return OK;
		}	
	}
}

void PrintSpace(int n)  //打印空格
{
	int a = n;
	while(a--)			//循环
		putchar(' ');   //输出空格
}
void ShowMember(Member t)																		//函数五：显示所有家族成员
{
	if(t==NULL)
		return ;
	else
	{
		int i;
		putchar('*');
		PrintSpace(8*t->level);
		cout<<t->memberInfo.name;//输出姓名
		if(t->couple != NULL) cout<<"--wife:"<<t->couple->memberInfo.name; //若存在配偶，写输出配偶姓名
		cout<<endl;
		for(i = 0; i<t->childNum ; i++)  //输出孩子节点信息
			ShowMember(t->child[i]);
	}
   return;
}
void ShowFamilyInfo(Family T)																	//函数六：显示家庭人员信息
{
	cout<<"                    FamilyNumber: "<<T.familyInfo.familyNumber<<endl;  //输出家庭总人数
	cout<<"                    ManNumber: "<<T.familyInfo.mNumber<<endl;		  //输出家庭男性数量
	cout<<"                    WomanNumber: "<<T.familyInfo.wNumber<<endl;		  //输出家庭女性数量	
}

Member SearchFamily(Member t,char key[])														//函数七：根据关键字查找成员节点（一般为名字）
{
	Member m = NULL; //查找节点初始化为空
	Member mm = NULL;//辅助节点设计
	if(strncmp(t->memberInfo.name,key,strlen(key)) == 0)  //若当前节点姓名等于关键字
	{
		return t;
	}
	if(t ->childNum != 0)		 //若当前节点存在孩子节点
	{
		int i;
		for(i = 0 ; i<t->childNum ; i++)
		{
		    mm = SearchFamily(t->child[i],key);
			if( mm != NULL)
			{
				m = mm;           //更新查找节点
				break;			  //退出循环
			}
		}
	}
	return m;					 //返回查找节点
}

void SaveFamilyFile(Family T)																	  //函数八：将节点保存在文件里
{
	Member head;
	Member queue[20];
	int i,front,rear;//创建一个队列
	FILE *fp;
	fp=fopen("Information.txt", "w");
	if(fp==NULL)
	{
		cout<<"false"<<endl;
		return ;
	}//以读写方式打开文件
	fwrite(T.ancestor,sizeof(MemberNode),1,fp);
	front =rear=0;
	queue[rear++]=T.ancestor;
	while(front !=rear) //广度有限遍历树并且写入文件
	{
		head=queue[front++];
		for(i=0;i<head->childNum;i++)
		{
			fwrite(head->child[i],sizeof(MemberNode),1,fp);
			queue[rear++]=head->child[i];
		}
	}
	fclose(fp);
	fp=NULL;
	return ;
}
void ReadFamily(Family &T)
{
	Member head,root;
	Member queue[20];
	int i,front,rear;//创建一个队列
	FILE *fp;
	fp=fopen("Information.txt", "r");
	if(fp==NULL)
	{
		cout<<"false"<<endl;
		return ;
	}//以读方式打开文件
	root=(Member)malloc(sizeof(MemberNode));

	fread(root,sizeof(MemberNode),1,fp);

	front =rear=0;
	queue[rear++]=root;
	while(front!=rear)
	{
		head=queue[front++];
		if(head->childNum==0)//若果孩子树为0，依次置为空
		{
			int i;
			for(i=0;i<10;i++)
				head->child[i]=NULL;
		}
		else
		{
			for(i=0;i<head->childNum;i++)
			{
				head->child[i]=(Member)malloc(sizeof(MemberNode));
				fread(head->child[i],sizeof(MemberNode),1,fp);
				head->child[i]->parent=head;//指向父亲结点
				queue[rear++]=head->child[i];
			}
		}
	}
	T.ancestor=root;
	fclose(fp);
	fp=NULL;
	return ;
}

void ResetMemberInfo(Member &m,char name[])  //重载1：修改成员名字
{
}
void ResetMemberInfo(Member &m,int year,int month,int day)  //重载2：修改成员死亡日期
{
}
void ResetMemberInfo(Member &m)  //重载1：修改成员配偶信息直接在里面操作
{
}
int Function(Family &T,int x)
{
	Member m = NULL;
	Member pMember = NULL,searchMember = NULL;				//定义查询父指针和查找指针
	char searchName[50] = "";					//定义查找姓名数组

	switch(x)
	{
	case 1:
		system("cls");			//清屏
		if(InitFamily(T) == OK)//初始化
		{
			cout<<endl;
			cout<<"   --------------------Succeed to initialize the family genealogy!--------------------"<<endl<<endl;
			return 1;
		}
		else
		{
			cout<<endl;
			cout<<"   --------------------Failed to initialize the family genealogy!--------------------"<<endl<<endl;
			return 0;	
		}
	case 2:
		system("cls");											//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                --------------------FamilyTreeView-----------------------"<<endl;	//提示信息
		ShowMember(T.ancestor);									//显示
		cout<<endl;
		cout<<"                --------------------FamilyInformation--------------------"<<endl; //提示信息
		ShowFamilyInfo(T);										//输出家庭信息
		cout<<endl;
		return 1;
	case 3:
		system("cls");											//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                    Please input the position you want to insert(the fatherName)->"<<endl;
		cin>>searchName;										//输入查找姓名

		pMember = SearchFamily(T.ancestor,searchName);			//在树中查找姓名

		if(pMember == NULL)										//若查找失败
		{
			cout<<"                    The member is not exit!"<<endl<<endl;				//输出提示信息
		}
		else					
		{
			cout<<"                    Please input the init-Information if the new member:"<<endl;		    //输出提示
			InitMember(m,T);								//将成员初始化
			InsertMember(T,pMember,m);					//将成员信息插入到父节点pMember中
			cout<<"                    Insert successful!"<<endl<<endl;				//提示信息
		}	
		return 1;
	case 4:
		system("cls");			//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout << "Please input the name of the member that you want to delete from this book:" << endl;
		cin >> searchName;
		searchMember = SearchFamily(T.ancestor, searchName); //在树中查找姓名
		if (searchMember == NULL)							//若查找失败
		{
			cout << "The member is no exit!" << endl << endl;					//输出提示信息
		}
		else
		{
			if(searchMember==T.ancestor)
			{
				cout << "You can not delete the first one  !" << endl;
				return 1;
			}
			DeleteMember(searchMember);
			if (DeleteMember(searchMember))
				cout << "Successfully delete this member and his/her relative members!" << endl;
			else
				cout << "Falie to delete......" << endl;
		}
		return 1;
	case 5:
		system("cls");			//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                    Please input the position you want to insert(the memberName)->"<<endl;
		cin>>searchName;							//输入查找姓名

		searchMember = SearchFamily(T.ancestor,searchName); //在树中查找姓名

		if(searchMember == NULL)							//若查找失败
		{
			cout<<"                    The member is no exit!"<<endl<<endl;					//输出提示信息
		}
		else					
		{
			cout<<"                    Search successful!"<<endl<<endl;
			cout<<"   --------------------Member information--------------------"<<endl;
			searchMember->memberInfo.PrintInfo();			//输出查找到节点的详细信息     
			if(searchMember->couple != NULL)				//若有妻室
			{
				cout<<"   --------------------wife's information--------------------"<<endl;	//输出提示信息				
				searchMember->couple->memberInfo.PrintInfo();//输出妻子的信息
			}
			cout<<endl;									   	 //换行
		}	
		return 1;
	case 6:
		system("cls");			//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		return 1;
	case 7:
		system("cls");			//清屏
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		SaveFamilyFile(T);
		cout << "Successfully save the members to a file!" << endl;
		return 1;
	case 8:
		system("cls");			//清屏
		ReadFamily(T);
		cout << "Successfully read the members from a file!" << endl;
		return 1;
	default:
		return 0;
	}
}



/*问题
1.界面设计
2.输出家族信息时的显示
3.树形显示
4.全英
5.写入文件
*/

/*
函数一：初始化祖先及家族信息
函数二：初始化家族成员；
函数三：插入家族成员
函数四：删除家族成员
函数五：显示所有家族成员
函数六：显示家庭人员信息节点（一般为名字）
函数八：将节点保存在文件里
函数七：根据关键字查找成员
函数九：修改成员信息（死亡日期，配偶情况，姓名）//重载
*/
