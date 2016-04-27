//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_RESIZE_H
#define MSMV_FRAMEWORK_RESIZE_H

#include "AbstractTransformation.hpp"

class Resize: public AbstractTransformation {
public:
    constexpr static char* name = "Resize";

    Resize(arguments args) : AbstractTransformation(args, this->name) {
        if(args.size() < 1)
            throw po::required_option("Min Size x in Resize");
        if(args.size() < 2)
            throw po::required_option("Max Size x in Resize");
        if(args.size() < 3)
            throw po::required_option("Min Size y in Resize");
        if(args.size() < 4)
            throw po::required_option("Max Size y in Resize");
        m_x_min = boost::lexical_cast<int>(args[0]);
        m_x_max = boost::lexical_cast<int>(args[1]);
        m_y_min = boost::lexical_cast<int>(args[2]);
        m_y_max = boost::lexical_cast<int>(args[3]);
    }

protected:
    virtual std::tuple<arguments, cv::Mat> apply();

private:
    int m_x_min, m_y_min, m_x_max, m_y_max;

};


#endif //MSMV_FRAMEWORK_RESIZE_H
