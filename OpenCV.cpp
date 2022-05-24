#include "OpenCV.h"

OpenCV::~OpenCV()
{
    delete[] this->image;
    delete[] this->path;
}

void OpenCV::setDataPath(const String path) {
    this->path = path;
};

Mat OpenCV::setImage(const String path, const String imageName) {
    this->setDataPath(path);

    samples::addSamplesDataSearchPath(path);
    String imagePath = samples::findFile(imageName);

    this->image = imread(imagePath);
    return this->image;
};

void OpenCV::displayImage(String windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow (windowName, image);
    waitKey(0);
}