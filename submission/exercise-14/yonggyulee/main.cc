#include <iostream>
#include <memory>

class MyBaseClass {
public:

	virtual void Hello() {
		std::cout << "This is Base\n";
	}

	virtual ~MyBaseClass() {
		std::cout << "~MyBaseClass()\n";
	}
};

class MyDerivedClass : public MyBaseClass {
public:

	void Hello() override {
		std::cout << "This is Derived\n";
	}

	~MyDerivedClass() {
		std::cout << "~MyDerivedClass()\n";
	}
};

int main() {

	std::unique_ptr<MyBaseClass> ptr
		= std::make_unique<MyDerivedClass>();

	ptr->Hello();


	return 0;
}
