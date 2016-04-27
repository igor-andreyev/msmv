//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_GAUSSIANBLUR_H
#define MSMV_FRAMEWORK_GAUSSIANBLUR_H


#include "AbstractTransformation.hpp"


class GaussianBlur: public AbstractTransformation {

public:
    constexpr static char* name = "GaussianBlur";

    GaussianBlur(arguments args) : AbstractTransformation(args, this->name) {
        if (args.size() < 1)
            throw po::required_option("Min WindowX in Gaussian noise");
        if (args.size() < 2)
            throw po::required_option("Max WindowX in Gaussian noise");

        if (args.size() < 3)
            throw po::required_option("Min WindowY in Gaussian noise");
        if (args.size() < 4)
            throw po::required_option("Max WindowY in Gaussian noise");

        if (args.size() < 5)
            throw po::required_option("Min Stddev in Gaussian noise");
        if (args.size() < 6)
            throw po::required_option("Max Stddev in Gaussian noise");


        m_window_x_min = boost::lexical_cast<int>(args[0]);
        m_window_x_max = boost::lexical_cast<int>(args[1]);
        m_window_y_min = boost::lexical_cast<int>(args[2]);
        m_window_y_max = boost::lexical_cast<int>(args[3]);

        m_stddev_min = boost::lexical_cast<double>(args[4]);
        m_stddev_max = boost::lexical_cast<double>(args[5]);
    }

protected:
    virtual std::tuple<arguments, cv::Mat> apply();

private:
    double m_stddev_min, m_stddev_max;
    int m_window_x_max, m_window_x_min, m_window_y_max, m_window_y_min;

};


#endif //MSMV_FRAMEWORK_GAUSSIANBLUR_H
