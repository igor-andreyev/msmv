//
// Created by iandreyev on 11.04.16.
//

#include "BrightnessAndContrast.h"

std::tuple< arguments, cv::Mat> BrightnessAndContrast::apply() {
    cv::Mat result = cv::Mat::zeros(this->m_image.size(), this->m_image.type());

    double m_alpha = randomize(this->m_alpha_min, this->m_alpha_max);
    double m_bias = randomize(this->m_bias_min, this->m_bias_max);

    for( int y = 0; y < this->m_image.rows; y++ ) {
        for( int x = 0; x < this->m_image.cols; x++ ) {
            for( int c = 0; c < this->m_image.channels(); c++ ) {
                result.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>(m_alpha*(this->m_image.at<cv::Vec3b>(y,x)[c] ) + m_bias );
            }
        }
    }

    return std::tuple< arguments, cv::Mat>(arguments {std::to_string(m_alpha), std::to_string(m_bias)}, result);
}

