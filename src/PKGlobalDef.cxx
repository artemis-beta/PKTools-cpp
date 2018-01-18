#include "PKGlobalDef.hxx"

Level _global_logger_level = ERROR;

void setLoggerLevel( std::string level_str )
{ 
    if( level_str == "INFO" )
    {
        _global_logger_level = INFO;
    }
    else if( level_str == "DEBUG" )
    {
        _global_logger_level = DEBUG;
    }
    else if( level_str == "ERROR" )
    {
        _global_logger_level = ERROR; 
    }
    else if( level_str == "FATAL" )
    {
        _global_logger_level = FATAL;
    }
    else if( level_str == "CRITICAL" )
    {
        _global_logger_level = CRITICAL;
    }
    else
    {
        std::cout << "Invalid logger level option '" << level_str << "'\n";
        std::cout << ". Using default." << std::endl;
    }
}
