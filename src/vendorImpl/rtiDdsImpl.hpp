#ifndef RTI_DDS_IMPL
#define RTI_DDS_IMPL

#include <include/communicationManager.hpp>

// include both the standard APIs and rti extensions
#include <dds/pub/ddspub.hpp>

template <typename T>
class RtiDdsWriter : public CommunicationWriter
{
public:
    RtiDdsWriter(const dds::pub::Publisher &_publisher);
    bool SyncSend() override;

private:
    dds::pub::DataWriter<T> _writer;
};

template <typename T>
class RtiDdsImplement : public CommunicationManager
{
public:
    RtiDdsImplement();

    bool initialize() override;

    std::string print_configuration() override;

    std::shared_ptr<CommunicationWriter> create_writer() override;

private:
    dds::domain::DomainParticipant _participant;
    dds::sub::Subscriber _subscriber;
    dds::pub::Publisher _publisher;
};

#endif