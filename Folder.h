#ifndef GIMPSEP_FOLDER_H
#define GIMPSEP_FOLDER_H

#include "Image.h"

class Folder
{
public:
	Folder(String &folderPath);
	~Folder();
	void addImageFromName(String imageName);
	Image getImageFromIndex(int index);
	Mat getMatImageFromIndex(int index);
	void changeImageFromIndex(int index, Mat image);
	void displayImageFromIndex(int index);
	void saveFromIndex(int index);
	void saveAsFromIndex(const String name, int index);

private:
	String path;
	vector<Image> allImages;
};

#endif