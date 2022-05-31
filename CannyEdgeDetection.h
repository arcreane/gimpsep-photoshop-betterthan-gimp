#ifndef GIMPSEP_CANNYEDGEDETECTION_H
#define GIMPSEP_CANNYEDGEDETECTION_H

#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;

class CannyEdgeDetection
{
public:
	~CannyEdgeDetection();
	Mat detect(Mat image, int thresholdOne, int thresholdTwo, Size kernelSize);
};

#endif