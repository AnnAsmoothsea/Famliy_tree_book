// DD3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "DD3.h"
#include "afxdialogex.h"
#include "II1.h"

// DD3 �Ի���

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


// DD3 ��Ϣ�������


void DD3::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void DD3::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void DD3::OnBnClickedInsertwifeinfo()
{
	II1 *dlg=new II1();//��ģ̬
    dlg->Create(IDD_Insert,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);     
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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



Member DD3::SearchFamily(Member t,char key[])														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�
{
	Member m = NULL; //���ҽڵ��ʼ��Ϊ��
	Member mm = NULL;//�����ڵ����
	if(strncmp(t->memberInfo.name,key,strlen(key)) == 0 && t->memberInfo.sex == 'm')  //����ǰ�ڵ��������ڹؼ�����Ϊ���Խڵ�
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

void DD3::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
}



void DD3::OnBnClickedRadio555()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1)	  //��Ϊ����
	{
		GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(true);   //����������Ϣ
	}
}


void DD3::OnBnClickedRadio666()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo)->EnableWindow(false);   //����������Ϣ

}


void DD3::OnBnClickedRadio333()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_mdy11)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_mdm11)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_mdd11)->EnableWindow(false);  //���������Ϣ
}


void DD3::OnBnClickedRadio444()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_mdy11)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_mdm11)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_mdd11)->EnableWindow(true);  //���������Ϣ
}


