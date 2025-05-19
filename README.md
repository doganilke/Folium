# Folium - PDF Manipulation Tool

[![C++](https://img.shields.io/badge/C++-17-blue.svg)]()
[![CMake](https://img.shields.io/badge/CMake-3.5+-brightgreen.svg)]()
[![PoDoFo](https://img.shields.io/badge/PoDoFo-0.10-lightgrey.svg)]()

A command-line tool for merging and splitting PDF files, built with modern C++ and PoDoFo library.

## Features

- **Merge PDFs**: Combine multiple PDF files into one
- **Split PDFs**: Extract pages into separate files
- **Command-line interface**: Easy to use in scripts and automation
- **Cross-platform**: Works on Windows, Linux, and macOS

## Installation

### Prerequisites
- C++17 compatible compiler
- CMake 3.5+
- [PoDoFo](https://github.com/podofo/podofo) library
- [vcpkg](https://vcpkg.io/) (recommended for dependencies)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/doganilke/Folium.git
cd folium

# Create build directory
mkdir build && cd build

# Configure with vcpkg
cmake .. -DCMAKE_TOOLCHAIN_FILE=[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake

# Build
cmake --build .

# Run tests (optional)
ctest -V
