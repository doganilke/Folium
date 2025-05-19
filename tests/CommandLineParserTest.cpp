#include "CommandLineParser.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(CommandLineParserTest, ValidMergeCommand) {
    const char* argv[] = {"program", "merge", "file1.pdf", "file2.pdf"};
    CommandLineParser parser(4, const_cast<char**>(argv));
    
    EXPECT_TRUE(parser.isValid());
    EXPECT_EQ(parser.getCommand(), "merge");
    EXPECT_THAT(parser.getArguments(), testing::ElementsAre("file1.pdf", "file2.pdf"));
}

TEST(CommandLineParserTest, ValidSplitCommand) {
    const char* argv[] = {"program", "split", "input.pdf", "output_%d.pdf"};
    CommandLineParser parser(4, const_cast<char**>(argv));
    
    EXPECT_TRUE(parser.isValid());
    EXPECT_EQ(parser.getCommand(), "split");
    EXPECT_THAT(parser.getArguments(), testing::ElementsAre("input.pdf", "output_%d.pdf"));
}

TEST(CommandLineParserTest, InvalidNoCommand) {
    const char* argv[] = {"program"};
    CommandLineParser parser(1, const_cast<char**>(argv));
    
    EXPECT_FALSE(parser.isValid());
}

TEST(CommandLineParserTest, InvalidNoArgumentsForMerge) {
    const char* argv[] = {"program", "merge"};
    CommandLineParser parser(2, const_cast<char**>(argv));
    
    EXPECT_TRUE(parser.isValid()); // Parser itself is valid, command validation happens later
    EXPECT_EQ(parser.getCommand(), "merge");
    EXPECT_TRUE(parser.getArguments().empty());
}

TEST(CommandLineParserTest, InvalidNoArgumentsForSplit) {
    const char* argv[] = {"program", "split"};
    CommandLineParser parser(2, const_cast<char**>(argv));
    
    EXPECT_TRUE(parser.isValid()); // Parser itself is valid, command validation happens later
    EXPECT_EQ(parser.getCommand(), "split");
    EXPECT_TRUE(parser.getArguments().empty());
}