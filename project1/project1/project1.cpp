// project1.cpp : 定义应用程序的入口点。
//
/*
#include "stdafx.h"
#include "project1.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPTSTR    lpCmdLine,
int       nCmdShow)
{
UNREFERENCED_PARAMETER(hPrevInstance);
UNREFERENCED_PARAMETER(lpCmdLine);

// TODO: 在此放置代码。
MSG msg;
HACCEL hAccelTable;

// 初始化全局字符串
LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
LoadString(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
MyRegisterClass(hInstance);

// 执行应用程序初始化:
if (!InitInstance (hInstance, nCmdShow))
{
return FALSE;
}

hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT1));

// 主消息循环:
while (GetMessage(&msg, NULL, 0, 0))
{
if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
}

return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
WNDCLASSEX wcex;

wcex.cbSize = sizeof(WNDCLASSEX);

wcex.style			= CS_HREDRAW | CS_VREDRAW;
wcex.lpfnWndProc	= WndProc;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInstance;
wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_PROJECT1);
wcex.lpszClassName	= szWindowClass;
wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
HWND hWnd;

hInst = hInstance; // 将实例句柄存储在全局变量中

hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

if (!hWnd)
{
return FALSE;
}

ShowWindow(hWnd, nCmdShow);
UpdateWindow(hWnd);

return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
int wmId, wmEvent;
PAINTSTRUCT ps;
HDC hdc;

switch (message)
{
case WM_COMMAND:
wmId    = LOWORD(wParam);
wmEvent = HIWORD(wParam);
// 分析菜单选择:
switch (wmId)
{
case IDM_ABOUT:
DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
break;
case IDM_EXIT:
DestroyWindow(hWnd);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
break;
case WM_PAINT:
hdc = BeginPaint(hWnd, &ps);
// TODO: 在此添加任意绘图代码...
EndPaint(hWnd, &ps);
break;
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
UNREFERENCED_PARAMETER(lParam);
switch (message)
{
case WM_INITDIALOG:
return (INT_PTR)TRUE;

case WM_COMMAND:
if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
{
EndDialog(hDlg, LOWORD(wParam));
return (INT_PTR)TRUE;
}
break;
}
return (INT_PTR)FALSE;
}
*/

#include "stdafx.h"
#include<Windows.h>
#include <tchar.h>  
#include "ShellAPI.h"
#include "Resource.h"
#include<iostream>
#include<atltime.h>
#include<string.h>
int APIENTRY WinMain(HINSTANCE hInstance, // 本模块的实例句柄
HINSTANCE hPrevInstance, // Win16 留下的废物，现在已经不用了
LPSTR lpCmdLine, // 命令行参数
int nCmdShow) // 主窗口初始化时的显示方式
{ // 下面这行代码是我添加的，用于弹出一个小对话框
int nSel = MessageBox(NULL, TEXT("Hello, Win32 Application"), TEXT("04Win32AppDemo"), MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3); //MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3
if(nSel == IDYES) // 用户选择了“是”按钮
{
	ShellExecute(0,"open","calc.exe","","",SW_SHOWNORMAL);
	Sleep(5000);
	CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("%Y年%m月%d日%H点%M分%S秒");
	HWND maindHwnd = FindWindow(NULL, "计算器");
	if(!maindHwnd)
	{
		MessageBox(NULL,_T("没有找到该窗口"),_T("提示"),MB_OK);
	}
	SendMessage(maindHwnd,WM_CLOSE,0,0);
	MessageBox(NULL,_T("任务已完成"),strTime,MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3);
}
else if(nSel == IDNO) // 用户选择了“否”按钮
{

} else if(nSel == IDCANCEL) // 用户选择了“取消”按钮
{

}
return 0; 
}




////////////////////////////////////////////////////////////////////

