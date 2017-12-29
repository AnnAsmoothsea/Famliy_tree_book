#pragma once
#include "TreeDefined.h"

extern int flag;   //定义一个标志变量
// DD3 对话框
extern Member currentNode;    //当前节点信息
extern Family T;             //家族树
extern  CString string ;     //全局变量输出提示信息；
extern CString ss;			 //查找框输出信息
extern CString ancestorName;
extern int specailflag;
extern int reactFlag;

class DD3 : public CDialogEx
{
	DECLARE_DYNAMIC(DD3)

public:
	DD3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DD3();
	void TranStrToArray(char a[],CString cstring);
// 对话框数据
	enum { IDD = IDD_DIALOG1 };
	Member SearchFamily(Member t,char key[]);//  家族树查找节点
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
