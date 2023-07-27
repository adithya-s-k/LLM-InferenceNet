#include "ListeningSocket.hpp"

http::ListeningSocket::ListeningSocket(int domain,int service,int protocol,int port,u_long interface,int bklog):BindingSocket(domain,service,protocol,port,interface)
{
	backlog=bklog;
	start_listening();
	test_connection(listening);
}

void http::ListeningSocket::start_listening()
{
	listening=listen(get_sock(),backlog);
}


// getter functions

int http::ListeningSocket::get_backlog()
{
	return backlog;
}

int http::ListeningSocket::get_listening()
{
	return listening;
}