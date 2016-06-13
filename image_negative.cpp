/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "header.h"
using namespace cv;

int in_main(int argc, char** argv) {
	string original_image = "Original Image";
	string negative_image = "Negative Image";

	//read the image in matrix image
	Mat image = imread("jessy.jpg");
	cvtColor(image, image, CV_BGR2GRAY);

	// initialize matrix with 0 for our result
	Mat new_image = Mat::zeros(image.size(), image.type());
	// initialize matrix with 255
	Mat sub_mat = Mat::ones(image.size(), image.type()) * 255;

	//subtract the original matrix by sub_mat to give the negative output new_image
	subtract(sub_mat, image, new_image);

	// Create Windows
	namedWindow(original_image, 1);
	namedWindow(negative_image, 1);

	// Show stuff
	imshow(original_image, image);
	imshow(negative_image, new_image);

	// Wait until user press some key
	waitKey();
	return 0;
}
