//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_FISHEYE_H
#define MSMV_FRAMEWORK_FISHEYE_H

#include "AbstractTransformation.hpp"

class LensDistort : public AbstractTransformation {
public:
    constexpr static char* name = "LensDistort";

    LensDistort(std::vector<std::string> args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("k1 in LensDistort");
        if(args.size() < 2)
            throw po::required_option("k2 in LensDistort");
        if(args.size() < 3)
            throw po::required_option("p1 in LensDistort");
        if(args.size() < 4)
            throw po::required_option("p2 in LensDistort");
        m_k1 = boost::lexical_cast<float>(args[0]);
        m_k2 = boost::lexical_cast<float>(args[1]);
        m_p1 = boost::lexical_cast<float>(args[2]);
        m_p2 = boost::lexical_cast<float>(args[3]);
    }

protected:
    virtual std::tuple<std::vector<std::string>, cv::Mat> apply();

private:
    double m_k1, m_k2, m_p1, m_p2;

};



#endif //MSMV_FRAMEWORK_FISHEYE_H
