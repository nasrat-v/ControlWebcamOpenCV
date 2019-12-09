
#include "../header/Blob.hh"

Blob::Blob(const Blob::__t_form &form)
{
    m_form.contour = form.contour;
    m_form.convexHull = form.convexHull;
    initAttributes();
    initCenterPosition();
}

Blob::~Blob() = default;

void Blob::initAttributes()
{
    m_boundingRect = cv::boundingRect(m_form.convexHull);
    m_diagonalSize = sqrt(pow(m_boundingRect.width, 2) + pow(m_boundingRect.height, 2));
    m_aspectRatio = ((float)m_boundingRect.width / (float)m_boundingRect.height);
}

void Blob::initCenterPosition()
{
    cv::Point currentCenter;

    currentCenter.x = ((m_boundingRect.x + m_boundingRect.x + m_boundingRect.width) / 2);
    currentCenter.y = ((m_boundingRect.y + m_boundingRect.y + m_boundingRect.height) / 2);
    m_centerPositions.push_back(currentCenter);
}

void Blob::setForm(const Blob::__t_form &form)
{
    m_form.contour = form.contour;
    m_form.convexHull = form.convexHull;
}

const Blob::__t_form &Blob::getForm() const
{
    return (m_form);
}

void Blob::setContour(const __contour &contour)
{
    m_form.contour = contour;
}

const __contour &Blob::getContour() const
{
    return (m_form.contour);
}

void Blob::setConvexHull(const __convx_hull &convexHull)
{
    m_form.convexHull = convexHull;
}

const __convx_hull &Blob::getConvexHull() const
{
    return (m_form.convexHull);
}

void Blob::setBoundingRect(const cv::Rect &boundRect)
{
    m_boundingRect = boundRect;
}

const cv::Rect &Blob::getBoundingRect() const
{
    return (m_boundingRect);
}