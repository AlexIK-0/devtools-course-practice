// Copyright 2023 KUZNETSOV_SERGEY

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(KUZNETSOV_SERGEY_ComplexNumberTest, Equality_Test) {
  ComplexNumber a(4.0, 2.0);
  ComplexNumber b(4.0, 2.0);
  ASSERT_TRUE(a == b);
}

TEST(KUZNETSOV_SERGEY_ComplexNumberTest, Real_Test) {
  double re = 5.0;
  ComplexNumber x(re, -2.0);
  ASSERT_EQ(x.getRe(), re);
}

TEST(KUZNETSOV_SERGEY_ComplexNumberTest, Imaginary_Test) {
  double im = 7.5;
  ComplexNumber x(3.2, im);
  ASSERT_EQ(x.getIm(), im);
}

TEST(KUZNETSOV_SERGEY_ComplexNumberTest, Constructor_Test) {
  double re = 2.3, im = 3.1;
  ComplexNumber x(re, im);
  EXPECT_EQ(x.getRe(), re);
  EXPECT_EQ(x.getIm(), im);
}
