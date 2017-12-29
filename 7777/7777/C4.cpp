// C4.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "C4.h"
#include "afxdialogex.h"
#include "II1.h"

// CC4 对话框

IMPLEMENT_DYNAMIC(CC4, CDialogEx)

CC4::CC4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC4::IDD, pParent)
{

}

CC4::~CC4()
{
}

void CC4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CC4, CDialogEx)
	ON_BN_CLICKED(IDC_InsertWifeInfo5, &CC4::OnBnClickedInsertwifeinfo5)
	ON_BN_CLICKED(IDOK, &CC4::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO5, &CC4::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CC4::OnBnClickedRadio6)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RADIO4, &CC4::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO3, &CC4::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CC4 消息处理程序


void CC4::OnBnClickedInsertwifeinfo5()
{
	//打开修改成员信息对话框
	II1 *dlg=new II1();//非模态
    dlg->Create(IDD_Insert,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);     

}







void  CC4::ShowMemberInfo()  //显示成员个人信息
{
	CString str;
	str = currentNode->memberInfo.name;					//将char[ ]转化为CString
	GetDlgItem(IDC_mName2)->SetWindowTextW(str);      //显示成员姓名



	str = currentNode->memberInfo.eduDegree;					//将char[ ]转化为CString
	GetDlgItem(IDC_mEduDegree2)->SetWindowTextW(str);			//显示成员学历

	str = currentNode->memberInfo.policy;					//将char[ ]转化为CString
	GetDlgItem(IDC_mPolicy2)->SetWindowTextW(str);			//显示成员政治面貌

	str = currentNode->memberInfo.birthPlace;					//将char[ ]转化为CString
	GetDlgItem(IDC_mBirthPlace2)->SetWindowTextW(str);			//显示成员籍贯

	str = currentNode->memberInfo.number;					//将char[ ]转化为CString
	GetDlgItem(IDC_mNumber2)->SetWindowTextW(str);			//显示成员联系方式

	str = currentNode->memberInfo.adress;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAdress2)->SetWindowTextW(str);			//显示成员家庭住址

	str = currentNode->memberInfo.anotherInfo;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAnotherInfo2)->SetWindowTextW(str);			//显示成员其它描述信息

}











void CC4::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstring;

	GetDlgItem(IDC_mName2)->GetWindowTextW(cstring);							 //获得插入节点的姓名
	strcpy(currentNode->memberInfo.name,CW2A(cstring)); //设置修改节点的姓名  将CString转化为char*

	GetDlgItem(IDC_mEduDegree2)->GetWindowTextW(cstring);  //获取修改节点的学历
	strcpy(currentNode->memberInfo.eduDegree,CW2A(cstring)); //设置插入节点的学历  将CString转化为char*

	GetDlgItem(IDC_mPolicy2)->GetWindowTextW(cstring);  //获取修改节点的政治面貌
	strcpy(currentNode->memberInfo.policy,CW2A(cstring)); //设置修改节点的政治面貌  将CString转化为char*

	GetDlgItem(IDC_mBirthPlace2)->GetWindowTextW(cstring);  //获取修改节点的籍贯
	strcpy(currentNode->memberInfo.birthPlace,CW2A(cstring)); //设置修改节点的籍贯  将CString转化为char*

	GetDlgItem(IDC_mNumber2)->GetWindowTextW(cstring);  //获取修改节点的联系方式
	strcpy(currentNode->memberInfo.number,CW2A(cstring)); //设置修改节点的联系方式  将CString转化为char*

	GetDlgItem(IDC_mAdress2)->GetWindowTextW(cstring);  //获取修改节点的家庭住址
	strcpy(currentNode->memberInfo.adress,CW2A(cstring)); //设置修改节点的家庭住址  将CString转化为char*

	GetDlgItem(IDC_mAnotherInfo2)->GetWindowTextW(cstring);  //获取修改节点的其它信息
	strcpy(currentNode->memberInfo.anotherInfo,CW2A(cstring)); //设置修改节点的其它信息  将CString转化为char*


	if(((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck() == 1 && currentNode->memberInfo.isAlive == true)  //单击死亡按钮且成员原状态为健在，更新死亡时间
	{
		CString s1,s2,s3;
		GetDlgItem(IDC_mdy111)->GetWindowTextW(s1);  //获取修改节点的死亡年
		GetDlgItem(IDC_mdm111)->GetWindowTextW(s2);  //获取修改节点的死亡月
		GetDlgItem(IDC_mdd111)->GetWindowTextW(s3);  //获取修改节点的死亡日
		
		if(s1 == "" || s2 == "" || s3 == "")
			MessageBox(_T("警告：\r\n请补全死亡日期"));
		else
		{
			currentNode->memberInfo.isAlive = false;				    //设置是否健在
			currentNode->memberInfo.deadYear= _ttoi(cstring);			 //设置插入节点的死亡年  将CString转化为int	
			currentNode->memberInfo.deadMonth = _ttoi(cstring);		 //设置插入节点的死亡月  将CString转化为int	
			currentNode->memberInfo.deadDay = _ttoi(cstring);			 //设置插入节点的死亡日  将CString转化为int

			if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 1)           //若单击了配偶按钮且输入了配偶信息
			{	//将妻子节点连接到当前节点下
				currentNode->couple = wife;
				wife->couple = currentNode;
				currentNode->memberInfo.isMarrige = true;    //设置婚姻状态
				T.familyInfo.familyNumber++;				//家庭成员数加1
				T.familyInfo.wNumber++;						//女性成员数+1
				MessageBox(_T("已添加妻子信息"));
			}
			if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 0)			//若单击了配偶按钮且未输入配偶信息
				MessageBox(_T("警告:\r\n未输入妻子信息"));									//输出警告提示
			flag = 0;
			CDialogEx::OnOK();
		}
	}
	else																				//若未单击死亡按钮
	{	
		if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 1)           //若单击了配偶按钮且输入了配偶信息
		{	//将妻子节点连接到当前节点下
			currentNode->couple = wife;
			wife->couple = currentNode;
			currentNode->memberInfo.isMarrige = true;    //设置婚姻状态
			T.familyInfo.familyNumber++;				//家庭成员数加1
			T.familyInfo.wNumber++;						//女性成员数+1
			MessageBox(_T("已添加妻子信息"));
		}
		if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 0)			//若单击了配偶按钮且未输入配偶信息
			MessageBox(_T("警告:\r\n未输入妻子信息"));	
		flag = 0;
		CDialogEx::OnOK();
	}
	
}


