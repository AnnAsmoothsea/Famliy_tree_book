#include "com_Header.h"
#include "TreeDefined.h"
#include "TreeFunction.h"
int main()
{
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
