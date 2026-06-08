#include "Server.hpp"
#include "error.hpp"
#include "Message.hpp"
#include <iostream>
#include <cstring>
#include <cctype>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

Server::Server()
    : _port(0), _password(""), _listenFd(-1)
{}

Server::Server(int port, const std::string& password)
    : _port(port), _password(password), _listenFd(-1)
{
    initHandlers();
}

Server::Server(const Server& copy)
{
    *this = copy;
}

Server& Server::operator=(const Server& other)
{
    if(this != &other)
    {
        _port = other._port;
        _password = other._password;
        _listenFd = other._listenFd;
        _pollFds = other._pollFds;
        _clients = other._clients;
        _handlers = other._handlers;
    }
    return(*this);
}

Server::~Server()
{
    std::map<int, Client*>::iterator  it;

    for(it = _clients.begin(); it != _clients.end(); ++it)
    {
        close(it->first);
        delete it->second;
    }
    if(_listenFd != -1)
        close(_listenFd);
}

void  Server::setup()
{
    _listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if(_listenFd < 0)
        throwSystemError("socket");

    int opt = 1;
    if(setsockopt(_listenFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
        throwSystemError("setsockopt");

    if(fcntl(_listenFd, F_SETFL, O_NONBLOCK) < 0)
        throwSystemError("fcntl");

    struct sockaddr_in  addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(_port);

    if(bind(_listenFd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        throwSystemError("bind");

    if(listen(_listenFd, SOMAXCONN) < 0)
        throwSystemError("listen");

    std::cout << "ircserv listening on port " << _port << std::endl;
}

void  Server::acceptClient()
{
    int  clientFd = accept(_listenFd, NULL, NULL);
    if(clientFd < 0)
        return;
    fcntl(clientFd, F_SETFL, O_NONBLOCK);

    _clients[clientFd] = new Client(clientFd);

    struct pollfd  pfd;
    pfd.fd = clientFd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    _pollFds.push_back(pfd);

    std::cout << "client connected #" << clientFd << std::endl;
}

bool  Server::receiveFromClient(int fd)
{
    char     buf[4096];
    ssize_t  r = recv(fd, buf, sizeof(buf), 0);

    if(r <= 0)
        return(false);
    _clients[fd]->appendToReadBuffer(std::string(buf, r));

    std::string  line;
    while(_clients[fd]->extractLine(line))
        dispatch(*_clients[fd], parseMessage(line));
    return(true);
}

void  Server::removeClient(int fd)
{
    close(fd);
    delete _clients[fd];
    _clients.erase(fd);
    for(size_t i = 0; i < _pollFds.size(); i++)
    {
        if(_pollFds[i].fd == fd)
        {
            _pollFds.erase(_pollFds.begin() + i);
            break;
        }
    }
    std::cout << "client #" << fd << " disconnected" << std::endl;
}

void  Server::initHandlers()
{
    _handlers["PASS"] = &Server::handlePass;
    _handlers["NICK"] = &Server::handleNick;
    _handlers["USER"] = &Server::handleUser;
}

void  Server::dispatch(Client& client, const Message& msg)
{
    if(msg.command.empty())
        return;

    std::string  cmd = msg.command;
    for(size_t i = 0; i < cmd.size(); i++)
        cmd[i] = std::toupper(static_cast<unsigned char>(cmd[i]));

    std::map<std::string, HandlerType>::iterator  it = _handlers.find(cmd);
    if(it == _handlers.end())
    {
        std::cout << "[#" << client.getFd() << "] unknown command: " << msg.command << std::endl;
        return;
    }
    (this->*(it->second))(client, msg.params);
}

void  Server::run()
{
    struct pollfd  listenPfd;

    listenPfd.fd = _listenFd;
    listenPfd.events = POLLIN;
    listenPfd.revents = 0;
    _pollFds.push_back(listenPfd);

    while(true)
    {
        if(poll(&_pollFds[0], _pollFds.size(), -1) < 0)
            throwSystemError("poll");

        std::vector<int>  toRemove;
        size_t            n = _pollFds.size();

        for(size_t i = 0; i < n; i++)
        {
            if((_pollFds[i].revents & POLLIN) == 0)
                continue;
            if(_pollFds[i].fd == _listenFd)
                acceptClient();
            else if(receiveFromClient(_pollFds[i].fd) == false)
                toRemove.push_back(_pollFds[i].fd);
        }
        for(size_t i = 0; i < toRemove.size(); i++)
            removeClient(toRemove[i]);
    }
}
