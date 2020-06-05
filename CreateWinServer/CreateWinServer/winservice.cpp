//winsvr.c

#include "stdafx.h"
#include "winservice.h"
#include <winsvc.h>
//#include "common.h"
//#define TLOG printf

#include <time.h>
void log2file(char *fmt, ...)
{
	FILE *fp = NULL;
	va_list args = NULL;
	char sprint_buf[1024] = {0};


	char timebuf[50] = {0};
	struct tm *stm ;
	time_t tt = time(NULL);
	stm= localtime(&tt);

	char userName[MAX_PATH] = {0};

	sprintf(timebuf, "%d[%04d-%02d-%02d %02d:%02d:%02d]:", GetCurrentProcessId(),stm->tm_year+1900,
		stm->tm_mon+1, stm->tm_mday, stm->tm_hour, stm->tm_min, stm->tm_sec);

	char filename[250] = {0};
	sprintf(filename, "C:\\asia_log\\LocalMain_Service_%04d-%02d-%02d.log", stm->tm_year+1900,
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

#define TLOG log2file
BOOL Service_Install(LPCSTR svrname, LPCSTR txt, LPCSTR pathname)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	char szKey[1024]={0};
	HKEY hKey;
	
	{
		size_t pathlen = strlen(pathname)+1;
		LPSTR oldpath = (LPSTR)_alloca(pathlen);
		if (Service_GetPath(svrname, oldpath, pathlen)) {
			if (strcmp(oldpath, pathname) != 0) {
				Service_Uninstall(svrname);
			}
		}
	}
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	//创建服务
	hService = OpenServiceA(hSCM, svrname, SERVICE_START );
	
	if (!hService) {
		hService = CreateServiceA(
			hSCM, svrname, svrname,
			SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS,
			SERVICE_AUTO_START, SERVICE_ERROR_NORMAL,
			(LPCSTR)pathname, NULL, NULL, NULL, NULL, NULL);
		if (!hService) 
			{
				TLOG("\nRegister Service Main Function Error! err=%d", GetLastError());
				goto _Failed;
		}
		/*
		strcpy(szKey,   "SYSTEM\\CurrentControlSet\\Services\\");   
		strcat(szKey,   svrname);   
		if   (RegCreateKey(HKEY_LOCAL_MACHINE, szKey, &hKey) != ERROR_SUCCESS)  goto _Failed;
		RegSetValueEx(hKey,   
			"Description",   
			0,   
			REG_SZ,   
			(LPBYTE)txt,   
			strlen(txt));   
		RegCloseKey(hKey);*/
	}

	bRet = TRUE;
_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}

BOOL Service_Start(LPCSTR svrname)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	//函数建立了一个到服务控制管理器的连接
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	//打开一个已经存在的服务
	hService = OpenServiceA(hSCM, svrname, SERVICE_START );	
	if (!hService) goto _Failed;
	//启动服务
	if(!StartService(hService, 0 , 0)) goto _Failed;
	
	bRet = TRUE;
_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}

VOID Service_Stop(LPCSTR svrname)
{
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SERVICE_STATUS st;

	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	hService = OpenServiceA(hSCM, svrname, SERVICE_STOP|SERVICE_QUERY_STATUS );
	if (!hService) goto _Failed;

	//停止服务
	while(QueryServiceStatus(hService, &st))
	{	
		if(st.dwCurrentState == SERVICE_STOPPED)
			break;
		ControlService(hService, SERVICE_CONTROL_STOP, &st);
	}
	
_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
}

BOOL Service_Uninstall(LPCSTR svrname)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SERVICE_STATUS st;
	
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	hService = OpenServiceA(hSCM, svrname, SERVICE_STOP | DELETE|SERVICE_QUERY_STATUS );
	if (!hService) goto _Failed;
	
	//停止服务
	while(QueryServiceStatus(hService, &st))
	{	
		if(st.dwCurrentState == SERVICE_STOPPED)
			break;
		ControlService(hService, SERVICE_CONTROL_STOP, &st);
	}	
	bRet = DeleteService(hService);

