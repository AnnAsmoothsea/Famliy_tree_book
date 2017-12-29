// DD3.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "DD3.h"
#include "afxdialogex.h"
#include "II1.h"

// DD3 对话框

IMPLEMENT_DYNAMIC(DD3, CDialogEx)

DD3::DD3(CWnd* pParent /*=NULL*/)
	: CDialogEx(DD3::IDD, pParent)
{

}

DD3::~DD3()
{
}
void DD3::TranStrToArray(char a[],CString cstring)
{
	int i;
	for(i = 0 ;i<cstring.GetLength();i++)
		a[i] = cstring[i];
}

void DD3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DD3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DD3::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT6, &DD3::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_InsertWifeInfo, &DD3::OnBnClickedInsertwifeinfo)
	ON_BN_CLICKED(IDC_RADIO5, &DD3::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &DD3::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON2, &DD3::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_RADIO444, &DD3::OnBnClickedRadio444)
//	ON_BN_CLICKED(IDC_RADIO333, &DD3::OnBnClickedRadio333)
	ON_BN_CLICKED(IDC_RADIO555, &DD3::OnBnClickedRadio555)
	ON_BN_CLICKED(IDC_RADIO666, &DD3::OnBnClickedRadio666)
	ON_BN_CLICKED(IDC_RADIO333, &DD3::OnBnClickedRadio333)
	ON_BN_CLICKED(IDC_RADIO444, &DD3::OnBnClickedRadio444)
	ON_BN_CLICKED(IDC_BUTTON3, &DD3::OnBnClickedButton3)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// DD3 消息处理程序


void DD3::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void DD3::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DD3::OnBnClickedInsertwifeinfo()
{
	II1 *dlg=new II1();//非模态
    dlg->Create(IDD_Insert,this);    //第一个参数是对话框ID号
    dlg->ShowWindow(SW_SHOW);     
	// TODO: 在此添加控件通知处理程序代码
}




void DD3::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(true);
}


void DD3::OnBnClickedRadio6()
{
	GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(false);
	// TODO: Add your control notification handler code here
}



Member DD3::SearchFamily(Member t,char key[])														//函数七：根据关键字查找成员节点（一般为名字）
{
	Member m = NULL; //查找节点初始化为空
	Member mm = NULL;//辅助节点设计
	if(strncmp(t->memberInfo.name,key,strlen(key)) == 0 && t->memberInfo.sex == 'm')  //若当前节点姓名等于关键字且为男性节点
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

void DD3::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	
}



void DD3::OnBnClickedRadio555()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1)	  //若为男性
	{
		GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(true);   //设置妻子信息
	}
}


void DD3::OnBnClickedRadio666()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(false);   //设置妻子信息

}


void DD3::OnBnClickedRadio333()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_mdy11)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_mdm11)->EnableWindow(false);  //添加死亡信息
	GetDlgItem(IDC_mdd11)->EnableWindow(false);  //添加死亡信息
}


void DD3::OnBnClickedRadio444()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_mdy11)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_mdm11)->EnableWindow(true);  //添加死亡信息
	GetDlgItem(IDC_mdd11)->EnableWindow(true);  //添加死亡信息
}


