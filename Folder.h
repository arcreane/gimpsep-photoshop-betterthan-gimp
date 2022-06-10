#ifndef GIMPSEP_FOLDER_H
#define GIMPSEP_FOLDER_H

#include "Image.h"

class Folder
{
public:
	Folder(String folderPath);
	~Folder();
	void addImageFromName(String imageName);
	void addImageFromMat(Mat image);
	void addImage(Image image);
	Image getImageFromIndex(int index);
	Mat getMatImageFromIndex(int index);
	String getFolderPath();
	void changeImageFromIndex(int index, Mat image);
	void displayImageFromIndex(int index);
	void saveFromIndex(int index);
	void saveAsFromIndex(const String name, int index);
	int numberOfImage();

private:
	String path;
	vector<Image> allImages;
};

#endif