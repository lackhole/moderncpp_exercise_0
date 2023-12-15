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

	// copy constructor
	MyVector(const MyVector& other)
		: capacity_(other.capacity_),
		size_(other.size_)
	{
		data_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			data_[i] = other[i];
		}
	}
	// move constructor
	MyVector(MyVector&& other) noexcept
		: size_(other.size_),
		  capacity_(other.capacity_)
	{
		delete[] data_;
		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}
	// copy assignment operator
	MyVector& operator=(const MyVector& other)
	{
		size_ = other.size_;
		capacity_ = other.capacity_;
		for (int i = 0; i < size_; ++i)
		{
			data_[i] = other.data_[i];
		}
		return *this;
	}
	// move assignment operator
	MyVector& operator=(MyVector&& other) 
	{
		if (this != &other)
		{
			delete[] data_;
			size_ = other.size_;
			capacity_ = other.capacity_;
			other.data_ = nullptr;
			other.capacity_ = 0;
			other.size_ = 0;
		}
		return *this;
	}

	~MyVector() {
		delete[] data_;
	}

	void push_back(const T& data)
	{
		if (size_ >= capacity_)
		{
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

	void pop_back()
	{
		if (size_ > 0) {
			size_ -= 1;
		}
	}

	// 음수 인덱스를 받았을 때 예외처리 필요
	const T& operator[](std::size_t i) const
	{
		return *(data_ + i);
	}

	T& operator[](std::size_t i) {
		return *(data_ + i);
	}

	std::size_t size() const
	{
		return this->size_;
	}


private:
	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};

int main()
{
	{
		MyVector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		
		MyVector<int> v2 = std::move(v);
		std::cout << v2.size() << std::endl;
		std::cout << v.size() << std::endl;

	} // v 소멸

	return 0;
}