#pragma once

#include <SimpleLoggingLibrary/Headers/LoggerFactory.h>

SLL::ConfigPackage BuildLogConfig( )
{
    SLL::ConfigPackage config;

    config.Enable(SLL::OptionFlag::LogToStdout);
    config.Enable(SLL::OptionFlag::LogTimestamp);
    config.Enable(SLL::OptionFlag::LogVerbosityLevel);

    return config;
}


std::shared_ptr<SLL::ILogger>& GetLogger( )
{
    static std::shared_ptr<SLL::ILogger> pLogger = SLL::BuildLogger(BuildLogConfig( ));

    return pLogger;
}
