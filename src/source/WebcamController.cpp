
#include "../header/WebcamController.hh"

WebcamController::WebcamController() = default;

WebcamController::~WebcamController() = default;

ERR WebcamController::controllerLoop()
{
    Frame frame;
    ImageProvider imgProvider;

    m_imgProvider.setVideoPath(VIDEO_PATH);
    if (imgProvider.openVideo() == ERROR)
        return (ERROR);
    while (42)
    {
        m_imgProvider.getNextImg(frame);
        if (!frame.getImage().empty())
            cv::imshow(WINDOW_NAME, frame.getImage());
        cv::waitKey(1);
    }
    return (SUCCESS);
}