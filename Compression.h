//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_COMPRESSION_H
#define MSMV_FRAMEWORK_COMPRESSION_H


#include "AbstractTransformation.hpp"

class Compression: public AbstractTransformation {
    public:
        constexpr static char* name = "Compression";

    Compression(std::vector<std::string> args) : AbstractTransformation(args, this->name) {
            if(args.size() < 1)
                throw po::required_option("Compression type in Compression");
            if(args.size() < 2)
                throw po::required_option("Compression quality in Compression");
            m_type = args[0];
            m_quality = boost::lexical_cast<int>(args[1]);

        }

    protected:
        virtual std::tuple<std::vector<std::string>, cv::Mat> apply();

    private:
        std::string m_type;
        int m_quality;
};


#endif //MSMV_FRAMEWORK_COMPRESSION_H
