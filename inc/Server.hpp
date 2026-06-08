#pragma once

#include "Client.hpp"
#include "Message.hpp"
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
        typedef void (Server::*HandlerType)(Client&, const std::vector<std::string>&);

        void  acceptClient();
        bool  receiveFromClient(int fd);
        void  removeClient(int fd);
        void  initHandlers();
        void  dispatch(Client& client, const Message& msg);

        void  handlePass(Client& client, const std::vector<std::string>& params);
        void  handleNick(Client& client, const std::vector<std::string>& params);
        void  handleUser(Client& client, const std::vector<std::string>& params);

        int                                 _port;
        std::string                         _password;
        int                                 _listenFd;
        std::vector<struct pollfd>          _pollFds;
        std::map<int, Client*>              _clients;
        std::map<std::string, HandlerType>  _handlers;
};
