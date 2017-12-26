#include "iostream"
#include "string"
using namespace std;

/*
��ɰ˸�����
ɾ��δ���  -------�����
����Ϊ���  -------������
�����Ż���Ӣ����ʾ    ------��˼�£�����
�����Ѽ������գ���������ĵ����������������д����ͼ   ------�ѩ
*/
void Show()
{
	cout<<"            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
	cout<<"            *                                                           *"<<endl;
    cout<<"            *                                                           *"<<endl;
	cout<<"            *             1.Create a family genealogy                   *"<<endl;   //���
	cout<<"            *             2.Show the family genealogy                   *"<<endl;   //���
	cout<<"            *             3.Insert family genealogy                     *"<<endl;   //���
	cout<<"            *             4.Delete the family genealogy                 *"<<endl;   //δ���  ---�����
	cout<<"            *             5.Search the family genealogy                 *"<<endl;   //���
	cout<<"            *             6.Revise the member's information             *"<<endl;	 //δ���  ---��������Σ���˼�����֣�
	cout<<"            *             7.Save                                        *"<<endl;   //δ���  ---������
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
	T.ancestor = (Member)malloc(sizeof(MemberNode));//��������ڵ�ռ�
	if(!T.ancestor) return OVERFLOW;//���ڵ�����ʧ�ܣ�����OVERFLOW
	T.ancestor=NULL;
	T.ancestor->couple = NULL;
	T.ancestor->parent = NULL;		//�����ȵĸ��ڵ��ÿ�
	for(i = 0; i < 10 ;i++)			//�������Ƚڵ㺢�ӽڵ�
		T.ancestor->child[i] = NULL;//�����Ƚڵ�ĺ��ӽڵ��ÿ�
	return OK;
}*/
status InitFamily(Family &T)																//����һ����ʼ�����ȼ�������Ϣ
{

	int i;
	T.ancestor = (Member)malloc(sizeof(MemberNode));//��������ڵ�ռ�
	if(!T.ancestor) return OVERFLOW;//���ڵ�����ʧ�ܣ�����OVERFLOW


    /*******���ȵĻ�����Ϣ����ͥ������Ϣ����**********/

	T.ancestor->parent=NULL;
	cout<<"                    Please input ancestor's name��";
	cin>>T.ancestor->memberInfo.name;//��������
	T.ancestor->memberInfo.sex='m';

	cout<<"                    Please input ancestor's birthdate��";//���ȳ���������
	cin>>T.ancestor->memberInfo.birthYear;
	cout<<"                                                       ";
	cin>>T.ancestor->memberInfo.birthMonth;
	cout<<"                                                       ";
	cin>>T.ancestor->memberInfo.birthDay;
   

	cout<<"                    Please input ancestor's age��";//��������
	cin>>T.ancestor->memberInfo.age;
	T.familyInfo.maxAge = T.familyInfo.maxAge = T.ancestor->memberInfo.age;//����ͥ�����С�����ʼ��


	cout<<"                    Please input ancestor's birthplace��";						//���ȳ�����
	cin>>T.ancestor->memberInfo.birthPlace;


	cout<<"                    Is the ancestor still alive (0:No��1:Yes)��";			//�����Ƿ���
	cin>>(bool)T.ancestor->memberInfo.isAlive;

	if(T.ancestor->memberInfo.isAlive == false) //�����Ȳ�����
	{
		cout<<"                    Please input ancestor's deathdate��";       //������������
		cin>>T.ancestor->memberInfo.deadYear;
		cin>>T.ancestor->memberInfo.deadMonth;
		cin>>T.ancestor->memberInfo.deadDay;
	}

	cout<<"                    Is the ancestor married(0:No��1:Yes)��";				//�����Ƿ�����ż
	cin>>(bool)T.ancestor->memberInfo.isMarrige;

	if(T.ancestor->memberInfo.isMarrige == true) //����������ż
	{
		T.ancestor->couple = (Member)malloc(sizeof(MemberNode));//��ż�ڵ����ռ�
		if(!T.ancestor->couple) return OVERFLOW;

		cout<<"                    Please input the name of the ancestor's wife��";			//��ż����
		cin>>T.ancestor->couple->memberInfo.name;

		cout<<"                    Please input the birthdate of the ancestor's wife��";		//��ż����������
		cin>>T.ancestor->couple->memberInfo.birthYear;
		cout<<"                                                       ";
		cin>>T.ancestor->couple->memberInfo.birthMonth;
		cout<<"                                                       ";
		cin>>T.ancestor->couple->memberInfo.birthDay;

		cout<<"                    Please input the age of the ancestor's wife��";			//��ż����
		cin>>T.ancestor->couple->memberInfo.age;

		cout<<"                    Please input the birthplace of the ancestor's wife��";					//��ż������
		cin>>T.ancestor->couple->memberInfo.birthPlace;

		cout<<"                    Is the ancestor's wife still alive (0:No��1:Yes)��";   //��ż�Ƿ���
		cin>>T.ancestor->couple->memberInfo.isAlive;

		if(T.ancestor->couple->memberInfo.isAlive == false)  //����ż������
		{
			cout<<"                    Please input the deathdate of the ancestor's wife��";   //��ż��������
			cin>>T.ancestor->couple->memberInfo.deadYear;
			cin>>T.ancestor->couple->memberInfo.deadMonth;
			cin>>T.ancestor->couple->memberInfo.deadDay;
			cout<<"                    hhhhh"<<endl;
		}
		T.familyInfo.wNumber++;					//Ů�Գ�Ա��+1
		T.familyInfo.familyNumber++;			//��ͥ��Ա����1
	}
	else										//������ż
		T.ancestor->couple = NULL;				//����żָ���ÿ�

	T.familyInfo.familyNumber++;				//��ͥ��Ա����1
	T.familyInfo.mNumber++;						//���Գ�Ա��+1

   /*******���ȵĻ�����Ϣ����ͥ������Ϣ�������**********/

	T.ancestor->level = 0;						//���ڵ���Ϊ0
	T.ancestor->childNum = 0;					//��������Ϊ0

    /*********ָ�����ʼ��**********/
	T.ancestor->parent = NULL;		//�����ȵĸ��ڵ��ÿ�
	for(i = 0; i < 10 ;i++)			//�������Ƚڵ㺢�ӽڵ�
		T.ancestor->child[i] = NULL;//�����Ƚڵ�ĺ��ӽڵ��ÿ�
	return OK;

}
	
