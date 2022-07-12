#include <iostream>
#include <string>

#include "../header/Client.h"

using namespace Clnt;

Client::Client(){
    int init = Client::InitClientSocket();
    if(init != 0){
        std::cout<<"Error initializing client.\n";
    } else {
        Client::Run();
    }

}

Client::~Client(){
    Client::DesClientSocket();
}

int Client::InitClientSocket(){
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if ((client_fd
         = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    return 0;

}

void Client::DesClientSocket(){
    IsRunning = false;
    close(client_fd);
}


void Client::Run(){
    while(IsRunning){
        std::string hello = "Hello from client";
        char buffer[1024] = { 0 };

        send(sock, hello.c_str(), strlen(hello.c_str()), 0);
        printf("Hello message sent\n");
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }
}