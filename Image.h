#ifndef TEST_OPENCV_H
#define TEST_OPENCV_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class Image
{
private:
    String path;
    Mat image;

public:
    ~Image();

    void setDataPath(const String path);
    void setImage(const String path, const String name);
    void changeImage(Mat image);
    void displayImage(const String windowName);

    Mat getImage();
};

#endif
