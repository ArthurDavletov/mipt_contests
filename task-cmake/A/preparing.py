def create_header():
    with open("../A/index.h", "w", encoding="utf-8") as file:
        header_body = """\
#ifndef INDEX_H
#define INDEX_H

#include <vector>

int code_year = 2024;
int ufa_year = 1574;
int mipt_year = 1951;

// индекс первого совпавшего элемента за линейное время. -1, если нет
int GetIndex(const std::vector<int>& s, int elem) {
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == elem) return i;
  }
  return -1;
}

// Что тут написать, я не знаю, помогите

#endif
"""
        file.write(header_body)


if __name__ == "__main__":
    create_header()
