#include <src/vendorImpl/rtiDdsImpl.hpp>

#include <iostream>

RtiDdsImplement::RtiDdsImplement() : _participant(dds::core::null),
                                     _subscriber(dds::core::null),
                                     _publisher(dds::core::null)
{
}

bool RtiDdsImplement::initialize()
{
    /*创建一个临时的DomainParticipant对象，并在RtiDdsImplement初始化的时候赋值给成员对象_participant*/
    _participant = dds::domain::DomainParticipant(0);
}

std::string
RtiDdsImplement::print_configuration()
{
    std::string Hello("Hello RtiDdsImplement");
    std::cout << Hello << std::endl;
    return Hello;
}