#include <iostream>
#include <cstdint> // size_t

using namespace std;

template<typename T>
class MyVector {
public:

    MyVector() : data_(nullptr), capacity_(3), size_(0) { // 초기화
        data_ = new T[capacity_];
    }

    // 복사 생성자
    MyVector(const MyVector& a) : capacity_(a.capacity_), size_(a.size_) {
        // 포인터는 그대로 가져오면 안됨, 같은 객체를 가리키게 됨
        data_ = new T[capacity_];

        for (int i = 0; i < size_; i++) {
            data_[i] = a[i];
        }
    }

    // 이동 생성자
    MyVector(MyVector&& a) : capacity_(move(a.capacity_)), size_(move(a.size_)) {
        data_ = new T[capacity_];

        for (int i = 0; i < size_; i++) {
            data_[i] = move(a[i]);
        }
    }

    // 이동 대입 연산자
    MyVector& operator=(const MyVector& a) noexcept {
        data_ = move(a.data_);
        capacity_ = move(a.capacity_);
        size_ = move(a.size_);

        return *this;
    }

    MyVector& operator=(MyVector&& a) noexcept {
        data_ = move(a.data_);
        capacity_ = move(a.capacity_);
        size_ = move(a.size_);

        return *this;
    }

    ~MyVector() {
        delete[] data_;
    }

    void push_back(const T& n) {
        if (capacity_ <= size_) {
            // 용량 늘리기
            capacity_ *= 2;

            // 메모리 새로 할당
            T* new_data = new T[capacity_];

            // 복사
            copy(data_, data_ + size_, new_data);

            // 기존 메모리 해제
            delete[] data_;

            // 기존 포인터 대체
            data_ = new_data;
        }

        data_[size_] = n;
        size_++;
    }

    void pop_back() {
        // 사이즈 줄이기
        if (size_ > 0) {
            size_--;
        }
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }

    size_t size() const {
        return size_;
    }

private:
    T* data_; // 벡터에 대한 포인터
    size_t capacity_;
    size_t size_;
};

// Use case
int main()
{
    {
        MyVector<int> v;

        v.push_back(1); // v.size() == 1
        //cout << v.size()<<endl;
        v.push_back(2); // v.size() == 2
        //cout << v.size() << endl;
        v.push_back(3); // v.size() == 3
        //cout << v.size() << endl;
        v.push_back(4); // v.size() == 4
        //cout << v.size() << endl;
        v.push_back(5); // v.size() == 5
        //cout << v.size() << endl;
        v.pop_back();
        //cout << v.size() << endl;
        //cout << v[3] << endl;

        MyVector<int> v2 = std::move(v);
        // v2.size() == 5 
        // v.size() == 0
    } // v 소멸


    return 0;
}