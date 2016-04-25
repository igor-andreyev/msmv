//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_FISHEYE_H
#define MSMV_FRAMEWORK_FISHEYE_H

#include "AbstractTransformation.hpp"

class FishEye : public AbstractTransformation {
public:
    constexpr static char* name = "FishEye";

    FishEye(std::vector<std::string> args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Cx in FishEye");
        if(args.size() < 2)
            throw po::required_option("Cy in FishEye");
        if(args.size() < 3)
            throw po::required_option("K in FishEye");
        m_cx = boost::lexical_cast<float>(args[0]);
        m_cy = boost::lexical_cast<float>(args[1]);
        m_k = boost::lexical_cast<float>(args[1]);
    }

protected:
    virtual std::tuple<std::vector<std::string>, cv::Mat> apply();

private:
    double m_cx, m_cy, m_k;

};



#endif //MSMV_FRAMEWORK_FISHEYE_H
