#include "simplevectors/embed.h"

#include <gtest/gtest.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <regex>
#include <utility>

#ifndef M_PI
#define M_PI 3.14159265f
#endif

#ifndef M_PI_2
#define M_PI_2 M_PI / 2
#endif

#ifndef M_PI_4
#define M_PI_4 M_PI / 4
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4305)
#pragma warning(disable : 4244)
#endif

using namespace svector;

TEST(Embed2XYZ, GetterSetterTest2D) {
  EmbVec2D vector(1, 2);
  EXPECT_EQ(x(vector), 1);
  EXPECT_EQ(y(vector), 2);

  x(vector, 3);
  y(vector, 4);

  EXPECT_EQ(x(vector), 3);
  EXPECT_EQ(y(vector), 4);
}

TEST(Embed2XYZ, GetterSetterTest3D) {
  EmbVec3D vector(1, 2, 5);
  EXPECT_EQ(x(vector), 1);
  EXPECT_EQ(y(vector), 2);
  EXPECT_EQ(z(vector), 5);

  x(vector, 3);
  y(vector, 4);
  z(vector, 0);

  EXPECT_EQ(x(vector), 3);
  EXPECT_EQ(y(vector), 4);
  EXPECT_EQ(z(vector), 0);
}

TEST(Embed2ConstructorTest2D, ZeroConstructorTest) {
  EmbVec2D vector;
  EXPECT_EQ(vector.x, 0);
  EXPECT_EQ(vector.y, 0);
  EXPECT_EQ(magn(vector), 0);
  EXPECT_EQ(angle(vector), 0);
}

TEST(Embed2ConstructorTest2D, XYConstructorTest) {
  EmbVec2D vector(5, -2);
  EXPECT_EQ(vector.x, 5);
  EXPECT_EQ(vector.y, -2);
}

TEST(Embed2ConstructorTest2D, CopyConstructorTest) {
  EmbVec2D vector1(3, 6);
  EmbVec2D vector2(vector1);

  EXPECT_EQ(vector2.x, 3);
  EXPECT_EQ(vector2.y, 6);

  EmbVec2D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x, 0);
  EXPECT_EQ(vector2.y, 0);
}

TEST(Embed2OperatorTest2D, AddTest) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{2, 5}, {-3, 4}, {-1, 9}},
      {{6, -7}, {3, -2.4}, {9, -9.4}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    EmbVec2D rhs(testcase[1].first, testcase[1].second);
    EmbVec2D res(testcase[2].first, testcase[2].second);

    EmbVec2D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(Embed2OperatorTest2D, AddChain) {
  EmbVec2D v1(3, -5);
  EmbVec2D v2(4, -6);
  EmbVec2D v3(2, 1);
  EmbVec2D v4(-3, 6);
  EmbVec2D res(6, -4);

  EmbVec2D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(Embed2OperatorTest2D, AddInPlace) {
  EmbVec2D v1(2, 5);
  v1 += EmbVec2D(-3, 4);
  EmbVec2D res(-1, 9);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest2D, SubtractTest) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{2, 5}, {-3, 4}, {5, 1}},
      {{6, -7}, {3, -2.4}, {3, -4.6}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    EmbVec2D rhs(testcase[1].first, testcase[1].second);
    EmbVec2D res(testcase[2].first, testcase[2].second);

    EmbVec2D difference = lhs - rhs;
    EXPECT_EQ(difference, res);
  }
}

TEST(Embed2OperatorTest2D, SubtractChain) {
  EmbVec2D v1(3, -5);
  EmbVec2D v2(4, -6);
  EmbVec2D v3(2, 1);
  EmbVec2D v4(-3, 6);
  EmbVec2D res(0, -6);

  EmbVec2D difference = v1 - v2 - v3 - v4;
  EXPECT_EQ(difference, res);
}

TEST(Embed2OperatorTest2D, SubtractInPlace) {
  EmbVec2D v1(2, 5);
  v1 -= EmbVec2D(-3, 4);
  EmbVec2D res(5, 1);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest2D, NegativeOfAVector) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{2, 5}, {-2, -5}},
      {{6, -7}, {-6, 7}},
      {{-4, 2}, {4, -2}},
      {{-5, -2}, {5, 2}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D num(testcase[0].first, testcase[0].second);
    EmbVec2D res(testcase[1].first, testcase[1].second);

    EXPECT_EQ(-num, res);
  }
}

TEST(Embed2OperatorTest2D, PositiveOfAVector) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{2, 5}, {2, 5}},
      {{6, -7}, {6, -7}},
      {{-4, 2}, {-4, 2}},
      {{-5, -2}, {-5, -2}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D num(testcase[0].first, testcase[0].second);
    EmbVec2D res(testcase[1].first, testcase[1].second);

    EXPECT_EQ(+num, res);
  }
}

