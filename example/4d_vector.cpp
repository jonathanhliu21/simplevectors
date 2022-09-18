#include "simplevectors/vectors.hpp"

/**
 * An example 4D vector
 *
 * Extends Vector base class, where many operations are already given.
 */
class Vector4D : public svector::Vector<4> {
  // inherits zero constructor, copy constructor, and initializer list
  // constructor
  using svector::Vector<4>::Vector;

  /**
   * This constructor is needed for the operators to work
   */
  Vector4D(const svector::Vector<4> &other) {
    this->m_components[0] = other[0];
    this->m_components[1] = other[1];
    this->m_components[2] = other[2];
    this->m_components[3] = other[3];
  };

  /**
   * Make custom constructor that takes in components
   */
  Vector4D(const double w, const double x, const double y, const double z) {
    this->m_components[0] = w;
    this->m_components[1] = x;
    this->m_components[2] = y;
    this->m_components[3] = z;
  }

  /**
   * Conjugate of a quaternion (represented by this 4D vector)
   */
  Vector4D conjugate() const {
    Vector4D ret;
    ret[0] = this->m_components[0];
    ret[1] = -this->m_components[1];
    ret[2] = -this->m_components[2];
    ret[3] = -this->m_components[3];

    return ret;
  }
};
