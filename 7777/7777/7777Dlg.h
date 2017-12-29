
// 7777Dlg.h : ͷ�ļ�
//

#pragma once


#include "DD1.h"
#include "DD2.h"
#include "DD3.h"
#include "DD4.h"
#include "C1.h"
#include "C3.h"
#include "C4.h"
#include "TreeDefined.h"


extern int x;
extern CString ancestorName;//��������
extern Member currentNode;        //��¼��ǰ�ڵ�
extern HTREEITEM treeArray[500];    //ȫ�����鱣��HTREEITEM�ڵ�
extern int tcount;                  //��¼���нڵ������
extern Member child;
extern int specailflag;				//ȫ�ֹ��ܱ�����־

extern char historyName[100];  //��¼��ʷ����
// CMy7777Dlg �Ի���
class CMy7777Dlg : public CDialogEx
{
// ����
public:
	CMy7777Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY7777_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	DD1 d1;
	DD2 d2;
	DD3 d3;
	DD4 d4;

	CC1 c1;
	CC3 c3;
	CC4 c4;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg LRESULT Onadd_event_ok(WPARAM wParam, LPARAM lParam);

	void ShowfamilyInfo();//��d4����ʾ��ͥ��Ϣ 
	void ShowMemberInfo();  //��ʾ��Ա������Ϣ
	Member SearchFamily(Member t,char key[]);
	void TravelAll(HTREEITEM ht);  //�����������ڵ�
	void DeleteTreeCtrl(HTREEITEM hItem);		  //ɾ��treecontrol�����ڵ�
	HTREEITEM TreeVisit(HTREEITEM hItem,char key[]); 
	void ExpandTree(HTREEITEM hItem);		//չ���������нڵ�
	int DeleteMember(Member m);
	int SaveFamilyFile(Family T,char savepath[100]);		//����


public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnEnChangeFamiliinfo();
	afx_msg void OnBnClickedButton1();
	
	CTreeCtrl m_treeShow;   //tree control��������
	CImageList m_imageList;
	HICON hIcon[3];      // ͼ��������   
    HTREEITEM hRoot;     // ���ĸ��ڵ�ľ��   
    HTREEITEM hChildItem; // �ɱ�ʾ��һ����ڵ�ľ��   
	CMenu m_Menu;
	CBrush m_brush;




//	Family T;   //������
//	afx_msg void OnEnChangeFamiliinfo();
//	afx_msg void OnEnChangeSearch();
	afx_msg void OnNMClickFamilytree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSingleExpandFamilytree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedFamilytree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeSearch();
	afx_msg void OnBnClickedButton2();
	afx_msg void On32771();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32776();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void On32780();
	afx_msg void On32782();
};
