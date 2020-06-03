// asia_service.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "winservice.h"
#include "WSessionManager.h"
WSessionManager manger;
void servicerun()
{
	manger.Run();
}

static void WINAPI  service_shutdown(DWORD dwOpcode)
{

	manger.StopSessionManager();
}

static void WINAPI service_main(DWORD argc, LPTSTR *argv)
{   

	servicerun();
}


int _tmain(int argc, _TCHAR* argv[])
{

	char path[MAX_PATH] = {0};
	char *cmdline = "";
	int ret = 0;
	if(argc > 1)
	{
		cmdline = argv[1];
	}
	//	MessageBox(NULL,"xsa",NULL,NULL);

	if(stricmp(cmdline, "/run") == 0)
	{
		servicerun();
		return 0;
	}

	Service_Param_Invoke_ex("FirstServer", cmdline, "AssistantService Asiainfo", service_main, service_shutdown);
	return 0;
}

