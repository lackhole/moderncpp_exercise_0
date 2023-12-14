동적 배열 `MyVector`를 구현해 봅시다. (3)

`MyVector` 다음 기능이 구현되어 있지 않았다면 구현해야 합니다.
* 배열 제일 끝에 perfect forwarding 으로 원소 삽입 (`emplace_back`)
  * 삽입 시 메모리 재할당이 필요하면 재할당 해야 합니다.
* Rvalue 인 `MyVector`의 `operator[]`가 호출 되면 원소를 이동 반환 합니다. 

```c++

template<typename T>
class MyVector {
 public:
  // Existing codes...
  
  
  void emplace_back(/* ... */) { /* ... */ }
  
  /* operator[](std::size_t i) */
};


// Use case
int main() {

  {
    MyVector<std::string> v;
    
    v.push_back("hello");
    v.push_back("world");
    
    const char str[] = "hello again";
    
    v.emplace_back(std::begin(str), std::end(str));
    v.emplace_back(std::string("hello last time")); // No copy of `std:string` should be performed
    
  } // v, v2 소멸


  return 0;
}

```
