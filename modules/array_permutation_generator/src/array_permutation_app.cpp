// Copyright 2023 Kozlov Aleksey

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/array_permutations.h"
#include "include/array_permutations_app.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char **argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help") {
    return this->help();
  }

  if (std::string(argv[1]) == "--test2") {
    // Arrange
    std::vector<int> numbers = {atoi(argv[2]), atoi(argv[3])};
    std::vector<std::vector<int>> result;
    ArrayPermutaionGenerator::Generator(numbers, 0, &result);

    // Act
    // std::vector<std::vector<int>> expectResult = { {-10, -20}, {-20, -10} };

    os << result[0][0] << ", " << result[0][1] << "; " << result[1][0] << ", "
       << result[1][1];
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[1]) == "--test3") {
    // Arrange
    std::vector<int> numbers = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
    std::vector<std::vector<int>> result;
    ArrayPermutaionGenerator::Generator(numbers, 0, &result);

    os << "Size: " << result.size();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[1]) == "--test5") {
    // Arrange
    std::vector<int> numbers = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),
                                atoi(argv[5]), atoi(argv[6])};
    std::vector<std::vector<int>> result;
    ArrayPermutaionGenerator::Generator(numbers, 0, &result);

    os << "Size: " << result.size();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[1]) == "--test1") {
    // Arrange
    std::vector<int> numbers = {atoi(argv[2])};
    std::vector<std::vector<int>> result;
    ArrayPermutaionGenerator::Generator(numbers, 0, &result);

    os << result[0][0];
    std::cout << os.str() << std::endl;
    return "success";
  }

  std::string CLPApplication::help() {
    std::string help = "This program generates permutations";
    return help;
  }

  std::string CLPApplication::argument_error() {
    std::string error = "Invalid argument amount, try --help or -h commands";
    return error;
  }
}
