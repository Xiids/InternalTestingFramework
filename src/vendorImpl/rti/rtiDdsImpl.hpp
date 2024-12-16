#ifndef RTI_DDS_IMPL
#define RTI_DDS_IMPL

#include <include/communicationManager.hpp>

// include both the standard APIs and rti extensions
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include "test.hpp"

template <typename T>
class RtiDdsWriter : public CommunicationWriter
{
public:
    RtiDdsWriter(const dds::pub::DataWriter<T> &_writer);
    int SyncSend() override;

protected:
    dds::pub::DataWriter<T> writer;
};

template <typename T>
class RtiDdsImplement : public CommunicationManager
{
public:
    RtiDdsImplement();

    bool initialize() override;

    std::string print_configuration() override;

    std::shared_ptr<CommunicationWriter> create_writer(const std::string &topicName) override;

    // protected:
    dds::domain::DomainParticipant _participant;
    dds::pub::Publisher _publisher;
    dds::topic::Topic<T> _topic;
    dds::pub::DataWriter<T> _writer;
};

extern template class RtiDdsImplement<::TestType>;
template class RtiDdsImplement<::TestType>;

#endif