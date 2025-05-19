#include "SplitCommand.h"
#include "MockPdfSplitter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;

TEST(SplitCommandTest, ExecuteCallsSplitterCorrectly) {
    MockPdfSplitter splitter;
    std::string input = "input.pdf";
    std::string output = "output_%d.pdf";
    
    EXPECT_CALL(splitter, Split(input, output))
        .Times(1);
    
    SplitCommand cmd(input, output, splitter);
    cmd.execute();
}