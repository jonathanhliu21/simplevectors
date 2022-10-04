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
