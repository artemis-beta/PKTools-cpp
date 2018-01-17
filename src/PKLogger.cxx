#include "PKLogger.hxx"
#include "PKGlobalDef.hxx"
#include <iostream>
#include <string>

PKLogger::PKLogger( const char* name )
{
    _logger_name = name;

}

void _global_out(Level type, std::string type_str, std::string _logger_name, const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g)
{
    if( type >= _global_logger_level )
    {
        std::cout << _logger_name;
        std::cout << ":\t" << type_str << ":\t";
        printf(msg, a, b, c, d, e, f, g);
        putchar('\n');
    }
}

void PKLogger::Error( const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g )
{
    _global_out( ERROR, "ERROR", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Info( const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g )
{
    _global_out( INFO, "INFO", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Critical( const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g )
{
    _global_out( CRITICAL, "CRITICAL", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Fatal( const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g )
{
    _global_out( FATAL, "FATAL", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Debug( const char* msg, const char* a, const char* b, const char* c,
                    const char* d, const char* e, const char* f, const char* g )
{
    _global_out( DEBUG, "DEBUG", _logger_name, msg, a, b, c, d, e, f, g );
}