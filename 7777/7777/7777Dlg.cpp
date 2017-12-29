
// 7777Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "7777.h"
#include "7777Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "7777.h"



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnPaint();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_32771, &CAboutDlg::On32771)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMy7777Dlg 对话框
		


CMy7777Dlg::CMy7777Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy7777Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_House);
}

void CMy7777Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, FamilyTree, m_treeShow);
}

BEGIN_MESSAGE_MAP(CMy7777Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMy7777Dlg::OnTcnSelchangeTab1)
//	ON_EN_CHANGE(FamiliInfo, &CMy7777Dlg::OnEnChangeFamiliinfo)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy7777Dlg::OnBnClickedButton1)
//	ON_EN_CHANGE(FamiliInfo, &CMy7777Dlg::OnEnChangeFamiliinfo)
//ON_EN_CHANGE(IDC_Search, &CMy7777Dlg::OnEnChangeSearch)
ON_NOTIFY(NM_CLICK, FamilyTree, &CMy7777Dlg::OnNMClickFamilytree)
ON_NOTIFY(TVN_SINGLEEXPAND, FamilyTree, &CMy7777Dlg::OnTvnSingleExpandFamilytree)
ON_NOTIFY(TVN_SELCHANGED, FamilyTree, &CMy7777Dlg::OnTvnSelchangedFamilytree)
ON_BN_CLICKED(IDC_BUTTON3, &CMy7777Dlg::OnBnClickedButton3)
ON_EN_CHANGE(IDC_Search, &CMy7777Dlg::OnEnChangeSearch)
ON_BN_CLICKED(IDC_BUTTON2, &CMy7777Dlg::OnBnClickedButton2)
ON_COMMAND(ID_32771, &CMy7777Dlg::On32771)
ON_COMMAND(ID_32773, &CMy7777Dlg::On32773)
ON_COMMAND(ID_32774, &CMy7777Dlg::On32774)
ON_COMMAND(ID_32776, &CMy7777Dlg::On32776)
ON_WM_CTLCOLOR()
ON_COMMAND(ID_32780, &CMy7777Dlg::On32780)
ON_COMMAND(ID_32782, &CMy7777Dlg::On32782)
END_MESSAGE_MAP()


// CMy7777Dlg 消息处理程序

