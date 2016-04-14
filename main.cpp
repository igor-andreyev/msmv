#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <boost/program_options.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <fstream>

#include "ImageHandler.h"
#include "TransformationsHolder.h"
#include "RandomItem.h"


std::vector<std::string> openDatabase(std::string & path, std::string & extension) {
    namespace fs=boost::filesystem;

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

bool prepareOutput(std::string & path) {
    namespace fs=boost::filesystem;
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

int main(int argc, char *argv[]) {
    std::vector<OptionsHandler> handlers;
    std::string input, output;
    int count;
    std::tie(handlers, input, output, count) = parse_options(argc, argv);

    TransformationsHolder transformationsHolder(handlers);

    std::string ext(".pgm");
    auto paths = openDatabase(input, ext);
    std::vector<std::string> result_table;
    if (prepareOutput(output)) {
        for(int i =0; i < count; i++) {
            std::string path = *select_randomly(paths.begin(), paths.end());
            std::string out_path(output);
            out_path.append("/").append(boost::lexical_cast<std::string>(i)).append(ext);
            ImageHandler h(path, out_path);
            h.setMat(transformationsHolder.tranform(h.getMat()));
            h.write();
            std::cout << path << " - " << out_path << std::endl;
            result_table.push_back(std::string().append(out_path).append(" - ").append(path));

        }

        std::string result_table_file(output);
        result_table_file.append("/result.txt");
        std::ofstream output_file(result_table_file);


        if(!output_file.is_open()) {
            std::cerr << "Couldn't open 'output.txt'" << std::endl;
            return -1;
        }
        for(auto line: result_table) {
            output_file << line << std::endl;
        }
        output_file.close();
    }

    return 0;
}