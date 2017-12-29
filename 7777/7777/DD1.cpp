// DD1.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "DD1.h"
#include "C3.h"
#include "afxdialogex.h"


// DD1 对话框

IMPLEMENT_DYNAMIC(DD1, CDialogEx)

DD1::DD1(CWnd* pParent /*=NULL*/)
	: CDialogEx(DD1::IDD, pParent)
{

}

DD1::~DD1()
{
}

void DD1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DD1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &DD1::OnBnClickedButton3)
//	ON_BN_CLICKED(IDC_BUTTON14, &DD1::OnBnClickedButton14)
ON_BN_CLICKED(IDC_BUTTON4, &DD1::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &DD1::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON1, &DD1::OnBnClickedButton1)
//ON_BN_CLICKED(IDC_BUTTON12, &DD1::OnBnClickedButton12)
//ON_BN_CLICKED(IDC_RADIO3, &DD1::OnBnClickedRadio3)
//ON_BN_CLICKED(IDC_BUTTON6, &DD1::OnBnClickedButton6)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_RADIOm1, &DD1::OnBnClickedRadiom1)
ON_BN_CLICKED(IDC_RADIOm2, &DD1::OnBnClickedRadiom2)
ON_BN_CLICKED(IDC_RADIOm5, &DD1::OnBnClickedRadiom5)
END_MESSAGE_MAP()


// DD1 消息处理程序



void  DD1::ShowMemberInfo()  //显示成员个人信息
{
	CString str;
	str = currentNode->memberInfo.name;					//将char[ ]转化为CString
	GetDlgItem(IDC_mName)->SetWindowTextW(str);      //显示成员姓名


	str.Format(_T("%d"),  currentNode->memberInfo.age);	//将年龄转化为CSring
    GetDlgItem(IDC_mAge)->SetWindowTextW(str);		//显成员年龄

	str = currentNode->memberInfo.nation;					//将char[ ]转化为CString
	GetDlgItem(IDC_mNation)->SetWindowTextW(str);      //显示成员民族

	if(currentNode->memberInfo.sex == 'w')     //若成员为男性
	{
		((CButton *)GetDlgItem(IDC_RADIOm3))->SetCheck(true);   //设置单选按钮
	}
	else											//若成员为女性		
	{
		((CButton *)GetDlgItem(IDC_RADIOm4))->SetCheck(true);   //设置单选按钮
	}

	str.Format(_T("%d"),  currentNode->memberInfo.birthYear);	//将出生年转化为CSring
    GetDlgItem(IDC_mby)->SetWindowTextW(str);		//显成员出生年
	str.Format(_T("%d"),  currentNode->memberInfo.birthMonth);	//将出生月转化为CSring
    GetDlgItem(IDC_mbm)->SetWindowTextW(str);		//显成员出生月
	str.Format(_T("%d"),  currentNode->memberInfo.birthDay);	//将叔生日转化为CSring
    GetDlgItem(IDC_mbd)->SetWindowTextW(str);		//显成员出生日

	if(currentNode->memberInfo.isAlive == true)     //若成员健在
	{
		((CButton *)GetDlgItem(IDC_RADIOm1))->SetCheck(true);   //设置单选按钮
	}
	else											//若成员未健在			
	{
		((CButton *)GetDlgItem(IDC_RADIOm2))->SetCheck(true);   //设置单选按钮
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//将死亡年转化为CSring
		GetDlgItem(IDC_mdy)->SetWindowTextW(str);		//显成员死亡年
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//将死亡月转化为CSring
		GetDlgItem(IDC_mdm)->SetWindowTextW(str);		//显成员死亡月
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//将死亡日转化为CSring
		GetDlgItem(IDC_mdd)->SetWindowTextW(str);		//显成员死亡日
	}
	if(currentNode->level != 0)                             //如果不为根节点
	{
		str = currentNode->parent->memberInfo.name;					//将char[ ]转化为CString
		GetDlgItem(IDC_MFatherName)->SetWindowTextW(str);      //显示成员父亲的姓名
		if(currentNode->parent->couple != NULL)
		{
			str = currentNode->parent->couple->memberInfo.name;					//将char[ ]转化为CString
			GetDlgItem(IDC_MMotherName)->SetWindowTextW(str);      //显示成员母亲的姓名
		}
	}

	str = currentNode->memberInfo.eduDegree;					//将char[ ]转化为CString
	GetDlgItem(IDC_mEduDegree)->SetWindowTextW(str);			//显示成员学历

	str = currentNode->memberInfo.policy;					//将char[ ]转化为CString
	GetDlgItem(IDC_mPolicy)->SetWindowTextW(str);			//显示成员政治面貌

	str = currentNode->memberInfo.birthPlace;					//将char[ ]转化为CString
	GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(str);			//显示成员籍贯

	str = currentNode->memberInfo.number;					//将char[ ]转化为CString
	GetDlgItem(IDC_mNumber)->SetWindowTextW(str);			//显示成员联系方式

	str = currentNode->memberInfo.adress;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAdress)->SetWindowTextW(str);			//显示成员家庭住址

	str = currentNode->memberInfo.anotherInfo;					//将char[ ]转化为CString
	GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(str);			//显示成员其它描述信息

}



