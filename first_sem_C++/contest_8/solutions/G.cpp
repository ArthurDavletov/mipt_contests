#include <iostream>

int main() {
  int s, n;
  std::cin >> s >> n;
  int* weight = new int[n];
  int* sizes = new int[s + 1]{};
  for (int i = 0; i < n; i++) {
    std::cin >> weight[i];
  }
  for (int i = 0; i < n; i++) {
    for (int w = s; w >= weight[i]; w--) {
      if (w == weight[i] ||
          (sizes[w - weight[i]] != 0 && sizes[w - weight[i]] + 1 > sizes[w])) {
        sizes[w] = sizes[w - weight[i]] + 1;
      }
    }
  }
  int max_size = 0;
  for (int i = 0; i <= s; i++) {
    if (sizes[i] > max_size) {
      max_size = sizes[i];
    }
  }
  for (int i = 0; i <= s; i++) {
    if (sizes[i] == max_size) {
      std::cout << sizes[i] << ' ' << i << std::endl;
      break;
    }
  }
  delete[] weight;
  delete[] sizes;
  return 0;
}