BOOL CMy7777Dlg::OnInitDialog()                       //主窗体响应
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动

	m_Menu.LoadMenu(IDR_MENU2);  //  IDR_MENU1为你加入的菜单的ID，在Resource视图的Menu文件夹下可以找到
	SetMenu(&m_Menu);


	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码



	/******************************开始********************************/
	m_tab.InsertItem(0,_T("家庭信息"));   //创建tabcontrol页
	m_tab.InsertItem(1,_T("新建家谱"));
	m_tab.InsertItem(2,_T("插入成员"));
	m_tab.InsertItem(3,_T("成员基本信息"));

    d1.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1)); 
	d2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1)); 
	d3.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB1)); 
	d4.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1)); 

	CRect rs; 
    m_tab.GetClientRect(&rs); 

	rs.bottom -= 2;
    rs.left += 1;
    rs.top += 27;
    rs.right -= 3;

	d1.MoveWindow(&rs); 
	d2.MoveWindow(&rs); 
	d3.MoveWindow(&rs); 
	d4.MoveWindow(&rs);

	d1.ShowWindow(false); 
	d2.ShowWindow(false); 
	d3.ShowWindow(false); 
	d4.ShowWindow(true); 

	m_tab.SetCurSel(0);
	/********************************结束******************************/

		// 加载四个图标，并将它们的句柄保存到数组   
	hIcon[0] = theApp.LoadIcon(IDI_Girl);   
    hIcon[1] = theApp.LoadIcon(IDI_Boy);   
    hIcon[2] = theApp.LoadIcon(IDI_House);
	hIcon[3] = theApp.LoadIcon(IDI_Face);

	// 创建图像序列CImageList对象   
	m_imageList.Create(24, 24, ILC_COLOR32, 3, 3);  
    for (int i=0; i<4; i++)   
    {   
        m_imageList.Add(hIcon[i]);   
    }  
    // 将三个图标添加到图像序列 
	m_treeShow.SetImageList(&m_imageList, TVSIL_NORMAL);   

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy7777Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy7777Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy7777Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy7777Dlg::ShowfamilyInfo()
{
	CString str;
	
	if(ancestorName != "")   //如果有祖先
	{
		str = T.ancestor->memberInfo.name;					//将char[ ]转化为CString
		d4.GetDlgItem(IDC_CreatMan)->SetWindowTextW(str);		//显示祖先姓名

		str.Format(_T("%d"), T.familyInfo.familyNumber);	//将家庭人数转化为CSring
		d4.GetDlgItem(IDC_TotalNum)->SetWindowTextW(str);		//显示家庭总人数

		str.Format(_T("%d"), T.familyInfo.mNumber);			//将家庭男性人数转化为CSring
		d4.GetDlgItem(IDC_MaleNum)->SetWindowTextW(str);		//显示男性家庭总人数

		str.Format(_T("%d"), T.familyInfo.wNumber);			//将家庭女性人数转化为CSring
		d4.GetDlgItem(IDC_FemaleNum)->SetWindowTextW(str);		//显示家庭女性人数

		str = T.familyInfo.historyDesease;					 //将char[ ]转化为CString
		if(str == "")	d4.GetDlgItem(IDC_HistoryDesease)->SetWindowTextW(_T("无"));//显示家庭疾病史
		else			d4.GetDlgItem(IDC_HistoryDesease)->SetWindowTextW(str);//显示家庭疾病史

		str = T.familyInfo.anotherInfo;						 //将char[ ]转化为CString
		if(str == "")	d4.GetDlgItem(IDC_AnotherInfo)->SetWindowTextW(_T("无"));	//显示家庭其它信息
		else			d4.GetDlgItem(IDC_AnotherInfo)->SetWindowTextW(str);	//显示家庭其它信息
	}
}
void CMy7777Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)  //tabcontrol菜单消息相应事件
{
	// TODO: 在此添加控件通知处理程序代码


	int CurSel = m_tab.GetCurSel(); 
 switch(CurSel) 
 { 
 case 0: 
         d1.ShowWindow(false); 
         d2.ShowWindow(false); 
         d3.ShowWindow(false); 
		 d4.ShowWindow(true); 
		 ShowfamilyInfo();					//显示家庭信息
 break; 
 case 1: 
         d1.ShowWindow(false); 
         d2.ShowWindow(true); 
         d3.ShowWindow(false);
		 d4.ShowWindow(false); 
 break; 
 case 2: 
         d1.ShowWindow(false); 
         d2.ShowWindow(false); 
         d3.ShowWindow(true); 
		 d4.ShowWindow(false); 
 break; 
 case 3: 
         d1.ShowWindow(true); 
         d2.ShowWindow(false); 
         d3.ShowWindow(false); 
		 d4.ShowWindow(false); 
		 if(currentNode != NULL)
			ShowMemberInfo();
 break; 
 default: 
         ; 
     }     
 
    *pResult = 0;


	*pResult = 0;
}




void CMy7777Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();      //退出程序
}

void CMy7777Dlg::DeleteTreeCtrl(HTREEITEM hItem)
{
	if(m_treeShow.ItemHasChildren(hItem) == 0)  //若没有子节点
	{
		m_treeShow.DeleteItem(hItem);//删除当前节点
		return;  //返回
	}
	else
	{
		HTREEITEM hChildItem = m_treeShow.GetChildItem(hItem);
		while(hChildItem!=NULL)
		{
			DeleteTreeCtrl(hChildItem);
			hChildItem =  m_treeShow.GetNextItem(hChildItem, TVGN_NEXT); 
		}
	}
	return ;  //返回
}
HTREEITEM CMy7777Dlg::TreeVisit(HTREEITEM hItem,char key[]) 

{   
	HTREEITEM t = NULL,tt = NULL;
	char test[100];
	strcpy(test,CW2A(m_treeShow.GetItemText(hItem))); //将CString转化为char*
	if(strcmp(test,key) == 0)
	{
		return hItem;//返回查找到的节点
	}

	int n =  m_treeShow.ItemHasChildren(hItem);
	if(n == 1)   //若存在孩子节点
	{
		HTREEITEM hChildItem = m_treeShow.GetChildItem(hItem);  
		while(hChildItem!=NULL) 
		{
			t = TreeVisit(hChildItem,key); //递归遍历孩子节点
			strcpy(test,CW2A(m_treeShow.GetItemText(t))); //将CString转化为char*
			if(strcmp(test,key) == 0)
			{
				tt = t;
				break;
			}
			hChildItem = m_treeShow.GetNextItem(hChildItem, TVGN_NEXT);   
		}

	}
	return tt;

} 


