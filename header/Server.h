#ifndef Server_h_
#define Server_h_

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>
#include <queue>

#define PORT 8080

namespace Serv
{

    class Server
    {
        private:
            int server_fd, new_socket, valread;
            bool IsRunning = true;
            std::thread thread_obj;

            // std::thread mThread;
            std::condition_variable mCV;
            std::mutex mMutex;
            std::queue<std::string> mQueue;
            bool mStop;

        public:
            Server(/* args */);
            ~Server();
        private:
            void InitMasterSocket();
            
            void DesMasterSocket();
            void Run();


    };
}


#endif