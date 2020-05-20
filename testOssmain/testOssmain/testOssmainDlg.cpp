
// testOssmainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "testOssmain.h"
#include "testOssmainDlg.h"
#include "afxdialogex.h"

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


// CtestOssmainDlg 对话框




CtestOssmainDlg::CtestOssmainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestOssmainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestOssmainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestOssmainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestOssmainDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestOssmainDlg 消息处理程序

BOOL CtestOssmainDlg::OnInitDialog()
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

void CtestOssmainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestOssmainDlg::OnPaint()
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
HCURSOR CtestOssmainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "tinyxml2.h"
#include<stdio.h>
#include<Windows.h>

//#define _stat _stat64i32
using namespace std;
#include <userenv.h>
#pragma comment(lib,"userenv.lib") 


const char* dbeaver_tmpl = "<data-source id =\"%s\" provider=\"generic\" driver=\"vertica\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
						   <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
						   <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
						   <property name = \"socks-host\" value=\"\"/> \
						   <property name = \"socks-port\" value=\"1080\"/> \
						   </network-handler> \
						   <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
						   <property name = \"port\" value=\"22\"/> \
						   <property name = \"host\" value=\"\"/> \
						   <property name = \"keyPath\" value=\"\"/> \
						   <property name = \"authType\" value=\"PASSWORD\"/> \
						   </network-handler> \
						   </connection> \
						   <custom-property name = \"default.activeObject\" value=\"\"/> \
						   </data-source>";
const char* dbeaver_tmp_postgresql = "<data-source id =\"%s\" provider=\"generic\" driver=\"postgresql\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
									 <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
									 <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
									 <property name = \"socks-host\" value=\"\"/> \
									 <property name = \"socks-port\" value=\"1080\"/> \
									 </network-handler> \
									 <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
									 <property name = \"port\" value=\"22\"/> \
									 <property name = \"host\" value=\"\"/> \
									 <property name = \"keyPath\" value=\"\"/> \
									 <property name = \"authType\" value=\"PASSWORD\"/> \
									 </network-handler> \
									 </connection> \
									 <custom-property name = \"default.activeObject\" value=\"\"/> \
									 </data-source>";

const char ENCRYPTION_KEY[] = "sdf@!#$verf^wv%6Fwe%$$#FFGwfsdefwfe135s$^H)dg";
const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen <= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;
	std::string strTemp(pszDst);
	delete[] pszDst;
	return strTemp;
}

void log2file(char *fmt, ...)
{
	FILE *fp = NULL;
	va_list args = NULL;
	char sprint_buf[1024] = {0};


	char timebuf[50] = {0};
	struct tm *stm ;
	time_t tt = time(NULL);
	stm= localtime(&tt);
	sprintf(timebuf, "%d[%04d-%02d-%02d %02d:%02d:%02d]:", GetCurrentProcessId(),stm->tm_year+1900,
		stm->tm_mon+1, stm->tm_mday, stm->tm_hour, stm->tm_min, stm->tm_sec);

	char filename[250] = {0};
	sprintf(filename, "C:\\asia_log\\testOssMain_%04d-%02d-%02d.log", stm->tm_year+1900,
		stm->tm_mon+1, stm->tm_mday);
	fp = fopen(filename, "a+");
	if(fp)
	{
		va_start(args, fmt);


		//fprintf(fp, "[%s]:",timebuf);
		fprintf(fp, timebuf);
		vfprintf(fp, fmt, args);
		fprintf(fp, "\n");
		va_end(args);
		fclose(fp);
	}

	return;

}


