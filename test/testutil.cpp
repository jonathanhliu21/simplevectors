#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

TEST(OperatorTestUtil, DotTest2D) {
  svector::Vector2D lhs(2, 5);
  svector::Vector2D rhs(-3, -4);

  double product = svector::dot(lhs, rhs);
  double product2 = svector::dot(rhs, lhs);
  EXPECT_EQ(product, -26);
  EXPECT_EQ(product2, product);
}

TEST(OperatorTestUtil, DotTest3D) {
  svector::Vector3D lhs(2, 5, 6);
  svector::Vector3D rhs(-3, -4, 2);

  double product = svector::dot(lhs, rhs);
  double product2 = svector::dot(rhs, lhs);
  EXPECT_EQ(product, -14);
  EXPECT_EQ(product, product2);
}

TEST(XYMagnitudeTestUtil, TestMagnitudeGivenXY) {
  svector::Vector2D vector(4.612, -3.322);
  double magn = svector::magn(vector);
  double magn_r = std::round(magn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 5.684);
}

TEST(XYMagnitudeTestUtil, TestMagnitudeGivenXYZ) {
  svector::Vector3D vector(4.612, -3.322, 2.552);
  double magn = svector::magn(vector);
  double magn_r = std::round(magn * 1000.0) / 1000.0;

  EXPECT_EQ(magn_r, 6.230);
}

TEST(NormalizeTestUtil, TestNormalize2D) {
  svector::Vector2D vector(3, 4);
  vector = svector::normalize(vector);

  EXPECT_EQ(vector, svector::Vector2D(0.6, 0.8));
}

TEST(NormalizeTestUtil, TestNormalize3D) {
  svector::Vector3D vector(2, -3, -6);
  vector = svector::normalize(vector);

  EXPECT_EQ(vector, svector::Vector3D(2 / 7.0, -3 / 7.0, -6 / 7.0));
}

TEST(XYZTestUtil, GetTest2D) {
  svector::Vector2D v(3, 5);
  EXPECT_EQ(svector::x(v), 3);
  EXPECT_EQ(svector::y(v), 5);
}

TEST(XYZTestUtil, SetTest2D) {
  svector::Vector2D v;

  svector::x(v, 3);
  svector::y(v, 5);

  EXPECT_EQ(svector::x(v), 3);
  EXPECT_EQ(svector::y(v), 5);
}

TEST(XYZTestUtil, GetTest3D) {
  svector::Vector3D v(3, 5, 6);
  EXPECT_EQ(svector::x(v), 3);
  EXPECT_EQ(svector::y(v), 5);
  EXPECT_EQ(svector::z(v), 6);
}

TEST(XYZTestUtil, SetTest3D) {
  svector::Vector3D v;

  svector::x(v, 3);
  svector::y(v, 5);
  svector::z(v, 6);

  EXPECT_EQ(svector::x(v), 3);
  EXPECT_EQ(svector::y(v), 5);
  EXPECT_EQ(svector::z(v), 6);
}

TEST(AngleTestUtil, AngleTest2D) {
  std::vector<std::vector<double>> tests{
      {4.5, 2.3, 0.472},
      {-3.4, 5.44, 2.129},
      {-0.35, -4.44, -1.649},
      {6.2, -3, -0.451},
  };

  for (auto testcase : tests) {
    svector::Vector2D vector(testcase[0], testcase[1]);
    double ang = svector::angle(vector);
    double ang_r = std::round(ang * 1000.0) / 1000.0;

    EXPECT_EQ(ang_r, testcase[2]);
  }
}

TEST(RotationTestUtil, RotateTest2D) {
  std::vector<std::vector<double>> tests{
      {1, 0, M_PI / 6, 0.866, 0.5},     {1, 1, M_PI / 4, 0, 1.414},
      {1.732, 1, M_PI / 3, 0, 2},       {0, 1, M_PI / 4, -0.707, 0.707},
      {-1, 0, M_PI / 3, -0.5, -0.866},  {-0.5, -0.866, M_PI / 6, 0, -1},
      {0, -1, M_PI / 4, 0.707, -0.707}, {0.707, -0.707, M_PI / 4, 1, 0},
  };

  for (auto testcase : tests) {
    svector::Vector2D vector(testcase[0], testcase[1]);
    svector::Vector2D vectorp(testcase[3], testcase[4]);

    svector::Vector2D rotated = svector::rotate(vector, testcase[2]);

    EXPECT_EQ(std::round(vectorp.x() * 1000) / 1000,
              std::round(rotated.x() * 1000) / 1000);
    EXPECT_EQ(std::round(vectorp.y() * 1000) / 1000,
              std::round(rotated.y() * 1000) / 1000);
  }
}
