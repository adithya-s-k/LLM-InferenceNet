#ifndef SimpleSocket
#define SimpleSocket

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace http
{
	class SimpleSocket
	{
	private:
		struct sockaddr_in address;
		int sock;
		int connection;
	public:
		// constructor
		SimpleSocket(int domain,int service,int protocol,int port,u_long interface)
		~SimpleSocket();
		// virtual function to connect to network
		virtual connect_to_network(int sock,struct socket_adder_in address)=0;
		void test_connection(sock);
		struct sockaddr_in get_address();
		int get_sock();
		int get_connection();
	};
}



#endif