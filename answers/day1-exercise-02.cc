#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
  // 벡터 입력받기
  std::vector<int> v(10);
  for (auto& x : v) {
    std::cin >> x;
  }

  std::map<int, int> my_map;
  for (int i = 0; i < v.size(); ++i) {
    my_map.emplace(v[i], i);
  }

  // a 입력받기
  int a;
  std::cin >> a;

  // 정렬 후, upper_build 함수 사용
  // 원본 벡터의 인덱스를 저장하기 위해 std::map 사용
  auto it = my_map.upper_bound(a);
  if (it == my_map.end()) {
    std::cout << -1;
  } else {
    std::cout << it->second;
  }


  return 0;
}