status InitMember(Member &m,Family &T)					     									//����������ʼ�������Ա��
{
	int i;
	m = (Member)malloc(sizeof(MemberNode));//Ϊ��Ա�ڵ�����ռ�
	if(!m) return OVERFLOW;					//���ڵ�����ʧ�ܣ�����OVERFLOW

    /*******��Ա�Ļ�����Ϣ����**********/

	cout<<"                    Please input the member's name��";
	cin>>m->memberInfo.name;				//��Ա����

	cout<<"                    Please input the member's birthdate��";		//��Ա����������
	cin>>m->memberInfo.birthYear;
	cout<<"                                                       ";
	cin>>m->memberInfo.birthMonth;
	cout<<"                                                       ";
	cin>>m->memberInfo.birthDay;
   

	cout<<"                    Please input the member's age��";				//��Ա����
	cin>>m->memberInfo.age;

	cout<<"                    Please input the member's birthplace��";					 //��Ա������
	cin>>m->memberInfo.birthPlace;


	cout<<"                    Is the member still alive (0:No��1:Yes)��";	 //��Ա�Ƿ���
	cin>>(bool)m->memberInfo.isAlive;

	if(m->memberInfo.isAlive == false)       //����Ա������
	{
		cout<<"                    Please input the member's deathdate��";  //��Ա��������
		cin>>m->memberInfo.deadYear;
		cin>>m->memberInfo.deadMonth;
		cin>>m->memberInfo.deadDay;
	}

	cout<<"                    Please input the member's sex (w:female��m:male)��";	 //��Ա�Ա�
	cin>>m->memberInfo.sex;

	if(m->memberInfo.sex == 'm')				//��Ϊ����
	{
		cout<<"                    Is the member married (0:No��1:Yes)��";	 //��Ա�Ƿ�����ż
		cin>>(bool)m->memberInfo.isMarrige;

		if(m->memberInfo.isMarrige == true)       //����Ա����ż
		{
			Member q;
			q = (Member)malloc(sizeof(MemberNode));//��Ա��ż�ڵ����ռ�
			m->couple=q;
			if(!q) return OVERFLOW;

			cout<<"                    Please input the name of the member's wife��";			//��Ա��ż����
			cin>>q->memberInfo.name;

			cout<<"                    Please input the birthdate of the member's wife��";		//��Ա��ż����������
			cin>>q->memberInfo.birthYear;
			cout<<"                                                       ";
			cin>>q->memberInfo.birthMonth;
			cout<<"                                                       ";
			cin>>q->memberInfo.birthDay;

			cout<<"                    Please input the age of the member's wife��";		    	//��Ա��ż����
			cin>>q->memberInfo.age;

			cout<<"                    Please input the birthplace of the member's wife��";					//��ż������
			cin>>q->memberInfo.birthPlace;

			cout<<"                    Is the member's wife still alive (0:No��1:Yes)��";    //��ż�Ƿ���
			cin>>q->memberInfo.isAlive;

			T.familyInfo.familyNumber++;

			if(q->memberInfo.isAlive == false)  //����Ա��ż������
			{
				cout<<"                    Please input the deathdate of the ancestor's wife��";   //��ż��������
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
		m->couple = NULL;					    //����żָ���ÿ�
	}

	/*******��Ա�Ļ�����Ϣ�������**********/

	m->childNum = 0;							//����������ʼ��Ϊ0

	/*********ָ�����ʼ��**********/

	m->parent = NULL;	   //����Ա�ĸ��ڵ��ÿ�
	for(i = 0; i < 10 ;i++)//������Ա�ڵ�ĺ��ӽڵ�
		m->child[i] = NULL;//����Ա�ĺ��ӽڵ��ÿ�

	/*********ָ�����ʼ�����**********/

	return OK;

}
status InsertMember(Family &T,Member &pMember,Member m)											//����������������Ա
{
	pMember->child[pMember->childNum] = m;  //����Ա�ڵ���ڵ�i�����Ӻ���
	m->level = pMember->level+1;			//�ó�Ա��ε��ڸ��ڵ���+1
	m->parent = pMember;                    //�����ӽڵ�ĸ�ָ��ָ�򸸽ڵ�
	T.familyInfo.familyNumber ++;			//��ͥ������+1

	if(m->memberInfo.sex = 'w')  T.familyInfo.wNumber ++;	//��ΪŮ�ԣ����ͥŮ������+1
	else  T.familyInfo.mNumber ++;							//�������ԣ���ͥ��������+1
	pMember->childNum ++;									//���ڵ�ĺ�������+1
    
	return 0;
}

status DeleteMember(Member m)	//�����ģ�ɾ�������Ա
{

	if(m->childNum != 0)    //����к���
	 {
		int i = 0;//����ǰ�ڵ���ں��ӽڵ�,��ݹ���ô˺���,�����������������˼����ɾ���Ե�i����������
			for (i = 0; i < m->childNum; i++)
			{
				DeleteMember(m->child[i]);
			}
			m->childNum = 0;//Ϊ�˷�ֹ����ʱ���ӽڵ������±�֮��Ĺ�ϵ��������ɾ��ÿһ��������С�������ٽ�childNum��Ϊ0
			return OK;
	 }
	else                   //����޺���
	{
		if (m->couple != NULL)  //���������
		{
			free(m->couple);
			m->couple=NULL;

			if(m->parent!=NULL)
			    m->parent->childNum--;
			free(m);
			m=NULL;
			return OK;
		}						//���û������
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

void PrintSpace(int n)  //��ӡ�ո�
{
	int a = n;
	while(a--)			//ѭ��
		putchar(' ');   //����ո�
}
void ShowMember(Member t)																		//�����壺��ʾ���м����Ա
{
	if(t==NULL)
		return ;
	else
	{
		int i;
		putchar('*');
		PrintSpace(8*t->level);
		cout<<t->memberInfo.name;//�������
		if(t->couple != NULL) cout<<"--wife:"<<t->couple->memberInfo.name; //��������ż��д�����ż����
		cout<<endl;
		for(i = 0; i<t->childNum ; i++)  //������ӽڵ���Ϣ
			ShowMember(t->child[i]);
	}
   return;
}
void ShowFamilyInfo(Family T)																	//����������ʾ��ͥ��Ա��Ϣ
{
	cout<<"                    FamilyNumber: "<<T.familyInfo.familyNumber<<endl;  //�����ͥ������
	cout<<"                    ManNumber: "<<T.familyInfo.mNumber<<endl;		  //�����ͥ��������
	cout<<"                    WomanNumber: "<<T.familyInfo.wNumber<<endl;		  //�����ͥŮ������	
}

Member SearchFamily(Member t,char key[])														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�
{
	Member m = NULL; //���ҽڵ��ʼ��Ϊ��
	Member mm = NULL;//�����ڵ����
	if(strncmp(t->memberInfo.name,key,strlen(key)) == 0)  //����ǰ�ڵ��������ڹؼ���
	{
		return t;
	}
	if(t ->childNum != 0)		 //����ǰ�ڵ���ں��ӽڵ�
	{
		int i;
		for(i = 0 ; i<t->childNum ; i++)
		{
		    mm = SearchFamily(t->child[i],key);
			if( mm != NULL)
			{
				m = mm;           //���²��ҽڵ�
				break;			  //�˳�ѭ��
			}
		}
	}
	return m;					 //���ز��ҽڵ�
}

void SaveFamilyFile(Family T)																	  //�����ˣ����ڵ㱣�����ļ���
{
	Member head;
	Member queue[20];
	int i,front,rear;//����һ������
	FILE *fp;
	fp=fopen("Information.txt", "w");
	if(fp==NULL)
	{
		cout<<"false"<<endl;
		return ;
	}//�Զ�д��ʽ���ļ�
	fwrite(T.ancestor,sizeof(MemberNode),1,fp);
	front =rear=0;
	queue[rear++]=T.ancestor;
	while(front !=rear) //������ޱ���������д���ļ�
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
	int i,front,rear;//����һ������
	FILE *fp;
	fp=fopen("Information.txt", "r");
	if(fp==NULL)
	{
		cout<<"false"<<endl;
		return ;
	}//�Զ���ʽ���ļ�
	root=(Member)malloc(sizeof(MemberNode));

	fread(root,sizeof(MemberNode),1,fp);

	front =rear=0;
	queue[rear++]=root;
	while(front!=rear)
	{
		head=queue[front++];
		if(head->childNum==0)//����������Ϊ0��������Ϊ��
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
				head->child[i]->parent=head;//ָ���׽��
				queue[rear++]=head->child[i];
			}
		}
	}
	T.ancestor=root;
	fclose(fp);
	fp=NULL;
	return ;
}

void ResetMemberInfo(Member &m,char name[])  //����1���޸ĳ�Ա����
{
}
void ResetMemberInfo(Member &m,int year,int month,int day)  //����2���޸ĳ�Ա��������
{
}
void ResetMemberInfo(Member &m)  //����1���޸ĳ�Ա��ż��Ϣֱ�����������
{
}
int Function(Family &T,int x)
{
	Member m = NULL;
	Member pMember = NULL,searchMember = NULL;				//�����ѯ��ָ��Ͳ���ָ��
	char searchName[50] = "";					//���������������

	switch(x)
	{
	case 1:
		system("cls");			//����
		if(InitFamily(T) == OK)//��ʼ��
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
		system("cls");											//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                --------------------FamilyTreeView-----------------------"<<endl;	//��ʾ��Ϣ
		ShowMember(T.ancestor);									//��ʾ
		cout<<endl;
		cout<<"                --------------------FamilyInformation--------------------"<<endl; //��ʾ��Ϣ
		ShowFamilyInfo(T);										//�����ͥ��Ϣ
		cout<<endl;
		return 1;
	case 3:
		system("cls");											//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                    Please input the position you want to insert(the fatherName)->"<<endl;
		cin>>searchName;										//�����������

		pMember = SearchFamily(T.ancestor,searchName);			//�����в�������

		if(pMember == NULL)										//������ʧ��
		{
			cout<<"                    The member is not exit!"<<endl<<endl;				//�����ʾ��Ϣ
		}
		else					
		{
			cout<<"                    Please input the init-Information if the new member:"<<endl;		    //�����ʾ
			InitMember(m,T);								//����Ա��ʼ��
			InsertMember(T,pMember,m);					//����Ա��Ϣ���뵽���ڵ�pMember��
			cout<<"                    Insert successful!"<<endl<<endl;				//��ʾ��Ϣ
		}	
		return 1;
	case 4:
		system("cls");			//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout << "Please input the name of the member that you want to delete from this book:" << endl;
		cin >> searchName;
		searchMember = SearchFamily(T.ancestor, searchName); //�����в�������
		if (searchMember == NULL)							//������ʧ��
		{
			cout << "The member is no exit!" << endl << endl;					//�����ʾ��Ϣ
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
		system("cls");			//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		cout<<"                    Please input the position you want to insert(the memberName)->"<<endl;
		cin>>searchName;							//�����������

		searchMember = SearchFamily(T.ancestor,searchName); //�����в�������

		if(searchMember == NULL)							//������ʧ��
		{
			cout<<"                    The member is no exit!"<<endl<<endl;					//�����ʾ��Ϣ
		}
		else					
		{
			cout<<"                    Search successful!"<<endl<<endl;
			cout<<"   --------------------Member information--------------------"<<endl;
			searchMember->memberInfo.PrintInfo();			//������ҵ��ڵ����ϸ��Ϣ     
			if(searchMember->couple != NULL)				//��������
			{
				cout<<"   --------------------wife's information--------------------"<<endl;	//�����ʾ��Ϣ				
				searchMember->couple->memberInfo.PrintInfo();//������ӵ���Ϣ
			}
			cout<<endl;									   	 //����
		}	
		return 1;
	case 6:
		system("cls");			//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		return 1;
	case 7:
		system("cls");			//����
		if((T.ancestor==NULL))
		{
			cout<<"                --------------------This is a empty tree!!!-----------------------"<<endl;
			return 1;
		}
		SaveFamilyFile(T);
		cout << "Successfully save the members to a file!" << endl;
		return 1;
	case 8:
		system("cls");			//����
		ReadFamily(T);
		cout << "Successfully read the members from a file!" << endl;
		return 1;
	default:
		return 0;
	}
}



/*����
1.�������
2.���������Ϣʱ����ʾ
3.������ʾ
4.ȫӢ
5.д���ļ�
*/

/*
����һ����ʼ�����ȼ�������Ϣ
����������ʼ�������Ա��
����������������Ա
�����ģ�ɾ�������Ա
�����壺��ʾ���м����Ա
����������ʾ��ͥ��Ա��Ϣ�ڵ㣨һ��Ϊ���֣�
�����ˣ����ڵ㱣�����ļ���
�����ߣ����ݹؼ��ֲ��ҳ�Ա
�����ţ��޸ĳ�Ա��Ϣ���������ڣ���ż�����������//����
*/
