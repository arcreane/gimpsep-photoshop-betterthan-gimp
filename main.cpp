#include <iostream>
#include "OpenCV.h"

int main() {
    String folderLocation;
    String imageName;

    cout << "Enter the image folder path\n";
    cin >> folderLocation;

    OpenCV opencv;
    
    opencv.setDataPath(folderLocation);

    cout << "Enter the image name\n";
    cin >> imageName;
    cout << endl;

    opencv.setImage(folderLocation, imageName);
    opencv.displayImage("Your image");

    string wanted;

    while(wanted == "Exit" || wanted == "exit") {
        cout << "Que voulez-vous faire ? (écrire un des choix suivant)
                \nResize Brightness Erode Dilate Panorama Stitching\n Exit pour stop le programme";
        cin << wanted;
    }

    opencv.~OpenCV();
    delete folderLocation;
    delete imageName;
    delete opencv;
    delete wanted;
}
