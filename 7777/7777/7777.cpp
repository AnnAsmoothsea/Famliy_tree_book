
// 7777.cpp : ����Ӧ�ó��������Ϊ��
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


// CMy7777App ����

CMy7777App::CMy7777App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMy7777App ����

	CMy7777App theApp;
	CString string;  //�༭���ַ���
	CString ss;      //���ҿ��ַ���
	Family T;    //����һ��������
	int x = 0;//�༭����Ϣ��Ӧ�¼�
	CString ancestorName;//����һ���ַ������������������
	CString ancestorWifeName; //����һ���ַ����������������������
	Member wife = NULL;				//�������ӽڵ�
	Member currentNode = NULL;        //��¼��ǰ�ڵ�
	int flag  = 0;   //����һ����־����
	HTREEITEM treeArray[500];  //����һ�����ڵ������������ѽ��������ڵ�
	int tcount = 0;
	char historyName[100];		//��¼��ʷ����
	Member child = NULL;     //���庢�ӽڵ�
	int specailflag = -1;
	int reactFlag = 0;
	int selectx = -1;

// CMy7777App ��ʼ��

BOOL CMy7777App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMy7777Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}



	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

