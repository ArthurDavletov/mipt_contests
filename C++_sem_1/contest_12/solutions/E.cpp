#include <iostream>
#include <random>

int Max(int first, int second) {
  if (first > second) {
    return first;
  }
  return second;
}

struct Node {
  Node() = default;
  explicit Node(int p_value, Node* p_parent = nullptr) : value(p_value), parent(p_parent) {
    left = nullptr;
    right = nullptr;
    height = 1;
    counter = 1;
  }
  int value;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;
  int counter = 1;
};

class AVL {
 public:
  bool Find(int x) {
    auto node = FindNode(x);
    return node && node->value == x;
  }

  void Push(int x) {
    auto parent = FindNode(x);
    if (!parent) {
      root_ = new Node(x);
      size_++;
      return;
    }
    if (parent->value == x) {
      parent->counter++;
      return;
    }
    auto new_node = new Node(x, parent);
    size_++;
    if (x > parent->value) {
      parent->right = new_node;
    } else {
      parent->left = new_node;
    }
    if (!parent->left || !parent->right) {
      FixHeight(new_node);
    }
    Balance(new_node);
  }

  void Clear() {
    Clear(root_);
  }

  int GetSize() {
    return size_;
  }

  bool IsBalanced() {
    return IsBalanced(root_);
  }

  void PrintHalfFullNodes() {
    SearchHalfFullNodes(root_);
  }

  void PrintCounter() {
    SearchNodes(root_);
  }

  ~AVL() {
    Clear();
  }

 private:
  void LeftRotation(Node* node) {
    auto b = node->right;
    auto c = b->left;

    node->right = c;
    if (c) {
      c->parent = node;
    }
    b->left = node;
    b->parent = node->parent;
    if (node->parent) {
      if (node->parent->left == node) {
        node->parent->left = b;
      } else {
        node->parent->right = b;
      }
    } else {
      root_ = b;
    }
    node->parent = b;
    FixHeight(node);
    FixHeight(b);
  }

  void BigLeftRotation(Node* node) {
    auto b = node->right;
    auto c = b->left;
    auto p = c->left;
    auto q = c->right;

    node->right = p;
    if (p) {
      p->parent = node;
    }
    b->left = q;
    if (q) {
      q->parent = b;
    }
    c->left = node;
    c->parent = node->parent;
    if (node->parent) {
      if (node->parent->left == node) {
        node->parent->left = c;
      } else {
        node->parent->right = c;
      }
    } else {
      root_ = c;
    }
    node->parent = c;
    c->right = b;
    b->parent = c;

    FixHeight(node);
    FixHeight(b);
    FixHeight(c);
  }

  void RightRotation(Node* node) {
    auto b = node->left;
    auto c = b->right;

    node->left = c;
    if (c) {
      c->parent = node;
    }
    b->right = node;
    b->parent = node->parent;
    if (node->parent) {
      if (node->parent->left == node) {
        node->parent->left = b;
      } else {
        node->parent->right = b;
      }
    } else {
      root_ = b;
      b->parent = nullptr;
    }
    node->parent = b;
    FixHeight(node);
    FixHeight(b);
  }

  void BigRightRotation(Node* node) {
    auto b = node->left;
    auto c = b->right;
    auto p = c->left;
    auto q = c->right;

    b->right = p;
    if (p) {
      p->parent = b;
    }
    node->left = q;
    if (q) {
      q->parent = node;
    }
    b->parent = c;
    c->left = b;
    c->right = node;
    c->parent = node->parent;
    if (node->parent) {
      if (node->parent->left == node) {
        node->parent->left = c;
      } else {
        node->parent->right = c;
      }
    } else {
      root_ = c;
    }
    node->parent = c;

    FixHeight(node);
    FixHeight(b);
    FixHeight(c);
  }

  int GetHeight(Node* node) {
    if (!node) {
      return 0;
    }
    return node->height;
  }

  int BFactor(Node* node) {
    return GetHeight(node->left) - GetHeight(node->right);
  }

  void Balance(Node* node) {
    if (!node) {
      return;
    }
    if (BFactor(node) == -2) {
      if (BFactor(node->right) <= 0) {
        LeftRotation(node);
      } else {
        BigLeftRotation(node);
      }
    } else if (BFactor(node) == 2) {
      if (BFactor(node->left) >= 0) {
        RightRotation(node);
      } else {
        BigRightRotation(node);
      }
    }
    if (node->parent) {
      Balance(node->parent);
    }
  }

  void Clear(Node* runner) {
    if (runner) {
      Clear(runner->left);
      Clear(runner->right);
      delete runner;
      runner = nullptr;
      size_--;
    }
  }

  Node* FindNode(int x) {
    auto runner = root_;
    while (runner && (runner->left || runner->right)) {
      if (x == runner->value) {
        return runner;
      }
      if (x > runner->value) {
        if (!runner->right) {
          break;
        }
        runner = runner->right;
      } else {
        if (!runner->left) {
          break;
        }
        runner = runner->left;
      }
    }
    return runner;
  }

  void FixHeight(Node* runner) {
    if (runner) {
      runner->height = 1 + Max(GetHeight(runner->left), GetHeight(runner->right));
    }
  }

  bool IsBalanced(Node* runner) {
    if (runner) {
      auto left = IsBalanced(runner->left);
      auto right = IsBalanced(runner->right);
      return left && right && abs(BFactor(runner)) < 2;
    }
    return true;
  }

  void SearchHalfFullNodes(Node* runner) {
    if (runner) {
      SearchHalfFullNodes(runner->left);
      if ((!runner->left && runner->right) || (runner->left && !runner->right)) {
        std::cout << runner->value << std::endl;
      }
      SearchHalfFullNodes(runner->right);
    }
  }

  void SearchNodes(Node* runner) {
    if (runner) {
      SearchNodes(runner->left);
      std::cout << runner->value << ' ' << runner->counter << std::endl;
      SearchNodes(runner->right);
    }
  }

  size_t size_ = 0;
  Node* root_ = nullptr;
};

int main() {
  AVL tree;
  int x;
  std::cin >> x;
  while (x != 0) {
    tree.Push(x);
    std::cin >> x;
  }
  tree.PrintCounter();
  return 0;
}
