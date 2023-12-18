#include <iostream>

using namespace std;
/*
* exercise-09.cpp
*
* by jekim
* 2023-12-15
*/
template<typename T>
class MyVector {
public:
	MyVector(const int& size = 3) {
		data_ = new T[size];
		capacity_ = size;
		size_ = 0;
	}
	~MyVector() {
		if(data_ != nullptr)
			delete[] data_;
	}

	MyVector(const MyVector& r) : capacity_(r.capacity_), size_(r.size_){
		data_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) data_[i] = r.data_[i];
	}

	MyVector(MyVector&& r) noexcept : capacity_(r.capacity_), size_(r.size_), data_(r.data_) {
		r.data_ = nullptr;
		r.size_ = 0;
		r.capacity_ = 0;
	}

	MyVector& operator=(const MyVector& r) {
		if (data_ != nullptr) {
			delete[] data_;
			capacity_ = r.capacity_;
			size_ = r.size_;
			data_ = new T[capacity_];
			for (size_t i = 0; i < size_; ++i)
				data_[i] = r.data_[i];
		}
		return *this;
	}

	MyVector& operator=(MyVector&& r)noexcept {
		if (this != &r) {
			delete[] data_;
			data_ = r.data_;
			capacity_ = r.capacity_;
			size_ = r.size_;
			r.data_ = 0;
			r.capacity_ = 0;
			r.data_ = nullptr;
		}
		return *this;
	}
	void push_back(const T& val) {
		if(capacity_ <= size_) {
			capacity_ *= 2;
			T* temp = new T[capacity_];
			for (int i = 0; i < size_; i++)
				temp[i] = data_[i];
			delete[] data_;
			data_ = temp;
		}
		data_[size_] = val;
		++size_;
	}
	void pop_back() {
		if (size_ > 0) size_--;
	}

	T& operator[](std::size_t i) {
		if (i >= 0 && i < size_) return data_[i];
	}
	std::size_t size() const {
		return size_;
	}

//private:
	T* data_;
	size_t size_;
	size_t capacity_;
};
int main() {

	{  MyVector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		// Copy Constructor
		MyVector<int> v2 = v1;
		std::cout << "Copy Constructor: ";
		for (std::size_t i = 0; i < v2.size(); ++i) {
			std::cout << v2[i] << " ";
		}

		// Move Constructor
		MyVector<int> v3 = std::move(v1);
		std::cout << "\nMove Constructor: ";
		for (std::size_t i = 0; i < v3.size(); ++i) {
			std::cout << v3[i] << " ";
		}

		// Copy Assignment Operator
		MyVector<int> v4;
		v4 = v2;
		std::cout << "\nCopy Assignment Operator: ";
		for (std::size_t i = 0; i < v4.size(); ++i) {
			std::cout << v4[i] << " ";
		}

		// Move Assignment Operator
		MyVector<int> v5;
		v5 = std::move(v2);
		std::cout << "\nMove Assignment Operator: ";
		for (std::size_t i = 0; i < v5.size(); ++i) {
			std::cout << v5[i] << " ";
		}

		
	} // v �Ҹ�
	return 0;
}
