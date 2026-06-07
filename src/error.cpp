#include "error.hpp"
#include <stdexcept>
#include <cstring>
#include <cerrno>

int  errorReturn(const std::string& msg, int status)
{
    std::cerr << msg << std::endl;
    return(status);
}

void  throwSystemError(const std::string& call)
{
    throw std::runtime_error(call + ": " + std::strerror(errno));
}
