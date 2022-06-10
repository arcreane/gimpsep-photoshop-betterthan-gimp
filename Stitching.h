#ifndef GIMPSEP_STITCHING_H
#define GIMPSEP_STITCHING_H

#include <opencv2/opencv.hpp>
#include <string>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>
#include "Folder.h"
using namespace std;
using namespace cv;

class Stitching {

    public:
    Stitching();
    ~Stitching();
    int configuration(Folder folder);
    string result_name = "result.jpg";
    Stitcher::Mode mode = Stitcher::PANORAMA;
    vector<Mat> imgs;

    private:
    int divideImages();
    void nameResult();
    int modeImages();
    int selectingImages(Folder folder);
    bool divide_images = false;
};


#endif //GIMPSEP_STITCHING_H
