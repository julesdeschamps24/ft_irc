#include "Server.hpp"
#include <iostream>

// ===== PARTIE C : channels (JOIN / PART) =====

// A faire : creer le channel s'il n'existe pas (dans _channels), ajouter le client
// comme membre, prevenir tous les membres qu'il a rejoint, et lui envoyer le topic.
void  Server::handleJoin(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] JOIN (" << params.size() << " param)" << std::endl;
}

// A faire : retirer le client du channel et prevenir les autres membres (PART).
void  Server::handlePart(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PART (" << params.size() << " param)" << std::endl;
}
