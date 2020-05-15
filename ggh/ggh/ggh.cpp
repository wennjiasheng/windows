// ggh.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ggh.h"
//
//#define MAX_LOADSTRING 100
//
//// 全局变量:
//HINSTANCE hInst;								// 当前实例
//TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
//TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
//
//// 此代码模块中包含的函数的前向声明:
//ATOM				MyRegisterClass(HINSTANCE hInstance);
//BOOL				InitInstance(HINSTANCE, int);
//LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY _tWinMain(HINSTANCE hInstance,
//                     HINSTANCE hPrevInstance,
//                     LPTSTR    lpCmdLine,
//                     int       nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//
// 	// TODO: 在此放置代码。
//	MSG msg;
//	HACCEL hAccelTable;
//
//	// 初始化全局字符串
//	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//	LoadString(hInstance, IDC_GGH, szWindowClass, MAX_LOADSTRING);
//	MyRegisterClass(hInstance);
//
//	// 执行应用程序初始化:
//	if (!InitInstance (hInstance, nCmdShow))
//	{
//		return FALSE;
//	}
//
//	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GGH));
//
//	// 主消息循环:
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return (int) msg.wParam;
//}
//
//
//
////
////  函数: MyRegisterClass()
////
////  目的: 注册窗口类。
////
////  注释:
////
////    仅当希望
////    此代码与添加到 Windows 95 中的“RegisterClassEx”
////    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
////    这样应用程序就可以获得关联的
////    “格式正确的”小图标。
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEX wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style			= CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc	= WndProc;
//	wcex.cbClsExtra		= 0;
//	wcex.cbWndExtra		= 0;
//	wcex.hInstance		= hInstance;
//	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GGH));
//	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
//	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
//	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GGH);
//	wcex.lpszClassName	= szWindowClass;
//	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	return RegisterClassEx(&wcex);
//}
//
////
////   函数: InitInstance(HINSTANCE, int)
////
////   目的: 保存实例句柄并创建主窗口
////
////   注释:
////
////        在此函数中，我们在全局变量中保存实例句柄并
////        创建和显示主程序窗口。
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   HWND hWnd;
//
//   hInst = hInstance; // 将实例句柄存储在全局变量中
//
//   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
//
//   if (!hWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}
//
////
////  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  目的: 处理主窗口的消息。
////
////  WM_COMMAND	- 处理应用程序菜单
////  WM_PAINT	- 绘制主窗口
////  WM_DESTROY	- 发送退出消息并返回
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	int wmId, wmEvent;
//	PAINTSTRUCT ps;
//	HDC hdc;
//
//	switch (message)
//	{
//	case WM_COMMAND:
//		wmId    = LOWORD(wParam);
//		wmEvent = HIWORD(wParam);
//		// 分析菜单选择:
//		switch (wmId)
//		{
//		case IDM_ABOUT:
//			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//			break;
//		case IDM_EXIT:
//			DestroyWindow(hWnd);
//			break;
//		default:
//			return DefWindowProc(hWnd, message, wParam, lParam);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		// TODO: 在此添加任意绘图代码...
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//
//// “关于”框的消息处理程序。
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		return (INT_PTR)TRUE;
//
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//			return (INT_PTR)TRUE;
//		}
//		break;
//	}
//	return (INT_PTR)FALSE;
//}


#include <windows.h>  
#include <tchar.h>  
#include "ShellAPI.h"  
//#include "resource1.h"  
#include <string.h>

#define WM_IAWENTRAY    WM_USER+5  //系统托盘的自定义消息  

//定义全局变量  
HINSTANCE g_hInst;
NOTIFYICONDATA e;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	g_hInst = hInstance; //获取该程序实例句柄  

	static TCHAR szAppName[] = TEXT("TimeWork");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	WNDCLASS wc;
	 wc.style = CS_HREDRAW | CS_VREDRAW;
	 wc.lpfnWndProc = WndProc;
	 wc.cbClsExtra = 0;
	 wc.cbWndExtra = 0;
	 wc.hInstance = hInstance;
	 wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	 wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	 wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	 wc.lpszMenuName = "MainMenu";
	 wc.lpszClassName = "MainWindowClass";
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,                  // window class name  
		TEXT("托盘程序"), // window caption  
		WS_OVERLAPPEDWINDOW,        // window style  
		CW_USEDEFAULT,              // initial x position  
		CW_USEDEFAULT,              // initial y position  
		CW_USEDEFAULT,              // initial x size  
		CW_USEDEFAULT,              // initial y size  
		NULL,                       // parent window handle  
		NULL,                       // window menu handle  
		hInstance,                  // program instance handle  
		NULL);                     // creation parameters  

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//初始化NOTIFYICONDATA结构  
	e.cbSize = sizeof(NOTIFYICONDATA);
	e.hWnd = hwnd;
	e.uID = 107;//IDI_GGH;
	e.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	e.uCallbackMessage = WM_IAWENTRAY;
	e.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_GGH));
	//e.hIcon = LoadIcon(g_hInst, (LPCTSTR)(32512));
	strcpy_s(e.szTip,20,"我太难了！"); //添加的托盘提示符字符串，鼠标放在托盘处会显示提示文字
	//	_tcscpy(e.szTip, TEXT("TimeWork正在工作！\r\n点击打开主界面")); //_tcscpy是windows宏，需包含头文件tchar.h  

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;

	switch (message)
	{
	case WM_CREATE:
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hello, my fridents！"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_IAWENTRAY:
		if (wParam == IDI_GGH) {
			if (lParam == WM_LBUTTONDOWN) {
				//还可以在这个地方加入一个菜单，鼠标右键单击时显示  
				ShowWindow(hwnd, SW_SHOWNORMAL);
				return TRUE;
			}
		}
		return FALSE;
	case WM_SYSCOMMAND:
		switch (wParam)
		{
		case SC_CLOSE:
			DestroyWindow(hwnd);
			PostQuitMessage(0);
			break;
		case SC_MINIMIZE:
			ShowWindow(hwnd, SW_HIDE);
			Shell_NotifyIcon(NIM_ADD, &e); //最小化时隐藏窗口并设置系统托盘  
			break;
		}
		return 0;

	case WM_DESTROY:
		Shell_NotifyIcon(NIM_DELETE, &e);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam); 

}
