#include <iostream>

int main() {
  int64_t n = 0;
  int64_t m = 0;
  std::cin >> n;
  auto s = new int64_t[n];
  auto prefix = new int64_t[n + 1];
  auto postfix = new int64_t[n + 1];
  prefix[0] = postfix[0] = 0;
  for (int64_t i = 0; i < n; i++) {
    std::cin >> s[i];
    prefix[i + 1] = prefix[i] + s[i];
  }
  for (int64_t i = 1; i <= n; i++) {
    postfix[i] = postfix[i - 1] + s[n - i];
  }
  std::cin >> m;
  int64_t first = 0;
  int64_t second = 0;
  for (int64_t i = 0; i < m; i++) {
    std::cin >> first >> second;
    std::cout << prefix[n] - prefix[first - 1] - postfix[n - second] << ' ';
  }
  delete[] s;
  delete[] prefix;
  delete[] postfix;
  return 0;
}