void getXmlDirPath(std::wstring &filePath){
	DWORD dwSize = 256;
	wchar_t szHomeDir[256] = { 0 };
	memset(szHomeDir, 0, dwSize);
	HANDLE hToken = 0;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{
		if (GetUserProfileDirectoryW(hToken, szHomeDir, &dwSize))
		{
			//filePath.append(szHomeDir).append(L"\\.dbeaver");Users\\温家盛\\AppData\\Roaming\\DBeaverData\\workspace6\\.metadata
			filePath.append(szHomeDir).append(L"\\AppData\\Roaming\\DBeaverData\\workspace6");
		}
	}
}
//判断当前dbeaver是否已经配置了postgresql的jdbc驱动
BOOL isInstallPostgreDiver(std::wstring &driverXmlPath,std::wstring &xmlPath)
{
	HANDLE pFile;
	DWORD fileSize;
	char *buffer,*tmpBuf;C:
	DWORD dwBytesRead,dwBytesToRead,tmpLen;
	pFile = CreateFileW(driverXmlPath.c_str(),GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
		//打开已存在的文件 
		FILE_ATTRIBUTE_NORMAL, NULL); 
	if ( pFile == INVALID_HANDLE_VALUE) 
	{ 
		//printf("open file error!\n"); 
		CloseHandle(pFile); 
		driverXmlPath= L"";
		driverXmlPath.append(L"C:\\Users\\温家盛\\AppData\\Roaming\\DBeaverData\\workspace6\\.metadata\\.plugins\\org.jkiss.dbeaver.core\\drivers.xml");

		pFile = CreateFileW(driverXmlPath.c_str(),GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL, NULL); 
		if ( pFile == INVALID_HANDLE_VALUE) 
		{
			return FALSE; 
		}
	} 
	fileSize = GetFileSize(pFile,NULL); 
	//得到文件的大小 
	buffer = (char *) malloc(fileSize+2); 
	ZeroMemory(buffer,fileSize); 
	dwBytesToRead = fileSize; 
	dwBytesRead = 0; 
	tmpBuf = buffer; 
	do{ //循环读文件，确保读出完整的文件    
		ReadFile(pFile,tmpBuf,dwBytesToRead,&dwBytesRead,NULL);
		if (dwBytesRead == 0) 
			break; 
		dwBytesToRead -= dwBytesRead; 
		tmpBuf += dwBytesRead;
	} while (dwBytesToRead > 0); 
	CloseHandle(pFile); 
	//遍历是否安装了驱动
	//log2file("\npostgres diver xml:%s\n",buffer);
	if(strstr(buffer,"postgresql")!=NULL)
	{
		free(buffer); 
		return TRUE;
	}

	free(buffer); 
	return FALSE;

}

