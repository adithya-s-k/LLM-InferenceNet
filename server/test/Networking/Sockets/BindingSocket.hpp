#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include<stdio.h>
#include "SimpleSocket.hpp"

namespace http
{
	class BindingSocket:public SimpleSocket
	{
	public:
		// constructor 
		BindingSocket(int domain,int service,int protocol,int port,u_long interface);
		
		~BindingSocket();
		
		// virtual function from the parent class
		int connect_to_network(int sock,struct socket_adder_in address);
	};
}

#endif