TEST(Embed2OperatorTest2D, ScalarMultiplication) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{-3, -4}, {5, -1}, {-15, -20}},
      {{3, 4.5}, {2.5, -1}, {7.5, 11.25}},
  };
  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    float rhs = testcase[1].first;
    EmbVec2D res(testcase[2].first, testcase[2].second);

    EmbVec2D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(Embed2OperatorTest2D, DotProduct) {
  EmbVec2D lhs(2, 5);
  EmbVec2D rhs(-3, -4);

  float product = dot(lhs, rhs);
  float product2 = dot(rhs, lhs);
  EXPECT_EQ(product, -26);
  EXPECT_EQ(product2, product);
}

TEST(Embed2OperatorTest2D, ScalarMultiplyInPlace) {
  EmbVec2D v1(2, 5);
  v1 *= 5;
  EmbVec2D res(10, 25);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest2D, ScalarDivision) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{-3, -4}, {5, -1}, {-0.6, -0.8}},
      {{35, 42}, {7, -1}, {5, 6}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    float rhs = testcase[1].first;
    EmbVec2D res(testcase[2].first, testcase[2].second);

    EmbVec2D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(Embed2OperatorTest2D, ScalarDivideInPlace) {
  EmbVec2D v1(-3, -4);
  v1 /= 5;
  EmbVec2D res(-0.6, -0.8);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest2D, EqualityTest) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{-3, -4}, {-3, -4}},
      {{35, 42}, {35, 42}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    EmbVec2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(Embed2OperatorTest2D, InequalityTest) {
  std::vector<std::vector<std::pair<float, float>>> tests{
      {{-3, -4}, {-3, -4.1}},
      {{35, 42}, {19, 534}},
  };

  for (const auto &testcase : tests) {
    EmbVec2D lhs(testcase[0].first, testcase[0].second);
    EmbVec2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(Embed2XYMagnitudeAngleMatchTest2D, TestMagnitudeGivenXY) {
  EmbVec2D vector(4.612, -3.322);
  float magnn = magn(vector);

  EXPECT_LT(std::abs(magnn - 5.683856), 0.001);
}

TEST(Embed2XYMagnitudeAngleMatchTest2D, TestAngleGivenXY) {
  std::vector<std::vector<float>> tests{
      {4.5, 2.3, 0.472},
      {-3.4, 5.44, 2.129},
      {-0.35, -4.44, -1.649},
      {6.2, -3, -0.451},
  };

  for (const auto &testcase : tests) {
    EmbVec2D vector(testcase[0], testcase[1]);
    float ang = angle(vector);

    EXPECT_LT(std::abs(ang - testcase[2]), 0.001);
  }
}

TEST(Embed2NormalizeTest2D, TestNormalize) {
  EmbVec2D vector(3, 4);
  vector = normalize(vector);

  EXPECT_EQ(vector, EmbVec2D(0.6, 0.8));
}

TEST(Embed2RotationTest2D, CounterclockwiseRotation) {
  std::vector<std::vector<float>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (const auto &testcase : tests) {
    EmbVec2D vector(testcase[0], testcase[1]);
    EmbVec2D vectorp(testcase[3], testcase[4]);

    EmbVec2D rotated = rotate(vector, testcase[2]);

    EXPECT_LT(std::abs(vectorp.x - rotated.x), 0.001);
    EXPECT_LT(std::abs(vectorp.y - rotated.y), 0.001);
  }
}

TEST(Embed2RotationTest2D, ClockwiseRotation) {
  std::vector<std::vector<float>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (const auto &testcase : tests) {
    EmbVec2D vector(testcase[3], testcase[4]);
    EmbVec2D vectorp(testcase[0], testcase[1]);

    EmbVec2D rotated = rotate(vector, -testcase[2]);

    EXPECT_LT(std::abs(vectorp.x - rotated.x), 0.001);
    EXPECT_LT(std::abs(vectorp.y - rotated.y), 0.001);
  }
}

/**
 * END 2D TESTS
 * ======================================================================
 * BEGIN 3D TESTS
 */

TEST(Embed2ConstructorTest3D, ZeroConstructorTest) {
  EmbVec3D vector;
  EXPECT_EQ(vector.x, 0);
  EXPECT_EQ(vector.y, 0);
  EXPECT_EQ(vector.z, 0);

  EXPECT_EQ(magn(vector), 0);
}

TEST(Embed2ConstructorTest3D, XYZConstructorTest) {
  EmbVec3D vector(5, -2, 7);
  EXPECT_EQ(vector.x, 5);
  EXPECT_EQ(vector.y, -2);
  EXPECT_EQ(vector.z, 7);
}

TEST(Embed2ConstructorTest3D, CopyConstructorTest) {
  EmbVec3D vector1(3, 6, 2);
  EmbVec3D vector2(vector1);

  EXPECT_EQ(vector2.x, 3);
  EXPECT_EQ(vector2.y, 6);
  EXPECT_EQ(vector2.z, 2);

  EmbVec3D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x, 0);
  EXPECT_EQ(vector2.y, 0);
  EXPECT_EQ(vector2.z, 0);
}

TEST(Embed2OperatorTest3D, AddTest) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {-1, 9, 6}},
      {{6, -7, 1}, {3, -2.4, 5}, {9, -9.4, 6}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    EmbVec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    EmbVec3D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(Embed2OperatorTest3D, AddChain) {
  EmbVec3D v1(3, -5, 1);
  EmbVec3D v2(4, -6, -1);
  EmbVec3D v3(2, 1, 1);
  EmbVec3D v4(-3, 6, -2);
  EmbVec3D res(6, -4, -1);

  EmbVec3D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(Embed2OperatorTest3D, AddInPlace) {
  EmbVec3D v1(2, 5, 8);
  v1 += EmbVec3D(-3, 4, -2);
  EmbVec3D res(-1, 9, 6);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest3D, SubtractTest) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {5, 1, 10}},
      {{6, -7, 1}, {3, -2.4, 5}, {3, -4.6, -4}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    EmbVec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    EmbVec3D sum = lhs - rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(Embed2OperatorTest3D, SubtractChain) {
  EmbVec3D v1(3, -5, 1);
  EmbVec3D v2(4, -6, -1);
  EmbVec3D v3(2, 1, 1);
  EmbVec3D v4(-3, 6, -2);
  EmbVec3D res(0, -6, 3);

  EmbVec3D sum = v1 - v2 - v3 - v4;
  EXPECT_EQ(sum, res);
}

TEST(Embed2OperatorTest3D, SubtractInPlace) {
  EmbVec3D v1(2, 5, 8);
  v1 -= EmbVec3D(-3, 4, -2);
  EmbVec3D res(5, 1, 10);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest3D, NegativeOfAVector) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{2, 5, 8}, {-2, -5, -8}},
      {{6, -7, -8}, {-6, 7, 8}},
      {{-4, 2, 6}, {4, -2, -6}},
      {{-5, -2, 0}, {5, 2, 0}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(-num, res);
  }
}

TEST(Embed2OperatorTest3D, PositiveOfAVector) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{2, 5, 8}, {2, 5, 8}},
      {{6, -7, -8}, {6, -7, -8}},
      {{-4, 2, 6}, {-4, 2, 6}},
      {{-5, -2, 0}, {-5, -2, 0}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(+num, res);
  }
}

