#pragma once
#include "TreeDefined.h"

// CC1 �Ի���
extern int flag;   //����һ����־����
extern Family T;   //������
extern int specailflag;
extern int reactFlag;
extern CString string;
extern CString ss;

class CC1 : public CDialogEx
{
	DECLARE_DYNAMIC(CC1)

public:
	CC1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CC1();

// �Ի�������
	enum { IDD = IDD_CorrectFamilInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
