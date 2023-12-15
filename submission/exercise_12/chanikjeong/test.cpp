#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
class MyVector {
public:
    MyVector(const int& temp = 3) {
        data = new T[temp]; //data=new int[3]
        m_size = 0;
        m_capacity = temp;
    }
    ~MyVector() {
        if (data != nullptr) {
            delete[] data;
        }
    }
    //
    MyVector(const MyVector& r) //복사 생성자
    {
        
        data = new T[r.m_capacity];
        m_size=r.m_size;
        m_capacity = r.m_capacity;
        copy(r.data, r.data + m_size, data); //r.data -> data로 복사
    }

    MyVector(MyVector&&r) noexcept //이동 생성자
    { /* ... */
        m_size = exchange(r.m_size,0);
        m_capacity = exchange(r.m_capacity,0);
        data = r.data;

        r.data = nullptr; //자신이 가리키고 있던 메모리 해제하지 못하게
        
    }
    
    MyVector(const initializer_list<T> ls) : MyVector(ls.size()){
        
        int count = 0;
        for (auto & i:ls) {
            data[count++] = i;
        }
        m_size = count;
        m_capacity = m_size;

    }


    //복사 대입 연산자
    MyVector& operator=(const MyVector& r) { /* ... */ 
        if (this !=&r) { // Myvector v1(v1); 자기 자신 대입시 실행x
            if (m_capacity < r.m_capacity) {
                delete[] data;
  
                m_size = r.m_size;
                m_capacity = r.m_capacity;
                data= new T[m_capacity];
               
            }
            /*
            for (int i = 0; i < r.m_size; i++) {
                data[i] = r[i];
            }*/
            copy(r, r + r.m_size, data);
        }
        
        return *this;
    }
    //이동 대입 연산자
    MyVector& operator=(MyVector&& r) noexcept{ /* ... */
        if (this != &r) {

            delete[] data;
            m_size = exchange(r.m_size, 0); //m_size=r.m_size 이후 r.m_size=0으로
            m_capacity = exchange(r.m_capacity, 0);
            data = r.data;

            r.data = nullptr;
        }
        return *this;
    }
    void push_back(const T& n) {

        if (m_capacity <= m_size) {
            m_capacity *= 2; //용량 늘리고

            T* tmp = new T[m_capacity]; //용량만큼 새 메모리 할당
            /*
            for (int i = 0; i < m_size; i++) {
                tmp[i] = data[i];
            }*/
            copy(data, data + m_size, tmp);
            delete[] data; // 기존 data가 가리키는 부가 메모리 해제후
            data = tmp; // tmp가 가리키는 동적 배열 가리키게 
        }
        //용량 넉넉하면 추가만
        data[m_size] = n; //맨 뒤에 데이터 추가
        m_size++;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {  //가변 인자
        if (m_capacity <= m_size) {
            m_capacity *= 2;
            T* tmp = new T[m_capacity];
            
            copy(data, data + m_size, tmp);
            delete[] data;
            data = tmp;
        }
        // 사용자가 제공한 인자(args)를 사용하여 객체를 직접 생성
        data[m_size++] = T(forward<Args>(args)...);
    
    }

    void pop_back() { 
        m_size = m_size > 0 ? m_size - 1 : 0;
    }

 
    T& operator[](size_t i) &{ // Lvalue 참조 버전
        return data[i];
    }
    
    //추가.. const 참조 객체 접근시
    const T& operator[](size_t i) const & {// const 참조 버전
        return data[i];
    }
    
    //Rvalue 참조일 때 원소를 이동
    T&& operator[](size_t i)&& {// Rvalue 참조 버전
        return move(data[i]);
    }

    size_t size() const {
        /* ... */
        return m_size;
    }
    T* begin() {
        return data; //시작주소
    }
    T* end() {
        return data + m_size; // 포인터 주소연산 ,끝 주소(empty)
    }
private:
    T* data;
    size_t m_size;
    size_t m_capacity;
};

// Use case
int main() {


    {
        MyVector<string> v;

        v.push_back("hello");
        v.push_back("world");

        const char str[] = "hello again";

        v.emplace_back(begin(str), end(str));
        v.emplace_back(string("hello last time")); // No copy of `std:string` should be performed
        
        for (const auto& i : v) {
            cout << i << endl;
        }
        cout << '\n';
        const auto& vref = v;
        cout << "const auto& vref: " << vref[0] << endl;
        //vref[0] = "ss";
    } // v, v2 소멸
    
    // 객체 생성
    MyVector<int> v;

    // push_back을 사용하여 일부 데이터 추가
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // Rvalue 참조 버전을 사용하여 원소를 이동
    int&& movedElement = move(v)[1];

    // 이동된 원소를 출력
    cout << "Moved Element: " << movedElement << endl;

    // v 객체의 크기 출력
    cout << "Vector Size: " << v.size() << endl;

    /*----------------------------------초기화 리스트----------------*/
    MyVector<int> mv = {1,2,3,4,5};
    for (const auto& c : mv) {
        cout << c << ' ';
    }
    cout <<'\n'<< mv.size() << endl;
    cout << mv[3] << endl;

    return 0;
}
