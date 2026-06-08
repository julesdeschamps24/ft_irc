#include "Message.hpp"

Message  parseMessage(const std::string& line)
{
    Message                 msg;
    std::string::size_type  i = 0;
    std::string::size_type  len = line.size();
    std::string::size_type  start;

    while(i < len && line[i] == ' ')
        i++;

    if(i < len && line[i] == ':')
    {
        i++;
        start = i;
        while(i < len && line[i] != ' ')
            i++;
        msg.prefix = line.substr(start, i - start);
    }

    while(i < len && line[i] == ' ')
        i++;
    start = i;
    while(i < len && line[i] != ' ')
        i++;
    msg.command = line.substr(start, i - start);

    while(i < len)
    {
        while(i < len && line[i] == ' ')
            i++;
        if(i >= len)
            break;
        if(line[i] == ':')
        {
            i++;
            msg.params.push_back(line.substr(i));
            break;
        }
        start = i;
        while(i < len && line[i] != ' ')
            i++;
        msg.params.push_back(line.substr(start, i - start));
    }
    return(msg);
}
