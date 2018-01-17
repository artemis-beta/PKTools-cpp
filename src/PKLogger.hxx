#ifndef __PKLOGGER__
#define __PKLOGGER__

class PKLogger
{
    private:
        const char* _logger_name;
    public:
        PKLogger( const char* );
        void Error( const char* msg, const char* a="", const char* b="", const char* c="",
                    const char* d="", const char* e="", const char* f="", const char* g="" );
        void Info( const char* msg, const char* a="", const char* b="", const char* c="",
                    const char* d="", const char* e="", const char* f="", const char* g="" );
        void Debug( const char* msg, const char* a="", const char* b="", const char* c="",
                    const char* d="", const char* e="", const char* f="", const char* g="" );
        void Critical( const char* msg, const char* a="", const char* b="", const char* c="",
                    const char* d="", const char* e="", const char* f="", const char* g="" );
        void Fatal( const char* msg, const char* a="", const char* b="", const char* c="",
                    const char* d="", const char* e="", const char* f="", const char* g="" );
};

#endif