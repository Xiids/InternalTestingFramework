#ifndef RTI_DDS_IMPL
#define RTI_DDS_IMPL

#include <include/communicationManager.hpp>

class RtiDdsImplement : public CommunicationManager
{
public:
    std::string print_configuration() override;
};

#endif