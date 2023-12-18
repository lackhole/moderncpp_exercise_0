전역 변수 `int x`를 선언하고, `0`으로 초기화 합니다.
`std::thread` 객체 두개를 선언하고, 람다 함수와 반복문을 이용해 `x`를 `100'000'000`번 증가시킵니다.
동기화 알고리즘 (`std::mutex` 등)은 사용하지 않습니다.

스레드들을 동기화 하고 `x` 를 출력합니다.

```c++
int x;

int main() {
  
  std::thread th1( /* ... */ );
  std::thread th2( /* ... */ );
  
  // do something
  
  std::cout << x << '\n';

  return 0;
}

```
