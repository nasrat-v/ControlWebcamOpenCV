
#include "../header/WebcamController.hh"

WebcamController::WebcamController() = default;

WebcamController::~WebcamController() = default;

ERR WebcamController::openVideo(const char *path)
{
    if (path == nullptr)
        m_capVideo.open(0);
    else
        m_capVideo.open(path);
    if (!m_capVideo.isOpened())
    {
        std::cout << "Error cannot open video" << std::endl;
        return (ERROR);
    }
    std::cout << "Video opened" << std::endl;
    return (SUCCESS);
}

void WebcamController::getNextImg(Frame &frame)
{
    cv::Mat img;

    m_capVideo.read(img);
    if (!img.empty())
        frame.setImage(img);
}

void WebcamController::setDiffFrames(const Frame &frame)
{
    if (m_diffFrames.size() < NB_FRAMES_MIN)
        m_diffFrames.push_back(frame);
    else
    {
        m_diffFrames.erase(m_diffFrames.begin());
        m_diffFrames.push_back(frame);
    }
}

void WebcamController::findBlobs(const __contour_vec &allContours, Frame &frame)
{
    Blob::__t_form form;

    for (__contour cnt : allContours)
    {
        form.contour = cnt;
        form.convexHull = m_imageProcesser.findConvexHullFromContour(cnt);
        frame.addBlob(createBlob(form));
    }
}

Blob WebcamController::createBlob(const Blob::__t_form &form)
{
    return (Blob(form));
}

void WebcamController::applyRulesOnFrame(cv::Mat firstImg, cv::Mat lastImg, Frame &frame)
{
    cv::Mat processedImg;
    __contour_vec moveContours;
    __convx_hull_vec moveConvexHulls;

    m_imageProcesser.imgToHSV(firstImg, BLUE_RANGE);
    m_imageProcesser.imgToHSV(lastImg, BLUE_RANGE);
    processedImg = m_imageProcesser.differenceImg(firstImg, lastImg);
    m_imageAdditionner.showImage("diff", processedImg);

    m_imageProcesser.threshImg(processedImg);
    frame.setImage(processedImg);

    moveContours = m_imageProcesser.findContoursFromImg(processedImg);
    cv::Mat contoursImg = m_imageAdditionner.drawContours(processedImg.size(), moveContours);
    m_imageAdditionner.showImage("movement contours", contoursImg);

    moveConvexHulls = m_imageProcesser.findConvexHullsFromContours(moveContours);
    cv::Mat convexImg = m_imageAdditionner.drawContours(processedImg.size(), moveConvexHulls);
    m_imageAdditionner.showImage("movement convex_hulls", convexImg);

    findBlobs(moveContours, frame);
}

void WebcamController::processFrames()
{
    Frame frame;
    cv::Mat firstImg = m_diffFrames.front().getImage().clone();
    cv::Mat lastImg = m_diffFrames.back().getImage().clone();

    if (m_diffFrames.size() != NB_FRAMES_MIN) // first time
        return;   
    applyRulesOnFrame(firstImg.clone(), lastImg.clone(), frame);

    cv::Mat trackImg = m_imageAdditionner.drawRectangle(lastImg, frame.getBlobs());
    m_imageAdditionner.showImage("track", trackImg);

    frame.clearAllBlobs();
}

ERR WebcamController::controllerLoop()
{
    Frame frame;

    if (openVideo(VIDEO_PATH) == ERROR)
        return (ERROR);
    while (42)
    {
        getNextImg(frame);
        setDiffFrames(frame);
        processFrames();
        cv::waitKey(1);
    }
    return (SUCCESS);
}