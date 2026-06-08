#pragma once

#include "Client.hpp"
#include <string>
#include <vector>
#include <map>
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
        bool  receiveFromClient(int fd);
        void  removeClient(int fd);

        int                         _port;
        std::string                 _password;
        int                         _listenFd;
        std::vector<struct pollfd>  _pollFds;
        std::map<int, Client*>      _clients;
};
