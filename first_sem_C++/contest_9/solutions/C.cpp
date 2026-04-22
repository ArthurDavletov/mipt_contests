#include <iostream>
#include <string>

int main() {
  std::string line;
  std::cin >> line;
  int counter = 0;
  int state = 0;
  for (int i = 0; i < static_cast<int>(line.length()); i++) {
    if (line[i] == ')') {
      state--;
      if (state < 0) {
        counter++;
        state = 0;
      }
    }
    if (line[i] == '(') {
      state++;
    }
  }
  std::cout << abs(state) + counter << std::endl;
  return 0;
}
