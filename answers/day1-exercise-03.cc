#include <iostream>

// https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95#%EC%86%8C%EC%8A%A4_%EC%BD%94%EB%93%9C
//
// while 문도 결국 재귀함수로 바꿀 수 있다.
// 재귀함수로 구현
constexpr int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

// 재귀함수일 때 (a % b != 0) 일반형 작성
template<int a, int b, int r = a % b>
struct gcd2 {
  static constexpr int value = gcd2<b, r>::value;
};

// 재귀함수가 아닐 때를 특수화
template<int a, int b>
struct gcd2<a, b, 0> {
  static constexpr int value = b;
};


int main() {
  static_assert(gcd(1071, 1029) == 21, "");
  static_assert(gcd(78696, 19332) == 36, "");
  static_assert(gcd2<1071, 1029>::value == 21, "");
  static_assert(gcd2<78696, 19332>::value == 36, "");
  return 0;
}
