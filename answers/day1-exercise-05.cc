#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  // N 입력 받기
  int N;
  std::cin >> N;

  // (원소: 원소의 개수)를 저장하는 자료구조 사용
  std::unordered_map<int, int> A;
  for (int i = 0; i < N; ++i) {
    // 원소 입력 받기
    int x;
    std::cin >> x;

    // 개수를 저장할 것이므로, 원소 x가 없다면
    // (x: 1)을 key-value 쌍으로 저장할 것이고,
    // 이미 원소 x가 있다면 기존의 개수(value)를
    // 1 만큼 증가시켜야 한다

    auto it = A.find(x);

    // 원소 x가 이미 있음
    if (it != A.end()) {
      // 개수 1만큼 증가
      it->second += 1;
    }
    // 원소 x가 없음
    else {
      // 최초 삽입; (x: 1)을 저장함.
      A.emplace(x, 1);
    }
  }


  // M 입력 받음
  int M;
  std::cin >> M;

  // B 입력 받음
  std::vector<int> B(M);
  for (auto& x : B) {
    std::cin >> x;
  }

  // B의 원소들에 대해 순회함 O(M)
  for(const auto& x : B) {
    // B의 원소가 A에 있는지 검사 O(1)
    auto it = A.find(x);

    // A에 있음: 개수 출력
    if (it != A.end()) {
      std::cout << it->second << ' ';
    }
    // A에 없음: 0 출력
    else {
      std::cout << 0 << ' ';
    }
  }


  return 0;
}
