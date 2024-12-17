#ifndef PARAMETER_HANDING_HPP
#define PARAMETER_HANDING_HPP

#include <variant>
#include <vector>
#include <unordered_map>

class ParameterHanding
{
public:
    ParameterHanding() {};
    virtual ~ParameterHanding() = default;

    void printArgsConfig();

    virtual bool processParameter(const std::variant<int> &param1,
                                  const std::variant<std::vector<char *>> &param2) = 0;

protected:
    std::unordered_map<std::string, std::string> _parameter;
};

#endif
