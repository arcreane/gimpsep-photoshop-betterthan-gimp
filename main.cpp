#include <iostream>
#include "Folder.h"
#include "ResizeImage.h"
#include "DilateImage.h"
#include "ErodeImage.h"
#include "CannyEdgeDetection.h"
#include "Stitching.h"

int main() {
    String folderLocation;
    String imageName;

    cout << "Entrer le chemin du dossier\n";
    cin >> folderLocation;

    while (folderLocation.size() == 0) {
        cout << "Entrer le chemin du dossier\n";
        cin >> folderLocation;
    }

    Folder folder = Folder(folderLocation);

    cout << "Entrer le nom de l'image (avec l'extention)\n";
    cin >> imageName;

    while (imageName.size() == 0)
    {
        cout << "Entrer le nom de l'image (avec l'extention)\n";
        cin >> imageName;
    }

    folder.addImageFromName(imageName);
    
    folder.displayImageFromIndex(0);

    String text = "Que voulez-vous faire ?\n";
    text += "1 = Redimensionner\n2 = Luminositer\n3 = Eroder\n4 = Dilater\n5 = Panorama\n";
    text += "6 = Detection contours\n7 = Afficher l'image\n8 = Sauvegarder\n9 = Sauvegarder sous\n";
    text += "0 = Quitter\n";
    int wanted = -1;
    
    while(wanted != 0)
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
                cout << "Rentrer un nombre supérieur à 0 (exemple 1.3)";
                cin >> scale;
            }
            
            folder.changeImageFromIndex(0, resizeImage.resizing(folder.getMatImageFromIndex(0), scale));
            folder.displayImageFromIndex(0);
            resizeImage.~ResizeImage();
        }
        else if (wanted == 2)
        {
            int level;
            cout << "\nEntrer un nombre - Pourcentage de luminosité\n";
            cin >> level;

            Mat imageBrighness;
            folder.getMatImageFromIndex(0).convertTo(imageBrighness, -1, 1, level);
            folder.changeImageFromIndex(0, imageBrighness);
            folder.displayImageFromIndex(0);
            imageBrighness.~Mat();
        }
        else if (wanted == 3) {
            int erodeElem;
            cout << "\nEntrer un le type d'Erosion:\n 0: Rect\n 1: Cross\n 2: Ellipse\n";
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
                cout << "Entrer un nombre supprerieur � 0\n";
                cin >> erodeSize;
            }

            ErodeImage erodeImage;
            folder.changeImageFromIndex(0, erodeImage.eroding(folder.getMatImageFromIndex(0), erodeElem, erodeSize));
            folder.displayImageFromIndex(0);
            erodeImage.~ErodeImage();
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
                cout << "Entrer un nombre supprerieur � 0\n";
                cin >> dilateSize;
            }

            DilateImage dilateImage;

            folder.changeImageFromIndex(0, dilateImage.dilating(folder.getMatImageFromIndex(0), dilateElem, dilateSize));
            folder.displayImageFromIndex(0);
            dilateImage.~DilateImage();
        }
        else if (wanted == 5) 
        {
            Folder folder = Folder(folderLocation);
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
        else if (wanted == 6)
        {
            cout << "Pour la detection de contours, nous utilisons un comparateur à Hysteresis (aka a double seuil).\n";
            cout << "Par consequent, vous aurez a renseigner les deux seuils (haut et bas) du comparateur.\n";
            int thresholdOne;
            cout << "Entrer le premier seuil (bas) du comparateur (par defaut 100)\n";
            cin >> thresholdOne;

            int thresholdTwo;
            cout << "Entrer le second seuil (haut) du comparateur (par defaut 200)\n";
            cin >> thresholdTwo;

            cout << "Afin de pauffiner la detection, nous utilisons un filtre a convolution blurrGaussian.\n"; 
            cout << "Par consequent, nous avons besoin d'une matrice de convolution (kernel).\n";
            
            int kernelColSize;
            cout << "Entrer le nombre de colonnes dans la matrice de convolution (par defaut 3)\n";
            cin >> kernelColSize;

            int kernelRowSize;
            cout << "Entrer le nombre de lignes dans la matrice de convolution (par defaut 3)\n";
            cin >> kernelRowSize;

            Size kernelSize = Size(kernelColSize,kernelRowSize);

            CannyEdgeDetection cannyEdgeDetection;
            folder.changeImageFromIndex(0, cannyEdgeDetection.detect(folder.getMatImageFromIndex(0),thresholdOne,thresholdTwo,kernelSize));
            folder.displayImageFromIndex(0);
        }
        else if (wanted == 7) {
            folder.displayImageFromIndex(0);
        }
        else if (wanted == 8) {
            folder.saveFromIndex(0);
        }
        else if (wanted == 9) {
            String newImageName;

            cout << "Entrer le nom le l'image sans l'extention\n";
            cin >> newImageName;

            while (newImageName.size() == 0)
            {
                cout << "Entrer le nom le l'image sans l'extention\n";
                cin >> newImageName;
            }

            int extension;
            cout << "Entrer l'extention voulue:\n0 = png\n1 = jpg\n";
            cin >> extension;

            if (extension < 0 && extension > 1)
            {
                cout << "Entrer l'extention voulue:\n0 = png\n1 = jpg\n";
                cin >> extension;
            }

            if (extension == 0)
            {
                newImageName += ".png";
            }
            else
            {
                newImageName += ".jpg";
            }

            folder.saveAsFromIndex(newImageName, 0);
            newImageName.clear();
        }
    }

    return 0;
}