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
} // namespace svector

#endif
