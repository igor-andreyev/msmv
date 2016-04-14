//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_GAUSSIANNOISE_H
#define MSMV_FRAMEWORK_GAUSSIANNOISE_H

#include "AbstractTransformation.h"


class GaussianNoise: public AbstractTransformation {
public:
    const static unsigned hash = str_hash("GaussianNoise");

    GaussianNoise(std::vector<std::string> args) : AbstractTransformation(args) {
        if(args.size() < 1)
            throw po::required_option("Mean in Gaussian noise");
        if(args.size() < 2)
            throw po::required_option("Stddev in Gaussian noise");
        m_mean = boost::lexical_cast<int>(args[0]);
        m_stddev = boost::lexical_cast<int>(args[1]);
    }

protected:
    virtual cv::Mat apply();

private:
    int m_mean, m_stddev;

};


#endif //MSMV_FRAMEWORK_GAUSSIANNOISE_H
