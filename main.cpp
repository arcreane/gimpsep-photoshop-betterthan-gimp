#include <iostream>
#include "Image.h"
#include "ResizeImage.h"
#include "DilateImage.h"
#include "ErodeImage.h"

int main() {
    String folderLocation = "D:/Projet/gimpsep-photoshop-betterthan-gimp/sample/data";
    String imageName = "squirrel.jpg";

    //cout << "Enter the image folder path\n";
    //cin >> folderLocation;

    Image image;
    
    image.setDataPath(folderLocation);

    //cout << "Enter the image name\n";
    //cin >> imageName;

    image.setImage(folderLocation, imageName);
    image.displayImage();

    String text = "Que voulez-vous faire ? (ecrire un des choix suivant)\n";
    text += "1 = Resize\n2 = Brightness\n3 = Erode\n4 = Dilate\n5 = Panorama\n6 = Stitching\n7 = Show\n8 = Save\n9 = SaveAs\n";
    text += "-1 = Exit\n";
    int wanted = 0;
    
    while(wanted != -1)
    {
        cout << text;
        cin >> wanted;

        if(wanted == 1) 
        {
            double scale;
            ResizeImage resizeImage;


            cout << "\nRentrer l'echelle de resize (nombre supprerieur a 0)\n";
            cin >> scale;

            while (scale < 0) 
            {
                cout << "Rentrer un nombre en 0 et 1 (exemple 0.3)";
                cin >> scale;
            }
            
            image.changeImage(resizeImage.resizing(image.getImage(), scale));
            image.displayImage();
        }
        else if (wanted == 3) {
            int erodeElem;
            cout << "\nEntrer un nombre\nErosion form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
            cin >> erodeElem;

            while (erodeElem < 0 || erodeElem > 2)
            {
                cout << "Entrer un nombre entre 0 et 3\nErosion form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
                cin >> erodeElem;
            }

            int erodeSize;
            cout << "Entrer un nombre supprerieur a 0 - Pourcentage d'erosion\n";
            cin >> erodeSize;

            while (erodeSize < 0)
            {
                cout << "Entrer un nombre supprerieur à 0\n";
                cin >> erodeSize;
            }

            ErodeImage erodeImage;
            image.changeImage(erodeImage.eroding(image.getImage(), erodeElem, erodeSize));
            image.displayImage();
        }
        else if (wanted == 4)
        {
            int dilateElem;
            cout << "\nEntrer un nombre\nDilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
            cin >> dilateElem;

            while (dilateElem < 0 || dilateElem > 2)
            {
                cout << "Entrer un nombre entre 0 et 3\nDilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
                cin >> dilateElem;
            }

            int dilateSize;
            cout << "Entrer un nombre supprerieur a 0 - Pourcentage de dilatation\n";
            cin >> dilateSize;

            while (dilateSize < 0)
            {
                cout << "Entrer un nombre supprerieur à 0\n";
                cin >> dilateSize;
            }

            DilateImage dilateImage;

            image.changeImage(dilateImage.dilating(image.getImage(), dilateElem, dilateSize));
            image.displayImage();
        }
    }
}
