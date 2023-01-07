#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <regex>
#include <utility>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(ConstructorTest2D, ZeroConstructorTest) {
  svector::Vector2D vector;
  EXPECT_EQ(vector.x(), 0);
  EXPECT_EQ(vector.y(), 0);
  EXPECT_EQ(vector.magn(), 0);
  EXPECT_EQ(vector.angle(), 0);
}

TEST(ConstructorTest2D, XYConstructorTest) {
  svector::Vector2D vector(5, -2);
  EXPECT_EQ(vector.x(), 5);
  EXPECT_EQ(vector.y(), -2);
}

TEST(ConstructorTest2D, CopyConstructorTest) {
  svector::Vector2D vector1(3, 6);
  svector::Vector2D vector2(vector1);

  EXPECT_EQ(vector2.x(), 3);
  EXPECT_EQ(vector2.y(), 6);

  svector::Vector2D vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2.x(), 0);
  EXPECT_EQ(vector2.y(), 0);
}

TEST(SetterTest2D, SetterXTest) {
  svector::Vector2D vector1{2, 5};
  vector1.x(4);

  EXPECT_EQ(vector1.x(), 4);
  EXPECT_EQ(vector1.y(), 5);
}

TEST(SetterTest2D, SetterYTest) {
  svector::Vector2D vector1{2, 5};
  vector1.y(4);

  EXPECT_EQ(vector1.x(), 2);
  EXPECT_EQ(vector1.y(), 4);
}

TEST(StringTest2D, StringTest) {
  svector::Vector2D vector(3.52, -5.6);

  std::regex r("<3\\.520*, -5\\.60*>");

  EXPECT_TRUE(std::regex_match(vector.toString(), r));
}

TEST(OperatorTest2D, AddTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {-1, 9}},
      {{6, -7}, {3, -2.4}, {9, -9.4}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    svector::Vector2D rhs(testcase[1].first, testcase[1].second);
    svector::Vector2D res(testcase[2].first, testcase[2].second);

    svector::Vector2D sum = lhs + rhs;
    EXPECT_EQ(sum, res);
  }
}

TEST(OperatorTest2D, AddChain) {
  svector::Vector2D v1(3, -5);
  svector::Vector2D v2(4, -6);
  svector::Vector2D v3(2, 1);
  svector::Vector2D v4(-3, 6);
  svector::Vector2D res(6, -4);

  svector::Vector2D sum = v1 + v2 + v3 + v4;
  EXPECT_EQ(sum, res);
}

TEST(OperatorTest2D, AddInPlace) {
  svector::Vector2D v1(2, 5);
  v1 += svector::Vector2D(-3, 4);
  svector::Vector2D res(-1, 9);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, SubtractTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-3, 4}, {5, 1}},
      {{6, -7}, {3, -2.4}, {3, -4.6}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    svector::Vector2D rhs(testcase[1].first, testcase[1].second);
    svector::Vector2D res(testcase[2].first, testcase[2].second);

    svector::Vector2D difference = lhs - rhs;
    EXPECT_EQ(difference, res);
  }
}

TEST(OperatorTest2D, SubtractChain) {
  svector::Vector2D v1(3, -5);
  svector::Vector2D v2(4, -6);
  svector::Vector2D v3(2, 1);
  svector::Vector2D v4(-3, 6);
  svector::Vector2D res(0, -6);

  svector::Vector2D difference = v1 - v2 - v3 - v4;
  EXPECT_EQ(difference, res);
}

TEST(OperatorTest2D, SubtractInPlace) {
  svector::Vector2D v1(2, 5);
  v1 -= svector::Vector2D(-3, 4);
  svector::Vector2D res(5, 1);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, NegativeOfAVector) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{2, 5}, {-2, -5}},
      {{6, -7}, {-6, 7}},
      {{-4, 2}, {4, -2}},
      {{-5, -2}, {5, 2}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D num(testcase[0].first, testcase[0].second);
    svector::Vector2D res(testcase[1].first, testcase[1].second);

    EXPECT_EQ(-num, res);
  }
}

TEST(OperatorTest2D, ScalarMultiplication) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-15, -20}},
      {{3, 4.5}, {2.5, -1}, {7.5, 11.25}},
  };
  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    svector::Vector2D res(testcase[2].first, testcase[2].second);

    svector::Vector2D product = lhs * rhs;
    EXPECT_EQ(product, res);
  }
}

TEST(OperatorTest2D, DotProduct) {
  svector::Vector2D lhs(2, 5);
  svector::Vector2D rhs(-3, -4);

  double product = lhs.dot(rhs);
  double product2 = rhs.dot(lhs);
  EXPECT_EQ(product, -26);
  EXPECT_EQ(product2, product);
}

TEST(OperatorTest2D, ScalarMultiplyInPlace) {
  svector::Vector2D v1(2, 5);
  v1 *= 5;
  svector::Vector2D res(10, 25);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, ScalarDivision) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {5, -1}, {-0.6, -0.8}},
      {{35, 42}, {7, -1}, {5, 6}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    double rhs = testcase[1].first;
    svector::Vector2D res(testcase[2].first, testcase[2].second);

    svector::Vector2D quotient = lhs / rhs;
    EXPECT_EQ(quotient, res);
  }
}

TEST(OperatorTest2D, ScalarDivideInPlace) {
  svector::Vector2D v1(-3, -4);
  v1 /= 5;
  svector::Vector2D res(-0.6, -0.8);

  EXPECT_EQ(v1, res);
}

TEST(OperatorTest2D, EqualityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4}},
      {{35, 42}, {35, 42}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    svector::Vector2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs == rhs);
  }
}

TEST(OperatorTest2D, InequalityTest) {
  std::vector<std::vector<std::pair<double, double>>> tests{
      {{-3, -4}, {-3, -4.1}},
      {{35, 42}, {19, 534}},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D lhs(testcase[0].first, testcase[0].second);
    svector::Vector2D rhs(testcase[1].first, testcase[1].second);

    EXPECT_TRUE(lhs != rhs);
  }
}

TEST(XYMagnitudeAngleMatchTest2D, TestMagnitudeGivenXY) {
  svector::Vector2D vector(4.612, -3.322);
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

  for (const auto &testcase : tests) {
    svector::Vector2D vector(testcase[0], testcase[1]);
    double ang = vector.angle();
    double ang_r = std::round(ang * 1000.0) / 1000.0;

    EXPECT_EQ(ang_r, testcase[2]);
  }
}

TEST(ToComponentTest2D, TestConvertToPair) {
  svector::Vector2D vector(3.5, -6.2);
  std::pair<double, double> testPair =
      vector.componentsAs<std::pair<double, double>>();

  EXPECT_EQ(testPair, std::make_pair(3.5, -6.2));
}

TEST(ToComponentTest2D, TestConvertToStruct) {
  svector::Vector2D vector(3.5, -6.2);

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
  svector::Vector2D vector(3, 4);
  vector = vector.normalize();

  EXPECT_EQ(vector, svector::Vector2D(0.6, 0.8));
}

TEST(RotationTest2D, CounterclockwiseRotation) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (const auto &testcase : tests) {
    svector::Vector2D vector(testcase[0], testcase[1]);
    svector::Vector2D vectorp(testcase[3], testcase[4]);

    svector::Vector2D rotated = vector.rotate(testcase[2]);

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

  for (const auto &testcase : tests) {
    svector::Vector2D vector(testcase[3], testcase[4]);
    svector::Vector2D vectorp(testcase[0], testcase[1]);

    svector::Vector2D rotated = vector.rotate(-testcase[2]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
  }
}
