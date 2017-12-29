#pragma once


#include "TreeDefined.h"
#include "7777.h"
#include "DD1.h"
#include "DD3.h"
#include "DD4.h"

extern CString string; //编辑框字符串
extern CString ss; //查找框字符串
extern Family T;  //家庭树
extern int x;    //父窗口文本框响应控制
extern CString ancestorName;  //祖先姓名
extern int flag;   //定义一个标志变量

//extern Family T;
// DD2 对话框

class DD2 : public CDialogEx
{
	DECLARE_DYNAMIC(DD2)

public:
	DD2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DD2();
	void TranStrToArray(char a[],CString cstring);

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
