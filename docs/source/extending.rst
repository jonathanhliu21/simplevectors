Extending
=========

To go beyond only 2D and 3D, you can extend the ``Vector``` base class (the 2D and 3D vector classes extend this base class as well). `Vector` is a template class, where the template takes in the number of dimensions the vector has:

.. code-block:: cpp

  class Quaternion : public svector::Vector<4> {};

The ``Vector`` base class provides a protected variable, ``m_components``, an ``std::array`` of each component of the vector. It also provides these methods, **which are not virtual**:

- ``operator+()``: adds two vectors
- ``operator-()``: subtracts two vectors, or flips the direction of a vector if used as a unary operator
- ``operator*()``: scalar multiplication
- ``operator/()``: scalar division
- ``operator==()``: equality (by comparing each component)
- ``operator!=()``: inequality
- ``operator+=()``: adds in place
- ``operator-=()``: subtracts in place
- ``operator*=()``: multiplies in place
- ``operator/=()``: divides in place
- ``dot()``: finds the dot product of two vectors
- ``magn()``: finds the magnitude of a vector
- ``normalize()``: normalizes a vector
- ``numDimensions()``: determines the number of dimensions in a vector
- ``operator[](index)``: returns dimension `index`'s component of a vector

Note that the binary operations with another vector require vectors **that have the same dimension**.

The base class provides these constructors:

- ``Vector()``: initializes a 0 vector (or a vector with 0s in every dimension)
- ``Vector(std::initializer_list<double> args)``: initializes a vector, with each component given in the initializer list
- ``Vector(const Vector<dimensions>& other)``: copy constructor

You can inherit them using ``using svector::Vector<D>::Vector`` or write your own constructors.

These methods are virtual and could be overridden:

- ``std::string toString()``: converts vector to a string format

To make the operators work, you must include a constructor that takes in a base class:

.. code-block:: cpp

  class Quaternion : public svector::Vector<4> {
    Quaternion(const svector::Vector<4>& other){
      this->m_components[0] = other[0]; 
      this->m_components[1] = other[1]; 
      this->m_components[2] = other[2]; 
      this->m_components[3] = other[3]; 
    };
  };

After this, you can make your own methods interacting with the components of the vectors.

