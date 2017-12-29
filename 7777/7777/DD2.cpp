// DD2.cpp : 实现文件
//

#include "stdafx.h"
#include "DD2.h"
#include "afxdialogex.h"
#include "com_Header.h"
#include "MemberInfo.h"
#include "FamilyInfo.h"
#include "7777Dlg.h"
#include "II1.h"

// DD2 对话框

IMPLEMENT_DYNAMIC(DD2, CDialogEx)

DD2::DD2(CWnd* pParent /*=NULL*/)
	: CDialogEx(DD2::IDD, pParent)
{

}

DD2::~DD2()
{
}

void DD2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_s1);
}


BEGIN_MESSAGE_MAP(DD2, CDialogEx)
	ON_BN_CLICKED(IDC_CreatFamily, &DD2::OnBnClickedCreatfamily)
	ON_BN_CLICKED(IDC_RADIO1, &DD2::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DD2::OnBnClickedRadio2)
//	ON_NOTIFY(BCN_DROPDOWN, IDC_RADIO3, &DD2::OnBnDropDownRadio3)
ON_BN_CLICKED(IDC_RADIO3, &DD2::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_RADIO4, &DD2::OnBnClickedRadio4)
//ON_BN_CLICKED(IDC_InsertWifeInfo1, &DD2::OnBnClickedInsertwifeinfo1)
ON_BN_CLICKED(IDC_InsertWifeInfo1, &DD2::OnBnClickedInsertwifeinfo1)
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// DD2 消息处理程序

