#include "Resize.h"

Mat Resize::resizeImage(Mat image, double scale) {
    Mat resizedImage;

    width = int(image.size().width * scale);
    height = int(image.size().height * scale);
    int dim[2] = { width, height };

    resize(image, resizedImage, Size(width, height), INTER_LINEAR);

    return resizedImage;
}

