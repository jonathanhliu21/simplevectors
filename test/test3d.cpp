#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <regex>
#include <utility>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 M_PI / 2
#endif

#ifndef M_PI_4
#define M_PI_4 M_PI / 4
#endif

TEST(ConstructorTest3D, ZeroConstructorTest) {
  svector::Vector3D vector;
  EXPECT_EQ(vector.x(), 0);
  EXPECT_EQ(vector.y(), 0);
  EXPECT_EQ(vector.z(), 0);

  EXPECT_EQ(vector.magn(), 0);
}

TEST(ConstructorTest3D, XYZConstructorTest) {
  svector::Vector3D vector(5, -2, 7);
  EXPECT_EQ(vector.x(), 5);
  EXPECT_EQ(vector.y(), -2);
  EXPECT_EQ(vector.z(), 7);
}

TEST(ConstructorTest3D, CopyConstructorTest) {
  svector::Vector3D vector1(3, 6, 2);
  svector::Vector3D vector2(vector1);

  EXPECT_EQ(vector2.x(), 3);
  EXPECT_EQ(vector2.y(), 6);
  EXPECT_EQ(vector2.z(), 2);

  svector::Vector3D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x(), 0);
  EXPECT_EQ(vector2.y(), 0);
  EXPECT_EQ(vector2.z(), 0);
}

TEST(SetterTest3D, SetterXTest) {
  svector::Vector3D vector1{2, 5};
  vector1.x(4);

  EXPECT_EQ(vector1.x(), 4);
  EXPECT_EQ(vector1.y(), 5);
  EXPECT_EQ(vector1.z(), 0);
}

TEST(SetterTest3D, SetterYTest) {
  svector::Vector3D vector1{2, 5};
  vector1.y(4);

  EXPECT_EQ(vector1.x(), 2);
  EXPECT_EQ(vector1.y(), 4);
  EXPECT_EQ(vector1.z(), 0);
}

TEST(SetterTest3D, SetterZTest) {
  svector::Vector3D vector1{2, 5};
  vector1.z(7);

  EXPECT_EQ(vector1.x(), 2);
  EXPECT_EQ(vector1.y(), 5);
  EXPECT_EQ(vector1.z(), 7);
}

TEST(StringTest3D, StringTest) {
  svector::Vector3D vector(3.52, -5.6, 2.2);

  std::regex r("<3\\.520*, -5\\.60*, 2\\.20*>");

  EXPECT_TRUE(std::regex_match(vector.toString(), r));
}

TEST(OperatorTest3D, AddTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {-1, 9, 6}},
      {{6, -7, 1}, {3, -2.4, 5}, {9, -9.4, 6}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    svector::Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    svector::Vector3D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest3D, AddChain) {
  svector::Vector3D v1(3, -5, 1);
  svector::Vector3D v2(4, -6, -1);
  svector::Vector3D v3(2, 1, 1);
  svector::Vector3D v4(-3, 6, -2);
  svector::Vector3D res(6, -4, -1);

  svector::Vector3D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest3D, AddInPlace) {
  svector::Vector3D v1(2, 5, 8);
  v1 += svector::Vector3D(-3, 4, -2);
  svector::Vector3D res(-1, 9, 6);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, SubtractTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {5, 1, 10}},
      {{6, -7, 1}, {3, -2.4, 5}, {3, -4.6, -4}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    svector::Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    svector::Vector3D sum = lhs - rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest3D, SubtractChain) {
  svector::Vector3D v1(3, -5, 1);
  svector::Vector3D v2(4, -6, -1);
  svector::Vector3D v3(2, 1, 1);
  svector::Vector3D v4(-3, 6, -2);
  svector::Vector3D res(0, -6, 3);

  svector::Vector3D sum = v1 - v2 - v3 - v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest3D, SubtractInPlace) {
  svector::Vector3D v1(2, 5, 8);
  v1 -= svector::Vector3D(-3, 4, -2);
  svector::Vector3D res(5, 1, 10);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, NegativeOfAVector) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-2, -5, -8}},
      {{6, -7, -8}, {-6, 7, 8}},
      {{-4, 2, 6}, {4, -2, -6}},
      {{-5, -2, 0}, {5, 2, 0}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(-num, res);
  }
}

TEST(OperatorTest3D, PositiveOfAVector) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {2, 5, 8}},
      {{6, -7, -8}, {6, -7, -8}},
      {{-4, 2, 6}, {-4, 2, 6}},
      {{-5, -2, 0}, {-5, -2, 0}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(+num, res);
  }
}

TEST(OperatorTest3D, ScalarMultiplication) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 8}, {5, -1, -1}, {-15, -20, 40}},
      {{3, 4.5, 2}, {2.5, -1, -1}, {7.5, 11.25, 5.0}},
  };
  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    svector::Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    svector::Vector3D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(OperatorTest3D, DotProduct) {
  svector::Vector3D lhs(2, 5, 6);
  svector::Vector3D rhs(-3, -4, 2);

  double product = lhs.dot(rhs);
  double product2 = rhs.dot(lhs);
  EXPECT_EQ(product, -14);
  EXPECT_EQ(product, product2);
}

TEST(OperatorTest3D, ScalarMultiplyInPlace) {
  svector::Vector3D v1(2, 5, 8);
  v1 *= 3;
  svector::Vector3D res(6, 15, 24);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, CrossProduct) {
  svector::Vector3D v1(2, 3, 5);
  svector::Vector3D v2(1, 2, 3);
  svector::Vector3D res(-1, -1, 1);

  EXPECT_EQ(v1.cross(v2), res);
  EXPECT_EQ(v2.cross(v1), -res);
}

