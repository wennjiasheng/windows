#include <stdio.h>
#include <string.h>
#include <winsock.h>
#pragma comment(lib,"ws2_32.lib")

void main()
{
	//存放版本
	WORD wversion;
	//指针，存放网络执行信息
	WSADATA wsadata;
	//管理错误，标号
	int err;

	//客户端套接字,用于连接
	SOCKET sockclient;
	//服务器地址
	SOCKADDR_IN  addrserver;
	//客户端地址
	SOCKADDR_IN  addrclienet;

	//长度
	int length = 0;
	//接收
	char recvstr[256] = { 0 };
	//标示
	const char bflags = 1;
	//设定版本
	wversion = MAKEWORD(2, 2);
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
	//UDP报文传输
	sockclient = socket(AF_INET, SOCK_DGRAM, 0);
	//setsockopt()函数，用于任意类型、任意状态套接口的设置选项值。
	//尽管在不同协议层上存在选项，但本函数仅定义了最高的“套接口”层次上的选项。
	//多播必须指定的参数
	//flags设定，1代表广播，0禁止广播
	setsockopt(sockclient, SOL_SOCKET, SO_REUSEADDR, &bflags, sizeof(bflags));

	//存放客户端ip地址
	addrclienet.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrclienet.sin_family = AF_INET;
	addrclienet.sin_port = htons(9999);//端口
	//客户端套接字与客户端信息绑定
	bind(sockclient, (SOCKADDR*)&addrclienet, sizeof(SOCKADDR));
	//等于地址长度
	length = sizeof(SOCKADDR);
	while (1)
	{
		printf("wait-----------------\n");
		//从客户端接收消息,地址信息存放在addrserver中
		recvfrom(sockclient, recvstr, 256, 0, (SOCKADDR*)&addrserver, &length);
		if (WSAGetLastError() != 0)
		{
			puts("收取失败");
		}
		//哪个服务器发送的
		printf("%s speak %s\n", inet_ntoa(addrserver.sin_addr), recvstr);
	}
	closesocket(sockclient);
	WSACleanup();
	system("pause");
}