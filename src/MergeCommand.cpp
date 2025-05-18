#include "MergeCommand.h"
#include <iostream>

MergeCommand::MergeCommand(std::vector<std::string> files)
    : files_(std::move(files)) {}

void MergeCommand::execute() {
    if (files_.empty()) {
        std::cerr << "No input files specified for merging.\n";
        return;
    }
    try {
        // For output filename, you could customize or fix it
        std::string outputFile = "merged_output.pdf";
        merger_.Merge(outputFile, files_);
        std::cout << "Merge completed, output file: " << outputFile << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error during merging: " << e.what() << std::endl;
    }
}
