#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

class DuiWinWnd  : public WindowImplBase
{
protected:
	
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()
	{
		return _T("makegif.xml");
	}
	virtual LPCTSTR GetWindowClassName(void)const
	{
		return _T("GIFMakeWnd");
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))//对消息拦截
		{
			CDuiString strName = msg.pSender->GetName();
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("最小化"), _T("测试"), IDOK);
			}
			else if (strName == _T("btn_cmd"))
			{
				GenerateGifWithPic();
			}
		}
		else if (msg.sType == _T("itemselectchanged"))
		{
			CComboBoxUI* pComboselect = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
			int iSelect = pComboselect->GetCurSel();
			if (iSelect == 0)
			{
				MessageBox(NULL, _T("选择图片"), _T("测试"), IDOK);
			}
			else
			{
				MessageBox(NULL, _T("选择视频"), _T("测试"), IDOK);
			}
		}
	}

	void SendMessage(CDuiString strCMD)//给cmd发命令
	{
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(strSEInfo));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_SHOW;
		//给命令行发消息
		ShellExecuteEx(&strSEInfo);
		//等命令响应完成
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
		MessageBox(NULL, _T("命令完成"), _T("gif"), IDOK);
	}
	void GenerateGifWithPic()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmppeg\\");
		//构建命令
		CDuiString strCMD;
		
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -r 3 -i ");
		strCMD += strPath;
		strCMD += _T(".\\Pictrue\\%d.ipg ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		//给cmd发送命令
		SendMessage(strCMD);
	}

};

	
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	DuiWinWnd wnd;
	wnd.Create(NULL, _T("makegif"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	wnd.CenterWindow();
	wnd.ShowModal();//启动消息循环
	return 0;
}