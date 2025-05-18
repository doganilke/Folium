#include "CommandLineParser.h"
#include "CommandFactory.h"
#include <iostream>

int main(int argc, char* argv[]) {
    CommandLineParser parser(argc, argv);

    if (!parser.isValid()) {
        parser.printUsage();
        return 1;
    }

    auto cmd = CommandFactory::createCommand(parser.getCommand(), parser.getArguments());
    if (!cmd) {
        parser.printUsage();
        return 1;
    }

    cmd->execute();

    return 0;
}
