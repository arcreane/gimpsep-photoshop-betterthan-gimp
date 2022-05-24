#include <iostream>
#include "Image.h"
#include "ResizeImage.h"

int main() {
    String folderLocation = "D:/Projet/gimpsep-photoshop-betterthan-gimp/sample/data";
    String imageName = "page.png";

    //cout << "Enter the image folder path\n";
    //cin >> folderLocation;

    Image configuratorOfImage;
    
    configuratorOfImage.setDataPath(folderLocation);

    //cout << "Enter the image name\n";
    //cin >> imageName;

    configuratorOfImage.setImage(folderLocation, imageName);
    configuratorOfImage.displayImage();

    String text = "Que voulez-vous faire ? (ecrire un des choix suivant)\n";
    text += "Resize Brightness Erode Dilate Panorama Stitching Show\n";
    text += "Exit pour stop le programme\n";
    string wanted;
    
    while(wanted != "Exit" && wanted != "exit") {
        cout << text;
        cin >> wanted;

        if(wanted == "Resize" || wanted == "resize") {
            double scale;
            ResizeImage resizeImage;


            cout << "Rentrer l'echelle de resize (nombre supprerieur à 0)\n";
            cin >> scale;

            while (scale < 0) {
                cout << "Rentrer un nombre en 0 et 1 (exemple 0.3)";
                cin >> scale;
            }
            
            configuratorOfImage.changeImage(resizeImage.resizing(configuratorOfImage.getImage(), scale));
            configuratorOfImage.displayImage();
        } else if (wanted == "Dilate" || wanted == "dilate") {
            int dilateElem;
            cout << "Dilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
            cin >> dilateElem;

            while (dilateElem < 0 || dilateElem > 3)
            {
                cout << "Entrer un nombre entre 0 et 3\nDilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
                cin >> dilateElem;
            }

            int dilateSize;
            cout << "Entrer un nombre supprerieur à 0\nPourcentage de dilatation\n";
            cin >> dilateSize;

            while (dilateSize)
            {
                cout << "Entrer un nombre supprerieur à 0\n";
                cin >> dilateSize;
            }
        }
    }
}
