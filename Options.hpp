//
// Created by iandreyev on 14.04.16.
//

#ifndef MSMV_FRAMEWORK_OPTIONSPARSER_H
#define MSMV_FRAMEWORK_OPTIONSPARSER_H

#include<iostream>
#include<vector>

struct OptionsHandler {
    std::string type;
    std::vector<std::string> args;
};

struct Options {
    std::vector<OptionsHandler> handlers;
    std::string input;
    std::string output;
    int count;
    std::string extension;
};


Options parse_options(int argc, char **argv);


#endif //MSMV_FRAMEWORK_OPTIONSPARSER_H
