#pragma once

#include <string>

class Client
{
    public:
        Client();
        Client(int fd);
        Client(const Client& copy);
        Client& operator=(const Client& other);
        ~Client();

        int                 getFd() const;
        const std::string&  getReadBuffer() const;
        void                appendToReadBuffer(const std::string& data);

    private:
        int          _fd;
        std::string  _readBuffer;
};
