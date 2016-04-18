//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_CONTRAST_H
#define MSMV_FRAMEWORK_CONTRAST_H

#include "AbstractTransformation.h"

class BrightnessAndContrast : public AbstractTransformation {
private:
    float m_alpha, m_bias=0.0;
protected:
    virtual cv::Mat apply();

public:
    BrightnessAndContrast(std::vector<std::string> & args)
            : AbstractTransformation(args) {
        if(args.size() < 1)
            throw po::required_option("Alpha level in BrightnessAndContrast noise");
        if(args.size() < 2)
            throw po::required_option("Bias level in BrightnessAndContrast noise");
        m_alpha = boost::lexical_cast<double>(args[0]);
        m_bias = boost::lexical_cast<double>(args[1]);
    }

};


#endif //MSMV_FRAMEWORK_CONTRAST_H
