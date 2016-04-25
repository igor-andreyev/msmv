//
// Created by iandreyev on 11.04.16.
//

#include "GaussianNoise.h"

std::tuple<std::vector<std::string>, cv::Mat> GaussianNoise::apply() {
    cv::Mat img = this->m_image.clone();
    cv::randn(img, this->m_mean, this->m_stddev);
    return std::tuple<std::vector<std::string>, cv::Mat>(this->p_args, this->m_image + img);
}
