//
// Created by iandreyev on 11.04.16.
//

#include "SaltPepperNoise.h"

std::tuple<std::vector<std::string>, cv::Mat> SaltPepperNoise::apply() {
    cv::Mat saltpepper_noise = cv::Mat::zeros(this->m_image.rows, this->m_image.cols, CV_8U);
    cv::randu(saltpepper_noise, 0, 255);
    cv::Mat saltpepper_img = this->m_image.clone();
    saltpepper_img.setTo(255, saltpepper_noise > this->m_hi);
    saltpepper_img.setTo(0, saltpepper_noise < this->m_low);
    return std::tuple<std::vector<std::string>, cv::Mat>(this->p_args, saltpepper_img);
}
