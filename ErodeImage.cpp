#include "ErodeImage.h"

ErodeImage::~ErodeImage() {}

Mat ErodeImage::eroding(Mat image, int erodeElem, int erodeSize)
{
    if (erodeElem == 0) { 
        erodeType = MORPH_RECT;
    }
    else if (erodeElem == 1) 
    {
        erodeType = MORPH_CROSS;
    }
    else if (erodeElem == 2) 
    { 
        erodeType = MORPH_ELLIPSE;
    }
    Mat element = getStructuringElement(erodeType,
        Size(2 * erodeSize + 1, 2 * erodeSize + 1),
        Point(erodeSize, erodeSize));

    erode(image, image, element);

    return image;
}