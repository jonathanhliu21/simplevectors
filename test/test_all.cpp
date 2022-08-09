#include "simplevector2d.h"
#include "simplevector3d.h"
#include "units.h"

#include <gtest/gtest.h>

#include <regex>
#include <utility>

using namespace svector;

TEST(ConstructorTest2D, ZeroConstructorTest) {
  Vector2D vector;
  EXPECT_EQ(vector.x(), 0);
  EXPECT_EQ(vector.y(), 0);
  EXPECT_EQ(vector.magn(), 0);
  EXPECT_EQ(vector.angle(), 0);
}

TEST(ConstructorTest2D, XYConstructorTest) {
  Vector2D vector(5, -2);
  EXPECT_EQ(vector.x(), 5);
  EXPECT_EQ(vector.y(), -2);
}

TEST(ConstructorTest2D, CopyConstructorTest) {
  Vector2D vector1(3, 6);
  Vector2D vector2(vector1);

  EXPECT_EQ(vector2.x(), 3);
  EXPECT_EQ(vector2.y(), 6);

  Vector2D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x(), 0);
  EXPECT_EQ(vector2.y(), 0);
}

TEST(StringTest2D, StringTest) {
  Vector2D vector(3.52, -5.6);

  std::regex r("<3\.520*, -5\.60*>");

  EXPECT_TRUE(std::regex_match(vector.toString(), r));
}

TEST(OperatorTest2D, AddTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {-1, 9}},
      {{6, -7}, {3, -2.4}, {9, -9.4}},
  };

  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    Vector2D rhs(testcase[1].first, testcase[1].second);
    Vector2D res(testcase[2].first, testcase[2].second);

    Vector2D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest2D, AddChain) {
  Vector2D v1(3, -5);
  Vector2D v2(4, -6);
  Vector2D v3(2, 1);
  Vector2D v4(-3, 6);
  Vector2D res(6, -4);

  Vector2D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest2D, AddInPlace) {
  Vector2D v1(2, 5);
  v1 += Vector2D(-3, 4);
  Vector2D res(-1, 9);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, SubtractTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {5, 1}},
      {{6, -7}, {3, -2.4}, {3, -4.6}},
  };

  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    Vector2D rhs(testcase[1].first, testcase[1].second);
    Vector2D res(testcase[2].first, testcase[2].second);

    Vector2D difference = lhs - rhs;
    EXPECT_EQ(difference, res);
  }
}

TEST(OperatorTest2D, SubtractChain) {
  Vector2D v1(3, -5);
  Vector2D v2(4, -6);
  Vector2D v3(2, 1);
  Vector2D v4(-3, 6);
  Vector2D res(0, -6);

  Vector2D difference = v1 - v2 - v3 - v4;
  EXPECT_EQ(difference, res);
}

TEST(OperatorTest2D, SubtractInPlace) {
  Vector2D v1(2, 5);
  v1 -= Vector2D(-3, 4);
  Vector2D res(5, 1);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, NegativeOfAVector) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-2, -5}},
      {{6, -7}, {-6, 7}},
      {{-4, 2}, {4, -2}},
      {{-5, -2}, {5, 2}},
  };

  for (auto testcase : tests) {
    Vector2D num(testcase[0].first, testcase[0].second);
    Vector2D res(testcase[1].first, testcase[1].second);

    EXPECT_EQ(-num, res);
  }
}

TEST(OperatorTest2D, ScalarMultiplication) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-15, -20}},
      {{3, 4.5}, {2.5, -1}, {7.5, 11.25}},
  };
  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    Vector2D res(testcase[2].first, testcase[2].second);

    Vector2D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(OperatorTest2D, DotProduct) {
  Vector2D lhs(2, 5);
  Vector2D rhs(-3, -4);

  double product = lhs * rhs;
  EXPECT_EQ(product, -26);
}

