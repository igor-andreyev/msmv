//
// Created by iandreyev on 25.04.16.
//

#include "Resize.h"


std::tuple<std::vector<std::string>, cv::Mat> Resize::apply() {
    cv::Mat img(cv::Size(this->m_x, this->m_y), this->m_image.depth(), this->m_image.channels());
    cv::resize(this->m_image, img, img.size());
    return std::tuple<std::vector<std::string>, cv::Mat>(this->p_args,img);
}