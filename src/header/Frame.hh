
#ifndef __FRAME_HH__
#define __FRAME_HH__

#include "Blob.hh"

typedef std::vector<__contour>      __contour_vec;
typedef std::vector<__convx_hull>   __convx_hull_vec;

class Frame
{
public:
    Frame();
    ~Frame();

    void                    setImage(const cv::Mat &img);
    const cv::Mat           &getImage() const;
    /*void                    setContours(const __contour_vec &contours);
    const __contour_vec     &getContours() const;
    void                    setConvexHulls(const __convx_hull_vec &convexHulls);
    const __convx_hull_vec  &getConvexHulls() const;*/
    void                    addBlob(const Blob &blob);
    const std::vector<Blob> &getBlobs() const;
    void                    clearAllBlobs();


private:
    cv::Mat                 m_image;
    //__contour_vec           m_contours;
    //__convx_hull_vec        m_convexHulls;
    std::vector<Blob>       m_blobs;
};

#endif /* !__FRAME_HH__ */