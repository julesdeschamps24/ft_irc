#include "Server.hpp"
#include <iostream>

// TODO (C): eject the target client from the channel (operator only)
void  Server::handleKick(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] KICK (" << params.size() << " param)" << std::endl;
}

// TODO (C): invite a client to a channel (operator only)
void  Server::handleInvite(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] INVITE (" << params.size() << " param)" << std::endl;
}

// TODO (C): view or change the channel topic
void  Server::handleTopic(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] TOPIC (" << params.size() << " param)" << std::endl;
}

// TODO (C): change channel modes i/t/k/o/l (operator only)
void  Server::handleMode(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] MODE (" << params.size() << " param)" << std::endl;
}
