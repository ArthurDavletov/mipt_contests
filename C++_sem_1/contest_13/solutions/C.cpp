#include <iostream>
#include <climits>

// O(nlogn)

int BinSearchIndex(int* table, int size, int elem) {
  int left = -1;
  int right = size;
  while (left < right - 1) {
    int half = (left + right) / 2;
    if (table[half] < elem) {
      left = half;
    } else {
      right = half;
    }
  }
  return left;
}

int IndexOfMax(int* table, int size) {
  auto answer = -1;
  auto max_elem = INT_MIN;
  for (int i = 0; i < size; i++) {
    if (table[i] > max_elem && table[i] != INT_MAX) {
      answer = i;
      max_elem = table[i];
    }
  }
  return answer;
}

int main() {
  int n;
  std::cin >> n;
  auto s = new int[n];
  auto dp = new int[n + 1];
  dp[0] = INT_MIN;
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
    dp[i + 1] = INT_MAX;
  }
  // int elem;
  // std::cin >> elem;
  // std::cout << BinSearchIndex(s, n, elem) << '\n'; return 0;
  for (int i = 0; i < n; i++) {
    auto p = BinSearchIndex(dp, n + 1, s[i]);
    if (dp[p + 1] > s[i]) {
      dp[p + 1] = s[i];
    }
  }
  std::cout << IndexOfMax(dp, n + 1) << std::endl;
  delete[] dp;
  delete[] s;
  return 0;
}
