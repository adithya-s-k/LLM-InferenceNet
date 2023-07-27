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
	public:
		// constructor
		SimpleSocket(int domain,int service,int protocol,int port,u_long interface)
		~SimpleSocket();
		// virtual function to connect to network
		virtual int connect_to_network(int sock,struct socket_adder_in address)=0;

		// function to test socket
		void test_connection(sock);

		// getter functions
		struct sockaddr_in get_address();
		int get_sock();

		// setter functions 
		void set_connection(int con);
	};
}



#endif