#ifndef TEST_OPENCV_H
#define TEST_OPENCV_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class OpenCV
{
private:
    Mat image;
public:
    ~OpenCV();
    void setDataPath(const String path);
    Mat setImage(String name);
    void displayImage(String windowName);
};

#endif
