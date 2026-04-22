#include <iostream>
#include <cmath>

double Distance(int x1, int y1, int x2, int y2) {
  return sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int main() {
  int** points = new int*[3];
  for (int i = 0; i < 3; i++) {
    points[i] = new int[2];
    std::cin >> points[i][0];
    std::cin >> points[i][1];
  }
  double p = 0;
  p += Distance(points[0][0], points[0][1], points[1][0], points[1][1]);
  p += Distance(points[0][0], points[0][1], points[2][0], points[2][1]);
  p += Distance(points[1][0], points[1][1], points[2][0], points[2][1]);
  std::cout.precision(7);
  std::cout << p << std::endl;
  for (int i = 0; i < 3; i++) {
    delete[] points[i];
  }
  delete[] points;
  return 0;
}
