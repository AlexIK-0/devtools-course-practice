// Copyright 2023 Matveyev Sergey

#include "include/AVLTree_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/AVLTree.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }

  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    AVLTree<int> testavl;
    testavl.insert(atoi(argv[2]));
    testavl.insert(atoi(argv[3]));
    testavl.insert(atoi(argv[4]));
    testavl.insert(atoi(argv[5]));
    testavl.insert(atoi(argv[6]));

    os << testavl.contains(20);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    AVLTree<int> testavl;
    testavl.insert(atoi(argv[2]));
    testavl.insert(atoi(argv[3]));
    testavl.insert(atoi(argv[4]));
    testavl.insert(atoi(argv[5]));
    testavl.insert(atoi(argv[6]));

    os << testavl.find_max();
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    AVLTree<int> testavl;
    testavl.insert(atoi(argv[2]));
    testavl.insert(atoi(argv[3]));
    testavl.insert(atoi(argv[4]));
    testavl.insert(atoi(argv[5]));
    testavl.insert(atoi(argv[6]));

    os << testavl.find_min();
    std::cout << os.str() << std::endl;
    return "success";
  }

  return this->argument_error();
}

std::string CLPApplication::help() {
  std::string help = "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
