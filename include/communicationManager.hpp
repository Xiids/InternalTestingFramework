#ifndef COMMUNICATION_MANAGER_HPP
#define COMMUNICATION_MANAGER_HPP

#include <string>
#include <memory>

class CommunicationWriter
{
public:
    virtual ~CommunicationWriter() = default;

    /*IF We need to distinguish between synchronous and asynchronous sending?*/
    virtual bool SyncSend() = 0;
    virtual bool ASyncSend() = 0;
};

class CommunicationManager
{
public:
    virtual ~CommunicationManager() = default;

    /**
     * The initialize method allows different middleware to be initialized based on the user-provided parameters.
     */
    virtual bool initialize() = 0;

    virtual std::string print_configuration() = 0;

    virtual std::shared_ptr<CommunicationWriter> create_writer() = 0;
};
#endif