#include <include/parameterHandling.hpp>

#include <iostream>
#include <iomanip>

void ParameterHanding::printArgsConfig()
{
    // 打印标题
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "| " << std::setw(25) << std::left << "Argument"
              << " | " << std::setw(20) << std::left << "Value"
              << " |" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    // 打印参数配置
    for (const auto &args : _parameter)
    {
        std::cout << "| "
                  << std::setw(25) << std::left << args.first
                  << " | "
                  << std::setw(20) << std::left << args.second
                  << " |" << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
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

bool ParameterHanding::isPrintConfig()
{
    auto it = _parameter.find("printConfig");
    if (it != _parameter.end() && it->second == "true")
    {
        return true;
    }
    return false;
}
