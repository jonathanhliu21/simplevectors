/**
 * basevector.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_BASEVECTOR_HPP_
#define INCLUDE_SVECTOR_BASEVECTOR_HPP_

#include <algorithm>        // std::min
#include <array>            // std::array
#include <cmath>            // std::sqrt
#include <cstddef>          // std::size_t
#include <initializer_list> // std::initializer_list
#include <string>           // std::string, std::to_string

namespace svector {
// COMBINER_PY_START
/**
 * A base vector representation.
 */
template <std::size_t D, typename T = double> class Vector {
public:
  typedef typename std::array<T, D>::iterator iterator;
  typedef typename std::array<T, D>::const_iterator const_iterator;
  typedef typename std::array<T, D>::reverse_iterator reverse_iterator;
  typedef
      typename std::array<T, D>::const_reverse_iterator const_reverse_iterator;

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
      if (counter >= D) {
        break;
      }

      this->m_components[counter] = num;
      counter++;
    }
  }

  /**
   * Copy constructor.
   */
  Vector(const Vector<D> &other) {
    for (std::size_t i = 0; i < D; i++) {
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
    for (std::size_t i = 0; i < D - 1; i++) {
      str += std::to_string(this->m_components[i]);
      str += ", ";
    }

    str += std::to_string(this->m_components[D - 1]);
    str += ">";

    return str;
  }

  /**
   * Adds two vectors.
   */
  Vector<D> operator+(const Vector<D> &other) const {
    Vector<D> tmp;
    for (std::size_t i = 0; i < D; i++) {
      tmp[i] = this->m_components[i] + other[i];
    }

    return tmp;
  }

  /**
   * Subtracts two vectors.
   */
  Vector<D> operator-(const Vector<D> &other) const {
    Vector<D> tmp;
    for (std::size_t i = 0; i < D; i++) {
      tmp[i] = this->m_components[i] - other[i];
    }

    return tmp;
  }

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
   * Scalar multiplication of vector.
   */
  Vector<D> operator*(const T other) const {
    Vector<D> tmp;
    for (std::size_t i = 0; i < D; i++) {
      tmp[i] = this->m_components[i] * other;
    }

    return tmp;
  }

  /**
   * Scalar division of vector.
   */
  Vector<D> operator/(const T other) const {
    Vector<D> tmp;
    for (std::size_t i = 0; i < D; i++) {
      tmp[i] = this->m_components[i] / other;
    }

    return tmp;
  }

  /**
   * Equality
   */
  bool operator==(const Vector<D> &other) const {
    for (std::size_t i = 0; i < D; i++) {
      if (this->m_components[i] != other[i])
        return false;
    }

    return true;
  }

  /**
   * Inequality
   */
  bool operator!=(const Vector<D> &other) const { return !((*this) == other); }

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
   * Dot product of two vectors.
   *
   * Note that the dimensions of the other vector has the be the same
   * as the current one.
   *
   * @param other The other vector to dot current vector with.
   *
   * @returns The dot product of the two vectors.
   */
  T dot(const Vector<D> &other) const {
    T result = 0;

    for (std::size_t i = 0; i < D; i++) {
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
  Vector<D> normalize() const { return (*this) / this->magn(); }

  /**
   * Gets number of dimensions.
   *
   * @returns Number of dimensions.
   */
  std::size_t numDimensions() const { return D; }

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
  template <typename newT> std::array<newT, D> eachComponentAs() const {
    std::array<newT, D> result;

    for (std::size_t i = 0; i < D; i++) {
      result[i] = newT{this->m_components[i]};
    }

    return result;
  }

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
  std::array<T, D> m_components;

private:
  /**
   * Compares elements between vectors lexographically (IN DEVELOPMENT).
   *
   * Loops through components one by one, and for each component, if self
   * component is less than other component, then returns -1, if self component
   * is greater than other component, then returns 1, if all components are
   * equal, then returns 0.
   *
   * If self vector has fewer components, then returns -1, if other vector
   * has fewer components, returns 1.
   *
   * @param other The other vector to compare to
   *
   * @returns -1 if compares less, 0 if compares equal, and 1 if compares
   * greater
   */
  template <std::size_t D2, typename T2>
  int compare(const Vector<D2, T2> &other) const noexcept {
    std::size_t min_dim = std::min(D, D2);

    // check dimensions first
    if (D != D2) {
      return D < D2 ? -1 : 1;
    }

    // compare one by one
    for (std::size_t i = 0; i < min_dim; i++) {
      if (this->m_components[i] == other[i])
        continue;
      else if (this->m_components[i] < other[i])
        return -1;
      else
        return 1;
    }

    // means two vectors are equal
    return 0;
  }
};
// COMBINER_PY_END
} // namespace svector

#endif