Member CMy7777Dlg::SearchFamily(Member t,char key[])														//函数七：根据关键字查找成员节点（一般为名字）
{
	Member m = NULL; //查找节点初始化为空
	Member mm = NULL;//辅助节点设计
	if(strcmp(t->memberInfo.name,key) == 0)  //若当前节点姓名等于关键字
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



void  CMy7777Dlg::ShowMemberInfo()  //显示成员个人信息
{

	((CButton *)d1.GetDlgItem(IDC_RADIOm1))->SetCheck(false);   //设置单选按钮
	((CButton *)d1.GetDlgItem(IDC_RADIOm2))->SetCheck(false);   //设置单选按钮
	((CButton *)d1.GetDlgItem(IDC_RADIOm3))->SetCheck(false);   //设置单选按钮
	((CButton *)d1.GetDlgItem(IDC_RADIOm4))->SetCheck(false);   //设置单选按钮
	((CButton *)d1.GetDlgItem(IDC_RADIOm5))->SetCheck(false);   //设置单选按钮
	((CButton *)d1.GetDlgItem(IDC_RADIOm6))->SetCheck(false);   //设置单选按钮


	CString str,str2;
	str = currentNode->memberInfo.name;					//将char[ ]转化为CString
	d1.GetDlgItem(IDC_mName)->SetWindowTextW(str);      //显示成员姓名

	str = "第";
	str2.Format(_T("%d"), currentNode->level+1);			//将代数转化为CSring
	str += str2;
	str += "代";
	d1.GetDlgItem(IDC_mLevel)->SetWindowTextW(str);		//显成员代数

	str.Format(_T("%d"), currentNode->memberInfo.age);	//将年龄转化为CSring
    d1.GetDlgItem(IDC_mAge)->SetWindowTextW(str);		//显成员年龄

	str = currentNode->memberInfo.nation;					//将char[ ]转化为CString
	d1.GetDlgItem(IDC_mNation)->SetWindowTextW(str);      //显示成员民族

	if(currentNode->memberInfo.sex == 'm')     //若成员为男性
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm3))->SetCheck(true);   //设置单选按钮
	}
	else									   //若成员为女性		
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm4))->SetCheck(true);   //设置单选按钮
	}

	str.Format(_T("%d"),  currentNode->memberInfo.birthYear);	//将出生年转化为CSring
    d1.GetDlgItem(IDC_mby)->SetWindowTextW(str);		//显成员出生年
	str.Format(_T("%d"),  currentNode->memberInfo.birthMonth);	//将出生月转化为CSring
    d1.GetDlgItem(IDC_mbm)->SetWindowTextW(str);		//显成员出生月
	str.Format(_T("%d"),  currentNode->memberInfo.birthDay);	//将叔生日转化为CSring
    d1.GetDlgItem(IDC_mbd)->SetWindowTextW(str);		//显成员出生日

	if(currentNode->memberInfo.isAlive == true)     //若成员健在
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm1))->SetCheck(true);   //设置单选按钮
	}
	else											//若成员已故		
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm2))->SetCheck(true);   //设置单选按钮
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//将死亡年转化为CSring
		d1.GetDlgItem(IDC_mdy)->SetWindowTextW(str);		//显成员死亡年
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//将死亡月转化为CSring
		d1.GetDlgItem(IDC_mdm)->SetWindowTextW(str);		//显成员死亡月
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//将死亡日转化为CSring
		d1.GetDlgItem(IDC_mdd)->SetWindowTextW(str);		//显成员死亡日
	}

	if(currentNode->memberInfo.isMarrige == true)			//若无配偶
		((CButton *)d1.GetDlgItem(IDC_RADIOm5))->SetCheck(true);   //设置单选按钮
	else
		((CButton *)d1.GetDlgItem(IDC_RADIOm6))->SetCheck(true);   //设置单选按钮

	if(currentNode->level != 0)                             //如果不为根节点
	{
		str = currentNode->parent->memberInfo.name;					//将char[ ]转化为CString
		d1.GetDlgItem(IDC_MFatherName)->SetWindowTextW(str);      //显示成员父亲的姓名
		if(currentNode->parent->couple != NULL)
		{
			str = currentNode->parent->couple->memberInfo.name;					//将char[ ]转化为CString
			d1.GetDlgItem(IDC_MMotherName)->SetWindowTextW(str);      //显示成员母亲的姓名
		}
	}

	str = currentNode->memberInfo.eduDegree;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mEduDegree)->SetWindowTextW(_T("未填写"));
	else
		d1.GetDlgItem(IDC_mEduDegree)->SetWindowTextW(str);			//显示成员学历

	str = currentNode->memberInfo.policy;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mPolicy)->SetWindowTextW(_T("未填写"));
	else
		d1.GetDlgItem(IDC_mPolicy)->SetWindowTextW(str);			//显示成员政治面貌

	str = currentNode->memberInfo.birthPlace;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(_T("未填写"));
	else
		d1.GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(str);			//显示成员籍贯

	str = currentNode->memberInfo.number;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mNumber)->SetWindowTextW(_T("无"));
	else
		d1.GetDlgItem(IDC_mNumber)->SetWindowTextW(str);			//显示成员联系方式

	str = currentNode->memberInfo.adress;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mAdress)->SetWindowTextW(_T("无"));
	else
		d1.GetDlgItem(IDC_mAdress)->SetWindowTextW(str);			//显示成员家庭住址

	str = currentNode->memberInfo.anotherInfo;					//将char[ ]转化为CString
	if(str == "")
		d1.GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(_T("无"));
	else
		d1.GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(str);			//显示成员其它描述信息


}

