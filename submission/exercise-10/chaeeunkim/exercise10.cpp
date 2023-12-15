#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	MyVector() : data_(nullptr), capacity_(3), size_(0)
	{
		data_ = new T[capacity_];
	}

	~MyVector() {
		delete[] data_;
	}

	MyVector(const MyVector& other) : capacity_(other.capacity_), size_(other.size_)
	{
		data_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}

	MyVector(MyVector&& other) noexcept : capacity_(other.capacity_), size_(other.size_), data_(other.data_) {
		other.data_ = nullptr;
		other.capacity_ = 0;
		other.size_ = 0;
	}

	MyVector& operator=(const MyVector& other) {
		if (this != &other) {
			delete[] data_;

			capacity_ = other.capacity_;
			size_ = other.size_;
			data_ = new T[capacity_];

			// 다른 배열의 내용을 복사
			for (size_t i = 0; i < size_; ++i) {
				data_[i] = other.data_[i];
			}
		}

		return *this;
	}

	MyVector& operator=(MyVector&& other) noexcept {
		if (this != &other) {
			delete[] data_;
			data_ = other.data_;
			size_ = other.size_;
			capacity_ = other.capacity_;

			other.data_ = nullptr;
			other.capacity_ = 0;
			other.size_ = 0;
		}

		return *this;
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

	void pop_back() {
		if (size_ > 0) {
			size_--;
		}
	}

	const T& operator[](size_t s) const {
		return data_[s];
	}

	size_t size() const {
		return size_;
	}

private:
	T* data_;
	size_t capacity_;
	size_t size_;
};

int main() {

	{
		MyVector<int> v1;

		v1.push_back(1); // v.size() == 1
		v1.push_back(2); // v.size() == 2
		v1.push_back(3); // v.size() == 3
		v1.push_back(4); // v.size() == 4
		v1.push_back(5); // v.size() == 5

		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}

		cout << endl;

		MyVector<int> v2 = move(v1);
		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i] << " ";
		}
	}
}