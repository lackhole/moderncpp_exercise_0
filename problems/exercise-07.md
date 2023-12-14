아래 함수와 람다함수 모두에서, 인자 `a`, `b` 의 타입이 동일하다면
컴파일 에러를 발생시키도록 합니다(컴파일이 되지 않도록 합니다)

```c++
template<typename T, typename U>
auto add(T a, U b) {
  return a + b;
}
```

```c++
auto adder = [](auto a, auto b) {
  return a + b;
};
```
