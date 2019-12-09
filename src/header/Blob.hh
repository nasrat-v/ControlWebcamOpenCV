
#ifndef __BLOB_HH__
#define __BLOB_HH__

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <iostream>

//typedef cv::Point           __pos;
typedef std::vector<cv::Point>  __pos_vector;
typedef std::vector<cv::Point>  __contour;
typedef std::vector<cv::Point>  __convx_hull;

class Blob
{
public:
    typedef struct      __s_form
    {
        __contour       contour;
        __convx_hull    convexHull;
    }                   __t_form;

    Blob(const __t_form &form);
    ~Blob();

    void                setForm(const __t_form &form);
    const __t_form      &getForm() const;
    void                setContour(const __contour &contour);
    const __contour     &getContour() const;
    void                setConvexHull(const __convx_hull &convexHull);
    const __convx_hull  &getConvexHull() const;
    void                setBoundingRect(const cv::Rect &boundRect);
    const cv::Rect      &getBoundingRect() const;
    
private:
    __t_form        m_form;
    cv::Rect        m_boundingRect;
    double          m_diagonalSize;
    double          m_aspectRatio;
    cv::Point       m_currentCenter;
    __pos_vector    m_centerPositions;

    void            initAttributes();
    void            initCenterPosition();
};

#endif /* !__BLOB_HH__ */