스마트 포인터를 사용해도 다형성(polymorphism)이 유지되는지 테스트 해보는 실습입니다.

`MyBaseClass` 를 정의하고, `virtual void Hello()`를 정의합니다
-> `Hello()` 호출 시, `"This is Base"`를 출력합니다.
`MyBaseClass` 를 public 상속 받는 `MyDerivedClass`를 정의합니다
-> `Hello()` 호출 시, `"This is Derived"` 를 출력합니다.
아래 코드를 `main` 에 추가하고, 실행 시 어떤게 출력되는지 확인합니다

```c++

int main() {
  std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
  p->Hello();

  return 0;
}

```
