
// 7777Dlg.h : 头文件
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
extern CString ancestorName;//祖先姓名
extern Member currentNode;        //记录当前节点
extern HTREEITEM treeArray[500];    //全局数组保存HTREEITEM节点
extern int tcount;                  //记录树中节点的数量
extern Member child;
extern int specailflag;				//全局功能变量标志

extern char historyName[100];  //记录历史名字
// CMy7777Dlg 对话框
class CMy7777Dlg : public CDialogEx
{
// 构造
public:
	CMy7777Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY7777_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	DD1 d1;
	DD2 d2;
	DD3 d3;
	DD4 d4;

	CC1 c1;
	CC3 c3;
	CC4 c4;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg LRESULT Onadd_event_ok(WPARAM wParam, LPARAM lParam);

	void ShowfamilyInfo();//在d4框显示家庭信息 
	void ShowMemberInfo();  //显示成员个人信息
	Member SearchFamily(Member t,char key[]);
	void TravelAll(HTREEITEM ht);  //遍历所有树节点
	void DeleteTreeCtrl(HTREEITEM hItem);		  //删除treecontrol的树节点
	HTREEITEM TreeVisit(HTREEITEM hItem,char key[]); 
	void ExpandTree(HTREEITEM hItem);		//展开树的所有节点
	int DeleteMember(Member m);
	int SaveFamilyFile(Family T,char savepath[100]);		//保存


public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnEnChangeFamiliinfo();
	afx_msg void OnBnClickedButton1();
	
	CTreeCtrl m_treeShow;   //tree control关联变量
	CImageList m_imageList;
	HICON hIcon[3];      // 图标句柄数组   
    HTREEITEM hRoot;     // 树的根节点的句柄   
    HTREEITEM hChildItem; // 可表示任一分类节点的句柄   
	CMenu m_Menu;
	CBrush m_brush;




//	Family T;   //家族树
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
