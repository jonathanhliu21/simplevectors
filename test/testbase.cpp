#define SVECTOR_EXPERIMENTAL_FEATURES_

#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <regex>
#include <set>
#include <stdexcept>

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

TEST(IteratorTestV, FwdIterationTest) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (svector::Vector<10>::iterator it = v.begin(); it != v.end(); it++) {
    arr.push_back(*it);
  }

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, BkwdIterationTest) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (svector::Vector<10>::reverse_iterator it = v.rbegin(); it != v.rend();
       it++) {
    arr.push_back(*it);
  }

  std::reverse(arr.begin(), arr.end());

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, CopyTest) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  std::copy(v.begin(), v.end(), std::back_inserter(arr));

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, NonConstRangeLoopTest) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (double component : v) {
    arr.push_back(component);
  }

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, NonConstRangeLoopTestR) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (double &component : v) {
    arr.push_back(component);
  }

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, ConstRangeLoopTest) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (const double component : v) {
    arr.push_back(component);
  }

  EXPECT_EQ(arr, res);
}

TEST(IteratorTestV, ConstRangeLoopTestR) {
  std::vector<double> arr;
  std::vector<double> res{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};
  svector::Vector<10> v{2, 4, 2, 1, 2, 6, 4, 3, 4, 4};

  for (const double &component : v) {
    arr.push_back(component);
  }

  EXPECT_EQ(arr, res);
}

TEST(AtTestV, AtTest) {
  svector::Vector<3> v{2, 5, 3};
  EXPECT_EQ(v.at(0), 2);
  EXPECT_EQ(v.at(1), 5);
  EXPECT_EQ(v.at(2), 3);
}

TEST(AtTestV, OutOfBounds) {
  svector::Vector<3> v{2, 5, 3};
  EXPECT_THROW(v.at(4), std::out_of_range);
}

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
