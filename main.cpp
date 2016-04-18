#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <boost/program_options.hpp>
#include <boost/optional.hpp>

#include "ImageHandler.h"
#include "TransformationsHolder.h"
#include "RandomItem.h"
#include "ImageDB.h"

int main(int argc, char *argv[]) {
    std::vector<OptionsHandler> handlers;
    std::string input, output;
    int count;
    std::tie(handlers, input, output, count) = parse_options(argc, argv);

    TransformationsHolder transformationsHolder(handlers);

    std::string ext(".pgm");
    auto paths = ImageDB::openDatabase(input, ext);
    std::vector<std::string> result_table;
    if (ImageDB::prepareOutput(output)) {
        for(int i = 0; i < count; i++) {
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