#include <include/latencyMainClass.hpp>

int main(int argc, char *argv[])
{
    latencyMainClass _latencyMain;
    try
    {
        _latencyMain.runTest(argc, argv);
    }
    catch (const std::exception &ex)
    {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }
}