TEST(OperatorTest2D, ScalarMultiplyInPlace) {
  Vector2D v1(2, 5);
  v1 *= 5;
  Vector2D res(10, 25);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, ScalarDivision) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-0.6, -0.8}},
      {{35, 42}, {7, -1}, {5, 6}},
  };

  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    Vector2D res(testcase[2].first, testcase[2].second);

    Vector2D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(OperatorTest2D, ScalarDivideInPlace) {
  Vector2D v1(-3, -4);
  v1 /= 5;
  Vector2D res(-0.6, -0.8);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, EqualityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4}},
      {{35, 42}, {35, 42}},
  };

  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    Vector2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(OperatorTest2D, InequalityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4.1}},
      {{35, 42}, {19, 534}},
  };

  for (auto testcase : tests) {
    Vector2D lhs(testcase[0].first, testcase[0].second);
    Vector2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(XYMagnitudeAngleMatchTest2D, TestMagnitudeGivenXY) {
  Vector2D vector(4.612, -3.322);
  double magn = vector.magn();
  double magn_r = std::round(magn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 5.684);
}

TEST(XYMagnitudeAngleMatchTest2D, TestAngleGivenXY) {
  std::vector<std::vector<double>> tests{
      {4.5, 2.3, 0.472},
      {-3.4, 5.44, 2.129},
      {-0.35, -4.44, -1.649},
      {6.2, -3, -0.451},
  };

  for (auto testcase : tests) {
    Vector2D vector(testcase[0], testcase[1]);
    double ang = vector.angle();
    double ang_r = std::round(ang * 1000.0) / 1000.0;

    EXPECT_EQ(ang_r, testcase[2]);
  }
}

TEST(ToComponentTest2D, TestConvertToPair) {
  Vector2D vector(3.5, -6.2);
  std::pair<double, double> testPair =
      vector.componentsAs<std::pair<double, double>>();

  EXPECT_EQ(testPair, std::make_pair(3.5, -6.2));
}

TEST(ToComponentTest2D, TestConvertToStruct) {
  Vector2D vector(3.5, -6.2);

  struct Pair2 {
    double x, y;

    Pair2(double _x, double _y) {
      x = _x;
      y = _y;
    }

    bool operator==(const Pair2 &other) const {
      return x == other.x && y == other.y;
    }
  };

  Pair2 testPair = vector.componentsAs<Pair2>();

  EXPECT_EQ(testPair, Pair2(3.5, -6.2));
}

TEST(NormalizeTest2D, TestNormalize) {
  Vector2D vector(3, 4);
  vector = vector.normalize();

  EXPECT_EQ(vector, Vector2D(0.6, 0.8));
}

TEST(RotationTest2D, CounterclockwiseRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (auto testcase : tests) {
    Vector2D vector(testcase[0], testcase[1]);
    Vector2D vectorp(testcase[3], testcase[4]);

    Vector2D rotated = vector.rotate(testcase[2]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
  }
}

TEST(RotationTest2D, ClockwiseRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (auto testcase : tests) {
    Vector2D vector(testcase[3], testcase[4]);
    Vector2D vectorp(testcase[0], testcase[1]);

    Vector2D rotated = vector.rotate(-testcase[2]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
  }
}

/**
 * END 2D TESTS
 * ======================================================================
 * BEGIN 3D TESTS
 */

TEST(ConstructorTest3D, ZeroConstructorTest) {
  Vector3D vector;
  EXPECT_EQ(vector.x(), 0);
  EXPECT_EQ(vector.y(), 0);
  EXPECT_EQ(vector.z(), 0);

  EXPECT_EQ(vector.magn(), 0);
}

TEST(ConstructorTest3D, XYZConstructorTest) {
  Vector3D vector(5, -2, 7);
  EXPECT_EQ(vector.x(), 5);
  EXPECT_EQ(vector.y(), -2);
  EXPECT_EQ(vector.z(), 7);
}

TEST(ConstructorTest3D, CopyConstructorTest) {
  Vector3D vector1(3, 6, 2);
  Vector3D vector2(vector1);

  EXPECT_EQ(vector2.x(), 3);
  EXPECT_EQ(vector2.y(), 6);
  EXPECT_EQ(vector2.z(), 2);

  Vector3D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x(), 0);
  EXPECT_EQ(vector2.y(), 0);
  EXPECT_EQ(vector2.z(), 0);
}

TEST(StringTest3D, StringTest) {
  Vector3D vector(3.52, -5.6, 2.2);

  std::regex r("<3\.520*, -5\.60*, 2\.20*>");

  EXPECT_TRUE(std::regex_match(vector.toString(), r));
}

TEST(OperatorTest3D, AddTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {-1, 9, 6}},
      {{6, -7, 1}, {3, -2.4, 5}, {9, -9.4, 6}},
  };

  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vector3D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest3D, AddChain) {
  Vector3D v1(3, -5, 1);
  Vector3D v2(4, -6, -1);
  Vector3D v3(2, 1, 1);
  Vector3D v4(-3, 6, -2);
  Vector3D res(6, -4, -1);

  Vector3D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest3D, AddInPlace) {
  Vector3D v1(2, 5, 8);
  v1 += Vector3D(-3, 4, -2);
  Vector3D res(-1, 9, 6);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, SubtractTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {5, 1, 10}},
      {{6, -7, 1}, {3, -2.4, 5}, {3, -4.6, -4}},
  };

  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vector3D sum = lhs - rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest3D, SubtractChain) {
  Vector3D v1(3, -5, 1);
  Vector3D v2(4, -6, -1);
  Vector3D v3(2, 1, 1);
  Vector3D v4(-3, 6, -2);
  Vector3D res(0, -6, 3);

  Vector3D sum = v1 - v2 - v3 - v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest3D, SubtractInPlace) {
  Vector3D v1(2, 5, 8);
  v1 -= Vector3D(-3, 4, -2);
  Vector3D res(5, 1, 10);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, NegativeOfAVector) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-2, -5, -8}},
      {{6, -7, -8}, {-6, 7, 8}},
      {{-4, 2, 6}, {4, -2, -6}},
      {{-5, -2, 0}, {5, 2, 0}},
  };

  for (auto testcase : tests) {
    Vector3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vector3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(-num, res);
  }
}

