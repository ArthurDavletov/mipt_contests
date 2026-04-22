#include <iostream>
#include <string>

void KeysInput(std::string& first, std::string& second) {
  std::cin >> first;
  std::cin >> second;
}

void ValueInput(int& elem) {
  int mark;
  for (int i = 0; i < 3; i++) {
    std::cin >> mark;
    elem += mark;
  }
}

void InsertElem(int* best_marks, int elem, int index) {
  if (index == 0) {
    best_marks[2] = best_marks[1];
    best_marks[1] = best_marks[0];
  } else if (index == 1) {
    best_marks[2] = best_marks[1];
  }
  best_marks[index] = elem;
}

void ChangeArray(int* best_marks, int elem) {
  for (int i = 0; i < 3; i++) {
    if (elem >= best_marks[i]) {
      InsertElem(best_marks, elem, i);
      return;
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::string* firsts = new std::string[n];
  std::string* seconds = new std::string[n];
  int* values = new int[n]{};
  int* best_marks = new int[3]{};
  for (int i = 0; i < n; i++) {
    KeysInput(firsts[i], seconds[i]);
    ValueInput(values[i]);
    ChangeArray(best_marks, values[i]);
  }
  for (int i = 0; i < n; i++) {
    if (values[i] == best_marks[0] || values[i] == best_marks[1] ||
        values[i] == best_marks[2]) {
      std::cout << firsts[i] << ' ' << seconds[i] << '\
';
    }
  }
  delete[] firsts;
  delete[] seconds;
  delete[] values;
  delete[] best_marks;
  return 0;
}
