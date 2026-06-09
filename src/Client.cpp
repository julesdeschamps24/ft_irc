#include "Client.hpp"

Client::Client()
    : _fd(-1), _passOk(false), _registered(false)
{}

Client::Client(int fd)
    : _fd(fd), _passOk(false), _registered(false)
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
        _writeBuffer = other._writeBuffer;
        _nickname = other._nickname;
        _username = other._username;
        _realname = other._realname;
        _passOk = other._passOk;
        _registered = other._registered;
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

void  Client::appendToWriteBuffer(const std::string& data)
{
    _writeBuffer += data;
}

const std::string&  Client::getWriteBuffer() const
{
    return(_writeBuffer);
}

bool  Client::hasDataToWrite() const
{
    return(_writeBuffer.empty() == false);
}

void  Client::consumeWriteBuffer(std::string::size_type n)
{
    _writeBuffer.erase(0, n);
}

const std::string&  Client::getNickname() const
{
    return(_nickname);
}

void  Client::setNickname(const std::string& nickname)
{
    _nickname = nickname;
}

const std::string&  Client::getUsername() const
{
    return(_username);
}

void  Client::setUsername(const std::string& username)
{
    _username = username;
}

const std::string&  Client::getRealname() const
{
    return(_realname);
}

void  Client::setRealname(const std::string& realname)
{
    _realname = realname;
}

bool  Client::isPassOk() const
{
    return(_passOk);
}

void  Client::setPassOk(bool value)
{
    _passOk = value;
}

bool  Client::isRegistered() const
{
    return(_registered);
}

void  Client::setRegistered(bool value)
{
    _registered = value;
}
