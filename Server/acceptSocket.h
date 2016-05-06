#ifndef ACCEPTSOCKET_H
#define ACCEPTSOCKET_H

#include<sys/socket.h>
#include<netinet/in.h>
#include"shareData.h"
void acceptSocket(struct addr *listenAddr);

#endif