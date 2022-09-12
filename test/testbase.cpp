#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#include <regex>

TEST(ConstructorTestV, ZeroConstructorTest) {
  svector::Vector<1> v;
  EXPECT_EQ(v[0], 0);

  svector::Vector<20> v2;
  for (int i = 0; i < 20; i++) {
    EXPECT_EQ(v2[i], 0);
  }
}

TEST(ConstructorTestV, InitListTest) {
  svector::Vector<5> v{3, 5, 2, 3.5, 6};
  EXPECT_EQ(v[0], 3);
  EXPECT_EQ(v[1], 5);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 3.5);
  EXPECT_EQ(v[4], 6);

  svector::Vector2D v2{3, 5};
  EXPECT_EQ(v2[0], 3);
  EXPECT_EQ(v2[1], 5);

  svector::Vector3D v3{3, 5, 0};
  EXPECT_EQ(v3[0], 3);
  EXPECT_EQ(v3[1], 5);
  EXPECT_EQ(v3[2], 0);
}

TEST(ConstructorTestV, TooFewInitListTest) {
  svector::Vector<5> v{3, 5, 2};
  EXPECT_EQ(v[0], 3);
  EXPECT_EQ(v[1], 5);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 0);
  EXPECT_EQ(v[4], 0);
}

TEST(ConstructorTestV, TooManyInitListTest) {
  svector::Vector<5> v{3, 5, 2, 3.5, 6, 39, 2, 6};
  EXPECT_EQ(v[0], 3);
  EXPECT_EQ(v[1], 5);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 3.5);
  EXPECT_EQ(v[4], 6);
}

TEST(ConstructorTestV, CopyConstructorTest) {
  svector::Vector<2> vector1{3, 6};
  svector::Vector<2> vector2(vector1);

  EXPECT_EQ(vector2[0], 3);
  EXPECT_EQ(vector2[1], 6);

  svector::Vector<2> vector3;
  vector2 = vector3;

  EXPECT_EQ(vector2[0], 0);
  EXPECT_EQ(vector2[1], 0);
}

TEST(StringTestV, StringTest) {
  svector::Vector<5> vector{3.52, -5.6, 3, 4.2, 1.1};

  std::regex r("<3\.520*, -5\.60*, 3\.0*, 4\.20*, 1\.10*>");

  EXPECT_TRUE(std::regex_match(vector.toString(), r)) << vector.toString();
}

TEST(NumDimensionTestV, NumDimensionTest) {
  svector::Vector<3> v1;
  EXPECT_EQ(v1.numDimensions(), 3);

  svector::Vector<1> v2;
  EXPECT_EQ(v2.numDimensions(), 1);

  svector::Vector<10> v3;
  EXPECT_EQ(v3.numDimensions(), 10);
}

TEST(EachComponentAsTestV, EachComponentAsTest) {
  struct Test {
    int i;

    Test() {}

    Test(double d) { i = static_cast<int>(d); }
  };

  svector::Vector<3> v1{3, -5.2, 3.3};

  auto arr = v1.eachComponentAs<Test>();
  EXPECT_EQ(arr[0].i, 3);
  EXPECT_EQ(arr[1].i, -5);
  EXPECT_EQ(arr[2].i, 3);
}
