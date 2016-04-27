//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_SALTPEPPERNOISE_H
#define MSMV_FRAMEWORK_SALTPEPPERNOISE_H

#include "AbstractTransformation.hpp"

class SaltPepperNoise : public  AbstractTransformation {
public:
    constexpr static char* name = "SaltPepperNoise";

protected:
    virtual std::tuple<arguments, cv::Mat> apply();

public:
    SaltPepperNoise(arguments args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Min Black level in SaltPepper noise");
        if(args.size() < 2)
            throw po::required_option("Min Black level in SaltPepper noise");
        if(args.size() < 3)
            throw po::required_option("Max White level in SaltPepper noise");
        if(args.size() < 4)
            throw po::required_option("Max White level in SaltPepper noise");
        m_low_min = boost::lexical_cast<int>(args[0]);
        m_low_max = boost::lexical_cast<int>(args[1]);
        m_hi_min = boost::lexical_cast<int>(args[2]);
        m_hi_max = boost::lexical_cast<int>(args[3]);
    }
private:
    int m_hi_min, m_low_min, m_hi_max, m_low_max;

};


#endif //MSMV_FRAMEWORK_SALTPEPPERNOISE_H
