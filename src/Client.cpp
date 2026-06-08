#include "Client.hpp"

Client::Client()
    : _fd(-1)
{}

Client::Client(int fd)
    : _fd(fd)
{}

Client::Client(const Client& copy)
{
    *this = copy;
}

Client& Client::operator=(const Client& other)
{
    if(this != &other)
    {
        _fd = other._fd;
        _readBuffer = other._readBuffer;
    }
    return(*this);
}

Client::~Client() {}

int  Client::getFd() const
{
    return(_fd);
}

const std::string&  Client::getReadBuffer() const
{
    return(_readBuffer);
}

void  Client::appendToReadBuffer(const std::string& data)
{
    _readBuffer += data;
}
