
#ifndef __FRAME_HH__
#define __FRAME_HH__

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Frame
{
public:
    Frame();
    ~Frame();

    void            setImage(const cv::Mat &img);
    const cv::Mat   &getImage() const;

private:
    cv::Mat         m_image;
};

#endif /* !__FRAME_HH__ */