#include "CommandFactory.h"
#include "MockPdfMerger.h"
#include "MockPdfSplitter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;

class CommandFactoryTest : public ::testing::Test {
protected:
    MockPdfMerger merger;
    MockPdfSplitter splitter;
    CommandFactory factory;
    
    CommandFactoryTest() : factory(merger, splitter) {}
};

TEST_F(CommandFactoryTest, CreateMergeCommand) {
    std::vector<std::string> files = {"file1.pdf", "file2.pdf"};
    auto cmd = factory.createCommand("merge", files);
    
    EXPECT_NE(cmd, nullptr);
}

TEST_F(CommandFactoryTest, CreateMergeCommandFailsWithNoFiles) {
    auto cmd = factory.createCommand("merge", {});
    
    EXPECT_EQ(cmd, nullptr);
}

TEST_F(CommandFactoryTest, CreateSplitCommand) {
    auto cmd = factory.createCommand("split", {"input.pdf", "output_%d.pdf"});
    
    EXPECT_NE(cmd, nullptr);
}

TEST_F(CommandFactoryTest, CreateSplitCommandFailsWithInsufficientArgs) {
    auto cmd1 = factory.createCommand("split", {});
    EXPECT_EQ(cmd1, nullptr);
    
    auto cmd2 = factory.createCommand("split", {"input.pdf"});
    EXPECT_EQ(cmd2, nullptr);
}

TEST_F(CommandFactoryTest, CreateUnknownCommand) {
    auto cmd = factory.createCommand("unknown", {});
    
    EXPECT_EQ(cmd, nullptr);
}