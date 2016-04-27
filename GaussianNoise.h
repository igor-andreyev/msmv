//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_GAUSSIANNOISE_H
#define MSMV_FRAMEWORK_GAUSSIANNOISE_H

#include "AbstractTransformation.hpp"


class GaussianNoise: public AbstractTransformation {
public:
    constexpr static char* name = "GaussianNoise";

    GaussianNoise(arguments args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Min Mean in Gaussian noise");
        if(args.size() < 2)
            throw po::required_option("Max Mean in Gaussian noise");

        if(args.size() < 3)
            throw po::required_option("Min Stddev in Gaussian noise");
        if(args.size() < 4)
            throw po::required_option("Max Stddev in Gaussian noise");

        m_mean_min = boost::lexical_cast<int>(args[0]);
        m_mean_max = boost::lexical_cast<int>(args[1]);
        m_stddev_min = boost::lexical_cast<int>(args[2]);
        m_stddev_max = boost::lexical_cast<int>(args[3]);
    }

protected:
    virtual std::tuple<arguments, cv::Mat> apply();

private:
    int m_mean_min, m_mean_max, m_stddev_min, m_stddev_max;

};


#endif //MSMV_FRAMEWORK_GAUSSIANNOISE_H
