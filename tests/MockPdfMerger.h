#pragma once
#include "IPdfMerger.h"
#include <gmock/gmock.h>

class MockPdfMerger : public IPdfMerger {
public:
    MOCK_METHOD(void, Merge, (const std::string& outputFile, const std::vector<std::string>& inputFiles), (override));
};