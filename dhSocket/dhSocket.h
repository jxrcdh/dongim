#ifndef DHSOCKET_H
#define DHSOCKET_H

#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
class Socket;

class ServerSocket
{
public:
	static const int CreateSocketError = -1;
	static const int BindError = -2;
	static const int ListenError = -3;
private:
	int sockid;
	short port;
	struct sockaddr_in servaddr;
	int MaxListen;
public:
	ServerSocket(short _port,int _maxlisten):port(_port),MaxListen(_maxlisten){};
	int bindAndListen();
	Socket* AcceptLink();
};
class Socket
{
public:
	static const bool isServerSocket = true;
	static const bool isClientSocket = false;

	static const int CreateSocketError = -1;
	static const int WrongIPError = -2;
	static const int ConnectError = -3;
private:
	int sockid;
	bool flag;
	char* ip;
	bool Connected;
	short port;
	struct sockaddr_in servaddr;
public:
	Socket(const char* _ip,short _port):sockid(-1),flag(isClientSocket),Connected(false),port(_port)
	{
		if(_ip == NULL) ip=NULL;
		else
			strcpy(ip,_ip);
	};
	friend Socket* ServerSocket::AcceptLink();
	int readMsg(void* buf,size_t count);
	int writeMsg(const void* buf,size_t count);
	int init();
	int ConnectServer();
};

#endif