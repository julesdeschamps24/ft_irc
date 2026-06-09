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
        bool                extractLine(std::string& line);

        void                appendToWriteBuffer(const std::string& data);
        const std::string&  getWriteBuffer() const;
        bool                hasDataToWrite() const;
        void                consumeWriteBuffer(std::string::size_type n);

        const std::string&  getNickname() const;
        void                setNickname(const std::string& nickname);
        const std::string&  getUsername() const;
        void                setUsername(const std::string& username);
        const std::string&  getRealname() const;
        void                setRealname(const std::string& realname);
        bool                isPassOk() const;
        void                setPassOk(bool value);
        bool                isRegistered() const;
        void                setRegistered(bool value);

    private:
        int          _fd;
        std::string  _readBuffer;
        std::string  _writeBuffer;
        std::string  _nickname;
        std::string  _username;
        std::string  _realname;
        bool         _passOk;
        bool         _registered;
};
