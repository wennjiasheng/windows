// test练习.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <windows.h>
#include<stdio.h>
#include<iostream>
#include<atltime.h>
#include<string.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//WinExec("C:\\Program Files (x86)\\Tencent\\WeChat\\WeChat.exe",SW_SHOW);//运行微信
	/*LRESULT CLogCleanToolDlg::OnTrayIcon(WPARAM wParam, LPARAM lParam)
	{
		if(lParam == WM_LBUTTONDBLCLK) //双击托盘图标
		{
			Shell_NotifyIcon(NIM_DELETE,&m_nfData);
			ShowWindow(SW_SHOWNORMAL);
			SetForegroundWindow();
		}
		return 0;
	}*/
	/*NOTIFYICONDATA nid;
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);  
	nid.hWnd=NULL;  
	nid.uID=10086;  
	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP|NIF_INFO;  
	nid.uCallbackMessage=0;//自定义的消息名称,注意:这里的消息是用户自定义消息  
	//nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));  
	_tcscpy(nid.szTip,_T("亚信客户端"));//信息提示条为"计划任务提醒"  
	_tcscpy(nid.szInfo,_T("正在填入"));  
	_tcscpy(nid.szInfoTitle,_T("亚信客户端"));  
	nid.dwInfoFlags=NIIF_INFO;  
	nid.uTimeout=50000;
	Shell_NotifyIcon(NIM_DELETE,&nid);//在托盘区添加图标 
*//*
	NOTIFYICONDATA m_nfdata;
	m_nfdata.hWnd=NULL;  
	m_nfdata.uID=10086;  
	Shell_NotifyIcon(NIM_DELETE,&m_nfdata);
	*/
	  /*UpdateWindow(hWnd);
	 
	  //
	  //蔡军生 2007/07/14
	  //显示窗体測试。
	  MessageBox(NULL,_T("最大化"),_T("測试"),MB_OK);
	 
	  //显示窗体为最大化。
	  ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	 
	  
	  MessageBox(NULL,_T("原来位置"),_T("測试"),MB_OK);
	 
	  //显示窗体为原来位置。
	  ShowWindow(hWnd, SW_SHOWNORMAL);
	  */
	//HWND handle = FindWindow(NULL,"计算器");
	//SendMessage(handle,WM_CLOSE,0,0);



	/////////////////////////  获取时间 //////////////////


	//CString strTime;
	//CTime tTime = CTime::GetCurrentTime();
	//strTime = tTime.Format("%Y年%m月%d日%H点%M分%S秒");
	//MessageBox(NULL, strTime, TEXT("时间"), MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3); //MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3
	//
	
	
/////////	SendMessage  发送消息///////////////


	//HWND maindHwnd = FindWindow(NULL, "计算器");
	//if(!maindHwnd)
	//{
	//	MessageBox(NULL,_T("没有找到该窗口"),_T("提示"),MB_OK);
	//}
	//MessageBox(NULL,_T("任务已完成"),_T("提示"),MB_OK);
	//SendMessage(maindHwnd,WM_CLOSE,0,0);
	/*HWND wnd=FindWindow(NULL,"无标题.txt - 记事本");
	SendMessage(wnd,WM_CLOSE,0,0);*/
	/*ShellExecute(0,"open","calc.exe","","",SW_SHOWNORMAL);
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
	
	MessageBox(NULL,_T("任务已完成"),strTime,MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3);*/
	/*POINT curpos;
	while(1)
	{

		GetCursorPos(&curpos);
		printf("x:%d,y:%d",curpos.x,curpos.y);
		Sleep(1000);
		printf("\n");
	}*/
	
	return 0;
}