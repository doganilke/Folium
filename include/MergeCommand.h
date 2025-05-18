#pragma once
#include "ICommand.h"
#include "PdfMerger.h"
#include <vector>
#include <string>

class MergeCommand : public ICommand {
public:
    explicit MergeCommand(std::vector<std::string> files);
    void execute() override;

private:
    std::vector<std::string> files_;
    PdfMerger merger_;
};
