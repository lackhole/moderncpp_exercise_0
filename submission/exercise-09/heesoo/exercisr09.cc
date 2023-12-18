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
		size_ += 1;
	}


private :
	T* data_;
	std::size_t capacity_;
	std::size_t size_;


};


int main() {





	return 0;
}







