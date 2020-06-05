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
	log2file1("WSessionManager %d",__LINE__);
	log2file1("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	DWORD dwEventsFlag(0);
	while(1)
	{
		if(WTSWaitSystemEvent(WTS_CURRENT_SERVER_HANDLE, 
			WTS_EVENT_LOGOFF | WTS_EVENT_LOGON | WTS_EVENT_CONNECT | WTS_EVENT_DISCONNECT
			,&dwEventsFlag))
		{	
			log2file1("WSessionManager %d",__LINE__);
			printf("WSessionManager %d\n",__LINE__);


			//if(isStarted)
			//{
			//	log2file("用户Windows系统试图启动两个Session");
			//	Sleep(1500);
			//	continue;
			//}
			if(dwEventsFlag==WTS_EVENT_NONE)
			{
				log2file1("WSessionManager break");
				//break;
				return;
			}
			if((WTS_EVENT_LOGON & dwEventsFlag) == WTS_EVENT_LOGON )
			{
				log2file1("WSessionManager %d (WTS_EVENT_LOGON & dwEventsFlag) == WTS_EVENT_LOGON ",__LINE__);
			}
			if((WTS_EVENT_LOGOFF & dwEventsFlag) == WTS_EVENT_LOGOFF)
			{
				log2file1("WSessionManager %d dwEventsFlag) == WTS_EVENT_LOGOFF",__LINE__);
			}
			if((WTS_EVENT_CONNECT & dwEventsFlag) == WTS_EVENT_CONNECT )
			{
				log2file1("WSessionManager %d dwEventsFlag) == WTS_EVENT_CONNECT",__LINE__);
			}
			if((WTS_EVENT_DISCONNECT & dwEventsFlag) == WTS_EVENT_DISCONNECT )
			{
				log2file1("WSessionManager %d dwEventsFlag) == WTS_EVENT_DISCONNECT",__LINE__);
			}
			if( (WTS_EVENT_LOGON & dwEventsFlag) == WTS_EVENT_LOGON 
				||(WTS_EVENT_LOGOFF & dwEventsFlag) == WTS_EVENT_LOGOFF
				||(WTS_EVENT_CONNECT & dwEventsFlag) == WTS_EVENT_CONNECT
				||(WTS_EVENT_DISCONNECT & dwEventsFlag) == WTS_EVENT_DISCONNECT
				)
			{
				log2file1("WSessionManager %d",__LINE__);
				printf("WSessionManager %d\n",__LINE__);
				log2file1("dwEventsFlag %x",dwEventsFlag);
				log2file1("runfinish");
			}
		}
		else
		{
			log2file1("WTSWaitSystemEvent fail");
		}
	}
}
