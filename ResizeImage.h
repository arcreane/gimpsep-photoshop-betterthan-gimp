#ifndef GIMPSEP_RESIZEIMAGE_H
#define GIMPSEP_RESIZEIMAGE_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class ResizeImage
{
public:
    ~ResizeImage();

    Mat resizing(Mat image, double scale);

private:
    int width;
    int height;
};

#endif