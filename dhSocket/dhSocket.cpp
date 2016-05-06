#include"dhSocket.h"

int ServerSocket::bindAndListen()
{
	sockid = socket(AF_INET,SOCK_STREAM,0);
	if(-1==sockid)
		return CreateSocketError;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	if(bind(sockid,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1)
		return BindError;
	if(listen(sockid,MaxListen)==-1)
		return ListenError;
}

Socket* ServerSocket::AcceptLink()
{
	int conn_fd;
	if((conn_fd=accept(sockid,(struct sockaddr*)NULL,NULL))==-1)
		return NULL;
	else
	{
		Socket* linkedSock = new Socket((char*)NULL,port);
		linkedSock->sockid=conn_fd;
		linkedSock->flag=Socket::isServerSocket;
		linkedSock->Connected=true;
		return linkedSock;
	}
}

int Socket::readMsg(void* buf,size_t count)
{
	return read(sockid,buf,count);
}
int Socket::writeMsg(const void* buf,size_t count)
{
	return write(sockid,buf,count);
}
int Socket::init()
{
	if((sockid=socket(AF_INET,SOCK_STREAM,0))<0)
		return Socket::CreateSocketError;

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(port);

	if(inet_pton(AF_INET,ip,&servaddr.sin_addr)<=0)
		return Socket::WrongIPError;
}

int Socket::ConnectServer()
{
	if(connect(sockid,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)
		return Socket::ConnectError;
	else return 0;
}