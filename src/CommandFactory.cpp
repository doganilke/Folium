#include "CommandFactory.h"
#include "MergeCommand.h"
#include "SplitCommand.h"
#include <iostream>

std::unique_ptr<ICommand> CommandFactory::createCommand(const std::string& cmd, const std::vector<std::string>& args) {
    if (cmd == "merge") {
        if (args.empty()) {
            std::cerr << "Error: No input files provided for merge command.\n";
            return nullptr;
        }
        // args are input files
        return std::make_unique<MergeCommand>(args);
    } else if (cmd == "split") {
        if (args.size() < 2) {
            std::cerr << "Error: split command requires input file and output pattern.\n";
            return nullptr;
        }
        // args[0] = inputFile, args[1] = outputPattern
        return std::make_unique<SplitCommand>(args[0], args[1]);
    } else {
        std::cerr << "Unknown command: " << cmd << "\n";
        return nullptr;
    }
}
