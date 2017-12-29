// C3.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "C3.h"
#include "afxdialogex.h"
#include "II1.h"

// CC3 对话框

IMPLEMENT_DYNAMIC(CC3, CDialogEx)

CC3::CC3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC3::IDD, pParent)
{

}

CC3::~CC3()
{
}

void CC3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CC3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CC3::OnBnClickedOk)
	ON_BN_CLICKED(IDC_InsertWifeInfo4, &CC3::OnBnClickedInsertwifeinfo4)
	ON_BN_CLICKED(IDC_RADIOc4, &CC3::OnBnClickedRadioc4)
	ON_BN_CLICKED(IDC_RADIOc3, &CC3::OnBnClickedRadioc3)
	ON_BN_CLICKED(IDC_RADIOc6, &CC3::OnBnClickedRadioc6)
	ON_BN_CLICKED(IDC_RADIOc5, &CC3::OnBnClickedRadioc5)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_InsertWifeInfo5, &CC3::OnBnClickedInsertwifeinfo5)
END_MESSAGE_MAP()


// CC3 消息处理程序

Member CC3::SearchFamily(Member t,char key[])														//函数七：根据关键字查找成员节点（一般为名字）
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
void CC3::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString cstring;
	Member m;									 //定义一个节点临时存储插入信息
	GetDlgItem(IDC_cName)->GetWindowTextW(cstring);							 //获得插入节点的姓名

	if(cstring == "" )											 //未输入成员姓名
		MessageBox(_T("错误提示：\r\n请输入成员的姓名！"));			
	else
	{
		char name[100];
		strcpy(name,CW2A(cstring));
		if(SearchFamily(T.ancestor,name) == NULL)		//若为查找到当前输入节点
		{
			CString s1,s2,s3;
			GetDlgItem(IDC_cdy)->GetWindowTextW(s1);  //获取插入节点的死亡年
			GetDlgItem(IDC_cdm)->GetWindowTextW(s2);  //获取插入节点的死亡月
			GetDlgItem(IDC_cdd)->GetWindowTextW(s3);  //获取插入节点的死亡日
			if(((CButton *)GetDlgItem(IDC_RADIOc4))->GetCheck() == 1 && (s1 == "" || s2 == "" || s3 == ""))//若单击了死亡按钮，且未正常输入死亡年月日
				MessageBox(_T("错误提示：\r\n请补全死亡日期"));
			else
			{
				int i;
				m = (Member)malloc(sizeof(MemberNode));//插入节点申请空间
				m->couple = NULL;									    //插入节点的妻子节点置空
				m->childNum = 0;										//孩子数量为0
				for(i = 0; i < 10 ;i++)									//将插入节点的孩子节点置空
					m->child[i] = NULL;


				strcpy(m->memberInfo.name,CW2A(cstring)); //设置插入节点的姓名  将CString转化为char*

				GetDlgItem(IDC_cNation)->GetWindowTextW(cstring);  //获取插入节点的民族
				if(cstring == "")
					strcpy(m->memberInfo.nation,"汉族");
				else
					strcpy(m->memberInfo.nation,CW2A(cstring)); //设置插入节点的名族  将CString转化为char*

				m->memberInfo.sex='m';  //默认
				if(((CButton *)GetDlgItem(IDC_RADIOc1))->GetCheck() == 1)
				{
					m->memberInfo.sex='m';					//插入节点的性别置为男性
					
				}
				if(((CButton *)GetDlgItem(IDC_RADIOc2))->GetCheck() == 1)
				{
					m->memberInfo.sex='w';					//插入节点的性别置为女性
					
				}

				GetDlgItem(IDC_cAge)->GetWindowTextW(cstring);  //获取插入节点的年龄
				m->memberInfo.age = _ttoi(cstring);   //设置插入节点的年龄  将CString转化为int


				GetDlgItem(IDC_cby)->GetWindowTextW(cstring);  //获取插入节点的出生年
				m->memberInfo.birthYear= _ttoi(cstring);   //设置插入节点的出生年  将CString转化为int
				GetDlgItem(IDC_cbm)->GetWindowTextW(cstring);  //获取插入节点的出生月
				m->memberInfo.birthMonth = _ttoi(cstring);   //设置插入节点的出生月  将CString转化为int
				GetDlgItem(IDC_cbd)->GetWindowTextW(cstring);  //获取插入节点的出生日
				m->memberInfo.birthDay = _ttoi(cstring);   //设置插入节点的出生日  将CString转化为int

				if(((CButton *)GetDlgItem(IDC_RADIOc4))->GetCheck() == 1)  //单击死亡按钮
				{
					m->memberInfo.isAlive = false;				    //设置是否健在
					m->memberInfo.deadYear= _ttoi(s1);			 //设置插入节点的死亡年  将CString转化为int
					m->memberInfo.deadMonth = _ttoi(s2);		 //设置插入节点的死亡月  将CString转化为int
					m->memberInfo.deadDay = _ttoi(s3);			 //设置插入节点的死亡日  将CString转化为int
				}
				else
					m->memberInfo.isAlive = true;				    //设置是否健在

				GetDlgItem(IDC_cEduDegree)->GetWindowTextW(cstring);  //获取插入节点的学历
				strcpy(m->memberInfo.eduDegree,CW2A(cstring)); //设置插入节点的学历  将CString转化为char*

				GetDlgItem(IDC_cPolicy)->GetWindowTextW(cstring);  //获取插入节点的政治面貌
				strcpy(m->memberInfo.policy,CW2A(cstring)); //设置插入节点的政治面貌  将CString转化为char*

				GetDlgItem(IDC_cBirthPlace)->GetWindowTextW(cstring);  //获取插入节点的籍贯
				strcpy(m->memberInfo.birthPlace,CW2A(cstring)); //设置插入节点的籍贯  将CString转化为char*

				GetDlgItem(IDC_cNumber)->GetWindowTextW(cstring);  //获取插入节点的联系方式
				strcpy(m->memberInfo.number,CW2A(cstring)); //设置插入节点的联系方式  将CString转化为char*

				GetDlgItem(IDC_cAdress)->GetWindowTextW(cstring);  //获取插入节点的家庭住址
				strcpy(m->memberInfo.adress,CW2A(cstring)); //设置祖先节点的家庭住址  将CString转化为char*

				GetDlgItem(IDC_cAnotherInfo)->GetWindowTextW(cstring);  //获取插入节点的其它信息
				strcpy(m->memberInfo.anotherInfo,CW2A(cstring)); //设置祖先节点的其它信息  将CString转化为char*

				if(selectx == 1)					//添加到currentNode的子节点
				{
					currentNode->child[currentNode->childNum] = m;
					currentNode->childNum ++;
					m->parent = currentNode;
					m->level = currentNode->level+1;    //层次为父结点层次+1

				}
				if(selectx ==2)					//添加到currentNode的兄弟节点
				{
					currentNode->parent->child[currentNode->parent->childNum] = m;
					currentNode->parent->childNum ++;
					m->parent = currentNode->parent;
					m->level = currentNode->level;    //层次为父结点层次+1
				}
			
				if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1) && (flag == 1) )   //若为男性，存在妻子且输入妻子信息  (男性）
				{

					//将妻子节点连接到祖先节点下
					m->couple = wife;
					wife->couple = m;
					m->memberInfo.isMarrige = true;    //设置婚姻状态
					T.familyInfo.familyNumber++;				//家庭成员数加1
					T.familyInfo.wNumber++;						//女性成员数+1
				}
				if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1) && (flag == 0)) //若为男性，存在妻子且没有输入妻子信息
					MessageBox(_T("警告：未输入妻子信息！"));



				if(m->memberInfo.sex == 'w' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1))    //若为女性，存在配偶
				{
					m->memberInfo.isMarrige = true;																							//设置婚姻状态
				}

				//统计成员数量
				if(m->memberInfo.sex == 'm')
					T.familyInfo.mNumber++;						//女性成员数+1
				else
					T.familyInfo.wNumber++;						//女性成员数+1
				T.familyInfo.familyNumber++;					//家庭总人数+1

				child = m;
				//显示当前创建时间 用全局变量显示
				CDialogEx::OnOK();
			}
		}
		else
			MessageBox(_T("家族中已存在此成员~"));
	}
		
}


