//
// Created by iandreyev on 11.04.16.
//

#ifndef MSMV2_IMAGEHANDLER_H
#define MSMV2_IMAGEHANDLER_H


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


// small DAL for images

class ImageHandler {

public:
    ImageHandler(const cv::Mat &mat) : mat(mat) { }
    ImageHandler(const std::string & _path, const std::string & _out_path)
            : mat(cv::imread(_path)), in_path(_path), out_path(_out_path) {}

    const cv::Mat &getMat() const {
        return mat;
    }

    void setMat(const cv::Mat &mat) {
        this->mat = mat;
    }

    void write() {
        cv::imwrite(out_path, mat);
    }

private:
    cv::Mat mat;
    std::string in_path, out_path;
};


#endif //MSMV2_IMAGEHANDLER_H
