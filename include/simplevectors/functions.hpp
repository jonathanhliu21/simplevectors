/**
 * functions.hpp
 *
 * Functions for the vector classes (can be used for functional programming
 * rather than using properties of the classes).
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_FUNCTIONS_HPP_
#define INCLUDE_SVECTOR_FUNCTIONS_HPP_

#include <cmath>   // std::atan2, std::acos, std::sqrt
#include <cstddef> // std::size_t

#include "core/vector.hpp"
#include "core/vector2d.hpp"
#include "core/vector3d.hpp"

namespace svector {
// COMBINER_PY_START
/**
 * Gets the x-component of a 2D vector.
 *
 * @param v A 2D Vector.
 *
 * @returns x-component of the vector.
 */
inline double x(const Vector2D &v) { return v[0]; }

/**
 * Sets the x-component of a 2D vector.
 *
 * @param v A 2D Vector.
 * @param x_value The x-value to set to the vector.
 */
inline void x(Vector2D &v, const double x_value) { v[0] = x_value; }

/**
 * Gets the x-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns x-component of the vector.
 */
inline double x(const Vector3D &v) { return v[0]; }

/**
 * Sets the x-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param x_value The x-value to set to the vector.
 */
inline void x(Vector3D &v, const double x_value) { v[0] = x_value; }

/**
 * Gets the y-component of a 2D vector.
 *
 * @param v A 2D Vector.
 *
 * @returns y-component of the vector.
 */
inline double y(const Vector2D &v) { return v[1]; }

/**
 * Sets the y-component of a 2D vector.
 *
 * @param v A 2D Vector.
 * @param y_value The y-value to set to the vector.
 */
inline void y(Vector2D &v, const double y_value) { v[1] = y_value; }

/**
 * Gets the y-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns y-component of the vector.
 */
inline double y(const Vector3D &v) { return v[1]; }

/**
 * Sets the y-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param y_value The y value to set to the vector.
 */
inline void y(Vector3D &v, const double y_value) { v[1] = y_value; }

/**
 * Gets the z-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns z-component of the vector.
 */
inline double z(const Vector3D &v) { return v[2]; }

/**
 * Sets the z-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param z_value The z value to set to the vector.
 */
inline void z(Vector3D &v, const double z_value) { v[2] = z_value; }

/**
 * Dot product of two vectors.
 *
 * Note that the dimensions of the other vector has the be the same
 * as the current one.
 *
 * @param lhs First vector.
 * @param rhs Second vector.
 *
 * @returns The dot product of lhs and rhs.
 */
template <typename T, std::size_t D>
inline T dot(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
  T result = 0;

  for (std::size_t i = 0; i < D; i++) {
    result += lhs[i] * rhs[i];
  }

  return result;
}

/**
 * Gets the magnitude of the vector.
 *
 * @param v The vector to get magnitude of.
 *
 * @returns magnitude of vector.
 */
template <typename T, std::size_t D> inline T magn(const Vector<D, T> &v) {
  T sum_of_squares = 0;

  for (std::size_t i = 0; i < D; i++) {
    sum_of_squares += v[i] * v[i];
  }

  return std::sqrt(sum_of_squares);
}

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @param v The vector to normalize.
 *
 * @returns Normalized vector.
 */
template <typename T, std::size_t D>
inline Vector<D, T> normalize(const Vector<D, T> &v) {
  return v / magn(v);
}

/**
 * Gets the angle of a 2D vector in radians.
 *
 * The angle will be in the range (-π, π].
 *
 * @param v A 2D vector.
 *
 * @returns angle of the vector.
 */
inline double angle(const Vector2D &v) { return std::atan2(y(v), x(v)); }

/**
 * Rotates a 2D vector by a certain angle.
 *
 * The angle should be given in radians. The vector rotates
 * counterclockwise when the angle is positive and clockwise
 * when the angle is negative.
 *
 * @param v A 2D vector.
 * @param angle the angle to rotate the vector, in radians.
 *
 * @returns a new, rotated vector.
 */
inline Vector2D rotate(const Vector2D &v, const double ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)   -sin(ang) | |x|
   * | sin(ang)    cos(ang) | |y|
   */

  double xPrime = x(v) * std::cos(ang) - y(v) * std::sin(ang);
  double yPrime = x(v) * std::sin(ang) + y(v) * std::cos(ang);

  return Vector2D{xPrime, yPrime};
}

/**
 * Cross product of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector, crossed with the first vector.
 *
 * @returns The cross product of the two vectors.
 */
inline Vector3D cross(const Vector3D &lhs, const Vector3D &rhs) {
  double newx = y(lhs) * z(rhs) - z(lhs) * y(rhs);
  double newy = z(lhs) * x(rhs) - x(lhs) * z(rhs);
  double newz = x(lhs) * y(rhs) - y(lhs) * x(rhs);

  return Vector3D{newx, newy, newz};
}

