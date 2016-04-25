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
    virtual std::tuple<std::vector<std::string>, cv::Mat> apply();

public:
    SaltPepperNoise(std::vector<std::string> args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Black level in SaltPepper noise");
        if(args.size() < 2)
            throw po::required_option("White level in SaltPepper noise");
        m_low = boost::lexical_cast<int>(args[0]);
        m_hi = boost::lexical_cast<int>(args[1]);
    }
private:
    int m_hi, m_low;

};


#endif //MSMV_FRAMEWORK_SALTPEPPERNOISE_H
