#ifndef RTI_DDS_IMPL
#define RTI_DDS_IMPL

#include <include/communicationManager.hpp>

// include both the standard APIs and rti extensions
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include "test.hpp"

#include <chrono>
#include <thread>
#include <stdexcept>

template <typename T>
class RtiDdsWriter : public CommunicationWriter
{
public:
    RtiDdsWriter(const dds::pub::DataWriter<T> &_writer);
    int SyncSend(const TestMessage &message_) override;

    bool waitForPong() override;

protected:
    dds::pub::DataWriter<T> writer;
};

template <typename T>
class RtiDdsReader : public CommunicationReader
{
public:
    RtiDdsReader(const dds::sub::DataReader<T> &_reader);
    // int SyncSend() override;

protected:
    dds::sub::DataReader<T> reader;
};

/**
 * @brief RTI DDS Implementation

 * @param[in] NA.
 * @return NA.
 */
template <typename T>
class RtiDdsImplement : public CommunicationManager
{
public:
    RtiDdsImplement();

    bool initialize() override;

    std::string print_configuration() override;

    std::shared_ptr<CommunicationWriter> create_writer(const std::string &topicName) override;

    std::shared_ptr<CommunicationReader> create_reader(const std::string &topicName, std::shared_ptr<interReceiveCB> pongReceiveCB_) override;

private:
    dds::domain::DomainParticipant _participant;
    dds::pub::Publisher _publisher;
    dds::sub::Subscriber _subscriber;
    dds::topic::Topic<T> _topic;
    dds::pub::DataWriter<T> _writer;
    dds::sub::DataReader<T> _reader;
};

/**
 * reader listener
 * For future scalability to support types like flat and zero-copy.
 */
template <typename T>
class ReceiverListenerBase : public dds::sub::NoOpDataReaderListener<T>
{

protected:
    TestMessage _message;
    std::shared_ptr<interReceiveCB> _callback;

public:
    ReceiverListenerBase(std::shared_ptr<interReceiveCB> callback_) : _message(),
                                                                      _callback(callback_)
    {
    }
};

/**
 * Implements ReceiverListenerBase with Plain API.
 */
template <typename T>
class plainReceiverListener : public ReceiverListenerBase<T>
{

public:
    plainReceiverListener(std::shared_ptr<interReceiveCB> callback_) : ReceiverListenerBase<T>(callback_)
    {
    }

    void on_data_available(dds::sub::DataReader<T> &reader);
};

extern template class RtiDdsImplement<::TestType>;
template class RtiDdsImplement<::TestType>;

#endif