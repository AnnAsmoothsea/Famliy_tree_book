// DD4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "DD4.h"
#include "C1.h"
#include "afxdialogex.h"

// DD4 �Ի���

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


// DD4 ��Ϣ�������


void DD4::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	CC1 *dlg=new CC1();//��ģ̬
    dlg->Create(IDD_CorrectFamilInfo,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);         

}


void DD4::OnBnClickedCorrectfamilyinfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")							//��������
	{
		CString str;
		CC1 *dlg=new CC1();//��ģ̬
		if(dlg->DoModal()==IDOK) 
		{ 
			//��ʾ��ǰ�޸�ʱ�� ��ȫ�ֱ�����ʾ
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
			puts( tmp ); 
			string += "�޸ļ�����Ϣ ";
			string += tmp;
			string += "\r\n";  //����
			
			if(reactFlag == 0)
			{
				ss = "�����������Ϣ";
				reactFlag = 1;
			}
			else
			{
				ss = "�����������Ϣ ";
				reactFlag = 0;
			}

			specailflag = 5;   //���ñ�־����
			GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ�  
			GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //������Ϣ����ʾ�ɹ�
			MessageBox(_T("���޸ļ�����Ϣ��"));
		}  

	}
	else
		MessageBox(_T("���ȴ�������!"));
}


HBRUSH DD4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
