#pragma once
#include "TreeDefined.h"

// CC3 �Ի���
extern int flag;   //����һ����־����
extern Member child; //���ӽڵ�
extern Member currentNode; //���ӽڵ�
extern Family T;  //���������
extern int selectx;   //ѡ���־
extern CString string;
extern CString ss;
extern int specailflag;
extern int reactFlag;


class CC3 : public CDialogEx
{
	DECLARE_DYNAMIC(CC3)

public:
	CC3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CC3();


	Member SearchFamily(Member t,char key[]);														//�����ߣ����ݹؼ��ֲ��ҳ�Ա�ڵ㣨һ��Ϊ���֣�

// �Ի�������
	enum { IDD = IDD_InsertMemChild };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
