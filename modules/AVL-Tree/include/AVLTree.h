// Copyright 2023 Ermolaev Danila

#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>

template <typename TData>
struct AVLNode {
  int height;
  AVLNode* left;
  AVLNode* right;
  TData value;
  AVLNode() : height(0), left(nullptr), right(nullptr), value() {}
  explicit AVLNode(TData value)
      : height(0), left(nullptr), right(nullptr), value(value) {}
};

template <typename TData>
class AVLTree {
 public:
  AVLTree();
  AVLTree(const AVLTree& other);
  ~AVLTree();
  AVLTree& operator=(const AVLTree& other);
  bool contains(const TData& value) const;
  void insert(const TData& value);
  void remove(const TData& value);
  const TData& find_min() const;
  const TData& find_max() const;
  void print_tree(std::ostream& os = std::cout) const;
  bool is_empty() const;
  void make_empty();
  bool test_func();

 private:
  AVLNode<TData>* root;
  void preorderInsert(AVLNode<TData>* current);
  void insertRecurse(const TData& value, AVLNode<TData>*(&currNode));
  AVLNode<TData>* singleLeftShift(AVLNode<TData>* node);
  int findHeight(AVLNode<TData>* node) const;
  int max(int a, int b);
  void balance(AVLNode<TData>*(&node));
  AVLNode<TData>* singleRightShift(AVLNode<TData>* node);
  void removeRecurse(const TData& value, AVLNode<TData>*(&current));
  TData& recurse_find_min(AVLNode<TData>* node) const;
  TData& recurse_find_max(AVLNode<TData>* node) const;
  void printRecurse(AVLNode<TData>* node, int count, std::ostream& os) const;
  void emptyRecurse(AVLNode<TData>*(&node));
  bool containRecurse(AVLNode<TData>* node, const TData& value) const;
};

template <typename TData>
AVLTree<TData>::AVLTree() : root(nullptr) {}

template <typename TData>
AVLTree<TData>::AVLTree(const AVLTree& other) : root(nullptr) {
  if (other.root != nullptr) {
    this->preorderInsert(other.root);
  }
}

template <typename TData>
AVLTree<TData>::~AVLTree() {
  make_empty();
}

template <typename TData>
AVLTree<TData>& AVLTree<TData>::operator=(const AVLTree& other) {
  if (this == &other) {
    return *this;
  }
  this->make_empty();

  if (other.root == nullptr) {
    this->root = nullptr;
    return *this;
  }

  this->preorderInsert(other.root);
  return *this;
}

template <typename TData>
bool AVLTree<TData>::contains(const TData& value) const {
  return containRecurse(root, value);
}

template <typename TData>
bool AVLTree<TData>::containRecurse(AVLNode<TData>* node,
                                    const TData& value) const {
  if (node) {
    if (node->value == value) {
      return true;
    } else if (value < node->value) {
      // return containRecurse(node->left, value);
    } else if (value > node->value) {
      return containRecurse(node->right, value);
    }
  }

  return false;
}

template <typename TData>
void AVLTree<TData>::insert(const TData& value) {
  insertRecurse(value, root);
}

template <typename TData>
void AVLTree<TData>::insertRecurse(const TData& value,
                                   AVLNode<TData>*(&currNode)) {
  if (currNode == nullptr) {
    currNode = new AVLNode<TData>(value);
  } else if (value < currNode->value) {
    insertRecurse(value, currNode->left);
  } else if (value > currNode->value) {
    insertRecurse(value, currNode->right);
  }

  balance(currNode);
}

template <typename TData>
void AVLTree<TData>::remove(const TData& value) {
  removeRecurse(value, this->root);
}

template <typename TData>
void AVLTree<TData>::removeRecurse(const TData& value,
                                   AVLNode<TData>*(&current)) {
  if (!current) {
    return;
  }

  if (value == current->value) {
    if (current->left == nullptr && current->right == nullptr) {
      delete current;
      current = nullptr;
    } else if (current->left && current->right) {
      TData& minRight = recurse_find_min(current->right);
      current->value = minRight;
      removeRecurse(minRight, current->right);

    } else if (current->right || current->left) {
      AVLNode<TData>* temp = current;
      if (current->right) {
        current = current->right;
        delete temp;
      } else {
        current = current->left;
        delete temp;
      }
    }
  } else if (value < current->value) {
    removeRecurse(value, current->left);
  } else {
    removeRecurse(value, current->right);
  }

  balance(current);
}

