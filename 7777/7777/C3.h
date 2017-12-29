#pragma once
#include "TreeDefined.h"

// CC3 对话框
extern int flag;   //定义一个标志变量
extern Member child; //孩子节点
extern Member currentNode; //孩子节点
extern Family T;  //定义家族树
extern int selectx;   //选择标志
extern CString string;
extern CString ss;
extern int specailflag;
extern int reactFlag;


class CC3 : public CDialogEx
{
	DECLARE_DYNAMIC(CC3)

public:
	CC3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CC3();


	Member SearchFamily(Member t,char key[]);														//函数七：根据关键字查找成员节点（一般为名字）

// 对话框数据
	enum { IDD = IDD_InsertMemChild };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedInsertwifeinfo4();
	afx_msg void OnBnClickedRadioc4();
	afx_msg void OnBnClickedRadioc3();
	afx_msg void OnBnClickedRadioc6();
	afx_msg void OnBnClickedRadioc5();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedInsertwifeinfo5();
};
