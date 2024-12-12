#include <src/vendorImpl/rtiDdsImpl.hpp>

#include <iostream>

template <typename T>
RtiDdsWriter<T>::RtiDdsWriter(const dds::pub::Publisher &_publisher) : _writer(_publisher)
{
}

template <typename T>
RtiDdsImplement<T>::RtiDdsImplement() : _participant(dds::core::null),
                                        _subscriber(dds::core::null),
                                        _publisher(dds::core::null)
{
}

template <typename T>
bool RtiDdsImplement<T>::initialize()
{
    _participant = dds::domain::DomainParticipant(0);
    _publisher = dds::pub::Publisher(_participant);
}

template <typename T>
std::string RtiDdsImplement<T>::print_configuration()
{
    std::string Hello("Hello RtiDdsImplement");

    return Hello;
}

template <typename T>
std::shared_ptr<CommunicationWriter> RtiDdsImplement<T>::create_writer()
{
    return std::make_shared<RtiDdsWriter<T>>(_publisher);
}