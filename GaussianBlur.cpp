//
// Created by iandreyev on 11.04.16.
//
#include <opencv2/imgproc/imgproc.hpp>

#include "GaussianBlur.h"

cv::Mat GaussianBlur::apply() {
    cv::Mat result = cv::Mat::zeros(this->m_image.size(), this->m_image.type());
    cv::GaussianBlur(this->m_image, result, this->m_window, this->m_stddev);
    return result;
}