//#define WM_IAWENTRAY    WM_USER+5  //系统托盘的自定义消息  
//
//NOTIFYICONDATA e;
//
//
//LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); 
//int APIENTRY WinMain(HINSTANCE hInstance,    //Win32主函数
//	HINSTANCE hPrevInstance, 
//	LPSTR lpCmdLine, 
//	int nCmdShow) 
//{ 
//	char szClassName[] = "MainWClass"; 
//	WNDCLASSEX wndclass; 
//	// 用描述主窗口的参数填充WNDCLASSEX 结构
//	wndclass.cbSize = sizeof(wndclass); // 结构的大小
//	wndclass.style = CS_HREDRAW|CS_VREDRAW; // 指定如果大小改变就重画
//	wndclass.lpfnWndProc = MainWndProc; // 窗口函数指针
//	wndclass.cbClsExtra = 0; // 没有额外的类内存
//	wndclass.cbWndExtra = 0; // 没有额外的窗口内存
//	wndclass.hInstance = hInstance; // 实例句柄 
//	wndclass.hIcon = ::LoadIcon(NULL, MAKEINTRESOURCE(IDI_PROJECT1)); // 使用预定义图标 MAKEINTRESOURCE(IDI_PROJECT1)
//	wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW); // 使用预定义的光标
//	wndclass.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH); // 使用白色背景画刷
//	wndclass.lpszMenuName = NULL; // 不指定菜单
//	wndclass.lpszClassName = szClassName ; // 窗口类的名称 
//	wndclass.hIconSm = NULL; // 没有类的小图标
//	// 注册这个窗口类
//	::RegisterClassEx(&wndclass); 
//	// 创建主窗口
//	HWND hwnd = ::CreateWindowEx( 
//		0, // dwExStyle，扩展样式 
//		szClassName, // lpClassName，类名 
//		TEXT("输出窗口展示!"), // lpWindowName，标题 
//		WS_OVERLAPPEDWINDOW, // dwStyle，窗口风格 
//		CW_USEDEFAULT, // X，初始 X 坐标 
//		CW_USEDEFAULT, // Y，初始 Y 坐标 
//		CW_USEDEFAULT, // nWidth，宽度 
//		CW_USEDEFAULT, // nHeight，高度 
//		NULL, // hWndParent，父窗口句柄 
//		NULL, // hMenu，菜单句柄 
//		hInstance, // hlnstance，程序实例句柄 
//		NULL) ; // lpParam，用户数据 
//	if(hwnd == NULL) 
//	{ ::MessageBox(NULL, TEXT("创建窗口出错！"), TEXT("error"), MB_OK); 
//	return -1; 
//	} 
//	// 显示窗口，刷新窗口客户区
//	::ShowWindow(hwnd, nCmdShow); 
//	::UpdateWindow(hwnd); 
//	// 从消息队列中取出消息，交给窗口函数处理，直到GetMessage 返回FALSE，结束消息循环
//	MSG msg; 
//
//
//	//初始化NOTIFYICONDATA结构  
//	e.cbSize = sizeof(NOTIFYICONDATA);
//	e.hWnd = hwnd;
//	e.uID = 107;//IDI_GGH;
//	e.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
//	e.uCallbackMessage = WM_IAWENTRAY;
//	e.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
//	//e.hIcon = LoadIcon(g_hInst, (LPCTSTR)(32512));
//	strcpy_s(e.szTip,20,"我太难了！"); //添加的托盘提示符字符串，鼠标放在托盘处会显示提示文字
//	//	_tcscpy(e.szTip, TEXT("TimeWork正在工作！\r\n点击打开主界面")); //_tcscpy是windows宏，需包含头文件tchar.h 
//
//	while(::GetMessage(&msg, NULL, 0, 0)) 
//	{ // 转化键盘消息
//		::TranslateMessage(&msg); 
//		// 将消息发送到相应的窗口函数
//		::DispatchMessage(&msg); 
//	} 
//	// 当 GetMessage 返回FALSE 时程序结束
//	return msg.wParam; 
//} 
//LRESULT CALLBACK MainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) //回调函数
//{
//	char szText[] = "Hello world！";
//	//int cxChar = LOWORD (GetDialogBaseUnits ());    //获得窗口中内定字体字元宽度（低字组）
//	//int cyChar = HIWORD (GetDialogBaseUnits ());    //或得窗口中内定字体字元高度（高字组）
//	switch (message) 
//	{ 
//	case WM_PAINT: // 窗口客户区需要重画
//		{ HDC hdc; 
//		PAINTSTRUCT ps; 
//		// 使无效的客户区变的有效，并取得设备环境句柄
//		hdc = ::BeginPaint (hwnd, &ps) ; 
//		// 显示文字
//		TextOut(hdc, 500, 250, szText, strlen(szText)); 
//		/*TextOut (   hdc, 
//		rect.right / 2 - cxChar * lstrlen ( szText ) / 2,       //使字符串在窗口中水平居中
//		( rect.bottom - cyChar ) / 2,                           //使字符串在窗口中垂直居中
//		szText,                     //字符串的内容
//		lstrlen ( szText )          //lstrlen函数获取字符串的长度
//		) ;*/
//		::EndPaint(hwnd, &ps); 
//		return 0; 
//		} 
//		//case WM_DESTROY: // 正在销毁窗口
//		//	// 向消息队列投递一个WM_QUIT 消息，促使GetMessage 函数返回0，结束消息循环
//		//	::PostQuitMessage(0) ; 
//		//		return 0 ; 
//	case WM_DESTROY:
//		Shell_NotifyIcon(NIM_DELETE, &e);
//		PostQuitMessage(0);
//		return 0;
//	case WM_SYSCOMMAND:
//		switch (wParam)
//		{
//		case SC_CLOSE:
//			DestroyWindow(hwnd);
//			PostQuitMessage(0);
//			break;
//		case SC_MINIMIZE:
//			ShowWindow(hwnd, SW_HIDE);
//			Shell_NotifyIcon(NIM_ADD, &e); //最小化时隐藏窗口并设置系统托盘  
//			break;		
//		}
//		return 0;
//
//	} 
//	// 将我们不处理的消息交给系统做默认处理
//	return ::DefWindowProc(hwnd, message, wParam, lParam); 
//}