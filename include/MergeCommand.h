#pragma once
#include "ICommand.h"
#include "IPdfMerger.h"
#include <vector>
#include <string>

class MergeCommand : public ICommand {
public:
    MergeCommand(std::vector<std::string> files, IPdfMerger& merger);

    void execute() override;

private:
    std::vector<std::string> files_;
    IPdfMerger& merger_;
};
