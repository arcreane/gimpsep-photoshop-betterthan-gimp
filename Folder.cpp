#include "Folder.h"

Folder::Folder(String& folderPath) {
    path = folderPath;
}

Folder::~Folder() {}

void Folder::addImageFromName(String imageName)
{
    Image image;
    image.setImage(path, imageName);
    allImages.push_back(image);
}

Image Folder::getImageFromIndex(int index)
{
    return allImages[index];
}

Mat Folder::getMatImageFromIndex(int index)
{
    return allImages[index].getImage();
}

void Folder::changeImageFromIndex(int index, Mat image)
{
    allImages[index].changeImage(image);
}

void Folder::displayImageFromIndex(int index)
{
    allImages[index].displayImage();
}