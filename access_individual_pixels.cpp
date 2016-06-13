/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "header.h"

using namespace cv;
using namespace std;

int aip_main(int argc, char** argv) {
	Mat input, outputImage;

	input = imread("jessy.jpg", CV_LOAD_IMAGE_COLOR); //image is read as BGR by default

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			input.at<Vec3b>(j, i).val[0] = input.at<Vec3b>(j, i).val[0] + 30;
			input.at<Vec3b>(j, i).val[1] = input.at<Vec3b>(j, i).val[1] + 30;
			input.at<Vec3b>(j, i).val[2] = input.at<Vec3b>(j, i).val[2] + 30;
		}
	}

	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			Vec3b colors = input.at<Vec3b>(j, i);
			cout << "\nBlue " << (int) colors.val[0];
			cout << "\nGreen " << (int) colors.val[1];
			cout << "\nRed " << (int) colors.val[2];
		}
	}

	// Create a window for display.
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	// Show our image inside it.
	imshow("Original Image", input);

	waitKey(0);
	return 0;
}
