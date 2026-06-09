#include "Server.hpp"
#include <iostream>

// ===== PARTIE B : messagerie & connexion (PRIVMSG / PING / QUIT) =====

// A faire : envoyer le message a la cible.
// params[0] = destinataire (un pseudo OU un channel #xxx), params[1] = le texte.
// Si c'est un channel -> renvoyer le message a TOUS ses membres (sauf l'auteur).
void  Server::handlePrivmsg(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] PRIVMSG (" << params.size() << " param)" << std::endl;
}

// EXEMPLE d'utilisation de sendToClient (tu peux affiner le format RFC exact).
// Le client envoie "PING <token>", le serveur doit repondre "PONG <token>".
void  Server::handlePing(Client& client, const std::vector<std::string>& params)
{
    if(params.empty())
        return;
    sendToClient(client, "PONG :" + params[0] + "\r\n");
}

// A faire : prevenir les channels du client qu'il part, puis le deconnecter.
void  Server::handleQuit(Client& client, const std::vector<std::string>& params)
{
    std::cout << "[#" << client.getFd() << "] QUIT (" << params.size() << " param)" << std::endl;
}
