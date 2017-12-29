// DD2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DD2.h"
#include "afxdialogex.h"
#include "com_Header.h"
#include "MemberInfo.h"
#include "FamilyInfo.h"
#include "7777Dlg.h"
#include "II1.h"

// DD2 �Ի���

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


// DD2 ��Ϣ�������

void DD2::OnBnClickedCreatfamily()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(string);
	CString cstring;
	GetDlgItem(IDC_fName)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ������
	if(cstring == "") 
		MessageBox(_T("��������������!"));
	else
	{
		CString s1,s2,s3;
		GetDlgItem(IDC_dy)->GetWindowTextW(s1);  //��ȡ���Ƚڵ��������
		GetDlgItem(IDC_dm)->GetWindowTextW(s2);  //��ȡ���Ƚڵ��������
		GetDlgItem(IDC_dd)->GetWindowTextW(s3);  //��ȡ���Ƚڵ��������
		if(((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == 1  && (s1 == "" || s2 == "" || s3 == ""))  //����������ť ��δ��ȫ��������
			MessageBox(_T("������ʾ��\r\n�벹ȫ��������"));
		else		
		{
			int i;
			T.ancestor = (Member)malloc(sizeof(MemberNode));//��������ڵ�ռ�
			T.ancestor->parent=NULL;   //���Ƚڵ�ĸ�ָ���ÿ�
			T.ancestor->couple = NULL; //���Ƚڵ�����ӽڵ��ÿ�
			for(i = 0; i < 10 ;i++)			//�����Ƚڵ�ĺ��ӽڵ��ÿ�
				T.ancestor->child[i] = NULL;
			T.familyInfo.familyNumber++;				//��ͥ��Ա����1
			T.familyInfo.mNumber++;						//���Գ�Ա��+1
			T.ancestor->level = 0;						//���ڵ���Ϊ0
			T.ancestor->childNum = 0;					//��������Ϊ0
			

			strcpy(T.ancestor->memberInfo.name,CW2A(cstring)); //�������Ƚڵ������  ��CStringת��Ϊchar*
			ancestorName = cstring;    //��ȡ��������

			GetDlgItem(IDC_fNation1)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ������
			if(cstring == "")
				strcpy(T.ancestor->memberInfo.nation,"����");
			else
				strcpy(T.ancestor->memberInfo.nation,CW2A(cstring)); //�������Ƚڵ������  ��CStringת��Ϊchar*

			T.ancestor->memberInfo.sex='m';					//���Ƚڵ���Ա���Ϊ����

			GetDlgItem(IDC_fAge)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ������
			T.ancestor->memberInfo.age = _ttoi(cstring);   //�������Ƚڵ������  ��CStringת��Ϊint


			GetDlgItem(IDC_by)->GetWindowTextW(cstring);							   //��ȡ���Ƚڵ�ĳ�����
			T.ancestor->memberInfo.birthYear= _ttoi(cstring);						   //�������Ƚڵ�ĳ�����  ��CStringת��Ϊint
			GetDlgItem(IDC_bm)->GetWindowTextW(cstring);							   //��ȡ���Ƚڵ�ĳ�����
			T.ancestor->memberInfo.birthMonth = _ttoi(cstring);						   //�������Ƚڵ�ĳ�����  ��CStringת��Ϊint
			GetDlgItem(IDC_bd)->GetWindowTextW(cstring);                               //��ȡ���Ƚڵ�ĳ�����
			T.ancestor->memberInfo.birthDay = _ttoi(cstring);						   //�������Ƚڵ�ĳ�����  ��CStringת��Ϊint

			if(((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == 1)					//�������������ť
			{
				T.ancestor->memberInfo.isAlive = false;								    //�����Ƿ���
				T.ancestor->memberInfo.deadYear= _ttoi(s1);								//�������Ƚڵ��������  ��CStringת��Ϊint		
				T.ancestor->memberInfo.deadMonth = _ttoi(s2);						    //�������Ƚڵ��������  ��CStringת��Ϊint	
				T.ancestor->memberInfo.deadDay = _ttoi(s3);								//�������Ƚڵ��������  ��CStringת��Ϊint
			}
			else
				T.ancestor->memberInfo.isAlive = true;								    //�����Ƿ���


			GetDlgItem(IDC_fEduDegree)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ��ѧ��
			strcpy(T.ancestor->memberInfo.eduDegree,CW2A(cstring)); //�������Ƚڵ��ѧ��  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fPolicy)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ��������ò
			strcpy(T.ancestor->memberInfo.policy,CW2A(cstring)); //�������Ƚڵ��������ò  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fBirthplace)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ�ļ���
			strcpy(T.ancestor->memberInfo.birthPlace,CW2A(cstring)); //�������Ƚڵ�ļ���  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fNumber)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ����ϵ��ʽ
			strcpy(T.ancestor->memberInfo.number,CW2A(cstring)); //�������Ƚڵ����ϵ��ʽ  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fAdress)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ�ļ�ͥסַ
			strcpy(T.ancestor->memberInfo.adress,CW2A(cstring)); //�������Ƚڵ�ļ�ͥסַ  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fAnotherInfo)->GetWindowTextW(cstring);  //��ȡ���Ƚڵ��������Ϣ
			strcpy(T.ancestor->memberInfo.anotherInfo,CW2A(cstring)); //�������Ƚڵ��������Ϣ  ��CStringת��Ϊchar*

			GetDlgItem(IDC_fInfo1)->GetWindowTextW(cstring);  //��ȡ��ͥ������Ϣ
			strcpy(T.familyInfo.anotherInfo,CW2A(cstring)); //�������Ƚڵ��������Ϣ  ��CStringת��Ϊchar*
	
		
			/***************������Ϣ¼�����**********************/
		
			if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck() == 1&& flag == 1 )   //����������������������Ϣ
			{

				//�����ӽڵ����ӵ����Ƚڵ���
				T.ancestor->couple = wife;
				wife->couple = T.ancestor;
				T.ancestor->memberInfo.isMarrige = true;    //���û���״̬
				T.familyInfo.familyNumber++;				//��ͥ��Ա����1
				T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1

			}
			if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck() == 1&& flag == 0 ) //������������û������������Ϣ
				MessageBox(_T("���棺δ����������Ϣ��"));

			flag = 0; //�򽫱�־������Ϊ0���Ա���һ������������Ϣ
			//��ʾ��ǰ����ʱ�� ��ȫ�ֱ�����ʾ
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
			puts( tmp ); 
			string = "���״�����:";
			string += tmp;
			string += "\r\n";  //����
			x = 1;
			currentNode = T.ancestor;      //�޸�currentNode
			ss = "���������Ϣ";
			GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);    //���ҿ�ɹ�
			GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //������Ϣ����ʾ�ɹ�

			GetDlgItem(IDC_fName)->SetWindowTextW(_T(""));				//������Ϣ�ÿ�
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
			((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(false);		//���ð�ť״̬
			((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(false);
			((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);
			((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(false);

		}		

	}

}


void DD2::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_dy)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_dm)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_dd)->EnableWindow(false);  //���������Ϣ
	
}


void DD2::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_dy)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_dm)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_dd)->EnableWindow(true);  //���������Ϣ
	
}


void DD2::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo1)->EnableWindow(true);  //���������Ϣ
}


void DD2::OnBnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo1)->EnableWindow(false);  //���������Ϣ
}



void DD2::OnBnClickedInsertwifeinfo1()
{
	// ���½���ż�Ի���
	II1 *dlg=new II1();//��ģ̬
    dlg->Create(IDD_Insert,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);     
	
}


HBRUSH DD2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
