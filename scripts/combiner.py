#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""Combines separate files into a single header file

The header file should be named `simplevectors.h`, and everything
will be under the namespace `svector`.

This program will process the files and print the result to stdout.
"""

import re
import os

SIMPLEVECTOR2D_H_RSTR = r"/\/\ COMBINER_PY_STARTH_1\ *\n(.*)\/\/\ COMBINER_PY_ENDH_1"
SIMPLEVECTOR2D_CPP_RSTR = (
    r"/\/\ COMBINER_PY_STARTCPP_1\ *\n(.*)\/\/\ COMBINER_PY_ENDCPP_1"
)
SIMPLEVECTOR3D_H_RSTR = r"/\/\ COMBINER_PY_STARTH_2\ *\n(.*)\/\/\ COMBINER_PY_ENDH_2"
SIMPLEVECTOR3D_CPP_RSTR = (
    r"/\/\ COMBINER_PY_STARTCPP_2\ *\n(.*)\/\/\ COMBINER_PY_ENDCPP_2"
)
UNITS_H_RSTR = r"/\/\ COMBINER_PY_STARTH_3\ *\n(.*)\/\/\ COMBINER_PY_ENDH_3"

FILE_BEGIN = """/**
 * simplevectors.h
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef SIMPLEVECTORS_H
#define SIMPLEVECTORS_H

#include <cmath>
#include <string>

namespace svector{
"""

FILE_END = """}

#endif
"""


def combine():
    # read files into strings
    simplevector2d_h_str = ""
    simplevector2d_cpp_str = ""
    simplevector3d_h_str = ""
    simplevector3d_cpp_str = ""
    units_h_str = ""

    with open(os.path.join("include", "simplevectors", "simplevector2d.h")) as f:
        simplevector2d_h_str = f.read()

    with open(os.path.join("include", "simplevectors", "simplevector3d.h")) as f:
        simplevector3d_h_str = f.read()

    with open(os.path.join("include", "simplevectors", "units.h")) as f:
        units_h_str = f.read()

    with open(os.path.join("src", "simplevector2d.cpp")) as f:
        simplevector2d_cpp_str = f.read()

    with open(os.path.join("src", "simplevector3d.cpp")) as f:
        simplevector3d_cpp_str = f.read()

    # get each "sandwiched" part of each file
    sandwiched_units_h = re.search(UNITS_H_RSTR, units_h_str, flags=re.DOTALL).group(1)
    sandwiched_simplevector2d_h = re.search(
        SIMPLEVECTOR2D_H_RSTR, simplevector2d_h_str, flags=re.DOTALL
    ).group(1)
    sandwiched_simplevector2d_cpp = re.search(
        SIMPLEVECTOR2D_CPP_RSTR, simplevector2d_cpp_str, flags=re.DOTALL
    ).group(1)
    sandwiched_simplevector3d_h = re.search(
        SIMPLEVECTOR3D_H_RSTR, simplevector3d_h_str, flags=re.DOTALL
    ).group(1)
    sandwiched_simplevector3d_cpp = re.search(
        SIMPLEVECTOR3D_CPP_RSTR, simplevector3d_cpp_str, flags=re.DOTALL
    ).group(1)

    # get final output file
    output_str = (
        FILE_BEGIN
        + sandwiched_units_h
        + sandwiched_simplevector2d_h
        + sandwiched_simplevector3d_h
        + sandwiched_simplevector2d_cpp
        + sandwiched_simplevector3d_cpp
        + FILE_END
    )

    print(output_str)


if __name__ == "__main__":
    combine()
