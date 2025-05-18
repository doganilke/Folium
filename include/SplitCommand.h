#pragma once
#include "ICommand.h"
#include "PdfSplitter.h"
#include <string>

class SplitCommand : public ICommand {
public:
    SplitCommand(std::string inputFile, std::string outputPattern);
    void execute() override;

private:
    std::string inputFile_;
    std::string outputPattern_;
    PdfSplitter splitter_;
};
