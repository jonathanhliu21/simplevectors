/**
 * embed.hpp
 *
 * A minimized version of vectors for embedded devices with access to the STL.
 * This file is meant to be a standalone file.
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_EMBED_HPP_
#define INCLUDE_SVECTOR_EMBED_HPP_

#include <cmath>  // std::atan2, std::cos, std::sin, std::sqrt
#include <string> // std::string

namespace svector {
/**
 * A minimal 2D vector representation.
 */
struct Vector2D {
  double x, y;

  /**
   * No-argument constructor
   *
   * Initializes a zero vector.
   */
  Vector2D() {
    x = 0;
    y = 0;
  };

  /**
   * Initializes a vector given xy components
   *
   * @param x_other The x-component
   * @param y_other The y-component
   */
  Vector2D(const double x_other, const double y_other) {
    x = x_other;
    y = y_other;
  }
  /**
   * Copy constructor
   */
  Vector2D(const Vector2D &other) {
    x = other.x;
    y = other.y;
  }

  /**
   * Adds another vector object to self
   */
  Vector2D &operator+=(const Vector2D &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  /**
   * Subtracts another vector object from self
   */
  Vector2D &operator-=(const Vector2D &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /**
   * Multiplies vector by a number
   */
  Vector2D &operator*=(const double &other) {
    x *= other;
    y *= other;
    return *this;
  }

  /**
   * Divides vector by a number
   */
  Vector2D &operator/=(const double &other) {
    x /= other;
    y /= other;
    return *this;
  }
};

/**
 * A minimal 3D vector representation.
 */
struct Vector3D {
  double x, y, z;

  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vector3D() {
    x = 0;
    y = 0;
    z = 0;
  }

  /**
   * Initializes a vector given xyz components.
   *
   * @param x_other The x-component.
   * @param y_other The y-component.
   * @param z_other The z-component.
   */
  Vector3D(const double x_other, const double y_other, const double z_other) {
    x = x_other;
    y = y_other;
    z = z_other;
  }

  /**
   * Copy constructor
   */
  Vector3D(const Vector3D &other) {
    x = other.x;
    y = other.y;
    z = other.z;
  }
};

/**
 * String form; can be used for printing
 *
 * @param vec A 2D Vector.
 *
 * @returns string form of vector
 */
inline std::string toString(Vector2D &vec) {
  std::string s{"<"};
  s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ">";
  return s;
}

/**
 * Adds two vectors
 */
inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs) {
  return Vector2D{lhs.x + rhs.x, lhs.y + rhs.y};
}

/**
 * Subtracts two vectors
 */
inline Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs) {
  return Vector2D{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * Flips direction of vector
 */
inline Vector2D operator-(const Vector2D &vec) {
  return Vector2D{-vec.x, -vec.y};
}

/**
 * Scalar multiplication of vector
 */
inline Vector2D operator*(const Vector2D &lhs, const double rhs) {
  return Vector2D{lhs.x * rhs, lhs.y * rhs};
}

/**
 * Scalar division of vector
 */
inline Vector2D operator/(const Vector2D &lhs, const double rhs) {
  return Vector2D{lhs.x / rhs, lhs.y / rhs};
}

/**
 * Equality
 */
inline bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

/**
 * Inequality
 */
inline bool operator!=(const Vector2D &lhs, const Vector2D &rhs) {
  return !(lhs == rhs);
}

/**
 * Dot product of two vectors
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The dotted 3D vector.
 */
inline double dot(const Vector2D &lhs, const Vector2D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

/**
 * Gets the magnitude of the vector
 *
 * @param vec A 2D vector.
 *
 * @returns magnitude of vector
 */
inline double magn(const Vector2D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

/**
 * Gets the angle of the vector in radians.
 *
 * The angle will be in the range (-π, π].
 *
 * @param vec A 2D vector.
 *
 * @returns angle of the vector
 */
inline double angle(const Vector2D &vec) { return std::atan2(vec.y, vec.x); }

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @param vec A 2D vector.
 *
 * @returns Normalized vector
 */
inline Vector2D normalize(const Vector2D &vec) {
  Vector2D tmp(vec);
  return tmp / magn(vec);
}

/**
 * Rotates vector by a certain angle.
 *
 * The angle should be given in radians. The vector rotates
 * counterclockwise when the angle is positive and clockwise
 * when the angle is negative.
 *
 * @param vec A 2D vector.
 * @param angle the angle to rotate the vector, in radians
 *
 * @returns a new, rotated vector
 */
inline Vector2D rotate(const Vector2D &vec, const double ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)   -sin(ang) | |x|
   * | sin(ang)    cos(ang) | |y|
   */

  double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);

  return Vector2D{xPrime, yPrime};
}

/**
 * String form; can be used for printing
 *
 * @param vec A 3D Vector.
 *
 * @returns string form of vector
 */
inline std::string toString(Vector3D &vec) {
  std::string s{"<"};
  s = s + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ", " +
      std::to_string(vec.z) + ">";
  return s;
}

/**
 * Adds two vectors
 */
inline Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs) {
  return Vector3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

/**
 * Subtracts two vectors
 */
inline Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs) {
  return Vector3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

/**
 * Flips direction of vector
 */
inline Vector3D operator-(const Vector3D &vec) {
  return Vector3D{-vec.x, -vec.y, -vec.z};
}

/**
 * Scalar multiplication of vector
 */
inline Vector3D operator*(const Vector3D &lhs, const double rhs) {
  return Vector3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

/**
 * Scalar division of vector
 */
inline Vector3D operator/(const Vector3D &lhs, const double rhs) {
  return Vector3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

/**
 * Equality
 */
inline bool operator==(const Vector3D &lhs, const Vector3D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

/**
 * Inequality
 */
inline bool operator!=(const Vector3D &lhs, const Vector3D &rhs) {
  return !(lhs == rhs);
}

/**
 * Dot product of two vectors
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The dotted 3D vector.
 */
inline double dot(const Vector3D &lhs, const Vector3D &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

/**
 * Cross product of two vectors
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The crossed 3D vector.
 */
inline Vector3D cross(const Vector3D &lhs, const Vector3D &rhs) {
  double newx = lhs.y * rhs.z - lhs.z * rhs.y;
  double newy = lhs.z * rhs.x - lhs.x * rhs.z;
  double newz = lhs.x * rhs.y - lhs.y * lhs.x;

  return Vector3D{newx, newy, newz};
}

/**
 * Gets the magnitude of the vector
 *
 * @param vec A 2D vector.
 *
 * @returns magnitude of vector
 */
inline double magn(const Vector3D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/**
 * Gets α angle
 *
 * α is the angle between the vector and the x-axis
 *
 * @param vec A 3D Vector.
 *
 * @returns α
 */
inline double getAlpha(const Vector3D &vec) {
  return std::acos(vec.x / magn(vec));
}

/**
 * Gets β angle
 *
 * β is the angle between the vector and the y-axis
 *
 * @param vec A 3D Vector.
 *
 * @returns β
 */
inline double getBeta(const Vector3D &vec) {
  return std::acos(vec.y / magn(vec));
}

/**
 * Gets γ angle
 *
 * γ is the angle between the vector and the z-axis
 *
 * @param vec A 3D Vector.
 *
 * @returns γ
 */
inline double getGamma(const Vector3D &vec) {
  return std::acos(vec.z / magn(vec));
}

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
inline Vector3D rotateAlpha(const Vector3D &vec, const double &ang) {
  /**
   * Rotation matrix:
   *
   * |1   0           0     | |x|
   * |0  cos(ang)  −sin(ang)| |y|
   * |0  sin(ang)   cos(ang)| |z|
   */

  double xPrime = vec.x;
  double yPrime = vec.y * std::cos(ang) - vec.z * std::sin(ang);
  double zPrime = vec.y * std::sin(ang) + vec.z * std::cos(ang);

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
inline Vector3D rotateBeta(const Vector3D &vec, const double &ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)  0  sin(ang)| |x|
   * |   0       1      0   | |y|
   * |−sin(ang)  0  cos(ang)| |z|
   */

  double xPrime = vec.x * std::cos(ang) + vec.z * std::sin(ang);
  double yPrime = vec.y;
  double zPrime = -vec.x * std::sin(ang) + vec.z * std::cos(ang);

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
inline Vector3D rotateGamma(const Vector3D &vec, const double &ang) {
  /**
   * Rotation matrix:
   *
   * |cos(ang)  −sin(ang)  0| |x|
   * |sin(ang)  cos(ang)   0| |y|
   * |  0         0        1| |z|
   */

  double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);
  double zPrime = vec.z;

  return Vector3D{xPrime, yPrime, zPrime};
}
} // namespace svector

#endif
