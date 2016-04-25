//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_COMPRESSION_H
#define MSMV_FRAMEWORK_COMPRESSION_H


class Compression: public AbstractTransformation {
    public:
        const static unsigned hash = str_hash("Compression");

        Compression(std::vector<std::string> args) : AbstractTransformation(args) {
            if(args.size() < 1)
                throw po::required_option("Compression type in Compression");
            if(args.size() < 2)
                throw po::required_option("Compression quality in Compression");
            m_type = boost::lexical_cast<int>(args[0]);
            m_quality = boost::lexical_cast<int>(args[1]);

        }

    protected:
        virtual cv::Mat apply();

    private:
        std::string m_type;
        int m_quality;
};


#endif //MSMV_FRAMEWORK_COMPRESSION_H
