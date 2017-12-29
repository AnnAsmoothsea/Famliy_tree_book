#pragma once
#include "TreeDefined.h"

// CC1 对话框
extern int flag;   //定义一个标志变量
extern Family T;   //家族树
extern int specailflag;
extern int reactFlag;
extern CString string;
extern CString ss;

class CC1 : public CDialogEx
{
	DECLARE_DYNAMIC(CC1)

public:
	CC1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CC1();

// 对话框数据
	enum { IDD = IDD_CorrectFamilInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
