#ifndef Server_h_
#define Server_h_

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>

#define PORT 8080

namespace Serv
{

    class Server
    {
        private:
            int server_fd, new_socket, valread;
            bool IsRunning = true;
            std::thread* thread_obj;

        public:
            Server(/* args */);
            ~Server();
        private:
            void InitMasterSocket(){
                struct sockaddr_in address;
            };
            
            void DesMasterSocket();
            void Run();


    };
}


#endif