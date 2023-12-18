#include <iostream>
#include <cstdint>

template<typename T>
class MyVector {
public:
	MyVector()
		: data_(nullptr),
		  capacity_(3),
		  size_(0)
	{
		data_ = new T[capacity_];
	}

	~MyVector() {
		delete[] data_;
	}

	void push_back(const T& data) {
		if (size_ >= capacity_) {
			// 용량 늘리기
			capacity_ = capacity_ * 2;

			// 메모리 새로 할당
			T* new_data = new T[capacity_];

			// 기존 데이터 복사
			std::copy(data_, data_ + size_, new_data);

			// 기존 메모리 해제
			delete[] data_;

			// 기존 포인터 대체
			data_ = new_data;
		}

		data_[size_] = data;
		size_ += 1;
	}

private:
	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};




int main() {
	
	
	return 0;
}