void CC3::OnBnClickedInsertwifeinfo4()
{
	II1 *dlg=new II1();//非模态
    dlg->Create(IDD_Insert,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);     

	// TODO: Add your control notification handler code here
}


void CC3::OnBnClickedRadioc4()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_cdy)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_cdm)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_cdd)->EnableWindow(true);  //添加死亡信息

}


void CC3::OnBnClickedRadioc3()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_cdy)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_cdm)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_cdd)->EnableWindow(false);  //添加死亡信息
}


void CC3::OnBnClickedRadioc6()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);   //设置妻子信息
}


void CC3::OnBnClickedRadioc5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(currentNode->memberInfo.sex == 'm')	  //若为男性
	{
		GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(true);   //设置妻子信息
	}
}


HBRUSH CC3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor); 
	 // TODO:  在此更改 DC 的任何属性 
	 if(nCtlColor==CTLCOLOR_BTN)          //更改按钮颜色 
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(121,121,0));    
	  HBRUSH b=CreateSolidBrush(RGB(121,121,0)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_SCROLLBAR)  // 滚动条
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(233,233,220)); 
	  HBRUSH b=CreateSolidBrush(RGB(233,233,220)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_EDIT)   //更改编辑框 
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(165,254,236)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,255,255)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_STATIC)  //更改静态文本 
	 { 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(255,240,240)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,255,255)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_DLG)   //更改对话框背景色 
	 { 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(166,254,1)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,240,240)); 
	  return b; 
	 } 
	 // TODO:  如果默认的不是所需画笔，则返回另一个画笔 
	 return hbr; 
}


void CC3::OnBnClickedInsertwifeinfo5()


{
	// 打开添加妻子对话框
	II1 *dlg=new II1();//非模态
    dlg->Create(IDD_Insert,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);     
}
