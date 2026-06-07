#include "error.hpp"
#include <iostream>
#include <sstream>
#include <string>

static bool parsePort(const std::string& arg, int& port)
{
    std::istringstream iss(arg);

    iss >> port;
    if(iss.fail() || iss.eof() == false)
        return(false);
    if(port < 1 || port > 65535)
        return(false);
    return(true);
}

int main(int ac, char **av)
{
    if(ac != 3)
        return(errorReturn(ERR_ARGS, 1));

    int port;
    if(parsePort(av[1], port) == false)
        return(errorReturn(ERR_PORT, 1));

    std::string password = av[2];
    if(password.empty())
        return(errorReturn(ERR_PASSWORD, 1));

    std::cout << "ircserv will listen on port " << port
        << " with password \"" << password << "\"" << std::endl;
    return(0);
}
