/**
 * simplevector2d.cpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#include "simplevector2d.h"

namespace svector {
// COMBINER_PY_STARTCPP_1
/**
 * No-argument constructor
 *
 * Initializes a zero vector.
 */
Vector2D::Vector2D() {
  this->m_x = 0;
  this->m_y = 0;
}

/**
 * Initializes a vector given xy components
 *
 * @param x The x-component
 * @param y The y-component
 */
Vector2D::Vector2D(const double x, const double y) {
  this->m_x = x;
  this->m_y = y;
}

/**
 * Copy constructor
 */
Vector2D::Vector2D(const Vector2D &other) {
  this->m_x = other.x();
  this->m_y = other.y();
}

/**
 * String form; can be used for printing
 *
 * @returns string form of vector
 */
std::string Vector2D::toString() {
  std::string s{"<"};
  s = s + std::to_string(this->m_x) + ", " + std::to_string(this->m_y) + ">";
  return s;
}

/**
 * Adds two vectors
 */
Vector2D Vector2D::operator+(const Vector2D &other) const {
  return Vector2D{this->m_x + other.x(), this->m_y + other.y()};
}

/**
 * Subtracts two vectors
 */
Vector2D Vector2D::operator-(const Vector2D &other) const {
  return Vector2D{this->m_x - other.x(), this->m_y - other.y()};
}

/**
 * Flips direction of vector
 */
Vector2D Vector2D::operator-() const {
  return Vector2D{-this->m_x, -this->m_y};
}

/**
 * Scalar multiplication of vector
 */
Vector2D Vector2D::operator*(const double other) const {
  return Vector2D{this->m_x * other, this->m_y * other};
}

/**
 * Dot product of two vectors
 */
double Vector2D::operator*(const Vector2D &other) const {
  return this->m_x * other.x() + this->m_y * other.y();
}

/**
 * Scalar division of vector
 */
Vector2D Vector2D::operator/(const double other) const {
  return Vector2D{this->m_x / other, this->m_y / other};
}

/**
 * Equality
 */
bool Vector2D::operator==(const Vector2D &other) const {
  return this->m_x == other.x() && this->m_y == other.y();
}

/**
 * Inequality
 */
bool Vector2D::operator!=(const Vector2D &other) const {
  return !(this->m_x == other.x() && this->m_y == other.y());
}

/**
 * Adds another vector object to self
 */
Vector2D &Vector2D::operator+=(const Vector2D &other) {
  this->m_x += other.x();
  this->m_y += other.y();
  return *this;
}

/**
 * Subtracts another vector object from self
 */
Vector2D &Vector2D::operator-=(const Vector2D &other) {
  this->m_x -= other.x();
  this->m_y -= other.y();
  return *this;
}

/**
 * Multiplies vector by a number
 */
Vector2D &Vector2D::operator*=(const double &other) {
  this->m_x *= other;
  this->m_y *= other;
  return *this;
}

/**
 * Divides vector by a number
 */
Vector2D &Vector2D::operator/=(const double &other) {
  this->m_x /= other;
  this->m_y /= other;
  return *this;
}

/**
 * Gets the x-component of the vector
 *
 * @returns x-component of vector
 */
double Vector2D::x() const { return this->m_x; }

/**
 * Gets the y-component of the vector
 *
 * @returns y-component of vector
 */
double Vector2D::y() const { return this->m_y; }

/**
 * Gets the magnitude of the vector
 *
 * @returns magnitude of vector
 */
double Vector2D::magn() const {
  return std::sqrt(this->m_x * this->m_x + this->m_y * this->m_y);
}

/**
 * Gets the angle of the vector in radians.
 *
 * The angle will be in the range (-π, π].
 *
 * @returns angle of the vector
 */
double Vector2D::angle() const { return std::atan2(this->m_y, this->m_x); }

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @returns Normalized vector
 */
Vector2D Vector2D::normalize() const {
  Vector2D tmp(*this);
  return tmp / this->magn();
}

/**
 * Rotates vector by a certain angle.
 *
 * The angle should be given in radians. The vector rotates
 * counterclockwise when the angle is positive and clockwise
 * when the angle is negative.
 *
 * @param angle the angle to rotate the vector, in radians
 *
 * @returns a new, rotated vector
 */
Vector2D Vector2D::rotate(const double ang) const {
  /**
   * Rotation matrix:
   *
   * | cos(ang)   -sin(ang) | |x|
   * | sin(ang)    cos(ang) | |y|
   */

  double xPrime = this->m_x * std::cos(ang) - this->m_y * std::sin(ang);
  double yPrime = this->m_x * std::sin(ang) + this->m_y * std::cos(ang);

  return Vector2D{xPrime, yPrime};
}
// COMBINER_PY_ENDCPP_1
} // namespace svector
