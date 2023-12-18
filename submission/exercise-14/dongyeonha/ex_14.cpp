#include <iostream>
#include <memory>


class MyBaseClass {
public:
	virtual void Hello() {
		std::cout << "This is Base\n";
	}

	virtual ~MyBaseClass() = default; // 가상함수가 하나라도 있으면 소멸자도 virtual

};

class MyDerivedClass : public MyBaseClass {
public:
	void Hello() override {
		std::cout << "This is Derived\n";
	}

	virtual ~MyDerivedClass() = default;
};

int main() {
	std::unique_ptr<MyBaseClass> ptr = std::make_unique<MyDerivedClass>();
	ptr->Hello();

	return 0;
}