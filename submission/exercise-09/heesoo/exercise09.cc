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
			// �뷮 �ø���
			capacity_ = capacity_ * 2;

			// �޸� ���� �Ҵ�
			T* new_data = new T[capacity_];
			
			// ���� �޸� ����
			std::copy(data_, data_ + size_, new_data);

			// ���� �޸� ����
			delete[] data_;

			// ���� ������ ��ü
			data_ = new_data;
		}

		data_[size_] = data;
		size += 1;
	}

	void pop_back() {
		if (size_ > 0) {
			size -= 1;
			// data_[size_].~T();
		}
	}

	T& operator[](std::size_t i) {
		return data_[i];
	}

	const T& operator[](std::size_t i) const {
		return data_[i];
	}

	std::size_t size() const {
		return size_;
	}

private :
	T* data_;
	std::size_t capacity_;
	std::size_t size_;


};


int main() {





	return 0;
}







