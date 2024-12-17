#include <include/parameterHandling.hpp>

#include <string>

class CommandParameterHanding : public ParameterHanding
{
public:
    bool processParameter(const std::variant<int> &param1,
                          const std::variant<std::vector<char *>> &param2);
};