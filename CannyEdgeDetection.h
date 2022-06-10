#ifndef GIMPSEP_CANNYEDGEDETECTION_H
#define GIMPSEP_CANNYEDGEDETECTION_H

#include <opencv2/opencv.hpp>
#include <string>
#include "Folder.h"

using namespace cv;
using namespace std;

class CannyEdgeDetection
{
public:
	CannyEdgeDetection(Folder& folder, int thresholdOne, int thresholdTwo, Size kernelSize);
	~CannyEdgeDetection();
	Mat detect(Mat image, int thresholdOne, int thresholdTwo, Size kernelSize);
};

#endif