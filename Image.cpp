#include "Image.h"

Image::~Image() {}

void Image::setDataPath(const String folderPath) {
    path = folderPath;
};

void Image::setImage(const String folderPath, const String imageName) {
    setDataPath(folderPath);

    samples::addSamplesDataSearchPath(folderPath);
    String imagePath = samples::findFile(imageName);

    image = imread(imagePath);
};

void Image::changeImage(Mat newImage) {
    image = newImage;
}

void Image::displayImage(String windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow (windowName, image);
    waitKey(0);
}

Mat Image::getImage() {
    return image;
}