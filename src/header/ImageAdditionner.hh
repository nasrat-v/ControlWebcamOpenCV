
#ifndef __IMAGE_ADDITIONNER_HH__
#define __IMAGE_ADDITIONNER_HH__

# define SCALAR_BLACK   cv::Scalar(0.0, 0.0, 0.0)
# define SCALAR_WHITE   cv::Scalar(255.0, 255.0, 255.0)
# define SCALAR_YELLOW  cv::Scalar(0.0, 255.0, 255.0)
# define SCALAR_GREEN   cv::Scalar(0.0, 200.0, 0.0)
# define SCALAR_RED     cv::Scalar(0.0, 0.0, 255.0)
# define SCALAR_BLUE    cv::Scalar(255.0, 0.0, 0.0)
# define SCALAR_ORANGE  cv::Scalar(0.0 ,165.0 , 255.0)

#include "Frame.hh"

class ImageAdditionner
{
public:
    ImageAdditionner();
    ~ImageAdditionner();

    void        showImage(const char *nameWindow, const cv::Mat &img);
    cv::Mat     drawContours(const cv::Size &imageSize, const __contour_vec &contours);
    cv::Mat     drawContour(const cv::Size &imageSize, const __contour &contour);                                                    
    cv::Mat     drawRectangle(cv::Mat img, const std::vector<Blob> &frameBlobs);
};

#endif /* !__IMAGE_ADDITIONNER_HH__ */