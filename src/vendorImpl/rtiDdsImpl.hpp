#ifndef RTI_DDS_IMPL
#define RTI_DDS_IMPL

#include <include/communicationManager.hpp>

// include both the standard APIs and rti extensions
#include <rti/rti.hpp>

class RtiDdsWriter : public CommunicationWriter
{
public:
    bool SyncSend() override;
};

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