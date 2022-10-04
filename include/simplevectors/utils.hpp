#ifndef INCLUDE_SVECTOR_UTILS_HPP_
#define INCLUDE_SVECTOR_UTILS_HPP_

#include <cstddef>

#include "core/vector.hpp"
#include "core/vector2d.hpp"
#include "core/vector3d.hpp"

namespace svector {
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
template <typename T, std::size_t D> T dot(Vector<D, T> lhs, Vector<D, T> rhs) {
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
template <typename T, std::size_t D> T magn(Vector<D, T> v) {
  T sum_of_squares = 0;

  for (auto i : v) {
    sum_of_squares += i * i;
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
template <typename T, std::size_t D> Vector<D, T> normalize(Vector<D, T> v) {
  return v / v.magn();
}

#ifndef SVECTOR_USE_CLASS_OPERATORS
/**
 * Adds two vectors.
 */
template <typename T, std::size_t D>
Vector<D, T> operator+(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
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
Vector<D, T> operator-(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
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
Vector<D, T> operator*(const Vector<D, T> &lhs, const T2 rhs) {
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
Vector<D, T> operator/(const Vector<D, T> &lhs, const T2 rhs) {
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
bool operator==(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
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
bool operator!=(const Vector<D, T> &lhs, const Vector<D, T> &rhs) {
  return !(lhs == rhs);
}
#endif
} // namespace svector

#endif
