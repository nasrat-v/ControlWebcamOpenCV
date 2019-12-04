
#include "../header/Frame.hh"

Frame::Frame() = default;

Frame::~Frame() = default;

void Frame::setImage(const cv::Mat &img)
{
    m_image = img;
}

const cv::Mat &Frame::getImage() const
{
    return (m_image);
}