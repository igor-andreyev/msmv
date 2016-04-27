//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_COMPRESSION_H
#define MSMV_FRAMEWORK_COMPRESSION_H


#include "AbstractTransformation.hpp"

class Compression: public AbstractTransformation {
    public:
        constexpr static char* name = "Compression";

    Compression(arguments args) : AbstractTransformation(args, this->name) {
            if(args.size() < 1)
                throw po::required_option("Compression type in Compression");
            if(args.size() < 2)
                throw po::required_option("Min Compression quality in Compression");
            if(args.size() < 3)
                throw po::required_option("Max Compression quality in Compression");
            m_type = args[0];
            m_quality_min = boost::lexical_cast<int>(args[1]);
            m_quality_max = boost::lexical_cast<int>(args[2]);
        }

    protected:
        virtual std::tuple<arguments, cv::Mat> apply();

    private:
        std::string m_type;
        int m_quality_min, m_quality_max;
};


#endif //MSMV_FRAMEWORK_COMPRESSION_H
