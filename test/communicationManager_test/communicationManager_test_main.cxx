#include <src/vendorImpl/rti/rtiDdsImpl.hpp>

#include <iostream>

int main()
{
    RtiDdsImplement<::TestType> rtiddsimpl;
    rtiddsimpl.initialize();

    auto wr_1 = rtiddsimpl.create_writer("wr_1");
    auto wr_2 = rtiddsimpl.create_writer("wr_2");
    while (1)
    {
        wr_1->SyncSend();
    }

    return 0;
}