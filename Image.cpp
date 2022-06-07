#include "Image.h"

Image::~Image() {}

void Image::setImage(const String folderPath, const String imageName) {
    name = imageName;
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
    int key = waitKey(0);
    if (key != -1) {
        destroyWindow(windowName);
    }
}

void Image::save(const String folderPath)
{
    imwrite(folderPath + "/" + name, image);
    cout << "Image enregistrer sous : " + folderPath + "/" + name + "\n";
}

void Image::saveAs(const String folderPath, const String imageName)
{
    imwrite(folderPath + "/" + imageName, image);
    cout << "Image enregistrer sous : " + folderPath + "/" + imageName + "\n";
}

Mat Image::getImage() 
{
    return image;
}

String Image::getWindowName() 
{
    return windowName;
}