cmake_minimum_required(VERSION 3.16)
project(FoliumApp LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find PoDoFo Package
find_package(podofo CONFIG REQUIRED)

# Source files
set(SRC_FILES
    src/main.cpp
    src/PdfMerger.cpp
    src/PdfSplitter.cpp

    src/MergeCommand.cpp
    src/SplitCommand.cpp
    src/CommandFactory.cpp
    src/CommandLineParser.cpp
)

# Add Executable
add_executable(Folium ${SRC_FILES})

# Include Directories
target_include_directories(Folium PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

# Link Libraries
target_link_libraries(Folium PRIVATE
    $<IF:$<TARGET_EXISTS:podofo_shared>,podofo_shared,podofo_static>
)

# Set Output Directory
set_target_properties(Folium PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Print Status
message(STATUS "Building FoliumApp with C++17 and PoDoFo")
