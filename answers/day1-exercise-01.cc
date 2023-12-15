#include <algorithm>
#include <iostream>
#include <list>

int main() {
  // list 선언
  std::list<int> list;

  // list 입력 받기
  for (int i = 0; i < 10; ++i) {
    int x;
    std::cin >> x;
    list.emplace_back(x);
  }

  // a, b 게산하기
  int x;
  int y;
  std::cin >> x >> y;

  int a = std::min(x, y);
  int b = std::max(x, y);

  // [a, b) 지우기
  auto first = std::next(list.begin(), a);
  auto last = std::next(list.begin(), b);
  list.erase(first, last);

  // list 출력
  std::for_each(list.begin(), list.end(), [](const auto& x) {
    std::cout << x  << ' ';
  });

  return 0;
}
