Embedding
=========

For adding vectors to an embedded device, there is a file called ``embed.hpp``, located in ``include/simplevectors``, which contains a minimized version of the 2D and 3D vector objects above, named ``Vec2D`` and ``Vec3D``, respectively. They include every feature mentioned except for looping and extending.

Differences from ``Vector2D`` and ``Vector3D``:

- Names are ``Vec2D`` and ``Vec3D`` instead of ``Vector2D`` and ``Vector3D``.
- Uses ``.x``, ``.y``, and ``.z`` instead of ``.x()``, ``.y()``, and ``.z()`` to access x, y, and z values.
- There are no methods in the minimized objects (e.g. ``.dot()``, ``.cross()``, etc), so you must use the functional equivalents (e.g. ``dot(vec)``, ``cross(vec)``) mentioned above. Most functions are compatible between the embed and non-embed versions, with some exceptions that are stated below.
- Embedded devices only support 2D and 3D vectors.
- This file is not included within ``simplevectors/vectors.hpp`` because it is meant to be a standalone file, so it must be included explicitly.

.. code-block:: cpp

  #include <simplevectors/embed.hpp>

  // ...

  svector::Vec2D embv2(2, 4);
  svector::Vec3D embv3(2, 4, 5);

  svector::toString(embv2); // <2.000, 4.000>
  svector::toString(embv3); // <2.000, 4.000, 5.000>

  std::cout << embv2.x << std::endl; // 2
  std::cout << embv3.y << std::endl; // 4
  std::cout << embv3.z << std::endl; // 5

  // all operators work the same

  svector::Vec2D emblhs(2, 5);
  svector::Vec2D embrhs(3, -4);
  double embdot = svector::dot(emblhs, embrhs); // -14

Embedded devices without access to the STL
------------------------------------------

For embedded devices without access to the C++ STL, such as on an Arduino, there is another file named ``embed.h``. It is mostly the same as ``embed.hpp``, with a few exceptions:

- 2D vectors are named ``EmbVec2D`` rather than ``Vec2D``.
- 3D vectors are named ``EmbVec3D`` rather than ``Vec3D``.
- It does not contain a ``std`` namespace, but the ``svector`` namespace is still there.
- There is no ``toString()`` function.
- Uses floats rather than doubles to store numbers to save memory, but this means the numbers are less precise

