#include "../header/OpenCV.h"

OpenCV::~OpenCV()
{
}

void OpenCV::setDataPath(string path) {
    samples::addSamplesDataSearchPath(path);
};
 
Mat OpenCV::setImage(string imageName) {
    String imagePath = samples::findFile(imageName);
    return imread(imagePath);
};

void OpenCV::displayImage(string windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow (windowName, image);
    waitKey(0);
}