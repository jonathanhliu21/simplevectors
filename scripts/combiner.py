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

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <string>

namespace svector {
"""

FILE_END = """}

#endif
"""

"""Reads sandwiched part of file from file path"""


def get_sandwiched(fpath):
    filestr = ""
    with open(fpath) as f:
        filestr = f.read()

    sandwiched_groups = re.search(RE_STR, filestr, flags=re.DOTALL)
    assert sandwiched_groups is not None

    return sandwiched_groups.group(1)


def combine():
    # get final output file
    output_str = (
        FILE_BEGIN
        + get_sandwiched(os.path.join("include", "simplevectors", "core", "units.hpp"))
        + get_sandwiched(os.path.join("include", "simplevectors", "core", "vector.hpp"))
        + get_sandwiched(
            os.path.join("include", "simplevectors", "core", "vector2d.hpp")
        )
        + get_sandwiched(
            os.path.join("include", "simplevectors", "core", "vector3d.hpp")
        )
        + get_sandwiched(os.path.join("include", "simplevectors", "vectors.hpp"))
        + FILE_END
    )

    print(output_str)


if __name__ == "__main__":
    combine()
