#include "Channel.hpp"

Channel::Channel() {}

Channel::Channel(const std::string& name)
    : _name(name)
{}

Channel::Channel(const Channel& copy)
{
    *this = copy;
}

Channel& Channel::operator=(const Channel& other)
{
    if(this != &other)
    {
        _name = other._name;
        _topic = other._topic;
        _members = other._members;
        _operators = other._operators;
    }
    return(*this);
}

Channel::~Channel() {}

const std::string&  Channel::getName() const
{
    return(_name);
}

const std::string&  Channel::getTopic() const
{
    return(_topic);
}

void  Channel::setTopic(const std::string& topic)
{
    _topic = topic;
}

void  Channel::addMember(Client* client)
{
    _members.insert(client);
}

void  Channel::removeMember(Client* client)
{
    _members.erase(client);
    _operators.erase(client);
}

bool  Channel::hasMember(Client* client) const
{
    return(_members.find(client) != _members.end());
}

bool  Channel::isEmpty() const
{
    return(_members.empty());
}

void  Channel::addOperator(Client* client)
{
    _operators.insert(client);
}

void  Channel::removeOperator(Client* client)
{
    _operators.erase(client);
}

bool  Channel::isOperator(Client* client) const
{
    return(_operators.find(client) != _operators.end());
}
