#include <iostream>

template<typename T>
class MyVector {
public:
    MyVector()
        : data_(NULL),
        capacity_(3),
        size_(0)
    {
        std::cout << "constructor call" << std::endl;
        data_ = new T[capacity_];
    }

    ~MyVector() { 
        std::cout << "destructor call" << std::endl;
        delete[] data_;
    }

    void push_back(const T& data) {
        if (size_ >= capacity_) {
            capacity_ = capacity_ * 2;

            T* new_data = new T[capacity_];
            std::copy(data_, data_ + size_, new_data);

            delete[] data_;
            data_ = new_data;
        }

        data_[size_++] = data;
    }

    void pop_back() { 
        size_--;
    }

    T& operator[](std::size_t i) { 
        return data_[i];
    }

    std::size_t size() const { 
        return size_;
    }

    T& top() {
        return data_[size_-1];
    }

private:
    T* data_;
    std::size_t capacity_;
    std::size_t size_;
};


// Use case
int main() {
    {
        MyVector<int> v;

        v.push_back(1); std::cout << v.top() << " : " << v.size() << std::endl; // v.size() == 1
        v.push_back(2); std::cout << v.top() << " : " << v.size() << std::endl; // v.size() == 2
        v.push_back(3); std::cout << v.top() << " : " << v.size() << std::endl; // v.size() == 3
        v.push_back(4); std::cout << v.top() << " : " << v.size() << std::endl; // v.size() == 4
        v.push_back(5); std::cout << v.top() << " : " << v.size() << std::endl; // v.size() == 5

        v.pop_back(); std::cout << v.top() << " : " << v.size() << std::endl;
        v.pop_back(); std::cout << v.top() << " : " << v.size() << std::endl;

        v.push_back(100); std::cout << v.top() << " : " << v.size() << std::endl;

    } // v ¼Ò¸ê


    return 0;
}

