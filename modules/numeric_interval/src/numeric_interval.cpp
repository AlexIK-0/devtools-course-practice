// Copyright 2023 Kozlov Aleksey

#include "include/numeric_interval.h"

#include <cstring>
#include <string>
#include <vector>

using std::vector;

NumericInterval::NumericInterval()
    : leftBorder(0),
      rightBorder(0),
      leftInclude(true),
      rightInclude(true),
      _interval(std::array<int, 4>()) {}

NumericInterval::NumericInterval(int _leftBorder, int _rightBorder,
                                 bool _leftInclude, bool _rightInclude)
    : leftBorder(_leftBorder),
      rightBorder(_rightBorder),
      leftInclude(_leftInclude),
      rightInclude(_rightInclude),
      _interval(std::array<int, 4>()) {}

std::vector<int> NumericInterval::getBorderPoint() const {
  int beginning = leftInclude ? leftBorder : leftBorder + 1;
  int end = rightInclude ? rightBorder : rightBorder - 1;
  return {beginning, end};
}

std::vector<int> NumericInterval::getAllIntegerPoint() const {
  std::vector<int> border = this->getBorderPoint();
  std::vector<int> res;
  for (int i = border[0]; i <= border[1]; i++) {
    res.push_back(i);
  }
  return res;
}

bool NumericInterval::containsInterval(const NumericInterval& b) const {
  if (leftBorder <= b.leftBorder && rightBorder >= b.rightBorder) {
    if ((!leftInclude && b.leftInclude && leftBorder == b.leftBorder) ||
        (!rightInclude && b.rightInclude && rightBorder == b.rightBorder)) {
      return false;
    }
    return true;
  }
  return false;
}

bool NumericInterval::containsIntegerRange(
    const std::vector<int>& range) const {
  std::vector<int> border = this->getBorderPoint();
  int count_point = range.size();
  for (int i = 0; i < count_point; i++) {
    if (border[0] > range[i] || border[1] < range[i]) {
      return false;
    }
  }
  return true;
}

bool NumericInterval::overlapsRange(const NumericInterval& b) const {
  std::vector<int> border_a = this->getBorderPoint();
  int beginning = b.leftInclude ? b.leftBorder : b.leftBorder + 1;
  int end = b.rightInclude ? b.rightBorder : b.rightBorder - 1;
  if (border_a[0] > end || border_a[1] < beginning) {
    return false;
  }
  return true;
}

bool NumericInterval::operator==(const NumericInterval& b) const {
  bool res = true;
  return res;
}

bool NumericInterval::operator!=(const NumericInterval& b) const {
  return !(*this == b);
}
