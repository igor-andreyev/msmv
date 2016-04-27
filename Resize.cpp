//
// Created by iandreyev on 25.04.16.
//

#include "Resize.h"
#include "RandomItem.h"

std::tuple<arguments, cv::Mat> Resize::apply() {
    int m_x = randomize(m_x_min, m_x_max);
    int m_y = randomize(m_y_min, m_y_max);
    cv::Mat img(cv::Size(m_x, m_y), this->m_image.depth(), this->m_image.channels());
    cv::resize(this->m_image, img, img.size());
    return std::tuple<arguments, cv::Mat>(arguments {std::to_string(m_x), std::to_string(m_y)},img);
}