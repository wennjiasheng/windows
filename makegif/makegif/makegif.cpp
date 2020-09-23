#include"UIlib.h"
using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

#include<fstream>
class DuiWinWnd : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}
	//获取xml文件
	virtual CDuiString GetSkinFile()
	{
		return _T("gifMake.xml");
	}
	//设置窗口类名字
	virtual LPCTSTR GetWindowClassName(void) const
	{
		return _T("GIFMakeWnd");
	}
	//重新定义消息响应
	virtual void Notify(TNotifyUI& msg)
	{
		CDuiString strName = msg.pSender->GetName();
		if (msg.sType == _T("click"))
		{
			if (strName == _T("close"))
			{
				Close();
			}
			else if (strName == _T("small"))
			{
				MessageBox(NULL, _T("text"), _T("测试"), IDOK);
			}
			else if (strName == _T("Button1"))
			{
				LoadFile();
			}
			else if (strName == _T("生成2"))
			{
				GenerateGifWithPic();
			}
			else if (strName == _T("截取"))
			{
				CutView();
			}
			else if (strName == _T("提取1"))
			{
				GetSRTFile();
				LoadSRT();
			}
			else if (strName == _T("Button4"))
			{
				CListUI *pEdit = (CListUI*)m_PaintManager.FindControl(_T("edit_word"));
				CDuiString strWord = pEdit->GetText();
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());
				pListItemp->SetText(1, strWord);
			}
			else if (strName == _T("写入"))
			{
				WriteSRT();
			}
			else if (strName == _T("提取2"))
			{
				GenerateView();
			}
			else if (strName == _T("烧录"))
			{
				BornSRT2View();
			}
			else if (strName == _T("生成1"))
			{
				GenerateGifWithView();
			}
		}
		else if (msg.sType == _T("itemselect"))
		{
			if (strName == _T("List1"))
			{
				//获取list的空间
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
				//获取当前list被选中的一行
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());
				//将list种所选择的行增加到edit中
				CListUI *pEdit = (CListUI*)m_PaintManager.FindControl(_T("edit_word"));
				pEdit->SetText(pListItemp->GetText(1));
			}
			if (strName == _T("Combo1"))
			{
				//根据CComboBox控件的name拿到改控件
				CComboBoxUI* pComboUI = (CComboBoxUI*)m_PaintManager.FindControl(_T("Combo1"));
				//选择图片方式生成
				if (0 == pComboUI->GetCurSel())
				{
					((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("提取1")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("写入")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("提取2")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("烧录")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button2")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button3")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("截取")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_word")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button4")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("生成1")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("生成2")))->SetEnabled(true);
				}
				//选择视频方式生成
				else
				{
					((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("提取1")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("写入")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("提取2")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("烧录")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button2")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button3")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("截取")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_word")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button4")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("生成1")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("生成2")))->SetEnabled(false);
				}
			}
		}
	}

	void SendMessage(CDuiString strCMD)
	{
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd.exe");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE;

		ShellExecuteEx(&strSEInfo);

		WaitForSingleObject(strSEInfo.hProcess, INFINITE);

		MessageBox(NULL, _T("text"), _T("测试"), IDOK);
	}
	//图片生成动态图
	void GenerateGifWithPic()
	{
		//ffmpeg -r 3 -i .\Pictrue\%d.jpg output.gif -y
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		//构造命令
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -r 3 -i ");
		strCMD += strPath;
		strCMD += _T("Pictrue\\%d.jpg ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		//发命令
		SendMessage(strCMD);

	}
	//截取视频
	//例如给cmd发送ffmpeg -i input.mkv -vcodec copy -acodec copy -ss 00:40:07 -to 00:40:28 11.mkv -y
	void CutView()
	{
		//构造命令
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("Edit1")))->GetText();

		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		if (!strViewPath.IsEmpty())
		{
			strCMD += strViewPath;
		}
		else
		{
			strCMD += strPath;
			strCMD += _T("input.mkv");
		}
		strCMD += _T(" -vcodec copy -acodec copy -ss ");
		strCMD += _T(" ");
		//获取起始时间和结尾时间
		CDuiString strStartTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->GetText();
		if (!(IsTimeTrue(strStartTime)))
		{
			MessageBox(NULL, _T("起始时间错误"), _T("错误"), IDOK);
			return;
		}
		CDuiString strEndTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->GetText();
		if (!(IsTimeTrue(strEndTime)))
		{
			MessageBox(NULL, _T("结束时间错误"), _T("错误"), IDOK);
		}
		strCMD += strStartTime;
		strCMD += _T(" -to ");
		strCMD += strEndTime;
		strCMD += _T(" ");
		strCMD += strPath;
		strCMD += _T("11.mkv -y");
		//执行命令
		SendMessage(strCMD);
	}
	//提取字幕流文件
	void GetSRTFile()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("11.mkv ");
		strCMD += strPath;
		strCMD += _T("11.srt -y");

		SendMessage(strCMD);
	}
	// 
	void LoadFile()
	{
		OPENFILENAME ofn;
		memset(&ofn, 0, sizeof(OPENFILENAME));
		TCHAR strPath[MAX_PATH] = {0};
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFile = strPath;
		ofn.nMaxFile = sizeof(strPath);
		ofn.lpstrFilter = _T("All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0\0");
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn))
		{
			((CEditUI*)m_PaintManager.FindControl(_T("Edit1")))->SetText(strPath);
		}
	}
	//加载srt字幕文件加载到界面list控件
	void LoadSRT()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\11.srt");
		std::ifstream fIn(strPath.GetData());

		char strSRTCon[512] = { 0 };
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
		//把list控件里之前的内容清空
		pList->RemoveAll();
		while (!fIn.eof())
		{
			//读取序号
			fIn.getline(strSRTCon, 512);

			CListTextElementUI* pListItem = new CListTextElementUI;
			pList->Add(pListItem);
			//读取时间轴
			fIn.getline(strSRTCon, 512);
			pListItem->SetText(0, UTF8ToUnicode(strSRTCon));
			//读取字幕
			fIn.getline(strSRTCon, 512);
			pListItem->SetText(1, UTF8ToUnicode(strSRTCon));
			//读取空行
			fIn.getline(strSRTCon, 512);
		}

		fIn.close();
	}

	void WriteSRT()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\11.srt");
		std::ofstream fOut(strPath.GetData());

		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
		int szCount = pList->GetCount();
		for (int i = 0; i < szCount; ++i)
		{
			CListTextElementUI* pListItem = (CListTextElementUI*)pList->GetItemAt(i);
			//序号
			CDuiString strNo;
			strNo.Format(_T("%d"), i + 1);
	
			//时间轴
			CDuiString strTime = pListItem->GetText(0);
			//内容
			CDuiString strWord = pListItem->GetText(1);
			//写回
			//写行号
			string strNewLine = Unicode2ANSI(_T("\n"));
			string itemNo = Unicode2ANSI(strNo);
			fOut.write(itemNo.c_str(), itemNo.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//写时间轴
			string itemTime = Unicode2ANSI(strTime);
			fOut.write(itemTime.c_str(), itemTime.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//写文本
			string itemWord = Unicode2ANSI(strWord);
			fOut.write(itemWord.c_str(), itemWord.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//写空行
			fOut.write(strNewLine.c_str(), strNewLine.size());
		}
		fOut.close();
	}
	//从截取的小段视频中抽离视频流
	void GenerateView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("11.mkv -vcodec copy -an -sn ");
		strCMD += strPath;
		strCMD += _T("22.mkv -y");
		SendMessage(strCMD);
	}
	//烧录 将修改后的SRT字幕与视频烧录成一个整体
	void BornSRT2View()
	{
		CDuiString strCMD1;
		strCMD1 += _T("/c cd ");
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg ");
		strCMD1 += strPath;
		CDuiString strCMD2;
		strCMD2 += _T("& ffmpeg -i 22.mkv -vf subtitles=11.srt 33.mkv -y");
		strCMD1 += strCMD2;
		SendMessage(strCMD1);
	}
	//视频生产动态图
	void GenerateGifWithView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("33.mkv -vf scale=iw/2:ih/2 -f gif ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		SendMessage(strCMD);
	}

	CDuiString UTF8ToUnicode(const char* str)
	{
		int szLen = ::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), NULL, 0);
		wchar_t* pContent = new wchar_t[szLen + 1];
		::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), pContent, szLen);
		pContent[szLen] = '\0';
		CDuiString s(pContent);
		delete[] pContent;
		return s;
	}
	string Unicode2ANSI(CDuiString str)
	{
		int szLen = ::WideCharToMultiByte(CP_ACP, 0, str.GetData(), -1, NULL, 0, NULL, FALSE);
		char* pBuff = new char[szLen + 1];
		::WideCharToMultiByte(CP_ACP, 0, str.GetData(), -1, pBuff, szLen, NULL, FALSE);
		pBuff[szLen] = '\0';
		string s(pBuff);
		delete[] pBuff;
		return s;
	}

	bool IsTimeTrue(CDuiString strTime)
	{
		//00:00:00
		if (strTime.GetLength() != 8)
		{
			return false;
		}
		for (int i = 0; i < strTime.GetLength(); i++)
		{
			if (strTime[i] == ':')
				continue;
			if (!(strTime[i] >= '0' && strTime[i] <= '9'))
				return false;
		}
		return true;
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	DuiWinWnd wnd;

	wnd.Create(NULL, _T("MakeGif"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	wnd.CenterWindow();
	wnd.ShowModal();
	return 0;
}
//#include"UIlib.h"
//using namespace DuiLib;
//
//#pragma comment(lib,"DuiLib_ud.lib")
//
//class DuiWinWnd  : public WindowImplBase
//{
//protected:
//	virtual CDuiString GetSkinFolder()
//	{
//		return _T("");
//	}
//	virtual CDuiString GetSkinFile()
//	{
//		return _T("gifMake.xml");
//	}
//	virtual LPCTSTR GetWindowClassName(void)const
//	{
//		return _T("GIFMakeWnd");
//	}
//	//重写消息响应
//	virtual void Notify(TNotifyUI& msg)
//	{
//		//单击消息
//		if (msg.sType == _T("click"))//对消息拦截
//		{
//			CDuiString strName = msg.pSender->GetName();
//			if (strName == _T("close"))
//			{
//				Close();
//			}
//			else if (strName == _T("small"))
//			{
//				MessageBox(NULL, _T("最小化"), _T("测试"), IDOK);
//			}
//			else if (strName == _T("btn_cmd"))
//			{
//				GenerateGifWithPic();
//			}
//		}
//		//选择ComboBox控件类型消息
//		else if (msg.sType == _T("itemselect"))
//		{
//			//根据名字获取控件
//			CComboBoxUI* pComboselect = (CComboBoxUI*)m_PaintManager.FindControl(_T("Combo1"));
//			int iSelect = pComboselect->GetCurSel();
//			if (iSelect == 0)
//			{
//				MessageBox(NULL, _T("选择图片"), _T("测试"), IDOK);
//			}
//			else
//			{
//				MessageBox(NULL, _T("选择视频"), _T("测试"), IDOK);
//			}
//		}
//	}
//
//	void SendMessage(CDuiString strCMD)//给cmd发命令
//	{
//		SHELLEXECUTEINFO strSEInfo;
//		memset(&strSEInfo, 0, sizeof(strSEInfo));
//		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
//		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
//		strSEInfo.lpFile = _T("C:\\WINDOWS\\system32\\cmd.exe");
//		strSEInfo.lpParameters = strCMD;
//		strSEInfo.nShow = SW_SHOW;
//		//给命令行发消息
//
//		ShellExecuteEx(&strSEInfo);
//		//等命令响应完成
//		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
//		MessageBox(NULL, _T("命令完成"), _T("gif"), IDOK);
//	}
//	void GenerateGifWithPic()
//	{
//		CDuiString strPath = CPaintManagerUI::GetInstancePath();
//		strPath += _T("\\ffmppeg\\");
//		//构建命令
//		CDuiString strCMD;
//		
//		strCMD += _T("/c ");
//		strCMD += strPath;
//		strCMD += _T("ffmpeg -r 3 -i ");
//		strCMD += strPath;
//		strCMD += _T(".\\Pictrue\\%d.ipg ");
//		strCMD += strPath;
//		strCMD += _T("output.gif -y");
//		//给cmd发送命令
//		SendMessage(strCMD);
//	}
//
//};
//
//	
//int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
//	nCmdShow)
//{
//	CPaintManagerUI::SetInstance(hInstance);
//	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
//	DuiWinWnd wnd;
//	wnd.Create(NULL, _T("makegif"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
//	wnd.CenterWindow();
//	wnd.ShowModal();//启动消息循环
//	return 0;
//}