void CMy7777Dlg::OnNMClickFamilytree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码


	CPoint point;
	GetCursorPos(&point);//获得鼠标点击的位置
	m_treeShow.ScreenToClient(&point);//转化为客户坐标
	UINT uFlags;

	HTREEITEM CurrentItem;
	CurrentItem=m_treeShow.HitTest(point,&uFlags);//获得当前点击节点的ITEM
	//获得该节点的父节点
	// HTREEITEM ParentItem=m_videotree.GetParentItem(CurrentItem);
	char name[100];            //姓名数组
	CString CurrentVideo;    //保存当前点击节点的姓名
	CurrentVideo=m_treeShow.GetItemText(CurrentItem) ;//获得节点值
	if(CurrentVideo != "")
	{
		//页面转换
		d1.ShowWindow(true); 
		d2.ShowWindow(false); 
		d3.ShowWindow(false); 
		d4.ShowWindow(false); 
		m_tab.SetCurSel(3);
		//显示节点信息;
		strcpy(name,CW2A(CurrentVideo)); //获取搜索关键字  将CString转化为char
		currentNode = SearchFamily(T.ancestor,name);  //刷新当前节点

		if(currentNode != NULL)
			ShowMemberInfo();
		else
			 MessageBox(_T("当前节点为空"));
	}
		
	
	*pResult = 0;
}


void CMy7777Dlg::OnTvnSingleExpandFamilytree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
}


void CMy7777Dlg::OnTvnSelchangedFamilytree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CMy7777Dlg::ExpandTree(HTREEITEM hItem)
{
	if(m_treeShow.ItemHasChildren(hItem) == 0)  //若没有子节点
	{
		m_treeShow.Expand(hItem,TVE_EXPAND);
		return;  //返回
	}
	else
	{
		HTREEITEM hChildItem = m_treeShow.GetChildItem(hItem);
		while(hChildItem!=NULL)
		{
			ExpandTree(hChildItem);
			hChildItem =  m_treeShow.GetNextItem(hChildItem, TVGN_NEXT); 
		}
	}
	return ;  //返回
}


void CMy7777Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	if(ancestorName != "")
	{
		CString cstring;
		char test[100];
		GetDlgItem(IDC_Search)->GetWindowTextW(cstring);   //获取查询信息
		strcpy(test,CW2A(cstring));						  //将CString转化为char*
		Member m = SearchFamily(T.ancestor,test);
		if(m == NULL)
		{
			MessageBox(_T("家族中无该成员，请重新输入"));
		}
		else
		{
			MessageBox(_T("查找成功！"));
			HTREEITEM findNode = TreeVisit(hRoot,m->memberInfo.name);  //获得查到的节点
			ExpandTree(findNode);										//展开到查找节点
			currentNode = m;
			d1.ShowWindow(true); 
			d2.ShowWindow(false); 
			d3.ShowWindow(false); 
			d4.ShowWindow(false); 
			if(currentNode != NULL)
				ShowMemberInfo();
			else
				 MessageBox(_T("当前节点为空"));
		}
	}
	else
		MessageBox(_T("请先创建家谱！"));

}




