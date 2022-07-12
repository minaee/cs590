#include <iostream>
#include <string>

#include "../header/Server.h"

using namespace Serv;

Server::Server(/* args*/)
{
    Server::InitMasterSocket();
    // thread_obj = new std::thread(Run);
    thread_obj = std::thread(&Server::Run, this); //create thread and execute Run()
}

Server::~Server()
{
    DesMasterSocket();
    // thread_obj->join();
    // delete thread_obj;
    //Join thread
    if (thread_obj.joinable()) {
        thread_obj.join();
    }
}

void Server::InitMasterSocket(){
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    
  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
        == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

void Server::DesMasterSocket(){
    IsRunning = false;
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
}

void Server::Run(){
    while(IsRunning){
        
        char buffer[1024] = { 0 };

        std::string hello = "Hello from server";
        
        valread = read(new_socket, buffer, 1024);
        std::cout<<buffer<<std::endl;

        send(new_socket, hello.c_str(), strlen(hello.c_str()), 0);
        printf("Hello message sent\n");
    }
}