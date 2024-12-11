#ifndef TIME_SUPPORT_HPP
#define TIME_SUPPORT_HPP

#include <memory>
#include <chrono>

class TimeSupport
{
public:
    static std::shared_ptr<TimeSupport> get_instance();

    inline std::int64_t get_time_ns();

    inline std::int64_t get_time_us();

    inline std::int64_t calculate_time_diff_ns(std::int64_t start_time_ns, std::int64_t end_time_ns);

private:
    TimeSupport() {};
    ~TimeSupport() {};

    TimeSupport(const TimeSupport &) = delete;

    TimeSupport operator=(const TimeSupport &) = delete;
};

std::int64_t
TimeSupport::get_time_ns()
{
    return std::chrono::steady_clock::now().time_since_epoch().count();
}

std::int64_t
TimeSupport::get_time_us()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

std::int64_t
TimeSupport::calculate_time_diff_ns(std::int64_t start_time_ns, std::int64_t end_time_ns)
{
    return end_time_ns - start_time_ns;
}

#endif