// C1.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "C1.h"
#include "afxdialogex.h"


// CC1 对话框

IMPLEMENT_DYNAMIC(CC1, CDialogEx)

CC1::CC1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC1::IDD, pParent)
{

}

CC1::~CC1()
{
}

void CC1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CC1, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CC1::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CC1::OnBnClickedOk)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CC1 消息处理程序


void CC1::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CC1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString str;

	GetDlgItem(IDC_EDITf1)->GetWindowTextW(str);		 //获取家族病史
	strcpy(T.familyInfo.historyDesease,CW2A(str));		 //修改家族遗传病史  将CString转化为char*

	GetDlgItem(IDC_EDITf2)->GetWindowTextW(str);		 //获取家族其它信息
	strcpy(T.familyInfo.anotherInfo,CW2A(str));			 //修改家族其它信息  将CString转化为char*
	

	CDialogEx::OnOK();
}


void CC1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString str;
	str = T.familyInfo.historyDesease;					//获取家庭疾病史
	GetDlgItem(IDC_EDITf1)->SetWindowTextW(str);   //显示家族病史

	str = T.familyInfo.anotherInfo;					    //获取家庭其它信息
	GetDlgItem(IDC_EDITf2)->SetWindowTextW(str);   //显示家族其它信息
}


HBRUSH CC1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
