//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_FISHEYE_H
#define MSMV_FRAMEWORK_FISHEYE_H

#include "AbstractTransformation.hpp"

class LensDistort : public AbstractTransformation {
public:
    constexpr static char* name = "LensDistort";

    LensDistort(arguments args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Min k1 in LensDistort");
        if(args.size() < 2)
            throw po::required_option("Max k1 in LensDistort");

        if(args.size() < 3)
            throw po::required_option("Min k2 in LensDistort");
        if(args.size() < 4)
            throw po::required_option("Max k2 in LensDistort");

        if(args.size() < 5)
            throw po::required_option("Min p1 in LensDistort");
        if(args.size() < 6)
            throw po::required_option("Max p1 in LensDistort");

        if(args.size() < 7)
            throw po::required_option("Min p2 in LensDistort");
        if(args.size() < 8)
            throw po::required_option("Max p2 in LensDistort");

        m_k1_min = boost::lexical_cast<float>(args[0]);
        m_k1_max = boost::lexical_cast<float>(args[1]);
        m_k2_min = boost::lexical_cast<float>(args[2]);
        m_k2_max = boost::lexical_cast<float>(args[3]);
        m_p1_min = boost::lexical_cast<float>(args[4]);
        m_p1_max = boost::lexical_cast<float>(args[5]);
        m_p2_min = boost::lexical_cast<float>(args[6]);
        m_p2_max = boost::lexical_cast<float>(args[7]);
    }

protected:
    virtual std::tuple<arguments, cv::Mat> apply();

private:
    double m_k1_min, m_k1_max,
            m_k2_min, m_k2_max,
            m_p1_min,m_p1_max,
            m_p2_min, m_p2_max;

};



#endif //MSMV_FRAMEWORK_FISHEYE_H

