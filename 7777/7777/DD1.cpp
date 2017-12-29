// DD1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "DD1.h"
#include "C3.h"
#include "afxdialogex.h"


// DD1 �Ի���

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


// DD1 ��Ϣ�������



void  DD1::ShowMemberInfo()  //��ʾ��Ա������Ϣ
{
	CString str;
	str = currentNode->memberInfo.name;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mName)->SetWindowTextW(str);      //��ʾ��Ա����


	str.Format(_T("%d"),  currentNode->memberInfo.age);	//������ת��ΪCSring
    GetDlgItem(IDC_mAge)->SetWindowTextW(str);		//�Գ�Ա����

	str = currentNode->memberInfo.nation;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mNation)->SetWindowTextW(str);      //��ʾ��Ա����

	if(currentNode->memberInfo.sex == 'w')     //����ԱΪ����
	{
		((CButton *)GetDlgItem(IDC_RADIOm3))->SetCheck(true);   //���õ�ѡ��ť
	}
	else											//����ԱΪŮ��		
	{
		((CButton *)GetDlgItem(IDC_RADIOm4))->SetCheck(true);   //���õ�ѡ��ť
	}

	str.Format(_T("%d"),  currentNode->memberInfo.birthYear);	//��������ת��ΪCSring
    GetDlgItem(IDC_mby)->SetWindowTextW(str);		//�Գ�Ա������
	str.Format(_T("%d"),  currentNode->memberInfo.birthMonth);	//��������ת��ΪCSring
    GetDlgItem(IDC_mbm)->SetWindowTextW(str);		//�Գ�Ա������
	str.Format(_T("%d"),  currentNode->memberInfo.birthDay);	//��������ת��ΪCSring
    GetDlgItem(IDC_mbd)->SetWindowTextW(str);		//�Գ�Ա������

	if(currentNode->memberInfo.isAlive == true)     //����Ա����
	{
		((CButton *)GetDlgItem(IDC_RADIOm1))->SetCheck(true);   //���õ�ѡ��ť
	}
	else											//����Աδ����			
	{
		((CButton *)GetDlgItem(IDC_RADIOm2))->SetCheck(true);   //���õ�ѡ��ť
		str.Format(_T("%d"),  currentNode->memberInfo.deadYear);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdy)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadMonth);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdm)->SetWindowTextW(str);		//�Գ�Ա������
		str.Format(_T("%d"),  currentNode->memberInfo.deadDay);	//��������ת��ΪCSring
		GetDlgItem(IDC_mdd)->SetWindowTextW(str);		//�Գ�Ա������
	}
	if(currentNode->level != 0)                             //�����Ϊ���ڵ�
	{
		str = currentNode->parent->memberInfo.name;					//��char[ ]ת��ΪCString
		GetDlgItem(IDC_MFatherName)->SetWindowTextW(str);      //��ʾ��Ա���׵�����
		if(currentNode->parent->couple != NULL)
		{
			str = currentNode->parent->couple->memberInfo.name;					//��char[ ]ת��ΪCString
			GetDlgItem(IDC_MMotherName)->SetWindowTextW(str);      //��ʾ��Աĸ�׵�����
		}
	}

	str = currentNode->memberInfo.eduDegree;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mEduDegree)->SetWindowTextW(str);			//��ʾ��Աѧ��

	str = currentNode->memberInfo.policy;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mPolicy)->SetWindowTextW(str);			//��ʾ��Ա������ò

	str = currentNode->memberInfo.birthPlace;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mBirthPlace)->SetWindowTextW(str);			//��ʾ��Ա����

	str = currentNode->memberInfo.number;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mNumber)->SetWindowTextW(str);			//��ʾ��Ա��ϵ��ʽ

	str = currentNode->memberInfo.adress;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAdress)->SetWindowTextW(str);			//��ʾ��Ա��ͥסַ

	str = currentNode->memberInfo.anotherInfo;					//��char[ ]ת��ΪCString
	GetDlgItem(IDC_mAnotherInfo)->SetWindowTextW(str);			//��ʾ��Ա����������Ϣ

}



void DD1::TranStrToArray(char a[],CString cstring)
{
	int i;
	for(i = 0 ;i<cstring.GetLength();i++)
		a[i] = cstring[i];
}

void DD1::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")
	{
		if(currentNode == NULL)
		{
			MessageBox(_T("��ѡ��ǰ�ڵ�"));
		}
		else
		{
			CString str;
			CC4 *c4 = new CC4();

			strncpy(historyName,currentNode->memberInfo.name,strlen(currentNode->memberInfo.name));							//��¼�޸�֮ǰ����ʷ����
			if(c4->DoModal() == IDOK)
			{
				//��ʾ��ǰ�޸�ʱ�� ��ȫ�ֱ�����ʾ
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
				puts( tmp ); 
				string += "�޸ĳ�Ա";
				string += currentNode->memberInfo.name;
				string += "��Ϣ ";
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

				specailflag = 6;   //���ñ�־����
				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ�  
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //��Ա��Ϣ����ʾ�ɹ�
				MessageBox(_T("���޸ĳ�Ա��Ϣ��"));
			}
		}
	}
	else
		MessageBox(_T("���ȴ�������!"));
}


