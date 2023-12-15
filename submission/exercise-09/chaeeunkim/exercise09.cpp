#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	MyVector() {
		data_ = new T[3];
	}

	~MyVector() { 
		delete[] data_;
	}

	void push_back(T a) {
		if (i == size_s) {
			size_t new_size = size_s * 2;
			int * new_data_ = new T[new_size];
			for (size_t j = 0; j < size_s; j++) {
				new_data_[j] = data_[j];
			}
			delete[] data_;

			data_ = new_data_;
			size_s = new_size;
		}
		data_[i++] = a;
	}

	void pop_back() {
		if (i > 0) {
			i--;
		}
	}

	T operator[](size_t s) {
		return data_[s];
	}

	size_t size() const {
		return i;
	}

private:
	T* data_;
	size_t i = 0;
	size_t size_s = 3;
};

int main() {
	
	{
		MyVector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
}