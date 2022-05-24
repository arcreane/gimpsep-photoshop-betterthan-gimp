#include <iostream>
#include "OpenCV.h"

int main() {
    cout << "Hello, World!" << endl;
    String folderLocation;
    String imageName;
    cout << "Enter the image folder path\n";
    cin >> folderLocation;

    OpenCV opencv;
    
    opencv.setDataPath(folderLocation);

    cout << "Enter the image name\n";
    cin >> imageName;

    opencv.setImage(imageName);
    opencv.displayImage("tetes");
}
