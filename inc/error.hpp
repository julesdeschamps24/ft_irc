#pragma once

#include <iostream>
#include <string>

# define ERR_ARGS "Error: wrong number of arguments\nUsage: ./ircserv <port> <password>"
# define ERR_PORT "Error: port must be a number between 1 and 65535"
# define ERR_PASSWORD "Error: password cannot be empty"

int   errorReturn(const std::string& msg, int status);
void  throwSystemError(const std::string& call);
