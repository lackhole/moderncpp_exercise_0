#include <iostream>
#include <algorithm>
#include <vector>

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
    //복사 대입 연산자
    MyVector& operator=(const MyVector& r) { /* ... */ 
        if (this !=&r) { // Myvector v1(v1); 자기 자신 대입시 실행x
            if (m_capacity < r.m_capacity) {
                delete[] data;
  
                m_size = r.m_size;
                m_capacity = r.m_capacity;
                data= new T[m_capacity];
               
            }
            for (int i = 0; i < r.m_size; i++) {
                data[i] = r[i];
            }
        }
        
        return *this;
    }
    //이동 대입 연산자
    MyVector& operator=(MyVector&& r) noexcept{ /* ... */
        if (this != &r) {

            delete[] data;
            m_size = exchange(r.m_size, 0);
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
            for (int i = 0; i < m_size; i++) {
                tmp[i] = data[i];
            }
            delete[] data; //? 기존 data가 가리키는 부가메모리 해제후
            data = tmp; // tmp가 가리키는 동적 배열 가리키게 
        }
        //용량 넉넉하면 추가만
        data[m_size] = n; //맨 뒤에 데이터 추가
        m_size++;
    }

    void pop_back(/* ... */) { 
        /* ... */
        m_size = m_size > 0 ? m_size - 1 : 0;
    }

    /* return-type */ 
    T& operator[](size_t i) { /* ... */
        return data[i];
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
    int m_capacity;
    // Define other member variables if necessary
};

// Use case
int main() {

    {
        MyVector<int> v;
        cout <<"초기 사이즈: "<< v.size() << '\n';
        v.push_back(1); // v.size() == 1
        v.push_back(2); // v.size() == 2
        cout<<"1,2 push후 사이즈: "<<v.size() << '\n';
        v.push_back(3); // v.size() == 3
        cout << "3 push " << '\n';
        v.pop_back();
        cout << "pop " << '\n';
        v.push_back(4); // v.size() == 4
   
        cout << "4 push후 사이즈 :"<<v.size() << '\n';
        v.push_back(5); // v.size() == 5
        cout << "5 push " << '\n';
        
        cout << "전체 출력: ";
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';

        MyVector<int> v2 = std::move(v); //이동생성자 호출
        for (auto i : v2) {
            cout << i << ' ';
        }

    } // v 소멸

    

    return 0;
}
