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
 * @file simplevectors.hpp
 *
 * @internal
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Jonathan Liu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * @endinternal
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
#include <type_traits>
#include <vector>

namespace svector {
"""

FILE_END = """} // namespace svector

#endif
"""


def get_sandwiched(fpath):
    """Reads sandwiched part of file from file path"""

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
        + get_sandwiched(os.path.join("include", "simplevectors", "functions.hpp"))
        + FILE_END
    )

    print(output_str)


if __name__ == "__main__":
    combine()
