
#include "../header/ImageProcesser.hh"

ImageProcesser::ImageProcesser() = default;

ImageProcesser::~ImageProcesser() = default;

void ImageProcesser::imgToHSV(cv::Mat &img, const ScalarColor::__t_color_range &range)
{
    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
    cv::inRange(img, range._firstRange, range._secondRange, img);
}

void ImageProcesser::imgToGray(cv::Mat &img)
{
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
}

cv::Mat ImageProcesser::differenceImg(cv::Mat firstImg, cv::Mat secondImg)
{
    cv::Mat imgDifference;

    cv::GaussianBlur(firstImg, firstImg, cv::Size(5, 5), 0);
    cv::GaussianBlur(secondImg, secondImg, cv::Size(5, 5), 0);
    cv::absdiff(firstImg, secondImg, imgDifference);
    return (imgDifference);
}

cv::Mat ImageProcesser::differenceImgGray(cv::Mat firstImg, cv::Mat secondImg)
{
    imgToGray(firstImg);
    imgToGray(secondImg);
    return (differenceImg(firstImg, secondImg));
}

void ImageProcesser::threshImg(cv::Mat &img)
{
    cv::Mat structuringElement1x1;
    cv::Mat structuringElement3x3;
    cv::Mat structuringElement5x5;
    cv::Mat structuringElement7x7;
    cv::Mat structuringElement9x9;
    cv::Mat structuringElement11x11;

    cv::threshold(img, img, 30, 255.0, cv::THRESH_BINARY);
    structuringElement1x1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 1));
    structuringElement3x3 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    structuringElement5x5 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    structuringElement7x7 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
    structuringElement9x9 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9));
    structuringElement11x11 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11));
    cv::erode(img, img, structuringElement1x1);
    cv::erode(img, img, structuringElement3x3);
    cv::erode(img, img, structuringElement5x5);
    cv::dilate(img, img, structuringElement7x7);
    cv::dilate(img, img, structuringElement9x9);
    cv::dilate(img, img, structuringElement11x11);
}

__contour_vec ImageProcesser::findContoursFromImg(const cv::Mat &img)
{
    __contour_vec contours;

    cv::findContours(img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    return (contours);
}

__convx_hull_vec ImageProcesser::findConvexHullsFromContours(const __contour_vec &contours)
{
    size_t  i = 0;
    size_t  contoursSize = contours.size();
    __convx_hull_vec convexHulls(contoursSize);

    while (i < contoursSize)
    {
        cv::convexHull(contours[i], convexHulls[i]);
        i++;
    }
    return (convexHulls);
}

__convx_hull ImageProcesser::findConvexHullFromContour(const __contour &contour)
{
    __convx_hull convexHull(contour.size());

    cv::convexHull(contour, convexHull);
    return (convexHull);
}