_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}

BOOL Service_Uninstall_NoWait(LPCSTR svrname)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SERVICE_STATUS st;
	
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	hService = OpenServiceA(hSCM, svrname, SERVICE_STOP | DELETE|SERVICE_QUERY_STATUS );
	if (!hService) goto _Failed;
	
	//停止服务
	while(QueryServiceStatus(hService, &st))
	{	
		if(st.dwCurrentState == SERVICE_STOPPED)
			break;
		ControlService(hService, SERVICE_CONTROL_STOP, &st);
		break;
	}	
	bRet = DeleteService(hService);

_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}
BOOL Service_IsRunning(LPCSTR svrname)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SERVICE_STATUS st;
	if(_stricmp(svrname, "/run") == 0)
	{
		return TRUE;
	}
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	hService = OpenServiceA(hSCM, svrname, SERVICE_STOP|SERVICE_QUERY_STATUS );
	if (!hService) goto _Failed;
	
	if (!QueryServiceStatus(hService, &st)) goto _Failed;
	if (st.dwCurrentState == SERVICE_RUNNING) {
		bRet = TRUE;
	}
	
_Failed:
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}

BOOL Service_GetPath(LPCSTR svrname, LPSTR path, size_t len)
{
	BOOL bRet = FALSE;
	SC_HANDLE hService=(SC_HANDLE)INVALID_HANDLE_VALUE;
	SC_HANDLE hSCM=(SC_HANDLE)INVALID_HANDLE_VALUE;
	//SERVICE_STATUS st;
	#define QSC_LEN 8192
	LPQUERY_SERVICE_CONFIG qsc = (LPQUERY_SERVICE_CONFIG)LocalAlloc(LPTR, QSC_LEN);
	DWORD nbytes;

	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCM) goto _Failed;
	
	hService = OpenServiceA(hSCM, svrname, SERVICE_QUERY_CONFIG );
	if (!hService) goto _Failed;
	
	if (!QueryServiceConfig(hService, qsc, QSC_LEN, &nbytes)) goto _Failed;

	memset(path, 0, len);
	_tcsncpy(path, qsc->lpBinaryPathName, len-1);
	bRet = TRUE;
_Failed:
	if (qsc) LocalFree(qsc);
	if(hService) CloseServiceHandle(hService);
	if(hSCM) CloseServiceHandle(hSCM);
	return bRet;
}
static LPSERVICE_MAIN_FUNCTION svr_func;
static LPHANDLER_FUNCTION	strl_func;
static SERVICE_STATUS_HANDLE status_handle;
static SERVICE_STATUS svr_status;
/*
BOOL Service_IsRunning(LPCSTR svrname)
{
	return svr_status.dwCurrentState==SERVICE_RUNNING;
}
*/
static void WINAPI ServiceStrl(DWORD dwOpcode)
{
	TLOG("ServiceStrl %d\n",dwOpcode);
	log2file("ServiceStrl %d\n",dwOpcode);
	switch(dwOpcode){   
	case   SERVICE_CONTROL_STOP:  
	case	SERVICE_CONTROL_SHUTDOWN:

	if(strl_func != NULL)
	{
	strl_func(dwOpcode);
	}
	svr_status.dwCurrentState  = SERVICE_STOPPED;
	SetServiceStatus(status_handle, &svr_status);
	break;   
	default:   
	break;   
	}   	
}

