#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


#define PORT 8080

namespace Clnt
{

    class Client
    {
    private:
        /* data */
        int sock = 0, valread, client_fd;
        bool IsRunning = true;

    public:
        Client(/* args */);
        ~Client();
    private:
        int InitClientSocket();
        void DesClientSocket();
        void Run();
    };
}