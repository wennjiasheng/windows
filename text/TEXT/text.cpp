// DataCapture.cpp : 定义控制台应用程序的入口点。
//


#include "winsock2.h"
#include "mstcpip.h"
#include "iostream"
using namespace std;
#pragma comment(lib,"ws2_32.lib")

#define DEFAULT_BUFLEN 65535
#define DEFAULT_NAMELEN 512

int main()
{
	WSADATA wsaData;
	SOCKET SnifferSocket = INVALID_SOCKET;
	char recvbuf[DEFAULT_BUFLEN];
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;
	HOSTENT* local;
	char HostName[DEFAULT_NAMELEN];
	IN_ADDR addr;
	SOCKADDR_IN LocalAddr, RemoteAddr;
	int addrlen = sizeof(SOCKADDR_IN);
	int in = 0, i = 0;
	DWORD dwBufferLen[10];
	DWORD Optval = 1;
	DWORD dwBytesReturned = 0;

	//初始化套接字
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		cout << "初始化失败：" << iResult << endl;
		return 1;
	}
	//创建套接字
	SnifferSocket = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (INVALID_SOCKET == SnifferSocket)
	{
		cout << "创建套接字失败：" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	//获取本机名称
	memset(HostName, 0, DEFAULT_NAMELEN);
	iResult = gethostname(HostName, sizeof(HostName));
	if (SOCKET_ERROR == iResult)
	{
		cout << "获取本机名称失败：" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	//获取本机IP
	local = gethostbyname(HostName);
	cout << "本机可用的IP地址有：" << endl;
	if (NULL == local)
	{
		cout << "获取IP失败：" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	while (local->h_addr_list[i] != 0)
	{
		addr.s_addr = *(u_long*)local->h_addr_list[i++];
		cout << "\t" << i << ":\t" << inet_ntoa(addr) << endl;
	}
	cout << "请选择捕获数据包待使用的接口号：";
	cin >> in;
	memset(&LocalAddr, 0, sizeof(LocalAddr));
	memcpy(&LocalAddr.sin_addr.S_un.S_addr, local->h_addr_list[in - 1], sizeof(LocalAddr.sin_addr.S_un.S_addr));
	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_port = 0;
	//绑定
	iResult = bind(SnifferSocket, (SOCKADDR*)&LocalAddr, sizeof(LocalAddr));
	if (SOCKET_ERROR == iResult)
	{
		cout << "绑定失败：" << WSAGetLastError() << endl;
		closesocket(SnifferSocket);
		WSACleanup();
		return 1;
	}
	cout << "成功绑定套接字和" << in << "号借口地址";
	//设置套接字接受命令
	iResult = WSAIoctl(SnifferSocket, SIO_RCVALL, &Optval, sizeof(Optval), &dwBufferLen, sizeof(dwBufferLen), &dwBytesReturned, NULL, NULL);
	if (SOCKET_ERROR == iResult)
	{
		cout << "套接字设置失败：" << WSAGetLastError() << endl;
		closesocket(SnifferSocket);
		WSACleanup();
		return 1;
	}
	//开始接受数据
	cout << "开始接受数据" << endl;
	do
	{
		//接受数据
		iResult = recvfrom(SnifferSocket, recvbuf, DEFAULT_BUFLEN, 0, (SOCKADDR*)&RemoteAddr, &addrlen);
		if (iResult > 0)
		{
			cout << "接受来自" << inet_ntoa(RemoteAddr.sin_addr) << "的数据包," << "长度为" << iResult << endl;
		}
		else
			cout << "接受失败：" << WSAGetLastError() << endl;
	} while (iResult > 0);
	{

	}

	return 0;
}