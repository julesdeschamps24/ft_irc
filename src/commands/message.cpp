#include "Server.hpp"
#include <iostream>

// TODO (B): forward the message to the target client / channel members
void  Server::handlePrivmsg(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PRIVMSG (" << params.size() << " param)" << std::endl;
}

// TODO (B): reply with PONG <token>
void  Server::handlePing(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PING (" << params.size() << " param)" << std::endl;
}

// TODO (B): notify channels, then disconnect the client
void  Server::handleQuit(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] QUIT (" << params.size() << " param)" << std::endl;
}
