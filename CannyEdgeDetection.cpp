#include "CannyEdgeDetection.h"

CannyEdgeDetection::~CannyEdgeDetection() {}

Mat CannyEdgeDetection::detect(Mat image, int thresholdOne, int thresholdTwo, Size kernelSize)
{
	Mat blurredImage;
	GaussianBlur(image, blurredImage, kernelSize, (0.0));

	Mat cannyImage;
	Canny(blurredImage, cannyImage, thresholdOne, thresholdTwo);

	return cannyImage;
};
