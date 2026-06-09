#include "Server.hpp"
#include <iostream>

// ===== PARTIE B : enregistrement (PASS / NICK / USER) =====
// L'ordre d'enregistrement est : PASS -> NICK -> USER.
// Quand les 3 sont OK, marquer le client comme enregistre (setRegistered(true))
// et lui envoyer le message de bienvenue 001.

// A faire : comparer params[0] avec le mot de passe du serveur.
// Si correct -> client.setPassOk(true). Sinon -> erreur 464 + fermer.
void  Server::handlePass(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PASS (" << params.size() << " param)" << std::endl;
}

// A faire : definir le pseudo (params[0]) via client.setNickname(...).
// Verifier qu'il est valide et pas deja pris -> sinon erreur 431/433.
void  Server::handleNick(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] NICK (" << params.size() << " param)" << std::endl;
}

// A faire : definir username/realname (setUsername / setRealname).
// Si PASS + NICK + USER sont OK -> setRegistered(true) et envoyer le 001.
void  Server::handleUser(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] USER (" << params.size() << " param)" << std::endl;
}
