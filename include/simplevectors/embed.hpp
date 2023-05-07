/**
 * @file embed.hpp
 *
 * @brief A minimized version of vectors for embedded devices with access to the
 STL.
 *
 * This file is meant to be a standalone file, so it is not included in
 * vectors.hpp.
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
 *
 * @copyright Copyright (c) 2023 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_EMBED_HPP_
#define INCLUDE_SVECTOR_EMBED_HPP_

#include <cmath>  // std::acos, std::atan2, std::cos, std::sin, std::sqrt
#include <string> // std::string

namespace svector {
/**
 * @brief A minimal 2D vector representation.
 */
struct Vec2D {
  /**
   * @brief No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vec2D() : x{0}, y{0} {};

  /**
   * @brief Initializes a vector given xy components.
   *
   * @param xOther The x-component.
   * @param yOther The y-component.
   */
  Vec2D(const double xOther, const double yOther) : x{xOther}, y{yOther} {}

  /**
   * @brief Copy constructor.
   */
  Vec2D(const Vec2D &other) = default;

  /**
   * @brief Move constructor.
   *
   * Uses C++ default move constructor.
   */
  Vec2D(Vec2D &&) noexcept = default;

  /**
   * @brief Assignment operator.
   */
  Vec2D &operator=(const Vec2D &other) {
    // check if assigning to self
    if (this == &other) {
      return *this;
    }

    x = other.x;
    y = other.y;
    return *this;
  }

  /**
   * @brief Move assignment operator
   *
   * Uses C++ default move assignment operator.
   */
  Vec2D &operator=(Vec2D &&) noexcept = default;

  /**
   * @brief Destructor
   *
   * Uses C++ default destructor.
   */
  virtual ~Vec2D() = default;

