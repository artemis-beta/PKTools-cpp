#ifndef __PKLOGGER__
#define __PKLOGGER__

#include "PKGlobalDef.hxx"
#include <iostream>
#include <string>
#include <sstream>
#include "boost/format.hpp"

std::string getAsChar(double a);
std::string getAsChar(int a);
std::string getAsChar(float a);
std::string getAsChar(std::string a);

class PKLogger
{
    private:
        std::string _logger_name;
    public:
        PKLogger( std::string );
        void Error( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
        void Warning( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
        void Info( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
        void Debug( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
        void Critical( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
        void Fatal( std::string msg, std::string a="", std::string b="", std::string c="",
                    std::string d="", std::string e="", std::string f="", std::string g="" );
};

#endif
