#include "SplitCommand.h"
#include <iostream>

SplitCommand::SplitCommand(std::string inputFile, std::string outputPattern)
    : inputFile_(std::move(inputFile)), outputPattern_(std::move(outputPattern)) {}

void SplitCommand::execute() {
    if (inputFile_.empty() || outputPattern_.empty()) {
        std::cerr << "Input file or output pattern is missing for splitting.\n";
        return;
    }
    try {
        splitter_.Split(inputFile_, outputPattern_);
        std::cout << "Split completed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error during splitting: " << e.what() << std::endl;
    }
}
