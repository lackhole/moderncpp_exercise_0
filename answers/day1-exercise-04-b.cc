#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>

int main() {
  // N 입력 받기
  int N;
  std::cin >> N;

  struct abs_comparator {
    bool operator()(int a, int b) const {
      return std::abs(a) < std::abs(b);
    }
  };

  // abs_comparator 를 대소 비교에 사용하는 map을 사용
  // 단, std::abs를 사용할 경우 key 값이 겹칠 수 있으므로 std::multimap 사용 함
  // 이 예제에서는 std::multiset을 사용 해도 됨
  std::multimap<int, int, abs_comparator> map;

  // map 입력 받기
  // 입력 받을 때마다 abs_comparator에 의해 내부적으로 정렬됨
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    map.emplace(x, /* 안 쓰임 */ x);
  }

  for (const auto& key_value : map) {
    std::cout << key_value.first << " ";
  }

  return 0;
}
