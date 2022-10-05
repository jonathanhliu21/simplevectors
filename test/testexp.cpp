#define SVECTOR_EXPERIMENTAL_FEATURES

#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#include <set>

TEST(CompareTest, CompareSameDimensionsLtGt) {
  svector::Vector<3> v1{3, 5, 1};
  svector::Vector<3> v2{4, 5, 1};

  EXPECT_TRUE(v1 < v2);
  EXPECT_TRUE(v2 > v1);

  v1 = {4, 5, 9};
  v2 = {4, 8, 3};

  EXPECT_TRUE(v1 < v2);
  EXPECT_TRUE(v2 > v1);

  v1 = {4, 5, 2};
  v2 = {4, 5, 3};

  EXPECT_TRUE(v1 < v2);
  EXPECT_TRUE(v2 > v1);
}

TEST(CompareTest, CompareSameDimensionsLeGe) {
  svector::Vector<3> v1{3, 5, 1};
  svector::Vector<3> v2{4, 5, 1};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);

  v1 = {4, 5, 9};
  v2 = {4, 8, 3};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);

  v1 = {4, 5, 2};
  v2 = {4, 5, 3};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);

  v1 = {4, 5, 3};
  v2 = {4, 5, 3};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);
}

TEST(CompareTest, CompareDifferentDimensionsLtGt) {
  svector::Vector<3> v1{3, 5, 1};
  svector::Vector<4> v2{3, 5, 1};

  EXPECT_TRUE(v1 < v2);
  EXPECT_TRUE(v2 > v1);

  v1 = {999, 999, 999};
  v2 = {-999, -999, -999};

  EXPECT_TRUE(v1 < v2);
  EXPECT_TRUE(v2 > v1);
}

TEST(CompareTest, CompareDifferentDimensionsLeGe) {
  svector::Vector<3> v1{3, 5, 1};
  svector::Vector<4> v2{3, 5, 1};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);

  v1 = {999, 999, 999};
  v2 = {-999, -999, -999};

  EXPECT_TRUE(v1 <= v2);
  EXPECT_TRUE(v2 >= v1);
}

TEST(CompareTest, SetTest) {
  std::set<svector::Vector<4>> s_test;
  s_test.insert({3, -1, 2, 6});
  s_test.insert({3, -1, 2, 6});
  EXPECT_EQ(s_test.size(), 1);
  EXPECT_NE(s_test.find({3, -1, 2, 6}), s_test.end());
  EXPECT_EQ(s_test.find({5, -6, 2, 6}), s_test.end());

  s_test.insert({5, -6, 2, 6});
  EXPECT_EQ(s_test.size(), 2);
  EXPECT_NE(s_test.find({3, -1, 2, 6}), s_test.end());
  EXPECT_NE(s_test.find({5, -6, 2, 6}), s_test.end());

  s_test.erase({3, -1, 2, 6});
  EXPECT_EQ(s_test.size(), 1);
  EXPECT_EQ(s_test.find({3, -1, 2, 6}), s_test.end());
  EXPECT_NE(s_test.find({5, -6, 2, 6}), s_test.end());
}
