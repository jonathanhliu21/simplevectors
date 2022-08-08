/**
 * simplevector2d.h
 *
 * Copyright (c) 2022 Jonathan Liu. All rights reserved.
 * MIT License
 */

#ifndef SIMPLEVECTOR2D_H
#define SIMPLEVECTOR2D_H

#include <cmath>
#include <string>

#include "units.h"

namespace svector {
/**
 * A simple 2D vector representation
 */
class Vector2D {
public:
  Vector2D();
  Vector2D(const double x, const double y);
  Vector2D(const Vector2D &other);

  std::string toString();

  Vector2D operator+(const Vector2D &other) const;
  Vector2D operator-() const;
  Vector2D operator-(const Vector2D &other) const;
  Vector2D operator*(const double other) const;
  double operator*(const Vector2D &other) const;
  Vector2D operator/(const double other) const;
  bool operator==(const Vector2D &other) const;
  bool operator!=(const Vector2D &other) const;

  Vector2D &operator+=(const Vector2D &other);
  Vector2D &operator-=(const Vector2D &other);
  Vector2D &operator*=(const double &other);
  Vector2D &operator/=(const double &other);

  double x() const;
  double y() const;
  double magn() const;
  double angle() const;

  template <typename T> T componentsAs() const;

  Vector2D normalize() const;
  Vector2D rotate(const double ang) const;

private:
  double m_x;
  double m_y;
};

/**
 * Converts components of vector to an object with a constructor
 * that has two parameters.
 *
 * For example, this method can be used to convert the components of
 * a 2D vector into a `pair<double, double>`, or a struct with two
 * variables and a constructor for those two variables.
 *
 * @returns Converted value
 */
template <typename T> T Vector2D::componentsAs() const {
  return T{this->m_x, this->m_y};
}
} // namespace svector

#endif
