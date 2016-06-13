/* ---------------------------------------------------------------------------
** UP DCS Summer School API 2016
** Image Processing and Computer Vision Class
**
** Author: nmenego
** -------------------------------------------------------------------------*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int e2_main(int argc, char** argv) {
	Mat src, dst;

	char* source_window = "Source image";
	char* equalized_window = "Equalized Image";

	// Load image
	src = imread("jessy.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	if (!src.data) {
		cout << "File not found!" << endl;
		return -1;
	}

	// Apply Histogram Equalization
	equalizeHist(src, dst);

	// Display results
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);

	imshow(source_window, src);
	imshow(equalized_window, dst);

	/// Wait until user exits the program
	waitKey(0);

	return 0;
}
