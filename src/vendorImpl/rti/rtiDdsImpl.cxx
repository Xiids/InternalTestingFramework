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
bool RtiDdsWriter<T>::waitForPong()
{
    std::cout << "waitForPong ...." << std::endl;
    while (!writer.publication_matched_status().current_count())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

template <typename T>
RtiDdsReader<T>::RtiDdsReader(const dds::sub::DataReader<T> &_reader) : reader(_reader)
{
}

template <typename T>
RtiDdsImplement<T>::RtiDdsImplement() : _participant(dds::core::null),
                                        _publisher(dds::core::null),
                                        _subscriber(dds::core::null),
                                        _topic(dds::core::null),
                                        _writer(dds::core::null),
                                        _reader(dds::core::null)
{
    std::cout << "Hello RtiDdsImplement()" << std::endl;
}

template <typename T>
bool RtiDdsImplement<T>::initialize()
{
    _participant = dds::domain::DomainParticipant(0);
    _publisher = dds::pub::Publisher(_participant);
    _subscriber = dds::sub::Subscriber(_participant);

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

template <typename T>
std::shared_ptr<CommunicationReader>
RtiDdsImplement<T>::create_reader(const std::string &topicName, std::shared_ptr<pongReceiveCB> pongReceiveCB_)
{
    pongReceiveCB_->processMessage();
    _topic = dds::topic::Topic<T>(_participant, topicName);

    auto listener = std::make_shared<plainReceiverListener<T>>(pongReceiveCB_);

    _reader = dds::sub::DataReader<T>(this->_subscriber,
                                      this->_topic,
                                      dds::sub::qos::DataReaderQos(),
                                      listener,
                                      dds::core::status::StatusMask::data_available());

    return std::make_shared<RtiDdsReader<T>>(_reader);
}
