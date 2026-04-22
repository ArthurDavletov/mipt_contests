#include <iostream>

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int n, m;
  std::cin >> n;
  auto a = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cin >> m;
  auto b = new int[m];
  for (int j = 0; j < m; j++) {
    std::cin >> b[j];
  }
  auto table = new int*[n + 1];
  table[0] = new int[m + 1]{};
  for (int i = 1; i <= n; i++) {
    table[i] = new int[m + 1]{};
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] != b[j - 1]) {
        table[i][j] = Max(table[i - 1][j], table[i][j - 1]);
      } else {
        table[i][j] = table[i - 1][j - 1] + 1;
      }
    }
  }
  auto answer = new int[n + 1]{1000000};
  if (table[n][m] != 0) {
    int counter = 0;
    int i = n, j = m;
    while (i != 0 && j != 0) {
      if (table[i - 1][j] == table[i][j]) {
        i--;
      } else if (table[i][j - 1] == table[i][j]) {
        j--;
      } else {
        answer[counter++] = a[--i];
        j--;
      }
    }
    counter--;
    for (; counter >= 0; counter--) {
      std::cout << answer[counter] << ' ';
    }
    std::cout << std::endl;
  }
  delete[] a;
  delete[] b;
  for (int i = 0; i <= n; i++) {
    delete[] table[i];
  }
  delete[] table;
  delete[] answer;
  return 0;
}
