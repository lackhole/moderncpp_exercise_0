#include <iostream>
#include <cstdint>
#include <memory>

void TestUniquePtr();
void TestSharedPtr();
void Print();

static int default_constructor_count = 0;
static int copy_constructor_count = 0;
static int move_constructor_count = 0;
static int op_copy_constructor_count = 0;
static int op_move_constructor_count = 0;
static int del_constructor_count = 0;

using namespace std;

template<typename T>
class MyVector {
public:
	MyVector() // 기본생성자
		: data_(nullptr),
		capacity_(3),
		size_(0)
	{
		data_ = new T[capacity_];
		++default_constructor_count;

		//cout << "생성자 " << endl;
	}
//
//	~MyVector() { // 소멸자
//		delete[] data_;
//		++del_constructor_count;
//		//cout << "소멸자" << endl;
//	}

	MyVector(MyVector&& v) noexcept { // 이동 생성자
		delete[] data_;
		this->capacity_ = v.capacity_;
		this->data_ = new T[capacity_];
		this->size_ = v.size_;

		++move_constructor_count;

		//cout << "이동생성자" << endl;
	}

	MyVector& operator=(MyVector&& v) noexcept { // 이동 연산자
		delete[] data_;
		this->capacity_ = v.capacity_;
		this->data_ = new T[capacity_];
		this->size_ = v.size_;

		++op_move_constructor_count;

		//cout << "이동연산자" << endl;
	}

	MyVector(MyVector& v) { // 복사생성자
		delete[] data_;
		this->capacity_ = v.capacity_;
		this->data_ = new T[capacity_];
		this->size_ = v.size_;

		++copy_constructor_count;
		//cout << "복사생성자" << endl;
	}

	MyVector& operator=(const MyVector & r) { // 복사 대입 연산자

		if (this != &r) {
			this->capacity_ = r.capacity_;
			this->data_ = r.data_;
			this->size_ = r.data_;
			
		}

		++op_copy_constructor_count;
		//cout << "복사대입연산자 호출" << endl;
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

private:
	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};



void TestUniquePtr() {

	auto p = std::make_unique<MyVector<char>>();

	
	auto p2 = std::move(p);
}

void TestSharedPtr() {
	
	// MyVector 생성
	auto p =std::make_shared<MyVector<char>>();
	
	auto p2 = p;  
	
	/*cout << "p.use_count(): " << p.use_count() << endl;
	cout << "p2.use_count(): " << p2.use_count() << endl;*/

	
	p2.reset();

	std::weak_ptr<MyVector<char>> weak_p = p; // weak_p에 p의 소유권이 이전

	auto lock = weak_p.lock();
	if (lock) {
		std::cout << "Acquired ownership\n";
	}
}




void Print() {
	std::cout << "-------------------------------------" << endl;
	std::cout << "기본 생성자 호출 횟수: " << default_constructor_count << endl;
	std::cout << "복사 생성자 호출 횟수: " << copy_constructor_count << endl;
	std::cout << "이동 생성자 호출 횟수: " << move_constructor_count << endl;
	std::cout << "복사 대입 연산자 호출 횟수: " << op_copy_constructor_count << endl;
	std::cout << "이동 대입 연산자 호출 횟수: " << op_move_constructor_count << endl;
	std::cout << "소멸자 호출 횟수: " << del_constructor_count << endl;
	std::cout << "-------------------------------------" << endl;

	default_constructor_count = 0;
	copy_constructor_count = 0;
	move_constructor_count = 0;
	op_copy_constructor_count = 0;
	op_move_constructor_count = 0;
	del_constructor_count = 0;
}

int main() {
	TestUniquePtr();
	Print();

	TestSharedPtr();

	Print();

	return 0;
}
