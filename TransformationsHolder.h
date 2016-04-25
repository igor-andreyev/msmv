//
// Created by iandreyev on 14.04.16.
//

#ifndef MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H
#define MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H

#include "AbstractTransformation.hpp"
#include "Options.hpp"
#include "GaussianNoise.h"
#include "GaussianBlur.h"
#include "SaltPepperNoise.h"

class TransformationsHolder {
public:
    TransformationsHolder(std::vector<OptionsHandler> & _handlers);
    cv::Mat transform(ImageHandler _image);
    virtual ~TransformationsHolder();

private:
    cv::Mat chain(std::vector<AbstractTransformation *> &  _ops, const cv::Mat & _mat);
    AbstractTransformation* makeTransformation(const OptionsHandler &h);

    std::vector<AbstractTransformation*> transformations;
};



#endif //MSMV_FRAMEWORK_TRANSFORMATIONSHOLDER_H
