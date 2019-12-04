
#ifndef __IMAGE_PROVIDER_HH__
#define __IMAGE_PROVIDER_HH__

# define SUCCESS        (ERR)1
# define ERROR          (ERR)~0
# define WEBCAM_PATH    0

#include <iostream>
#include "Frame.hh"

typedef uint8_t     ERR;

class ImageProvider
{
public:
    ImageProvider();
    ~ImageProvider();

    void                setVideoPath(char *path);
    ERR                 openVideo();
    void                getNextImg(Frame &frame);

private:
    cv::VideoCapture    m_capVideo;
    cv::Mat             m_img;
    char                *m_videoPath;
};

#endif /* !__IMAGE_PROVIDER_HH__ */