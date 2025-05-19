#pragma once

#include <string>
#include <vector>

class IPdfMerger {
public:
    virtual ~IPdfMerger() = default;
    virtual void Merge(const std::string& outputFile, const std::vector<std::string>& inputFiles) = 0;
};