#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
#define INCLUDED_HTTP_TCPSERVER_LINUX

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

namespace http
{
    class TcpServer
    {
    public:
        TcpServer();
        ~TcpServer();
    private:
        std::string user_ip;
        int user_portno,user_socketid,user_newsocket;
        long user_incomingmsg;
        struct socket_adder_in user_socketAddress
                {
                    short socket_in_family;
                    unsigned short socket_in_port;
                    struct input_adder socket_in_adder;
                    char socket_in_zero[8];
                };
        struct input_adder
        {
            unsigned long socket_address;
        };
        unsigned int length_user_socketAddress;
        std::string user_serverMessage;

        int startServer();
        void closeServer();
    };
} // namespace http

#endif