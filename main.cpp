#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
using namespace std;
using namespace cv;

int main()
{
	string data_path = "D:/Structured_Light_Data/Res1111/MoveSlow1111/XY/";
	string savePath = "D:/Structured_Light_Data/Res1111/MoveSlow1111/XYforMatlab/";
	string fileName = "XY";
	string fileSuffix = ".yml";
	
	int iBegin = 1;
	int iEnd = 50;

	for (int i = iBegin; i <= iEnd; i++)
	{
		string idx2str;
		strstream ss;
		ss << i;
		ss >> idx2str;

		FileStorage fs;
		fs.open(data_path + fileName + idx2str + fileSuffix, FileStorage::READ);
		Mat iH, iW, deltaH, deltaW;
		fs["iX"] >> iH;
		fs["iY"] >> iW;
		fs["deltaX"] >> deltaH;
		fs["deltaW"] >> deltaW;
		fs.release();

		Size size;
		fstream file;
		
		size = iH.size();
		file.open(savePath + "iH" + idx2str + ".txt", ios::out);
		for (int h = 0; h < size.height; h++)
		{
			for (int w = 0; w < size.width; w++)
			{
				file << iH.at<double>(h, w) << " ";
			}
			file << endl;
		}
		file.close();

		size = iW.size();
		file.open(savePath + "iW" + idx2str + ".txt", ios::out);
		for (int h = 0; h < size.height; h++)
		{
			for (int w = 0; w < size.width; w++)
			{
				file << iW.at<double>(h, w) << " ";
			}
			file << endl;
		}
		file.close();

		size = deltaH.size();
		file.open(savePath + "deltaH" + idx2str + ".txt", ios::out);
		for (int h = 0; h < size.height; h++)
		{
			for (int w = 0; w < size.width; w++)
			{
				file << deltaH.at<double>(h, w) << " ";
			}
			file << endl;
		}
		file.close();

		size = deltaW.size();
		file.open(savePath + "deltaW" + idx2str + ".txt", ios::out);
		for (int h = 0; h < size.height; h++)
		{
			for (int w = 0; w < size.width; w++)
			{
				file << deltaW.at<double>(h, w) << " ";
			}
			file << endl;
		}
		file.close();
	}
}