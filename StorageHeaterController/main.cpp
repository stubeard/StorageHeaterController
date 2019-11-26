#include "HeaterControlModel.h"
#include "ConsoleView.h"
#include "PresentationLayer.h"
#include "Defines.h"
#include <iostream>

int main()
{
    std::cout << "Storage Heater Control Utility, Version [" << StorageHeaterControl::VERSION << "] Built on [" << __DATE__ << "] at [" __TIME__ << "]" << std::endl;

    StorageHeaterControl::HeaterControlModel model{};
    StorageHeaterControl::ConsoleView view{};

    StorageHeaterControl::PresentationLayer presentationLayer{ model, view };

    return 0;
}
