#include <iostream>

// O(n^2)

int IndexOfMax(int* table, int size) {
  int index = 0;
  for (int i = 1; i < size; i++) {
    if (table[index] < table[i]) {
      index = i;
    }
  }
  return index;
}

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int main() {
  int n;
  std::cin >> n;
  auto s = new int[n];
  auto dp = new int[n];
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    std::cin >> s[i];
    for (int j = 0; j < i; j++) {
      if (s[i] > s[j] && dp[i] < dp[j] + 1) {
        dp[i] = 1 + dp[j];
      }
    }
  }
  auto index = IndexOfMax(dp, n);
  auto max_len = dp[index];
  auto answer_size = max_len;
  auto answer = new int[answer_size];
  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] == max_len) {
      answer[--max_len] = s[i];
      index = i;
    }
  }
  for (int i = 0; i < answer_size; i++) {
    std::cout << answer[i] << ' ';
  }
  std::cout << std::endl;
  delete[] answer;
  delete[] dp;
  delete[] s;
  return 0;
}