TEST(OperatorTest3D, ScalarMultiplication) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 8}, {5, -1, -1}, {-15, -20, 40}},
      {{3, 4.5, 2}, {2.5, -1, -1}, {7.5, 11.25, 5.0}},
  };
  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vector3D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(OperatorTest3D, DotProduct) {
  Vector3D lhs(2, 5, 6);
  Vector3D rhs(-3, -4, 2);

  double product = lhs * rhs;
  EXPECT_EQ(product, -14);
}

TEST(OperatorTest3D, ScalarMultiplyInPlace) {
  Vector3D v1(2, 5, 8);
  v1 *= 3;
  Vector3D res(6, 15, 24);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, CrossProduct) {
  Vector3D v1(2, 3, 5);
  Vector3D v2(1, 2, 3);
  Vector3D res(-1, -1, 1);

  EXPECT_EQ(v1 ^ v2, res);
  EXPECT_EQ(v2 ^ v1, -res);
}

TEST(OperatorTest3D, ScalarDivision) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 5}, {5, -1, -1}, {-0.6, -0.8, 1.0}},
      {{35, 42, 49}, {7, -1, -1}, {5, 6, 7}},
  };

  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    Vector3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vector3D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(OperatorTest3D, ScalarDivideInPlace) {
  Vector3D v1(-3, -4, 5);
  v1 /= 5;
  Vector3D res(-0.6, -0.8, 1);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest3D, EqualityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {-3, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.2}},
  };

  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(OperatorTest3D, InequalityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {300, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.3}},
  };

  for (auto testcase : tests) {
    Vector3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vector3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(XYMagnitudeAngleMatchTest3D, TestMagnitudeGivenXYZ) {
  Vector3D vector(4.612, -3.322, 2.552);
  double magn = vector.magn();
  double magn_r = std::round(magn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 6.230);
}

TEST(XYMagnitudeAngleMatchTest3D, TestAlphaGivenXYZ) {
  Vector3D vector(-3, 2, -6);
  double ang = vector.angle<ALPHA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.014);
}

TEST(XYMagnitudeAngleMatchTest3D, TestBetaGivenXYZ) {
  Vector3D vector(-3, 2, -6);
  double ang = vector.angle<BETA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 1.281);
}

TEST(XYMagnitudeAngleMatchTest3D, TestGammaGivenXYZ) {
  Vector3D vector(-3, 2, -6);
  double ang = vector.angle<GAMMA>();
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.600);
}

TEST(ToComponentTest3D, TestConvertToStruct) {
  Vector3D vector(3.5, -6.2, 2.4);

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
  Vector3D vector(-3, 2, -6);

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
  Vector3D vector(2, -3, -6);
  vector = vector.normalize();

  EXPECT_EQ(vector, Vector3D(2 / 7.0, -3 / 7.0, -6 / 7.0));
}

TEST(RotationTest3D, AlphaRotation) {
  std::vector<std::vector<double>> tests{
      {3, 4, 0, M_PI / 2, 3, 0, 4},
      {3, 4, 0, -M_PI / 2, 3, 0, -4},
      {3, 2.8284, 2.8284, M_PI / 4, 3, 0, 4},
      {3, 2.8284, 2.8284, -M_PI / 4, 3, 4, 0}};

  for (auto testcase : tests) {
    Vector3D vector(testcase[0], testcase[1], testcase[2]);
    Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vector3D rotated = vector.rotate<ALPHA>(testcase[3]);

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

  for (auto testcase : tests) {
    Vector3D vector(testcase[0], testcase[1], testcase[2]);
    Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vector3D rotated = vector.rotate<BETA>(testcase[3]);

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

  for (auto testcase : tests) {
    Vector3D vector(testcase[0], testcase[1], testcase[2]);
    Vector3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vector3D rotated = vector.rotate<GAMMA>(testcase[3]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z() * 1000) / 1000,
              std::round(rotated.z() * 1000) / 1000);
  }
}
