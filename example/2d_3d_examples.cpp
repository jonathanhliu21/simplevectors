#include "simplevectors/vectors.hpp"

#include <cmath>
#include <utility>

namespace svector_2d_3d_examples {
/**
 * Determines the angle between two vectors
 */
double angleBetween(svector::Vector2D v1, svector::Vector2D v2) {
  return acos((v1.dot(v2)) / (v1.magn() * v2.magn()));
}

/**
 * Determines if two 2D vectors are orthogonal
 */
bool isOrthogonal(svector::Vector2D v1, svector::Vector2D v2) {
  return v1.dot(v2) == 0;
}

/**
 * Decomposes a vector v into a pair {v1, v2} when projected onto
 * another vector w. v1 is parallel to w, and v2 is orthogonal to w.
 */
std::pair<svector::Vector2D, svector::Vector2D> decompose(svector::Vector2D v,
                                                          svector::Vector2D w) {
  svector::Vector2D v1 = w * ((v.dot(w)) / (w.magn() * w.magn()));
  svector::Vector2D v2 = v - v1;

  return {v1, v2};
}

/**
 * Determines the angle between two vectors
 */
double angleBetween(svector::Vector3D v1, svector::Vector3D v2) {
  return acos((v1.dot(v2)) / (v1.magn() * v2.magn()));
}

/**
 * Determines the area of parallelogram formed by v and w
 */
double areaParallelogram(svector::Vector3D v, svector::Vector3D w) {
  return v.cross(w).magn();
}
} // namespace svector_2d_3d_examples
