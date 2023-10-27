// Copyright 2023 ASOSKOV MIKHAIL

#ifndef MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_APP_H_
#define MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_APP_H_

#include <vector>
#include <string>

#include "../include/bilinear_interpolation.h"

class BilinearInterpolationApp {
 public:
    void help();
    std::string operator()(int argc, const char** argv);

 private:
    std::string message;
};

#endif  // MODULES_BILINEAR_INTERPOLATION_INCLUDE_BILINEAR_INTERPOLATION_APP_H_