void CMy7777Dlg::OnEnChangeSearch()
{



	if(x)     //如果x等于1,则创建根节点
	{
		hRoot = m_treeShow.InsertItem(ancestorName,3,3);   //创建根节点
		treeArray[tcount] = hRoot;      //保存根节点
		tcount ++;						//树节点的数量+1

		/*d1.ShowWindow(true); 
		d2.ShowWindow(false); 
		d3.ShowWindow(false); 
		d4.ShowWindow(false); 
		if(currentNode != NULL)
		{
			ShowMemberInfo();
			m_tab.SetCurSel(3);
		}*/

		MessageBox(_T("皮氏家谱创建成功！"));
		x = 0;  //标志变量设为0；
	}


	HTREEITEM findNode;
	char name[100],temp[100];
	//创建子节点
	
	if(specailflag == 1  || specailflag == 2 ||  specailflag == 3)  //specailflag被初始化了
	{
		CString str;
		
		Member x;
		int i;
		if(specailflag == 1)  //为brother创建节点
		{
			strcpy(name,currentNode->parent->memberInfo.name);
			str = child->memberInfo.name;
			x = child;
		}
		if(specailflag == 2)  //为child创建节点
		{
			strcpy(name,currentNode->memberInfo.name);
			str = child->memberInfo.name;
			x = child;
		}
		if(specailflag == 3)  //为currentNode创建节点
		{
			
			strcpy(name,currentNode->parent->memberInfo.name);
			str = currentNode->memberInfo.name;
			x = currentNode;
		}

		findNode = TreeVisit(hRoot,name);
		HTREEITEM t;

		if(x->memberInfo.sex == 'm')  //若为男性
			t = m_treeShow.InsertItem(str, 1, 1,findNode); 
		else if(x->memberInfo.sex  == 'w')							    //若为女性
			t = m_treeShow.InsertItem(str, 0, 0,findNode); 
		else
			MessageBox(_T("你是猪吗？"));

		m_treeShow.Expand(findNode,TVE_EXPAND);
		ExpandTree(hRoot);       //展开所有节点
		treeArray[tcount] = t;
		tcount++;

		/*d1.ShowWindow(true); 
		d2.ShowWindow(false); 
		d3.ShowWindow(false); 
		d4.ShowWindow(false); 
		if(currentNode != NULL)
		{
			ShowMemberInfo();
			m_tab.SetCurSel(3);
		}*/
		str = "已成功添加成员：";
		str += x->memberInfo.name;
		MessageBox(str);

		specailflag = -1;   //标志变量置为-1
	}

	if(specailflag == 4)   //删除当前节点
	{
		CString test;
		test += "已成功将成员";
		test += currentNode->memberInfo.name;
		test += "移出族谱！";
		findNode = TreeVisit(hRoot,currentNode->memberInfo.name);   //查找到节点
		DeleteTreeCtrl(findNode);
		DeleteMember(currentNode);
		MessageBox(test);

		currentNode = NULL;									//将当前节点置空
		specailflag = -1;									//标志变量置为-1
	}


	if(specailflag == 5)
	{
		ShowfamilyInfo();									//刷新家族信息显示
		specailflag = -1;									//标志变量置为-1
	}


	if(specailflag == 6)									//修改成员的信息
	{
		CString test;
		HTREEITEM tt = TreeVisit(hRoot,historyName);        //在树控件中查找所有修改之前的节点
		test = (LPCSTR)currentNode->memberInfo.name;
		m_treeShow.SetItemText(tt,test);					//刷新树控件中节点名字的显示
		ShowMemberInfo();									//刷新家族信息显示
		specailflag = -1;									//标志变量置为-1
	}

}
int CMy7777Dlg::DeleteMember(Member m)	//函数四：删除家族树成员
{

	if(m->childNum != 0)    //如果有孩子
	 {
		int i = 0;//若当前节点存在孩子节点,则递归调用此函数,利用树的深度搜索的思想来删除以第i棵整棵子树
			for (i = 0; i < m->childNum; i++)
			{
				DeleteMember(m->child[i]);
			}
			m->childNum = 0;//为了防止访问时孩子节点与其下标之间的关系发生错误，删除每一棵完整的小子树后再将childNum置为0
			return 1;
	 }
	else                   //如果无孩子
	{
		if (m->couple != NULL)  //如果有妻子
		{
			free(m->couple);
			m->couple=NULL;

			if(m->parent!=NULL)
			    m->parent->childNum--;
			if(m->memberInfo.sex == 'w')
				T.familyInfo.wNumber--;
			else
				T.familyInfo.mNumber--;

			T.familyInfo.familyNumber--;

			free(m);
			m=NULL;
			return 1;
		}						//如果没有妻子
		else
		{
			if(m->parent!=NULL)
			    m->parent->childNum--;
			if(m->memberInfo.sex == 'w')
				T.familyInfo.wNumber--;
			else
				T.familyInfo.mNumber--;

			T.familyInfo.familyNumber--;
			free(m);
			m=NULL;
			return 1;
		}	
	}
}




