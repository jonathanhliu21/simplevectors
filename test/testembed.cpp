#include "simplevectors/embed.hpp"

#include <gtest/gtest.h>

#include <regex>
#include <utility>

using namespace svector;

TEST(EmbedConstructorTest2D, ZeroConstructorTest) {
  Vec2D vector;
  EXPECT_EQ(vector.x, 0);
  EXPECT_EQ(vector.y, 0);
  EXPECT_EQ(magn(vector), 0);
  EXPECT_EQ(angle(vector), 0);
}

TEST(EmbedConstructorTest2D, XYConstructorTest) {
  Vec2D vector(5, -2);
  EXPECT_EQ(vector.x, 5);
  EXPECT_EQ(vector.y, -2);
}

TEST(EmbedConstructorTest2D, CopyConstructorTest) {
  Vec2D vector1(3, 6);
  Vec2D vector2(vector1);

  EXPECT_EQ(vector2.x, 3);
  EXPECT_EQ(vector2.y, 6);

  Vec2D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x, 0);
  EXPECT_EQ(vector2.y, 0);
}

TEST(EmbedStringTest2D, StringTest) {
  Vec2D vector(3.52, -5.6);

  std::regex r("<3\\.520*, -5\\.60*>");

  EXPECT_TRUE(std::regex_match(toString(vector), r));
}

TEST(EmbedOperatorTest2D, AddTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {-1, 9}},
      {{6, -7}, {3, -2.4}, {9, -9.4}},
  };

  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    Vec2D rhs(testcase[1].first, testcase[1].second);
    Vec2D res(testcase[2].first, testcase[2].second);

    Vec2D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(EmbedOperatorTest2D, AddChain) {
  Vec2D v1(3, -5);
  Vec2D v2(4, -6);
  Vec2D v3(2, 1);
  Vec2D v4(-3, 6);
  Vec2D res(6, -4);

  Vec2D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(EmbedOperatorTest2D, AddInPlace) {
  Vec2D v1(2, 5);
  v1 += Vec2D(-3, 4);
  Vec2D res(-1, 9);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest2D, SubtractTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {5, 1}},
      {{6, -7}, {3, -2.4}, {3, -4.6}},
  };

  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    Vec2D rhs(testcase[1].first, testcase[1].second);
    Vec2D res(testcase[2].first, testcase[2].second);

    Vec2D difference = lhs - rhs;
    EXPECT_EQ(difference, res);
  }
}

TEST(EmbedOperatorTest2D, SubtractChain) {
  Vec2D v1(3, -5);
  Vec2D v2(4, -6);
  Vec2D v3(2, 1);
  Vec2D v4(-3, 6);
  Vec2D res(0, -6);

  Vec2D difference = v1 - v2 - v3 - v4;
  EXPECT_EQ(difference, res);
}

TEST(EmbedOperatorTest2D, SubtractInPlace) {
  Vec2D v1(2, 5);
  v1 -= Vec2D(-3, 4);
  Vec2D res(5, 1);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest2D, NegativeOfAVector) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-2, -5}},
      {{6, -7}, {-6, 7}},
      {{-4, 2}, {4, -2}},
      {{-5, -2}, {5, 2}},
  };

  for (const auto &testcase : tests) {
    Vec2D num(testcase[0].first, testcase[0].second);
    Vec2D res(testcase[1].first, testcase[1].second);

    EXPECT_EQ(-num, res);
  }
}

TEST(EmbedOperatorTest2D, ScalarMultiplication) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-15, -20}},
      {{3, 4.5}, {2.5, -1}, {7.5, 11.25}},
  };
  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    Vec2D res(testcase[2].first, testcase[2].second);

    Vec2D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(EmbedOperatorTest2D, DotProduct) {
  Vec2D lhs(2, 5);
  Vec2D rhs(-3, -4);

  double product = dot(lhs, rhs);
  double product2 = dot(rhs, lhs);
  EXPECT_EQ(product, -26);
  EXPECT_EQ(product2, product);
}