  /**
   * @brief In-place addtion
   *
   * Adds another vector object to current vector.
   *
   * @param other The other object to add.
   */
  Vec2D &operator+=(const Vec2D &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  /**
   * @brief In-place subtraction
   *
   * Subtracts another vector object from current vector.
   *
   * @param other The other object to subtract.
   */
  Vec2D &operator-=(const Vec2D &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /**
   * @brief In-place scalar multiplication
   *
   * Performs scalar multiplication on the current object.
   *
   * @param other The number to multiply by.
   */
  Vec2D &operator*=(const double &other) {
    x *= other;
    y *= other;
    return *this;
  }

  /**
   * @brief In-place scalar division
   *
   * Performs scalar division on the current object.
   *
   * @param other The number to divide by.
   */
  Vec2D &operator/=(const double &other) {
    x /= other;
    y /= other;
    return *this;
  }

  double x; //!< The x-component of the 2D vector.
  double y; //!< The y-component of the 2D vector.
};

/**
 * @brief A minimal 3D vector representation.
 */
struct Vec3D {
  /**
   * @brief No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vec3D() : x{0}, y{0}, z{0} {}

  /**
   * @brief Initializes a vector given xyz components.
   *
   * @param xOther The x-component.
   * @param yOther The y-component.
   * @param zOther The z-component.
   */
  Vec3D(const double xOther, const double yOther, const double zOther)
      : x{xOther}, y{yOther}, z{zOther} {}

  /**
   * @brief Copy constructor.
   */
  Vec3D(const Vec3D &other) = default;

  /**
   * @brief Move constructor
   *
   * Uses C++ default move constructor.
   */
  Vec3D(Vec3D &&) noexcept = default;

  /**
   * @brief Assignment operator.
   */
  Vec3D &operator=(const Vec3D &other) {
    // check if assigning to self
    if (this == &other) {
      return *this;
    }

    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  /**
   * @brief Move assignment operator
   *
   * Uses C++ default move assignment operator.
   */
  Vec3D &operator=(Vec3D &&) noexcept = default;

  /**
   * @brief Destructor
   *
   * Uses C++ default destructor.
   */
  virtual ~Vec3D() = default;

  /**
   * @brief In-place addtion
   *
   * Adds another vector object to current vector.
   *
   * @param other The other object to add.
   */
  Vec3D &operator+=(const Vec3D &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  /**
   * @brief In-place subtraction
   *
   * Subtracts another vector object from current vector.
   *
   * @param other The other object to subtract.
   */
  Vec3D &operator-=(const Vec3D &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  /**
   * @brief In-place scalar multiplication
   *
   * Performs scalar multiplication on the current object.
   *
   * @param other The number to multiply by.
   */
  Vec3D &operator*=(const double &other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }

  /**
   * @brief In-place scalar division
   *
   * Performs scalar division on the current object.
   *
   * @param other The number to divide by.
   */
  Vec3D &operator/=(const double &other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
  }

  double x; //!< The x-component of the 3D vector.
  double y; //!< The y-component of the 3D vector.
  double z; //!< The z-component of the 3D vector.
};

/**
 * @brief Gets the x-component of a 2D vector.
 *
 * @param v A 2D Vector.
 *
 * @returns x-component of the vector.
 */
inline double x(const Vec2D &v) { return v.x; }

/**
 * @brief Sets the x-component of a 2D vector.
 *
 * @param v A 2D Vector.
 * @param xValue The x-value to set to the vector.
 */
inline void x(Vec2D &v, const double xValue) { v.x = xValue; }

/**
 * @brief Gets the x-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns x-component of the vector.
 */
inline double x(const Vec3D &v) { return v.x; }

/**
 * @brief Sets the x-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param xValue The x-value to set to the vector.
 */
inline void x(Vec3D &v, const double xValue) { v.x = xValue; }

/**
 * @brief Gets the y-component of a 2D vector.
 *
 * @param v A 2D Vector.
 *
 * @returns y-component of the vector.
 */
inline double y(const Vec2D &v) { return v.y; }

/**
 * @brief Sets the y-component of a 2D vector.
 *
 * @param v A 2D Vector.
 * @param yValue The y-value to set to the vector.
 */
inline void y(Vec2D &v, const double yValue) { v.y = yValue; }

/**
 * @brief Gets the y-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns y-component of the vector.
 */
inline double y(const Vec3D &v) { return v.y; }

/**
 * @brief Sets the y-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param yValue The y value to set to the vector.
 */
inline void y(Vec3D &v, const double yValue) { v.y = yValue; }

/**
 * @brief Gets the z-component of a 3D vector.
 *
 * @param v A 3D Vector.
 *
 * @returns z-component of the vector.
 */
inline double z(const Vec3D &v) { return v.z; }

/**
 * @brief Sets the z-component of a 3D vector.
 *
 * @param v A 3D Vector.
 * @param zValue The z value to set to the vector.
 */
inline void z(Vec3D &v, const double zValue) { v.z = zValue; }

/**
 * @brief String form
 *
 * This can be used for printing.
 *
 * @param vec A 2D Vector.
 *
 * @returns string form of vector.
 */
inline std::string toString(const Vec2D &vec) {
  std::string s{"<"};
  s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ">";
  return s;
}

/**
 * @brief Vector addition
 *
 * Performs vector addition and returns a new vector representing the sum of
 * the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline Vec2D operator+(const Vec2D &lhs, const Vec2D &rhs) {
  return Vec2D{lhs.x + rhs.x, lhs.y + rhs.y};
}

/**
 * @brief Vector subtraction
 *
 * Performs vector subtraction and returns a new vector representing the
 * difference of the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline Vec2D operator-(const Vec2D &lhs, const Vec2D &rhs) {
  return Vec2D{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * @brief Negative of a vector
 *
 * Makes all components of a vector negative.
 *
 * This can also be thought of flipping the direction of the vector.
 *
 * @param vec A 2D vector
 *
 * @returns A new vector representing the negative of the given vector.
 */
inline Vec2D operator-(const Vec2D &vec) { return Vec2D{-vec.x, -vec.y}; }

/**
 * @brief Scalar multiplication
 *
 * Performs scalar multiplication and returns a new vector representing the
 * product.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline Vec2D operator*(const Vec2D &lhs, const double rhs) {
  return Vec2D{lhs.x * rhs, lhs.y * rhs};
}

/**
 * @brief Scalar division
 *
 * Performs scalar division and returns a new vector representing the
 * quotient.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline Vec2D operator/(const Vec2D &lhs, const double rhs) {
  return Vec2D{lhs.x / rhs, lhs.y / rhs};
}

/**
 * @brief Compares equality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors compare equal.
 */
inline bool operator==(const Vec2D &lhs, const Vec2D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

/**
 * @brief Compares inequality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors do not compare equal.
 */
inline bool operator!=(const Vec2D &lhs, const Vec2D &rhs) {
  return !(lhs == rhs);
}

/**
 * @brief Calculates the dot product of two vectors.
 *
 * @param lhs First vector.
 * @param rhs Second vector.
 *
 * @returns The dot product of lhs and rhs.
 */
inline double dot(const Vec2D &lhs, const Vec2D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

/**
 * @brief Gets the magnitude of the vector.
 *
 * @param vec A 2D vector.
 *
 * @returns magnitude of vector.
 */
inline double magn(const Vec2D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

/**
 * @brief Gets the angle of a 2D vector in radians.
 *
 * The angle will be in the range (-π, π].
 *
 * @param vec A 2D vector.
 *
 * @returns angle of the vector.
 */
inline double angle(const Vec2D &vec) { return std::atan2(vec.y, vec.x); }

/**
 * @brief Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @note This method will result in undefined behavior if the vector is a zero
 * vector (if the magnitude equals zero).
 *
 * @param vec A 2D vector.
 *
 * @returns Normalized vector.
 */
inline Vec2D normalize(const Vec2D &vec) { return vec / magn(vec); }

/**
 * @brief Determines whether a vector is a zero vector.
 *
 * @returns Whether the given vector is a zero vector.
 */
inline bool isZero(const Vec2D &vec) { return magn(vec) == 0; }

/**
 * @brief Rotates vector by a certain angle.
 *
 * The angle should be given in radians. The vector rotates
 * counterclockwise when the angle is positive and clockwise
 * when the angle is negative.
 *
 * @param vec A 2D vector.
 * @param ang the angle to rotate the vector, in radians.
 *
 * @returns a new, rotated vector.
 */
inline Vec2D rotate(const Vec2D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // | cos(ang)   -sin(ang) | |x|
  // | sin(ang)    cos(ang) | |y|
  //

  const double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  const double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);

  return Vec2D{xPrime, yPrime};
}

/**
 * @brief String form
 *
 * This can be used for printing.
 *
 * @param vec A 3D Vector.
 *
 * @returns string form of vector.
 */
inline std::string toString(const Vec3D &vec) {
  std::string s{"<"};
  s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ", " +
      std::to_string(vec.z) + ">";
  return s;
}

/**
 * @brief Vector addition
 *
 * Performs vector addition and returns a new vector representing the sum of
 * the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline Vec3D operator+(const Vec3D &lhs, const Vec3D &rhs) {
  return Vec3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

/**
 * @brief Vector subtraction
 *
 * Performs vector subtraction and returns a new vector representing the
 * difference of the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline Vec3D operator-(const Vec3D &lhs, const Vec3D &rhs) {
  return Vec3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

/**
 * @brief Negative of a vector
 *
 * Makes all components of a vector negative.
 *
 * This can also be thought of flipping the direction of the vector.
 *
 * @param vec A 3D vector
 *
 * @returns A new vector representing the negative of the given vector.
 */
inline Vec3D operator-(const Vec3D &vec) {
  return Vec3D{-vec.x, -vec.y, -vec.z};
}

/**
 * @brief Scalar multiplication
 *
 * Performs scalar multiplication and returns a new vector representing the
 * product.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline Vec3D operator*(const Vec3D &lhs, const double rhs) {
  return Vec3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

/**
 * @brief Scalar division
 *
 * Performs scalar division and returns a new vector representing the
 * quotient.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline Vec3D operator/(const Vec3D &lhs, const double rhs) {
  return Vec3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

/**
 * @brief Compares equality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors compare equal.
 */
inline bool operator==(const Vec3D &lhs, const Vec3D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

/**
 * @brief Compares inequality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors do not compare equal.
 */
inline bool operator!=(const Vec3D &lhs, const Vec3D &rhs) {
  return !(lhs == rhs);
}

/**
 * @brief Calculates the dot product of two vectors.
 *
 * @param lhs First vector.
 * @param rhs Second vector.
 *
 * @returns The dot product of lhs and rhs.
 */
inline double dot(const Vec3D &lhs, const Vec3D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

/**
 * @brief Cross product of two vectors.
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The crossed 3D vector.
 */
inline Vec3D cross(const Vec3D &lhs, const Vec3D &rhs) {
  const double newx = lhs.y * rhs.z - lhs.z * rhs.y;
  const double newy = lhs.z * rhs.x - lhs.x * rhs.z;
  const double newz = lhs.x * rhs.y - lhs.y * rhs.x;

  return Vec3D{newx, newy, newz};
}

/**
 * @brief Gets the magnitude of the vector.
 *
 * @param vec A 3D vector.
 *
 * @returns magnitude of vector.
 */
inline double magn(const Vec3D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/**
 * @brief Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @note This method will result in undefined behavior if the vector is a zero
 * vector (if the magnitude equals zero).
 *
 * @param vec A 3D vector.
 *
 * @returns Normalized vector.
 */
inline Vec3D normalize(const Vec3D &vec) { return vec / magn(vec); }

/**
 * @brief Determines whether a vector is a zero vector.
 *
 * @returns Whether the given vector is a zero vector.
 */
inline bool isZero(const Vec3D &vec) { return magn(vec) == 0; }

/**
 * @brief Gets α angle.
 *
 * α is the angle between the vector and the x-axis.
 *
 * @note This method will result in undefined behavior if the vector is a zero
 * vector (if the magnitude equals zero).
 *
 * @param vec A 3D Vector.
 *
 * @returns α.
 */
inline double alpha(const Vec3D &vec) { return std::acos(vec.x / magn(vec)); }

/**
 * @brief Gets β angle.
 *
 * β is the angle between the vector and the y-axis.
 *
 * @note This method will result in undefined behavior if the vector is a zero
 * vector (if the magnitude equals zero).
 *
 * @param vec A 3D Vector.
 *
 * @returns β.
 */
inline double beta(const Vec3D &vec) { return std::acos(vec.y / magn(vec)); }

/**
 * @brief Gets γ angle.
 *
 * γ is the angle between the vector and the z-axis.
 *
 * @note This method will result in undefined behavior if the vector is a zero
 * vector (if the magnitude equals zero).
 *
 * @param vec A 3D Vector.
 *
 * @returns γ.
 */
inline double gamma(const Vec3D &vec) { return std::acos(vec.z / magn(vec)); }

/**
 * @brief Rotates around x-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vec3D rotateAlpha(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |1   0           0     | |x|
  // |0  cos(ang)  −sin(ang)| |y|
  // |0  sin(ang)   cos(ang)| |z|
  //

  const double xPrime = vec.x;
  const double yPrime = vec.y * std::cos(ang) - vec.z * std::sin(ang);
  const double zPrime = vec.y * std::sin(ang) + vec.z * std::cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
}

/**
 * @brief Rotates around y-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vec3D rotateBeta(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // | cos(ang)  0  sin(ang)| |x|
  // |   0       1      0   | |y|
  // |−sin(ang)  0  cos(ang)| |z|
  //

  const double xPrime = vec.x * std::cos(ang) + vec.z * std::sin(ang);
  const double yPrime = vec.y;
  const double zPrime = -vec.x * std::sin(ang) + vec.z * std::cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
}

/**
 * @brief Rotates around z-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline Vec3D rotateGamma(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |cos(ang)  −sin(ang)  0| |x|
  // |sin(ang)  cos(ang)   0| |y|
  // |  0         0        1| |z|
  //

  const double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  const double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);
  const double zPrime = vec.z;

  return Vec3D{xPrime, yPrime, zPrime};
}
} // namespace svector

#endif
