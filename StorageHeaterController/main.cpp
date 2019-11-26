#include "HeaterControlModel.h"
#include "ConsoleView.h"
#include "PresentationLayer.h"

int main()
{
    StorageHeaterControl::HeaterControlModel model{};
    StorageHeaterControl::ConsoleView view{};

    StorageHeaterControl::PresentationLayer presentationLayer{ model, view };

    return 0;
}
