//
// Created by iandreyev on 18.04.16.
//

#ifndef MSMV_FRAMEWORK_IMAGEDB_H
#define MSMV_FRAMEWORK_IMAGEDB_H

#include <boost/filesystem.hpp>
#include <fstream>

namespace fs=boost::filesystem;

class ImageDB {
public:
    static std::vector<std::string> openDatabase(std::string & path, std::string & extension);
    static bool prepareOutput(std::string & path);

};


#endif //MSMV_FRAMEWORK_IMAGEDB_H
