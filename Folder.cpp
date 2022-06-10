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

vector<Mat> Folder::getMatImage()
{
    vector<Mat> img;
    for(int i =0;i<allImages.size();i++)
        img.push_back(getMatImageFromIndex(i));
    return img;
}

void Folder::changeImageFromIndex(int index, Mat image)
{
    allImages[index].changeImage(image);
}

void Folder::displayImageFromIndex(int index)
{
    allImages[index].displayImage();
}

void Folder::saveFromIndex(int index)
{
    getImageFromIndex(index).save(path);
}

void Folder::saveAsFromIndex(const String name, int index)
{
    getImageFromIndex(index).saveAs(path, name);
}