TEST(EmbedOperatorTest2D, ScalarMultiplyInPlace) {
  Vec2D v1(2, 5);
  v1 *= 5;
  Vec2D res(10, 25);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest2D, ScalarDivision) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-0.6, -0.8}},
      {{35, 42}, {7, -1}, {5, 6}},
  };

  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    Vec2D res(testcase[2].first, testcase[2].second);

    Vec2D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(EmbedOperatorTest2D, ScalarDivideInPlace) {
  Vec2D v1(-3, -4);
  v1 /= 5;
  Vec2D res(-0.6, -0.8);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest2D, EqualityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4}},
      {{35, 42}, {35, 42}},
  };

  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    Vec2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(EmbedOperatorTest2D, InequalityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4.1}},
      {{35, 42}, {19, 534}},
  };

  for (const auto &testcase : tests) {
    Vec2D lhs(testcase[0].first, testcase[0].second);
    Vec2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(EmbedXYMagnitudeAngleMatchTest2D, TestMagnitudeGivenXY) {
  Vec2D vector(4.612, -3.322);
  double magnn = magn(vector);
  double magn_r = std::round(magnn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 5.684);
}

TEST(EmbedXYMagnitudeAngleMatchTest2D, TestAngleGivenXY) {
  std::vector<std::vector<double>> tests{
      {4.5, 2.3, 0.472},
      {-3.4, 5.44, 2.129},
      {-0.35, -4.44, -1.649},
      {6.2, -3, -0.451},
  };

  for (const auto &testcase : tests) {
    Vec2D vector(testcase[0], testcase[1]);
    double ang = angle(vector);
    double ang_r = std::round(ang * 1000.0) / 1000.0;

    EXPECT_EQ(ang_r, testcase[2]);
  }
}

TEST(EmbedNormalizeTest2D, TestNormalize) {
  Vec2D vector(3, 4);
  vector = normalize(vector);

  EXPECT_EQ(vector, Vec2D(0.6, 0.8));
}

TEST(EmbedRotationTest2D, CounterclockwiseRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (const auto &testcase : tests) {
    Vec2D vector(testcase[0], testcase[1]);
    Vec2D vectorp(testcase[3], testcase[4]);

    Vec2D rotated = rotate(vector, testcase[2]);

    EXPECT_EQ(std::round(vectorp.x * 1000) / 1000,
              std::round(rotated.x * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y * 1000) / 1000,
              std::round(rotated.y * 1000) / 1000);
  }
}

TEST(EmbedRotationTest2D, ClockwiseRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (const auto &testcase : tests) {
    Vec2D vector(testcase[3], testcase[4]);
    Vec2D vectorp(testcase[0], testcase[1]);

    Vec2D rotated = rotate(vector, -testcase[2]);

    EXPECT_EQ(std::round(vectorp.x * 1000) / 1000,
              std::round(rotated.x * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y * 1000) / 1000,
              std::round(rotated.y * 1000) / 1000);
  }
}

/**
 * END 2D TESTS
 * ======================================================================
 * BEGIN 3D TESTS
 */

TEST(EmbedConstructorTest3D, ZeroConstructorTest) {
  Vec3D vector;
  EXPECT_EQ(vector.x, 0);
  EXPECT_EQ(vector.y, 0);
  EXPECT_EQ(vector.z, 0);

  EXPECT_EQ(magn(vector), 0);
}

TEST(EmbedConstructorTest3D, XYZConstructorTest) {
  Vec3D vector(5, -2, 7);
  EXPECT_EQ(vector.x, 5);
  EXPECT_EQ(vector.y, -2);
  EXPECT_EQ(vector.z, 7);
}

TEST(EmbedConstructorTest3D, CopyConstructorTest) {
  Vec3D vector1(3, 6, 2);
  Vec3D vector2(vector1);

  EXPECT_EQ(vector2.x, 3);
  EXPECT_EQ(vector2.y, 6);
  EXPECT_EQ(vector2.z, 2);

  Vec3D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x, 0);
  EXPECT_EQ(vector2.y, 0);
  EXPECT_EQ(vector2.z, 0);
}

