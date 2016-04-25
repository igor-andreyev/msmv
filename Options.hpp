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


std::tuple<const std::vector<OptionsHandler>, std::string, std::string, int, std::string> parse_options(int argc, char *argv[]);


#endif //MSMV_FRAMEWORK_OPTIONSPARSER_H
