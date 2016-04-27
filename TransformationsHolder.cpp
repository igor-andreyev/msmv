//
// Created by iandreyev on 25.04.16.
//

#include "TransformationsHolder.h"
#include "Compression.h"
#include "Resize.h"
#include "LensDistort.h"
#include "BrightnessAndContrast.h"

TransformationsHolder::TransformationsHolder(std::vector<OptionsHandler> & _handlers) {
    for(auto h: _handlers) {
        this->transformations.push_back(makeTransformation(h));
    }
}

std::tuple<std::string, cv::Mat> TransformationsHolder::transform(ImageHandler _image) {
    return chain(transformations, _image.getMat());
}

TransformationsHolder::~TransformationsHolder() {
    for(auto t: transformations)
        delete t;
}

std::tuple<std::string, cv::Mat> TransformationsHolder::chain(std::vector<AbstractTransformation *> &  _ops, const cv::Mat & _mat) {
    cv::Mat result;
    cv::Mat tmp = _mat;
    std::string desc = "";
    for(size_t i = 0; i < _ops.size(); i++) {
        std::vector<std::string> args;
        std::tie(args, result) = _ops[i]->transform(tmp);
        desc.append(_ops[i]->getP_name()).append("(");
        for( std::string t: args)
            desc.append(t).append(" ");
        desc.append(")-> ");
        tmp = result;
    }
    return std::tuple<std::string, cv::Mat>(desc,result);
}

AbstractTransformation* TransformationsHolder::makeTransformation(const OptionsHandler &h) {
    switch (str_hash(h.type.c_str())) {
        case str_hash(GaussianNoise::name):
            return new GaussianNoise(h.args);
        case str_hash(SaltPepperNoise::name):
            return new SaltPepperNoise(h.args);
        case str_hash(GaussianBlur::name):
            return new GaussianBlur(h.args);
        case str_hash(Compression::name):
            return new Compression(h.args);
        case str_hash(Resize::name):
            return new Resize(h.args);
        case str_hash(LensDistort::name):
            return new LensDistort(h.args);
        case str_hash(BrightnessAndContrast::name):
            return new BrightnessAndContrast(h.args);

        default:
            std::string error(std::string("Unknown transformation type: ").append(h.type));
            throw po::invalid_option_value(error);
    }
}

