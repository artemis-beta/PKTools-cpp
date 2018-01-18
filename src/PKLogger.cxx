#include "PKLogger.hxx"

PKLogger::PKLogger( std::string name )
{
    _logger_name = name;

}

void _global_out(Level type, std::string type_str, std::string _logger_name, std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g)
{
    if(a == ""){msg += "%1%";}
    if(b == ""){msg += "%2%";}
    if(c == ""){msg += "%3%";}
    if(d == ""){msg += "%4%";}
    if(e == ""){msg += "%5%";}
    if(f == ""){msg += "%6%";}
    if(g == ""){msg += "%7%";}
    
    if( type >= _global_logger_level )
    {
	std::string msg_w_args = boost::str(boost::format(msg) % a % b % c % d % e % f % g);
        std::cout << _logger_name;
        std::cout << ":\t" << type_str << ":\t";
        std::cout << msg_w_args << std::endl;
    }
}

void PKLogger::Error( std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g )
{
    _global_out( ERROR, "ERROR", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Info( std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g )
{
    _global_out( INFO, "INFO", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Critical( std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g )
{
    _global_out( CRITICAL, "CRITICAL", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Fatal( std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g )
{
    _global_out( FATAL, "FATAL", _logger_name, msg, a, b, c, d, e, f, g );
}

void PKLogger::Debug( std::string msg, std::string a, std::string b, std::string c,
                    std::string d, std::string e, std::string f, std::string g )
{
    _global_out( DEBUG, "DEBUG", _logger_name, msg, a, b, c, d, e, f, g );
}
