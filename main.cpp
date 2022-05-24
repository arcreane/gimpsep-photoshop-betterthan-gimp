#include <iostream>
#include "Image.h"
#include "Resize.h"

int main() {
    String folderLocation;
    String imageName;

    cout << "Enter the image folder path\n";
    cin >> folderLocation;

    Image configuratorOfImage;
    
    configuratorOfImage.setDataPath(folderLocation);

    cout << "Enter the image name\n";
    cin >> imageName;
    cout << endl;

    configuratorOfImage.setImage(folderLocation, imageName);
    configuratorOfImage.displayImage("Your image");

    string wanted;

    while(wanted == "Exit" || wanted == "exit") {
        cout << "Que voulez-vous faire ? (écrire un des choix suivant)\nResize Brightness Erode Dilate Panorama Stitching\n Exit pour stop le programme";
        cin >> wanted;

        if(wanted == "Resize" || wanted == "resize" ) {
            double scale;
            Resize resize;

            cout << "Rentrer l'échelle de resize (nombre entre 0 et 1)";
            cin >> scale;
            
            configuratorOfImage.changeImage(resize.resizeImage(configuratorOfImage.getImage(), scale));
        }
    }
}
