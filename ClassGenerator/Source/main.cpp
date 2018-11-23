#include <winerror.h>

#include <Logging.hpp>

int main(const int argc, const char* const argv[ ])
{
    if ( argc <= 1 || argv[1] == '\0' )
    {
        GetLogger( )->Log(
            SLL::VerbosityLevel::ERROR, 
            "Invalid number of arguments - actual[%d]  expected[2+].", 
            argc
        );

        return ERROR_INVALID_PARAMETER;
    }

    return ERROR_SUCCESS;
}
