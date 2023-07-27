#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>

#define PORT 8080

const char* get_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
const char* post_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
const char* redirect_response = "HTTP/1.1 302 Found\r\nLocation: ";

std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
    } else {
        return "File not found.";
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);
        printf("%s\n", buffer);

        // Parse HTTP method (GET, POST, etc.) from the request
        char method[10];
        sscanf(buffer, "%s", method);

        if (strcmp(method, "GET") == 0) {
            // Handle GET request
            std::string response = read_file("info.html");
            write(new_socket, get_response, strlen(get_response));
            write(new_socket, response.c_str(), response.size());
        } else if (strcmp(method, "POST") == 0) {
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
                write(new_socket, redirect_header.c_str(), redirect_header.size());
            }
        } else {
            // Handle unsupported HTTP methods
            char *error_response = "HTTP/1.1 405 Method Not Allowed\nContent-Type: text/plain\nContent-Length: 26\n\nMethod Not Allowed!";
            write(new_socket, error_response, strlen(error_response));
        }

        printf("------------------Response sent-------------------\n");
        close(new_socket);
    }
    return 0;
}
