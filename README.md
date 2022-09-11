# Simplevectors

Simple 2D and 3D vector implementations in C++.

**NOTE**: This is mostly tested on MacOS 12.6 with C++14, clang  13.0.0, CMake  3.22.2, and GNU make 3.81


## Installation

The simplest way is to download the single-header `simplevectors.h` file from the releases page. To include the file, simply put the path to the header file.

```cpp
#include "path/to/simplevectors.hpp"
```

### CMake

Alternatively, you can use CMake to install the library:

```cmake
cmake_minimum_required(VERSION 3.9)
project(MyProject LANGUAGES CXX)

find_package(simplevectors REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE simplevectors)
```

If you do this, the include path will be slightly different:

```cpp
#include <simplevectors/vectors.hpp>
```

## Usage

This section covers basic usage. For more details, read the docstrings in the source code files.

Everything is under the namespace `svector`. 

### Initialization

```cpp
svector::Vector2D zero2d; // <0, 0>
svector::Vector3D zero3d; // <0, 0, 0>

svector::Vector2D v2d(2, 4);    // <2, 4>
svector::Vector3D v3d(2, 4, 5); // <2, 4, 5>
```

### Printing

Both `Vector2D` and `Vector3D` have `toString()` methods for printing.

```cpp
#include <iostream>

std::cout << zero2d.toString() << std::endl; // "<0.000, 0.000>"
std::cout << v3d.toString() << std::endl; // "<2.000, 4.000, 5.000>"
```

### Properties

```cpp
// components of the vector
std::cout << v2d.x() << " " // 2.000
          << v2d.y() << " " // 4.000
          << std::endl;

std::cout << v3d.x() << " " // 2.000
          << v3d.y() << " " // 4.000
          << v3d.z() << " " // 5.000
          << std::endl;

// 2D magnitude and angle from horizontal, in radians
// Angle ranges from (-π, π]
std::cout << v2d.magn() << std::endl;  // 4.472
std::cout << v2d.angle() << std::endl; // 1.107

// 3D magnitude and angle from x-axis (ALPHA), y-axis (BETA),
// and z-axis (GAMMA) in radians
// Angles range from [0, π]
std::cout << v3d.magn() << std::endl;                  // 6.708
std::cout << v3d.angle<svector::ALPHA>() << std::endl; // 1.268
std::cout << v3d.angle<svector::BETA>() << std::endl;  // 0.932
std::cout << v3d.angle<svector::GAMMA>() << std::endl; // 0.730
```

### Operations

These are operations that can be done on both 2D and 3D vectors. For simplicity, examples will be shown with only 2D vectors.

```cpp
svector::Vector2D lhs(2, 5);
svector::Vector2D rhs(3, -4);

svector::Vector2D sum = lhs + rhs;        // <5, 1>
svector::Vector2D difference = lhs - rhs; // <-1, 9>
svector::Vector2D product = lhs * 3;      // <6, 15>
svector::Vector2D quotient = lhs / 3;     // <0.667, 1.667>
double dot_product = lhs.dot(rhs);        // -14
svector::Vector2D neg = -lhs;             // <-2, -5>
```

Cross products only work on 3D vectors.

```cpp
svector::Vector3D lhs3d(2, 5, -3);
svector::Vector3D rhs3d(6, 5, 9);

svector::Vector3D cross = lhs3d.cross(rhs3d); // <60, -36, -20>
```

Vectors can be added, subtracted, multiplied, or divided in place.
```cpp
svector::Vector2D inplacev(2, 5);
inplacev += svector::Vector2D(3, 6);
inplacev -= svector::Vector2D(2, 3);
inplacev *= 5;
inplacev /= 7;

std::cout << inplacev.toString() << std::endl; // <2.143, 5.714>
```

### Equality

Works for both 2D and 3D vectors.

```cpp
svector::Vector2D lhs1(2, 5);
svector::Vector2D rhs1(3, -4);
svector::Vector2D lhs2(2, 5);
svector::Vector2D rhs2(2, 5);

bool equal1 = lhs1 == rhs1;  // false
bool equal2 = lhs1 != rhs1;  // true
bool equal3 = lhs2 == rhs2;  // true
bool equal4 = lhs2 != rhs2;  // false
```

### Normalization

```cpp
svector::Vector2D unnorm2D(3, 4);
svector::Vector3D unnorm3D(3, 4, 5);

svector::Vector2D norm2D = unnorm2D.normalize(); // <0.6, 0.8>
svector::Vector3D norm3D = unnorm3D.normalize(); // <0.424, 0.566, 0.707>
```

### Rotation 2D

For 2D vectors, the `rotate` method requires one argument, `ang`, which is the angle to rotate in radians. A positive angle indicates counterclockwise rotation, and a negative angle indicates clockwise rotation. The method returns a new vector.

```cpp
svector::Vector2D v1(1, 0);
svector::Vector2D v2(1, 0);

svector::Vector2D v1ccw = v1.rotate(M_PI_4);  // <0.707, 0.707>
svector::Vector2D v2cw = v1.rotate(-M_PI_4);  // <0.707, -0.707>
```

### Rotation 3D

For 3D vectors, the `rotate` method only works for one axis at a time. It requires a template argument indicating the axis to rotate around: `ALPHA` for the x-axis, `BETA` for the y-axis, and `GAMMA` for the z-axis.

```cpp
svector::Vector3D v1_3D(1, 0, 1);

svector::Vector3D v1_xRotation =
    v1_3D.rotate<svector::ALPHA>(M_PI_2); // <1, -1, 0>
svector::Vector3D v1_yRotation =
    v1_3D.rotate<svector::BETA>(M_PI_2); // <1, 0, -1>
svector::Vector3D v1_zRotation =
    v1_3D.rotate<svector::GAMMA>(M_PI_2); // <0, 1, 1>
```

Rotations can also be chained:

```cpp
svector::Vector3D v1_chained =
    v1_3D.rotate<svector::ALPHA>(M_PI_2)
        .rotate<svector::BETA>(M_PI_2)
        .rotate<svector::GAMMA>(M_PI_2); // <1, 0, -1>
```

## License

MIT License (© 2022 Jonathan Liu)
