#include <iostream>
#include <string>

struct Node {
  int value;
  Node* prev = nullptr;
};

class Stack {
 public:
  void Push(int n) {
    last_ = new Node{n, last_};
    size_++;
    std::cout << "ok" << std::endl;
  }

  void Pop() {
    std::cout << last_->value << std::endl;
    Node* new_last = last_->prev;
    delete last_;
    last_ = new_last;
    size_--;
  }

  void Back() {
    std::cout << last_->value << std::endl;
  }

  void Size() {
    std::cout << size_ << std::endl;
  }

  void Clear() {
    while (size_ > 0) {
      Node* runner = last_->prev;
      delete last_;
      last_ = runner;
      size_--;
    }
  }

  ~Stack() {
    Clear();
  }

 private:
  Node* last_ = nullptr;
  size_t size_ = 0;
};

int main() {
  Stack stack;
  int m, n;
  std::string command;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> command;
    if (command == "push") {
      std::cin >> n;
      stack.Push(n);
    } else if (command == "pop") {
      stack.Pop();
    } else if (command == "back") {
      stack.Back();
    } else if (command == "size") {
      stack.Size();
    } else if (command == "clear") {
      stack.Clear();
      std::cout << "ok" << std::endl;
    } else if (command == "exit") {
      std::cout << "bye" << std::endl;
      stack.Clear();
      break;
    }
  }
  stack.Clear();
  return 0;
}
