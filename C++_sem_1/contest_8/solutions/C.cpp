#include <iostream>

int Min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int Min(int a, int b, int c) {
  int elem = a;
  if (b < elem) {
    elem = b;
  }
  if (c < elem) {
    elem = c;
  }
  return elem;
}

int main() {
  int n;
  std::cin >> n;
  int* a = new int[n];
  int* b = new int[n];
  int* c = new int[n];
  int* q = new int[n]{};
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i] >> c[i];
  }
  q[0] = a[0];
  if (n > 1) {
    q[1] = Min(a[0] + a[1], b[0]);
  }
  if (n > 2) {
    q[2] = Min(q[1] + a[2], q[0] + b[1], c[0]);
  }
  for (int i = 3; i < n; i++) {
    q[i] = Min(q[i - 1] + a[i], q[i - 2] + b[i - 1], q[i - 3] + c[i - 2]);
  }
  std::cout << q[n - 1] << std::endl;
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] q;
  return 0;
}