void DD1::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void DD1::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")
	{
		if(currentNode->level != 0) //�����Ϊ���ڵ�
		{
			selectx = 2;   //�����Ů,�ֵ�
			CC3 dlg;
			if (IDOK==dlg.DoModal())
			{
				specailflag = 1;  ///�����Ǳ���
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
				puts( tmp ); 
				string += "�����Ա:";
			
				string += child->memberInfo.name;
				string += " ";
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

				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ���ʾ�ɹ�
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //������Ϣ����ʾ�ɹ�

			}
			UpdateData(FALSE); 
		}
		else
			MessageBox(_T("�޷������ڵ�����ֵܽڵ�"));
	      
	}
	else
		MessageBox(_T("���ȴ�������!"));
}


void DD1::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")
	{
		if(currentNode->memberInfo.sex == 'w')
			MessageBox(_T("Ů�Գ�Ա�޷����뺢�ӳ�Ա"));
		else
		{
			selectx = 1;   //�����Ů
			CC3 dlg;
			if (IDOK==dlg.DoModal())
			{
				specailflag = 2;  ///�����Ǳ���
				time_t t = time(0); 
				char tmp[64]; 
				strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
				puts( tmp ); 
				string += "�����Ա:";
			
				string += child->memberInfo.name;
				string += " ";
				string += tmp;
				string += "\r\n";  //����
				ss+=" ";
				GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ���ʾ�ɹ�
				GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //������Ϣ����ʾ�ɹ�

			}
			UpdateData(FALSE); 
		}
	}
	else
		MessageBox(_T("���ȴ�������!"));
}

Member DD1::SearchFamily(Member t,char key[])														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�
{
	Member m = NULL; //���ҽڵ��ʼ��Ϊ��
	Member mm = NULL;//�����ڵ����
	if(strncmp(t->memberInfo.name,key,strlen(key)) == 0)  //����ǰ�ڵ��������ڹؼ���
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


void DD1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")   //��δ��������
	{
		if(currentNode == NULL)																//�����ǰ�ڵ�Ϊ��
			MessageBox(_T("����ѡ��ĳ�ڵ㣡"));
		else
		{
			if(currentNode->level == 0)														  //��Ϊ���Ƚڵ�
			MessageBox(_T("�޷�ɾ�����Ƚڵ㣡"));
			else																			  //����Ϊ���Ƚڵ�
			{
				if(currentNode != NULL && currentNode->childNum != 0)								//���ڵ�ǿ��Һ����ӽڵ㣬�����ʾ��Ϣ
				{
					if(MessageBox(_T("�ó�Ա������Ů���Ƿ�ȷ��ɾ����"),_T("HelloMsg"), MB_YESNO|MB_ICONEXCLAMATION)== IDYES )
					{
						//��ʾ��ǰ�޸�ʱ�� ��ȫ�ֱ�����ʾ
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
						puts( tmp ); 
						string += "����Ա";
						string += currentNode->memberInfo.name;
						string += "���� ";
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

						specailflag = 4;   //���ñ�־����
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ�  
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //��Ա��Ϣ����ʾ�ɹ�
					}
				}
				if(currentNode != NULL && currentNode->childNum == 0)								//���ڵ�ǿ���û���ӽڵ�
				{
						//��ʾ��ǰ�޸�ʱ�� ��ȫ�ֱ�����ʾ
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
						puts( tmp ); 
						string += "����Ա";
						string += currentNode->memberInfo.name;
						string += "���� ";
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

						specailflag = 4;   //���ñ�־����
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ�  
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //��Ա��Ϣ����ʾ�ɹ�
				}
		}
		}

	}
	else
		MessageBox(_T("���ȴ�������!"));
	

}





HBRUSH DD1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void DD1::OnBnClickedRadiom1()
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_mdy)->EnableWindow(false);  //���������Ϣ
	//GetDlgItem(IDC_mdm)->EnableWindow(false);  //���������Ϣ
	//GetDlgItem(IDC_mdd)->EnableWindow(false);  //���������Ϣ
}


void DD1::OnBnClickedRadiom2()
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_mdy)->EnableWindow(true);  //���������Ϣ
	//GetDlgItem(IDC_mdm)->EnableWindow(true);  //���������Ϣ
	//GetDlgItem(IDC_mdd)->EnableWindow(true);  //���������Ϣ
}


void DD1::OnBnClickedRadiom5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
