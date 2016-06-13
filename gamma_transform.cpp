/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <math.h>
#include "header.h"

using namespace cv;
using namespace std;

int gt_main(int argc, char** argv) {

	Mat inputimage, outputimage;

	inputimage = imread("jessy.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	outputimage = inputimage.clone();

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", inputimage);

	int min = inputimage.at<uchar>(0, 0);
	int max = inputimage.at<uchar>(0, 0);
	for (int i = 0; i < inputimage.cols; i++) {
		for (int j = 0; j < inputimage.rows; j++) {
			if (min > inputimage.at<uchar>(j, i))
				min = inputimage.at<uchar>(j, i);
			if (max < inputimage.at<uchar>(j, i))
				max = inputimage.at<uchar>(j, i);
		}
	}

	float gamma[11] = { .04, .10, .20, .40, .67, 1, 3, 4, 5, 10, 25 };

	for (int g = 0; g < 11; g++) {
		for (int i = 0; i < inputimage.cols; i++) {
			for (int j = 0; j < inputimage.rows; j++) {
				outputimage.at<uchar>(j, i) = 255
						* pow((inputimage.at<uchar>(j, i) - min), gamma[g])
						/ pow((max - min), gamma[g]);
			}
		}
		char filename[20];
		sprintf(filename, "gamma%02d.jpg", g);
		imwrite(filename, outputimage);
	}
	waitKey(0);
	return 0;
}
