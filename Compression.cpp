//
// Created by iandreyev on 25.04.16.
//

#include "Compression.h"


std::tuple<arguments, cv::Mat> Compression::apply() {
    cv::Mat img = this->m_image.clone();
    std::vector<int> parameters;
    std::string ext;

    auto m_quality = randomize(m_quality_min, m_quality_max);

    if(this->m_type == "JPEG") {
        ext = ".jpeg";
        parameters.push_back(CV_IMWRITE_JPEG_QUALITY);
        if(m_quality < 0 && m_quality > 100)
            throw po::required_option("Bad quality value for Compression");
    } else if(this->m_type == "PNG") {
        ext = ".png";
        parameters.push_back(CV_IMWRITE_PNG_COMPRESSION);
        if(m_quality < 0 && m_quality > 10)
            throw po::required_option("Bad quality value for Compression");
    } else {
        throw po::required_option("Bad compression type: " + this->m_type + " in Compression");
    }
    parameters.push_back(m_quality);

    std::vector<uchar> buffer;
    cv::imencode(ext, this->m_image, buffer, parameters);
    cv::imdecode(buffer, CV_LOAD_IMAGE_ANYDEPTH, &img);


    return std::tuple<arguments, cv::Mat>(arguments {m_type, std::to_string(m_quality)}, img);
}

