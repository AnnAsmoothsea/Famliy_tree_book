
// 7777.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "7777.h"
#include "7777Dlg.h"

#include "TreeDefined.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMy7777App

BEGIN_MESSAGE_MAP(CMy7777App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMy7777App 构造

CMy7777App::CMy7777App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMy7777App 对象

	CMy7777App theApp;
	CString string;  //编辑框字符串
	CString ss;      //查找框字符串
	Family T;    //定义一个家族树
	int x = 0;//编辑框消息响应事件
	CString ancestorName;//定义一个字符串数组接受祖先姓名
	CString ancestorWifeName; //定义一个字符串数组接受祖先妻子姓名
	Member wife = NULL;				//定义妻子节点
	Member currentNode = NULL;        //记录当前节点
	int flag  = 0;   //定义一个标志变量
	HTREEITEM treeArray[500];  //定义一个树节点数组来保存已建立的树节点
	int tcount = 0;
	char historyName[100];		//记录历史名字
	Member child = NULL;     //定义孩子节点
	int specailflag = -1;
	int reactFlag = 0;
	int selectx = -1;

// CMy7777App 初始化

BOOL CMy7777App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMy7777Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}



	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

