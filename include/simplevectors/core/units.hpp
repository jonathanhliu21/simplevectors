/**
 * @file units.hpp
 *
 * All STL includes and enums needed for the core library.
 *
 * @copyright Copyright (c) 2022 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_UNITS_HPP_
#define INCLUDE_SVECTOR_UNITS_HPP_

// all includes
#include <algorithm> // std::min
#include <array>     // std::array
#include <cmath>     // std::acos, std::atan2, std::cos, std::sin, std::sqrt
#include <cstddef>   // std::size_t
#include <cstdint>   // std::int8_t
#include <initializer_list> // std::initializer_list
#include <string>           // std::string, std::to_string

namespace svector {
// COMBINER_PY_START
/**
 * An enum representing the angle to use for a 3D vector.
 *
 * ALPHA is the angle between the positive x-axis and the vector, BETA is the
 * angle between the positive y-axis and the vector, and GAMMA is the angle
 * between the positive z-axis and the vector.
 *
 * This is only used in svector::Vector3D::angle() and
 * svector::Vector3D::rotate().
 */
enum AngleDir { ALPHA, BETA, GAMMA };
// COMBINER_PY_END
} // namespace svector

#endif
