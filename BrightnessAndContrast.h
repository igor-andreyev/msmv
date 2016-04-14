//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV_FRAMEWORK_CONTRAST_H
#define MSMV_FRAMEWORK_CONTRAST_H

#include "AbstractTransformation.h"

class BrightnessAndContrast : public AbstractTransformation {
private:
    float m_alpha, m_bias=0.0;
protected:
    virtual cv::Mat apply();

public:
    BrightnessAndContrast(double _alpha, double _bias=0.0)
            : m_alpha(_alpha), m_bias(_bias) { }

};


#endif //MSMV_FRAMEWORK_CONTRAST_H
