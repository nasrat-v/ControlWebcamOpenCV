
#include "../header/WebcamController.hh"
#include "../header/Palette.hh"

int main()
{
    WebcamController controller;

    //launchPalette();
    if (controller.controllerLoop() == ERROR)
        return (-1);
    return (0);
}
