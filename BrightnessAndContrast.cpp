//
// Created by iandreyev on 11.04.16.
//

#include "BrightnessAndContrast.h"

cv::Mat BrightnessAndContrast::apply() {
    cv::Mat result = cv::Mat::zeros(this->m_image.size(), this->m_image.type());
    for( int y = 0; y < this->m_image.rows; y++ ) {
        for( int x = 0; x < this->m_image.cols; x++ ) {
            for( int c = 0; c < this->m_image.channels(); c++ ) {
                result.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>(this->m_alpha*(this->m_image.at<cv::Vec3b>(y,x)[c] ) + this->m_bias );
            }
        }
    }

    return result;
}