TEST(EmbedStringTest3D, StringTest) {
  Vec3D vector(3.52, -5.6, 2.2);

  std::regex r("<3\\.520*, -5\\.60*, 2\\.20*>");

  EXPECT_TRUE(std::regex_match(toString(vector), r));
}

TEST(EmbedOperatorTest3D, AddTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {-1, 9, 6}},
      {{6, -7, 1}, {3, -2.4, 5}, {9, -9.4, 6}},
  };

  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    Vec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vec3D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(EmbedOperatorTest3D, AddChain) {
  Vec3D v1(3, -5, 1);
  Vec3D v2(4, -6, -1);
  Vec3D v3(2, 1, 1);
  Vec3D v4(-3, 6, -2);
  Vec3D res(6, -4, -1);

  Vec3D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(EmbedOperatorTest3D, AddInPlace) {
  Vec3D v1(2, 5, 8);
  v1 += Vec3D(-3, 4, -2);
  Vec3D res(-1, 9, 6);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest3D, SubtractTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-3, 4, -2}, {5, 1, 10}},
      {{6, -7, 1}, {3, -2.4, 5}, {3, -4.6, -4}},
  };

  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);
    Vec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vec3D sum = lhs - rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(EmbedOperatorTest3D, SubtractChain) {
  Vec3D v1(3, -5, 1);
  Vec3D v2(4, -6, -1);
  Vec3D v3(2, 1, 1);
  Vec3D v4(-3, 6, -2);
  Vec3D res(0, -6, 3);

  Vec3D sum = v1 - v2 - v3 - v4;
  EXPECT_EQ(sum, res);
}

TEST(EmbedOperatorTest3D, SubtractInPlace) {
  Vec3D v1(2, 5, 8);
  v1 -= Vec3D(-3, 4, -2);
  Vec3D res(5, 1, 10);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest3D, NegativeOfAVector) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{2, 5, 8}, {-2, -5, -8}},
      {{6, -7, -8}, {-6, 7, 8}},
      {{-4, 2, 6}, {4, -2, -6}},
      {{-5, -2, 0}, {5, 2, 0}},
  };

  for (const auto &testcase : tests) {
    Vec3D num(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vec3D res(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_EQ(-num, res);
  }
}

TEST(EmbedOperatorTest3D, ScalarMultiplication) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 8}, {5, -1, -1}, {-15, -20, 40}},
      {{3, 4.5, 2}, {2.5, -1, -1}, {7.5, 11.25, 5.0}},
  };
  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    Vec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vec3D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(EmbedOperatorTest3D, DotProduct) {
  Vec3D lhs(2, 5, 6);
  Vec3D rhs(-3, -4, 2);

  double product = dot(lhs, rhs);
  double product2 = dot(rhs, lhs);
  EXPECT_EQ(product, -14);
  EXPECT_EQ(product, product2);
}

TEST(EmbedOperatorTest3D, ScalarMultiplyInPlace) {
  Vec3D v1(2, 5, 8);
  v1 *= 3;
  Vec3D res(6, 15, 24);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest3D, CrossProduct) {
  Vec3D v1(2, 3, 5);
  Vec3D v2(1, 2, 3);
  Vec3D res(-1, -1, 1);

  EXPECT_EQ(cross(v1, v2), res);
  EXPECT_EQ(cross(v2, v1), -res);
}

TEST(EmbedOperatorTest3D, ScalarDivision) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, 5}, {5, -1, -1}, {-0.6, -0.8, 1.0}},
      {{35, 42, 49}, {7, -1, -1}, {5, 6, 7}},
  };

  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    double rhs = testcase[1][0];
    Vec3D res(testcase[2][0], testcase[2][1], testcase[2][2]);

    Vec3D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(EmbedOperatorTest3D, ScalarDivideInPlace) {
  Vec3D v1(-3, -4, 5);
  v1 /= 5;
  Vec3D res(-0.6, -0.8, 1);

  EXPECT_EQ(v1, res);
}

