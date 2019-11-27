#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>
#include <chrono>

namespace StorageHeaterControl
{
    const std::string VERSION{ "01.0" };
    constexpr int SCHEDULE_UPDATE_TIME_IN_US{ std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::minutes( 30 ) ).count() };

    const std::string TEMPLATE{ "################################################" };
    const size_t PERIODS_IN_SCHEDULE{ TEMPLATE.size() };
}

#endif // __DEFINES_H__
