예제 15에서 `x` 가 `200'000'000` 이 나오지 않았다면 정상입니다.  

`std::atomic`과 `std::mutex` 두가지 방법을 모두 사용해서 `x`가 `200'000'000`이 나오도록 해 봅시다.

전역 변수 대신 각각 `x1`, `x2` 를 사용하고, 각각의 경우에 대해 전체 실행에 걸린 시간을 출력합니다.

시간 측정은 `std::chrono::steady_clock::now()` 함수를 사용합니다.

```c++


int main() {
  
  // Use std::atomic
  ? x1;
  
  // 시간 측정
  std::thread th1( /* ... */ );
  std::thread th2( /* ... */ );
  
  // do something
  
  std::cout << x1 << '\n';
  std::cout << "걸린 시간: " << /* ... */ << '\n';
  
  // Use std::mutex
  ? x2;
  
  // 시간 측정
  std::thread th3( /* ... */ );
  std::thread th4( /* ... */ );
  
  // do something
  
  std::cout << x2 << '\n';
  std::cout << "걸린 시간: " << /* ... */ << '\n';

  return 0;
}

```
