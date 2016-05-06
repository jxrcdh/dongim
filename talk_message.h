#ifndef _TALK_MESSAGE_H
#define _TALK_MESSAGE_H

class talk_message
{
private:
	unsigned int speaker;
	unsigned int speakto;
	char msg[4096];
	unsigned msgLength;
public:
	talk_message(){};
	int toChar(char*,unsigned len);
};
#endif