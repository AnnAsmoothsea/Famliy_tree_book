
// 7777Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "7777Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "7777.h"



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMy7777Dlg �Ի���
		


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


// CMy7777Dlg ��Ϣ�������

BOOL CMy7777Dlg::OnInitDialog()                       //��������Ӧ
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�

	m_Menu.LoadMenu(IDR_MENU2);  //  IDR_MENU1Ϊ�����Ĳ˵���ID����Resource��ͼ��Menu�ļ����¿����ҵ�
	SetMenu(&m_Menu);


	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������



	/******************************��ʼ********************************/
	m_tab.InsertItem(0,_T("��ͥ��Ϣ"));   //����tabcontrolҳ
	m_tab.InsertItem(1,_T("�½�����"));
	m_tab.InsertItem(2,_T("�����Ա"));
	m_tab.InsertItem(3,_T("��Ա������Ϣ"));

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
	/********************************����******************************/

		// �����ĸ�ͼ�꣬�������ǵľ�����浽����   
	hIcon[0] = theApp.LoadIcon(IDI_Girl);   
    hIcon[1] = theApp.LoadIcon(IDI_Boy);   
    hIcon[2] = theApp.LoadIcon(IDI_House);
	hIcon[3] = theApp.LoadIcon(IDI_Face);

	// ����ͼ������CImageList����   
	m_imageList.Create(24, 24, ILC_COLOR32, 3, 3);  
    for (int i=0; i<4; i++)   
    {   
        m_imageList.Add(hIcon[i]);   
    }  
    // ������ͼ����ӵ�ͼ������ 
	m_treeShow.SetImageList(&m_imageList, TVSIL_NORMAL);   

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy7777Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy7777Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy7777Dlg::ShowfamilyInfo()
{
	CString str;
	
	if(ancestorName != "")   //���������
	{
		str = T.ancestor->memberInfo.name;					//��char[ ]ת��ΪCString
		d4.GetDlgItem(IDC_CreatMan)->SetWindowTextW(str);		//��ʾ��������

		str.Format(_T("%d"), T.familyInfo.familyNumber);	//����ͥ����ת��ΪCSring
		d4.GetDlgItem(IDC_TotalNum)->SetWindowTextW(str);		//��ʾ��ͥ������

		str.Format(_T("%d"), T.familyInfo.mNumber);			//����ͥ��������ת��ΪCSring
		d4.GetDlgItem(IDC_MaleNum)->SetWindowTextW(str);		//��ʾ���Լ�ͥ������

		str.Format(_T("%d"), T.familyInfo.wNumber);			//����ͥŮ������ת��ΪCSring
		d4.GetDlgItem(IDC_FemaleNum)->SetWindowTextW(str);		//��ʾ��ͥŮ������

		str = T.familyInfo.historyDesease;					 //��char[ ]ת��ΪCString
		if(str == "")	d4.GetDlgItem(IDC_HistoryDesease)->SetWindowTextW(_T("��"));//��ʾ��ͥ����ʷ
		else			d4.GetDlgItem(IDC_HistoryDesease)->SetWindowTextW(str);//��ʾ��ͥ����ʷ

		str = T.familyInfo.anotherInfo;						 //��char[ ]ת��ΪCString
		if(str == "")	d4.GetDlgItem(IDC_AnotherInfo)->SetWindowTextW(_T("��"));	//��ʾ��ͥ������Ϣ
		else			d4.GetDlgItem(IDC_AnotherInfo)->SetWindowTextW(str);	//��ʾ��ͥ������Ϣ
	}
}
void CMy7777Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)  //tabcontrol�˵���Ϣ��Ӧ�¼�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	int CurSel = m_tab.GetCurSel(); 
 switch(CurSel) 
 { 
 case 0: 
         d1.ShowWindow(false); 
         d2.ShowWindow(false); 
         d3.ShowWindow(false); 
		 d4.ShowWindow(true); 
		 ShowfamilyInfo();					//��ʾ��ͥ��Ϣ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();      //�˳�����
}

