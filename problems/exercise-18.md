예제 17에서 `std::mutex`를 사용한 버전만 가져옵시다.

시간 측정 코드도 빼도 좋습니다.

이번에는 마지막에 `x`를 출력하는것을 비동기로 자동으로 해 줄 겁니다.
`th3` 은 `x`가 `200'000'000`이 되기 전 까지 sleep 하고 있다가 `200'000'000`
이 되면 일어나서 `x`를 출력 합니다.

```c++


int main() {
  int x;
  std::mutex m;
  std::condition_variable cv;
  
  std::thread th1( /* ... */ );
  std::thread th2( /* ... */ );
  
  
  std::thread th3([]() {
    // wait until x becomes 200'000'000
  
    std::cout << x << '\n';
  });

  return 0;
}

```
