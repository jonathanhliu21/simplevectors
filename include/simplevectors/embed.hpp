/**
 * @file embed.hpp
 *
 * A minimized version of vectors for embedded devices with access to the STL.
 * This file is meant to be a standalone file, so it is not included in
 * vectors.hpp
 *
 * @copyright Copyright (c) 2022 Jonathan Liu. This project is released under
 * the MIT License. All rights reserved.
 */

#ifndef INCLUDE_SVECTOR_EMBED_HPP_
#define INCLUDE_SVECTOR_EMBED_HPP_

#include <cmath>  // std::atan2, std::cos, std::sin, std::sqrt
#include <string> // std::string

namespace svector {
/**
 * A minimal 2D vector representation.
 */
struct Vec2D {
  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vec2D() {
    x = 0;
    y = 0;
  };

  /**
   * Initializes a vector given xy components.
   *
   * @param x_other The x-component.
   * @param y_other The y-component.
   */
  Vec2D(const double x_other, const double y_other) {
    x = x_other;
    y = y_other;
  }

  /**
   * Copy constructor.
   */
  Vec2D(const Vec2D &other) {
    x = other.x;
    y = other.y;
  }

  /**
   * Assignment operator.
   */
  Vec2D &operator=(const Vec2D &other) {
    x = other.x;
    y = other.y;
    return *this;
  }

  /**
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
 * A minimal 3D vector representation.
 */
struct Vec3D {
  /**
   * No-argument constructor.
   *
   * Initializes a zero vector.
   */
  Vec3D() {
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
  Vec3D(const double x_other, const double y_other, const double z_other) {
    x = x_other;
    y = y_other;
    z = z_other;
  }

  /**
   * Copy constructor.
   */
  Vec3D(const Vec3D &other) {
    x = other.x;
    y = other.y;
    z = other.z;
  }

  /**
   * Assignment operator.
   */
  Vec3D &operator=(const Vec3D &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }

  /**
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
 * String form; can be used for printing.
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
 * Compares equality of two vectors.
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
 * Compares inequality of two vectors.
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
 * Calculates the dot product of two vectors.
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
 * Gets the magnitude of the vector.
 *
 * @param vec A 2D vector.
 *
 * @returns magnitude of vector.
 */
inline double magn(const Vec2D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y);
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
inline double angle(const Vec2D &vec) { return std::atan2(vec.y, vec.x); }

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @param vec A 2D vector.
 *
 * @returns Normalized vector.
 */
inline Vec2D normalize(const Vec2D &vec) {
  Vec2D tmp(vec);
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

  double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);

  return Vec2D{xPrime, yPrime};
}

/**
 * String form; can be used for printing.
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
 * Compares equality of two vectors.
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
 * Compares inequality of two vectors.
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
 * Calculates the dot product of two vectors.
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
 * Cross product of two vectors.
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The crossed 3D vector.
 */
inline Vec3D cross(const Vec3D &lhs, const Vec3D &rhs) {
  double newx = lhs.y * rhs.z - lhs.z * rhs.y;
  double newy = lhs.z * rhs.x - lhs.x * rhs.z;
  double newz = lhs.x * rhs.y - lhs.y * rhs.x;

  return Vec3D{newx, newy, newz};
}

/**
 * Gets the magnitude of the vector.
 *
 * @param vec A 3D vector.
 *
 * @returns magnitude of vector.
 */
inline double magn(const Vec3D &vec) {
  return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
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
inline Vec3D normalize(const Vec3D &vec) {
  Vec3D tmp(vec);
  return tmp / magn(vec);
}

/**
 * Gets α angle.
 *
 * α is the angle between the vector and the x-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns α.
 */
inline double getAlpha(const Vec3D &vec) {
  return std::acos(vec.x / magn(vec));
}

/**
 * Gets β angle.
 *
 * β is the angle between the vector and the y-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns β.
 */
inline double getBeta(const Vec3D &vec) { return std::acos(vec.y / magn(vec)); }

/**
 * Gets γ angle.
 *
 * γ is the angle between the vector and the z-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns γ.
 */
inline double getGamma(const Vec3D &vec) {
  return std::acos(vec.z / magn(vec));
}

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
inline Vec3D rotateAlpha(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |1   0           0     | |x|
  // |0  cos(ang)  −sin(ang)| |y|
  // |0  sin(ang)   cos(ang)| |z|
  //

  double xPrime = vec.x;
  double yPrime = vec.y * std::cos(ang) - vec.z * std::sin(ang);
  double zPrime = vec.y * std::sin(ang) + vec.z * std::cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
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
inline Vec3D rotateBeta(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // | cos(ang)  0  sin(ang)| |x|
  // |   0       1      0   | |y|
  // |−sin(ang)  0  cos(ang)| |z|
  //

  double xPrime = vec.x * std::cos(ang) + vec.z * std::sin(ang);
  double yPrime = vec.y;
  double zPrime = -vec.x * std::sin(ang) + vec.z * std::cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
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
inline Vec3D rotateGamma(const Vec3D &vec, const double ang) {
  //
  // Rotation matrix:
  //
  // |cos(ang)  −sin(ang)  0| |x|
  // |sin(ang)  cos(ang)   0| |y|
  // |  0         0        1| |z|
  //

  double xPrime = vec.x * std::cos(ang) - vec.y * std::sin(ang);
  double yPrime = vec.x * std::sin(ang) + vec.y * std::cos(ang);
  double zPrime = vec.z;

  return Vec3D{xPrime, yPrime, zPrime};
}
} // namespace svector

#endif