/**
 * Gets α angle.
 *
 * α is the angle between the vector and the x-axis.
 *
 * @param v A 3D vector.
 *
 * @returns α
 */
inline double alpha(const Vector3D &v) { return std::acos(x(v) / magn(v)); }

/**
 * Gets β angle.
 *
 * β is the angle between the vector and the y-axis.
 *
 * @param v A 3D vector.
 *
 * @returns β
 */
inline double beta(const Vector3D &v) { return std::acos(y(v) / magn(v)); }

/**
 * Gets γ angle.
 *
 * γ is the angle between the vector and the z-axis.
 *
 * @param v A 3D vector.
 *
 * @returns γ
 */
inline double gamma(const Vector3D &v) { return std::acos(z(v) / magn(v)); }

/**
 * Rotates around x-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param v A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vector3D rotateAlpha(const Vector3D &v, const double &ang) {
  /**
   * Rotation matrix:
   *
   * |1   0           0     | |x|
   * |0  cos(ang)  −sin(ang)| |y|
   * |0  sin(ang)   cos(ang)| |z|
   */

  double xPrime = x(v);
  double yPrime = y(v) * std::cos(ang) - z(v) * std::sin(ang);
  double zPrime = y(v) * std::sin(ang) + z(v) * std::cos(ang);

  return Vector3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around y-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param v A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vector3D rotateBeta(const Vector3D &v, const double &ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)  0  sin(ang)| |x|
   * |   0       1      0   | |y|
   * |−sin(ang)  0  cos(ang)| |z|
   */

  double xPrime = x(v) * std::cos(ang) + z(v) * std::sin(ang);
  double yPrime = y(v);
  double zPrime = -x(v) * std::sin(ang) + z(v) * std::cos(ang);

  return Vector3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around z-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param v A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vector3D rotateGamma(const Vector3D &v, const double &ang) {
  /**
   * Rotation matrix:
   *
   * |cos(ang)  −sin(ang)  0| |x|
   * |sin(ang)  cos(ang)   0| |y|
   * |  0         0        1| |z|
   */

  double xPrime = x(v) * std::cos(ang) - y(v) * std::sin(ang);
  double yPrime = x(v) * std::sin(ang) + y(v) * std::cos(ang);
  double zPrime = z(v);

  return Vector3D{xPrime, yPrime, zPrime};
}

#ifndef SVECTOR_USE_CLASS_OPERATORS
/**
 * Adds two vectors.
 */
template <typename T, std::size_t D>
inline Vector<D, T> operator+(const Vector<D, T> &lhs,
                              const Vector<D, T> &rhs) {
  Vector<D, T> tmp;
  for (std::size_t i = 0; i < D; i++) {
    tmp[i] = lhs[i] + rhs[i];
  }

  return tmp;
}

/**
 * Subtracts two vectors.
 */
template <typename T, std::size_t D>
inline Vector<D, T> operator-(const Vector<D, T> &lhs,
                              const Vector<D, T> &rhs) {
  Vector<D, T> tmp;
  for (std::size_t i = 0; i < D; i++) {
    tmp[i] = lhs[i] - rhs[i];
  }

  return tmp;
}

/**
 * Scalar multiplication of vectors
 */
template <typename T, typename T2, std::size_t D>
inline Vector<D, T> operator*(const Vector<D, T> &lhs, const T2 rhs) {
  Vector<D, T> tmp;
  for (std::size_t i = 0; i < D; i++) {
    tmp[i] = lhs[i] * rhs;
  }

  return tmp;
}

/**
 * Scalar division of vectors
 */
template <typename T, typename T2, std::size_t D>
inline Vector<D, T> operator/(const Vector<D, T> &lhs, const T2 rhs) {
  Vector<D, T> tmp;
  for (std::size_t i = 0; i < D; i++) {
    tmp[i] = lhs[i] / rhs;
  }

  return tmp;
}

/**
 * Equality
 */
template <typename T, std::size_t D>
inline bool operator==(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
  for (std::size_t i = 0; i < D; i++) {
    if (lhs[i] != rhs[i])
      return false;
  }

  return true;
}

/**
 * Inequality
 */
template <typename T, std::size_t D>
inline bool operator!=(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
  return !(lhs == rhs);
}
#endif

#ifdef SVECTOR_EXPERIMENTAL_COMPARE
template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator<(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) < 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator>(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) > 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator<=(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) <= 0;
}

template <std::size_t D1, std::size_t D2, typename T1, typename T2>
bool operator>=(const Vector<D1, T1> &lhs, const Vector<D2, T2> &rhs) {
  return lhs.compare(rhs) >= 0;
}
#endif
// COMBINER_PY_END
} // namespace svector

#endif