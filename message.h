#ifndef _MESSAGE_H
#define _MESSAGE_H
#include<string.h>
const unsigned int MaxMessage=65535;
struct message
{
  char type;
  unsigned int msgLength;
  char msg[MaxMessage];
};
int getLoginMsg(unsigned int id,char PassWord[],char Dest[],unsigned int len);
int getLoginInfo(char InfoStr[],unsigned int,unsigned int& id,char password[],unsigned int len);
class message_control
{
 private:
  message_control(){}
 public:
  static int msg2char(char *,unsigned,const message&);
  //change the return pointer to use the share_ptr release the memory
  static share_ptr<message> char2msg(char *,unsigned);
 
};
#endif
