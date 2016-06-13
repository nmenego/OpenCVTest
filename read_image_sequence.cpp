#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/video.hpp>
#include "header.h"

using namespace cv;

int ris_main(  int argc, char** argv )
{
  int frameCount = 0;

  Mat image;

  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened()) {  // check if we succeeded
      return -1;
  }

  namedWindow("Original Image Sequence",CV_WINDOW_AUTOSIZE);

  for(;; frameCount++) {

	  if (frameCount % 100 == 0) {
		  printf("frameCount = %d \n", frameCount);
	  }

      Mat frame;
      cap >> frame; // get a new frame from camera
      imshow("Original Image Sequence", frame);

      Mat grayimage;
      cvtColor (frame, grayimage, CV_BGR2GRAY);
      imshow("Gray Image", grayimage);

      Mat blurred;
//      medianBlur (frame, blurred, 31);
      GaussianBlur(frame, blurred, Size(15, 15), 0.0,0.0,0);
      imshow("Blurred Image", blurred);
      if(waitKey(20) >= 0) break;
  }
  // the camera will be de-initialized automatically in VideoCapture destructor

  printf("frameCount = %d \n", frameCount);
  return 0;
}

