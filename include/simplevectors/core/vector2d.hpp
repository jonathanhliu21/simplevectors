/**
 * @file vector2d.hpp
 *
 * Contains a 2D vector representation.
 *
 * @copyright Copyright (c) 2023 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_VECTOR2D_HPP_
#define INCLUDE_SVECTOR_VECTOR2D_HPP_

#include <cmath> // std::atan2, std::cos, std::sin

#include "simplevectors/core/vector.hpp" // svector::Vector

namespace svector {
// COMBINER_PY_START

typedef Vector<2> Vec2_; //!< An alias to Vector<2>.

/**
 * @brief A simple 2D vector representation.
 */
class Vector2D : public Vec2_ {
public:
  using Vec2_::Vector;

  /**
   * @brief Initializes a vector given xy components.
   *
   * @param x The x-component.
   * @param y The y-component.
   */
  Vector2D(const double x, const double y) {
    this->m_components[0] = x;
    this->m_components[1] = y;
  }

  /**
   * @brief Copy constructor for base class.
   */
  Vector2D(const Vec2_ &other) {
    this->m_components[0] = other[0];
    this->m_components[1] = other[1];
  }

  /**
   * @brief Gets x-component
   *
   * Gets the x-component of the vector.
   *
   * @returns x-component of vector.
   */
  double x() const { return this->m_components[0]; }

  /**
   * @brief Sets x-component
   *
   * Sets the x-component of the vector.
   *
   * @param newX x-value to set
   */
  void x(const double &newX) { this->m_components[0] = newX; }

  /**
   * @brief Gets y-component
   *
   * Gets the y-component of the vector.
   *
   * @returns y-component of vector.
   */
  double y() const { return this->m_components[1]; }

  /**
   * @brief Sets y-component
   *
   * Sets the y-component of the vector.
   *
   * @param newY y-value to set
   */
  void y(const double &newY) { this->m_components[1] = newY; }

  /**
   * @brief Angle of vector
   *
   * Gets the angle of the vector in radians.
   *
   * The angle will be in the range (-π, π].
   *
   * @returns The angle of the vector.
   */
  double angle() const { return std::atan2(this->y(), this->x()); }

  /**
   * @brief Rotates vector by a certain angle.
   *
   * The angle should be given in radians. The vector rotates
   * counterclockwise when the angle is positive and clockwise
   * when the angle is negative.
   *
   * @param ang the angle to rotate the vector, in radians.
   *
   * @returns A new, rotated vector.
   */
  Vector2D rotate(const double ang) const {
    //
    // Rotation matrix:
    //
    // | cos(ang)   -sin(ang) | |x|
    // | sin(ang)    cos(ang) | |y|
    //

    const double xPrime = this->x() * std::cos(ang) - this->y() * std::sin(ang);
    const double yPrime = this->x() * std::sin(ang) + this->y() * std::cos(ang);

    return Vector2D{xPrime, yPrime};
  }

  /**
   * @brief Converts vector to another object
   *
   * Converts the components of the vector to an object with a constructor
   * that has two parameters.
   *
   * For example, this method can be used to convert the components of
   * a 2D vector into a `pair<double, double>`, or a struct with two
   * variables and a constructor for those two variables.
   *
   * @returns The converted value.
   */
  template <typename T> T componentsAs() const {
    return T{this->x(), this->y()};
  }
};
// COMBINER_PY_END
} // namespace svector

#endif
