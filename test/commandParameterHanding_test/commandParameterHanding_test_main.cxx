#include <src/runTime/commandParameterHanding.hpp>

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::shared_ptr<ParameterHanding> handler = std::make_shared<CommandParameterHanding>();

    std::variant<int> param1 = argc;
    std::vector<char *> param2(argv, argv + argc);
    std::variant<std::vector<char *>> varParam2 = param2;

    handler->processParameter(param1, varParam2);
    handler->printArgsConfig();
    return 0;
}