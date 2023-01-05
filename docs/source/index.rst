Simplevectors Documentation
===========================

Simple vector implementations in C++.

**NOTE**: C++11 or higher is needed for this library.

**NOTE**: This is mostly tested on MacOS 12.6 with C++11, clang 13.0.0, CMake 3.22.2, and GNU make 3.81.

.. image:: https://img.shields.io/github/actions/workflow/status/jonyboi396825/simplevectors/test.yml
   :alt: GitHub Workflow Status

.. image:: https://readthedocs.org/projects/simplevectors/badge/?version=latest
    :target: https://simplevectors.readthedocs.io/en/latest/?badge=latest
    :alt: Documentation Status

Installation
------------

The simplest way is to download the single-header `simplevectors.hpp` file from the releases page. To include the file, simply put the path to the header file.

.. code-block:: cpp

   #include "path/to/simplevectors.hpp"

CMake
~~~~~

Alternatively, you can use CMake to install the library:

.. code-block:: cmake

   cmake_minimum_required(VERSION 3.16.3)
   project(MyProject LANGUAGES CXX)

   find_package(simplevectors REQUIRED)

   add_executable(main main.cpp)
   target_link_libraries(main PRIVATE simplevectors::simplevectors)

If you do this, the include path will be slightly different:

.. code-block:: cpp

   #include <simplevectors/vectors.hpp>

License
-------

MIT License (© 2022 Jonathan Liu)

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   installation
   basic_usage
   extending
   embedding
   api/library_root

