// Copyright 2023 Kozlov Aleksey

#include <iostream>
#include <string>

#include "include/vector-distances_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
