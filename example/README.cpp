#include <simplevectors/vectors.hpp>

#include <iostream>

int main() {
  svector::Vector2D zero2d; // <0, 0>
  svector::Vector3D zero3d; // <0, 0, 0>

  svector::Vector2D v2d(2, 4);    // <2, 4>
  svector::Vector3D v3d(2, 4, 5); // <2, 4, 5>

  std::cout << "TO STRING TEST" << std::endl;
  std::cout << zero2d.toString() << std::endl; // "<0.000, 0.000>"
  std::cout << v3d.toString() << std::endl;    // "<2.000, 4.000, 5.000>"

  std::cout << "PROPERTIES TEST" << std::endl;
  // components of the vector
  std::cout << v2d.x() << " " // 2.000
            << v2d.y() << " " // 4.000
            << std::endl;

  std::cout << v3d.x() << " " // 2.000
            << v3d.y() << " " // 4.000
            << v3d.z() << " " // 5.000
            << std::endl;

  // 2D magnitude and angle from horizontal, in radians
  std::cout << v2d.magn() << std::endl;  // 4.472
  std::cout << v2d.angle() << std::endl; // 1.107

  // 3D magnitude and angle from x-axis (ALPHA), y-axis (BETA),
  // and z-axis (GAMMA) in radians
  std::cout << v3d.magn() << std::endl;                  // 6.708
  std::cout << v3d.angle<svector::ALPHA>() << std::endl; // 1.268
  std::cout << v3d.angle<svector::BETA>() << std::endl;  // 0.9322
  std::cout << v3d.angle<svector::GAMMA>() << std::endl; // 0.730

  std::cout << "OPERATIONS TEST" << std::endl;

  svector::Vector2D lhs(2, 5);
  svector::Vector2D rhs(3, -4);

  svector::Vector2D sum = lhs + rhs;        // <5, 1>
  svector::Vector2D difference = lhs - rhs; // <-1, 9>
  svector::Vector2D product = lhs * 3;      // <6, 15>
  svector::Vector2D quotient = lhs / 3;     // <0.667, 1.667>
  double dot_product = lhs.dot(rhs);        // -14
  svector::Vector2D neg = -lhs;             // <-2, -5>

  std::cout << sum.toString() << std::endl;
  std::cout << difference.toString() << std::endl;
  std::cout << product.toString() << std::endl;
  std::cout << quotient.toString() << std::endl;
  std::cout << dot_product << std::endl;
  std::cout << neg.toString() << std::endl;

  svector::Vector3D lhs3d(2, 5, -3);
  svector::Vector3D rhs3d(6, 5, 9);

  svector::Vector3D cross = lhs3d.cross(rhs3d); // <60, -36, -20>
  std::cout << cross.toString() << std::endl;

  svector::Vector2D inplacev(2, 5);
  inplacev += svector::Vector2D(3, 6);
  inplacev -= svector::Vector2D(2, 3);
  inplacev *= 5;
  inplacev /= 7;

  std::cout << inplacev.toString() << std::endl; // <2.143, 5.714>

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

  class Quaternion : public svector::Vector<4> {
    Quaternion(const svector::Vector<4> &other) {
      this->m_components[0] = other[0];
      this->m_components[1] = other[1];
      this->m_components[2] = other[2];
      this->m_components[3] = other[3];
    };
  };
}
