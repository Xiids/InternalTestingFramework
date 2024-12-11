#ifndef TIME_SUPPORT_HPP
#define TIME_SUPPORT_HPP

#include <memory>

class TimeSupport
{
public:
    static std::shared_ptr<TimeSupport> get_instance();

    void get_time();

private:
    TimeSupport() {};
    ~TimeSupport() {};

    TimeSupport(const TimeSupport &) = delete;

    TimeSupport operator=(const TimeSupport &) = delete;
};

#endif