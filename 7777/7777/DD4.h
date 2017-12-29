#pragma once

extern CString string;
extern CString ancestorName;  //祖先姓名
extern CString ancestorWifeName;  //祖先姓名
// DD4 对话框

class DD4 : public CDialogEx
{
	DECLARE_DYNAMIC(DD4)

public:
	DD4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DD4();
	void TranStrToArray(char a[],CString cstring);
// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCorrectfamilyinfo();
	CStatic m_picture;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
