#ifndef LATENCY_MAIN_CLASS
#define LATENCY_MAIN_CLASS

#include <include/communicationManager.hpp>
#include <src/vendorImpl/rti/rtiDdsImpl.hpp>
#include <src/runTime/commandParameterHanding.hpp>
#include <memory>
#include <chrono>
#include <thread>

class latencyMainClass
{
private:
    std::shared_ptr<CommunicationManager> _manager;
    std::shared_ptr<ParameterHanding> _parameterHander;

public:
    bool runTest(int argc, char *argv[]);

    bool runPing();
    bool runPong();

    latencyMainClass(/* args */);
    ~latencyMainClass();
};

#endif