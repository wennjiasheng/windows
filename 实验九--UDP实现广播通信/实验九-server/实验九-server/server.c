#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

void main()
{
	WORD wversion;//存放版本
	WSADATA wsadata;//指针，存放网络执行信息
	int err;//管理错误，标号

	SOCKET socksever;//服务器套接字
	//记录服务器信息
	SOCKADDR_IN  addrserver;
	//记录客户端信息
	SOCKADDR_IN  addrclienet;

	int length = 0;
	char sendstr[256] = { 0 };
	BOOL bflags = 1;//标示
	wversion = MAKEWORD(2, 2);//设定版本
	err = WSAStartup(wversion, &wsadata);
	if (err != 0)
	{
		printf("获取版本失败");
		return;
	}

	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		printf("版本对比失败，不一致");
		return;
	}

	socksever = socket(AF_INET, SOCK_DGRAM, 0);//报文
	// SO_BROADCAST多播必须指定的参数
	//flags设定，1代表广播，0禁止广播
	setsockopt(socksever, SOL_SOCKET, SO_BROADCAST, &bflags, sizeof(bflags));//绑定

	addrserver.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//任意主机
	addrserver.sin_family = AF_INET;
	addrserver.sin_port = htons(7888);//端口

	//服务器信息与套接字绑定
	bind(socksever, (SOCKADDR*)&addrserver, sizeof(SOCKADDR));//绑定

	//填写广播，255.255.255.255,广播
	addrclienet.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
	addrclienet.sin_family = AF_INET;
	addrclienet.sin_port = htons(9999);//端口

	length = sizeof(SOCKADDR);//保存地址长度

	while (1)
	{
		memset(sendstr, 0, 256);
		scanf("%s", sendstr);//获取读取
		//发送消息到客户端(广播)
		sendto(socksever, sendstr, strlen(sendstr), 0, (SOCKADDR*)&addrclienet, length);
	}
	closesocket(socksever);
	WSACleanup();
	system("pause");
}