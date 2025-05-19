#pragma once
#include "ICommand.h"
#include "IPdfSplitter.h"
#include <string>

class SplitCommand : public ICommand {
public:
    SplitCommand(std::string inputFile, std::string outputPattern, IPdfSplitter& splitter);

    void execute() override;

private:
    std::string inputFile_;
    std::string outputPattern_;
    IPdfSplitter& splitter_;
};
