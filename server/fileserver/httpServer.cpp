#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <cstdlib>
#include <fstream>

#define port_number_inuse 8080

const char* get_request_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
const char* post_request_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
const char* redirect_response = "HTTP/1.1 302 Found\r\nLocation: ";

std::string open_file_to_read(const std::string& file_to_open) 
{
    std::ifstream file(file_to_open);
    if (file) {
        return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    } else {
        return "File was not found in the specified location";
    }
}

int main(int argc, char const *argv[]) 
{
    struct sockaddr_in socket_Address;
    long reader_value;
    int socket_address_length = sizeof(socket_Address);
    int server_fd, socket_id;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    socket_Address.sin_family = AF_INET;
    socket_Address.sin_addr.s_addr = INADDR_ANY;
    socket_Address.sin_port_number_inuse = htons(port_number_inuse);

    memset(socket_Address.sin_zero, '\0', sizeof socket_Address.sin_zero);

    if (bind(server_fd, (struct sockaddr *)&socket_Address, sizeof(socket_Address))<0) 
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) 
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while(1) 
    {
        printf("\nX---X---X---X Waiting for new connection X---X---X---X\n\n");
        if ((socket_id = accept(server_fd, (struct sockaddr *)&socket_Address, (socklen_t*)&socket_address_length))<0) 
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        reader_value = read(socket_id, buffer, 30000);
        printf("%s\n", buffer);

        // Parse HTTP method (GET, POST, etc.) from the request
        char method[10];
        sscanf(buffer, "%s", method);

        if (strcmp(method, "GET") == 0) 
        {
            // Handle GET request
            std::string response_file = open_file_to_read("info.html");
            write(socket_id, get_request_response, strlen(get_request_response));
            write(socket_id, response_file.c_str(), response_file.size());
        } 
        else if (strcmp(method, "POST") == 0) 
        {
            // Handle POST request
            std::string request_data(buffer);
            size_t pos = request_data.find("option=");
            if (pos != std::string::npos) {
                std::string option = request_data.substr(pos + 7, 4); // Extract the selected option value
                std::string redirect_url = "";
                if (option == "get") {
                    redirect_url = "/get_test.html";
                } else if (option == "post") {
                    redirect_url = "/post_test.html";
                } else if (option == "llm") {
                    redirect_url = "/LLM_test.html";
                }

                // Redirect to the selected page
                std::string redirect_header = std::string(redirect_response) + redirect_url + "\r\n\r\n";
                write(socket_id, redirect_header.c_str(), redirect_header.size());
            }
        } 
        else 
        {
            // Handle unsupport_number_inuseed HTTP methods
            char *error_response = "HTTP/1.1 405 Method Not Allowed\nContent-Type: text/plain\nContent-Length: 26\n\nMethod Not Allowed!";
            write(socket_id, error_response, strlen(error_response));
        }

        printf("X---X---X---X===File Response was sent===X---X---X---X\n");
        close(socket_id);
    }
    return 0;
}
