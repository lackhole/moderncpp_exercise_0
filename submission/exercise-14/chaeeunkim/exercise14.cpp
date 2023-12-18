#include <iostream>
using namespace std;

class MyBaseClass {
public:
	virtual void Hello() {
		cout << "This is Base" << endl;
	}
};

class MyDerivedClass : public MyBaseClass{
public:
	virtual void Hello() {
		cout << "This is Derived" << endl;
	}
};

int main() {
	std::unique_ptr<MyBaseClass> p = std::make_unique<MyDerivedClass>();
	p->Hello();

	return 0;
}