#include <iostream>
#include <memory>
#include <iostream>
#include <utility>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__ 
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif

int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignnment_operator_count = 0;
int move_assignnment_operator_count = 0;
int destrucor_count = 0;


class MyApplication {
	public:
		MyApplication() {
			default_constructor_count++;
			std::cout << MY_FUNCTION << '\n';
		}

		MyApplication(const MyApplication&) {
			copy_constructor_count++;
			std::cout << MY_FUNCTION << '\n';
		}

		MyApplication(MyApplication&&) noexcept {
			move_constructor_count++;
			std::cout << MY_FUNCTION << '\n';
		}

		MyApplication& operator=(const MyApplication&) {
			copy_assignnment_operator_count++;
			std::cout << MY_FUNCTION << '\n';
			return *this;
		}

		MyApplication& operator=(MyApplication&&) noexcept {
			move_assignnment_operator_count++;
			std::cout << MY_FUNCTION << '\n';
			return *this;
		}

		~MyApplication() {
			destrucor_count++;
			std::cout << MY_FUNCTION << '\n';
		}
};


void TestUniquePtr() {
	// MyApplication ����
	auto p = std::make_unique<MyApplication>();

	// MyApplication ����ũ �����͸� �̵� ���״�. -> �׷���, MyApplication���� ������ �̵�������, �̵����Կ����ڰ� ȣ����� �ʴ´�. 
	auto p2 = std::move(p);
}

void TestSharedPtr() {
	// MyApplication ����
	auto p = std::make_shared<MyApplication>();

	// std::shared_ptr�� ���� ������ ȣ��
	auto p2 = p;

	// p2 �ʱ�ȭ
	p2.reset();

	// ���� ���� ���� std::weak_ptr ����.
	std::weak_ptr<MyApplication> weak_p = p;

	// auto::shared_ptr ��ȯ
	auto lock = weak_p.lock();
	if (lock) {
		std::cout << "Acquired ownership\n";
	}
}


int main() {
	//MyApplication my_app;
	
	TestUniquePtr();
	std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << "\n";
	std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << "\n";
	std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << "\n";
	std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_assignnment_operator_count << "\n";
	std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_assignnment_operator_count << "\n";
	std::cout << "�Ҹ��� ȣ�� Ƚ��: " << destrucor_count << "\n";

	TestSharedPtr();
	std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << "\n";
	std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << "\n";
	std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << "\n";
	std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_assignnment_operator_count << "\n";
	std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_assignnment_operator_count << "\n";
	std::cout << "�Ҹ��� ȣ�� Ƚ��: " << destrucor_count << "\n";

	// ���� �����ڿ� �̵� �����ڸ� ����ϴ� ���� ���� ���� ��, ����Ʈ �����͸� ����ȴ�. 
	return 0;
}
