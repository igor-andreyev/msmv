//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_GAUSSIANNOISE_H
#define MSMV_FRAMEWORK_GAUSSIANNOISE_H

#include "AbstractTransformation.hpp"


class GaussianNoise: public AbstractTransformation {
public:
    constexpr static char* name = "GaussianNoise";

    GaussianNoise(std::vector<std::string> args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Mean in Gaussian noise");
        if(args.size() < 2)
            throw po::required_option("Stddev in Gaussian noise");
        m_mean = boost::lexical_cast<int>(args[0]);
        m_stddev = boost::lexical_cast<int>(args[1]);
    }

protected:
    virtual std::tuple<std::vector<std::string>, cv::Mat> apply();

private:
    int m_mean, m_stddev;

};


#endif //MSMV_FRAMEWORK_GAUSSIANNOISE_H
