#include "SplitCommand.h"

SplitCommand::SplitCommand(std::string inputFile, std::string outputPattern, IPdfSplitter& splitter)
    : inputFile_(std::move(inputFile)), outputPattern_(std::move(outputPattern)), splitter_(splitter) {}

void SplitCommand::execute() {
    splitter_.Split(inputFile_, outputPattern_);
}
