
#ifndef __WEBCAM_CONTROLLER_HH__
#define __WEBCAM_CONTROLLER_HH__

# define VIDEO_PATH     NULL //"../input/768x576.avi"
# define SUCCESS        (ERR)1
# define ERROR          (ERR)~0
# define NB_FRAMES_MIN  2

#include <vector>
#include "ImageProcesser.hh"
#include "ImageAdditionner.hh"
#include "Frame.hh"

typedef uint8_t         ERR;

class WebcamController
{
public:
    WebcamController();
    ~WebcamController();

    ERR                 controllerLoop();

private:
    cv::VideoCapture    m_capVideo;
    std::vector<Frame>  m_diffFrames;
    ImageProcesser      m_imageProcesser;
    ImageAdditionner    m_imageAdditionner;

    ERR                 openVideo(const char *path);
    void                getNextImg(Frame &frame);
    void                setDiffFrames(const Frame &frame);
    void                findBlobs(const __contour_vec &allContours, Frame &frame);
    Blob                createBlob(const Blob::__t_form &form);
    void                applyRulesOnFrame(cv::Mat firstImg, cv::Mat lastImg, Frame &frame);
    void                processFrames();
};

#endif /* !__WEBCAM_CONTROLLER_HH__ */
