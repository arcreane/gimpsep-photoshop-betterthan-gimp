#ifndef GIMPSEP_DILATEIMAGE_H
#define GIMPSEP_DILATEIMAGE_H

#include <opencv2/opencv.hpp>
#include <string>
#include "Folder.h"

using namespace cv;
using namespace std;

class DilateImage
{
public:
	DilateImage(Folder& folder, int dilateElem, int dilateSize);
	~DilateImage();

	Mat dilating(Mat image, int dilateElem, int dilateSize);

private:
	int dilateType = 0;

};

#endif