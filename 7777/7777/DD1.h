#pragma once
#include "C4.h"

// DD1 �Ի���
extern int flag;   //����һ����־����
extern int selectx;   //ѡ���־
extern CString ancestorName;  //��������
extern int specailflag;
extern int reactFlag;
extern Family T;
extern char historyName[100];  //��¼��ʷ����
class DD1 : public CDialogEx
{
	DECLARE_DYNAMIC(DD1)

public:
	DD1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DD1();
	void TranStrToArray(char a[],CString cstring);
	Member SearchFamily(Member t,char key[]);
	void ShowMemberInfo();  //��ʾ��Ա������Ϣ
	int DeleteMember(Member m);	//�����ģ�ɾ�������Ա
// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton12();
//	afx_msg void OnBnClickedRadio3();
//	afx_msg void OnBnClickedButton6();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRadiom1();
	afx_msg void OnBnClickedRadiom2();
	afx_msg void OnBnClickedRadiom5();
};
