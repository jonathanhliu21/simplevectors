/**
 * simplevector3d.h
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef SIMPLEVECTOR3D_H
#define SIMPLEVECTOR3D_H

#include <cmath>
#include <string>

#include "units.h"

namespace svector {
/**
 * A simple 3D vector representation
 */
class Vector3D {
public:
  Vector3D();
  Vector3D(const double x, const double y, const double z);
  Vector3D(const Vector3D &other);

  std::string toString();

  Vector3D operator+(const Vector3D &other) const;
  Vector3D operator-() const;
  Vector3D operator-(const Vector3D &other) const;
  Vector3D operator*(const double other) const;
  double operator*(const Vector3D &other) const;
  Vector3D operator^(const Vector3D &other) const;
  Vector3D operator/(const double other) const;
  bool operator==(const Vector3D &other) const;
  bool operator!=(const Vector3D &other) const;

  Vector3D &operator+=(const Vector3D &other);
  Vector3D &operator-=(const Vector3D &other);
  Vector3D &operator*=(const double &other);
  Vector3D &operator/=(const double &other);

  double x() const;
  double y() const;
  double z() const;
  double magn() const;
  template <AngleDir D> double angle() const;

  template <typename T> T componentsAs() const;
  template <typename T> T anglesAs() const;

  Vector3D normalize() const;
  template <AngleDir D> Vector3D rotate(const double &ang) const;

private:
  double m_x;
  double m_y;
  double m_z;

  double getAlpha() const;
  double getBeta() const;
  double getGamma() const;

  Vector3D rotateAlpha(const double &ang) const;
  Vector3D rotateBeta(const double &ang) const;
  Vector3D rotateGamma(const double &ang) const;
};

/**
 * Converts components of vector to an object with a constructor that
 * has three parameters.
 *
 * For example, this method can be used to convert the components
 * of a 3D vector into a struct with three variables and a
 * constructor for those three variables.
 *
 * @returns Converted value
 */
template <typename T> T Vector3D::componentsAs() const {
  return T{this->m_x, this->m_y, this->m_z};
}

/**
 * Converts angles of vector to an object with a constructor that
 * has three parameters.
 *
 * For example, this method can be used to convert the angles
 * of a 3D vector into a struct with three variables and a
 * constructor for those three variables.
 *
 * @returns Converted value
 */
template <typename T> T Vector3D::anglesAs() const {
  return T{this->getAlpha(), this->getBeta(), this->getGamma()};
}

/**
 * Gets a specific angle of the vector.
 *
 * Can get angle to x-axis (svector::ALPHA), to y-axis
 * (svector::BETA),or to z-axis (svector::GAMMA).
 *
 * Each angle is in the range [0, π].
 *
 * @param D The angle direction to return
 */
template <AngleDir D> double Vector3D::angle() const {
  if (D == ALPHA)
    return this->getAlpha();
  else if (D == BETA)
    return this->getBeta();
  else
    return this->getGamma();
}

/**
 * Rotates vector around a certain axis by a certain angle.
 *
 * When given template is ALPHA, rotates around x-axis,
 * when given template is BETA, rotates around y-axis,
 * and when given template is GAMMA, rotates around z-axis.
 *
 * The angle should be given in radians. The vector rotates
 * counterclockwise when the angle is positive and clockwise
 * when the angle is negative.
 *
 * @param angle the angle to rotate the vector, in radians
 *
 * @returns a new, rotated vector
 */
template <AngleDir D> Vector3D Vector3D::rotate(const double &ang) const {
  if (D == ALPHA)
    return this->rotateAlpha(ang);
  else if (D == BETA)
    return this->rotateBeta(ang);
  else
    return this->rotateGamma(ang);
};
} // namespace svector

#endif
