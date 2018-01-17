#ifndef __PKGLOBALDEF__
#define __PKGLOBALDEF__

#include <string>
#include <iostream>

enum Level
{
    DEBUG,
    INFO,
    ERROR,
    CRITICAL,
    FATAL
};

extern Level _global_logger_level;

void setLoggerLevel( std::string level_str );

#endif