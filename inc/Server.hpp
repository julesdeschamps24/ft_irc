#pragma once

#include <string>
#include <vector>
#include <poll.h>

class Server
{
    public:
        Server();
        Server(int port, const std::string& password);
        Server(const Server& copy);
        Server& operator=(const Server& other);
        ~Server();

        void  setup();
        void  run();

    private:
        void  acceptClient();

        int                         _port;
        std::string                 _password;
        int                         _listenFd;
        std::vector<struct pollfd>  _pollFds;
        std::vector<int>            _clientFds;
};
