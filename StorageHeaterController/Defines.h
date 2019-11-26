#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>
#include <chrono>

namespace StorageHeaterControl
{
    const std::string VERSION{ "01.0D" };
    constexpr int SCHEDULE_UPDATE_TIME_IN_US{ std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::minutes( 30 ) ).count() };
}

#endif // __DEFINES_H__
