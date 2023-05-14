#include <simplevectors/embed.hpp>
#include <simplevectors/vectors.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 M_PI / 2
#endif

#ifndef M_PI_4
#define M_PI_4 M_PI / 4
#endif

int main() {
  // ----------------------------------------
  // This is for the quickstart example.
  // ----------------------------------------

  svector::Vector<2> vector2; // creates a 2D-vector
  svector::Vector2D
      vector2d; // creates a 2D-vector with 2D-specific functionality

  svector::Vector<3> vector3; // creates a 3D-vector
  svector::Vector3D
      vector3d; // creates a 3D-vector with 3D-specific functionality

  svector::Vector<4> vector4; // creates a 4D-vector

  // ----------------------------------------
  // This is for the basic examples.
  // ----------------------------------------

  std::cout << "INITIALIZATION TEST" << std::endl;

  svector::Vector2D zero2d; // <0, 0>
  svector::Vector3D zero3d; // <0, 0, 0>

  svector::Vector2D v2d(2, 4);    // <2, 4>
  svector::Vector3D v3d(2, 4, 5); // <2, 4, 5>

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

  std::cout << vec_from_std_array.toString() << std::endl;  // "<1, 2, 3, 5, 2>"
  std::cout << vec_from_std_vector.toString() << std::endl; // "<1, 0>"
  std::cout << vec_from_initializer_list.toString() << std::endl; // "<1, 4>"

  std::cout << "TO STRING TEST" << std::endl;
  std::cout << zero2d.toString() << std::endl; // "<0.000, 0.000>"
  std::cout << v3d.toString() << std::endl;    // "<2.000, 4.000, 5.000>"

  std::cout << "PROPERTIES TEST" << std::endl;
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

  std::cout << v2d.toString() << std::endl; // "<4.000, 4.000>"
  std::cout << v3d.toString() << std::endl; // "<2.000, 5.000, 3.000>"

  // set component values
  v2d[0] = 2;
  v2d[1] = 4; // v2d is now <2, 4>

  v3d[0] = 2;
  v3d[1] = 4;
  v3d[2] = 5; // v3d is now <2, 4, 5>

  // components of the vector
  std::cout << v2d[0] << " " // "2"
            << v2d[1] << " " // "4"
            << std::endl;

  std::cout << v3d[0] << " " // "2"
            << v3d[1] << " " // "4"
            << v3d[2] << " " // "5"
            << std::endl;

  std::cout << "OPERATIONS TEST" << std::endl;

  svector::Vector2D lhs(2, 5);
  svector::Vector2D rhs(3, -4);

  svector::Vector2D sum = lhs + rhs;        // <5, 1>
  svector::Vector2D difference = lhs - rhs; // <-1, 9>
  svector::Vector2D product = lhs * 3;      // <6, 15>
  svector::Vector2D quotient = lhs / 3;     // <0.667, 1.667>
  double dot_product = lhs.dot(rhs);        // -14
  svector::Vector2D neg = -lhs;             // <-2, -5>
  svector::Vector2D pos = +lhs;             // <2, 5>

  std::cout << sum.toString() << std::endl;
  std::cout << difference.toString() << std::endl;
  std::cout << product.toString() << std::endl;
  std::cout << quotient.toString() << std::endl;
  std::cout << dot_product << std::endl;
  std::cout << neg.toString() << std::endl;
  std::cout << pos.toString() << std::endl;

  svector::Vector3D lhs3d(2, 5, -3);
  svector::Vector3D rhs3d(6, 5, 9);

  svector::Vector3D cross = lhs3d.cross(rhs3d); // <60, -36, -20>
  std::cout << cross.toString() << std::endl;

  svector::Vector2D inplacev(2, 5);
  inplacev += svector::Vector2D(3, 6);
  inplacev -= svector::Vector2D(2, 3);
  inplacev *= 5;
  inplacev /= 7;

  std::cout << inplacev.toString() << std::endl; // "<2.143, 5.714>"

  std::cout << "EQUALITY TEST" << std::endl;
  svector::Vector2D lhs1(2, 5);
  svector::Vector2D rhs1(3, -4);
  svector::Vector2D lhs2(2, 5);
  svector::Vector2D rhs2(2, 5);

  bool equal1 = lhs1 == rhs1; // false
  bool equal2 = lhs1 != rhs1; // true
  bool equal3 = lhs2 == rhs2; // true
  bool equal4 = lhs2 != rhs2; // false

  std::cout << (equal1 ? "true" : "false") << std::endl;
  std::cout << (equal2 ? "true" : "false") << std::endl;
  std::cout << (equal3 ? "true" : "false") << std::endl;
  std::cout << (equal4 ? "true" : "false") << std::endl;

  std::cout << "NORMALIZATION TEST" << std::endl;
  svector::Vector2D unnorm2D(3, 4);
  svector::Vector3D unnorm3D(3, 4, 5);

  svector::Vector2D norm2D = unnorm2D.normalize(); // <0.6, 0.8>
  svector::Vector3D norm3D = unnorm3D.normalize(); // <0.424, 0.566, 0.707>

  std::cout << norm2D.toString() << std::endl;
  std::cout << norm3D.toString() << std::endl;

  std::cout << "ROTATION 2D TEST" << std::endl;
  svector::Vector2D v1(1, 0);
  svector::Vector2D v2(1, 0);

  svector::Vector2D v1ccw = v1.rotate(M_PI_4); // <0.707, 0.707>
  svector::Vector2D v2cw = v1.rotate(-M_PI_4); // <0.707, -0.707>

  std::cout << v1ccw.toString() << std::endl;
  std::cout << v2cw.toString() << std::endl;

  std::cout << "ROTATION 3D TEST" << std::endl;
  svector::Vector3D v1_3D(1, 0, 1);

  svector::Vector3D v1_xRotation =
      v1_3D.rotate<svector::ALPHA>(M_PI_2); // <1, -1, 0>
  svector::Vector3D v1_yRotation =
      v1_3D.rotate<svector::BETA>(M_PI_2); // <1, 0, -1>
  svector::Vector3D v1_zRotation =
      v1_3D.rotate<svector::GAMMA>(M_PI_2); // <0, 1, 1>

  std::cout << v1_xRotation.toString() << std::endl;
  std::cout << v1_yRotation.toString() << std::endl;
  std::cout << v1_zRotation.toString() << std::endl;

  svector::Vector3D v1_chained =
      v1_3D.rotate<svector::ALPHA>(M_PI_2)
          .rotate<svector::BETA>(M_PI_2)
          .rotate<svector::GAMMA>(M_PI_2); // <1, 0, -1>
  std::cout << v1_chained.toString() << std::endl;

  std::cout << "LOOP TEST" << std::endl;
  svector::Vector<5> vector_loop{1, 6, 4, 3, 9};

  for (const auto &i : vector_loop) {
    std::cout << i << std::endl;
  } // 1, 6, 4, 3, 9

  class Quaternion : public svector::Vector<4> {
    Quaternion(const svector::Vector<4> &other) {
      this->m_components[0] = other[0];
      this->m_components[1] = other[1];
      this->m_components[2] = other[2];
      this->m_components[3] = other[3];
    };
  };

  std::cout << "EMBED TEST" << std::endl;
  svector::Vec2D embv2(2, 4);
  svector::Vec3D embv3(2, 4, 5);

  std::cout << svector::toString(embv2) << std::endl; // <2.000, 4.000>
  std::cout << svector::toString(embv3) << std::endl; // <2.000, 4.000, 5.000>

  std::cout << embv2.x << std::endl; // 2
  std::cout << embv3.y << std::endl; // 4
  std::cout << embv3.z << std::endl; // 5

  // all operators work the same

  svector::Vec2D emblhs(2, 5);
  svector::Vec2D embrhs(3, -4);
  double embdot = svector::dot(emblhs, embrhs); // -14
  std::cout << embdot << std::endl;
}
