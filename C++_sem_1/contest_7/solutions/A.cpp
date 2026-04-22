#include <iostream>
#include <string>
#include <cmath>

struct Node {
  explicit Node(int p_value, int p_index = 0) {
    value = p_value;
    index = p_index;
    if (index == 0) {
      index = ++index_id;
    }
  }
  Node() = default;
  int value;
  int index;
  static int index_id;
};

int Node::index_id;

class Heap {
 public:
  void Insert(int n, int index = 0) {
    auto new_node = new Node(n, index);
    std::cout << "ok" << std::endl;
    size_++;
    for (int i = 0; i < layers_count_; i++) {
      for (int j = 0; j < pow(2, i); j++) {
        if (!layers_[i][j]) {
          layers_[i][j] = new_node;
          SiftUp(i, j);
          SiftDown(i, j);
          return;
        }
      }
    }
    Increase();
    layers_[layers_count_ - 1][0] = new_node;
  }

  void ExtractMin() {
    if (layers_count_ > 0 && layers_[0][0]) {
      std::cout << layers_[0][0]->value << std::endl;
      for (int i = layers_count_ - 1; i >= 0; i--) {
        for (int j = 0; j < static_cast<int>(pow(2, i)); j++) {
          if (layers_[i][j]) {
            std::swap(layers_[0][0], layers_[i][j]);
            delete layers_[i][j];
            layers_[i][j] = nullptr;
            SiftDown(0, 0);
            return;
          }
        }
      }
    }
    std::cout << "error" << std::endl;
  }

  void Delete(int x, bool to_print = true) {
    for (int i = 0; i < layers_count_; i++) {
      for (int j = 0; j < static_cast<int>(pow(2, i)); j++) {
        if (layers_[i][j] && layers_[i][j]->index == x) {
          for (int i_last = layers_count_ - 1; i_last >= 0; i_last--) {
            for (int j_last = 0; j_last < static_cast<int>(pow(2, i_last)); j_last++) {
              if (layers_[i_last][j_last]) {
                std::swap(layers_[i][j], layers_[i_last][j_last]);
                delete layers_[i_last][j_last];
                layers_[i_last][j_last] = nullptr;
                SiftDown(i, j);
                if (to_print) {
                  std::cout << "ok" << std::endl;
                }
                return;
              }
            }
          }
        }
      }
    }
    if (to_print) {
      std::cout << "error" << std::endl;
    }
  }

  void Change(int x, int n) {
    for (int i = 0; i < layers_count_; i++) {
      for (int j = 0; j < static_cast<int>(pow(2, i)); j++) {
        if (layers_[i][j] && layers_[i][j]->index == x) {
          auto index = layers_[i][j]->index;
          Delete(index, false);
          Insert(n, index);
          std::cout << "ok" << std::endl;
          return;
        }
      }
    }
    std::cout << "error" << std::endl;
  }

  void GetMin() {
    if (layers_count_ > 0 && layers_[0][0]) {
      std::cout << layers_[0][0]->value << std::endl;
    } else {
      std::cout << "error" << std::endl;
    }
  }

  void Size() {
    std::cout << size_ << std::endl;
  }

  void Clear() {
    for (int i = 0; i < layers_count_; i++) {
      for (int j = 0; j < static_cast<int>(pow(2, i)); j++) {
        delete layers_[i][j];
      }
      delete[] layers_[i];
    }
    if (layers_count_ > 0) {
      delete[] layers_;
    }
    size_ = 0;
    layers_count_ = 0;
  }

  /*void PrintHeap() {
    for (int i = 0; i < layers_count_; i++) {
      for (int j = 0; j < static_cast<int>(pow(2, i)); j++) {
        if (layers_[i][j]) {
          std::cout << layers_[i][j]->value << ' ';
        } else {
          std::cout << "*" << ' ';
        }
      }
      std::cout << std::endl;
    }
   }*/

  ~Heap() {
    Clear();
  }

 private:
  void Increase() {
    auto new_layers = new Node**[layers_count_ + 1];
    for (int i = 0; i < layers_count_; i++) {
      new_layers[i] = layers_[i];
    }
    new_layers[layers_count_] = new Node*[static_cast<int>(pow(2, layers_count_))]{nullptr};
    if (layers_count_ > 0) {
      delete[] layers_;
    }
    layers_ = new_layers;
    layers_count_++;
  }

  void SiftUp(int layer, int col_index) {
    while (layer > 0) {
      auto& child = layers_[layer][col_index];
      int parent_layer = layer - 1;
      int parent_col_index = col_index / 2;
      auto& parent = layers_[parent_layer][parent_col_index];
      if (child->value < parent->value) {
        std::swap(child, parent);
      } else {
        return;
      }
      layer = parent_layer;
      col_index = parent_col_index;
    }
  }

  void SiftDown(int layer, int col_index) {
    while (layer + 1 != layers_count_) {
      auto& parent = layers_[layer][col_index];
      auto& lc = layers_[layer + 1][col_index * 2];
      auto& rc = layers_[layer + 1][col_index * 2 + 1];
      if (!lc) {
        if (!rc) {
          break;
        }
        if (rc->value < parent->value) {
          std::swap(rc, parent);
        }
        break;
      }
      if (!rc) {
        if (lc->value < parent->value) {
          std::swap(lc, parent);
        }
        break;
      }
      auto& min_child = lc;
      if (rc && min_child->value > rc->value) {
        min_child = rc;
      }
      if (min_child->value > lc->value) {
        min_child = lc;
      }
      if (min_child->value == parent->value) {
        break;
      }
      std::swap(min_child, parent);
      layer++;
      col_index *= 2;
      if (min_child->value == rc->value) {
        col_index++;
      }
    }
  }

  size_t size_ = 0;
  int layers_count_ = 0;
  Node*** layers_ = new Node**[layers_count_];
};

int main() {
  Heap heap;
  int m, x, n;
  std::string command;
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> command;
    if (command == "insert") {
      std::cin >> n;
      heap.Insert(n);
    } else if (command == "extract_min") {
      heap.ExtractMin();
    } else if (command == "delete") {
      std::cin >> x;
      heap.Delete(x);
    } else if (command == "change") {
      std::cin >> x >> n;
      heap.Change(x, n);
    } else if (command == "get_min") {
      heap.GetMin();
    } else if (command == "size") {
      heap.Size();
    } else if (command == "clear") {
      heap.Clear();
      std::cout << "ok" << std::endl;
    }
    /*heap.PrintHeap();
    std::cout << "=================\n";*/
  }
  return 0;
}
