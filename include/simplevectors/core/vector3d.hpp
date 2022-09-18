/**
 * vector3d.hpp
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef INCLUDE_SVECTOR_VECTOR3D_HPP_
#define INCLUDE_SVECTOR_VECTOR3D_HPP_

#include "units.hpp"  // svector::AngleDir
#include "vector.hpp" // svector::Vector

#include <cmath> // std::acos, std::cos, std::sin

namespace svector {
// COMBINER_PY_START

typedef Vector<3> _Vec3;

/**
 * A simple 3D vector representation.
 */
class Vector3D : public _Vec3 {
public:
  using _Vec3::Vector;

  /**
   * Initializes a vector given xyz components.
   *
   * @param x The x-component.
   * @param y The y-component.
   * @param z The z-component.
   */
  Vector3D(const double x, const double y, const double z) {
    this->m_components[0] = x;
    this->m_components[1] = y;
    this->m_components[2] = z;
  }

  /**
   * Copy constructor for base class.
   */
  Vector3D(const _Vec3 &other) {
    this->m_components[0] = other[0];
    this->m_components[1] = other[1];
    this->m_components[2] = other[2];
  }

  /**
   * Gets the x-component of the vector.
   *
   * @returns x-component of vector.
   */
  double x() const { return this->m_components[0]; }

  /**
   * Gets the y-component of the vector.
   *
   * @returns y-component of vector.
   */
  double y() const { return this->m_components[1]; }

  /**
   * Gets the z-component of the vector.
   *
   * @returns z-component of vector.
   */
  double z() const { return this->m_components[2]; }

  /**
   * Cross product of two vectors.
   *
   * Note that the dimensions of the other vector has the be the same
   * as the current one.
   *
   * @param other The other vector to cross current vector with.
   *
   * @returns The cross product of the two vectors.
   */
  Vector3D cross(const Vector3D &other) const {
    double newx = this->y() * other.z() - this->z() * other.y();
    double newy = this->z() * other.x() - this->x() * other.z();
    double newz = this->x() * other.y() - this->y() * other.x();

    return Vector3D{newx, newy, newz};
  }

  /**
   * Converts components of vector to an object with a constructor
   * that has two parameters.
   *
   * For example, this method can be used to convert the components of
   * a 2D vector into a `pair<double, double>`, or a struct with two
   * variables and a constructor for those two variables.
   *
   * @returns Converted value.
   */
  template <typename T> T componentsAs() const {
    return T{this->x(), this->y(), this->z()};
  }

  /**
   * Converts angles of vector to an object with a constructor that
   * has three parameters.
   *
   * For example, this method can be used to convert the angles
   * of a 3D vector into a struct with three variables and a
   * constructor for those three variables.
   *
   * @returns Converted value.
   */
  template <typename T> T anglesAs() const {
    return T{this->getAlpha(), this->getBeta(), this->getGamma()};
  }

  /**
   * Gets a specific angle of the vector.
   *
   * Can get angle to x-axis (svector::ALPHA), to y-axis
   * (svector::BETA),or to z-axis (svector::GAMMA).
   *
   * Each angle is in the range [0, π]. Angle will be in radians.
   *
   * @param D The angle direction to return.
   */
  template <AngleDir D> double angle() const {
    switch (D) {
    case ALPHA:
      return this->getAlpha();
    case BETA:
      return this->getBeta();
    default:
      return this->getGamma();
    }
  }

  /**
   * Rotates vector around a certain axis by a certain angle.
   *
   * When given template is ALPHA, rotates around x-axis,
   * when given template is BETA, rotates around y-axis,
   * and when given template is GAMMA, rotates around z-axis.
   *
   * Uses the basic gimbal-like 3D rotation matrices for the
   * x-axis, y-axis, and the z-axis.
   *
   * @param angle the angle to rotate the vector, in radians.
   *
   * @returns a new, rotated vector.
   */
  template <AngleDir D> Vector3D rotate(const double &ang) const {
    switch (D) {
    case ALPHA:
      return this->rotateAlpha(ang);
    case BETA:
      return this->rotateBeta(ang);
    default:
      return this->rotateGamma(ang);
    }
  };

private:
  /**
   * Gets α angle.
   *
   * α is the angle between the vector and the x-axis.
   *
   * @returns α
   */
  double getAlpha() const { return std::acos(this->x() / this->magn()); }

  /**
   * Gets β angle.
   *
   * β is the angle between the vector and the y-axis.
   *
   * @returns β
   */
  double getBeta() const { return std::acos(this->y() / this->magn()); }

  /**
   * Gets γ angle.
   *
   * γ is the angle between the vector and the z-axis.
   *
   * @returns γ
   */
  double getGamma() const { return std::acos(this->z() / this->magn()); }

  /**
   * Rotates around x-axis.
   */
  Vector3D rotateAlpha(const double &ang) const {
    /**
     * Rotation matrix:
     *
     * |1   0           0     | |x|
     * |0  cos(ang)  −sin(ang)| |y|
     * |0  sin(ang)   cos(ang)| |z|
     */

    double xPrime = this->x();
    double yPrime = this->y() * std::cos(ang) - this->z() * std::sin(ang);
    double zPrime = this->y() * std::sin(ang) + this->z() * std::cos(ang);

    return Vector3D{xPrime, yPrime, zPrime};
  }

  /**
   * Rotates around y-axis.
   */
  Vector3D rotateBeta(const double &ang) const {
    /**
     * Rotation matrix:
     *
     * | cos(ang)  0  sin(ang)| |x|
     * |   0       1      0   | |y|
     * |−sin(ang)  0  cos(ang)| |z|
     */

    double xPrime = this->x() * std::cos(ang) + this->z() * std::sin(ang);
    double yPrime = this->y();
    double zPrime = -this->x() * std::sin(ang) + this->z() * std::cos(ang);

    return Vector3D{xPrime, yPrime, zPrime};
  }

  /**
   * Rotates around z-axis.
   */
  Vector3D rotateGamma(const double &ang) const {
    /**
     * Rotation matrix:
     *
     * |cos(ang)  −sin(ang)  0| |x|
     * |sin(ang)  cos(ang)   0| |y|
     * |  0         0        1| |z|
     */

    double xPrime = this->x() * std::cos(ang) - this->y() * std::sin(ang);
    double yPrime = this->x() * std::sin(ang) + this->y() * std::cos(ang);
    double zPrime = this->z();

    return Vector3D{xPrime, yPrime, zPrime};
  }
};
// COMBINER_PY_END
} // namespace svector

#endif
