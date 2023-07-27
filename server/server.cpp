#include <iostream>
#include <string>
using namespace std;

struct request
{
	string query;
	int priority;
};

struct request_list // to host a list of all the requests that come into picture
{
	request req;
	request_list *next;
}

class request_queue
{
private:
	request_list *list_start;
	request_list *list_end;
public:
	void request_Add(request *r)  // function that is called everytime there is a new incoming request 
	{
		request_list *temp;
		temp->req=r;
		temp->next=NULL;
		if(!list_start)
		{
			list_start= list_end = temp;
		}
		else
		{
			list_end->next=temp;
			list_end=list_end->next;
		}
	}
	void request_Remove(request *r) // function that is called everytime a sever request is completed 
	{
		request_list *prev,*current=list_start;
		while (current!=r)
		{
			prev=current
			current=current->next;
		}
		prev->next=current->next;
		current->next=NULL;
		free(current);
	}

};

int main(int argc, char const *argv[])
{
	using namespace http;
	TcpServer server= TcpServer("0.0.0.0",8080);
	return 0;
}