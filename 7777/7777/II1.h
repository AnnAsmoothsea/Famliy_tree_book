#pragma once
#include "TreeDefined.h"

// II1 dialog
extern Member wife;
extern int flag;   //定义一个标志变量
class II1 : public CDialogEx
{
	DECLARE_DYNAMIC(II1)

public:
	II1(CWnd* pParent = NULL);   // standard constructor
	virtual ~II1();

// Dialog Data
	enum { IDD = IDD_Insert };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadiox2();
	afx_msg void OnBnClickedRadiox1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
