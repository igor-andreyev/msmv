//
// Created by iandreyev on 25.04.16.
//

#ifndef MSMV_FRAMEWORK_RESIZE_H
#define MSMV_FRAMEWORK_RESIZE_H

#include "AbstractTransformation.hpp"

class Resize: public AbstractTransformation {
public:
    const static unsigned hash = str_hash("Resize");

    Resize(std::vector<std::string> args) : AbstractTransformation(args) {
            if(args.size() < 1)
                throw po::required_option("Size x in Resize");
            if(args.size() < 2)
                throw po::required_option("Size y in Resize");
            m_x = boost::lexical_cast<int>(args[0]);
            m_y = boost::lexical_cast<int>(args[1]);
    }

protected:
    virtual cv::Mat apply();

private:
    int m_x, m_y;

};


#endif //MSMV_FRAMEWORK_RESIZE_H
