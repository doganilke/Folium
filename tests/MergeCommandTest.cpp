#include "MergeCommand.h"
#include "MockPdfMerger.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::ElementsAre;

TEST(MergeCommandTest, ExecuteCallsMergerCorrectly) {
    MockPdfMerger merger;
    std::vector<std::string> files = {"file1.pdf", "file2.pdf"};
    
    EXPECT_CALL(merger, Merge("output.pdf", ElementsAre("file1.pdf", "file2.pdf")))
        .Times(1);
    
    MergeCommand cmd(files, merger);
    cmd.execute();
}