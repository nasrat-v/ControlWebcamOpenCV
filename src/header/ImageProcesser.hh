
#ifndef __IMAGE_PROCESSER_HH__
#define __IMAGE_PROCESSER_HH__

#include "Frame.hh"
#include "ScalarColor.hpp"

class ImageProcesser
{
public:
    ImageProcesser();
    ~ImageProcesser();

    void                imgToHSV(cv::Mat &img, const ScalarColor::__t_color_range &range);
    void                imgToGray(cv::Mat &img);
    cv::Mat             differenceImg(cv::Mat firstImg, cv::Mat secondImg);
    cv::Mat             differenceImgGray(cv::Mat firstImg, cv::Mat secondImg);
    void                threshImg(cv::Mat &img);
    __contour_vec       findContoursFromImg(const cv::Mat &img);
    __convx_hull_vec    findConvexHullsFromContours(const __contour_vec &contours);
    __convx_hull        findConvexHullFromContour(const __contour &contour);
};

#endif /* !__IMAGE_PROCESSER_HH__*/