#include "Server.hpp"
#include <iostream>

// ===== PARTIE C : commandes operateur (KICK / INVITE / TOPIC / MODE) =====
// La plupart exigent que le client soit operateur du channel (isOperator).

// A faire : ejecter le client cible du channel (operateur uniquement).
void  Server::handleKick(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] KICK (" << params.size() << " param)" << std::endl;
}

// A faire : inviter un client dans un channel (operateur uniquement).
void  Server::handleInvite(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] INVITE (" << params.size() << " param)" << std::endl;
}

// A faire : afficher le topic (sans argument) ou le changer (avec argument).
void  Server::handleTopic(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] TOPIC (" << params.size() << " param)" << std::endl;
}

// A faire : changer les modes du channel.
//   i = invitation seule, t = topic reserve aux ops, k = mot de passe,
//   o = donner/retirer le statut operateur, l = limite d'utilisateurs.
void  Server::handleMode(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] MODE (" << params.size() << " param)" << std::endl;
}
