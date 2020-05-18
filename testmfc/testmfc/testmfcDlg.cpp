
// testmfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "testmfc.h"
#include "testmfcDlg.h"
#include "afxdialogex.h"
#include<string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtestmfcDlg 对话框




CtestmfcDlg::CtestmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestmfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestmfcDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestmfcDlg 消息处理程序

BOOL CtestmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtestmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
	//显示。
	HCURSOR CtestmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

	/*HWND getMyFindWindowEx(HWND hwndParent, HWND hc,LPCTSTR classname, int index)
	{
		HWND hwnd(0);
		if(hc!=0)
		{
			hwnd = hc;
		}
		do
		{
			hwnd = FindWindowEx(hwndParent, hwnd,"Edit" ,NULL );

			if(hwnd > 0)
			{
				index--;

			}else
			{
				AfxMessageBox("窗口不存在");
				return hwnd;

			}

		} while(index>0);
		return hwnd;
	}
*/
#include <string>
using namespace std;
void CtestmfcDlg::OnBnClickedButton1()
{
	string s = "123";
	// TODO: 在此添加控件通知处理程序代码

	/*CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("%Y%m%d%H%M%S");
	char szTempFile[MAX_PATH] = {0};
	GetTempPath(sizeof(szTempFile), szTempFile);
	strcat(szTempFile, "asia_");
	strcat(szTempFile, strTime);
	strcat(szTempFile, ".tcs");
	AfxMessageBox(szTempFile);*/

	//HWND h = (HWND)0x002614D8;
	//::SendMessage(h,WM_SETTEXT,3,(LPARAM)"123");
	//return;
	/*char *classname = "Edit";
	HWND hwnd = ::FindWindow("#32770","Quick Connect");
	if(hwnd ==NULL )
	{
	AfxMessageBox("窗口不存在");
	return ;
	}
	HWND hWnd = ::FindWindowExA(hwnd, NULL, "#32770", NULL);
	if(hWnd ==NULL )
	{
	AfxMessageBox("窗口不存在");
	return ;
	}
	HWND hc(0);
	HWND h = getMyFindWindowEx(hWnd,hc,classname,1);	
	if(h<=0)
	{
	return ;
	}
	hc = h;
	::SendMessage(h,WM_SETTEXT,11,(LPARAM)"10.1.198.67");
	HWND h1 = getMyFindWindowEx(hWnd,hc,classname,1);
	::SendMessage(h1,WM_SETTEXT,2,(LPARAM)"22");
	hc = h1;
	HWND h2 = getMyFindWindowEx(hWnd,hc,classname,1);
	if(h2<=0)
	{
	return ;
	}
	::SendMessage(h2,WM_SETTEXT,5,(LPARAM)"aiuap");
	HWND hb = ::FindWindowEx(hwnd,0,"Button","Connect");
	::SendMessage(hb,WM_LBUTTONDOWN,0,0);
	::SendMessage(hb,WM_LBUTTONUP,0,0);
	AfxMessageBox("操作成功！！！");*/
	HWND hwnd = ::FindWindow("#32770","Quick Connect");
	hwnd = ::GetWindow(hwnd,GW_CHILD);
	HWND h = ::GetWindow(hwnd,GW_HWNDLAST);//寻找hwnd最后一个兄弟窗口
	h = ::GetWindow(h,GW_HWNDPREV);//寻找h前一个兄弟窗口
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_CHILD);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,11,(LPARAM)"10.1.198.67");
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,2,(LPARAM)"22");
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,5,(LPARAM)"aiuap");
	::SendMessage(h,WM_LBUTTONDOWN,0,0); 
	::SendMessage(h,WM_LBUTTONUP,0,0);	
	AfxMessageBox("操作成功！！！");
}

