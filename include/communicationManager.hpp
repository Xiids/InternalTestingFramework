#ifndef COMMUNICATION_MANAGER_HPP
#define COMMUNICATION_MANAGER_HPP

#include <string>

class CommunicationManager
{
public:
    virtual ~CommunicationManager() {};

    virtual std::string print_configuration() = 0;
};
#endif