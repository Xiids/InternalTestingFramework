#include <include/timeSppport.hpp>

#include <iostream>
#include <windows.h> // 包含 Sleep 函数

int main()
{
    std::cout << "hello" << std::endl;

    auto start = TimeSupport::get_instance()->get_time_ns();

    Sleep(2000);

    auto end = TimeSupport::get_instance()->get_time_ns();

    std::cout << TimeSupport::get_instance()->calculate_time_diff_ns(start, end) << std::endl;

    return 0;
}