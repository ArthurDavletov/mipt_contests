#include <iostream>
#include <string>

int Max(int first, int second) {
  if (first > second) {
    return first;
  }
  return second;
}

struct Node {
  Node() = default;
  explicit Node(int p_value) : value(p_value) {
    left = nullptr;
    right = nullptr;
    height = 1;
    counter = 1;
  }
  int value;
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
    root_ = Push(root_, x);
  }

  void Pop(int key) {
    root_ = Pop(root_, key);
  }

  void GetMin() {
    auto node = GetMin(root_);
    if (node) {
      std::cout << node->value << std::endl;
    }
  }

  void GetMax() {
    auto node = GetMax(root_);
    if (node) {
      std::cout << node->value << std::endl;
    }
  }

  void Clear() {
    Clear(root_);
  }

  int GetSize() {
    return size_;
  }

  ~AVL() {
    Clear();
  }

 private:
  Node* Push(Node* node, int x) {
    if (!node) {
      size_++;
      return new Node(x);
    }
    if (node->value == x) {
      node->counter++;
      return node;
    }
    if (x > node->value) {
      node->right = Push(node->right, x);
    } else {
      node->left = Push(node->left, x);
    }
    return Balance(node);
  }

  Node* LeftRotation(Node* node) {
    auto b = node->right;
    auto c = b->left;

    node->right = c;
    b->left = node;
    FixHeight(node);
    FixHeight(b);
    return b;
  }

  Node* BigLeftRotation(Node* node) {
    auto b = node->right;
    auto c = b->left;
    auto p = c->left;
    auto q = c->right;

    node->right = p;
    b->left = q;
    c->left = node;
    c->right = b;
    FixHeight(node);
    FixHeight(b);
    FixHeight(c);
    return c;
  }

  Node* RightRotation(Node* node) {
    auto b = node->left;
    auto c = b->right;

    node->left = c;
    b->right = node;
    FixHeight(node);
    FixHeight(b);
    return b;
  }

  Node* BigRightRotation(Node* node) {
    auto b = node->left;
    auto c = b->right;
    auto p = c->left;
    auto q = c->right;

    b->right = p;
    node->left = q;
    c->left = b;
    c->right = node;

    FixHeight(node);
    FixHeight(b);
    FixHeight(c);
    return c;
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

  Node* Balance(Node* node) {
    FixHeight(node);
    if (!node) {
      return nullptr;
    }
    if (BFactor(node) == -2) {
      if (BFactor(node->right) <= 0) {
        return LeftRotation(node);
      }
      return BigLeftRotation(node);
    }
    if (BFactor(node) == 2) {
      if (BFactor(node->left) >= 0) {
        return RightRotation(node);
      }
      return BigRightRotation(node);
    }
    return node;
  }

  Node* GetMin(Node* node) {
    if (!node) {
      return nullptr;
    }
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  Node* GetMax(Node* node) {
    if (!node) {
      return nullptr;
    }
    while (node->right) {
      node = node->right;
    }
    return node;
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

  Node* Pop(Node* node, int key) {
    if (!node) {
      return nullptr;
    }
    if (key > node->value) {
      node->right = Pop(node->right, key);
    } else if (key < node->value) {
      node->left = Pop(node->left, key);
    } else {
      if (node->counter > 1) {
        node->counter--;
        return node;
      }
      if (!node->left) {
        Node* right = node->right;
        delete node;
        size_--;
        return right;
      }
      if (!node->right) {
        Node* left = node->left;
        delete node;
        size_--;
        return left;
      }
      Node* max_node = GetMax(node->left);
      node->value = max_node->value;
      node->left = Pop(node->left, max_node->value);
    }
    return Balance(node);
  }

  void FixHeight(Node* runner) {
    if (runner) {
      runner->height = 1 + Max(GetHeight(runner->left), GetHeight(runner->right));
    }
  }

  size_t size_ = 0;
  Node* root_ = nullptr;
};

int main() {
  AVL tree;
  int n, x;
  std::string command;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> command;
    if (command == "get_min") {
      tree.GetMin();
    } else if (command == "get_max") {
      tree.GetMax();
    } else if (command == "find") {
      std::cin >> x;
      if (tree.Find(x)) {
        std::cout << "TRUE" << std::endl;
      } else {
        std::cout << "FALSE" << std::endl;
      }
    } else if (command == "push") {
      std::cin >> x;
      tree.Push(x);
    } else if (command == "pop") {
      std::cin >> x;
      tree.Pop(x);
    }
  }
  return 0;
}
