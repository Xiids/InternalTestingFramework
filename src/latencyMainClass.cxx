#include <include/latencyMainClass.hpp>
#include <include/timeSppport.hpp>

bool latencyMainClass::runTest(int argc, char *argv[])
{
    _parameterHander = std::make_shared<CommandParameterHanding>();

    std::variant<int> param1 = argc;
    std::vector<char *> param2(argv, argv + argc);
    std::variant<std::vector<char *>> varParam2 = param2;

    _parameterHander->processParameter(param1, varParam2);

    if (_parameterHander->isPrintConfig())
        _parameterHander->printArgsConfig();

    if (!(_manager = std::make_shared<RtiDdsImplement<::TestType>>()))
    {
        std::cout << "Failed to create test object" << std::endl;
        return false;
    }

    _manager->initialize();

    [&]()
    {
        (this->*(_parameterHander->isPing() ? &latencyMainClass::runPing : &latencyMainClass::runPong))();
    }();

    return true;
}

bool latencyMainClass::runPing()
{
    std::cout << "Running Ping Test Mode " << std::endl;
    std::shared_ptr<CommunicationWriter> _writer = _manager->create_writer("ddd");

    auto latencyPingReceiveCB_ = std::make_shared<latencyPingReceiveCB>();

    if (auto _reader = _manager->create_reader("fff", latencyPingReceiveCB_))
    {
    }

    _writer->waitForPong();

    std::cout << "starting xx " << std::endl;
    TestMessage _message;

    for (int i = 0; i < 100; i++)
    {
        unsigned long long now = TimeSupport::get_instance()->get_time_us();
        _message.timestamp_sec = static_cast<int>(now / 1000000);
        _message.timestamp_usec = static_cast<unsigned int>(now % 1000000);
        _writer->SyncSend(_message);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return true;
}

bool latencyMainClass::runPong()
{
    std::cout << "Running Pong Test Mode " << std::endl;

    auto latencyPongReceiveCB_ = std::make_shared<latencyPongReceiveCB>(_manager->create_writer("fff"));

    if (auto _reader = _manager->create_reader("ddd", latencyPongReceiveCB_))
    {
    }

    std::this_thread::sleep_for(std::chrono::seconds(20));

    return true;
}

latencyMainClass::latencyMainClass(/* args */)
{
}

latencyMainClass::~latencyMainClass()
{
}

/**
 * --------------------------------------------------------------------------
 */

void latencyPongReceiveCB::processMessage(const TestMessage &message_)
{
    writer_->SyncSend(message_);
    return;
}

/**
 * --------------------------------------------------------------------------
 */

void latencyPingReceiveCB::processMessage(const TestMessage &message_)
{
    unsigned long long now = TimeSupport::get_instance()->get_time_us();

    std::cout << message_.timestamp_sec - static_cast<int>(now / 1000000)
              << "." << message_.timestamp_usec - static_cast<unsigned int>(now % 1000000) << std::endl;
}