// Copyright 2023 Kozlov Aleksey

#ifndef MODULES_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_
#define MODULES_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_

#include <array>
#include <string>
#include <vector>

class NumericInterval {
 public:
  NumericInterval();
  NumericInterval(int _leftBorder, int _rightBorder, bool _rightInclude,
                  bool _leftInclude);

  std::vector<int> getBorderPoint() const;
  std::vector<int> getAllIntegerPoint() const;
  bool containsInterval(const NumericInterval& b) const;
  bool containsIntegerRange(const std::vector<int>& b) const;
  bool overlapsRange(const NumericInterval& b) const;

  bool operator==(const NumericInterval& z) const;
  bool operator!=(const NumericInterval& z) const;

 private:
  int leftBorder;
  int rightBorder;
  bool leftInclude;
  bool rightInclude;
  std::array<int, 4> _interval;
};

#endif  // MODULES_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_
