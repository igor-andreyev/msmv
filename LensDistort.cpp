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



tuple<arguments, Mat> LensDistort::apply() {
    double m_k1, m_k2, m_p1, m_p2;
    m_k1 = randomize(this->m_k1_min, this->m_k1_max);
    m_k2 = randomize(this->m_k2_min, this->m_k2_max);
    m_p1 = randomize(this->m_p1_min, this->m_p1_max);
    m_p2 = randomize(this->m_p2_min, this->m_p2_max);
    cv::Mat result = distort_wrapper(this->m_image, m_k1, m_k2, m_p1, m_p2);
    return std::tuple<arguments, cv::Mat>(arguments {std::to_string(m_k1), std::to_string(m_k2), std::to_string(m_p1), std::to_string(m_p2)}, result);
}


