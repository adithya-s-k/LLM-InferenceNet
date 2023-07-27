##ifndef ListeningSocket_hpp
#define ListeningSocket_hpp 

#include <stdio.h>
#include "BindingSocket.hpp"

namespace http
{
	class ListeningSocket: public BindingSocket
	{
	private:
		int backlog;
		int listening;
	public:
		// constructor 
		ListeningSocket(int domain,int service,int protocol,int port,u_long interface,int bklog);
		void start_listening();
		~ListeningSocket();
		// getter functions
		int get_backlog();
		int get_listening();
		
	};
}

#endif