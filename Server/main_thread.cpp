#include"main_thread.h"
#include"shareData.h"

extern const int maxEPOLL;

int create_epoll(int size)
{
	return epoll_create(size);
}
int system_start()
{
	//do some check

	//see if the queue has a hasn't processed socket
	int epfd = create_epoll(maxEPOLL);
	while(true)
	{
		while(!unProcessfd.empty())
		{

		}
	}
}