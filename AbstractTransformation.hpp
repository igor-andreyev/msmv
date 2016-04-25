//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_IMAGETRANSFORMATION_H
#define MSMV_FRAMEWORK_IMAGETRANSFORMATION_H

#include "ImageHandler.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>

namespace po=boost::program_options;


constexpr unsigned int str_hash(const char * str, int h = 0) {
    return !str[h] ? 5381 : (str_hash(str, h+1)*33) ^ str[h];
}

class AbstractTransformation {
public:
    constexpr static char* name = "Abstract";

    AbstractTransformation(std::vector<std::string> & args, const char* _name): p_name(_name), p_args(args) {}

    std::tuple<std::vector<std::string>, cv::Mat> transform(cv::Mat & _image) {
        this->m_image = _image;
        return this->apply();
    };

    const std::string &getP_name() const {
        return p_name;
    }

private:
    std::string p_name;

public:
    std::vector<std::string>  p_args;

protected:
    virtual std::tuple<std::vector<std::string>, cv::Mat> apply() = 0;
    cv::Mat m_image;
};


#endif //MSMV_FRAMEWORK_IMAGETRANSFORMATION_H
