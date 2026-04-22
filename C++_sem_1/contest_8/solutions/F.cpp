#include <iostream>

int main() {
  int w, n, t;
  std::cin >> w >> n;
  int* price = new int[n];
  int* weight = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> price[i] >> weight[i];
  }
  int* prev = new int[w + 1]{};
  int* now = new int[w + 1]{};
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= w; j++) {
      now[j] = prev[j];
      if (weight[i] <= j) {
        t = price[i] + prev[j - weight[i]];
        if (t > now[j]) {
          now[j] = t;
        }
      }
    }
    for (int i = 0; i <= w; i++) {
      prev[i] = now[i];
    }
  }
  for (int i = w; i >= 0; i--) {
    if (now[i - 1] != now[i]) {
      std::cout << now[i] << ' ' << i << std::endl;
      break;
    }
  }
  delete[] price;
  delete[] weight;
  delete[] prev;
  delete[] now;
  return 0;
}
