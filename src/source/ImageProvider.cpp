
#include "../header/ImageProvider.hh"

ImageProvider::ImageProvider()
{
    m_videoPath = nullptr;
}

ImageProvider::~ImageProvider() = default;

void ImageProvider::setVideoPath(char *path)
{
    m_videoPath = path;
}

ERR ImageProvider::openVideo()
{
    //cv::VideoCapture cap;
    //if (m_videoPath == nullptr)
        m_capVideo.open(0);
    //else
    //    m_capVideo.open(m_videoPath);
    if (!m_capVideo.isOpened())
    {
        std::cout << "Error cannot open video" << std::endl;
        return (ERROR);
    }
        m_capVideo >> m_img;
        imshow("lala", m_img);
        cv::waitKey(1);
    std::cout << "Video opened" << std::endl;
    return (SUCCESS);
}

void ImageProvider::getNextImg(Frame &frame)
{
    cv::Mat mat;

    m_capVideo >> mat;
    if (mat.empty())
        std::cout << "papaap" << std::endl;
    frame.setImage(mat);
}