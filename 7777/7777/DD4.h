#pragma once

extern CString string;
extern CString ancestorName;  //��������
extern CString ancestorWifeName;  //��������
// DD4 �Ի���

class DD4 : public CDialogEx
{
	DECLARE_DYNAMIC(DD4)

public:
	DD4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DD4();
	void TranStrToArray(char a[],CString cstring);
// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCorrectfamilyinfo();
	CStatic m_picture;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
