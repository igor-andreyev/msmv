//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_GAUSSIANBLUR_H
#define MSMV_FRAMEWORK_GAUSSIANBLUR_H


#include "AbstractTransformation.h"


class GaussianBlur: public AbstractTransformation {

public:
    const static unsigned hash = str_hash("GaussianBlur");
    GaussianBlur(std::vector<std::string> args) : AbstractTransformation(args) {
        if (args.size() < 1)
            throw po::required_option("WindowX in Gaussian noise");
        if (args.size() < 2)
            throw po::required_option("WindowY in Gaussian noise");
        if (args.size() < 3)
            throw po::required_option("Stddev in Gaussian noise");
        m_window = cv::Size(boost::lexical_cast<int>(args[0]), boost::lexical_cast<int>(args[1]));
        m_stddev = boost::lexical_cast<double>(args[2]);
    }

protected:
    virtual cv::Mat apply();

private:
    double m_stddev;
    cv::Size m_window;

};


#endif //MSMV_FRAMEWORK_GAUSSIANBLUR_H
