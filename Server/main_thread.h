#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H
#include<sys/epoll.h>
#include"../user/user_info.h"
struct Userconn_event
{
	void (*call_back)(void);
};
int system_start();
int addsockfd(int epfd,int fd,struct epoll_event *);
int create_epoll(int);
void doConnUser();

#endif