//
void DisplayErrorText(
	DWORD dwError
	)
{
	//_asm {int 3};
	HLOCAL hlocal = NULL;   // Buffer that gets the error message string

	// Use the default system locale since we look for Windows messages.
	// Note: this MAKELANGID combination has 0 as value
	DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

	// Get the error code's textual description
	BOOL fOk = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_ALLOCATE_BUFFER, 
		NULL, dwError, systemLocale, 
		(PTSTR) &hlocal, 0, NULL);

	if (!fOk) {
		// Is it a network-related error?
		HMODULE hDll = LoadLibraryEx(TEXT("netmsg.dll"), NULL, 
			DONT_RESOLVE_DLL_REFERENCES);

		if (hDll != NULL) {
			fOk = FormatMessage(
				FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS |
				FORMAT_MESSAGE_ALLOCATE_BUFFER,
				hDll, dwError, systemLocale,
				(PTSTR) &hlocal, 0, NULL);
			FreeLibrary(hDll);
		}
	}

	if (fOk && (hlocal != NULL)) {
		//SetDlgItemText(hwnd, IDC_ERRORTEXT, (PCTSTR) LocalLock(hlocal));
		MessageBox(0,(PCTSTR) LocalLock(hlocal),TEXT("error"),MB_ICONERROR);
		LocalFree(hlocal);
	} else {
		MessageBox(0,TEXT("No text found for this error number."),TEXT("error"),MB_ICONERROR);
	}
}
#define _ENCODE32
CString  ax_asia_decryption(const char* lpSrc)
{
	CString strResult = "";
#ifdef _ENCODE32
	HINSTANCE hLib = LoadLibrary("encode2.dll");
#else
	HINSTANCE hLib = LoadLibrary("encode2_x64.dll");
#endif
	//指定要注册的ocx文件的路径及文件名。
	if (hLib == NULL)
	{
		//MessageBox("不能载入OCX文件!");
		log2file("载入encode模块失败");
		DisplayErrorText(GetLastError());
		//strlog.Format(_T("控件%s载入失败"),ocxpath);
		//AppendLog(strlog);

		return strResult;
	}
	//strlog.Format(_T("控件%s载入成功"),ocxpath);
	//AppendLog(strlog);


	//获取注册函数DllRegisterServer地址
	typedef char* (__cdecl *_asia_decryption)(const char *src);
	_asia_decryption asia_decryption = (_asia_decryption)GetProcAddress(hLib,"asia_decryption");



	//调用注册函数DllRegisterServer
	if(asia_decryption!=NULL)
	{
		strResult = (*asia_decryption)(lpSrc);

		return strResult;
	}
	else
	{
		log2file("载入encode内函数失败");
		DisplayErrorText(GetLastError());
		//strlog.Format(_T("查找控件%s注册函数失败"),ocxpath);
		//AppendLog(strlog);
	}
	FreeLibrary(hLib);
	return strResult;
	//return NULL;
}
//const char ENCRYPTION_KEY[] = "sdf@!#$verf^wv%6Fwe%$$#FFGwfsdefwfe135s$^H)dg";
//const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
char *base64_encodefordbeaver(const char* data, int data_len)
{
	int prepare = 0, ret_len = 0, temp = 0, tmp = 0, i = 0;
	char *ret = NULL;
	char *f = NULL;
	char changed[4];
	ret_len = data_len / 3;
	temp = data_len % 3;
	if (temp > 0)
	{
		ret_len += 1;
	}
	ret_len = ret_len * 4 + 1;
	ret = (char *) malloc(ret_len);
	if (ret == NULL)
	{
		exit(0);
	}
	memset(ret, 0, ret_len);
	f = ret;
	while (tmp < data_len)
	{
		temp = 0;
		prepare = 0;
		memset(changed, '\0', 4);
		while (temp < 3)
		{
			if (tmp >= data_len)
			{
				break;
			}
			prepare = ((prepare << 8) | (data[tmp] & 0xFF));
			tmp++;
			temp++;
		}
		prepare = (prepare << ((3 - temp) * 8));
		for (i = 0; i < 4; i++)
		{
			if (temp < i)
			{
				changed[i] = 0x40;
			}
			else
			{
				changed[i] = (prepare >> ((3 - i) * 6)) & 0x3F;
			}
			*f = base[changed[i]];
			f++;
		}
	}
	*f = '\0';
	return ret;
}
char* dbeaver_pwd_encode(const char* str, int len){
	char* szBuf = new char[len + 2];
	memcpy(szBuf, str, len);
	szBuf[len] = 0;
	szBuf[len + 1] = -127;
	int keyOffset = 0, keyLen = strlen(ENCRYPTION_KEY);
	for (int i = 0; i < len + 2; i++) {
		byte keyChar = ENCRYPTION_KEY[keyOffset];
		keyOffset++;
		if (keyOffset >= keyLen) {
			keyOffset = 0;
		}
		szBuf[i] ^= keyChar;
	}
	char* result = base64_encodefordbeaver(szBuf, len + 2);
	delete szBuf;
	return result;
}

void OutputDebugPrintf(const char * strOutputString,...)
{
	char strBuffer[4096]={0};
	va_list vlArgs;
	va_start(vlArgs,strOutputString);
	_vsnprintf(strBuffer,sizeof(strBuffer)-1,strOutputString,vlArgs);
	//vsprintf(strBuffer,strOutputString,vlArgs);
	va_end(vlArgs);
	OutputDebugString(strBuffer);
}
//const char* dbeaver_tmp_postgresql = "<data-source id =\"%s\" provider=\"generic\" driver=\"postgresql\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
//									 <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
//									 <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
//									 <property name = \"socks-host\" value=\"\"/> \
//									 <property name = \"socks-port\" value=\"1080\"/> \
//									 </network-handler> \
//									 <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
//									 <property name = \"port\" value=\"22\"/> \
//									 <property name = \"host\" value=\"\"/> \
//									 <property name = \"keyPath\" value=\"\"/> \
//									 <property name = \"authType\" value=\"PASSWORD\"/> \
//									 </network-handler> \
//									 </connection> \
//									 <custom-property name = \"default.activeObject\" value=\"\"/> \
//									 </data-source>";

