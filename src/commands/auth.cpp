#include "Server.hpp"
#include <iostream>

void  Server::handlePass(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PASS (" << params.size() << " param)" << std::endl;
}

void  Server::handleNick(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] NICK (" << params.size() << " param)" << std::endl;
}

void  Server::handleUser(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] USER (" << params.size() << " param)" << std::endl;
}
