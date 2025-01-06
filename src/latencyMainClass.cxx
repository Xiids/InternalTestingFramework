#include <include/latencyMainClass.hpp>

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
}

bool latencyMainClass::runPing()
{
    std::cout << "Running Ping Test Mode " << std::endl;
    std::shared_ptr<CommunicationWriter> _writer;

    _writer = _manager->create_writer("ddd");

    _writer->waitForPong();

    std::cout << "starting xx " << std::endl;
    _writer->SyncSend();
    _writer->SyncSend();
    _writer->SyncSend();
    _writer->SyncSend();

    std::this_thread::sleep_for(std::chrono::seconds(20));
}

bool latencyMainClass::runPong()
{
    std::cout << "Running Pong Test Mode " << std::endl;

    auto latencyPongReceiveCB_ = std::make_shared<latencyPongReceiveCB>();

    if (auto _reader = _manager->create_reader("ddd", latencyPongReceiveCB_))
    {
    }

    std::this_thread::sleep_for(std::chrono::seconds(20));
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

void latencyPongReceiveCB::processMessage()
{
    std::cout << "got ping message" << std::endl;
}