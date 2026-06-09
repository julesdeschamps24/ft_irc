#pragma once

#include "Client.hpp"
#include "Channel.hpp"
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
        void  flushClient(int fd);
        void  removeClient(int fd);
        void  initHandlers();
        void  dispatch(Client& client, const Message& msg);
        void  sendToClient(Client& client, const std::string& message);

        // auth (commands/auth.cpp) -- B
        void  handlePass(Client& client, const std::vector<std::string>& params);
        void  handleNick(Client& client, const std::vector<std::string>& params);
        void  handleUser(Client& client, const std::vector<std::string>& params);
        // messaging & connection (commands/message.cpp) -- B
        void  handlePrivmsg(Client& client, const std::vector<std::string>& params);
        void  handlePing(Client& client, const std::vector<std::string>& params);
        void  handleQuit(Client& client, const std::vector<std::string>& params);
        // channels (commands/channel.cpp) -- C
        void  handleJoin(Client& client, const std::vector<std::string>& params);
        void  handlePart(Client& client, const std::vector<std::string>& params);
        // operators (commands/operator.cpp) -- C
        void  handleKick(Client& client, const std::vector<std::string>& params);
        void  handleInvite(Client& client, const std::vector<std::string>& params);
        void  handleTopic(Client& client, const std::vector<std::string>& params);
        void  handleMode(Client& client, const std::vector<std::string>& params);

        int                                 _port;
        std::string                         _password;
        int                                 _listenFd;
        std::vector<struct pollfd>          _pollFds;
        std::map<int, Client*>              _clients;
        std::map<std::string, Channel*>     _channels;
        std::map<std::string, HandlerType>  _handlers;
};