BOOL DeleteDirectory(LPCWSTR strDes)
{
	//删除目标目录下的所有文件     
	WIN32_FIND_DATAW       FileData;
	HANDLE                hSearch;
	BOOL                  bFinished = FALSE;
	std::wstring               strTemp;

	strTemp = strDes;
	strTemp += L"//*.*";

	hSearch = FindFirstFileW(strTemp.c_str(), &FileData);
	if (hSearch == INVALID_HANDLE_VALUE)
	{
		bFinished = TRUE;           //该目录下没有文件
	}
	while (!bFinished)
	{
		strTemp = strDes;
		strTemp += L"//";
		strTemp += FileData.cFileName;
		//strTemp = strTemp + L"//" +FileData.cFileName;
		if ((wcscmp(FileData.cFileName, L".") != 0) && (wcscmp(FileData.cFileName, L"..") != 0))
		{
			//是目录就进入递归调用     
			if (FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				DeleteDirectory(strTemp.c_str());
			}
			else
			{//是文件则删除     
				DeleteFileW(strTemp.c_str());
			}
		}
		bFinished = FindNextFileW(hSearch, &FileData) ? FALSE : TRUE;
	}
	FindClose(hSearch);
	//删除空目录     
	RemoveDirectoryW(strDes);
	return TRUE;
}

std::string ws2s(std::wstring& inputws)
{ 
	return WChar2Ansi(inputws.c_str()); 
}
#include <sys/stat.h>

