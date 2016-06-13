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

int e1_main(int argc, char** argv) {
	int frameCount = 0;

	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) {  // check if we succeeded
		return -1;
	}

	string original_image = "Original Image";
	string log_image = "Log Transform Image";
	string gamma_image = "Gamma Transform Image";

	namedWindow(original_image, CV_WINDOW_AUTOSIZE);
	namedWindow(log_image, CV_WINDOW_AUTOSIZE);
	namedWindow(log_image, CV_WINDOW_AUTOSIZE);

	for (;; frameCount++) {

		if (frameCount % 100 == 0) {
			printf("frameCount = %d \n", frameCount);
		}

		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, frame, CV_BGR2GRAY);
		imshow(original_image, frame);

		Mat logImage = frame.clone();

		int min = logImage.at<uchar>(0, 0);
		int max = logImage.at<uchar>(0, 0);
		for (int i = 0; i < logImage.cols; i++) {
			for (int j = 0; j < frame.rows; j++) {
				if (min > logImage.at<uchar>(j, i))
					min = logImage.at<uchar>(j, i);
				if (max < logImage.at<uchar>(j, i))
					max = logImage.at<uchar>(j, i);
			}
		}

		for (int i = 0; i < logImage.cols; i++) {
			for (int j = 0; j < logImage.rows; j++) {
				logImage.at<uchar>(j, i) = 255
						* log(1 + logImage.at<uchar>(j, i) - min)
						/ log(1 + max - min);
			}
		}

		imshow(log_image, logImage);

		// gamma transformation
		Mat gammaImage = frame.clone();
		float gamma = .04;
		for (int i = 0; i < gammaImage.cols; i++) {
			for (int j = 0; j < gammaImage.rows; j++) {
				gammaImage.at<uchar>(j, i) = 255
						* pow((gammaImage.at<uchar>(j, i) - min), gamma)
						/ pow((max - min), gamma);
			}
		}

		imshow(gamma_image, gammaImage);

		// wait for input...
		if (waitKey(20) >= 0)
			break;
	}

	return 0;
}
