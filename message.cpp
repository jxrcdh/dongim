#include"message.h"
#include<memory.h>
int message_control::msg2char(char* buf,unsigned length,const message& msg)
{
	//if the length of the message more long than the buf, return -1;
    if(buf<(msg.msgLength+sizeof(msg.type)+sizeof(msg.msgLength)))
  	  return -1;
    memcpy(buf,&msg.type,sizeof(msg.type));
    memcpy(buf+sizeof(msg.type),&msg.msgLength,sizeof(msg.msgLength));
    memcpy(buf+sizeof(msg.type)+sizeof(msg.msgLength),&msg.msg,msg.msgLength);
    return sizeof(char)+sizeof(unsigned)+msg.msgLength;
}
share_ptr<message> message_control::char2msg(char* buf,unsigned length)
{
	if(length<(sizeof(char)+sizeof(unsigned)))
		return NULL;
	message* reciveMsg = new message();
	memcpy(&reciveMsg->type,buf,sizeof(reciveMsg->type));
	memcpy(&reciveMsg->msgLength,buf+sizeof(reciveMsg->type),sizeof(reciveMsg->msgLength));
	memcpy(reciveMsg->msg,buf+sizeof(reciveMsg->type)+sizeof(reciveMsg->msgLength),length-(sizeof(reciveMsg->type)+sizeof(reciveMsg->msgLength)));
	return share_ptr<message>(reciveMsg);
}
int getLoginMsg(unsigned int id,char PassWord[],char Dest[],unsigned int len)
{
	unsigned int passlen = strlen(PassWord);
	if((passlen+sizeof(id))>=len) return -1;
	Dest[0]=id&0xFF;
	Dest[1]=(id>>8)&0xFF;
	Dest[2]=(id>>16)&0xFF;
	Dest[3]=(id>>24)&0xFF;

	strncpy(Dest+4,PassWord,passlen);
	return passlen+4;
}
int getLoginInfo(char InfoStr[],unsigned int len,unsigned int& id,char password[],unsigned int passlen)
{
	if((passlen+sizeof(id))<=len) return -1;

	id = (unsigned int)InfoStr[0]+((unsigned int)InfoStr[1]<<8)+((unsigned int)InfoStr[2]<<16)+((unsigned int)InfoStr[3]<<24);
	strncpy(password,InfoStr+4,len-sizeof(id));
	return 0;
}