void DD2::OnBnClickedCreatfamily()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(string);
	CString cstring;
	GetDlgItem(IDC_fName)->GetWindowTextW(cstring);  //获取祖先节点的姓名
	if(cstring == "") 
		MessageBox(_T("请输入祖先姓名!"));
	else
	{
		CString s1,s2,s3;
		GetDlgItem(IDC_dy)->GetWindowTextW(s1);  //获取祖先节点的死亡年
		GetDlgItem(IDC_dm)->GetWindowTextW(s2);  //获取祖先节点的死亡月
		GetDlgItem(IDC_dd)->GetWindowTextW(s3);  //获取祖先节点的死亡日
		if(((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == 1  && (s1 == "" || s2 == "" || s3 == ""))  //单击死亡按钮 且未补全死亡日期
			MessageBox(_T("错误提示：\r\n请补全死亡日期"));
		else		
		{
			int i;
			T.ancestor = (Member)malloc(sizeof(MemberNode));//祖先申请节点空间
			T.ancestor->parent=NULL;   //祖先节点的父指针置空
			T.ancestor->couple = NULL; //祖先节点的妻子节点置空
			for(i = 0; i < 10 ;i++)			//将祖先节点的孩子节点置空
				T.ancestor->child[i] = NULL;
			T.familyInfo.familyNumber++;				//家庭成员数加1
			T.familyInfo.mNumber++;						//男性成员数+1
			T.ancestor->level = 0;						//根节点层次为0
			T.ancestor->childNum = 0;					//孩子数量为0
			

			strcpy(T.ancestor->memberInfo.name,CW2A(cstring)); //设置祖先节点的姓名  将CString转化为char*
			ancestorName = cstring;    //获取祖先姓名

			GetDlgItem(IDC_fNation1)->GetWindowTextW(cstring);  //获取祖先节点的民族
			if(cstring == "")
				strcpy(T.ancestor->memberInfo.nation,"汉族");
			else
				strcpy(T.ancestor->memberInfo.nation,CW2A(cstring)); //设置祖先节点的名族  将CString转化为char*

			T.ancestor->memberInfo.sex='m';					//祖先节点的性别置为男性

			GetDlgItem(IDC_fAge)->GetWindowTextW(cstring);  //获取祖先节点的年龄
			T.ancestor->memberInfo.age = _ttoi(cstring);   //设置祖先节点的年龄  将CString转化为int


			GetDlgItem(IDC_by)->GetWindowTextW(cstring);							   //获取祖先节点的出生年
			T.ancestor->memberInfo.birthYear= _ttoi(cstring);						   //设置祖先节点的出生年  将CString转化为int
			GetDlgItem(IDC_bm)->GetWindowTextW(cstring);							   //获取祖先节点的出生月
			T.ancestor->memberInfo.birthMonth = _ttoi(cstring);						   //设置祖先节点的出生月  将CString转化为int
			GetDlgItem(IDC_bd)->GetWindowTextW(cstring);                               //获取祖先节点的出生日
			T.ancestor->memberInfo.birthDay = _ttoi(cstring);						   //设置祖先节点的出生日  将CString转化为int

			if(((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == 1)					//若点击了死亡按钮
			{
				T.ancestor->memberInfo.isAlive = false;								    //设置是否健在
				T.ancestor->memberInfo.deadYear= _ttoi(s1);								//设置祖先节点的死亡年  将CString转化为int		
				T.ancestor->memberInfo.deadMonth = _ttoi(s2);						    //设置祖先节点的死亡月  将CString转化为int	
				T.ancestor->memberInfo.deadDay = _ttoi(s3);								//设置祖先节点的死亡日  将CString转化为int
			}
			else
				T.ancestor->memberInfo.isAlive = true;								    //设置是否健在


			GetDlgItem(IDC_fEduDegree)->GetWindowTextW(cstring);  //获取祖先节点的学历
			strcpy(T.ancestor->memberInfo.eduDegree,CW2A(cstring)); //设置祖先节点的学历  将CString转化为char*

			GetDlgItem(IDC_fPolicy)->GetWindowTextW(cstring);  //获取祖先节点的政治面貌
			strcpy(T.ancestor->memberInfo.policy,CW2A(cstring)); //设置祖先节点的政治面貌  将CString转化为char*

			GetDlgItem(IDC_fBirthplace)->GetWindowTextW(cstring);  //获取祖先节点的籍贯
			strcpy(T.ancestor->memberInfo.birthPlace,CW2A(cstring)); //设置祖先节点的籍贯  将CString转化为char*

			GetDlgItem(IDC_fNumber)->GetWindowTextW(cstring);  //获取祖先节点的联系方式
			strcpy(T.ancestor->memberInfo.number,CW2A(cstring)); //设置祖先节点的联系方式  将CString转化为char*

			GetDlgItem(IDC_fAdress)->GetWindowTextW(cstring);  //获取祖先节点的家庭住址
			strcpy(T.ancestor->memberInfo.adress,CW2A(cstring)); //设置祖先节点的家庭住址  将CString转化为char*

			GetDlgItem(IDC_fAnotherInfo)->GetWindowTextW(cstring);  //获取祖先节点的其它信息
			strcpy(T.ancestor->memberInfo.anotherInfo,CW2A(cstring)); //设置祖先节点的其它信息  将CString转化为char*

			GetDlgItem(IDC_fInfo1)->GetWindowTextW(cstring);  //获取家庭其它信息
			strcpy(T.familyInfo.anotherInfo,CW2A(cstring)); //设置祖先节点的其它信息  将CString转化为char*
	
		
			/***************基本信息录入完成**********************/
		
			if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck() == 1&& flag == 1 )   //若存在妻子且输入妻子信息
			{

				//将妻子节点连接到祖先节点下
				T.ancestor->couple = wife;
				wife->couple = T.ancestor;
				T.ancestor->memberInfo.isMarrige = true;    //设置婚姻状态
				T.familyInfo.familyNumber++;				//家庭成员数加1
				T.familyInfo.wNumber++;						//女性成员数+1

			}
			if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck() == 1&& flag == 0 ) //若存在妻子且没有输入妻子信息
				MessageBox(_T("警告：未输入妻子信息！"));

			flag = 0; //则将标志变量置为0，以便下一次输入妻子信息
			//显示当前创建时间 用全局变量显示
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
			puts( tmp ); 
			string = "家谱创建于:";
			string += tmp;
			string += "\r\n";  //换行
			x = 1;
			currentNode = T.ancestor;      //修改currentNode
			ss = "输入查找信息";
			GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);    //查找框成功
			GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //家族信息框显示成功

			GetDlgItem(IDC_fName)->SetWindowTextW(_T(""));				//基本信息置空
			GetDlgItem(IDC_fNation1)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fAge)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_by)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_bm)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_bd)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_dy)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_dm)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_dd)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fEduDegree)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fPolicy)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fBirthplace)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fNumber)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fAdress)->SetWindowTextW(_T(""));  
			GetDlgItem(IDC_fAnotherInfo)->SetWindowTextW(_T("")); 
			GetDlgItem(IDC_fInfo1)->SetWindowTextW(_T("")); 
			((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(false);		//设置按钮状态
			((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(false);
			((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);
			((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(false);

		}		

	}

}


void DD2::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_dy)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_dm)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_dd)->EnableWindow(false);  //添加死亡信息
	
}


void DD2::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_dy)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_dm)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_dd)->EnableWindow(true);  //添加死亡信息
	
}


void DD2::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo1)->EnableWindow(true);  //添加妻子信息
}


void DD2::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo1)->EnableWindow(false);  //添加妻子信息
}



void DD2::OnBnClickedInsertwifeinfo1()
{
	// 打开新建配偶对话框
	II1 *dlg=new II1();//非模态
    dlg->Create(IDD_Insert,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);     
	
}


HBRUSH DD2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
