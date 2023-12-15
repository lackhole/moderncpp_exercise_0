POD 클래스 `MyApplication` 을 정의하고 **모든** 특수
멤버 함수 호출 시에 현재 멤버 함수의 signature 를 출력하도록 합니다.

```c++
class MyApplication {
/*
  Implementation
*/
};

int main() {
  // print: MyApplication::MyApplication()
  MyApplication a;

  // print: MyApplication::MyApplication(const MyApplication&)
  MyApplication b = a; 


  // print: MyApplication::~MyApplication()   (b destroyed)
  // print: MyApplication::~MyApplication()   (a destroyed)
  return 0;
}
```

## Note
MSVC 에서는 `__FUNCSIG__` 매크로를,
gcc 및 clang 에서는 `__PRETTY_FUNCTION__`
매크로를 사용하면 함수의 signature 를 쉽게
얻을 수 있습니다.

표준은 `__func__` 매크로 입니다