TEST(Embed2OperatorTest3D, ScalarMultiplication) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{-3, -4, 8}, {5, -1, -1}, {-15, -20, 40}},
      {{3, 4.5, 2}, {2.5, -1, -1}, {7.5, 11.25, 5.0}},
  };
  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    float rhs = testcase[1][0];
    EmbVec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    EmbVec3D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(Embed2OperatorTest3D, DotProduct) {
  EmbVec3D lhs(2, 5, 6);
  EmbVec3D rhs(-3, -4, 2);

  float product = dot(lhs, rhs);
  float product2 = dot(rhs, lhs);
  EXPECT_EQ(product, -14);
  EXPECT_EQ(product, product2);
}

TEST(Embed2OperatorTest3D, ScalarMultiplyInPlace) {
  EmbVec3D v1(2, 5, 8);
  v1 *= 3;
  EmbVec3D res(6, 15, 24);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest3D, CrossProduct) {
  EmbVec3D v1(2, 3, 5);
  EmbVec3D v2(1, 2, 3);
  EmbVec3D res(-1, -1, 1);

  EXPECT_EQ(cross(v1, v2), res);
  EXPECT_EQ(cross(v2, v1), -res);
}

TEST(Embed2OperatorTest3D, ScalarDivision) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{-3, -4, 5}, {5, -1, -1}, {-0.6, -0.8, 1.0}},
      {{35, 42, 49}, {7, -1, -1}, {5, 6, 7}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    float rhs = testcase[1][0];
    EmbVec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    EmbVec3D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(Embed2OperatorTest3D, ScalarDivideInPlace) {
  EmbVec3D v1(-3, -4, 5);
  v1 /= 5;
  EmbVec3D res(-0.6, -0.8, 1);

  EXPECT_EQ(v1, res);
}

TEST(Embed2OperatorTest3D, EqualityTest) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{-3, -4, -5}, {-3, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.2}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(Embed2OperatorTest3D, InequalityTest) {
  std::vector<std::vector<std::vector<float>>> tests{
      {{-3, -4, -5}, {300, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.3}},
  };

  for (const auto &testcase : tests) {
    EmbVec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    EmbVec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(Embed2XYMagnitudeAngleMatchTest3D, TestMagnitudeGivenXYZ) {
  EmbVec3D vector(4.612, -3.322, 2.552);
  float magnn = magn(vector);

  EXPECT_LT(std::abs(magnn - 6.230484), 0.001);
}

TEST(Embed2XYMagnitudeAngleMatchTest3D, TestAlphaGivenXYZ) {
  EmbVec3D vector(-3, 2, -6);
  float ang = alpha(vector);

  EXPECT_LT(std::abs(ang - 2.014), 0.001);
}

TEST(Embed2XYMagnitudeAngleMatchTest3D, TestBetaGivenXYZ) {
  EmbVec3D vector(-3, 2, -6);
  float ang = beta(vector);

  EXPECT_LT(std::abs(ang - 1.281), 0.001);
}

TEST(Embed2XYMagnitudeAngleMatchTest3D, TestGammaGivenXYZ) {
  EmbVec3D vector(-3, 2, -6);
  float ang = gamma(vector);

  EXPECT_LT(std::abs(ang - 2.600), 0.001);
}

TEST(Embed2NormalizeTest3D, TestNormalize) {
  EmbVec3D vector(2, -3, -6);
  vector = normalize(vector);

  EXPECT_EQ(vector, EmbVec3D(2 / 7.0, -3 / 7.0, -6 / 7.0));
}

TEST(Embed2RotationTest3D, AlphaRotation) {
  std::vector<std::vector<float>> tests{
      {3, 4, 0, M_PI / 2, 3, 0, 4},
      {3, 4, 0, -M_PI / 2, 3, 0, -4},
      {3, 2.8284, 2.8284, M_PI / 4, 3, 0, 4},
      {3, 2.8284, 2.8284, -M_PI / 4, 3, 4, 0}};

  for (const auto &testcase : tests) {
    EmbVec3D vector(testcase[0], testcase[1], testcase[2]);
    EmbVec3D vectorp(testcase[4], testcase[5], testcase[6]);

    EmbVec3D rotated = rotateAlpha(vector, testcase[3]);

    EXPECT_LT(std::abs(vectorp.x - rotated.x), 0.001);
    EXPECT_LT(std::abs(vectorp.y - rotated.y), 0.001);
    EXPECT_LT(std::abs(vectorp.z - rotated.z), 0.001);
  }
}

TEST(Embed2RotationTest3D, BetaRotation) {
  std::vector<std::vector<float>> tests{
      {4, 3, 0, M_PI / 2, 0, 3, -4},
      {4, 3, 0, -M_PI / 2, 0, 3, 4},
      {2.8284, 3, 2.8284, M_PI / 4, 4, 3, 0},
      {2.8284, 3, 2.8284, -M_PI / 4, 0, 3, 4}};

  for (const auto &testcase : tests) {
    EmbVec3D vector(testcase[0], testcase[1], testcase[2]);
    EmbVec3D vectorp(testcase[4], testcase[5], testcase[6]);

    EmbVec3D rotated = rotateBeta(vector, testcase[3]);

    EXPECT_LT(std::abs(vectorp.x - rotated.x), 0.001);
    EXPECT_LT(std::abs(vectorp.y - rotated.y), 0.001);
    EXPECT_LT(std::abs(vectorp.z - rotated.z), 0.001);
  }
}

TEST(Embed2RotationTest3D, GammaRotation) {
  std::vector<std::vector<float>> tests{
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
    EmbVec3D vector(testcase[0], testcase[1], testcase[2]);
    EmbVec3D vectorp(testcase[4], testcase[5], testcase[6]);

    EmbVec3D rotated = rotateGamma(vector, testcase[3]);

    EXPECT_LT(std::abs(vectorp.x - rotated.x), 0.001);
    EXPECT_LT(std::abs(vectorp.y - rotated.y), 0.001);
    EXPECT_LT(std::abs(vectorp.z - rotated.z), 0.001);
  }
}

TEST(Embed2IsZeroTest, IsZeroTestNonZeroDimensionVector) {
  svector::EmbVec3D v{2, 5, 3};
  EXPECT_TRUE(!isZero(v));

  svector::EmbVec3D v2{0, 0, 0};
  EXPECT_TRUE(isZero(v2));
}
