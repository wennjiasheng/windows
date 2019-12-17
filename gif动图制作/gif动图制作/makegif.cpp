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
		}
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