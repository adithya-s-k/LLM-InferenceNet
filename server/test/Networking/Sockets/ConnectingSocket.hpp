#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace http
{
	class ConnectingSocket: public SimpleSocket
	{
	public:
		// constructor 	
		ConnectingSocket(int domain,int service,int protocol,int port,u_long interface);
		
		~ConnectingSocket();
		
		// virtual function from the parent class
		int connect_to_network(int sock,struct socket_adder_in address);
		
	};
}


#endif