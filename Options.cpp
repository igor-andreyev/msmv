//
// Created by iandreyev on 25.04.16.
//

#include "Options.hpp"
#include <vector>
#include "boost/program_options.hpp"

std::tuple<const std::vector<OptionsHandler>, std::string, std::string, int> parse_options(int argc, char *argv[]) {
    namespace po=boost::program_options;
    po::options_description description(std::string("Usage: ") + std::string(argv[0]) + " -i input -o output {--transformation [options]}");
    std::vector<OptionsHandler> result;
    std::string input, output;
    int count;
    try {
        description.add_options()
                ("help,h", "Show help")
                ("input,i", po::value<std::string>(&input)->required(), "Input database directory")
                ("output,o", po::value<std::string>(&output)->required(), "Output directory")
                ("count,c", po::value<int>(&count)->required(), "Image count")
                ("transformation,t", po::value<std::vector<std::string>>()->multitoken()->required(), "Transformations list")
                ;

        po::command_line_parser parser{argc, argv};
        po::parsed_options parsed_options = parser.options(description).run();

        std::vector<std::vector<std::string>> lists;
        for (auto o: parsed_options.options) {
            if (o.string_key == "transformation") {
                lists.push_back(o.value);
            }
        }

        po::variables_map vm;
        po::store(parsed_options, vm);
        po::notify(vm);

        for (size_t i = 0; i < lists.size(); ++i) {
            std::string name;
            std::vector<std::string> args;
            name.swap(lists[i][0]);
            lists[i].erase(lists[i].begin());
            args.swap(lists[i]);
            result.push_back(OptionsHandler {name, args});
        }
        if (vm.count("help"))
            std::cout << description << std::endl;

    } catch (const po::error &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << description << std::endl;
        result.clear();
    }
    return std::make_tuple(result, input, output, count);
}
