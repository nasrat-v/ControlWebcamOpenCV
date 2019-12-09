
#ifndef __SCALAR_COLOR_HPP__
#define __SCALAR_COLOR_HPP__

# define SCALAR_BLACK   cv::Scalar(0.0, 0.0, 0.0)
# define SCALAR_WHITE   cv::Scalar(255.0, 255.0, 255.0)
# define SCALAR_YELLOW  cv::Scalar(0.0, 255.0, 255.0)
# define SCALAR_GREEN   cv::Scalar(0.0, 200.0, 0.0)
# define SCALAR_RED     cv::Scalar(0.0, 0.0, 255.0)
# define SCALAR_BLUE    cv::Scalar(255.0, 0.0, 0.0)
# define SCALAR_ORANGE  cv::Scalar(0.0 ,165.0 , 255.0)

# define WHITE_RANGE     ScalarColor::__t_color_range { "White Range", cv::Scalar(250, 250, 250), cv::Scalar(255, 255, 255), SCALAR_WHITE }
# define BLUE_RANGE      ScalarColor::__t_color_range { "Blue Range", cv::Scalar(90, 150, 105), cv::Scalar(135, 255, 255), SCALAR_BLUE }
# define RED_RANGE       ScalarColor::__t_color_range { "Red Range", cv::Scalar(0, 150, 100), cv::Scalar(10, 255, 255), SCALAR_RED }
# define ORANGE_RANGE    ScalarColor::__t_color_range { "Orange Range", cv::Scalar(11, 150, 100), cv::Scalar(20, 255, 255), SCALAR_ORANGE }
# define YELLOW_RANGE    ScalarColor::__t_color_range { "Yellow Range", cv::Scalar(21, 150, 100), cv::Scalar(30, 255, 255), SCALAR_YELLOW }

#include <string>
#include <iostream>
#include <opencv2/core/types.hpp>

class ScalarColor
{
public:

    typedef struct  __s_color_range
    {
        std::string _nameRange;
        cv::Scalar  _firstRange;
        cv::Scalar  _secondRange;
        cv::Scalar  _displayColor;

        bool operator<(const __s_color_range &colorRange) const
        {
            return (_nameRange < colorRange._nameRange);
        }
    }               __t_color_range;
};


#endif /* !__SCALAR_COLOR_HPP__*/
