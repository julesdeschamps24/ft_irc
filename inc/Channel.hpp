#pragma once

#include "Client.hpp"
#include <string>
#include <set>

class Channel
{
    public:
        Channel();
        Channel(const std::string& name);
        Channel(const Channel& copy);
        Channel& operator=(const Channel& other);
        ~Channel();

        const std::string&  getName() const;
        const std::string&  getTopic() const;
        void                setTopic(const std::string& topic);

        void  addMember(Client* client);
        void  removeMember(Client* client);
        bool  hasMember(Client* client) const;
        bool  isEmpty() const;

        void  addOperator(Client* client);
        void  removeOperator(Client* client);
        bool  isOperator(Client* client) const;

    private:
        std::string        _name;
        std::string        _topic;
        std::set<Client*>  _members;
        std::set<Client*>  _operators;
};
