/**
 * embed.h
 *
 * A minimized version of vectors for embedded devices without access to the
 * STL (such as on an Arduino, hence the ".h" instead of ".hpp" and the lack of
 * a svector namespace). This file is meant to be a standalone file, so it is
 * not included in vectors.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_EMBED_HPP_
#define INCLUDE_SVECTOR_EMBED_HPP_

#include <math.h>

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
   * Adds another vector object to self.
   */
  Vec2D &operator+=(const Vec2D &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  /**
   * Subtracts another vector object from self.
   */
  Vec2D &operator-=(const Vec2D &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /**
   * Multiplies vector by a number.
   */
  Vec2D &operator*=(const double &other) {
    x *= other;
    y *= other;
    return *this;
  }

  /**
   * Divides vector by a number.
   */
  Vec2D &operator/=(const double &other) {
    x /= other;
    y /= other;
    return *this;
  }

  double x, y;
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
   * Adds another vector object to self.
   */
  Vec3D &operator+=(const Vec3D &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  /**
   * Subtracts another vector object from self.
   */
  Vec3D &operator-=(const Vec3D &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  /**
   * Multiplies vector by a number.
   */
  Vec3D &operator*=(const double &other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }

  /**
   * Divides vector by a number.
   */
  Vec3D &operator/=(const double &other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
  }

  double x, y, z;
};

/**
 * Adds two vectors.
 */
inline Vec2D operator+(const Vec2D &lhs, const Vec2D &rhs) {
  return Vec2D{lhs.x + rhs.x, lhs.y + rhs.y};
}

/**
 * Subtracts two vectors.
 */
inline Vec2D operator-(const Vec2D &lhs, const Vec2D &rhs) {
  return Vec2D{lhs.x - rhs.x, lhs.y - rhs.y};
}

/**
 * Flips direction of vector.
 */
inline Vec2D operator-(const Vec2D &vec) { return Vec2D{-vec.x, -vec.y}; }

/**
 * Scalar multiplication of vector.
 */
inline Vec2D operator*(const Vec2D &lhs, const double rhs) {
  return Vec2D{lhs.x * rhs, lhs.y * rhs};
}

/**
 * Scalar division of vector.
 */
inline Vec2D operator/(const Vec2D &lhs, const double rhs) {
  return Vec2D{lhs.x / rhs, lhs.y / rhs};
}

/**
 * Equality.
 */
inline bool operator==(const Vec2D &lhs, const Vec2D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

/**
 * Inequality.
 */
inline bool operator!=(const Vec2D &lhs, const Vec2D &rhs) {
  return !(lhs == rhs);
}

/**
 * Dot product of two vectors.
 *
 * @param lhs A 2D vector.
 * @param rhs A 2D vector.
 *
 * @returns The dotted 2D vector.
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
inline double angle(const Vec2D &vec) { return atan2(vec.y, vec.x); }

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
 * @param angle the angle to rotate the vector, in radians.
 *
 * @returns a new, rotated vector.
 */
inline Vec2D rotate(const Vec2D &vec, const double ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)   -sin(ang) | |x|
   * | sin(ang)    cos(ang) | |y|
   */

  double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
  double yPrime = vec.x * sin(ang) + vec.y * cos(ang);

  return Vec2D{xPrime, yPrime};
}

/**
 * Adds two vectors.
 */
inline Vec3D operator+(const Vec3D &lhs, const Vec3D &rhs) {
  return Vec3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

/**
 * Subtracts two vectors.
 */
inline Vec3D operator-(const Vec3D &lhs, const Vec3D &rhs) {
  return Vec3D{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}

/**
 * Flips direction of vector.
 */
inline Vec3D operator-(const Vec3D &vec) {
  return Vec3D{-vec.x, -vec.y, -vec.z};
}

/**
 * Scalar multiplication of vector.
 */
inline Vec3D operator*(const Vec3D &lhs, const double rhs) {
  return Vec3D{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
}

/**
 * Scalar division of vector.
 */
inline Vec3D operator/(const Vec3D &lhs, const double rhs) {
  return Vec3D{lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
}

/**
 * Equality.
 */
inline bool operator==(const Vec3D &lhs, const Vec3D &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

/**
 * Inequality.
 */
inline bool operator!=(const Vec3D &lhs, const Vec3D &rhs) {
  return !(lhs == rhs);
}

/**
 * Dot product of two vectors.
 *
 * @param lhs A 3D vector.
 * @param rhs A 3D vector.
 *
 * @returns The dotted 3D vector.
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
 * @returns magnitude of vector
 */
inline double magn(const Vec3D &vec) {
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
inline double getAlpha(const Vec3D &vec) { return acos(vec.x / magn(vec)); }

/**
 * Gets β angle.
 *
 * β is the angle between the vector and the y-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns β.
 */
inline double getBeta(const Vec3D &vec) { return acos(vec.y / magn(vec)); }

/**
 * Gets γ angle.
 *
 * γ is the angle between the vector and the z-axis.
 *
 * @param vec A 3D Vector.
 *
 * @returns γ.
 */
inline double getGamma(const Vec3D &vec) { return acos(vec.z / magn(vec)); }

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
inline Vec3D rotateAlpha(const Vec3D &vec, const double ang) {
  /**
   * Rotation matrix:
   *
   * |1   0           0     | |x|
   * |0  cos(ang)  −sin(ang)| |y|
   * |0  sin(ang)   cos(ang)| |z|
   */

  double xPrime = vec.x;
  double yPrime = vec.y * cos(ang) - vec.z * sin(ang);
  double zPrime = vec.y * sin(ang) + vec.z * cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
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
inline Vec3D rotateBeta(const Vec3D &vec, const double ang) {
  /**
   * Rotation matrix:
   *
   * | cos(ang)  0  sin(ang)| |x|
   * |   0       1      0   | |y|
   * |−sin(ang)  0  cos(ang)| |z|
   */

  double xPrime = vec.x * cos(ang) + vec.z * sin(ang);
  double yPrime = vec.y;
  double zPrime = -vec.x * sin(ang) + vec.z * cos(ang);

  return Vec3D{xPrime, yPrime, zPrime};
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
inline Vec3D rotateGamma(const Vec3D &vec, const double ang) {
  /**
   * Rotation matrix:
   *
   * |cos(ang)  −sin(ang)  0| |x|
   * |sin(ang)  cos(ang)   0| |y|
   * |  0         0        1| |z|
   */

  double xPrime = vec.x * cos(ang) - vec.y * sin(ang);
  double yPrime = vec.x * sin(ang) + vec.y * cos(ang);
  double zPrime = vec.z;

  return Vec3D{xPrime, yPrime, zPrime};
}

#endif
