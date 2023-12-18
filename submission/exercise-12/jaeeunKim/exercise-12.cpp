#include <iostream>

using namespace std;
/*
* exercise-12.cpp
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

	// constructor for initializer_list
	MyVector(const initializer_list<T> r):
		size_(r.size()),
		capacity_(r.size()*2),
		data_(nullptr)
	{
		data_ = new T[capacity_];
		copy(r.begin(), r.end(), data_);
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

	T& operator[](size_t i) & {
		if (i < size_) return data_[i];
		else
			throw out_of_range("Index out of bounds");
	}

	const T& operator[](size_t i) const & {
		if (i < size_) return data_[i];
		else
			throw out_of_range("Index out of bounds");
	}

	T&& operator[](size_t i) && {
		if (i < size_) return move(data_[i]);
		else
			throw out_of_range("Index out of bounds");
	}

	const T&& operator[](size_t i) const && {
		if ( i < size_) return move(data_[i]);
		else
			throw out_of_range("Index out of bounds");
	}

	const size_t size() const {
		return size_;
	}
	void emplace_back(T&& val) {
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* temp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i)
				temp[i] = move(data_[i]);
			delete[] data_;
			data_ = temp;
		}
		data_[size_] = move(val);
		++size_;
	}

	template <typename... Args>
	void emplace_back(Args&&... args) {
		if (size_ = capacity_) {
			capacity_ *= 2;
			T* temp = new T[capacity_];
			for (size_t i = 0; i < size_; ++i)
				temp[i] = move(data_[i]);
			delete[] data_;
			data_ = temp;
		}
		data_[size_] = T(forward<Args>(args)...);
		++size_;
	}

	T* begin() {
		if(data_!=nullptr)
			return data_;
	}
	const T* begin() const {
		if (data_ != nullptr)
			return data_;
	}

	T* end() {
		return data_ + size_;
	}

	const T* end() const {
		return data_ + size_;
	}
private:
	T* data_;
	size_t size_;
	size_t capacity_;
};
int main() {

	{  
		const MyVector<int> v = { 1,2,3,4,5 };
		for (const auto& x : v) { 
			cout << x << ' ';
		}
	} 
	return 0;
}