int CMy7777Dlg::SaveFamilyFile(Family T,char savepath[100])																	  //函数八：将节点保存在文件里
{
	Member head;
	Member queue[20];
	int i,front,rear;//创建一个队列
	FILE *fp;
	fp=fopen(savepath, "w");
	if(fp==NULL)
	{
		return 0;
	}//以读写方式打开文件
	fwrite(T.ancestor,sizeof(MemberNode),1,fp);
	front =rear=0;
	queue[rear++]=T.ancestor;
	while(front !=rear) //广度有限遍历树并且写入文件
	{
		head=queue[front++];
		for(i=0;i<head->childNum;i++)
		{
			fwrite(head->child[i],sizeof(MemberNode),1,fp);
			queue[rear++]=head->child[i];
		}
	}
	fclose(fp);
	fp=NULL;
	return 1;
}
void CMy7777Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString test;
	CString filepath;
	char savepath[100];
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
	{
		filepath=dlg.GetPathName();
		UpdateData(FALSE);
	}
	strcpy(savepath,CW2A(filepath));      //将CString 转换为char数组
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "已将成功将家谱保存至：\r\n";
		test += filepath;
		MessageBox(test);
	}
	//else
	//	MessageBox(_T("保存失败！"));
	
}


void CAboutDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
}


void CMy7777Dlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	d1.ShowWindow(false); 
    d2.ShowWindow(true); 
    d3.ShowWindow(false);
	d4.ShowWindow(false);
	m_tab.SetCurSel(1);
}


void CMy7777Dlg::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CString test;
	CString filepath;
	char savepath[100];
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
	{
		filepath=dlg.GetPathName();
		UpdateData(FALSE);
	}
	strcpy(savepath,CW2A(filepath));      //将CString 转换为char数组
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "已将成功将家谱保存至：\r\n";
		test += filepath;
		MessageBox(test);
	}
	//else
	//	MessageBox(_T("保存失败！"));
}


void CMy7777Dlg::On32774()
{
	// TODO: 在此添加命令处理程序代码
	d1.ShowWindow(false); 
    d2.ShowWindow(false); 
    d3.ShowWindow(true); 
	d4.ShowWindow(false); 
	m_tab.SetCurSel(2);
}


void CMy7777Dlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	d1.ShowWindow(true); 
    d2.ShowWindow(false); 
    d3.ShowWindow(false); 
	d4.ShowWindow(false); 
	if(currentNode != NULL)
	ShowMemberInfo();
	m_tab.SetCurSel(3);
}


HBRUSH CMy7777Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	 
}


void CMy7777Dlg::On32780() 
{
	// 打开关于对话框

	CAboutDlg dlg;
	dlg.DoModal();
}


void CMy7777Dlg::On32782()
{
	// TODO: Add your command handler code here
	CString test;
	CString filepath;
	char savepath[100];
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
	{
		filepath=dlg.GetPathName();
		UpdateData(FALSE);
	}
	strcpy(savepath,CW2A(filepath));      //将CString 转换为char数组
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "已将成功将家谱保存至：\r\n";
		test += filepath;
		MessageBox(test);
	}
	else
		MessageBox(_T("保存失败！"));
}
