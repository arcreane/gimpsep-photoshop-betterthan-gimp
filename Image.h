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

    void setImage(const String folderPath, const String name);
    void changeImage(Mat image);
    void displayImage();

    Mat getImage();
    String getWindowName();
private:
    String windowName = "Your Image";
    Mat image;
};

#endif