//winservice.h
#define _CRT_SECURE_NO_WARNINGS
#if !defined(_WINSERVICE_H_) 
#define _WINSERVICE_H_

#include <wtypes.h>
#include <tchar.h>
#include <WINSVC.H>
#include <malloc.h>
#include <stdio.h>
//#ifdef __cplusplus
//extern "C" {
//#endif
//

BOOL Service_Install(LPCSTR svrname, LPCSTR txt, LPCSTR pathname);

BOOL Service_Uninstall(LPCSTR svrname);
BOOL Service_Uninstall_NoWait(LPCSTR svrname);
BOOL Service_Start(LPCSTR svrname);

VOID Service_Stop(LPCSTR svrname);

BOOL Service_IsRunning(LPCSTR svrname);

BOOL Service_Run(LPCSTR svrname, LPSERVICE_MAIN_FUNCTION svr_main_func);

VOID Service_Param_Invoke(LPCSTR svrname, LPCSTR Param, LPCSTR txt,
						  LPSERVICE_MAIN_FUNCTION svr_main_func);
VOID Service_Param_Invoke_ex(LPCSTR svrname, LPCSTR Param, LPCSTR txt,
	LPSERVICE_MAIN_FUNCTION svr_main_func, LPHANDLER_FUNCTION svr_strl_func);

BOOL Service_GetPath(LPCSTR svrname, LPSTR path, size_t len);

//#ifdef __cplusplus
//}
//#endif
	
#endif ///_WINSERVICE_H_

