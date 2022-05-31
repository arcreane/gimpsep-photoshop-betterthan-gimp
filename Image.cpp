#include "Image.h"

Image::~Image() {}

void Image::setImage(const String folderPath, const String imageName) {
    image = imread(folderPath + "/" + imageName);
};

void Image::changeImage(Mat newImage)
{
    image = newImage;
}

void Image::displayImage() 
{
    namedWindow(windowName);
    imshow (windowName, image);
    cout << "Fermer l'image pour continuer\n" << endl;
    waitKey(0);
}

Mat Image::getImage() 
{
    return image;
}

String Image::getWindowName() 
{
    return windowName;
}