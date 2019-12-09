
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

/*void Frame::setContours(const __contour_vec &contours)
{
    m_contours = contours;
}

const __contour_vec &Frame::getContours() const
{
    return (m_contours);
}

void Frame::setConvexHulls(const __convx_hull_vec &convexHulls)
{
    m_convexHulls = convexHulls;
}

const __convx_hull_vec &Frame::getConvexHulls() const
{
    return (m_convexHulls);
}*/

void Frame::addBlob(const Blob &blob)
{
    m_blobs.push_back(blob);
}

const std::vector<Blob> &Frame::getBlobs() const
{
    return (m_blobs);
}

void Frame::clearAllBlobs()
{
    m_blobs.clear();
}