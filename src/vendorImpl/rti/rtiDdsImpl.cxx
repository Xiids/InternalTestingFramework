#include <src/vendorImpl/rti/rtiDdsImpl.hpp>

#include <iostream>

template <typename T>
RtiDdsWriter<T>::RtiDdsWriter(const dds::pub::DataWriter<T> &_writer) : writer(_writer)
{
}

template <typename T>
int RtiDdsWriter<T>::SyncSend(const TestMessage &message_)
{
    T _data;
    _data.timestamp_sec(message_.timestamp_sec);
    _data.timestamp_usec(message_.timestamp_usec);
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

    return true;
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

/**
 * RTI on_data_available callback function implementation
 */
template <typename T>
void plainReceiverListener<T>::on_data_available(dds::sub::DataReader<T> &reader)
{
    dds::sub::LoanedSamples<T> samples = reader.take();

    for (const auto &sample : samples)
    {
        if (sample.info().valid())
        {
            const T &data = sample.data();
            this->_message.timestamp_sec = data.timestamp_sec();
            this->_message.timestamp_usec = data.timestamp_usec();
            this->_callback->processMessage(this->_message);
        }
    }
}

/**
 * Common methods for creating RTI DDS Reader
 */
template <typename T>
std::shared_ptr<CommunicationReader>
RtiDdsImplement<T>::create_reader(const std::string &_topicName, std::shared_ptr<interReceiveCB> _pongReceiveCB)
{
    try
    {
        _topic = dds::topic::Topic<T>(_participant, _topicName);

        auto listener = std::make_shared<plainReceiverListener<T>>(_pongReceiveCB);

        _reader = dds::sub::DataReader<T>(this->_subscriber,
                                          this->_topic,
                                          dds::sub::qos::DataReaderQos(),
                                          listener,
                                          dds::core::status::StatusMask::data_available());

        return std::make_shared<RtiDdsReader<T>>(_reader);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error creating RTI DDS Reader: " << e.what() << std::endl;
        throw;
    }
}
