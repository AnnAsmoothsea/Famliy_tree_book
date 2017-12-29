// DD4.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "DD4.h"
#include "C1.h"
#include "afxdialogex.h"

// DD4 对话框

IMPLEMENT_DYNAMIC(DD4, CDialogEx)

DD4::DD4(CWnd* pParent /*=NULL*/)
	: CDialogEx(DD4::IDD, pParent)
{

}

DD4::~DD4()
{
}


void DD4::DoDataExchange(CDataExchange* pDX)
{
	
}


BEGIN_MESSAGE_MAP(DD4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DD4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CorrectFamilyInfo, &DD4::OnBnClickedCorrectfamilyinfo)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// DD4 消息处理程序


void DD4::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


	CC1 *dlg=new CC1();//非模态
    dlg->Create(IDD_CorrectFamilInfo,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);         

}


void DD4::OnBnClickedCorrectfamilyinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")							//若有祖先
	{
		CString str;
		CC1 *dlg=new CC1();//非模态
		if(dlg->DoModal()==IDOK) 
		{ 
			//显示当前修改时间 用全局变量显示
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
			puts( tmp ); 
			string += "修改家族信息 ";
			string += tmp;
			string += "\r\n";  //换行
			
			if(reactFlag == 0)
			{
				ss = "请输入查找信息";
				reactFlag = 1;
			}
			else
			{
				ss = "请输入查找信息 ";
				reactFlag = 0;
			}

			specailflag = 5;   //设置标志变量
			GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框  
			GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //家族信息框显示成功
			MessageBox(_T("已修改家族信息！"));
		}  

	}
	else
		MessageBox(_T("请先创建族谱!"));
}


HBRUSH DD4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
