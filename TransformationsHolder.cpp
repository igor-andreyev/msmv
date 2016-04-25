//
// Created by iandreyev on 25.04.16.
//

#include "TransformationsHolder.h"

TransformationsHolder::TransformationsHolder(std::vector<OptionsHandler> & _handlers) {
    for(auto h: _handlers) {
        this->transformations.push_back(makeTransformation(h));
    }
}

cv::Mat TransformationsHolder::transform(ImageHandler _image) {
    return chain(transformations, _image.getMat());
}

TransformationsHolder::~TransformationsHolder() {
    for(auto t: transformations)
        delete t;
}

cv::Mat TransformationsHolder::chain(std::vector<AbstractTransformation *> &  _ops, const cv::Mat & _mat) {
    cv::Mat result;
    cv::Mat tmp = _mat;
    for(size_t i = 0; i < _ops.size(); i++) {
        result = _ops[i]->transform(tmp);
        tmp = result;
    }
    return result;
}

AbstractTransformation* TransformationsHolder::makeTransformation(const OptionsHandler &h) {
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

