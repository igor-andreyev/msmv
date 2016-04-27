//
// Created by iandreyev on 11.04.16.
//

#include "SaltPepperNoise.h"

std::tuple<arguments, cv::Mat> SaltPepperNoise::apply() {
    cv::Mat saltpepper_noise = cv::Mat::zeros(this->m_image.rows, this->m_image.cols, CV_8U);
    cv::randu(saltpepper_noise, 0, 255);
    cv::Mat saltpepper_img = this->m_image.clone();
    int m_hi = randomize(this->m_hi_min, this->m_hi_max);
    int m_low = randomize(this->m_low_min, this->m_low_max);
    saltpepper_img.setTo(255, saltpepper_noise > m_hi);
    saltpepper_img.setTo(0, saltpepper_noise < m_low);
    return std::tuple<arguments, cv::Mat>(arguments {std::to_string(m_low), std::to_string(m_hi)}, saltpepper_img);
}
