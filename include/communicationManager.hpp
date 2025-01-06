#ifndef COMMUNICATION_MANAGER_HPP
#define COMMUNICATION_MANAGER_HPP

#include <string>
#include <memory>

class TestMessage
{
public:
    int size;

    TestMessage()
        : size(0)
    {
    }
};

/**
 * The callback function for receiving data on the pong side, base class.
 */
class pongReceiveCB
{
public:
public:
    virtual ~pongReceiveCB()
    {
    }
    // virtual void process_message(TestMessage &message) = 0;
    virtual void processMessage() = 0;
};

class CommunicationWriter
{
public:
    virtual ~CommunicationWriter() = default;

    /*IF We need to distinguish between synchronous and asynchronous sending?*/
    virtual int SyncSend() = 0;
    // virtual bool ASyncSend() = 0;

    virtual bool waitForPong() = 0;
};

class CommunicationReader
{
public:
    virtual ~CommunicationReader() = default;
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

    virtual std::shared_ptr<CommunicationWriter> create_writer(const std::string &topicName) = 0;

    virtual std::shared_ptr<CommunicationReader> create_reader(const std::string &topicName) = 0;
};

#endif