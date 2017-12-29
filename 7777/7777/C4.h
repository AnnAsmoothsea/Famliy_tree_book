#pragma once
#include "TreeDefined.h"

// CC4 对话框
extern int flag;   //定义一个标志变量
extern int specailflag;
extern int reactFlag;
extern Member currentNode;  // 当前节点
extern Family T;
class CC4 : public CDialogEx
{
	DECLARE_DYNAMIC(CC4)

public:
	CC4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CC4();
	void ShowMemberInfo();

// 对话框数据
	enum { IDD = IDD_CorrectMemInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
