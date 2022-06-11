#include <iostream>
#include "ResizeImage.h"
#include "DilateImage.h"
#include "ErodeImage.h"
#include "CannyEdgeDetection.h"
#include "Stitching.h"

String askFolder() 
{
    String folderLocation;

    cout << "Entrer le chemin du dossier\n";
    cin >> folderLocation;

    while (folderLocation.size() == 0) {
        cout << "Entrer un chemin valide\n";
        cin >> folderLocation;
    }

    return folderLocation;
}

void askImage(Folder& folder) 
{
    String imageName;

    cout << "Entrer le nom de l'image (avec l'extention)\n";
    cin >> imageName;

    while (imageName.size() == 0)
    {
        cout << "Entrer le nom de l'image (avec l'extention)\n";
        cin >> imageName;
    }

    folder.addImageFromName(imageName);
}

int askWantOption()
{
    int wanted;

    String text = "Que voulez-vous faire ?\n";
    text += "1 = Redimensionner\n2 = Luminositer\n3 = Eroder\n4 = Dilater\n5 = Panorama\n";
    text += "6 = Detection contours\n7 = Afficher l'image\n8 = Sauvegarder\n9 = Sauvegarder sous\n";
    text += "0 = Quitter\n";

    cout << text;
    cin >> wanted;

    return wanted;
}

bool wantToStartWithImage()
{
    String wanted;

    cout << "Voulez-vous commencer avec une image ? (Oui/Non)\n";
    cin >> wanted;

    if (wanted == "O" || wanted == "o" || wanted == "Oui" || wanted == "oui")
    {
        return true;
    }

    return false;
}

bool asImageDefine(Folder folder)
{
    if (folder.numberOfImage() == 0) {
        return false;
    }
    
    return true;
}

double askResize()
{
    double scale;

    cout << "\nRentrer l'echelle de resize (nombre supprerieur a 0)\n";
    cin >> scale;

    while (scale < 0)
    {
        cout << "Rentrer un nombre supérieur à 0 (exemple 1.3)";
        cin >> scale;
    }

    return scale;
}

int askBrightness()
{
    int level;

    cout << "\nEntrer un nombre - Pourcentage de luminosité\n";
    cin >> level;

    return level;
}

int askErodeElem()
{
    int erodeElem;
    cout << "\nEntrer un le type d'Erosion:\n 0: Rect\n 1: Cross\n 2: Ellipse\n";
    cin >> erodeElem;

    while (erodeElem < 0 || erodeElem > 2)
    {
        cout << "Entrer un nombre entre 0 et 3\nErosion form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
        cin >> erodeElem;
    }

    return erodeElem;
}

int askErodeSize()
{
    int erodeSize;
    cout << "Entrer un nombre supprerieur a 0 - Pourcentage d'erosion\n";
    cin >> erodeSize;

    while (erodeSize < 0)
    {
        cout << "Entrer un nombre supprerieur � 0\n";
        cin >> erodeSize;
    }

    return erodeSize;
}

int askDilateElem()
{
    int dilateElem;
    cout << "\nEntrer un nombre\nDilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
    cin >> dilateElem;

    while (dilateElem < 0 || dilateElem > 2)
    {
        cout << "Entrer un nombre entre 0 et 3\nDilatation form:\n 0: Rect \n 1: Cross \n 2: Ellipse\n";
        cin >> dilateElem;
    }

    return dilateElem;
}

int askDilateSize()
{
    int dilateSize;

    cout << "Entrer un nombre supprerieur a 0 - Pourcentage de dilatation\n";
    cin >> dilateSize;

    while (dilateSize < 0)
    {
        cout << "Entrer un nombre supprerieur � 0\n";
        cin >> dilateSize;
    }

    return dilateSize;
}

int askThresholdOne() {
    int thresholdOne;

    cout << "Pour la detection de contours, nous utilisons un comparateur à Hysteresis (aka a double seuil).\n";
    cout << "Par consequent, vous aurez a renseigner les deux seuils (haut et bas) du comparateur.\n";
    cout << "Entrer le premier seuil (bas) du comparateur (valeur normal : 100)\n";
    cin >> thresholdOne;

    while (thresholdOne < 0)
    {
        cout << "Entrer un nombre supérieur a 0\n";
        cin >> thresholdOne;
    }

    return thresholdOne;
}

