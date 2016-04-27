#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include "ImageHandler.h"
#include "TransformationsHolder.h"
#include "ImageDB.h"
#include "RandomItem.h"



int main(int argc, char *argv[]) {

    Options opt = parse_options(argc, argv);

    TransformationsHolder transformationsHolder(opt.handlers);

    auto paths = ImageDB::openDatabase(opt.input, opt.extension);
    std::vector<std::string> result_table;
    if (ImageDB::prepareOutput(opt.output) && paths.size() > 0) {
        for(int i = 0; i < opt.count; i++) {
            std::string path = *select_randomly(paths.begin(), paths.end());
            std::string out_path(opt.output);
            std::string desc;
            cv::Mat result;
            out_path.append("/").append(boost::lexical_cast<std::string>(i)).append(opt.extension);
            ImageHandler h(path, out_path);
            std::tie(desc, result) = transformationsHolder.transform(h.getMat());
            h.setMat(result);
            h.write();
            std::cout << path << " - " << out_path << std::endl;
            result_table.push_back(std::string().append(out_path).append(" - ").append(path).append(": ").append(desc));

        }

        std::string result_table_file(opt.output);
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