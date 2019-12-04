
#include "../header/WebcamController.hh"

int main()
{
    WebcamController controller;

    if (controller.controllerLoop() == ERROR)
        return (-1);
    return (0);
}
