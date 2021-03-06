#ifndef GIMPSEP_ErodeImage_H
#define GIMPSEP_ErodeImage_H

#include <opencv2/opencv.hpp>
#include <string>
#include "Folder.h"

using namespace cv;
using namespace std;

class ErodeImage
{
public:
	ErodeImage(Folder& folder, int erodeElem, int erodeSize);
	~ErodeImage();

	Mat eroding(Mat image, int erodeElem, int erodeSize);

private:
	int erodeType = 0;

};

#endif