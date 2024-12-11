#include <include/timeSppport.hpp>

#include <memory>
#include <iostream>

std::shared_ptr<TimeSupport>
TimeSupport::get_instance()
{
    static std::shared_ptr<TimeSupport> timeSupport_instance(new TimeSupport(),
                                                             [](TimeSupport *p)
                                                             { delete p; });

    return timeSupport_instance;
}

void TimeSupport::get_time()
{
    // TODO
}