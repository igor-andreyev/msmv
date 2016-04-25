//
// Created by iandreyev on 25.04.16.
//

#include "Compression.h"

cv::Mat Compression::apply() {
    cv::Mat img = this->m_image.clone();
    std::vector<int> parameters;

    if(this->m_type == "JPEG") {
        parameters.push_back(CV_IMWRITE_JPEG_QUALITY);
        if(this->m_quality < 0 && m_quality > 100)
            throw po::required_option("Bad quality value for Compression");
    } else if(this->m_type == "PNG") {
        parameters.push_back(CV_IMWRITE_PNG_COMPRESSION);
        if(this->m_quality < 0 && m_quality > 10)
            throw po::required_option("Bad quality value for Compression");
    } else {
        throw po::required_option("Bad compression type: " + this->m_type + " in Compression");
    }
    parameters.push_back(this->m_quality);

    std::vector<uchar> buffer;
    cv::imencode(m_type, this->m_image, buffer, parameters);
    cv::imdecode(buffer, CV_LOAD_IMAGE_ANYDEPTH, &img);


    return img;
}