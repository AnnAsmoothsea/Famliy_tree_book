// C4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "C4.h"
#include "afxdialogex.h"
#include "II1.h"

// CC4 �Ի���

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


// CC4 ��Ϣ�������


void CC4::OnBnClickedInsertwifeinfo5()
{
	//���޸ĳ�Ա��Ϣ�Ի���
	II1 *dlg=new II1();//��ģ̬
    dlg->Create(IDD_Insert,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);     

}







void  CC4::ShowMemberInfo()  //��ʾ��Ա������Ϣ
{
	CString str;
	str = currentNode->memberInfo.name;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mName2)->SetWindowTextW(str);      //��ʾ��Ա����



	str = currentNode->memberInfo.eduDegree;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mEduDegree2)->SetWindowTextW(str);			//��ʾ��Աѧ��

	str = currentNode->memberInfo.policy;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mPolicy2)->SetWindowTextW(str);			//��ʾ��Ա������ò

	str = currentNode->memberInfo.birthPlace;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mBirthPlace2)->SetWindowTextW(str);			//��ʾ��Ա����

	str = currentNode->memberInfo.number;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mNumber2)->SetWindowTextW(str);			//��ʾ��Ա��ϵ��ʽ

	str = currentNode->memberInfo.adress;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAdress2)->SetWindowTextW(str);			//��ʾ��Ա��ͥסַ

	str = currentNode->memberInfo.anotherInfo;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAnotherInfo2)->SetWindowTextW(str);			//��ʾ��Ա����������Ϣ

}











void CC4::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cstring;

	GetDlgItem(IDC_mName2)->GetWindowTextW(cstring);							 //��ò���ڵ������
	strcpy(currentNode->memberInfo.name,CW2A(cstring)); //�����޸Ľڵ������  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mEduDegree2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ��ѧ��
	strcpy(currentNode->memberInfo.eduDegree,CW2A(cstring)); //���ò���ڵ��ѧ��  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mPolicy2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ��������ò
	strcpy(currentNode->memberInfo.policy,CW2A(cstring)); //�����޸Ľڵ��������ò  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mBirthPlace2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ�ļ���
	strcpy(currentNode->memberInfo.birthPlace,CW2A(cstring)); //�����޸Ľڵ�ļ���  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mNumber2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ����ϵ��ʽ
	strcpy(currentNode->memberInfo.number,CW2A(cstring)); //�����޸Ľڵ����ϵ��ʽ  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mAdress2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ�ļ�ͥסַ
	strcpy(currentNode->memberInfo.adress,CW2A(cstring)); //�����޸Ľڵ�ļ�ͥסַ  ��CStringת��Ϊchar*

	GetDlgItem(IDC_mAnotherInfo2)->GetWindowTextW(cstring);  //��ȡ�޸Ľڵ��������Ϣ
	strcpy(currentNode->memberInfo.anotherInfo,CW2A(cstring)); //�����޸Ľڵ��������Ϣ  ��CStringת��Ϊchar*


	if(((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck() == 1 && currentNode->memberInfo.isAlive == true)  //����������ť�ҳ�Աԭ״̬Ϊ���ڣ���������ʱ��
	{
		CString s1,s2,s3;
		GetDlgItem(IDC_mdy111)->GetWindowTextW(s1);  //��ȡ�޸Ľڵ��������
		GetDlgItem(IDC_mdm111)->GetWindowTextW(s2);  //��ȡ�޸Ľڵ��������
		GetDlgItem(IDC_mdd111)->GetWindowTextW(s3);  //��ȡ�޸Ľڵ��������
		
		if(s1 == "" || s2 == "" || s3 == "")
			MessageBox(_T("���棺\r\n�벹ȫ��������"));
		else
		{
			currentNode->memberInfo.isAlive = false;				    //�����Ƿ���
			currentNode->memberInfo.deadYear= _ttoi(cstring);			 //���ò���ڵ��������  ��CStringת��Ϊint	
			currentNode->memberInfo.deadMonth = _ttoi(cstring);		 //���ò���ڵ��������  ��CStringת��Ϊint	
			currentNode->memberInfo.deadDay = _ttoi(cstring);			 //���ò���ڵ��������  ��CStringת��Ϊint

			if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 1)           //����������ż��ť����������ż��Ϣ
			{	//�����ӽڵ����ӵ���ǰ�ڵ���
				currentNode->couple = wife;
				wife->couple = currentNode;
				currentNode->memberInfo.isMarrige = true;    //���û���״̬
				T.familyInfo.familyNumber++;				//��ͥ��Ա����1
				T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1
				MessageBox(_T("�����������Ϣ"));
			}
			if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 0)			//����������ż��ť��δ������ż��Ϣ
				MessageBox(_T("����:\r\nδ����������Ϣ"));									//���������ʾ
			flag = 0;
			CDialogEx::OnOK();
		}
	}
	else																				//��δ����������ť
	{	
		if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 1)           //����������ż��ť����������ż��Ϣ
		{	//�����ӽڵ����ӵ���ǰ�ڵ���
			currentNode->couple = wife;
			wife->couple = currentNode;
			currentNode->memberInfo.isMarrige = true;    //���û���״̬
			T.familyInfo.familyNumber++;				//��ͥ��Ա����1
			T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1
			MessageBox(_T("�����������Ϣ"));
		}
		if(((CButton *)GetDlgItem(IDC_RADIO5))->GetCheck() == 1 && flag == 0)			//����������ż��ť��δ������ż��Ϣ
			MessageBox(_T("����:\r\nδ����������Ϣ"));	
		flag = 0;
		CDialogEx::OnOK();
	}
	
}


