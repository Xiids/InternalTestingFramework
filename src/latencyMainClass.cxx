#include <include/latencyMainClass.hpp>

bool latencyMainClass::runTest(int argc, char *argv[])
{
    _parameterHander = std::make_shared<CommandParameterHanding>();

    std::variant<int> param1 = argc;
    std::vector<char *> param2(argv, argv + argc);
    std::variant<std::vector<char *>> varParam2 = param2;

    _parameterHander->processParameter(param1, varParam2);
    _parameterHander->printArgsConfig();

    if (!(_manager = std::make_shared<RtiDdsImplement<::TestType>>()))
    {
        std::cout << "Failed to create test object" << std::endl;
        return false;
    }

    [&]()
    {
        (this->*(_parameterHander->isPing() ? &latencyMainClass::runPing : &latencyMainClass::runPong))();
    }();
}

bool latencyMainClass::runPing()
{
    std::cout << "Running Ping Test Mode " << std::endl;
}

bool latencyMainClass::runPong()
{
    std::cout << "Running Pong Test Mode " << std::endl;
}

latencyMainClass::latencyMainClass(/* args */)
{
}

latencyMainClass::~latencyMainClass()
{
}