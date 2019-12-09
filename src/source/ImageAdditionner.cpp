
#include "../header/ImageAdditionner.hh"

ImageAdditionner::ImageAdditionner() = default;

ImageAdditionner::~ImageAdditionner() = default;

void ImageAdditionner::showImage(const char *nameWindow, const cv::Mat &img)
{
    if (!img.empty())
        cv::imshow(nameWindow, img);
}

cv::Mat ImageAdditionner::drawContours(const cv::Size &imageSize, 
                                                            const __contour_vec &contours)
{
    cv::Mat img(std::move(imageSize), CV_8UC3, SCALAR_BLACK);

    cv::drawContours(img, contours, -1, SCALAR_GREEN, -1);
    return (img);
}

cv::Mat ImageAdditionner::drawContour(const cv::Size &imageSize, 
                                                            const __contour &contour)
{
    cv::Mat img(std::move(imageSize), CV_8UC3, SCALAR_BLACK);

    cv::drawContours(img, contour, -1, SCALAR_BLUE, -1);
    return (img);
}

cv::Mat ImageAdditionner::drawRectangle(cv::Mat img, const std::vector<Blob> &frameBlobs)
{
    for (const Blob &blob : frameBlobs)
        cv::rectangle(img, blob.getBoundingRect(), SCALAR_RED, 2);
    return (img);
}
