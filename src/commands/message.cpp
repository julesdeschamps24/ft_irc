#include "Server.hpp"
#include <iostream>

// TODO (B): forward the message to the target client / channel members
void  Server::handlePrivmsg(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PRIVMSG (" << params.size() << " param)" << std::endl;
}

// EXAMPLE of using sendToClient (B can refine the exact RFC format).
// A client sends "PING <token>"; the server must answer "PONG <token>".
void  Server::handlePing(Client& client, const std::vector<std::string>& params)
{
    if(params.empty())
        return;
    sendToClient(client, "PONG :" + params[0] + "\r\n");
}

// TODO (B): notify channels, then disconnect the client
void  Server::handleQuit(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] QUIT (" << params.size() << " param)" << std::endl;
}
