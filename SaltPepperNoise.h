//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_SALTPEPPERNOISE_H
#define MSMV_FRAMEWORK_SALTPEPPERNOISE_H

#include "AbstractTransformation.h"

class SaltPepperNoise : public  AbstractTransformation {
public:
    const static unsigned hash = str_hash("SaltPepperNoise");
protected:
    virtual cv::Mat apply();

public:
    SaltPepperNoise(std::vector<std::string> args) : AbstractTransformation(args) {
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
