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
	GetDlgItem(IDC_wName)->GetWindowTextW(cstring);  //��ȡ���ӽڵ������
	if(cstring == "")
		MessageBox(_T("������ʾ����������������"));
	else
	{
		
		wife = (Member)malloc(sizeof(MemberNode));//��������ڵ�ռ�
		wife->parent=NULL;   //���ӵĸ�ָ���ÿ�
		int i;
		for(i = 0; i < 10 ;i++)			//�����ӽڵ�ĺ��ӽڵ��ÿ�
			wife->child[i] = NULL;
		wife->couple  = NULL;           //�����ӽڵ����żָ���ÿ�

	
		strncpy(wife->memberInfo.name,CW2A(cstring),strlen(wife->memberInfo.name)); //�������ӽڵ������  ��CStringת��Ϊchar*

		GetDlgItem(IDC_wNation1)->GetWindowTextW(cstring);  //��ȡ���ӽڵ������
		strncpy(wife->memberInfo.nation,CW2A(cstring),strlen(wife->memberInfo.nation)); //�������ӽڵ������  ��CStringת��Ϊchar*

		wife->memberInfo.sex='w';					//���ӽڵ���Ա���ΪŮ��

		GetDlgItem(IDC_wAge)->GetWindowTextW(cstring);  //��ȡ���ӽڵ������
		wife->memberInfo.age = _ttoi(cstring);   //�������ӽڵ������  ��CStringת��Ϊint


		GetDlgItem(IDC_wby)->GetWindowTextW(cstring);  //��ȡ���ӽڵ�ĳ�����
		wife->memberInfo.birthYear= _ttoi(cstring);   //�������ӽڵ�ĳ�����  ��CStringת��Ϊint
		GetDlgItem(IDC_wbm)->GetWindowTextW(cstring);  //��ȡ���ӽڵ�ĳ�����
		wife->memberInfo.birthMonth = _ttoi(cstring);   //�������ӽڵ�ĳ�����  ��CStringת��Ϊint
		GetDlgItem(IDC_wbd)->GetWindowTextW(cstring);  //��ȡ���ӽڵ�ĳ�����
		wife->memberInfo.birthDay = _ttoi(cstring);   //�������ӽڵ�ĳ�����  ��CStringת��Ϊint

		

		GetDlgItem(IDC_wEduDegree)->GetWindowTextW(cstring);  //��ȡ���ӽڵ��ѧ��
		strcpy(wife->memberInfo.eduDegree,CW2A(cstring)); //�������ӽڵ��ѧ��  ��CStringת��Ϊchar*

		GetDlgItem(IDC_wPolicy)->GetWindowTextW(cstring);  //��ȡ���ӽڵ��������ò
		strcpy(wife->memberInfo.policy,CW2A(cstring)); //�������ӽڵ��������ò  ��CStringת��Ϊchar*

		GetDlgItem(IDC_wBirthplace)->GetWindowTextW(cstring);  //��ȡ���ӽڵ�ļ���
		strcpy(wife->memberInfo.birthPlace,CW2A(cstring)); //�������ӽڵ�ļ���  ��CStringת��Ϊchar*

		GetDlgItem(IDC_wNumber)->GetWindowTextW(cstring);  //��ȡ���ӽڵ����ϵ��ʽ
		strcpy(wife->memberInfo.number,CW2A(cstring)); //�������ӽڵ����ϵ��ʽ  ��CStringת��Ϊchar*

		GetDlgItem(IDC_wAdress)->GetWindowTextW(cstring);  //��ȡ���ӽڵ�ļ�ͥסַ
		strcpy(wife->memberInfo.adress,CW2A(cstring)); //�������ӽڵ�ļ�ͥסַ  ��CStringת��Ϊchar*	

		if(((CButton *)GetDlgItem(IDC_RADIOx2))->GetCheck() == 1)  //����������ť
		{
			CString s1,s2,s3;
			GetDlgItem(IDC_wdy)->GetWindowTextW(s1);  //��ȡ���ӽڵ��������
			GetDlgItem(IDC_wdm)->GetWindowTextW(s2);  //��ȡ���ӽڵ��������
			GetDlgItem(IDC_wdd)->GetWindowTextW(s3);  //��ȡ���ӽڵ��������
			if(s1 == "" || s2 == "" || s3 == "")
				MessageBox(_T("���棺\r\n�벹ȫ�������ڣ�"));
			else
			{

				wife->memberInfo.deadYear= _ttoi(s1);   //�������ӽڵ��������  ��CStringת��Ϊint
				wife->memberInfo.deadMonth = _ttoi(s2);   //�������ӽڵ��������  ��CStringת��Ϊint		
				wife->memberInfo.deadDay = _ttoi(s3);   //�������ӽڵ��������  ��CStringת��Ϊint
				flag = 1;								//��־��������Ϊ1����ʾ�Ѵ�������
				CDialogEx::OnOK();
			}
		}
		else
		{
				flag = 1;								//��־��������Ϊ1����ʾ�Ѵ�������
				CDialogEx::OnOK();
		}
		
	}

}


void II1::OnBnClickedRadiox2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_wdy)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_wdm)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_wdd)->EnableWindow(true);  //���������Ϣ
}


void II1::OnBnClickedRadiox1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_wdy)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_wdm)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_wdd)->EnableWindow(false);  //���������Ϣ
}


HBRUSH II1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
