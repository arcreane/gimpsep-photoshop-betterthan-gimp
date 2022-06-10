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
    void setImageFromMat(Mat matImage);
    void changeImage(Mat image);
    void displayImage();
    void save(const String folderPath);
    void saveAs(const String folderPath, const String imageNames);

    Mat getImage();
    String getWindowName();
private:
    String windowName = "Your Image";
    String name;
    Mat image;
};

#endif