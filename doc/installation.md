# Installation

These are different ways you can install simplevectors.

## Simple Install

The simplest way is to download the single-header `simplevectors.hpp` file from the releases page. To include the file, simply put the path to the header file.

```cpp
#include "path/to/simplevectors.hpp"
```

## CMake

Alternatively, you can use CMake to install the library. First install the library onto your system:

```txt
$ cmake -B build -DSVECTOR_INSTALL=1 -DCMAKE_BUILD_TYPE=Release
$ cmake --build build --target install
```

Then, place the code below into your `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.16.3)
project(MyProject LANGUAGES CXX)

find_package(simplevectors REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE simplevectors::simplevectors)
```

If you do follow these instruction steps, the include path will be slightly different:

```cpp
#include <simplevectors/vectors.hpp>
```

