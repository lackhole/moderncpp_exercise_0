#include <iostream>
#include <memory>

class MyBaseClass {
public:
	virtual void Hello() {
		std::cout << "This is Base"<<std::endl;
	}

};

class MyDerivedClass :public MyBaseClass {
	void Hello() {
		std::cout << "This is Derived"<<std::endl;
	}
};

int main() {
	std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
	p->Hello();

	p->MyBaseClass::Hello();



	return 0;

}