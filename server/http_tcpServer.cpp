#include <http_tcpServer.h>
#include <iostream>
#include <sstream>
#include <unistd.h>


namespace
{
	void log(const std::string& user_message)
	{
		std::cout<<user_message<<endl;
	}

	void ErrorExitCode(const std::string& server_error_message)
	{
		log("Error: "+server_error_message);
		exit(1);
	}
}

namespace http
{

	TcpServer::TcpServer(std::string ip,int portno): user_ip(ip),user_portno(portno),user_socketid(),user_newsocket(),user_incomingmsg(),lenght_user_socketAddress(sizeof(user_socketAddress)),user_serverMessage(buildResponse())
	{
		startServer();
	}

	int TcpServer::startServer()
	{
		user_socketid=socket(AF_INET, SOCK_STREAM,0);
		if (user_socketid<0)
		{
			ErrorExitCode("Socket could not be created");
			return 1;
		}
		return 0;
	}
	void TcpServer::closeServer()
	{
		close(user_socketid);
		close(user_newsocket);
		exit(0);
	}
	
	void TcpServer::startListen()
	{
	    if (listen(user_socketid, 20) < 0)
	    {
	        exitWithError("Socket listen failed");
	    }
	    std::ostringstream ss;
	    ss << "\n*** Listening on ADDRESS: " 
	        << inet_ntoa(user_socketAddress.sin_addr) 
	        << " PORT: " << ntohs(user_socketAddress.sin_port) 
	        << " ***\n\n";
	    log(ss.str());
	}

	void TcpServer::acceptConnection(SOCKET &new_socket)
	{
	    new_socket = accept(user_socketid, (input_adder *)&user_socketAddress, 
	                        &lenght_user_socketAddress);
	    if (new_socket < 0)
	    {
	        std::ostringstream ss;
	        ss << 
	        "Server failed to accept incoming connection from ADDRESS: " 
	        << inet_ntoa(user_socketAddress.sin_addr) << "; PORT: " 
	        << ntohs(user_socketAddress.sin_port);
	        exitWithError(ss.str());
	    }
	}

	TcpServer::~TcpServer()
	{
		closeServer();
	}

} //namespace http