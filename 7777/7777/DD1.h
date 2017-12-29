#pragma once
#include "C4.h"

// DD1 对话框
extern int flag;   //定义一个标志变量
extern int selectx;   //选择标志
extern CString ancestorName;  //祖先姓名
extern int specailflag;
extern int reactFlag;
extern Family T;
extern char historyName[100];  //记录历史名字
class DD1 : public CDialogEx
{
	DECLARE_DYNAMIC(DD1)

public:
	DD1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DD1();
	void TranStrToArray(char a[],CString cstring);
	Member SearchFamily(Member t,char key[]);
	void ShowMemberInfo();  //显示成员个人信息
	int DeleteMember(Member m);	//函数四：删除家族成员
// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton12();
//	afx_msg void OnBnClickedRadio3();
//	afx_msg void OnBnClickedButton6();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRadiom1();
	afx_msg void OnBnClickedRadiom2();
	afx_msg void OnBnClickedRadiom5();
};
