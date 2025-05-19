cmake_minimum_required(VERSION 3.5)
project(FoliumTests)
enable_testing()

# Use classic find_package without CONFIG
find_package(GTest REQUIRED)

add_executable(FoliumTests
    tests_main.cpp
    CommandLineParserTest.cpp
    CommandFactoryTest.cpp
    MergeCommandTest.cpp
    SplitCommandTest.cpp
)

target_include_directories(FoliumTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GTEST_INCLUDE_DIRS}  # This includes both gtest and gmock headers now
)

target_link_libraries(FoliumTests PRIVATE
    gtest
    gtest_main
    gmock
    gmock_main
    FoliumCore
)

include(GoogleTest)
gtest_discover_tests(FoliumTests)
