#include "HeaterControlModel.h"
#include "ConsoleView.h"
#include "PresentationLayer.h"

int main()
{
    HeaterControlModel model{};
    ConsoleView view{};

    PresentationLayer presentationLayer{ model, view };

    return 0;
}
