#include "MergeCommand.h"

MergeCommand::MergeCommand(std::vector<std::string> files, IPdfMerger& merger)
    : files_(std::move(files)), merger_(merger) {}

void MergeCommand::execute() {
    const std::string outputFile = "output.pdf"; 
    merger_.Merge(outputFile, files_);
}
