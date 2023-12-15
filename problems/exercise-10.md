동적 배열 `MyVector`를 구현해 봅시다. (2)

`MyVector` 다음 기능을 추가로 가져야 합니다.

* 복사 생성자 `copy constructor`
* 복사 대입 연산자 `copy assignment operator`
* 이동 생성자 `move constructor`
  * 이동은 O(1) 시간에 완료되어야 하고 불필요한 자원을 사용하지 않습니다
* 이동 대입 연산자 `move assignment operator`
  * 이동은 O(1) 시간에 완료되어야 하고 불필요한 자원을 사용하지 않습니다


```c++

template<typename T>
class MyVector {
 public:
  // Existing codes...
  
  
  MyVector(const MyVector&) { /* ... */ }
  MyVector(MyVector&&) { /* ... */ }
  
  MyVector& operator=(const MyVector&) { /* ... */ }
  MyVector& operator=(MyVector&&) { /* ... */ }
  
};


// Use case
int main() {

  {
    MyVector<int> v;
    
    v.push_back(1); // v.size() == 1
    v.push_back(2); // v.size() == 2
    v.push_back(3); // v.size() == 3
    v.push_back(4); // v.size() == 4
    v.push_back(5); // v.size() == 5
    
    
    MyVector<T> v2 = std::move(v);
    // v2.size() == 5 
    // v.size() == 0
    
  } // v, v2 소멸


  return 0;
}

```
