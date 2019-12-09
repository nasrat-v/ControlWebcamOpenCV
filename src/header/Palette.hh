
#ifndef __PALETTE_HH__
#define __PALETTE_HH__

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cstring>
#include "stdio.h"

# define HUEMAX                 179
# define SATMAX                 255
# define VALMAX                 255

using namespace std;
using namespace cv;

int launchPalette();
void onTrackbar_changed(int, void*);
void drawPointers();

#endif /* !__PALETTE_HH__ */