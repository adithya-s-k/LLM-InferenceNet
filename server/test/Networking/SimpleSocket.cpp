#include <SimpleSocket.hpp>

http:SimpleSocket::SimpleSocket(int domain,int service,int protocol,int port,u_long interface)
{
	// Define address structure 
	address.sin_family=domain;
	address.sin_port=htons(port);
	address.sin_addr.s_addr = htonl(interface);

	// Establish socket
	sock=socket(domain,service,protocol);
	test_connection(sock)

	// Establish network connection
	connection = connect_to_network(sock,address);
	test_connection(connection);
}


void http::SimpleSocket::test_connection(int item)
{
	if (item<0)
	{
		std::cout<<"failed to connect to socket"<<std::endl;
		exit(1);
	}
}

struct sockaddr_in http::SimpleSocket::get_address()
{
	
}