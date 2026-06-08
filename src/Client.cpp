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

bool  Client::extractLine(std::string& line)
{
    std::string::size_type  pos = _readBuffer.find('\n');

    if(pos == std::string::npos)
        return(false);
    line = _readBuffer.substr(0, pos);
    _readBuffer.erase(0, pos + 1);
    if(line.empty() == false && line[line.size() - 1] == '\r')
        line.erase(line.size() - 1);
    return(true);
}
