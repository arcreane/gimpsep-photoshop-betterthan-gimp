#ifndef GIMPSEP_RESIZEIMAGE_H
#define GIMPSEP_RESIZEIMAGE_H

#include <opencv2/opencv.hpp>
#include <string>
#include "Folder.h"

using namespace cv;
using namespace std;

class ResizeImage
{
public:
    ResizeImage(Folder& folder, int scale);
    ~ResizeImage();

    Mat resizing(Mat image, double scale);

private:
    int width;
    int height;
};

#endif