// Copyright 2023 Kozlov Aleksey

#include <gtest/gtest.h>

#include <vector>

#include "include/numeric_interval.h"

TEST(Numeric_Interval_Test,
     Correctness_Of_The_Default_Constructor) {
  ASSERT_NO_THROW(NumericInterval a);
}

TEST(Numeric_Interval_Test,
     Correctnes_Of_The_Constructor_With_Parameters_1) {
  ASSERT_NO_THROW(NumericInterval a(1, 7, true, true));
}

TEST(Numeric_Interval_Test,
     Correctnes_Of_The_Constructor_With_Parameters_2) {
  ASSERT_NO_THROW(NumericInterval a(-7, 7, false, true));
}

TEST(Numeric_Interval_Test,
     Correctnes_Of_The_Constructor_With_Parameters_3) {
  ASSERT_NO_THROW(NumericInterval a(-15, -3, true, false));
}

TEST(Numeric_Interval_Test,
     Can_Return_The_Border_Points_1) {
  int a = 1;
  int b = 20;
  bool c = true;
  bool d = false;
  NumericInterval z(a, b, c, d);

  std::vector<int> res = z.getBorderPoint();

  ASSERT_TRUE(a == res[0] && b - 1 == res[1]);
}

TEST(Numeric_Interval_Test,
     Can_Return_The_Border_Points_2) {
  int a = -10;
  int b = 20;
  bool c = true;
  bool d = true;
  NumericInterval z(a, b, c, d);

  std::vector<int> res = z.getBorderPoint();

  ASSERT_TRUE(a == res[0] && b == res[1]);
}

TEST(Numeric_Interval_Test,
     Can_Return_The_Border_Points_3) {
  int a = -4;
  int b = 20;
  bool c = false;
  bool d = true;
  NumericInterval z(a, b, c, d);

  std::vector<int> res = z.getBorderPoint();

  ASSERT_TRUE(a + 1 == res[0] && b == res[1]);
}

TEST(Numeric_Interval_Test,
     Can_Return_Can_Return_All_Integer_Points_1) {
  int a = 1;
  int b = 20;
  bool c = true;
  bool d = false;
  NumericInterval z(a, b, c, d);

  bool flag = true;
  std::vector<int> res = z.getAllIntegerPoint();
  int i = 0;
  int size = res.size();
  if (size == b - a) {
    for (int j = a; j < b; j++) {
      if (res[i++] != j) {
        flag = false;
      }
    }
  } else {
    flag = false;
  }

  ASSERT_TRUE(flag);
}

TEST(Numeric_Interval_Test,
     Can_Return_Can_Return_All_Integer_Points_2) {
  int a = -10;
  int b = 0;
  bool c = true;
  bool d = true;
  NumericInterval z(a, b, c, d);

  bool flag = true;
  std::vector<int> res = z.getAllIntegerPoint();
  int i = 0;
  int size = res.size();
  if (size == b - a + 1) {
    for (int j = a; j <= b; j++) {
      if (res[i++] != j) {
        flag = false;
      }
    }
  } else {
    flag = false;
  }

  ASSERT_TRUE(flag);
}

TEST(Numeric_Interval_Test,
     Can_Return_Can_Return_All_Integer_Points_3) {
  int a = -6;
  int b = 3;
  bool c = false;
  bool d = true;
  NumericInterval z(a, b, c, d);

  bool flag = true;
  std::vector<int> res = z.getAllIntegerPoint();
  int i = 0;
  int size = res.size();
  if (size == b - a) {
    for (int j = a + 1; j <= b; j++) {
      if (res[i++] != j) {
        flag = false;
      }
    }
  } else {
    flag = false;
  }

  ASSERT_TRUE(flag);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Another_Interval_1) {
  NumericInterval a(3, 15, true, false);
  NumericInterval b(4, 9, false, false);

  bool res = a.containsInterval(b);

  ASSERT_TRUE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Another_Interval_2) {
  NumericInterval a(3, 8, true, true);
  NumericInterval b(4, 9, false, false);

  bool res = a.containsInterval(b);

  ASSERT_FALSE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Another_Interval_3) {
  NumericInterval a(4, 8, false, true);
  NumericInterval b(4, 5, true, true);

  bool res = a.containsInterval(b);

  ASSERT_FALSE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Another_Interval_4) {
  NumericInterval a(0, 5, true, false);
  NumericInterval b(4, 5, true, true);

  bool res = a.containsInterval(b);

  ASSERT_FALSE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Integer_Range_1) {
  NumericInterval a(3, 8, true, false);
  std::vector<int> range = {5, 3, 6, 8};

  bool res = a.containsIntegerRange(range);

  ASSERT_FALSE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Inclusion_Of_Integer_Range_2) {
  NumericInterval a(3, 8, true, false);
  std::vector<int> range = {3, 6, 4, 5};

  bool res = a.containsIntegerRange(range);

  ASSERT_TRUE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Intersection_With_Another_Interval_1) {
  NumericInterval a(3, 8, true, false);
  NumericInterval b(1, 8, false, false);

  bool res = a.overlapsRange(b);

  ASSERT_TRUE(res);
}

TEST(Numeric_Interval_Test,
     Correctly_Detects_The_Intersection_With_Another_Interval_2) {
  NumericInterval a(3, 8, true, false);
  NumericInterval b(8, 13, true, false);

  bool res = a.overlapsRange(b);

  ASSERT_FALSE(res);
}

TEST(Numeric_Interval_Test,
     Correctness_Of_The_Equality_Operator_1) {
  NumericInterval a(3, 8, true, false);
  NumericInterval b(3, 8, true, false);

  ASSERT_TRUE(a == b);
}

TEST(Numeric_Interval_Test,
     The_Correctness_Of_The_Operator_Is_Not_Equality_2) {
  NumericInterval a(-3, 8, true, true);
  NumericInterval b(-3, 8, true, true);

  ASSERT_FALSE(a != b);
}
