#include"stdafx.h"
#include"WSessionManager.h"




void log2file1(char *fmt, ...)
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

void WSessionManager::StopAllAgent()
{
	WinExec("taskkill /f /im assistant.exe",SW_HIDE);

}

void WSessionManager::StopSessionManager()
{
	DWORD dwEventsFlag(0); 
	WTSWaitSystemEvent(WTS_CURRENT_SERVER_HANDLE, WTS_EVENT_FLUSH, &dwEventsFlag);
	StopAllAgent();		
}

void WSessionManager::Run()
{
	int i=10;
	while(i>0)
	{
		log2file1("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		--i;
		Sleep(1000);
	}
	log2file1("runfinish");
}
