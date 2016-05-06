struct userConnectInfo
{
	int userID;
	Socket* userSock;
	userConnectInfo(int _userid,Socket* _usersock):userID(_userid),userSock(_usersock){};
}