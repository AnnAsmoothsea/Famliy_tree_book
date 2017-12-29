// C3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "7777.h"
#include "C3.h"
#include "afxdialogex.h"
#include "II1.h"

// CC3 �Ի���

IMPLEMENT_DYNAMIC(CC3, CDialogEx)

CC3::CC3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC3::IDD, pParent)
{

}

CC3::~CC3()
{
}

void CC3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CC3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CC3::OnBnClickedOk)
	ON_BN_CLICKED(IDC_InsertWifeInfo4, &CC3::OnBnClickedInsertwifeinfo4)
	ON_BN_CLICKED(IDC_RADIOc4, &CC3::OnBnClickedRadioc4)
	ON_BN_CLICKED(IDC_RADIOc3, &CC3::OnBnClickedRadioc3)
	ON_BN_CLICKED(IDC_RADIOc6, &CC3::OnBnClickedRadioc6)
	ON_BN_CLICKED(IDC_RADIOc5, &CC3::OnBnClickedRadioc5)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_InsertWifeInfo5, &CC3::OnBnClickedInsertwifeinfo5)
END_MESSAGE_MAP()


// CC3 ��Ϣ�������

Member CC3::SearchFamily(Member t,char key[])														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�
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
void CC3::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString cstring;
	Member m;									 //����һ���ڵ���ʱ�洢������Ϣ
	GetDlgItem(IDC_cName)->GetWindowTextW(cstring);							 //��ò���ڵ������

	if(cstring == "" )											 //δ�����Ա����
		MessageBox(_T("������ʾ��\r\n�������Ա��������"));			
	else
	{
		char name[100];
		strcpy(name,CW2A(cstring));
		if(SearchFamily(T.ancestor,name) == NULL)		//��Ϊ���ҵ���ǰ����ڵ�
		{
			CString s1,s2,s3;
			GetDlgItem(IDC_cdy)->GetWindowTextW(s1);  //��ȡ����ڵ��������
			GetDlgItem(IDC_cdm)->GetWindowTextW(s2);  //��ȡ����ڵ��������
			GetDlgItem(IDC_cdd)->GetWindowTextW(s3);  //��ȡ����ڵ��������
			if(((CButton *)GetDlgItem(IDC_RADIOc4))->GetCheck() == 1 && (s1 == "" || s2 == "" || s3 == ""))//��������������ť����δ������������������
				MessageBox(_T("������ʾ��\r\n�벹ȫ��������"));
			else
			{
				int i;
				m = (Member)malloc(sizeof(MemberNode));//����ڵ�����ռ�
				m->couple = NULL;									    //����ڵ�����ӽڵ��ÿ�
				m->childNum = 0;										//��������Ϊ0
				for(i = 0; i < 10 ;i++)									//������ڵ�ĺ��ӽڵ��ÿ�
					m->child[i] = NULL;


				strcpy(m->memberInfo.name,CW2A(cstring)); //���ò���ڵ������  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cNation)->GetWindowTextW(cstring);  //��ȡ����ڵ������
				if(cstring == "")
					strcpy(m->memberInfo.nation,"����");
				else
					strcpy(m->memberInfo.nation,CW2A(cstring)); //���ò���ڵ������  ��CStringת��Ϊchar*

				m->memberInfo.sex='m';  //Ĭ��
				if(((CButton *)GetDlgItem(IDC_RADIOc1))->GetCheck() == 1)
				{
					m->memberInfo.sex='m';					//����ڵ���Ա���Ϊ����
					
				}
				if(((CButton *)GetDlgItem(IDC_RADIOc2))->GetCheck() == 1)
				{
					m->memberInfo.sex='w';					//����ڵ���Ա���ΪŮ��
					
				}

				GetDlgItem(IDC_cAge)->GetWindowTextW(cstring);  //��ȡ����ڵ������
				m->memberInfo.age = _ttoi(cstring);   //���ò���ڵ������  ��CStringת��Ϊint


				GetDlgItem(IDC_cby)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
				m->memberInfo.birthYear= _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint
				GetDlgItem(IDC_cbm)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
				m->memberInfo.birthMonth = _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint
				GetDlgItem(IDC_cbd)->GetWindowTextW(cstring);  //��ȡ����ڵ�ĳ�����
				m->memberInfo.birthDay = _ttoi(cstring);   //���ò���ڵ�ĳ�����  ��CStringת��Ϊint

				if(((CButton *)GetDlgItem(IDC_RADIOc4))->GetCheck() == 1)  //����������ť
				{
					m->memberInfo.isAlive = false;				    //�����Ƿ���
					m->memberInfo.deadYear= _ttoi(s1);			 //���ò���ڵ��������  ��CStringת��Ϊint
					m->memberInfo.deadMonth = _ttoi(s2);		 //���ò���ڵ��������  ��CStringת��Ϊint
					m->memberInfo.deadDay = _ttoi(s3);			 //���ò���ڵ��������  ��CStringת��Ϊint
				}
				else
					m->memberInfo.isAlive = true;				    //�����Ƿ���

				GetDlgItem(IDC_cEduDegree)->GetWindowTextW(cstring);  //��ȡ����ڵ��ѧ��
				strcpy(m->memberInfo.eduDegree,CW2A(cstring)); //���ò���ڵ��ѧ��  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cPolicy)->GetWindowTextW(cstring);  //��ȡ����ڵ��������ò
				strcpy(m->memberInfo.policy,CW2A(cstring)); //���ò���ڵ��������ò  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cBirthPlace)->GetWindowTextW(cstring);  //��ȡ����ڵ�ļ���
				strcpy(m->memberInfo.birthPlace,CW2A(cstring)); //���ò���ڵ�ļ���  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cNumber)->GetWindowTextW(cstring);  //��ȡ����ڵ����ϵ��ʽ
				strcpy(m->memberInfo.number,CW2A(cstring)); //���ò���ڵ����ϵ��ʽ  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cAdress)->GetWindowTextW(cstring);  //��ȡ����ڵ�ļ�ͥסַ
				strcpy(m->memberInfo.adress,CW2A(cstring)); //�������Ƚڵ�ļ�ͥסַ  ��CStringת��Ϊchar*

				GetDlgItem(IDC_cAnotherInfo)->GetWindowTextW(cstring);  //��ȡ����ڵ��������Ϣ
				strcpy(m->memberInfo.anotherInfo,CW2A(cstring)); //�������Ƚڵ��������Ϣ  ��CStringת��Ϊchar*

				if(selectx == 1)					//��ӵ�currentNode���ӽڵ�
				{
					currentNode->child[currentNode->childNum] = m;
					currentNode->childNum ++;
					m->parent = currentNode;
					m->level = currentNode->level+1;    //���Ϊ�������+1

				}
				if(selectx ==2)					//��ӵ�currentNode���ֵܽڵ�
				{
					currentNode->parent->child[currentNode->parent->childNum] = m;
					currentNode->parent->childNum ++;
					m->parent = currentNode->parent;
					m->level = currentNode->level;    //���Ϊ�������+1
				}
			
				if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1) && (flag == 1) )   //��Ϊ���ԣ���������������������Ϣ  (���ԣ�
				{

					//�����ӽڵ����ӵ����Ƚڵ���
					m->couple = wife;
					wife->couple = m;
					m->memberInfo.isMarrige = true;    //���û���״̬
					T.familyInfo.familyNumber++;				//��ͥ��Ա����1
					T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1
				}
				if(m->memberInfo.sex == 'm' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1) && (flag == 0)) //��Ϊ���ԣ�����������û������������Ϣ
					MessageBox(_T("���棺δ����������Ϣ��"));



				if(m->memberInfo.sex == 'w' && (((CButton *)GetDlgItem(IDC_RADIOc5))->GetCheck() == 1))    //��ΪŮ�ԣ�������ż
				{
					m->memberInfo.isMarrige = true;																							//���û���״̬
				}

				//ͳ�Ƴ�Ա����
				if(m->memberInfo.sex == 'm')
					T.familyInfo.mNumber++;						//Ů�Գ�Ա��+1
				else
					T.familyInfo.wNumber++;						//Ů�Գ�Ա��+1
				T.familyInfo.familyNumber++;					//��ͥ������+1

				child = m;
				//��ʾ��ǰ����ʱ�� ��ȫ�ֱ�����ʾ
				CDialogEx::OnOK();
			}
		}
		else
			MessageBox(_T("�������Ѵ��ڴ˳�Ա~"));
	}
		
}


