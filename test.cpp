//
// Created by Cecile LI on 10/06/2022.
//
#include <iostream>
#include <fstream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include "Folder.h"

using namespace std;
using namespace cv;

// Define mode for stitching as panorama
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures
vector<Mat> imgs;

int main()
{
    String folderLocation = "/Users/cecile/Documents/GitHub/Gimpsep/sample/test";
    Folder folder = Folder(folderLocation);

    // Get all the images that need to be
    // stitched as arguments from command line
    String text = "Number of image\n";
    cout << text;
    int nb;
    cin >> nb;
    for (int i = 0; i < nb; ++i)
    {
        // Read the ith argument or image
        // and push into the image array
        String text = "path\n";
        cout << text;
        String filename;
        cin >> filename;
        Mat img = imread(filename);
        if (img.empty())
        {
            // Exit if image is not present
            cout << "Can't read image '" << filename << "'\n";
            return -1;
        }
        imgs.push_back(img);
        /*String imageName;
        cin >> imageName;
        folder.addImageFromName(imageName);*/
    }

    // Define object to store the stitched image
    Mat pano;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode);

    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);
    //Stitcher::Status status = stitcher->stitch(folder.getMatImage(), pano);

    if (status != Stitcher::OK)
    {
        // Check if images could not be stitched
        // status is OK if images are stitched successfully
        cout << "Can't stitch images\n";
        return -1;
    }

    // Store a new image stitched from the given
    //set of images as "result.jpg"
    imwrite("result.jpg", pano);

    // Show the result
    imshow("Result", pano);

    waitKey(0);
    return 0;
}
