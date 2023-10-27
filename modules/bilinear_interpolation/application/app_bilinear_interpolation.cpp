// Copyright 2023 Asoskov Mikhail

#include <stdio.h>

#include "../include/bilinear_interpolation_app.h"

int main(int argc, const char** argv) {
    BilinearInterpolationApp BilinearInterpolationApp;
    std::string output = BilinearInterpolationApp(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
