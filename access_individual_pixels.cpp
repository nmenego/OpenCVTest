#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "header.h"

using namespace cv;
using namespace std;

int aip_main( int argc, char** argv )
{
	Mat input, outputImage;

	input = imread(argv[1]);	//image is read as BGR by default

	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++) {
			Vec3b colors = input.at<Vec3b>(j,i);
			cout << "\nBlue " << (int)colors.val[0];
			cout << "\nRed " << (int) colors.val[0];
			cout << "\nGreen " << (int)colors.val[0];
		}

}
