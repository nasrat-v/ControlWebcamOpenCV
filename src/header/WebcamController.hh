
#ifndef __WEBCAM_CONTROLLER_HH__
#define __WEBCAM_CONTROLLER_HH__

# define VIDEO_PATH     NULL
# define WINDOW_NAME    "webcam"

#include "ImageProvider.hh"

class WebcamController
{
public:
    WebcamController();
    ~WebcamController();

    ERR             controllerLoop();

private:
    ImageProvider   m_imgProvider;
    Frame           m_frame;
};

#endif /* !__WEBCAM_CONTROLLER_HH__ */
