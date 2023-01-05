# Simplevectors

Simple vector implementations in C++.

**NOTE**: C++11 or higher is needed for this library.

**NOTE**: This is mostly tested on MacOS 12.6 with C++11, clang 13.0.0, CMake 3.22.2, and GNU make 3.81

![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/jonyboi396825/simplevectors/test.yml)

[![Documentation Status](https://readthedocs.org/projects/simplevectors/badge/?version=latest)](https://simplevectors.readthedocs.io/en/latest/?badge=latest)

## Installation

The simplest way is to download the single-header `simplevectors.hpp` file from the releases page. To include the file, simply put the path to the header file.

```cpp
#include "path/to/simplevectors.hpp"
```

### CMake

Alternatively, you can use CMake to install the library:

```cmake
cmake_minimum_required(VERSION 3.16.3)
project(MyProject LANGUAGES CXX)

find_package(simplevectors REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE simplevectors::simplevectors)
```

If you do this, the include path will be slightly different:

```cpp
#include <simplevectors/vectors.hpp>
```

## Links

Source Code: <https://github.com/jonyboi396825/simplevectors>

Documentation: <https://simplevectors.readthedocs.io/en/latest/>

## License

MIT License (© 2022 Jonathan Liu)
