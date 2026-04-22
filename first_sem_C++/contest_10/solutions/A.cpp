#include <iostream>

struct Node {
  explicit Node(int p_value) : value(p_value) {
  }
  explicit Node(int p_value, Node* p_parent) : value(p_value), parent(p_parent) {
  }
  Node() = default;
  int value;
  Node* parent = nullptr;
  Node* left_child = nullptr;
  Node* right_child = nullptr;
};

class BinarySearchTree {
 public:
  void Push(int value) {
    auto parent_node = FindNode(value);
    if (!parent_node) {
      root_ = new Node(value);
      size_++;
      return;
    }
    if (parent_node->value == value) {
      return;
    }
    auto new_node = new Node(value, parent_node);
    size_++;
    if (value < parent_node->value) {
      parent_node->left_child = new_node;
    }
    if (value > parent_node->value) {
      parent_node->right_child = new_node;
    }
  }

  void Clear() {
    Clear(root_);
  }

  void Size() {
    std::cout << size_ << std::endl;
  }

  ~BinarySearchTree() {
    Clear();
  }

 private:
  Node* FindNode(int value) {
    auto runner = root_;
    while (runner && (runner->left_child || runner->right_child)) {
      if (value == runner->value) {
        return runner;
      }
      if (value <= runner->value) {
        if (!runner->left_child) {
          break;
        }
        runner = runner->left_child;
        continue;
      }
      if (!runner->right_child) {
        break;
      }
      runner = runner->right_child;
    }
    return runner;
  }

  void Clear(Node* runner) {
    if (runner) {
      if (runner->left_child) {
        Clear(runner->left_child);
      }
      if (runner->right_child) {
        Clear(runner->right_child);
      }
      delete runner;
    }
    root_ = nullptr;
    size_ = 0;
  }

  size_t size_ = 0;
  Node* root_ = nullptr;
};

int main() {
  BinarySearchTree bst;
  int number;
  std::cin >> number;
  while (number != 0) {
    bst.Push(number);
    std::cin >> number;
  }
  bst.Size();
  return 0;
}
