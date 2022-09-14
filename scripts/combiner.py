#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""Combines separate files into a single header file

The header file should be named `simplevectors.hpp`, and everything
will be under the namespace `svector`.

This program will process the files and print the result to stdout.
"""

import re
import os

RE_STR = r"/\/\ COMBINER_PY_START\ *\n(.*)\/\/\ COMBINER_PY_END"

FILE_BEGIN = """/**
 * simplevectors.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTORS_SIMPLEVECTORS_HPP_
#define INCLUDE_SVECTORS_SIMPLEVECTORS_HPP_

#include <array>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <string>

namespace svector {
"""

FILE_END = """}

#endif
"""


def combine():
    # read files into strings
    units_str = ""
    vector_str = ""
    vector2d_str = ""
    vector3d_str = ""

    with open(os.path.join("include", "simplevectors", "core", "units.hpp")) as f:
        units_str = f.read()

    with open(os.path.join("include", "simplevectors", "core", "vector.hpp")) as f:
        vector_str = f.read()

    with open(os.path.join("include", "simplevectors", "core", "vector2d.hpp")) as f:
        vector2d_str = f.read()

    with open(os.path.join("include", "simplevectors", "core", "vector3d.hpp")) as f:
        vector3d_str = f.read()

    # get each "sandwiched" part of each file
    sandwiched_units_groups = re.search(RE_STR, units_str, flags=re.DOTALL)
    sandwiched_vector_groups = re.search(RE_STR, vector_str, flags=re.DOTALL)
    sandwiched_vector2d_groups = re.search(RE_STR, vector2d_str, flags=re.DOTALL)
    sandwiched_vector3d_groups = re.search(RE_STR, vector3d_str, flags=re.DOTALL)

    assert sandwiched_units_groups is not None
    assert sandwiched_vector_groups is not None
    assert sandwiched_vector2d_groups is not None
    assert sandwiched_vector3d_groups is not None

    sandwiched_units = sandwiched_units_groups.group(1)
    sandwiched_vector = sandwiched_vector_groups.group(1)
    sandwiched_vector2d = sandwiched_vector2d_groups.group(1)
    sandwiched_vector3d = sandwiched_vector3d_groups.group(1)

    # get final output file
    output_str = (
        FILE_BEGIN
        + sandwiched_units
        + sandwiched_vector
        + sandwiched_vector2d
        + sandwiched_vector3d
        + FILE_END
    )

    print(output_str)


if __name__ == "__main__":
    combine()
