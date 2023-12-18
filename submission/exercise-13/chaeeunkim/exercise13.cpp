#include <memory>
#include <iostream>
#include <utility>
using namespace std;

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__ 
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif

int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignment_count = 0;
int move_assignment_count = 0;
int destructor_count = 0;

class MyApplication {
public:
	MyApplication() {
		default_constructor_count++;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(const MyApplication& other) {
		copy_constructor_count++;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(MyApplication&&) noexcept {
		move_constructor_count++;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication& operator=(const MyApplication& other) {
		copy_assignment_count++;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	MyApplication& operator=(MyApplication&&) noexcept {
		move_assignment_count++;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	~MyApplication() {
		destructor_count++;
		std::cout << MY_FUNCTION << '\n';
	}
};

void TestUniquePtr() {
	// MyApplication 생성
	auto p = std::make_unique<MyApplication>();

	// unique pointer 이동
	auto p2 = std::move(p);
}

void TestSharedPtr() {
	// MyApplication 생성
	auto p = std::make_shared<MyApplication>();

	// copy constructor (소유권 복사)
	auto p2 = p;

	// p2 초기화
	p2.reset();

	// 약한 참조 객체 weak_ptr 생성
	std::weak_ptr<MyApplication> weak_p = p;

	//shared_ptr 반환
	auto lock = weak_p.lock();
	if (lock) {
		std::cout << "Acquired ownership\n";
	}
}

int main() {
	/*
	MyApplication my_app;  //기본 생성자 호출
	cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
	*/
	
	TestUniquePtr();
	cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
	cout << "복사 생성자 호출 횟수: " << copy_constructor_count << '\n';
	cout << "이동 생성자 호출 횟수: " << move_constructor_count << '\n';
	cout << "복사 대입 연산자 호출 횟수: " << copy_assignment_count << '\n';
	cout << "이동 대입 연산자 호출 횟수: " << move_assignment_count << '\n';
	cout << "소멸자 호출 횟수: " << destructor_count << '\n';

	TestSharedPtr();
	cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
	cout << "복사 생성자 호출 횟수: " << copy_constructor_count << '\n';
	cout << "이동 생성자 호출 횟수: " << move_constructor_count << '\n';
	cout << "복사 대입 연산자 호출 횟수: " << copy_assignment_count << '\n';
	cout << "이동 대입 연산자 호출 횟수: " << move_assignment_count << '\n';
	cout << "소멸자 호출 횟수: " << destructor_count << '\n';

	return 0;
}