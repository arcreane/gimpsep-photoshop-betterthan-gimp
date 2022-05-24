//
// Created by Cecile LI on 24/05/2022.
//

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
    void setDataPath(string path);
    Mat setImage(string name);
    void displayImage(string windowName);
};

#endif //TEST_OPENCV_H
