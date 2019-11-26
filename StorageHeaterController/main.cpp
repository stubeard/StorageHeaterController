#include "HeaterControlModel.h"
#include "ConsoleView.h"
#include "PresentationLayer.h"
#include "Defines.h"
#include <iostream>

bool running = true;

static void signal_handler( int s )
{
    running = false;
}
int main()
{
    std::cout << "Storage Heater Control Utility, Version [" << StorageHeaterControl::VERSION << "] Built on [" << __DATE__ << "] at [" __TIME__ << "]" << std::endl;

    signal( SIGINT, signal_handler );

    StorageHeaterControl::HeaterControlModel model{};
    StorageHeaterControl::ConsoleView view{};

    StorageHeaterControl::PresentationLayer presentationLayer{ model, view };

    while( running )
    {
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }

    return 0;
}
