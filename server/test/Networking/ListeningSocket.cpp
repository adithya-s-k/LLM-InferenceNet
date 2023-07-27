#include <ListeningSocket.hpp>

http::ListeningSocket::ListeningSocket(int domain,int service,int protocol,int port,u_long interface,int bklog):BindingSocket(domain,service,protocol,port,interface)
{
	backlog=bklog;
	start_listening();
	test_connection(listening);
}

void http::ListeningSocket::start_listening()
{
	listening=listen(get_connection(),backlog);
}