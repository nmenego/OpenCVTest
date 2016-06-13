#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "header.h"

void salt(cv::Mat& image, int n) {
    int i, j;

    for (int k = 0; k < n; k++) {
        i = rand() % image.cols;
        j = rand() % image.rows;

        if (image.channels() == 1) {  // gray-level image
            image.at<uchar>(j, i) = 255;
        } else if (image.channels() == 3) { // color image
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

int it_main(int argc, char** argv) {
    srand(cv::getTickCount());

    cv::Mat image = cv::imread("boldt.jpg", 0);

    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

    salt(image, 3000);

    cv::namedWindow("Salted Image");
    cv::imshow("Salted Image", image);

    cv::imwrite("salted.bmp", image);

    cv::waitKey(5000);
    return 0;
}
