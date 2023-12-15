#include <iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	MyVector():data_(nullptr), capacity_(3), size_(0) { 
		data_ = new T[capacity_];
	}
	
	~MyVector() { 
		delete[] data_;
	}

	void push_back(int n) {
		if (size_ >= capacity_) { // if array is full
			capacity_ = capacity_ + 10;
			T* new_data = new T[capacity_]; 
			copy(data_, data_ + size_, new_data);
			delete[] data_;
			data_ = new_data;
		}
		data_[size_] = n;
		size_++;
	}

	void pop_back() {
		if (size_ > 0) {
			size_--;
		}
	}

	int operator[](size_t i) {
		return data_[i];
	}

	size_t size() const {
		return size_;
	}
	
private:
	T* data_;
	int size_;
	int capacity_;
};


// Use case
int main() {
		
	MyVector<int> v;
	
	v.push_back(1); // v.size() == 1
	v.push_back(2); // v.size() == 2
	v.push_back(3); // v.size() == 3
	v.push_back(4); // v.size() == 4
	v.push_back(5); // v.size() == 5
	// v 소멸
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] <<'\n';
	}
	v.pop_back();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] <<'\n';
	}


	return 0;
}