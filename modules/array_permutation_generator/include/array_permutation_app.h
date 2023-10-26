// Copyright 2023 Kozlov Aleksey

#ifndef MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_APP_H_
#define MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_ARRAY_PERMUTATION_GENERATOR_INCLUDE_ARRAY_PERMUTATION_APP_H_
