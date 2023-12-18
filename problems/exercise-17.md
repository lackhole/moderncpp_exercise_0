예제 16에서의 시간을 비교 해 보고, `std::atomic` 과 memory order 을 사용해
더 빠르게 실행할 수 있도록 수정 해 봅니다.


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
