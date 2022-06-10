//
// Created by Cecile LI on 07/06/2022.
//

#include "Stitching.h"

Stitching::Stitching() {}

Stitching::~Stitching() {}

int Stitching::divideImages(){
    String question = "Do you want to internally creates three chunks of each image to increase stitching success ?\nyes/no\n";
    cout << question;
    String choice;
    cin >> choice;
    if (choice == "yes"){
        divide_images = true;
    }
    else if (choice == "no"){
        divide_images = false;
    }
    else
    {
        cout << "Bad value\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void Stitching::nameResult(){
    String text2 = "Name the output of the image :\n";
    cout << text2;
    String choice2;
    cin >> choice2;
    result_name = choice2;
}

int Stitching::modeImages(){
    String text3 = "Do you want to change configuration of stitcher to scans ? (default is panorama)\nyes/no\n";
    cout << text3;
    String choice3;
    cin >> choice3;
    if (choice3 == "no"){
    }
    else if (choice3 == "yes"){
        mode = Stitcher::SCANS;
    }
    else
    {
        cout << "Bad value\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int Stitching::selectingImages(Folder folder){
    String text = "Number of image\n";
    cout << text;
    int nb;
    cin >> nb;
    Image img;
    for (int i = 0; i < nb; ++i){
        String text = "name of the file : \n";
        cout << text;
        String imageName;
        cin >> imageName;
        folder.addImageFromName(imageName);
        img = folder.getImageFromIndex(i);
        if (img.getImage().empty())
        {
            cout << "Can't read image \n";
            return EXIT_FAILURE;
        }
        if (divide_images)
        {
            Rect rect(0, 0, img.getImage().cols / 2, img.getImage().rows);
            imgs.push_back(img.getImage()(rect).clone());
            rect.x = img.getImage().cols / 3;
            imgs.push_back(img.getImage()(rect).clone());
            rect.x = img.getImage().cols / 2;
            imgs.push_back(img.getImage()(rect).clone());
        }
        else
            imgs.push_back(img.getImage());
    }
}

int Stitching::configuration(Folder folder)
{
    String question = "Enter 'edit' if you want to edit the parameters \n";
    cout << question;
    String wanted;
    cin >> wanted;
    if(wanted == "edit")
    {
        divideImages();
        nameResult();
        modeImages();
    }
    selectingImages(folder);
    return EXIT_SUCCESS;
}

int main()
{
    String path = "/Users/cecile/Documents/GitHub/Gimpsep/sample/data";
    Folder folder = Folder(path);
    Stitching stitching = Stitching();
    int configSuccess = stitching.configuration(folder);
    if (configSuccess) return EXIT_FAILURE;
    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(stitching.mode);
    Stitcher::Status status = stitcher->stitch(stitching.imgs, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return EXIT_FAILURE;
    }
    imwrite(stitching.result_name, pano);
    cout << "stitching completed successfully\n" << stitching.result_name << " saved!";
    imshow("Result", pano);
    waitKey(0);
    return EXIT_SUCCESS;
}