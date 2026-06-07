#include "error.hpp"

int  errorReturn(const std::string& msg, int status)
{
    std::cerr << msg << std::endl;
    return(status);
}
