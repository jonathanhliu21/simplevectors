/**
 * @file units.hpp
 *
 * All STL includes and enums needed for the core library.
 *
 * @copyright Copyright (c) 2023 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_UNITS_HPP_
#define INCLUDE_SVECTOR_UNITS_HPP_

namespace svector {
// COMBINER_PY_START
/**
 * @brief Angle enumerator
 *
 * An enum representing the angle to use for a 3D vector.
 *
 * This is only used in svector::Vector3D::angle() and
 * svector::Vector3D::rotate().
 */
enum AngleDir {
  ALPHA, //!< Angle between positive x-axis and vector
  BETA,  //!< Angle between positive y-axis and vector
  GAMMA  //!< Angle between positive z-axis and vector
};
// COMBINER_PY_END
} // namespace svector

#endif
