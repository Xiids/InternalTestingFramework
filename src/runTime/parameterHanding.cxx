#include <include/parameterHandling.hpp>

#include <iostream>

void ParameterHanding::printArgsConfig()
{
    for (auto &args : _parameter)
    {
        std::cout << "arg = " << args.first << " : value = " << args.second << std::endl;
    }
}

bool ParameterHanding::isPing()
{
    auto it = _parameter.find("pub");
    if (it != _parameter.end() && it->second == "true")
    {
        return true;
    }
    return false;
}
