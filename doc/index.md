@mainpage

# Simplevectors Documentation

Simple, embeddable, and extendable vector implementations in C++.

@note C++11 or higher is needed for this library.

@note This is mostly tested on MacOS 12.6 with C++11, clang 13.0.0, CMake 3.22.2, and GNU make 3.81.

![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/jonyboi396825/simplevectors/test.yml)
![GitHub Docs Status](https://img.shields.io/github/actions/workflow/status/jonyboi396825/simplevectors/doc.yml?label=docs)

## Links

- Source Code: <https://github.com/jonyboi396825/simplevectors>
- Documentation: <https://jonyboi396825.github.io/simplevectors/index.html>

## Quickstart

This is a very basic example of simplevectors. First, download `simplevectors.hpp` from the releases page on the GitHub repository, then paste the code below:

```cpp
#include "path/to/simplevectors.hpp"

int main(){
  svector::Vector<2> vector2; // creates a 2D-vector
  svector::Vector2D
      vector2d; // creates a 2D-vector with 2D-specific functionality

  svector::Vector<3> vector3; // creates a 3D-vector
  svector::Vector3D
      vector3d; // creates a 3D-vector with 3D-specific functionality

  svector::Vector<4> vector4; // creates a 4D-vector
}
```

## More info

For more information about usage, look under the "Related Pages" tab. For info about the API classes, look under the "Classes" tab.  For info about functions, look under the "Files" tab.

## License

MIT License (© 2023 Jonathan Liu)

