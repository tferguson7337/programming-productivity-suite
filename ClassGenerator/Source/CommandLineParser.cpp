#include <CommandLineParser.h>

#include <Logging.h>

std::vector<CLP::CommandFlag<utf8>> BuildCommandFlags( )
{
    std::vector<CLP::CommandFlag<utf8>> cmdFlags;

    cmdFlags.push_back(CLP::CommandFlag<utf8>("/dummy", nullptr, false, true, false));

    return cmdFlags;
}

void InitializeCommandLineParser( )
{
    CLP::CommandParser<utf8>& clp = CLP::CommandParser<utf8>::GetInstance( );

    if ( !clp.GetRegisteredCommandFlags( ).empty( ) )
    {
        static const char* msg = __FUNCTION__": Attempted CLP re-initialization.";
        GetLogger( )->Log(SLL::VerbosityLevel::ERROR, msg);
        throw std::logic_error(msg);
    }

    for ( auto& flag : BuildCommandFlags( ) )
    {
        clp.RegisterCommandFlag(std::move(flag));
    }
}
