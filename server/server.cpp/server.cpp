// SiimpleHelloServer.cpp : 初始套接字编程，仅仅用来实现基本的通信。
//

#include<iostream>
#include<stdio.h>
#include<tchar.h>
#include <WinSock2.h>
#include <Windows.h>
#include<stdlib.h>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")
#define SERVER_PORT "2500"
#define BUFFER_LEN  512

int _tmain(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	struct addrinfo hints, *result = NULL;
	char *sendbuf = "Hello from Server!";
	char recvbuf[BUFFER_LEN];
	int iResult, isendResult;
	memset(recvbuf, 0, BUFFER_LEN*sizeof(char));
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: &d\n", iResult);
		return 1;
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	iResult = getaddrinfo(NULL, SERVER_PORT, &hints, &result);
	if (iResult != 0){
		printf("getaddrinfo failed with error %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET){
		printf("socket failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR){
		printf("bind failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR){
		printf("listen failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (iResult == INVALID_SOCKET){
		printf("accept failed with error %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	do{
		iResult = recv(ClientSocket, recvbuf, 30, 0);
		if (iResult>0){
			printf("Received message from client: %s\n", recvbuf);
			isendResult = send(ClientSocket, sendbuf, strlen(sendbuf), 0);
			if (isendResult == SOCKET_ERROR){
				printf("send failed with error %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			printf("Bytes sent: %d\n", isendResult);
		}
		else if (iResult == 0){
			printf("Connection closing...\n");
		}
		else{
			printf("recv failed with error:d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}
	} while (iResult>0);

	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR){
		printf("shutdown failed with error %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return 0;
}

