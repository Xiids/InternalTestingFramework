#include <include/timeSppport.hpp>

#include <iostream>

#ifndef WINDOWS_MINGW
#include <thread>
#else
#include <mingw.thread.h>
#endif

int main()
{
    std::cout << "hello" << std::endl;

    auto start = TimeSupport::get_instance()->get_time_ns();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    auto end = TimeSupport::get_instance()->get_time_ns();

    std::cout << TimeSupport::get_instance()->calculate_time_diff_ns(start, end) << std::endl;

    return 0;
}