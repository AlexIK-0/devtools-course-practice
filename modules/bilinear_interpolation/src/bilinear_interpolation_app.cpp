// Copyright 2023 Asoskov Mikhail

#include "../include/bilinear_interpolation_app.h"

void BilinearInterpolationApp::help() {
    message.append("This is application for bilinear interpolation.\n")
    .append("Please provide arguments in the following format:\n")
    .append("row1: <1 element> <2 element> ... <n element> </n>\n")
    .append("row2: <1 element> <2 element> ... <n element> </n>\n")
    .append("row3: <1 element> <2 element> ... <n element> </n> ...\n")
    .append("rown: <1 element> <2 element> ... <n element> </n> <factor>\n")
    .append("All elements must be integer!");
}

std::vector<int> ToOneDimensionalVector
                (const std::vector<std::vector<int>>& image) {
    std::vector<int> result;
    for (const auto& row : image) {
        for (const auto& element : row) {
            result.push_back(element);
        }
    }
    return result;
}

std::string VectorToString(std::vector<int> vector) {
    std::string result = "";
    for (int elem : vector) {
        result.append(std::to_string(elem));
    }
    return result;
}

std::string BilinearInterpolationApp::operator()
                        (int argc, const char** argv) {
    if (argc <= 1) {
        help();
        return message;
    }

    std::vector<std::vector<int>> image;

    std::vector<int> current;
    for (int i = 1; i < argc - 1; i++) {
        std::string element = argv[i];

        if (element == "/n") {
            image.push_back(current);
            current.clear();
        } else {
            current.push_back(std::atoi(argv[i]));
        }
    }

    int factor = std::atoi(argv[argc - 1]);

    BilinearInterpolator bi;
    bi.bilinearInterpolation(&image, factor);

    std::vector<int> res = ToOneDimensionalVector(image);

    message = VectorToString(res);
    return message;
}

