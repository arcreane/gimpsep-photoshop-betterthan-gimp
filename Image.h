#ifndef GIMPSEP_IMAGE_H
#define GIMPSEP_IMAGE_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class Image
{
public:
    ~Image();

    void setDataPath(const String path);
    void setImage(const String path, const String name);
    void changeImage(Mat image);
    void displayImage();

    Mat getImage();
    String getWindowName();

private:
    String windowName = "Your Image";
    String path;
    Mat image;
};

#endif