#include "CannyEdgeDetection.h"

CannyEdgeDetection::CannyEdgeDetection(Folder& folder, int thresholdOne, int thresholdTwo, Size kernelSize)
{
	folder.changeImageFromIndex(0, detect(folder.getMatImageFromIndex(0), thresholdOne, thresholdTwo, kernelSize));
	folder.displayImageFromIndex(0);
}

CannyEdgeDetection::~CannyEdgeDetection() {}

Mat CannyEdgeDetection::detect(Mat image, int thresholdOne, int thresholdTwo, Size kernelSize)
{
	Mat blurredImage;
	GaussianBlur(image, blurredImage, kernelSize, (0.0));

	Mat cannyImage;
	Canny(blurredImage, cannyImage, thresholdOne, thresholdTwo);

	return cannyImage;
};
