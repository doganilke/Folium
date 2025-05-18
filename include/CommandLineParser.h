#pragma once
#include <string>
#include <vector>

class CommandLineParser {
public:
    CommandLineParser(int argc, char* argv[]);
    bool isValid() const;
    std::string getCommand() const;
    std::vector<std::string> getArguments() const;
    void printUsage() const;

private:
    bool valid_;
    std::string command_;
    std::vector<std::string> arguments_;
};