void DD1::TranStrToArray(char a[],CString cstring)
{
	int i;
	for(i = 0 ;i<cstring.GetLength();i++)
		a[i] = cstring[i];
}

void DD1::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")
	{
		if(currentNode == NULL)
		{
			MessageBox(_T("请选择当前节点"));
		}
		else
		{
			CString str;
			CC4 *c4 = new CC4();

			strncpy(historyName,currentNode->memberInfo.name,strlen(currentNode->memberInfo.name));							//记录修改之前的历史名字
			if(c4->DoModal() == IDOK)
			{
				//显示当前修改时间 用全局变量显示
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
				puts( tmp ); 
				string += "修改成员";
				string += currentNode->memberInfo.name;
				string += "信息 ";
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

				specailflag = 6;   //设置标志变量
				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框  
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //成员信息框显示成功
				MessageBox(_T("已修改成员信息！"));
			}
		}
	}
	else
		MessageBox(_T("请先创建族谱!"));
}


void DD1::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
}


void DD1::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")
	{
		if(currentNode->level != 0) //如果不为根节点
		{
			selectx = 2;   //添加子女,兄弟
			CC3 dlg;
			if (IDOK==dlg.DoModal())
			{
				specailflag = 1;  ///定义标记变量
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
				puts( tmp ); 
				string += "加入成员:";
			
				string += child->memberInfo.name;
				string += " ";
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

				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框显示成功
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //家族信息框显示成功

			}
			UpdateData(FALSE); 
		}
		else
			MessageBox(_T("无法给根节点添加兄弟节点"));
	      
	}
	else
		MessageBox(_T("请先创建族谱!"));
}


void DD1::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")
	{
		if(currentNode->memberInfo.sex == 'w')
			MessageBox(_T("女性成员无法加入孩子成员"));
		else
		{
			selectx = 1;   //添加子女
			CC3 dlg;
			if (IDOK==dlg.DoModal())
			{
				specailflag = 2;  ///定义标记变量
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
				puts( tmp ); 
				string += "加入成员:";
			
				string += child->memberInfo.name;
				string += " ";
				string += tmp;
				string += "\r\n";  //换行
				ss+=" ";
				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框显示成功
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //家族信息框显示成功

			}
			UpdateData(FALSE); 
		}
	}
	else
		MessageBox(_T("请先创建族谱!"));
}

Member DD1::SearchFamily(Member t,char key[])														//函数七：根据关键字查找成员节点（一般为名字）
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


void DD1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")   //若未创建族谱
	{
		if(currentNode == NULL)																//如果当前节点为空
			MessageBox(_T("请先选择某节点！"));
		else
		{
			if(currentNode->level == 0)														  //若为祖先节点
			MessageBox(_T("无法删除祖先节点！"));
			else																			  //若不为祖先节点
			{
				if(currentNode != NULL && currentNode->childNum != 0)								//若节点非空且含有子节点，输出提示信息
				{
					if(MessageBox(_T("该成员含有子女，是否确认删除？"),_T("HelloMsg"), MB_YESNO|MB_ICONEXCLAMATION)== IDYES )
					{
						//显示当前修改时间 用全局变量显示
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
						puts( tmp ); 
						string += "将成员";
						string += currentNode->memberInfo.name;
						string += "移族 ";
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

						specailflag = 4;   //设置标志变量
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框  
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //成员信息框显示成功
					}
				}
				if(currentNode != NULL && currentNode->childNum == 0)								//若节点非空且没有子节点
				{
						//显示当前修改时间 用全局变量显示
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
						puts( tmp ); 
						string += "将成员";
						string += currentNode->memberInfo.name;
						string += "移族 ";
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

						specailflag = 4;   //设置标志变量
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框  
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //成员信息框显示成功
				}
		}
		}

	}
	else
		MessageBox(_T("请先创建族谱!"));
	

}





HBRUSH DD1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void DD1::OnBnClickedRadiom1()
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_mdy)->EnableWindow(false);  //添加死亡信息
	//GetDlgItem(IDC_mdm)->EnableWindow(false);  //添加死亡信息
	//GetDlgItem(IDC_mdd)->EnableWindow(false);  //添加死亡信息
}


void DD1::OnBnClickedRadiom2()
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_mdy)->EnableWindow(true);  //添加死亡信息
	//GetDlgItem(IDC_mdm)->EnableWindow(true);  //添加死亡信息
	//GetDlgItem(IDC_mdd)->EnableWindow(true);  //添加死亡信息
}


void DD1::OnBnClickedRadiom5()
{
	// TODO: 在此添加控件通知处理程序代码
}
