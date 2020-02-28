// L1_4_calcPixelAverage.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("D:\\testImage\\1.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	srcMat.copyTo(deepMat);
	shallowMat = srcMat;
	uchar threshold = 100;
	int height = srcMat.rows;//����
	int width = srcMat.cols;//����
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) {
				average = 255;
			}
			else {
				average = 0;
			}
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-------------�������ش���------------------------
		} //���д������ 

	}
	imshow("shallowMat", shallowMat);
	imshow("deepMat", deepMat);
	waitKey();

	return 0;
}
