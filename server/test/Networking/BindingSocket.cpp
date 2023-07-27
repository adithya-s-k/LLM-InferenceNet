#include <BindingSocket.hpp>

// Constructor 

http::BindingSocket::BindingSocket(int domain,int service,int protocol,u_long interface):SimpleSocket(domain,service,protocol,interface)
{
	set_connection(connect_to_network(get_sock(),get_address()));
	test_connection(get_connection());
}

// definition of connect to network 

int http::BindingSocket::connect_to_network(int sock,struct socket_adder_in address)
{
	return bind(sock,(struct sockaddr_in*)&address,sizeof(address));
}

