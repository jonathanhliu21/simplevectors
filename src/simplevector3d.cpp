/**
 * simplevector3d.cpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#include "simplevector3d.h"

namespace svector {
/**
 * No-argument constructor
 *
 * Initializes a zero vector.
 */
Vector3D::Vector3D() {
  this->m_x = 0;
  this->m_y = 0;
  this->m_z = 0;
}

/**
 * Initializes a vector given xyz components
 *
 * @param x The x-component
 * @param y The y-component
 * @param z The z-component
 */
Vector3D::Vector3D(const double x, const double y, const double z) {
  this->m_x = x;
  this->m_y = y;
  this->m_z = z;
}

/**
 * Copy constructor
 */
Vector3D::Vector3D(const Vector3D &other) {
  this->m_x = other.x();
  this->m_y = other.y();
  this->m_z = other.z();
}

/**
 * String form; can be used for printing
 *
 * @returns string form of vector
 */
std::string Vector3D::toString() {
  std::string s{"<"};
  s = s + std::to_string(this->m_x) + ", " + std::to_string(this->m_y) + ", " +
      std::to_string(this->m_z) + ">";
  return s;
}

/**
 * Adds two vectors
 */
Vector3D Vector3D::operator+(const Vector3D &other) const {
  return Vector3D{this->m_x + other.x(), this->m_y + other.y(),
                  this->m_z + other.z()};
}

/**
 * Subtracts two vectors
 */
Vector3D Vector3D::operator-(const Vector3D &other) const {
  return Vector3D{this->m_x - other.x(), this->m_y - other.y(),
                  this->m_z - other.z()};
}

/**
 * Flips direction of vector
 */
Vector3D Vector3D::operator-() const {
  return Vector3D{-this->m_x, -this->m_y, -this->m_z};
}

/**
 * Scalar multiplication of vector
 */
Vector3D Vector3D::operator*(const double other) const {
  return Vector3D{this->m_x * other, this->m_y * other, this->m_z * other};
}

/**
 * Dot product of two vectors
 */
double Vector3D::operator*(const Vector3D &other) const {
  return this->m_x * other.x() + this->m_y * other.y() + this->m_z + other.z();
}

/**
 * Cross product of two vectors
 */
Vector3D Vector3D::operator^(const Vector3D &other) const {
  double newx = this->m_y * other.z() - this->m_z * other.y();
  double newy = this->m_z * other.x() - this->m_x * other.z();
  double newz = this->m_x * other.y() - this->m_y * other.x();

  return Vector3D{newx, newy, newz};
}

/**
 * Scalar division of vector
 */
Vector3D Vector3D::operator/(const double other) const {
  return Vector3D{this->m_x / other, this->m_y / other, this->m_z / other};
}

/**
 * Equality
 */
bool Vector3D::operator==(const Vector3D &other) const {
  return this->m_x == other.x() && this->m_y == other.y() &&
         this->m_z == other.z();
}

/**
 * Inequality
 */
bool Vector3D::operator!=(const Vector3D &other) const {
  return !(this->m_x == other.x() && this->m_y == other.y() &&
           this->m_z == other.z());
}

/**
 * Adds another vector object to self
 */
Vector3D &Vector3D::operator+=(const Vector3D &other) {
  this->m_x += other.x();
  this->m_y += other.y();
  this->m_z += other.z();
  return *this;
}

/**
 * Subtracts another vector object from self
 */
Vector3D &Vector3D::operator-=(const Vector3D &other) {
  this->m_x -= other.x();
  this->m_y -= other.y();
  this->m_z -= other.z();
  return *this;
}

/**
 * Multiplies vector by a number
 */
Vector3D &Vector3D::operator*=(const double &other) {
  this->m_x *= other;
  this->m_y *= other;
  this->m_z *= other;
  return *this;
}

/**
 * Divides vector by a number
 */
Vector3D &Vector3D::operator/=(const double &other) {
  this->m_x /= other;
  this->m_y /= other;
  this->m_z /= other;
  return *this;
}

/**
 * Gets the x-component of the vector
 *
 * @returns x-component of vector
 */
double Vector3D::x() const { return this->m_x; }

/**
 * Gets the y-component of the vector
 *
 * @returns y-component of vector
 */
double Vector3D::y() const { return this->m_y; }

/**
 * Gets the z-component of the vector
 *
 * @returns z-component of vector
 */
double Vector3D::z() const { return this->m_z; }

/**
 * Gets the magnitude of the vector
 *
 * @returns magnitude of vector
 */
double Vector3D::magn() const {
  return std::sqrt(this->m_x * this->m_x + this->m_y * this->m_y +
                   this->m_z * this->m_z);
}

/**
 * Normalizes a vector.
 *
 * Finds the unit vector with the same direction angle as the current vector.
 *
 * @returns Normalized vector
 */
Vector3D Vector3D::normalize() const {
  Vector3D tmp(*this);
  return tmp / this->magn();
}

/**
 * Gets α angle
 *
 * α is the angle between the vector and the x-axis
 *
 * @returns α
 */
double Vector3D::getAlpha() const {
  return std::acos(this->m_x / this->magn());
}

/**
 * Gets β angle
 *
 * β is the angle between the vector and the y-axis
 *
 * @returns β
 */
double Vector3D::getBeta() const { return std::acos(this->m_y / this->magn()); }

/**
 * Gets γ angle
 *
 * γ is the angle between the vector and the z-axis
 *
 * @returns γ
 */
double Vector3D::getGamma() const {
  return std::acos(this->m_z / this->magn());
}

/**
 * Rotates around x-axis
 */
Vector3D Vector3D::rotateAlpha(const double &ang) const {
  /**
   * Rotation matrix:
   *
   * |1   0           0     | |x|
   * |0  cos(ang)  −sin(ang)| |y|
   * |0  sin(ang)   cos(ang)| |z|
   */

  double xPrime = this->m_x;
  double yPrime = this->m_y * std::cos(ang) - this->m_z * std::sin(ang);
  double zPrime = this->m_z * std::sin(ang) + this->m_z * std::cos(ang);

  return Vector3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around y-axis
 */
Vector3D Vector3D::rotateBeta(const double &ang) const {
  /**
   * Rotation matrix:
   *
   * | cos(ang)  0  sin(ang)| |x|
   * |   0       1      0   | |y|
   * |−sin(ang)  0  cos(ang)| |z|
   */

  double xPrime = this->m_x * std::cos(ang) + this->m_z * std::sin(ang);
  double yPrime = this->m_y;
  double zPrime = -this->m_x * std::sin(ang) + this->m_z * std::cos(ang);

  return Vector3D{xPrime, yPrime, zPrime};
}

/**
 * Rotates around z-axis
 */
Vector3D Vector3D::rotateGamma(const double &ang) const {
  /**
   * Rotation matrix:
   *
   * |cos(ang)  −sin(ang)  0| |x|
   * |sin(ang)  cos(ang)   0| |y|
   * |  0         0        1| |z|
   */

  double xPrime = this->m_x * std::cos(ang) - this->m_y * std::sin(ang);
  double yPrime = this->m_x * std::sin(ang) + this->m_y * std::cos(ang);
  double zPrime = this->m_z;

  return Vector3D{xPrime, yPrime, zPrime};
}
} // namespace svector
