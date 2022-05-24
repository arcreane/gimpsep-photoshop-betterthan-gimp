#include "DilateImage.h"

DilateImage::~DilateImage() {}

Mat DilateImage::dilating(Mat image, int dilateElem, int dilateSize) 
{
    if (dilateElem == 0) 
    { 
        dilateType = MORPH_RECT;
    } else if (dilateElem == 1) 
    { 
        dilateType = MORPH_CROSS;
    } else if (dilateElem == 2) 
    { 
        dilateType = MORPH_ELLIPSE; 
    }

    Mat element = getStructuringElement(dilateType,
        Size(2 * dilateSize + 1, 2 * dilateSize + 1),
        Point(dilateSize, dilateSize));

    dilate(image, image, element);

    return image;
}