TEST(OperatorTest3D, ScalarDivision) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 5}, {5, -1, -1}, {-0.6, -0.8, 1.0}},
      {{35, 42, 49}, {7, -1, -1}, {5, 6, 7}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    svector::Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    svector::Vector3D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(OperatorTest3D, ScalarDivideInPlace) {
  svector::Vector3D v1(-3, -4, 5);
  v1 /= 5;
  svector::Vector3D res(-0.6, -0.8, 1);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, EqualityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {-3, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.2}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(OperatorTest3D, InequalityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {300, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.3}},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    svector::Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(XYMagnitudeAngleMatchTest3D, TestMagnitudeGivenXYZ) {
  svector::Vector3D vector(4.612, -3.322, 2.552);
  double magn = vector.magn();
  double magn_r = std::round(magn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 6.230);
}

TEST(XYMagnitudeAngleMatchTest3D, TestAlphaGivenXYZ) {
  svector::Vector3D vector(-3, 2, -6);
  double ang = vector.angle<svector::ALPHA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.014);
}

TEST(XYMagnitudeAngleMatchTest3D, TestBetaGivenXYZ) {
  svector::Vector3D vector(-3, 2, -6);
  double ang = vector.angle<svector::BETA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 1.281);
}

TEST(XYMagnitudeAngleMatchTest3D, TestGammaGivenXYZ) {
  svector::Vector3D vector(-3, 2, -6);
  double ang = vector.angle<svector::GAMMA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.600);
}

TEST(ToComponentTest3D, TestConvertToStruct) {
  svector::Vector3D vector(3.5, -6.2, 2.4);

  struct Pair3 {
    double x, y, z;

    Pair3(double _x, double _y, double _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    bool operator==(const Pair3 &other) const {
      return x == other.x && y == other.y && z == other.z;
    }
  };

  Pair3 testPair = vector.componentsAs<Pair3>();

  EXPECT_EQ(testPair, Pair3(3.5, -6.2, 2.4));
}

TEST(ToAngleTest3D, TestConvertToStruct) {
  svector::Vector3D vector(-3, 2, -6);

  struct Pair3 {
    double x, y, z;

    Pair3(double _x, double _y, double _z) {
      x = std::round(_x * 1000.0);
      y = std::round(_y * 1000.0);
      z = std::round(_z * 1000.0);
    }
  };

  Pair3 testPair = vector.anglesAs<Pair3>();

  EXPECT_EQ(testPair.x, 2014);
  EXPECT_EQ(testPair.y, 1281);
  EXPECT_EQ(testPair.z, 2600);
}

TEST(NormalizeTest3D, TestNormalize) {
  svector::Vector3D vector(2, -3, -6);
  vector = vector.normalize();

  EXPECT_EQ(vector, svector::Vector3D(2 / 7.0, -3 / 7.0, -6 / 7.0));
}

TEST(RotationTest3D, AlphaRotation) {
  std::vector<std::vector<double>> tests{
      {3, 4, 0, M_PI / 2, 3, 0, 4},
      {3, 4, 0, -M_PI / 2, 3, 0, -4},
      {3, 2.8284, 2.8284, M_PI / 4, 3, 0, 4},
      {3, 2.8284, 2.8284, -M_PI / 4, 3, 4, 0}};

  for (const auto &testcase : tests) {
    svector::Vector3D vector(testcase[0], testcase[1], testcase[2]);
    svector::Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    svector::Vector3D rotated = vector.rotate<svector::ALPHA>(testcase[3]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z() * 1000) / 1000,
              std::round(rotated.z() * 1000) / 1000);
  }
}

TEST(RotationTest3D, BetaRotation) {
  std::vector<std::vector<double>> tests{
      {4, 3, 0, M_PI / 2, 0, 3, -4},
      {4, 3, 0, -M_PI / 2, 0, 3, 4},
      {2.8284, 3, 2.8284, M_PI / 4, 4, 3, 0},
      {2.8284, 3, 2.8284, -M_PI / 4, 0, 3, 4}};

  for (const auto &testcase : tests) {
    svector::Vector3D vector(testcase[0], testcase[1], testcase[2]);
    svector::Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    svector::Vector3D rotated = vector.rotate<svector::BETA>(testcase[3]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z() * 1000) / 1000,
              std::round(rotated.z() * 1000) / 1000);
  }
}

TEST(RotationTest3D, GammaRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, 3, M_PI / 6, 0.866, 0.5, 3},
      {1, 1, 3, M_PI / 4, 0, 1.414, 3},
      {1.732, 1, 3, M_PI / 3, 0, 2, 3},
      {0, 1, 3, M_PI / 4, -0.707, 0.707, 3},
      {-1, 0, 3, M_PI / 3, -0.5, -0.866, 3},
      {-0.5, -0.866, 3, M_PI / 6, 0, -1, 3},
      {0, -1, 3, M_PI / 4, 0.707, -0.707, 3},
      {0.707, -0.707, 3, M_PI / 4, 1, 0, 3},
  };

  for (const auto &testcase : tests) {
    svector::Vector3D vector(testcase[0], testcase[1], testcase[2]);
    svector::Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    svector::Vector3D rotated = vector.rotate<svector::GAMMA>(testcase[3]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z() * 1000) / 1000,
              std::round(rotated.z() * 1000) / 1000);
  }
}
