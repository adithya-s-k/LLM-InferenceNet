#include "TestServer.hpp"

http::TestServer::TestServer():SimpleServer(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10)
{
	launch();
}

void http::TestServer::acceptor()
{

	struct sockaddr_in address=get_sock()->get_address();
	int add_len=sizeof(address);
	new_socket=accept(get_sock()->get_sock(),(struct sockaddr_in*)&address,(socklen_t*)&add_len);
	read(new_socket,buffer,30000);

}


void http::TestServer::handler()
{
	std::cout<<buffer<<std::endl;
}

void http::TestServer::responder()
{
	char *hello="hello world";
	write(new_socket,hello,strlen(hello));
	close(new_socket);
}

void http::TestServer::launch()
{
	while(true)
	{
		std::cout<<"=====waiting====="<<std::endl;
		acceptor();
		handler();
		responder();
		std::cout<<"======session terminated======"<<std::endl;
	}
}