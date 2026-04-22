#include <iostream>
#include <string>

struct Node {
  explicit Node(int p_n, Node* p_next = nullptr) : value(p_n), next(p_next) {
  }
  int value;
  Node* next;
};

class Queue {
 public:
  void Push(int n) {
    auto new_node = new Node(n);
    if (back_) {
      back_->next = new_node;
    }
    back_ = new_node;
    if (!front_) {
      front_ = back_;
    }
    size_++;
    std::cout << "ok" << std::endl;
  }

  void Pop() {
    std::cout << front_->value << std::endl;
    auto next_node = front_->next;
    delete front_;
    front_ = next_node;
    if (!front_) {
      back_ = nullptr;
    }
    size_--;
  }

  void Front() {
    std::cout << front_->value << std::endl;
  }

  void Size() {
    std::cout << size_ << std::endl;
  }

  void Clear() {
    while (size_ > 0) {
      auto next_node = front_->next;
      delete front_;
      front_ = next_node;
      size_--;
    }
    back_ = nullptr;
    front_ = nullptr;
  }

  ~Queue() {
    Clear();
  }

 private:
  size_t size_ = 0;
  Node* front_ = nullptr;
  Node* back_ = nullptr;
};

int main() {
  std::string command;
  int m, n;
  Queue queue;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> command;
    if (command == "push") {
      std::cin >> n;
      queue.Push(n);
    } else if (command == "pop") {
      queue.Pop();
    } else if (command == "front") {
      queue.Front();
    } else if (command == "size") {
      queue.Size();
    } else if (command == "clear") {
      queue.Clear();
      std::cout << "ok" << std::endl;
    } else if (command == "exit") {
      std::cout << "bye" << std::endl;
      break;
    }
  }
  return 0;
}
