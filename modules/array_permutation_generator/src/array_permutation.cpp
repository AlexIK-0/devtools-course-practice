// Copyright 2023 Asoskov Mikhail

#include "include/array_permutation.h"

void ArrayPermutaionGenerator::Generator(const std::vector<int>& numbers,
                                int start,
                                std::vector<std::vector<int>>* result) {
    int countNumbers = numbers.size();

    std::vector<int> localNumbers = numbers;

    if (start == countNumbers - 1) {
        result->push_back(localNumbers);
        return;
    }

    for (int i = start; i < countNumbers; i++) {
        std::swap(localNumbers[start], localNumbers[i]);
        Generator(localNumbers, start + 1, result);
        std::swap(localNumbers[start], localNumbers[i]);
    }
}