void CMy7777Dlg::DeleteTreeCtrl(HTREEITEM hItem)
{
	if(m_treeShow.ItemHasChildren(hItem) == 0)  //��û���ӽڵ�
	{
		m_treeShow.DeleteItem(hItem);//ɾ����ǰ�ڵ�
		return;  //����
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
	return ;  //����
}
HTREEITEM CMy7777Dlg::TreeVisit(HTREEITEM hItem,char key[]) 

{   
	HTREEITEM t = NULL,tt = NULL;
	char test[100];
	strcpy(test,CW2A(m_treeShow.GetItemText(hItem))); //��CStringת��Ϊchar*
	if(strcmp(test,key) == 0)
	{
		return hItem;//���ز��ҵ��Ľڵ�
	}

	int n =  m_treeShow.ItemHasChildren(hItem);
	if(n == 1)   //�����ں��ӽڵ�
	{
		HTREEITEM hChildItem = m_treeShow.GetChildItem(hItem);  
		while(hChildItem!=NULL) 
		{
			t = TreeVisit(hChildItem,key); //�ݹ�������ӽڵ�
			strcpy(test,CW2A(m_treeShow.GetItemText(t))); //��CStringת��Ϊchar*
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


Member CMy7777Dlg::SearchFamily(Member t,char key[])														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�
{
	Member m = NULL; //���ҽڵ��ʼ��Ϊ��
	Member mm = NULL;//�����ڵ����
	if(strcmp(t->memberInfo.name,key) == 0)  //����ǰ�ڵ��������ڹؼ���
	{
		return t;
	}
	if(t ->childNum != 0)		 //����ǰ�ڵ���ں��ӽڵ�
	{
		int i;
		for(i = 0 ; i<t->childNum ; i++)
		{
		    mm = SearchFamily(t->child[i],key);
			if( mm != NULL)
			{
				m = mm;           //���²��ҽڵ�
				break;			  //�˳�ѭ��
			}
		}
	}
	return m;					 //���ز��ҽڵ�
}



void  CMy7777Dlg::ShowMemberInfo()  //��ʾ��Ա������Ϣ
{

	((CButton *)d1.GetDlgItem(IDC_RADIOm1))->SetCheck(false);   //���õ�ѡ��ť
	((CButton *)d1.GetDlgItem(IDC_RADIOm2))->SetCheck(false);   //���õ�ѡ��ť
	((CButton *)d1.GetDlgItem(IDC_RADIOm3))->SetCheck(false);   //���õ�ѡ��ť
	((CButton *)d1.GetDlgItem(IDC_RADIOm4))->SetCheck(false);   //���õ�ѡ��ť
	((CButton *)d1.GetDlgItem(IDC_RADIOm5))->SetCheck(false);   //���õ�ѡ��ť
	((CButton *)d1.GetDlgItem(IDC_RADIOm6))->SetCheck(false);   //���õ�ѡ��ť


	CString str,str2;
	str = currentNode->memberInfo.name;					//��char[ ]ת��ΪCString
	d1.GetDlgItem(IDC_mName)->SetWindowTextW(str);      //��ʾ��Ա����

	str = "��";
	str2.Format(_T("%d"), currentNode->level+1);			//������ת��ΪCSring
	str += str2;
	str += "��";
	d1.GetDlgItem(IDC_mLevel)->SetWindowTextW(str);		//�Գ�Ա����

	str.Format(_T("%d"), currentNode->memberInfo.age);	//������ת��ΪCSring
    d1.GetDlgItem(IDC_mAge)->SetWindowTextW(str);		//�Գ�Ա����

	str = currentNode->memberInfo.nation;					//��char[ ]ת��ΪCString
	d1.GetDlgItem(IDC_mNation)->SetWindowTextW(str);      //��ʾ��Ա����

	if(currentNode->memberInfo.sex == 'm')     //����ԱΪ����
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm3))->SetCheck(true);   //���õ�ѡ��ť
	}
	else									   //����ԱΪŮ��		
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm4))->SetCheck(true);   //���õ�ѡ��ť
	}

	str.Format(_T("%d"),  currentNode->memberInfo.birthYear);	//��������ת��ΪCSring
    d1.GetDlgItem(IDC_mby)->SetWindowTextW(str);		//�Գ�Ա������
	str.Format(_T("%d"),  currentNode->memberInfo.birthMonth);	//��������ת��ΪCSring
    d1.GetDlgItem(IDC_mbm)->SetWindowTextW(str);		//�Գ�Ա������
	str.Format(_T("%d"),  currentNode->memberInfo.birthDay);	//��������ת��ΪCSring
    d1.GetDlgItem(IDC_mbd)->SetWindowTextW(str);		//�Գ�Ա������

	if(currentNode->memberInfo.isAlive == true)     //����Ա����
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm1))->SetCheck(true);   //���õ�ѡ��ť
	}
	else											//����Ա�ѹ�		
	{
		((CButton *)d1.GetDlgItem(IDC_RADIOm2))->SetCheck(true);   //���õ�ѡ��ť
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//��������ת��ΪCSring
		d1.GetDlgItem(IDC_mdy)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//��������ת��ΪCSring
		d1.GetDlgItem(IDC_mdm)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//��������ת��ΪCSring
		d1.GetDlgItem(IDC_mdd)->SetWindowTextW(str);		//�Գ�Ա������
	}

	if(currentNode->memberInfo.isMarrige == true)			//������ż
		((CButton *)d1.GetDlgItem(IDC_RADIOm5))->SetCheck(true);   //���õ�ѡ��ť
	else
		((CButton *)d1.GetDlgItem(IDC_RADIOm6))->SetCheck(true);   //���õ�ѡ��ť

	if(currentNode->level != 0)                             //�����Ϊ���ڵ�
	{
		str = currentNode->parent->memberInfo.name;					//��char[ ]ת��ΪCString
		d1.GetDlgItem(IDC_MFatherName)->SetWindowTextW(str);      //��ʾ��Ա���׵�����
		if(currentNode->parent->couple != NULL)
		{
			str = currentNode->parent->couple->memberInfo.name;					//��char[ ]ת��ΪCString
			d1.GetDlgItem(IDC_MMotherName)->SetWindowTextW(str);      //��ʾ��Աĸ�׵�����
		}
	}

	str = currentNode->memberInfo.eduDegree;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mEduDegree)->SetWindowTextW(_T("δ��д"));
	else
		d1.GetDlgItem(IDC_mEduDegree)->SetWindowTextW(str);			//��ʾ��Աѧ��

	str = currentNode->memberInfo.policy;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mPolicy)->SetWindowTextW(_T("δ��д"));
	else
		d1.GetDlgItem(IDC_mPolicy)->SetWindowTextW(str);			//��ʾ��Ա������ò

	str = currentNode->memberInfo.birthPlace;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(_T("δ��д"));
	else
		d1.GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(str);			//��ʾ��Ա����

	str = currentNode->memberInfo.number;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mNumber)->SetWindowTextW(_T("��"));
	else
		d1.GetDlgItem(IDC_mNumber)->SetWindowTextW(str);			//��ʾ��Ա��ϵ��ʽ

	str = currentNode->memberInfo.adress;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mAdress)->SetWindowTextW(_T("��"));
	else
		d1.GetDlgItem(IDC_mAdress)->SetWindowTextW(str);			//��ʾ��Ա��ͥסַ

	str = currentNode->memberInfo.anotherInfo;					//��char[ ]ת��ΪCString
	if(str == "")
		d1.GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(_T("��"));
	else
		d1.GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(str);			//��ʾ��Ա����������Ϣ


}