void CC3::OnBnClickedInsertwifeinfo4()
{
	II1 *dlg=new II1();//��ģ̬
    dlg->Create(IDD_Insert,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);     

	// TODO: Add your control notification handler code here
}


void CC3::OnBnClickedRadioc4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_cdy)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_cdm)->EnableWindow(true);  //���������Ϣ
	GetDlgItem(IDC_cdd)->EnableWindow(true);  //���������Ϣ

}


void CC3::OnBnClickedRadioc3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_cdy)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_cdm)->EnableWindow(false);  //���������Ϣ
	GetDlgItem(IDC_cdd)->EnableWindow(false);  //���������Ϣ
}


void CC3::OnBnClickedRadioc6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(false);   //����������Ϣ
}


void CC3::OnBnClickedRadioc5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(currentNode->memberInfo.sex == 'm')	  //��Ϊ����
	{
		GetDlgItem(IDC_InsertWifeInfo5)->EnableWindow(true);   //����������Ϣ
	}
}


HBRUSH CC3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CC3::OnBnClickedInsertwifeinfo5()


{
	// ��������ӶԻ���
	II1 *dlg=new II1();//��ģ̬
    dlg->Create(IDD_Insert,this);    //��һ�������ǶԻ���ID��
    dlg->ShowWindow(SW_SHOW);     
}
