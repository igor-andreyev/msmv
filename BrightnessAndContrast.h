//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_CONTRAST_H
#define MSMV_FRAMEWORK_CONTRAST_H

#include "AbstractTransformation.hpp"

class BrightnessAndContrast : public AbstractTransformation {
private:
    float m_alpha_min, m_alpha_max, m_bias_min, m_bias_max=0.0;
protected:
    virtual std::tuple<arguments, cv::Mat> apply();

public:
    BrightnessAndContrast(arguments args)
            : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Minimum alpha level in BrightnessAndContrast noise");
        if(args.size() < 2)
            throw po::required_option("Maximum alpha level in BrightnessAndContrast noise");
        if(args.size() < 3)
            throw po::required_option("Minimum bias level in BrightnessAndContrast noise");
        if(args.size() < 4)
            throw po::required_option("Maximum bias level in BrightnessAndContrast noise");
        m_alpha_min = boost::lexical_cast<float>(args[0]);
        m_alpha_max = boost::lexical_cast<float>(args[1]);
        m_bias_min = boost::lexical_cast<float>(args[2]);
        m_bias_max =  boost::lexical_cast<float>(args[3]);
    }

    constexpr static char* name = "BrightnessAndContrast";
};


#endif //MSMV_FRAMEWORK_CONTRAST_H
