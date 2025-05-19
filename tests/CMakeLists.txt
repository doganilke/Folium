cmake_minimum_required(VERSION 3.5)

project(FoliumTests)

# Enable testing support
enable_testing()

# Find required packages
find_package(GTest REQUIRED CONFIG)

add_executable(FoliumTests
    tests_main.cpp
    CommandLineParserTest.cpp
    CommandFactoryTest.cpp
    MergeCommandTest.cpp
    SplitCommandTest.cpp
)

# Include directories (for both your headers and mocks)
target_include_directories(FoliumTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}  # For mock headers in the same directory
    ${GTEST_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(FoliumTests PRIVATE
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    FoliumCore
)

# Discover and add tests
include(GoogleTest)
gtest_discover_tests(FoliumTests)