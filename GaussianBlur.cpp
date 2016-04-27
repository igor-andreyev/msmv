//
// Created by iandreyev on 11.04.16.
//
#include <opencv2/imgproc/imgproc.hpp>
#include "GaussianBlur.h"

std::tuple<arguments, cv::Mat> GaussianBlur::apply() {
    cv::Mat result = cv::Mat::zeros(this->m_image.size(), this->m_image.type());

    int window_x = odd_randomize(this->m_window_x_min, this->m_window_x_max);
    int window_y = odd_randomize(this->m_window_y_min, this->m_window_y_max);
    double m_stddev = randomize(this->m_stddev_min, this->m_stddev_max);

    cv::GaussianBlur(this->m_image, result, cv::Size(window_x, window_y), m_stddev);
    return std::tuple<arguments, cv::Mat>(arguments{std::to_string(window_x), std::to_string(window_y), std::to_string(m_stddev)}, result);
}

