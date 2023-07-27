##ifndef TestServer_hpp
#define TestServer_hpp 

#include <stdio.h>
#include "SimpleServer.hpp"
#include <unistd.h>
namespace http
{
	class TestServer: public SimpleServer
	{
	private: 
		char buffer[30000]={0};
		int new_socket;
		void acceptor();
		void handler();
		void responder();

	public:
		TestServer();
		~TestServer();
		void launch();
	};
}

#endif