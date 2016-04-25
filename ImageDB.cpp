//
// Created by iandreyev on 18.04.16.
//

#include <iostream>
#include "ImageDB.h"

std::vector<std::string> ImageDB::openDatabase(std::string & path, std::string & extension){
    std::vector<std::string> result;


    if (fs::exists(path)) {
        if (fs::is_directory(path)) {
            for (fs::recursive_directory_iterator it(path), it_end; it != it_end; ++it) {
                if (fs::is_regular(*it) && it->path().extension() == extension) {
                    result.push_back(it->path().string());
                }
            }
        } else {
            std::cerr << "Input database is not directory: " << path << std::endl;
        }
    } else {
        std::cerr << "No input database available: " << path << std::endl;
    }
    return result;
}

bool ImageDB::prepareOutput(std::string & path) {
    fs::path p(path);
    if(!fs::exists(path)) {
        if (fs::exists(p.parent_path())) {
            if(fs::is_directory(p.parent_path())) {
                if(fs::create_directory(p)) {
                    return true;
                } else {
                    std::cerr << "Cannot create output directory: " << p << std::endl;
                }
            } else {
                std::cerr << "Target path is not directory: " << p.parent_path() << std::endl;
            }
        } else {
            std::cerr << "Parent directory is not exists " << p.parent_path() << std::endl;
        }
    } else {
        std::cerr << "Target path already exists: " << path << std::endl;
    }
    return false;
}
