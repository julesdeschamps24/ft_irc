#include "Server.hpp"
#include <iostream>

// TODO (C): create the channel if needed, add the client, broadcast the JOIN
void  Server::handleJoin(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] JOIN (" << params.size() << " param)" << std::endl;
}

// TODO (C): remove the client from the channel, broadcast the PART
void  Server::handlePart(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PART (" << params.size() << " param)" << std::endl;
}
