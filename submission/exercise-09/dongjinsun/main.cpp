#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class MyVector {
    public:
        MyVector(): capacity_(3), size_(0){
            data_ = new T[3];
        }
        ~MyVector(){
            delete[] data_;
        }
        T operator[](std::size_t i){
            if (i<size_)
                return data_[i];
            else
                return (T)-1;
        }
        void push_back(T n){
            if (size_ == capacity_-1){
                capacity_ *= 2;
                T* temp = new T[capacity_];
                std::copy(data_,data_+(int)size_,temp);
                delete[] data_;
                data_ = temp;
            }
            data_[size_] = n;
            size_++;
        }
        
        void pop_back(){
            size_--;
        }

        std::size_t size() const {
            return size_;
        }

    private:
        T* data_;
        int capacity_;
        size_t size_;
};

int main() {

  {
    MyVector<int> v;
    
    v.push_back(1); // v.size() == 1
    std :: cout << v.size() << std::endl;
    v.push_back(2); // v.size() == 2
    std :: cout << v.size() << std::endl;
    v.push_back(3); // v.size() == 3]
    std :: cout << v.size() << std::endl;
    v.push_back(4); // v.size() == 4
    std :: cout << v.size() << std::endl;
    v.push_back(5); // v.size() == 5
    std :: cout << v.size() << std::endl;
    std :: cout << v[0] << std::endl;
    std :: cout << v[1] << std::endl;
    std :: cout << v[2] << std::endl;
    std :: cout << v[3] << std::endl;
    std :: cout << v[4] << std::endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    std :: cout << v.size() << std::endl;
  } // v 소멸


  return 0;
}