short LocalDbeaver4PostgresqlLogin(LPCTSTR sExecName, LPCTSTR cUserName, LPCTSTR cPassWord, LPCTSTR cHost, LPCTSTR cPort, LPCTSTR cDbName, LPCTSTR cCharSet)
{
	//_asm{int 3};
	log2file("%s: %s %s %s %s %s %s %s",__FUNCTION__,sExecName,cUserName,cPassWord,cHost,cPort,cDbName,cCharSet);
	std::wstring xmlPath= L"";
	std::wstring driverXmlPath= L"";
	getXmlDirPath(xmlPath);
	std::wstring metadataPath = xmlPath;
	driverXmlPath = xmlPath;
	driverXmlPath.append(L"\\.metadata\\.plugins\\org.jkiss.dbeaver.core\\drivers.xml");
	log2file("xml:%s",ws2s(driverXmlPath).c_str());
	if(!isInstallPostgreDiver(driverXmlPath,xmlPath))
	{
		::MessageBox(NULL, "没有给Dbeaver工具配置Postgresql的驱动", "提示", 0);
		return 0;
	}
	xmlPath.append(L"\\General");
	
	SHCreateDirectory(NULL, xmlPath.c_str());

	string str_tmp = cPassWord;
	CString strpassword = ax_asia_decryption(str_tmp.c_str());
	if(strpassword.GetLength() < 1)
	{
		log2file("Dbeaver4Postgresql工具使用了未加密的密码");
		strpassword = str_tmp.c_str();
	}
	char* encodedPwd = dbeaver_pwd_encode(strpassword.GetString(), strpassword.GetLength());
	tinyxml2::XMLDocument doc(false);
	xmlPath.append(L"\\.dbeaver-data-sources.xml");
	struct _stat buf;
	int result = _stat(ws2s(xmlPath).c_str(), &buf);
	OutputDebugPrintf("LocalDbeaver4PostgresqlLogin:xml路径:%s",ws2s(xmlPath).c_str());
	log2file("LocalDbeaver4PostgresqlLogin:xml路径:%s",ws2s(xmlPath).c_str());
	//log2file();
	if (result != 0)
	{
		metadataPath.append(L"\\.metadata\\.plugins\\org.eclipse.core.resources");
		//RemoveDirectoryW(metadataPath.c_str());
		//SHFILEOPSTRUCTW FileOp = { 0 };
		//FileOp.fFlags = FOF_ALLOWUNDO |   //允许放回回收站
		//	FOF_NOCONFIRMATION | FOF_SILENT; //不出现确认对话框
		//FileOp.pFrom = metadataPath.c_str();//L"C:\\Users\\zhangtx\\.dbeaver\\.metadata\\.plugins\\org.eclipse.core.resources";
		//FileOp.pTo = NULL;      //一定要是NULL
		//FileOp.wFunc = FO_DELETE;    //删除操作
		//result = SHFileOperationW(&FileOp);
		DeleteDirectory(metadataPath.c_str());
		//DeleteDirs(metadataPath.c_str());
		//::MessageBoxA(NULL, ws2s(metadataPath).c_str(),"Tips",MB_OK);
		//Sleep(500);
	}
	doc.LoadFile(ws2s(xmlPath).c_str());
	tinyxml2::XMLNode* root = doc.RootElement();
	if (!root)
	{
		doc.NewDeclaration();
		root = doc.InsertEndChild(doc.NewElement("data-sources"));
	}
	tinyxml2::XMLElement* curElement = root->FirstChildElement("data-source");
	tinyxml2::XMLElement* nextElement = NULL;
	while (curElement)
	{
		nextElement = curElement->NextSiblingElement();
		if (strstr(curElement->Attribute("id"), "creator_ai4a")){
			const char* txt = curElement->Value();
			doc.DeleteNode(curElement);
		}
		curElement = nextElement;
	}
	char* szBuf = (char*) malloc(2000);
	::memset(szBuf, 0, 2000);
	char szDbTitle[200] = { 0 };
	sprintf(szDbTitle, "PostgreSQL_%s_%s_%s", cHost, cPort, cDbName);
	char szDbUrl[200] = {0};
	sprintf(szDbUrl, "jdbc:postgresql://%s:%s/%s", cHost, cPort, cDbName);
	sprintf(szBuf, dbeaver_tmp_postgresql, "postgresql-1426154947249-creator_ai4a",
		szDbTitle, //dbname
		cHost, //host
		cPort, //port
		cDbName, //database
		szDbUrl, //url
		cUserName, //username
		encodedPwd //password
		);
	tinyxml2::XMLDocument docNode;
	docNode.Parse(szBuf);
	tinyxml2::XMLPrinter printer;
	docNode.Print(&printer);
	tinyxml2::XMLText* textNode = doc.NewText(printer.CStr());
	root->InsertFirstChild(textNode);
	doc.SaveFile(ws2s(xmlPath).c_str());
	free(szBuf);
	free(encodedPwd);

	////以下为插入vertica数据库jar包的代码
	//tinyxml2::XMLDocument doc1(false);
	//doc1.LoadFile(ws2s(driverXmlPath).c_str());
	//tinyxml2::XMLNode* root1 = doc1.RootElement();
	//if(root1)
	//{
	//	tinyxml2::XMLElement* providerNode=root1->FirstChildElement("provider");
	//	while(providerNode!=NULL)
	//	{
	//		const char *p = providerNode->Attribute("id");
	//		if(strcmp(providerNode->Attribute("id"),"generic")==0)
	//			break;
	//		providerNode=providerNode->NextSiblingElement();//下一个兄弟节点
	//	}
	//	if(providerNode)
	//	{
	//		tinyxml2::XMLElement* driverNode=providerNode->FirstChildElement("driver");
	//		while(driverNode!=NULL)
	//		{
	//			const char *p = providerNode->Attribute("id");
	//			if(strcmp(driverNode->Attribute("id"),"postgresql")==0)
	//				break;
	//			driverNode=driverNode->NextSiblingElement();//下一个兄弟节点
	//		}
	//		if(driverNode)
	//		{
	//			doc1.DeleteNode(driverNode);
	//		}
	//		tinyxml2::XMLElement* verticaNode = doc1.NewElement("driver");
	//		verticaNode->SetAttribute("id","postgresql");
	//		verticaNode->SetAttribute("custom ","false");
	//		verticaNode->SetAttribute("name ","PostgreSQL");
	//		verticaNode->SetAttribute("class ","org.postgresql.Driver");
	//		verticaNode->SetAttribute("url ","jdbc:vertica://{host}:{port}/{database}");
	//		verticaNode->SetAttribute("port ","5433");
	//		verticaNode->SetAttribute("description ","PostgreSQL standard driver");
	//		tinyxml2::XMLElement* verticaDriverNode = doc1.NewElement("library");
	//		verticaDriverNode->SetAttribute("path","C:\\Windows\\postgresql-9.1-901.jdbc4.jar");
	//		verticaNode->InsertEndChild(verticaDriverNode);
	//		providerNode->InsertEndChild(verticaNode);

	//	}
	//}
	//doc1.SaveFile(ws2s(driverXmlPath).c_str());

	//启动dbeaver.exe软件
	HINSTANCE hInstance = ShellExecute(NULL, "open", sExecName, "", "", SW_SHOW);
	if ((int) hInstance < 32)
	{
		char cTmp[255];
		sprintf(cTmp, "没有安装%s或者找不到%s(请重新设置环境变量)", sExecName, sExecName);
		::MessageBox(NULL, cTmp, "提示", 0);
		return -1;
	}
	return 0;
}
void CtestOssmainDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	LocalDbeaver4PostgresqlLogin("C:\\Users\\温家盛\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\DBeaver Community\\DBeaver","postgres","postgres","10.1.198.67 ","5432","postgres",NULL);
}
