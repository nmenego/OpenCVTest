/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int lt_main(int argc, char** argv) {

	Mat inputimage, outputimage;

	inputimage = imread("jessy.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	outputimage = inputimage.clone();

	namedWindow("Input Image", WINDOW_AUTOSIZE);
	imshow("Input Image", inputimage);

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

	for (int i = 0; i < inputimage.cols; i++) {
		for (int j = 0; j < inputimage.rows; j++) {
			outputimage.at<uchar>(j, i) = 255
					* log(1 + inputimage.at<uchar>(j, i) - min)
					/ log(1 + max - min);
		}
	}

	//imwrite("images/output/log.jpg", outputimage);
	namedWindow("Log Transform", WINDOW_AUTOSIZE);
	imshow("Log Transform", outputimage);

	waitKey(0);
	return 0;
}
