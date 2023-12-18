#include <iostream>
#include <type_traits>

template<typename T, typename U>
auto add(T a, U b) {
  static_assert(!std::is_same<T, U>::value,
                "T and U must be different type");
  return a + b;
}

int main() {
  add(1, 1.0);
  // add(1, 1) <- 컴파일 안 됨

  auto adder = [](auto a, auto b) {
    static_assert(!std::is_same<decltype(a), decltype(b)>::value,
                  "T and U must be different type");
    return a + b;
  };

  adder(1, 1.0);
  // add(1, 1) <- 컴파일 안 됨

  return 0;
}
