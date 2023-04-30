Basic Usage
===========

This section covers basic usage of vectors with ``Vector2D`` and ``Vector3D`` objects. For more details, see the :doc:`/api/library_root`.

Everything is under the namespace ``svector``.

The examples below are combined in the ``example/basic_examples.cpp`` file in the source code.

All of the examples below (except for initialization, printing, and those specifically noted) show the methods of the vector object. For each method, there is also a function under the `svector` namespace that takes in a vector object and the arguments for the corresponding method. For example:

.. code-block:: cpp

  svector::Vector2D v2d(2, 4);
  double xval = v2d.x() + 1;
  v2d.x(xval);

is equivalent to:

.. code-block:: cpp

  svector::Vector2D v2d(2, 4);
  double xval = svector::x(v2d) + 1;
  svector::x(v2d, xval);

.. note::
   To ensure compatiblity between embedded and non-embedded versions, it is recommended to use the functional equivalents over the member functions.

Initialization
--------------

Below are examples of zero initialization and initializing with values.

.. code-block:: cpp

  svector::Vector2D zero2d; // <0, 0>
  svector::Vector3D zero3d; // <0, 0, 0>

  svector::Vector2D v2d(2, 4);    // <2, 4>
  svector::Vector3D v3d(2, 4, 5); // <2, 4, 5>

Using ``makeVector()``
~~~~~~~~~~~~~~~~~~~~~~~

You can also initialize a vector in a functional manner by using the ``makeVector()`` function. This function can be used to initialize a vector from an ``std::array``, ``std::vector``, or an initializer list. Note that if you are using ``makeVector()`` to initialize from a ``std::vector`` or an initializer list, then you need to specify the number of dimensions as a template argument. If you are using an initializer list, you also need to specify the type of the vector elements.

.. code-block:: cpp

  std::array<double, 5> an_std_array = {{1, 2, 3, 5, 2}};
  svector::Vector<5> vec_from_std_array =
      svector::makeVector(an_std_array); // <1, 2, 3, 5, 2>

  std::vector<double> an_std_vector = {1};
  svector::Vector2D vec_from_std_vector =
      svector::makeVector<2>(an_std_vector); // <1, 0>
  // If there are too few elements inside the std::vector, then the rest of the
  // dimensions for the vector will be 0. If there are too many, then the vector
  // truncates the dimensions.

  svector::Vector2D vec_from_initializer_list =
      svector::makeVector<2, double>({1, 4, 5}); // <1, 4>
  // If there are too few or too many elements inside the initializer list, then
  // makeVector() handles it the same way as it would handle a std::vector that
  // has too few/many elements.

Printing
--------

Both ``Vector2D`` and ``Vector3D`` have ``toString()`` methods for printing.

.. code-block:: cpp

  #include <iostream>

  std::cout << zero2d.toString() << std::endl; // "<0.000, 0.000>"
  std::cout << v3d.toString() << std::endl; // "<2.000, 4.000, 5.000>"

Properties
----------

The properties are shown in the code snippet below.

.. code-block:: cpp

  // components of the vector
  std::cout << v2d.x() << " " // "2"
            << v2d.y() << " " // "4"
            << std::endl;

  std::cout << v3d.x() << " " // "2"
            << v3d.y() << " " // "4"
            << v3d.z() << " " // "5"
            << std::endl;

  // 2D magnitude and angle from horizontal, in radians
  std::cout << v2d.magn() << std::endl;  // "4.472"
  std::cout << v2d.angle() << std::endl; // "1.107"

  // 3D magnitude and angle from x-axis (ALPHA), y-axis (BETA),
  // and z-axis (GAMMA) in radians
  std::cout << v3d.magn() << std::endl;                  // "6.708"
  std::cout << v3d.angle<svector::ALPHA>() << std::endl; // "1.268"
  std::cout << v3d.angle<svector::BETA>() << std::endl;  // "0.9322"
  std::cout << v3d.angle<svector::GAMMA>() << std::endl; // "0.730"
  // NOTE: the angle methods will result in undefined behavior if the magnitude
  // of the vector is zero.

  // set component values
  v2d.x(4); // v2d is now <4, 4>
  v3d.y(5);
  v3d.z(3); // v3d is now <2, 5, 3>

  // check if a vector is a zero vector (magnitude is zero)
  std::cout << (v2d.isZero() ? "true" : "false") << std::endl; // false
  std::cout << (v3d.isZero() ? "true" : "false") << std::endl; // false

Note that the functional equivalent for getting the angles of a 3D vector is slightly different:

.. code-block:: cpp

  std::cout << svector::alpha(v3d) << std::endl; // alpha angle
  std::cout << svector::beta(v3d) << std::endl;  // beta angle
  std::cout << svector::gamma(v3d) << std::endl; // gamma angle
  // NOTE: the angle methods will result in undefined behavior if the magnitude
  // of the vector is zero.

You can also access the x, y, and z components using the ``[]`` operator. In this case, the 0th index would correspond to the x-value, the 1st index would correspond to the y-value, and the 2nd index would correspond to the z-value. This also works on higher-dimensional vectors. There is no functional equivalent to this operator.

