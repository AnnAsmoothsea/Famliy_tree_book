#pragma once


#include "TreeDefined.h"
#include "7777.h"
#include "DD1.h"
#include "DD3.h"
#include "DD4.h"

extern CString string; //�༭���ַ���
extern CString ss; //���ҿ��ַ���
extern Family T;  //��ͥ��
extern int x;    //�������ı�����Ӧ����
extern CString ancestorName;  //��������
extern int flag;   //����һ����־����

//extern Family T;
// DD2 �Ի���

class DD2 : public CDialogEx
{
	DECLARE_DYNAMIC(DD2)

public:
	DD2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DD2();
	void TranStrToArray(char a[],CString cstring);

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCreatfamily();
	CButton m_s1;

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
//	afx_msg void OnBnDropDownRadio3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
//	afx_msg void OnBnClickedInsertwifeinfo1();
	afx_msg void OnBnClickedInsertwifeinfo1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
