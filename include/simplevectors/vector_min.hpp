/**
 * vector_min.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_VECTOR_MIN_HPP_
#define INCLUDE_SVECTOR_VECTOR_MIN_HPP_

#include <cstddef>          // std::size_t
#include <initializer_list> // std::initializer_list

namespace svector {
template <std::size_t D, typename T = double> struct Vector {
  T m_components[D];

  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vector() {
    for (std::size_t i = 0; i < D; i++) {
      m_components[i] = 0;
    }
  }

  /**
   * Initializes a vector given initializer list.
   *
   * The initializer list should represent the components
   * of the vector in each dimension.
   *
   * @param args the initializer list.
   */
  Vector(const std::initializer_list<T> args) {
    // in case length of args < dimensions
    for (std::size_t i = 0; i < D; i++) {
      m_components[i] = 0;
    }

    std::size_t counter = 0;
    for (auto num : args) {
      if (counter >= D) {
        break;
      }

      m_components[counter] = num;
      counter++;
    }
  }

  /**
   * Copy constructor.
   */
  Vector(const Vector<D> &other) {
    for (std::size_t i = 0; i < D; i++) {
      m_components[i] = other[i];
    }
  }

  /**
   * Initializes a vector given xy components.
   *
   * @param x The x-component.
   * @param y The y-component.
   */
  Vector(const double x, const double y);

  /**
   * Initializes a vector given xyz components.
   *
   * @param x The x-component.
   * @param y The y-component.
   * @param z The z-component.
   */
  Vector(const double x, const double y, const double z);

  /**
   * Flips direction of vector.
   */
  Vector<D> operator-() const {
    Vector<D> tmp;
    for (std::size_t i = 0; i < D; i++) {
      tmp[i] = -this->m_components[i];
    }

    return tmp;
  }

  /**
   * Adds another vector object to self.
   */
  Vector<D> &operator+=(const Vector<D> &other) {
    for (std::size_t i = 0; i < D; i++) {
      this->m_components[i] += other[i];
    }

    return *this;
  }

  /**
   * Subtracts another vector object from self.
   */
  Vector<D> &operator-=(const Vector<D> &other) {
    for (std::size_t i = 0; i < D; i++) {
      this->m_components[i] -= other[i];
    }

    return *this;
  }

  /**
   * Multiplies vector by a number.
   */
  Vector<D> &operator*=(const T other) {
    for (std::size_t i = 0; i < D; i++) {
      this->m_components[i] *= other;
    }

    return *this;
  }

  /**
   * Divides vector by a number.
   */
  Vector<D> &operator/=(const T other) {
    for (std::size_t i = 0; i < D; i++) {
      this->m_components[i] /= other;
    }

    return *this;
  }

  /**
   * Gets a certain component of the vector given the dimension number.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  const T &operator[](const std::size_t index) const {
    return m_components[index];
  }

  /**
   * Sets a certain component of the vector given the dimension number.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  T &operator[](const std::size_t index) { return m_components[index]; }

  /**
   * Gets a certain component of the vector given the dimension number.
   *
   * Throws an out_of_range exception if given number is out of bounds.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  const T &at(const std::size_t index) const { return m_components.at(index); }

  /**
   * Sets a certain component of the vector given the dimension number.
   *
   * Throws an out_of_range exception if given number is out of bounds.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  T &at(const std::size_t index) { return m_components.at(index); }
};

typedef Vector<2> Vector2D;
typedef Vector<3> Vector3D;

template <> inline Vector2D::Vector(const double x, const double y) {
  m_components[0] = x;
  m_components[1] = y;
}

template <>
inline Vector3D::Vector(const double x, const double y, const double z) {
  m_components[0] = x;
  m_components[1] = y;
  m_components[2] = z;
}
} // namespace svector

#endif
