/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "header.h"

using namespace cv;
using namespace std;

int rsi_main(int argc, char** argv) {

	Mat image;
	image = imread("jessy.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
	Mat outputImage;

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	// Create a window for display.
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	// Show our image inside it.
	imshow("Original Image", image);
	imwrite("blurred.jpg", outputImage);

	waitKey(0);
	return 0;
}
