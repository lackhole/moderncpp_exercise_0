#include <iostream>

using namespace std;
/*
* exercise-10.cpp
*
* by jekim
* 2023-12-15
*/
template<typename T>
class MyVector {
public:
	// default constructor
	MyVector(const int& size = 3) {
		data_ = new T[size];
		capacity_ = size;
		size_ = 0;
	}

	// destructor
	~MyVector() {
		if (data_ != nullptr)
			delete[] data_;
	}

	// copy constructor 
	MyVector(const MyVector& r) : capacity_(r.capacity_), size_(r.size_) {
		data_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) data_[i] = r.data_[i];
	}

	// move constructor
	MyVector(MyVector&& r) noexcept : capacity_(r.capacity_), size_(r.size_), data_(r.data_) {
		r.data_ = nullptr;
		r.size_ = 0;
		r.capacity_ = 0;
	}
	// copy assignment operator
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

	// move assignment operator
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
		//if(capacity_ <= size_) {
		if (capacity_ == size_) {
			// increase capacity
			capacity_ *= 2;

			// new memory allocation
			T* temp = new T[capacity_];

			//copy data_ to temp
			copy(data_, data_ + size_, temp);

			delete[] data_;
			data_ = temp;
		}
		data_[size_] = val;
		++size_;
	}

	void pop_back() {
		if (size_ > 0) size_--;
	}

	T& operator[](size_t i) {
		if (i >= 0 && i < size_) return data_[i];
	}

	// for const object
	const T& operator[](size_t i) const {
		if (i >= 0 && i < size_) return data_[i];
	}

	size_t size() const {
		return size_;
	}
private:
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
	cout << "Copy Constructor: ";
	for (size_t i = 0; i < v2.size(); ++i) {
		cout << v2[i] << " ";
	}

	// Move Constructor
	MyVector<int> v3 = move(v1);
	cout << "\nMove Constructor: ";
	for (size_t i = 0; i < v3.size(); ++i) {
		cout << v3[i] << " ";
	}

	// Copy Assignment Operator
	MyVector<int> v4;
	v4 = v2;
	cout << "\nCopy Assignment Operator: ";
	for (size_t i = 0; i < v4.size(); ++i) {
		cout << v4[i] << " ";
	}

	// Move Assignment Operator
	MyVector<int> v5;
	v5 = move(v2);
	cout << "\nMove Assignment Operator: ";
	for (size_t i = 0; i < v5.size(); ++i)
		cout << v5[i] << " ";
	} // v �Ҹ�
	return 0;
}