static void WINAPI ServiceMain(DWORD argc, LPTSTR *argv)
{
    //注册服务控制
	//TLOG("argv[0]=%s\n",argv[0]);
	//_asm{int 3};
	//RegisterServiceCtrlHandlerEx()
    //status_handle = RegisterServiceCtrlHandler(argv[0], ServiceStrl);
	status_handle = RegisterServiceCtrlHandler(argv[0], ServiceStrl);
    if (!status_handle) return;

	svr_status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	svr_status.dwCurrentState = SERVICE_START_PENDING;
	//下面的属性设置为0  则注册的服务   不接受关闭操作
	svr_status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	svr_status.dwWin32ExitCode = 0;
	svr_status.dwServiceSpecificExitCode = 0;
	svr_status.dwCheckPoint = 0;
	svr_status.dwWaitHint = 0;	

    SetServiceStatus(status_handle, &svr_status);
	
    svr_status.dwCurrentState = SERVICE_RUNNING;
    SetServiceStatus(status_handle, &svr_status); 
//	LOGSYS(LMINFO,"Service pid %d,%d  begin to run service!", GetCurrentProcessId(),GetCurrentThreadId());
	svr_func(argc, argv);
	
	svr_status.dwCurrentState = SERVICE_STOPPED;
    SetServiceStatus(status_handle, &svr_status); 
}

BOOL Service_Run(LPCSTR svrname, LPSERVICE_MAIN_FUNCTION svr_main_func)
{
    SERVICE_TABLE_ENTRY st[] =
    {
        { (LPSTR)svrname, (LPSERVICE_MAIN_FUNCTION)ServiceMain },
        { NULL, NULL }
    };
	log2file("Service_Run begin");
//	LOGSYS(LMINFO,"Service pid %d,%d  called to run!", GetCurrentProcessId(),GetCurrentThreadId());
	svr_func = svr_main_func;

	return StartServiceCtrlDispatcher(st);
}


VOID Service_Param_Invoke_ex(LPCSTR svrname, LPCSTR Param, LPCSTR txt,
	LPSERVICE_MAIN_FUNCTION svr_main_func, LPHANDLER_FUNCTION svr_strl_func)
{
	strl_func = svr_strl_func;
	if (_stricmp(Param, "-install") == 0)
	{
		char buf[1024];
		printf("name :%s\n",svrname);
		TLOG("\nBegin to Install %s", svrname);
		GetModuleFileNameA(NULL, buf, sizeof(buf));
		if (Service_Install (svrname, txt, buf)) {
			Service_Start(svrname);
			TLOG("\nSucceed to Install %s", svrname);
		} else {
			TLOG("\nFailed to Install %s", svrname);
		}
	}
	else if (_stricmp(Param, "-remove") == 0)
	{
		TLOG("\nBegin to UnInstall %s", svrname);
		if (Service_Uninstall(svrname)) {
			TLOG("\nSucceed to UnInstall %s", svrname);
		} else {
			TLOG("\nFailed to UnInstall %s", svrname);
		}
		Sleep(1000);
	}
	else if (_stricmp(Param, "-start") == 0)
	{
		TLOG("\nBegin to start %s", svrname);
		if (Service_Start (svrname)) 
		{
			TLOG("\nSucceed to start %s", svrname);
		} else {
			TLOG("\nFailed to start %s", svrname);
		}
	}
	else if (_stricmp(Param, "-stop") == 0)
	{
		TLOG("\nBegin to stop %s", svrname);
		Service_Stop(svrname);
		TLOG("\nstop : %s", svrname);
	}
	else if (_stricmp(Param, "-restart") == 0)
	{
		TLOG("\nBegin to Restart %s", svrname);
		Service_Stop(svrname);
		TLOG("\nstop : %s", svrname);
		if (Service_Start (svrname)) 
		{
			TLOG("\nSucceed to restart %s", svrname);
		} else {
			TLOG("Failed to restart %s", svrname);
		}
	}
	else if(_stricmp(Param, "/run")==0)
	{
		LPTSTR sargv[1];
		sargv[0] = (LPTSTR)"/run";
		svr_main_func(1, sargv);
	}
	else
	{
		//服务系统调用，控制分发
		if (!Service_Run(svrname, svr_main_func))
		{
			TLOG("\nRegister Service Main Function Error! err=%d", GetLastError());
		}
	}
}

VOID Service_Param_Invoke(LPCSTR svrname, LPCSTR Param, LPCSTR txt,
	LPSERVICE_MAIN_FUNCTION svr_main_func)
{
	Service_Param_Invoke_ex(svrname, Param, txt, svr_main_func,NULL);
}
