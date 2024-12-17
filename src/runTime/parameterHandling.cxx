#include <include/parameterHandling.hpp>

#include <iostream>

void ParameterHanding::printArgsConfig()
{
    for (auto &args : _parameter)
    {
        std::cout << "arg = " << args.first << " : value = " << args.second << std::endl;
    }
}