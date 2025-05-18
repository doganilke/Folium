#pragma once
#include "ICommand.h"
#include <memory>
#include <string>
#include <vector>

class CommandFactory {
public:
    static std::unique_ptr<ICommand> createCommand(const std::string& cmd, const std::vector<std::string>& args);
};
