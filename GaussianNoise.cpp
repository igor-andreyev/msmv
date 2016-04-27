//
// Created by iandreyev on 11.04.16.
//

#include "GaussianNoise.h"

std::tuple<arguments, cv::Mat> GaussianNoise::apply() {
    cv::Mat img = this->m_image.clone();

    int m_mean = randomize(m_mean_min, m_mean_max);
    int m_stddev = randomize(m_stddev_min, m_stddev_max);


    cv::randn(img, m_mean, m_stddev);
    return std::tuple<arguments, cv::Mat>(arguments{std::to_string(m_mean), std::to_string(m_stddev)}, this->m_image + img);
}
