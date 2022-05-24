#ifndef GIMPSEP_DILATEIMAGE_H
#define GIMPSEP_DILATEIMAGE_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class DilateImage
{
public:
	~DilateImage();

	Mat dilating(Mat image, int dilateElem, int dilateSize);

private:
	int dilateType = 0;

};

#endif