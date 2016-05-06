#include<map>
#include<queue>

std::map<int,int> id2sockfd;
std::queue<int> unProcessfd;
const int maxEPOLL = 1024;
int addSocketfd(int fd)
{}