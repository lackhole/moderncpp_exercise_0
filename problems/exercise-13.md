실습 9에서 구현한 [`MyApplication`](../answers/day2-exercise-08.cc) 클래스를 가져옵니다.

`main` 함수 안에서 `TestUniquePtr`, `TestSharedPtr` 두 함수 호출 이후
`MyApplication`의 특수 멤버 함수들이 각각 몇 번씩 호출되었는지 출력합니다.

```c++

#include <memory>
#include <iostream>
#include <utility>

void TestUniquePtr() {
  // MyApplication 생성
  auto p = std::make_unique<MyApplication>();

  // MyApplication 이동
  auto p2 = std::move(p);
}

void TestSharedPtr() {
  // MyApplication 생성
  auto p = std::make_shared<MyApplication>();

  // ?
  auto p2 = p;

  // p2 초기화
  p2.reset();

  // ?
  std::weak_ptr<MyApplication> weak_p = p;

  auto lock = weak_p.lock();
  if (lock) {
    std::cout << "Acquired ownership\n";
  }
}

int default_constructor_count = 0;
// ...

class MyApplication { /* ... */ };

int main() {
  TestUniquePtr();
  std::cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n’;
  std::cout << "복사 생성자 호출 횟수: " << /* ... */ << '\n’;
  std::cout << "이동 생성자 호출 횟수: " << /* ... */ << '\n’;
  std::cout << "복사 대입 연산자 호출 횟수: " << /* ... */ << '\n’;
  std::cout << "이동 대입 연산자 호출 횟수: " << /* ... */ << '\n’;
  std::cout << "소멸자 호출 횟수: " << /* ... */ << '\n’;

  TestSharedPtr();
  std::cout << "기본 생성자 호출 횟수: " << /* ... */ << '\n’;
  // ...

  return 0;
}



```