void CC4::OnBnClickedRadio5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(true);  //���������Ϣ
}


void CC4::OnBnClickedRadio6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);  //���������Ϣ
	
}


void CC4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	//����ʾ��

	CString str;
	str = currentNode->memberInfo.name;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mName2)->SetWindowTextW(str);      //��ʾ��Ա����

	if(currentNode->memberInfo.isAlive == 1)     //����Ա����
		((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(true);
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(true);
		GetDlgItem(IDC_RADIO3)->EnableWindow();					//���ý��ڰ�ť���ɵ��
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdy111)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdm111)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdd111)->SetWindowTextW(str);		//�Գ�Ա������
	}

	if(currentNode->memberInfo.isMarrige == true)
	{
		((CButton *)GetDlgItem(IDC_RADIO5))->SetCheck(true); //�����ѻ���
		GetDlgItem(IDC_RADIO6)->EnableWindow(false);		 //����������ť���ɵ��
		GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);		 //����������Ӱ�ť���ɵ��
	}
	else
		((CButton *)GetDlgItem(IDC_RADIO6))->SetCheck(true); //����δ����
		
	str = currentNode->memberInfo.eduDegree;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mEduDegree2)->SetWindowTextW(str);			//��ʾ��Աѧ��

	str = currentNode->memberInfo.policy;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mPolicy2)->SetWindowTextW(str);			//��ʾ��Ա������ò

	str = currentNode->memberInfo.birthPlace;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mBirthPlace2)->SetWindowTextW(str);			//��ʾ��Ա����

	str = currentNode->memberInfo.number;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mNumber2)->SetWindowTextW(str);			//��ʾ��Ա��ϵ��ʽ

	str = currentNode->memberInfo.adress;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAdress2)->SetWindowTextW(str);			//��ʾ��Ա��ͥסַ

	str = currentNode->memberInfo.anotherInfo;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAnotherInfo2)->SetWindowTextW(str);			//��ʾ��Ա����������Ϣ
    //����ʾ��

}


HBRUSH CC4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CC4::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_mdy111)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_mdm111)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_mdd111)->EnableWindow(true);  //���������Ϣ
	/*((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);*/
}


void CC4::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_mdy111)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_mdm111)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_mdd111)->EnableWindow(false);  //���������Ϣ
}
