#include "ResizeImage.h"


ResizeImage::ResizeImage(Folder& folder, int scale)
{
    folder.changeImageFromIndex(0, resizing(folder.getMatImageFromIndex(0), scale));
    folder.displayImageFromIndex(0);
}

ResizeImage::~ResizeImage() {}

Mat ResizeImage::resizing(Mat image, double scale) {
    width = int(image.size().width * scale);
    height = int(image.size().height * scale);

    resize(image, image, Size(width, height));

    return image;
}

