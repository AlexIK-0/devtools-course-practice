// Copyright 2023 Asoskov Mikhail

#ifndef MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_H_
#define MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_H_

#include <vector>
#include <random>

namespace ArrayPermutaionGenerator {

    void Generator(const std::vector<int>& numbers,
                    int start,
                    std::vector<std::vector<int>>* result);
}

#endif  // MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_H_
