// C1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "C1.h"
#include "afxdialogex.h"


// CC1 �Ի���

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


// CC1 ��Ϣ�������


void CC1::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CC1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString str;

	GetDlgItem(IDC_EDITf1)->GetWindowTextW(str);		 //��ȡ���岡ʷ
	strcpy(T.familyInfo.historyDesease,CW2A(str));		 //�޸ļ����Ŵ���ʷ  ��CStringת��Ϊchar*

	GetDlgItem(IDC_EDITf2)->GetWindowTextW(str);		 //��ȡ����������Ϣ
	strcpy(T.familyInfo.anotherInfo,CW2A(str));			 //�޸ļ���������Ϣ  ��CStringת��Ϊchar*
	

	CDialogEx::OnOK();
}


void CC1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString str;
	str = T.familyInfo.historyDesease;					//��ȡ��ͥ����ʷ
	GetDlgItem(IDC_EDITf1)->SetWindowTextW(str);   //��ʾ���岡ʷ

	str = T.familyInfo.anotherInfo;					    //��ȡ��ͥ������Ϣ
	GetDlgItem(IDC_EDITf2)->SetWindowTextW(str);   //��ʾ����������Ϣ
}


HBRUSH CC1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
