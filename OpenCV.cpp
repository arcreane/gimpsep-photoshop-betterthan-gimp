#include "OpenCV.h"

OpenCV::~OpenCV()
{
}

void OpenCV::setDataPath(const String path) {
    samples::addSamplesDataSearchPath(path);
};

Mat OpenCV::setImage(String imageName) {
    String imagePath = samples::findFile(imageName);
    return imread(imagePath);
};

void OpenCV::displayImage(String windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow (windowName, image);
    waitKey(0);
}