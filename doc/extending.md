# Extending

To go beyond only 2D and 3D, you can extend the `Vector` base class (the 2D and 3D vector classes extend this base class as well). `Vector` is a template class, where the template takes in the number of dimensions the vector has:

```cpp
class Quaternion : public svector::Vector<4> {};
```

The `Vector` base class provides a protected variable, `m_components`, an `std::array` of each component of the vector. Please check the library API (under the Classes tab) for more details on inherited member functions. Note which ones are virtual and which ones are not.

@note The binary operations with another vector require vectors **that have the same dimension**.

If you want to provide a different implementation for any of the non-operator methods (such as fast inverse square root for calculating the normalized vector), you can add a new method with a different name (such as `fastNormalize()`).

The base class provides these constructors:

- `Vector()`: initializes a zero vector (or a vector with 0s in every dimension)
- `Vector(std::initializer_list<double> args)`: initializes a vector, with each component given in the initializer list
- `Vector(const Vector<dimensions>& other)`: copy constructor

You can inherit them using `using svector::Vector<D>::Vector` or write your own constructors.

To make the operators work (without needing a downcast), you must include a constructor that takes in a base class:

```cpp
class Quaternion : public svector::Vector<4> {
  Quaternion(const svector::Vector<4>& other){
    this->m_components[0] = other[0]; 
    this->m_components[1] = other[1]; 
    this->m_components[2] = other[2]; 
    this->m_components[3] = other[3]; 
  };
};
```

After this, you can make your own methods interacting with the components of the vectors.