void DD3::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(ancestorName != "")
	{
		CString cstring,cstring2;
		char name[100];
		GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);							 //��ò���ڵ������
		strcpy(name,CW2A(cstring));													//CStringת��Ϊchar����
		if(SearchFamily(T.ancestor,name) == NULL)									//�жϼ������Ƿ���ڴ˳�Ա,���������򴴽�
		{
			Member m;																 //����һ���ڵ���ʱ�洢������Ϣ
			GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);							 //��ò���ڵ������

			GetDlgItem(IDC_mFather1)->GetWindowTextW(cstring2);							 //��ȡ����ڵ㸸�ڵ������
			if(cstring == "" && cstring2 != "")											 //δ�����Ա����
				MessageBox(_T("������ʾ��\r\n����������Ա��������"));			
			else if(cstring != "" && cstring2 == "")									 //δ���븸������
				MessageBox(_T("������ʾ��\r\n����������Ա���׵�������"));
			else if(cstring == "" && cstring2 == "")
				MessageBox(_T("������ʾ��\r\n������ó�Ա�������ó�Ա���׵�����"));//δ�����Ա�����͸�������
			else
			{
				char fatherName[100];
				strcpy(fatherName,CW2A(cstring2)); //��ȡ����ڵ㸸�׵�����  ��CStringת��Ϊchar*
				Member fatherNode = SearchFamily(T.ancestor,fatherName);

				if(fatherNode == NULL)           //��δ���ҵ����ڵ�
					MessageBox(_T("�˼����в����ڸø��׳�Ա�����������룡"));
				else							 //���ҵ��ø��׳�Ա
				{
					CString s1,s2,s3;
					GetDlgItem(IDC_mdy11)->GetWindowTextW(s1);  //��ȡ����ڵ��������
					GetDlgItem(IDC_mdm11)->GetWindowTextW(s2);  //��ȡ����ڵ��������
					GetDlgItem(IDC_mdd11)->GetWindowTextW(s3);  //��ȡ����ڵ��������

					if(((CButton *)GetDlgItem(IDC_RADIO444))->GetCheck() == 1  && (s1 == "" || s2 == "" || s3 == ""))  //����������ť
						MessageBox(_T("������ʾ��\r\n�벹ȫ�������ڣ�"));
					else
					{
						int i;
						m = (Member)malloc(sizeof(MemberNode));//����ڵ�����ռ�
						strcpy(m->memberInfo.name,CW2A(cstring));//���ýڵ������

						m->parent=fatherNode;   //����ڵ�ĸ�ָ�����ӵ����ڵ�
						fatherNode->child[fatherNode->childNum] = m;   //���ڵ�ĺ���ָ��ָ��m
						fatherNode->childNum++;                        //���ڵ�ĺ�������+1

						m->couple = NULL;		 //����ڵ�����ӽڵ��ÿ�
						m->level = fatherNode->level +1 ;						//���ڵ���Ϊ���ڵ���+1
						m->childNum = 0;										//��������Ϊ0
						for(i = 0; i < 10 ;i++)									//������ڵ�ĺ��ӽڵ��ÿ�
							m->child[i] = NULL;
					


						strcpy(m->memberInfo.name,CW2A(cstring)); //���ò���ڵ������  ��CStringת��Ϊchar*
						GetDlgItem(IDC_mNation1)->GetWindowTextW(cstring);  //��ȡ����ڵ������
						if(cstring == "")
							strcpy(m->memberInfo.nation,"����");
						else
							strcpy(m->memberInfo.nation,CW2A(cstring)); //���ò���ڵ������  ��CStringת��Ϊchar*

						m->memberInfo.sex='m';  //Ĭ��
						if(((CButton *)GetDlgItem(IDC_RADIO111))->GetCheck() == 1)
						{
							m->memberInfo.sex='m';					//����ڵ���Ա���Ϊ����
						}
						if(((CButton *)GetDlgItem(IDC_RADIO222))->GetCheck() == 1)
						{
							m->memberInfo.sex='w';					//����ڵ���Ա���ΪŮ��
						}

						GetDlgItem(IDC_mAge1)->GetWindowTextW(cstring);  //��ȡ����ڵ������
						m->memberInfo.age = _ttoi(cstring);   //���ò���ڵ������  ��CStringת��Ϊint


						GetDlgItem(IDC_mby1)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
						m->memberInfo.birthYear= _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint
						GetDlgItem(IDC_mbm1)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
						m->memberInfo.birthMonth = _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint
						GetDlgItem(IDC_mbd1)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
						m->memberInfo.birthDay = _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint

						if(((CButton *)GetDlgItem(IDC_RADIO444))->GetCheck() == 1)			//�������������ť
						{
							m->memberInfo.isAlive = false;								    //����״̬Ϊ����
							m->memberInfo.deadYear= _ttoi(s1);								//���ò���ڵ��������  ��CStringת��Ϊint		
							m->memberInfo.deadMonth = _ttoi(s2);						    //���ò���ڵ��������  ��CStringת��Ϊint	
							m->memberInfo.deadDay = _ttoi(s3);								//���ò���ڵ��������  ��CStringת��Ϊint
						}
						else
							m->memberInfo.isAlive = true;								    //����״̬Ϊ����


						GetDlgItem(IDC_mEduDegree1)->GetWindowTextW(cstring);  //��ȡ����ڵ��ѧ��
						strcpy(m->memberInfo.eduDegree,CW2A(cstring)); //���ò���ڵ��ѧ��  ��CStringת��Ϊchar*

						GetDlgItem(IDC_mPolicy1)->GetWindowTextW(cstring);  //��ȡ����ڵ��������ò
						strcpy(m->memberInfo.policy,CW2A(cstring)); //���ò���ڵ��������ò  ��CStringת��Ϊchar*

						GetDlgItem(IDC_mBirthPlace1)->GetWindowTextW(cstring);  //��ȡ����ڵ�ļ���
						strcpy(m->memberInfo.birthPlace,CW2A(cstring)); //���ò���ڵ�ļ���  ��CStringת��Ϊchar*

						GetDlgItem(IDC_mNumber1)->GetWindowTextW(cstring);  //��ȡ����ڵ����ϵ��ʽ
						strcpy(m->memberInfo.number,CW2A(cstring)); //���ò���ڵ����ϵ��ʽ  ��CStringת��Ϊchar*

						GetDlgItem(IDC_mAdress1)->GetWindowTextW(cstring);  //��ȡ����ڵ�ļ�ͥסַ
						strcpy(m->memberInfo.adress,CW2A(cstring)); //�������Ƚڵ�ļ�ͥסַ  ��CStringת��Ϊchar*

						GetDlgItem(IDC_mAnotherInfo1)->GetWindowTextW(cstring);  //��ȡ����ڵ��������Ϣ
						strcpy(m->memberInfo.anotherInfo,CW2A(cstring)); //�������Ƚڵ��������Ϣ  ��CStringת��Ϊchar*


			
						if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1) && (flag == 1) )   //��Ϊ���ԣ���������������������Ϣ  (���ԣ�
						{

							//�����ӽڵ����ӵ����Ƚڵ���
							m->couple = wife;
							wife->couple = m;
							m->memberInfo.isMarrige = true;    //���û���״̬

							T.familyInfo.familyNumber++;				//��ͥ����������1
							T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1

							flag = 0;									//����־������Ϊ0
						}
						if((((CButton *)GetDlgItem(IDC_RADIO111))->GetCheck() == 1) && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1) && (flag == 0)) //��Ϊ���ԣ�����������û������������Ϣ
							MessageBox(_T("���棺δ����������Ϣ��"));

						//ͳ�Ƴ�Ա����
						if(m->memberInfo.sex == 'm')
						{
							T.familyInfo.familyNumber++;				//��ͥ����������1
							T.familyInfo.mNumber++;						//���Գ�Ա��+1
						}
						else
						{
							T.familyInfo.familyNumber++;				//��ͥ����������1
							T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1
						}

						if((((CButton *)GetDlgItem(IDC_RADIO222))->GetCheck() == 1) && (((CButton *)GetDlgItem(IDC_RADIO555))->GetCheck() == 1))    //��ΪŮ�ԣ�������ż
						{
							m->memberInfo.isMarrige = true;																							//���û���״̬
						}
			
			

						//��ʾ��ǰ����ʱ�� ��ȫ�ֱ�����ʾ
						time_t t = time(0); 
						char tmp[64]; 
						strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z",localtime(&t) ); 
						puts( tmp ); 
						string += "�����Ա:";
						GetDlgItem(IDC_mName1)->GetWindowTextW(cstring);   //��ò���ڵ������
						string += cstring;
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

						currentNode = m;      //currentNode��¼��ǰ����ڵ�

						specailflag  = 3;  //���ñ�־����
						GetParent()->GetParent()->GetDlgItem(IDC_Search)->SetWindowText(ss);		//���ҿ���ʾ�ɹ�
						GetParent()->GetParent()->GetDlgItem(FamiliInfo)->SetWindowText(string);    //������Ϣ����ʾ�ɹ�

						GetDlgItem(IDC_mName1)->SetWindowTextW(_T(""));				//������Ϣ�ÿ�
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
						((CButton *)GetDlgItem(IDC_RADIO111))->SetCheck(false);		//���ð�ť״̬
						((CButton *)GetDlgItem(IDC_RADIO222))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO333))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO444))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO555))->SetCheck(false);
						((CButton *)GetDlgItem(IDC_RADIO666))->SetCheck(false);
					}
				}
		
			}
		}
		else			//�������д��ڴ˳�Ա���������ʾ��Ϣ�������������
		{
			MessageBox(_T("�������Ѵ��ڴ˳�Ա"));
		}
		
	}
	else
		MessageBox(_T("���ȴ�������!"));
}


HBRUSH DD3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
