//
// Created by Cecile LI on 07/06/2022.
//

#include "Stitching.h"

Stitching::Stitching(Folder& folder) 
{
    int configSuccess = configuration(folder);
    if (configSuccess) {
        throw exception("La configuration a échouée");
    }

    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        throw exception("Can't stitch images, error code = " + int(status));
    }

    cout << "stitching réalisé avec succès\n";

    folder.addImageFromMat(pano);
    folder.displayImageFromIndex(folder.numberOfImage() - 1);
}

Stitching::~Stitching() {}

int Stitching::divideImages()
{
    String question = "Voulez-vous créer en interne trois morceaux de chaque image pour augmenter le succès de l'assemblage ?\n(O/N)\n";
    String wanted;

    cout << question;
    cin >> wanted;

    if (wanted == "O" || wanted == "o" || wanted == "Oui" || wanted == "oui"){
        divide_images = true;
    }
    else {
        divide_images = false;
    }

    return EXIT_SUCCESS;
}

int Stitching::modeImages(){
    String text = "Voulez-vous changer la configuration de l'assembleur en scans ? (par défaut :panorama)\n(O/N)\n";
    String wanted;

    cout << text;
    cin >> wanted;
    if (wanted == "N" || wanted == "n" || wanted == "Non" || wanted == "non"){
    }
    else if (wanted == "O" || wanted == "o" || wanted == "Oui" || wanted == "oui"){
        mode = Stitcher::SCANS;
    }
    else
    {
        cout << "Bad value\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int Stitching::selectingImages(Folder folder)
{
    String text = "Nombre d'images ?\n";
    int numberOfImage;
    cout << text;
    cin >> numberOfImage;

    while (numberOfImage < 1)
    {
        cout << "Entrer un nombre supérieur à 1\n";
        cin >> numberOfImage;
    }

    Image img;
    for (int i = 0; i < numberOfImage; ++i){
        String text = "Nom de l'image n°" + to_string(i + 1) + " (avec l'extension) :\n";
        String imageName;

        cout << text;
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
        else {
            imgs.push_back(img.getImage());
        }
    }
}

int Stitching::configuration(Folder folder)
{
    String question = "Vous-voulez changer les parametres ? (O/N)\n";
    String wanted;

    cout << question;
    cin >> wanted;

    if(wanted == "O" || wanted == "o" || wanted == "Oui" || wanted == "oui")
    {
        divideImages();
        modeImages();
    }

    selectingImages(folder);

    return EXIT_SUCCESS;
}