#include <src/runTime/commandParameterHanding.hpp>

bool CommandParameterHanding::processParameter(const std::variant<int> &param1,
                                               const std::variant<std::vector<char *>> &param2)
{
    auto argc = std::get_if<int>(&param1);

    int argc_val = *argc;

    auto argv = std::get_if<std::vector<char *>>(&param2);

    for (int i = 1; i < argc_val; ++i)
    {
        std::string arg(argv->at(i));

        if (arg == "-bestEffort")
        {
            _parameter["reliability"] = arg;
        }
    }
}
