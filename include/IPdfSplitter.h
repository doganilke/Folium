#pragma once

#include <string>
#include <vector>

class IPdfSplitter {
public:
    virtual ~IPdfSplitter() = default;
    virtual void Split(const std::string& inputFile, const std::string& outputPattern) = 0;
};
