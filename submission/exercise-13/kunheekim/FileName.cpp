#include <iostream>
#include <memory>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__ 
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif
int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignment_operator_count = 0;
int move_signment_operator_count = 0;
int desturctor_count = 0;

class MyApplication {
public:
	MyApplication() {
		default_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(const MyApplication&) {
		copy_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(MyApplication&&) noexcept {
		move_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication& operator=(const MyApplication&) {
		copy_assignment_operator_count += 1;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	MyApplication& operator=(MyApplication&&) noexcept {
		move_signment_operator_count += 1;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	~MyApplication() {
		desturctor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}
};

void TestUniquePtr() {
	// MyApplication 생성
	auto p = std::make_unique<MyApplication>();

	// MyApplication 이동
	auto p2 = std::move(p);
}

void TestSharedPtr() {
	// MyApplication 생성
	auto p = std::make_shared<MyApplication>();

	// ? //선언과 동시에 초기화 중
	//shared_ptr의 복사 생성자 호출
	
	auto p2 = p;

	// p2 초기화
	p2.reset();

	// ? // 약한 참조 객체 
	std::weak_ptr<MyApplication> weak_p = p;

	auto lock = weak_p.lock();
	if (lock) {
		std::cout << "Acquired ownership\n";
	}
}

int main() {

	//MyApplication my_app;
	TestUniquePtr();
	//TestSharedPtr();
	std::cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
	std::cout << "복사 생성자 호출 횟수: " << copy_constructor_count << '\n';
	std::cout << "이동 생성자 호출 횟수: " << move_constructor_count << '\n';
	std::cout << "복사 대입 연산자 호출 횟수: " << copy_assignment_operator_count << '\n';
	std::cout << "이동 대입 연산자 호출 횟수: " << move_signment_operator_count << '\n';
	std::cout << "소멸자 호출 횟수: " << desturctor_count << '\n';

	//TestUniquePtr();
	TestSharedPtr();
	std::cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
	std::cout << "복사 생성자 호출 횟수: " << copy_constructor_count << '\n';
	std::cout << "이동 생성자 호출 횟수: " << move_constructor_count << '\n';
	std::cout << "복사 대입 연산자 호출 횟수: " << copy_assignment_operator_count << '\n';
	std::cout << "이동 대입 연산자 호출 횟수: " << move_signment_operator_count << '\n';
	std::cout << "소멸자 호출 횟수: " << desturctor_count << '\n';


	return 0;
}