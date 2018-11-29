#include <Logging.h>

#include <CommandLineParser.h>

int main(const int argc, const char* const argv[ ])
{
    int exitCode = -1;

    GetLogger( )->Log(SLL::VerbosityLevel::INFO, "ClassGenerator Entry.");

    try
    {
        InitializeCommandLineParser( );
        CLP::CommandParser<utf8>::GetInstance( ).ParseCommandLine(argc, argv);
    }
    catch ( const std::exception& e )
    {
        GetLogger( )->Log(
            SLL::VerbosityLevel::FATAL,
            __FUNCTION__": Failed to parse command-line arguments - exception[%s]",
            e.what( )
        );

        goto done;
    }


    exitCode = 0;
done:

    GetLogger( )->Log(
        (exitCode == 0) ? SLL::VerbosityLevel::INFO : SLL::VerbosityLevel::WARN, 
        "ClassGenerator Exit[%d].", 
        exitCode
    );

    return exitCode;
}
