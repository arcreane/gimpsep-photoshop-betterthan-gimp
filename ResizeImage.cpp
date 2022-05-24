#include "ResizeImage.h"

ResizeImage::~ResizeImage() {}

Mat ResizeImage::resizing(Mat image, double scale) {
    width = int(image.size().width * scale);
    height = int(image.size().height * scale);

    resize(image, image, Size(width, height));

    return image;
}

