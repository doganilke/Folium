#include "CommandLineParser.h"
#include <iostream>

CommandLineParser::CommandLineParser(int argc, char* argv[]) : valid_(false) {
    if (argc < 2) {
        return;
    }
    command_ = argv[1];
    for (int i = 2; i < argc; ++i) {
        arguments_.push_back(argv[i]);
    }
    valid_ = true;
}

bool CommandLineParser::isValid() const {
    return valid_;
}

std::string CommandLineParser::getCommand() const {
    return command_;
}

std::vector<std::string> CommandLineParser::getArguments() const {
    return arguments_;
}

void CommandLineParser::printUsage() const {
    std::cout << "Usage:\n"
              << "  folium merge file1.pdf file2.pdf ...\n"
              << "  folium split input.pdf output_pattern\n"
              << "Example:\n"
              << "  folium merge hello.pdf world.pdf\n"
              << "  folium split merged.pdf split_page_%d.pdf\n";
}
