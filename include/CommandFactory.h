#pragma once
#include <memory>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IPdfMerger.h"
#include "IPdfSplitter.h"

class CommandFactory {
public:
    CommandFactory(IPdfMerger& merger, IPdfSplitter& splitter);

    std::unique_ptr<ICommand> createCommand(const std::string& cmd, const std::vector<std::string>& args);

private:
    IPdfMerger& merger_;
    IPdfSplitter& splitter_;
};
