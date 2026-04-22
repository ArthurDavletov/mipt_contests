#include <iostream>
#include <string>

struct Node {
  explicit Node(int p_value) : value(p_value), prior(rand()) {
  }
  explicit Node() : prior(rand()) {
  }
  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  int prior;
};

class Treap {
 public:
  void GetMin() {
    auto runner = root_;
    if (!runner) {
      return;
    }
    while (runner->left) {
      runner = runner->left;
    }
    std::cout << runner->value << std::endl;
  }

  void GetMax() {
    auto runner = root_;
    if (!runner) {
      return;
    }
    while (runner->right) {
      runner = runner->right;
    }
    std::cout << runner->value << std::endl;
  }

  bool Find(int value) {
    auto runner = root_;
    while (runner) {
      if (value == runner->value) {
        return true;
      }
      if (value > runner->value) {
        runner = runner->right;
      } else {
        runner = runner->left;
      }
    }
    return false;
  }

  void Push(int value) {
    root_ = Push(root_, value);
    size_++;
  }

  void Pop(int value) {
    Pop(root_, value);
  }

  void Clear() {
    Clear(root_);
    root_ = nullptr;
    size_ = 0;
  }

  ~Treap() {
    Clear();
  }

 private:
  std::pair<Node*, Node*> Split(Node* runner, int key) {
    if (!runner) {
      return std::pair<Node*, Node*>(nullptr, nullptr);
    }
    if (key > runner->value) {
      auto t = Split(runner->right, key);
      runner->right = t.first;
      return std::pair<Node*, Node*>(runner, t.second);
    }
    auto t = Split(runner->left, key);
    runner->left = t.second;
    return std::pair<Node*, Node*>(t.first, runner);
  }

  Node* Merge(Node* l, Node* r) {
    if (!l) {
      return r;
    }
    if (!r) {
      return l;
    }
    if (l->prior > r->prior) {
      l->right = Merge(l->right, r);
      return l;
    }
    r->left = Merge(l, r->left);
    return r;
  }

  void Clear(Node* runner) {
    if (runner) {
      Clear(runner->left);
      Clear(runner->right);
      delete runner;
      size_--;
    }
  }

  Node* Push(Node* node, int key) {
    auto t = Split(node, key);
    auto new_node = new Node(key);
    return Merge(Merge(t.first, new_node), t.second);
  }

  void Pop(Node* node, int key, Node* parent = nullptr) {
    if (!node) {
      return;
    }
    if (!parent) {
      parent = node;
    }
    if (key > node->value) {
      Pop(node->right, key, node);
    }
    if (key < node->value) {
      Pop(node->left, key, node);
    }
    if (parent->left && parent->left->value == key) {
      parent->left = Merge(node->left, node->right);
      delete node;
      size_--;
      return;
    }
    if (parent->right && parent->right->value == key) {
      parent->right = Merge(node->left, node->right);
      // delete node;
      size_--;
      return;
    }
  }

  Node* root_ = nullptr;
  size_t size_ = 0;
};

int main() {
  Treap treap;
  std::string command;
  int n, value;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> command;
    if (command == "get_min") {
      treap.GetMin();
    } else if (command == "get_max") {
      treap.GetMax();
    } else if (command == "find") {
      std::cin >> value;
      if (treap.Find(value)) {
        std::cout << "TRUE" << std::endl;
      } else {
        std::cout << "FALSE" << std::endl;
      }
    } else if (command == "push") {
      std::cin >> value;
      treap.Push(value);
    } else if (command == "pop") {
      std::cin >> value;
      treap.Pop(value);
    }
  }
  return 0;
}