int askThresholdTwo()
{
    int thresholdTwo;

    cout << "Entrer le second seuil (haut) du comparateur (valeur normal : 200)\n";
    cin >> thresholdTwo;

    while (thresholdTwo < 0)
    {
        cout << "Entrer un nombre supérieur a 0\n";
        cin >> thresholdTwo;
    }

    return thresholdTwo;
}

int askKernelColSize() {
    int kernelColSize;

    cout << "Afin de pauffiner la detection, nous utilisons un filtre a convolution blurrGaussian.\n";
    cout << "Par consequent, nous avons besoin d'une matrice de convolution (kernel).\n";
    cout << "Entrer le nombre de colonnes dans la matrice de convolution (valeur normal : 3)\n";
    cin >> kernelColSize;

    while (kernelColSize < 1)
    {
        cout << "Entrer un nombre supérieur a 1\n";
        cin >> kernelColSize;
    }

    return kernelColSize;
}

int askkernelRowSize()
{
    int kernelRowSize;
    cout << "Entrer le nombre de lignes dans la matrice de convolution (valeur normal : 3)\n";
    cin >> kernelRowSize;

    while (kernelRowSize < 1)
    {
        cout << "Entrer un nombre supérieur a 1\n";
        cin >> kernelRowSize;
    }

    return kernelRowSize;
}

String askImageName()
{
    String newImageName;

    cout << "Entrer le nom le l'image sans l'extention\n";
    cin >> newImageName;

    while (newImageName.size() == 0)
    {
        cout << "Entrer le nom le l'image sans l'extention\n";
        cin >> newImageName;
    }
    
    return newImageName;
}

String askExtension()
{
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
        return ".png";
    }

    return  ".jpg";
}

int main() {
    Folder folder = Folder(askFolder());

    bool wantImage = wantToStartWithImage();
    if (wantImage) {
        askImage(folder);
        folder.displayImageFromIndex(0);
    }

    int wanted = -1;
    
    while(wanted != 0)
    {
        wanted = askWantOption();

        if (!asImageDefine(folder) && wanted != 5) {
            askImage(folder);
        }
        
        if(wanted == 1) 
        {
            double scale = askResize();
            ResizeImage resizeImage = ResizeImage(folder, scale);
            resizeImage.~ResizeImage();
        }
        else if (wanted == 2)
        {
            int level = askBrightness();

            Mat imageBrighness;
            folder.getMatImageFromIndex(0).convertTo(imageBrighness, -1, 1, level);
            folder.changeImageFromIndex(0, imageBrighness);
            folder.displayImageFromIndex(0);
            imageBrighness.~Mat();
        }
        else if (wanted == 3) {
            int erodeElem = askErodeElem();

            int erodeSize = askErodeSize();

            ErodeImage erodeImage = ErodeImage(folder, erodeElem, erodeSize);
            erodeImage.~ErodeImage();
        }
        else if (wanted == 4)
        {
            int dilateElem = askDilateElem();
            int dilateSize = askDilateSize();

            DilateImage dilateImage = DilateImage(folder, dilateElem, dilateSize);
            dilateImage.~DilateImage();
        }
        else if (wanted == 5) 
        {
            Folder folderForStitching = Folder(folder.getFolderPath());
            try
            {
                Stitching stitching = Stitching(folderForStitching);
            }
            catch (const runtime_error& e)
            {
                cerr << e.what() << endl;
                return -1;
            }

            int index = folderForStitching.numberOfImage() - 1;
            if (asImageDefine(folder)) {
                folder.changeImageFromIndex(0, folderForStitching.getMatImageFromIndex(index));
            }
            else
            {
                folder.addImage(folderForStitching.getImageFromIndex(index));
            }
        }
        else if (wanted == 6)
        {
            int thresholdOne = askThresholdOne();
            int thresholdTwo = askThresholdTwo();
            int kernelColSize = askKernelColSize();
            int kernelRowSize = askkernelRowSize();
            Size kernelSize = Size(kernelColSize, kernelRowSize);

            CannyEdgeDetection cannyEdgeDetection = CannyEdgeDetection(folder, thresholdOne, thresholdTwo, kernelSize);
            cannyEdgeDetection.~CannyEdgeDetection();
        }
        else if (wanted == 7) {
            folder.displayImageFromIndex(0);
        }
        else if (wanted == 8) {
            folder.saveFromIndex(0);
        }
        else if (wanted == 9) {
            String newImageName = askImageName() + askExtension();

            folder.saveAsFromIndex(newImageName, 0);
            newImageName.clear();
        }
    }

    return 0;
}