void CC4::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(true);  //添加妻子信息
}


void CC4::OnBnClickedRadio6()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);  //添加妻子信息
	
}


void CC4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	//错误示范

	CString str;
	str = currentNode->memberInfo.name;					//将char[ ]转化为CString
	GetDlgItem(IDC_mName2)->SetWindowTextW(str);      //显示成员姓名

	if(currentNode->memberInfo.isAlive == 1)     //若成员健在
		((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(true);
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(true);
		GetDlgItem(IDC_RADIO3)->EnableWindow();					//设置健在按钮不可点击
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//将死亡年转化为CSring
		GetDlgItem(IDC_mdy111)->SetWindowTextW(str);		//显成员死亡年
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//将死亡月转化为CSring
		GetDlgItem(IDC_mdm111)->SetWindowTextW(str);		//显成员死亡月
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//将死亡日转化为CSring
		GetDlgItem(IDC_mdd111)->SetWindowTextW(str);		//显成员死亡日
	}

	if(currentNode->memberInfo.isMarrige == true)
	{
		((CButton *)GetDlgItem(IDC_RADIO5))->SetCheck(true); //设置已婚配
		GetDlgItem(IDC_RADIO6)->EnableWindow(false);		 //设置死亡按钮不可点击
		GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);		 //设置添加妻子按钮不可点击
	}
	else
		((CButton *)GetDlgItem(IDC_RADIO6))->SetCheck(true); //设置未分配
		
	str = currentNode->memberInfo.eduDegree;					//将char[ ]转化为CString
	GetDlgItem(IDC_mEduDegree2)->SetWindowTextW(str);			//显示成员学历

	str = currentNode->memberInfo.policy;					//将char[ ]转化为CString
	GetDlgItem(IDC_mPolicy2)->SetWindowTextW(str);			//显示成员政治面貌

	str = currentNode->memberInfo.birthPlace;					//将char[ ]转化为CString
	GetDlgItem(IDC_mBirthPlace2)->SetWindowTextW(str);			//显示成员籍贯

	str = currentNode->memberInfo.number;					//将char[ ]转化为CString
	GetDlgItem(IDC_mNumber2)->SetWindowTextW(str);			//显示成员联系方式

	str = currentNode->memberInfo.adress;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAdress2)->SetWindowTextW(str);			//显示成员家庭住址

	str = currentNode->memberInfo.anotherInfo;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAnotherInfo2)->SetWindowTextW(str);			//显示成员其它描述信息
    //错误示范

}


HBRUSH CC4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CC4::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_mdy111)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_mdm111)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_mdd111)->EnableWindow(true);  //添加死亡信息
	/*((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);*/
}


void CC4::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_mdy111)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_mdm111)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_mdd111)->EnableWindow(false);  //添加死亡信息
}
