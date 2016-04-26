//
// Created by iandreyev on 25.04.16.
//

#include "LensDistort.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

cv::Mat distort_wrapper(cv::Mat _src, double k1, double k2, double p1, double p2) {
    cv::Mat cam;
    cam = cv::Mat::eye(3, 3, CV_64F);

    int w= _src.size().width;
    int h= _src.size().height;
    int c_x = w/2;
    int c_y = h/2;



    cam.at<double>(0,0) = 1.0;
    cam.at<double>(1,0) = 0.0;
    cam.at<double>(2,0) = 0.0;
    cam.at<double>(0,1) = 0.0;
    cam.at<double>(1,1) = 1.0;
    cam.at<double>(2,1) = 0.0;
    cam.at<double>(0,2) = c_x;
    cam.at<double>(1,2) = c_y;
    cam.at<double>(2,2) = 1.0;

    cv::Mat distCoeffs;
    distCoeffs = Mat::zeros(4, 1, CV_64F);

    distCoeffs.at<double>(0,0) = k1;
    distCoeffs.at<double>(1,0) = k2;
    distCoeffs.at<double>(2,0) = p1;
    distCoeffs.at<double>(3,0) = p2;

    cv::Mat result = _src.clone();
    cv::undistort(_src, result, cam, distCoeffs);
    return result;
}



tuple<vector<string>, Mat> LensDistort::apply() {
    cv::Mat result = distort_wrapper(this->m_image, this->m_k1, this->m_k2, this->m_p1, -this->m_p2);
    return std::tuple<std::vector<std::string>, cv::Mat>(this->p_args, result);
}

