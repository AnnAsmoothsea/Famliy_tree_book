#pragma once
#include "TreeDefined.h"

extern int flag;   //����һ����־����
// DD3 �Ի���
extern Member currentNode;    //��ǰ�ڵ���Ϣ
extern Family T;             //������
extern  CString string ;     //ȫ�ֱ��������ʾ��Ϣ��
extern CString ss;			 //���ҿ������Ϣ
extern CString ancestorName;
extern int specailflag;
extern int reactFlag;

class DD3 : public CDialogEx
{
	DECLARE_DYNAMIC(DD3)

public:
	DD3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DD3();
	void TranStrToArray(char a[],CString cstring);
// �Ի�������
	enum { IDD = IDD_DIALOG1 };
	Member SearchFamily(Member t,char key[]);//  ���������ҽڵ�
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedInsertwifeinfo();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedRadio444();
//	afx_msg void OnBnClickedRadio333();
	afx_msg void OnBnClickedRadio555();
	afx_msg void OnBnClickedRadio666();
	afx_msg void OnBnClickedRadio333();
	afx_msg void OnBnClickedRadio444();
	afx_msg void OnBnClickedButton3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
