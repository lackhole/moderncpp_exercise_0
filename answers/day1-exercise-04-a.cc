#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  // N 입력 받기
  int N;
  std::cin >> N;

  // vector 입력 받기
  std::vector<int> v(N);
  for (auto& x : v) {
    std::cin >> x;
  }

  // std::abs 사용해서 정렬
  std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    // return 값이 true 이면 비교에 사용되는 key의 값이 작은 것
    return std::abs(a) < std::abs(b);
  });

  // vector 출력
  for (const auto& x : v) {
    std::cout << x << ' ';
  }

  return 0;
}
