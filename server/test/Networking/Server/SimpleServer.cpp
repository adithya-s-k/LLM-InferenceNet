#include "SimpleServer.hpp"

http::SimpleServer::SimpleServer(int domain,int service, int protocol,int port,u_long interface,int bklog)
{
	socket=new ListeningSocket(domain,service,protocol,port,interface,bklog);
}

ListeningSocket* http::SimpleServer::get_socket()
{
	return socket;
}