#include <src/vendorImpl/rti/rtiDdsImpl.hpp>

#include <iostream>

template <typename T>
RtiDdsWriter<T>::RtiDdsWriter(const dds::pub::DataWriter<T> &_writer) : writer(_writer)
{
}

template <typename T>
int RtiDdsWriter<T>::SyncSend()
{
    T _data;
    writer.write(_data);
    return 0;
}

template <typename T>
RtiDdsImplement<T>::RtiDdsImplement() : _participant(dds::core::null),
                                        _publisher(dds::core::null),
                                        _topic(dds::core::null),
                                        _writer(dds::core::null)
{
    std::cout << "Hello RtiDdsImplement()";
}

template <typename T>
bool RtiDdsImplement<T>::initialize()
{
    _participant = dds::domain::DomainParticipant(0);
    _publisher = dds::pub::Publisher(_participant);

    return false;
}

template <typename T>
std::string RtiDdsImplement<T>::print_configuration()
{
    std::string Hello("Hello RtiDdsImplement");

    return Hello;
}

template <typename T>
std::shared_ptr<CommunicationWriter>
RtiDdsImplement<T>::create_writer(const std::string &topicName)
{
    _topic = dds::topic::Topic<T>(_participant, topicName);
    _writer = dds::pub::DataWriter<T>(this->_publisher, this->_topic);
    return std::make_shared<RtiDdsWriter<T>>(_writer);
}