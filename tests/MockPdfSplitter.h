#pragma once
#include "IPdfSplitter.h"
#include <gmock/gmock.h>

class MockPdfSplitter : public IPdfSplitter {
public:
    MOCK_METHOD(void, Split, (const std::string& inputFile, const std::string& outputPattern), (override));
};