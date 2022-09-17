/**
 * basevector.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_BASEVECTOR_HPP_
#define INCLUDE_SVECTOR_BASEVECTOR_HPP_

#include <array>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <string>

namespace svector {
// COMBINER_PY_START
/**
 * A base vector representation.
 */
template <std::size_t dimensions, typename T = double> class Vector {
public:
  typedef typename std::array<T, dimensions>::iterator iterator;
  typedef typename std::array<T, dimensions>::const_iterator const_iterator;
  typedef typename std::array<T, dimensions>::reverse_iterator reverse_iterator;
  typedef typename std::array<T, dimensions>::const_reverse_iterator
      const_reverse_iterator;

  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vector() { this->m_components.fill(0); }

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
    this->m_components.fill(0);

    std::size_t counter = 0;
    for (auto num : args) {
      if (counter >= dimensions) {
        break;
      }

      this->m_components[counter] = num;
      counter++;
    }
  }

  /**
   * Copy constructor.
   */
  Vector(const Vector<dimensions> &other) {
    for (std::size_t i = 0; i < dimensions; i++) {
      this->m_components[i] = other[i];
    }
  }

  /**
   * String form; can be used for printing.
   *
   * @returns string form of vector.
   */
  virtual std::string toString() const {
    std::string str = "<";
    for (std::size_t i = 0; i < dimensions - 1; i++) {
      str += std::to_string(this->m_components[i]);
      str += ", ";
    }

    str += std::to_string(this->m_components[dimensions - 1]);
    str += ">";

    return str;
  }

  /**
   * Adds two vectors.
   */
  Vector<dimensions> operator+(const Vector<dimensions> &other) const {
    Vector<dimensions> tmp;
    for (std::size_t i = 0; i < dimensions; i++) {
      tmp[i] = this->m_components[i] + other[i];
    }

    return tmp;
  }

  /**
   * Subtracts two vectors.
   */
  Vector<dimensions> operator-(const Vector<dimensions> &other) const {
    Vector<dimensions> tmp;
    for (std::size_t i = 0; i < dimensions; i++) {
      tmp[i] = this->m_components[i] - other[i];
    }

    return tmp;
  }

  /**
   * Flips direction of vector.
   */
  Vector<dimensions> operator-() const {
    Vector<dimensions> tmp;
    for (std::size_t i = 0; i < dimensions; i++) {
      tmp[i] = -this->m_components[i];
    }

    return tmp;
  }

  /**
   * Scalar multiplication of vector.
   */
  Vector<dimensions> operator*(const T other) const {
    Vector<dimensions> tmp;
    for (std::size_t i = 0; i < dimensions; i++) {
      tmp[i] = this->m_components[i] * other;
    }

    return tmp;
  }

  /**
   * Scalar division of vector.
   */
  Vector<dimensions> operator/(const T other) const {
    Vector<dimensions> tmp;
    for (std::size_t i = 0; i < dimensions; i++) {
      tmp[i] = this->m_components[i] / other;
    }

    return tmp;
  }

  /**
   * Equality
   */
  bool operator==(const Vector<dimensions> &other) const {
    for (std::size_t i = 0; i < dimensions; i++) {
      if (this->m_components[i] == other[i])
        continue;
      else
        return false;
    }

    return true;
  }

  /**
   * Inequality
   */
  bool operator!=(const Vector<dimensions> &other) const {
    return !((*this) == other);
  }

  /**
   * Adds another vector object to self.
   */
  Vector<dimensions> &operator+=(const Vector<dimensions> &other) {
    for (std::size_t i = 0; i < dimensions; i++) {
      this->m_components[i] += other[i];
    }

    return *this;
  }

  /**
   * Subtracts another vector object from self.
   */
  Vector<dimensions> &operator-=(const Vector<dimensions> &other) {
    for (std::size_t i = 0; i < dimensions; i++) {
      this->m_components[i] -= other[i];
    }

    return *this;
  }

  /**
   * Multiplies vector by a number.
   */
  Vector<dimensions> &operator*=(const T other) {
    for (std::size_t i = 0; i < dimensions; i++) {
      this->m_components[i] *= other;
    }

    return *this;
  }

  /**
   * Divides vector by a number.
   */
  Vector<dimensions> &operator/=(const T other) {
    for (std::size_t i = 0; i < dimensions; i++) {
      this->m_components[i] /= other;
    }

    return *this;
  }

  /**
   * Dot product of two vectors.
   *
   * Note that the dimensions of the other vector has the be the same
   * as the current one.
   *
   * @param other The other vector to dot current vector with.
   *
   * @returns The dot product of the two vectors.
   */
  T dot(const Vector<dimensions> &other) const {
    T result = 0;

    for (std::size_t i = 0; i < dimensions; i++) {
      result += this->m_components[i] * other[i];
    }

    return result;
  }

  /**
   * Gets the magnitude of the vector.
   *
   * @returns magnitude of vector.
   */
  T magn() const {
    T sum_of_squares = 0;
    for (auto i : this->m_components) {
      sum_of_squares += i * i;
    }

    return std::sqrt(sum_of_squares);
  };

  /**
   * Normalizes a vector.
   *
   * Finds the unit vector with the same direction angle as the current vector.
   *
   * @returns Normalized vector.
   */
  Vector<dimensions> normalize() const { return (*this) / this->magn(); }

  /**
   * Gets number of dimensions.
   *
   * @returns Number of dimensions.
   */
  std::size_t numDimensions() const { return dimensions; }

  /**
   * Gets a certain component of the vector given the dimension number.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  const T &operator[](const std::size_t index) const {
    return this->m_components[index];
  }

  /**
   * Sets a certain component of the vector given the dimension number.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  T &operator[](const std::size_t index) { return this->m_components[index]; }

  /**
   * Gets a certain component of the vector given the dimension number.
   *
   * Throws an out_of_range exception if given number is out of bounds.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  const T &at(const std::size_t index) const {
    return this->m_components.at(index);
  }

  /**
   * Sets a certain component of the vector given the dimension number.
   *
   * Throws an out_of_range exception if given number is out of bounds.
   *
   * @param index The dimension number.
   *
   * @returns That dimension's component of the vector.
   */
  T &at(const std::size_t index) { return this->m_components.at(index); }

  /**
   * Converts the components in each dimension to a certain type
   * by putting the component into the type's constructor.
   *
   * @returns std::array of converted components.
   */
  template <typename newT>
  std::array<newT, dimensions> eachComponentAs() const {
    std::array<newT, dimensions> result;

    for (std::size_t i = 0; i < dimensions; i++) {
      result[i] = newT{this->m_components[i]};
    }

    return result;
  };

  iterator begin() noexcept { return iterator{this->m_components.begin()}; }
  const_iterator begin() const noexcept {
    return const_iterator{this->m_components.begin()};
  }
  iterator end() noexcept { return iterator{this->m_components.end()}; }
  const_iterator end() const noexcept {
    return const_iterator{this->m_components.end()};
  }

  reverse_iterator rbegin() noexcept {
    return reverse_iterator{this->m_components.rbegin()};
  }
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator{this->m_components.rbegin()};
  }
  reverse_iterator rend() noexcept {
    return reverse_iterator{this->m_components.rend()};
  }
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator{this->m_components.rend()};
  }

protected:
  std::array<T, dimensions> m_components;
};
// COMBINER_PY_END
} // namespace svector

#endif
