// II1.cpp : implementation file
//

#include "stdafx.h"
#include "7777.h"
#include "II1.h"
#include "afxdialogex.h"


// II1 dialog

IMPLEMENT_DYNAMIC(II1, CDialogEx)

II1::II1(CWnd* pParent /*=NULL*/)
	: CDialogEx(II1::IDD, pParent)
{

}

II1::~II1()
{
}

void II1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(II1, CDialogEx)
	ON_BN_CLICKED(IDOK, &II1::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIOx2, &II1::OnBnClickedRadiox2)
	ON_BN_CLICKED(IDC_RADIOx1, &II1::OnBnClickedRadiox1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// II1 message handlers


void II1::OnBnClickedOk()
{
	//MessageBox(_T("jjjjj"));
	// TODO: Add your control notification handler code here
	CString cstring;
	GetDlgItem(IDC_wName)->GetWindowTextW(cstring);  //获取妻子节点的姓名
	if(cstring == "")
		MessageBox(_T("错误提示：请输入妻子姓名"));
	else
	{
		
		wife = (Member)malloc(sizeof(MemberNode));//妻子申请节点空间
		wife->parent=NULL;   //妻子的父指针置空
		int i;
		for(i = 0; i < 10 ;i++)			//将妻子节点的孩子节点置空
			wife->child[i] = NULL;
		wife->couple  = NULL;           //将妻子节点的配偶指针置空

	
		strncpy(wife->memberInfo.name,CW2A(cstring),strlen(wife->memberInfo.name)); //设置妻子节点的姓名  将CString转化为char*

		GetDlgItem(IDC_wNation1)->GetWindowTextW(cstring);  //获取妻子节点的民族
		strncpy(wife->memberInfo.nation,CW2A(cstring),strlen(wife->memberInfo.nation)); //设置妻子节点的名族  将CString转化为char*

		wife->memberInfo.sex='w';					//妻子节点的性别置为女性

		GetDlgItem(IDC_wAge)->GetWindowTextW(cstring);  //获取妻子节点的年龄
		wife->memberInfo.age = _ttoi(cstring);   //设置妻子节点的年龄  将CString转化为int


		GetDlgItem(IDC_wby)->GetWindowTextW(cstring);  //获取妻子节点的出生年
		wife->memberInfo.birthYear= _ttoi(cstring);   //设置妻子节点的出生年  将CString转化为int
		GetDlgItem(IDC_wbm)->GetWindowTextW(cstring);  //获取妻子节点的出生月
		wife->memberInfo.birthMonth = _ttoi(cstring);   //设置妻子节点的出生月  将CString转化为int
		GetDlgItem(IDC_wbd)->GetWindowTextW(cstring);  //获取妻子节点的出生日
		wife->memberInfo.birthDay = _ttoi(cstring);   //设置妻子节点的出生日  将CString转化为int

		

		GetDlgItem(IDC_wEduDegree)->GetWindowTextW(cstring);  //获取妻子节点的学历
		strcpy(wife->memberInfo.eduDegree,CW2A(cstring)); //设置妻子节点的学历  将CString转化为char*

		GetDlgItem(IDC_wPolicy)->GetWindowTextW(cstring);  //获取妻子节点的政治面貌
		strcpy(wife->memberInfo.policy,CW2A(cstring)); //设置妻子节点的政治面貌  将CString转化为char*

		GetDlgItem(IDC_wBirthplace)->GetWindowTextW(cstring);  //获取妻子节点的籍贯
		strcpy(wife->memberInfo.birthPlace,CW2A(cstring)); //设置妻子节点的籍贯  将CString转化为char*

		GetDlgItem(IDC_wNumber)->GetWindowTextW(cstring);  //获取妻子节点的联系方式
		strcpy(wife->memberInfo.number,CW2A(cstring)); //设置妻子节点的联系方式  将CString转化为char*

		GetDlgItem(IDC_wAdress)->GetWindowTextW(cstring);  //获取妻子节点的家庭住址
		strcpy(wife->memberInfo.adress,CW2A(cstring)); //设置妻子节点的家庭住址  将CString转化为char*	

		if(((CButton *)GetDlgItem(IDC_RADIOx2))->GetCheck() == 1)  //单击死亡按钮
		{
			CString s1,s2,s3;
			GetDlgItem(IDC_wdy)->GetWindowTextW(s1);  //获取妻子节点的死亡年
			GetDlgItem(IDC_wdm)->GetWindowTextW(s2);  //获取妻子节点的死亡月
			GetDlgItem(IDC_wdd)->GetWindowTextW(s3);  //获取妻子节点的死亡日
			if(s1 == "" || s2 == "" || s3 == "")
				MessageBox(_T("警告：\r\n请补全死亡日期！"));
			else
			{

				wife->memberInfo.deadYear= _ttoi(s1);   //设置妻子节点的死亡年  将CString转化为int
				wife->memberInfo.deadMonth = _ttoi(s2);   //设置妻子节点的死亡月  将CString转化为int		
				wife->memberInfo.deadDay = _ttoi(s3);   //设置妻子节点的死亡日  将CString转化为int
				flag = 1;								//标志变量设置为1，表示已创建妻子
				CDialogEx::OnOK();
			}
		}
		else
		{
				flag = 1;								//标志变量设置为1，表示已创建妻子
				CDialogEx::OnOK();
		}
		
	}

}


void II1::OnBnClickedRadiox2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_wdy)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_wdm)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_wdd)->EnableWindow(true);  //添加死亡信息
}


void II1::OnBnClickedRadiox1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_wdy)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_wdm)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_wdd)->EnableWindow(false);  //添加死亡信息
}


HBRUSH II1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
