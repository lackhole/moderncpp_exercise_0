#include <iostream>
#include <memory>
using namespace std;

class MyBaseClass {
public:
	virtual void Hello() {
		cout << "This is Base\n";
	}

	virtual ~MyBaseClass() {
		cout << "~MyBaseClass()\n";
	}
};

class MyDerivedClass : public MyBaseClass {
public:
	void Hello() override{
		cout << "This is Derived\n";
	}

	~MyDerivedClass() {
		cout << "~MyDerivedClass()\n";
	}
};

int main() {
	//auto ptr = std::make_unique<MyDerivedClass>();
	std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
	p->Hello();

	return 0;
}