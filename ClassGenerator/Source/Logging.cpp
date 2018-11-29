#include <Logging.h>

SLL::ConfigPackage BuildLogConfig( )
{
    SLL::ConfigPackage config;

    config.Enable(SLL::OptionFlag::LogToStdout);
    config.Enable(SLL::OptionFlag::LogTimestamp);
    config.Enable(SLL::OptionFlag::LogVerbosityLevel);
    
    config.Enable(SLL::OptionFlag::LogInColor);
    config.SetColor(SLL::VerbosityLevel::INFO, SLL::Color::DEFAULT);
    config.SetColor(SLL::VerbosityLevel::WARN, SLL::Color::BRIGHT | SLL::Color::YELLOW);
    config.SetColor(SLL::VerbosityLevel::ERROR, SLL::Color::BRIGHT | SLL::Color::RED);
    config.SetColor(SLL::VerbosityLevel::FATAL, SLL::Color::BRIGHT | SLL::Color::CYAN);

    return config;
}


std::shared_ptr<SLL::ILogger>& GetLogger( )
{
    static std::shared_ptr<SLL::ILogger> pLogger = SLL::BuildLogger(BuildLogConfig( ));

    return pLogger;
}