template <typename TData>
const TData& AVLTree<TData>::find_min() const {
  return recurse_find_min(root);
}

template <typename TData>
TData& AVLTree<TData>::recurse_find_min(AVLNode<TData>* node) const {
  // if (!node) {
  //   throw std::invalid_argument("Tree is empty, no minimum value.");
  // }

  if (node->left == nullptr) {
    return node->value;
  }
  return recurse_find_min(node->left);
}

template <typename TData>
const TData& AVLTree<TData>::find_max() const {
  return recurse_find_max(this->root);
}

template <typename TData>
TData& AVLTree<TData>::recurse_find_max(AVLNode<TData>* node) const {
  // if (!node) {
  //   throw std::invalid_argument("Tree is empty, no maximum value.");
  // }

  if (node->right == nullptr) {
    return node->value;
  }

  return recurse_find_max(node->right);
}

template <typename TData>
void AVLTree<TData>::print_tree(std::ostream& os) const {
  if (this->root == nullptr) {
    os << "<empty>" << std::endl;
  }

  int count = -1;
  printRecurse(root, count, os);
}

template <typename TData>
void AVLTree<TData>::printRecurse(AVLNode<TData>* node, int count,
                                  std::ostream& os) const {
  if (node) {
    count++;

    printRecurse(node->right, count, os);

    if (node != root) {
      for (int i = 0; i < count * 2; i++) {
        os << " ";
      }
    }

    os << node->value << std::endl;
    printRecurse(node->left, count, os);
  }
}

template <typename TData>
bool AVLTree<TData>::is_empty() const {
  return (root == nullptr);
}

template <typename TData>
void AVLTree<TData>::make_empty() {
  emptyRecurse(root);
}

template <typename TData>
void AVLTree<TData>::emptyRecurse(AVLNode<TData>*(&node)) {
  if (node) {
    emptyRecurse(node->left);
    emptyRecurse(node->right);
    delete node;
  }

  node = nullptr;
}

template <typename TData>
int AVLTree<TData>::findHeight(AVLNode<TData>* node) const {
  return !node ? -1 : node->height;
}

template <typename TData>
int AVLTree<TData>::max(int a, int b) {
  return a > b ? a : b;
}

template <typename TData>
void AVLTree<TData>::preorderInsert(AVLNode<TData>* current) {
  if (current) {
    this->insert(current->value);
    this->preorderInsert(current->left);
    this->preorderInsert(current->right);
  }

  return;
}

template <typename TData>
void AVLTree<TData>::balance(AVLNode<TData>*(&node)) {
  if (!node) {
    return;
  }

  int factor = findHeight(node->left) - findHeight(node->right);

  if (factor < -1) {
    if (findHeight(node->right->right) >= findHeight(node->right->left)) {
      // node = singleLeftShift(node);
    } else {
      node->right = singleRightShift(node->right);
      node = singleLeftShift(node);
    }
  } else if (factor > 1) {
    if (findHeight(node->left->left) >= findHeight(node->left->right)) {
      // node = singleRightShift(node);
    } else {
      node->left = singleLeftShift(node->left);
      node = singleRightShift(node);
    }
  }

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
}

template <typename TData>
AVLNode<TData>* AVLTree<TData>::singleLeftShift(AVLNode<TData>* node) {
  AVLNode<TData>* nodeRight = node->right;

  node->right = nodeRight->left;
  nodeRight->left = node;

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
  nodeRight->height =
      max(findHeight(nodeRight->left), findHeight(nodeRight->right)) + 1;

  return nodeRight;
}

template <typename TData>
AVLNode<TData>* AVLTree<TData>::singleRightShift(AVLNode<TData>* node) {
  AVLNode<TData>* nodeLeft = node->left;

  node->left = nodeLeft->right;
  nodeLeft->right = node;

  node->height = max(findHeight(node->left), findHeight(node->right)) + 1;
  nodeLeft->height =
      max(findHeight(nodeLeft->left), findHeight(nodeLeft->right)) + 1;

  return nodeLeft;
}
