/**
 * @file embed.h
 *
 * A minimized version of vectors for embedded devices without access to the
 * STL (such as on an Arduino, hence the ".h" instead of ".hpp" and the lack of
 * a svector namespace). This file is meant to be a standalone file, so it is
 * not included in vectors.hpp.
 *
 * @copyright Copyright (c) 2022 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_EMBED_HPP_
#define INCLUDE_SVECTOR_EMBED_HPP_

#include <math.h> // atan2, cos, sin, sqrt

/**
 * A minimal 2D vector representation.
 */
struct EmbVec2D {
  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  EmbVec2D() : x(0), y(0){};

  /**
   * Initializes a vector given xy components.
   *
   * @param x_other The x-component.
   * @param y_other The y-component.
   */
  EmbVec2D(const double x_other, const double y_other)
      : x(x_other), y(y_other) {}

  /**
   * Copy constructor.
   */
  EmbVec2D(const EmbVec2D &other) : x(other.x), y(other.y) {}

  /**
   * Move constructor (uses C++ default move constructor)
   */
  EmbVec2D(EmbVec2D &&) noexcept = default;

  /**
   * Assignment operator.
   */
  EmbVec2D &operator=(const EmbVec2D &other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  /**
   * Move assignment operator (uses C++ default move assignment operator)
   */
  EmbVec2D &operator=(EmbVec2D &&) noexcept = default;

  /**
   * Destructor (uses C++ default destructor)
   */
  virtual ~EmbVec2D() = default;

  /**
   * Adds another vector object to current vector.
   *
   * @param other The other object to add.
   */
  EmbVec2D &operator+=(const EmbVec2D &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  /**
   * Subtracts another vector object from current vector.
   *
   * @param other The other object to subtract.
   */
  EmbVec2D &operator-=(const EmbVec2D &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /**
   * Performs scalar multiplication on the current object.
   *
   * @param other The number to multiply by.
   */
  EmbVec2D &operator*=(const double &other) {
    x *= other;
    y *= other;
    return *this;
  }

  /**
   * Performs scalar division on the current object.
   *
   * @param other The number to divide by.
   */
  EmbVec2D &operator/=(const double &other) {
    x /= other;
    y /= other;
    return *this;
  }

  double x; //!< The x-component of the 2D vector.
  double y; //!< The y-component of the 2D vector.
};

/**
 * A minimal 3D vector representation.
 */
struct EmbVec3D {
  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  EmbVec3D() : x(0), y(0), z(0) {}

  /**
   * Initializes a vector given xyz components.
   *
   * @param x_other The x-component.
   * @param y_other The y-component.
   * @param z_other The z-component.
   */
  EmbVec3D(const double x_other, const double y_other, const double z_other)
      : x(x_other), y(y_other), z(z_other) {}

  /**
   * Copy constructor.
   */
  EmbVec3D(const EmbVec3D &other) : x(other.x), y(other.y), z(other.z) {}

  /**
   * Move constructor (uses C++ default move constructor)
   */
  EmbVec3D(EmbVec3D &&) noexcept = default;

  /**
   * Assignment operator.
   */
  EmbVec3D &operator=(const EmbVec3D &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  /**
   * Move assignment operator (uses C++ default move assignment operator)
   */
  EmbVec3D &operator=(EmbVec3D &&) noexcept = default;

  /**
   * Destructor (uses C++ default destructor)
   */
  virtual ~EmbVec3D() = default;

  /**
   * Adds another vector object to current vector.
   *
   * @param other The other object to add.
   */
  EmbVec3D &operator+=(const EmbVec3D &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  /**
   * Subtracts another vector object from current vector.
   *
   * @param other The other object to subtract.
   */
  EmbVec3D &operator-=(const EmbVec3D &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  /**
   * Performs scalar multiplication on the current object.
   *
   * @param other The number to multiply by.
   */
  EmbVec3D &operator*=(const double &other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }

  /**
   * Performs scalar division on the current object.
   *
   * @param other The number to divide by.
   */
  EmbVec3D &operator/=(const double &other) {
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
 * Performs vector addition and returns a new vector representing the sum of
 * the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline EmbVec2D operator+(const EmbVec2D &lhs, const EmbVec2D &rhs) {
  return EmbVec2D{lhs.x + rhs.x, lhs.y + rhs.y};
}

/**
 * Performs vector subtraction and returns a new vector representing the
 * difference of the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline EmbVec2D operator-(const EmbVec2D &lhs, const EmbVec2D &rhs) {
  return EmbVec2D{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * Makes all components of a vector negative.
 *
 * This can also be thought of flipping the direction of the vector.
 *
 * @param vec A 2D vector
 *
 * @returns A new vector representing the negative of the given vector.
 */
inline EmbVec2D operator-(const EmbVec2D &vec) {
  return EmbVec2D{-vec.x, -vec.y};
}

/**
 * Performs scalar multiplication and returns a new vector representing the
 * product.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline EmbVec2D operator*(const EmbVec2D &lhs, const double rhs) {
  return EmbVec2D{lhs.x * rhs, lhs.y * rhs};
}

/**
 * Performs scalar division and returns a new vector representing the
 * quotient.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline EmbVec2D operator/(const EmbVec2D &lhs, const double rhs) {
  return EmbVec2D{lhs.x / rhs, lhs.y / rhs};
}

/**
 * Compares equality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors compare equal.
 */
inline bool operator==(const EmbVec2D &lhs, const EmbVec2D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

/**
 * Compares inequality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors do not compare equal.
 */
inline bool operator!=(const EmbVec2D &lhs, const EmbVec2D &rhs) {
  return !(lhs == rhs);
}

/**
 * Calculates the dot product of two vectors.
 *
 * @param lhs First vector.
 * @param rhs Second vector.
 *
 * @returns The dot product of lhs and rhs.
 */
inline double dot(const EmbVec2D &lhs, const EmbVec2D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

/**
 * Gets the magnitude of the vector.
 *
 * @param vec A 2D vector.
 *
 * @returns magnitude of vector.
 */
inline double magn(const EmbVec2D &vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y);
}

/**
 * Gets the angle of the vector in radians.
 *
 * The angle will be in the range (-π, π].
 *
 * @param vec A 2D vector.
 *
 * @returns angle of the vector.
 */
inline double angle(const EmbVec2D &vec) { return atan2(vec.y, vec.x); }

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @param vec A 2D vector.
 *
 * @returns Normalized vector.
 */
inline EmbVec2D normalize(const EmbVec2D &vec) { return vec / magn(vec); }

/**
 * Rotates vector by a certain angle.
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
inline EmbVec2D rotate(const EmbVec2D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // | cos(ang)   -sin(ang) | |x|
  // | sin(ang)    cos(ang) | |y|
  //

  double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
  double yPrime = vec.x * sin(ang) + vec.y * cos(ang);

  return EmbVec2D{xPrime, yPrime};
}

/**
 * Performs vector addition and returns a new vector representing the sum of
 * the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline EmbVec3D operator+(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  return EmbVec3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

/**
 * Performs vector subtraction and returns a new vector representing the
 * difference of the two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the vector sum.
 */
inline EmbVec3D operator-(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  return EmbVec3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

/**
 * Makes all components of a vector negative.
 *
 * This can also be thought of flipping the direction of the vector.
 *
 * @param vec A 3D vector
 *
 * @returns A new vector representing the negative of the given vector.
 */
inline EmbVec3D operator-(const EmbVec3D &vec) {
  return EmbVec3D{-vec.x, -vec.y, -vec.z};
}

/**
 * Performs scalar multiplication and returns a new vector representing the
 * product.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline EmbVec3D operator*(const EmbVec3D &lhs, const double rhs) {
  return EmbVec3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

/**
 * Performs scalar division and returns a new vector representing the
 * quotient.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A new vector representing the scalar product.
 */
inline EmbVec3D operator/(const EmbVec3D &lhs, const double rhs) {
  return EmbVec3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

/**
 * Compares equality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors compare equal.
 */
inline bool operator==(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

/**
 * Compares inequality of two vectors.
 *
 * @param lhs The first vector.
 * @param rhs The second vector.
 *
 * @returns A boolean representing whether the two vectors do not compare equal.
 */
inline bool operator!=(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  return !(lhs == rhs);
}

/**
 * Calculates the dot product of two vectors.
 *
 * @param lhs First vector.
 * @param rhs Second vector.
 *
 * @returns The dot product of lhs and rhs.
 */
inline double dot(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

/**
 * Cross product of two vectors.
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The crossed 3D vector.
 */
inline EmbVec3D cross(const EmbVec3D &lhs, const EmbVec3D &rhs) {
  double newx = lhs.y * rhs.z - lhs.z * rhs.y;
  double newy = lhs.z * rhs.x - lhs.x * rhs.z;
  double newz = lhs.x * rhs.y - lhs.y * rhs.x;

  return EmbVec3D{newx, newy, newz};
}

/**
 * Gets the magnitude of the vector.
 *
 * @param vec A 3D vector.
 *
 * @returns magnitude of vector
 */
inline double magn(const EmbVec3D &vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @param vec A 3D vector.
 *
 * @returns Normalized vector.
 */
inline EmbVec3D normalize(const EmbVec3D &vec) { return vec / magn(vec); }

/**
 * Gets α angle.
 *
 * α is the angle between the vector and the x-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns α.
 */
inline double getAlpha(const EmbVec3D &vec) { return acos(vec.x / magn(vec)); }

/**
 * Gets β angle.
 *
 * β is the angle between the vector and the y-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns β.
 */
inline double getBeta(const EmbVec3D &vec) { return acos(vec.y / magn(vec)); }

/**
 * Gets γ angle.
 *
 * γ is the angle between the vector and the z-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns γ.
 */
inline double getGamma(const EmbVec3D &vec) { return acos(vec.z / magn(vec)); }

/**
 * Rotates around x-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline EmbVec3D rotateAlpha(const EmbVec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |1   0           0     | |x|
  // |0  cos(ang)  −sin(ang)| |y|
  // |0  sin(ang)   cos(ang)| |z|
  //

  double xPrime = vec.x;
  double yPrime = vec.y * cos(ang) - vec.z * sin(ang);
  double zPrime = vec.y * sin(ang) + vec.z * cos(ang);

  return EmbVec3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around y-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline EmbVec3D rotateBeta(const EmbVec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // | cos(ang)  0  sin(ang)| |x|
  // |   0       1      0   | |y|
  // |−sin(ang)  0  cos(ang)| |z|
  //

  double xPrime = vec.x * cos(ang) + vec.z * sin(ang);
  double yPrime = vec.y;
  double zPrime = -vec.x * sin(ang) + vec.z * cos(ang);

  return EmbVec3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around z-axis.
 *
 * Uses the basic gimbal-like 3D rotation matrices for rotation.
 *
 * @param vec A 3D vector.
 * @param ang The angle to rotate the vector, in radians.
 *
 * @returns A new, rotated vector.
 */
inline EmbVec3D rotateGamma(const EmbVec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |cos(ang)  −sin(ang)  0| |x|
  // |sin(ang)  cos(ang)   0| |y|
  // |  0         0        1| |z|
  //

  double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
  double yPrime = vec.x * sin(ang) + vec.y * cos(ang);
  double zPrime = vec.z;

  return EmbVec3D{xPrime, yPrime, zPrime};
}

#endif