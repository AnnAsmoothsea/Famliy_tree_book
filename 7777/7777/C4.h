#pragma once
#include "TreeDefined.h"

// CC4 �Ի���
extern int flag;   //����һ����־����
extern int specailflag;
extern int reactFlag;
extern Member currentNode;  // ��ǰ�ڵ�
extern Family T;
class CC4 : public CDialogEx
{
	DECLARE_DYNAMIC(CC4)

public:
	CC4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CC4();
	void ShowMemberInfo();

// �Ի�������
	enum { IDD = IDD_CorrectMemInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsertwifeinfo5();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio3();
};
