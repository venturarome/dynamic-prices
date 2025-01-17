#ifndef ARGSPARSER_H
#define ARGSPARSER_H

class ArgsParser {
    public:
    static std::unordered_map<std::string, std::string> parse(int argc, char* argv[]) {

        std::unordered_map<std::string, std::string> args;

        if (argc == 1) {
            return args;
        }

        for (int i = 1; i < argc; i++) {
            std::string_view arg = argv[i];
            if (!arg.starts_with('-')) {
                std::cout << "Invalid argument: '" << arg << "'." << std::endl
                    << "Every argument must be preceded with an argument identifier." << std::endl
                    << "Type -h for help." << std::endl;
                exit(1);
            }

            if (arg == "-h") {
                std::cout << "Usage: ./dynamic-prices [options]" << std::endl
                        << "Options:" << std::endl
                        << "    -h: show this help" << std::endl
                        << "    -ui <value>: selects ui to use. Values:" << std::endl
                        << "         cmd (default): command line interface" << std::endl
                        << "         gui: graphical user interface" << std::endl;
                    exit(0);
            }

            if (arg == "-ui") {
                if (argc <= i + 1) {
                    std::cout << "Missing argument for option '" << arg << "'." << std::endl;
                    exit(1);
                }
                args["ui"] = argv[++i];
            }
            // else if (arg == "-xx") { ... }
            else {
                std::cout << "Unknown option '" << arg << "'." << std::endl;
                exit(1);
            }
        }

        return args;
    }
};


#endif