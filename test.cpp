#include "com_Header.h"
#include "TreeDefined.h"
#include "TreeFunction.h"
#include "TreeLoad.h"
int main()
{
	ShowGraph();
	ShowLoad();
	Family T;
	T.ancestor=NULL;
	//InitEmpty(T);
	int x;
	while(1)
	{
		Show();//�˵���ʾ
		cin>>x;
	    Function(T,x);//ʵ�ֹ���
	}
	cout<<"The procedure is over!"<<endl;
	return 0;
}
