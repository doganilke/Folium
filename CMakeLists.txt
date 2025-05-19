cmake_minimum_required(VERSION 3.16)
project(FoliumApp
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "PDF manipulation tool using PoDoFo"
)

#-----------------------------------------------------------------------------
# Global Configuration
#-----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use environment variable NPROC for parallel builds if set
if(DEFINED ENV{NPROC})
    set(CMAKE_BUILD_PARALLEL_LEVEL $ENV{NPROC})
endif()

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#-----------------------------------------------------------------------------
# Dependencies
#-----------------------------------------------------------------------------
# Find PoDoFo package (assumes it provides proper CMake config files)
find_package(podofo CONFIG REQUIRED)

# Check for targets podofo_shared or podofo_static
if(NOT TARGET podofo_shared AND NOT TARGET podofo_static)
    message(FATAL_ERROR "PoDoFo package found but no valid targets (podofo_shared or podofo_static)")
endif()

#-----------------------------------------------------------------------------
# Main Library
#-----------------------------------------------------------------------------
add_library(FoliumCore STATIC
    src/PdfMerger.cpp
    src/PdfSplitter.cpp
    src/MergeCommand.cpp
    src/SplitCommand.cpp
    src/CommandFactory.cpp
    src/CommandLineParser.cpp
)

target_include_directories(FoliumCore PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(FoliumCore PUBLIC
    $<IF:$<TARGET_EXISTS:podofo_shared>,podofo_shared,podofo_static>
)

#-----------------------------------------------------------------------------
# Main Executable
#-----------------------------------------------------------------------------
add_executable(Folium src/main.cpp)
target_link_libraries(Folium PRIVATE FoliumCore)

#-----------------------------------------------------------------------------
# Testing Support (assumes tests directory with CMakeLists.txt)
#-----------------------------------------------------------------------------
enable_testing()
add_subdirectory(tests)

#-----------------------------------------------------------------------------
# Installation (optional)
#-----------------------------------------------------------------------------
install(TARGETS Folium
    RUNTIME DESTINATION bin
)

install(TARGETS FoliumCore
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

#-----------------------------------------------------------------------------
# Summary
#-----------------------------------------------------------------------------
message(STATUS "\n========================================")
message(STATUS "  FoliumApp Configuration Summary")
message(STATUS "========================================")
message(STATUS "Version:       ${PROJECT_VERSION}")
message(STATUS "C++ Standard:  ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Tests:   ${BUILD_TESTING}")
message(STATUS "PoDoFo Found:  ${podofo_FOUND}")
message(STATUS "Output Dir:    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "========================================\n")