void DD3::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(ancestorName != "")
	{
		CString cstring,cstring2;
		char name[100];
		GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);							 //获得插入节点的姓名
		strcpy(name,CW2A(cstring));													//CString转化为char数组
		if(SearchFamily(T.ancestor,name) == NULL)									//判断家族中是否存在此成员,若不存在则创建
		{
			Member m;																 //定义一个节点临时存储插入信息
			GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);							 //获得插入节点的姓名

			GetDlgItem(IDC_mFather1)->GetWindowTextW(cstring2);							 //获取插入节点父节点的姓名
			if(cstring == "" && cstring2 != "")											 //未输入成员姓名
				MessageBox(_T("错误提示：\r\n请输入插入成员的姓名！"));			
			else if(cstring != "" && cstring2 == "")									 //未输入父亲姓名
				MessageBox(_T("错误提示：\r\n请输入插入成员父亲的姓名！"));
			else if(cstring == "" && cstring2 == "")
				MessageBox(_T("错误提示：\r\n请输入该成员姓名及该成员父亲的姓名"));//未输入成员姓名和父亲姓名
			else
			{
				char fatherName[100];
				strcpy(fatherName,CW2A(cstring2)); //获取插入节点父亲的姓名  将CString转化为char*
				Member fatherNode = SearchFamily(T.ancestor,fatherName);

				if(fatherNode == NULL)           //若未查找到父节点
					MessageBox(_T("此家族中不存在该父亲成员！请重新输入！"));
				else							 //查找到该父亲成员
				{
					CString s1,s2,s3;
					GetDlgItem(IDC_mdy11)->GetWindowTextW(s1);  //获取插入节点的死亡年
					GetDlgItem(IDC_mdm11)->GetWindowTextW(s2);  //获取插入节点的死亡月
					GetDlgItem(IDC_mdd11)->GetWindowTextW(s3);  //获取插入节点的死亡日

					if(((CButton *)GetDlgItem(IDC_RADIO444))->GetCheck() == 1  && (s1 == "" || s2 == "" || s3 == ""))  //单击死亡按钮
						MessageBox(_T("错误提示：\r\n请补全死亡日期！"));
					else
					{
						int i;
						m = (Member)malloc(sizeof(MemberNode));//插入节点申请空间
						strcpy(m->memberInfo.name,CW2A(cstring));//设置节点的名称

						m->parent=fatherNode;   //插入节点的父指针连接到父节点
						fatherNode->child[fatherNode->childNum] = m;   //父节点的孩子指针指向m
						fatherNode->childNum++;                        //父节点的孩子数量+1

						m->couple = NULL;		 //插入节点的妻子节点置空
						m->level = fatherNode->level +1 ;						//根节点层次为父节点层次+1
						m->childNum = 0;										//孩子数量为0
						for(i = 0; i < 10 ;i++)									//将插入节点的孩子节点置空
							m->child[i] = NULL;
					


						strcpy(m->memberInfo.name,CW2A(cstring)); //设置插入节点的姓名  将CString转化为char*
						GetDlgItem(IDC_mNation1)->GetWindowTextW(cstring);  //获取插入节点的民族
						if(cstring == "")
							strcpy(m->memberInfo.nation,"汉族");
						else
							strcpy(m->memberInfo.nation,CW2A(cstring)); //设置插入节点的名族  将CString转化为char*

						m->memberInfo.sex='m';  //默认
						if(((CButton *)GetDlgItem(IDC_RADIO111))->GetCheck() == 1)
						{
							m->memberInfo.sex='m';					//插入节点的性别置为男性
						}
						if(((CButton *)GetDlgItem(IDC_RADIO222))->GetCheck() == 1)
						{
							m->memberInfo.sex='w';					//插入节点的性别置为女性
						}

						GetDlgItem(IDC_mAge1)->GetWindowTextW(cstring);  //获取插入节点的年龄
						m->memberInfo.age = _ttoi(cstring);   //设置插入节点的年龄  将CString转化为int


						GetDlgItem(IDC_mby1)->GetWindowTextW(cstring);  //获取插入节点的出生年
						m->memberInfo.birthYear= _ttoi(cstring);   //设置插入节点的出生年  将CString转化为int
						GetDlgItem(IDC_mbm1)->GetWindowTextW(cstring);  //获取插入节点的出生月
						m->memberInfo.birthMonth = _ttoi(cstring);   //设置插入节点的出生月  将CString转化为int
						GetDlgItem(IDC_mbd1)->GetWindowTextW(cstring);  //获取插入节点的出生日
						m->memberInfo.birthDay = _ttoi(cstring);   //设置插入节点的出生日  将CString转化为int

						if(((CButton *)GetDlgItem(IDC_RADIO444))->GetCheck() == 1)			//若点击了死亡按钮
						{
							m->memberInfo.isAlive = false;								    //设置状态为死亡
							m->memberInfo.deadYear= _ttoi(s1);								//设置插入节点的死亡年  将CString转化为int		
							m->memberInfo.deadMonth = _ttoi(s2);						    //设置插入节点的死亡月  将CString转化为int	
							m->memberInfo.deadDay = _ttoi(s3);								//设置插入节点的死亡日  将CString转化为int
						}
						else
							m->memberInfo.isAlive = true;								    //设置状态为健在


						GetDlgItem(IDC_mEduDegree1)->GetWindowTextW(cstring);  //获取插入节点的学历
						strcpy(m->memberInfo.eduDegree,CW2A(cstring)); //设置插入节点的学历  将CString转化为char*

						GetDlgItem(IDC_mPolicy1)->GetWindowTextW(cstring);  //获取插入节点的政治面貌
						strcpy(m->memberInfo.policy,CW2A(cstring)); //设置插入节点的政治面貌  将CString转化为char*

						GetDlgItem(IDC_mBirthPlace1)->GetWindowTextW(cstring);  //获取插入节点的籍贯
						strcpy(m->memberInfo.birthPlace,CW2A(cstring)); //设置插入节点的籍贯  将CString转化为char*

						GetDlgItem(IDC_mNumber1)->GetWindowTextW(cstring);  //获取插入节点的联系方式
						strcpy(m->memberInfo.number,CW2A(cstring)); //设置插入节点的联系方式  将CString转化为char*

						GetDlgItem(IDC_mAdress1)->GetWindowTextW(cstring);  //获取插入节点的家庭住址
						strcpy(m->memberInfo.adress,CW2A(cstring)); //设置祖先节点的家庭住址  将CString转化为char*

						GetDlgItem(IDC_mAnotherInfo1)->GetWindowTextW(cstring);  //获取插入节点的其它信息
						strcpy(m->memberInfo.anotherInfo,CW2A(cstring)); //设置祖先节点的其它信息  将CString转化为char*


			
						if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1) && (flag == 1) )   //若为男性，存在妻子且输入妻子信息  (男性）
						{

							//将妻子节点连接到祖先节点下
							m->couple = wife;
							wife->couple = m;
							m->memberInfo.isMarrige = true;    //设置婚姻状态

							T.familyInfo.familyNumber++;				//家庭成总人数加1
							T.familyInfo.wNumber++;						//女性成员数+1

							flag = 0;									//将标志变量置为0
						}
						if((((CButton *)GetDlgItem(IDC_RADIO111))->GetCheck() == 1) && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1) && (flag == 0)) //若为男性，存在妻子且没有输入妻子信息
							MessageBox(_T("警告：未输入妻子信息！"));

						//统计成员数量
						if(m->memberInfo.sex == 'm')
						{
							T.familyInfo.familyNumber++;				//家庭成总人数加1
							T.familyInfo.mNumber++;						//男性成员数+1
						}
						else
						{
							T.familyInfo.familyNumber++;				//家庭成总人数加1
							T.familyInfo.wNumber++;						//女性成员数+1
						}

						if((((CButton *)GetDlgItem(IDC_RADIO222))->GetCheck() == 1) && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1))    //若为女性，存在配偶
						{
							m->memberInfo.isMarrige = true;																							//设置婚姻状态
						}
			
			

						//显示当前创建时间 用全局变量显示
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z",localtime(&t) ); 
						puts( tmp ); 
						string += "加入成员:";
						GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);   //获得插入节点的姓名
						string += cstring;
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

						currentNode = m;      //currentNode记录当前插入节点

						specailflag  = 3;  //设置标志变量
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//查找框显示成功
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //家族信息框显示成功

						GetDlgItem(IDC_mName1)->SetWindowTextW(_T(""));				//基本信息置空
						GetDlgItem(IDC_mNation1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mAge1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mby1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mbm1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mbd1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mdy1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mdm1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mdd1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mFather1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mEduDegree1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mPolicy1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mBirthPlace1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mNumber1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mAdress1)->SetWindowTextW(_T(""));  
						GetDlgItem(IDC_mAnotherInfo1)->SetWindowTextW(_T("")); 
						((CButton *)GetDlgItem(IDC_RADIO111))->SetCheck(false);		//设置按钮状态
						((CButton *)GetDlgItem(IDC_RADIO222))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO333))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO444))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO555))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO666))->SetCheck(false);
					}
				}
		
			}
		}
		else			//若家族中存在此成员，则输出提示信息，并且清空输入
		{
			MessageBox(_T("家族中已存在此成员"));
		}
		
	}
	else
		MessageBox(_T("请先创建族谱!"));
}


HBRUSH DD3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
