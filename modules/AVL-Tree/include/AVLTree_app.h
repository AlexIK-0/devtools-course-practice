// Copyright 2023 Matveyev Sergey

#ifndef MODULES_AVL_TREE_INCLUDE_AVLTREE_APP_H_
#define MODULES_AVL_TREE_INCLUDE_AVLTREE_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_AVL_TREE_INCLUDE_AVLTREE_APP_H_