.. code-block:: cpp

  // set component values
  v2d[0] = 2;
  v2d[1] = 4; // v2d is now <2, 4>

  v3d[0] = 2;
  v3d[1] = 4;
  v3d[2] = 5; // v3d is now <2, 4, 5>

  // components of the vector
  std::cout << v2d[0] << " " // same as x(), will print out "2"
            << v2d[1] << " " // same as y(), will print out "4"
            << std::endl;

  std::cout << v3d[0] << " " // same as x(), will print out "2"
            << v3d[1] << " " // same as y(), will print out "4"
            << v3d[2] << " " // same as z(), will print out "5"
            << std::endl;

Operations
----------

Below are the operations that can be done on both 2D and 3D vectors. For simplicity, examples will be shown with only 2D vectors.

.. code-block:: cpp

  svector::Vector2D lhs(2, 5);
  svector::Vector2D rhs(3, -4);

  svector::Vector2D sum = lhs + rhs;        // <5, 1>
  svector::Vector2D difference = lhs - rhs; // <-1, 9>
  svector::Vector2D product = lhs * 3;      // <6, 15>
  svector::Vector2D quotient = lhs / 3;     // <0.667, 1.667>
  double dot_product = lhs.dot(rhs);        // -14
  svector::Vector2D neg = -lhs;             // <-2, -5>

Cross products only work on 3D vectors.

.. code-block:: cpp

  svector::Vector3D lhs3d(2, 5, -3);
  svector::Vector3D rhs3d(6, 5, 9);

  svector::Vector3D cross = lhs3d.cross(rhs3d); // <60, -36, -20>

Vectors can be added, subtracted, multiplied, or divided in place.

.. code-block:: cpp

  svector::Vector2D inplacev(2, 5);
  inplacev += svector::Vector2D(3, 6);
  inplacev -= svector::Vector2D(2, 3);
  inplacev *= 5;
  inplacev /= 7;

  std::cout << inplacev.toString() << std::endl; // "<2.143, 5.714>"

Equality
--------

Works for both 2D and 3D vectors.

.. code-block:: cpp

  svector::Vector2D lhs1(2, 5);
  svector::Vector2D rhs1(3, -4);
  svector::Vector2D lhs2(2, 5);
  svector::Vector2D rhs2(2, 5);

  bool equal1 = lhs1 == rhs1;  // false
  bool equal2 = lhs1 != rhs1;  // true
  bool equal3 = lhs2 == rhs2;  // true
  bool equal4 = lhs2 != rhs2;  // false

Normalization
-------------

Below shows an example of vector normalization.

.. code-block:: cpp

  svector::Vector2D unnorm2D(3, 4);
  svector::Vector3D unnorm3D(3, 4, 5);

  svector::Vector2D norm2D = unnorm2D.normalize(); // <0.6, 0.8>
  svector::Vector3D norm3D = unnorm3D.normalize(); // <0.424, 0.566, 0.707>


**NOTE**: ``normalize()`` will result in undefined behavior if the magnitude of the vector is zero.

Rotation 2D
-----------

For 2D vectors, the ``rotate`` method requires one argument, ``ang``, which is the angle to rotate in radians. A positive angle indicates counterclockwise rotation, and a negative angle indicates clockwise rotation. The method returns a new vector.

.. code-block:: cpp

  svector::Vector2D v1(1, 0);
  svector::Vector2D v2(1, 0);

  svector::Vector2D v1ccw = v1.rotate(M_PI_4);  // <0.707, 0.707>
  svector::Vector2D v2cw = v1.rotate(-M_PI_4);  // <0.707, -0.707>

Rotation 3D
-----------

For 3D vectors, the ``rotate`` method only works for one axis at a time. It requires a template argument indicating the axis to rotate around: ``ALPHA`` for the x-axis, ``BETA`` for the y-axis, and ``GAMMA`` for the z-axis.

.. code-block:: cpp

  svector::Vector3D v1_3D(1, 0, 1);

  svector::Vector3D v1_xRotation =
      v1_3D.rotate<svector::ALPHA>(M_PI_2); // <1, -1, 0>
  svector::Vector3D v1_yRotation =
      v1_3D.rotate<svector::BETA>(M_PI_2); // <1, 0, -1>
  svector::Vector3D v1_zRotation =
      v1_3D.rotate<svector::GAMMA>(M_PI_2); // <0, 1, 1>

Rotations can also be chained:

.. code-block:: cpp

  svector::Vector3D v1_chained =
      v1_3D.rotate<svector::ALPHA>(M_PI_2)
          .rotate<svector::BETA>(M_PI_2)
          .rotate<svector::GAMMA>(M_PI_2); // <1, 0, -1>

Note that the functional equivalent of rotation around a certain axis is slightly different:

.. code-block:: cpp

  svector::Vector3D v1_xRotation = svector::rotateAlpha(v1_3D, M_PI_2);
  svector::Vector3D v1_yRotation = svector::rotateBeta(v1_3D, M_PI_2);
  svector::Vector3D v1_zRotation = svector::rotateGamma(v1_3D, M_PI_2);

Looping
-------

The ``Vector`` class and the classes that extend it (namely ``Vector2D`` and ``Vector3D``) are container-like in the sense that they have iterators and ``begin()``, ``end()``, ``rbegin()``, and ``rend()`` methods. This means that they can be looped through like any other STL container.

.. code-block:: cpp

  svector::Vector<5> vector_loop{1, 6, 4, 3, 9};

  for (const auto& i: vector_loop) {
    std::cout << i << std::endl;
  } // 1, 6, 4, 3, 9

This can be helpful for calculating sums.
