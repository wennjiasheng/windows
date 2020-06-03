#include<iostream>
#include<Windows.h>
#include <Wtsapi32.h>
#pragma comment(lib, "Wtsapi32.lib")
#include<stdio.h>
#include <time.h>

class WSessionManager
{
public:		
	void StopAllAgent(); 
	void StopSessionManager();
	void Run();
};