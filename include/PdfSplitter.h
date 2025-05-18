#pragma once

#include "IPdfSplitter.h"
#include <string>
#include <vector>

class PdfSplitter : public IPdfSplitter {
public:
    void Split(const std::string& inputFile, const std::string& outputPattern) override;
};
