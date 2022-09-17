#include "simplevectors/vectors.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <regex>
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