TEST(EmbedOperatorTest3D, EqualityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {-3, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.2}},
  };

  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(EmbedOperatorTest3D, InequalityTest) {
  std::vector<std::vector<std::vector<double>>> tests{
      {{-3, -4, -5}, {300, -4, -5}},
      {{35, 42, 2.2}, {35, 42, 2.3}},
  };

  for (const auto &testcase : tests) {
    Vec3D lhs(testcase[0][0], testcase[0][1], testcase[0][2]);
    Vec3D rhs(testcase[1][0], testcase[1][1], testcase[1][2]);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(EmbedXYMagnitudeAngleMatchTest3D, TestMagnitudeGivenXYZ) {
  Vec3D vector(4.612, -3.322, 2.552);
  double magnn = magn(vector);
  double magn_r = std::round(magnn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 6.230);
}

TEST(EmbedXYMagnitudeAngleMatchTest3D, TestAlphaGivenXYZ) {
  Vec3D vector(-3, 2, -6);
  double ang = getAlpha(vector);
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.014);
}

TEST(EmbedXYMagnitudeAngleMatchTest3D, TestBetaGivenXYZ) {
  Vec3D vector(-3, 2, -6);
  double ang = getBeta(vector);
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 1.281);
}

TEST(EmbedXYMagnitudeAngleMatchTest3D, TestGammaGivenXYZ) {
  Vec3D vector(-3, 2, -6);
  double ang = getGamma(vector);
  double ang_r = std::round(ang * 1000.0) / 1000.0;

  EXPECT_EQ(ang_r, 2.600);
}

TEST(EmbedNormalizeTest3D, TestNormalize) {
  Vec3D vector(2, -3, -6);
  vector = normalize(vector);

  EXPECT_EQ(vector, Vec3D(2 / 7.0, -3 / 7.0, -6 / 7.0));
}

TEST(EmbedRotationTest3D, AlphaRotation) {
  std::vector<std::vector<double>> tests{
      {3, 4, 0, M_PI / 2, 3, 0, 4},
      {3, 4, 0, -M_PI / 2, 3, 0, -4},
      {3, 2.8284, 2.8284, M_PI / 4, 3, 0, 4},
      {3, 2.8284, 2.8284, -M_PI / 4, 3, 4, 0}};

  for (const auto &testcase : tests) {
    Vec3D vector(testcase[0], testcase[1], testcase[2]);
    Vec3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vec3D rotated = rotateAlpha(vector, testcase[3]);

    EXPECT_EQ(std::round(vectorp.x * 1000) / 1000,
              std::round(rotated.x * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y * 1000) / 1000,
              std::round(rotated.y * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z * 1000) / 1000,
              std::round(rotated.z * 1000) / 1000);
  }
}

TEST(EmbedRotationTest3D, BetaRotation) {
  std::vector<std::vector<double>> tests{
      {4, 3, 0, M_PI / 2, 0, 3, -4},
      {4, 3, 0, -M_PI / 2, 0, 3, 4},
      {2.8284, 3, 2.8284, M_PI / 4, 4, 3, 0},
      {2.8284, 3, 2.8284, -M_PI / 4, 0, 3, 4}};

  for (const auto &testcase : tests) {
    Vec3D vector(testcase[0], testcase[1], testcase[2]);
    Vec3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vec3D rotated = rotateBeta(vector, testcase[3]);

    EXPECT_EQ(std::round(vectorp.x * 1000) / 1000,
              std::round(rotated.x * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y * 1000) / 1000,
              std::round(rotated.y * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z * 1000) / 1000,
              std::round(rotated.z * 1000) / 1000);
  }
}

TEST(EmbedRotationTest3D, GammaRotation) {
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
    Vec3D vector(testcase[0], testcase[1], testcase[2]);
    Vec3D vectorp(testcase[4], testcase[5], testcase[6]);

    Vec3D rotated = rotateGamma(vector, testcase[3]);

    EXPECT_EQ(std::round(vectorp.x * 1000) / 1000,
              std::round(rotated.x * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y * 1000) / 1000,
              std::round(rotated.y * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.z * 1000) / 1000,
              std::round(rotated.z * 1000) / 1000);
  }
}
