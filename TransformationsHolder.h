//
// Created by iandreyev on 14.04.16.
//

#ifndef MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H
#define MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H

#include "AbstractTransformation.h"
#include "Options.h"
#include "GaussianNoise.h"
#include "GaussianBlur.h"
#include "SaltPepperNoise.h"

class TransformationsHolder {

public:

    TransformationsHolder(std::vector<OptionsHandler> & _handlers) {
        for(auto h: _handlers) {
            this->transformations.push_back(makeTransformation(h));
        }
    }

    cv::Mat tranform(ImageHandler _image) {
        return chain(transformations, _image.getMat());
    }

    virtual ~TransformationsHolder() {
        for(auto t: transformations)
            delete t;
    }

private:
    cv::Mat chain(std::vector<AbstractTransformation *> &  _ops, const cv::Mat & _mat) {
        cv::Mat result;
        cv::Mat tmp = _mat;
        for(size_t i = 0; i < _ops.size(); i++) {
            result = _ops[i]->transform(tmp);
            tmp = result;
        }
        return result;
    }

    AbstractTransformation* makeTransformation(const OptionsHandler &h) {
        switch (str_hash(h.type.c_str())) {
            case GaussianNoise::hash:
                return new GaussianNoise(h.args);
            case SaltPepperNoise::hash:
                return new SaltPepperNoise(h.args);
            case GaussianBlur::hash:
                return new GaussianBlur(h.args);
            default:
                std::string error(std::string("Unknown transformation type: ").append(h.type));
                throw po::invalid_option_value(error);
        }
    }


    std::vector<AbstractTransformation*> transformations;
};



#endif //MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H
