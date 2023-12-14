#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int a, b, N;
  std::cin >> a >> b >> N;

  // Create A and B
  std::vector<int> A(N);
  std::vector<int> B(N);

  // Fill A and B
  std::iota(A.begin(), A.end(), a); // A = [a, a + 1, ... ]
  std::iota(B.begin(), B.end(), b); // B = [b, b + 1, ... ]

  // A와 B의 내적 구하기
  auto out = std::inner_product(A.begin(), A.end(), B.begin(), 0);

  std::cout << out << '\n';

  return 0;
}
