#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"
#include <sstream>
#include <iostream>
#include <string>

#include <stdlib.h>
#include <dirent.h>

using namespace cv;
using namespace std;

const int SLICES = 8;
const int CELL_SIZE = 100;
const int GAP = 10;
int imageCount = 0;
const unsigned char isFile =0x8;

void splitBoard(char* dir);

void principal(){

  DIR *dir;
  struct dirent *lsdir;
  dir = opendir("./resource/input");

  /* print all the files and directories within directory */
  while ( ( lsdir = readdir(dir) ) != NULL ){
  	if( strcmp(lsdir->d_name, ".") != 0 && strcmp(lsdir->d_name, "..") != 0 &&  lsdir->d_type == isFile){
    	stringstream filename;
    	filename << "./resource/input/" << lsdir->d_name;
    	char* name = new char[filename.str().length()+1];
    	filename >> name;
    	splitBoard(name);
    	cout << name << "\n";
    }
  }
  closedir(dir);
}

void splitBoard(char* dir){
	Mat image, imageDest;
	image = imread(dir,  CV_LOAD_IMAGE_COLOR);

	if ( !image.data ){
		printf("No image data \n");
	}

	//casa
	Rect roi;
    roi.width = image.size().width;
    roi.height = image.size().height;

    roi.x = roi.width - roi.height ;
    roi.x = max(roi.x / 2, 0);
    roi.y = roi.height - roi.width;
    roi.y = max(roi.y / 2, 0);

    roi.width = min(image.size().width, image.size().height);
    roi.height = min(image.size().width, image.size().height);
    Mat casa = image(roi);
	resize(casa, image, Size(SLICES * CELL_SIZE, SLICES * CELL_SIZE), 0, 0);
	

	roi.width = CELL_SIZE - GAP * 2;
    roi.height =  CELL_SIZE - GAP * 2;
	for(int i = 0; i < SLICES; i++){
		for(int j = 0; j < SLICES; j++){
			roi.x = j * CELL_SIZE + GAP;
			roi.y = i * CELL_SIZE + GAP;
			casa = image(roi);

			stringstream filename;
			filename << "./resource/output/all/img" << std::setw(2) << std::setfill('0') << imageCount << "["<<i << "x" << j << "].jpg";
			imwrite(filename.str(), casa);

			if((i + j) % 2){
				stringstream filename;
				filename << "./resource/output/pair/img" << std::setw(2) << std::setfill('0') << imageCount << "["<<i << "x" << j << "].jpg";
				imwrite(filename.str(), casa);
			}
			else{
				stringstream filename;
				filename << "./resource/output/odd/img" << std::setw(2) << std::setfill('0') << imageCount << "["<<i << "x" << j << "].jpg";
				imwrite(filename.str(), casa);
			}
		}
	}
	imageCount++;
}
