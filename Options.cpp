//
// Created by iandreyev on 25.04.16.
//

#include "Options.hpp"
#include "boost/program_options.hpp"

Options parse_options(int argc, char **argv) {
    namespace po=boost::program_options;
    po::options_description description(std::string("Usage: ") + std::string(argv[0]) + " -i input_directory -o output_directory -c image_count -e extension {--transformation [options]}");
    std::vector<OptionsHandler> result;
    std::string input, output, extension;
    int count;
    try {
        description.add_options()
                ("help", "Show help")
                ("input", po::value<std::string>(&input)->required(), "Input database directory")
                ("output", po::value<std::string>(&output)->required(), "Output directory")
                ("count", po::value<int>(&count)->required(), "Image count")
                ("extension", po::value<std::string>(&extension)->required(), "Image extension")
                ("transformation", po::value<std::vector<std::string>>()->multitoken()->required(), "Transformations list")

                ;

        po::command_line_parser parser{argc, argv};
        po::parsed_options parsed_options = parser.options(description).style(po::command_line_style::unix_style ^ po::command_line_style::allow_short).run();

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
        std::cerr << "Runned as: ";
        for(int i = 0; i < argc; i++)
            std::cerr << argv[i] << " ";
        std::cerr << std::endl;
        std::cerr << e.what() << std::endl;
        std::cerr << description << std::endl;
        exit(1);
    }

    std::string ext="";
    if(extension[0]!='.')
        ext.append(".");
    ext.append(extension);
    return Options{result, input, output, count, ext};
}
