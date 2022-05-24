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

	Mat dilating(int dilateElem, int dilateSize, Mat image);

private:
	int dilateType = 0;

};

#endif