void CMy7777Dlg::OnNMClickFamilytree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	CPoint point;
	GetCursorPos(&point);//����������λ��
	m_treeShow.ScreenToClient(&point);//ת��Ϊ�ͻ�����
	UINT uFlags;

	HTREEITEM CurrentItem;
	CurrentItem=m_treeShow.HitTest(point,&uFlags);//��õ�ǰ����ڵ��ITEM
	//��øýڵ�ĸ��ڵ�
	// HTREEITEM ParentItem=m_videotree.GetParentItem(CurrentItem);
	char name[100];            //��������
	CString CurrentVideo;    //���浱ǰ����ڵ������
	CurrentVideo=m_treeShow.GetItemText(CurrentItem) ;//��ýڵ�ֵ
	if(CurrentVideo != "")
	{
		//ҳ��ת��
		d1.ShowWindow(true); 
		d2.ShowWindow(false); 
		d3.ShowWindow(false); 
		d4.ShowWindow(false); 
		m_tab.SetCurSel(3);
		//��ʾ�ڵ���Ϣ;
		strcpy(name,CW2A(CurrentVideo)); //��ȡ�����ؼ���  ��CStringת��Ϊchar
		currentNode = SearchFamily(T.ancestor,name);  //ˢ�µ�ǰ�ڵ�

		if(currentNode != NULL)
			ShowMemberInfo();
		else
			 MessageBox(_T("��ǰ�ڵ�Ϊ��"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

void CMy7777Dlg::ExpandTree(HTREEITEM hItem)
{
	if(m_treeShow.ItemHasChildren(hItem) == 0)  //��û���ӽڵ�
	{
		m_treeShow.Expand(hItem,TVE_EXPAND);
		return;  //����
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
	return ;  //����
}


void CMy7777Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if(ancestorName != "")
	{
		CString cstring;
		char test[100];
		GetDlgItem(IDC_Search)->GetWindowTextW(cstring);   //��ȡ��ѯ��Ϣ
		strcpy(test,CW2A(cstring));						  //��CStringת��Ϊchar*
		Member m = SearchFamily(T.ancestor,test);
		if(m == NULL)
		{
			MessageBox(_T("�������޸ó�Ա������������"));
		}
		else
		{
			MessageBox(_T("���ҳɹ���"));
			HTREEITEM findNode = TreeVisit(hRoot,m->memberInfo.name);  //��ò鵽�Ľڵ�
			ExpandTree(findNode);										//չ�������ҽڵ�
			currentNode = m;
			d1.ShowWindow(true); 
			d2.ShowWindow(false); 
			d3.ShowWindow(false); 
			d4.ShowWindow(false); 
			if(currentNode != NULL)
				ShowMemberInfo();
			else
				 MessageBox(_T("��ǰ�ڵ�Ϊ��"));
		}
	}
	else
		MessageBox(_T("���ȴ������ף�"));

}




void CMy7777Dlg::OnEnChangeSearch()
{



	if(x)     //���x����1,�򴴽����ڵ�
	{
		hRoot = m_treeShow.InsertItem(ancestorName,3,3);   //�������ڵ�
		treeArray[tcount] = hRoot;      //������ڵ�
		tcount ++;						//���ڵ������+1

		/*d1.ShowWindow(true); 
		d2.ShowWindow(false); 
		d3.ShowWindow(false); 
		d4.ShowWindow(false); 
		if(currentNode != NULL)
		{
			ShowMemberInfo();
			m_tab.SetCurSel(3);
		}*/

		MessageBox(_T("Ƥ�ϼ��״����ɹ���"));
		x = 0;  //��־������Ϊ0��
	}


	HTREEITEM findNode;
	char name[100],temp[100];
	//�����ӽڵ�
	
	if(specailflag == 1  || specailflag == 2 ||  specailflag == 3)  //specailflag����ʼ����
	{
		CString str;
		
		Member x;
		int i;
		if(specailflag == 1)  //Ϊbrother�����ڵ�
		{
			strcpy(name,currentNode->parent->memberInfo.name);
			str = child->memberInfo.name;
			x = child;
		}
		if(specailflag == 2)  //Ϊchild�����ڵ�
		{
			strcpy(name,currentNode->memberInfo.name);
			str = child->memberInfo.name;
			x = child;
		}
		if(specailflag == 3)  //ΪcurrentNode�����ڵ�
		{
			
			strcpy(name,currentNode->parent->memberInfo.name);
			str = currentNode->memberInfo.name;
			x = currentNode;
		}

		findNode = TreeVisit(hRoot,name);
		HTREEITEM t;

		if(x->memberInfo.sex == 'm')  //��Ϊ����
			t = m_treeShow.InsertItem(str, 1, 1,findNode); 
		else if(x->memberInfo.sex  == 'w')							    //��ΪŮ��
			t = m_treeShow.InsertItem(str, 0, 0,findNode); 
		else
			MessageBox(_T("��������"));

		m_treeShow.Expand(findNode,TVE_EXPAND);
		ExpandTree(hRoot);       //չ�����нڵ�
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
		str = "�ѳɹ���ӳ�Ա��";
		str += x->memberInfo.name;
		MessageBox(str);

		specailflag = -1;   //��־������Ϊ-1
	}

	if(specailflag == 4)   //ɾ����ǰ�ڵ�
	{
		CString test;
		test += "�ѳɹ�����Ա";
		test += currentNode->memberInfo.name;
		test += "�Ƴ����ף�";
		findNode = TreeVisit(hRoot,currentNode->memberInfo.name);   //���ҵ��ڵ�
		DeleteTreeCtrl(findNode);
		DeleteMember(currentNode);
		MessageBox(test);

		currentNode = NULL;									//����ǰ�ڵ��ÿ�
		specailflag = -1;									//��־������Ϊ-1
	}


	if(specailflag == 5)
	{
		ShowfamilyInfo();									//ˢ�¼�����Ϣ��ʾ
		specailflag = -1;									//��־������Ϊ-1
	}


	if(specailflag == 6)									//�޸ĳ�Ա����Ϣ
	{
		CString test;
		HTREEITEM tt = TreeVisit(hRoot,historyName);        //�����ؼ��в��������޸�֮ǰ�Ľڵ�
		test = (LPCSTR)currentNode->memberInfo.name;
		m_treeShow.SetItemText(tt,test);					//ˢ�����ؼ��нڵ����ֵ���ʾ
		ShowMemberInfo();									//ˢ�¼�����Ϣ��ʾ
		specailflag = -1;									//��־������Ϊ-1
	}

}
int CMy7777Dlg::DeleteMember(Member m)	//�����ģ�ɾ����������Ա
{

	if(m->childNum != 0)    //����к���
	 {
		int i = 0;//����ǰ�ڵ���ں��ӽڵ�,��ݹ���ô˺���,�����������������˼����ɾ���Ե�i����������
			for (i = 0; i < m->childNum; i++)
			{
				DeleteMember(m->child[i]);
			}
			m->childNum = 0;//Ϊ�˷�ֹ����ʱ���ӽڵ������±�֮��Ĺ�ϵ��������ɾ��ÿһ��������С�������ٽ�childNum��Ϊ0
			return 1;
	 }
	else                   //����޺���
	{
		if (m->couple != NULL)  //���������
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
		}						//���û������
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




int CMy7777Dlg::SaveFamilyFile(Family T,char savepath[100])																	  //�����ˣ����ڵ㱣�����ļ���
{
	Member head;
	Member queue[20];
	int i,front,rear;//����һ������
	FILE *fp;
	fp=fopen(savepath, "w");
	if(fp==NULL)
	{
		return 0;
	}//�Զ�д��ʽ���ļ�
	fwrite(T.ancestor,sizeof(MemberNode),1,fp);
	front =rear=0;
	queue[rear++]=T.ancestor;
	while(front !=rear) //������ޱ���������д���ļ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString test;
	CString filepath;
	char savepath[100];
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
	{
		filepath=dlg.GetPathName();
		UpdateData(FALSE);
	}
	strcpy(savepath,CW2A(filepath));      //��CString ת��Ϊchar����
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "�ѽ��ɹ������ױ�������\r\n";
		test += filepath;
		MessageBox(test);
	}
	//else
	//	MessageBox(_T("����ʧ�ܣ�"));
	
}


void CAboutDlg::On32771()
{
	// TODO: �ڴ���������������
}


void CMy7777Dlg::On32771()
{
	// TODO: �ڴ���������������
	d1.ShowWindow(false); 
    d2.ShowWindow(true); 
    d3.ShowWindow(false);
	d4.ShowWindow(false);
	m_tab.SetCurSel(1);
}


void CMy7777Dlg::On32773()
{
	// TODO: �ڴ���������������
	CString test;
	CString filepath;
	char savepath[100];
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
	{
		filepath=dlg.GetPathName();
		UpdateData(FALSE);
	}
	strcpy(savepath,CW2A(filepath));      //��CString ת��Ϊchar����
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "�ѽ��ɹ������ױ�������\r\n";
		test += filepath;
		MessageBox(test);
	}
	//else
	//	MessageBox(_T("����ʧ�ܣ�"));
}


void CMy7777Dlg::On32774()
{
	// TODO: �ڴ���������������
	d1.ShowWindow(false); 
    d2.ShowWindow(false); 
    d3.ShowWindow(true); 
	d4.ShowWindow(false); 
	m_tab.SetCurSel(2);
}


void CMy7777Dlg::On32776()
{
	// TODO: �ڴ���������������
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
	 // TODO:  �ڴ˸��� DC ���κ����� 
	 if(nCtlColor==CTLCOLOR_BTN)          //���İ�ť��ɫ 
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(121,121,0));    
	  HBRUSH b=CreateSolidBrush(RGB(121,121,0)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_SCROLLBAR)  // ������
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(233,233,220)); 
	  HBRUSH b=CreateSolidBrush(RGB(233,233,220)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_EDIT)   //���ı༭�� 
	 { 
	  //pDC->SetBkMode(TRANSPARENT); 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(165,254,236)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,255,255)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_STATIC)  //���ľ�̬�ı� 
	 { 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(255,240,240)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,255,255)); 
	  return b; 
	 } 
	 else if(nCtlColor==CTLCOLOR_DLG)   //���ĶԻ��򱳾�ɫ 
	 { 
	  pDC->SetTextColor(RGB(0,0,0)); 
	  pDC->SetBkColor(RGB(166,254,1)); 
	  HBRUSH b=CreateSolidBrush(RGB(255,240,240)); 
	  return b; 
	 } 
	 // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������ 
	 return hbr; 


}


void CAboutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	 
}


void CMy7777Dlg::On32780() 
{
	// �򿪹��ڶԻ���

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
	strcpy(savepath,CW2A(filepath));      //��CString ת��Ϊchar����
	if(SaveFamilyFile(T,savepath) != 0)
	{
		test += "�ѽ��ɹ������ױ�������\r\n";
		test += filepath;
		MessageBox(test);
	}
	else
		MessageBox(_T("����ʧ�ܣ�"));
}
